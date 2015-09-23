/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ocb_indir_setup_linear.C $  */
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
/// @file p8_ocb_indir_setup_linear.C
/// @brief  Configure OCB Channel for Linear Streaming or Non-streaming mode

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner:
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

/// High-level procedure flow:
/// @verbatim
///  Setup specified channel to linear streaming or non-streaming mode by
///  calling proc proc_ocb_init
///
///  Procedure Prereq:
///     - System clocks are running
/// @endverbatim
///
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_pm.H>
#include <p9_pm_ocb_indir_setup_linear.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
fapi2::ReturnCode p9_pm_ocb_indir_setup_linear(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p9ocb::P9_OCB_CHAN_NUM  i_ocb_chan,
    p9ocb::P9_OCB_CHAN_TYPE i_ocb_type,
    const uint32_t      i_ocb_bar)
{
    FAPI_IMP("Entering...");
    FAPI_DBG("For channel %x as type %x, OCB Bar %x",
             i_ocb_chan, i_ocb_type, i_ocb_bar);

    return fapi2::FAPI2_RC_SUCCESS;
}
