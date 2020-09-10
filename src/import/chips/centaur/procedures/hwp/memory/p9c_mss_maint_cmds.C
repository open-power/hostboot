/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_maint_cmds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file p9c_mss_maint_cmds.C
/// @brief Utility functions for running maint cmds,accessing markstore, and accessing steer muxes.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//------------------------------------------------------------------------------
//    Includes
//------------------------------------------------------------------------------

#include <p9c_mss_maint_cmds.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_dimmBadDqBitmapFuncs.H>
#include <generic/memory/lib/utils/c_str.H>

//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------


/// @brief The number of symbols per rank
constexpr uint8_t MSS_SYMBOLS_PER_RANK =                  72;


/// @brief The used for symbol ranges on port 0: Symbols 71-40, 7-4
constexpr uint8_t MSS_PORT_0_SYMBOL_71 =                  71;
constexpr uint8_t MSS_PORT_0_SYMBOL_40 =                  40;
constexpr uint8_t MSS_PORT_0_SYMBOL_7 =                   7;
constexpr uint8_t MSS_PORT_0_SYMBOL_4 =                   4;

/// @brief The used for symbol ranges on port 1: Symbols 39-8, 3-0
constexpr uint8_t MSS_PORT_1_SYMBOL_39 =                  39;
constexpr uint8_t MSS_PORT_1_SYMBOL_8 =                   8;
constexpr uint8_t MSS_PORT_1_SYMBOL_3 =                   3;
constexpr uint8_t MSS_PORT_1_SYMBOL_0 =                   0;

/// @brief MASTER RANK = 0:3 SLAVE RANK = 4:6 BANK = 7:10 ROW = 11:27 COL = 28:39, note: c2, c1, c0 always 0
constexpr uint8_t VALID_BITS_IN_ADDR_STRING = 37;



/// @brief 9 x8 DRAMs we can steer, plus one for no steer option
constexpr uint8_t MSS_X8_STEER_OPTIONS_PER_PORT =         10;

/// @brief 18 x4 DRAMs we can steer on port0, plus one for no steer option
constexpr uint8_t MSS_X4_STEER_OPTIONS_PER_PORT0 =        19;

/// @brief 17 x4 DRAMs we can steer on port1, plus one no steer option
/// NOTE: Only 17 DRAMs we can steer since one DRAM is used for the
/// ECC spare.
constexpr uint8_t MSS_X4_STEER_OPTIONS_PER_PORT1 =        18;

/// @brief 18 on port0, 17 on port1, plus one no steer option
/// NOTE: Can's use ECC spare to fix bad spare DRAMs
constexpr uint8_t MSS_X4_ECC_STEER_OPTIONS =              36;

/// @brief Max 8 patterns
constexpr uint8_t MSS_MAX_PATTERNS =                      9;


namespace mss_memconfig
{
/// @brief DRAM size in gigabits, used to determine address range for maint cmds
enum DramSize
{
    GBIT_2 = 0,
    GBIT_4 = 1,
    GBIT_8 = 2,
};

/// @brief DRAM width, used to determine address range for maint cmds
enum DramWidth
{
    X4 = fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
    X8 = fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8,
};

/// @brief DRAM row, column, and bank bits, used to determine address range
///        for maint cmds
enum MemOrg
{
    ROW_14 = 0x00003FFF,
    ROW_15 = 0x00007FFF,
    ROW_16 = 0x0000FFFF,
    ROW_17 = 0x0001FFFF,
    COL_10 = 0x000003F8,    // c2, c1, c0 always 0
    COL_11 = 0x000007F8,    // c2, c1, c0 always 0
    COL_12 = 0x00000FF8,    // c2, c1, c0 always 0
    BANK_3 = 0x00000007,
    BANK_4 = 0x0000000F,
};

/// @brief Spare DRAM config, used to identify what spares exist
enum SpareDramConfig
{
    NO_SPARE    = 0,
    LOW_NIBBLE  = 1, // x4 spare (low nibble: default)
    HIGH_NIBBLE = 2, // x4 spare (high nibble: no plan to use)
    FULL_BYTE   = 3  // x8 dpare
};

};




static constexpr uint32_t mss_mbaxcr[MAX_MBA_PER_CEN] =
{
    // port0/1                     port2/3
    CEN_MBAXCR01Q,          CEN_MBAXCR23Q
};

static constexpr uint32_t mss_mbeccfir[MAX_MBA_PER_CEN] =
{
    // port0/1                     port2/3
    CEN_ECC01_MBECCFIR,  CEN_ECC23_MBECCFIR
};

static constexpr uint32_t mss_mbsecc[MAX_MBA_PER_CEN] =
{
    // port0/1                     port2/3
    CEN_ECC01_MBSECCQ,   CEN_ECC23_MBSECCQ
};

static constexpr uint32_t mss_markstore_regs[MAX_RANKS_PER_PORT][MAX_MBA_PER_CEN] =
{
    // port0/1                     port2/3
    {CEN_ECC01_MBMS0,    CEN_ECC23_MBMS0},
    {CEN_ECC01_MBMS1,    CEN_ECC23_MBMS1},
    {CEN_ECC01_MBMS2,    CEN_ECC23_MBMS2},
    {CEN_ECC01_MBMS3,    CEN_ECC23_MBMS3},
    {CEN_ECC01_MBMS4,    CEN_ECC23_MBMS4},
    {CEN_ECC01_MBMS5,    CEN_ECC23_MBMS5},
    {CEN_ECC01_MBMS6,    CEN_ECC23_MBMS6},
    {CEN_ECC01_MBMS7,    CEN_ECC23_MBMS7}
};

static constexpr uint32_t mss_mbstr[MAX_MBA_PER_CEN] =
{
    // port0/1                   port2/3
    CEN_MCBISTS01_MBSTRQ,     CEN_MCBISTS23_MBSTRQ
};

static constexpr uint32_t mss_mbmmr[MAX_MBA_PER_CEN] =
{
    // port0/1                   port2/3
    CEN_ECC01_MBMMRQ,  CEN_ECC23_MBMMRQ
};

static constexpr uint32_t mss_readMuxRegs[MAX_RANKS_PER_PORT][MAX_MBA_PER_CEN] =
{
    // port0/1                     port2/3
    {CEN_ECC01_MBSBS0,   CEN_ECC23_MBSBS0},
    {CEN_ECC01_MBSBS1,   CEN_ECC23_MBSBS1},
    {CEN_ECC01_MBSBS2,   CEN_ECC23_MBSBS2},
    {CEN_ECC01_MBSBS3,   CEN_ECC23_MBSBS3},
    {CEN_ECC01_MBSBS4,   CEN_ECC23_MBSBS4},
    {CEN_ECC01_MBSBS5,   CEN_ECC23_MBSBS5},
    {CEN_ECC01_MBSBS6,   CEN_ECC23_MBSBS6},
    {CEN_ECC01_MBSBS7,   CEN_ECC23_MBSBS7}
};

static constexpr uint32_t mss_writeMuxRegs[MAX_RANKS_PER_PORT] =
{

    CEN_MBA_MBABS0,
    CEN_MBA_MBABS1,
    CEN_MBA_MBABS2,
    CEN_MBA_MBABS3,
    CEN_MBA_MBABS4,
    CEN_MBA_MBABS5,
    CEN_MBA_MBABS6,
    CEN_MBA_MBABS7
};

//------------------------------------------------------------------------------
// Conversion from symbol index to galois field stored in markstore
//------------------------------------------------------------------------------
static constexpr uint8_t mss_symbol2Galois[MSS_SYMBOLS_PER_RANK] =
{
    0x80, 0xa0, 0x90, 0xf0, 0x08, 0x0a, 0x09, 0x0f, // symbols  0- 7
    0x98, 0xda, 0xb9, 0x7f, 0x91, 0xd7, 0xb2, 0x78, // symbols  8-15
    0x28, 0xea, 0x49, 0x9f, 0x9a, 0xd4, 0xbd, 0x76, // symbols 16-23
    0x60, 0xb0, 0xc0, 0x20, 0x06, 0x0b, 0x0c, 0x02, // symbols 24-31
    0xc6, 0xfb, 0x1c, 0x42, 0xca, 0xf4, 0x1d, 0x46, // symbols 32-39
    0xd6, 0x8b, 0x3c, 0xc2, 0xcb, 0xf3, 0x1f, 0x4e, // symbols 40-47
    0xe0, 0x10, 0x50, 0xd0, 0x0e, 0x01, 0x05, 0x0d, // symbols 48-55
    0x5e, 0x21, 0xa5, 0x3d, 0x5b, 0x23, 0xaf, 0x3e, // symbols 56-63
    0xfe, 0x61, 0x75, 0x5d, 0x51, 0x27, 0xa2, 0x38, // symbols 64-71
};



static constexpr uint8_t mss_x8dramSparePort0Index_to_symbol[MSS_X8_STEER_OPTIONS_PER_PORT] =
{
    // symbol
    MSS_INVALID_SYMBOL,    // Port0 DRAM spare not used
    68,      // DRAM 17 (x8)
    64,      // DRAM 16 (x8)
    60,      // DRAM 15 (x8)
    56,      // DRAM 14 (x8)
    52,      // DRAM 13 (x8)
    48,      // DRAM 12 (x8)
    44,      // DRAM 11 (x8)
    40,      // DRAM 10 (x8)
    4
};      // DRAM 1 (x8)

static constexpr uint8_t mss_x4dramSparePort0Index_to_symbol[MSS_X4_STEER_OPTIONS_PER_PORT0] =
{
    // symbol
    MSS_INVALID_SYMBOL,   // Port0 DRAM spare not used
    70,     // DRAM 35 (x4)
    68,     // DRAM 34 (x4)
    66,     // DRAM 33 (x4)
    64,     // DRAM 32 (x4)
    62,     // DRAM 31 (x4)
    60,     // DRAM 30 (x4)
    58,     // DRAM 29 (x4)
    56,     // DRAM 28 (x4)
    54,     // DRAM 27 (x4)
    52,     // DRAM 26 (x4)
    50,     // DRAM 25 (x4)
    48,     // DRAM 24 (x4)
    46,     // DRAM 23 (x4)
    44,     // DRAM 22 (x4)
    42,     // DRAM 21 (x4)
    40,     // DRAM 20 (x4)
    6,      // DRAM 3 (x4)
    4
};     // DRAM 2 (x4)



static constexpr uint8_t mss_x8dramSparePort1Index_to_symbol[MSS_X8_STEER_OPTIONS_PER_PORT] =
{
    // symbol
    MSS_INVALID_SYMBOL,    // Port1 DRAM spare not used
    36,      // DRAM 9 (x8)
    32,      // DRAM 8 (x8)
    28,      // DRAM 7 (x8)
    24,      // DRAM 6 (x8)
    20,      // DRAM 5 (x8)
    16,      // DRAM 4 (x8)
    12,      // DRAM 3 (x8)
    8,       // DRAM 2 (x8)
    0
};      // DRAM 0 (x8)



static constexpr uint8_t mss_x4dramSparePort1Index_to_symbol[MSS_X4_STEER_OPTIONS_PER_PORT1] =
{
    // symbol
    MSS_INVALID_SYMBOL,   // Port1 DRAM spare not used
    38,     // DRAM 19 (x4)
    36,     // DRAM 18 (x4)
    34,     // DRAM 17 (x4)
    32,     // DRAM 16 (x4)
    30,     // DRAM 15 (x4)
    28,     // DRAM 14 (x4)
    26,     // DRAM 13 (x4)
    24,     // DRAM 12 (x4)
    22,     // DRAM 11 (x4)
    20,     // DRAM 10 (x4)
    18,     // DRAM 9 (x4)
    16,     // DRAM 8 (x4)
    14,     // DRAM 7 (x4)
    12,     // DRAM 6 (x4)
    10,     // DRAM 5 (x4)
    8,      // DRAM 4 (x4)
    2
};     // DRAM 1 (x4)
// NOTE: DRAM 0 (x4) (symbols 0,1) on Port1 is used for the ECC spare,
// so can't use DRAM spare to fix DRAM 0.



static constexpr uint8_t mss_eccSpareIndex_to_symbol[MSS_X4_ECC_STEER_OPTIONS] =
{
    // symbol
    MSS_INVALID_SYMBOL,      // ECC spare not used
    70,        // DRAM 35 (x4)
    68,        // DRAM 34 (x4)
    66,        // DRAM 33 (x4)
    64,        // DRAM 32 (x4)
    62,        // DRAM 31 (x4)
    60,        // DRAM 30 (x4)
    58,        // DRAM 29 (x4)
    56,        // DRAM 28 (x4)
    54,        // DRAM 27 (x4)
    52,        // DRAM 26 (x4)
    50,        // DRAM 25 (x4)
    48,        // DRAM 24 (x4)
    46,        // DRAM 23 (x4)
    44,        // DRAM 22 (x4)
    42,        // DRAM 21 (x4)
    40,        // DRAM 20 (x4)
    38,        // DRAM 19 (x4)
    36,        // DRAM 18 (x4)
    34,        // DRAM 17 (x4)
    32,        // DRAM 16 (x4)
    30,        // DRAM 15 (x4)
    28,        // DRAM 14 (x4)
    26,        // DRAM 13 (x4)
    24,        // DRAM 12 (x4)
    22,        // DRAM 11 (x4)
    20,        // DRAM 10 (x4)
    18,        // DRAM 9 (x4)
    16,        // DRAM 8 (x4)
    14,        // DRAM 7 (x4)
    12,        // DRAM 6 (x4)
    10,        // DRAM 5 (x4)
    8,         // DRAM 4 (x4)
    6,         // DRAM 3 (x4)
    4,         // DRAM 2 (x4)
    2
};        // DRAM 1 (x4)
// NOTE: DRAM 0 (x4) (symbols 0,1) used for the ECC spare.
// NOTE: Can't use ECC spare to fix bad spare DRAMs on Port0 or Port1

constexpr uint8_t NUM_DRAM_WIDTHS = 2; //0=x8 1=x4
constexpr uint8_t NUM_BEATS = 16; //   8 on port 0,2     8 on port 1,3
constexpr uint8_t NUM_WORDS = 2;

static constexpr uint32_t mss_maintBufferData[NUM_DRAM_WIDTHS][MSS_MAX_PATTERNS][NUM_BEATS][NUM_WORDS] =
{
    /*
    ---Pattern 00
    Pattern sent to encoder (x8 mode):
        port0,2           port1,3
    t0  0000000000000000 0000000000000000
    t1  0000000000000000 0000000000000000
    t2  0000000000000000 0000000000000000
    t3  0000000000000000 0000000000000000 MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
    t4  0000000000000000 0000000000000000
    t5  0000000000000000 0000000000000000
    t6  0000000000000000 0000000000000000
    t7  0000000000000000 0000000000000000 MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
    */

// PATTERN_0
    // port0,2
    {   {   {0x00000000, 0x00000000}, // DW0
            {0x00000000, 0x00000000}, // DW2
            {0x00000000, 0x00000000}, // DW4
            {0x00000000, 0x00000000}, // DW6
            {0x00000000, 0x00000000}, // DW8
            {0x00000000, 0x00000000}, // DW10
            {0x00000000, 0x00000000}, // DW12
            {0x00000000, 0x00000000}, // DW14
            // port1,3
            {0x00000000, 0x00000000}, // DW1
            {0x00000000, 0x00000000}, // DW3
            {0x00000000, 0x00000000}, // DW5
            {0x00000000, 0x00000000}, // DW7
            {0x00000000, 0x00000000}, // DW9
            {0x00000000, 0x00000000}, // DW11
            {0x00000000, 0x00000000}, // DW13
            {0x00000000, 0x00000000}
        },// DW15


        /*
        ---Pattern 1
        Pattern sent to encoder (x8 mode):
            port0,2           port1,3
        t0  ffffffffffffffff ffffffffffffffff
        t1  ffffffffffffffff ffffffffffffffff
        t2  ffffffffffffffff ffffffffffffffff
        t3  ffffffffffffffff ffffffffffffffff MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        t4  ffffffffffffffff ffffffffffffffff
        t5  ffffffffffffffff ffffffffffffffff
        t6  ffffffffffffffff ffffffffffffffff
        t7  ffffffffffffffff ffffffffffffffff MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        */

// PATTERN_1
        // port0,2
        {   {0xffffffff, 0xffffffff}, // DW0
            {0xffffffff, 0xffffffff}, // DW2
            {0xffffffff, 0xffffffff}, // DW4
            {0xffffffff, 0xffffffff}, // DW6
            {0xffffffff, 0xffffffff}, // DW8
            {0xffffffff, 0xffffffff}, // DW10
            {0xffffffff, 0xffffffff}, // DW12
            {0xffffffff, 0xffffffff}, // DW14
            // port1,3
            {0xffffffff, 0xffffffff}, // DW1
            {0xffffffff, 0xffffffff}, // DW3
            {0xffffffff, 0xffffffff}, // DW5
            {0xffffffff, 0xffffffff}, // DW7
            {0xffffffff, 0xffffffff}, // DW9
            {0xffffffff, 0xffffffff}, // DW11
            {0xffffffff, 0xffffffff}, // DW13
            {0xffffffff, 0xffffffff}
        },// DW15


        /*---Pattern 2
        Pattern sent to encoder (x8 mode):
            port0,2           port1,3
        t0  6789555555555555 5555555555555555
        t1  6f2eaaaaaaaaaaaa aaaaaaaaaaaaaaaa
        t2  ae79555555555555 5555555555555555
        t3  84edaaaaaaaaaaaa aaaaaaaaaaaaaaaa MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        t4  545eaaaaaaaaaaaa aaaaaaaaaaaaaaaa
        t5  a791555555555555 5555555555555555
        t6  6622aaaaaaaaaaaa aaaaaaaaaaaaaaaa
        t7  f7f8555555555555 5555555555555555 MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        */

// PATTERN_2
        // port0,2
        {   {0x67895555, 0x55555555}, // DW0
            {0x6f2eaaaa, 0xaaaaaaaa}, // DW2
            {0xae795555, 0x55555555}, // DW4
            {0x84edaaaa, 0xaaaaaaaa}, // DW6
            {0x545eaaaa, 0xaaaaaaaa}, // DW8
            {0xa7915555, 0x55555555}, // DW10
            {0x6622aaaa, 0xaaaaaaaa}, // DW12
            {0xf7f85555, 0x55555555}, // DW14
            // port1,3
            {0x55555555, 0x55555555}, // DW1
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW3
            {0x55555555, 0x55555555}, // DW5
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW7
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW9
            {0x55555555, 0x55555555}, // DW11
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW13
            {0x55555555, 0x55555555}
        },// DW15

        /*
        ---Pattern 3
        Pattern sent to encoder (x8 mode):
            port0,2           port1,3
        t0  aaaaaac47aaaaaaa aaaaaaaaaaaaaaaa
        t1  555555abf1555555 5555555555555555
        t2  aaaaaa01aeaaaaaa aaaaaaaaaaaaaaaa
        t3  5555550c81555555 5555555555555555 MDI= (0,0), tag(0,1,2,3) = (1,1,1,1)
        t4  5555557a7f555555 5555555555555555
        t5  aaaaaaccafaaaaaa aaaaaaaaaaaaaaaa
        t6  555555456d555555 5555555555555555
        t7  aaaaaa21deaaaaaa aaaaaaaaaaaaaaaa MDI= (1,1), tag(0,1,2,3) = (0,0,0,0)
        */

// PATTERN_3
        // port0,2
        {   {0xaaaaaac4, 0x7aaaaaaa}, // DW0
            {0x555555ab, 0xf1555555}, // DW2
            {0xaaaaaa01, 0xaeaaaaaa}, // DW4
            {0x5555550c, 0x81555555}, // DW6
            {0x5555557a, 0x7f555555}, // DW8
            {0xaaaaaacc, 0xafaaaaaa}, // DW10
            {0x55555545, 0x6d555555}, // DW12
            {0xaaaaaa21, 0xdeaaaaaa}, // DW14
            // port1,3
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW1
            {0x55555555, 0x55555555}, // DW3
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW5
            {0x55555555, 0x55555555}, // DW7
            {0x55555555, 0x55555555}, // DW9
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW11
            {0x55555555, 0x55555555}, // DW13
            {0xaaaaaaaa, 0xaaaaaaaa}
        },// DW15

        /*
        ---Pattern 4
        Pattern sent to encoder (x8 mode):
            port0,2           port1,3
        t0  ffffffffffff8403 ffffffffffffffff
        t1  ffffffffffff83d3 ffffffffffffffff
        t2  ffffffffffffbf89 ffffffffffffffff
        t3  ffffffffffff1133 ffffffffffffffff MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
        t4  000000000000006c 0000000000000000
        t5  000000000000468a 0000000000000000
        t6  000000000000cf7e 0000000000000000
        t7  ffffffffffff6d37 ffffffffffffffff MDI= (1,0), tag(0,1,2,3) = (1,1,1,0)
        */

// PATTERN_4
        // port0,2
        {   {0xffffffff, 0xffff8403}, // DW0
            {0xffffffff, 0xffff83d3}, // DW2
            {0xffffffff, 0xffffbf89}, // DW4
            {0xffffffff, 0xffff1133}, // DW6
            {0x00000000, 0x0000006c}, // DW8
            {0x00000000, 0x0000468a}, // DW10
            {0x00000000, 0x0000cf7e}, // DW12
            {0xffffffff, 0xffff6d37}, // DW14
            // port1,3
            {0xffffffff, 0xffffffff}, // DW1
            {0xffffffff, 0xffffffff}, // DW3
            {0xffffffff, 0xffffffff}, // DW5
            {0xffffffff, 0xffffffff}, // DW7
            {0x00000000, 0x00000000}, // DW9
            {0x00000000, 0x00000000}, // DW11
            {0x00000000, 0x00000000}, // DW13
            {0xffffffff, 0xffffffff}
        },// DW15

        /*
        ---Pattern 5
        Pattern sent to encoder (x8 mode):
            port0,2           port1,3
        t0  0000000000000000 0000000006c00000
        t1  0000000000000000 0000000068f40000
        t2  0000000000000000 00000000701c0000
        t3  0000000000000000 00000000f7640000 MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        t4  ffffffffffffffff ffffffffe523ffff
        t5  ffffffffffffffff ffffffff5603ffff
        t6  ffffffffffffffff fffffffffeb5ffff
        t7  0000000000000000 0000000098a40000 MDI= (0,1), tag(0,1,2,3) = (0,0,0,1)
        */

// PATTERN_5
        // port0,2
        {   {0x00000000, 0x00000000}, // DW0
            {0x00000000, 0x00000000}, // DW2
            {0x00000000, 0x00000000}, // DW4
            {0x00000000, 0x00000000}, // DW6
            {0xffffffff, 0xffffffff}, // DW8
            {0xffffffff, 0xffffffff}, // DW10
            {0xffffffff, 0xffffffff}, // DW12
            {0x00000000, 0x00000000}, // DW14
            // port1,3
            {0x00000000, 0x06c00000}, // DW1
            {0x00000000, 0x68f40000}, // DW3
            {0x00000000, 0x701c0000}, // DW5
            {0x00000000, 0xf7640000}, // DW7
            {0xffffffff, 0xe523ffff}, // DW9
            {0xffffffff, 0x5603ffff}, // DW11
            {0xffffffff, 0xfeb5ffff}, // DW13
            {0x00000000, 0x98a40000}
        },// DW15

        /*
        ---Pattern 6
        Pattern sent to encoder (x8 mode):
            port0,2           port1,3
        t0  ffffffffffffffff ffffffffceb3ffff
        t1  0000000000000000 0000000034460000
        t2  ffffffffffffffff ffffffffb1afffff
        t3  0000000000000000 00000000fd080000 MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
        t4  0000000000000000 0000000037540000
        t5  ffffffffffffffff ffffffff3443ffff
        t6  0000000000000000 000000001a260000
        t7  ffffffffffffffff ffffffff3f3fffff MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
        */

// PATTERN_6
        // port0,2
        {   {0xffffffff, 0xffffffff}, // DW0
            {0x00000000, 0x00000000}, // DW2
            {0xffffffff, 0xffffffff}, // DW4
            {0x00000000, 0x00000000}, // DW6
            {0x00000000, 0x00000000}, // DW8
            {0xffffffff, 0xffffffff}, // DW10
            {0x00000000, 0x00000000}, // DW12
            {0xffffffff, 0xffffffff}, // DW14
            // port1,3
            {0xffffffff, 0xceb3ffff}, // DW1
            {0x00000000, 0x34460000}, // DW3
            {0xffffffff, 0xb1afffff}, // DW5
            {0x00000000, 0xfd080000}, // DW7
            {0x00000000, 0x37540000}, // DW9
            {0xffffffff, 0x3443ffff}, // DW11
            {0x00000000, 0x1a260000}, // DW13
            {0xffffffff, 0x3f3fffff}
        },// DW15

        /*
        ---Pattern 7
        Pattern sent to encoder (x8 mode):
            port0,2           port1,3
        t0  83dc000000000000 0000000000000000
        t1  d4b7ffffffffffff ffffffffffffffff
        t2  8c2c000000000000 0000000000000000
        t3  5d8affffffffffff ffffffffffffffff MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
        t4  ec57ffffffffffff ffffffffffffffff
        t5  a9d4000000000000 0000000000000000
        t6  8447ffffffffffff ffffffffffffffff
        t7  eafe000000000000 0000000000000000 MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
        */

// PATTERN_7
        // port0,2
        {   {0x83dc0000, 0x00000000}, // DW0
            {0xd4b7ffff, 0xffffffff}, // DW2
            {0x8c2c0000, 0x00000000}, // DW4
            {0x5d8affff, 0xffffffff}, // DW6
            {0xec57ffff, 0xffffffff}, // DW8
            {0xa9d40000, 0x00000000}, // DW10
            {0x8447ffff, 0xffffffff}, // DW12
            {0xeafe0000, 0x00000000}, // DW14
            // port1,3
            {0x00000000, 0x00000000}, // DW1
            {0xffffffff, 0xffffffff}, // DW3
            {0x00000000, 0x00000000}, // DW5
            {0xffffffff, 0xffffffff}, // DW7
            {0xffffffff, 0xffffffff}, // DW9
            {0x00000000, 0x00000000}, // DW11
            {0xffffffff, 0xffffffff}, // DW13
            {0x00000000, 0x00000000}
        },// DW15

// PATTERN_8: random seed
        {   {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678}
        }
    },


    /*
    ---Pattern 00
    Pattern sent to encoder (x4 mode):
        port0,2           port1,3
    t0  0000000000000000 0000000000000000
    t1  0000000000000000 0000000000000000
    t2  0000000000000000 0000000000000000
    t3  0000000000000000 0000000000000000 MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
    t4  0000000000000000 0000000000000000
    t5  0000000000000000 0000000000000000
    t6  0000000000000000 0000000000000000
    t7  0000000000000000 0000000000000000 MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
    */

// PATTERN_0
    // port0,2
    {   {   {0x00000000, 0x00000000}, // DW0
            {0x00000000, 0x00000000}, // DW2
            {0x00000000, 0x00000000}, // DW4
            {0x00000000, 0x00000000}, // DW6
            {0x00000000, 0x00000000}, // DW8
            {0x00000000, 0x00000000}, // DW10
            {0x00000000, 0x00000000}, // DW12
            {0x00000000, 0x00000000}, // DW14
            // port1,3
            {0x00000000, 0x00000000}, // DW1
            {0x00000000, 0x00000000}, // DW3
            {0x00000000, 0x00000000}, // DW5
            {0x00000000, 0x00000000}, // DW7
            {0x00000000, 0x00000000}, // DW9
            {0x00000000, 0x00000000}, // DW11
            {0x00000000, 0x00000000}, // DW13
            {0x00000000, 0x00000000}
        },// DW15


        /*
        ---Pattern 1
        Pattern sent to encoder (x4 mode):
            port0,2           port1,3
        t0  ffffffffffffffff ffffffffffffffff
        t1  ffffffffffffffff ffffffffffffffff
        t2  ffffffffffffffff ffffffffffffffff
        t3  ffffffffffffffff ffffffffffffffff MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        t4  ffffffffffffffff ffffffffffffffff
        t5  ffffffffffffffff ffffffffffffffff
        t6  ffffffffffffffff ffffffffffffffff
        t7  ffffffffffffffff ffffffffffffffff MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        */

// PATTERN_1
        // port0,2
        {   {0xffffffff, 0xffffffff}, // DW0
            {0xffffffff, 0xffffffff}, // DW2
            {0xffffffff, 0xffffffff}, // DW4
            {0xffffffff, 0xffffffff}, // DW6
            {0xffffffff, 0xffffffff}, // DW8
            {0xffffffff, 0xffffffff}, // DW10
            {0xffffffff, 0xffffffff}, // DW12
            {0xffffffff, 0xffffffff}, // DW14
            // port1,3
            {0xffffffff, 0xffffffff}, // DW1
            {0xffffffff, 0xffffffff}, // DW3
            {0xffffffff, 0xffffffff}, // DW5
            {0xffffffff, 0xffffffff}, // DW7
            {0xffffffff, 0xffffffff}, // DW9
            {0xffffffff, 0xffffffff}, // DW11
            {0xffffffff, 0xffffffff}, // DW13
            {0xffffffff, 0xffffffff}
        },// DW15


        /*---Pattern 2
        Pattern sent to encoder (x4 mode):
            port0,2           port1,3
        t0  5055555555555555 5555555555555555
        t1  a96aaaaaaaaaaaaa aaaaaaaaaaaaaaaa
        t2  6215555555555555 5555555555555555
        t3  dd5aaaaaaaaaaaaa aaaaaaaaaaaaaaaa MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        t4  89eaaaaaaaaaaaaa aaaaaaaaaaaaaaaa
        t5  7fd5555555555555 5555555555555555
        t6  b32aaaaaaaaaaaaa aaaaaaaaaaaaaaaa
        t7  acc5555555555555 5555555555555555 MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        */

// PATTERN_2
        // port0,2
        {   {0x50555555, 0x55555555}, // DW0
            {0xa96aaaaa, 0xaaaaaaaa}, // DW2
            {0x62155555, 0x55555555}, // DW4
            {0xdd5aaaaa, 0xaaaaaaaa}, // DW6
            {0x89eaaaaa, 0xaaaaaaaa}, // DW8
            {0x7fd55555, 0x55555555}, // DW10
            {0xb32aaaaa, 0xaaaaaaaa}, // DW12
            {0xacc55555, 0x55555555}, // DW14
            // port1,3
            {0x55555555, 0x55555555}, // DW1
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW3
            {0x55555555, 0x55555555}, // DW5
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW7
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW9
            {0x55555555, 0x55555555}, // DW11
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW13
            {0x55555555, 0x55555555}
        },// DW15

        /*
        ---Pattern 3
        Pattern sent to encoder (x4 mode):
            port0,2           port1,3
        t0  aaaaaab7caaaaaaa aaaaaaaaaaaaaaaa
        t1  555555f2d5555555 5555555555555555
        t2  aaaaaad8aaaaaaaa aaaaaaaaaaaaaaaa
        t3  5555552495555555 5555555555555555 MDI= (0,0), tag(0,1,2,3) = (1,1,1,1)
        t4  55555540b5555555 5555555555555555
        t5  aaaaaa04baaaaaaa aaaaaaaaaaaaaaaa
        t6  555555c095555555 5555555555555555
        t7  aaaaaa956aaaaaaa aaaaaaaaaaaaaaaa MDI= (1,1), tag(0,1,2,3) = (0,0,0,0)
        */

// PATTERN_3
        // port0,2
        {   {0xaaaaaab7, 0xcaaaaaaa}, // DW0
            {0x555555f2, 0xd5555555}, // DW2
            {0xaaaaaad8, 0xaaaaaaaa}, // DW4
            {0x55555524, 0x95555555}, // DW6
            {0x55555540, 0xb5555555}, // DW8
            {0xaaaaaa04, 0xbaaaaaaa}, // DW10
            {0x555555c0, 0x95555555}, // DW12
            {0xaaaaaa95, 0x6aaaaaaa}, // DW14
            // port1,3
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW1
            {0x55555555, 0x55555555}, // DW3
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW5
            {0x55555555, 0x55555555}, // DW7
            {0x55555555, 0x55555555}, // DW9
            {0xaaaaaaaa, 0xaaaaaaaa}, // DW11
            {0x55555555, 0x55555555}, // DW13
            {0xaaaaaaaa, 0xaaaaaaaa}
        },// DW15

        /*
        ---Pattern 4
        Pattern sent to encoder (x4 mode):
            port0,2           port1,3
        t0  ffffffffffff93ff ffffffffffffffff
        t1  ffffffffffffb5bf ffffffffffffffff
        t2  ffffffffffff207f ffffffffffffffff
        t3  ffffffffffffb37f ffffffffffffffff MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
        t4  0000000000002340 0000000000000000
        t5  00000000000062e0 0000000000000000
        t6  0000000000006740 0000000000000000
        t7  ffffffffffff6a3f ffffffffffffffff MDI= (1,0), tag(0,1,2,3) = (1,1,1,0)
        */

// PATTERN_4
        // port0,2
        {   {0xffffffff, 0xffff93ff}, // DW0
            {0xffffffff, 0xffffb5bf}, // DW2
            {0xffffffff, 0xffff207f}, // DW4
            {0xffffffff, 0xffffb37f}, // DW6
            {0x00000000, 0x00002340}, // DW8
            {0x00000000, 0x000062e0}, // DW10
            {0x00000000, 0x00006740}, // DW12
            {0xffffffff, 0xffff6a3f}, // DW14
            // port1,3
            {0xffffffff, 0xffffffff}, // DW1
            {0xffffffff, 0xffffffff}, // DW3
            {0xffffffff, 0xffffffff}, // DW5
            {0xffffffff, 0xffffffff}, // DW7
            {0x00000000, 0x00000000}, // DW9
            {0x00000000, 0x00000000}, // DW11
            {0x00000000, 0x00000000}, // DW13
            {0xffffffff, 0xffffffff}
        },// DW15

        /*
        ---Pattern 5
        Pattern sent to encoder (x4 mode):
            port0,2           port1,3
        t0  0000000000000000 0000000090c00000
        t1  0000000000000000 00000000b0400000
        t2  0000000000000000 0000000087a00000
        t3  0000000000000000 0000000033000000 MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        t4  ffffffffffffffff ffffffff9dbfffff
        t5  ffffffffffffffff ffffffffa69fffff
        t6  ffffffffffffffff ffffffff257fffff
        t7  0000000000000000 00000000c7400000 MDI= (0,1), tag(0,1,2,3) = (0,0,0,1)
        */

// PATTERN_5
        // port0,2
        {   {0x00000000, 0x00000000}, // DW0
            {0x00000000, 0x00000000}, // DW2
            {0x00000000, 0x00000000}, // DW4
            {0x00000000, 0x00000000}, // DW6
            {0xffffffff, 0xffffffff}, // DW8
            {0xffffffff, 0xffffffff}, // DW10
            {0xffffffff, 0xffffffff}, // DW12
            {0x00000000, 0x00000000}, // DW14
            // port1,3
            {0x00000000, 0x90c00000}, // DW1
            {0x00000000, 0xb0400000}, // DW3
            {0x00000000, 0x87a00000}, // DW5
            {0x00000000, 0x33000000}, // DW7
            {0xffffffff, 0x9dbfffff}, // DW9
            {0xffffffff, 0xa69fffff}, // DW11
            {0xffffffff, 0x257fffff}, // DW13
            {0x00000000, 0xc7400000}
        },// DW15

        /*
        ---Pattern 6
        Pattern sent to encoder (x4 mode):
            port0,2           port1,3
        t0  ffffffffffffffff ffffffff7e3fffff
        t1  0000000000000000 0000000018c00000
        t2  ffffffffffffffff ffffffffc8bfffff
        t3  0000000000000000 000000006b800000 MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
        t4  0000000000000000 00000000f2800000
        t5  ffffffffffffffff ffffffff659fffff
        t6  0000000000000000 00000000c5c00000
        t7  ffffffffffffffff ffffffff473fffff MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
        */

// PATTERN_6
        // port0,2
        {   {0xffffffff, 0xffffffff}, // DW0
            {0x00000000, 0x00000000}, // DW2
            {0xffffffff, 0xffffffff}, // DW4
            {0x00000000, 0x00000000}, // DW6
            {0x00000000, 0x00000000}, // DW8
            {0xffffffff, 0xffffffff}, // DW10
            {0x00000000, 0x00000000}, // DW12
            {0xffffffff, 0xffffffff}, // DW14
            // port1,3
            {0xffffffff, 0x7e3fffff}, // DW1
            {0x00000000, 0x18c00000}, // DW3
            {0xffffffff, 0xc8bfffff}, // DW5
            {0x00000000, 0x6b800000}, // DW7
            {0x00000000, 0xf2800000}, // DW9
            {0xffffffff, 0x659fffff}, // DW11
            {0x00000000, 0xc5c00000}, // DW13
            {0xffffffff, 0x473fffff}
        },// DW15

        /*
        ---Pattern 7
        Pattern sent to encoder (x4 mode):
            port0,2           port1,3
        t0  8200000000000000 0000000000000000
        t1  d3bfffffffffffff ffffffffffffffff
        t2  d080000000000000 0000000000000000
        t3  539fffffffffffff ffffffffffffffff MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
        t4  63ffffffffffffff ffffffffffffffff
        t5  d640000000000000 0000000000000000
        t6  5c3fffffffffffff ffffffffffffffff
        t7  dcb0000000000000 0000000000000000 MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
        */

// PATTERN_7
        // port0,2
        {   {0x82000000, 0x00000000}, // DW0
            {0xd3bfffff, 0xffffffff}, // DW2
            {0xd0800000, 0x00000000}, // DW4
            {0x539fffff, 0xffffffff}, // DW6
            {0x63ffffff, 0xffffffff}, // DW8
            {0xd6400000, 0x00000000}, // DW10
            {0x5c3fffff, 0xffffffff}, // DW12
            {0xdcb00000, 0x00000000}, // DW14
            // port1,3
            {0x00000000, 0x00000000}, // DW1
            {0xffffffff, 0xffffffff}, // DW3
            {0x00000000, 0x00000000}, // DW5
            {0xffffffff, 0xffffffff}, // DW7
            {0xffffffff, 0xffffffff}, // DW9
            {0x00000000, 0x00000000}, // DW11
            {0xffffffff, 0xffffffff}, // DW13
            {0x00000000, 0x00000000}
        },// DW15

// PATTERN_8: random seed
        {   {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678},
            {0x12345678, 0x87654321},
            {0x87654321, 0x12345678}
        }
    }
};


constexpr uint8_t NUM_LOOPS_FOR_65TH_BYTE = 4;


static constexpr uint8_t mss_65thByte[NUM_DRAM_WIDTHS][MSS_MAX_PATTERNS][NUM_LOOPS_FOR_65TH_BYTE] =
{


// bit1=tag0_2, bit2=tag1_3, bit3=MDI

// PATTERN_0 (x8 mode)

    // MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
    {   {
            0x00,   // 1st 64B of cachline: tag0=0, tag1=0, MDI=0
            0x00,   // 1st 64B of cachline: tag2=0, tag3=0, MDI=0
            // MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
            0x00,   // 2nd 64B of cachline: tag0=0, tag1=0, MDI=0
            0x00
        },  // 2nd 64B of cachline: tag2=0, tag3=0, MDI=0

// PATTERN_1 (x8 mode)

        // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        {
            0xF0,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=1
            0x70,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=1
            // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
            0x70,   // 2nd 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0
        },  // 2nd 64B of cachline: tag2=1, tag3=1, MDI=1

// PATTERN_2 (x8 mode)

        // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        {
            0xF0,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=1
            // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
            0xF0,   // 2nd 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0
        },  // 2nd 64B of cachline: tag2=1, tag3=1, MDI=1

// PATTERN_3 (x8 mode)
        // MDI= (0,0), tag(0,1,2,3) = (1,1,1,1)
        {
            0x60,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=0
            0x60,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=0
            // MDI= (1,1), tag(0,1,2,3) = (0,0,0,0)
            0x90,   // 2nd 64B of cachline: tag0=0, tag1=0, MDI=1
            0x90
        },  // 2nd 64B of cachline: tag2=0, tag3=0, MDI=1

// PATTERN_4 (x8 mode)
        // MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
        {
            0x00,   // 1st 64B of cachline: tag0=0, tag1=0, MDI=0
            0x00,   // 1st 64B of cachline: tag2=0, tag3=0, MDI=0
            // MDI= (1,0), tag(0,1,2,3) = (1,1,1,0)
            0xF0,   // 2nd 64B of cachline: tag0=1, tag1=1, MDI=1
            0xC0
        },  // 2nd 64B of cachline: tag2=1, tag3=0, MDI=0

// PATTERN_5 (x8 mode)
        // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        {
            0xF0,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=1
            // MDI= (0,1), tag(0,1,2,3) = (0,0,0,1)
            0x00,   // 2nd 64B of cachline: tag0=0, tag1=0, MDI=0
            0x10
        },  // 2nd 64B of cachline: tag2=0, tag3=1, MDI=1

// PATTERN_6 (x8 mode)
        // MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
        {
            0x30,   // 1st 64B of cachline: tag0=0, tag1=1, MDI=1
            0x30,   // 1st 64B of cachline: tag2=0, tag3=1, MDI=1
            // MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
            0xC0,   // 2nd 64B of cachline: tag0=1, tag1=0, MDI=0
            0xC0
        },  // 2nd 64B of cachline: tag2=1, tag3=0, MDI=0

// PATTERN_7 (x8 mode)
        // MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
        {
            0xC0,   // 1st 64B of cachline: tag0=1, tag1=0, MDI=0
            0xC0,   // 1st 64B of cachline: tag2=1, tag3=0, MDI=0
            // MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
            0x30,   // 2nd 64B of cachline: tag0=0, tag1=1, MDI=1
            0x30
        },  // 2nd 64B of cachline: tag2=0, tag3=1, MDI=1

// PATTERN_8: random seed  (x8 mode)
        {
            0x20,   // 1st 64B of cachline: tag0=0, tag1=1, MDI=0
            0x60,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=0
            0x30,   // 2nd 64B of cachline: tag0=0, tag1=1, MDI=1
            0x70
        }
    }, // 2nd 64B of cachline: tag2=1, tag3=1, MDI=1




// bit1=tag0_2, bit2=tag1_3, bit3=MDI

// PATTERN_0 (x4 mode)

    // MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
    {   {
            0x00,   // 1st 64B of cachline: tag0=0, tag1=0, MDI=0
            0x00,   // 1st 64B of cachline: tag2=0, tag3=0, MDI=0
            // MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
            0x00,   // 2nd 64B of cachline: tag0=0, tag1=0, MDI=0
            0x00
        },  // 2nd 64B of cachline: tag2=0, tag3=0, MDI=0

// PATTERN_1 (x4 mode)

        // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        {
            0xF0,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=1
            // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
            0xF0,   // 2nd 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0
        },  // 2nd 64B of cachline: tag2=1, tag3=1, MDI=1

// PATTERN_2 (x4 mode)

        // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        {
            0xF0,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=1
            // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
            0xF0,   // 2nd 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0
        },  // 2nd 64B of cachline: tag2=1, tag3=1, MDI=1

// PATTERN_3 (x4 mode)
        // MDI= (0,0), tag(0,1,2,3) = (1,1,1,1)
        {
            0x60,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=0
            0x60,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=0
            // MDI= (1,1), tag(0,1,2,3) = (0,0,0,0)
            0x90,   // 2nd 64B of cachline: tag0=0, tag1=0, MDI=1
            0x90
        },  // 2nd 64B of cachline: tag2=0, tag3=0, MDI=1

// PATTERN_4 (x4 mode)
        // MDI= (0,0), tag(0,1,2,3) = (0,0,0,0)
        {
            0x00,   // 1st 64B of cachline: tag0=0, tag1=0, MDI=0
            0x00,   // 1st 64B of cachline: tag2=0, tag3=0, MDI=0
            // MDI= (1,0), tag(0,1,2,3) = (1,1,1,0)
            0xF0,   // 2nd 64B of cachline: tag0=1, tag1=1, MDI=1
            0xC0
        },  // 2nd 64B of cachline: tag2=1, tag3=0, MDI=0

// PATTERN_5 (x4 mode)
        // MDI= (1,1), tag(0,1,2,3) = (1,1,1,1)
        {
            0xF0,   // 1st 64B of cachline: tag0=1, tag1=1, MDI=1
            0xF0,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=1
            // MDI= (0,1), tag(0,1,2,3) = (0,0,0,1)
            0x80,   // 2nd 64B of cachline: tag0=0, tag1=0, MDI=0
            0x10
        },  // 2nd 64B of cachline: tag2=0, tag3=1, MDI=1

// PATTERN_6 (x4 mode)
        // MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
        {
            0x30,   // 1st 64B of cachline: tag0=0, tag1=1, MDI=1
            0x30,   // 1st 64B of cachline: tag2=0, tag3=1, MDI=1
            // MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
            0xC0,   // 2nd 64B of cachline: tag0=1, tag1=0, MDI=0
            0xC0
        },  // 2nd 64B of cachline: tag2=1, tag3=0, MDI=0

// PATTERN_7 (x4 mode)
        // MDI= (0,0), tag(0,1,2,3) = (1,0,1,0)
        {
            0xC0,   // 1st 64B of cachline: tag0=1, tag1=0, MDI=0
            0xC0,   // 1st 64B of cachline: tag2=1, tag3=0, MDI=0
            // MDI= (1,1), tag(0,1,2,3) = (0,1,0,1)
            0x30,   // 2nd 64B of cachline: tag0=0, tag1=1, MDI=1
            0x30
        },  // 2nd 64B of cachline: tag2=0, tag3=1, MDI=1

// PATTERN_8: random seed  (x8 mode)
        {
            0x20,   // 1st 64B of cachline: tag0=0, tag1=1, MDI=0
            0x60,   // 1st 64B of cachline: tag2=1, tag3=1, MDI=0
            0x30,   // 2nd 64B of cachline: tag0=0, tag1=1, MDI=1
            0x70
        }
    }
};// 2nd 64B of cachline: tag2=1, tag3=1, MDI=1


static constexpr uint32_t mss_ECC[NUM_DRAM_WIDTHS][MSS_MAX_PATTERNS][NUM_LOOPS_FOR_65TH_BYTE] =
{

// bit 4:15 ECC_c6_c5_c4, bit 16:31 ECC_c3_c2_c1_c0

// PATTERN_0 (x8 mode)
    {   {
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 2nd 64B of cachline
            0x00000000
        },  // 2nd 64B of cachline

// PATTERN_1 (x8 mode)
        {
            0x0DA49500,   // 1st 64B of cachline
            0x0234A60E,   // 1st 64B of cachline
            0x0DA49500,   // 2nd 64B of cachline
            0x0234A60E
        },  // 2nd 64B of cachline

// PATTERN_2 (x8 mode)
        {
            0x0FFFFFFF,   // 1st 64B of cachline
            0x0FFFFFFF,   // 1st 64B of cachline
            0x0FFFFFFF,   // 2nd 64B of cachline
            0x0FFFFFFF
        },  // 2nd 64B of cachline

// PATTERN_3 (x8 mode)
        {
            0x056A55AA,   // 1st 64B of cachline
            0x056A55AA,   // 1st 64B of cachline
            0x0A95AA55,   // 2nd 64B of cachline
            0x0A95AA55
        },  // 2nd 64B of cachline

// PATTERN_4 (x8 mode)
        {
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 1st 64B of cachline
            0x0FFFFFFF,   // 2nd 64B of cachline
            0x0FC0FF00
        },  // 2nd 64B of cachline

// PATTERN_5 (x8 mode)
        {
            0x0FFFFFFF,   // 1st 64B of cachline
            0x0FFFFFFF,   // 1st 64B of cachline
            0x0ED81C6A,   // 2nd 64B of cachline
            0x0D970552
        },  // 2nd 64B of cachline

// PATTERN_6 (x8 mode)
        {
            0x003F00FF,   // 1st 64B of cachline
            0x003F00FF,   // 1st 64B of cachline
            0x0FC0FF00,   // 2nd 64B of cachline
            0x0FC0FF00
        },  // 2nd 64B of cachline

// PATTERN_7 (x8 mode)
        {
            0x0FC0FF00,   // 1st 64B of cachline
            0x0FC0FF00,   // 1st 64B of cachline
            0x003F00FF,   // 2nd 64B of cachline
            0x003F00FF
        },  // 2nd 64B of cachline

// PATTERN_8: random
        {
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 2nd 64B of cachline
            0x00000000
        }
    }, // 2nd 64B of cachline

// bit 4:15 ECC_c6_c5_c4, bit 16:31 ECC_c3_c2_c1_c0

// PATTERN_0 (x4 mode)
    {   {
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 2nd 64B of cachline
            0x00000000
        },  // 2nd 64B of cachline

// PATTERN_1 (x4 mode)
        {
            0x09978000,   // 1st 64B of cachline
            0x03DBC0C0,   // 1st 64B of cachline
            0x09978000,   // 2nd 64B of cachline
            0x03DBC0C0
        },  // 2nd 64B of cachline

// PATTERN_2 (x4 mode)
        {
            0x0FFFF0F0,   // 1st 64B of cachline
            0x0FFFF0F0,   // 1st 64B of cachline
            0x0FFFF0F0,   // 2nd 64B of cachline
            0x0FFFF0F0
        },  // 2nd 64B of cachline

// PATTERN_3 (x4 mode)
        {
            0x056A50A0,   // 1st 64B of cachline
            0x056A50A0,   // 1st 64B of cachline
            0x0A95A050,   // 2nd 64B of cachline
            0x0A95A050
        },  // 2nd 64B of cachline

// PATTERN_4 (x4 mode)
        {
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 1st 64B of cachline
            0x0FFFF0F0,   // 2nd 64B of cachline
            0x0FC0F000
        },  // 2nd 64B of cachline

// PATTERN_5 (x4 mode)
        {
            0x0FFFF0F0,   // 1st 64B of cachline
            0x0FFFF0F0,   // 1st 64B of cachline
            0x07BB8020,   // 2nd 64B of cachline
            0x07A4A0D0
        },  // 2nd 64B of cachline

// PATTERN_6 (x4 mode)
        {
            0x003F00F0,   // 1st 64B of cachline
            0x003F00F0,   // 1st 64B of cachline
            0x0FC0F000,   // 2nd 64B of cachline
            0x0FC0F000
        },  // 2nd 64B of cachline

// PATTERN_7 (x4 mode)
        {
            0x0FC0F000,   // 1st 64B of cachline
            0x0FC0F000,   // 1st 64B of cachline
            0x003F00F0,   // 2nd 64B of cachline
            0x003F00F0
        },  // 2nd 64B of cachline

// PATTERN_8: random
        {
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 1st 64B of cachline
            0x00000000,   // 2nd 64B of cachline
            0x00000000
        }
    }
};// 2nd 64B of cachline

//------------------------------------------------------------------------------
// Parent class
//------------------------------------------------------------------------------


///
/// @brief Constructor
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
/// @param[in] i_end_addr,        Address cmd will stop at
/// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
/// @param[in] i_poll            Set to true if you wait for command to complete
/// @param[in] i_cmd_type         Command type
///
mss_MaintCmd::mss_MaintCmd(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                           const fapi2::buffer<uint64_t>& i_start_addr,
                           const fapi2::buffer<uint64_t>& i_end_addr,
                           const uint32_t i_stop_condition,
                           const bool i_poll,
                           const CmdType i_cmd_type ) :
    iv_target( i_target ),
    iv_start_addr( i_start_addr ),
    iv_end_addr( i_end_addr ),
    iv_stop_condition( i_stop_condition),
    iv_poll (i_poll),
    iv_cmd_type(i_cmd_type) {}

///
/// @brief  Called once a command is done if we need to restore settings that
///         had to be modified to run a specific command type, or clear error
///         data in the hw that is no longer relevant.
///
/// @return SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::cleanupCmd()
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief  Stops running maint cmd, and saves the address it stopped at.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::stopCmd()
{
    fapi2::buffer<uint64_t> l_mbmsrq;
    fapi2::buffer<uint64_t> l_mbmccq;
    fapi2::buffer<uint64_t> l_mbmacaq;
    fapi2::buffer<uint64_t> l_mbspa_mask;
    fapi2::buffer<uint64_t> l_mbspa_mask_original;
    fapi2::buffer<uint64_t> l_mbspa_and;

    // 1 ms delay for HW mode -- LWM changed 100,000,000 to 1,000,000 to match comment
    constexpr uint64_t  HW_MODE_DELAY = DELAY_1MS;
    // 200000 sim cycle delay for SIM mode
    constexpr uint64_t  SIM_MODE_DELAY = DELAY_200000SIMCYCLES;
    uint32_t l_count = 0;
    uint32_t l_loop_limit = 10;

    FAPI_INF("ENTER mss_MaintCmd::stopCmd()");

    // Read MBSPA MASK
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBSPAMSKQ, l_mbspa_mask));
    // Save original mask value so we can restore it when done
    l_mbspa_mask_original.insert<0, 64, 0>(l_mbspa_mask);
    // Mask bits 0 and 8, to hide the special attentions when the cmd completes
    l_mbspa_mask.setBit<0>();
    l_mbspa_mask.setBit<8>();

    // Write MBSPA MASK
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBSPAMSKQ, l_mbspa_mask));
    // Read MBMSRQ
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMSRQ, l_mbmsrq));

    // If MBMSRQ[0], maint_cmd_in_progress, stop the cmd
    if (l_mbmsrq.getBit<0>())
    {
        // Read MBMCCQ
        FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCCQ, l_mbmccq));
        // Set bit 1 to force the cmd to stop
        l_mbmccq.setBit<1>();
        // Write MBMCCQ
        FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBMCCQ, l_mbmccq));

        // Loop to check for cmd in progress bit to turn off
        do
        {
            // Wait 1ms
            fapi2::delay(HW_MODE_DELAY, SIM_MODE_DELAY);
            // Read MBMSRQ
            FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMSRQ, l_mbmsrq));
            l_count++;
        }
        while (l_mbmsrq.getBit<0>() && (l_count < l_loop_limit));

        FAPI_ASSERT(!l_mbmsrq.getBit<0>(),
                    fapi2::CEN_MSS_MAINT_UNSUCCESSFUL_FORCED_MAINT_CMD_STOP().
                    set_MBA(iv_target).
                    set_MBMCC(l_mbmccq).
                    set_MBMSR(l_mbmsrq).
                    set_CMD_TYPE(iv_cmd_type),
                    "MBMSRQ[0] = 1, unsuccessful forced maint cmd stop on %s.",
                    mss::c_str(iv_target));

        // Clear MCMCC bit 1, just in case cmd was already stopped
        // before we set it, in which case, bit 1 would not have self cleared.
        l_mbmccq.clearBit<1>();
        // Write MBMCCQ
        FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBMCCQ, l_mbmccq));
    }

    // Store the address we stopped at in iv_start_addr
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMACAQ, iv_start_addr));

    // Only 0-36 are valid address bits so clear the rest, 37-63
    iv_start_addr.clearBit<VALID_BITS_IN_ADDR_STRING, 27>();

    // Clear bits 0 and 8 in MBSPA AND register
    l_mbspa_and.flush<1>();
    l_mbspa_and.clearBit<0>();
    l_mbspa_and.clearBit<8>();

    // Write MPSPA AND register
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBSPAQ_WOX_AND, l_mbspa_and));
    // Restore MBSPA MASK
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBSPAMSKQ, l_mbspa_mask_original));

    FAPI_INF("EXIT mss_MaintCmd::stopCmd()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Checks for valid hw state and setup required before a cmd is run.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::preConditionCheck()
{
    fapi2::buffer<uint64_t> l_mbmccq;
    fapi2::buffer<uint64_t> l_mbmsrq;
    fapi2::buffer<uint64_t> l_mbaxcr;
    fapi2::buffer<uint64_t> l_ccs_modeq;
    fapi2::buffer<uint64_t> l_mbsecc;
    fapi2::buffer<uint64_t> l_mbmct;

    FAPI_INF("ENTER mss_MaintCmd::preConditionCheck()");

    iv_targetCentaur = iv_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, iv_target,  iv_mbaPosition));
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCCQ, l_mbmccq));
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMSRQ, l_mbmsrq));
    FAPI_TRY(fapi2::getScom(iv_targetCentaur, mss_mbaxcr[iv_mbaPosition], l_mbaxcr));
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_CCS_MODEQ, l_ccs_modeq));
    FAPI_TRY(fapi2::getScom(iv_targetCentaur, mss_mbsecc[iv_mbaPosition], l_mbsecc));
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCTQ, l_mbmct));

    // Check for MBMCCQ[0], maint_cmd_start, to be reset by hw.
    FAPI_ASSERT(!l_mbmccq.getBit<0>(),
                fapi2::CEN_MSS_MAINT_START_NOT_RESET().
                set_MBA(iv_target).
                set_MBMCC(l_mbmccq).
                set_CMD_TYPE(iv_cmd_type).
                set_MBMCT(l_mbmct),
                "MBMCCQ[0]: maint_cmd_start not reset by hw on %s.", mss::c_str(iv_target));

    // Check for MBMCCQ[1], maint_cmd_stop, to be reset by hw.
    FAPI_ASSERT(!l_mbmccq.getBit<1>(),
                fapi2::CEN_MSS_MAINT_STOP_NOT_RESET().
                set_MBA(iv_target).
                set_MBMCC(l_mbmccq).
                set_CMD_TYPE(iv_cmd_type).
                set_MBMCT(l_mbmct),
                "MBMCCQ[1]: maint_cmd_stop not reset by hw on %s.", mss::c_str(iv_target));
    FAPI_ASSERT(!l_mbmsrq.getBit<0>(),
                fapi2::CEN_MSS_MAINT_CMD_IN_PROGRESS().
                set_MBA(iv_target).
                set_MBMSR(l_mbmsrq).
                set_CMD_TYPE(iv_cmd_type).
                set_MBMCT(l_mbmct),
                "MBMSRQ[0]: Can't start new cmd if previous cmd still in progress on %s.", mss::c_str(iv_target));

    // Check MBAXCRn, to show memory configured behind this MBA
    FAPI_ASSERT( (l_mbaxcr.getBit<0, 4>()) ,
                 fapi2::CEN_MSS_MAINT_NO_MEM_CNFG().
                 set_MBAXCR(l_mbaxcr),
                 "MBAXCRn[0:3] = 0, meaning no memory configured behind this MBA on %s.", mss::c_str(iv_target));

    // Check CCS_MODEQ[29] to make sure mux switched from CCS to mainline
    FAPI_ASSERT(!l_ccs_modeq.getBit<29>(),
                fapi2::CEN_MSS_MAINT_CCS_MUX_NOT_MAINLINE().
                set_MBA(iv_target).
                set_CCS_MODE(l_ccs_modeq).
                set_CMD_TYPE(iv_cmd_type),
                "CCS_MODEQ[29] = 1, meaning mux set for CCS instead of mainline on %s.", mss::c_str(iv_target));

    // Check MBSECC[0] = 0, to make sure ECC check/correct is enabled
    FAPI_ASSERT(!l_mbsecc.getBit<0>(),
                fapi2::CEN_MSS_MAINT_ECC_DISABLED().
                set_MBA(iv_target).
                set_MBSECC(l_mbsecc).
                set_CMD_TYPE(iv_cmd_type),
                "MBSECC[0] = 1, meaning ECC check/correct disabled on %s.", mss::c_str(iv_target));

    FAPI_INF("EXIT mss_MaintCmd::preConditionCheck()");
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief  Loads command type into hw.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::loadCmdType()
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dram_gen = 0;

    FAPI_INF("ENTER mss_MaintCmd::loadCmdType()");

    // Get DDR3/DDR4: ATTR_EFF_DRAM_GEN
    // 0x01 = fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3
    // 0x02 = fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, iv_target,  l_dram_gen));
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCTQ, l_data));
    l_data.insert < 0, 5, 32 - 5 > ( static_cast<uint32_t>(iv_cmd_type));

    // Setting super fast address increment mode for DDR3, where COL bits are LSB. Valid for all cmds.
    // NOTE: Super fast address increment mode is broken for DDR4 due to DD1 bug
    if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3)
    {
        l_data.setBit<5>();
    }

    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBMCTQ, l_data));

    FAPI_INF("EXIT mss_MaintCmd::loadCmdType()");
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief  Loads start address into hw.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::loadStartAddress()
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_INF("ENTER mss_MaintCmd::loadStartAddress()");
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMACAQ, l_data));

    // Load address bits 0:39
    l_data.insert<0, 40, 0>(iv_start_addr);
    // Clear error status bits 40:46
    l_data.clearBit<40, 7>();
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBMACAQ, l_data));

    FAPI_INF("EXIT mss_MaintCmd::loadStartAddress()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Loads end address into hw.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::loadEndAddress()
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_INF("ENTER mss_MaintCmd::loadEndAddress()");
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMEAQ, l_data));
    l_data.insert<0, 40, 0>(iv_end_addr);
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBMEAQ, l_data));

    FAPI_INF("EXIT mss_MaintCmd::loadEndAddress()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Loads stop conditions into hw.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::loadStopCondMask()
{
    fapi2::buffer<uint64_t> l_mbasctlq;
    uint8_t l_mbspa_0_fixed_for_dd2 = 0;

    FAPI_INF("ENTER mss_MaintCmd::loadStopCondMask()");

    // Get attribute that tells us if mbspa 0 cmd complete attention is fixed for dd2
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_HW217608_MBSPA_0_CMD_COMPLETE_ATTN_FIXED, iv_targetCentaur,
                           l_mbspa_0_fixed_for_dd2));

    // Get stop conditions from MBASCTLQ
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBASCTLQ, l_mbasctlq));

    // Start by clearing all bits 0:12 and bit 16
    l_mbasctlq.clearBit<0, 13>();
    l_mbasctlq.clearBit<16>();

    // Enable stop immediate
    if ( 0 != (iv_stop_condition & STOP_IMMEDIATE) )
    {
        l_mbasctlq.setBit<0>();
    }

    // Enable stop end of rank
    if ( 0 != (iv_stop_condition & STOP_END_OF_RANK) )
    {
        l_mbasctlq.setBit<1>();
    }

    // Stop on hard NCE ETE
    if ( 0 != (iv_stop_condition & STOP_ON_HARD_NCE_ETE) )
    {
        l_mbasctlq.setBit<2>();
    }

    // Stop on intermittent NCE ETE
    if ( 0 != (iv_stop_condition & STOP_ON_INT_NCE_ETE) )
    {
        l_mbasctlq.setBit<3>();
    }

    // Stop on soft NCE ETE
    if ( 0 != (iv_stop_condition & STOP_ON_SOFT_NCE_ETE) )
    {
        l_mbasctlq.setBit<4>();
    }

    // Stop on SCE
    if ( 0 != (iv_stop_condition & STOP_ON_SCE) )
    {
        l_mbasctlq.setBit<5>();
    }

    // Stop on MCE
    if ( 0 != (iv_stop_condition & STOP_ON_MCE) )
    {
        l_mbasctlq.setBit<6>();
    }

    // Stop on retry CE ETE
    if ( 0 != (iv_stop_condition & STOP_ON_RETRY_CE_ETE) )
    {
        l_mbasctlq.setBit<7>();
    }

    // Stop on MPE
    if ( 0 != (iv_stop_condition & STOP_ON_MPE) )
    {
        l_mbasctlq.setBit<8>();
    }

    // Stop on UE
    if ( 0 != (iv_stop_condition & STOP_ON_UE) )
    {
        l_mbasctlq.setBit<9>();
    }

    // Stop on end address
    if ( 0 != (iv_stop_condition & STOP_ON_END_ADDRESS) )
    {
        l_mbasctlq.setBit<10>();
    }

    // Enable command complete attention
    if ( 0 != (iv_stop_condition & ENABLE_CMD_COMPLETE_ATTENTION) )
    {
        l_mbasctlq.setBit<11>();
    }

    // Stop on SUE
    if ( 0 != (iv_stop_condition & STOP_ON_SUE) )
    {
        l_mbasctlq.setBit<12>();
    }

    // Command complete attention on clean and error
    // DD2: enable (fixed)
    // DD1: disable (broken)
    if (l_mbspa_0_fixed_for_dd2)
    {
        l_mbasctlq.setBit<16>();
    }

    // Write stop conditions to MBASCTLQ
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBASCTLQ, l_mbasctlq));

    FAPI_INF("EXIT mss_MaintCmd::loadStopCondMask()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Starts command.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::startMaintCmd()
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_INF("ENTER mss_MaintCmd::startMaintCmd()");
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCCQ, l_data));
    l_data.setBit<0>();
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBMCCQ, l_data));
    FAPI_INF("EXIT mss_MaintCmd::startMaintCmd()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Checks for hw to be right state after cmd is started.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
/// @note   For now, no array of pattens, just hardcoded pattern of all 0's.
///
fapi2::ReturnCode mss_MaintCmd::postConditionCheck()
{
    fapi2::buffer<uint64_t> l_mbmccq;
    fapi2::buffer<uint64_t> l_mbafirq;
    fapi2::buffer<uint64_t> l_mbmct;

    FAPI_INF("ENTER mss_MaintCmd::postConditionCheck()");

    // Read MBMCCQ
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCCQ, l_mbmccq));
    // Read MBAFIRQ
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBAFIRQ, l_mbafirq));
    // Read MBMCT[0:4], cmd type, for FFDC
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCTQ, l_mbmct));


    FAPI_ASSERT(!l_mbmccq.getBit<0>(),
                fapi2::CEN_MSS_MAINT_START_NOT_RESET().
                set_MBA(iv_target).
                set_MBMCC(l_mbmccq).
                set_CMD_TYPE(iv_cmd_type).
                set_MBMCT(l_mbmct),
                "MBMCCQ[0]: maint_cmd_start not reset by hw on %s.",
                mss::c_str(iv_target));

    FAPI_ASSERT(!l_mbafirq.getBit<0>(),
                fapi2::CEN_MSS_MAINT_INVALID_CMD().
                set_MBA(iv_target).
                set_MBAFIR(l_mbafirq).
                set_CMD_TYPE(iv_cmd_type).
                set_MBMCT(l_mbmct),
                "MBAFIRQ[0], invalid_maint_cmd on %s.", mss::c_str(iv_target));

    // Check for MBAFIRQ[1], invalid_maint_address.
    FAPI_ASSERT(!l_mbafirq.getBit<1>(),
                fapi2::CEN_MSS_MAINT_INVALID_ADDR().
                set_MBA(iv_target).
                set_MBAFIR(l_mbafirq).
                set_CMD_TYPE(iv_cmd_type).
                set_MBMCT(l_mbmct),
                "MBAFIRQ[1], cmd started with invalid_maint_address on %s.", mss::c_str(iv_target));

    FAPI_INF("EXIT mss_MaintCmd::postConditionCheck()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Polls for command complete.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::pollForMaintCmdComplete()
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_INF("ENTER mss_MaintCmd::pollForMaintCmdComplete()");
    uint32_t count = 0;
    // 1 ms delay for HW mode -- LWM changed 100,000,000 to 1,000,000 to match comment
    constexpr uint64_t  HW_MODE_DELAY = 1000000;
    // 200000 sim cycle delay for SIM mode
    constexpr uint64_t  SIM_MODE_DELAY = 200000;
    constexpr uint32_t loop_limit = 50000;

    do
    {
        fapi2::delay(HW_MODE_DELAY, SIM_MODE_DELAY);
        // Want to see cmd complete attention
        FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBSPAQ, l_data));
        FAPI_DBG("MBSPAQ = 0x%X", l_data);
        // Read MBMACAQ just to see if it's incrementing
        FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMACAQ, l_data));
        FAPI_DBG("MBMACAQ = 0x%X", l_data);
        // Waiting for MBMSRQ[0] maint cmd in progress bit to turn off
        FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMSRQ, l_data));
        FAPI_DBG("MBMSRQ = 0x%X", l_data);
        ++count;
    }

    // Poll until cmd in progress bit goes off
    while (l_data.getBit<0>() && (count < loop_limit));

    FAPI_ASSERT(count != loop_limit,
                fapi2::CEN_MSS_MAINT_CMD_TIMEOUT().
                set_MBA(iv_target).
                set_CMD_TYPE(iv_cmd_type).
                set_CENTAUR(iv_targetCentaur),
                "Maint cmd timeout on %s.", mss::c_str(iv_target));

    FAPI_INF("Maint cmd complete. ");

    FAPI_INF("EXIT mss_MaintCmd::pollForMaintCmdComplete()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  FOR DEBUG ONLY: Reads hw regs for FFDC after command is done.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::collectFFDC()
{
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dramSparePort0Symbol = MSS_INVALID_SYMBOL;
    uint8_t l_dramSparePort1Symbol = MSS_INVALID_SYMBOL;
    uint8_t l_eccSpareSymbol = MSS_INVALID_SYMBOL;
    uint8_t l_symbol_mark = MSS_INVALID_SYMBOL;
    uint8_t l_chip_mark = MSS_INVALID_SYMBOL;

    FAPI_INF("ENTER mss_MaintCmd::collectFFDC()");

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCTQ, l_data));
    FAPI_DBG("MBMCTQ = 0x%X", l_data);
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMACAQ, l_data));
    FAPI_DBG("MBMACAQ = 0x%X", l_data);

    // Print out error status bits from MBMACAQ
    if (l_data.getBit<40>())
    {
        FAPI_DBG("MBMACAQ error status: 40:NCE");
    }

    if (l_data.getBit<41>())
    {
        FAPI_DBG("MBMACAQ error status: 41:SCE");
    }

    if (l_data.getBit<42>())
    {
        FAPI_DBG("MBMACAQ error status: 42:MCE");
    }

    if (l_data.getBit<43>())
    {
        FAPI_DBG("MBMACAQ error status: 43:RCE");
    }

    if (l_data.getBit<44>())
    {
        FAPI_DBG("MBMACAQ error status: 44:MPE");
    }

    if (l_data.getBit<45>())
    {
        FAPI_DBG("MBMACAQ error status: 45:UE");
    }

    if (l_data.getBit<46>())
    {
        FAPI_DBG("MBMACAQ error status: 46:SUE");
    }

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMEAQ, l_data));
    FAPI_DBG("MBMEAQ = 0x%X", l_data);

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBASCTLQ, l_data));
    FAPI_DBG("MBASCTLQ = 0x%X", l_data);

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCCQ, l_data));
    FAPI_DBG("MBMCCQ = 0x%X", l_data);

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMSRQ, l_data));
    FAPI_DBG("MBMSRQ = 0x%X", l_data);

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBAFIRQ, l_data));
    FAPI_DBG("MBAFIRQ = 0x%X", l_data);

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBSPAQ, l_data));
    FAPI_DBG("MBSPAQ = 0x%X", l_data);

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBACALFIRQ, l_data));
    FAPI_DBG("MBACALFIR = 0x%X", l_data);

    FAPI_TRY(fapi2::getScom(iv_targetCentaur, mss_mbeccfir[iv_mbaPosition], l_data));
    FAPI_DBG("MBECCFIR = 0x%X", l_data);

    // Print out maint ECC FIR bits from MBECCFIR
    if (l_data.getBit<20>())
    {
        FAPI_DBG("20:Maint MPE, rank0");
    }

    if (l_data.getBit<21>())
    {
        FAPI_DBG("21:Maint MPE, rank1");
    }

    if (l_data.getBit<22>())
    {
        FAPI_DBG("22:Maint MPE, rank2");
    }

    if (l_data.getBit<23>())
    {
        FAPI_DBG("23:Maint MPE, rank3");
    }

    if (l_data.getBit<24>())
    {
        FAPI_DBG("24:Maint MPE, rank4");
    }

    if (l_data.getBit<25>())
    {
        FAPI_DBG("25:Maint MPE, rank5");
    }

    if (l_data.getBit<26>())
    {
        FAPI_DBG("26:Maint MPE, rank6");
    }

    if (l_data.getBit<27>())
    {
        FAPI_DBG("27:Maint MPE, rank7");
    }

    if (l_data.getBit<36>())
    {
        FAPI_DBG("36: Maint NCE");
    }

    if (l_data.getBit<37>())
    {
        FAPI_DBG("37: Maint SCE");
    }

    if (l_data.getBit<38>())
    {
        FAPI_DBG("38: Maint MCE");
    }

    if (l_data.getBit<39>())
    {
        FAPI_DBG("39: Maint RCE");
    }

    if (l_data.getBit<40>())
    {
        FAPI_DBG("40: Maint SUE");
    }

    if (l_data.getBit<41>())
    {
        FAPI_DBG("41: Maint UE");
    }

    for ( uint8_t l_rank = 0; l_rank < MAX_RANKS_PER_PORT; ++l_rank )
    {
        FAPI_TRY(fapi2::getScom(iv_targetCentaur, mss_markstore_regs[l_rank][iv_mbaPosition], l_data));
        FAPI_DBG("MBMS%d = 0x%X", l_rank, l_data);
    }

    for ( uint8_t l_rank = 0; l_rank < MAX_RANKS_PER_PORT; ++l_rank )
    {
        FAPI_TRY(mss_get_mark_store(iv_target, l_rank, l_symbol_mark, l_chip_mark ));
    }

    for ( uint8_t l_rank = 0; l_rank < MAX_RANKS_PER_PORT; ++l_rank )
    {
        FAPI_TRY(mss_check_steering(iv_target,
                                    l_rank,
                                    l_dramSparePort0Symbol,
                                    l_dramSparePort1Symbol,
                                    l_eccSpareSymbol));
    }

    FAPI_INF("EXIT mss_MaintCmd::collectFFDC()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Loads pattern into hw.
/// @param[in]  i_initPattern    Index into array containing patterns to load.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
/// @note   For now, no array of pattens, just hardcoded pattern of all 0's.
///
fapi2::ReturnCode mss_MaintCmd::loadPattern(PatternIndex i_initPattern)
{
    FAPI_INF("ENTER mss_MaintCmd::loadPattern()");
    static constexpr uint32_t maintBufferDataRegs[MAX_MBA_PER_CEN][NUM_BEATS][NUM_WORDS] =
    {
        // port0
        {   {CEN_MAINT0_MAINT_BUFF0_DATA0_WO, CEN_MAINT0_MAINT_BUFF0_DATA_ECC0_WO},// DW0
            {CEN_MAINT0_MAINT_BUFF2_DATA0_WO, CEN_MAINT0_MAINT_BUFF2_DATA_ECC0_WO}, // DW2
            {CEN_MAINT0_MAINT_BUFF0_DATA1_WO, CEN_MAINT0_MAINT_BUFF0_DATA_ECC1_WO}, // DW4
            {CEN_MAINT0_MAINT_BUFF2_DATA1_WO, CEN_MAINT0_MAINT_BUFF2_DATA_ECC1_WO}, // DW6
            {CEN_MAINT0_MAINT_BUFF0_DATA2_WO, CEN_MAINT0_MAINT_BUFF0_DATA_ECC2_WO}, // DW8
            {CEN_MAINT0_MAINT_BUFF2_DATA2_WO, CEN_MAINT0_MAINT_BUFF2_DATA_ECC2_WO}, // DW10
            {CEN_MAINT0_MAINT_BUFF0_DATA3_WO, CEN_MAINT0_MAINT_BUFF0_DATA_ECC3_WO}, // DW12
            {CEN_MAINT0_MAINT_BUFF2_DATA3_WO, CEN_MAINT0_MAINT_BUFF2_DATA_ECC3_WO}, // DW14

            // port1
            {CEN_MAINT0_MAINT_BUFF1_DATA0_WO, CEN_MAINT0_MAINT_BUFF1_DATA_ECC0_WO}, // DW1
            {CEN_MAINT0_MAINT_BUFF3_DATA0_WO, CEN_MAINT0_MAINT_BUFF3_DATA_ECC0_WO}, // DW3
            {CEN_MAINT0_MAINT_BUFF1_DATA1_WO, CEN_MAINT0_MAINT_BUFF1_DATA_ECC1_WO}, // DW5
            {CEN_MAINT0_MAINT_BUFF3_DATA1_WO, CEN_MAINT0_MAINT_BUFF3_DATA_ECC1_WO}, // DW7
            {CEN_MAINT0_MAINT_BUFF1_DATA2_WO, CEN_MAINT0_MAINT_BUFF1_DATA_ECC2_WO}, // DW9
            {CEN_MAINT0_MAINT_BUFF3_DATA2_WO, CEN_MAINT0_MAINT_BUFF3_DATA_ECC2_WO}, // DW11
            {CEN_MAINT0_MAINT_BUFF1_DATA3_WO, CEN_MAINT0_MAINT_BUFF1_DATA_ECC3_WO}, // DW13
            {CEN_MAINT0_MAINT_BUFF3_DATA3_WO, CEN_MAINT0_MAINT_BUFF3_DATA_ECC3_WO}
        },// DW15

        // port2
        {   {CEN_MAINT1_MAINT_BUFF0_DATA0_WO, CEN_MAINT1_MAINT_BUFF0_DATA_ECC0_WO},// DW0
            {CEN_MAINT1_MAINT_BUFF2_DATA0_WO, CEN_MAINT1_MAINT_BUFF2_DATA_ECC0_WO}, // DW2
            {CEN_MAINT1_MAINT_BUFF0_DATA1_WO, CEN_MAINT1_MAINT_BUFF0_DATA_ECC1_WO}, // DW4
            {CEN_MAINT1_MAINT_BUFF2_DATA1_WO, CEN_MAINT1_MAINT_BUFF2_DATA_ECC1_WO}, // DW6
            {CEN_MAINT1_MAINT_BUFF0_DATA2_WO, CEN_MAINT1_MAINT_BUFF0_DATA_ECC2_WO}, // DW8
            {CEN_MAINT1_MAINT_BUFF2_DATA2_WO, CEN_MAINT1_MAINT_BUFF2_DATA_ECC2_WO}, // DW10
            {CEN_MAINT1_MAINT_BUFF0_DATA3_WO, CEN_MAINT1_MAINT_BUFF0_DATA_ECC3_WO}, // DW12
            {CEN_MAINT1_MAINT_BUFF2_DATA3_WO, CEN_MAINT1_MAINT_BUFF2_DATA_ECC3_WO}, // DW14

            // port3
            {CEN_MAINT1_MAINT_BUFF1_DATA0_WO, CEN_MAINT1_MAINT_BUFF1_DATA_ECC0_WO}, // DW1
            {CEN_MAINT1_MAINT_BUFF3_DATA0_WO, CEN_MAINT1_MAINT_BUFF3_DATA_ECC0_WO}, // DW3
            {CEN_MAINT1_MAINT_BUFF1_DATA1_WO, CEN_MAINT1_MAINT_BUFF1_DATA_ECC1_WO}, // DW5
            {CEN_MAINT1_MAINT_BUFF3_DATA1_WO, CEN_MAINT1_MAINT_BUFF3_DATA_ECC1_WO}, // DW6
            {CEN_MAINT1_MAINT_BUFF1_DATA2_WO, CEN_MAINT1_MAINT_BUFF1_DATA_ECC2_WO}, // DW9
            {CEN_MAINT1_MAINT_BUFF3_DATA2_WO, CEN_MAINT1_MAINT_BUFF3_DATA_ECC2_WO}, // DW11
            {CEN_MAINT1_MAINT_BUFF1_DATA3_WO, CEN_MAINT1_MAINT_BUFF1_DATA_ECC3_WO}, // DW13
            {CEN_MAINT1_MAINT_BUFF3_DATA3_WO, CEN_MAINT1_MAINT_BUFF3_DATA_ECC3_WO}
        }
    };// DW15


    static constexpr uint32_t maintBuffer65thRegs[4][2] =
    {
        // MBA01                                                 MBA23
        {CEN_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC0_WO,    CEN_MAINT1_MAINT_BUFF_65TH_BYTE_64B_ECC0_WO}, // 1st 64B of cacheline
        {CEN_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC1_WO,    CEN_MAINT1_MAINT_BUFF_65TH_BYTE_64B_ECC1_WO}, // 1st 64B of cacheline
        {CEN_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC2_WO,    CEN_MAINT1_MAINT_BUFF_65TH_BYTE_64B_ECC2_WO}, // 2nd 64B of cacheline
        {CEN_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC3_WO,    CEN_MAINT1_MAINT_BUFF_65TH_BYTE_64B_ECC3_WO}
    };// 2nd 64B of cacheline

    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_ecc;
    fapi2::buffer<uint64_t> l_65th;
    fapi2::buffer<uint64_t> l_mbmmr;
    fapi2::buffer<uint64_t> l_mbsecc;
    uint32_t loop = 0;
    uint8_t l_dramWidth = 0;
    uint8_t l_attr_centaur_ec_enable_rce_with_other_errors_hw246685 = 0;

    FAPI_INF("pattern = 0x%.8X 0x%.8X",
             mss_maintBufferData[l_dramWidth][i_initPattern][0][0],
             mss_maintBufferData[l_dramWidth][i_initPattern][0][1]);

    //----------------------------------------------------
    // Get l_dramWidth
    //----------------------------------------------------
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, iv_target,  l_dramWidth));

    // Convert from attribute enum values: 8,4 to index values: 0,1
    if(l_dramWidth == mss_memconfig::X8)
    {
        l_dramWidth = 0;
    }
    else
    {
        l_dramWidth = 1;
    }


    //----------------------------------------------------
    // Load the data: 16 loops x 64bits = 128B cacheline
    //----------------------------------------------------
    FAPI_INF("Load the data: 16 loops x 64bits = 128B cacheline");

    // Set bit 9 so that hw will generate the fabric ECC.
    // This is an 8B ECC protecting the data moving on internal buses in
    // the Centaur.
    l_ecc.flush<0>();
    l_ecc.setBit<9>();


    for(loop = 0; loop < NUM_BEATS; ++loop)
    {
        // A write to MAINT_BUFFx_DATAy will not update until the corresponding
        // MAINT_BUFFx_DATA_ECCy is written to.
        l_data.insert<0, 32, 0>(mss_maintBufferData[l_dramWidth][i_initPattern][loop][0]);
        l_data.insert<32, 32, 0>(mss_maintBufferData[l_dramWidth][i_initPattern][loop][1]);
        FAPI_TRY(fapi2::putScom(iv_targetCentaur, maintBufferDataRegs[iv_mbaPosition][loop][0], l_data));
        FAPI_TRY(fapi2::putScom(iv_targetCentaur, maintBufferDataRegs[iv_mbaPosition][loop][1], l_ecc));
    }

    //----------------------------------------------------
    // Load the 65th byte: 4 loops to fill in the two 65th bytes in cacheline
    //----------------------------------------------------
    FAPI_INF("Load the 65th byte: 4 loops to fill in the two 65th bytes in the cacheline");

    l_65th.flush<0>();

    // Set bit 56 so that hw will generate the fabric ECC.
    // This is an 8B ECC protecting the data moving on internal buses in Centaur.
    l_65th.setBit<56>();

    for(loop = 0; loop < NUM_LOOPS_FOR_65TH_BYTE; ++loop )
    {
        l_65th.insert<1, 3, 1>(mss_65thByte[l_dramWidth][i_initPattern][loop]);
        FAPI_TRY(fapi2::putScom(iv_targetCentaur, maintBuffer65thRegs[loop][iv_mbaPosition], l_65th));
    }

    //----------------------------------------------------
    // Save i_initPattern in unused maint mark reg
    // so we know what pattern was used when we do
    // UE isolation
    //----------------------------------------------------

    // No plans to use maint mark, but make sure it's disabled to be safe
    FAPI_TRY(fapi2::getScom(iv_targetCentaur, mss_mbsecc[iv_mbaPosition], l_mbsecc));

    l_mbsecc.clearBit<4>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_ENABLE_RCE_WITH_OTHER_ERRORS_HW246685, iv_targetCentaur,
                           l_attr_centaur_ec_enable_rce_with_other_errors_hw246685));


    if(l_attr_centaur_ec_enable_rce_with_other_errors_hw246685)
    {
        l_mbsecc.setBit<16>();
    }

    FAPI_TRY(fapi2::putScom(iv_targetCentaur, mss_mbsecc[iv_mbaPosition], l_mbsecc));

    l_mbmmr.flush<0>();
    // Store i_initPattern, with range 0-8, in MBMMR bits 4-7
    l_mbmmr.insert < 4, 4, 8 - 4 > (static_cast<uint8_t>(i_initPattern));
    FAPI_TRY(fapi2::putScom(iv_targetCentaur, mss_mbmmr[iv_mbaPosition] , l_mbmmr));

    FAPI_INF("EXIT mss_MaintCmd::loadPattern()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Loads timebase speed into hw.
/// @param[in]  i_speed  See enum TimeBaseSpeed
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_MaintCmd::loadSpeed(const TimeBaseSpeed i_speed)
{
    FAPI_INF("ENTER mss_MaintCmd::loadSpeed()");
    fapi2::buffer<uint64_t> l_data;
    uint32_t l_ddr_freq = 0;
    uint64_t l_step_size = 0;
    uint64_t l_num_address_bits = 0;
    uint64_t l_num_addresses = 0;
    uint64_t l_address_bit = 0;
    fapi2::buffer<uint64_t> l_start_address;
    fapi2::buffer<uint64_t> l_end_address;
    uint64_t l_cmd_interval = 0;

    // burst_window_sel
    // MBMCTQ[6]: 0 = 512 Maint Clks
    //            1 = 536870912 Maint Clks
    uint8_t l_burst_window_sel = 0;

    // timebase_sel
    // MBMCTQ[9:10]: 00 = 1 Maint Clk
    //               01 = 8192 Maint clks
    uint8_t l_timebase_sel = 0;

    // timebase_burst_sel
    // MBMCTQ[11]: 0 = disable burst mode
    //             1 = enable burst mode
    uint8_t l_timebase_burst_sel = 0;

    // timebase_interval
    // MBMCTQ[12:23]: The operation interval for timebase operations
    //                equals the timebase_sel x MBMCTQ[12:23].
    // NOTE: Should never be 0, or will hang mainline traffic.
    uint32_t l_timebase_interval = 1;

    // burst_window
    // MBMCTQ[24:31]: The burst window for timebase operations with burst mode
    //                enabled equals burst_window_sel x MBMCTQ[24:31]
    uint8_t l_burst_window = 0;

    // burst_interval
    // MBMCTQ[32:39]: The burst interval for timebase operations with burst mode
    //                enabled equals the number of burst windows that will have
    //                no operations occurring in them.
    uint8_t l_burst_interval = 0;

    constexpr uint64_t TIMEBASE_SEL01 = 8192;
    constexpr uint64_t PICO_TO_NANOS = 1000;

    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMCTQ, l_data));

    if (FAST_MAX_BW_IMPACT == i_speed)
    {
        l_timebase_sel = 0;
        l_timebase_interval = 1;
    }

    else if (FAST_MED_BW_IMPACT == i_speed)
    {
        l_timebase_sel = 0;
        l_timebase_interval = 512;
    }

    else if (FAST_MIN_BW_IMPACT == i_speed)
    {
        l_timebase_sel = 1;
        l_timebase_interval = 12;
    }

    else // BG_SCRUB
    {
        // Get l_ddr_freq from ATTR_MSS_FREQ
        // Possible frequencies are 800, 1066, 1333, 1600, 1866, and 2133 MHz
        // NOTE: Max 32 address bits using 800 and 1066 result in scrub
        // taking longer than 12h, but these is no plan to actually use
        // those frequencies.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, iv_targetCentaur,  l_ddr_freq));

        // Make sure it's non-zero, to avoid divide by 0
        FAPI_ASSERT(l_ddr_freq != 0,
                    fapi2::CEN_MSS_MAINT_ZERO_DDR_FREQ().
                    set_MBA(iv_target).
                    set_CMD_TYPE(iv_cmd_type),
                    "ATTR_MSS_FREQ set to zero so can't calculate scrub rate on %s.", mss::c_str(iv_target));

        // l_timebase_sel
        // MBMCTQ[9:10]: 00 = 1 * Maint Clk
        //               01 = 8192 * Maint Clk
        // Where Maint Clk = 2/1_ddr_freq
        l_timebase_sel = 1;

        // Get l_step_size in nSec
        l_step_size = TIMEBASE_SEL01 * 2 * PICO_TO_NANOS / l_ddr_freq;

        FAPI_DBG("l_ddr_freq = %d MHz, l_step_size = %d nSec",
                 (uint32_t)l_ddr_freq, (uint32_t)l_step_size);

        // Get l_end_address
        FAPI_TRY(mss_get_address_range( iv_target,
                                        MSS_ALL_RANKS,
                                        l_start_address,
                                        l_end_address ));


        // Get l_num_address_bits by counting bits set to 1 in l_end_address.
        for(l_address_bit = 0; l_address_bit < VALID_BITS_IN_ADDR_STRING; l_address_bit++ )
        {
            if(l_end_address.getBit(l_address_bit))
            {
                l_num_address_bits++;
            }
        }

        // NOTE: Assumption is max 32 address bits, which can be done
        // in 12h (+/- 2h). More than 32 address bits would
        // double scrub time for every extra address bit.
        if (l_num_address_bits > 32)
        {
            FAPI_INF("WARNING: l_num_address_bits: %d, is greater than 32, so scrub will take longer than 12h.",
                     (uint32_t)l_num_address_bits);
        }

        // NOTE: Smallest number of address bits is supposed to be 25.
        // So if for some reason it's less (like in VBU),
        // use 25 anyway so the scrub rate calculation still works.
        if (l_num_address_bits < 25)
        {
            FAPI_INF("WARNING: l_num_address_bits: %d, is less than 25, but using 25 in calculation anyway.",
                     (uint32_t)l_num_address_bits);
            l_num_address_bits = 25;
        }

        // Get l_num_addresses
        l_num_addresses = 1;

        for(uint32_t i = 0; i < l_num_address_bits; i++ )
        {
            l_num_addresses *= 2;
        }

        // Convert to M addresses
        l_num_addresses /= 1000000;

        // Get interval between cmds in order to through l_num_addresses in 12h
        l_cmd_interval = (12 * 60 * 60 * 1000) / l_num_addresses;

        // How many times to multiply l_step_size to get l_cmd_interval?
        l_timebase_interval = l_cmd_interval / l_step_size;

        // Round up to nearest integer for more accurate number
        l_timebase_interval += (l_cmd_interval % l_step_size >= l_step_size / 2) ? 1 : 0;

        // Make sure smallest is 1
        if (l_timebase_interval == 0)
        {
            l_timebase_interval = 1;
        }

        FAPI_DBG("l_num_address_bits = %d, l_num_addresses = %d (M), l_cmd_interval = %d nSec, l_timebase_interval = %d",
                 (uint32_t)l_num_address_bits, (uint32_t)l_num_addresses, (uint32_t)l_cmd_interval, (uint32_t)l_timebase_interval);

    } // End BG_SCRUB

    // burst_window_sel
    // MBMCTQ[6]
    l_data.insert < 6, 1, 8 - 1 > (l_burst_window_sel);

    // timebase_sel
    // MBMCTQ[9:10]
    l_data.insert < 9, 2, 8 - 2 > (l_timebase_sel);

    // timebase_burst_sel
    // MBMCTQ[11]
    l_data.insert < 11, 1, 8 - 1 > (l_timebase_burst_sel);

    // timebase_interval
    // MBMCTQ[12:23]
    l_data.insert < 12, 12, 32 - 12 > (l_timebase_interval);

    // burst_window
    // MBMCTQ[24:31]
    l_data.insert < 24, 8, 8 - 8 > (l_burst_window);

    // burst_interval
    // MBMCTQ[32:39]
    l_data.insert < 32, 8, 8 - 8 > (l_burst_interval);

    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBMCTQ, l_data));

    FAPI_INF("EXIT mss_MaintCmd::loadSpeed()");
fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// SuperFastInit
//------------------------------------------------------------------------------
const mss_MaintCmd::CmdType mss_SuperFastInit::cv_cmd_type = SUPERFAST_INIT;

///
/// @brief Superfastinit Constructor
///
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
/// @param[in] i_end_addr,        Address cmd will stop at
/// @param[in] i_initPattern     Pattern to initialize memory
/// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
/// @param[in] i_poll            Set to true if you wait for command to complete
///
mss_SuperFastInit::mss_SuperFastInit( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const fapi2::buffer<uint64_t>& i_start_addr,
                                      const fapi2::buffer<uint64_t>& i_end_addr,
                                      const PatternIndex i_initPattern,
                                      const uint32_t i_stop_condition,
                                      const bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_start_addr,
                  i_end_addr,
                  i_stop_condition,
                  i_poll,
                  cv_cmd_type),
    iv_initPattern( i_initPattern ) // NOTE: iv_initPattern is instance
// variable of SuperFastInit, since not
// needed in parent class
{}



///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_SuperFastInit::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_SuperFastInit::setupAndExecuteCmd()");
    fapi2::buffer<uint64_t> l_data;

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck());
    // Load pattern
    FAPI_TRY(loadPattern(iv_initPattern));
    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType());
    // Load start address: MBMACAQ
    FAPI_TRY(loadStartAddress());
    // Load end address: MBMEAQ
    FAPI_TRY(loadEndAddress());
    // Load stop conditions: MBASCTLQ
    FAPI_TRY(loadStopCondMask());
    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd());
    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    FAPI_TRY(postConditionCheck());

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        FAPI_INF("EXIT mss_SuperFastInit::setupAndExecuteCmd()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete());

    // Collect FFDC
    FAPI_TRY(collectFFDC());

    FAPI_INF("EXIT mss_SuperFastInit::setupAndExecuteCmd()");
fapi_try_exit:
    return fapi2::current_err;
}




const mss_MaintCmd::CmdType mss_SuperFastRandomInit::cv_cmd_type = SUPERFAST_RANDOM_INIT;

///
/// @brief SuperFastRandomInit Constructor
///
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
/// @param[in] i_end_addr,        Address cmd will stop at
/// @param[in] i_initPattern     Pattern to initialize
/// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
/// @param[in] i_poll            Set to true if you wait for command to complete
///
mss_SuperFastRandomInit::mss_SuperFastRandomInit( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const fapi2::buffer<uint64_t>& i_start_addr,
        const fapi2::buffer<uint64_t>& i_end_addr,
        const PatternIndex i_initPattern,
        const uint32_t i_stop_condition,
        const bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_start_addr,
                  i_end_addr,
                  i_stop_condition,
                  i_poll,
                  cv_cmd_type),
    iv_initPattern( i_initPattern )
{}




///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_SuperFastRandomInit::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_SuperFastRandomInit::setupAndExecuteCmd()");
    fapi2::buffer<uint64_t> l_data;

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck());

    // Load pattern
    FAPI_TRY(loadPattern(iv_initPattern));

    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType());

    // Load start address: MBMACAQ
    FAPI_TRY(loadStartAddress());

    // Load end address: MBMEAQ
    FAPI_TRY(loadEndAddress());

    // Load stop conditions: MBASCTLQ
    FAPI_TRY(loadStopCondMask());

    // Disable 8B ECC check/correct on WRD data bus: MBA_WRD_MODE(0:1) = 11
    // before a SuperFastRandomInit command is issued
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBA_WRD_MODE, iv_saved_MBA_WRD_MODE));

    l_data.insert<0, 64, 0>(iv_saved_MBA_WRD_MODE);
    l_data.setBit<0>();
    l_data.setBit<1>();

    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBA_WRD_MODE, l_data));

    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd());

    // Check for early problems with maint cmd instead of waiting for
    //cmd timeout
    FAPI_TRY(postConditionCheck());

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        FAPI_INF("EXIT mss_SuperFastRandomInit::setupAndExecuteCmd()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete());

    // Collect FFDC
    FAPI_TRY(collectFFDC());

    FAPI_INF("EXIT mss_SuperFastRandomInit::setupAndExecuteCmd()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Called once a command is done if we need to restore settings that
///         had to be modified to run a specific command type, or clear error
///         data in the hw that is no longer relevant.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
/// @note   NOT YET IMPLEMENTED
///
fapi2::ReturnCode mss_SuperFastRandomInit::cleanupCmd()
{

    FAPI_INF("ENTER mss_SuperFastRandomInit::cleanupCmd()");

    // Clear maintenance command complete attention, scrub stats, etc...

    // Restore MBA_WRD_MODE
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBA_WRD_MODE, iv_saved_MBA_WRD_MODE));

    FAPI_INF("EXIT mss_SuperFastRandomInit::cleanupCmd()");
fapi_try_exit:
    return fapi2::current_err;
}



//------------------------------------------------------------------------------
// mss_SuperFastRead
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_SuperFastRead::cv_cmd_type = SUPERFAST_READ;

///
/// @brief SuperFastRead Constructor
///
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
/// @param[in] i_end_addr,        Address cmd will stop at
/// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
/// @param[in] i_poll            Set to true if you wait for command to complete
///
mss_SuperFastRead::mss_SuperFastRead( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const fapi2::buffer<uint64_t>& i_start_addr,
                                      const fapi2::buffer<uint64_t>& i_end_addr,
                                      const uint32_t i_stop_condition,
                                      const bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_start_addr,
                  i_end_addr,
                  i_stop_condition,
                  i_poll,
                  cv_cmd_type) {}

///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_SuperFastRead::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_SuperFastRead::setupAndExecuteCmd()");
    fapi2::buffer<uint64_t> l_data;

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck());
    // Setup required to trap UE actual data needed for IPL UE isolation
    FAPI_TRY(ueTrappingSetup());
    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType());
    // Load start address: MBMACAQ
    FAPI_TRY(loadStartAddress());
    // Load end address: MBMEAQ
    FAPI_TRY(loadEndAddress());
    // Load stop conditions: MBASCTLQ
    FAPI_TRY(loadStopCondMask());
    // Need to set RRQ to fifo mode to ensure super fast read commands
    // are done on order. Otherwise, if cmds get out of order we can't be sure
    // the trapped address in MBMACA will be correct when we stop
    // on error. That means we could unintentionally skip addresses if we just
    // try to increment MBMACA and continue.
    // NOTE: Cleanup needs to be done to restore settings done.
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBA_RRQ0Q, iv_saved_MBA_RRQ0));

    l_data.insert<0, 64, 0>(iv_saved_MBA_RRQ0);
    l_data.clearBit<6, 5>(); // Set 6:10 = 00000 (fifo mode)
    l_data.setBit<12>();    // Disable MBA RRQ fastpath

    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBA_RRQ0Q, l_data));

    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd());

    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    FAPI_TRY(postConditionCheck());

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        FAPI_INF("EXIT mss_SuperFastRead::setupAndExecuteCmd()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete());

    // Collect FFDC
    FAPI_TRY(collectFFDC());

    FAPI_INF("EXIT mss_SuperFastRead::setupAndExecuteCmd()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set registers to trap UEs
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode mss_SuperFastRead::ueTrappingSetup()
{
    FAPI_INF("ENTER mss_SuperFastRead::ueTrappingSetup()");

    static constexpr uint32_t maintBufferDataRegs[MAX_MBA_PER_CEN][MAX_PORTS_PER_MBA][NUM_WORDS] =
    {
        // port0/1
        {   {CEN_MAINT0_MAINT_BUFF0_DATA0_WO, CEN_MAINT0_MAINT_BUFF0_DATA_ECC0_WO},
            {CEN_MAINT0_MAINT_BUFF0_DATA4_WO, CEN_MAINT0_MAINT_BUFF0_DATA_ECC4_WO}
        },
        // port2/3
        {   {CEN_MAINT1_MAINT_BUFF0_DATA0_WO, CEN_MAINT1_MAINT_BUFF0_DATA_ECC0_WO},
            {CEN_MAINT1_MAINT_BUFF0_DATA4_WO, CEN_MAINT1_MAINT_BUFF0_DATA_ECC4_WO}
        }
    };

    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_ecc;
    fapi2::buffer<uint64_t> l_mbstr;
    uint32_t loop = 0;

    // Set bit 9 so that hw will generate the fabric ECC.
    // This is an 8B ECC protecting the data moving on internal buses in
    // the Centaur.
    l_ecc.setBit<9>();

    // Load unique pattern into both halves of the maint buffer,
    // so we can tell which half contains a trapped UE.
    l_data.insert<0, 32, 0>(0xFACEB00C);
    l_data.insert<32, 32, 0>(0xD15C0DAD);


    for(loop = 0; loop < MAX_PORTS_PER_MBA; ++loop )
    {
        FAPI_TRY(fapi2::putScom(iv_targetCentaur, maintBufferDataRegs[iv_mbaPosition][loop][0], l_data));

        // A write to MAINT_BUFFx_DATAy will not update until the corresponding
        // MAINT_BUFFx_DATA_ECCy is written to.
        FAPI_TRY(fapi2::putScom(iv_targetCentaur, maintBufferDataRegs[iv_mbaPosition][loop][1], l_ecc));
    }

    // Enable UE trapping
    FAPI_TRY(fapi2::getScom(iv_targetCentaur, mss_mbstr[iv_mbaPosition], l_mbstr));
    l_mbstr.setBit<59>();
    FAPI_TRY(fapi2::putScom(iv_targetCentaur, mss_mbstr[iv_mbaPosition], l_mbstr));

    FAPI_INF("EXIT mss_SuperFastRead::ueTrappingSetup()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Called once a command is done if we need to restore settings that
///         had to be modified to run a specific command type, or clear error
///         data in the hw that is no longer relevant.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_SuperFastRead::cleanupCmd()
{
    FAPI_INF("ENTER mss_SuperFastRead::cleanupCmd()");
    fapi2::buffer<uint64_t> l_mbstr;

    // Clear maintenance command complete attention, scrub stats, etc...
    // Undo rrq fifo mode
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBA_RRQ0Q, iv_saved_MBA_RRQ0));

    // Disable UE trapping
    FAPI_TRY(fapi2::getScom(iv_targetCentaur, mss_mbstr[iv_mbaPosition], l_mbstr));
    l_mbstr.clearBit<59>();
    FAPI_TRY(fapi2::putScom(iv_targetCentaur, mss_mbstr[iv_mbaPosition], l_mbstr));

    FAPI_INF("EXIT mss_SuperFastRead::cleanupCmd()");
fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// AtomicInject
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_AtomicInject::cv_cmd_type = ATOMIC_ALTER_ERROR_INJECT;

///
/// @brief AtomicInject Constructor
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
/// @param[in] i_injectType      Type of inject
///
mss_AtomicInject::mss_AtomicInject( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                    const fapi2::buffer<uint64_t>& i_start_addr,
                                    const InjectType i_injectType ) :
    mss_MaintCmd( i_target,
                  i_start_addr,
                  fapi2::buffer<uint64_t>(),   // i_end_addr not used for this cmd
                  NO_STOP_CONDITIONS,   // i_stop_condition not used for this cmd
                  true,                     // i_poll always true for this cmd
                  cv_cmd_type),

    iv_injectType( i_injectType ) // NOTE: iv_injectType is instance variable
// of AtomicInject, since not needed
// in parent class
{}

///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_AtomicInject::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_AtomicInject::setupAndExecuteCmd()");
    fapi2::buffer<uint64_t> l_mbectl;

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck(), "Failed precondition check");

    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType(), "Failed loadCmdType");

    // Load start address: MBMACAQ
    FAPI_TRY(loadStartAddress(), "Failed loadStartAddress");

    // Load stop conditions: MBASCTLQ
    FAPI_TRY(loadStopCondMask(), "Failed loadStopCondMask");

    // Load inject type: MBECTLQ
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBECTLQ, l_mbectl), "Failed getScom");
    l_mbectl.flush<0>();
    l_mbectl.setBit(iv_injectType);
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBECTLQ, l_mbectl), "Failed getScom");

    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd(), "Failed startMaintCmd");

    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    FAPI_TRY(postConditionCheck(), "Failed postConditionCheck");

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete(), "Failed pollForMaintCmdComplete");

    // Clear inject type: MBECTLQ
    l_mbectl.flush<0>();

    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBECTLQ, l_mbectl), "Failed putScom");

    // Collect FFDC
    FAPI_TRY(collectFFDC(), "Failed collectFFDC");

    FAPI_INF("EXIT mss_AtomicInject::setupAndExecuteCmd()");
fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// Display
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_Display::cv_cmd_type = MEMORY_DISPLAY;

///
/// @brief Display Constructor
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
///
mss_Display::mss_Display( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                          const fapi2::buffer<uint64_t>& i_start_addr) :
    mss_MaintCmd( i_target,
                  i_start_addr,
                  fapi2::buffer<uint64_t>(),    // i_end_addr not used for this cmd
                  NO_STOP_CONDITIONS,   // i_stop_condition not used for this cmd
                  true,                      // i_poll always true for this cmd
                  cv_cmd_type) {}


///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_Display::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_Display::setupAndExecuteCmd()");
    // Read the data from the display cmd: MBMSRQ
    static const uint32_t maintBufferReadDataRegs[NUM_BEATS] =
    {
        // Port0                                    beat  double word
        CEN_MBA_MAINT0_MAINT_BUFF0_DATA0_RO, // 0     DW0
        CEN_MBA_MAINT0_MAINT_BUFF2_DATA0_RO, // 1     DW2
        CEN_MBA_MAINT0_MAINT_BUFF0_DATA1_RO, // 2     DW4
        CEN_MBA_MAINT0_MAINT_BUFF2_DATA1_RO, // 3     DW6
        CEN_MBA_MAINT0_MAINT_BUFF0_DATA2_RO, // 4     DW8
        CEN_MBA_MAINT0_MAINT_BUFF2_DATA2_RO, // 5     DW10
        CEN_MBA_MAINT0_MAINT_BUFF0_DATA3_RO, // 6     DW12
        CEN_MBA_MAINT0_MAINT_BUFF2_DATA3_RO, // 7     DW14

        // Port1
        CEN_MBA_MAINT0_MAINT_BUFF1_DATA0_RO, // 0     DW1
        CEN_MBA_MAINT0_MAINT_BUFF3_DATA0_RO, // 1     DW3
        CEN_MBA_MAINT0_MAINT_BUFF1_DATA1_RO, // 2     DW5
        CEN_MBA_MAINT0_MAINT_BUFF3_DATA1_RO, // 3     DW7
        CEN_MBA_MAINT0_MAINT_BUFF1_DATA2_RO, // 4     DW9
        CEN_MBA_MAINT0_MAINT_BUFF3_DATA2_RO, // 5     DW11
        CEN_MBA_MAINT0_MAINT_BUFF1_DATA3_RO, // 6     DW13
        CEN_MBA_MAINT0_MAINT_BUFF3_DATA3_RO
    };// 7     DW15


    static const uint32_t maintBufferRead65thByteRegs[4] =
    {
        CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC0_RO,
        CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC1_RO,
        CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC2_RO,
        CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC3_RO
    };

    uint32_t loop = 0;
    fapi2::buffer<uint64_t> l_data;

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck());
    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType());
    // Load start address: MBMACAQ
    FAPI_TRY(loadStartAddress());
    // Load stop conditions: MBASCTLQ
    FAPI_TRY(loadStopCondMask());
    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd());
    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    FAPI_TRY(postConditionCheck());

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        FAPI_INF("EXIT Display::setupAndExecuteCmd()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete());

    //----------------------------------------------------
    // Read the data: 16 loops x 64bits = 128B cacheline
    //----------------------------------------------------
    FAPI_ERR("Read the data: 16 loops x 64bits = 128B cacheline");

    for(loop = 0; loop < NUM_BEATS; loop++ )
    {
        FAPI_TRY(fapi2::getScom(iv_target, maintBufferReadDataRegs[loop], l_data));
        FAPI_ERR("0x%X", l_data);
    }

    //----------------------------------------------------
    // Read the 65th byte: 4 loops
    //----------------------------------------------------
    FAPI_ERR("Read the 65th byte and ECC bits: 4 loops");

    for(loop = 0; loop < NUM_LOOPS_FOR_65TH_BYTE; loop++ )
    {
        FAPI_TRY(fapi2::getScom(iv_target, maintBufferRead65thByteRegs[loop], l_data));
        FAPI_ERR("0x%X", l_data);
    }

    // Collect FFDC
    FAPI_TRY(collectFFDC());
    FAPI_INF("EXIT Display::setupAndExecuteCmd()");

fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// Increment MBMACA Address
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_IncrementAddress::cv_cmd_type = INCREMENT_MBMACA_ADDRESS;

///
/// @brief IncrementAddress Constructor
/// @param[in] i_target          MBA target
///
mss_IncrementAddress::mss_IncrementAddress( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target ):

    mss_MaintCmd( i_target,
                  fapi2::buffer<uint64_t>(),  // i_start_addr not used for this cmd
                  fapi2::buffer<uint64_t>(),  // i_end_addr not used for this cmd
                  NO_STOP_CONDITIONS,   // i_stop_condition not used for this cmd
                  true,                    // i_poll always true for this cmd
                  cv_cmd_type) {}

///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_IncrementAddress::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_IncrementAddress::setupAndExecuteCmd()");

    fapi2::buffer<uint64_t> l_mbspa_mask;
    fapi2::buffer<uint64_t> l_mbspa_mask_original;
    fapi2::buffer<uint64_t> l_mbspa_and;
    fapi2::buffer<uint64_t> l_mbmacaq;

    // Read MBSPA MASK
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBSPAMSKQ, l_mbspa_mask));

    // Save original mask value so we can restore it when done
    l_mbspa_mask_original.insert<0, 64, 0>(l_mbspa_mask);

    // Mask bits 0 and 8, to hide the special attentions when the cmd completes
    l_mbspa_mask.setBit<0>();
    l_mbspa_mask.setBit<8>();

    // Write MBSPA MASK
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBSPAMSKQ, l_mbspa_mask));

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck());

    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType());

    // Read start address: MBMACAQ
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMACAQ, l_mbmacaq));

    FAPI_INF("MBMACAQ = 0x%X ", l_mbmacaq);

    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd());

    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    FAPI_TRY(postConditionCheck());

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete());

    // Read incremented start address: MBMACAQ
    FAPI_TRY(fapi2::getScom(iv_target, CEN_MBA_MBMACAQ, l_mbmacaq));

    // Clear bits 0 and 8 in MBSPA AND register
    l_mbspa_and.flush<1>();
    l_mbspa_and.clearBit<0>();
    l_mbspa_and.clearBit<8>();


    // Write MPSPA AND register
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBSPAQ_WOX_AND, l_mbspa_and));

    // Restore MBSPA MASK
    FAPI_TRY(fapi2::putScom(iv_target, CEN_MBA_MBSPAMSKQ, l_mbspa_mask_original));

    FAPI_INF("EXIT mss_IncrementAddress::setupAndExecuteCmd()");
fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// mss_TimeBaseScrub
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_TimeBaseScrub::cv_cmd_type = TIMEBASE_SCRUB;

///
/// @brief TimeBaseScrub Constructor
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
/// @param[in] i_end_addr,        Address cmd will stop at
/// @param[in] i_speed           TimeBase Speed
/// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
/// @param[in] i_poll            Set to true if you wait for command to complete
///
mss_TimeBaseScrub::mss_TimeBaseScrub( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const fapi2::buffer<uint64_t>& i_start_addr,
                                      const fapi2::buffer<uint64_t>& i_end_addr,
                                      const TimeBaseSpeed i_speed,
                                      const uint32_t i_stop_condition,
                                      const bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_start_addr,
                  i_end_addr,
                  i_stop_condition,
                  i_poll,
                  cv_cmd_type),

// NOTE: iv_speed is instance variable of TimeBaseScrub, since not
// needed in parent class
    iv_speed( i_speed )
{}



///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_TimeBaseScrub::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_TimeBaseScrub::setupAndExecuteCmd()");

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck(), "Failed preConditionCheck");

    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType(), "Failed loadCmdType");

    // Load start address: MBMACAQ
    FAPI_TRY(loadStartAddress(), "Failed loadStartAddress");

    // Load end address: MBMEAQ
    FAPI_TRY(loadEndAddress(), "Failed loadEndAddress");

    // Load speed: MBMCTQ
    FAPI_TRY(loadSpeed(iv_speed), "Failed loadSpeed");

    // Load stop conditions: MBASCTLQ
    FAPI_TRY(loadStopCondMask(), "Failed loadStopCondMask");

    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd(), "Failed startMaintCmd");

    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    FAPI_TRY(postConditionCheck(), "Failed postConditionCheck");

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        FAPI_INF("EXIT mss_TimeBaseScrub::setupAndExecuteCmd()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete(), "Failed pollForMaintCmdComplete");

    // Collect FFDC
    FAPI_TRY(collectFFDC(), "Failed collectFFDC");

    FAPI_INF("EXIT mss_TimeBaseScrub::setupAndExecuteCmd()");
fapi_try_exit:
    return fapi2::current_err;
}


//------------------------------------------------------------------------------
// mss_TimeBaseSteerCleanup
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_TimeBaseSteerCleanup::cv_cmd_type = TIMEBASE_STEER_CLEANUP;

///
/// @brief TimeBaseSteerCleanup Constructor
/// @param[in] i_target          MBA target
/// @param[in] i_start_addr       Address cmd will start at
/// @param[in] i_end_addr,        Address cmd will stop at
/// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
/// @param[in] i_speed           TimeBase speed
/// @param[in] i_poll            Set to true if you wait for command to complete
///
mss_TimeBaseSteerCleanup::mss_TimeBaseSteerCleanup( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const fapi2::buffer<uint64_t>& i_start_addr,
        const fapi2::buffer<uint64_t>& i_end_addr,
        const TimeBaseSpeed i_speed,
        const uint32_t i_stop_condition,
        const bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_start_addr,
                  i_end_addr,
                  i_stop_condition,
                  i_poll,
                  cv_cmd_type),

// NOTE: iv_speed is instance variable of TimeBaseSteerCleanup, since not
// needed in parent class
    iv_speed( i_speed )
{}



///
/// @brief  Saves any settings that need to be restored when command is done.
///         Loads the setup parameters into the hardware. Starts the command,
///         then either polls for complete or exits with command running.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_TimeBaseSteerCleanup::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_TimeBaseSteerCleanup::setupAndExecuteCmd()");

    // Make sure maint logic in valid state to run new cmd
    FAPI_TRY(preConditionCheck());

    // Load cmd type: MBMCTQ
    FAPI_TRY(loadCmdType());

    // Load start address: MBMACAQ
    FAPI_TRY(loadStartAddress());

    // Load end address: MBMEAQ
    FAPI_TRY(loadEndAddress());

    // Load speed: MBMCTQ
    FAPI_TRY(loadSpeed(iv_speed));

    // Load stop conditions: MBASCTLQ
    FAPI_TRY(loadStopCondMask());

    // Start the command: MBMCCQ
    FAPI_TRY(startMaintCmd());

    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    FAPI_TRY(postConditionCheck());

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        FAPI_INF("EXIT mss_TimeBaseSteerCleanup::setupAndExecuteCmd()");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Poll for command complete: MBMSRQ
    FAPI_TRY(pollForMaintCmdComplete());

    // Collect FFDC
    FAPI_TRY(collectFFDC());

    FAPI_INF("EXIT mss_TimeBaseSteerCleanup::setupAndExecuteCmd()");
fapi_try_exit:
    return fapi2::current_err;
}



//------------------------------------------------------------------------------
// Utility funcitons
//------------------------------------------------------------------------------

///
/// @brief  Calculates start and end address for a single rank, or all ranks behind the mba.
///
/// @param[in]  i_target       MBA target
/// @param[in]  i_rank         Either single rank on the MBA to get start/end address
///                        for (0x00-0x07)
///                        Or MSS_ALL_RANKS = 0xff to get start/end address for
///                        all ranks behind the MBA.
/// @param[out] o_start_addr    Address to start cmd at.
/// @param[out] o_end_addr      Address to stop cmd at.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_address_range( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint8_t i_rank,
        fapi2::buffer<uint64_t>& o_start_addr,
        fapi2::buffer<uint64_t>& o_end_addr )
{
    FAPI_INF("ENTER mss_get_address_range()");
    constexpr uint8_t NUM_CONFIG_TYPES = 9;
    constexpr uint8_t NUM_CONFIG_SUBTYPES = 4;
    constexpr uint8_t NUM_SLOT_CONFIGS = 2;
    static const uint8_t memConfigType[NUM_CONFIG_TYPES][NUM_CONFIG_SUBTYPES][NUM_SLOT_CONFIGS] =
    {

        // Refer to Centaur Workbook: 5.2 Master and Slave Rank Usage
        //
        //       SUBTYPE_A                    SUBTYPE_B                    SUBTYPE_C                    SUBTYPE_D
        //
        //SLOT_0_ONLY   SLOT_0_AND_1   SLOT_0_ONLY   SLOT_0_AND_1   SLOT_0_ONLY   SLOT_0_AND_1   SLOT_0_ONLY   SLOT_0_AND_1
        //
        //master slave  master slave   master slave  master slave   master slave  master slave   master slave  master slave
        //
        {{0xff,         0xff},         {0xff,        0xff},         {0xff,         0xff},       {0xff,         0xff}},  // TYPE_0
        {{0x00,         0x40},         {0x10,        0x50},         {0x30,         0x70},       {0xff,         0xff}},  // TYPE_1
        {{0x01,         0x41},         {0x03,        0x43},         {0x07,         0x47},       {0xff,         0xff}},  // TYPE_2
        {{0x11,         0x51},         {0x13,        0x53},         {0x17,         0x57},       {0xff,         0xff}},  // TYPE_3
        {{0x31,         0x71},         {0x33,        0x73},         {0x37,         0x77},       {0xff,         0xff}},  // TYPE_4
        {{0x00,         0x40},         {0x10,        0x50},         {0x30,         0x70},       {0xff,         0xff}},  // TYPE_5
        {{0x01,         0x41},         {0x03,        0x43},         {0x07,         0x47},       {0xff,         0xff}},  // TYPE_6
        {{0x11,         0x51},         {0x13,        0x53},         {0x17,         0x57},       {0xff,         0xff}},  // TYPE_7
        {{0x31,         0x71},         {0x33,        0x73},         {0x37,         0x77},       {0xff,         0xff}}
    }; // TYPE_8

    fapi2::buffer<uint64_t> l_data;
    mss_memconfig::MemOrg l_row;
    mss_memconfig::MemOrg l_col;
    mss_memconfig::MemOrg l_bank;
    uint32_t l_dramSize = 0;
    uint8_t l_dramWidth = 0;
    uint8_t l_mbaPosition = 0;
    uint8_t l_isSIM = 1;
    uint8_t l_slotConfig = 0;
    uint8_t l_configType = 0;
    uint8_t l_configSubType = 0;
    uint8_t l_end_master_rank = 0;
    uint8_t l_end_slave_rank = 0;
    uint8_t l_dram_gen = 0;

    // Get Centaur target for the given MBA
    const auto l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

    // Get MBA position: 0 = mba01, 1 = mba23
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

    // Check system attribute if sim: 1 = Awan/HWSimulator. 0 = Simics/RealHW.
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_isSIM));

    // Get l_dramWidth
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));

    // Get DDR3/DDR4: ATTR_EFF_DRAM_GEN
    // 0x01 = fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3
    // 0x02 = fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target,  l_dram_gen));

    // Check MBAXCRn, to show memory configured behind this MBA
    FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_mbaxcr[l_mbaPosition], l_data));

    FAPI_ASSERT((l_data.getBit<0, 4>()),
                fapi2::CEN_MSS_MAINT_NO_MEM_CNFG().
                set_MBA(i_target).
                set_MBAXCR(l_data),
                "MBAXCRn[0:3] = 0, meaning no memory configured behind this MBA on %s.", mss::c_str(i_target));

    //********************************************************************
    // Find max row/col/bank, based on l_dramSize and l_dramWidth
    //********************************************************************

    // Get l_dramSize
    l_data.extract < 6, 2, 32 - 2 > (l_dramSize); // (6:7)

    if((l_dramWidth == mss_memconfig::X8) &&
       (l_dramSize == mss_memconfig::GBIT_2) &&
       (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
    {
        // For memory part Size = 256Mbx8 (2Gb), row/col/bank = 15/10/3
        FAPI_INF("For memory part Size = 256Mbx8 (2Gb), row/col/bank = 15/10/3, DDR3");
        l_row =     mss_memconfig::ROW_15;
        l_col =     mss_memconfig::COL_10;
        l_bank =    mss_memconfig::BANK_3;
    }

    else if((l_dramWidth == mss_memconfig::X8) &&
            (l_dramSize == mss_memconfig::GBIT_2) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
    {
        // For memory part Size = 256Mbx8 (2Gb), row/col/bank = 14/10/4
        FAPI_INF("For memory part Size = 256Mbx8 (2Gb), row/col/bank = 14/10/4, DDR4");
        l_row =     mss_memconfig::ROW_14;
        l_col =     mss_memconfig::COL_10;
        l_bank =    mss_memconfig::BANK_4;
    }

    else if((l_dramWidth == mss_memconfig::X4) &&
            (l_dramSize == mss_memconfig::GBIT_2) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
    {
        // For memory part Size = 512Mbx4 (2Gb), row/col/bank = 15/11/3
        FAPI_INF("For memory part Size = 512Mbx4 (2Gb), row/col/bank = 15/11/3, DDR3");
        l_row =     mss_memconfig::ROW_15;
        l_col =     mss_memconfig::COL_11;
        l_bank =    mss_memconfig::BANK_3;
    }

    else if((l_dramWidth == mss_memconfig::X4) &&
            (l_dramSize == mss_memconfig::GBIT_2) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
    {
        // For memory part Size = 512Mbx4 (2Gb), row/col/bank = 15/10/4
        FAPI_INF("For memory part Size = 512Mbx4 (2Gb), row/col/bank = 15/10/4, DDR4");
        l_row =     mss_memconfig::ROW_15;
        l_col =     mss_memconfig::COL_10;
        l_bank =    mss_memconfig::BANK_4;
    }

    else if((l_dramWidth == mss_memconfig::X8) &&
            (l_dramSize == mss_memconfig::GBIT_4) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
    {
        // For memory part Size = 512Mbx8 (4Gb), row/col/bank = 16/10/3
        FAPI_INF("For memory part Size = 512Mbx8 (4Gb), row/col/bank = 16/10/3, DDR3");
        l_row =     mss_memconfig::ROW_16;
        l_col =     mss_memconfig::COL_10;
        l_bank =    mss_memconfig::BANK_3;
    }

    else if((l_dramWidth == mss_memconfig::X8) &&
            (l_dramSize == mss_memconfig::GBIT_4) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
    {
        // For memory part Size = 512Mbx8 (4Gb), row/col/bank = 14/10/4
        FAPI_INF("For memory part Size = 512Mbx8 (4Gb), row/col/bank = 14/10/4, DDR4");
        l_row =     mss_memconfig::ROW_15;
        l_col =     mss_memconfig::COL_10;
        l_bank =    mss_memconfig::BANK_4;
    }


    else if((l_dramWidth == mss_memconfig::X4) &&
            (l_dramSize == mss_memconfig::GBIT_4) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
    {
        // For memory part Size = 1Gbx4 (4Gb), row/col/bank = 16/11/3
        FAPI_INF("For memory part Size = 1Gbx4 (4Gb), row/col/bank = 16/11/3, DDR3");
        l_row =     mss_memconfig::ROW_16;
        l_col =     mss_memconfig::COL_11;
        l_bank =     mss_memconfig::BANK_3;
    }

    else if((l_dramWidth == mss_memconfig::X4) &&
            (l_dramSize == mss_memconfig::GBIT_4) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
    {
        // For memory part Size = 1Gbx4 (4Gb), row/col/bank = 16/10/4
        FAPI_INF("For memory part Size = 1Gbx4 (4Gb), row/col/bank = 16/10/4, DDR4");
        l_row =     mss_memconfig::ROW_16;
        l_col =     mss_memconfig::COL_10;
        l_bank =     mss_memconfig::BANK_4;
    }

    else if((l_dramWidth == mss_memconfig::X8) &&
            (l_dramSize == mss_memconfig::GBIT_8) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
    {
        // For memory part Size = 1Gbx8 (8Gb), row/col/bank = 16/11/3
        FAPI_INF("For memory part Size = 1Gbx8 (8Gb), row/col/bank = 16/11/3, DDR3");
        l_row =     mss_memconfig::ROW_16;
        l_col =     mss_memconfig::COL_11;
        l_bank =     mss_memconfig::BANK_3;
    }

    else if((l_dramWidth == mss_memconfig::X8) &&
            (l_dramSize == mss_memconfig::GBIT_8) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
    {
        // For memory part Size = 1Gbx8 (8Gb), row/col/bank = 16/10/4
        FAPI_INF("For memory part Size = 1Gbx8 (8Gb), row/col/bank = 16/10/4, DDR4");
        l_row =     mss_memconfig::ROW_16;
        l_col =     mss_memconfig::COL_10;
        l_bank =     mss_memconfig::BANK_4;
    }


    else if((l_dramWidth == mss_memconfig::X4) &&
            (l_dramSize == mss_memconfig::GBIT_8) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
    {
        // For memory part Size = 2Gbx4 (8Gb), row/col/bank = 16/12/3
        FAPI_INF("For memory part Size = 2Gbx4 (8Gb), row/col/bank = 16/12/3, DDR3");
        l_row =     mss_memconfig::ROW_16;
        l_col =     mss_memconfig::COL_12;
        l_bank =     mss_memconfig::BANK_3;
    }

    else if((l_dramWidth == mss_memconfig::X4) &&
            (l_dramSize == mss_memconfig::GBIT_8) &&
            (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
    {
        // For memory part Size = 2Gbx4 (8Gb), row/col/bank = 17/10/4
        FAPI_INF("Forosr memory part Size = 2Gbx4 (8Gb), row/col/bank = 17/10/4, DDR4");
        l_row =     mss_memconfig::ROW_17;
        l_col =     mss_memconfig::COL_10;
        l_bank =     mss_memconfig::BANK_4;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_DRAM_SIZE_WIDTH().
                    set_MBA(i_target).
                    set_MBAXCR(l_data).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_DRAM_GEN(l_dram_gen),
                    "Invalid l_dramSize = %d or l_dramWidth = %d in MBAXCRn, or l_dram_gen = %d on %s.",
                    l_dramSize, l_dramWidth, l_dram_gen, mss::c_str(i_target));
    }


//********************************************************************
// Find l_end_master_rank and l_end_slave_rank based on DIMM configuration
//********************************************************************

// (0:3) Configuration type (1-8)
    l_data.extract < 0, 4, 8 - 4 > (l_configType);

// (4:5) Configuration subtype (A, B, C, D)
    l_data.extract < 4, 2, 8 - 2 > (l_configSubType);

// (8)   Slot Configuration
// 0 = Centaur DIMM or IS DIMM, slot0 only, 1 = IS DIMM slots 0 and 1
    l_data.extract < 8, 1, 8 - 1 > (l_slotConfig);

    FAPI_INF("memConfigType[%d][%d][%d] = 0x%02x",
             l_configType, l_configSubType, l_slotConfig,
             memConfigType[l_configType][l_configSubType][l_slotConfig]);

    l_end_master_rank = (memConfigType[l_configType][l_configSubType][l_slotConfig] & 0xf0) >> 4;
    l_end_slave_rank = memConfigType[l_configType][l_configSubType][l_slotConfig] & 0x0f;

    FAPI_INF("end master rank = %d, end slave rank = %d", l_end_master_rank, l_end_slave_rank);

    FAPI_ASSERT((l_end_master_rank != 0x0f) && (l_end_slave_rank != 0x0f),
                fapi2::CEN_MSS_MAINT_INVALID_DIMM_CNFG().
                set_MBA(i_target).
                set_MBAXCR(l_data),
                "MBAXCRn configured with unsupported combination of l_configType, l_configSubType, l_slotConfig on %s.",
                mss::c_str(i_target));

    //********************************************************************
    // Get address range for all ranks configured behind this MBA
    //********************************************************************
    if (i_rank == MSS_ALL_RANKS)
    {
        FAPI_INF("Get address range for rank = ALL_RANKS");

        // Start address is just rank 0 with row/col/bank all 0's
        o_start_addr.flush<0>();

        // If Awan/HWSimulator, end address is just start address +3
        if (l_isSIM)
        {
            FAPI_INF("ATTR_IS_SIMULATION = 1, Awan/HWSimulator, so use smaller address range.");

            // Do only rank0, row0, all banks all cols
            l_end_master_rank = 0;
            l_end_slave_rank = 0;

            uint32_t l_row_zero = 0;
            o_end_addr.flush<0>();

            // MASTER RANK = 0:3
            o_end_addr.insert < 0, 4, 8 - 4 > (l_end_master_rank);

            // SLAVE RANK = 4:6
            o_end_addr.insert < 4, 3, 8 - 3 > (l_end_slave_rank);

            // BANK = 7:10
            o_end_addr.insert < 7, 4, 32 - 4 > ((uint32_t)l_bank);

            // ROW = 11:27
            o_end_addr.insert < 11, 17, 32 - 17 > ((uint32_t)l_row_zero);

            // COL = 28:39, note: c2, c1, c0 always 0
            o_end_addr.insert < 28, 12, 32 - 12 > ((uint32_t)l_col);
        }
        // Else, set end address to be last address of l_end_master_rank
        else
        {
            o_end_addr.flush<0>();

            // MASTER RANK = 0:3
            o_end_addr.insert < 0, 4, 8 - 4 > (l_end_master_rank);

            // SLAVE RANK = 4:6
            o_end_addr.insert < 4, 3, 8 - 3 > (l_end_slave_rank);

            // BANK = 7:10
            o_end_addr.insert < 7, 4, 32 - 4 > ((uint32_t)l_bank);

            // ROW = 11:27
            o_end_addr.insert < 11, 17, 32 - 17 > ((uint32_t)l_row);

            // COL = 28:39, note: c2, c1, c0 always 0
            o_end_addr.insert < 28, 12, 32 - 12 > ((uint32_t)l_col);
        }
    }
    //********************************************************************
    // Get address range for single rank configured behind this MBA
    //********************************************************************
    else
    {
        FAPI_INF("Get address range for master rank = %d\n", i_rank );

        // Check for i_rank out of range
        FAPI_ASSERT(i_rank < MAX_RANKS_PER_PORT,
                    fapi2::CEN_MSS_MAINT_GET_ADDRESS_RANGE_BAD_INPUT().
                    set_MBA(i_target).
                    set_RANK(i_rank),
                    "i_rank input to mss_get_address_range out of range on %s.", mss::c_str(i_target));

        // NOTE: If this rank is not valid, we should see MBAFIR[1]: invalid
        // maint address, when cmd started

        // Start address is just i_rank with row/col/bank all 0's
        o_start_addr.flush<0>();

        // MASTER RANK = 0:3
        o_start_addr.insert < 0, 4, 8 - 4 > (i_rank);

        // If Awan/HWSimulator, end address is just start address +3
        if (l_isSIM)
        {
            FAPI_INF("ATTR_IS_SIMULATION = 1, Awan/HWSimulator, so use smaller address range.");

            l_end_slave_rank = 0;

            uint32_t l_row_zero = 0;
            o_end_addr.flush<0>();
            // MASTER RANK = 0:3
            o_end_addr.insert < 0, 4, 8 - 4 > (i_rank);
            // SLAVE RANK = 4:6
            o_end_addr.insert < 4, 3, 8 - 3 > (l_end_slave_rank);
            // BANK = 7:10
            o_end_addr.insert < 7, 4, 32 - 4 > ((uint32_t)l_bank);
            // ROW = 11:27
            o_end_addr.insert < 11, 17, 32 - 17 > ((uint32_t)l_row_zero);
            // COL = 28:39, note: c2, c1, c0 always 0
            o_end_addr.insert < 28, 12, 32 - 12 > ((uint32_t)l_col);

        }
        // Else, set end address to be last address of i_rank
        else
        {
            o_end_addr.flush<0>();
            // MASTER RANK = 0:3
            o_end_addr.insert < 0, 4, 8 - 4 > (i_rank);
            // SLAVE RANK = 4:6
            o_end_addr.insert < 4, 3, 8 - 3 > (l_end_slave_rank);
            // BANK = 7:10
            o_end_addr.insert < 7, 4, 32 - 4 > ((uint32_t)l_bank);
            // ROW = 11:27
            o_end_addr.insert < 11, 17, 32 - 17 > ((uint32_t)l_row);
            // COL = 28:36
            o_end_addr.insert < 28, 12, 32 - 12 > ((uint32_t)l_col);
        }

    }




    FAPI_INF("EXIT mss_get_address_range()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Calculates start and end address for a single slave rank
///
/// @param[in]  i_target       MBA target
/// @param[in]  i_master        master rank corresponding to the desired slave rank on the MBA to get start/end address
///                        for (0x00-0x07)
/// @param[in]  i_slave         Slave rank to get the address range for
/// @param[out] o_start_addr    Address to start cmd at.
/// @param[out] o_end_addr      Address to stop cmd at.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_slave_address_range( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint8_t i_master,
        const uint8_t i_slave,
        fapi2::buffer<uint64_t>& o_start_addr,
        fapi2::buffer<uint64_t>& o_end_addr )
{
    FAPI_INF("ENTER mss_get_slave_address_range()");
    FAPI_TRY(mss_get_address_range(i_target, i_master, o_start_addr, o_end_addr));
    //START SLAVE RANK = 4:6
    o_start_addr.insert < 4, 3, 8 - 3 > (i_slave);
    //END SLAVE RANK = 4:6
    o_end_addr.insert < 4, 3, 8 - 3 > (i_slave);

    FAPI_INF("EXIT mss_get_slave_address_range()");
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief  Mark store is implemented as one register per rank, so read register for the rank.
///
///         If MPE FIR for the given rank (scrub or fetch) is on after the read,
///         we will read one more time to make sure we get latest.
///
/// @param[in]  i_target        MBA target
/// @param[in]  i_rank          Rank to get markstore for.
/// @param[out] o_symbolMark    Symbol mark, converted from galois field to symbol
///                         index,(if no mark return 0xff)
/// @param[out] o_chipMark      Chip mark, converted from galois field to first
///                         symbol index of the chip, (if no mark return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const uint8_t i_rank,
                                      uint8_t& o_symbolMark,
                                      uint8_t& o_chipMark )
{
    fapi2::buffer<uint64_t> l_markstore;
    fapi2::buffer<uint64_t> l_mbeccfir;
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dramWidth = 0;
    uint8_t l_symbolMarkGalois = 0;
    uint8_t l_chipMarkGalois = 0;
    uint8_t l_symbolsPerChip = 4;
    uint8_t l_mbaPosition = 0;
    fapi2::buffer<uint64_t> l_mbscfg;
    uint8_t l_dd2_enable_exit_point_1 = 0;

    o_symbolMark = MSS_INVALID_SYMBOL;
    o_chipMark = MSS_INVALID_SYMBOL;

    // Get Centaur target for the given MBA
    const auto l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

    // Get MBA position: 0 = mba01, 1 = mba23
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

    // Get l_dramWidth
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));

    // Check for i_rank out of range
    FAPI_ASSERT( i_rank < MAX_RANKS_PER_PORT,
                 fapi2::CEN_MSS_MAINT_GET_MARK_STORE_BAD_INPUT().
                 set_MBA(i_target).
                 set_RANK(i_rank),
                 "i_rank input to mss_get_mark_store out of range on %s.", mss::c_str(i_target));

    // Read markstore register for the given rank
    FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_markstore_regs[i_rank][l_mbaPosition], l_markstore));

    // If MPE FIR for the given rank (scrub or fetch) is on after the read,
    // we will read one more time just to make sure we get latest.
    FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_mbeccfir[l_mbaPosition], l_mbeccfir));

    if (l_mbeccfir.getBit(i_rank) || l_mbeccfir.getBit(20 + i_rank))
    {
        FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_markstore_regs[i_rank][l_mbaPosition], l_markstore));
    }

    // Get l_symbolMarkGalois
    l_markstore.extract < 0, 8, 8 - 8 > (l_symbolMarkGalois);

    if (l_symbolMarkGalois == 0x00) // No symbol mark
    {
        o_symbolMark = MSS_INVALID_SYMBOL;
    }
    else if (l_dramWidth == mss_memconfig::X4)
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_X4_SYMBOL_ON_READ().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_MARKSTORE(l_markstore),
                    "l_symbolMarkGalois invalid: symbol mark not allowed in x4 mode on %s.", mss::c_str(i_target));
    }
    else // Converted from galois field to symbol index
    {
        o_symbolMark = MSS_SYMBOLS_PER_RANK;

        for ( uint32_t i = 0; i < MSS_SYMBOLS_PER_RANK; i++ )
        {
            if ( l_symbolMarkGalois == mss_symbol2Galois[i] )
            {
                o_symbolMark = i;
                break;
            }
        }

        FAPI_ASSERT(MSS_SYMBOLS_PER_RANK > o_symbolMark,
                    fapi2::CEN_MSS_MAINT_INVALID_MARKSTORE().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_MARKSTORE(l_markstore),
                    "Invalid galois field in markstore on %s.", mss::c_str(i_target));
    }

    // Get l_chipMarkGalois
    l_markstore.extract < 8, 8, 8 - 8 > (l_chipMarkGalois);

    if (l_chipMarkGalois == 0x00) // No chip mark
    {
        o_chipMark = MSS_INVALID_SYMBOL;
    }
    else // Converted from galois field to chip index
    {

        if (l_dramWidth == mss_memconfig::X4)
        {
            l_symbolsPerChip = 2;
        }
        else if (l_dramWidth == mss_memconfig::X8)
        {
            l_symbolsPerChip = 4;
        }

        o_chipMark = MSS_SYMBOLS_PER_RANK;

        for ( uint32_t i = 0; i < MSS_SYMBOLS_PER_RANK; i = i + l_symbolsPerChip)
        {
            if ( l_chipMarkGalois == mss_symbol2Galois[i] )
            {
                o_chipMark = i;
                break;
            }
        }

        // TODO: create error if x4 mode and symbol 0,1?
        FAPI_ASSERT( MSS_SYMBOLS_PER_RANK > o_chipMark,
                     fapi2::CEN_MSS_MAINT_INVALID_MARKSTORE().
                     set_MBA(i_target).
                     set_DRAM_WIDTH(l_dramWidth).
                     set_RANK(i_rank).
                     set_MARKSTORE(l_markstore),
                     "Invalid galois field in markstore on %s.", mss::c_str(i_target));
    }

    // Get attribute that tells we have cen DD2, and can enable exit poing 1
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_DD2_ENABLE_EXIT_POINT_1, l_targetCentaur,
                           l_dd2_enable_exit_point_1));

    if(l_dd2_enable_exit_point_1)
    {
        // If valid chip or symbol mark, enable exit point 1
        if ((o_chipMark != MSS_INVALID_SYMBOL) || (o_symbolMark != MSS_INVALID_SYMBOL))
        {
            // Read MBSCFGQ
            FAPI_TRY(fapi2::getScom(l_targetCentaur, CEN_MBSCFGQ, l_mbscfg));
            l_mbscfg.setBit<0>();
            // Write MBSCFGQ
            FAPI_TRY(fapi2::putScom(l_targetCentaur, CEN_MBSCFGQ, l_mbscfg));
        }
    }


    FAPI_INF("mss_get_mark_store(): rank%d, chip mark = %d, symbol mark = %d",
             i_rank, o_chipMark, o_symbolMark );
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief  Mark store is implemented as one register per rank, so write register for the rank
///
///         NOTE: Will be writing to both chip and symbol
///         field at same time, so should use a read/modify/write approach to
///         avoid unintentionally over-writing something.
///
/// @param[in]  i_target       MBA target
/// @param[in]  i_rank         Rank to write markstore for.
/// @param[in]  i_symbolMark   Symbol index, which will be converted to galois field
///                        (if input is 0xff, we write 0x00 for no symbol mark).
/// @param[in]  i_chipMark     First symbol index of the chip, which will be
///                        converted to galois field (if input is 0xff, we write
///                        0x00 for no chip mark).
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_put_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const uint8_t i_rank,
                                      const uint8_t i_symbolMark,
                                      const uint8_t i_chipMark )
{
    FAPI_INF("ENTER mss_put_mark_store()");
    fapi2::buffer<uint64_t> l_markstore;
    fapi2::buffer<uint64_t> l_mbeccfir;
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dramWidth = 0;
    uint8_t l_symbolMarkGalois = 0;
    uint8_t l_chipMarkGalois = 0;
    uint8_t l_mbaPosition = 0;
    uint8_t l_rank_index = 0;
    bool l_exit_point_1_needed = false;
    fapi2::buffer<uint64_t> l_mbscfg;
    uint8_t l_dd2_enable_exit_point_1 = 0;

    // Get Centaur target for the given MBA
    const auto l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

    // Get MBA position: 0 = mba01, 1 = mba23
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

    // Get l_dramWidth
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));
    // Check for i_rank out of range
    FAPI_ASSERT( i_rank < MAX_RANKS_PER_PORT,
                 fapi2::CEN_MSS_MAINT_PUT_MARK_STORE_BAD_INPUT().
                 set_MBA(i_target).
                 set_RANK(i_rank),
                 "i_rank input to mss_put_mark_store out of range on %s.", mss::c_str(i_target));


    // Get l_symbolMarkGalois
    if (i_symbolMark == MSS_INVALID_SYMBOL) // No symbol mark
    {
        l_symbolMarkGalois = 0x00;
    }
    else if ( l_dramWidth == mss_memconfig::X4 )
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_X4_SYMBOL_ON_WRITE().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_SYMBOL_MARK(i_symbolMark).
                    set_CHIP_MARK(i_chipMark),
                    "i_symbolMark invalid: symbol mark not allowed in x4 mode on %s.", mss::c_str(i_target));

    }
    else if ( MSS_SYMBOLS_PER_RANK <= i_symbolMark )
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_SYMBOL_INDEX().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_SYMBOL_MARK(i_symbolMark).
                    set_CHIP_MARK(i_chipMark),
                    "i_symbolMark invalid: symbol index out of range on %s.", mss::c_str(i_target));
    }
    else // Convert from symbol index to galois field
    {
        l_symbolMarkGalois = mss_symbol2Galois[i_symbolMark];
    }

    l_markstore.insert<0, 8, 0>(l_symbolMarkGalois);

    // Get l_chipMarkGalois
    if (i_chipMark == MSS_INVALID_SYMBOL) // No chip mark
    {
        l_chipMarkGalois = 0x00;
    }
    else if ( MSS_SYMBOLS_PER_RANK <= i_chipMark )
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_SYMBOL_INDEX().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_SYMBOL_MARK(i_symbolMark).
                    set_CHIP_MARK(i_chipMark),
                    "i_chipMark invalid: symbol index out of range on %s.", mss::c_str(i_target));
    }
    else if ((l_dramWidth == mss_memconfig::X8) && (i_chipMark % 4) )
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_CHIP_INDEX().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_SYMBOL_MARK(i_symbolMark).
                    set_CHIP_MARK(i_chipMark),
                    "i_chipMark invalid: not first symbol index of a x8 chip on %s.", mss::c_str(i_target));
    }
    else if ((l_dramWidth == mss_memconfig::X4) && (i_chipMark % 2) )
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_CHIP_INDEX().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_SYMBOL_MARK(i_symbolMark).
                    set_CHIP_MARK(i_chipMark),
                    "i_chipMark invalid: not first symbol index of a x4 chip on %s.", mss::c_str(i_target));

    }
    // TODO: create error if x4 mode and symbol 0,1?
    else // Convert from symbol index to galois field
    {
        l_chipMarkGalois = mss_symbol2Galois[i_chipMark];
    }

    l_markstore.insert<8, 8, 0>(l_chipMarkGalois);

    // Write markstore register for the given rank
    FAPI_TRY(fapi2::putScom(l_targetCentaur, mss_markstore_regs[i_rank][l_mbaPosition], l_markstore));

    // If MPE FIR for the given rank (scrub or fetch) is on after the write,
    // we will return a fapi2::ReturnCode to indicate write may not have worked.
    // Up to caller to read again if they want to see what new chip mark is.
    FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_mbeccfir[l_mbaPosition], l_mbeccfir));

    if (l_mbeccfir.getBit(i_rank) || l_mbeccfir.getBit(20 + i_rank))
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_MARKSTORE_WRITE_BLOCKED().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_SYMBOL_MARK(i_symbolMark).
                    set_CHIP_MARK(i_chipMark).
                    set_MBECCFIR(l_mbeccfir),
                    "Markstore write may have been blocked due to MPE FIR set on %s.", mss::c_str(i_target));
    }

    // Get attribute that tells we have cen DD2, and can enable exit poing 1
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_DD2_ENABLE_EXIT_POINT_1, l_targetCentaur,
                           l_dd2_enable_exit_point_1));

    if(l_dd2_enable_exit_point_1)
    {
        // Read all mark store for both MBAs
        for ( l_mbaPosition = 0; l_mbaPosition < MAX_MBA_PER_CEN; l_mbaPosition++)
        {
            for ( l_rank_index = 0; l_rank_index < MAX_RANKS_PER_PORT; l_rank_index++ )
            {
                FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_markstore_regs[l_rank_index][l_mbaPosition], l_markstore));

                if (l_markstore.getBit<0, 16>())
                {
                    // Mark found, so exit point 1 needed
                    l_exit_point_1_needed = true;
                    break;
                }
            }

            if (l_exit_point_1_needed)
            {
                break;
            }
        }

        // Read MBSCFGQ
        FAPI_TRY(fapi2::getScom(l_targetCentaur, CEN_MBSCFGQ, l_mbscfg));

        // Enable exit point 1
        if (l_exit_point_1_needed)
        {
            l_mbscfg.setBit<0>();
        }
        // Else, disable exit point 1
        else
        {
            l_mbscfg.clearBit<0>();
        }

        // Write MBSCFGQ
        FAPI_TRY(fapi2::putScom(l_targetCentaur, CEN_MBSCFGQ, l_mbscfg));

    } // End if l_dd2_enable_exit_point_1

    FAPI_INF("EXIT mss_put_mark_store()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Gets either the read or write steer mux control register for the given rank
///
///         Converts from steer code to x8/x4 dram index to
///         first symbol index for all DRAMs steered on that rank.
///
/// @param[in]  i_target                 MBA target
/// @param[in]  i_rank                   Rank we want to read steer mux for.
/// @param[in]  i_mux_type                Select either the read mux or the write mux
///                                  to get.
/// @param[out] o_dramSparePort0Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dramSparePort1Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @param[out] o_eccSpareSymbol         First symbol index of the DRAM fixed by the
///                                  ECC spare, which can be used on either port0
///                                  or port1 (if no steer, return 0xff)
/// @note   The ECC spare is available only with x4 mode ECC.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_rank,
                                     const mss_SteerMux::mux_type i_mux_type,
                                     uint8_t& o_dramSparePort0Symbol,
                                     uint8_t& o_dramSparePort1Symbol,
                                     uint8_t& o_eccSpareSymbol )
{
    fapi2::buffer<uint64_t> l_steerMux;
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dramWidth = 0;
    uint8_t l_dramSparePort0Index = 0;
    uint8_t l_dramSparePort1Index = 0;
    uint8_t l_eccSpareIndex = 0;
    uint8_t l_mbaPosition = 0;

    o_dramSparePort0Symbol = MSS_INVALID_SYMBOL;
    o_dramSparePort1Symbol = MSS_INVALID_SYMBOL;
    o_eccSpareSymbol = MSS_INVALID_SYMBOL;

    // Get Centaur target for the given MBA
    const auto l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

    // Get MBA position: 0 = mba01, 1 = mba23
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

    // Get l_dramWidth
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));

    // Check for i_rank or i_mux_type out of range
    if ((i_rank >= 8) ||
        !((i_mux_type == mss_SteerMux::READ_MUX) || (i_mux_type == mss_SteerMux::WRITE_MUX)))
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_GET_STEER_MUX_BAD_INPUT().
                    set_MBA(i_target).
                    set_RANK(i_rank).
                    set_MUX_TYPE(i_mux_type),
                    "i_rank or i_mux_type input to mss_get_steer_mux out of range on %s.", mss::c_str(i_target));
    }

    // Read steer mux register for the given rank and mux type (read or write).
    if (i_mux_type == mss_SteerMux::READ_MUX)
    {
        // Read muxes are in the MBS
        FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_readMuxRegs[i_rank][l_mbaPosition], l_steerMux));
    }
    else
    {
        // Write muxes are in the MBA
        FAPI_TRY(fapi2::getScom(i_target, mss_writeMuxRegs[i_rank], l_steerMux));
    }

    // Get l_dramSparePort0Index
    l_steerMux.extract < 0, 5, 8 - 5 > (l_dramSparePort0Index);


    // Get o_dramSparePort0Symbol if index in valid range
    if ((l_dramWidth == mss_memconfig::X8) && (l_dramSparePort0Index < MSS_X8_STEER_OPTIONS_PER_PORT))
    {
        o_dramSparePort0Symbol = mss_x8dramSparePort0Index_to_symbol[l_dramSparePort0Index];
    }
    else if ((l_dramWidth == mss_memconfig::X4) && (l_dramSparePort0Index < MSS_X4_STEER_OPTIONS_PER_PORT0))
    {
        o_dramSparePort0Symbol = mss_x4dramSparePort0Index_to_symbol[l_dramSparePort0Index];
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_STEER_MUX().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_MUX_TYPE(i_mux_type).
                    set_STEER_MUX(l_steerMux),
                    "Steer mux l_dramSparePort0Index out of range on %s.", mss::c_str(i_target));
    }

    // Get l_dramSparePort1Index
    l_steerMux.extract < 5, 5, 8 - 5 > (l_dramSparePort1Index);

    // Get o_dramSparePort1Symbol if index in valid range
    if ((l_dramWidth == mss_memconfig::X8) && (l_dramSparePort1Index < MSS_X8_STEER_OPTIONS_PER_PORT))
    {
        o_dramSparePort1Symbol = mss_x8dramSparePort1Index_to_symbol[l_dramSparePort1Index];
    }
    else if ((l_dramWidth == mss_memconfig::X4) && (l_dramSparePort1Index < MSS_X4_STEER_OPTIONS_PER_PORT1))
    {
        o_dramSparePort1Symbol = mss_x4dramSparePort1Index_to_symbol[l_dramSparePort1Index];
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_STEER_MUX().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_MUX_TYPE(i_mux_type).
                    set_STEER_MUX(l_steerMux),
                    "Steer mux l_dramSparePort1Index out of range on %s.", mss::c_str(i_target));
    }

    // Get l_eccSpareIndex
    l_steerMux.extract < 10, 6, 8 - 6 > (l_eccSpareIndex);

    // Get o_eccSpareSymbol if index in valid range
    if (l_eccSpareIndex < MSS_X4_ECC_STEER_OPTIONS)
    {
        o_eccSpareSymbol = mss_eccSpareIndex_to_symbol[l_eccSpareIndex];
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_INVALID_STEER_MUX().
                    set_MBA(i_target).
                    set_DRAM_WIDTH(l_dramWidth).
                    set_RANK(i_rank).
                    set_MUX_TYPE(i_mux_type).
                    set_STEER_MUX(l_steerMux),
                    "o_eccSpareSymbol out of range on %s.", mss::c_str(i_target));
    }

    FAPI_INF("mss_get_steer_mux(): rank%d, port0 steer = %d, port1 steer = %d, ecc steer = %d",
             i_rank, o_dramSparePort0Symbol, o_dramSparePort1Symbol, o_eccSpareSymbol );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Updates the read or write steer mux control register with the steer type for the rank.
///
///
/// @param[in]  i_target                MBA target
/// @param[in]  i_rank                  Rank we want to write steer mux for.
/// @param[in]  i_mux_type               Select either the read mux or the write mux
///                                 to update.
/// @param[in]  i_steer_type             0 = DRAM_SPARE_PORT0, Spare DRAM on port0
///                                 1 = DRAM_SPARE_PORT1, Spare DRAM on port1
///                                 2 = ECC_SPARE, ECC spare (used in x4 mode only)
/// @param[in]  i_symbol                First symbol index of the DRAM to steer
///                                 around.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_put_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_rank,
                                     const mss_SteerMux::mux_type i_mux_type,
                                     const uint8_t i_steer_type,
                                     const uint8_t i_symbol )
{
    FAPI_INF("ENTER mss_put_steer_mux()");
    fapi2::buffer<uint64_t> l_steerMux;
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_dramWidth = 0;
    uint8_t l_dramSparePort0Index = 0;
    uint8_t l_dramSparePort1Index = 0;
    uint8_t l_eccSpareIndex = 0;
    uint8_t l_mbaPosition = 0;

    // Get Centaur target for the given MBA
    const auto l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

    // Get MBA position: 0 = mba01, 1 = mba23
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));

    // Get l_dramWidth
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));

    // Check for i_rank or i_mux_type or i_steer_type or i_symbol out of range
    if ((i_rank >= 8) ||
        !((i_mux_type == mss_SteerMux::READ_MUX) || (i_mux_type == mss_SteerMux::WRITE_MUX)) ||
        !((i_steer_type == mss_SteerMux::DRAM_SPARE_PORT0) || (i_steer_type == mss_SteerMux::DRAM_SPARE_PORT1)
          || (i_steer_type == mss_SteerMux::ECC_SPARE)) ||
        (i_symbol >= 72))
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_PUT_STEER_MUX_BAD_INPUT().
                    set_MBA(i_target).
                    set_RANK(i_rank).
                    set_MUX_TYPE(i_mux_type).
                    set_STEER_TYPE(i_steer_type).
                    set_SYMBOL(i_symbol),
                    "i_rank or i_mux_type or i_steer_type or i_symbol input to mss_get_steer_mux out of range on %s.",
                    mss::c_str(i_target));
    }

    // TODO: add error if ecc_spare and symbol is 0 or 1?


    // Read steer mux register for the given rank and mux type (read or write).
    if (i_mux_type == mss_SteerMux::READ_MUX)
    {
        // Read muxes are in the MBS
        FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_readMuxRegs[i_rank][l_mbaPosition], l_steerMux));
    }
    else
    {
        // Write muxes are in the MBA
        FAPI_TRY(fapi2::getScom(i_target, mss_writeMuxRegs[i_rank], l_steerMux));
    }

    // Convert from i_symbol to l_dramSparePort0Index
    if (i_steer_type == mss_SteerMux::DRAM_SPARE_PORT0)
    {
        if (l_dramWidth == mss_memconfig::X8)
        {
            l_dramSparePort0Index = MSS_X8_STEER_OPTIONS_PER_PORT;

            for ( uint32_t i = 0; i < MSS_X8_STEER_OPTIONS_PER_PORT; i++ )
            {
                if ( i_symbol == mss_x8dramSparePort0Index_to_symbol[i] )
                {
                    l_dramSparePort0Index = i;
                    break;
                }
            }

            FAPI_ASSERT(MSS_X8_STEER_OPTIONS_PER_PORT > l_dramSparePort0Index,
                        fapi2::CEN_MSS_MAINT_INVALID_SYMBOL_TO_STEER().
                        set_MBA(i_target).
                        set_DRAM_WIDTH(l_dramWidth).
                        set_RANK(i_rank).
                        set_MUX_TYPE(i_mux_type).
                        set_STEER_TYPE(i_steer_type).
                        set_SYMBOL(i_symbol),
                        "No match for i_symbol = %d in mss_x8dramSparePort0Index_to_symbol[] on %s.", i_symbol,
                        mss::c_str(i_target));
        }

        else if (l_dramWidth == mss_memconfig::X4)
        {
            l_dramSparePort0Index = MSS_X4_STEER_OPTIONS_PER_PORT0;

            for ( uint32_t i = 0; i < MSS_X4_STEER_OPTIONS_PER_PORT0; i++ )
            {
                if ( i_symbol == mss_x4dramSparePort0Index_to_symbol[i] )
                {
                    l_dramSparePort0Index = i;
                    break;
                }
            }

            FAPI_ASSERT(MSS_X4_STEER_OPTIONS_PER_PORT0 > l_dramSparePort0Index,
                        fapi2::CEN_MSS_MAINT_INVALID_SYMBOL_TO_STEER().
                        set_MBA(i_target).
                        set_DRAM_WIDTH(l_dramWidth).
                        set_RANK(i_rank).
                        set_MUX_TYPE(i_mux_type).
                        set_STEER_TYPE(i_steer_type).
                        set_SYMBOL(i_symbol),
                        "No match for i_symbol in mss_x4dramSparePort0Index_to_symbol[] on %s.", mss::c_str(i_target));
        }

        l_steerMux.insert < 0, 5, 8 - 5 > (l_dramSparePort0Index);
    }


    // Convert from i_symbol to l_dramSparePort1Index
    if (i_steer_type == mss_SteerMux::DRAM_SPARE_PORT1)
    {
        if (l_dramWidth == mss_memconfig::X8)
        {
            l_dramSparePort1Index = MSS_X8_STEER_OPTIONS_PER_PORT;

            for ( uint32_t i = 0; i < MSS_X8_STEER_OPTIONS_PER_PORT; i++ )
            {
                if ( i_symbol == mss_x8dramSparePort1Index_to_symbol[i] )
                {
                    l_dramSparePort1Index = i;
                    break;
                }
            }

            FAPI_ASSERT(MSS_X8_STEER_OPTIONS_PER_PORT > l_dramSparePort1Index,
                        fapi2::CEN_MSS_MAINT_INVALID_SYMBOL_TO_STEER().
                        set_MBA(i_target).
                        set_DRAM_WIDTH(l_dramWidth).
                        set_RANK(i_rank).
                        set_MUX_TYPE(i_mux_type).
                        set_STEER_TYPE(i_steer_type).
                        set_SYMBOL(i_symbol),
                        "No match for i_symbol in mss_x8dramSparePort1Index_to_symbol[] on %s.", mss::c_str(i_target));
        }

        else if (l_dramWidth == mss_memconfig::X4)
        {
            l_dramSparePort1Index = MSS_X4_STEER_OPTIONS_PER_PORT1;

            for ( uint32_t i = 0; i < MSS_X4_STEER_OPTIONS_PER_PORT1; i++ )
            {
                if ( i_symbol == mss_x4dramSparePort1Index_to_symbol[i] )
                {
                    l_dramSparePort1Index = i;
                    break;
                }
            }

            FAPI_ASSERT(MSS_X4_STEER_OPTIONS_PER_PORT1 > l_dramSparePort1Index,
                        fapi2::CEN_MSS_MAINT_INVALID_SYMBOL_TO_STEER().
                        set_MBA(i_target).
                        set_DRAM_WIDTH(l_dramWidth).
                        set_RANK(i_rank).
                        set_MUX_TYPE(i_mux_type).
                        set_STEER_TYPE(i_steer_type).
                        set_SYMBOL(i_symbol),
                        "No match for i_symbol in mss_x4dramSparePort1Index_to_symbol[] on %s.", mss::c_str(i_target));
        }

        l_steerMux.insert < 5, 5, 8 - 5 > (l_dramSparePort1Index);
    }



    // Convert from i_symbol to l_eccSpareIndex
    if (i_steer_type == mss_SteerMux::ECC_SPARE)
    {
        if (l_dramWidth == mss_memconfig::X4)
        {
            l_eccSpareIndex = MSS_X4_ECC_STEER_OPTIONS;

            for ( uint32_t i = 0; i < MSS_X4_ECC_STEER_OPTIONS; i++ )
            {
                if ( i_symbol == mss_eccSpareIndex_to_symbol[i] )
                {
                    l_eccSpareIndex = i;
                    break;
                }
            }

            FAPI_ASSERT(MSS_X4_ECC_STEER_OPTIONS > l_eccSpareIndex,
                        fapi2::CEN_MSS_MAINT_INVALID_SYMBOL_TO_STEER().
                        set_MBA(i_target).
                        set_DRAM_WIDTH(l_dramWidth).
                        set_RANK(i_rank).
                        set_MUX_TYPE(i_mux_type).
                        set_STEER_TYPE(i_steer_type).
                        set_SYMBOL(i_symbol),
                        "No match for i_symbol in mss_eccSpareIndex_to_symbol[] on %s.", mss::c_str(i_target));

        }
        else if (l_dramWidth == mss_memconfig::X8)
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_MAINT_NO_X8_ECC_SPARE().
                        set_MBA(i_target).
                        set_DRAM_WIDTH(l_dramWidth).
                        set_RANK(i_rank).
                        set_MUX_TYPE(i_mux_type).
                        set_STEER_TYPE(i_steer_type).
                        set_SYMBOL(i_symbol),
                        "ECC_SPARE not valid with x8 mode on %s.", mss::c_str(i_target));
        }

        l_steerMux.insert < 10, 6, 8 - 6 > (l_eccSpareIndex);
    }

    // Write the steer mux register for the given rank and mux
    // type (read or write).
    if (i_mux_type == mss_SteerMux::READ_MUX)
    {
        // Read muxes are in the MBS
        FAPI_TRY(fapi2::putScom(l_targetCentaur, mss_readMuxRegs[i_rank][l_mbaPosition], l_steerMux));
    }
    else
    {
        // Write muxes are in the MBA
        FAPI_TRY(fapi2::putScom(i_target, mss_writeMuxRegs[i_rank], l_steerMux));
    }


    FAPI_INF("EXIT mss_put_steer_mux()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  Reads the steer muxes for the given rank
///
/// @param[in]  i_target                 MBA target
/// @param[in]  i_rank                   Rank we want to read steer mux for.
/// @param[out] o_dramSparePort0Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dramSparePort1Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @param[out] o_eccSpareSymbol         First symbol index of the DRAM fixed by the
///                                  ECC spare, which can be used on either port0
///                                  or port1 (if no steer, return 0xff)
/// @note   The ECC spare is available only with x4 mode ECC.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_check_steering(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_rank,
                                     uint8_t& o_dramSparePort0Symbol,
                                     uint8_t& o_dramSparePort1Symbol,
                                     uint8_t& o_eccSpareSymbol )
{
    // Get the read steer mux, with the assuption
    // that the write mux will be the same.
    return mss_get_steer_mux(i_target,
                             i_rank,
                             mss_SteerMux::READ_MUX,
                             o_dramSparePort0Symbol,
                             o_dramSparePort1Symbol,
                             o_eccSpareSymbol);
}

///
/// @brief  Set write mux, wait for periodic cal, set read mux, for the given rank.
///
/// @param[in]  i_target                MBA target
/// @param[in]  i_rank                  Rank we want to write steer mux for.
/// @param[in]  i_symbol                First symbol index of the DRAM to steer
///                                 around.
/// @param[in] i_x4EccSpare             If true, writes the x4 ECC Spare. Otherwise,
///                                 writes the DRAM spare (default).
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_do_steering(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                  const uint8_t i_rank,
                                  const uint8_t i_symbol,
                                  const bool i_x4EccSpare)
{
    FAPI_INF("ENTER mss_do_steering()");
    constexpr uint64_t  HW_MODE_DELAY = 250000000; // 250mSec delay
    // 200000 sim cycle delay for SIM mode
    constexpr uint64_t  SIM_MODE_DELAY = 200000;

    uint8_t l_steer_type = 0; // 0 = DRAM_SPARE_PORT0, Spare DRAM on port0
    // 1 = DRAM_SPARE_PORT1, Spare DRAM on port1
    // 2 = ECC_SPARE, ECC spare (used in x4 mode only)

    // Check for i_rank or i_symbol out of range
    FAPI_ASSERT( (MAX_RANKS_PER_PORT > i_rank) && (MSS_SYMBOLS_PER_RANK > i_symbol),
                 fapi2::CEN_MSS_MAINT_DO_STEER_INPUT_OUT_OF_RANGE().
                 set_MBA(i_target).
                 set_RANK(i_rank).
                 set_SYMBOL(i_symbol).
                 set_X4ECCSPARE(i_x4EccSpare),
                 "i_rank or i_symbol input to mss_do_steer out of range on %s.", mss::c_str(i_target));

    //------------------------------------------------------
    // Determine l_steer_type
    //------------------------------------------------------
    if (i_x4EccSpare)
    {
        l_steer_type = mss_SteerMux::ECC_SPARE;
    }
    else
    {
        // Symbols 71-40, 7-4 come from port0
        if (((i_symbol <= MSS_PORT_0_SYMBOL_71) && (i_symbol >= MSS_PORT_0_SYMBOL_40)) ||
            ((i_symbol <= MSS_PORT_0_SYMBOL_7) && (i_symbol >= MSS_PORT_0_SYMBOL_4)))
        {
            l_steer_type = mss_SteerMux::DRAM_SPARE_PORT0;
        }
        // Symbols 39-8, 3-0 come from port1
        else
        {
            l_steer_type = mss_SteerMux::DRAM_SPARE_PORT1;
        }
    }

    //------------------------------------------------------
    // Update write mux
    //------------------------------------------------------
    FAPI_TRY(mss_put_steer_mux(
                 i_target,               // MBA
                 i_rank,                 // Master rank: 0-7
                 mss_SteerMux::WRITE_MUX,// write mux
                 l_steer_type,            // DRAM_SPARE_PORT0/DRAM_SPARE_PORT1/ECC_SPARE
                 i_symbol));              // First symbol index of DRAM to steer around


    //------------------------------------------------------
    // Wait for a periodic cal.
    //------------------------------------------------------

    fapi2::delay(HW_MODE_DELAY, SIM_MODE_DELAY);


    //------------------------------------------------------
    // Update read mux
    //------------------------------------------------------
    FAPI_TRY(mss_put_steer_mux(
                 i_target,               // MBA
                 i_rank,                 // Master rank: 0-7
                 mss_SteerMux::READ_MUX, // read mux
                 l_steer_type,            // DRAM_SPARE_PORT0/DRAM_SPARE_PORT1/ECC_SPARE
                 i_symbol));              // First symbol index of DRAM to steer around


    FAPI_INF("EXIT mss_do_steering()");
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief  This procedure applies the maximum possible DRAM repairs (chip/symbol marks, DRAM steers)
///
///         brief cont. :  to known bad bits recorded in
///         DIMM VPD. This operation is done on both valid logical DIMM pairs
///         behind the given MBA.
///
/// @param[in]  i_target                MBA target
/// @param[out] o_repairs_applied       8-bit mask, where a bit set means the
///                                 specified rank had any repairs applied.
///
///                       rank0 = 0x80           (maps to port0_dimm0, port1_dimm0)
///                       rank1 = 0x40           (maps to port0_dimm0, port1_dimm0)
///                       rank2 = 0x20           (maps to port0_dimm0, port1_dimm0)
///                       rank3 = 0x10           (maps to port0_dimm0, port1_dimm0)
///                       rank4 = 0x08           (maps to port0_dimm1, port1_dimm1)
///                       rank5 = 0x04           (maps to port0_dimm1, port1_dimm1)
///                       rank6 = 0x02           (maps to port0_dimm1, port1_dimm1)
///                       rank7 = 0x01           (maps to port0_dimm1, port1_dimm1)
///
/// @param[out] o_repairs_exceeded      4-bit mask, where a bit set means the
///                                 specified DIMM-select on the specified port
///                                 had more bad bits than could be repaired.
///
///                        port0_dimm0 = 0x8
///                        port0_dimm1 = 0x4
///                        port1_dimm0 = 0x2
///                        port1_dimm1 = 0x1
///
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_restore_DRAM_repairs( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint8_t& o_repairs_applied,
        uint8_t& o_repairs_exceeded)
{
    bool l_flag_standby = false;
    struct repair_count l_count;
    FAPI_TRY(mss_restore_DRAM_repairs_asm(i_target, o_repairs_applied, o_repairs_exceeded, l_flag_standby, l_count));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  This procedure counts the maximum possible DRAM repairs (chip/symbol marks, DRAM steers)
///
///         brief cont. :  to known bad bits recorded in
///         DIMM VPD. This operation is done on both valid logical DIMM pairs
///         behind the given MBA.
///
/// @param[in]  i_target                MBA target
/// @param[out] o_repairs_applied       8-bit mask, where a bit set means the
///                                 specified rank had any repairs applied.
///
///                       rank0 = 0x80           (maps to port0_dimm0, port1_dimm0)
///                       rank1 = 0x40           (maps to port0_dimm0, port1_dimm0)
///                       rank2 = 0x20           (maps to port0_dimm0, port1_dimm0)
///                       rank3 = 0x10           (maps to port0_dimm0, port1_dimm0)
///                       rank4 = 0x08           (maps to port0_dimm1, port1_dimm1)
///                       rank5 = 0x04           (maps to port0_dimm1, port1_dimm1)
///                       rank6 = 0x02           (maps to port0_dimm1, port1_dimm1)
///                       rank7 = 0x01           (maps to port0_dimm1, port1_dimm1)
///
/// @param[out] o_repairs_exceeded      4-bit mask, where a bit set means the
///                                 specified DIMM-select on the specified port
///                                 had more bad bits than could be repaired.
///
///                        port0_dimm0 = 0x8
///                        port0_dimm1 = 0x4
///                        port1_dimm0 = 0x2
///                        port1_dimm1 = 0x1
///
/// @param[in]  i_strandby_flag     Boolean if we are in standby at call time
/// @param[out] o_repair_count      Repair counts
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_restore_DRAM_repairs_asm( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint8_t& o_repairs_applied,
        uint8_t& o_repairs_exceeded,
        const bool i_standby_flag,
        struct repair_count& o_repair_count)
{

    FAPI_INF("ENTER mss_restore_DRAM_repairs()");
    uint8_t l_dramWidth = 0;
    uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE] = {0}; // 10 byte array of bad bits
    fapi2::buffer<uint64_t> l_data;
    uint8_t l_port = 0;
    uint8_t l_dimm = 0;
    uint8_t l_rank = 0;
    uint8_t l_byte = 0;
    uint8_t l_nibble = 0;
    uint8_t l_dq_pair_index = 0;
    uint8_t l_bad_dq_pair_index = 0;
    uint8_t l_bad_dq_pair_count = 0;
    uint8_t l_dq_pair_mask = 0xC0;
    uint8_t l_byte_being_steered = 0xff;
    uint8_t l_bad_symbol = MSS_INVALID_SYMBOL;
    uint8_t l_symbol_mark = MSS_INVALID_SYMBOL;
    uint8_t l_chip_mark = MSS_INVALID_SYMBOL;
    uint8_t l_dramSparePort0Symbol = MSS_INVALID_SYMBOL;
    uint8_t l_dramSparePort1Symbol = MSS_INVALID_SYMBOL;
    uint8_t l_eccSpareSymbol = MSS_INVALID_SYMBOL;
    bool l_spare_exists = false;
    bool l_spare_used = false;
    bool l_chip_mark_used = false;
    bool l_symbol_mark_used = false;
    uint8_t l_valid_dimms  = 0;
    uint8_t l_valid_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    bool l_x4_DRAM_spare_low_exists = false;
    bool l_x4_DRAM_spare_high_exists = false;
    bool l_x4_DRAM_spare_used = false;
    bool l_x4_ECC_spare_used = false;
    uint8_t l_index = 0;
    // NO_SPARE = 0, LOW_NIBBLE = 1, HIGH_NIBBLE = 2, FULL_BYTE = 3
    uint8_t l_spare_dram[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0}; // Array defining if spare dram exit
    //New structures Updated to use for ASMI menu

    uint8_t l_steer[MAX_RANKS_PER_PORT][3] = {0};
    uint8_t l_mark_store[MAX_RANKS_PER_PORT][2] = {0};

    enum
    {
        MSS_REPAIRS_APPLIED     = 1,
        MSS_REPAIRS_EXCEEDED    = 2,
    };

    uint8_t l_repair_status[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] =
    {
        {{0, 0, 0, 0} , {0, 0, 0, 0}},
        {{0, 0, 0, 0} , {0, 0, 0, 0}}
    };

    static const uint8_t l_repairs_applied_translation[MAX_RANKS_PER_PORT] =
    {
        0x80,   //rank0  (maps to port0_dimm0, port1_dimm0)
        0x40,   //rank1  (maps to port0_dimm0, port1_dimm0)
        0x20,   //rank2  (maps to port0_dimm0, port1_dimm0)
        0x10,   //rank3  (maps to port0_dimm0, port1_dimm0)
        0x08,   //rank4  (maps to port0_dimm1, port1_dimm1)
        0x04,   //rank5  (maps to port0_dimm1, port1_dimm1)
        0x02,   //rank6  (maps to port0_dimm1, port1_dimm1)
        0x01
    };  //rank7  (maps to port0_dimm1, port1_dimm1)

    static const uint8_t l_repairs_exceeded_translation[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] =
    {
        //  dimm0   dimm1
        {    0x8,     0x4 },    // port0
        {    0x2,     0x1 }
    };   // port1

    // Start with no repairs applies and no repairs exceeded
    o_repairs_applied = 0;
    o_repairs_exceeded = 0;


    // Get array attribute that defines if spare dram exits
    //     l_spare_dram[port][dimm][rank]
    //     NO_SPARE = 0, LOW_NIBBLE = 1, HIGH_NIBBLE = 2, FULL_BYTE = 3
    //     NOTE: Typically will same value for whole Centaur.
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, i_target,  l_spare_dram));

    // Get l_dramWidth
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));

    // Find out which dimms are functional
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, i_target,  l_valid_dimms));

    l_valid_dimm[0][0] = (l_valid_dimms & 0x80); // port0, dimm0
    l_valid_dimm[0][1] = (l_valid_dimms & 0x40); // port0, dimm1
    l_valid_dimm[1][0] = (l_valid_dimms & 0x08); // port1, dimm0
    l_valid_dimm[1][1] = (l_valid_dimms & 0x04); // port1, dimm1

    //Initializing the repair count array
    for(l_rank = 0; l_rank < MAX_RANKS_PER_PORT; l_rank++)
    {
        o_repair_count.symbolmark_count[l_rank] = 0;
        o_repair_count.chipmark_count[l_rank] = 0;
        o_repair_count.steer_count[l_rank] = 0;
    }

    memset(l_steer, MSS_INVALID_SYMBOL, 8 * 3);
    memset(l_mark_store, MSS_INVALID_SYMBOL, 8 * 2);

    // For each port in the given MBA:0,1
    for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++ )
    {
        // For each DIMM select on the given port:0,1
        for(l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++ )
        {
            if (l_valid_dimm[l_port][l_dimm])
            {
                // For each rank select on the given DIMM select:0,1,2,3
                for(l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; l_rank++ )
                {
                    // Get the bad DQ Bitmap for l_port, l_dimm, l_rank
                    FAPI_TRY(dimmGetBadDqBitmap(i_target,
                                                l_port,
                                                l_dimm,
                                                l_rank,
                                                l_dqBitmap));

                    // x8 ECC
                    // x8 bit chip mark, x2 bit symbol mark, spare x8 DRAM if CDIMM
                    if (l_dramWidth == mss_memconfig::X8)
                    {
                        // Determine if spare x8 DRAM exists
                        l_spare_exists = l_spare_dram[l_port][l_dimm][l_rank] == mss_memconfig::FULL_BYTE;

                        // Start with spare not used
                        l_spare_used = false;
                        l_byte_being_steered = MSS_INVALID_SYMBOL;

                        if(i_standby_flag)
                        {
                            mss_get_dummy_mark_store(
                                i_target,               // MBA
                                4 * l_dimm + l_rank,    // Master rank: 0-7
                                l_symbol_mark,          // MSS_INVALID_SYMBOL if no symbol mark
                                l_chip_mark,            // MSS_INVALID_SYMBOL if no chip mark
                                l_mark_store);
                        }
                        else
                        {

                            // Read mark store
                            FAPI_TRY(mss_get_mark_store(
                                         i_target,               // MBA
                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                         l_symbol_mark,          // MSS_INVALID_SYMBOL if no symbol mark
                                         l_chip_mark));          // MSS_INVALID_SYMBOL if no chip mark

                        }


                        // Check if chip mark used (may have been used on other port)
                        l_chip_mark_used = l_chip_mark != MSS_INVALID_SYMBOL;

                        // Check if symbol mark used (may have been used on other port)
                        l_symbol_mark_used = l_symbol_mark != MSS_INVALID_SYMBOL;

                        // For each byte 0-9, where 9 is the spare
                        for(l_byte = 0; l_byte < DIMM_DQ_RANK_BITMAP_SIZE; l_byte++ )
                        {
                            if ((l_byte == 9) && !l_spare_exists)
                            {
                                // Don't look at byte 9 if spare doesn't exist
                                break;
                            }

                            if (l_dqBitmap[l_byte] == 0)
                            {
                                // Don't bother analyzing if byte is clean
                                continue;
                            }

                            // Mask initialized to look at first dq pair in byte
                            l_dq_pair_mask = 0xC0;

                            // Start with no bad dq pairs counted for this byte
                            l_bad_dq_pair_count = 0;

                            // For each of the 4 dq pairs in the byte
                            for(l_dq_pair_index = 0; l_dq_pair_index < 4; l_dq_pair_index++ )
                            {

                                // If any bad bits in this dq pair
                                if (l_dqBitmap[l_byte] & l_dq_pair_mask)
                                {
                                    // Increment bad symbol count
                                    l_bad_dq_pair_count++;

                                    // Record bad dq pair - just most recent if multiple bad
                                    l_bad_dq_pair_index = l_dq_pair_index;
                                }

                                // Shift mask to next symbol
                                l_dq_pair_mask = l_dq_pair_mask >> 2;
                            }

                            // If spare is bad but not used, not valid to try repair
                            if ( l_spare_exists && (l_byte == 9) && (l_bad_dq_pair_count > 0) && !l_spare_used)
                            {
                                FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                         l_dqBitmap[l_byte]);
                                FAPI_ERR("WARNING: Bad unused spare - no valid repair on %s", mss::c_str(i_target));
                                break;
                            }

                            // If more than one dq pair is bad
                            if(l_bad_dq_pair_count > 1)
                            {

                                // If spare x8 DRAM exists and not used yet,
                                if (l_spare_exists && !l_spare_used)
                                {
                                    l_bad_symbol = mss_centaurDQ_to_symbol(8 * l_byte, l_port) - 3;

                                    if(i_standby_flag)
                                    {
                                        mss_put_dummy_steer_mux(

                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            mss_SteerMux::READ_MUX, // read mux
                                            l_port,                 // l_port: 0,1
                                            l_bad_symbol,           // First symbol index of byte to steer
                                            l_steer);
                                    }
                                    else
                                    {

                                        // Update read mux
                                        FAPI_TRY(mss_put_steer_mux(

                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     mss_SteerMux::READ_MUX, // read mux
                                                     l_port,                 // l_port: 0,1
                                                     l_bad_symbol));          // First symbol index of byte to steer
                                    }


                                    // Update write mux



                                    if(i_standby_flag)
                                    {
                                        //do nothing
                                    }
                                    else
                                    {
                                        FAPI_TRY(mss_put_steer_mux(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     mss_SteerMux::WRITE_MUX,// write mux
                                                     l_port,                 // l_port: 0,1
                                                     l_bad_symbol));          // First symbol index of byte to steer
                                    }


                                    // Spare now used on this port,dimm,rank
                                    l_spare_used = true;

                                    // Remember which byte is being steered
                                    // so we know where to apply chip or symbol mark
                                    // if spare turns out to be bad
                                    l_byte_being_steered = l_byte;

                                    // Update which rank 0-7 has had repairs applied
                                    o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                    l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                    // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                    if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                        && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                    }

                                    FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                             l_dqBitmap[l_byte]);
                                    FAPI_ERR("WARNING: dq %d-%d, symbols %d-%d, FIXED CHIP WITH X8 STEER on %s",
                                             8 * l_byte, 8 * l_byte + 7, l_bad_symbol, l_bad_symbol + 3, mss::c_str(i_target));

                                }

                                // Else if chip mark not used yet, update mark store with chip mark
                                else if (!l_chip_mark_used)
                                {
                                    // NOTE: Have to do a read/modify/write so we
                                    // only update chip mark, and don't overwrite
                                    // symbol mark.

                                    if(i_standby_flag)
                                    {
                                        mss_get_dummy_mark_store(

                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            l_symbol_mark,          // Reading this just to write it back
                                            l_chip_mark,            // Expecting MSS_INVALID_SYMBOL since no chip mark
                                            l_mark_store);
                                    }

                                    else
                                    {


                                        // Read mark store
                                        FAPI_TRY(mss_get_mark_store(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     l_symbol_mark,          // Reading this just to write it back
                                                     l_chip_mark ));          // Expecting MSS_INVALID_SYMBOL since no chip mark
                                    }



                                    // Special case:
                                    // If this is a bad spare byte we are analyzing
                                    // the chip mark goes on the byte being steered
                                    if (l_byte == 9)
                                    {
                                        l_chip_mark = mss_centaurDQ_to_symbol(8 * l_byte_being_steered, l_port) - 3;
                                        FAPI_ERR("WARNING: Bad spare so chip mark goes on l_byte_being_steered = %d on %s", l_byte_being_steered ,
                                                 mss::c_str(i_target));
                                    }

                                    else
                                    {
                                        l_chip_mark = mss_centaurDQ_to_symbol(8 * l_byte, l_port) - 3;
                                    }

                                    if(i_standby_flag)
                                    {

                                        mss_put_dummy_mark_store(
                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            l_symbol_mark,          // Writting back exactly what we read
                                            l_chip_mark,            // First symbol index of byte getting chip mark
                                            l_mark_store);

                                    }
                                    else
                                    {


                                        // Write mark store
                                        FAPI_TRY(mss_put_mark_store(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     l_symbol_mark,          // Writting back exactly what we read
                                                     l_chip_mark));          // First symbol index of byte getting chip mark
                                    }


                                    // Chip mark now used on this rank
                                    l_chip_mark_used = true;

                                    // Update which rank 0-7 has had repairs applied
                                    o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                    l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                    // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                    if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                        && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                    }

                                    FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                             l_dqBitmap[l_byte]);
                                    FAPI_ERR("WARNING: dq %d-%d, symbols %d-%d, FIXED CHIP WITH X8 CHIP MARK on %s",
                                             8 * l_byte, 8 * l_byte + 7, l_chip_mark, l_chip_mark + 3 , mss::c_str(i_target));

                                }

                                // Else, more bad bits than we can repair so update o_repairs_exceeded
                                else
                                {
                                    o_repairs_exceeded |= l_repairs_exceeded_translation[l_port][l_dimm];

                                    l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_EXCEEDED;

                                    // If port1 repairs exceeded and port0 had a repair, say port0 repairs exceeded too
                                    if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED)
                                        && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_APPLIED))
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[0][l_dimm];
                                    }

                                    FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                             l_dqBitmap[l_byte]);
                                    FAPI_ERR("WARNING: dq %d-%d, REPAIRS EXCEEDED %s", 8 * l_byte, 8 * l_byte + 7, mss::c_str(i_target));

                                    // Break out of loop on bytes
                                    break;
                                }
                            } // End If bad symbol count > 1

                            //Else if bad symbol count = 1
                            else if(l_bad_dq_pair_count == 1)
                            {
                                // If symbol mark not used yet, update mark store with symbol mark
                                if (!l_symbol_mark_used)
                                {

                                    // NOTE: Have to do a read/modify/write so we
                                    // only update symbol mark, and don't overwrite
                                    // chip mark.

                                    // Read mark store
                                    if(i_standby_flag)
                                    {
                                        mss_get_dummy_mark_store(
                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            l_symbol_mark,          // Expecting MSS_INVALID_SYMBOL since no symbol mark
                                            l_chip_mark,            // Reading this just to write it back
                                            l_mark_store);
                                    }
                                    else
                                    {
                                        FAPI_TRY(mss_get_mark_store(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     l_symbol_mark,          // Expecting MSS_INVALID_SYMBOL since no symbol mark
                                                     l_chip_mark ));          // Reading this just to write it back
                                    }


                                    // Special case:
                                    // If this is a bad spare byte we are analying
                                    // the symbol mark goes on the byte being steered
                                    if (l_byte == 9)
                                    {
                                        l_symbol_mark = mss_centaurDQ_to_symbol(8 * l_byte_being_steered + 2 * l_bad_dq_pair_index, l_port);
                                        FAPI_ERR("WARNING: Bad spare so symbol mark goes on l_byte_being_steered = %d on %s", l_byte_being_steered,
                                                 mss::c_str(i_target));
                                    }

                                    else
                                    {
                                        l_symbol_mark = mss_centaurDQ_to_symbol(8 * l_byte + 2 * l_bad_dq_pair_index, l_port);
                                    }


                                    // Update mark store

                                    if(i_standby_flag)
                                    {
                                        mss_put_dummy_mark_store(
                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            l_symbol_mark,          // Single bad symbol found on this byte
                                            l_chip_mark,            // Writting back exactly what we read
                                            l_mark_store);

                                    }
                                    else
                                    {
                                        FAPI_TRY(mss_put_mark_store(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     l_symbol_mark,          // Single bad symbol found on this byte
                                                     l_chip_mark));          // Writting back exactly what we read
                                    }


                                    // Symbol mark now used on this rank
                                    l_symbol_mark_used = true;

                                    // Update which rank 0-7 has had repairs applied
                                    o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                    l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                    // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                    if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                        && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                    }

                                    FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                             l_dqBitmap[l_byte]);
                                    FAPI_ERR("WARNING: dq %d-%d, symbol %d, FIXED SYMBOL WITH X2 SYMBOL MARK on %s",
                                             8 * l_byte + 2 * l_bad_dq_pair_index, 8 * l_byte + 2 * l_bad_dq_pair_index + 1, l_symbol_mark, mss::c_str(i_target));
                                }


                                // Else if spare x8 DRAM exists and not used yet, update steer mux
                                else if (l_spare_exists && !l_spare_used)
                                {

                                    l_bad_symbol = mss_centaurDQ_to_symbol(8 * l_byte, l_port) - 3;

                                    // Update read mux

                                    if(i_standby_flag)
                                    {
                                        mss_put_dummy_steer_mux(
                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            mss_SteerMux::READ_MUX, // read mux
                                            l_port,                 // l_port: 0,1
                                            l_bad_symbol,           // First symbol index of byte to steer
                                            l_steer);

                                    }
                                    else
                                    {

                                        FAPI_TRY(mss_put_steer_mux(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     mss_SteerMux::READ_MUX, // read mux
                                                     l_port,                 // l_port: 0,1
                                                     l_bad_symbol));         // First symbol index of byte to steer
                                    }


                                    // Update write mux
                                    if(i_standby_flag)
                                    {
                                        //do nothing
                                    }
                                    else
                                    {
                                        FAPI_TRY(mss_put_steer_mux(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     mss_SteerMux::WRITE_MUX,// write mux
                                                     l_port,                 // l_port: 0,1
                                                     l_bad_symbol));         // First symbol index of byte to steer
                                    }


                                    // Spare now used on this port,dimm,rank
                                    l_spare_used = true;

                                    // Remember which byte is being steered
                                    // so we where to apply chip or symbol mark
                                    // if spare turns out to be bad
                                    l_byte_being_steered = l_byte;

                                    // Update which rank 0-7 has had repairs applied
                                    o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                    l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                    // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                    if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                        && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                    }

                                    FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                             l_dqBitmap[l_byte]);
                                    FAPI_ERR("WARNING: dq %d-%d, symbols %d-%d, FIXED SYMBOL WITH X8 STEER on %s",
                                             8 * l_byte + 2 * l_bad_dq_pair_index, 8 * l_byte + 2 * l_bad_dq_pair_index + 1, l_bad_symbol, l_bad_symbol + 3,
                                             mss::c_str(i_target));

                                }

                                // Else if chip mark not used yet, update mark store with chip mark
                                else if (!l_chip_mark_used)
                                {

                                    // NOTE: Have to do a read/modify/write so we
                                    // only update chip mark, and don't overwrite
                                    // symbol mark.

                                    // Read mark store

                                    if(i_standby_flag)
                                    {
                                        mss_get_dummy_mark_store(
                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            l_symbol_mark,          // Reading this just to write it back
                                            l_chip_mark,            // Expecting MSS_INVALID_SYMBOL since no chip mark
                                            l_mark_store);
                                    }
                                    else
                                    {

                                        FAPI_TRY(mss_get_mark_store(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     l_symbol_mark,          // Reading this just to write it back
                                                     l_chip_mark));          // Expecting MSS_INVALID_SYMBOL since no chip mark
                                    }

                                    // Special case:
                                    // If this is a bad spare byte we are analying
                                    // the chip mark goes on the byte being steered
                                    if (l_byte == 9)
                                    {
                                        l_chip_mark = mss_centaurDQ_to_symbol(8 * l_byte_being_steered, l_port) - 3;
                                        FAPI_ERR("WARNING: Bad spare so chip mark goes on l_byte_being_steered = %d on %s", l_byte_being_steered,
                                                 mss::c_str(i_target));
                                    }

                                    else
                                    {
                                        l_chip_mark = mss_centaurDQ_to_symbol(8 * l_byte, l_port) - 3;
                                    }

                                    // Update mark store
                                    if(i_standby_flag)
                                    {
                                        mss_put_dummy_mark_store(
                                            i_target,               // MBA
                                            4 * l_dimm + l_rank,    // Master rank: 0-7
                                            l_symbol_mark,          // Writting back exactly what we read
                                            l_chip_mark,            // First symbol index of byte getting chip mark
                                            l_mark_store);
                                    }
                                    else
                                    {


                                        FAPI_TRY(mss_put_mark_store(
                                                     i_target,               // MBA
                                                     4 * l_dimm + l_rank,    // Master rank: 0-7
                                                     l_symbol_mark,          // Writting back exactly what we read
                                                     l_chip_mark));          // First symbol index of byte getting chip mark
                                    }


                                    // Chip mark now used on this rank
                                    l_chip_mark_used = true;

                                    // Update which rank 0-7 has had repairs applied
                                    o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                    l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                    // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                    if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                        && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                    }

                                    FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                             l_dqBitmap[l_byte]);
                                    FAPI_ERR("WARNING: dq %d-%d, symbols %d-%d, FIXED SYMBOL WITH X8 CHIP MARK on %s",
                                             8 * l_byte + 2 * l_bad_dq_pair_index, 8 * l_byte + 2 * l_bad_dq_pair_index + 1, l_chip_mark, l_chip_mark + 3,
                                             mss::c_str(i_target));

                                }


                                // Else, more bad bits than we can repair so update o_repairs_exceeded
                                else
                                {

                                    o_repairs_exceeded |= l_repairs_exceeded_translation[l_port][l_dimm];

                                    l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_EXCEEDED;

                                    // If port1 repairs exceeded and port0 had a repair, say port0 repairs exceeded too
                                    if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED)
                                        && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_APPLIED))
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[0][l_dimm];
                                    }

                                    FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                             l_dqBitmap[l_byte]);
                                    FAPI_ERR("WARNING: dq %d-%d, REPAIRS EXCEEDED on %s",
                                             8 * l_byte + 2 * l_bad_dq_pair_index, 8 * l_byte + 2 * l_bad_dq_pair_index + 1, mss::c_str(i_target));

                                    // Break out of loop on bytes
                                    break;
                                }
                            } // End If bad symbol count = 1
                        } // End For each byte 0-9, where 9 is the spare
                    } // End x8 ECC

                    // x4 ECC
                    // x4 chip mark, x4 ECC steer, spare x4 DRAM if CDIMM
                    else if (l_dramWidth == mss_memconfig::X4)
                    {
                        // Determine if spare x4 DRAM exists
                        l_x4_DRAM_spare_low_exists = l_spare_dram[l_port][l_dimm][l_rank] == mss_memconfig::LOW_NIBBLE;
                        l_x4_DRAM_spare_high_exists = l_spare_dram[l_port][l_dimm][l_rank] == mss_memconfig::HIGH_NIBBLE;

                        // Start with spare x4 DRAM not used
                        l_x4_DRAM_spare_used = false;

                        // Read mark store

                        if(i_standby_flag)
                        {
                            mss_get_dummy_mark_store(
                                i_target,               // MBA
                                4 * l_dimm + l_rank,    // Master rank: 0-7
                                l_symbol_mark,          // MSS_INVALID_SYMBOL, since no symbol mark in x4 mode
                                l_chip_mark,            // MSS_INVALID_SYMBOL if no chip mark
                                l_mark_store);
                        }
                        else
                        {


                            FAPI_TRY(mss_get_mark_store(
                                         i_target,               // MBA
                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                         l_symbol_mark,          // MSS_INVALID_SYMBOL, since no symbol mark in x4 mode
                                         l_chip_mark));          // MSS_INVALID_SYMBOL if no chip mark
                        }


                        // Check if chip mark used (may have been used on other port)
                        l_chip_mark_used = l_chip_mark != MSS_INVALID_SYMBOL;


                        // READ steer mux
                        if(i_standby_flag)
                        {
                            mss_check_dummy_steering(
                                i_target,
                                4 * l_dimm + l_rank,
                                l_dramSparePort0Symbol,
                                l_dramSparePort1Symbol,
                                l_eccSpareSymbol,
                                l_steer);
                        }
                        else
                        {
                            FAPI_TRY(mss_check_steering(
                                         i_target,               // MBA
                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                         l_dramSparePort0Symbol, // Should be MSS_INVALID_SYMBOL since not used yet
                                         l_dramSparePort1Symbol, // Should be MSS_INVALID_SYMBOL since not used yet
                                         l_eccSpareSymbol));      // MSS_INVALID_SYMBOL if no ECC steer in place yet
                        }


                        // Check if ECC spare used (may have been used on other port)
                        l_x4_ECC_spare_used = l_eccSpareSymbol != MSS_INVALID_SYMBOL;

                        // For each byte 0-9, where 9 is the spare
                        for(l_byte = 0; l_byte < DIMM_DQ_RANK_BITMAP_SIZE; l_byte++ )
                        {
                            // For each nibble
                            for(l_nibble = 0; l_nibble < 2; l_nibble++ )
                            {
                                // If nibble bad
                                if (l_dqBitmap[l_byte] & (0xf0 >> (4 * l_nibble)))
                                {
                                    // If ECC spare is bad and not used, not valid to try repair
                                    if ((l_port == 1) && (l_byte == 8) && (l_nibble == 1) && !l_x4_ECC_spare_used)
                                    {
                                        FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                                 l_dqBitmap[l_byte]);
                                        FAPI_ERR("WARNING: Bad unused x4 ECC spare - no valid repair on %s", mss::c_str(i_target));
                                    }

                                    // Else if DRAM spare is bad and not used, not valid to try repair
                                    else if (((l_byte == 9) && (l_nibble == 0) && l_x4_DRAM_spare_low_exists && !l_x4_DRAM_spare_used) ||
                                             ((l_byte == 9) && (l_nibble == 1) && l_x4_DRAM_spare_high_exists && !l_x4_DRAM_spare_used))
                                    {
                                        FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                                 l_dqBitmap[l_byte]);
                                        FAPI_ERR("WARNING: Bad unused x4 DRAM spare - no valid repair on %s", mss::c_str(i_target));
                                    }

                                    // Else if on the nibble not connected to a spare
                                    else if (((l_byte == 9) && (l_nibble == 0) && !l_x4_DRAM_spare_low_exists) ||
                                             ((l_byte == 9) && (l_nibble == 1) && !l_x4_DRAM_spare_high_exists))
                                    {
                                        // Do nothing
                                        //FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte, l_dqBitmap[l_byte]);
                                        //FAPI_ERR("WARNING: This nibble has no spare x4 DRAM connected on %s", mss::c_str(i_target));
                                    }

                                    // Else if spare x4 DRAM exists and not used yet (and not ECC spare)
                                    else if (((l_x4_DRAM_spare_low_exists || l_x4_DRAM_spare_high_exists) && !l_x4_DRAM_spare_used) &&
                                             !((l_port == 1) && (l_byte == 8) && (l_nibble == 1)))
                                    {
                                        // Find first symbol index for this bad nibble
                                        l_bad_symbol = mss_centaurDQ_to_symbol(8 * l_byte + 4 * l_nibble, l_port) - 1;

                                        // Update read mux

                                        if(i_standby_flag)
                                        {
                                            mss_put_dummy_steer_mux(
                                                i_target,               // MBA
                                                4 * l_dimm + l_rank,    // Master rank: 0-7
                                                mss_SteerMux::READ_MUX, // read mux
                                                l_port,                 // l_port: 0,1
                                                l_bad_symbol,           // First symbol index of byte to steer
                                                l_steer);
                                        }
                                        else
                                        {


                                            FAPI_TRY(mss_put_steer_mux(
                                                         i_target,               // MBA
                                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                                         mss_SteerMux::READ_MUX, // read mux
                                                         l_port,                 // l_port: 0,1
                                                         l_bad_symbol));          // First symbol index of byte to steer
                                        }


                                        // Update write mux
                                        if(i_standby_flag)
                                        {
                                            //do nothing
                                        }
                                        else
                                        {
                                            FAPI_TRY(mss_put_steer_mux(
                                                         i_target,               // MBA
                                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                                         mss_SteerMux::WRITE_MUX,// write mux
                                                         l_port,                 // l_port: 0,1
                                                         l_bad_symbol));          // First symbol index of byte to steer
                                        }

                                        // Spare now used on this port,dimm,rank
                                        l_x4_DRAM_spare_used = true;

                                        // Update which rank 0-7 has had repairs applied
                                        o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                        l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                        // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                        if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                            && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                        {
                                            o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                        }

                                        FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                                 l_dqBitmap[l_byte]);
                                        FAPI_ERR("WARNING: dq %d-%d, symbols %d-%d, FIXED CHIP WITH X4 DRAM STEER on %s",
                                                 8 * l_byte + 4 * l_nibble, 8 * l_byte + 4 * l_nibble + 3, l_bad_symbol, l_bad_symbol + 1, mss::c_str(i_target));
                                    }

                                    // Else if x4 ECC spare not used yet (and not DRAM spare)
                                    else if (!l_x4_ECC_spare_used &&
                                             !(((l_byte == 9) && (l_nibble == 0) && l_x4_DRAM_spare_low_exists) ||
                                               ((l_byte == 9) && (l_nibble == 1) && l_x4_DRAM_spare_high_exists)))
                                    {
                                        // Find first symbol index for this bad nibble
                                        l_bad_symbol = mss_centaurDQ_to_symbol(8 * l_byte + 4 * l_nibble, l_port) - 1;

                                        // Update read mux
                                        if(i_standby_flag)
                                        {
                                            mss_put_dummy_steer_mux(
                                                i_target,               // MBA
                                                4 * l_dimm + l_rank,    // Master rank: 0-7
                                                mss_SteerMux::READ_MUX, // read mux
                                                mss_SteerMux::ECC_SPARE,// Use ECC spare
                                                l_bad_symbol,           // First symbol index of byte to steer
                                                l_steer);
                                        }
                                        else
                                        {

                                            FAPI_TRY(mss_put_steer_mux(
                                                         i_target,               // MBA
                                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                                         mss_SteerMux::READ_MUX, // read mux
                                                         mss_SteerMux::ECC_SPARE,// Use ECC spare
                                                         l_bad_symbol));          // First symbol index of byte to steer
                                        }


                                        // Update write mux
                                        if(i_standby_flag)
                                        {
                                            //do nothing
                                        }
                                        else
                                        {
                                            FAPI_TRY(mss_put_steer_mux(
                                                         i_target,               // MBA
                                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                                         mss_SteerMux::WRITE_MUX,// write mux
                                                         mss_SteerMux::ECC_SPARE,// Use ECC spare
                                                         l_bad_symbol));          // First symbol index of byte to steer
                                        }

                                        // Spare now used on this port,dimm,rank
                                        l_x4_ECC_spare_used = true;

                                        // Update which rank 0-7 has had repairs applied
                                        o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                        l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                        // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                        if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                            && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                        {
                                            o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                        }

                                        FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                                 l_dqBitmap[l_byte]);
                                        FAPI_ERR("WARNING: dq %d-%d, symbols %d-%d, FIXED CHIP WITH X4 ECC STEER on %s",
                                                 8 * l_byte + 4 * l_nibble, 8 * l_byte + 4 * l_nibble + 3, l_bad_symbol, l_bad_symbol + 1, mss::c_str(i_target));
                                    }

                                    // Else if x4 chip mark not used yet
                                    else if (!l_chip_mark_used)
                                    {

                                        // If this is a bad deployed ECC spare, the chip mark goes on the nibble being steered
                                        if ((l_port == 1) && (l_byte == 8) && (l_nibble == 1) && l_x4_ECC_spare_used)
                                        {
                                            // Find first symbol index of the nibble being steered with the ECC spare

                                            if(i_standby_flag)
                                            {
                                                mss_check_dummy_steering(
                                                    i_target,
                                                    4 * l_dimm + l_rank,
                                                    l_dramSparePort0Symbol,
                                                    l_dramSparePort1Symbol,
                                                    l_eccSpareSymbol,
                                                    l_steer);
                                            }
                                            else
                                            {
                                                FAPI_TRY(mss_check_steering(
                                                             i_target,               // MBA
                                                             4 * l_dimm + l_rank,    // Master rank: 0-7
                                                             l_dramSparePort0Symbol, // don't care
                                                             l_dramSparePort1Symbol, // don't care
                                                             l_eccSpareSymbol));      // first symbol index of the nibble being steered with the ECC spare
                                            }


                                            l_chip_mark = l_eccSpareSymbol;
                                            FAPI_ERR("WARNING: bad deployed ECC spare, so chip mark goes on the nibble being steered, symbols %d-%d on %s",
                                                     l_chip_mark, l_chip_mark + 1, mss::c_str(i_target));

                                        }

                                        // Else if this is a bad deployed DRAM spare, the chip mark goes on the nibble being steered
                                        else if (((l_byte == 9) && (l_nibble == 0) && l_x4_DRAM_spare_low_exists && l_x4_DRAM_spare_used) ||
                                                 ((l_byte == 9) && (l_nibble == 1) && l_x4_DRAM_spare_high_exists && l_x4_DRAM_spare_used))
                                        {
                                            // Find first symbol index of the nibble being steered with the DRAM spare
                                            if(i_standby_flag)
                                            {
                                                mss_check_dummy_steering(
                                                    i_target,
                                                    4 * l_dimm + l_rank,
                                                    l_dramSparePort0Symbol,
                                                    l_dramSparePort1Symbol,
                                                    l_eccSpareSymbol,
                                                    l_steer);
                                            }
                                            else
                                            {
                                                FAPI_TRY(mss_check_steering(
                                                             i_target,               // MBA
                                                             4 * l_dimm + l_rank,    // Master rank: 0-7
                                                             l_dramSparePort0Symbol, // first symbol index of the nibble being steered with the port0 DRAM spare
                                                             l_dramSparePort1Symbol, // first symbol index of the nibble being steered with the port1 DRAM spare
                                                             l_eccSpareSymbol));      // don't care
                                            }


                                            l_chip_mark = (l_port == 0) ? l_dramSparePort0Symbol : l_dramSparePort1Symbol;
                                            FAPI_ERR("WARNING: bad deployed DRAM spare, so chip mark goes on the nibble being steered, symbols %d-%d on %s",
                                                     l_chip_mark, l_chip_mark + 1, mss::c_str(i_target));
                                        }

                                        // Else this is not a bad deployed ECC or DRAM spare
                                        else
                                        {
                                            l_chip_mark = mss_centaurDQ_to_symbol(8 * l_byte + 4 * l_nibble, l_port) - 1;
                                        }

                                        // Update mark store

                                        if(i_standby_flag)
                                        {
                                            mss_put_dummy_mark_store(
                                                i_target,               // MBA
                                                4 * l_dimm + l_rank,    // Master rank: 0-7
                                                l_symbol_mark,          // MSS_INVALID_SYMBOL, since no symbol mark in x4 mode
                                                l_chip_mark,            // First symbol index of byte getting chip mark
                                                l_mark_store);
                                        }
                                        else
                                        {


                                            FAPI_TRY(mss_put_mark_store(
                                                         i_target,               // MBA
                                                         4 * l_dimm + l_rank,    // Master rank: 0-7
                                                         l_symbol_mark,          // MSS_INVALID_SYMBOL, since no symbol mark in x4 mode
                                                         l_chip_mark));          // First symbol index of byte getting chip mark
                                        }


                                        // Chip mark now used on this rank
                                        l_chip_mark_used = true;

                                        // Update which rank 0-7 has had repairs applied
                                        o_repairs_applied |= l_repairs_applied_translation[4 * l_dimm + l_rank];

                                        l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_APPLIED;

                                        // If port1 repairs applied and port0 had repairs exceeded, say port1 repairs exceeded too
                                        if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_APPLIED)
                                            && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED))
                                        {
                                            o_repairs_exceeded |= l_repairs_exceeded_translation[1][l_dimm];
                                        }

                                        FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                                 l_dqBitmap[l_byte]);
                                        FAPI_ERR("WARNING: dq %d-%d, symbols %d-%d, FIXED CHIP WITH X4 CHIP MARK on %s",
                                                 8 * l_byte + 4 * l_nibble, 8 * l_byte + 4 * l_nibble + 3, l_chip_mark, l_chip_mark + 1, mss::c_str(i_target));

                                    }

                                    // Else, more bad bits than we can repair so update o_repairs_exceeded
                                    else
                                    {
                                        o_repairs_exceeded |= l_repairs_exceeded_translation[l_port][l_dimm];

                                        l_repair_status[l_port][l_dimm][l_rank] = MSS_REPAIRS_EXCEEDED;

                                        // If port1 repairs exceeded and port0 had a repair, say port0 repairs exceeded too
                                        if ((l_repair_status[1][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED)
                                            && (l_repair_status[0][l_dimm][l_rank] == MSS_REPAIRS_APPLIED))
                                        {
                                            o_repairs_exceeded |= l_repairs_exceeded_translation[0][l_dimm];
                                        }

                                        FAPI_ERR("WARNING: port=%d, dimm=%d, rank=%d, l_dqBitmap[%d] = %02x", l_port, l_dimm, l_rank, l_byte,
                                                 l_dqBitmap[l_byte]);
                                        FAPI_ERR("WARNING: dq %d-%d, REPAIRS EXCEEDED %s", 8 * l_byte + 4 * l_nibble, 8 * l_byte + 4 * l_nibble + 3,
                                                 mss::c_str(i_target));

                                        // Break out of loop on nibbles
                                        break;
                                    }
                                } // End if nibble bad
                            } // End for each nibble

                            // Break of of loop on bytes is we have already exceeded repairs on this port,dimm,rank
                            if (l_repair_status[l_port][l_dimm][l_rank] == MSS_REPAIRS_EXCEEDED)
                            {
                                break;
                            }

                        } // End for each byte
                    } // End x4 ECC
                } // End loop on rank
            } // End if valid dimm
        } // End loop on dimm
    } // End loop on port

    //Updating steer and mark_store arrays
    if(i_standby_flag)
    {
        for(l_rank = 0; l_rank < MAX_RANKS_PER_PORT; l_rank++)
        {
            for(l_index = 0; l_index < 3; l_index++)
            {
                if( l_index == 0)
                {
                    if(l_steer[l_rank][l_index] != MSS_INVALID_SYMBOL)
                    {
                        o_repair_count.steer_count[l_rank] = o_repair_count.steer_count[l_rank] + 1;
                    }
                }

                if( l_index == 1)
                {
                    if(l_steer[l_rank][l_index] != MSS_INVALID_SYMBOL)
                    {
                        o_repair_count.steer_count[l_rank] = o_repair_count.steer_count[l_rank] + 1;
                    }

                }

                if( l_index == 2)
                {
                    if(l_steer[l_rank][l_index] != MSS_INVALID_SYMBOL)
                    {
                        o_repair_count.chipmark_count[l_rank] = o_repair_count.chipmark_count[l_rank] + 1;
                    }
                }
            }
        }

        for(l_rank = 0; l_rank < MAX_RANKS_PER_PORT; l_rank++)
        {
            for(l_index = 0; l_index < 2; l_index++)
            {
                if(l_index == 0)
                {
                    if(l_mark_store[l_rank][l_index] != MSS_INVALID_SYMBOL)
                    {
                        o_repair_count.symbolmark_count[l_rank] = o_repair_count.symbolmark_count[l_rank] + 1;
                    }
                }

                if(l_index == 1)
                {
                    if(l_mark_store[l_rank][l_index] != MSS_INVALID_SYMBOL)
                    {
                        o_repair_count.chipmark_count[l_rank] = o_repair_count.chipmark_count[l_rank] + 1;
                    }
                }
            }
        }
    }

    for(l_rank = 0; l_rank < MAX_RANKS_PER_PORT; l_rank++)
    {
        FAPI_INF("\n\n\n RANK %d\n\n\n", l_rank);
        FAPI_INF("\n \nSymbol mark count %d", o_repair_count.symbolmark_count[l_rank] );
        FAPI_INF("\n \nchip  mark count %d", o_repair_count.chipmark_count[l_rank]) ;
        FAPI_INF("\n \nsteer  mark count %d", o_repair_count.steer_count[l_rank]) ;
        FAPI_INF("_________________________________________________________");
    }


    FAPI_INF("o_repairs_applied =  %02x\n", o_repairs_applied);
    FAPI_INF("o_repairs_exceeded =  %02x\n", o_repairs_exceeded);

    FAPI_INF("EXIT mss_restore_DRAM_repairs()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief  This function takes converts from a Centaur DQ on a given port to a corresponding symbol index.
/// @param[in]  i_dq     Centaur DQ from 0-71
/// @param[in]  i_port   port 0 or 1
/// @return          Symbol index
///
uint8_t mss_centaurDQ_to_symbol( const uint8_t i_dq,
                                 const uint8_t i_port )
{

    uint8_t o_symbol = MSS_INVALID_SYMBOL;

    if ( 64 <= i_dq )                           // DQs 64 - 71
    {
        o_symbol = (71 - i_dq) / 2;             // symbols 0 - 3

        if ( 0 == i_port )
        {
            o_symbol += 4;    // symbols 4 - 7
        }
    }
    else                                        // DQs 0 - 63
    {
        o_symbol = (71 - i_dq + 8) / 2;         // symbols 8 - 39

        if ( 0 == i_port )
        {
            o_symbol += 32;    // symbols 40 - 71
        }
    }

    return o_symbol;
}

///
/// @brief  Identifies UE bits from trap data
///
///         This function compares trapped actual UE data to an expected
///         data pattern in order to identify the bits that contributed to
///         a UE encountered during IPL memory diagnostics.
///
/// @param[in]  i_target                MBA target
/// @param[in]  i_rank                  Rank containing the UE.
/// @param[out] o_bad_bits              Map of bad bits (Centaur DQ format) 2 ports x 10 bytes
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_IPL_UE_isolation( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                        const uint8_t i_rank,
                                        uint8_t (&o_bad_bits)[2][10])

{
    FAPI_INF("ENTER mss_IPL_UE_isolation()");

    static const uint32_t maintBufferReadDataRegs[2][2][8] =
    {

        // UE trap 0:
        // Port0                                    beat  double word
        {   {
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA0_RO, // 0     DW0
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA0_RO, // 1     DW2
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA1_RO, // 2     DW4
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA1_RO, // 3     DW6
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA2_RO, // 4     DW8
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA2_RO, // 5     DW10
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA3_RO, // 6     DW12
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA3_RO
            },// 7     DW14

            // Port1
            {
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA0_RO, // 0     DW1
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA0_RO, // 1     DW3
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA1_RO, // 2     DW5
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA1_RO, // 3     DW7
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA2_RO, // 4     DW9
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA2_RO, // 5     DW11
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA3_RO, // 6     DW13
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA3_RO
            }
        },//7     DW15

        // UE trap 1:
        // Port0
        {   {
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA4_RO, // 0     DW0
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA4_RO, // 1     DW2
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA5_RO, // 2     DW4
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA5_RO, // 3     DW6
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA6_RO, // 4     DW8
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA6_RO, // 5     DW10
                CEN_MBA_MAINT0_MAINT_BUFF0_DATA7_RO, // 6     DW12
                CEN_MBA_MAINT0_MAINT_BUFF2_DATA7_RO
            },// 7     DW14

            // Port1
            {
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA4_RO, // 0     DW1
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA4_RO, // 1     DW3
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA5_RO, // 2     DW5
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA5_RO, // 3     DW7
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA6_RO, // 4     DW9
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA6_RO, // 5     DW11
                CEN_MBA_MAINT0_MAINT_BUFF1_DATA7_RO, // 6     DW13
                CEN_MBA_MAINT0_MAINT_BUFF3_DATA7_RO
            }
        }
    };//7    DW15


    static const uint32_t maintBufferRead65thByteRegs[2][4] =
    {
        // UE trap 0
        {
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC0_RO,
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC1_RO,
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC2_RO,
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC3_RO
        },
        // UE trap 1
        {
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC4_RO,
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC5_RO,
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC6_RO,
            CEN_MBA_MAINT0_MAINT_BUFF_65TH_BYTE_64B_ECC7_RO
        }
    };


    uint8_t l_UE_trap = 0; // 0,1, since UE can be in 1st or 2nd half of buffer
    uint8_t l_port = 0;    // 0,1
    uint8_t l_beat = 0;    // 0-7
    uint8_t l_byte = 0;    // 0-9
    uint8_t l_nibble = 0;  // 0-17
    uint8_t l_loop = 0;
    fapi2::buffer<uint64_t> l_data;
    fapi2::buffer<uint64_t> l_data_32;
    fapi2::buffer<uint64_t> l_data_64;
    fapi2::buffer<uint64_t> l_UE_trap0_signature;
    fapi2::buffer<uint64_t> l_UE_trap1_signature;
    fapi2::buffer<uint32_t> l_UE_trap0_signature_32;
    fapi2::buffer<uint32_t> l_UE_trap1_signature_32;
    fapi2::buffer<uint64_t> l_mbmmr;
    fapi2::buffer<uint64_t> l_mbmct;
    fapi2::buffer<uint64_t> l_mbstr;
    uint8_t l_initPattern = 0;
    uint8_t l_cmd_type = 0;
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
    uint8_t l_mbaPosition = 0;
    uint32_t l_tmp_data_diff[2] = {0};
    uint8_t l_tag_MDI = 0;
    uint8_t l_tmp_65th_byte_diff = 0;
    fapi2::buffer<uint64_t> l_diff;
    uint32_t l_ECC = 0;
    uint32_t l_tmp_ECC_diff = 0;
    fapi2::buffer<uint32_t> l_ECC_diff;
    uint8_t l_ECC_c6_c5_c4_01 = 0;
    uint8_t l_ECC_c6_c5_c4_23 = 0;
    uint8_t l_ECC_c3_c2_c1_c0_01 = 0;
    uint8_t l_ECC_c3_c2_c1_c0_23 = 0;
    uint8_t l_dramSparePort0Symbol = MSS_INVALID_SYMBOL;
    uint8_t l_dramSparePort1Symbol = MSS_INVALID_SYMBOL;
    uint8_t l_eccSpareSymbol = MSS_INVALID_SYMBOL;
    uint8_t l_dramWidth = 0;


    //----------------------------------------------------
    // Get l_dramWidth
    //----------------------------------------------------
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,  l_dramWidth));


    // Convert from attribute enum values: 8,4 to index values: 0,1
    if(l_dramWidth == mss_memconfig::X8)
    {
        l_dramWidth = 0;
    }
    else
    {
        l_dramWidth = 1;
    }

    //----------------------------------------------------
    // Initialize o_bad_bits
    //----------------------------------------------------

    for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++ )
    {
        for(l_byte = 0; l_byte < DIMM_DQ_RANK_BITMAP_SIZE; l_byte++ )
        {
            o_bad_bits[l_port][l_byte] = 0;
        }
    }


    //----------------------------------------------------
    // Get the expected pattern (stored in mbmmr reg)
    //----------------------------------------------------

    // Get Centaur target for the given MBA
    l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();


    // Get MBA position: 0 = mba01, 1 = mba23
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target,  l_mbaPosition));


    // MBMMR[4:7] contains the pattern index
    FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_mbmmr[l_mbaPosition], l_mbmmr));


    l_mbmmr.extract < 4, 4, 8 - 4 > (l_initPattern);


    // MBMCT[0:4] contains the cmd type
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBMCTQ, l_mbmct));


    l_mbmct.extract < 0, 5, 8 - 5 > (l_cmd_type);


    // No isolation if cmd is timebased steer cleanup
    if (l_cmd_type == 2)
    {
        FAPI_ERR("WARNING: rank%d maint UE during steer cleanup - no bad bit isolation possible on %s.", i_rank,
                 mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // No isolation if pattern is random
    if (l_initPattern == 8)
    {
        FAPI_ERR("WARNING: rank%d maint UE with random pattern - no bad bit isolation possible on %s.", i_rank,
                 mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }


    FAPI_INF("Expected pattern%d = 0x%.8X 0x%.8X", l_initPattern,
             mss_maintBufferData[l_dramWidth][l_initPattern][0][0],
             mss_maintBufferData[l_dramWidth][l_initPattern][0][1]);

    //----------------------------------------------------
    // Figure out which half of the buffer has the UE...
    // Remember we had to first load the buffers with
    // a hex signatue, and whichever gets overwritten
    // has a UE trapped
    //----------------------------------------------------
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MAINT0_MAINT_BUFF0_DATA0_RO, l_UE_trap0_signature));


    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MAINT0_MAINT_BUFF0_DATA4_RO, l_UE_trap1_signature));


    // UE may be trapped in both halves of the buffer,
    // but we will only use one.
    l_UE_trap0_signature.extract<0, 32>(l_UE_trap0_signature_32);
    l_UE_trap1_signature.extract<0, 32>(l_UE_trap1_signature_32);

    if ((l_UE_trap0_signature_32 != 0xFACEB00C) &&
        (l_UE_trap0_signature_32 != 0xD15C0DAD))
    {
        FAPI_INF("UE trapped in 1st half of maint buffer");
        l_UE_trap = 0;
    }
    else if ((l_UE_trap1_signature_32 != 0xFACEB00C) &&
             (l_UE_trap1_signature_32 != 0xD15C0DAD))
    {
        FAPI_INF("UE trapped in 2nd half of maint buffer");
        l_UE_trap = 1;
    }
    else
    {
        // Read for FFDC: MBSTR[59]: UE trap enable bit
        FAPI_TRY(fapi2::getScom(l_targetCentaur, mss_mbstr[l_mbaPosition], l_mbstr));
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_MAINT_NO_UE_TRAP().
                    set_MBA(i_target).
                    set_UE_TRAP0(l_UE_trap0_signature).
                    set_UE_TRAP1(l_UE_trap1_signature).
                    set_MBMCT(l_mbmct).
                    set_MBMMR(l_mbmmr).
                    set_MBSTR(l_mbstr),
                    "IPL UE trapping didn't work on i_rank = %d on %s.", i_rank, mss::c_str(i_target));
    }

    //----------------------------------------------------
    // DATA: Do XOR of expected and actual data to find stuck bits
    //----------------------------------------------------

    for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++ )
    {
        l_tmp_data_diff[0] = 0;
        l_tmp_data_diff[1] = 0;

        FAPI_INF("port%d", l_port);

        for(l_beat = 0; l_beat < 8; l_beat++ )
        {
            FAPI_TRY(fapi2::getScom(i_target, maintBufferReadDataRegs[l_UE_trap][l_port][l_beat], l_data));

            FAPI_INF("Actual data, beat%d: 0x%X", l_beat, l_data);

            FAPI_INF("Expected pattern%d = 0x%.8X 0x%.8X", l_initPattern,
                     mss_maintBufferData[l_dramWidth][l_initPattern][l_port * 8 + l_beat][0],
                     mss_maintBufferData[l_dramWidth][l_initPattern][l_port * 8 + l_beat][1]);
            l_data.extract<0, 32>(l_data_32);
            l_data.extract<32, 32>(l_data_64);
            // DO XOR of actual and expected data, and OR the result together for all 8 beats
            l_tmp_data_diff[0] |= l_data_32 ^ mss_maintBufferData[l_dramWidth][l_initPattern][l_port * 8 + l_beat][0];
            l_tmp_data_diff[1] |= l_data_64 ^ mss_maintBufferData[l_dramWidth][l_initPattern][l_port * 8 + l_beat][1];

            FAPI_INF("***************************************** l_tmp_diff: 0x%.8X 0x%.8X", l_tmp_data_diff[0], l_tmp_data_diff[1]);
        }

        // Put l_tmp_diff into a fapi2::buffer<uint64_t> to make it easier
        // to get into o_bad_bits
        l_diff.insert<0, 32, 0>(l_tmp_data_diff[0]);
        l_diff.insert<32, 32, 0>(l_tmp_data_diff[1]);

        for(l_byte = 0; l_byte < 8; l_byte++ )
        {
            FAPI_TRY(l_diff.extract(o_bad_bits[l_port][l_byte], 8 * l_byte, 8, 0));
        }
    } // End loop on ports

    //----------------------------------------------------
    // 65th byte: Do XOR of expected and actual 65th byte to find stuck bits
    //----------------------------------------------------

    for(l_loop = 0; l_loop < NUM_LOOPS_FOR_65TH_BYTE; l_loop++ )
    {
        l_tag_MDI = 0;
        l_tmp_65th_byte_diff = 0;

        FAPI_TRY(fapi2::getScom(i_target, maintBufferRead65thByteRegs[l_UE_trap][l_loop], l_data));


        // Grab bit 0 = Checkbit0_1
        // Grab bit 1 = Tag0_2
        // Grab bit 2 = Tag1_3
        // Grab bit 3 = MDI
        l_data.extract<0, 4, 0>(l_tag_MDI);


        FAPI_INF("Actual:   bit0 (Checkbit0_1), bit1(Tag0_2), bit2(Tag1_3), bit3(MDI) = 0x%.2X", l_tag_MDI);

        FAPI_INF("Expected: bit0 (Checkbit0_1), bit1(Tag0_2), bit2(Tag1_3), bit3(MDI) = 0x%.2X",
                 mss_65thByte[l_dramWidth][l_initPattern][l_loop]);

        // DO XOR of actual and expected data
        l_tmp_65th_byte_diff = l_tag_MDI ^ mss_65thByte[l_dramWidth][l_initPattern][l_loop];
        FAPI_INF("***************************************** l_tmp_65th_byte_diff: 0x%.2X", l_tmp_65th_byte_diff);


        // Check for mismatch in bit 0: Checkbit0_1
        if (l_tmp_65th_byte_diff & 0x80)
        {
            // Checkbit0_1 maps to port0 bit 64, which is on byte8
            o_bad_bits[0][8] |= 0x80;
        }

        // Check for mismatch in bit 1: Tag0_2
        if (l_tmp_65th_byte_diff & 0x40)
        {
            // Tag0_2 maps to port0 bit 65, which is on byte8
            o_bad_bits[0][8] |= 0x40;
        }

        // Check for mismatch in bit 2: Tag1_3
        if (l_tmp_65th_byte_diff & 0x20)
        {
            // Tag1_3 maps to port0 bit 64, which is on byte8
            o_bad_bits[0][8] |= 0x80;
        }

        // Check for mismatch in bit 3: MDI
        if (l_tmp_65th_byte_diff & 0x10)
        {
            // MDI maps to port0 bit 65, which is on byte8
            o_bad_bits[0][8] |= 0x40;
        }
    } // End loops through trapped 65th byte info


    //----------------------------------------------------
    // ECC: Do XOR of expected and actual ECC bits to find stuck bits
    //----------------------------------------------------

    for(l_loop = 0; l_loop < NUM_LOOPS_FOR_65TH_BYTE; l_loop++ )
    {
        l_ECC = 0;

        FAPI_TRY(fapi2::getScom(i_target, maintBufferRead65thByteRegs[l_UE_trap][l_loop], l_data));


        // Grab bits 4:15 = ECC_c6_c5_c4, and bits 16:31 = ECC_c3_c2_c1_c0
        l_data.extract<4, 28, 4>(l_ECC);


        FAPI_INF("Actual:   ECC = 0x%.8X", l_ECC);

        FAPI_INF("Expected: ECC = 0x%.8X", mss_ECC[l_dramWidth][l_initPattern][l_loop]);

        // DO XOR of actual and expected data
        l_tmp_ECC_diff |= l_ECC ^ mss_ECC[l_dramWidth][l_initPattern][l_loop];
        FAPI_INF("***************************************** l_tmp_ECC_diff: 0x%.8X", l_tmp_ECC_diff);
    }

    // Put l_tmp_ECC_diff into a fapi2::buffer<uint64_t> to make it easier
    // to get into o_bad_bits
    l_ECC_diff.insert<0, 32, 0>(l_tmp_ECC_diff);


    l_ECC_diff.extract < 4, 6, 8 - 6 > (l_ECC_c6_c5_c4_01);
    l_ECC_diff.extract < 10, 6, 8 - 6 > (l_ECC_c6_c5_c4_23);
    l_ECC_diff.extract<16, 8, 0>(l_ECC_c3_c2_c1_c0_01);
    l_ECC_diff.extract<24, 8, 0>(l_ECC_c3_c2_c1_c0_23);


    // The 6 bits of ECC_c6_c5_c4 maps to byte8 on port0
    o_bad_bits[0][8] |= l_ECC_c6_c5_c4_01 | l_ECC_c6_c5_c4_23;
    // The 8 bits of ECC_c3_c2_c1_c0 maps to byte8 byte on port1
    o_bad_bits[1][8] |= l_ECC_c3_c2_c1_c0_01 | l_ECC_c3_c2_c1_c0_23;


    //----------------------------------------------------
    // Spare: Mark byte9 bad if bad bits found in position being steered
    //----------------------------------------------------

    // READ steer mux, which gets me a symbol for port0 and port1
    FAPI_TRY(mss_check_steering(i_target,
                                i_rank,
                                l_dramSparePort0Symbol,
                                l_dramSparePort1Symbol,
                                l_eccSpareSymbol));



//----------------------------
// x8
//----------------------------
    if (l_dramWidth == 0)
    {
        // If steering on port0
        if ( l_dramSparePort0Symbol != 0xff)
        {
            // Find the byte being steered
            l_byte = mss_x8_chip_mark_to_centaurDQ[l_dramSparePort0Symbol / 4][0] / 8;

            // If that byte has any bad bits in it, copy them to byte9,
            if (o_bad_bits[0][l_byte])
            {
                o_bad_bits[0][9] = o_bad_bits[0][l_byte];

                // Clear byte being steered, since it did not contribute to UE
                o_bad_bits[0][l_byte] = 0;
            }
        }

        // If steering on port1
        if ( l_dramSparePort1Symbol != 0xff)
        {
            // Find the byte being steered
            l_byte = mss_x8_chip_mark_to_centaurDQ[l_dramSparePort1Symbol / 4][0] / 8;

            // If that byte has any bad bits in it, copy them to byte9,
            if (o_bad_bits[1][l_byte])
            {
                o_bad_bits[1][9] = o_bad_bits[1][l_byte];

                // Clear byte being steered, since it did not contribute to UE
                o_bad_bits[1][l_byte] = 0;
            }
        }
    }

    //----------------------------
    // x4
    //----------------------------
    else
    {
        // If steering on port0
        if ( l_dramSparePort0Symbol != 0xff)
        {
            // Find the nibble being steered (0-17)
            l_nibble = mss_x4_chip_mark_to_centaurDQ[l_dramSparePort0Symbol / 2][0] / 4;

            // If odd nibble (1,3,5,7,9,11,13,15,17)
            if (l_nibble % 2)
            {
                // If that nibble has any bad bits in it, copy them to byte9,
                if (o_bad_bits[0][l_nibble / 2] & 0x0f)
                {
                    o_bad_bits[0][9] = (o_bad_bits[0][l_nibble / 2] << 4) & 0xf0;

                    // Clear nibble being steered, since it did not contribute to UE
                    o_bad_bits[0][l_nibble / 2] &= 0xf0;
                }
            }

            // Else even nibble (0,2,4,6,8,10,12,14,16)
            else
            {
                // If that nibble has any bad bits in it, copy them to byte9,
                if (o_bad_bits[0][l_nibble / 2] & 0xf0)
                {
                    o_bad_bits[0][9] = o_bad_bits[0][l_nibble / 2] & 0xf0;

                    // Clear nibble being steered, since it did not contribute to UE
                    o_bad_bits[0][l_nibble / 2] &= 0x0f;
                }
            }
        }

        // If steering on port1
        if ( l_dramSparePort1Symbol != 0xff)
        {
            // Find the nibble being steered (0-17)
            l_nibble = mss_x4_chip_mark_to_centaurDQ[l_dramSparePort1Symbol / 2][0] / 4;

            // If odd nibble (1,3,5,7,9,11,13,15,17)
            if (l_nibble % 2)
            {
                // If that nibble has any bad bits in it, copy them to byte9,
                if (o_bad_bits[1][l_nibble / 2] & 0x0f)
                {
                    o_bad_bits[1][9] = (o_bad_bits[1][l_nibble / 2] << 4) & 0xf0;

                    // Clear nibble being steered, since it did not contribute to UE
                    o_bad_bits[1][l_nibble / 2] &= 0xf0;
                }
            }

            // Else even nibble (0,2,4,6,8,10,12,14,16)
            else
            {
                // If that nibble has any bad bits in it, copy them to byte9,
                if (o_bad_bits[1][l_nibble / 2] & 0xf0)
                {
                    o_bad_bits[1][9] = o_bad_bits[1][l_nibble / 2] & 0xf0;

                    // Clear nibble being steered, since it did not contribute to UE
                    o_bad_bits[1][l_nibble / 2] &= 0x0f;
                }
            }
        }


        // If ecc spare used
        if ( l_eccSpareSymbol != 0xff)
        {
            // Find the nibble being steered (0-17)
            l_nibble = mss_x4_chip_mark_to_centaurDQ[l_eccSpareSymbol / 2][0] / 4;

            // Find the port being steered (0,1)
            l_port = mss_x4_chip_mark_to_centaurDQ[l_eccSpareSymbol / 2][1];

            // If odd nibble (1,3,5,7,9,11,13,15,17)
            if (l_nibble % 2)
            {
                // If that nibble has any bad bits in it, copy them to port1,nibble 17
                if (o_bad_bits[l_port][l_nibble / 2] & 0x0f)
                {
                    o_bad_bits[1][8] |= o_bad_bits[l_port][l_nibble / 2] & 0x0f;

                    // Clear nibble being steered, since it did not contribute to UE
                    o_bad_bits[l_port][l_nibble / 2] &= 0xf0;
                }
            }

            // Else even nibble (0,2,4,6,8,10,12,14,16)
            else
            {
                // If that nibble has any bad bits in it, copy them to port1,nibble 17
                if (o_bad_bits[l_port][l_nibble / 2] & 0xf0)
                {
                    o_bad_bits[1][8] |= (o_bad_bits[l_port][l_nibble / 2] >> 4) & 0x0f;

                    // Clear nibble being steered, since it did not contribute to UE
                    o_bad_bits[l_port][l_nibble / 2] &= 0x0f;
                }
            }
        }
    }



    //----------------------------------------------------
    // Show results
    //----------------------------------------------------

    FAPI_ERR("WARNING: IPL UE isolation results for rank = %d on %s.", i_rank, mss::c_str(i_target));
    FAPI_ERR("WARNING: Expected pattern = 0x%.8X", mss_maintBufferData[l_dramWidth][l_initPattern][0][0]);

    for(l_port = 0; l_port < 2; l_port++ )
    {
        for(l_byte = 0; l_byte < 10; l_byte++ )
        {
            FAPI_ERR("WARNING: o_bad_bits[port%d][byte%d] = %02x",
                     l_port, l_byte, o_bad_bits[l_port][l_byte]);
        }
    }


    FAPI_INF("EXIT mss_IPL_UE_isolation()");
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Update o_symbolMark and o_chipMark with mark_store values
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centaur input rank
/// @param[out] o_symbolMark Symbol Mark
/// @param[out] o_chipMark Chip Mark
/// @param[out] mark_store Markstore array
///
void mss_get_dummy_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                               const uint8_t i_rank,
                               uint8_t& o_symbolMark,
                               uint8_t& o_chipMark,
                               uint8_t mark_store[8][2])
{

    FAPI_INF("ENTER mss_get_dummy_mark_store(), i_rank = %d", i_rank);

    o_symbolMark = mark_store[i_rank][0];
    o_chipMark = mark_store[i_rank][1];

    FAPI_INF("EXIT mss_get_dummy_mark_store(): o_symbolMark = %d, o_chipMark = %d",
             o_symbolMark, o_chipMark);
}

///
/// @brief  Set mark store with new symbol and chip mark values
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centaur input rank
/// @param[out] i_symbolMark Symbol Mark
/// @param[out] i_chipMarkChip Mark
/// @param[out] mark_store Markstore array
///
void mss_put_dummy_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                               const uint8_t i_rank,
                               const uint8_t i_symbolMark,
                               const uint8_t i_chipMark,
                               uint8_t mark_store[8][2])
{
    FAPI_INF("ENTER mss_put_dummy_mark_store(): i_rank = %d, i_symbolMark = %d, i_chipMark = %d",
             i_rank, i_symbolMark, i_chipMark );

    mark_store[i_rank][0] = i_symbolMark;
    mark_store[i_rank][1] = i_chipMark;

    FAPI_INF("EXIT mss_put_dummy_mark_store()");
}


///
/// @brief Pull steer mux values from steer array
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centuar input rank
/// @param[in] i_mux_type  Read or Write
/// @param[out] o_dramSparePort0Symbol Port 0 spare val
/// @param[out] o_dramSparePort1Symbol Port 1 spare val
/// @param[out] o_eccSpareSymbol Ecc Spare val
/// @param[out] steer[8][3] Steer mux array
///
void mss_get_dummy_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                              const uint8_t i_rank,
                              const mss_SteerMux::mux_type i_mux_type,
                              uint8_t& o_dramSparePort0Symbol,
                              uint8_t& o_dramSparePort1Symbol,
                              uint8_t& o_eccSpareSymbol,
                              uint8_t steer[8][3])
{

    FAPI_INF("ENTER mss_get_dummy_steer_mux(): i_rank = %d", i_rank );

    o_dramSparePort0Symbol = steer[i_rank][0];
    o_dramSparePort1Symbol = steer[i_rank][1];
    o_eccSpareSymbol = steer[i_rank][2];

    FAPI_INF("EXIT mss_get_dummy_steer_mux(): port0 steer = %d, port1 steer = %d, ecc steer = %d",
             o_dramSparePort0Symbol, o_dramSparePort1Symbol, o_eccSpareSymbol );
}

///
/// @brief Set steer mux value for a given rank and type
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centuar input rank
/// @param[in] i_mux_type Read or Write
/// @param[in] i_steer_type spare port 0, port 1 or ecc spare
/// @param[in] i_symbol First symbol index of byte to steer
/// @param[out] steer[8][3]  Steer mux array
///
void mss_put_dummy_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                              const uint8_t i_rank,
                              const mss_SteerMux::mux_type i_mux_type,
                              const uint8_t i_steer_type,
                              const uint8_t i_symbol,
                              uint8_t steer[8][3])
{
    FAPI_INF("ENTER mss_put_dummy_steer_mux(): i_rank = %d, i_steer_type = %d, i_symbol = %d",
             i_rank, i_steer_type, i_symbol );

    steer[i_rank][i_steer_type] = i_symbol;


    FAPI_INF("EXIT mss_put_dummy_steer_mux()");
}

///
/// @brief Populate output vars with corresponding steer mux array values
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centuar input rank
/// @param[out] o_dramSparePort0Symbol Spare port 0 symbol
/// @param[out] o_dramSparePort1Symbol Spare port 1 symbol
/// @param[out] o_eccSpareSymbol ECC spare symbol
/// @param[out] steer[8][3] Steer mux array
///
void mss_check_dummy_steering(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                              const uint8_t i_rank,
                              uint8_t& o_dramSparePort0Symbol,
                              uint8_t& o_dramSparePort1Symbol,
                              uint8_t& o_eccSpareSymbol,
                              uint8_t steer[8][3])

{
    // Get the read steer mux, with the assuption
    // that the write mux will be the same.
    mss_get_dummy_steer_mux( i_target,
                             i_rank,
                             mss_SteerMux::READ_MUX,
                             o_dramSparePort0Symbol,
                             o_dramSparePort1Symbol,
                             o_eccSpareSymbol,
                             steer);


}

