/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_getputsram_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file p10_getputsram_utils.H
///
/// @brief Common code to support get/putsram HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: N/A
/// *HWP Consumed by: HB, Cronus, SBE
///
#ifndef _P10_GETPUTSRAM_UTILS_H_
#define _P10_GETPUTSRAM_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pm_ocb_init.H>

//------------------------------------------------------------------------------
// Constants definitions
//------------------------------------------------------------------------------
const uint32_t PAU0_PERV_CHIPLET_ID  = 0x10;
const uint32_t PAU3_PERV_CHIPLET_ID  = 0x13;
const uint32_t EQ0_PERV_CHIPLET_ID   = 0x20;
const uint32_t EQ7_PERV_CHIPLET_ID   = 0x27;
const uint32_t PCI0_PERV_CHIPLET_ID  = 0x08;
const uint32_t PCI1_PERV_CHIPLET_ID  = 0x09;

// PCIe constants
const uint8_t MODE_PCIE_TOP_BIT_MASK        = 0b10000000; // Bit 0
const uint8_t MODE_PCIE_PHY_BIT_MASK        = 0b01000000; // Bit 1

// OCC constants
const uint8_t MODE_OCC_ACCESS_MODE_BIT_SHIFT = 6;   // Bits 0:1
const uint8_t MODE_OCB_CHAN_BIT_SHIFT        = 3;   // Bits 2:4
const uint8_t MODE_OCB_PBA_INTERLEAVED_SHIFT = 2;   // Bit  5
const uint8_t OCB_MODE_LOWER_LIMIT           = 1;
const uint8_t OCB_MODE_UPPER_LIMIT           = 3;
const uint8_t OCB_MODE_CIRCULAR              = 3;

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
//

extern "C" {

///
/// @brief Decode the OCB channel number from an input Mode value
///
/// @param[in]  i_mode          For OCC:
///                               bits 0:1  1 = Normal; 2 = Debug; 3 = Circular
///                               bits 2:4  OCB channel number
///                                         0b001: OCB_CHAN0
///                                         0b010: OCB_CHAN1
///                                         0b011: OCB_CHAN2
///                                         0b100: OCB_CHAN3
///                                         Default to OCB_CHAN3 otherwise.
///                               bits 5    OCB(SRAM)-PBA(Mainstore) Interleaved mode
///                               bits 6:7  Reserved
///
/// @return ocb::PM_OCB_CHAN_NUM
///
    ocb::PM_OCB_CHAN_NUM getOcbChanNum(const uint8_t i_mode);


///
/// @brief Check if OCB-PBA Interleaved Mode is active
///
/// @param[in]  i_mode          For OCC:
///                               bits 0:1  1 = Normal; 2 = Debug; 3 = Circular
///                               bits 2:4  OCB channel number
///                                         0b001: OCB_CHAN0
///                                         0b010: OCB_CHAN1
///                                         0b011: OCB_CHAN2
///                                         0b100: OCB_CHAN3
///                                         Default to OCB_CHAN3 otherwise.
///                               bits 5    OCB(SRAM)-PBA(Mainstore) Interleaved mode
///                               bits 6:7  Reserved
///
/// @return true if mode active, false if not
///
    bool is_OCB_PBA_InterleavedMode (const uint8_t i_mode);

///
/// @brief Save or restore PBA setup context when in getSram interleaved mode
///
/// @param[in]  i_target        Reference to proc chip target
/// @param[in]  i_mode          For OCC:
///                               bits 0:1  1 = Normal; 2 = Debug; 3 = Circular
///                               bits 2:4  OCB channel number
///                                         0b001: OCB_CHAN0
///                                         0b010: OCB_CHAN1
///                                         0b011: OCB_CHAN2
///                                         0b100: OCB_CHAN3
///                                         Default to OCB_CHAN3 otherwise.
///                               bits 5    OCB(SRAM)-PBA(Mainstore) Interleaved mode
///                               bits 6:7  Reserved
/// @param[in]  i_save          true: read and save PBA setup context
///                             false: restore saved PBA setup context
///
/// @return true if mode active, false if not
///
    fapi2::ReturnCode p10_ocb_handlePbaContext (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
            const uint8_t i_mode,
            const bool    i_save );

} //extern "C"

#endif //_P10_GETPUTSRAM_UTILS_H_
