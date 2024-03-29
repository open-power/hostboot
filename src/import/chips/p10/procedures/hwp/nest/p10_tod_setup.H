/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_tod_setup.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
// @file p10_tod_setup.H
// @brief Procedures to configure the TOD topology
//
// *HWP HW Maintainer    : Douglas Holtsinger <Douglas.Holtsinger@ibm.com>
// *HWP FW Maintainer    : Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by      : HB,FSP
//
// -----------------------------------------------------------------------------

#ifndef _P10_TOD_SETUP_H_
#define _P10_TOD_SETUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_tod_utils.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_tod_setup_FP_t) (
    tod_topology_node*,
    const p10_tod_setup_tod_sel,
    const p10_tod_setup_osc_sel);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

extern "C" {

/// @brief Setup the TOD network
/// @param[in,out] i_tod_node Reference to TOD topology (included FAPI targets)
/// @param[in] i_tod_sel Specifies the topology to configure
/// @param[in] i_osc_sel Specifies the oscillator to use for the master
/// @return FAPI2_RC_SUCCESS if TOD topology is successfully configured else
///         error
    fapi2::ReturnCode p10_tod_setup(
        tod_topology_node* i_tod_node,
        const p10_tod_setup_tod_sel i_tod_sel,
        const p10_tod_setup_osc_sel i_osc_sel);

} //extern "C"

#endif //_P10_TOD_SETUP_H_
