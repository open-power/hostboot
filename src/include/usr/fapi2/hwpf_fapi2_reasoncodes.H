/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/hwpf_fapi2_reasoncodes.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
        RC_NV_NO_PROC_FOUND            = FAPI2_COMP_ID | 0x1d,
        RC_PPE_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x1e,
        RC_PERV_NO_PROC_FOUND          = FAPI2_COMP_ID | 0x1f,
        RC_CAPP_NO_PROC_FOUND          = FAPI2_COMP_ID | 0x20,
        RC_SBE_NO_PROC_FOUND           = FAPI2_COMP_ID | 0x21,
        RC_INVALID_CHILD_COUNT         = FAPI2_COMP_ID | 0x22,
        RC_UNIT_NO_PERV_FOUND          = FAPI2_COMP_ID | 0x23,
        // HWP generated errors
        RC_HWP_GENERATED_ERROR         = HWPF_COMP_ID | 0x0f,

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
};

#endif // HWPF_FAPI2_REASONCODES_H_
