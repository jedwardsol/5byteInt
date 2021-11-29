#pragma once

#include <limits>
#include "5ByteInt.h"


template<>
class std::numeric_limits<int40_t>
{
public:
// constants

    static constexpr bool               is_specialized                      {true};
    static constexpr bool               is_signed                           {true};
    static constexpr bool               is_integer                          {true};
    static constexpr bool               is_exact                            {true};
    static constexpr bool               is_bounded                          {true};
    static constexpr bool               traps                               {false};

    static constexpr bool               is_modulo                           {false};
    static constexpr int                digits10                            { 12 };                        
    static constexpr int                max_digits10                        { 0  };                        

    static constexpr int                radix                               {2};                        
    static constexpr int                digits                              {39};


// functions
    [[nodiscard]]static constexpr       int40_t max()    noexcept           { return  int40_t{(1LL<<39) - 1}; }
    [[nodiscard]]static constexpr       int40_t min()    noexcept           { return  max()    /* - 1;*/; }
    [[nodiscard]]static constexpr       int40_t lowest() noexcept           { return  min();       }


// irrelevent float constants

    static constexpr bool               is_iec559                           {false};
    static constexpr float_round_style  round_style                         {std::round_toward_zero};
    static constexpr bool               has_infinity                        {false};
    static constexpr bool               has_quiet_NaN                       {false};
    static constexpr bool               has_signaling_NaN                   {false};
    static constexpr bool               has_denorm                          {false};
    static constexpr bool               has_denorm_loss                     {false};
    static constexpr int                min_exponent                        {0};
    static constexpr int                min_exponent10                      {0};
    static constexpr int                max_exponent                        {0};
    static constexpr int                max_exponent10                      {0};
    static constexpr bool               tinyness_before                     {false};
 
// irrelevent float functions

    [[nodiscard]]static constexpr       int epsilon()       noexcept        { return 0; }
    [[nodiscard]]static constexpr       int round_error()   noexcept        { return 0; }
    [[nodiscard]]static constexpr       int infinity()      noexcept        { return 0; }
    [[nodiscard]]static constexpr       int quiet_NaN()     noexcept        { return 0; }
    [[nodiscard]]static constexpr       int signaling_NaN() noexcept        { return 0; }
    [[nodiscard]]static constexpr       int denorm_min()    noexcept        { return 0; }
};

template<>
class std::numeric_limits<uint40_t>
{
public:
// constants

    static constexpr bool               is_specialized                      {true};
    static constexpr bool               is_signed                           {false};
    static constexpr bool               is_integer                          {true};
    static constexpr bool               is_exact                            {true};
    static constexpr bool               is_bounded                          {true};
    static constexpr bool               traps                               {false};

    static constexpr bool               is_modulo                           {true};
    static constexpr int                digits10                            { 13  };                        
    static constexpr int                max_digits10                        { 0 };                        

    static constexpr int                radix                               {2};                        
    static constexpr int                digits                              {40};


// functions
    [[nodiscard]]static constexpr       uint40_t max()    noexcept          { return  uint40_t{(1LL<<40) - 1}; }
    [[nodiscard]]static constexpr       uint40_t min()    noexcept          { return  uint40_t{0}; }
    [[nodiscard]]static constexpr       uint40_t lowest() noexcept          { return  min();       }


// irrelevent float constants

    static constexpr bool               is_iec559                           {false};
    static constexpr float_round_style  round_style                         {std::round_toward_zero};
    static constexpr bool               has_infinity                        {false};
    static constexpr bool               has_quiet_NaN                       {false};
    static constexpr bool               has_signaling_NaN                   {false};
    static constexpr bool               has_denorm                          {false};
    static constexpr bool               has_denorm_loss                     {false};
    static constexpr int                min_exponent                        {0};
    static constexpr int                min_exponent10                      {0};
    static constexpr int                max_exponent                        {0};
    static constexpr int                max_exponent10                      {0};
    static constexpr bool               tinyness_before                     {false};
 
// irrelevent float functions

    [[nodiscard]]static constexpr       int epsilon()       noexcept        { return 0; }
    [[nodiscard]]static constexpr       int round_error()   noexcept        { return 0; }
    [[nodiscard]]static constexpr       int infinity()      noexcept        { return 0; }
    [[nodiscard]]static constexpr       int quiet_NaN()     noexcept        { return 0; }
    [[nodiscard]]static constexpr       int signaling_NaN() noexcept        { return 0; }
    [[nodiscard]]static constexpr       int denorm_min()    noexcept        { return 0; }
};

