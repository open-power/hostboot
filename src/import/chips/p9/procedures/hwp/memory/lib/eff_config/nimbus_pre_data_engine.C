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
/// @brief pre_data_engine implimentation for mss::proc_type::NIMBUS
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI

#include <generic/memory/lib/utils/index.H>
#include <lib/mss_attribute_accessors.H>
#include <generic/memory/lib/data_engine/pre_data_init.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, DIMM_TYPE specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, DIMM_TYPE>
{
    public:
        using attr_type = fapi2::ATTR_EFF_DIMM_TYPE_Type;
        static const fapi2::TargetType TARGET_TYPE = fapi2::ATTR_EFF_DIMM_TYPE_TargetType;

        ///
        /// @brief attribute getter
        /// @param[in] i_target the MCS target
        /// @param[out] o_setting array to populate
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          attr_type& o_setting)
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_TYPE, i_target, o_setting) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief attribute setter
        /// @param[in] i_target the MCS target
        /// @param[in] i_setting array to set
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          const attr_type& i_setting)
        {
            attr_type l_data = {};
            memcpy(l_data, i_setting, sizeof(l_data));
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, DRAM_GEN specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, DRAM_GEN>
{
    public:
        using attr_type = fapi2::ATTR_EFF_DRAM_GEN_Type;
        static const fapi2::TargetType TARGET_TYPE = fapi2::ATTR_EFF_DRAM_GEN_TargetType;

        ///
        /// @brief attribute getter
        /// @param[in] i_target the MCS target
        /// @param[out] o_setting array to populate
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          attr_type& o_setting)
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EFF_DRAM_GEN, i_target, o_setting) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief attribute setter
        /// @param[in] i_target the MCS target
        /// @param[in] i_setting array to set
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          const attr_type& i_setting)
        {
            attr_type l_data = {};
            memcpy(l_data, i_setting, sizeof(l_data));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, HYBRID specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, HYBRID>
{
    public:
        using attr_type = fapi2::ATTR_EFF_HYBRID_Type;
        static const fapi2::TargetType TARGET_TYPE = fapi2::ATTR_EFF_HYBRID_TargetType;

        ///
        /// @brief attribute getter
        /// @param[in] i_target the MCS target
        /// @param[out] o_setting array to populate
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          attr_type& o_setting)
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EFF_HYBRID, i_target, o_setting) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief attribute setter
        /// @param[in] i_target the MCS target
        /// @param[in] i_setting array to set
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          const attr_type& i_setting)
        {
            attr_type l_data = {};
            memcpy(l_data, i_setting, sizeof(l_data));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID, i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, HYBRID_MEDIA specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, HYBRID_MEDIA>
{
    public:
        using attr_type = fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE_Type;
        static const fapi2::TargetType TARGET_TYPE = fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE_TargetType;

        ///
        /// @brief attribute getter
        /// @param[in] i_target the MCS target
        /// @param[out] o_setting array to populate
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          attr_type& o_setting)
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE, i_target, o_setting) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief attribute setter
        /// @param[in] i_target the MCS target
        /// @param[in] i_setting array to set
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          const attr_type& i_setting)
        {
            attr_type l_data = {};
            memcpy(l_data, i_setting, sizeof(l_data));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE, i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, MRANKS specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, MRANKS>
{
    public:
        using attr_type = fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_Type;
        static const fapi2::TargetType TARGET_TYPE = fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_TargetType;

        ///
        /// @brief attribute getter
        /// @param[in] i_target the MCS target
        /// @param[out] o_setting array to populate
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          attr_type& o_setting)
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, o_setting) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief attribute setter
        /// @param[in] i_target the MCS target
        /// @param[in] i_setting array to set
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          const attr_type& i_setting)
        {
            attr_type l_data = {};
            memcpy(l_data, i_setting, sizeof(l_data));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, DIMM_RANKS_CNFG specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, DIMM_RANKS_CNFG>
{
    public:
        using attr_type = fapi2::ATTR_EFF_DIMM_RANKS_CONFIGED_Type;
        static const fapi2::TargetType TARGET_TYPE = fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_TargetType;

        ///
        /// @brief attribute getter
        /// @param[in] i_target the MCS target
        /// @param[out] o_setting array to populate
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          attr_type& o_setting)
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_RANKS_CONFIGED, i_target, o_setting) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief attribute setter
        /// @param[in] i_target the MCS target
        /// @param[in] i_setting array to set
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                          const attr_type& i_setting)
        {
            attr_type l_data = {};
            memcpy(l_data, i_setting, sizeof(l_data));

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_RANKS_CONFIGED, i_target, l_data) );

        fapi_try_exit:
            return fapi2::current_err;
        }
};

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

///
/// @brief Set ATTR_EFF_DIMM_TYPE
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode pre_data_engine<mss::proc_type::NIMBUS>::set_dimm_type()
{
    uint8_t l_base_module_type = 0;
    uint8_t l_dimm_type = 0;

    FAPI_TRY(iv_spd_data.base_module(l_base_module_type));
    FAPI_TRY(lookup_table_check(iv_dimm, BASE_MODULE_TYPE_MAP, SET_ATTR_DIMM_TYPE, l_base_module_type, l_dimm_type));
    FAPI_TRY( (set_field<mss::proc_type::NIMBUS, DIMM_TYPE>(iv_dimm, l_dimm_type)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_DRAM_GEN
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode pre_data_engine<mss::proc_type::NIMBUS>::set_dram_gen()
{
    uint8_t l_device_type = 0;
    uint8_t l_dram_gen = 0;

    FAPI_TRY(iv_spd_data.device_type(l_device_type));
    FAPI_TRY(lookup_table_check(iv_dimm, DRAM_GEN_MAP, SET_ATTR_DRAM_GEN, l_device_type, l_dram_gen));

    FAPI_TRY( (set_field<mss::proc_type::NIMBUS, DRAM_GEN>(iv_dimm, l_dram_gen)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_HYBRID
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode pre_data_engine<mss::proc_type::NIMBUS>::set_hybrid()
{
    uint8_t l_spd_hybrid_type = 0;
    uint8_t l_hybrid = 0;

    FAPI_TRY(iv_spd_data.hybrid(l_spd_hybrid_type));
    FAPI_TRY(lookup_table_check(iv_dimm, HYBRID_MAP, SET_ATTR_HYBRID, l_spd_hybrid_type, l_hybrid));

    FAPI_TRY( (set_field<mss::proc_type::NIMBUS, HYBRID>(iv_dimm, l_hybrid)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_HYBRID_MEMORY_TYPE
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode pre_data_engine<mss::proc_type::NIMBUS>::set_hybrid_media()
{
    uint8_t l_hybrid_media = 0;
    uint8_t l_spd_hybrid_media = 0;

    FAPI_TRY(iv_spd_data.hybrid_media(l_spd_hybrid_media));
    FAPI_TRY(lookup_table_check(iv_dimm, HYBRID_MAP, SET_ATTR_HYBRID, l_spd_hybrid_media, l_hybrid_media));

    FAPI_TRY( (set_field<mss::proc_type::NIMBUS, HYBRID_MEDIA>(iv_dimm, l_hybrid_media)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode pre_data_engine<mss::proc_type::NIMBUS>::set_master_ranks()
{
    // Sets up commonly used member variables
    uint8_t l_master_ranks_spd = 0;
    uint8_t l_master_ranks_to_set = 0;
    FAPI_TRY(iv_spd_data.num_package_ranks_per_dimm(l_master_ranks_spd),
             "%s failed to get number of package ranks from SPD", spd::c_str(iv_dimm));
    FAPI_TRY(lookup_table_check(iv_dimm, NUM_PACKAGE_RANKS_MAP, PRE_DATA_ENGINE_CTOR, l_master_ranks_spd,
                                l_master_ranks_to_set), "%s failed MASTER_RANKS lookup check", spd::c_str(iv_dimm));

    FAPI_TRY( (set_field<mss::proc_type::NIMBUS, MRANKS>(iv_dimm, l_master_ranks_to_set)) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets ATTR_EFF_DIMM_RANKS_CONFIGED
/// @return FAPI2_RC_SUCCESS iff okay
///
template<>
fapi2::ReturnCode pre_data_engine<mss::proc_type::NIMBUS>::set_dimm_ranks_configured()
{
    // Set configed ranks. Set the bit representing the master rank configured (0 being left most.) So,
    // a 4R DIMM would be 0b11110000 (0xF0). This is used by PRD.
    fapi2::buffer<uint8_t> l_ranks_configed;
    uint8_t l_master_ranks = 0;

    // Make sure the number of master ranks is setup
    FAPI_TRY( set_master_ranks(), "%s Failed to set the number of master ranks", spd::c_str(iv_dimm) );
    FAPI_TRY( eff_num_master_ranks_per_dimm(iv_dimm, l_master_ranks),
              "%s Failed to get the number of master ranks", spd::c_str(iv_dimm) );

    FAPI_TRY( l_ranks_configed.setBit(0, l_master_ranks),
              "%s. Failed to setBit", spd::c_str(iv_dimm) );

    FAPI_TRY( (set_field<mss::proc_type::NIMBUS, DIMM_RANKS_CNFG>(iv_dimm, uint8_t(l_ranks_configed))) );

fapi_try_exit:
    return fapi2::current_err;
}

}//mss
