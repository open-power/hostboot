/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/hwpf_fapi2_reasoncodes.H $              */
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
        MOD_FAPI2_PLAT_GET_VPD_MCS                  = 0x0E,
        MOD_FAPI2_PIB_ERR_MASK                      = 0x0F,
        MOD_FAPI2_PLAT_PARSE_WOF_TABLES             = 0x10,
        MOD_FAPI2_CVPD_ACCESS                       = 0x11,
        MOD_FAPI2_BAD_DQ_BITMAP                     = 0x12,
        MOD_FAPI2_GET_CHIP_CFAM_TARGET              = 0x13,
        MOD_FAPI2_GET_MB_VPD_ATTR                   = 0x15,
        MOD_FAPI2_GET_PLL_BUCKET                    = 0x16,
        MOD_FAPI2_GET_RING                          = 0x17,
        MOD_FAPI2_SET_ATTR_FREQ_MCA_MHZ             = 0x18,
        MOD_FAPI2_PLAT_GET_PROC_TEST                = 0x19,
        MOD_FAPI2_MONITOR_FOR_FSP_MSGS              = 0x1A,
        MOD_FAPI2_PLAT_GET_VPD_OCMB                 = 0x1B,
        MOD_FAPI2_PLAT_ERROR_ON_SET                 = 0x1C,
        MOD_FAPI2_PLAT_GET_MC_PLL_BUCKET            = 0x1D,
        MOD_FAPI2_PLAT_GET_FREQ_MCA_MHZ             = 0x1E,
        MOD_GET_OMI_FREQ_AND_VCO                    = 0x1F,
        MOD_FAPI2_SPD_ACCESS                        = 0x20,
        MOD_GET_OMI_FREQ                            = 0x21,
        MOD_FAPI2_EXPLR_IB_I2C_READ                 = 0x22,
        MOD_FAPI2_EXPLR_IB_I2C_WRITE                = 0x23,
        MOD_FAPI2_GET_DEFAULT_WOF_TABLE             = 0x24,
        MOD_FAPI2_GET_SEEPROM_ECC_LESS_WOF_DATA     = 0x25,
        MOD_FAPI2_GET_OVERRIDE_WOF_TABLE            = 0x26,
        MOD_TRIGGER_ATTR_SYNC                       = 0x27,
        MOD_FAPI2_PLAT_GET_SCOM                     = 0x28,
        MOD_FAPI2_PLAT_PUT_SCOM                     = 0x29,
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
        RC_INVALID_TARGET_TYPE         = FAPI2_COMP_ID | 0x37,
        RC_INVALID_PARENT_TARGET_FOUND = FAPI2_COMP_ID | 0x39,
        RC_GET_RING_SECTION_FAILED     = FAPI2_COMP_ID | 0x3A,
        RC_ACCESS_RING_FAILED          = FAPI2_COMP_ID | 0x3B,
        RC_FAILED_TO_DECOMPRESS_RING   = FAPI2_COMP_ID | 0x3C,
        RC_INCORRECT_HW_IMAGE_TYPE     = FAPI2_COMP_ID | 0x3D,
        RC_DD_SUPPORT_CHECK_FAILED     = FAPI2_COMP_ID | 0x3E,
        RC_SET_ATTR_NOT_VALID          = FAPI2_COMP_ID | 0x3F,
        RC_FAILED_TO_GET_RING_LIST     = FAPI2_COMP_ID | 0x40,
        RC_ATTR_OVERRIDE_DISALLOWED    = FAPI2_COMP_ID | 0x41,
        RC_UNKNOWN_OCMB_CHIP_TYPE      = FAPI2_COMP_ID | 0x42,
        RC_INVALID_BUFFER_SIZE         = FAPI2_COMP_ID | 0x43,
        RC_WOF_MRW_IDX_NOT_INCLUDED    = FAPI2_COMP_ID | 0x44,
        RC_WOF_HEADER_ENTRY_BEYOND_IMG = FAPI2_COMP_ID | 0x45,
        RC_WOF_READ_UNCORRECTABLE_ECC  = FAPI2_COMP_ID | 0x46,
        RC_WOF_OVERRIDE_MAGIC_MISMATCH = FAPI2_COMP_ID | 0x47,
        RC_WOF_OVERRIDE_VERSION_MISMATCH = FAPI2_COMP_ID | 0x48,
        RC_WOF_OVERRIDE_TABLE_NOT_FOUND  = FAPI2_COMP_ID | 0x49,
        RC_INVALID_ERROR_LOG             = FAPI2_COMP_ID | 0x4A,

        RC_UNSUPPORTED_OPERATION       = FAPI2_COMP_ID | 0xF0,

        // HWP generated errors
        RC_HWP_GENERATED_ERROR         = HWPF_COMP_ID | 0x0f,

        // DIMM SPD generated errors
        RC_BAD_DQ_MFG_MODE_BITS        = HWPF_COMP_ID | 0x30,
        // PLL_BUCKET generated errors
        RC_NO_MATCHING_FREQ            = HWPF_COMP_ID | 0x31,
        RC_FREQ_LIST_NOT_FOUND         = HWPF_COMP_ID | 0x32,
        RC_PROC_FREQ_MISMATCH          = HWPF_COMP_ID | 0x33,

        RC_INVALID_SPD_DRAM_GEN        = FAPI2_COMP_ID | 0x34,
        RC_CANNOT_FIND_POSITION        = FAPI2_COMP_ID | 0x35,

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
