/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/p9n/p9n_data_init_traits.H $ */
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
/// @file p9n_data_init_traits.H
/// @brief Trait class definitions for Nimbus pre_data_init
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _MSS_P9N_PRE_DATA_INIT_TRAITS_H_
#define _MSS_P9N_PRE_DATA_INIT_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>

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
        static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_TYPE;

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
        static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_GEN;

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
        static constexpr generic_ffdc_codes FFDC_CODE = SET_HYBRID;

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
        static constexpr generic_ffdc_codes FFDC_CODE = SET_HYBRID_MEDIA;

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
        static constexpr generic_ffdc_codes FFDC_CODE = SET_MRANKS;

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
        static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_RANKS_CNFG;

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

}// mss

#endif
