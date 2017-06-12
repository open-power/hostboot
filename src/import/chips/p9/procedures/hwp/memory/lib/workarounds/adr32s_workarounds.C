/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/adr32s_workarounds.C $ */
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
/// @file workarounds/adr32s_workarounds.C
/// @brief Workarounds for the ADR32s logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors.H>

#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/utils/conversions.H>
#include <lib/fir/fir.H>
#include <lib/workarounds/adr32s_workarounds.H>
#include <lib/phy/ddr_phy.H>
#include <lib/phy/dcd.H>
#include <generic/memory/lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace workarounds
{

namespace adr32s
{

///
/// @brief Clears the FIRs mistakenly set by the DCD calibration
/// @param[in] i_target MCBIST target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Always needs to be run for DD1.* parts.  unsure for DD2
///
fapi2::ReturnCode clear_dcd_firs( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("%s clearing DCD FIRs!", mss::c_str(i_target));

    // Run the fir clear to reset bits that are caused by the DCD calibration
    for( const auto& l_mca : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_IOM_PHY0_DDRPHY_FIR_REG> l_mca_fir_reg(l_mca, fapi2::current_err);
        FAPI_TRY(fapi2::current_err, "unable to create fir::reg for %d", MCA_IOM_PHY0_DDRPHY_FIR_REG);

        // Per Steve Wyatt:
        // Bit 55 gets set during the DCD cal in the ADR
        // Bit 56/58 get set during the DCD cal in the DP's
        // Bit 59 is set due to parity errors and must be cleared, per Tim Buccholtz
        // Clearing them all here, as the DCD cal is run on the ADR/DP's in the same code in lib/adr32s.C
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_1>()); // bit 55
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_2>()); // bit 56
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_4>()); // bit 58
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_5>()); // bit 59
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform ADR DCD calibration - Nimbus Only
/// @param[in] i_target the MCBIST (controler) to perform calibration on
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode duty_cycle_distortion_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    const auto l_mca = mss::find_targets<TARGET_TYPE_MCA>(i_target);

    // Skips DCD calibration if we're a DD2 part
    if (!mss::chip_ec_feature_dcd_workaround(i_target))
    {
        FAPI_INF("%s Skipping DCD calibration algorithm due to part revision", mss::c_str(i_target));
        return FAPI2_RC_SUCCESS;
    }

    // Clears the FIRs created by DCD calibration, if needed
    FAPI_TRY(mss::workarounds::adr32s::clear_dcd_firs(i_target));

    // We must calibrate each of our ports. Each has 2 ADR units and each unit needs it's A-side and B-side calibrated.
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        uint64_t l_seed = TT::DD1_DCD_ADJUST_DEFAULT;

        // Sets up the DLL control regs for DCD cal for this port
        FAPI_TRY(mss::dcd::setup_dll_control_regs( p ));

        for (const auto& r : TT::DUTY_CYCLE_DISTORTION_REG)
        {
            FAPI_TRY(mss::dcd::sw_cal_per_register(p, r, l_seed));
        }

        // Restores the DLL control regs for DCD cal for this port
        FAPI_TRY(mss::dcd::restore_dll_control_regs( p ));
    }

    // Clears the FIRs created by DCD calibration, if needed
    FAPI_TRY(mss::workarounds::adr32s::clear_dcd_firs(i_target));

    FAPI_INF("%s Cleared DCD firs", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retries to clear the cal update bit, as it has been seen that the bit can be "sticky" in hardware
/// @param[in] i_target MCA target on which to operate
/// @param[in] i_reg the register on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode setup_dll_control_regs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_reg )
{
    // Traits definition
    typedef dutyCycleDistortionTraits<TARGET_TYPE_MCA> TT;

    // Poll limit declaration - this is an engineering judgement value from the lab's experimentation
    // The bit thus far has always unstuck after 3 loops, so 10 is more than safe
    constexpr uint64_t POLL_LIMIT = 10;
    bool l_done = false;
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    for(uint64_t i = 0; i < POLL_LIMIT; ++i)
    {
        fapi2::buffer<uint64_t> l_data;

        FAPI_TRY(mss::getScom(i_target, i_reg, l_data), "%s failed to getScom from register 0x%016lx", mss::c_str(i_target),
                 i_reg);

        // If our bit is a 0, then we're done
        l_done = !l_data.getBit<TT::DLL_CAL_UPDATE>();

        // Break out
        if(l_done)
        {
            FAPI_INF("%s DLL control register 0x%016lx is setup correctly after %lu attempts", mss::c_str(i_target), i_reg, i);
            break;
        }

        // Stops cal from updating and disables cal good to keep parity good (these regs have parity issues on bits 60-63)
        l_data.clearBit<TT::DLL_CAL_UPDATE>();
        l_data.clearBit<TT::DLL_CAL_GOOD>();

        FAPI_TRY(mss::putScom(i_target, i_reg, l_data), "%s failed to putScom from register 0x%016lx", mss::c_str(i_target),
                 i_reg);
    }

    // do the error check
    FAPI_ASSERT( l_done,
                 fapi2::MSS_DLL_UPDATE_BIT_STUCK()
                 .set_TARGET(i_target)
                 .set_REGISTER(i_reg),
                 "Failed to setup DLL control reg for %s 0x%016lx", mss::c_str(i_target), i_reg );

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace adr32s
} // close namespace workarounds
} // close namespace mss
