/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/shared/mss_const.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <generic/memory/lib/utils/mss_math.H>

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
    NIBBLES_PER_BYTE = 2,
    BITS_PER_NIBBLE = 4,
    BITS_PER_BYTE = 8,
    BITS_PER_DQS = 2,              ///< Differential clock pair
    MAX_RANKS_DIMM1 = 2,           ///< DIMM1 (inner DIMM) can't be a 4R DIMM
    MAX_PRIMARY_RANKS_PER_PORT = 4,
    MAX_RANK_PAIRS = 4,
    MAX_MRANK_PER_PORT = MAX_DIMM_PER_PORT * MAX_RANK_PER_DIMM,
    RANK_MID_POINT = 4,            ///< Which rank number indicates the switch to the other DIMM
    DEFAULT_POLL_LIMIT = 50,       ///< the number of poll attempts in the event we can't calculate another
    MAX_NUM_IMP = 4,               ///< number of impedances valid per slew type
    MAX_NUM_CAL_SLEW_RATES = 4,    ///< 3V/ns, 4V/ns, 5V/ns, 6V/n
    MAX_DQ_BITS = 72,              /// TODO RTC:157753 This is Nimbus specific. Should be attribute/trait of processor.
    MAX_DQ_NIBBLES_X4 = MAX_DQ_BITS / BITS_PER_NIBBLE, ///< For x4's there are 18 DQ nibbles for DQ 72 bits
    MAX_DRAMS_X8 = MAX_DQ_BITS / BITS_PER_NIBBLE, ///< For x8's there are 9 DRAM for 72 bits
    MAX_DRAMS_X4 = MAX_DQ_BITS / BITS_PER_BYTE, ///< For x4's there are 18 DRAM for 72 bits

    NUM_MRW_FREQS = 4,             ///< Used for ATTR_MSS_MRW_SUPPORTED_FREQ
    NUM_MAX_FREQS = 5,             ///< Used for ATTR_MAX_ALLOWED_DIMM_FREQ


    MARK_STORE_COUNT = 8,          ///< Elements in a VPD mark/store array
    BAD_DQ_BYTE_COUNT = 10,        ///< Elements in a BAD_DQ_BITMAP attribute array

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

    // MCBIST polling constant for actual HW
    // The specific value here is not important, only that it is very large to avoid polling timeouts,
    // but not to avoid any actual hardware timeouts
    // Note: ~0 is not used as that would cause MCBIST to never timeout even if the hardware is in an infinite loop
    // You can't get greater than ~0, so you'd never timeout
    // TODO RTC:166340 - Clean up MCBIST polling
    OVERLY_LARGE_NUMBER_OF_POLLS = 5000000000000,
};

enum times
{
    CONVERT_PS_IN_A_NS      = 1000,     ///< 1000 pico in an nano
    CONVERT_PS_IN_A_US      = 1000000,  ///< 1000000 picos in a micro

    DELAY_1NS               = 1,
    DELAY_10NS              = 10 ,      ///< general purpose 10  ns delay for HW mode
    DELAY_100NS             = 100,      ///< general purpose 100 ns delay for HW mode
    DELAY_1US               = 1000,     ///< general purpose 1 usec delay for HW mode
    DELAY_10US              = 10000,    ///< general purpose 1 usec delay for HW mode
    DELAY_100US             = 100000,   ///< general purpose 100 usec delay for HW mode
    DELAY_1MS               = 1000000,  ///< general purpose 1 ms delay for HW mode

    // Not *exactly* a time but go with it.
    MHZ_TO_KHZ              = 1000,

    SEC_IN_HOUR             = 60 * 60,  ///< seconds in an hour, used for scrub times
    BG_SCRUB_IN_HOURS       = 12,

    CMD_TIMEBASE            = 8192,     ///< Represents the timebase multiplier for the MCBIST inter cmd gap
    FULL_DLL_CAL_DELAY      = 37382,    ///< Full DLL calibration (in ddphy_nck cycles)
};

///
/// @brief ID codes so we can lookup which function triggered the ffdc fail
///
enum ffdc_function_codes
{
    // Used in fw_mark_store.H for MSS_INVALID_RANK_PASSED
    FWMS_READ = 30,
    FWMS_WRITE = 31,

    // Used in hw_mark_store.H for MSS_INVALID_RANK_PASSED
    HWMS_READ = 40,
    HWMS_WRITE = 41,

    // MSS_INVALID_INDEX_PASSED
    SYMBOL_COUNT_READ = 50,
    SYMBOL_COUNT_WRITE = 51,

    // Used in rank.H
    MAP_RP_PRIMARY_TO_INIT_CAL = 60,

    // Power thermal functions
    SLOPE = 70,
    INTERCEPT = 71,
    POWER_LIMIT = 72,
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
    _INVALID_ = 0xFF,
    NO_CHIP_SELECT_ACTIVE = 0xFF,
};

///
/// @brief function ID codes for FFDC functions
/// @note If we get a fail in HB, we can trace back to the function that failed
///
enum ffdc_functions
{
    // Following are used in rank.H
    RANK_PAIR_TO_PHY = 0,
    RANK_PAIR_FROM_PHY = 1,
    SET_RANKS_IN_PAIR = 2,
    GET_RANKS_IN_PAIR = 3,
    GET_RANK_FIELD = 4,
    GET_PAIR_VALID = 5,
    SET_RANK_FIELD = 6,
    RD_CTR_WORKAROUND_READ_DATA = 7,
    OVERRIDE_ODT_WR_CONFIG = 8,
    RECORD_BAD_BITS_HELPER = 9,
};
// Static consts describing the bits used in the cal_step_enable attribute
// These are bit positions. 0 is the left most bit.
enum cal_steps : uint64_t
{
    DRAM_ZQCAL        = 0,  ///< DRAM ZQ Calibration Long
    DB_ZQCAL          = 1,  ///< (LRDIMM) Data Buffer ZQ Calibration Long
    MREP              = 2,  ///< (LRDIMM) DRAM Interface MDQ Receive Enable Phase
    MRD_COARSE        = 3,  ///< (LRDIMM) DRAM-to-DB Read Delay - Coarse
    MRD_FINE          = 4,  ///< (LRDIMM) DRAM-to-DB Read Delay - Fine
    WR_LEVEL          = 5,  ///< Write Leveling
    INITIAL_PAT_WR    = 6,  ///< Initial Pattern Write
    WR_VREF_LATCH     = 7,  ///< Write VREF Latching
    DWL               = 8,  ///< (LRDIMM) DRAM Interface Write Leveling
    MWD_COARSE        = 9,  ///< (LRDIMM) DB-to-DRAM Write Delay - Coarse
    MWD_FINE          = 10, ///< (LRDIMM) DB-to-DRAM Write Delay - Fine
    HWL               = 11, ///< (LRDIMM) Host Interface Write Leveling
    DQS_ALIGN         = 12, ///< DQS (read) alignment
    RDCLK_ALIGN       = 13, ///< Alignment of the internal SysClk to the Read clock
    READ_CTR_2D_VREF  = 14, ///< Read Vref
    READ_CTR          = 15, ///< Read Centering
    WRITE_CTR_2D_VREF = 16, ///< Write Vref
    WRITE_CTR         = 17, ///< Write Centering
    COARSE_WR         = 18, ///< Initial Coarse Pattern Write
    COARSE_RD         = 19, ///< Coarse Read Centering
    TRAINING_ADV      = 20, ///< Flag for draminit training advance in the attribute/ CUSTOM_READ_CTR in code

    // Not *exactly* a cal step but go w/it
    RUN_ALL_CAL_STEPS          = 0xFFFFF800,
    RUN_CAL_SKIP_WR_RD_2D_VREF = 0xFFFD7800,

    INITIAL_PAT_WR_TO_RD_CTR_LEN = inclusive_range(INITIAL_PAT_WR, READ_CTR),
    WR_VREF_TO_COARSE_RD_LEN = inclusive_range(WRITE_CTR_2D_VREF, COARSE_RD),
    RDCLK_ALIGN_TO_RD_CTR_LEN = inclusive_range(RDCLK_ALIGN, READ_CTR),
    // In this case, we just want to clear everything prior to WR 2D VREF, inclusive range also kills the WR VREF bit
    DRAM_ZQCAL_UP_TO_WRITE_CTR_2D_VREF = WRITE_CTR_2D_VREF,
};

///
/// @brief enums for draminit_training_adv procedure
///
enum training_advance
{
    PATTERN0_START = 0,
    PATTERN0_LEN = 16,
    PATTERN1_START = 16,
    PATTERN1_LEN = 16
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

///
/// @brief throttle_type used to set bulk_pwr_throttls to run POWER or THERMAL throttling
/// @note OCC will be using the POWER option
///
enum class throttle_type
{
    POWER = 0,
    THERMAL = 1,
};

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
