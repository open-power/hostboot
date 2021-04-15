/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/fapi2/hbbl_plat_hw_access.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file hbbl_plat_hw_access.C
///
/// @brief Implements hardware-access functions for the bootloader platform
///        layer.
///

#include <return_code.H>
#include <buffer.H>
#include <target.H>
#include <target_types.H>

#include <plat_hw_access.H>
#include <bl_xscom.H>

namespace fapi2
{

// Operational mode for scom operations (ignore errors, wakeup core, etc.)
OpModes opMode = NORMAL;

// Bitmap of PIB errors to ignore during a PIB oeration
uint8_t pib_err_mask = 0x00;

// Bits 7-15 are address portion
const uint32_t CFAM_ADDRESS_MASK = 0x1FF;

// Bits 0-6 are engine offset
const uint32_t CFAM_ENGINE_OFFSET = 0xFE00;

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

/// @brief Platform-level implementation called by getScom()
ReturnCode platGetScom(const Target<TARGET_TYPE_ALL>& i_target,
                       const uint64_t i_address,
                       buffer<uint64_t>& o_data)
{
    size_t l_readSize = sizeof(uint64_t);
    ReturnCode l_rc = XSCOM::xscomPerformOp(DeviceFW::READ,
                                            o_data.pointer(),
                                            l_readSize,
                                            i_address);
    return l_rc;
}

/// @brief Platform-level implementation called by putScom()
ReturnCode platPutScom(const Target<TARGET_TYPE_ALL>& i_target,
                       const uint64_t i_address,
                       const buffer<uint64_t> i_data)
{
    size_t l_writeSize = sizeof(uint64_t);
    ReturnCode l_rc = XSCOM::xscomPerformOp(DeviceFW::WRITE,
                                            const_cast<uint64_t*>(i_data.pointer()),
                                            l_writeSize,
                                            i_address);
    return l_rc;
}

} // End namespace
