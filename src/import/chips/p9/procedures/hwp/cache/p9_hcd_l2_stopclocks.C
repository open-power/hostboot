/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_hcd_l2_stopclocks.C $ */
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
/// @file  p9_hcd_l2_stopclocks.C
/// @brief Quad Clock Stop
///
/// Procedure Summary:

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : HB:PERV
// *HWP Level              : 2

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_misc_scom_addresses.H>
#include <p9_quad_scom_addresses.H>
#include <p9_hcd_common.H>
#include "p9_hcd_l2_stopclocks.H"

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P9_HCD_L2_STOPCLOCKS_CONSTANTS
{
    L2_CLK_SYNC_TIMEOUT_IN_MS = 1,
    L2_CLK_STOP_TIMEOUT_IN_MS = 1
};

//------------------------------------------------------------------------------
// Procedure: Quad Clock Stop
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_hcd_l2_stopclocks(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    const p9hcd::P9_HCD_EX_CTRL_CONSTANTS       i_select_ex)
{
    FAPI_INF(">>p9_hcd_l2_stopclocks: ex[%d]",  i_select_ex);
    fapi2::buffer<uint64_t>                     l_data64;
    uint32_t                                    l_timeout;
    uint64_t                                    l_region_clock = 0;
    uint64_t                                    l_l2sync_clock = 0;
    uint64_t                                    l_l2mask_pscom = 0;
    uint8_t                                     l_attr_chip_unit_pos = 0;
    auto l_perv = i_target.getParent<fapi2::TARGET_TYPE_PERV>();
    auto l_chip = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_perv,
                           l_attr_chip_unit_pos));
    l_attr_chip_unit_pos = l_attr_chip_unit_pos - p9hcd::PERV_TO_QUAD_POS_OFFSET;

    if (i_select_ex & p9hcd::EVEN_EX)
    {
        l_region_clock |= p9hcd::CLK_REGION_EX0_L2;
        l_l2sync_clock |= BIT64(36);
        l_l2mask_pscom |= BIT64(2) | BIT64(10);
    }

    if (i_select_ex & p9hcd::ODD_EX)
    {
        l_region_clock |= p9hcd::CLK_REGION_EX1_L2;
        l_l2sync_clock |= BIT64(37);
        l_l2mask_pscom |= BIT64(3) | BIT64(11);
    }

    // -------------------------
    // Prepare to stop L2 clocks
    // -------------------------

    FAPI_DBG("Assert L2 pscom masks via RING_FENCE_MASK_LATCH_REG[2/3,10/11]");
    FAPI_TRY(putScom(i_target, EQ_RING_FENCE_MASK_LATCH_REG, l_l2mask_pscom));

    // -------------------------------
    // Stop L2 clocks
    // -------------------------------

    FAPI_DBG("Clear all SCAN_REGION_TYPE bits");
    FAPI_TRY(putScom(i_target, EQ_SCAN_REGION_TYPE, MASK_ZERO));

    FAPI_DBG("Stop L2 clocks via CLK_REGION");
    l_data64 = (p9hcd::CLK_STOP_CMD           |
                l_region_clock                |
                p9hcd::CLK_THOLD_ALL);
    FAPI_TRY(putScom(i_target, EQ_CLK_REGION, l_data64));

    FAPI_DBG("Poll for L2 clocks stopped via CPLT_STAT0[8]");
    l_timeout = (p9hcd::CYCLES_PER_MS / p9hcd::INSTS_PER_POLL_LOOP) *
                L2_CLK_STOP_TIMEOUT_IN_MS;

    do
    {
        FAPI_TRY(getScom(i_target, EQ_CPLT_STAT0, l_data64));
    }
    while((l_data64.getBit<8>() != 1) && ((--l_timeout) != 0));

    FAPI_ASSERT((l_timeout != 0),
                fapi2::PMPROC_L2CLKSTOP_TIMEOUT()
                .set_EQ_TARGET(i_target)
                .set_EQCPLTSTAT(l_data64),
                "L2 Clock Stop Timeout");

    FAPI_DBG("Check L2 clocks stopped");
    FAPI_TRY(getScom(i_target, EQ_CLOCK_STAT_SL, l_data64));

    FAPI_ASSERT((((~l_data64) & l_region_clock) == 0),
                fapi2::PMPROC_L2CLKSTOP_FAILED()
                .set_EQ_TARGET(i_target)
                .set_EQCLKSTAT(l_data64),
                "L2 Clock Stop Failed");
    FAPI_DBG("L2 clocks stopped now");

    // -------------------------------
    // Disable L2 clock sync
    // -------------------------------

    FAPI_DBG("Drop L2 clock sync enables via QPPM_EXCGCR[36,37]");
    FAPI_TRY(putScom(i_target, EQ_QPPM_EXCGCR_CLEAR, l_l2sync_clock));

    FAPI_DBG("Poll for L2 clock sync dones to drop via QPPM_QACSR[36,37]");
    l_timeout = (p9hcd::CYCLES_PER_MS / p9hcd::INSTS_PER_POLL_LOOP) *
                L2_CLK_SYNC_TIMEOUT_IN_MS;

    do
    {
        FAPI_TRY(getScom(i_target, EQ_QPPM_QACSR, l_data64));
    }
    while(((l_data64 & l_l2sync_clock)) && ((--l_timeout) != 0));

    FAPI_ASSERT((l_timeout != 0),
                fapi2::PMPROC_CACHECLKSYNCDROP_TIMEOUT().set_EQPPMQACSR(l_data64),
                "L2 Clock Sync Drop Timeout");
    FAPI_DBG("L2 clock sync dones dropped");

    // -------------------------------
    // Fence up
    // -------------------------------

    FAPI_DBG("Assert regional fences via CPLT_CTRL1[8/9]");
    FAPI_TRY(putScom(i_target, EQ_CPLT_CTRL1_OR, l_region_clock));


    // -------------------------------
    // Update QSSR
    // -------------------------------

    FAPI_DBG("Set EX as stopped in QSSR");
    FAPI_TRY(putScom(l_chip, PU_OCB_OCI_QSSR_OR,
                     ((uint64_t)i_select_ex << SHIFT64((l_attr_chip_unit_pos << 1) + 1))));


fapi_try_exit:

    FAPI_INF("<<p9_hcd_l2_stopclocks");
    return fapi2::current_err;
}

