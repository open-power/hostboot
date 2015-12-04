/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_setup.H $      */
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
/// @file p9_tod_setup.H
/// @brief Procedures to configure the TOD topology
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

#ifndef _P9_TOD_SETUP_H_
#define _P9_TOD_SETUP_H_

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
(*p9_tod_setup_FP_t) (tod_topology_node*,
                      const p9_tod_setup_tod_sel,
                      const p9_tod_setup_osc_sel);

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

extern "C" {

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Gets the value in the TFMR register
/// @param[in] i_target       => P9 chip target
/// @param[out] o_tfmr_val    => Value that is in the TFMR register
/// @return FAPI_RC_SUCCESS if TFMR read is successful else FAPI or ECMD error is sent through
    fapi2::ReturnCode p9_tod_setup(
        tod_topology_node* i_tod_node,
        const p9_tod_setup_tod_sel i_tod_sel,
        const p9_tod_setup_osc_sel i_osc_sel);

} //extern "C"

#endif //_P9_TOD_SETUP_H_

