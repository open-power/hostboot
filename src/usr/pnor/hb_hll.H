/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/hb_hll.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2025                             */
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

/*
 * @ file hb_hll.H - Defines the structures and constants for the Hostboot
 *                   Hash Lid List - aka HB_HLL - PNOR sectionn
 */
#ifndef __HB_HLL_H
#define __HB_HLL_H
#include <stdint.h>
#include "spnorrp.H"

/******************************************************************************/
/*
 * ****    HB_HLL Structure - Hostboot Hash Lid List   ****
 *
 * Purpose: Keeps sha3() hashes of PNOR partitions/lids that Hostboot might
 *          load during the course of the IPL.  These hashes will be referenced
 *          to validate the secure sections of the loaded partition/lids.
 *
 * HB_HLL Layout:
 *
 * [ V3 Secure Header (15KB) ]          <-- generated and appended in genPnorImages.pl
 * [ HB_HLL_Metadata_t (128 bytes)]     <-- general information about the HB_HLL layout
 * [ HB_HLL_SectionEntry_t (96 bytes)]  <-- info corresponding to one pnor section
 * [ HB_HLL_SectionEntry_t (96 bytes)]
 * [ HB_HLL_SectionEntry_t (96 bytes)], etc
 *
 */

struct HB_HLL_Metadata_t
{
    uint64_t eyeCatcher;              //<-- "HB_HLL" <-- 8 bytes
    uint16_t version;                 // <-- start at 1
    uint16_t compatibleVersion;       //<-- start at 1
    uint16_t numberOfEntries;         // number of HB_HLL_SectionEntry_t structs after
                                      //   HB_HLL_Metadata_t
    uint16_t hashSignMode;            // SHA3_512 <-- 0x0001
    uint16_t sectionEntrySize;        //<-- 96 bytes for version 1
    uint16_t offsetToHashListEntries; //<-- 128 bytes from start HB_HLL_HEADER struct to first
                                      //    HB_HLL_SectionEntry_t struct
    uint8_t  reserved[108];
} __attribute__ ((packed));

// HB HLL Section Entry
struct HB_HLL_SectionEntry_t
{
    uint8_t  partName[PART_NAME_MAX+1];// <-- 16 bytes
    uint64_t protectedSize;
    uint64_t sectionSize;
    uint8_t  hash[64]; // <-- 64 bytes
} __attribute__ ((packed));


// Constants to keep in sync with genPnorImages.pl - see @HB_HLL_SYNC@
const uint64_t HB_HLL_EYE_CATCHER = 0x48425F484C4C0000ull;  //'HB_HLL\0'

constexpr size_t HB_HLL_SIZE_OF_METADATA = 128; // bytes
static_assert(sizeof(HB_HLL_Metadata_t)==HB_HLL_SIZE_OF_METADATA,
              "HB_HLL_SIZE_OF_METADATA is not 128 bytes");

constexpr size_t HB_HLL_OFFSET_TO_LIST_ENTRIES = 128; // bytes
static_assert(HB_HLL_OFFSET_TO_LIST_ENTRIES==HB_HLL_SIZE_OF_METADATA,
              "HB_HLL_OFFSET_TO_LIST_ENTRIES is not 128 bytes");

constexpr size_t HB_HLL_VERSION = 1;
constexpr size_t HB_HLL_COMPATIBLE_VERSION = 1;
constexpr size_t HB_HLL_HASH_SIGN_MODE = 1;      // SHA3_512
constexpr size_t HB_HLL_SECTION_ENTRY_STRUCT_SIZE = 96; // bytes
static_assert(sizeof(HB_HLL_SectionEntry_t)==HB_HLL_SECTION_ENTRY_STRUCT_SIZE,
              "HB_HLL_SECTION_ENTRY_STRUCT_SIZE is not 96 bytes");


/******************************************************************************/

#endif // __HB_HLL_H
