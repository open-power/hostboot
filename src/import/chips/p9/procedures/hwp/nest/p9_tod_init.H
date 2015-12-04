/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_init.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
//-----------------------------------------------------------------------------------
//
/// @file p9_tod_init.H
/// @brief Procedures to initialize the TOD to 'running' state
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by:
// ----------------------------------------------------------------------------------
//
// *! ADDITIONAL COMMENTS :
// *!
// *!
// *!
//-----------------------------------------------------------------------------------

#ifndef _P9_TOD_INIT_H_
#define _P9_TOD_INIT_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

#include <fapi2.H>
#include "p9_tod_utils.H"

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_tod_init_FP_t) (const tod_topology_node*,
                     fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* );

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Initialized the TOD to 'running' state
/// @param[in] i_tod_node => Reference to TOD topology (FAPI targets are included in this)
/// @param[in] i_failingTodProc => Pointer to the fapi target, the memory location addressed by this parameter will be populated with processor target which is not able ot receive proper signals from OSC. Caller needs to look at this parameter only when p9_tod_init fail and reason code indicated OSC failure. Defaulted to NULL.
/// @return FAPI_RC_SUCCESS if TOD topology is successfully initialized else FAPI or ECMD error is sent through
    fapi2::ReturnCode p9_tod_init(
        const tod_topology_node* i_tod_node,
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>* i_target = NULL);

} //extern "C"

#endif //_P9_TOD_INIT_H_

