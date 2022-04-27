/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloader_trace.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

#ifndef __BOOT_LOADER_TRACE_H
#define __BOOT_LOADER_TRACE_H

#include <arch/ppc.H>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file    bootloader_trace.H
 *
 *  TaskInfo structs for each task that will run.
 */

// @sync_trace_size this number needs to be in sync
// with others with this tag
#ifndef BOOTLOADER_TRACE_SIZE
#define BOOTLOADER_TRACE_SIZE 64
#endif

#include <bootloader/bootloader_data.H> // include after trace size is set

/** @enum BootloaderTraces
 *  @brief List of Hostboot Bootloader Trace values.
 *
 *  These are used as trace values for the Hostboot Bootloader code.
 */
enum BootloaderTraces
{
    /** Bootloader main started */
    BTLDR_TRC_MAIN_START                     = 0x10,

    /** Bootloader main getHBBSection returned */
    BTLDR_TRC_MAIN_GETHBBSECTION_RTN         = 0x11,

    /** Bootloader main handleMMIO to working location returned */
    BTLDR_TRC_MAIN_WORKING_HANDLEMMIO_RTN    = 0x12,

    /** Bootloader main removeECC returned */
    BTLDR_TRC_MAIN_REMOVEECC_RTN             = 0x13,

    /** Bootloader main verifyContainer started */
    BTLDR_TRC_MAIN_VERIFY_START          = 0x14,

    /** Bootloader main verifyContainer succeeded */
    BTLDR_TRC_MAIN_VERIFY_SUCCESS        = 0x15,

    /** Bootloader main copy HBB to running location done */
    BTLDR_TRC_MAIN_COPY_HBB_DONE             = 0x16,

    /** Unused hole from previously used traces */

    /** Bootloader main verifyContainer skip verification - SAB unset */
    BTLDR_TRC_MAIN_VERIFY_SAB_UNSET          = 0x19,

    /** Bootloader main verifyComponentId succeeded */
    BTLDR_TRC_COMP_ID_VERIFY_SUCCESS         = 0x1A,

    /** Bootloader main verifyComponentId failed */
    BTLDR_TRC_COMP_ID_VERIFY_FAILED          = 0x1B,

    /** Bootloader main working length too big */
    BTLDR_TRC_BAD_WORK_LEN                   = 0x1C,

    /** Bootloader handleMMIO started */
    BTLDR_TRC_HANDLEMMIO_START               = 0x20,

    /** Bootloader PNOR Access getHBBSection started */
    BTLDR_TRC_PA_GETHBBSECTION_START         = 0x30,

    /** Technically the below value falls here in the IPL flow between
     *  BTLDR_TRC_PA_GETHBBSECTION_START + BTLDR_TRC_PA_FINDTOC_TOC1_HANDLEMMIO_RTN,
     *  but the value is defined below in numerical order to help guarantee
     *  it won't be re-used.
    BTLDR_TRC_PA_FINDTOC_TOC1_LPC_RTN        = 0x36,
    **/

    /** Bootloader PNOR Access findTOC handleMMIO to copy TOC ONE returned */
    BTLDR_TRC_PA_FINDTOC_TOC1_HANDLEMMIO_RTN = 0x31,

    /** Bootloader PNOR Access findTOC readTOC for TOC ONE returned */
    BTLDR_TRC_PA_FINDTOC_TOC1_READTOC_RTN    = 0x32,

    /** Bootloader PNOR Access findTOC use PNOR start address */
    BTLDR_TRC_PA_FINDTOC_USE_PNOR_START      = 0x33,

    /** Bootloader PNOR Access findTOC adjust PNOR address */
    BTLDR_TRC_PA_FINDTOC_ADJUST_PNOR_ADDR    = 0x34,

    /** Bootloader PNOR Access getHBBSection findTOC returned */
    BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_RTN   = 0x35,

    /** Bootloader PNOR Access findTOC handleMMIO LPC Error Check returned */
    BTLDR_TRC_PA_FINDTOC_TOC1_LPC_RTN        = 0x36,

    /** Bootloader PNOR Access readTOC zeroSection returned */
    BTLDR_TRC_PA_READTOC_ZEROSECTION_RTN     = 0x41,

    /** Bootloader PNOR Access readTOC checkForNullBuffer returned */
    BTLDR_TRC_PA_READTOC_CHECKNULLBUFFER_RTN = 0x42,

    /** Bootloader PNOR Access readTOC performHdrChecksum returned */
    BTLDR_TRC_PA_READTOC_HDRCHECKSUM_RTN     = 0x43,

    /** Bootloader PNOR Access readTOC checkHeader returned */
    BTLDR_TRC_PA_READTOC_CHECKHEADER_RTN     = 0x44,

    /** Bootloader PNOR Access readTOC parseEntries returned */
    BTLDR_TRC_PA_READTOC_PARSEENTRIES_RTN    = 0x45,

    /** Bootloader main removeECC returned corrected ECC rc */
    BTLDR_TRC_MAIN_REMOVEECC_CORRECTED       = 0xD0,

    /** Bootloader Utils checkHeader magic invalid */
    BTLDR_TRC_UTILS_CHECKHEADER_MAGIC        = 0xE0,

    /** Bootloader Utils checkHeader version invalid */
    BTLDR_TRC_UTILS_CHECKHEADER_VERSION      = 0xE1,

    /** Bootloader Utils checkHeader entry size invalid */
    BTLDR_TRC_UTILS_CHECKHEADER_ENTRYSIZE    = 0xE2,

    /** Bootloader Utils checkHeader entry count invalid */
    BTLDR_TRC_UTILS_CHECKHEADER_ENTRYCNT     = 0xE3,

    /** Bootloader Utils checkHeader block size invalid */
    BTLDR_TRC_UTILS_CHECKHEADER_BLOCKSIZE    = 0xE4,

    /** Bootloader Utils checkHeader block count invalid */
    BTLDR_TRC_UTILS_CHECKHEADER_BLOCKCNT     = 0xE5,

    /** Bootloader Utils checkHeader header size invalid */
    BTLDR_TRC_UTILS_CHECKHEADER_HDRSIZE      = 0xE6,

    /** Bootloader Utils parseEntries invalid section */
    BTLDR_TRC_UTILS_PARSE_INVALID_SECTION    = 0xE7,

    /** Bootloader Utils SectionIdToString PNOR section id out of range*/
    BTLDR_TRC_UTILS_PNOR_SECID_OUT_OF_RANGE    = 0xE8,

    /** Bootloader Utils cmpSecurebootMagicNumber requested address to compare is a nullptr*/
    BTLDR_TRC_UTILS_CMP_MAGIC_NUM_NULLPTR    = 0xE9,

    /** Bootloader main getHBBSection returned error */
    BTLDR_TRC_MAIN_GETHBBSECTION_FAIL        = 0xF0,

    /** Bootloader main removeECC returned error */
    BTLDR_TRC_MAIN_REMOVEECC_FAIL            = 0xF1,

    /** Bootloader PNOR Access readTOC performHdrChecksum checksum error */
    BTLDR_TRC_PA_READTOC_HDRCHECKSUM_ERR     = 0xF3,

    /** Bootloader PNOR Access readTOC checkHeader header error */
    BTLDR_TRC_PA_READTOC_CHECKHEADER_ERR     = 0xF4,

    /** Bootloader PNOR Access readTOC parseEntries entry error */
    BTLDR_TRC_PA_READTOC_PARSEENTRIES_ERR    = 0xF5,

    /** Bootloader PNOR Access findTOC readTOC errors */
    BTLDR_TRC_PA_FINDTOC_READTOC_ERR         = 0xF6,

    /** Bootloader Utils parseEntries checksum error */
    BTLDR_TRC_UTILS_PARSE_CHECKSUM_ERROR     = 0xF7,

    /** Bootloader Utils parseEntries size extends beyond Flash */
    BTLDR_TRC_UTILS_PARSE_EXCEEDS_FLASH      = 0xF8,

    /** Bootloader PNOR Access getHBBSection findTOC error */
    BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_ERR   = 0xF9,

    /** Bootloader PNOR Access getHBBSection findTOC no HBB section */
    BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_NOHBB = 0xFA,

    /** Bootloader main verifyContainer failed */
    BTLDR_TRC_MAIN_VERIFY_FAIL               = 0xFB,

    /** Bootloader main verifyContainer secure rom invalid */
    BTLDR_TRC_MAIN_VERIFY_INVALID_SECROM     = 0xFC,

    /** Bootloader PNOR Access findTOC handleMMIO LPC ERR returned */
    BTLDR_TRC_PA_FINDTOC_TOC1_LPC_ERR        = 0xFD,

    /** Bootloader LPC Error(s) converted to System Checkstop */
    BTLDR_TRC_LPC_ERR_FORCE_XSTOP    = 0xFE,
};

#ifndef BOOTLOADER_TRACE
#define BOOTLOADER_TRACE(trace_value) \
{ \
    g_blData->bl_trace[g_blData->bl_trace_index++] = \
        trace_value; \
    g_blData->bl_trace_index %= BOOTLOADER_TRACE_SIZE; \
    lwsync(); \
}
#endif

#ifndef BOOTLOADER_TRACE_W_BRK
#define BOOTLOADER_TRACE_W_BRK(trace_value) \
{ \
    BOOTLOADER_TRACE(trace_value); \
    /* MAGIC_INSTRUCTION(MAGIC_BREAK); */ \
}
#endif

#endif
