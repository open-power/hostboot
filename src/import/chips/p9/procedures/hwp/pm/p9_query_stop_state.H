/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_query_stop_state.H $            */
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

/// @file  p9_query_stop_state.H
/// @brief Determine the state of cores, L2, and L3 of the targeted EX
///        Set ATTRs to know if the logic has clocks or power (scomable or scanable)
///        Further operations in the dump flow will only operate on scommable
///        portions of the targets.   FW/Platform is responsible for checking these
///        states before calling HWPs
///
// *HWP HWP Owner: Brian Vanderpool <vanderp@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS
///
///-----------------------------------------------------------------------------

#ifndef _P9_QUERY_STOP_STATE_H_
#define _P9_QUERY_STOP_STATE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_pm.H>
#include <p9_quad_scom_addresses.H>
#include <p9_hcd_common.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_query_stop_state_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EX>&);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief Determine the state of cores, L2, and L3 of the targeted EX and set ATTRS if powered up and clocking
///
/// @param[in] i_target    EX target
/// @attr
/// @attritem  ATTR_L2_HASCLOCKS      - Indicates the L2 region has clocks running and scommable
/// @attritem  ATTR_L3_HASCLOCKS      - Indicates the L3 region has clocks running and scommable
/// @attritem  ATTR_C0_EXEC_HASCLOCKS - Indicates the execution units in core 0 have clocks running and scommable
/// @attritem  ATTR_C1_EXEC_HASCLOCKS - Indicates the execution units in core 1 have clocks running and scommable
/// @attritem  ATTR_C0_PC_HASCLOCKS   - Indicates the core pervasive unit in core 0 has clocks running and scommable
/// @attritem  ATTR_C1_PC_HASCLOCKS   - Indicates the core pervasive unit in core 1 has clocks running and scommable
/// @attritem  ATTR_L2_HASPOWER      - Indicates L2 has power and has valid latch state that could be scanned
/// @attritem  ATTR_L3_HASPOWER      - Indicates L3 has power and has valid latch state that could be scanned
/// @attritem  ATTR_C0_HASPOWER      - Indicates core 0 has power and has valid latch state that could be scanned
/// @attritem  ATTR_C1_HASPOWER      - Indicates core 1 has power and has valid latch state that could be scanned
///
/// @return FAPI2_RC_SUCCESS if success, else error code.

    fapi2::ReturnCode
    p9_query_stop_state(
        const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target);

} // extern "C"

#endif // _P9_QUERY_STOP_STATE_H_
