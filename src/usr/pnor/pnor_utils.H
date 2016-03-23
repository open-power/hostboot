/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_utils.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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

#ifndef PNOR_UTILS_H
#define PNOR_UTILS_H

#include <pnor/pnor_const.H>
#include "limits.h"
#include "ffs.h"


/** @file pnor_utils.H
 *  @brief Provides the utility functions used by different PNOR
 *         classes.
 */

namespace PNOR
{


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
    TOC_SIZE = 0x8000,
};


/**
* These error codes represent all the errors that can arise while
* parsing the table of contents for pnor flash. Note that they
* can be mixed up together.
* (example 0x30000001 is a invalid header with a bad magic number)
*/

enum pnorUtilErrorCodes
{
    NO_ERROR                   = 0x00000000,
    INVALID_MAGIC              = 0x00000001,
    UNSUPPORTED_FFS            = 0x00000002,
    INVALID_ENTRY_SIZE         = 0x00000004,
    NO_ENTRIES                 = 0x00000008,
    INVALID_BLOCK_SIZE         = 0x00000010,
    INVALID_BLOCK_COUNT        = 0x00000020,
    INVALID_HEADER_SIZE        = 0x00000040,
    ENTRY_CHECKSUM_ERR         = 0x00000080,
    ENTRY_EXTENDS_BEYOND_FLASH = 0x00000100,
    BUFF_IS_NULL               = 0x00000200,
    CHECKSUM_ERR               = 0x00000400,
    HEADER_ERR                 = 0x00000800,
    ENTRY_ERR                  = 0x00001000,
    NO_HBB_SECTION             = 0x00002000,
};

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
    LPC_SFC_MMIO_OFFSET = PNOR::LPC_TOP_OF_FLASH_OFFSET-PNOR_SIZE+1,

    //@TODO: RTC:124503 - delete the following line and call the LPC
    //interface instead
    LPC_FW_SPACE = 0xF0000000,
};



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
    uint8_t compress; /**< Compression Flags */
    uint32_t xzDecompressSize; /**< Size of uncompressed image */
} PACKED;

/**
  * @brief Creates a 4-byte Cyclic Redundancy Check (CRC) on the data
  *        provided. The last iteration of the for-loop includes the ffs
  *        checksum itself. Therefore if the 4-byte CRC created matches
  *        the ffs checksum, the resulting CRC will be 0
  *
  * @param[in] i_data       Pointer to the data
  *
  * @param[in] i_size       Size of the data
  *
  * @return uint32_t        return 4-byte CRC, 0 if checksums match
  */
uint32_t pnor_ffs_checksum(void* i_data,
                           size_t i_size);

/**
  * @brief Initialize each section by giving it an id and setting
  *        its initial flashAddr to be the INVALID_FLASH_OFFSET value
  *
  * @param[in/out]      io_toc TOC that we want to initialize
  *
  *  @return void
  */
void initializeSections(SectionData_t io_toc[NUM_SECTIONS]);


/**
  * @brief Ensure the buffer is not NULL, if it is, then return
  *        the appropriate err code from the o_errCode param.
  *        if the buffer is not NULL then cast it to a ffs_hdr
  *        and return that out through the respective o_param
  *
  * @param[in] i_tocBuffer  Buffer holding subsection of pnor flash
  *                         believed to hold a copy of the table of contents
  *
  * @param[out] o_errCode   Error code to inform the caller that the
  *                         buffer is null
  *
  * @param[out] o_ffs_hdr   version of the original input buffer
  *                         casted as an ffs_hdr
  */
void checkForNullBuffer(uint8_t* i_tocBuffer,
                           uint32_t& o_errCode,
                          ffs_hdr*& );


/**
  * @brief Perform a series of checks on the header of the table of contents
  *        These checks include: looking for valid magic #, valid block size,
  *        valid block count, valid entry size, valid entry count, version and
  *        total size.
  *
  * @param[in] i_ffs_hdr     struct containing information about the hdr
  *                          of the table of contents of pnor flash
  *
  * @param[out] io_errCode   Error code to inform the caller that
  *                          the checks on the hdr failed. A single error code
  *                          can describe multiple errors, so this function DOES
  *                          NOT quit after the first error it finds.
  *
*/
void checkHeader (ffs_hdr* i_ffs_hdr,
                  uint32_t& io_errCode);

/**
  * @brief Takes in an ffs_entry and returns the enum version of the section
  *         title.
  *
  * @param[in] i_entry     struct containing information about an entry
  *                        coming from pnor flash's table of contents
  *
  * @param[out] o_secId    This number represents a section name in the
  *                        enums found in include/usr/pnor/pnor_const.H
  *
*/
void getSectionEnum (ffs_entry* i_entry,
                      uint32_t* o_secId);
/**
  * @brief Iterate through the entries, each which represent a section in pnor.
  *         During the iteration we are checking that the entries are valid
  *        and we set the sectionData_t for each section in the TOC.
  *
  * @param[in] i_ffs_hdr          struct containing information about the hdr
  *                               of the table of contents of pnor flash
  *
  * @param[out] io_errCode        Error code to inform the caller that
  *                               the check on the entries in TOC failed
  *
  * @param[in/out] io_TOC         Array of section data that make up the TOC
  *                               of pnor flash.
  *
  * @param[out]  o_err_entry      Pass out bad entry so user can know which
  *                               entry has errors
  *
*/
void parseEntries (ffs_hdr* i_ffs_hdr,
                    uint32_t& io_errCode,
                    SectionData_t* io_TOC,
                    ffs_entry*& o_err_entry);

}  // End namespace PNOR


#endif
