/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dp16_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file workarounds/dp16.C
/// @brief Workarounds for the DP16 logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Steven Glancy <sglancy@usi.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/utils/scom.H>
#include <lib/utils/pos.H>
#include <lib/workarounds/dp16_workarounds.H>

namespace mss
{

namespace workarounds
{

namespace dp16
{

///
/// @brief DQS polarity workaround
/// For Monza DDR port 2, one pair of DQS P/N is swapped polarity.  Not in DDR port 6
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called during the phy scom init procedure, after the initfile is
/// processed. It is specific to the Monza module, but can be called for all modules as it
/// will enforce its requirements internally
///
fapi2::ReturnCode dqs_polarity( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    // Receiver config provided by S. Wyatt 8/16
    constexpr uint64_t rx_config = 0x4000;

    // For Monza DDR port 2, one pair of DQS P/N is swapped polarity.  Not in DDR port 6
    // For Monza DDR port 3, one pair of DQS P/N is swapped polarity.  Not in DDR port 7
    const auto l_pos = mss::pos(i_target);

    // TODO RTC:160353 Need module/chip rev EC support for workarounds
    // Need to check this for Monza only when attribute support for EC levels is in place

    // So we need to make sure our position is 2 or 3 and skip for the other ports.
    if (l_pos == 2)
    {
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_DP16_RX_PEAK_AMP_P0_4, rx_config) );
    }

    if (l_pos == 3)
    {
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_DP16_RX_PEAK_AMP_P0_0, rx_config) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace dp16
} // close namespace workarounds
} // close namespace mss

