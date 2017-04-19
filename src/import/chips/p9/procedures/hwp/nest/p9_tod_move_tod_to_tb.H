/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_move_tod_to_tb.H $ */
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
//------------------------------------------------------------------------------
//
/// @file p9_tod_move_tod_to_tb.H
/// @brief Procedures to initialize the TOD to 'running' state
///
// *HWP HWP Owner: Nick Klazynski jklazyns@us.ibm.com
// *HWP HWP Owner: Joachim Fenkes fenkes@de.ibm.com
// *HWP FW Owner: Manish Chowdhary manichow@in.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: Cronus only
//
// -----------------------------------------------------------------------------

#ifndef _P9_TOD_MOVE_TOD_TO_TB_H_
#define _P9_TOD_MOVE_TOD_TO_TB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_tod_utils.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_tod_move_tod_to_tb_FP_t) (
    const tod_topology_node*,
    const uint8_t,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>*);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

extern "C" {

/// @brief HWP entry point -- move_tod_to_tb
/// @param[in] i_tod_node Reference to TOD topology (including FAPI targets)
/// @param[in] i_thread_num The thread number to complete the transaction on
/// @param[in] i_failingTodProc Pointer to the fapi target, will be populated
///            with processor processor target which is not able ot receive
///            proper signals from OSC. Caller needs to look at this parameter
///            only when p9_tod_move_tod_to_tb fails and reason code indicated
///            OSC failure.  Defaulted to NULL.
/// @return FAPI_RC_SUCCESS if TOD topology is successfully initialized else
///         error
    fapi2::ReturnCode p9_tod_move_tod_to_tb(
        const tod_topology_node* i_tod_node,
        const uint8_t i_thread_num,
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* o_failingTodProc = NULL);

} //extern "C"

#endif //_P9_TOD_MOVE_TOD_TO_TB_H_

