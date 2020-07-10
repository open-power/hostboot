/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloaderif.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#ifndef __BOOT_LOADERIF_H
#define __BOOT_LOADERIF_H

#include <arch/ppc.H>
#include <securerom/ROM.H>
#include <arch/memorymap.H>

namespace Bootloader{
// Max size of HBBL without ECC. Must match PNOR layout for eyeCatch HBBL
// Must be aligned CACHELINE_SIZE of 128 bytes
#define MAX_HBBL_SIZE (20 * KILOBYTE)

// Location of the HW Key Hash located at the end of the HBBL without ECC
#define HBBL_HW_KEY_HASH_LOCATION  (MAX_HBBL_SIZE - sizeof(SHA512_t))

// Location of Secure Version is the byte preceding HBBL_HW_KEY_HASH_LOCATION
#define HBBL_SECURE_VERISON_LOCATION  (HBBL_HW_KEY_HASH_LOCATION - 1)

// Size of exception vector reserved space at start of the HBBL section
#define HBBL_EXCEPTION_VECTOR_SIZE (12 * KILOBYTE)

// Size of PNOR partition without ECC, page algined down, minus 4K header
#define MAX_HBB_SIZE (904 * KILOBYTE)

// Max Pairs
#define MAX_ROW_COUNT 8

// Location of running copy of HBB
#ifdef BOOTLOADER
#define HBB_HRMOR               (getHRMOR() - ( 2*MEGABYTE))
#define HBB_RUNNING_ADDR        (getHRMOR() - ( 2*MEGABYTE))
#else
#define HBB_HRMOR               (getHRMOR())
#define HBB_RUNNING_ADDR        (getHRMOR())
#endif

// Different Locations of BlToHBData struct over time.
// New values make "_LATEST" and switch current "_LATEST" to "V<N>"
// NOTE: Done this way to limit code space.
#define BLTOHB_COMM_DATA_ADDR_V1 (HBB_HRMOR + 512*KILOBYTE)
#define BLTOHB_COMM_DATA_ADDR_LATEST (HBB_HRMOR + MAX_HBB_SIZE)

// Expected BlToHbData eye catch
const uint64_t BLTOHB_EYECATCHER = 0x23626C746F686200; // #BLTOHB\0

// Used for version checking as the BlToHbData structure changes
enum BlToHbDataVersion
{
    // [release:4][version:4]
    BLTOHB_INIT             = 0x0000000900000001,
    BLTOHB_SAB              = 0x0000000900000002,
    BLTOHB_MMIOBARS         = 0x0000000900000003,
    BLTOHB_SECURE_OVERRIDES = 0x0000000900000004,
    BLTOHB_SIZE             = 0x0000000900000005,
    BLTOHB_KEYADDR          = 0x0000000900000006,
    BLTOHB_BACKDOOR         = 0x0000000900000007,
    BLTOHB_SECURE_VERSION   = 0x0000000900000008,
};

enum
{
    // Arbitrary size larger than the current structure size 8 byte aligned.
    // This will only be used when there is a BL/HB mismatch
    INITIAL_BLTOHB_PADDED_SIZE = 256
};


//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------


// To keep all the Stashed Keys & Addrs together within this struct
struct keyAddrPair_t
{
    keyAddrPair_t(uint8_t initVal) {
        for(uint8_t i=0; i < MAX_ROW_COUNT; i++)
        {
            key[i] = initVal;
            addr[i] = initVal;
        }
    }
    uint8_t  key[MAX_ROW_COUNT];
    uint64_t addr[MAX_ROW_COUNT];
} __attribute__((packed));


/** @struct BlToHbData
 *  @brief  Shared data between bootloader and Hostboot.
 *
 *  A shared structure of information that the bootloader has that hostboot
 *  does not. The Bootloader fills in this structure and places in the agreed
 *  on location with hostboot. Hostboot's kernel reads this structure out and
 *  saves it off before the pagemgr clears the cachelines.
 *
 */
struct BlToHbData
{
    BlToHbData() : eyeCatch(0), version(BLTOHB_INIT),
                   branchtableOffset(0), secureRom(nullptr),
                   secureRomSize(0), hwKeysHash(nullptr),
                   hwKeysHashSize(0), hbbHeader(nullptr),
                   hbbHeaderSize(0), secureAccessBit(0),
                   xscomBAR(MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR),
                   lpcBAR(MMIO_GROUP0_CHIP0_LPC_BASE_ADDR),
                   securityOverride(0), allowAttrOverrides(0),
                   sizeOfStructure(0), keyAddrStashData(0),
                   secBackdoorBit(0), min_secure_version(0) {}

    // Simple way to tell if data is valid
    uint64_t eyeCatch;
    // Track version in case there are compatibility issues
    uint64_t version;
    // Offset to branchtable from start of secureROM
    uint64_t branchtableOffset;
    // pointer to start of secureROM code
    const void* secureRom;
    // size of entire secureROM
    size_t secureRomSize;
    // pointer to the hw keys hash used for verification
    const void* hwKeysHash;
    // size of key
    size_t hwKeysHashSize;
    // pointer to the saved off Hostboot base header for TPM extension
    const void* hbbHeader;
    // size of Hostboot base header
    size_t hbbHeaderSize;
    // Secure Setting - Secure Access Bit
    bool secureAccessBit;
    // XSCOM MMIO BAR
    uint64_t xscomBAR;
    // LPC MMIO BAR
    uint64_t lpcBAR;
    // Secure Setting - Security Override
    bool securityOverride;
    // Secure Setting - Allow Attribute Overrides in Securemode
    bool allowAttrOverrides;
    // Size of this structure (Use for backwards compatibility)
    size_t sizeOfStructure;
    //keyAddr stash data
    keyAddrPair_t  keyAddrStashData;
    // Secure Setting - SBE Security Backdoor
    bool secBackdoorBit;
    // Minimum FW Secure Version
    uint8_t min_secure_version;
} __attribute__((packed));

/**
 * @brief Checks if Bootloader to hostboot data is valid by checking the
 *        eyeCatch and version
 *
 * @param[in] BlToHbData*        Pointer to BlToHbdata. Must not be NULL
 *
 * @return bool true if valid; false otherwise
 */
inline bool BlToHbDataValid (const BlToHbData * i_blToHbData)
{
    // Ensure Version and EyeCatch are valid
    return (i_blToHbData->eyeCatch == BLTOHB_EYECATCHER) &&
           (i_blToHbData->version >= BLTOHB_INIT);
}

} // end namespace bootloader

#endif
