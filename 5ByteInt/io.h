#pragma once

#include <iostream>
#include <format>

#include "5ByteInt.h"


std::ostream &operator<<(std::ostream &out,const int40_t  &i)
{
    // TODO : limit -ve values
    return out <<  static_cast<int40_t::native_t>(i);
}

std::ostream &operator<<(std::ostream &out,const uint40_t  &u)
{
    return out <<  static_cast<uint40_t::native_t>(u);
}



template <>
struct std::formatter<int40_t> : std::formatter<std::string>        
{
    auto format(int40_t const &i, std::format_context &ctx) 
    {
        return formatter<string>::format(std::format("{}", static_cast<int40_t::native_t>(i)), ctx);
    }
};

template <>
struct std::formatter<uint40_t> : std::formatter<std::string> 
{
    auto format(uint40_t const &u, std::format_context &ctx) 
    {
        return formatter<string>::format(std::format("{}", static_cast<uint40_t::native_t>(u)), ctx);
    }
};

