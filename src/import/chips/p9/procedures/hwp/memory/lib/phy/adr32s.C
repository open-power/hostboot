/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/adr32s.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file adr32s.C
/// @brief Subroutines for the PHY ADR32S registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/phy/adr32s.H>
#include <lib/workarounds/adr32s_workarounds.H>
#include <generic/memory/lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

// Definition of the ADR32S DLL Config registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::DLL_CNFG_REG =
{
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S0,
    MCA_DDRPHY_ADR_DLL_CNTL_P0_ADR32S1
};

// Definition of the ADR32S output driver registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::OUTPUT_DRIVER_REG =
{
    MCA_DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL_P0_ADR32S0,
    MCA_DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL_P0_ADR32S1,
};

// Definition of the ADR32S duty cycle distortion registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::DUTY_CYCLE_DISTORTION_REG =
{
    MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S0,
    MCA_DDRPHY_ADR_DCD_CONTROL_P0_ADR32S1,
};

// Definition of the ADR32S write clock static offset registers
const std::vector<uint64_t> adr32sTraits<fapi2::TARGET_TYPE_MCA>::PR_STATIC_OFFSET_REG =
{
    MCA_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S0,
    MCA_DDRPHY_ADR_MCCLK_WRCLK_PR_STATIC_OFFSET_P0_ADR32S1,
};

namespace adr32s
{

///
/// @brief Perform ADR DCD calibration - Nimbus Only
/// @param[in] i_target the MCBIST (controler) to perform calibration on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode duty_cycle_distortion_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    typedef adr32sTraits<TARGET_TYPE_MCA> TT;

    const auto l_mca = mss::find_targets<TARGET_TYPE_MCA>(i_target);
    fapi2::buffer<uint64_t> l_read;
    uint8_t l_sim = 0;

    FAPI_TRY( mss::is_simulation( l_sim) );

    // Nothing works here in cycle sim ...
    if (l_sim)
    {
        return FAPI2_RC_SUCCESS;
    }

    if (l_mca.size() == 0)
    {
        FAPI_INF("No MCA, skipping duty cycle distortion calibration");
        return FAPI2_RC_SUCCESS;
    }

    // Do a quick check to make sure this chip doesn't have the DCD logic built in (e.g., DD1 Nimbus)
    // TODO RTC:159687 For DD2 all we need to do is kick off the h/w cal and wait. We can check any ADR_DCD
    // register, they all should reflect the inclusion of the DCD logic.

    FAPI_TRY( mss::getScom(l_mca[0], TT::DUTY_CYCLE_DISTORTION_REG[0], l_read) );

    if (l_read.getBit<TT::DCD_CONTROL_DLL_CORRECT_EN>() == 1)
    {
        FAPI_ERR("seeing ADR DCD algorithm is in the logic but we didn't code it?");
        fapi2::Assert(false);
    }

    // Runs the DD1 algorithm for now. The below TODO is to add in a switch to the DD2 algorithm
    // TODO RTC:159687 For DD2 all we need to do is kick off the h/w cal and wait. We can check any ADR_DCD
    FAPI_TRY(mss::workarounds::adr32s::duty_cycle_distortion_calibration(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace adrs32

} // close namespace mss
