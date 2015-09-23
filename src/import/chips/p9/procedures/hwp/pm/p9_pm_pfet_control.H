/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pfet_control.H $  */
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
/// @file p9_pm_pfet_control.C
/// @brief Perform override operations to the EX PFET headers
///
/// *HWP HWP Owner: Greg Still  <stillgs@us.ibm.com>
/// *HWP FW  Owner: Sunil Kumar <skumar8j@in.ibm.com>
/// *HWP Team: PM
/// *HWP Level: 1
/// *HWP Consumed by: HS
///

#ifndef _P9_PM_PFETCTL_H_
#define _P9_PM_PFETCTL_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p9_pm_pfet_types.H"
#include "fapi2.H"
#include "p9_pm.H"

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_pfet_control_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const uint8_t,
    PMPFETTYPE_C::pfet_dom_t,
    PMPFETTYPE_C::pfet_force_t);

extern "C" {

/// @brief Controls the pfets for the specified EX chiplet
///
/// @param[in] i_target    Processor Chip target
/// @param[in] i_ex_number EX number
/// @param[in] i_domain    Domain: BOTH, ECO, CORE
/// @param[in] i_op        Operation:
///                        VON: Turns a chiplet domain on, VCS then VDD
///                        VOFF: Turns a chiplet domain off, VDD then VCS
//                         VOFF_OVERRIDE: Turns a chiplet domain off with
///                                         controller override
///
/// @return SUCCESS incase of success,
/// @return BAD_RETURN_CODE otherwise
    fapi2::ReturnCode p9_pm_pfet_control(const
                                         fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                         const uint8_t i_ex_number,
                                         PMPFETTYPE_C::pfet_dom_t i_domain,
                                         PMPFETTYPE_C::pfet_force_t i_op);

} // extern "C"

#endif // _P9_PM_PFETCTL_H_
