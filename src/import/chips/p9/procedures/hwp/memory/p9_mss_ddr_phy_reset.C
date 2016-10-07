/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_ddr_phy_reset.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_mss_ddr_phy_reset.C
/// @brief Reset the DDR PHY
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <stdint.h>
#include <string.h>

#include <fapi2.H>
#include <mss.H>

#include <p9_mss_ddr_phy_reset.H>
#include <lib/utils/count_dimm.H>
#include <lib/phy/adr32s.H>

using fapi2::TARGET_TYPE_MCBIST;

extern "C"
{

///
/// @brief Perform a phy reset on all the PHY related to this half-chip (mcbist)
/// @param[in] the mcbist representing the PHY
/// @return FAPI2_RC_SUCCESS iff OK
///
    fapi2::ReturnCode p9_mss_ddr_phy_reset(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
    {

        // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
        // attributes for the PHY, etc.
        if (mss::count_dimm(i_target) == 0)
        {
            FAPI_INF("... skipping ddr_phy_reset %s - no DIMM ...", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY(mss::change_force_mclk_low(i_target, mss::HIGH),
                 "force_mclk_low (set high) Failed rc = 0x%08X", uint64_t(fapi2::current_err) );

        // New for Nimbus - perform duty cycle clock distortion calibration
        FAPI_TRY( mss::adr32s::duty_cycle_distortion_calibration(i_target) );

        // 1. Drive all control signals to the PHY to their inactive state, idle state, or inactive value.
        FAPI_TRY( mss::dp16::reset_sysclk(i_target) );

        //    (Note: The chip should already be in this state.)
        FAPI_DBG("All control signals to the PHYs should already be set to their inactive state, idle state, or inactive values");

        // 2. Assert reset to PHY for 32 memory clocks
        FAPI_TRY( mss::change_resetn(i_target, mss::HIGH), "change_resetn for %s failed", mss::c_str(i_target) );
        fapi2::delay(mss::cycles_to_ns(i_target, 32), mss::cycles_to_simcycles(32));

        // 3. Deassert reset_n
        FAPI_TRY( mss::change_resetn(i_target, mss::LOW), "change_resetn for %s failed", mss::c_str(i_target) );

        //
        // Flush output drivers
        //

        // 8. Set FLUSH=1 and INIT_IO=1 in the DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL and DDRPHY_DP16_DATA_BIT_DIR1 register
        // 9. Wait at least 32 dphy_gckn clock cycles.
        // 10. Set FLUSH=0 and INIT_IO=0 in the DDRPHY_ADR_OUTPUT_FORCE_ATEST_CNTL register
        FAPI_TRY( mss::flush_output_drivers(i_target), "unable to flush output drivers for %s", mss::c_str(i_target) );

        //
        // ZCTL Enable
        //

        // 11. Assert the ZCNTL enable to the internal impedance controller in DDRPHY_PC_RESETS register
        // 12. Wait at least 1024 dphy_gckn cycles
        // 13. Deassert the ZCNTL impedance controller enable, Check for DONE in DDRPHY_PC_DLL_ZCAL
        FAPI_TRY( mss::enable_zctl(i_target), "enable_zctl for %s failed", mss::c_str(i_target) );

        //
        // DLL calibration
        //

        // 14. Begin DLL calibrations by setting INIT_RXDLL_CAL_RESET=0 in the DDRPHY_DP16_DLL_CNTL{0:1} registers
        // and DDRPHY_ADR_DLL_CNTL registers
        // 15. Monitor the DDRPHY_PC_DLL_ZCAL_CAL_STATUS register to determine when calibration is
        // complete. One of the 3 bits will be asserted for ADR and DP16.
        FAPI_INF( "starting DLL calibration %s", mss::c_str(i_target) );
        FAPI_TRY( mss::dll_calibration(i_target) );

        //
        // Start bang-bang-lock
        //

        // 16. Take dphy_nclk/SysClk alignment circuits out of reset and put into continuous update mode,
        FAPI_INF("set up of phase rotator controls %s", mss::c_str(i_target) );
        FAPI_TRY( mss::setup_phase_rotator_control_registers(i_target, mss::ON) );

        // 17. Wait at least 5932 dphy_nclk clock cycles to allow the dphy_nclk/SysClk alignment circuit to
        // perform initial alignment.
        FAPI_INF("Wait at least 5932 memory clock cycles for clock alignment circuit to perform initial alignment %s",
                 mss::c_str(i_target));
        FAPI_TRY( fapi2::delay(mss::cycles_to_ns(i_target, 5932), 2000) );

        // 18. Check for LOCK in DDRPHY_DP16_SYSCLK_PR_VALUE registers and DDRPHY_ADR_SYSCLK_PR_VALUE
        FAPI_INF("Checking for bang-bang lock %s ...", mss::c_str(i_target));
        FAPI_TRY( mss::check_bang_bang_lock(i_target) );

        // 19. Write 0b0 into the DDRPHY_PC_RESETS register bit 1. This write de-asserts the SYSCLK_RESET.
        FAPI_INF("deassert sysclk reset %s", mss::c_str(i_target));
        FAPI_TRY( mss::deassert_sysclk_reset(i_target), "deassert_sysclk_reset failed for %s", mss::c_str(i_target) );

        // 20. Write 8020h into the DDRPHY_ADR_SYSCLK_CNTL_PR Registers and
        // DDRPHY_DP16_SYSCLK_PR0/1 registers This write takes the dphy_nclk/
        // SysClk alignment circuit out of the Continuous Update mode.
        FAPI_INF("take sysclk alignment out of cont update mode %s", mss::c_str(i_target));
        FAPI_TRY( mss::setup_phase_rotator_control_registers(i_target, mss::OFF),
                  "set up of phase rotator controls failed (out of cont update) %s", mss::c_str(i_target) );

        // 21. Wait at least 32 dphy_nclk clock cycles.
        FAPI_DBG("Wait at least 32 memory clock cycles %s", mss::c_str(i_target));
        FAPI_TRY( fapi2::delay(mss::cycles_to_ns(i_target, 32), mss::cycles_to_simcycles(32)) );

        //
        // Done bang-bang-lock
        //

        // Per J. Bialas, force_mclk_low can be dasserted.
        FAPI_TRY(mss::change_force_mclk_low(i_target, mss::LOW),
                 "force_mclk_low (set low) Failed rc = 0x%08X", uint64_t(fapi2::current_err) );

        // If mss_unmask_ddrphy_errors gets it's own bad rc,
        // it will commit the passed in rc (if non-zero), and return it's own bad rc.
        // Else if mss_unmask_ddrphy_errors runs clean,
        // it will just return the passed in rc.
        // TODO RTC:159727  Need to code..   FAPI_TRY(mss_unmask_ddrphy_errors(i_target, rc));

    fapi_try_exit:
        return fapi2::current_err;

    }

}
