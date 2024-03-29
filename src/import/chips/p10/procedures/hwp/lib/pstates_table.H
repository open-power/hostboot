/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/pstates_table.H $     */
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
/// @file  pstates_table.h
/// @brief Definition of generated pstate tables written to HOMER PPMR
///
// *HWP HW Owner        : Rahul Batra <rbatra@us.ibm.com>
// *HWP HW Owner        : Michael Floyd <mfloyd@us.ibm.com>
// *HWP FW Owner        : Martha Broyles <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : PGPE:HS

#ifndef __PSTATES_TABLE_H__
#define __PSTATES_TABLE_H__

#include <pstates_common.H>
#include <pstates_pgpe.H>
#include <p10_hcode_image_defines.H>

/// Generated Pstate Table
///
/// This structure defines the Pstate Tables generated by PGPE Hcode upon
/// initialization.  This content depicts the values that will be computed
/// on the fly during Pstate protocol execution based on the Pstate Parameter
/// Block content.

#define MAX_PSTATE_TABLE_ENTRIES        128
#define MAX_PSTATE_TABLE_ENTRIES_V2     150  // (4400-2000)/16.667 = 144
#define MAX_VRATIO_VINDEX_TABLE_ENTRIES 299
#define GEN_PSTATES_TBL_MAGIC           0x50535441424c3030ULL //PSTABL00 (last two ASCII characters indicate version number)
#define GEN_PSTATES_TBL_MAGIC_V1        0x50535441424c3031ULL //PSTABL00 (last two ASCII characters indicate version number)
#define GEN_PSTATES_TBL_MAGIC_V2        0x50535442 //PSTB -- note: this is different that "PSTA" used for the base and V1

#ifndef __ASSEMBLER__
#ifdef __cplusplus
extern "C" {
#endif

/// Pstate Table
///
/// This structure defines the Pstate Table content
/// -- 16B structure

typedef struct
{
    /// Pstate number
    Pstate_t pstate;

    uint8_t padding;

    /// Assocated Frequency (in MHz)
    uint16_t    frequency_mhz;

    /// External VRM setpoint (in mV).  this directly translates to AVSBus value
    uint16_t    external_vdd_mv;

    /// Effective VDD voltage at the module pins.  This accounts for the system
    /// parameter effects.
    uint16_t    effective_vdd_mv;
} PstateTable_t;

typedef struct
{
    uint16_t vratio;
    uint16_t vindex;
} VRatioVIndexTable_t;

typedef struct
{

    /// Magic Number
    uint64_t magic;   // ASCII: "PSTABL00 "

    /// The fastest frequency - after biases have been applied
    uint32_t pstate0_frequency_khz;

    /// Highest Pstate Number => slowest Pstate generated
    uint32_t highest_pstate;

    // PGPE content
    GlobalPstateParmBlock_t globalppb;

    // Global Parameter End Marker
    uint32_t marker_gppb_end;

    /// Generated table with system paramters included but without biases
    PstateTable_t raw_pstates[MAX_PSTATE_TABLE_ENTRIES];

    uint32_t marker_raw_pstates_end;

    /// Generated table with system paramters and biases
    /// Note: if all bias attributes are 0, this content will be the same
    /// as the raw_pstates content.
    PstateTable_t biased_pstates[MAX_PSTATE_TABLE_ENTRIES];

    ///Generate table with vratio and vindex for all
    ///combinations of activeCores and sortCores
    VRatioVIndexTable_t vratio_vindex[MAX_VRATIO_VINDEX_TABLE_ENTRIES];

#ifndef __PPE_PLAT
    hcodeImageBuild::PgpeHeader_t pgpe_header;
#else
    ///PGPE Header
    PgpeHeader_t pgpe_header;
#endif
} GeneratedPstateInfo_t;

typedef struct
{

    /// Magic Number
    uint64_t magic;   // ASCII: "PSTABL00 "

    /// The fastest frequency - after biases have been applied
    uint32_t pstate0_frequency_khz;

    /// Highest Pstate Number => slowest Pstate generated
    uint32_t highest_pstate;

    /// Generated table with system paramters included but without biases
    PstateTable_t raw_pstates[MAX_PSTATE_TABLE_ENTRIES];

    /// Generated table with system paramters and biases
    /// Note: if all bias attributes are 0, this content will be the same
    /// as the raw_pstates content.
    PstateTable_t biased_pstates[MAX_PSTATE_TABLE_ENTRIES];

    ///Generate table with vratio and vindex for all
    ///combinations of activeCores and sortCores
    VRatioVIndexTable_t vratio_vindex[MAX_VRATIO_VINDEX_TABLE_ENTRIES];

#ifndef __PPE_PLAT
    hcodeImageBuild::PgpeHeader_t pgpe_header;
#else
    ///PGPE Header
    PgpeHeader_t pgpe_header;
#endif

    // PGPE content
    GlobalPstateParmBlock_v1_t globalppb;
} GeneratedPstateInfo_v1_t;

typedef struct
{

    /// Magic Number
    uint32_t magic;   // ASCII: "PSTB"
    uint16_t padding;
    uint16_t table_entries;  // filled in with

    /// The fastest frequency - after biases have been applied
    uint32_t pstate0_frequency_khz;

    /// Highest Pstate Number => slowest Pstate generated
    uint32_t highest_pstate;

    /// Generated table with system paramters included but without biases
    PstateTable_t raw_pstates[MAX_PSTATE_TABLE_ENTRIES_V2];

    /// Generated table with system paramters and biases
    /// Note: if all bias attributes are 0, this content will be the same
    /// as the raw_pstates content.
    PstateTable_t biased_pstates[MAX_PSTATE_TABLE_ENTRIES_V2];

    ///Generate table with vratio and vindex for all
    ///combinations of activeCores and sortCores
    VRatioVIndexTable_t vratio_vindex[MAX_VRATIO_VINDEX_TABLE_ENTRIES];

#ifndef __PPE_PLAT
    hcodeImageBuild::PgpeHeader_t pgpe_header;
#else
    ///PGPE Header
    PgpeHeader_t pgpe_header;
#endif

    // PGPE content
    GlobalPstateParmBlock_v1_t globalppb;
} GeneratedPstateInfo_v2_t;

#ifdef __cplusplus
} // end extern C
#endif
#endif    /* __ASSEMBLER__ */
#endif    /* __PSTATES_TABLE_H__ */
