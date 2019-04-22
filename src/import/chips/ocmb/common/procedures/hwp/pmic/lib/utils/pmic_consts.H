/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_consts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file pmic_consts.H
/// @brief Constants for PMIC procedures / i2C
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: CI

#ifndef MSS_PMIC_CONSTS_H
#define MSS_PMIC_CONSTS_H

namespace mss
{
namespace pmic
{

enum attr_eff_engine_fields
{
    // Template recursive base case
    ATTR_EFF_BASE_CASE = 0,

    PMIC0_SWA_VOLTAGE_SETTING           = 1,
    PMIC0_SWA_VOLTAGE_RANGE_SELECT      = 2,
    PMIC0_SWA_VOLTAGE_OFFSET            = 3,
    PMIC0_SWA_VOLTAGE_OFFSET_DIRECTION  = 4,
    PMIC0_SWA_SEQUENCE_DELAY            = 5,
    PMIC0_SWA_SEQUENCE_ORDER            = 6,

    PMIC0_SWB_VOLTAGE_SETTING           = 7,
    PMIC0_SWB_VOLTAGE_RANGE_SELECT      = 8,
    PMIC0_SWB_VOLTAGE_OFFSET            = 9,
    PMIC0_SWB_VOLTAGE_OFFSET_DIRECTION  = 10,
    PMIC0_SWB_SEQUENCE_DELAY            = 11,
    PMIC0_SWB_SEQUENCE_ORDER            = 12,

    PMIC0_SWC_VOLTAGE_SETTING           = 13,
    PMIC0_SWC_VOLTAGE_RANGE_SELECT      = 14,
    PMIC0_SWC_VOLTAGE_OFFSET            = 15,
    PMIC0_SWC_VOLTAGE_OFFSET_DIRECTION  = 16,
    PMIC0_SWC_SEQUENCE_DELAY            = 17,
    PMIC0_SWC_SEQUENCE_ORDER            = 18,

    PMIC0_SWD_VOLTAGE_SETTING           = 19,
    PMIC0_SWD_VOLTAGE_RANGE_SELECT      = 20,
    PMIC0_SWD_VOLTAGE_OFFSET            = 21,
    PMIC0_SWD_VOLTAGE_OFFSET_DIRECTION  = 22,
    PMIC0_SWD_SEQUENCE_DELAY            = 23,
    PMIC0_SWD_SEQUENCE_ORDER            = 24,

    PMIC1_SWA_VOLTAGE_SETTING           = 25,
    PMIC1_SWA_VOLTAGE_RANGE_SELECT      = 26,
    PMIC1_SWA_VOLTAGE_OFFSET            = 27,
    PMIC1_SWA_VOLTAGE_OFFSET_DIRECTION  = 28,
    PMIC1_SWA_SEQUENCE_DELAY            = 29,
    PMIC1_SWA_SEQUENCE_ORDER            = 30,

    PMIC1_SWB_VOLTAGE_SETTING           = 31,
    PMIC1_SWB_VOLTAGE_RANGE_SELECT      = 32,
    PMIC1_SWB_VOLTAGE_OFFSET            = 33,
    PMIC1_SWB_VOLTAGE_OFFSET_DIRECTION  = 34,
    PMIC1_SWB_SEQUENCE_DELAY            = 35,
    PMIC1_SWB_SEQUENCE_ORDER            = 36,

    PMIC1_SWC_VOLTAGE_SETTING           = 37,
    PMIC1_SWC_VOLTAGE_RANGE_SELECT      = 38,
    PMIC1_SWC_VOLTAGE_OFFSET            = 39,
    PMIC1_SWC_VOLTAGE_OFFSET_DIRECTION  = 40,
    PMIC1_SWC_SEQUENCE_DELAY            = 41,
    PMIC1_SWC_SEQUENCE_ORDER            = 42,

    PMIC1_SWD_VOLTAGE_SETTING           = 43,
    PMIC1_SWD_VOLTAGE_RANGE_SELECT      = 44,
    PMIC1_SWD_VOLTAGE_OFFSET            = 45,
    PMIC1_SWD_VOLTAGE_OFFSET_DIRECTION  = 46,
    PMIC1_SWD_SEQUENCE_DELAY            = 47,
    PMIC1_SWD_SEQUENCE_ORDER            = 48,

    PMIC0_PHASE_COMB                    = 49,
    PMIC1_PHASE_COMB                    = 50,

    PMIC0_MFG_ID                        = 51,
    PMIC1_MFG_ID                        = 52,

    DRAM_MODULE_HEIGHT                  = 53,

    // Dispatcher set to last enum value
    ATTR_EFF_DISPATCHER = DRAM_MODULE_HEIGHT,
};

///
/// @brief explorer ffdc codes
///
enum ffdc_codes
{
    SET_PMIC0_SWA_VOLTAGE_SETTING           = 0x1052,
    SET_PMIC0_SWA_VOLTAGE_RANGE_SELECT      = 0x1053,
    SET_PMIC0_SWA_VOLTAGE_OFFSET            = 0x1054,
    SET_PMIC0_SWA_VOLTAGE_OFFSET_DIRECTION  = 0x1055,
    SET_PMIC0_SWA_SEQUENCE_DELAY            = 0x1056,
    SET_PMIC0_SWA_SEQUENCE_ORDER            = 0X1057,

    SET_PMIC0_SWB_VOLTAGE_SETTING           = 0x1058,
    SET_PMIC0_SWB_VOLTAGE_RANGE_SELECT      = 0x1059,
    SET_PMIC0_SWB_VOLTAGE_OFFSET            = 0x105A,
    SET_PMIC0_SWB_VOLTAGE_OFFSET_DIRECTION  = 0x105B,
    SET_PMIC0_SWB_SEQUENCE_DELAY            = 0x105C,
    SET_PMIC0_SWB_SEQUENCE_ORDER            = 0X105D,

    SET_PMIC0_SWC_VOLTAGE_SETTING           = 0x105E,
    SET_PMIC0_SWC_VOLTAGE_RANGE_SELECT      = 0x105F,
    SET_PMIC0_SWC_VOLTAGE_OFFSET            = 0x1060,
    SET_PMIC0_SWC_VOLTAGE_OFFSET_DIRECTION  = 0x1061,
    SET_PMIC0_SWC_SEQUENCE_DELAY            = 0x1062,
    SET_PMIC0_SWC_SEQUENCE_ORDER            = 0X1063,

    SET_PMIC0_SWD_VOLTAGE_SETTING           = 0x1064,
    SET_PMIC0_SWD_VOLTAGE_RANGE_SELECT      = 0x1065,
    SET_PMIC0_SWD_VOLTAGE_OFFSET            = 0x1066,
    SET_PMIC0_SWD_VOLTAGE_OFFSET_DIRECTION  = 0x1067,
    SET_PMIC0_SWD_SEQUENCE_DELAY            = 0x1068,
    SET_PMIC0_SWD_SEQUENCE_ORDER            = 0X1069,

    SET_PMIC1_SWA_VOLTAGE_SETTING           = 0x106A,
    SET_PMIC1_SWA_VOLTAGE_RANGE_SELECT      = 0x106B,
    SET_PMIC1_SWA_VOLTAGE_OFFSET            = 0x106C,
    SET_PMIC1_SWA_VOLTAGE_OFFSET_DIRECTION  = 0x106D,
    SET_PMIC1_SWA_SEQUENCE_DELAY            = 0x106E,
    SET_PMIC1_SWA_SEQUENCE_ORDER            = 0X106F,

    SET_PMIC1_SWB_VOLTAGE_SETTING           = 0x1070,
    SET_PMIC1_SWB_VOLTAGE_RANGE_SELECT      = 0x1071,
    SET_PMIC1_SWB_VOLTAGE_OFFSET            = 0x1072,
    SET_PMIC1_SWB_VOLTAGE_OFFSET_DIRECTION  = 0x1073,
    SET_PMIC1_SWB_SEQUENCE_DELAY            = 0x1074,
    SET_PMIC1_SWB_SEQUENCE_ORDER            = 0X1075,

    SET_PMIC1_SWC_VOLTAGE_SETTING           = 0x1076,
    SET_PMIC1_SWC_VOLTAGE_RANGE_SELECT      = 0x1077,
    SET_PMIC1_SWC_VOLTAGE_OFFSET            = 0x1078,
    SET_PMIC1_SWC_VOLTAGE_OFFSET_DIRECTION  = 0x1079,
    SET_PMIC1_SWC_SEQUENCE_DELAY            = 0x107A,
    SET_PMIC1_SWC_SEQUENCE_ORDER            = 0X107B,

    SET_PMIC1_SWD_VOLTAGE_SETTING           = 0x107C,
    SET_PMIC1_SWD_VOLTAGE_RANGE_SELECT      = 0x107D,
    SET_PMIC1_SWD_VOLTAGE_OFFSET            = 0x107E,
    SET_PMIC1_SWD_VOLTAGE_OFFSET_DIRECTION  = 0x107F,
    SET_PMIC1_SWD_SEQUENCE_DELAY            = 0x1080,
    SET_PMIC1_SWD_SEQUENCE_ORDER            = 0X1081,

    SET_PMIC0_PHASE_COMB                    = 0x1082,
    SET_PMIC1_PHASE_COMB                    = 0x1083,

    SET_PMIC0_MFG_ID                        = 0x1084,
    SET_PMIC1_MFG_ID                        = 0x1085,

    SET_DRAM_MODULE_HEIGHT                  = 0x1086,
};


} // pmic
} // mss

#endif
