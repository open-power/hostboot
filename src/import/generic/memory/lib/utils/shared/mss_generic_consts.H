/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/shared/mss_generic_consts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
/* [+] Evan Lojewski                                                      */
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
/// @file mss_generic_consts.H
/// @brief Common constants to be shared
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_GENERIC_CONSTS_H_
#define _MSS_GENERIC_CONSTS_H_

#ifndef __PPE__
    #include <cstdint>
#endif

namespace mss
{

///
/// @brief Common constants
///
enum common_consts
{
    DEFAULT_POLL_LIMIT = 50,  ///< the number of poll attempts in the event we can't calculate another
    MEMCMP_EQUAL = 0,         ///< Equal comparison value for memcmp
    BAD_BITS_RANKS = 4,       ///< Bad bit attribute's number of ranks
    BAD_DQ_BYTE_COUNT = 10,      ///< Bad bit attribute's number of byte
    ATTR_RANK0 = 0, ///< Attribute index for rank0
    ATTR_RANK1 = 1, ///< Attribute index for rank1
    ATTR_RANK2 = 2, ///< Attribute index for rank2
    ATTR_RANK3 = 3, ///< Attribute index for rank3
};

///
/// @brief Common mcbist constants
///
enum mcbist_common_consts
{
    CYCLES_PER_CMD  = 4,      ///< Best case cycles per MCBIST command
    MAX_RANK_PER_DIMM = 4,

    BYTES_PER_GB = 1000000000,      ///< Multiplier to go from GB to B
    T_PER_MT     = 1000000,         ///< Multiplier to go from MT/s to T/s

    // Number of double words in...
    NUM_DW_IN_128B = 16,
    NUM_DW_IN_64B = 8,

    BG_SCRUB_IN_HOURS       = 12,
    CMD_TIMEBASE            = 8192,     ///< Represents the timebase multiplier for the MCBIST inter cmd gap
    MAX_CMD_GAP             = 4095,     ///< Represents the maximum (non-multplied) time for MCBIST inter cmd gap


    // MCBIST polling constant for actual HW
    // The specific value here is not important, only that it is very large to avoid polling timeouts,
    // but not to avoid any actual hardware timeouts
    // Note: ~0 is not used as that would cause MCBIST to never timeout even if the hardware is in an infinite loop
    // You can't get greater than ~0, so you'd never timeout
    // TODO RTC:166340 - Clean up MCBIST polling
    OVERLY_LARGE_NUMBER_OF_POLLS = 5000000000000,
};

///
/// @brief Common timings
///
enum common_timings
{
    DELAY_1NS               = 1,
    DELAY_10NS              = 10 ,         ///< general purpose 10  ns delay for HW mode
    DELAY_100NS             = 100,         ///< general purpose 100 ns delay for HW mode
    DELAY_1US               = 1000,        ///< general purpose 1 usec delay for HW mode
    DELAY_10US              = 10000,       ///< general purpose 1 usec delay for HW mode
    DELAY_100US             = 100000,      ///< general purpose 100 usec delay for HW mode
    DELAY_1MS               = 1000000,     ///< general purpose 1 ms delay for HW mode
    DELAY_1S                = 1000000000,  ///< general purpose 1 sec delay for HW mode
};

///
/// @brief Common conversions
///
enum conversions
{
    CONVERT_PS_IN_A_NS      = 1000,     ///< 1000 pico in an nano
    CONVERT_PS_IN_A_US      = 1000000,  ///< 1000000 picos in a micro
    MHZ_TO_KHZ              = 1000,
    SEC_IN_HOUR             = 60 * 60,  ///< seconds in an hour, used for scrub times
    NIBBLES_PER_BYTE = 2,
    BITS_PER_NIBBLE = 4,
    BITS_PER_BYTE = 8,
    BIT_POS_FOR_BYTE0 = BITS_PER_BYTE * 0,
    BIT_POS_FOR_BYTE1 = BITS_PER_BYTE * 1,
    BIT_POS_FOR_BYTE2 = BITS_PER_BYTE * 2,
    BIT_POS_FOR_BYTE3 = BITS_PER_BYTE * 3,
    BIT_POS_FOR_BYTE4 = BITS_PER_BYTE * 4,
    BIT_POS_FOR_BYTE5 = BITS_PER_BYTE * 5,
    BIT_POS_FOR_BYTE6 = BITS_PER_BYTE * 6,
    BIT_POS_FOR_BYTE7 = BITS_PER_BYTE * 7,

    // Used by exp_decoder.C for dA to cA
    DECI_TO_CENTI = 10,
};

enum generic_sizes
{
    NUM_MAX_FREQS = 5,             ///< Used for ATTR_MAX_ALLOWED_DIMM_FREQ
    MARK_STORE_COUNT = 8,          ///< Elements in a VPD mark/store array
    MAX_RANK_PER_DIMM_ATTR = 4,    ///< Elements in a per-rank attribute array
    MODULE_PARTNUMBER_ATTR = 20,   ///< Elements in a module partnumber attribute array
};

///
/// @brief FFDC generic codes
///
enum generic_ffdc_codes
{
    // Starting at 0x1%%% to avoid
    // any collisions with values
    // from controller specific ffdc codes
    SET_ATTR_DIMM_TYPE = 0x1000,
    SET_ATTR_DRAM_GEN = 0x1001,
    SET_ATTR_HYBRID = 0x1002,
    SET_ATTR_HYBRID_MEDIA = 0x1003,
    SET_ATTR_MASTER_RANKS = 0x1004,
    SET_ATTR_RANKS_CONFIGED  = 0x1005,
    GET_FIELD = 0x1006,
    READ_SPD_FIELD = 0x1007,
    BASE_CFG_PARAM_SELECT = 0x1008,
    DIMM_MODULE_PARAM_SELECT = 0x1009,
    BASE_CFG_FACTORY = 0x100A,
    DIMM_MODULE_FACTORY = 0x100B,
    GET_TAAMIN = 0x100C,
    GET_TCKMIN = 0x100D,
    GET_TCKMAX = 0x100E,
    GET_TIMEBASES_FTB = 0x100F,
    GET_TIMEBASES_MTB = 0x1010,
    GET_SUPPORTED_REV = 0x1011,
    TRASMIN = 0x1012,
    TRCMIN = 0x1013,
    TRFC1MIN = 0x1014,
    TRFC2MIN = 0x1015,
    TRFC4MIN = 0x1016,
    TFAWMIN = 0x1017,
    TWTR_S_MIN = 0x1018,
    TWRMIN = 0x1019,
    TWTR_L_MIN = 0x101A,
    DEVICE_TYPE = 0x101B,
    BASE_MODULE_TYPE = 0x101C,
    BAD_SPD_DATA = 0x101D,
    SET_FIELD = 0x101E,
    SELECT_SUPPORTED_FREQ = 0x101F,
    FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT = 0x1020,
    FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT_VECTOR = 0x1021,
    FREQ_SCOREBOARD_REMOVE_FREQS_NOT_ON_LIST = 0x1022,
    FREQ_SCOREBOARD_MAX_SUPPORTED_FREQ = 0x1023,
    FREQ_SCOREBOARD_SUPPORTED_FREQS = 0x1024,
    LIMIT_FREQ_BY_VPD = 0x1025,
    SET_DIMM_TYPE = 0x1026,
    SET_DRAM_GEN = 0x1027,
    SET_HYBRID = 0x1028,
    SET_HYBRID_MEDIA = 0x1029,
    SET_MRANKS = 0x102A,
    SET_HOST_TO_DDR_SPEED_RATIO = 0x102B,
    SET_ATTR_HOST_TO_DDR_SPEED_RATIO = 0x102C,
    CCS_INST_CONFIGURE_RANK = 0x102D,
    SET_SPD_CONTENT_REVISION = 0x102E,
    SET_ATTR_SPD_CONTENT_REVISION = 0x102F,
    SET_DIMM_RANKS_CNFG = 0x1039,
    DDIMM_RAWCARD_DECODE = 0x103a,
    INIT_RANK_INFO = 0x103B,
    BIAS_PMIC_FROM_SPD = 0x103C,
    PMIC_ENABLE_SPD = 0x103D,
    SET_DRAM_WIDTH = 0x1040,

    SET_SI_VREF_DRAM_WR = 0x1041,
    SET_SI_MC_RCV_IMP_DQ_DQS = 0x1042,
    SET_SI_MC_DRV_IMP_DQ_DQS_PULL_UP = 0x1043,
    SET_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN = 0x1044,
    SET_SI_MC_DRV_SLEW_RATE_DQ_DQS = 0x1045,
    SET_SI_MC_DRV_IMP_CMD_ADDR = 0x10466,
    SET_SI_MC_DRV_SLEW_RATE_CMD_ADDR = 0x1047,
    SET_SI_MC_DRV_IMP_CLK = 0x1048,
    SET_SI_MC_DRV_SLEW_RATE_CLK = 0x1049,
    SET_SI_MC_RCV_IMP_ALERT_N = 0x1050,
    SET_SI_DRAM_RTT_NOM = 0x1051,
    SET_SI_DRAM_RTT_WR = 0x1052,
    SET_SI_DRAM_RTT_PARK = 0x1053,
    SET_SI_DRAM_PREAMBLE = 0x1054,
    SET_SI_MC_DRV_EQ_DQ_DQS = 0x1055,
    SET_SI_DRAM_DRV_IMP_DQ_DQS = 0x1056,
    SET_SI_VREF_DQ_TRAIN_RANGE = 0x1057,
    SET_SI_VREF_DQ_TRAIN_VALUE = 0x1058,
    SET_SI_ODT_WR = 0x1059,
    SET_SI_ODT_RD = 0x1060,
    SET_SI_GEARDOWN_MODE = 0x1061,
    PRE_DATA_ENGINE_CTOR = 0x1062,
    SET_DRAM_GEN_METADATA = 0x1063,
    SET_DIMM_TYPE_METADATA = 0x1064,
    SET_DIMM_POS_METADATA = 0x1065,
    SET_LOGICAL_RANKS = 0x1066,
    SET_PRIM_STACK_TYPE = 0x1067,
    SET_DIMM_SIZE = 0x1068,
    SET_PRIM_BUS_WIDTH = 0x1069,
    SET_PRIM_DIE_COUNT = 0x1070,
    SET_DRAM_DENSITY = 0x1071,

    // Power thermal functions
    POWER_LIMIT = 0x1072,
    SLOPE = 0x1073,
    INTERCEPT = 0x1074,

    SET_SI_RD_VREF_DQ = 0x1075,
    SET_CAC_DELAY_A = 0x1076,
    SET_CAC_DELAY_B = 0x1077,
    EFD_CA_LATENCY_MODE = 0x1080,
    EFD_CA_PL_MODE = 0x1081,
    SET_COL_ADDR_BITS = 0x1082,
    SET_ROW_ADDR_BITS = 0x1083,
    SET_3DS_HEIGHT = 0x1084,
    SET_DRAM_CWL = 0x1085,
    SET_DRAM_TREFI = 0x1086,
    SET_DRAM_TCCD_L = 0x1087,
    SET_DRAM_TWTR_L = 0x1088,
    SET_DRAM_TWTR_S = 0x1089,
    SET_DRAM_TFAW = 0x108A,
    SET_DRAM_TRCD = 0x108B,
    SET_DRAM_TRP = 0x108C,
    SET_DRAM_TRAS = 0x108D,
    SET_DRAM_TWR = 0x108E,
    SET_DRAM_TRTP = 0x108F,
    SET_DRAM_TRRD_S = 0x1090,
    SET_DRAM_TRRD_L = 0x1091,
    SET_DRAM_TRFC = 0x1092,
    SET_DRAM_TRFC_DLR = 0x1093,
    SET_DRAM_MFG_ID = 0x1094,

    // Used in fw_mark_store.H for MSS_INVALID_RANK_PASSED
    FWMS_READ = 0x1095,
    FWMS_WRITE = 0x1096,

    // Used in hw_mark_store.H for MSS_INVALID_RANK_PASSED
    HWMS_READ = 0x1097,
    HWMS_WRITE = 0x1098,

    // MSS_INVALID_INDEX_PASSED
    SYMBOL_COUNT_READ = 0x1099,
    SYMBOL_COUNT_WRITE = 0x109A,

    SET_RCD_MFG_ID = 0x109B,
    SET_DRAM_MODULE_HEIGHT = 0x109C,
    SET_SPD_REVISION = 0x109D,

    MRS_MIRROR_MODE = 0x109E,
    MRS01_GEN = 0x109F,
    MRS02_GEN = 0x10A0,
    SET_MODULE_MFG_ID = 0x10A1,
    PDA_WR_VREF_LATCH_CONTAINER = 0x10A2,

    // PMIC polling
    POLL_INPUT_PORT_READY = 0x10A3,
    POLL_FOR_PBULK_GOOD = 0x10A4,

    EFD_FACTORY = 0x10A5,
};

///
/// @brief Supported proc types
/// @note Processor types by system generation and sub numbering
///
enum class proc_type
{
    NIMBUS  = 0x0900,
    CUMULUS = 0x0901,
    AXONE   = 0x0902,
};

///
/// @brief Supported memory controller types
///
enum class mc_type
{
    NIMBUS   = 0,
    CENTAUR  = 1,
    EXPLORER = 2,
};

///
/// @brief JEDEC supported DDR speeds
/// @note Includes DDR4 and DDR5 only
///
enum ddr_dimm_speeds
{
    // Supported frequencies
    DIMM_SPEED_1600 = 1600,
    DIMM_SPEED_1866 = 1866,
    DIMM_SPEED_2133 = 2133,
    DIMM_SPEED_2400 = 2400,
    DIMM_SPEED_2666 = 2666,
    DIMM_SPEED_2933 = 2933,
    DIMM_SPEED_3200 = 3200,
    DIMM_SPEED_3600 = 3600,
    DIMM_SPEED_4000 = 4000,
    DIMM_SPEED_4400 = 4400,
    DIMM_SPEED_4800 = 4800,

    // Max/Mins for specific generations here
    DDR4_MIN_SPEED = 1600,
    DDR4_MAX_SPEED = 3200,
    DDR5_MIN_SPEED = 3200,
    DDR5_MAX_SPEED = 4800,
};

///
/// @brief DDR4 JEDEC constants
///
enum ddr4_consts
{
    // WR VREF JEDEC values - we're using em in multiple places, so let's define them in one
    // Single range max is the maximum range for a single WR VREF range in JEDEC - 0b110010
    WR_VREF_SINGLE_RANGE_MAX = 0b110010,
    // Crossover range is where the top of Range 2 (the lower range) equals the bottom of Range 1 (the upper range)
    WR_VREF_CROSSOVER_RANGE  = 0b011000,
    // Max range is computed from single range max (50) + the crossover range (24)
    WR_VREF_MAX_COMPOSITE_RANGE = WR_VREF_SINGLE_RANGE_MAX + WR_VREF_CROSSOVER_RANGE,

    // Yes, Range 1 is 0 and Range 2 is 1
    WR_VREF_RANGE1 = 0,
    WR_VREF_RANGE2 = 1,
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
    // Uses "_" in the name for INVALID as INVALID is defined as a macro in the
    // FSP code. If we just use INVALID as an enum name, then the preprocessor
    // compile phase changes it to be the macro.
    _INVALID_ = 0xFF,
    NO_CHIP_SELECT_ACTIVE = 0xFF,
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
    WRITE_READ_SF_FIX = 1,
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
    WRITE_READ_SF_RF = 37,
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
    MARCH_RF = 53,
    MARCH_C_MINUS = 54,
    MARCH_IFA_13 = 55,
};


} // namespace mcbist

namespace omi
{

///
/// @brief dl0 no forward progress timer
///
enum no_forward_progress_timer
{
    NO_FORWARD_TIMER_1US      = 0b0000,
    NO_FORWARD_TIMER_2US      = 0b0001,
    NO_FORWARD_TIMER_4US      = 0b0010,
    NO_FORWARD_TIMER_8US      = 0b0011,
    NO_FORWARD_TIMER_16US     = 0b0100,
    NO_FORWARD_TIMER_32US     = 0b0101,
    NO_FORWARD_TIMER_64US     = 0b0110,
    NO_FORWARD_TIMER_128US    = 0b0111,
    NO_FORWARD_TIMER_256US    = 0b1000,
    NO_FORWARD_TIMER_512US    = 0b1001,
    NO_FORWARD_TIMER_1MS      = 0b1010,
    NO_FORWARD_TIMER_2MS      = 0b1011,
    NO_FORWARD_TIMER_4MS      = 0b1100,
    NO_FORWARD_TIMER_8MS      = 0b1101,
    NO_FORWARD_TIMER_16MS     = 0b1110,
    NO_FORWARD_TIMER_DISABLED = 0b1111,
};

///
/// @brief dl0 PHY control mode - determines the amount of time needed to receive pattern A or pattern B
///
enum phy_ctr_mode
{
    PHY_CTR_MODE_1US   = 0b0000,
    PHY_CTR_MODE_50US  = 0b0001,
    PHY_CTR_MODE_100US = 0b0010,
    PHY_CTR_MODE_200US = 0b0011,
    PHY_CTR_MODE_500US = 0b0100,
    PHY_CTR_MODE_1MS   = 0b0101,
    PHY_CTR_MODE_2MS   = 0b0110,
    PHY_CTR_MODE_3MS   = 0b0111,
    PHY_CTR_MODE_4MS   = 0b1000,
    PHY_CTR_MODE_5MS   = 0b1001,
    PHY_CTR_MODE_6MS   = 0b1010,
    PHY_CTR_MODE_8MS   = 0b1011,
    PHY_CTR_MODE_10MS  = 0b1100,
    PHY_CTR_MODE_15MS  = 0b1101,
    PHY_CTR_MODE_30MS  = 0b1110,
    PHY_CTR_MODE_60MS  = 0b1111,
};

///
/// @brief dl0 supported link widths
///
enum link_widths
{
    LINK_WIDTHS_X4PLUS1 = 0b1000,
    LINK_WIDTHS_X16     = 0b0100,
    LINK_WIDTHS_X8      = 0b0010,
    LINK_WIDTHS_X4      = 0b0001,
};

///
/// @brief dl0 train mode
///
enum train_mode
{
    TX_ZEROS             = 0b0000,
    TX_PATTERN_A         = 0b0001,
    TX_PATTERN_B         = 0b0010,
    TX_SYNC_PATTERN      = 0b0011,
    TX_TRAINING_STATE1   = 0b0100,
    TX_TRAINING_STATE2   = 0b0101,
    TX_TRAINING_STATE3   = 0b0110,
    TX_TRAINING_STATE0   = 0b0111,
    ENABLE_AUTO_TRAINING = 0b1000,
};


///
/// @brief These values are the number of clock cycles and the times specified assume a 625ps period.
///        This timer value must be greater than the di/dt timer
///
enum rx_cdr_timer
{
    CDR_TIMER_DISABLED  = 0b0001,
    CDR_TIMER_60NS      = 0b0001,
    CDR_TIMER_125NS     = 0b0010,
    CDR_TIMER_185NS     = 0b0011,
    CDR_TIMER_250NS     = 0b0100,
    CDR_TIMER_375NS     = 0b0101,
    CDR_TIMER_500NS     = 0b0110,
    CDR_TIMER_750NS     = 0b0111,
    CDR_TIMER_1US       = 0b1000,
    CDR_TIMER_2US       = 0b1001,
    CDR_TIMER_4US       = 0b1010,
    CDR_TIMER_8US       = 0b1011,
    CDR_TIMER_16US      = 0b1100,
    CDR_TIMER_32US      = 0b1101,
    CDR_TIMER_64US      = 0b1110,
    CDR_TIMER_128US     = 0b1111,
};

///
/// @brief Amount of time to wait after lane is turned on/off before another lane can be turned on/off
///
enum didt_timer
{
    DIDT_TIMER_DISABLED = 0b0000,
    DIDT_TIMER_5NS      = 0b0001,
    DIDT_TIMER_10NS     = 0b0010,
    DIDT_TIMER_15NS     = 0b0011,
    DIDT_TIMER_20NS     = 0b0100,
    DIDT_TIMER_30NS     = 0b0101,
    DIDT_TIMER_45NS     = 0b0110,
    DIDT_TIMER_60NS     = 0b0111,
    DIDT_TIMER_90NS     = 0b1000,
    DIDT_TIMER_125NS    = 0b1001,
    DIDT_TIMER_185NS    = 0b1010,
    DIDT_TIMER_250NS    = 0b1011,
    DIDT_TIMER_375NS    = 0b1100,
    DIDT_TIMER_500NS    = 0b1101,
    DIDT_TIMER_768NS    = 0b1110,
    DIDT_TIMER_1US      = 0b1111,
};

///
/// @brief Calibration timer - amount of time betweem re-calibration for a given lane
///
enum recal_timer
{
    RECAL_TIMER_DISABLED  = 0b000,
    RECAL_TIMER_25MS      = 0b001,
    RECAL_TIMER_50MS      = 0b010,
    RECAL_TIMER_100MS     = 0b011,
    RECAL_TIMER_200MS     = 0b100,
    RECAL_TIMER_400MS     = 0b101,
    RECAL_TIMER_800MS     = 0b110,
    RECAL_TIMER_1600MS    = 0b111,
};

///
/// @brief PMU prescalar value
///
enum pmu_prescalar
{
    PRESCALAR_16BIT = 0b000,
    PRESCALAR_8BIT  = 0b001,
    PRESCALAR_20BIT = 0b100,
};


///
/// @brief PMU cntrx pair selector
///
enum cntrl_pair_selector
{
    SEL_ODD      = 0b00,
    SEL_EVEN     = 0b01,
    SEL_BOTH_AND = 0b10,
    SEL_BOTH_XOR = 0b11,
};

///
/// @brief PMU cntrx event selector
///
enum cntrl_event_selector
{
    SIG_7_6 = 0b00,
    SIG_5_4 = 0b01,
    SIG_3_2 = 0b10,
    SIG_1_0 = 0b11,
};

///
/// @brief Configuration override to select lane width for dynamic lane power down modes.
///
enum lan_width_override
{
    TL_CTR_BY_SIDEBAND = 0b00,
    DL_OVERRIDE_X2     = 0b01,
    DL_OVERRIDE_X4     = 0b10,
    DL_OVERRIDE_X8     = 0b11,
};

///
/// @brief Number of consecutive pattern B seen before indicating received pattern B
///
enum b_hysteresis
{
    B_HYSTERESIS_16  = 0b0000,
    B_HYSTERESIS_24  = 0b0001,
    B_HYSTERESIS_32  = 0b0010,
    B_HYSTERESIS_40  = 0b0011,
    B_HYSTERESIS_48  = 0b0100,
    B_HYSTERESIS_56  = 0b0101,
    B_HYSTERESIS_64  = 0b0110,
    B_HYSTERESIS_72  = 0b0111,
    B_HYSTERESIS_80  = 0b1000,
    B_HYSTERESIS_96  = 0b1001,
    B_HYSTERESIS_128 = 0b1010,
    B_HYSTERESIS_256 = 0b1011,
    B_HYSTERESIS_512 = 0b1100,
    B_HYSTERESIS_1K  = 0b1101,
    B_HYSTERESIS_2K  = 0b1110,
    B_HYSTERESIS_4K  = 0b1111,
};

///
/// @brief Number of consecutive pattern A seen before indicating received pattern A.
///
enum a_hysteresis
{
    A_HYSTERESIS_16   = 0b0000,
    A_HYSTERESIS_24   = 0b0001,
    A_HYSTERESIS_32   = 0b0010,
    A_HYSTERESIS_48   = 0b0011,
    A_HYSTERESIS_64   = 0b0100,
    A_HYSTERESIS_96   = 0b0101,
    A_HYSTERESIS_128  = 0b0110,
    A_HYSTERESIS_256  = 0b0111,
    A_HYSTERESIS_512  = 0b1000,
    A_HYSTERESIS_1024 = 0b1001,
    A_HYSTERESIS_2K   = 0b1010,
    A_HYSTERESIS_4K   = 0b1011,
    A_HYSTERESIS_8K   = 0b1100,
    A_HYSTERESIS_16K  = 0b1101,
    A_HYSTERESIS_32K  = 0b1110,
    A_HYSTERESIS_64K  = 0b1111,
};

///
/// @brief Lanes disabled
///
enum
{
    LANE_DISABLED_NONE = 0b00000000,
    LANE_DISABLED_7    = 0b00000001,
    LANE_DISABLED_6    = 0b00000010,
    LANE_DISABLED_5    = 0b00000100,
    LANE_DISABLED_4    = 0b00001000,
    LANE_DISABLED_3    = 0b00010000,
    LANE_DISABLED_2    = 0b00100000,
    LANE_DISABLED_1    = 0b01000000,
    LANE_DISABLED_0    = 0b10000000,
};

///
/// @brief dl0 inject crc direction
///
enum crc_inject_dir
{
    CRC_DIR_RX = 0,
    CRC_DIR_TX = 1,
};

///
/// @brief dl0 crc injection rate
///
enum crc_inject_rate
{
    CRC_INJ_RATE_1US   = 0b0000,
    CRC_INJ_RATE_8US   = 0b0001,
    CRC_INJ_RATE_64US  = 0b0010,
    CRC_INJ_RATE_512US = 0b0011,
    CRC_INJ_RATE_4MS   = 0b0100,
    CRC_INJ_RATE_32MS  = 0b0101,
    CRC_INJ_RATE_256MS = 0b0110,
    CRC_INJ_RATE_2S    = 0b0111,
};

///
/// @brief CFG_DL0_EDPL_TIME: dl0 edpl time window
///
enum edpl_time_win
{
    EDPL_TIME_WIN_NO          = 0b0000,
    EDPL_TIME_WIN_4US         = 0b0001,
    EDPL_TIME_WIN_32US        = 0b0010,
    EDPL_TIME_WIN_256US       = 0b0011,
    EDPL_TIME_WIN_2MS         = 0b0100,
    EDPL_TIME_WIN_16MS        = 0b0101,
    EDPL_TIME_WIN_128MS       = 0b0110,
    EDPL_TIME_WIN_1S          = 0b0111,
    EDPL_TIME_WIN_8S          = 0b1000,
    EDPL_TIME_WIN_64S         = 0b1001,
    EDPL_TIME_WIN_512S        = 0b1010,
    EDPL_TIME_WIN_4KS         = 0b1011,
    EDPL_TIME_WIN_32KS        = 0b1100,
    EDPL_TIME_WIN_256KS       = 0b1101,
    EDPL_TIME_WIN_2MILLIONS   = 0b1110,
    EDPL_TIME_WIN_16MILLIONS  = 0b1111,
};

///
/// @brief CFG_DL0_EDPL_THRESHOLD: dl0 edpl threshold
///
enum edpl_err_thres
{
    EDPL_ERR_THRES_DISABLED = 0b000,
    EDPL_ERR_THRES_2        = 0b001,
    EDPL_ERR_THRES_4        = 0b010,
    EDPL_ERR_THRES_8        = 0b011,
    EDPL_ERR_THRES_16       = 0b100,
    EDPL_ERR_THRES_32       = 0b101,
    EDPL_ERR_THRES_64       = 0b110,
    EDPL_ERR_THRES_128      = 0b111,
};

///
/// @brief CONFIG1_CFG_PREIPL_PRBS_TIME: config1 pre-ipl prbs time
///
enum preipl_prbs_time
{
    PREIPL_PRBS_256US      = 0b000,
    PREIPL_PRBS_1US        = 0b001,
    PREIPL_PRBS_4MS        = 0b010,
    PREIPL_PRBS_16MS       = 0b011,
    PREIPL_PRBS_64MS       = 0b100,
    PREIPL_PRBS_256MS      = 0b101,
    PREIPL_PRBS_1S         = 0b110,
    PREIPL_PRBS_4S         = 0b111,
};

}
///
/// @brief Supported DIMM speed equality deliberations
///
enum class speed_equality : uint8_t
{
    NOT_EQUAL_DIMM_SPEEDS = 0, ///< denotes all DIMMs don't have the same speed
    EQUAL_DIMM_SPEEDS = 1, ///< denotes all DIMMs have the same speed
};

namespace spd
{

///
/// @brief SPD revisions - not tied any particular module
///
enum rev : uint8_t
{
    V0_0 = 0x00, ///< represents Rev 0.0
    V0_3 = 0x03, ///< represents Rev 0.3
    V0_4 = 0x04, ///< represents Rev 0.4
    V1_0 = 0x10, ///< represents Rev 1.0
    V1_1 = 0x11, ///< represents Rev 1.1
    V1_2 = 0x12, ///< represents Rev 1.2

    // These module revisions can vary independently
    // so we track the largest decoded revision here.
    GEN_SEC_MAX = V1_1,
    RDIMM_MAX = V1_1,
    LRDIMM_MAX = V1_2,
    DDIMM_MAX = V0_4,
};

///
/// @brief SPD module parameters
/// @note helps distinguish SPD decoder sections
///
enum module_params
{
    UNINITIALIZED,
    BASE_CNFG,
    RDIMM_MODULE,
    LRDIMM_MODULE,
    NVDIMM_MODULE,
    DDIMM_MODULE,
};

///
/// @brief DRAM generation selector
/// @note values set to SPD settings
///
enum device_type
{
    DDR4 = 0x0c,
};

///
/// @brief Base module types
/// @note values set to SPD settings
///
enum base_module_type
{
    RDIMM = 0b0001,
    LRDIMM = 0b0100,
    DDIMM = 0b1010,
    SORDIMM = 0b1000,
    MINIRDIMM = 0b0101,
};

enum guard_band : uint16_t
{
    // Used for caclulating spd timing values - from JEDEC rounding algorithm
    // Correction factor is 1% (for DDR3) or 2.5% (for DDR4)
    // when doing integer math, we add-in the inverse correction factor
    // Formula used for derivation:
    // Guardband = 1000 * (1000* correction_factor) - 1
    INVERSE_DDR4_CORRECTION_FACTOR = 974, ///< DDR4 correction factor
};

}// spd

namespace efd
{


///
/// @brief EFD Module identifier
/// @note helps distinguish the EFD identifier
///
enum id
{
    DDR4_CUSTOM_MICROCHIP = 0x11,
};

}//efd

///
/// @brief DIMM nibble mask
/// @note nibble0: 4 high bits, nibble1: 4 low bits
///
enum nibble_mask
{
    MASK_NIBBLE0 = 0xf0,
    MASK_NIBBLE1 = 0x0f,
};

///
/// @brief throttle_type used to set bulk_pwr_throttls to run POWER or THERMAL throttling
/// @note OCC will be using the POWER option
///
enum class throttle_type
{
    POWER = 0,
    THERMAL = 1,
};



///
/// @brief Trait classes for mc_type
/// @tparam MC the mc_type
///
template< mc_type MC >
class mcTypeTraits;

///
/// @brief Trait classes for mc_type - NIMBUS specialization
///
template< >
struct mcTypeTraits<mc_type::NIMBUS>
{
    enum
    {
        MC_PER_MODULE = 2,
        MCS_PER_MC = 2,
        MCS_PER_PROC = MC_PER_MODULE * MCS_PER_MC,
        PORTS_PER_MCBIST = 4,
        PORTS_PER_MCS = 2,
        DIMMS_PER_PORT = 2,
        DIMMS_PER_MCS = PORTS_PER_MCS * DIMMS_PER_PORT,
        DIMMS_PER_MCBIST = PORTS_PER_MCBIST * DIMMS_PER_PORT,
    };
};

///
/// @brief Trait classes for mc_type - EXPLORER specialization
///
template< >
struct mcTypeTraits<mc_type::EXPLORER>
{
    enum
    {
        MC_PER_PROC = 2,
        MI_PER_MC = 2,
        OMIC_PER_MC = 3,
        MCC_PER_MI = 2,
        OMI_PER_MCC = 2,
        OCMB_PER_OMI = 1,
        PORTS_PER_OCMB = 1,
        DIMMS_PER_PORT = 2,
    };
};

}// mss

#endif
