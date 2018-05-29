/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/nimbus_pre_data_engine.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @brief pre_data_engine implimentation for Nimbus
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI

#include <generic/memory/lib/utils/index.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/eff_config/attr_setters.H>
#include <generic/memory/lib/data_engine/pre_data_init.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

// =========================================================
// DDR4 SPD Document Release 4
// Byte 2 (0x002): Key Byte / DRAM Device Type
// =========================================================
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<NIMBUS>::DRAM_GEN_MAP =
{
    //{key value, dram gen}
    {0x0C, fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4}
    // Other key bytes reserved or not supported
};

// =========================================================
// DDR4 SPD Document Release 4
// Byte 3 (0x003): Key Byte / Module Type - Hybrid
// =========================================================
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<NIMBUS>::HYBRID_MAP =
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
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<NIMBUS>::HYBRID_MEMORY_TYPE_MAP =
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
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<NIMBUS>::BASE_MODULE_TYPE_MAP =
{
    //{key byte, dimm type}
    {1, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM},
    {2, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM},
    {4, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM},
    // All others reserved or not supported
};

// =========================================================
// DDR4 SPD Document Release 4
// Byte 12 (0x00C): Module Organization
// =========================================================
const std::vector< std::pair<uint8_t, uint8_t> > pre_data_engine<NIMBUS>::NUM_PACKAGE_RANKS_MAP =
{
    // {key byte, num of package ranks per DIMM (package ranks)}
    {0, fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R},
    {1, fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R},
    {3, fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_4R},
};

///
/// @brief ctor
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_data SPD data
/// @param[out] o_rc ReturnCode for failure to init object
///
pre_data_engine<NIMBUS>::pre_data_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const spd::facade& i_spd_data,
        fapi2::ReturnCode& o_rc):
    iv_dimm(i_target),
    iv_spd_data(i_spd_data)
{
    // Sets up commonly used member variables
    uint8_t l_master_ranks = 0;
    FAPI_TRY(iv_spd_data.num_package_ranks_per_dimm(l_master_ranks));
    FAPI_TRY(lookup_table_check(i_target, NUM_PACKAGE_RANKS_MAP, PRE_DATA_ENGINE_CTOR, l_master_ranks, iv_master_ranks));

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    return;
}

///
/// @brief Set ATTR_EFF_DIMM_TYPE
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pre_data_engine<NIMBUS>::set_dimm_type()
{
    uint8_t l_base_module_type = 0;
    uint8_t l_dimm_type = 0;

    FAPI_TRY(iv_spd_data.base_module(l_base_module_type));
    FAPI_TRY(lookup_table_check(iv_dimm, BASE_MODULE_TYPE_MAP, SET_ATTR_DIMM_TYPE, l_base_module_type, l_dimm_type));
    FAPI_TRY( (set_field<NIMBUS, DIMM_TYPE>(iv_dimm, l_dimm_type)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_DRAM_GEN
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pre_data_engine<NIMBUS>::set_dram_gen()
{
    uint8_t l_device_type = 0;
    uint8_t l_dram_gen = 0;

    FAPI_TRY(iv_spd_data.device_type(l_device_type));
    FAPI_TRY(lookup_table_check(iv_dimm, DRAM_GEN_MAP, SET_ATTR_DRAM_GEN, l_device_type, l_dram_gen));

    FAPI_TRY( (set_field<NIMBUS, DRAM_GEN>(iv_dimm, l_dram_gen)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_HYBRID
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pre_data_engine<NIMBUS>::set_hybrid()
{
    uint8_t l_spd_hybrid_type = 0;
    uint8_t l_hybrid = 0;

    FAPI_TRY(iv_spd_data.hybrid(l_spd_hybrid_type));
    FAPI_TRY(lookup_table_check(iv_dimm, HYBRID_MAP, SET_ATTR_HYBRID, l_spd_hybrid_type, l_hybrid));

    FAPI_TRY( (set_field<NIMBUS, HYBRID>(iv_dimm, l_hybrid)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_HYBRID_MEMORY_TYPE
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pre_data_engine<NIMBUS>::set_hybrid_media()
{
    uint8_t l_hybrid_media = 0;
    uint8_t l_spd_hybrid_media = 0;

    FAPI_TRY(iv_spd_data.hybrid_media(l_spd_hybrid_media));
    FAPI_TRY(lookup_table_check(iv_dimm, HYBRID_MAP, SET_ATTR_HYBRID, l_spd_hybrid_media, l_hybrid_media));

    FAPI_TRY( (set_field<NIMBUS, HYBRID_MEDIA>(iv_dimm, l_hybrid_media)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pre_data_engine<NIMBUS>::set_master_ranks()
{
    FAPI_TRY( (set_field<NIMBUS, MRANKS>(iv_dimm, iv_master_ranks)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets ATTR_EFF_DIMM_RANKS_CONFIGED
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode pre_data_engine<NIMBUS>::set_dimm_ranks_configured()
{
    // Set configed ranks. Set the bit representing the master rank configured (0 being left most.) So,
    // a 4R DIMM would be 0b11110000 (0xF0). This is used by PRD.
    fapi2::buffer<uint8_t> l_ranks_configed;

    FAPI_TRY( l_ranks_configed.setBit(0, iv_master_ranks),
              "%s. Failed to setBit", spd::c_str(iv_dimm) );

    FAPI_TRY( (set_field<NIMBUS, DIMM_RANKS_CNFG>(iv_dimm, uint8_t(l_ranks_configed))) );

fapi_try_exit:
    return fapi2::current_err;
}

}//mss
