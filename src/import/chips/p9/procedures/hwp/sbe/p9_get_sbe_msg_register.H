/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/sbe/p9_get_sbe_msg_register.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
/// @file  p9_get_sbe_msg_register.H
///
/// @brief Fetch the SBE messaging register
//------------------------------------------------------------------------------
// *HWP HW Owner        : Santosh Puranik <santosh.puranik@in.ibm.com>
// *HWP FW Owner        : Dhruvaraj Subhash Chandran <dhruvaraj@in.ibm.com>
// *HWP Team            : SBE
// *HWP Level           : 2
// *HWP Consumed by     : SE, Hostboot, Cronus
//------------------------------------------------------------------------------


#ifndef _P9_GET_SBE_MSG_REGISTER_H_
#define _P9_GET_SBE_MSG_REGISTER_H_

#include <fapi2.H>
#include "p9_sbe_ext_defs.H"


typedef fapi2::ReturnCode (*p9_get_sbe_msg_register_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        sbeMsgReg_t&);

///
/// @brief Returns the SBE messaging register
///
/// @param i_chip [in] Target to the proc chip
/// @param o_sbeReg [out] The SBE messaging register. Caller can interpret as sbeReg_t
///
/// @return FAPI2_RC_SUCCESS on success, else a FAPI2 RC indicating the failure
///
extern "C"
{
    fapi2::ReturnCode p9_get_sbe_msg_register(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip,
            sbeMsgReg_t& o_sbeReg);
}

#endif // _P9_GET_SBE_MSG_REGISTER_H_
