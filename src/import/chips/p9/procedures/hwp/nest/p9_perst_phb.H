/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_perst_phb.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
///
/// @file p9_perst_phb.H
/// @brief Procedure to assert/deassert PERST from PHB. (FAPI2)
///
// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: FSP

#ifndef _P9_PERST_PHB_H_
#define _P9_PERST_PHB_H_

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
#ifndef _PERST_ACTION_
#define _PERST_ACTION_

enum PERST_ACTION
{
    ACTIVATE_PERST,     //Drive PERST signal active from the PHB. Put in to Reset.
    DEACTIVATE_PERST    //Drive PERST signal inactive from the PHB. Take out of Reset.
};
#endif

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_phb_hv_utils.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_perst_phb_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PHB>&, const PERST_ACTION);

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------
///
/// @brief Assert/deassert PERST signal from PHB.
///
/// @param[in] i_target         => PHB target
/// @param[in] i_perst_action   => Input ACTIVATE or DEACTIVATE
///                                to control PERST signal from PHB.
///
/// @return FAPI_RC_SUCCESS if the PERST action completes successfully, else
///         FAPI2 error code.
///
    fapi2::ReturnCode p9_perst_phb(const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
                                   const PERST_ACTION i_perst_action);

} //extern"C"

#endif //_P9_PERST_PHB_H_
