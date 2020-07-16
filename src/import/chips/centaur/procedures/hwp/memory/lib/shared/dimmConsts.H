/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/lib/shared/dimmConsts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file dimmConsts.H
/// @brief DIMM Constants
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
//
#ifndef DIMMCONSTS_H_
#define DIMMCONSTS_H_

//TODO:RTC171671 : add namespace to consts
enum centaur_consts : size_t
{
    MAX_PORTS_PER_MBA = 2,         ///< Maximum number of ports on an MBA
    MAX_DIMM_PER_PORT = 2,         ///< Maximum number of DIMMs attached to an MBA PORT
    MAX_DIMM_PER_MBA = MAX_DIMM_PER_PORT * MAX_PORTS_PER_MBA, ///< Maximum number of DIMMs attached to an MBA
    MAX_MBA_PER_CEN = 2,           ///< Maximum number of MBAs on a membuf
    MAX_PORTS_PER_CEN = 4,         ///< Maximum number of ports on a centaur
    MAX_RANKS_PER_DIMM = 4,        ///< Maximum number of ranks on a DIMM
    NUM_RANK_GROUPS = 4,           ///< Maximum number of rank groups
    MAX_RANKS_PER_PORT = 8,        ///< Maximum number of ranks on a port
    MAX_RANKS_PER_RANK_GROUP = 4,  ///< Maximum number of ranks in a rank group
    DIMM_DQ_RANK_BITMAP_SIZE = 10, ///< Size in bytes of the Bad DQ bitmap for a rank.

    BITS_PER_BYTE = 8,
    BITS_PER_NIBBLE = 4,
    MAX_NIBBLES_PER_BYTE = 2,

    // This is the number of bits in DIMM_DQ_RANK_BITMAP_SIZE.
    DIMM_DQ_NUM_DQS = DIMM_DQ_RANK_BITMAP_SIZE * BITS_PER_BYTE, ///< Number of DQs (data query pins).

    // This must be big enough to contain the bitmap for each rank
    // (MAX_RANKS_PER_DIMM * DIMM_DQ_RANK_BITMAP_SIZE), plus the header
    DIMM_DQ_SPD_DATA_SIZE = 80,     ///< Size in bytes of Bad DQ Data in DIMM SPD

    // ISDIMM to C4 DQ and DQS constant
    DIMM_TO_C4_PORTS = 4,           ///< Number of Ports needed in the array
    DIMM_TO_C4_DQ_ENTRIES = 80,     ///< Number of entries in the DQ attribute
    DIMM_TO_C4_DQS_ENTRIES = 20,    ///< Number of entries in the DQS attribute

    ISDIMM_MAX_DQ_72 = 72,          ///< Number of DQ pins on ISDIMM
    ISDIMM_MAX_DQS_18 = 18,         ///< Number of DQS pins on ISDIMM
    CDIMM_MAX_DQ_80 = 80,

    MAX_ADDR = 19,
    MAX_CMD = 3,
    MAX_CNT = 20,
    MAX_CLK = 8,
    MAX_DATA_DISABLE = 5,

    LANES_PER_BLOCK = 16,
    MAX_BLOCKS_PER_RANK = 5,
    MAX_BYTES_PER_BLOCK = LANES_PER_BLOCK / BITS_PER_BYTE,
    MAX_NIBBLES_PER_BLOCK = LANES_PER_BLOCK / BITS_PER_NIBBLE,
    MAX_BYTES_PER_RANK = MAX_BYTES_PER_BLOCK * MAX_BLOCKS_PER_RANK,
    LANES_PER_PORT = LANES_PER_BLOCK * MAX_BLOCKS_PER_RANK,

    DP18_INSTANCES = 5,
    BITS_PER_REG = 16,
    BITS_PER_PORT = (LANES_PER_BLOCK * DP18_INSTANCES),

    DATA_BYTES_PER_PORT = 8,
    SP_ECC_BYTES_PER_PORT = 2,
    SP_ECC_BYTES_PER_PORT_ISDIMM = 1,

    MAX_DRAMS_PER_RANK_X8 = DATA_BYTES_PER_PORT + SP_ECC_BYTES_PER_PORT,
    // Subtract one because CDIMM only has one spare DRAM
    MAX_DRAMS_PER_RANK_X4 = MAX_DRAMS_PER_RANK_X8 * MAX_NIBBLES_PER_BYTE - 1,
    MAX_DRAMS_PER_RANK_X8_ISDIMM = DATA_BYTES_PER_PORT + SP_ECC_BYTES_PER_PORT_ISDIMM,
    MAX_DRAMS_PER_RANK_X4_ISDIMM = MAX_DRAMS_PER_RANK_X8_ISDIMM * MAX_NIBBLES_PER_BYTE,

    /// Dram data bus utilization is bus utilization / 4
    DRAM_BUS_UTILS = 4,
};

enum ohm : size_t
{
    OHM15 = 15,                ///< 15 OHMs
    OHM20 = 20,                ///< 20 OHMs
    OHM24 = 24,                ///< 24 OHMs
    OHM30 = 30,                ///< 30 OHMs
    OHM34 = 34,                ///< 34 OHMs
    OHM40 = 40,                ///< 40 OHMs
};

enum slew : size_t
{
    SLEW_3V_NS = 3,            ///< 3V/ns slew
    SLEW_4V_NS = 4,            ///< 4V/ns slew
    SLEW_5V_NS = 5,            ///< 5V/ns slew
    SLEW_6V_NS = 6,            ///< 6V/ns slew
    SLEW_MAXV_NS = 7,          ///< 7V/ns slew

    SLEW_TYPE_DATA = 0,        ///< Data line slew enum
    SLEW_TYPE_ADR_ADDR = 1,    ///< Address line slew enum
    SLEW_TYPE_ADR_CNTL = 2,    ///< Control line slew enum
    SLEW_TYPE_ADR_CLK = 3,     ///< Clock line slew enum
    SLEW_TYPE_ADR_SPCKE = 4,   ///< Spare CKE line slew enum
    MAX_NUM_SLEW_TYPES = 5    ///< Max slew types
};

enum mrs : size_t
{
    MRS0_BA = 0,   ///< MRS0 Bank Address
    MRS1_BA = 1,   ///< MRS1 Bank Address
    MRS2_BA = 2,   ///< MRS2 Bank Address
    MRS3_BA = 3,   ///< MRS3 Bank Address
    MRS4_BA = 4,   ///< MRS4 Bank Address
    MRS5_BA = 5,   ///< MRS5 Bank Address
    MRS6_BA = 6,   ///< MRS6 Bank Address
    INVALID_RANK = 255, ///< INVALID
};

enum dimm_types : size_t
{
    CDIMM = 0,    ///< Centaur DIMM
    RDIMM = 1,    ///< Registered Dimm
    UDIMM = 2,    ///< Unregistered Dimm
    LRDIMM = 3,   ///< Load Reduced Dimm
};

enum mss_ccs_status_query_result
{
    MSS_STAT_QUERY_PASS = 1,          ///<  CCS Pass Enum
    MSS_STAT_QUERY_IN_PROGRESS = 2,   ///<  CCS In Progress Enum
    MSS_STAT_QUERY_FAIL = 3           ///<  CCS Fail Enum
};

enum mss_ccs_data_pattern
{
    MSS_CCS_DATA_PATTERN_00 = 1,   ///< 00 Pattern Enum
    MSS_CCS_DATA_PATTERN_0F = 2,   ///< 0F Pattern Enum
    MSS_CCS_DATA_PATTERN_F0 = 3,   ///< F0 Pattern Enum
    MSS_CCS_DATA_PATTERN_FF = 4    ///< FF Pattern Enum
};

enum ffdc_function_codes
{
    // These are used in mss_row_repair.C
    CHECK_FOR_UNCALIBRATED_DRAM = 0,
    CLEAR_BAD_DQ_FOR_ROW_REPAIR = 1
};

constexpr bool MSS_CCS_START = 0;
constexpr bool MSS_CCS_STOP = 1;
constexpr uint8_t l_ISDIMM_dqmax = 71;
constexpr uint8_t l_CDIMM_dqmax = 79;
constexpr uint8_t CCS_MAX_INSTRUCTION_NUM = 32;

enum sim_cycles : size_t
{
    DELAY_100NS = 100,                ///< 100 ns delay for HW mode (2000 sim cycles if simclk = 20ghz)
    DELAY_1US = 1000,                 ///< 1 usec delay for HW mode (20000 sim cycles if simclk = 20ghz)
    DELAY_100US = 100000,             ///< 100 usec delay for HW mode (2000000 sim cycles if simclk = 20ghz)
    DELAY_500US = 500000,             ///< 500 usec delay for HW mode
    DELAY_500SIMCYCLES = 500,         ///< 500 sim cycle delay
    DELAY_1MS   = 1000000,            ///< 1ms delay
    DELAY_2000SIMCYCLES = 2000,       ///< 2000 sim cycle delay for sim mode (100 ns if simclk = 20Ghz)
    DELAY_20000SIMCYCLES = 20000,     ///< 20000 sim cycle delay for sim mode (1 usec if simclk = 20Ghz)
    DELAY_200000SIMCYCLES = 200000,   ///< 200000 sim cycle delay for sim mode
    DELAY_2000000SIMCYCLES = 2000000, ///< 2000000 sim cycle delay for sim mode  (100 usec if simclk = 20Ghz)
    DELAY_10000000SIMCYCLES = 10000000, ///< 10000000 sim cycle delay for sim mode
};
#endif
