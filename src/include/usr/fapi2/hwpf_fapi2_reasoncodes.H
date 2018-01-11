/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/hwpf_fapi2_reasoncodes.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// @file hwpf_fapi2_reasoncodes.H
///
/// @brief Define error reason codes for FAPI2 HWPs
///
///

#ifndef HWPF_FAPI2_REASONCODES_H_
#define HWPF_FAPI2_REASONCODES_H_

#include <hbotcompid.H>

namespace fapi2
{
    /**
     * @brief Defines the FAPI2 HWPF error log module IDs
     */
    enum fapi2ModuleId
    {
        MOD_FAPI2_RC_TO_ERRL                        = 0x01,
        MOD_FAPI2_GET_TARGETING_TARGET              = 0x02,
        MOD_FAPI2_PLAT_GET_TARGET_NAME              = 0x03,
        MOD_FAPI2_PLAT_HWP_TEST                     = 0x04,
        MOD_FAPI2_PLAT_GET_PARENT_TEST              = 0x05,
        MOD_FAPI2_PLAT_GET_CHILDREN_TEST            = 0x06,
        MOD_FAPI2_VERIFYCFAMACCESSTARGET            = 0x07,
        MOD_FAPI2_PLAT_GET_OTHER_END_TEST           = 0x08,
        MOD_FAPI2_PLAT_GET_OTHER_END                = 0x09,
        MOD_FAPI2_MVPD_ACCESS                       = 0x0A,
        MOD_FAPI2_PLAT_GET_CHILDREN_FILTER_TEST     = 0x0B,
        MOD_FAPI2_GET_TARGETING_ATTR                = 0x0C,
        MOD_FAPI2_SET_TARGETING_ATTR                = 0x0D,
        MOD_FAPI2_PLAT_GET_VPD                      = 0x0E,
        MOD_FAPI2_PIB_ERR_MASK                      = 0x0F,
        MOD_FAPI2_PLAT_PARSE_WOF_TABLES             = 0x10,
        MOD_FAPI2_CVPD_ACCESS                       = 0x11,
        MOD_FAPI2_BAD_DQ_BITMAP                     = 0x12,
        MOD_FAPI2_GET_CHIP_CFAM_TARGET              = 0x13,
        MOD_FAPI2_GET_ATTR_CEN_VPD_VERSION          = 0x14,
        MOD_FAPI2_GET_MB_VPD_ATTR                   = 0x15,
        MOD_FAPI2_GET_PLL_BUCKET                    = 0x16,
        MOD_FAPI2_GET_RING                          = 0x17,
    };

    /**
     * @brief Defines the HWPF error log reason codes
     */
    enum fapi2ReasonCode
    {
        // FAPI generated errors (must match return_code_defs.H)
        RC_INVALID_ATTR_GET            = HWPF_COMP_ID | 0x01,
        RC_INVALID_CHIP_EC_FEATURE_GET = HWPF_COMP_ID | 0x02,
        RC_INVALID_TARG_TARGET         = HWPF_COMP_ID | 0x07,
        RC_MISMATCHED_FAPI_TARG_TARGET = HWPF_COMP_ID | 0x08,
        RC_UNKNOWN_MODEL               = HWPF_COMP_ID | 0x09,
        RC_NULL_FAPI_TARGET            = HWPF_COMP_ID | 0x0A,
        RC_LOOKING_FOR_TYPE_NA         = HWPF_COMP_ID | 0x0B,
        RC_INCORRECT_TARGET            = HWPF_COMP_ID | 0x0C,
        RC_FAILED_MASKING_ERROR        = HWPF_COMP_ID | 0x12,

        // MVPD generated errors
        RC_INVALID_RECORD              = HWPF_COMP_ID | 0x0D,
        RC_INVALID_KEYWORD             = HWPF_COMP_ID | 0x0E,
        RC_RECORD_OUT_OF_BOUNDS        = HWPF_COMP_ID | 0x10,
        RC_KEYWORD_OUT_OF_BOUNDS       = HWPF_COMP_ID | 0x11,


        //Platform generated errors
        RC_NO_PROCS_FOUND              = FAPI2_COMP_ID | 0x0B,
        RC_NO_PATH_TO_TARGET_FOUND     = FAPI2_COMP_ID | 0x0C,
        RC_CORE_NO_EX_FOUND            = FAPI2_COMP_ID | 0x0D,
        RC_CORE_NO_EQ_FOUND            = FAPI2_COMP_ID | 0x0E,
        RC_CORE_NO_PROC_FOUND          = FAPI2_COMP_ID | 0x10,
        RC_EX_NO_EQ_FOUND              = FAPI2_COMP_ID | 0x11,
        RC_EX_NO_PROC_FOUND            = FAPI2_COMP_ID | 0x12,
        RC_EQ_NO_PROC_FOUND            = FAPI2_COMP_ID | 0x13,
        RC_MCA_NO_MCS_FOUND            = FAPI2_COMP_ID | 0x14,
        RC_MCA_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x15,
        RC_MCS_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x16,
        RC_MCBIST_NO_PROC_FOUND        = FAPI2_COMP_ID | 0x17,
        RC_PHB_NO_PEC_FOUND            = FAPI2_COMP_ID | 0x18,
        RC_PHB_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x19,
        RC_PEC_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x1a,
        RC_XBUS_NO_PROC_FOUND          = FAPI2_COMP_ID | 0x1b,
        RC_OBUS_NO_PROC_FOUND          = FAPI2_COMP_ID | 0x1c,
        RC_OBRICK_NO_PROC_FOUND        = FAPI2_COMP_ID | 0x1d,
        RC_PPE_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x1e,
        RC_PERV_NO_PROC_FOUND          = FAPI2_COMP_ID | 0x1f,
        RC_CAPP_NO_PROC_FOUND          = FAPI2_COMP_ID | 0x20,
        RC_SBE_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x21,
        RC_INVALID_CHILD_COUNT         = FAPI2_COMP_ID | 0x22,
        RC_UNIT_NO_PERV_FOUND          = FAPI2_COMP_ID | 0x23,
        RC_INCORRECT_OTHER_END         = FAPI2_COMP_ID | 0x24,
        RC_FOUND_TOO_MANY_PEERS        = FAPI2_COMP_ID | 0x25,
        RC_FOUND_NO_PEERS              = FAPI2_COMP_ID | 0x26,
        RC_BUFFER_TOO_SMALL            = FAPI2_COMP_ID | 0x27,
        RC_INVALID_TYPE                = FAPI2_COMP_ID | 0x28,
        RC_RETURNED_VPD_TOO_SMALL      = FAPI2_COMP_ID | 0x29,
        RC_INVALID_ATTRIBUTE           = FAPI2_COMP_ID | 0x2A,
        RC_WOF_IMAGE_MAGIC_MISMATCH    = FAPI2_COMP_ID | 0x2B,
        RC_WOF_TABLES_MAGIC_MISMATCH   = FAPI2_COMP_ID | 0x2C,
        RC_WOF_TABLE_NOT_FOUND         = FAPI2_COMP_ID | 0x2D,
        RC_WOF_IMAGE_VERSION_MISMATCH  = FAPI2_COMP_ID | 0x2E,
        RC_WOF_TABLES_VERSION_MISMATCH = FAPI2_COMP_ID | 0x2F,
        RC_MM_ALLOC_BLOCK_FAILED       = FAPI2_COMP_ID | 0x30,
        RC_MM_SET_PERMISSION_FAILED    = FAPI2_COMP_ID | 0x31,
        RC_MM_REMOVE_PAGES_FAILED      = FAPI2_COMP_ID | 0x32,
        RC_MM_SET_PERMISSION2_FAILED   = FAPI2_COMP_ID | 0x33,
        RC_NO_SINGLE_MBA               = FAPI2_COMP_ID | 0x34,
        RC_NO_PARENT_MBA               = FAPI2_COMP_ID | 0x35,
        RC_NO_CHILD_MBA                = FAPI2_COMP_ID | 0x36,
        RC_INVALID_TARGET_TYPE         = FAPI2_COMP_ID | 0x37,
        RC_NO_PARENT_MEMBUF            = FAPI2_COMP_ID | 0x38,
        RC_INVALID_PARENT_TARGET_FOUND = FAPI2_COMP_ID | 0x39,
        RC_GET_RING_SECTION_FAILED     = FAPI2_COMP_ID | 0x3A,
        RC_ACCESS_RING_FAILED          = FAPI2_COMP_ID | 0x3B,
        RC_FAILED_TO_DECOMPRESS_RING   = FAPI2_COMP_ID | 0x3C,
        RC_INCORRECT_HW_IMAGE_TYPE     = FAPI2_COMP_ID | 0x3D,
        RC_DD_SUPPORT_CHECK_FAILED     = FAPI2_COMP_ID | 0x3E,

        // HWP generated errors
        RC_HWP_GENERATED_ERROR         = HWPF_COMP_ID | 0x0f,

        // DIMM SPD generated errors
        RC_BAD_DQ_MFG_MODE_BITS        = HWPF_COMP_ID | 0x30,
        // PLL_BUCKET generated errors
        RC_NO_MATCHING_FREQ            = HWPF_COMP_ID | 0x31,
        RC_FREQ_LIST_NOT_FOUND         = HWPF_COMP_ID | 0x32,

    };

    /**
     * @brief Defines the HWPF error log user detail data sections
     */
    enum fapi2UserDetailDataSubSection
    {
        HWPF_FAPI2_UDT_HWP_RCVALUE        = 0x01,
        HWPF_FAPI2_UDT_HWP_FFDC           = 0x02,
        HWPF_FAPI2_UDT_STEP_ERROR_DETAILS = 0x03,
    };

    /**
     * @brief Defines the BAD_DQ_BITMAP error log detail data sections
     */
    enum fapi2BadDqBitmapDataSection
    {
        CLEAN_BAD_DQ_BITMAP_RANK0   = 0x01,
        CLEAN_BAD_DQ_BITMAP_RANK1   = 0x02,
        CLEAN_BAD_DQ_BITMAP_RANK2   = 0x03,
        CLEAN_BAD_DQ_BITMAP_RANK3   = 0x04,
        CURRENT_BAD_DQ_BITMAP_RANK0 = 0x05,
        CURRENT_BAD_DQ_BITMAP_RANK1 = 0x06,
        CURRENT_BAD_DQ_BITMAP_RANK2 = 0x07,
        CURRENT_BAD_DQ_BITMAP_RANK3 = 0x08,
    };

};

#endif // HWPF_FAPI2_REASONCODES_H_
