/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/shared/mss_generic_consts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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

#include <cstdint>

namespace mss
{

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
    PRE_DATA_ENGINE_CTOR = 0x1005,
    EXTRACT_SPD_FLD = 0x1006,
    SPD_READER = 0x1007,
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
};

///
/// @brief Supported proc types
///
enum proc_type
{
    NIMBUS,
    AXONE,
};

///
/// @brief JEDEC supported DDR4 speeds
///
enum ddr4_dimm_speeds
{
    DIMM_SPEED_1600 = 1600,
    DIMM_SPEED_1866 = 1866,
    DIMM_SPEED_2133 = 2133,
    DIMM_SPEED_2400 = 2400,
    DIMM_SPEED_2666 = 2666,
    DIMM_SPEED_2933 = 2933,
    DIMM_SPEED_3200 = 3200,
};

namespace spd
{

///
/// @brief SPD revisions - not tied any particular module
///
enum rev : uint8_t
{
    V1_0 = 0x10, ///< represents Rev 1.0
    V1_1 = 0x11, ///< represents Rev 1.1
    V1_2 = 0x12, ///< represents Rev 1.2

    // These module revisions can vary independently
    // so we track the largest decoded revision here.
    GEN_SEC_MAX = V1_1,
    RDIMM_MAX = V1_1,
    LRDIMM_MAX = V1_2,
};

///
/// @brief SPD module parameters
/// @note helps distinguish SPD decoder sections
///
enum parameters
{
    UNINITIALIZED,
    BASE_CNFG,
    RDIMM_MODULE,
    LRDIMM_MODULE,
    NVDIMM_MODULE,
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
/// @brief DIMM type selector
/// @note values set to SPD settings
///
enum dimm_type
{
    RDIMM = 0b0001,
    LRDIMM = 0b0100,
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
}// mss

#endif
