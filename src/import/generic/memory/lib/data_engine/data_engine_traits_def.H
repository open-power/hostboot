/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine_traits_def.H $ */
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
/// @file data_engine_traits_def.H
/// @brief Class to set preliminary eff_config attributes
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _MSS_DATA_ENGINE_TRAITS_DEF_H_
#define _MSS_DATA_ENGINE_TRAITS_DEF_H_

#include <cstring>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief enum list of preliminary data fields needed before eff_config
///
enum pre_data_init_fields
{
    // Template recursive base case
    ATTR_PRE_DATA_ENGINE_CASE = 0,

    // Attrs to set
    DIMM_TYPE = 1,
    DRAM_GEN = 2,
    HYBRID = 3,
    HYBRID_MEDIA = 4,
    MRANKS = 5,
    HOST_TO_DDR_SPEED_RATIO = 6,
    DIMM_RANKS_CNFG = 7,

    // Dispatcher set to last enum value
    ATTR_PRE_DATA_ENG_DISPATCHER = DIMM_RANKS_CNFG,
};

///
/// @brief enum list of preliminary data fields
/// @note Separating these fields into their own special case
/// since this is needed for reuse in incompatible code bases
/// (e.g. Nimbus vs Axone)
/// @warning these depend on pre_data_init_fields fields being set
///
enum generic_metadata_fields
{
    // Template recursive base case
    ATTR_METADATA_BASE_CASE = 0,

    // Attrs to set
    DIMM_TYPE_METADATA = 1,
    DRAM_GEN_METADATA = 2,
    DIMM_POS_METADATA = 3,

    // Dispatcher set to last enum value
    ATTR_METADATA_DISPATCHER = DIMM_POS_METADATA,
};

///
/// @brief enum list of SPD based attr fields to set
///
enum attr_eff_engine_fields
{
    // Template recursive base case
    ATTR_EFF_BASE_CASE = 0,

    // Attrs to set
    DRAM_WIDTH = 1,
    PRIM_BUS_WIDTH = 2,
    DRAM_DENSITY = 3,
    PRIMARY_DIE_COUNT = 4,
    PRIM_STACK_TYPE = 5,

    // Dispatcher set to last enum value
    ATTR_EFF_DISPATCHER = PRIM_STACK_TYPE,
};

///
/// @brief enum list of SI attr fields to set from EFD
///
enum attr_si_engine_fields
{
    // Template recursive base case
    ATTR_SI_BASE_CASE = 0,

    // Attrs to set
    SI_MC_RCV_IMP_DQ_DQS = 1,
    SI_MC_DRV_IMP_DQ_DQS_PULL_UP = 2,
    SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN = 3,
    SI_MC_DRV_SLEW_RATE_DQ_DQS = 4,
    SI_MC_DRV_IMP_CMD_ADDR = 5,
    SI_MC_DRV_SLEW_RATE_CMD_ADDR = 6,
    SI_MC_DRV_IMP_CLK = 7,
    SI_MC_DRV_SLEW_RATE_CLK = 8,
    SI_MC_RCV_IMP_ALERT_N = 9,
    SI_DRAM_RTT_NOM = 10,
    SI_DRAM_RTT_WR = 11,
    SI_DRAM_RTT_PARK = 12,
    SI_DRAM_PREAMBLE = 13,
    SI_MC_DRV_EQ_DQ_DQS = 14,
    SI_DRAM_DRV_IMP_DQ_DQS = 15,
    SI_VREF_DQ_TRAIN_RANGE = 16,
    SI_VREF_DQ_TRAIN_VALUE = 17,
    SI_ODT_WR = 18,
    SI_ODT_RD = 19,
    SI_GEARDOWN_MODE = 20,

    // Dispatcher set to last enum value
    ATTR_SI_DISPATCHER = SI_GEARDOWN_MODE,
};

///
/// @brief enum list of derived attributes
/// @note these are attributes that are derived from other
/// attributes or other APIs.
///
enum attr_engine_derived_fields
{
    // Attributes are set recursively from the bottom up.
    // When adding attrs that depend on other attrs
    // being set first, they should be placed earlier in the enum list
    // so that base level attrs are set first.

    // Template recursive base case
    ATTR_DERIVED_BASE_CASE = 0,

    // Attrs to set
    MEM_DIMM_SIZE = 1,
    LOGICAL_RANKS = 2,

    // Dispatcher set to last enum value
    ATTR_DERIVED_DISPATCHER = LOGICAL_RANKS,
};

///
/// @brief Forward declartion of traits for pre_data_engine
/// @class preDataInitTraits
/// @tparam T proc_type (e.g. Nimbus, Axone, etc.)
/// @tparam TT pre_data_init_fields (e.g. DIMM_TYPE, MRANK, etc.)
///
template< proc_type T, pre_data_init_fields TT >
class preDataInitTraits;

///
/// @brief Traits associated with DIMM positioning
/// @class dimmPosTraits
/// @tparam MC the MC type
///
template< mss::mc_type MC >
class dimmPosTraits;

///
/// @brief Forward declartion of traits for attrEngineTraits
/// @class attrEngineTraits
/// @tparam ET enum type
/// @tparam T enum value
///
template < typename ET, ET T>
struct attrEngineTraits;

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @tparam ET enum type
/// @tparam T enum value
///
template < typename ET, ET T >
struct setTimingTraits;

///
/// @brief Forward declartion of traits for attrEnumTraits
/// @class attrEnumTraits
/// @tparam ET enum type
///
template < typename ET >
struct attrEnumTraits;

}// mss

#endif
