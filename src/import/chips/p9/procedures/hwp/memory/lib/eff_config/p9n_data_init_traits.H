/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/p9n_data_init_traits.H $ */
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
#include <generic/memory/lib/data_engine/data_engine.H>
#include <lib/mss_attribute_accessors.H>

namespace mss
{

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, DIMM_TYPE specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, pre_data_init_fields::DIMM_TYPE>
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
                                          attr_type& i_setting)
        {
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_TYPE, i_target, i_setting);
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, DRAM_GEN specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, pre_data_init_fields::DRAM_GEN>
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
                                          attr_type& i_setting)
        {
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_GEN, i_target, i_setting);
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, HYBRID specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, pre_data_init_fields::HYBRID>
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
                                          attr_type& i_setting)
        {
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID, i_target, i_setting);
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, HYBRID_MEDIA specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, pre_data_init_fields::HYBRID_MEDIA>
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
                                          attr_type& i_setting)
        {
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_HYBRID_MEMORY_TYPE, i_target, i_setting);
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, MRANKS specialization
///
template<>
class preDataInitTraits<mss::proc_type::NIMBUS, pre_data_init_fields::MRANKS>
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
                                          attr_type& i_setting)
        {
            return FAPI_ATTR_SET(fapi2::ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, i_setting);
        }
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @note NIMBUS, DIMM_RANKS_CNFG specialization
///
template<>
struct preDataInitTraits<mss::proc_type::NIMBUS, pre_data_init_fields::DIMM_RANKS_CNFG>
{
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
        return FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_RANKS_CONFIGED, i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the MCS target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return FAPI_ATTR_SET(fapi2::ATTR_EFF_DIMM_RANKS_CONFIGED, i_target, i_setting);
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note AXONE, DIMM_TYPE_METADATA specialization
///
template<>
struct attrEngineTraits<proc_type::NIMBUS, generic_metadata_fields, generic_metadata_fields::DIMM_TYPE_METADATA>
{
    using attr_type = fapi2::ATTR_MEM_DIMM_TYPE_METADATA_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_DIMM_TYPE_METADATA_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_TYPE_METADATA;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the MCS target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return FAPI_ATTR_GET(fapi2::ATTR_MEM_DIMM_TYPE_METADATA, i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the MCS target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return FAPI_ATTR_SET(fapi2::ATTR_MEM_DIMM_TYPE_METADATA, i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[in] i_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        return mss::eff_dimm_type(i_target, o_setting);
    }
};

///
/// @brief Traits associated with DIMM positioning
/// @class dimmPosTraits - NIMBUS specializattion
///
template<>
class dimmPosTraits<mss::mc_type::NIMBUS>
{
    private:
        using PT = posTraits<fapi2::TARGET_TYPE_DIMM>;
        using MT = mss::mcTypeTraits<mc_type::NIMBUS>;

    public:
        // Public interface syntatic sugar
        using pos_type = PT::pos_type;

        // Proc 0 is DIMM 0-15, proc 2 is 64-79. 64 is the stride between processors
        static constexpr auto DIMM_STRIDE_PER_PROC = 64;
        static constexpr auto TOTAL_DIMM = MT::MC_PER_MODULE * MT::MCS_PER_MC * MT::PORTS_PER_MCS * MT::DIMMS_PER_PORT;

        ///
        /// @brief Return the PROC_CHIP parent of a DIMM
        /// @param[in] i_target the dimm target
        /// @return the fapi2 proc target
        ///
        static fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> get_proc(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
        {
            // Using fapi2 rather than mss::find as this is pretty low level stuff.
            return i_target.getParent<fapi2::TARGET_TYPE_MCA>().getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note generic_metadata_fields, DRAM_GEN_METADATA specialization
///
template<>
struct attrEngineTraits<proc_type::NIMBUS, generic_metadata_fields, generic_metadata_fields::DRAM_GEN_METADATA>
{
    using attr_type = fapi2::ATTR_MEM_DRAM_GEN_METADATA_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_DRAM_GEN_METADATA_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DRAM_GEN_METADATA;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the MCS target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return FAPI_ATTR_GET(fapi2::ATTR_MEM_DRAM_GEN_METADATA, i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the MCS target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return FAPI_ATTR_SET(fapi2::ATTR_MEM_DRAM_GEN_METADATA, i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[in] i_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        return mss::eff_dram_gen(i_target, o_setting);
    }
};

///
/// @brief Traits for pre_data_engine
/// @class attrEngineTraits
/// @note generic_metadata_fields, DIMM_POS_METADATA specialization
///
template<>
struct attrEngineTraits<proc_type::NIMBUS, generic_metadata_fields, generic_metadata_fields::DIMM_POS_METADATA>
{
    using attr_type = fapi2::ATTR_MEM_DIMM_POS_METADATA_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_DIMM_POS_METADATA_TargetType;
    static constexpr generic_ffdc_codes FFDC_CODE = SET_DIMM_POS_METADATA;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the MCS target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return FAPI_ATTR_GET(fapi2::ATTR_MEM_DIMM_POS_METADATA, i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the MCS target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return FAPI_ATTR_SET(fapi2::ATTR_MEM_DIMM_POS_METADATA, i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data SPD data
    /// @param[in] i_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            attr_integral_type& o_setting)
    {
        using TT = mss::dimmPosTraits<mss::mc_type::NIMBUS>;
        return gen::dimm_pos<TT>(i_target, o_setting);
    }
};

}// mss

#endif
