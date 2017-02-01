/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloaderif.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

namespace Bootloader{
// Max size of HBBL without ECC. Must match PNOR layout for eyeCatch HBBL
// Must be aligned CACHELINE_SIZE of 128 bytes
#define MAX_HBBL_SIZE (20 * KILOBYTE)

// Size of exception vector reserved space at start of the HBBL section
#define HBBL_EXCEPTION_VECTOR_SIZE (12 * KILOBYTE)

// The Bootloader to Hostboot communication area exists after the working HBB
#ifdef BOOTLOADER
#define BLTOHB_COMM_DATA_ADDR (getHRMOR() - ( 2*MEGABYTE) + 512*KILOBYTE)
#else
#define BLTOHB_COMM_DATA_ADDR (getHRMOR() + 512*KILOBYTE)
#endif

// Expected BlToHbData eye catch
const uint64_t BLTOHB_EYECATCHER = 0x23626C746F686200; // #BLTOHB\0

// Used for version checking as the BlToHbData structure changes
enum BlToHbDataVersion
{
    // [release:4][version:4]
    BLTOHB_INIT = 0x0000000900000001
};


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
                   hbbHeaderSize(0), totalSize(0) {}

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
    // Total size of data preserved by the Kernel
    size_t totalSize;
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