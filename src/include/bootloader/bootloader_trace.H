/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloader_trace.H $                   */
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

#ifndef __BOOT_LOADER_TRACE_H
#define __BOOT_LOADER_TRACE_H

#include <arch/ppc.H>

/**
 * @file    bootloader_trace.H
 *
 *  TaskInfo structs for each task that will run.
 */

#ifndef BOOTLOADER_TRACE_SIZE
#define BOOTLOADER_TRACE_SIZE 64
#endif

extern uint8_t bootloader_trace_index;
extern uint8_t bootloader_trace[BOOTLOADER_TRACE_SIZE];

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

    /** Bootloader main applySecureSignatureValidation returned */
    BTLDR_TRC_MAIN_APPLYSECSIGVAL_RTN        = 0x14,

    /** Bootloader main copy HBB to running location done */
    BTLDR_TRC_MAIN_COPY_HBB_DONE             = 0x15,

    /** Bootloader handleMMIO started */
    BTLDR_TRC_HANDLEMMIO_START               = 0x20,

    /** Bootloader PNOR Access getHBBSection started */
    BTLDR_TRC_PA_GETHBBSECTION_START         = 0x30,

    /** Bootloader PNOR Access findTOC handleMMIO to copy TOC ONE returned */
    BTLDR_TRC_PA_FINDTOC_TOC1_HANDLEMMIO_RTN = 0x31,

    /** Bootloader PNOR Access findTOC readTOC for TOC ONE returned */
    BTLDR_TRC_PA_FINDTOC_TOC1_READTOC_RTN    = 0x32,

    /** Bootloader PNOR Access findTOC handleMMIO to copy TOC TWO returned */
    BTLDR_TRC_PA_FINDTOC_TOC2_HANDLEMMIO_RTN = 0x33,

    /** Bootloader PNOR Access findTOC readTOC for TOC TWO returned */
    BTLDR_TRC_PA_FINDTOC_TOC2_READTOC_RTN    = 0x34,

    /** Bootloader PNOR Access getHBBSection findTOC returned */
    BTLDR_TRC_PA_GETHBBSECTION_FINDTOC_RTN   = 0x35,

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

    /** Bootloader main getHBBSection returned */
    BTLDR_TRC_MAIN_GETHBBSECTION_FAIL        = 0xF0,

    /** Bootloader main removeECC returned */
    BTLDR_TRC_MAIN_REMOVEECC_FAIL            = 0xF1,

    /** Bootloader PNOR Access readTOC checkForNullBuffer null buffer */
    BTLDR_TRC_PA_READTOC_CHKNULLBUFFER_NULL  = 0xF2,

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
};

#ifndef BOOTLOADER_TRACE
#define BOOTLOADER_TRACE(trace_value) \
{ \
    bootloader_trace[bootloader_trace_index++] = trace_value; \
    bootloader_trace_index %= BOOTLOADER_TRACE_SIZE; \
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
