#pragma once
#include <type_traits>
#include <cstdint>
#include <bit>
#include <concepts>
#include <array>
#include <compare>

static_assert(std::endian::native == std::endian::little);

template <bool isSigned>
class core40_t
{
public:

    using native_t = std::conditional_t<isSigned,int64_t, uint64_t>;

    constexpr core40_t() noexcept
    {
        store(0);
    }

    explicit constexpr core40_t(native_t native) noexcept
    {
        store(native);
    }

    explicit constexpr operator native_t() const noexcept
    {
        return load();
    }


   constexpr std::strong_ordering operator<=>(core40_t const other) const noexcept
    {
        return load() <=> other.load();
    }

    constexpr bool operator==(core40_t const other) const noexcept
    {
        return load() == other.load();
    }

    constexpr bool operator!=(core40_t const other) const noexcept
    {
        return !(*this == other);
    }

    constexpr explicit operator bool() const noexcept
    {
        return load() != 0;
    }

//

    constexpr core40_t operator+() noexcept
    {
        return *this;
    }

    constexpr core40_t operator~() noexcept
    {
        auto value{load()};

        value=~value;

        return core40_t<isSigned>{value};
    }

//

    constexpr core40_t &operator++() noexcept
    {
        auto value{load()};

        value++;

        store(value);

        return *this;
    }

    constexpr core40_t operator++(int) noexcept
    {
        auto const  original{*this};
        auto        value{load()};

        value++;

        store(value);

        return original;
    }

    constexpr core40_t &operator--() noexcept
    {
        auto value{load()};

        value--;

        store(value);

        return *this;
    }

    constexpr core40_t operator--(int) noexcept
    {
        auto original{*this};
        auto value{load()};

        value--;

        store(value);

        return original;
    }


    #define CORE40_T_COMPOUND(OP)                                     \
        constexpr core40_t &operator OP (core40_t const rhs) noexcept \
        {                                                             \
            auto value{load()};                                       \
            value OP rhs.load();                                      \
            store(value);                                             \
            return *this;                                             \
        }

    CORE40_T_COMPOUND(+=)
    CORE40_T_COMPOUND(-=)
    CORE40_T_COMPOUND(*=)
    CORE40_T_COMPOUND(/=)
    CORE40_T_COMPOUND(%=)

    CORE40_T_COMPOUND(&=)
    CORE40_T_COMPOUND(|=)
    CORE40_T_COMPOUND(^=)
    CORE40_T_COMPOUND(<<=)
    CORE40_T_COMPOUND(>>=)

    #undef CORE40_T_COMPOUND


private:

    constexpr void store(native_t native) noexcept
    {
        auto allBytes = std::bit_cast<std::array<std::byte,8>>(native);

        for(int i=0;i<5;i++)
        {
            bytes[i]=allBytes[i];
        }
    }
    
    constexpr native_t load() const noexcept
    {
        std::byte init{};

        if(negative())
        {
            init=std::byte{0xff};
        }

        std::array<std::byte,8> allBytes{bytes[0],bytes[1],bytes[2],bytes[3],bytes[3],init,init,init,};

        return std::bit_cast<native_t>(allBytes);
    }

    constexpr bool    negative() const noexcept
    {
        if constexpr(isSigned)
        {
            return static_cast<uint8_t>(bytes[4]) & 0b1000'0000;
        }
        else
        {
            return false;
        }
    }

    std::array<std::byte,5> bytes{};
};


#define CORE40_T_BINARYOP(OP)                                                               \
    template <bool isSigned>                                                                \
    constexpr inline core40_t<isSigned> operator OP (core40_t<isSigned>       lhs,          \
                                                     core40_t<isSigned> const rhs) noexcept \
    {                                                                                       \
        lhs OP##= rhs;                                                                      \
        return lhs;                                                                         \
    }

CORE40_T_BINARYOP(+)
CORE40_T_BINARYOP(-)
CORE40_T_BINARYOP(*)
CORE40_T_BINARYOP(/)
CORE40_T_BINARYOP(%)

//CORE40_T_BINARYOP(&)
CORE40_T_BINARYOP(|)
CORE40_T_BINARYOP(^)
CORE40_T_BINARYOP(<<)
CORE40_T_BINARYOP(>>)

#undef CORE40_T_BINARYOP



    template <bool isSigned>                                                                \
    constexpr inline core40_t<isSigned> operator & (core40_t<isSigned>       lhs,          \
                                                     core40_t<isSigned> const rhs) noexcept \
    {                                                                                       \
        lhs &= rhs;                                                                      \
        return lhs;                                                                         \
    }


using  int40_t = core40_t<true>;
using uint40_t = core40_t<false>;



constexpr inline int40_t operator-(int40_t i) noexcept
{
    auto value = int40_t::native_t{i};

    value=-value;

    return int40_t{value};
}


constexpr inline uint40_t operator""_u40(unsigned long long val)
{
    return uint40_t{val};
}

constexpr inline int40_t operator""_i40(unsigned long long val)
{
    return int40_t{static_cast<int64_t>(val)};
}


#include "compileTimeTest.h"