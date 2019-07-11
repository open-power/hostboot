/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_io_load_ppe.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_io_load_ppe.H
/// @brief Load image onto IO PPE SRAM
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///

#ifndef _P10_IO_LOAD_PPE_H_
#define _P10_IO_LOAD_PPE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*p10_io_load_ppe_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    void* const);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//
extern "C" {

///
/// @brief Load an image to IO PPE SRAM
/// This HWP is to be called by Hostboot/Cronus platforms to load IO PPE
/// and memory register images onto the IO PPE SRAM.
/// The images are stored in HW reference image, and platforms are responsible
/// for extracting and passing a pointer to the reference image to this HWP.
///
///   - Load I/O PPE image (RO/RW Sections) at offset:
///          FFFF_0000 (80kB)
///   - Load same Memory reg image at offsets:
///          FFFF_EC00 == Mem Regs Thread 0 (1kB)
///          FFFF_F000 == Mem Regs Thread 1 (1kB)
///          FFFF_F400 == Mem Regs Thread 2 (1kB)
///          FFFF_F800 == Mem Regs Thread 3 (1kB)
///          FFFF_FC00 == Mem Regs Thread 4 (1kB)
///
/// @param[in]  i_target            Reference to processor chip target
/// @param[in]  i_hw_image          Pointer to HW reference image data
///
/// @return FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p10_io_load_ppe(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        void* const i_hw_image);

} //extern "C"

#endif //_P10_IO_LOAD_PPE_H_
