/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/shared/mss_const.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CONST_H_
#define _MSS_CONST_H_

#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
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
    PORTS_PER_MODULE = MC_PER_MODULE * MCS_PER_MC * PORTS_PER_MCS,
    BITS_PER_DP = 16,
    NIBBLES_PER_DP = BITS_PER_DP / BITS_PER_NIBBLE,
    BYTES_PER_DP = BITS_PER_DP /  BITS_PER_BYTE,
    BITS_PER_DQS = 2,              ///< Differential clock pair
    MAX_RANKS_DIMM1 = 2,           ///< DIMM1 (inner DIMM) can't be a 4R DIMM
    MAX_PRIMARY_RANKS_PER_PORT = 4,
    MAX_RANK_PAIRS = 4,
    MAX_MRANK_PER_PORT = MAX_DIMM_PER_PORT * MAX_RANK_PER_DIMM,
    RANK_MID_POINT = 4,            ///< Which rank number indicates the switch to the other DIMM
    MAX_NUM_IMP = 4,               ///< number of impedances valid per slew type
    MAX_NUM_CAL_SLEW_RATES = 4,    ///< 3V/ns, 4V/ns, 5V/ns, 6V/n
    MAX_DQ_BITS = 72,
    MAX_DQ_NIBBLES = MAX_DQ_BITS / BITS_PER_NIBBLE, ///< For ISDIMMs are 18 DQ nibbles for DQ 72 bits
    MAX_DRAMS_X8 = MAX_DQ_BITS / BITS_PER_BYTE, ///< For x8's there are 9 DRAM for 72 bits
    MAX_DRAMS_X4 = MAX_DQ_BITS / BITS_PER_NIBBLE, ///< For x4's there are 18 DRAM for 72 bits
    MAX_LRDIMM_BUFFERS = MAX_DRAMS_X8,

    NUM_MRW_FREQS = 4,             ///< Used for ATTR_MSS_MRW_SUPPORTED_FREQ
    NUM_LRDIMM_TRAINING_PATTERNS = 5,             ///< Used for ATTR_MSS_LRDIMM_TRAINING_PATTERN

    ROW_REPAIR_BYTE_COUNT = 4,     ///< Elements in a ROW_REPAIR_DATA attribute array.

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
};

enum times
{
    // Not *exactly* a time but go with i
    FULL_DLL_CAL_DELAY      = 37382,    ///< Full DLL calibration (in ddphy_nck cycles)
};

///
/// @brief function ID codes for FFDC functions
/// @note If we get a fail in HB, we can trace back to the function that failed
///
enum ffdc_function_codes
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
    SET_PAIR_VALID = 10,

    // Used in eff_dimm.C
    SET_DRAM_DENSITY_INSTANCE = 19,
    NIBBLE_MAP_FUNC = 20,
    PACKAGE_RANK_MAP_FUNC = 21,
    SET_DRAM_WIDTH_INSTANCE = 22,
    PRIM_DIE_COUNT = 23,
    DIMM_SIZE = 24,
    DRAM_BANK_BITS = 25,
    DRAM_ROW_BITS = 26,
    SOFT_POST_PACKAGE_REPAIR = 27,
    EFF_BC07 = 28,

    // Used in rank.H
    MAP_RP_PRIMARY_TO_INIT_CAL = 60,

    // PDA function codes
    PDA_WR_VREF_LATCH_VECTOR = 81,
    PDA_ADD_COMMAND = 82,

    // PBA function codes
    PBA_EXECUTE_CONTAINER = 80,
    PBA_EXECUTE_VECTOR = 81,
    SET_PBA_MODE = 83,

    // WR VREF workaround functions
    WR_VREF_TRAINING_WORKAROUND = 90,
    CONFIGURE_WR_VREF_TO_NOMINAL = 91,
    RESET_WR_DQ_DELAY = 92,
    READ_RD_VREF_VALUES_FOR_DRAM = 93,
    GET_DRAM_DISABLE_REG_AND_POS = 94,
    GET_STARTING_WR_DQ_DELAY_VALUE = 95,

    SUPPORTED_FREQS = 99,

    // WR VREF functions
    DRAM_TO_RP_REG = 101,

    // eff_dimm.C
    RAW_CARD_FACTORY = 115,
    PRIMARY_STACK_TYPE = 116,

    // CW engine information
    CW_DATA_ENGINE = 117,
    CW_INFO_ENGINE = 118,

    // LR helper functions
    FINE_RECORDER_ADD_RESULTS = 119,
    FINE_RECORDER_FIND_EYE = 120,
    FIX_SHADOW_REGISTER = 121,

    // LR training function
    DWL_CALL_OUT = 130,
    MREP_CALL_OUT = 131,
};

// Static consts describing the bits used in the cal_step_enable attribute
// These are bit positions. 0 is the left most bit.
enum cal_steps : uint64_t
{
    // TK:LRDIMM Update calibration steps to add or remove LRDIMM steps
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
    TRAINING_ADV_RD   = 20, ///< Flag for draminit training advance in the attribute/ CUSTOM_READ_CTR in code
    TRAINING_ADV_WR   = 21, ///< Flag for draminit training advance in the attribute/ CUSTOM_WRITE_CTR in code
    BUFFER_RD_VREF    = 22, ///< (LRDIMM) Buffer read vref training
    DRAM_WR_VREF      = 23, ///< (LRDIMM) DRAM write vref training
    BUFFER_WR_VREF    = 24, ///< (LRDIMM) Buffer write vref training

    // TK:LRDIMM Update total calibration steps to have "LRDIMM" specific ones here
    // Not *exactly* a cal step but go w/it
    RUN_ALL_CAL_STEPS          = 0xFFFFFF80,
    RUN_CAL_SKIP_WR_RD_2D_VREF = 0xFFFD7F80,

    INITIAL_PAT_WR_TO_RD_CTR_LEN = inclusive_range(INITIAL_PAT_WR, READ_CTR),
    WR_VREF_TO_COARSE_RD_LEN = inclusive_range(WRITE_CTR_2D_VREF, COARSE_RD),
    READ_VREF_TO_READ_CTR_LEN = inclusive_range(READ_CTR_2D_VREF, READ_CTR),
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


// Possible values for power domains in MBARPC0Q
enum min_max_domains : uint64_t
{
    MAXALL_MINALL = 0b000,
    MAXALL_MIN1 = 0b001,
    MAXALL_MIN0 = 0b010,
    MAX1_MIN1 = 0b011,
    MAX1_MIN0 = 0b100,
};

} // namespace mss
#endif
