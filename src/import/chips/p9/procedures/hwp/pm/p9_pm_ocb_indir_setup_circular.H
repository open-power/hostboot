/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ocb_indir_setup_circular.H $ */
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
/// @file  p9_pm_ocb_indir_setup_circular.H
/// @brief  Configure OCB Channels for Circular Push or Pull Mode
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP Backup HWP Owner:
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS


#ifndef _P9_PM_OCB_INDIR_SETUP_CIRCULAR_H_
#define _P9_PM_OCB_INDIR_SETUP_CIRCULAR_H_

#include <fapi2.H>
#include <p9_pm_ocb_init.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_ocb_indir_setup_circular_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 p9ocb::PM_OCB_CHAN_NUM,
 p9ocb::PM_OCB_CHAN_TYPE);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// @brief Configure OCB Channels for Circular Push or Pull Mode
/// @param[in] i_target Chip Target
/// @param[in] i_ocb_chan Select channel 0-3 to set up
/// @param[in] i_ocb_type Circular push;  circular pull
/// @return FAPI2_RC_SUCCESS on success, error otherwise

    fapi2::ReturnCode p9_pm_ocb_indir_setup_circular(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        p9ocb::PM_OCB_CHAN_NUM i_ocb_chan,
        p9ocb::PM_OCB_CHAN_TYPE i_ocb_type);

} // extern "C"

#endif
