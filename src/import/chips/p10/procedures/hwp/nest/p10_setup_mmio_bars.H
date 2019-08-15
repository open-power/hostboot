/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_setup_mmio_bars.H $ */
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
/// @file p10_setup_mmio_bars.H
/// @brief Configure nest unit MMIO base address registers (FAPI2)
///
/// Program nest unit MMIO BAR registers, driven by attributes representing system
/// memory map.
///

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

#ifndef _P10_SETUP_MMIO_BARS_H_
#define _P10_SETUP_MMIO_BARS_H_


//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>


//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_setup_mmio_bars_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);


extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

///
/// @brief Program nest unit MMIO BAR registers, driven by attributes representing
///        system memory map
///
/// @param[in] i_target => Processor chip target
///
/// @return FAPI_RC_SUCCESS if the setup completes successfully, else error
//
    fapi2::ReturnCode p10_setup_mmio_bars(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} //extern"C"

#endif //_P10_SETUP_MMIO_BARS_H_
