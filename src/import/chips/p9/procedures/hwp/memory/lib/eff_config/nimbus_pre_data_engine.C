/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/nimbus_pre_data_engine.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file nimbus_pre_data_engine.C
/// @brief pre_data_engine implimentation for mss::proc_type::NIMBUS
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI

#include <lib/eff_config/pre_data_init.H>

namespace mss
{

// =========================================================
// DDR4 SPD Document Release 4
// Byte 2 (0x002): Key Byte / DRAM Device Type
// =========================================================
template<>
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<mss::proc_type::NIMBUS>::DRAM_GEN_MAP =
{
    //{key value, dram gen}
    {0x0C, fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4}
    // Other key bytes reserved or not supported
};

// =========================================================
// DDR4 SPD Document Release 4
// Byte 3 (0x003): Key Byte / Module Type - Hybrid
// =========================================================
template<>
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<mss::proc_type::NIMBUS>::HYBRID_MAP =
{
    //{key byte, dimm type}
    {0, fapi2::ENUM_ATTR_EFF_HYBRID_NOT_HYBRID},
    {1, fapi2::ENUM_ATTR_EFF_HYBRID_IS_HYBRID},
    // All others reserved or not supported
};


// =========================================================
// DDR4 SPD Document Release 4
// Byte 3 (0x003): Key Byte / Module Type - Hybrid
// =========================================================
template<>
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<mss::proc_type::NIMBUS>::HYBRID_MEMORY_TYPE_MAP =
{

    //{key byte, dimm type}
    {0, fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NONE},
    {1, fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NVDIMM},
    // All others reserved or not supported
};

// =========================================================
// DDR4 SPD Document Release 4
// Byte 3 (0x003): Key Byte / Module Type
// =========================================================
template<>
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<mss::proc_type::NIMBUS>::BASE_MODULE_TYPE_MAP =
{
    //{key byte, dimm type}
    {1, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM},
    {2, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM},
    {4, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM},
    {5, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM}, /* Mini RDIMM */
    {6, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM}, /* Mini UDIMM */
    /* 0x7: Reserved */
    {8, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM}, /* SO RDIMM */
    {9, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM}, /* SO UDIMM */
    // All others reserved or not supported
};

// =========================================================
// DDR4 SPD Document Release 4
// Byte 12 (0x00C): Module Organization
// =========================================================
template<>
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<mss::proc_type::NIMBUS>::NUM_PACKAGE_RANKS_MAP =
{
    // {key byte, num of package ranks per DIMM (package ranks)}
    {0, fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R},
    {1, fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R},
    {3, fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_4R},
};

}//mss
