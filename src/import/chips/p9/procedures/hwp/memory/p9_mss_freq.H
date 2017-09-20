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
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef MSS_FREQ_H_
#define MSS_FREQ_H_
#include <utility>
#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <lib/utils/conversions.H>

namespace mss
{

///
/// @brief      Sets DRAM CAS latency attributes
/// @param[in]  i_target the controller target the cas_latency vector is for
/// @param[in]  i_cas_latency vector of pairs. Contains the two final selected CAS latencies
/// @return     FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode set_CL_attr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                     const std::vector< std::pair< uint64_t, fapi2::Target<fapi2::TARGET_TYPE_MCA>> >& i_cas_latency)
{
    // I wish I could do the reinterpret cast or set the pointer to the vector :(
    // But no can do, manual copy pasta
    uint8_t l_temp [mss::PORTS_PER_MCS] = {0};

    for( const auto& cl : i_cas_latency )
    {
        // Local variable instead of calling it three times. Hopefully compiler can optimize this better
        const auto l_index = mss::index(cl.second);

        if ( l_index >= PORTS_PER_MCS)
        {
            FAPI_ERR("%s mss::index returned a value greater than PORTS_PER_MCS", mss::c_str(i_target) );
            fapi2::Assert(false);
        }

        l_temp[l_index] = cl.first;

        //Check for rounding issues. Going from a uint64_t to a uint8_t
        FAPI_ASSERT( l_temp[l_index] == cl.first,
                     fapi2::MSS_BAD_CL_CAST()
                     .set_CL(cl.first)
                     .set_MCA_TARGET(cl.second),
                     "%s bad cast for cas latency from %d to %d",
                     mss::c_str(cl.second),
                     cl.first,
                     l_temp[l_index]);

        FAPI_INF( "Final Chosen CL: %d for %s", l_temp[l_index], mss::c_str(cl.second));
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

    // DDR4 speed NIMBUS supports
    std::vector<uint64_t> l_supported = { 0,
                                          fapi2::ENUM_ATTR_MSS_FREQ_MT1866,
                                          fapi2::ENUM_ATTR_MSS_FREQ_MT2133,
                                          fapi2::ENUM_ATTR_MSS_FREQ_MT2400,
                                          fapi2::ENUM_ATTR_MSS_FREQ_MT2666,
                                        };
    std::sort( l_supported.begin(), l_supported.end() );

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

    // Shouldn't be getting 0 here. There have to be DIMMs installed for this code to be executed
    // The code would have errored out before if a frequency wasn't found.:w
    FAPI_ASSERT( std::binary_search(l_supported.begin(), l_supported.end(), l_final_freq) == true,
                 fapi2::MSS_BAD_FREQ_CALCULATED()
                 .set_MSS_FREQ(l_final_freq)
                 .set_MCBIST_TARGET(i_target)
                 .set_SUPPORTED_FREQ_0(fapi2::ENUM_ATTR_MSS_FREQ_MT1866)
                 .set_SUPPORTED_FREQ_1(fapi2::ENUM_ATTR_MSS_FREQ_MT2133)
                 .set_SUPPORTED_FREQ_2(fapi2::ENUM_ATTR_MSS_FREQ_MT2400)
                 .set_SUPPORTED_FREQ_3(fapi2::ENUM_ATTR_MSS_FREQ_MT2666),
                 "%s: Calculated FREQ (%d) isn't supported",
                 mss::c_str(i_target),
                 l_final_freq);

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
