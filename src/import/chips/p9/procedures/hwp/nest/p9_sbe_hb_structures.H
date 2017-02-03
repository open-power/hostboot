/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_sbe_hb_structures.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_sbe_hb_structures.H
/// @brief Structures shared between SBE/HB code
///

// *HWP HWP Owner: Joe McGill jmcgill@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: SBE, HB

#ifndef _SBE_HB_STRUCTURES_H_
#define _SBE_HB_STRUCTURES_H_

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
// Max Pairs
#define MAX_ROW_COUNT 8

// To keep all the Stashed Keys & Addrs together within this struct
typedef struct __attribute__((packed))
{
    uint8_t  key[MAX_ROW_COUNT];
    uint64_t addr[MAX_ROW_COUNT];
}
keyAddrPair_t;

// Used for version checking as the BootloaderConfigData_t structure changes
enum SbeBootloaderVersion
{
    // Keep initial version formatted as it was originally
    INIT = 0x901,
    // Later versions use format [release:2][version:2]
    SAB_ADDED = 0x00090002,
    MMIO_BARS_ADDED = 0x00090003,
    ADDR_STASH_SUPPORT_ADDED = 0x00090004,
};

union BootloaderSecureSettings
{
    uint8_t data8;
    struct
    {
        // Bit Breakdown - sync with ATTR_SECURE_SETTINGS
        uint8_t reserved           : 5; // reserved
        uint8_t allowAttrOverrides : 1; // Allow Attribute Overrides in
        // Secure Mode
        uint8_t securityOverride   : 1; // Security Override
        uint8_t secureAccessBit    : 1; // Secure Access Bit
    } __attribute__((packed));
};

// Structure starts at the bootloader zero address
//   Note - this structure must remain 64-bit aligned to
//          maintain compatibility with Hostboot
struct BootloaderConfigData_t
{
    uint32_t version;         // bytes  4:7  Version identifier
    uint8_t sbeBootSide;      // byte   8    0=SBE side 0, 1=SBE side 1
    //                                         [ATTR_SBE_BOOT_SIDE]
    uint8_t pnorBootSide;     // byte   9    0=PNOR side A, 1=PNOR side B
    //                                         [ATTR_PNOR_BOOT_SIDE]
    uint16_t pnorSizeMB;      // bytes 10:11 Size of PNOR in MB
    //                                         [ATTR_PNOR_SIZE]
    uint64_t blLoadSize;      // bytes 12:19 Size of Load
    //                                         Exception vectors and Bootloader
    BootloaderSecureSettings  secureSettings  ; // byte  20
    uint8_t reserved[7];      // bytes 21:27 Reserved space to maintain 64-bit alignment
    uint64_t xscomBAR;        // bytes 28:35 XSCOM MMIO BAR
    uint64_t lpcBAR;          // bytes 36:43 LPC MMIO BAR
    keyAddrPair_t pair;       // total of 72 Bytes (8+8*8) for Key/Addr Pair
}; // Note: Want to use '__attribute__((packed))' but compiler won't let us

#endif // _SBE_HB_STRUCTURES_H_
