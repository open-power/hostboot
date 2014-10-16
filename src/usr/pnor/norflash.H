/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/norflash.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __PNOR_NORFLASH_H
#define __PNOR_NORFLASH_H
#include <config.h>
#include <errl/errlentry.H>

class SfcDD;

/** @file norflash.H
 *  @brief Contains constants related to specific types of
 *    of NOR flash chips
 */

namespace PNOR {

/**
 * @brief Supported NOR Chip IDs
 */
enum NorChipIDs
{
    UNKNOWN_NOR_ID    = 0x12345600, /**< Initial value before read */

    MICRON_MFG_ID     = 0x20000000, /**< Micron Mfg ID */
    MICRON_NOR_ID     = 0x20ba2000, /**< Micron NOR */

    MACRONIX_MFG_ID   = 0xC2000000, /**< Macronix Mfg ID */
    MACRONIX32_NOR_ID = 0xC2201A00, /**< Macronix NOR MXxxL51235F */
    MACRONIX64_NOR_ID = 0xC2201900, /**< Macronix NOR MXxxL25635F */

    /* Note: Simics currently models Micron NOR  */
    VPO_NOR_ID        = 0x20201800, /**< VPO NOR chip ID */
    FAKE_NOR_ID       = 0xBADBAD00, /**< ID used during fake pnor */

    ID_MASK           = 0xFFFFFF00, /**< Only look at 3 bytes */
    MFGID_MASK        = 0xFF000000, /**< Manufacturer ID is the first byte */
};

/**
 * @brief SPI Config Info
 *    OP Codes and other MISC info for configuring SFC
 */
enum SpiConfigInfo
{
    SPI_NO_OPCODE       = 0x00, /**< Undefined value */

    /*
     * Micron Flash Commands
     */
    SPI_MICRON_FLAG_STAT    = 0x70, /**< Check write/erase complete */
    SPI_MICRON_CLRFLAG_STAT = 0x50, /**< Clear write/erase Status reg */

    /*
     * Macronix Flash Commands
     */
    SPI_MACRONIX_EN4B        = 0xB7, /**< Enable Macronix 4-Byte addressing */

    /* SPI protocol commands */
    SPI_JEDEC_WRITE_STATUS   = 0x01, //WRSR
    SPI_JEDEC_PAGE_PROGRAM   = 0x02, //PP
    SPI_JEDEC_READ           = 0x03, //READ
    SPI_JEDEC_WRITE_DISABLE  = 0x04, //WRDI
    SPI_JEDEC_READ_STATUS    = 0x05, //RDSR
    SPI_JEDEC_WRITE_ENABLE   = 0x06, //WREN
    SPI_JEDEC_FAST_READ      = 0x0B, //FAST_READ
    SPI_JEDEC_SECTOR_ERASE   = 0x20, //SE
    SPI_JEDEC_READ_SFDP      = 0x5A, //RDSFDP
    SPI_JEDEC_CHIPID         = 0x9F, //RDID
    SPI_JEDEC_BLOCK_ERASE    = 0xD8, //BE

};

/**
 * @brief General Constants related to flash
 */
enum NorConstants
{
    PAGE_PROGRAM_BYTES = 256, //**< 256 bytes per PP command
};


/**
 * Common format of Status Register
 */
union NorStatusReg_t
{
    uint8_t data8;
    struct
    {
        uint8_t writeProtect    : 1; //0
        uint8_t rsvd            : 5; //1:5
        uint8_t writeEnable     : 1; //6
        uint8_t writeInProgress : 1; //7
    };
    NorStatusReg_t() : data8(0x00) { };
};

/**
 * Flags used to trigger Hardware workarounds
 */
enum VendorWorkarounds
{
    // No workarounds present
    HWWK_NO_WORKAROUNDS = 0x00000000,

    // Must perform 'read flag status' commands after
    //  any write or erase
    HWWK_MICRON_WRT_ERASE = 0x00000001,

    // Must do a read of a low flash address before issuing read
    //  commands that return more than 1 word of data
    HWWK_MICRON_EXT_READ = 0x00000002,
};


/*
 * Vendor-specific interfaces
 */
#ifdef CONFIG_ALLOW_MICRON_PNOR

/**
 * @brief Check the version of the part to see if it has any
 *        known errors that require a workaround.
 *
 * @parm i_sfc  SFC driver to operate on
 * @parm o_workarounds  Function will OR in any flags it discovers
 *
 * @return error from operation
 */
errlHndl_t micronCheckForWorkarounds( SfcDD* i_sfc,
                                      uint32_t& o_workarounds );

/**
 * @brief Check flag status bit on Micron NOR chips
 *        The current version of Micron parts require the Flag
 *        Status register be read after a read or erase operation,
 *        otherwise all future operations won't work..
 *
 * @parm i_sfc  SFC driver to operate on
 *
 * @return Error from operation
 */
errlHndl_t micronFlagStatus( SfcDD* i_sfc );

#endif


};//namespace PNOR

#endif
