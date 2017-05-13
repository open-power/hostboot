/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_query_stop_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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

// ----------------------------------------------------------------------
// Data Structure Definitions
// ----------------------------------------------------------------------

typedef struct
{
    uint8_t  l2_hasclocks;
    uint8_t  l3_hasclocks;
    uint8_t  c0_exec_hasclocks;   // these could be put in an array, but is broken out since attributes are separate
    uint8_t  c1_exec_hasclocks;
    uint8_t  c0_pc_hasclocks;
    uint8_t  c1_pc_hasclocks;

    uint8_t  l2_haspower;
    uint8_t  l3_haspower;
    uint8_t  c0_haspower;
    uint8_t  c1_haspower;
} stop_attrs_t;

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief Determine the state of cores, L2, and L3 of the targeted EX, and
///        put the results into data structure stop_attrs_t.
///
/// @param[in]  i_target       EX target
/// @param[out] o_stop_attrs   Output data structure to hold the state value.
///
/// @return FAPI2_RC_SUCCESS if success, else error code.

fapi2::ReturnCode
query_stop_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target,
    stop_attrs_t& o_stop_attrs);

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_query_stop_state_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EX>&);

extern "C"
{

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
