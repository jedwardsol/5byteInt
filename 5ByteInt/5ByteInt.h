#pragma once
#include <type_traits>
#include <cstdint>
#include <bit>
#include <concepts>
#include <array>

static_assert(std::endian::native == std::endian::little);

template <bool isSigned>
class core5_t
{
public:

    using native_t = std::conditional_t<isSigned,int64_t, uint64_t>;

    constexpr core5_t() noexcept
    {
        store(0);
    }


    explicit constexpr core5_t(native_t native) noexcept
    {
        store(native);
    }


    explicit operator native_t() const noexcept
    {
        return load();
    }


//

    constexpr core5_t &operator++() noexcept
    {
        auto value{load()};

        value++;

        store(value);

        return *this;
    }

    constexpr core5_t operator++(int) noexcept
    {
        auto const  original{*this};
        auto        value{load()};

        value++;

        store(value);

        return original;
    }


    constexpr core5_t &operator--() noexcept
    {
        auto value{load()};

        value--;

        store(value);

        return *this;
    }

    constexpr core5_t operator--(int) noexcept
    {
        auto original{*this};
        auto value{load()};

        value--;

        store(value);

        return original;
    }


    #define CORE_5T_COMPOUND(OP)                                \
        constexpr core5_t &operator OP (core5_t rhs) noexcept   \
        {                                                       \
            auto value{load()};                                 \
            value OP rhs.load();                                \
            store(value);                                       \
            return *this;                                       \
        }                                                       

    CORE_5T_COMPOUND(+=)
    CORE_5T_COMPOUND(-=)
    CORE_5T_COMPOUND(*=)
    CORE_5T_COMPOUND(/=)
    CORE_5T_COMPOUND(%=)

    CORE_5T_COMPOUND(&=)
    CORE_5T_COMPOUND(|=)
    CORE_5T_COMPOUND(^=)
    CORE_5T_COMPOUND(<<=)
    CORE_5T_COMPOUND(>>=)

    #undef CORE_5T_COMPOUND


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

//    std::byte    bytes[5];    
    std::array<std::byte,5> bytes;

};


#define CORE_5T_BINARYOP(OP)                                                                      \
    template <bool isSigned>                                                                                \
    constexpr core5_t<isSigned> operator OP (core5_t<isSigned> lhs,core5_t<isSigned> const rhs) noexcept    \
    {                                                                                                       \
        lhs OP##= rhs;                                                                                   \
        return lhs;                                                                                         \
    }                                                       

CORE_5T_BINARYOP(+)
CORE_5T_BINARYOP(-)
CORE_5T_BINARYOP(*)
CORE_5T_BINARYOP(/)
CORE_5T_BINARYOP(%)

CORE_5T_BINARYOP(&)
CORE_5T_BINARYOP(|)
CORE_5T_BINARYOP(^)
CORE_5T_BINARYOP(<<)
CORE_5T_BINARYOP(>>)

#undef CORE_5T_BINARYOP









using  int40_t = core5_t<true>;
using uint40_t = core5_t<false>;

static_assert(sizeof(int40_t)==5);
static_assert(sizeof(uint40_t)==5);
