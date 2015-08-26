/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnor_const.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#ifndef __PNOR_PNOR_CONST_H
#define __PNOR_PNOR_CONST_H

#include <stdint.h>
#include <builtins.h>

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
    HB_BOOTLOADER,  /**< Hostboot Bootloader image */
    TEST,           /**< Scratch space for PNOR test cases */
    TESTRO,         /**< Scratch space for PNOR ReadOnly test cases */
    BACKUP_PART,     /**< Backup of TOC*/
    NUM_SECTIONS,   /**< Number of defined sections */

    FIRST_SECTION = TOC,  /**< First section (for looping) */
    /**< Used for error cases, initialization */
    INVALID_SECTION = NUM_SECTIONS,
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
    bool sha512perEC; /**< Version Checking perEC */
    bool readOnly; /**< Section is read only */
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

enum
{
    INVALID_OFFSET = 0xFFFFFFF,  // Invalid primary or alternate TOC
    BACKUP_TOC_OFFSET = 0x8000,
    INVALID_FLASH_OFFSET = 0xFFFFFFFF,
};

/** @brief PNOR::TEST section offsets for test cases to prevent
 *         concurrency problems
 */
enum TestSectionOffset{
    pnorTestSec_readwrite_offset = 0x100,
    pnorTestSec_smartwrite_offset = 0x120,
    pnorTestSec_rt_readwrite_offset = 0x6000,
};

}

#endif