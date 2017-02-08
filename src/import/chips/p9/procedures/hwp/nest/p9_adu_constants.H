/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_adu_constants.H $  */
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
/// @file p9_adu_constants.H
/// @brief Constant enums to support ADU get/putmem procedures (FAPI)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWp Consumed by: SBE

#ifndef _P9_ADU_CONSTANTS_H_
#define _P9_ADU_CONSTANTS_H_

//---------------------------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------------------------

extern "C"
{

//----------------------------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------------------------

//if the flag is more than 1 bit there will be a start and end bit for the flag
//these give the bit position that is expected for the flags
    enum adu_flags
    {
        // Operation type
        // 0b000: DMA partial
        // 0b001: Cache-inhibited
        // 0b010: PB disable op
        // 0b011: PMISC op
        // 0b100: PB enable op
        FLAG_ADU_TTYPE = 0xE0000000ull,                        // Bits 0:2

        // Utilize ADU HW auto-increment function
        // 0: Don't use autoinc
        // 1: Use autoinc
        FLAG_AUTOINC = 0x10000000ull,                          // Bit 3

        // Pick ADU lock (if required)
        // 0: Don't use lock pick
        // 1: Use lock pick
        FLAG_LOCK_PICK = 0x08000000ull,                        // Bit 4

        // In case of a fail with lock held, reset
        // ADU and release lock
        // 0: Reset & release
        // 1: Leave dirty
        FLAG_LEAVE_DIRTY = 0x04000000ull,                      // Bit 5

        // Check status only at the end of read/write stream
        // 0:  Do status check after every read/write
        // 1:  Don't do status check
        FLAG_ADU_FASTMODE = 0x02000000ull,                     // Bit 6

        // Collect/set itag with each 8B read/write
        // For a write only set if itag data should be 1
        // 0: Don't collect itag
        // 1: Collect itag
        FLAG_ITAG = 0x01000000ull,                             // Bit 7

        // Collect/set ecc with each 8B read/write
        // 0: Don't collect ecc
        // 1: Collect ecc
        FLAG_ECC = 0x00800000ull,                              // Bit 8

        // Overwrite the ecc/itag data
        // 0: Don't overwrite ECC
        // 1: Overwrite ECC
        FLAG_OVERWRITE_ECC = 0x00400000ull,                    // Bit 9

        // Transaction size (choice is 1, 2, 4, or 8)
        // 0b00: TSIZE_1
        // 0b01: TSIZE_2
        // 0b10: TSIZE_4
        // 0b11: TSIZE_8
        FLAG_SIZE = 0x00300000ull,                             // Bits 10:11

        // Number of ADU lock acquisitions to attempt
        // before giving up or attempting lock pick
        FLAG_LOCK_TRIES       = 0x000F0000,                    // Bit 12:15

        // Reserved bits
        FLAG_NOT_USED_BITS    = 0x0000FFFF,                    // Bit 16:31
    };

// Operation type values
    const uint32_t FLAG_ADU_TTYPE_DMA     = 0x00000000ull;   // DMA partial
    const uint32_t FLAG_ADU_TTYPE_CI      = 0x20000000ull;   // Cache inhibit
    const uint32_t FLAG_ADU_TTYPE_PB_DIS  = 0x40000000ull;   // PB operation (disable)
    const uint32_t FLAG_ADU_TTYPE_PMISC   = 0x60000000ull;   // Switch operation
    const uint32_t FLAG_ADU_TTYPE_PB_INIT = 0x80000000ull;   // PB operation (init)

// Flag size values
    const uint32_t FLAG_SIZE_TSIZE_1   = 0x00000000ull;
    const uint32_t FLAG_SIZE_TSIZE_2   = 0x00100000ull;
    const uint32_t FLAG_SIZE_TSIZE_4   = 0x00200000ull;
    const uint32_t FLAG_SIZE_TSIZE_8   = 0x00300000ull;

// Shift positions
    const uint64_t FLAG_ADU_TTYPE_SHIFT  = 29;
    const uint64_t FLAG_LOCK_TRIES_SHIFT = 16;
    const uint64_t FLAG_ADU_SIZE_SHIFT   = 20;

} //extern "C"

#endif //_P9_ADU_CONSTANTS_H_
