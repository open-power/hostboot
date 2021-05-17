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
    BLTOHB_TPM_FFDC         = 0x0000000A00000003,
};

enum
{
    // Arbitrary size larger than the current structure size 8 byte aligned.
    // This will only be used when there is a BL/HB mismatch
    INITIAL_BLTOHB_PADDED_SIZE = 256
};

// Possible sources of the TPM Deconfig Protect bit. This bit could be set
// by different entities. This enum indicates to Hostboot exactly who set
// the TDP bit for debugging purposes.
enum TdpBitSources : uint8_t
{
    TDP_BIT_UNSET    = 0,
    TDP_BIT_SET_SBE  = 1,
    TDP_BIT_SET_HBBL = 2
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
                   min_secure_version(0), tdpSource(TDP_BIT_UNSET),
                   measurement_seeprom_version(0), tpmRc(0)
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
    // Indicates who set the TDP bit
    TdpBitSources tdpSource;
    // Version of the measurement seeprom
    uint32_t measurement_seeprom_version;
    // The RC of the error that happened during TPM ops
    uint32_t tpmRc;

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
