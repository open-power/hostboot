/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_start.H $                 */
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
/// ----------------------------------------------------------------------------
/// @file  p9_htm_start.H
///
/// @brief Start the HTM collection from a processor chip
///
/// The purpose of this procedure is to start the HTM collection from a
/// processor chip.
///
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

#ifndef _P9_HTM_START_H_
#define _P9_HTM_START_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_htm_start_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------

// Timeout count for HTM control
const uint32_t PROC_HTM_CTRL_TIMEOUT_COUNT   = 20;

// HTM operations delay times for HW/sim
const uint32_t PROC_HTM_CTRL_HW_NS_DELAY     = 50000;
const uint32_t PROC_HTM_CTRL_SIM_CYCLE_DELAY = 50000;

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
///
/// @brief p9_htm_start procedure
///
/// This HWP is to trigger the HTM collection process.
/// p9_htm_setup must be called before running this HWP.
///
/// @param[in]    i_target   Reference to TARGET_TYPE_PROC_CHIP target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
extern "C"
{

    fapi2::ReturnCode p9_htm_start(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif  // _P9_HTM_START_H_
