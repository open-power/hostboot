/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnorif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
    ATTR_OVER,      /**< Attribute Override */
    NVRAM,          /**< Opal NVRAM */
    OCC,            /**< OCC lid */
    TEST,           /**< Scratch space for PNOR test cases */

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
    SectionId id;  /**< Identifier for this section */
    const char* name;  /**< Name of the section */
    uint64_t vaddr;  /**< Virtual address for the start of the section */
    uint64_t size;  /**< Size of partition in bytes */
    bool eccProtected;  /**< Section is ECC protected */
    bool sha512Version; /**< Version Checking */
    bool sha512perEC; /**< Version Checking perEC */
};

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
 * @brief Informs caller if PNORDD is using
 *        L3 Cache for fake PNOR or not.
 *
 * @return Indicate state of fake PNOR
 *         true = PNOR DD is using L3 Cache for fake PNOR
 *         false = PNOR DD not using L3 Cache for fake PNOR
 */
bool usingL3Cache();

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
const uint32_t pnorTestSec_readwrite_offset = 0x100;
const uint32_t pnorTestSec_smartwrite_offset = 0x120;
const uint32_t pnorTestSec_BMCAttrOverride_offset = 0x200;

}

#endif
