/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnorif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2017                        */
/* [+] Google Inc.                                                        */
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
#ifndef __PNOR_PNORIF_H
#define __PNOR_PNORIF_H

#include <stdint.h>
#include <builtins.h>
#include <pnor/pnor_const.H>
#include <errl/errlentry.H>
#include <utility>
#include <config.h>

namespace PNOR
{

// @TODO RTC:155374 Remove this in the future
extern const size_t BEST_EFFORT_NUM_BYTES;

/**
 * Information about a side of PNOR
 */
struct SideInfo_t
{
    SideId id;              /**< Side ID */
    char side;              /**< name of the side either A or B */
    bool isGolden;          /**< True if side is golden */
    bool isGuardPresent;    /**< True if guard section is present */
    bool hasOtherSide;      /**< True if a valid alternate side exists*/
    uint64_t primaryTOC;    /**< Address of the primary TOC */
    uint64_t backupTOC;     /**< Address of the backup TOC  */
    uint64_t hbbAddress;    /**< HBB Address associated with this side */
    uint64_t hbbMmioOffset; /**< HBB MMIO Offset associated with hbbAddress*/
};

/** Information about PNOR Layout */
struct PnorInfo_t
{
    uint32_t mmioOffset; //< Address of MMIO access
    uint32_t norWorkarounds; //< NOR flash workarounds
    uint32_t flashSize; //< Size of PNOR in bytes
};

/**
 * @brief Returns information about a given side of pnor
 *
 * @param[in]  i_side PNOR side
 * @param[out] o_info side information
 *
 * @return errlHndl_t Error log if request was invalid
 */
errlHndl_t getSideInfo (SideId i_side, SideInfo_t& o_info);

/**
 * @brief  Return the size and address of a given section of PNOR data
 *
 * @param[in] i_section  PNOR section
 * @param[out] o_info  Location and size information
 *
 * @return errlHndl_t  Error log if request was invalid
 */
errlHndl_t getSectionInfo( SectionId i_section,
                           SectionInfo_t& o_info );

#ifdef CONFIG_SECUREBOOT
/**
 *  @brief Loads requested PNOR section to secure virtual address space
 *
 *  @par Detailed Description:
 *      Loads requested PNOR section to secure virtual address space.  If secure
 *      mode is enabled, the load will fully validate the section before
 *      placing it in the address space.  Returns error if the requested
 *      section does not have secure space support.
 *
 *  @param[in] i_section PNOR section to load. Section must not already be
 *      loaded.
 *
 *  @return errlHndl_t Error log handle
 *  @retval NULL Successfully loaded PNOR section
 *  @retval !NULL Failed to load PNOR section
 */
errlHndl_t loadSecureSection(SectionId i_section);

/**
 *  @brief Flushes any applicable pending writes and unloads requested PNOR
 *      section from secure virtual address space
 *
 *  @param[in] i_section PNOR section to unload.  No-op if already unloaded.
 *
 *  @return errlHndl_t Error log handle
 *  @retval NULL Successfully unloaded PNOR section
 *  @retval !NULL Failed to unload PNOR section
 */
errlHndl_t unloadSecureSection(SectionId i_section);

#endif // CONFIG_SECUREBOOT

/**
 * @brief Determines whether the given section is inhibited by secure boot
 *        for containing attribute overrides.
 *
 * @param[in] i_section PNOR section to test.
 *
 * @return bool True if inhibited section, false otherwise.
 */
bool isInhibitedSection(const uint32_t i_section);


/**
 * @brief  Write the data back from hostboot memory to PNOR of a given section
 *         of PNOR
 *
 * @param[in] i_section  PNOR section
 *
 * @return errlHndl_t  Error log if request was invalid
 */
errlHndl_t flush (SectionId i_section);

/**
 * @brief checks and fixes correctable ECC errors in the PNOR
 *
 * @param[in] i_secion:   PNOR section
 * @return errlHndl_t:    Error Log
 */
errlHndl_t fixECC (SectionId i_section);

/**
 * @brief Informs caller if PNORDD is using
 *        L3 Cache for fake PNOR or not.
 *
 * @return Indicate state of fake PNOR
 *         true = PNOR DD is using L3 Cache for fake PNOR
 *         false = PNOR DD not using L3 Cache for fake PNOR
 */
 bool usingL3Cache();

/**
 * @brief  Clears the specified PNOR section with all FF's (w/ good ECC)
 *
 * @param[in] i_section  PNOR section to clear
 *
 * @return Error if fails
 */
errlHndl_t clearSection(PNOR::SectionId i_section);

/**
 * @brief Validate the Alternative Master Processor's LPC
 *        Connection to PNOR
 *
 * @return errlHndl_t  Error log if validation failed
 */
errlHndl_t validateAltMaster( void );

/**
 * @brief Retrieve some information about the PNOR/SFC hardware
 *
 * @param[out] o_pnorInfo Information about PNOR
 */
void getPnorInfo( PnorInfo_t& o_pnorInfo );

// @TODO RTC:155374 Remove this in the future
/**
 * @brief  Check if PNOR section appears to be secure and sets the
 *         internal TOC of PnorRp accordingly.
 *         Note: The setting of the flag is based on the Secureboot policy.
 *
 * @param[in] i_secId Section ID or index in the TOC to modify
 * @param[in] io_TOC  Pointer to internal array of section data that
 *                    represents the TOC of pnor flash
 *                    Asserts if nullptr
 *
 * @return errlHndl_t  Error log if request was invalid
 */
errlHndl_t setSecure(const uint32_t i_secId, SectionData_t* io_TOC);

/**
  * @brief Returns string representation of a PNOR SectionId.
  *        If id requested is out of range of known string array
  *          - Hostboot asserts
  *          - Bootloader terminates
  *
  * @param[in] i_secIdIndex     PNOR section id which also represents the index
  *                             into the string array.
  *
  * @return  const char*  - String associated with Section ID
  *
*/
const char * SectionIdToString( uint32_t i_secIdIndex );

/**
 * @brief  Memcmp a vaddr to the known secureboot magic number
 *
 * @param[in]   i_vaddr: vaddr of secureboot header to check for magic number
 *                       Note: must point to a buffer of size >= 4 bytes
 *                       Nullptr asserts or terminates bootloader
 *
 * @return  bool - True if the magic number and starting bytes of the vaddr
 *                 match. False otherwise.
 */
bool cmpSecurebootMagicNumber(const uint8_t* i_vaddr);

} // PNOR

#endif
