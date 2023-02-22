/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_fru_to_ipz_mapping.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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

#include <oem/ibm/libpldm/file_io.h>

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
    PSPD = 0x50535044,
    UTIL = 0x5554494C,
};

enum valid_special_keywords : uint16_t
{
    pdD  = 0x2344,
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

const uint16_t valid_util_keywords[]
                 { 0xFFFF,  // invalid
                   0xFFFF,  // invalid
                   0x5254,  // RT
                   0x4430,  // D0
                   0x4431,  // D1
                   0x4432,  // D2
                   0x4433,  // D3
                   0x4434,  // D4
                   0x4435,  // D5
                   0x4436,  // D6
                   0x4437,  // D7
                   0x4438,  // D8
                   0x4439,  // D9
                   0x4630,  // F0
                   0x4631,  // F1
                   0x4632,  // F2
                   0x4633,  // F3
                   0x4634,  // F4
                   0x4635,  // F5
                   0x4636,  // F6
                   0x4637,  // F7
                   0x4638,  // F8
                   0x4639,  // F9
                   0x5046,  // PF
                  };

// Must match valid_vsys_keywords and PLDM FRU IPZ Keyword Mapping Doc
enum valid_vsys_keywords_values
{
    VSYS_KEYWORDS_INVALID_0 = 0,
    VSYS_KEYWORDS_INVALID_1 = 1,
    VSYS_KEYWORDS_RT        = 2,
    VSYS_KEYWORDS_BR        = 3,
    VSYS_KEYWORDS_DR        = 4,
    VSYS_KEYWORDS_FV        = 5,
    VSYS_KEYWORDS_ID        = 6,
    VSYS_KEYWORDS_MN        = 7,
    VSYS_KEYWORDS_NN        = 8,
    VSYS_KEYWORDS_RB        = 9,
    VSYS_KEYWORDS_RG        = 10,
    VSYS_KEYWORDS_SE        = 11,
    VSYS_KEYWORDS_SG        = 12,
    VSYS_KEYWORDS_SU        = 13,
    VSYS_KEYWORDS_TM        = 14,
    VSYS_KEYWORDS_TN        = 15,
    VSYS_KEYWORDS_WN        = 16,
};



// Order must match PLDM FRU IPZ Keyword Mapping Doc
const uint16_t valid_lxr0_keywords[]
                { 0xFFFF,  // invalid
                  0xFFFF,  // invalid
                  0x5254,  // RT
                  0x4C58,  // LX
                  0x565A   // VZ
                };

// Order must match PLDM FRU IPZ Keyword Mapping Doc
const uint16_t valid_pspd_keywords[]
                { 0xFFFF,  // invalid
                  0xFFFF,  // invalid
                  0x5254,  // RT
                  0x5046,  // PF - not used
                  0x564D,  // VM - not used
                  0x565A,  // VZ - not used
                };

// special_add_xxx_keywords are a special type of
// additional # keywords that will be appended
// to the end of existing keywords for a record
//
// Special # keywords allowed to be explicitly ADDED
// Must also be entered in special_record_keywords_map
// Must also be entered in special_record_keyword_parm_map

const uint16_t special_add_pspd_keywords[]
                { pdD,  // #D
                };

// vpdParms are the parameters that are used to retrieve the special # keyword
// data blobs (content only)
struct vpdParms {
                   uint32_t filehandle;        // input for getLidFileFromOffset
                   pldm_fileio_file_type type; // input for getLidFileFromOffset
                   uint32_t record;            // record value for meta data
                   uint16_t keyword;           // keyword value for meta data
};

}

#endif
