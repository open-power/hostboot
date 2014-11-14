/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_common.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#ifndef PNOR_COMMON_H
#define PNOR_COMMON_H

#include <pnor/pnorif.H>
namespace PNOR {
    /**
     * Internal information to deal with the sections of PNOR
     */
    struct SectionData_t {
        PNOR::SectionId id;  /**< Identifier for this section */
        uint64_t virtAddr;  /**< Virtual address for the start of the section */
        uint32_t flashAddr;  /**< Address in flash */
        uint32_t size;/**< Actual size of content in bytes (not including ECC)*/
        uint8_t chip;  /**< Chip Select */
        uint8_t version; /**< Version Checking */
        uint16_t integrity; /**< Data Integrity */
        uint8_t misc; /**< Misc Flags */
    } PACKED;

    // Simple enum of TOC's per PNOR side
    enum TOCS
    {
        TOC_0 = 0,
        TOC_1 = 1,
        NUM_TOCS,
    };

    enum
    {
        // @TODO RTC: 120061 - Determine TOC locations
        // TOC offsets based on pnor layout
        SIDE_A_TOC_0_OFFSET = 0,
        SIDE_A_TOC_1_OFFSET = 0x8000,
        SIDE_B_TOC_0_OFFSET = 0x2000000,
        SIDE_B_TOC_1_OFFSET = 0x2008000,

        /** Real number of bytes required to read 1 logical page */
        PAGESIZE_PLUS_ECC = ((PAGESIZE * 9)/8),  // 8B data + 1B of ECC

        SUPPORTED_FFS_VERSION = 0x1,  /**< Supported FFS Version */
        FFS_TABLE_BASE_ADDR = 0x0,    /**< Currently only have FFS table */
    };

    /**
      * @brief Creates a 4-byte Cyclic Redundancy Check (CRC) on the data
      *        provided. The last iteration of the for-loop includes the ffs
      *        checksum itself. Therefore if the 4-byte CRC created matches
      *        the ffs checksum, the resulting CRC will be 0
      *
      * @param[in] ptr          Pointer to the data
      *
      * @param[in] size         Size of the data
      *
      * @return uint32_t        return 4-byte CRC, 0 if checksums match
      */
    uint32_t pnor_ffs_checksum(void* data, size_t size);

    /**
     * @brief parse the TOCs read from memory and store section
     *        information from one of the verified TOC's
     * @param[in] i_toc0Buffer      Pointer to toc0
     * @param[in] i_toc1Buffer      Pointer to toc1
     * @param[out] o_TOC_used       which TOC is used
     * @param[out] o_TOC            sectionInformation of the TOC used
     * @param[in]  i_baseVAddr      base virtual address of the TOC
     * @return Error
     */
    errlHndl_t parseTOC(uint8_t* i_toc0Buffer, uint8_t* i_toc1Buffer,
           TOCS & o_TOC_used, SectionData_t * o_TOC, uint64_t i_baseVAddr);
}

#endif
