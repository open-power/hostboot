/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/core/p9_hcd_core_stopclocks.C $ */
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
/// @file  p9_hcd_core_stopclocks.C
/// @brief Core Clock Stop
///
/// Procedure Summary:

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : HB:PREV
// *HWP Level              : 2

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_misc_scom_addresses.H>
#include <p9_quad_scom_addresses.H>
#include <p9_hcd_common.H>
#include <p9_common_clk_ctrl_state.H>
#include "p9_hcd_core_stopclocks.H"

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P9_HCD_CORE_STOPCLOCKS_CONSTANTS
{
    CORE_PCB_MUX_POLLING_HW_NS_DELAY      = 10000,
    CORE_PCB_MUX_POLLING_SIM_CYCLE_DELAY  = 320000,
    CORE_CLK_SYNC_POLLING_HW_NS_DELAY     = 10000,
    CORE_CLK_SYNC_POLLING_SIM_CYCLE_DELAY = 320000,
    CORE_CLK_STOP_POLLING_HW_NS_DELAY     = 10000,
    CORE_CLK_STOP_POLLING_SIM_CYCLE_DELAY = 320000
};

//------------------------------------------------------------------------------
// Procedure: Core Clock Stop
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_hcd_core_stopclocks(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_INF(">>p9_hcd_core_stopclocks");
    fapi2::ReturnCode                              l_rc;
    fapi2::buffer<uint64_t>                        l_ccsr;
    fapi2::buffer<uint64_t>                        l_data64;
    fapi2::buffer<uint64_t>                        l_temp64;
    uint32_t                                       l_loops1ms;
    uint8_t                                        l_attr_chip_unit_pos;
    uint8_t                                        l_attr_vdm_enabled;
    uint8_t                                        l_attr_sdisn_setup;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    auto  l_quad = i_target.getParent<fapi2::TARGET_TYPE_EQ>();
    auto  l_perv = i_target.getParent<fapi2::TARGET_TYPE_PERV>();
    auto  l_chip = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_SDISN_SETUP, l_chip,
                           l_attr_sdisn_setup));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_ENABLED,      l_chip,
                           l_attr_vdm_enabled));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,    l_perv,
                           l_attr_chip_unit_pos));
    l_attr_chip_unit_pos = (l_attr_chip_unit_pos -
                            p9hcd::PERV_TO_CORE_POS_OFFSET) % 4;

    // ----------------------------
    // Prepare to stop core clocks
    // ----------------------------

    FAPI_DBG("Check PM_RESET_STATE_INDICATOR via GPMMR[15]");
    FAPI_TRY(getScom(i_target, C_PPM_GPMMR_SCOM, l_data64));

    if (!l_data64.getBit<15>())
    {
        FAPI_DBG("Gracefully turn off power management, continue anyways if fail");
        /// @todo RTC158181 suspend_pm()
    }

    FAPI_DBG("Check core clock controller status");
    l_rc = p9_common_clk_ctrl_state<fapi2::TARGET_TYPE_CORE>(i_target);

    if (l_rc)
    {
        FAPI_INF("Clock controller of this core chiplet is inaccessible, return");
        goto fapi_try_exit;
    }

    FAPI_DBG("Check cache clock controller status");
    l_rc = p9_common_clk_ctrl_state<fapi2::TARGET_TYPE_EQ>(l_quad);

    if (l_rc)
    {
        FAPI_INF("WARNING: core is enabled while cache is not, continue anyways");
    }
    else
    {

        FAPI_DBG("Check PERV clock status for access to CME via CLOCK_STAT[4]");
        FAPI_TRY(getScom(l_quad, EQ_CLOCK_STAT_SL, l_data64));

        FAPI_DBG("Check PERV fence status for access to CME via CPLT_CTRL1[4]");
        FAPI_TRY(getScom(l_quad, EQ_CPLT_CTRL1, l_temp64));

        if (l_data64.getBit<4>() == 0 && l_temp64.getBit<4>() == 0)
        {
            //halt cme(poll for halted, if timeout, print warnning keep going).

            FAPI_DBG("Assert Core-L2/CC Quiesces via CME_SCOM_SICR[6,8]/[7,9]");
            FAPI_TRY(putScom(l_quad,
                             (l_attr_chip_unit_pos < 2) ?
                             EX_0_CME_SCOM_SICR_OR : EX_1_CME_SCOM_SICR_OR,
                             (BIT64(6 + (l_attr_chip_unit_pos % 2)) |
                              BIT64(8 + (l_attr_chip_unit_pos % 2)))));
        }
    }

    FAPI_DBG("Assert pm_mux_disable to get PCB Mux from CME via SLAVE_CONFIG[7]");
    FAPI_TRY(getScom(i_target, C_SLAVE_CONFIG_REG, l_data64));
    FAPI_TRY(putScom(i_target, C_SLAVE_CONFIG_REG, DATA_SET(7)));

    FAPI_DBG("Override possible PPM write protection to CME via CPPM_CPMMR[1]");
    FAPI_TRY(putScom(i_target, C_CPPM_CPMMR_OR, MASK_SET(1)));

    FAPI_DBG("Assert chiplet fence via NET_CTRL0[18]");
    FAPI_TRY(putScom(i_target, C_NET_CTRL0_WOR, MASK_SET(18)));

    // -------------------------------
    // Stop core clocks
    // -------------------------------

    FAPI_DBG("Clear all SCAN_REGION_TYPE bits");
    FAPI_TRY(putScom(i_target, C_SCAN_REGION_TYPE, MASK_ZERO));

    FAPI_DBG("Stop core clocks(all but pll) via CLK_REGION");
    l_data64 = (p9hcd::CLK_STOP_CMD           |
                p9hcd::CLK_REGION_ALL_BUT_PLL |
                p9hcd::CLK_THOLD_ALL);
    FAPI_TRY(putScom(i_target, C_CLK_REGION, l_data64));

    FAPI_DBG("Poll for core clocks stopped via CPLT_STAT0[8]");
    l_loops1ms = 1E6 / CORE_CLK_STOP_POLLING_HW_NS_DELAY;

    do
    {
        fapi2::delay(CORE_CLK_STOP_POLLING_HW_NS_DELAY,
                     CORE_CLK_STOP_POLLING_SIM_CYCLE_DELAY);

        FAPI_TRY(getScom(i_target, C_CPLT_STAT0, l_data64));
    }
    while((l_data64.getBit<8>() != 1) && ((--l_loops1ms) != 0));

    FAPI_ASSERT((l_loops1ms != 0),
                fapi2::PMPROC_CORECLKSTOP_TIMEOUT().set_CORECPLTSTAT(l_data64),
                "Core Clock Stop Timeout");

    FAPI_DBG("Check core clocks stopped via CLOCK_STAT_SL[4-13]");
    FAPI_TRY(getScom(i_target, C_CLOCK_STAT_SL, l_data64));

    FAPI_ASSERT((((~l_data64) & p9hcd::CLK_REGION_ALL_BUT_PLL) == 0),
                fapi2::PMPROC_CORECLKSTOP_FAILED().set_CORECLKSTAT(l_data64),
                "Core Clock Stop Failed");
    FAPI_DBG("Core clocks stopped now");

    // -------------------------------
    // Disable core clock sync
    // -------------------------------

    FAPI_DBG("Drop core clock sync enable via CPPM_CACCR[15]");
    FAPI_TRY(putScom(i_target, C_CPPM_CACCR_CLEAR, MASK_SET(15)));

    FAPI_DBG("Poll for core clock sync done to drop via CPPM_CACSR[13]");
    l_loops1ms = 1E6 / CORE_CLK_SYNC_POLLING_HW_NS_DELAY;

    do
    {
        fapi2::delay(CORE_CLK_SYNC_POLLING_HW_NS_DELAY,
                     CORE_CLK_SYNC_POLLING_SIM_CYCLE_DELAY);

        FAPI_TRY(getScom(i_target, C_CPPM_CACSR, l_data64));
    }
    while((l_data64.getBit<13>() == 1) && ((--l_loops1ms) != 0));

    FAPI_ASSERT((l_loops1ms != 0),
                fapi2::PMPROC_CORECLKSYNCDROP_TIMEOUT().set_COREPPMCACSR(l_data64),
                "Core Clock Sync Drop Timeout");
    FAPI_DBG("Core clock sync done dropped");

    // -------------------------------
    // Fence up
    // -------------------------------

    FAPI_DBG("Assert skew sense to skew adjust fence via NET_CTRL0[22]");
    FAPI_TRY(putScom(i_target, C_NET_CTRL0_WOR, MASK_SET(22)));

    FAPI_DBG("Drop ABIST_SRAM_MODE_DC to support ABIST Recovery via BIST[1]");
    FAPI_TRY(getScom(i_target, C_BIST, l_data64));
    FAPI_TRY(putScom(i_target, C_BIST, DATA_UNSET(1)));

    FAPI_DBG("Assert vital fence via CPLT_CTRL1[3]");
    FAPI_TRY(putScom(i_target, C_CPLT_CTRL1_OR, MASK_SET(3)));

    FAPI_DBG("Assert regional fences via CPLT_CTRL1[4-14]");
    FAPI_TRY(putScom(i_target, C_CPLT_CTRL1_OR, p9hcd::CLK_REGION_ALL));

    if (l_attr_sdisn_setup)
    {
        FAPI_DBG("DD1 Only: Drop sdis_n(flushing LCBES condition) vai CPLT_CONF0[34]");
        FAPI_TRY(putScom(i_target, C_CPLT_CONF0_CLEAR, MASK_SET(34)));
    }

    // -------------------------------
    // Disable VDM
    // -------------------------------

    if (l_attr_vdm_enabled == fapi2::ENUM_ATTR_VDM_ENABLED_TRUE)
    {
        FAPI_DBG("Set VDM Disable via CPPM_VDMCR[1]");
        FAPI_TRY(putScom(i_target, C_PPM_VDMCR_OR, MASK_SET(1)));
        FAPI_DBG("Drop VDM Poweron via CPPM_VDMCR[0]");
        FAPI_TRY(putScom(i_target, C_PPM_VDMCR_CLEAR, MASK_SET(0)));
    }

    // -------------------------------
    // Update stop history
    // -------------------------------

    FAPI_DBG("Set core as stopped in STOP history register");
    FAPI_TRY(putScom(i_target, C_PPM_SSHSRC, BIT64(0)));

    // -------------------------------
    // Clean up
    // -------------------------------

    FAPI_DBG("Return possible PPM write protection to CME via CPPM_CPMMR[1]");
    FAPI_TRY(putScom(i_target, C_CPPM_CPMMR_CLEAR, MASK_SET(1)));

    FAPI_DBG("Drop pm_mux_disable to release PCB Mux via SLAVE_CONFIG[7]");
    FAPI_TRY(getScom(i_target, C_SLAVE_CONFIG_REG, l_data64));
    FAPI_TRY(putScom(i_target, C_SLAVE_CONFIG_REG, DATA_UNSET(7)));

fapi_try_exit:

    FAPI_INF("<<p9_hcd_core_stopclocks");
    return fapi2::current_err;
}




