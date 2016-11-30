/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/shared/mss_const.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @mss_const.H
/// @This file contains constants for the memory team.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CONST_H_
#define _MSS_CONST_H_

#include <cstdint>

namespace mss
{

enum sizes
{
    PORTS_PER_MCS = 2,
    PORTS_PER_MCBIST = 4,
    MCS_PER_MC = 2,
    MC_PER_MODULE = 2,
    MCBIST_PER_MC = 1,
    MAX_DIMM_PER_PORT = 2,
    MAX_RANK_PER_DIMM = 4,
    NIBBLES_PER_DP = 4,
    BITS_PER_NIBBLE = 4,
    BITS_PER_BYTE = 8,
    BITS_PER_DQS = 2,              ///< Differential clock pair
    MAX_RANKS_DIMM1 = 2,           ///< DIMM1 (inner DIMM) can't be a 4R DIMM
    MAX_PRIMARY_RANKS_PER_PORT = 4,
    MAX_MRANK_PER_PORT = MAX_DIMM_PER_PORT * MAX_RANK_PER_DIMM,
    RANK_MID_POINT = 4,            ///< Which rank number indicates the switch to the other DIMM
    DEFAULT_POLL_LIMIT = 50,       ///< the number of poll attempts in the event we can't calculate another
    MAX_NUM_IMP = 4,               ///< number of impedances valid per slew type
    MAX_NUM_CAL_SLEW_RATES = 4,    ///< 3V/ns, 4V/ns, 5V/ns, 6V/n
    MAX_DQ_BITS = 72,              /// TODO RTC:157753 This is Nimbus specific. Should be attribute/trait of processor.

    BYTES_PER_GB = 1000000000,      ///< Multiplier to go from GB to B
    T_PER_MT     = 1000000,         ///< Multiplier to go from MT/s to T/s
    CYCLES_PER_CMD  = 4,            ///< Best case cycles per MCBIST command

    // All need to be attributes? - BRS
    WR_LVL_BIG_STEP = 0b0111,
    WR_LVL_SMALL_STEP = 0b000,
    WR_LVL_PRE_DLY = 0b101010,
    WR_LVL_NUM_VALID_SAMPLES = 0x5,

    // Attribute? BRS
    COARSE_CAL_STEP_SIZE = 0x4,
    CONSEQ_PASS = 0x8,

    // Largest size a VPD keyword can be
    VPD_KEYWORD_MAX = 255,

    // Number of double words in...
    NUM_DW_IN_128B = 16,
    NUM_DW_IN_64B = 8,
};

enum times
{
    CONVERT_PS_IN_A_NS      = 1000,     ///< 1000 pico in an nano
    CONVERT_PS_IN_A_US      = 1000000,  ///< 1000000 picos in a micro

    DELAY_1NS               = 1,
    DELAY_10NS              = 10 ,      ///< general purpose 10  ns delay for HW mode
    DELAY_100NS             = 100,      ///< general purpose 100 ns delay for HW mode
    DELAY_1US               = 1000,     ///< general purpose 1 usec delay for HW mode
    DELAY_100US             = 100000,   ///< general purpose 100 usec delay for HW mode
    DELAY_1MS               = 1000000,  ///< general purpose 1 ms delay for HW mode

    // Not *exactly* a time but go with it.
    MHZ_TO_KHZ              = 1000,

    SEC_IN_HOUR             = 60 * 60,  ///< seconds in an hour, used for scrub times
    BG_SCRUB_IN_HOURS       = 12,

    CMD_TIMEBASE            = 8192,     ///< Represents the timebase multiplier for the MCBIST inter cmd gap
};

enum states
{
    LOW = 0,
    HIGH = 1,
    START = 1,
    STOP = 0,
    START_N = 0,
    STOP_N = 1,
    ON = 1,
    OFF = 0,
    ON_N = 0,
    OFF_N = 1,
    YES = 1,
    NO = 0,
    YES_N = 0,
    NO_N = 1,
    INVALID = 0xFF,
    NO_CHIP_SELECT_ACTIVE = 0xFF,
};

// Static consts describing the bits used in the cal_step_enable attribute
// These are bit positions. 0 is the left most bit.
enum cal_steps
{
    EXT_ZQCAL         = 0,
    WR_LEVEL          = 1,
    DQS_ALIGN         = 2,
    RDCLK_ALIGN       = 3,
    READ_CTR          = 4,
    READ_CTR_2D_VREF  = 5,
    WRITE_CTR         = 6,
    WRITE_CTR_2D_VREF = 7,
    COARSE_WR         = 8,
    COARSE_RD         = 9,
};

// Static consts for DDR4 voltages used in p9_mss_volt
enum voltages : uint64_t
{
    DDR4_NOMINAL_VOLTAGE = 1200,
    DDR4_VPP_VOLTAGE = 2500,
};


enum port_select
{
    // Port selects for MCBIST and CCS
    // Select for 1 port
    PORT0            = 0b1000,
    PORT1            = 0b0100,
    PORT2            = 0b0010,
    PORT3            = 0b0001,
    // Selects for 2 port combinations
    PORT01           = PORT0 | PORT1,
    PORT02           = PORT0 | PORT2,
    PORT03           = PORT0 | PORT3,
    PORT12           = PORT1 | PORT2,
    PORT13           = PORT1 | PORT3,
    PORT23           = PORT2 | PORT3,
    // Selects for 3 port combinations
    PORT012          = PORT0 | PORT1 | PORT2,
    PORT013          = PORT0 | PORT1 | PORT3,
    PORT023          = PORT0 | PORT2 | PORT3,
    PORT123          = PORT1 | PORT2 | PORT3,
    // Select all
    PORT0123         = PORT0 | PORT1 | PORT2 | PORT3,
    // Maybe a better name for disabling all
    PORT_NONE        = 0b0000,
};

enum dimm_select
{
    // Dimm selects for MCBIST and CCS
    // Select for 1 dimm
    DIMM0            = 0b10,
    DIMM1            = 0b01,
    // Selects for 2 dimm combinations
    DIMM01           = DIMM0 | DIMM1,
    // Maybe a better name for disabling all
    DIMM_NONE        = 0b00,
};


namespace mcbist
{

enum broadcast_timebase
{
    // Number of 1024 2:1 cycle timebases to wait starting MCBIST
    // for SRQs to get synced for broadcast mode
    TB_COUNT_2     = 0b0000001,
    TB_COUNT_4     = 0b0000011,
    TB_COUNT_8     = 0b0000111,
    TB_COUNT_16    = 0b0001111,
    TB_COUNT_32    = 0b0011111,
    TB_COUNT_64    = 0b0111111,
    TB_COUNT_128   = 0b1111111,
};

enum rmw_address
{
    // 32B block addresses into the maint portion of the rmw buffer
    DW0            = 0b111110000,
    DW1            = 0b111110001,
    DW2            = 0b111110010,
    DW3            = 0b111110011,
    DW4            = 0b111110100,
    DW5            = 0b111110101,
    DW6            = 0b111110110,
    DW7            = 0b111110111,
    DW8            = 0b111111000,
    DW9            = 0b111111001,
    DWA            = 0b111111010,
    DWB            = 0b111111011,
    DWC            = 0b111111100,
    DWD            = 0b111111101,
    DWE            = 0b111111110,
    DWF            = 0b111111111,
};

enum data_rotate_mode
{
    // MCBIST data rotate modes refer to register MCBDRCR bits 0:3
    ROTATE_0_BITS  = 0b0000,
    ROTATE_1_BITS  = 0b0001,
    ROTATE_2_BITS  = 0b0010,
    ROTATE_3_BITS  = 0b0011,
    ROTATE_4_BITS  = 0b0100,
    ROTATE_5_BITS  = 0b0101,
    ROTATE_6_BITS  = 0b0110,
    ROTATE_7_BITS  = 0b0111,
    ROTATE_8_BITS  = 0b1000,
    ROTATE_9_BITS  = 0b1001,
    ROTATE_10_BITS = 0b1010,
    ROTATE_11_BITS = 0b1011,
    ROTATE_12_BITS = 0b1100,
    ROTATE_13_BITS = 0b1101,
    ROTATE_14_BITS = 0b1110,
    ROTATE_15_BITS = 0b1111,
};

enum data_seed_mode
{
    // MCBIST data seed modes refer to register MCBDRCR bits 21:22
    ALL_UNIQUE        = 0b00,
    REPEAT_SEED_0     = 0b01,
    REPEAT_SEED_1     = 0b10,
    REPEAT_SEED_2     = 0b11,
};

enum data_mode
{
    // MCBIST test data modes
    FIXED_DATA_MODE   = 0b000,
    RAND_FWD_MODE     = 0b001,
    RAND_REV_MODE     = 0b010,
    RAND_FWD_MAINT    = 0b011,
    RAND_REV_MAINT    = 0b100,
    DATA_EQ_ADDR      = 0b101,
    ROTATE_LEFT_MODE  = 0b110,
    ROTATE_RIGHT_MODE = 0b111,
};

// 0:3  Operation Type
enum op_type
{
    WRITE            = 0b0000, // fast, with no concurrent traffic
    READ             = 0b0001, // fast, with no concurrent traffic
    READ_WRITE       = 0b0010,
    WRITE_READ       = 0b0011,
    READ_WRITE_READ  = 0b0100,
    READ_WRITE_WRITE = 0b0101,
    RAND_SEQ         = 0b0110,
    READ_READ_WRITE  = 0b1000,
    SCRUB_RRWR       = 0b1001,
    STEER_RW         = 0b1010,
    ALTER            = 0b1011, // (W)
    DISPLAY          = 0b1100, // (R, slow)
    CCS_EXECUTE      = 0b1111,

    // if bits 9:11 (Data Mode bits)  = 000  (bits 4:8 used to specify which subtest to go to)
    // Refresh only cmd if bits 9:11 (Data Mode bits) /= 000
    GOTO_SUBTEST_N = 0b0111,
};


enum test_type
{
    USER_MODE = 0,
    CENSHMOO = 1,
    SUREFAIL = 2,
    MEMWRITE = 3,
    MEMREAD = 4,
    CBR_REFRESH = 5,
    MCBIST_SHORT = 6,
    SHORT_SEQ = 7,
    DELTA_I = 8,
    DELTA_I_LOOP = 9,
    SHORT_RAND = 10,
    LONG1 = 11,
    BUS_TAT = 12,
    SIMPLE_FIX = 13,
    SIMPLE_RAND = 14,
    SIMPLE_RAND_2W = 15,
    SIMPLE_RAND_FIXD = 16,
    SIMPLE_RA_RD_WR = 17,
    SIMPLE_RA_RD_R = 18,
    SIMPLE_RA_FD_R = 19,
    SIMPLE_RA_FD_R_INF = 20,
    SIMPLE_SA_FD_R = 21,
    SIMPLE_RA_FD_W = 22,
    INFINITE = 23,
    WR_ONLY = 24,
    W_ONLY = 25,
    R_ONLY = 26,
    W_ONLY_RAND = 27,
    R_ONLY_RAND = 28,
    R_ONLY_MULTI = 29,
    SHORT = 30,
    SIMPLE_RAND_BARI = 31,
    W_R_INFINITE = 32,
    W_R_RAND_INFINITE = 33,
    R_INFINITE1 = 34,
    R_INFINITE_RF = 35,
    MARCH = 36,
    SIMPLE_FIX_RF = 37,
    SHMOO_STRESS = 38,
    SIMPLE_RAND_RA = 39,
    SIMPLE_FIX_RA = 40,
    SIMPLE_FIX_RF_RA = 41,
    TEST_RR = 42,
    TEST_RF = 43,
    W_ONLY_INFINITE_RAND = 44,
    MCB_2D_CUP_SEQ = 45,
    MCB_2D_CUP_RAND = 46,
    SHMOO_STRESS_INFINITE = 47,
    HYNIX_1_COL = 48,
    RMWFIX = 49,
    RMWFIX_I = 50,
    W_INFINITE = 51,
    R_INFINITE = 52,
};


} // namespace mcbist

enum class shmoo_edge : std::size_t
{
    LEFT,
    RIGHT
};

enum visual_max : uint64_t
{
    MAX_VISUAL_VALUE = 9999
};

} // namespace mss
#endif
