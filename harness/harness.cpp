#include <iostream>
#include <iomanip>
#include <format>
#include <typeinfo>

#include "5ByteInt/5ByteInt.h"
#include "5ByteInt/limits.h"
#include "5ByteInt/io.h"


void construct()
{
    int40_t     i{ 42};

    int40_t     copy{i};
    int40_t     move{std::move(i)};

    copy = i;
    copy = std::move(i);


    constexpr auto  u_literal       =  42_u40;
    constexpr auto  i_literal       =  42_i40;
    constexpr auto  neg_i_literal   = -42_i40;

}




void print()
{
    auto        pi{  42_i40 };
    auto        ni{ -42_i40 };

    auto        pu{  42_u40 };
    uint40_t    nu(-42);

    std::cout << std::setw(10) << pi  << ' ' 
              << std::setw(10) << ni  << ' ' 
              << std::setw(10) << pu << ' ' 
              << std::setw(10) << nu << '\n';

    std::cout << std::hex;
    std::cout << std::setw(10) << pi  << ' ' 
              << std::setw(10) << ni  << ' ' 
              << std::setw(10) << pu << ' ' 
              << std::setw(10) << nu << '\n';
    std::cout << std::dec;


    std::cout << std::format("{:10} {:10} {:10} {:10}\n",
                             pi,
                             ni,
                             pu,
                             nu);

/*

    std::cout << std::format("{:10x} {:10x} {:10x} {:10x}\n",
                             pi,
                             ni,
                             pu,
                             nu);
*/

}




template<std::integral T>
void limits() 
{
    std::cout << std::format("{}\n", typeid(T).name());
    std::cout << std::format(" is_specialized      {}\n", std::numeric_limits<T>::is_specialized);
    std::cout << std::format(" is_signed           {}\n", std::numeric_limits<T>::is_signed     );
    std::cout << std::format(" is_integer          {}\n", std::numeric_limits<T>::is_integer    );
    std::cout << std::format(" is_exact            {}\n", std::numeric_limits<T>::is_exact      );
    std::cout << std::format(" is_bounded          {}\n", std::numeric_limits<T>::is_bounded    );
    std::cout << std::format(" traps               {}\n", std::numeric_limits<T>::traps         );
    std::cout << std::format(" is_modulo           {}\n", std::numeric_limits<T>::is_modulo     );
    std::cout << std::format(" digits10            {}\n", std::numeric_limits<T>::digits10      );
    std::cout << std::format(" max_digits10        {}\n", std::numeric_limits<T>::max_digits10  );
    std::cout << std::format(" radix               {}\n", std::numeric_limits<T>::radix         );
    std::cout << std::format(" digits              {}\n", std::numeric_limits<T>::digits        );

    std::cout << std::format(" max()               {}\n", std::numeric_limits<T>::max()         );
    std::cout << std::format(" min()               {}\n", std::numeric_limits<T>::min()         );
    std::cout << std::format(" lowest()            {}\n", std::numeric_limits<T>::lowest()      );
    std::cout << "\n";
}

template<typename T>
void limits() 
{
    std::cout << std::format("{}\n", typeid(T).name());
    std::cout << std::format(" is_specialized      {}\n", std::numeric_limits<T>::is_specialized);
    std::cout << std::format(" is_signed           {}\n", std::numeric_limits<T>::is_signed     );
    std::cout << std::format(" is_integer          {}\n", std::numeric_limits<T>::is_integer    );
    std::cout << std::format(" is_exact            {}\n", std::numeric_limits<T>::is_exact      );
    std::cout << std::format(" is_bounded          {}\n", std::numeric_limits<T>::is_bounded    );
    std::cout << std::format(" traps               {}\n", std::numeric_limits<T>::traps         );
    std::cout << std::format(" is_modulo           {}\n", std::numeric_limits<T>::is_modulo     );
    std::cout << std::format(" digits10            {}\n", std::numeric_limits<T>::digits10      );
    std::cout << std::format(" max_digits10        {}\n", std::numeric_limits<T>::max_digits10  );
    std::cout << std::format(" radix               {}\n", std::numeric_limits<T>::radix         );
    std::cout << std::format(" digits              {}\n", std::numeric_limits<T>::digits        );

    std::cout << std::format(" max()               {}\n", static_cast<typename T::native_t>(std::numeric_limits<T>::max())         );
    std::cout << std::format(" min()               {}\n", static_cast<typename T::native_t>(std::numeric_limits<T>::min())         );
    std::cout << std::format(" lowest()            {}\n", static_cast<typename T::native_t>(std::numeric_limits<T>::lowest())      );
    std::cout << "\n";
}



template <typename T>
void incdec()
{
    {
        T i{42};
        auto pre  = ++i;

        std::cout << std::format("{} {}\n",i,pre);
    }

    {
        T i{42};
        auto post  = i++;

        std::cout << std::format("{} {}\n",i,post);
    }

    {
        T i{42};
        auto pre  = --i;

        std::cout << std::format("{} {}\n",i,pre);
    }

    {
        T i{42};
        auto post  = i--;

        std::cout << std::format("{} {}\n",i,post);
    }
}



template <typename T>
void compound()
{
    {
        T i{42};
        i+= T{42};
        std::cout << std::format("{} \n",i);
    }

    {
        T i{42};
        i-= T{42};
        std::cout << std::format("{} \n",i);
    }

    {
        T i{42};
        i*= T{2};
        std::cout << std::format("{} \n",i);
    }

    {
        T i{42};
        i/= T{2};
        std::cout << std::format("{} \n",i);
    }

    {
        T i{42};
        i%= T{13};
        std::cout << std::format("{} \n",i);
    }


    {
        T i{42};
        i <<= T{2};
        std::cout << std::format("{} \n",i);
    }
}


template <typename T>
void binop()
{
    {
        T l{42};
        T r{13};

        auto sum = l+r;

        std::cout << std::format("{}+{}={} \n",l,r,sum);
    }

    {
        constexpr T l{42};
        constexpr T r{13};

        constexpr auto sum = l+r;

        std::cout << std::format("{}+{}={} \n",l,r,sum);
    }
}


template <typename T>
void compare()
{
    constexpr auto zero    {T{0}};    
    constexpr auto nonzero {T{99}};    

    constexpr auto little  {T{1}};    
    constexpr auto medium  {T{2}};    
    constexpr auto big     {T{3}};    

    static_assert(  !zero );
    static_assert(   nonzero );
    static_assert( !!nonzero );


    static_assert( little == little );
    static_assert( little != medium );
    static_assert( little < medium);
    static_assert( little <= medium);

    static_assert( big > medium);
    static_assert( big >= medium);

}


int main()
try
{
    construct();

    print();

    limits<int64_t>();
    limits<int40_t>();

    limits<uint64_t>();
    limits<uint40_t>();

    auto max = std::numeric_limits<int40_t>::max();


    incdec<int40_t>();
    incdec<uint40_t>();


    compound<int40_t>();
    compound<uint40_t>();

    binop<int40_t>();
    binop<uint40_t>();

    compare<int40_t>();
    compare<uint40_t>();


    return 0;
}
catch(std::exception const &e)
{
    std::cout << e.what() << '\n';
}