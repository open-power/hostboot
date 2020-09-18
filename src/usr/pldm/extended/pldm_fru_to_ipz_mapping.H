/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_fru_to_ipz_mapping.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#ifndef PLDM_FRU_TO_IPZ_MAPPING__
#define PLDM_FRU_TO_IPZ_MAPPING__

/**
 * @file pldm_fru_to_ipz_mapping.H
 *
 * @brief This header provides the constants needs to map IBM's OEM PLDM Fru
 *        Record type to the IPZ records. These are all based off of the
 *        PLDM FRU IPZ Keyword Mapping Doc
 */

namespace PLDM
{

// Currently these are the only VPD Records Hostboot Supports
// converting PLDM Fru Records to a IPZ VPD binary blob
// If more are added in the future be sure to update record_keyword_field_map
// with the appropriate PLDM Fru Record Field Type Numbers with IPZ Keywords
enum valid_records : uint32_t
{
    VINI = 0x56494E49,
    VSYS = 0x56535953,
    LXR0 = 0x4C585230,
};

constexpr uint8_t RT_FIELD_TYPE = 2;

// Order must match PLDM FRU IPZ Keyword Mapping Doc
const uint16_t valid_vini_keywords[]
                { 0xFFFF,  // invalid
                  0xFFFF,  // invalid
                  0x5254,  // RT
                  0x4233,  // B3
                  0x4234,  // B4
                  0x4237,  // B7
                  0x4343,  // CC
                  0x4345,  // CE
                  0x4354,  // CT
                  0x4452,  // DR
                  0x4647,  // FG
                  0x464E,  // FN
                  0x4845,  // HE
                  0x4857,  // HW
                  0x4858,  // HX
                  0x504E,  // PN
                  0x534E,  // SN
                  0x5453,  // TS
                  0x565A   // VZ
                };

// Order must match PLDM FRU IPZ Keyword Mapping Doc
const uint16_t valid_vsys_keywords[]
                { 0xFFFF,  // invalid
                  0xFFFF,  // invalid
                  0x5254,  // RT
                  0x4252,  // BR
                  0x4452,  // DR
                  0x4656,  // FV
                  0x4944,  // ID
                  0x4D4E,  // MN
                  0x4E4E,  // NN
                  0x5242,  // RB
                  0x5247,  // RG
                  0x5345,  // SE
                  0x5347,  // SG
                  0x5355,  // SU
                  0x544D,  // TM
                  0x544E,  // TN
                  0x574E   // WN
                };

// Order must match PLDM FRU IPZ Keyword Mapping Doc
const uint16_t valid_lxr0_keywords[]
                { 0xFFFF,  // invalid
                  0xFFFF,  // invalid
                  0x5254,  // RT
                  0x4C58,  // LX
                  0x565A   // VZ
                };
}

#endif