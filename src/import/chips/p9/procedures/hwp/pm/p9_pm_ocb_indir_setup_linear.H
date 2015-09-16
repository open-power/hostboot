/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ocb_indir_setup_linear.H $  */
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
/// @file p9_pm_ocb_indir_setup_linear.C
/// @brief  Configure OCB Channel for Linear Streaming or Non-streaming mode

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner:
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

#ifndef _P9_PM_OCB_INDIR_SETUP_LINEAR_H_
#define _P9_PM_OCB_INDIR_SETUP_LINEAR_H_

#include <fapi2.H>
#include <p9_pm_ocb_init.H>

typedef fapi2::ReturnCode (*p9_pm_ocb_indir_setup_linear_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 p9ocb::PM_OCB_CHAN_NUM,
 p9ocb::PM_OCB_CHAN_TYPE,
 const uint32_t);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// @brief  Configure OCB Channel for Linear Streaming or Non-streaming mode
/// @param[in]  i_target   Chip Target
/// @param[in]  i_ocb_chan select channel 0-3 to set up      (see p8_ocb_init.H)
/// @param[in]  i_ocb_type linear streaming or non-streaming (see p8_ocb_init.H)
/// @param[in]  i_ocb_bar  32-bit channel base address (29 bits + "000")
/// @return FAPI2_RC_SUCCESS on success, else error.

    fapi2::ReturnCode p9_pm_ocb_indir_setup_linear(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        p9ocb::PM_OCB_CHAN_NUM  i_ocb_chan,
        p9ocb::PM_OCB_CHAN_TYPE i_ocb_type,
        const uint32_t      i_ocb_bar);

} // extern "C"

#endif
