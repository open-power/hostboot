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
#include "ffs.h"
#include <devicefw/driverif.H>
#include <initservice/mboxRegs.H>

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
        /** Real number of bytes required to read 1 logical page */
        PAGESIZE_PLUS_ECC = ((PAGESIZE * 9)/8),  // 8B data + 1B of ECC

        SUPPORTED_FFS_VERSION = 0x1,  /**< Supported FFS Version */
        FFS_TABLE_BASE_ADDR = 0x0,    /**< Currently only have FFS table */
        TOC_SIZE = 0x8000,
        INVALID_OFFSET = 0xFFFFFFF,
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
     *        information from one of the verified TOCs
     * @param[in] i_toc0Buffer      Pointer to toc0
     * @param[in] i_toc1Buffer      Pointer to toc1
     * @param[out] o_TOC_used       which TOC is used
     * @param[out] o_TOC            sectionInformation of the TOC used
     * @param[in]  i_baseVAddr      base virtual address of the TOC
     * @return Error
     */
    errlHndl_t parseTOC(uint8_t* i_toc0Buffer, uint8_t* i_toc1Buffer,
           TOCS & o_TOC_used, SectionData_t * o_TOC, uint64_t i_baseVAddr);

    /*
     *  @brief: determine the physical offset of ffs entry
     *          (to be used before readTOC is called)
     *  @param[in] i_tocAddress - ffs hdr pointing to a valid TOC
     *  @param[in] i_entryName  - Name of the ffs entry to find the offset of
     *  @param[out] o_offset    - physical offset of the ffs entry
     */
    void findPhysicalOffset(ffs_hdr* i_tocAddress,
                                  const char* i_entryName,
                                  uint64_t & o_offset);

    /*
     * @brief used to translate mmio offset stored in mbox scratch 2
     *        to physical offset of HBB Image
     * @param[out] o_hbbAddress Physical Offset of HB Base Image
     *                          associated with the current boot
     * @return Error
     */
    errlHndl_t mmioToPhysicalOffset(uint64_t& o_hbbAddress);

    /*
     * @brief used to translate HBB Address to MMIO offset
     * @param[in] i_hbbAddress  - Physical Offset of the HB Base image
     * @param[out] o_mmioOffest - MMIO Offset of the HB Base image
     */
     void physicalToMmioOffset(uint64_t  i_hbbAddress,
                               uint64_t& o_mmioOffset);

    enum
    {
        LPC_TOP_OF_FLASH_OFFSET = 0x0FFFFFFF,
#ifdef CONFIG_PNOR_IS_32MB
        PNOR_SIZE = 32*MEGABYTE,
#else //default to 64MB
        PNOR_SIZE = 64*MEGABYTE,
#endif
        //The direct offset value must be equal to <top of flash>-<pnor size>+1
        // for the SBE to work so we can rely on that same assertion
        /**< Offset to direct read space, from FW base */
        LPC_SFC_MMIO_OFFSET = LPC_TOP_OF_FLASH_OFFSET-PNOR_SIZE+1,

        //@TODO: RTC:124503 - delete the following line and call the LPC
        //interface instead
        LPC_FW_SPACE = 0xF0000000,
    };

}

#endif
