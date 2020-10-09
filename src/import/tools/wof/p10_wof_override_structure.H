/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/tools/wof/p10_wof_override_structure.H $           */
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
#ifndef _P10_WOF_OVERRIDE_STRUCTURE_H_
#define _P10_WOF_OVERRIDE_STRUCTURE_H_

/*
        WOF Override Container
    ---------------------------
    |      Override Header    |  Points to Override Table
    |      Override Header    |  Points to Override Table
    |-------------------------|
    |  WTS Entry 1            |  Override Table
    |  WTS Entry 2            |    Each entry points to
    |  ...                    |    a WOF Table Set
    |-------------------------|
    |   WTS Entry Header 1    |  WTS Entry
    |        WOF Table Set 1  |    Returned if match
    |        WOF Table Set 2  |
    |        ...              |
    |-------------------------|
    |   WTS Entry Header 2    |  WTS Entry
    |        WOF Table Set 1  |    Returned if match
    |        WOF Table Set 2  |
    |        ...              |
    |-------------------------|
    |   ...                   |
    ---------------------------
    The structs for the Override Header and Override Table Entry are defined
    below.

    The structs for the WOF Table Image Header and WOF Table Entry
    are defined in p10_wof_table_set_structure.H

    The struct for the WOF Tables Header is defined in pstates_common.h.
*/

typedef struct __attribute__((__packed__))  wofContainerHeader
{
    // "WTSO", WOF Table Set Override.
    char[4]     magicNumber;
    // 0x01, Version of this header.

    uint8_t     version;
    // Varies, Number of entries in the Override Table.

    uint8_t     entryCount;
    // 0s, Reserved.

    char[2]     pad1;
    // Varies, Absolute offset to the Override Table
    uint16_t    offset;

    // 0s, Reserved.
    char[6]     pad2;

    // Varies, Provided from the -woi input parameter. Otherwise, all NULLs.
    char[16]    coverrideId;

} wofContainerHeader_t;

typedef struct __attribute__((__packed__))  wofOverrideTableEntry
{
    // Absolute offset to section containing WOF Table Set block
    uint32_t    offset;

    // Size of the WOF Table Set block, excluding any padding at the end.
    uint32_t    size;

    // DD Level Major (eg if DD21 -> 2)
    uint8_t     dd_major;

    // DD Level Minor (eg if DD21 -> 1)
    uint8_t     dd_minor;

    // 0s, Reserved.
    char[1]     pad1;

    // Core count from the WOF Table Set Header
    uint8_t     core_count;

    /// Socket Power (in Watts) for the WOF Tables
    uint16_t    socket_power_w;

    /// Core Sort Power Target Frequency (in MHz),
    uint16_t    sort_power_freq_mhz;

    /// Up to 16 ASCII characters as a Package designator
    char        package_name[16];

} wofOverrideTableEntry_t;

#endif //_P10_WOF_OVERRIDE_STRUCTURE_H_
