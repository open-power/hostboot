/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_init_mem_encryption.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
/// @file p10_init_mem_encryption.H
/// @brief Write 0's to full address space for memory encryption initialization
///

// *HWP HWP Owner: Lilith Hale Lilith.Hale@ibm.com
// *HWP FW Owner:
// *HWP Consumed by: cronus

#ifndef _p10_init_mem_encryption_H_
#define _p10_init_mem_encryption_H_


//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_init_mem_encryption_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>);

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

extern "C" {

///
/// @brief Write 0's to full address space for memory encryption initialization
///
/// @param[in] i_target => Processor chip target
///
/// @return FAPI_RC_SUCCESS if the setup completes successfully, else error
//
    fapi2::ReturnCode p10_init_mem_encryption(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target);

} //extern"C"

#endif //_p10_init_mem_encryption_H_
