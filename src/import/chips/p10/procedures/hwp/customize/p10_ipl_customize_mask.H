/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_ipl_customize_mask.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024,2025                        */
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
/* EKB-Mirror-To: hostboot                                                */
#ifndef _P10_IPL_CUSTOMIZE_MASK_H_
#define _P10_IPL_CUSTOMIZE_MASK_H_

//////////////////////////////////////
//////////////XIP HEADER//////////////
//////////////////////////////////////
// Identification - 8-byte aligned; 8 entries <=== 8*8=64 bytes
// uint64_t iv_magic;
// uint64_t iv_L1LoaderAddr;
// uint64_t iv_L2LoaderAddr;
// uint64_t iv_kernelAddr;
// uint64_t iv_dataAddr;
// uint64_t iv_linkAddress;
// uint64_t iv_reserved64[2];
//
// Section Table - 4-byte aligned; 18 entries <== 12*18=216 bytes
// IPL_IMAGE_SECTIONS = 18
// P9XipSection iv_section[IPL_IMAGE_SECTIONS];
// P9XipSection:
// uint32_t iv_offset;
// uint32_t iv_size;
// uint8_t iv_alignment;
// int8_t iv_ddSupport;
// uint8_t iv_reserved8[2];
//
// Other information - 4-byte aligned; 8 entries
// uint32_t iv_imageSize;
// uint32_t iv_buildDate; <== MASK 4 BYTES
// uint32_t iv_buildTime; <== MASK 4 BYTES
// char iv_buildTag[20];  <== MASK 20 BYTES
//
// Other Information - 1-byte aligned; 8 entries <== 1*8=8 bytes
// uint8_t iv_headerVersion;
// uint8_t iv_normalized;
// uint8_t iv_tocSorted;
// uint8_t iv_reserved8[5];
//
// Strings; 64 characters allocated
// char iv_buildUser[16]; <== MASK 16 BYTES
// char iv_buildHost[32]; <== MASK 32 BYTES
// char iv_buildHeadCommit[8]; <== MASK 8 BYTES
// char iv_reservedChar[8];
//


typedef struct
{
    //XIP Section name
    p9_xip_section_sbe_t section;

    //For Offset:[0] Marker:[1]
    bool selectOffsetMarker;

    //Offset start in respective section image OR
    //Marker to search for in respective section image
    uint8_t*  startOffsetMarker;

    //Number of bytes to mask from start offset/marker found in section image
    uint32_t numberOfBytesToMask;
} xipSectionMask_t;

// XIP Section Header offsets
const uint32_t xipSectionHeaderOffset0 = 0x0164;
const uint32_t xipSectionHeaderOffset1 = 0x0188;

// .data section: marker
// Marker: "Welcome to SBE - CommitId[0x"
const char dataSectionMarker[] = "Welcome to SBE - CommitId[0x";

// .hbbl section: marker
// Marker: "HBBL ID STRING ="
const char hbblSectionMarker[] = "HBBL ID STRING =";

// HDCT offset
const uint32_t xipSectionHdctOffset = 0x4;

// Secure boot header offsets
const uint32_t xipSectionSbhOffsetV1HWSigABC    = 0x020C; // offset=524(d)
const uint32_t xipSectionSbhOffsetV1PayloadHash = 0x43D; // offset=1085(d)
const uint32_t xipSectionSbhOffsetV1FWSigP      = 0x047E; // offset=1150(d)
const uint32_t xipSectionSbhOffsetV3HWSigA      = 0x102C; // offset=4140(d)
const uint32_t xipSectionSbhOffsetV3PayloadHash = 0x2D90; // offset=11664(d)
const uint32_t xipSectionSbhOffsetV3FWSigP      = 0x2DE7; // offset=11751(d)

#define NUMBER_OF_XIP_SECTIONS 15
#define SEL_OFFSET 0
#define SEL_MARKER 1

// Use global var to access respective images mask info and apply to seeprom img
constexpr xipSectionMask_t g_xipSectionMask[NUMBER_OF_XIP_SECTIONS] =
{
    {P9_XIP_SECTION_SBE_HEADER,       SEL_OFFSET,  (uint8_t*)& xipSectionHeaderOffset0,          28}, \
    {P9_XIP_SECTION_SBE_HEADER,       SEL_OFFSET,  (uint8_t*)& xipSectionHeaderOffset1,          56}, \
    {P9_XIP_SECTION_SBE_DATA,         SEL_MARKER,  (uint8_t*)& dataSectionMarker[0],              8}, \
    {P9_XIP_SECTION_SBE_HBBL,         SEL_MARKER,  (uint8_t*)& hbblSectionMarker[0],            128}, \
    {P9_XIP_SECTION_SBE_HDCT,         SEL_OFFSET,  (uint8_t*)& xipSectionHdctOffset,              8}, \
    {P9_XIP_SECTION_SBE_SBH_FIRMWARE, SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV1HWSigABC,   396}, \
    {P9_XIP_SECTION_SBE_SBH_FIRMWARE, SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV1FWSigP,     132}, \
    {P9_XIP_SECTION_SBE_SBH_FIRMWARE, SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV3HWSigA,     132}, \
    {P9_XIP_SECTION_SBE_SBH_FIRMWARE, SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV3FWSigP,     132}, \
    {P9_XIP_SECTION_SBE_SBH_HBBL,     SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV1HWSigABC,   396}, \
    {P9_XIP_SECTION_SBE_SBH_HBBL,     SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV1PayloadHash, 64}, \
    {P9_XIP_SECTION_SBE_SBH_HBBL,     SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV1FWSigP,     132}, \
    {P9_XIP_SECTION_SBE_SBH_HBBL,     SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV3HWSigA,     132}, \
    {P9_XIP_SECTION_SBE_SBH_HBBL,     SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV3PayloadHash, 64}, \
    {P9_XIP_SECTION_SBE_SBH_HBBL,     SEL_OFFSET,  (uint8_t*)& xipSectionSbhOffsetV3FWSigP,    4759}
};

#endif // _P10_IPL_CUSTOMIZE_MASK_H_
