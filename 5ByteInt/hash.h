#pragma once

#include <functional>

#include "5ByteInt.h"


template <>
struct std::hash<int40_t> 
{
    std::size_t operator()(int40_t i) const noexcept 
    {
        return std::hash<int40_t::native_t>{}( int40_t::native_t{i} );
    }
};

template <>
struct std::hash<uint40_t> 
{
    std::size_t operator()(uint40_t i) const noexcept 
    {
        return std::hash<uint40_t::native_t>{}( uint40_t::native_t{i} );
    }
};

