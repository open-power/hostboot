/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_hb_structures.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/// @file p10_sbe_hb_structures.H
/// @brief Structures shared between SBE/HB code
///
/// *HWP HW Maintainer : Doug Holtsinger <Douglas.Holtsinger@ibm.com>
/// *HWP FW Maintainer : Raja Das        <rajadas2@in.ibm.com>
/// *HWP Consumed by   : SBE
///

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
    // versions format [release:2bytes][version:2bytes]
    INIT        = 0x00100001,  // Original field
    SB_SETTING  = 0x00100002,  // Updated Version field
};

union BootloaderSecureSettings
{
    uint8_t data8;
    struct
    {
        // Bit Breakdown - sync with ATTR_SECURE_SETTINGS
        uint8_t reserved           : 4; // reserved
        uint8_t secBackdoorBit     : 1; // SBE Security Backdoor Bit
        uint8_t allowAttrOverrides : 1; // Allow Attribute Overrides in
        // Secure Mode
        uint8_t securityOverride   : 1; // Security Override
        uint8_t secureAccessBit    : 1; // Secure Access Bit
    } __attribute__((packed));
};

// Structure for .sb_setting from SBE image Xip
// Note - this structure must remain 64-bit aligned
//
struct sb_settings_t
{
    uint8_t hwKeyHash[64]; // HW Key Hash which is the first 64Bytes in the XIP
    uint8_t msv;           // Minimum Secure Version of the secure containier
    uint8_t reserved[7];   // 7Bytes reserved to align
};

// Structure starts at the bootloader zero address
//   Note - this structure must remain 64-bit aligned to
//          maintain compatibility with Hostboot
struct BootloaderConfigData_t
{
    uint32_t version;          // bytes 4:7   Version identifier
    uint8_t sbeBootSide;       // byte  8     0=SBE side 0, 1=SBE side 1
    // [ATTR_SBE_BOOT_SIDE]
    uint8_t lpcConsoleEnable;  // byte  9     If LPC console is enabled by SBE
    // 1 = Enabled, 0 = Not
    uint16_t cacheSizeMB;      // bytes 10:11 Size of Cache available for Host
    uint64_t blLoadSize;       // bytes 12:19 Size of Load
    // Exception vectors and Bootloader
    BootloaderSecureSettings  secureSettings; // byte  20
    uint8_t reserved[6];       // bytes 21:26  Reserved space to maintain 64-bit
    // alignment
    uint8_t numKeyAddrPair;    // byte  27     Number of Key-Add pair
    uint64_t xscomBAR;         // bytes 28:35  XSCOM MMIO BAR
    uint64_t lpcBAR;           // bytes 36:43  LPC MMIO BAR
    keyAddrPair_t pair;        // X Bytes allocated basis the numKeyAddrPair
    // (numKeyAddrPair + 8*numKeyAddrPair) 72Bytes 44:115, fixed.
    uint32_t mSeepromVersion;  // Versioning for the measurment seeprom code byte 116:119
    uint8_t  reserved1[8];     // 8bytes reserved to maintain cache alignment of 128Bytes
    // in cacheline0, so that HW Key Hash starts into next cacheline i.e. cacheline 1
    struct sb_settings_t sbSettings; // For HW key Hash & msv, this goes into
    // cacheline 1
}; // Note: Want to use '__attribute__((packed))' but compiler won't let us


#endif // _SBE_HB_STRUCTURES_H_
