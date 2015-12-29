/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnorif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#include <errl/errlentry.H>
#include <utility>
#include <config.h>

namespace PNOR
{

/**
 * PNOR Sections
 */
enum SectionId
{
    TOC,            /**< Table of Contents */
            // Value of HB_EXT_CODE must be 1 for debug framework.
    HB_EXT_CODE,    /**< Hostboot Extended Image */
    GLOBAL_DATA,    /**< Global Data */
    HB_BASE_CODE,   /**< Hostboot Base Image */
    CENTAUR_SBE,    /**< Centaur Self-Boot Engine image */
    SBE_IPL,        /**< Self-Boot Engine IPL image */
    WINK,           /**< Sleep Winkle Reference image */
    PAYLOAD,        /**< HAL/OPAL */
    HB_RUNTIME,     /**< Hostboot Runtime (for Sapphire) */
    HB_DATA,        /**< Hostboot Data */
    GUARD_DATA,     /**< Guard Data */
    HB_ERRLOGS,     /**< Hostboot Error log Repository */
    DIMM_JEDEC_VPD, /**< DIMM JEDEC VPD */
    MODULE_VPD,     /**< Module VPD */
    CENTAUR_VPD,    /**< Centaur VPD */
    NVRAM,          /**< Opal NVRAM */
    OCC,            /**< OCC lid */
    FIRDATA,        /**< FIRDATA */
    ATTR_TMP,       /**< Temporary Attribute Override */
    ATTR_PERM,      /**< Permanent Attribute Override */
    CAPP,           /**< CAPP lid */
    VERSION,        /**< PNOR version string section */
    TEST,           /**< Scratch space for PNOR test cases */
    TESTRO,         /**< Scratch space for PNOR ReadOnly test cases */

    NUM_SECTIONS,   /**< Number of defined sections */

    FIRST_SECTION = TOC,  /**< First section (for looping) */
    LAST_SECTION = TEST,  /**< Last section (for looping) */
    INVALID_SECTION = NUM_SECTIONS,  /**< Used for error cases, initialization */
};

/**
 * Information about a section of PNOR
 */
    // Size and layout of this structure must be maintained for debug framework.
struct SectionInfo_t
{
    SectionId id;       /**< Identifier for this section */
    const char* name;   /**< Name of the section */
    uint64_t vaddr;     /**< Virtual address of the start of the section */
    uint32_t flashAddr; /**< Flash address of the start of the section*/
    uint64_t size;      /**< Size of partition in bytes */
    bool eccProtected;  /**< Section is ECC protected */
    bool sha512Version; /**< Version Checking */
    bool sha512perEC;   /**< Version Checking perEC */
    bool readOnly;      /**< Section is read only */
    bool reprovision;   /**< Erase this section during a reprovision */
    bool xzCompressed;  /**< Section is XZ compressed */
    uint32_t xzSize;    /**< Size of uncompressed partition in bytes */
};

/**
 * PNOR Sides
 */
enum SideId
{
    WORKING = 0,
#ifdef CONFIG_PNOR_TWO_SIDE_SUPPORT
    ALTERNATE = 1,
#endif
    NUM_SIDES,
    INVALID_SIDE = NUM_SIDES,
    FIRST_SIDE   = WORKING,
};

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

enum
{
    INVALID_OFFSET = 0xFFFFFFF,  // Invalid primary or alternate TOC
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

/** @brief PNOR::TEST section offsets for test cases to prevent
 *         concurrency problems
 */
enum TestSectionOffset{
    pnorTestSec_readwrite_offset = 0x100,
    pnorTestSec_smartwrite_offset = 0x120,
    pnorTestSec_rt_readwrite_offset = 0x6000,
};

/** Information about PNOR Layout */
struct PnorInfo_t
{
    uint32_t mmioOffset; //< Address of MMIO access
    uint32_t norWorkarounds; //< NOR flash workarounds
    uint32_t flashSize; //< Size of PNOR in bytes
};

/**
 * @brief Retrieve some information about the PNOR/SFC hardware
 *
 * @param[out] o_pnorInfo Information about PNOR
 */
void getPnorInfo( PnorInfo_t& o_pnorInfo );

}

#endif
