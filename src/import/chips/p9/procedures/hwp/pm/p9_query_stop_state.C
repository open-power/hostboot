/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_query_stop_state.C $            */
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
///
/// @file p9_query_stop_state.C
/// @brief Determine the state of cores, L2, and L3 of the targeted EX
///        Set ATTRs to know the scommable/scannable state of the logic
///        Further operations in the dump flow will only operate on scommable
///        portions of the targets.   FW/Platform is responsible for checking these
///        states before calling HWPs
///
// *HWP HWP Owner: Brian Vanderpool <vanderp@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
///
///
/// @verbatim
/// High-level procedure flow:
///     - For each EX, check the PPMC stop state history to know the state
///       of the core.  Check the PPMQ stop state history to know the state of L2/L3
///
///       Set ATTRs to know the scommable/scannable state of the logic
///          L2_IS_SCOMABLE      indicates the L2 region has clocks running and scommable
///          L3_IS_SCOMABLE      indicates the L3 region has clocks running and scommable
///          C0_EXEC_IS_SCOMABLE indicates the execution units in core 0 have clocks running and scommable
///          C1_EXEC_IS_SCOMABLE indicates the execution units in core 1 have clocks running and scommable
///          C0_PC_IS_SCOMABLE   indicates the core pervasive unit in core 0 has clocks running and scommable
///          C1_PC_IS_SCOMABLE   indicates the core pervasive unit in core 1 has clocks running and scommable
///          L2_IS_SCANABLE      indicates L2 has power and has valid latch state that could be scanned
///          L3_IS_SCANABLE      indicates L3 has power and has valid latch state that could be scanned
///          C0_IS_SCANABLE      indicates core 0 has power and has valid latch state that could be scanned
///          C1_IS_SCANABLE      indicates core 1 has power and has valid latch state that could be scanned
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p9_query_stop_state.H"

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

fapi2::ReturnCode
p9_query_stop_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target)
{

    fapi2::buffer<uint8_t>  l_data8;

    FAPI_INF("> p9_query_stop_state...");

    // The list of attributes this procedure will set.
    // For level 1 delivery, set them all to 1.

    l_data8 = 1;

    // Is Scomable attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L2_IS_SCOMABLE,      i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L3_IS_SCOMABLE,      i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C0_EXEC_IS_SCOMABLE, i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C1_EXEC_IS_SCOMABLE, i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C0_PC_IS_SCOMABLE,   i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C1_PC_IS_SCOMABLE,   i_ex_target, l_data8));

    // Is Scanable attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L2_IS_SCANABLE,      i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L3_IS_SCANABLE,      i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C0_IS_SCANABLE,      i_ex_target, l_data8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C1_IS_SCANABLE,      i_ex_target, l_data8));

fapi_try_exit:
    FAPI_INF("< p9_query_stop_state...");
    return fapi2::current_err;
}
