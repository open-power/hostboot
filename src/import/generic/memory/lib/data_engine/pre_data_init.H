/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/pre_data_init.H $   */
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
/// @file pre_data_init.H
/// @brief Class to set preliminary eff_config attributes
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef _MSS_PRE_DATA_INIT_H_
#define _MSS_PRE_DATA_INIT_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief enum list of preliminary data fields
///
enum pre_data_init_fields
{
    DIMM_TYPE,
    DRAM_GEN,
    HYBRID,
    HYBRID_MEDIA,
    MRANKS,
    DIMM_RANKS_CNFG,
};

///
/// @brief Traits for pre_data_engine
/// @class preDataInitTraits
/// @tparam T proc_type (e.g. Nimbus, Axone, etc.)
/// @tparam TT pre_data_init_fields (e.g. DIMM_TYPE, MRANK, etc.)
///
template< proc_type T, pre_data_init_fields TT >
class preDataInitTraits;

///
/// @brief Helper function for attribute setting
/// @tparam T processor type (e.g. NIMBUS, AXONE, etc.)
/// defaulted to NIMBUS
/// @tparam X size of 1st array index
/// @tparam Y size of 2nd array index
/// @tparam TT FAPI2 target type
/// @tparam IT Input/outpu data type
/// @param[in] i_target the MCS target
/// @param[in] i_setting array to set
/// @param[out] o_data attribute data structure to set
/// @warning This is Nimbus specific
///
template < size_t X, size_t Y, typename IT >
void data_setter( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                  const IT i_setting,
                  IT (&o_data)[X][Y])
{
    const size_t l_port_index = mss::index( find_target<fapi2::TARGET_TYPE_MCA>(i_target) );
    const size_t l_dimm_index = mss::index(i_target);

    o_data[l_port_index][l_dimm_index] = i_setting;
}

///
/// @brief Mapping boilerplate check
/// @tparam T FAPI2 target type
/// @tparam IT map key type
/// @tparam OT map value type
/// @param[in] i_map SPD to attribute data mapping
/// @param[in] i_ffdc_code FFDC function code
/// @param[in] i_key Key to query map
/// @param[out] o_output value from key
///
template< fapi2::TargetType T, typename IT, typename OT >
fapi2::ReturnCode lookup_table_check(const fapi2::Target<T>& i_target,
                                     const std::vector<std::pair<IT, OT>>& i_map,
                                     const generic_ffdc_codes i_ffdc_code,
                                     const IT i_key,
                                     OT& o_output)
{
    const bool l_is_val_found = mss::find_value_from_key(i_map, i_key, o_output);

    FAPI_ASSERT( l_is_val_found,
                 fapi2::MSS_LOOKUP_FAILED()
                 .set_KEY(i_key)
                 .set_DATA(o_output)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(i_target),
                 "Failed to find a mapped value for %d on %s",
                 i_key,
                 mss::spd::c_str(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets preliminary data fields
/// @tparam P processor type (e.g. NIMBUS, AXONE, etc.)
/// @tparam F pre_data_init_fields
/// @tparam T FAPI2 target type
/// @tparam IT Input data type
/// @tparam TT defaulted to preDataInitTraits<T>
/// @param[in] i_setting value we want to set attr with
/// @return FAPI2_RC_SUCCESS iff okay
///
template< proc_type P,
          pre_data_init_fields F,
          fapi2::TargetType T,
          typename IT,
          typename TT = preDataInitTraits<P, F>
          >
fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target, const IT i_setting)
{
    const auto l_target = mss::find_target<TT::TARGET_TYPE>(i_target);
    typename TT::attr_type l_attr_list = {};
    IT l_mapping_value = i_setting;

    FAPI_TRY( TT::get_attr(l_target, l_attr_list) );

    // Indexing isn't very general
    data_setter(i_target, l_mapping_value, l_attr_list);

    FAPI_TRY( TT::set_attr(l_target, l_attr_list) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Data structure to set pre-effective config data
/// @class pre_data_engine
/// @tparam T supported processor type (e.g. Nimbus, Axone, etc.)
///
template< proc_type T >
class pre_data_engine
{
    private:

        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm;
        spd::facade iv_spd_data;

    public:

        static const std::vector<std::pair<uint8_t, uint8_t> > NUM_PACKAGE_RANKS_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > BASE_MODULE_TYPE_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > DRAM_GEN_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > HYBRID_MAP;
        static const std::vector<std::pair<uint8_t, uint8_t> > HYBRID_MEMORY_TYPE_MAP;

        ///
        /// @brief ctor
        /// @param[in] i_target the DIMM target
        /// @param[in] i_spd_data SPD decoder
        ///
        pre_data_engine(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const spd::facade& i_spd_data):
            iv_dimm(i_target),
            iv_spd_data(i_spd_data)
        {}

        ///
        /// @brief default dtor
        ///
        ~pre_data_engine() = default;

        ///
        /// @brief Set ATTR_EFF_DIMM_TYPE
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_dimm_type();

        ///
        /// @brief Set ATTR_EFF_DRAM_GEN
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_dram_gen();

        ///
        /// @brief Set ATTR_EFF_HYBRID
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_hybrid();

        ///
        /// @brief Set ATTR_EFF_HYBRID_MEMORY_TYPE
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_hybrid_media();

        ///
        /// @brief Set ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_master_ranks();

        ///
        /// @brief Sets ATTR_EFF_DIMM_RANKS_CONFIGED
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode set_dimm_ranks_configured();
};

///
/// @brief Sets pre_eff_config attributes
/// @tparam P processor type
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_decoder SPD decoder
/// @return FAPI2_RC_SUCCESS iff ok
///
template <mss::proc_type P>
fapi2::ReturnCode set_pre_init_attrs( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const spd::facade& i_spd_decoder )
{
    mss::pre_data_engine<P> l_data_engine(i_target, i_spd_decoder);

    // Set attributes needed before eff_config
    // DIMM type and DRAM gen are needed for c_str to aid debugging
    FAPI_TRY(l_data_engine.set_dimm_type(), "Failed to set DIMM type %s", mss::spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_dram_gen(), "Failed to set DRAM gen %s", mss::spd::c_str(i_target) );

    // Hybrid and hybrid media help detect hybrid modules, specifically NVDIMMs for Nimbus
    FAPI_TRY(l_data_engine.set_hybrid(), "Failed to set Hybrid %s", mss::spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_hybrid_media(), "Failed to set Hybrid Media %s", mss::spd::c_str(i_target) );

    // Number of master ranks needed for VPD decoding
    // and dimm_ranks_configured is a PRD attr...
    FAPI_TRY(l_data_engine.set_master_ranks(), "Failed to set Master ranks %s", mss::spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_dimm_ranks_configured(), "Failed to set DIMM ranks configured %s",
             mss::spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets pre_eff_config attributes
/// @tparam P processor type
/// @tparam T fapi2::TargetType
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCESS iff ok
///
template <mss::proc_type P, fapi2::TargetType T>
fapi2::ReturnCode set_pre_init_attrs( const fapi2::Target<T>& i_target )
{
    for( const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        std::vector<uint8_t> l_raw_spd;
        FAPI_TRY(mss::spd::get_raw_data(d, l_raw_spd));
        {
            // Gets the SPD facade
            fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
            mss::spd::facade l_spd_decoder(d, l_raw_spd, l_rc);

            // Checks that the facade was setup correctly
            FAPI_TRY(l_rc, "Failed to initialize SPD facade for %s", mss::spd::c_str(d));

            // Sets pre-init attributes
            FAPI_TRY(mss::set_pre_init_attrs<P>(d, l_spd_decoder), "%s failed to set pre init attrs", mss::spd::c_str(d) );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

}//mss

#endif
