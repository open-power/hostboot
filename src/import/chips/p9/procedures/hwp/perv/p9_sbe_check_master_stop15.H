/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_sbe_check_master_stop15.H $   */
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
//------------------------------------------------------------------------------
/// @file  p9_sbe_check_master_stop15.H
///
///------------------------------------------------------------------------------
// *HWP HWP Owner   : Greg Still <stillgsg@us.ibm.com>
// *HWP FW Owner    : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team        : PM
// *HWP Level       : 2
// *HWP Consumed by : SBE
//------------------------------------------------------------------------------


#ifndef _P9_SBE_CHECK_MASTER_STOP15_H_
#define _P9_SBE_CHECK_MASTER_STOP15_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_sbe_check_master_stop15_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_CORE>&);


/// @brief Check if the targeted core (master) is fully in STOP15
///
/// @param[in]  i_target   Reference to TARGET_TYPE_CORE target
///
/// @return     FAPI2_RC_SUCCESS if success
/// @return     STOP15_PENDING  STOP 15 not reached, but no error
///             HW state (still in progress)
/// @return     Others indicate hardware failur
///
extern "C"
{
    fapi2::ReturnCode
    p9_sbe_check_master_stop15(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target);
}

#endif  // _P9_SBE_CHECK_MASTER_STOP15_H_
