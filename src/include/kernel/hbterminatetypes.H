/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/hbterminatetypes.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
/** @file terminate.H
 *  @brief Defines kernel information about the TI data area
 */
#ifndef __KERNEL_HBTERMINATETYPES_H
#define __KERNEL_HBTERMINATETYPES_H
#include <stdint.h>

// Enum used to specify the command type in the TI Area.
// The default value is taken from PHYP.
enum command_type : uint8_t
{
    DEFAULT_COMMAND = 0xA1,
    INVALID_COMMAND = 0xFF,
};

// Enum indicating whether a SRC or EID is stored
enum hb_terminate_type : uint8_t
{
    // TODO RTC: 247696 HWSV still relies on TI_WITH_PLID constant; it needs
    // to be removed from here and from HWSV.
    TI_WITH_PLID = 0x01,
    TI_WITH_SRC  = 0x02,
    TI_WITH_EID  = 0x03,
};

// Enum used in the flag indicating who initiated the TI
enum hb_terminate_source : uint8_t
{
    NO_TI_ERROR =      0x00,
    TI_KERNEL_ASSERT = 0x01,
    TI_CRIT_ASSERT =   0x02,
    TI_SHUTDOWN =      0x03,
    TI_UNHANDLED_EX =  0x04,
    TI_BOOTLOADER =    0x05,
};

// Hardware Dump Type: Tells attention handling code what kind of dump to
// initiate as a result of the TI
enum hw_dump_type : uint16_t
{
    SW_DUMP = 0,
    // 1 is also a SW_DUMP
    HW_DUMP = 2,
};

/** @struct HB_T_SRC_DataArea
 *  @brief Defines the data space recreating an SRC needed for a TI from kernel
 *  space
 */
struct HB_T_SRC_DataArea
{

    union{
        struct {
            uint32_t ID:8;          /**< B1 or what we are using now*/
            uint32_t subsystem:8;   /**< Caller of the TI  */
            uint32_t reasoncode:16; /**< reasoncode */
        };
        uint32_t SRCword0;          /**< Full SRC word0 */
    };
     /**< Full SRC word1: Reserved by FSP SRCI comp */
    union{
        struct {
            uint32_t bpCCIN:16;     /**< BP CCIN*/
            uint32_t moduleID:8;    /**< Module ID  */
            uint32_t FSP:8;         /**< subsystem */
        };
        uint32_t SRCword2;          /**< Full SRC word2 */
    };

    uint32_t SRCword3;              /**< Full SRC word3 */
    uint32_t SRCword4;              /**< Full SRC word4 */
    /* Word 5-8 - user data */
    union{
        struct {
            uint32_t iType:16;     /**< SRC or EID failure*/
            uint32_t iSource:16;   /**< Source of the src */
        };
        uint32_t SRCword5;         /**< Full Dword5 */
    };
    // TODO RTC: 247696 Rename word* to SRCword* for consistency. HWSV usage
    // of these words also needs to be renamed at the same time.
    uint32_t word6;                /**< Full Dword6 */

    uint32_t word7;                /**< Full Dword7 */
    uint32_t word8;                /**< Full Dword8 */

};

/** @struct TI_DataArea
 *  @brief Defines the data space used to store the src or EID regarding a
 *     Terminate Immediate request; this struct is common between HB/HBBL/PHYP
 */
struct HB_TI_DataArea
{
    union {
        struct {
            uint32_t tiAreaValid:8;        /**< Whether this TI area is valid */
            command_type command:8;        /**< Command:Default taken from PHYP:
                                                0xA1 */
            uint32_t numberOfDataBytes:16; /**< The number of bytes of data */
        };
        uint32_t word0; // Offset 0x00
    };

    union {
        struct {
            uint32_t reserved0:8;
            hb_terminate_type type:8;     /**< indicates either plid or src  */
            hw_dump_type hardwareDumpType:16; /**< 0 = SW, 1 = SW, 2 = HW */
        };
        uint32_t word1; // Offset 0x04
    };

    union { // PHYP-specific data; unused in HB
        struct {
            uint32_t srcFormat:8;         /**< Default 0x2 in PHYP */
            uint32_t srcFlags:8;          /**< SRC flags */
            uint32_t numAsciiWords:8;     /**< The number of words of ASCII
                                               data */
            uint32_t numHexWords:8;       /**< The number of words of hex data*/
        };
        uint32_t word2; // Offset 0x08
    };

    union {
        struct {
            uint16_t hbDumpFlag:1;        /**< Get HB dump flag */
            uint16_t hbNotVisibleFlag:1;  /**< If 1, do not post a visible PEL for this TI */
            uint16_t reserved1:6;
            hb_terminate_source source:8; /**< Caller of the TI  */
        };
        uint16_t hostbootFlags;
    };
    uint16_t lengthOfSrc;                 /**< The byte length of SRC
                                               including header */
    // Offset 0x10
    HB_T_SRC_DataArea src;                /**< SRC  */
    uint32_t error_data;                  /**< Error Data */
    union {
        uint32_t eid;                    /**< EID of the error  */
        // TODO RTC: 247696 Remove the usage of plid here and in HWSV code.
        uint32_t plid;                   /**< PLID of the error (used by HWSV)*/
    };
} __attribute__((aligned(128))); // 128 byte alignment to meet SBE requirements

#endif
