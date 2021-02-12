/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pnor/pnor_const.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#ifndef BOOTLOADER
    HB_EXT_CODE,    /**< Hostboot Extended Image */
#endif
    HB_BASE_CODE,   /**< Hostboot Base Image */
#ifndef BOOTLOADER
    SBE_IPL,        /**< Self-Boot Engine IPL image */
    HCODE,          /**< HCODE Reference image */
    PAYLOAD,        /**< HAL/OPAL */
    HB_RUNTIME,     /**< Hostboot Runtime Image */
    HB_DATA,        /**< Hostboot Data */
    GUARD_DATA,     /**< Guard Data */
    HB_ERRLOGS,     /**< Hostboot Error log Repository */
    DIMM_JEDEC_VPD, /**< DIMM JEDEC VPD */
    MODULE_VPD,     /**< Module VPD */
    NVRAM,          /**< Opal NVRAM */
    OCC,            /**< OCC image */
    FIRDATA,        /**< DEPRECATED: FIR data for checkstop analysis */
    ATTR_TMP,       /**< Temporary Attribute Override */
    ATTR_PERM,      /**< Permanent Attribute Override */
    CAPP,           /**< CAPP lid */
    VERSION,        /**< PNOR version string section */
    HB_BOOTLOADER,  /**< Hostboot Bootloader image */
    TEST,           /**< Scratch space for PNOR test cases */
    TESTRO,         /**< Scratch space for PNOR ReadOnly test cases */
    BACKUP_PART,    /**< Backup of TOC*/
    RINGOVD,        /**< Ring override data */
    WOFDATA,        /**< VFRT data tables for WOF */
    SBKT,           /**< SecureBoot Key Transition */
    HB_VOLATILE,    /**< Semi volatile partition for reconfig */
    TESTLOAD,       /**< Secureboot test load */
    HDAT,           /**< HDAT data */
    EECACHE,        /**< EEPROM Cache */
    OCMBFW,         /**< OCMB image */
#ifdef CONFIG_DEVTREE
    DEVTREE,        /**< DEVTREE image */
#endif
#ifdef CONFIG_LOAD_PHYP_FROM_BOOTKERNEL
    BOOTKERNEL,     /**< Bootkernel -- HB uses for  PHYP */
#endif
    HCODE_LID,      /**< HCODE_LID Reference image */
    HB_DATA_RW,     /**< Hostboot Data RW */
#endif
    NUM_SECTIONS,   /**< Number of defined sections */

    FIRST_SECTION = TOC,  /**< First section (for looping) */
    /**< Used for error cases, initialization */
    INVALID_SECTION = NUM_SECTIONS,
};

enum PnorMode_t {
    MODEL_UNKNOWN,   /**< Invalid */
    MODEL_MEMCPY,    /**< No LPC logic, just do memcpy into cache area */
    MODEL_LPC_MEM,   /**< Break into 32-bit LPC ops but use fake-PNOR */
    MODEL_REAL_CMD,  /**< Code for real HW using Command based reads */
    MODEL_REAL_MMIO, /**< Code for real hardware using MMIO reads */
};

/**
 * Information about a section of PNOR
 */
    // Size and layout of this structure must be maintained for debug framework.
struct SectionInfo_t
{
    SectionInfo_t():
      id(INVALID_SECTION),
      name("INVALID_SECTION"),
      vaddr(0),
      flashAddr(0),
      size(0),
      sizeActual(0),
      eccProtected(false),
      sha512Version(false),
      sha512perEC(false),
      readOnly(false),
      reprovision(false),
      Volatile(false),
      secure(false),
      clearOnEccErr(false),
      hasHashTable(false)
      {}
    SectionId id;       /**< Identifier for this section */
    const char* name;   /**< Name of the section */
    uint64_t vaddr;     /**< Virtual address of the start of the section */
    uint32_t flashAddr; /**< Flash address of the start of the section*/
    uint64_t size;      /**< Logical size of partition in bytes (minus headers) */
    uint64_t sizeActual;/**< Physical size of partition in bytes */
    bool eccProtected;  /**< Section is ECC protected */
    bool sha512Version; /**< Version Checking */
    bool sha512perEC;   /**< Version Checking perEC */
    bool readOnly;      /**< Section is read only */
    bool reprovision;   /**< Erase this section during a reprovision */
    bool Volatile;   /**< Section loses contents on non HB reboots */
    bool secure;        /**< Indicates if a section is secure */
    bool clearOnEccErr; /**< Indicates on ECC errors, clear and reboot*/
    bool hasHashTable;  /**< Indicates if there exists a hash page table*/
    size_t secureProtectedPayloadSize; /**< Cache the secure payload size so
                                            that the secure container only
                                            needs to be parsed once */
};

/**
  * Internal information to deal with the sections of PNOR
  */
struct SectionData_t {
    SectionData_t(): secure(false) {}
    PNOR::SectionId id;  /**< Identifier for this section */
    uint64_t virtAddr;  /**< Virtual address for the start of the section */
    uint32_t flashAddr;  /**< Address in flash */
    uint32_t size;/**< Actual size of content in bytes (not including ECC)*/
    uint8_t chip;  /**< Chip Select */
    uint8_t version; /**< Version Checking */
    uint16_t integrity; /**< Data Integrity */
    uint8_t misc; /**< Misc Flags */
    uint8_t secure; /**< Indicates if a section is secure */
} PACKED;

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
    TOC_SIZE = 0x8000,
    TOC_OFFSET_FROM_TOP_OF_FLASH = 0x8FFF,
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
