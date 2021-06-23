/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_tod_init.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
// @file p10_tod_init.H
// @brief Procedures to initialize the TOD to 'running' state
//
// *HWP HW Maintainer    : Douglas Holtsinger <Douglas.Holtsinger@ibm.com>
// *HWP FW Maintainer    : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by      : HB,FSP
//
// -----------------------------------------------------------------------------

#ifndef _P10_TOD_INIT_H_
#define _P10_TOD_INIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_tod_utils.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_tod_init_FP_t) (
    const tod_topology_node*,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>*);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

extern "C" {

    /// @brief Initialize the TOD to 'running' state
    /// @param[in] i_tod_node Pointer to TOD topology (including FAPI targets)
    /// @param[out] o_failingTodProc Pointer to the fapi target, will be populated
    ///             with processor target unable to receive proper signals from OSC,
    ///             or the processor target where the TOD secondary topology failed.
    ///             Caller needs to look at this parameter only when p10_tod_init
    ///             fails and reason code indicated OSC or TOD secondary topology
    ///             failure. Defaulted to NULL.
    /// @return FAPI2_RC_SUCCESS if TOD topology is successfully initialized else
    ///         error
    fapi2::ReturnCode p10_tod_init(
        const tod_topology_node* i_tod_node,
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* o_failingTodProc = NULL);

} //extern "C"

#endif //_P10_TOD_INIT_H_
