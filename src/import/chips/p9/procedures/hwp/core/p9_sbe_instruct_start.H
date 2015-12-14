/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/core/p9_sbe_instruct_start.H $        */
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
/// @file p9_sbe_instruct_start.C
/// @brief  Placeholder for overrides needed to step the core from cache-contained execution to expand to memory
///
// *HWP HWP Owner: Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

#ifndef _PROC_SBE_INSTRUCT_START_H_
#define _PROC_SBE_INSTRUCT_START_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_thread_control.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_sbe_instruct_start_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& );

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
///
/// @brief Calls thread_control to start thread 0
/// @param[in] i_target Reference to core target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, RC_P9_THREAD_CONTROL_START_FAIL if start command failed,
///         else error code
///
    fapi2::ReturnCode p9_sbe_instruct_start(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target);

} // extern "C"

#endif // _PROC_SBE_INSTRUCT_START_H_
