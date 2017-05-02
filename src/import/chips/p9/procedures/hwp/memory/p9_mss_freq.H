/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_freq.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_mss_freq.H
/// @brief Calculate and save off DIMM frequencies
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef MSS_FREQ_H_
#define MSS_FREQ_H_

#include <fapi2.H>
#include <lib/freq/cas_latency.H>
#include <lib/freq/cycle_time.H>
#include <lib/shared/mss_const.H>
#include <lib/utils/conversions.H>

namespace mss
{

///
/// @brief      Sets DRAM CAS latency attributes
/// @param[in]  i_target the controller target
/// @param[in]  i_cas_latency vector of the two final selected CAS latencies
/// @return     FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode set_CL_attr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                     std::vector< uint64_t >& i_cas_latency)
{
    // I wish I could do the reinterpret cast or set the pointer to the vector :(
    // But no can do, manual copy pasta
    uint8_t l_temp [mss::PORTS_PER_MCS] = {};

    for( const auto& p : find_targets<fapi2::TARGET_TYPE_MCA>(i_target) )
    {
        // Local variable instead of calling it three times. Hopefully compiler can optimize this better
        const auto l_index = mss::index(p);

        if ( l_index >= PORTS_PER_MCS)
        {
            FAPI_ERR("%s mss::index returned a value greater than PORTS_PER_MCS", mss::c_str(i_target) );
            fapi2::Assert(false);
        }

        l_temp[l_index] = i_cas_latency[l_index];
        FAPI_ASSERT( l_temp[l_index] == i_cas_latency[l_index],
                     fapi2::MSS_BAD_CL_CAST()
                     .set_CL(i_cas_latency[l_index])
                     .set_MCA_TARGET(p),
                     "%s bad cast for cas latency from %d to %d",
                     mss::c_str(i_target),
                     i_cas_latency[l_index],
                     l_temp[l_index]);
        FAPI_INF( "Final Chosen CL: %d for %s", l_temp[l_index], mss::c_str(p));
    }

    // set CAS latency attribute
    // casts vector into the type FAPI_ATTR_SET is expecting by deduction
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EFF_DRAM_CL,
                            i_target,
                            l_temp) ,
              "Failed to set CAS latency attribute");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Sets frequency attributes
/// @param[in]  i_target the controller target
/// @param[in]  i_dimm_freq vector of freqs selected dimm freq in MT/s
/// @return     FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode set_freq_attrs(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                        const std::vector< std::vector<uint64_t> >& i_dimm_freq)
{
    // Find the minimum (but non-0) freq in the vector. If we see all 0's we'll write a 0. However,
    // we shouldn't as the caller should have been dealing with no DIMM before we got here.
    uint64_t l_final_freq = UINT64_MAX;

    for (const auto l_vec : i_dimm_freq)
    {
        for (const auto l_freq : l_vec)
        {
            if (l_freq != 0)
            {
                l_final_freq = std::min(l_final_freq, l_freq);
            }
        }
    }

    // If we saw all 0's, write a 0.
    l_final_freq = l_final_freq == UINT64_MAX ? 0 : l_final_freq;

    FAPI_INF( "Final Chosen Frequency: %d (%s)", l_final_freq, mss::c_str(i_target) );

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MSS_FREQ, i_target, l_final_freq),
             "Failed to set mss freq attribute");

fapi_try_exit:
    return fapi2::current_err;
}

}// mss namespace


typedef fapi2::ReturnCode (*p9_mss_freq_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCS>&);

extern "C"
{

    ///
    /// @brief Calculate and save off DIMM frequencies
    /// @param[in] i_target the controller (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_freq( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

}

#endif
