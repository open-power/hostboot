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
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/data_engine/p9n/p9n_data_init_traits.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>

namespace mss
{
// TK - Remove generalizations since this is dubbed Nimbus specific implementation

///
/// @class DataSetterTraits2D
/// @brief Traits for setting eff_config data
/// @tparam P proc_type
/// @tparam X size of 1st array index
/// @tparam Y size of 2nd array index
///
template < proc_type P, size_t X, size_t Y >
struct DataSetterTraits2D;

///
/// @class DataSetterTraits - Nimbus, [PORT][DIMM] array specialization
/// @brief Traits for setting eff_config data
///
template < >
struct DataSetterTraits2D < proc_type::NIMBUS,
           mcTypeTraits<mc_type::NIMBUS>::PORTS_PER_MCS,
           mcTypeTraits<mc_type::NIMBUS>::DIMMS_PER_PORT
           >
{
    static constexpr fapi2::TargetType TARGET = fapi2::TARGET_TYPE_MCA;
};

///
/// @brief Helper function to update a 2D array output
/// @tparam P proc_type
/// @tparam X size of 1st array index
/// @tparam Y size of 2nd array index
/// @tparam T Input/output data type
/// @tparam TT defaulted to DataSetterTraits2D<P, X, Y>
/// @param[in] i_target the DIMM target
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data attribute data structure to set
/// @warning This is Nimbus specific until MCA alias to MEM_PORT
///
template < proc_type P,
           size_t X,
           size_t Y,
           typename T,
           typename TT = DataSetterTraits2D<P, X, Y>
           >
fapi2::ReturnCode update_data(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const T i_setting,
                              const generic_ffdc_codes i_ffdc_code,
                              T (&o_data)[X][Y])
{
    // Currenlty only valid for a DIMM target, for Nimbus, traits enforces this at compile time
    // Use case is currently for pre_eff_config which is supported in both Axone and Nimbus
    const auto l_port_index = mss::index( find_target<TT::TARGET>(i_target) );
    const auto l_dimm_index = mss::index(i_target);

    FAPI_ASSERT( l_port_index < X,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_port_index)
                 .set_LIST_SIZE(X)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(i_target),
                 "Port index (%d) was larger than max (%d) on %s",
                 l_port_index,
                 X,
                 mss::spd::c_str(i_target) );

    FAPI_ASSERT( l_dimm_index < Y,
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(l_dimm_index)
                 .set_LIST_SIZE(Y)
                 .set_FUNCTION(i_ffdc_code)
                 .set_TARGET(i_target),
                 "DIMM index (%d) was larger than max (%d) on %s",
                 l_dimm_index,
                 Y,
                 mss::spd::c_str(i_target) );

    o_data[l_port_index][l_dimm_index] = i_setting;

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets attr data fields
/// @tparam P proc_type
/// @tparam TT data engine class traits (e.g. preDataInitTraits, etc.)
/// @tparam T FAPI2 target type
/// @tparam IT Input data type
/// @param[in] i_target the FAPI target
/// @param[in] i_setting value we want to set attr with
/// @return FAPI2_RC_SUCCESS iff okay
///
template< proc_type P,
          typename TT,
          fapi2::TargetType T,
          typename IT >
inline fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                                   const IT i_setting)
{
    const auto l_attr_target = mss::find_target<TT::TARGET_TYPE>(i_target);
    typename TT::attr_type l_attr_list = {};
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list) );

    FAPI_TRY( update_data<P>(i_target, i_setting, TT::FFDC_CODE, l_attr_list) );
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list) );

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
inline fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                                   const IT i_setting)
{
    FAPI_TRY( (set_field<P, TT>(i_target, i_setting)),
              "Failed set_field() for %s", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Data structure to set pre-effective config data
/// @class pre_data_engine
/// @tparam P supported processor type (e.g. Nimbus, Axone, etc.)
///
template< proc_type P >
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
        fapi2::ReturnCode set_dimm_type()
        {
            uint8_t l_base_module_type = 0;
            uint8_t l_dimm_type = 0;

            FAPI_TRY(iv_spd_data.base_module(l_base_module_type));
            FAPI_TRY(lookup_table_check(iv_dimm, BASE_MODULE_TYPE_MAP, SET_ATTR_DIMM_TYPE, l_base_module_type, l_dimm_type));
            FAPI_TRY( (set_field<P, DIMM_TYPE>(iv_dimm, l_dimm_type)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set ATTR_EFF_DRAM_GEN
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_dram_gen()
        {
            uint8_t l_device_type = 0;
            uint8_t l_dram_gen = 0;

            FAPI_TRY(iv_spd_data.device_type(l_device_type));
            FAPI_TRY(lookup_table_check(iv_dimm, DRAM_GEN_MAP, SET_ATTR_DRAM_GEN, l_device_type, l_dram_gen));

            FAPI_TRY( (set_field<P, DRAM_GEN>(iv_dimm, l_dram_gen)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set ATTR_EFF_HYBRID
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_hybrid()
        {
            uint8_t l_spd_hybrid_type = 0;
            uint8_t l_hybrid = 0;

            FAPI_TRY(iv_spd_data.hybrid(l_spd_hybrid_type));
            FAPI_TRY(lookup_table_check(iv_dimm, HYBRID_MAP, SET_ATTR_HYBRID, l_spd_hybrid_type, l_hybrid));

            FAPI_TRY( (set_field<P, HYBRID>(iv_dimm, l_hybrid)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set ATTR_EFF_HYBRID_MEMORY_TYPE
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_hybrid_media()
        {
            uint8_t l_hybrid_media = 0;
            uint8_t l_spd_hybrid_media = 0;

            FAPI_TRY(iv_spd_data.hybrid_media(l_spd_hybrid_media));
            FAPI_TRY(lookup_table_check(iv_dimm, HYBRID_MAP, SET_ATTR_HYBRID, l_spd_hybrid_media, l_hybrid_media));

            FAPI_TRY( (set_field<P, HYBRID_MEDIA>(iv_dimm, l_hybrid_media)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Set ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode set_master_ranks()
        {
            uint8_t l_master_ranks = 0;
            FAPI_TRY( get_master_ranks(l_master_ranks) );

            FAPI_TRY( (set_field<P, MRANKS>(iv_dimm, l_master_ranks)) );

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Sets ATTR_EFF_DIMM_RANKS_CONFIGED
        /// @return FAPI2_RC_SUCCESS iff okay
        ///
        fapi2::ReturnCode set_dimm_ranks_configured()
        {
            // Set configed ranks. Set the bit representing the master rank configured (0 being left most.) So,
            // a 4R DIMM would be 0b11110000 (0xF0). This is used by PRD.
            fapi2::buffer<uint8_t> l_ranks_configed;

            // Make sure the number of master ranks is setup
            uint8_t l_master_ranks = 0;
            FAPI_TRY( get_master_ranks(l_master_ranks) );

            FAPI_TRY( l_ranks_configed.setBit(0, l_master_ranks),
                      "%s. Failed to setBit", spd::c_str(iv_dimm) );

            FAPI_TRY( (set_field<P, DIMM_RANKS_CNFG>(iv_dimm, uint8_t(l_ranks_configed))) );

        fapi_try_exit:
            return fapi2::current_err;
        }

    private:

        ///
        /// @brief Gets master ranks from SPD
        /// @param[out] o_output num package ranks per DIMM
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode get_master_ranks(uint8_t& o_output)
        {
            // Sets up commonly used member variables
            uint8_t l_master_ranks_spd = 0;
            FAPI_TRY(iv_spd_data.num_package_ranks_per_dimm(l_master_ranks_spd),
                     "%s failed to get number of package ranks from SPD", spd::c_str(iv_dimm));

            FAPI_TRY(lookup_table_check(iv_dimm, NUM_PACKAGE_RANKS_MAP, PRE_DATA_ENGINE_CTOR, l_master_ranks_spd,
                                        o_output), "%s failed MASTER_RANKS lookup check", spd::c_str(iv_dimm));

        fapi_try_exit:
            return fapi2::current_err;
        }
};

///
/// @brief Sets pre_eff_config attributes
/// @tparam P processor type
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_decoder SPD decoder
/// @return FAPI2_RC_SUCCESS iff ok
///
template <mss::proc_type P>
inline fapi2::ReturnCode set_pre_init_attrs( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const spd::facade& i_spd_decoder );

///
/// @brief Sets pre_eff_config attributes - NIMBUS specialization
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_decoder SPD decoder
/// @return FAPI2_RC_SUCCESS iff ok
///
template <>
inline fapi2::ReturnCode set_pre_init_attrs<mss::proc_type::NIMBUS>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_target,
        const spd::facade& i_spd_decoder )
{
    // TK explicitly forcing this API to only run in Nimbus, need to move pre_data_engine to Nimbus chip path,
    // using template recursive algorithm moving forward
    mss::pre_data_engine<mss::proc_type::NIMBUS> l_data_engine(i_target, i_spd_decoder);

    // Set attributes needed before eff_config
    // DIMM type and DRAM gen are needed for c_str to aid debugging
    FAPI_TRY(l_data_engine.set_dimm_type(), "Failed to set DIMM type %s", mss::spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_dram_gen(), "Failed to set DRAM gen %s", mss::spd::c_str(i_target) );

    // Hybrid and hybrid media help detect hybrid modules, specifically NVDIMMs for Nimbus
    FAPI_TRY(l_data_engine.set_hybrid(), "Failed to set Hybrid %s", mss::spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_hybrid_media(), "Failed to set Hybrid Media %s", mss::spd::c_str(i_target) );

    // Number of master ranks needed for VPD decoding
    FAPI_TRY(l_data_engine.set_master_ranks(), "Failed to set Master ranks %s", mss::spd::c_str(i_target) );

    // and dimm_ranks_configured is a PRD attr...
    FAPI_TRY(l_data_engine.set_dimm_ranks_configured(), "Failed to set DIMM ranks configured %s",
             mss::spd::c_str(i_target) );

    // Adding metadata c-str fields derived from attrs set above
    FAPI_TRY( mss::attr_derived_engine<mss::generic_metadata_fields>::set(i_target) );

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
