/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/accessors/p9_get_mem_vpd_keyword.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

///
/// @file p9_get_mem_vpd_keyword.H
/// @brief Return mem vpd keyword based on VPDInfo
///

// *HWP HWP Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP HWP Backup: Matt Light <mklight@us.ibm.com>
// *HWP FW Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team:
// *HWP Level: 3
// *HWP Consumed by: Cronus, FSP, HB

#ifndef _GET_MEM_VPD_KEYWORD_H_
#define _GET_MEM_VPD_KEYWORD_H_

#include <fapi2.H>
#include <fapi2_vpd_access.H>

namespace fapi2
{
/// vpd keyword to be read based on input parameters and MR/MT/DQ mapping.
/// For example, X0...XZ for MT or J0...JZ for MR vpd data.
/// Return as a string for convenient debug traces.
enum
{
    KEYWORD_BYTE_SIZE       = 2,
};
typedef char keywordName_t [KEYWORD_BYTE_SIZE + 1];

typedef struct kwInfo
{
    keywordName_t kwName; // keyword, like X0..XZ, J0..JZ, Q1..Q8, or CK
    uint16_t      kwBlobSize;    // blob size (valid for Q# and CK)
    uint16_t      kwBlobIndex;   // offset of blob from start of keyword data
} keywordInfo_t;

}

typedef fapi2::ReturnCode (*p9_get_mem_vpd_keyword_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_MCS>&,
    const fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS>&,
    const uint8_t*,
    const size_t,
    fapi2::keywordInfo_t&);
extern "C"
{

    /// @brief Return VPD keyword based on MCS, VPDInfo, and MR/MT mapping
    /// The MR and MT keyword contains a header followed by a table. Each
    /// row in the table has criteria to select a vpd keyword.
    ///
    /// 0         1         2         3         4         5
    /// mmmm.mmmm.mmmm.mmmm.rrrr.rrrr.rrrr.rrrr.ffff.xxxx.dddd.dddd
    ///
    /// m...m       mcs ATTR_MEMVPD_POS position
    ///             0x8000 mcs vpd position 0 (proc 0, postion 0)
    ///             ... through ..
    ///             0x1000 mcs vpd position 3 (proc 0, postion 3)
    ///             0x0800 mcs vpd position 4 (proc 1, postion 0)
    ///             ... through ..
    ///             0x0100 mcs vpd position 7 (proc 1, position 3)
    ///             ... through ..
    ///             0x0001 mcs vpd position 15(proc 3, position 3)
    /// r...r       Dimm rank count pair
    ///             0x8000 dimm0 rank count 0, dimm1 rank count 0
    ///             0x4000 dimm0 rank count 0, dimm1 rank count 1
    ///             ... through ..
    ///             0x0002 dimm0 rank count 4, dimm1 rank count 2
    ///             0x0001 dimm0 rank count 4, dimm1 rank count 4
    /// ffff        frequency index from ATTR_MEMVPD_FREQS_MHZ
    ///             0x80 index 0
    ///             ... through ..
    ///             0x10 index 3
    ///             (frequency index 4-7 reserved)
    /// dddd        second char in keyword name
    ///
    /// All the configurations for a particular keyword are 'OR'ed into the
    /// row for that keyword.
    /// Rows with all 0's do not need to be included. The last row has dddd = 0.
    /// Unsupported configurations can be mapped to dddd = 0xff.
    ///
    /// Note: this interface should not be called directly by HWPs,
    /// it is provided for platform use behind the getVPD() interface.
    /// DQ keyword uses Q0 as a map to Q1-Q8 keywords.  Q0 and CK have a header.
    ///
    /// @param[in]  i_target, the MCS
    /// @param[in]  i_vpd_info, vpd criteria
    /// @param[in]  i_pMapping, MR, MT, Q0, or CK keyword data
    /// @param[in]  i_mappingSize, size of i_pMapping buffer
    /// @param[out] o_keywordInfo, keyword with its vpd information
    /// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode p9_get_mem_vpd_keyword (
        const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS>& i_vpd_info,
        const uint8_t*               i_pMapping,
        const size_t                 i_mappingSize,
        fapi2::keywordInfo_t& o_keywordInfo);

}

#endif
