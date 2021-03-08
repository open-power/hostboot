/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloaderif.H $                       */
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
#ifndef __BOOT_LOADERIF_H
#define __BOOT_LOADERIF_H

#include <arch/ppc.H>
#include <securerom/ROM.H>
#include <arch/memorymap.H>

namespace Bootloader{

// @HBBL_SIZE_SYNC@
// Max logical size of HBBL without secure header, padding, or ECC.
// Must match PNOR layout assumptions for eyeCatch HBBL
// Must be aligned CACHELINE_SIZE of 128 bytes
#define MAX_HBBL_SIZE (32 * KILOBYTE)

// Need to default the HW Key Hash to this imprint / development value if Hostboot
// code runs across an old SBE image without this value in the BootloaderConfigData_t's
// sb_settings_t struct (which mirrors the .sb_settings SBE section)
// @TODO RTC 269616 - Remove this
const SHA512_t default_hw_key_hash =
{
    0x40,0xd4,0x87,0xff,0x73,0x80,0xed,0x6a,
    0xd5,0x47,0x75,0xd5,0x79,0x5f,0xea,0x0d,
    0xe2,0xf5,0x41,0xfe,0xa9,0xdb,0x06,0xb8,
    0x46,0x6a,0x42,0xa3,0x20,0xe6,0x5f,0x75,
    0xb4,0x86,0x65,0x46,0x00,0x17,0xd9,0x07,
    0x51,0x5d,0xc2,0xa5,0xf9,0xfc,0x50,0x95,
    0x4d,0x6e,0xe0,0xc9,0xb6,0x7d,0x21,0x9d,
    0xfb,0x70,0x85,0x35,0x1d,0x01,0xd6,0xd1
};


// Size of exception vector reserved space at start of the HBBL section
#define HBBL_EXCEPTION_VECTOR_SIZE (12 * KILOBYTE)

// Size of PNOR partition without ECC, page algined down, minus 4K header
#define MAX_HBB_SIZE (904 * KILOBYTE)

// Max Pairs
#define MAX_ROW_COUNT 8

// Max number of key/addr pairs
#define MAX_KEY_ADDR_PAIRS 256

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
    BLTOHB_INIT             = 0x0000000A00000001,
    BLTOHB_SB_SETTING       = 0x0000000A00000002,
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


// A struct to store a key/address pair.
struct keyAddrPair_t
{
    // Initialize all struct members to the provided value
    keyAddrPair_t(uint8_t initVal) : key(initVal), addr(initVal)
    {
    }

    // Default constructor - initialize all members to 0
    keyAddrPair_t() : key(0), addr(0)
    {
    }

    uint8_t  key;
    uint64_t addr;
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
                   secureRomSize(0), hwKeysHashPtr(nullptr),
                   hwKeysHashSize(0), hbbHeader(nullptr),
                   hbbHeaderSize(0), secureAccessBit(0),
                   xscomBAR(MEMMAP::MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR),
                   lpcBAR(MEMMAP::MMIO_GROUP0_CHIP0_LPC_BASE_ADDR),
                   securityOverride(0), allowAttrOverrides(0),
                   sizeOfStructure(0), secBackdoorBit(0),
                   cacheSizeMb(0), numKeyAddrPair(0),
                   min_secure_version(0), tdpFlagSet(0),
                   measurement_seeprom_version(0)
    {
        memset(keyAddrStashData, 0, sizeof(keyAddrStashData));
    }

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
    const void* hwKeysHashPtr;
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
    // Secure Setting - SBE Security Backdoor
    bool secBackdoorBit;
    // The cache size available to HB (in MB)
    uint16_t cacheSizeMb;
    // The number of keyAddrPair structures included in SBE to BL comm area
    size_t numKeyAddrPair;
    //keyAddr stash data
    keyAddrPair_t keyAddrStashData[MAX_KEY_ADDR_PAIRS];
    // FW Minimum Secure Version
    uint8_t min_secure_version;
    // Flag to indicate whether bootloader set the TPM TDP bit
    uint8_t tdpFlagSet;
    // Version of the measurement seeprom
    uint32_t measurement_seeprom_version;

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
