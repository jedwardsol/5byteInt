#pragma once
#include "5ByteInt.h"
#include <concepts>

static_assert(sizeof(int40_t)==5);
static_assert(sizeof(uint40_t)==5);

static_assert(  1_i40);
static_assert( !0_i40);
static_assert(  1_u40);
static_assert( !0_u40);

static_assert( -1_i40 <  0_i40);
static_assert(  1_i40 == 1_i40);
static_assert(  1_i40 != 2_i40);
static_assert(  1_i40 <= 1_i40);
static_assert(  1_i40 <  2_i40);
static_assert(  1_i40 <= 2_i40);

static_assert(  1_u40 == 1_u40);
static_assert(  1_u40 != 2_u40);
static_assert(  1_u40 <= 1_u40);
static_assert(  1_u40 <  2_u40);
static_assert(  1_u40 <= 2_u40);


static_assert(  1_i40 + 2_i40 ==  3_i40);
static_assert(  1_u40 + 2_u40 ==  3_u40);
static_assert(  1_i40 - 5_i40 == -4_i40);
static_assert(  5_i40 - 1_i40 ==  4_i40);
static_assert( 23_i40 % 3_i40 ==  2_i40);
static_assert(  2_u40 | 1_u40 ==  3_u40);


static_assert ( std::totally_ordered<int40_t> );
static_assert ( std::totally_ordered<uint40_t> );
static_assert ( std::regular<int40_t> );
static_assert ( std::regular<uint40_t> );
