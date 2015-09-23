/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ocb_init.C $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file  p9_pm_ocb_init.C
/// @brief Setup and configure OCB channels
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS

///   Add support for linear window mode
///
///   High-level procedure flow:
///
///   - if mode = PM_INIT
///     - placeholder - currently do nothing
///   - if mode = PM_RESET
///     - reset each register in each OCB channel to its scan0-flush state
///   - if mode = PM_SETUP_PIB or PM_SETUP_ALL
///     - process parameters passed to procedure
///     - Set up channel control/status register based on passed parameters
///       (OCBCSRn)
///     - Set Base Address Register
///       - linear streaming & non-streaming => OCBARn
///       - push queue                       => OCBSHBRn  (only if PM_SETUP_ALL)
///       - pull queue                       => OCBSLBRn  (only if PM_SETUP_ALL)
///     - Set up queue control and status register (only if PM_SETUP_ALL)
///       - push queue  => OCBSHCSn
///       - pull queue  => OCBSLCSn
///
///   Procedure Prereq:
///   - System clocks are running
///

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_pm_ocb_init.H>

//------------------------------------------------------------------------------
//  Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Reset OCB Channels to default state (ie. scan-0 flush state)
///
/// @param [in]   i_target          Chip Target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode p9_pm_ocb_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Setup specified channel to type specified
///
/// @param [in]   i_target          Chip Target
/// @param [in]   i_ocb_chan        select channel 0-3 to set up
/// @param [in]   i_ocb_type        0=indirect  1=linear stream  2=circular push
///                                 3=circular pull
/// @param [in]   i_ocb_bar         32-bit channel base address(29 bits + "000")
/// @param [in]   i_ocb_upd_reg     0=update PIB registers only
///                                 1=update PIB & OCI registers
/// @param [in]   i_ocb_q_len       0-31 length of push or pull queue in
///                                 (queue_length + 1) * 8B
/// @param [in]   i_ocb_ouflow_en   0=disabled 1=enabled
/// @param [in]   i_ocb_itp_type    0=full  1=not full  2=empty  3=not empty
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode p9_pm_ocb_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9ocb::P9_OCB_CHAN_NUM    i_ocb_chan,
    const p9ocb::P9_OCB_CHAN_TYPE   i_ocb_type,
    const uint32_t                  i_ocb_bar,
    const p9ocb::P9_OCB_CHAN_REG    i_ocb_upd_reg,
    const uint8_t                   i_ocb_q_len,
    const p9ocb::P9_OCB_CHAN_OUFLOW i_ocb_ouflow_en,
    const p9ocb::P9_OCB_ITPTYPE     i_ocb_itp_type);

//------------------------------------------------------------------------------
//  Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_ocb_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE         i_mode,
    const p9ocb::P9_OCB_CHAN_NUM     i_ocb_chan,
    const p9ocb::P9_OCB_CHAN_TYPE    i_ocb_type,
    const uint32_t                   i_ocb_bar,
    const uint8_t                    i_ocb_q_len,
    const p9ocb::P9_OCB_CHAN_OUFLOW  i_ocb_ouflow_en,
    const p9ocb::P9_OCB_ITPTYPE      i_ocb_itp_type)
{
    FAPI_IMP("p9_pm_ocb_init Enter");

    FAPI_IMP("p9_pm_ocb_init EXIT");
    return fapi2::current_err;
}


fapi2::ReturnCode p9_pm_ocb_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9ocb::P9_OCB_CHAN_NUM    i_ocb_chan,
    const p9ocb::P9_OCB_CHAN_TYPE   i_ocb_type,
    const uint32_t                  i_ocb_bar,
    const p9ocb::P9_OCB_CHAN_REG    i_ocb_upd_reg,
    const uint8_t                   i_ocb_q_len,
    const p9ocb::P9_OCB_CHAN_OUFLOW i_ocb_ouflow_en,
    const p9ocb::P9_OCB_ITPTYPE     i_ocb_itp_type)
{
    FAPI_IMP("p9_pm_ocb_setup Enter");

    return fapi2::current_err;
} // end p9_pm_ocb_setup


fapi2::ReturnCode p9_pm_ocb_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("p9_pm_ocb_reset Enter");

    return fapi2::current_err;
}
