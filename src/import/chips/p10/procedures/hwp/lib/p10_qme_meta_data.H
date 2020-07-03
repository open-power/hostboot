/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_qme_meta_data.H $ */
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
/// @file   p10_qme_meta_data.H
/// @brief  define qme meta data structure.
///

// *HWP HWP Owner:        David Du   <daviddu@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:         Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:             PM
// *HWP Level:            2
// *HWP Consumed by:      PM:Hostboot:Phyp

#ifndef __QME_META_DATA_H__
#define __QME_META_DATA_H__

#include <p10_hcd_header_defs.H>

// -------------------------------------------------------------------
// Note: There can be NO semicolons(";") at end of macros in this file
//       There can ONLY have HCD_CONST/HCD_CONST64 macros in this file
// -------------------------------------------------------------------

/// Image Magic Numbers

HCD_CONST64(QMEATMT_MAGIC_NUMBER,                ULL(0x514d4541544d54))  // QMEATMT

typedef struct QmeAttrMeta
{
    char     magic_word[7];
    uint8_t  meta_data_version;

    // Do Not change the order below
    uint16_t system_num_of_attrs;
    uint16_t system_num_of_bytes;

    uint16_t proc_chip_num_of_attrs;
    uint16_t proc_chip_num_of_bytes;

    uint16_t perv_num_of_attrs;
    uint16_t perv_num_of_bytes;

    uint16_t ec_num_of_attrs;
    uint16_t ec_num_of_bytes;

    uint16_t ex_num_of_attrs;
    uint16_t ex_num_of_bytes;

    uint16_t eq_num_of_attrs;
    uint16_t eq_num_of_bytes;
} QmeAttrMeta_t;

#endif
