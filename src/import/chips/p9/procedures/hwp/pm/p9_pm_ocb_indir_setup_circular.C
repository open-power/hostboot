/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_ocb_indir_setup_circular.C $ */
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
/// @file  p9_pm_ocb_indir_setup_circular.C
/// @brief  Configure OCB Channels for Circular Push or Pull Mode
///
// *HWP HWP Owner       : Amit Kumar <akumar@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS


/// High-level procedure flow:
/// @verbatim
///  Setup specified channel to push or pull circular mode by calling
///  proc proc_ocb_init
///
///  Procedure Prereq:
///     - System clocks are running
/// @endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_pm_ocb_indir_setup_circular.H>

fapi2::ReturnCode p9_pm_ocb_indir_setup_circular(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9ocb::PM_OCB_CHAN_NUM i_ocb_chan,
    const p9ocb::PM_OCB_CHAN_TYPE i_ocb_type)
{
    FAPI_IMP("p9_pm_ocb_indir_setup_circular Enter");
    FAPI_DBG("For channel %x as type %x", i_ocb_chan, i_ocb_type);

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    FAPI_EXEC_HWP(l_rc,
                  p9_pm_ocb_init,
                  i_target,
                  p9pm::PM_SETUP_PIB,
                  i_ocb_chan,
                  i_ocb_type,
                  0, // ocb_bar
                  0, // ocb_q_len
                  p9ocb::OCB_Q_OUFLOW_NULL,
                  p9ocb::OCB_Q_ITPTYPE_NULL);

    FAPI_IMP("p9_pm_ocb_indir_setup_circular Exit");
    return l_rc;
}
