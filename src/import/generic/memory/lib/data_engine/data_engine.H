/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file data_engine.H
/// @brief Classes for the eff_config engine
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:CI

#ifndef _MSS_GEN_DATA_ENGINE_H_
#define _MSS_GEN_DATA_ENGINE_H_

#include <cstring>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>

namespace mss
{
namespace gen
{

///
/// @brief Template recursive algorithm for setting attrs
/// @class attr_engine - partial specialization when F != 0
/// @tparam P processor type
/// @tparam ET enum type - conceptually a list of attrs to set
/// @tparam F enum value - the specific attr value from ET to set
/// @tparam TT associated traits for attr_engine
///
template < proc_type P, typename ET, ET F, typename TT >
struct attr_engine<P, ET, F, TT, false>
{
    ///
    /// @brief Sets attributes fields F in ET
    /// @tparam IT the input type
    /// @param[in] i_input input (efd_decoder, spd_facade, fapi2 target)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename IT >
    static fapi2::ReturnCode single_set(const IT& i_input)
    {
        typename TT::attr_type_to_set l_value = {};

        FAPI_TRY( TT::get_value_to_set(i_input, l_value),
                  "Failed get_value_to_set() for proc_type: %d and enum val: %d", P, F);

        FAPI_TRY( set_field<TT>(i_input, l_value),
                  "Failed set_field() for proc_type: %d and enum val: %d", P, F);

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Sets attributes fields F in ET
    /// @tparam IT the input type
    /// @param[in] i_input input (efd_decoder, spd_facade, fapi2 target)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename IT >
    static fapi2::ReturnCode set(const IT& i_input)
    {
        FAPI_DBG("Processing field %u", F);
        FAPI_TRY( (attr_engine<P, ET, F, TT, static_cast<size_t>(F) == 0u>::single_set(i_input)),
                  "Failed attr_engine<P, ET, F>::single_set() for proc_type: %d and enum val: %d", P, F);

        // Compiler isn't smart enough to deduce F - 1u (decrementing the enum values by 1)
        // Cast needed to help the compiler deduce this value is an ET type
        // This does the recursive call to unroll a compile-time looping of a enum list of attrs to set
        // The recursion stops at the base case where NEXT_FLD == 0u
        {
            constexpr ET NEXT_FLD = static_cast<ET>( static_cast<size_t>(F) - 1u );
            using T =  mss::attrEngineTraits<P, ET, NEXT_FLD>;

            FAPI_TRY( (attr_engine <P, ET, NEXT_FLD, T, 0u == static_cast<size_t>(NEXT_FLD)>::set(i_input)),
                      "Failed (attr_engine <P, ET, NEXT_FLD>::set() for proc_type: %d and enum val: %d", P, F);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Template recursive algorithm for setting attrs
/// @class attr_engine - partial specialization where F == 0u
/// @tparam P processor type
/// @tparam ET attr fields enum type (conceptually a list of attrs to set)
/// @tparam F enum value - the specific attr value from ET to set
/// @tparam TT associated traits for attr_engine
///
template < proc_type P, typename ET, ET F, typename TT >
struct attr_engine< P, ET, F, TT, true >
{
    ///
    /// @brief Sets attributes fields F in ET
    /// @tparam IT the input type
    /// @param[in] i_input input (efd_decoder, spd_facade, fapi2 target)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    template < typename IT >
    static fapi2::ReturnCode set(const IT& i_input)
    {
        FAPI_DBG("NO-OP: Reached base case (0) of recursive template for proc_type: %d and enum value: %d", P, F);
        return fapi2::FAPI2_RC_SUCCESS;
    }
};

}// gen

}// mss

#endif
