/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_npu_scominit.H $              */
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
/// @file p9_npu_scominit.C
/// @brief Apply SCOM overrides for the NPU unit via an init file
///
// *HWP HWP Owner: Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB

#ifndef _PROC_NPU_SCOMINIT_H_
#define _PROC_NPU_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_npu_scominit_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
///
/// @brief Apply SCOM overrides for the NPU unit via an init file
/// @param[in] i_target Reference to processor chip target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_npu_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _PROC_NPU_SCOMINIT_H_
