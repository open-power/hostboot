/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/cache/p9_hcd_cache_stopclocks.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file  p9_hcd_cache_stopclocks.C
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
#include "p9_hcd_cache_stopclocks.H"

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P9_HCD_CACHE_STOPCLOCKS_CONSTANTS
{
    CACHE_CLK_STOP_TIMEOUT_IN_MS = 1
};

//------------------------------------------------------------------------------
// Procedure: Quad Clock Stop
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_hcd_cache_stopclocks(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    const p9hcd::P9_HCD_CLK_CTRL_CONSTANTS      i_select_regions,
    const p9hcd::P9_HCD_EX_CTRL_CONSTANTS       i_select_ex)
{
    FAPI_INF(">>p9_hcd_cache_stopclocks: regions[%x] ex[%d]",
             i_select_regions, i_select_ex);
    fapi2::buffer<uint64_t>                        l_data64;
    uint32_t                                       l_timeout;
    uint64_t                                       l_l3mask_pscom = 0;
    uint8_t                                        l_attr_chip_unit_pos = 0;
    uint8_t                                        l_attr_vdm_enable;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    auto l_perv = i_target.getParent<fapi2::TARGET_TYPE_PERV>();
    auto l_chip = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_ENABLE,    l_sys,
                           l_attr_vdm_enable));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_perv,
                           l_attr_chip_unit_pos));
    l_attr_chip_unit_pos = l_attr_chip_unit_pos - p9hcd::PERV_TO_QUAD_POS_OFFSET;

    if (i_select_regions & p9hcd::CLK_REGION_EX0_L3)
    {
        l_l3mask_pscom |= (BIT64(4) | BIT64(6) | BIT64(8));
    }

    if (i_select_regions & p9hcd::CLK_REGION_EX1_L3)
    {
        l_l3mask_pscom |= (BIT64(5) | BIT64(7) | BIT64(9));
    }

    // -----------------------------
    // Prepare to stop cache clocks
    // -----------------------------
    /// @todo RTC158181 disable l2 snoop? disable lco? assert refresh quiesce?

    FAPI_DBG("Assert L3 pscom masks via RING_FENCE_MASK_LATCH_REG[4-9]");
    FAPI_TRY(putScom(i_target, EQ_RING_FENCE_MASK_LATCH_REG, l_l3mask_pscom));

    FAPI_DBG("Assert chiplet fence via NET_CTRL0[18]");
    FAPI_TRY(putScom(i_target, EQ_NET_CTRL0_WOR, MASK_SET(18)));

    // -------------------------------
    // Stop L2 clocks
    // -------------------------------

    FAPI_EXEC_HWP(fapi2::current_err,
                  p9_hcd_l2_stopclocks,
                  i_target, i_select_ex);

    // -------------------------------
    // Stop cache clocks
    // -------------------------------

    FAPI_DBG("Clear all SCAN_REGION_TYPE bits");
    FAPI_TRY(putScom(i_target, EQ_SCAN_REGION_TYPE, MASK_ZERO));

    FAPI_DBG("Stop cache clocks via CLK_REGION");
    l_data64 = (p9hcd::CLK_STOP_CMD  |
                i_select_regions     |
                p9hcd::CLK_THOLD_ALL);
    FAPI_TRY(putScom(i_target, EQ_CLK_REGION, l_data64));

    FAPI_DBG("Poll for cache clocks stopped via CPLT_STAT0[8]");
    l_timeout = (p9hcd::CYCLES_PER_MS / p9hcd::INSTS_PER_POLL_LOOP) *
                CACHE_CLK_STOP_TIMEOUT_IN_MS;

    do
    {
        FAPI_TRY(getScom(i_target, EQ_CPLT_STAT0, l_data64));
    }
    while((l_data64.getBit<8>() != 1) && ((--l_timeout) != 0));

    FAPI_ASSERT((l_timeout != 0),
                fapi2::PMPROC_CACHECLKSTOP_TIMEOUT()
                .set_EQ_TARGET(i_target)
                .set_EQCPLTSTAT(l_data64),
                "Cache Clock Stop Timeout");

    FAPI_DBG("Check cache clocks stopped");
    FAPI_TRY(getScom(i_target, EQ_CLOCK_STAT_SL, l_data64));

    FAPI_ASSERT((((~l_data64) & i_select_regions) == 0),
                fapi2::PMPROC_CACHECLKSTOP_FAILED()
                .set_EQ_TARGET(i_target)
                .set_EQCLKSTAT(l_data64),
                "Cache Clock Stop Failed");
    FAPI_DBG("Cache clocks stopped now");

    // -------------------------------
    // Fence up
    // -------------------------------

    FAPI_DBG("Assert vital fence via CPLT_CTRL1[3]");
    FAPI_TRY(putScom(i_target, EQ_CPLT_CTRL1_OR, MASK_SET(3)));

    FAPI_DBG("Assert regional fences via CPLT_CTRL1[4-14]");
    FAPI_TRY(putScom(i_target, EQ_CPLT_CTRL1_OR, i_select_regions));

    // -------------------------------
    // Disable VDM
    // -------------------------------

    if (l_attr_vdm_enable == fapi2::ENUM_ATTR_VDM_ENABLE_ON)
    {
        FAPI_DBG("Drop vdm enable via QPPM_VDMCR[0]");
        FAPI_TRY(putScom(i_target, EQ_PPM_VDMCR_CLEAR, MASK_SET(0)));
    }

    // -------------------------------
    // Shutdown edram
    // -------------------------------
    // QCCR[0/4] EDRAM_ENABLE_DC
    // QCCR[1/5] EDRAM_VWL_ENABLE_DC
    // QCCR[2/6] L3_EX0/1_EDRAM_VROW_VBLH_ENABLE_DC
    // QCCR[3/7] EDRAM_VPP_ENABLE_DC

    if (i_select_regions & p9hcd::CLK_REGION_EX0_REFR)
    {
        FAPI_DBG("Sequence EX0 EDRAM disables via QPPM_QCCR[0-3]");
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(3)));
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(2)));
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(1)));
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(0)));
    }

    if (i_select_regions & p9hcd::CLK_REGION_EX1_REFR)
    {
        FAPI_DBG("Sequence EX1 EDRAM disables via QPPM_QCCR[4-7]");
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(7)));
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(6)));
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(5)));
        FAPI_TRY(putScom(i_target, EQ_QPPM_QCCR_WCLEAR, MASK_SET(4)));
    }

    // -------------------------------
    // Update QSSR and STOP history
    // -------------------------------

    FAPI_DBG("Set cache as stopped in QSSR");
    FAPI_TRY(putScom(l_chip, PU_OCB_OCI_QSSR_OR,
                     BIT64(l_attr_chip_unit_pos + 14)));

    FAPI_DBG("Set cache as stopped in STOP history register");
    FAPI_TRY(putScom(i_target, EQ_PPM_SSHSRC, (BIT64(0) | BIT64(13))));

fapi_try_exit:

    FAPI_INF("<<p9_hcd_cache_stopclocks");
    return fapi2::current_err;
}

