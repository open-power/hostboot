/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloader_data.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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

#ifndef __BOOTLOADER_DATA_H
#define __BOOTLOADER_DATA_H

/**
 * @file    bootloader_data.H
 *
 *  Data struct for Bootloader data placed outside of Bootloader image.
 */

#include <bootloader/bootloader_trace.H>
#include <bootloader/bootloaderif.H>
#include <bootloader/bl_pnorAccess.H>
#include <kernel/hbterminatetypes.H>


namespace Bootloader{
    typedef struct blData
    {
        // @name bl_trace
        // @brief Buffer for Bootloader Trace data
        // Buffer with bootloader trace entries.  There are 64 one-byte entries
        // in the buffer.  They are used to track events that have occurred in
        // the bootloader code.  After all entries have been used, the buffer
        // wraps and the oldest entry is overwritten by the newest trace data.
        uint8_t bl_trace[BOOTLOADER_TRACE_SIZE];

        // @name bl_trace_index
        // @brief Index for Bootloader Trace entries
        // One-byte index for next entry to use in bootloader_trace.
        uint8_t bl_trace_index;
        uint8_t bl_reserved1[1];

        // @name bl_trace_index_saved
        // @brief Saved index for Bootloader Trace entries
        // One-byte index for a saved bootloader_trace entry.
        uint8_t bl_trace_index_saved;
        uint8_t bl_reserved2[1];

        // @name bl_pnor_loop_count
        // @brief Bootloader loop counter
        // Counter for loop that walks PNOR to find a valid TOC.
        uint32_t bl_pnor_loop_count;

        // @name bl_first_pnor_mmio
        // @brief Address used by first PNOR MMIO
        // Address used on first attempt to read TOC from PNOR.
        uint64_t bl_first_pnor_mmio;

        // Instance of the TI Data Area
        HB_TI_DataArea bl_TIDataArea;
        static_assert( sizeof(HB_TI_DataArea) == 48, "HB_TI_DataArea "
                       "size changed.  Check bootloader_data.H alignment.  "
                       "Fix BlData.pm processing.");

        // Buffer to save HBB PNOR section data
        PNOR::SectionData_t bl_hbbSection;
        uint8_t bl_reserved3[(64 - sizeof(PNOR::SectionData_t)) % 16];
        static_assert( sizeof(PNOR::SectionData_t) == 26, "SectionData_t "
                       "size changed.  Check bootloader_data.H alignment.  "
                       "Fix BlData.pm processing.");

        // Bool indicating if the secureROM is valid. Toggles verification.
        bool secureRomValid;
        uint8_t bl_reserved4[15];

        // Object that will be stored where the SBE HB structure indicates
        BlToHbData blToHbData;
        uint8_t bl_reserved5[(512 - sizeof(BlToHbData)) % 16];
        static_assert( sizeof(BlToHbData) == 173, "BlToHbData "
                       "size changed.  Check bootloader_data.H alignment.  "
                       "Fix BlData.pm processing.");
    } blData_t;
} // end namespace Bootloader

/**
 * @brief Pointer to bootloader external data
 *
 * Pointer to location in main storage which bootloader uses for
 * storing data
 */
extern Bootloader::blData_t *g_blData;

/**
 * @brief Pointer to bootloader scratch space
 *
 * Pointer to location in main storage which bootloader uses as
 * scratch space
 */
extern uint8_t *g_blScratchSpace;

#endif
