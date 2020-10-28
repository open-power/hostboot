/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/tools/wof/p10_wof_table_set_structure.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef _P10_WOF_TABLE_SET_STRUCTURE_H_
#define _P10_WOF_TABLE_SET_STRUCTURE_H_

/*
        WOF Tables In PNOR
    ---------------------------
    |      Image Header       |  Points to Section Table
    |-------------------------|
    |  Section Table Entry 1  |  Section Table
    |  Section Table Entry 2  |    Each entry points to
    |  ...                    |    a WOF Table
    |-------------------------|
    |   WOF Tables Header 1   |  WOF Table
    |        VRT Block 1      |    Returned if match
    |        VRT Block 2      |
    |        ...              |
    |-------------------------|
    |   WOF Tables Header 2   |  WOF Table
    |        VRT Block 1      |    Returned if match
    |        VRT Block 2      |
    |        ...              |
    |-------------------------|
    |   ...                   |
    ---------------------------
    The structs for the Image Header and
    Section Table Entry are defined below.
    The struct for the WOF Tables Header
    is defined in pstates_common.h.
*/

typedef struct __attribute__((__packed__))  wofImageHeader
{
    // "WTIH", WOF Tables Image Header.
    uint32_t    magicNumber;
    // 0x01, Version of this header.
    uint8_t     version;
    // Varies, Number of entries in the Section Table.
    uint8_t     entryCount;
    // Varies, Absolute offset to the Section Table.
    uint32_t    offset;
    // Varies, Provided from the –tsi input parameter. Otherwise, all NULLs.
    char        setId[16];
    // 0s, Reserved.
    char        pad[6];
} wofImageHeader_t;

typedef struct __attribute__((__packed__))  wofSectionTableEntry
{
    // Absolute offset to section containing WOF Tables.
    uint32_t    offset;
    // Size of the WOF Tables section, excluding any padding at the end.
    uint32_t    size;
} wofSectionTableEntry_t;

#endif //_P10_WOF_TABLE_SET_STRUCTURE_H_
