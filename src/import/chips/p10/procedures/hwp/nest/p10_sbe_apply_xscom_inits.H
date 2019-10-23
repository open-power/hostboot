/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_apply_xscom_inits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_sbe_apply_xscom_inits.H
/// @brief Program ADU to apply set of register inits via XSCOM
///

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by  : SBE
//

#ifndef _P10_SBE_APPLY_XSCOM_INITS_H_
#define _P10_SBE_APPLY_XSCOM_INITS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
//Struct to hold the list of XSCOM address and the value to be applied
struct xscomsInits_t
{
    uint64_t address;
    uint64_t data;
};

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_sbe_apply_xscom_inits_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const size_t,
    const void*);
//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

//
// @brief Configures MC/MCD BAR resources on all sockets via XSCOM, as part
//        of HB cache contained exit sequence
//
// @param[in] i_target          Reference to processor chip target
// @param[in] i_xscomPairSize   Number of XSCOM register address-data pair to
//                              be initialized.
// @param[in] i_pxscomInit      Pointer to the data set of address-data pair
//
// @return fapi2::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
//
    fapi2::ReturnCode p10_sbe_apply_xscom_inits(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const size_t i_xscomPairSize,
        const void* i_pxscomInit);
} // extern "C"

#endif // _P10_SBE_APPLY_XSCOM_INITS_H_
