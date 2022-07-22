/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/hwpf_reasoncodes.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2022                        */
/* [+] Google Inc.                                                        */
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
#ifndef HWPFREASONCODES_H_
#define HWPFREASONCODES_H_

#include <hbotcompid.H>

namespace fapi
{
    /**
     * @brief Defines the HWPF error log module IDs
     */
    enum hwpfModuleId
    {
        // FAPI generated errors
        MOD_FAPI_RC_TO_ERRL                        = 0x01,

        // HWP generated errors
        MOD_HWP_RC_TO_ERRL                         = 0x02,

        // PLAT generated errors
        MOD_FAPI_GET_CHILD_CHIPLETS                = 0x03,
        MOD_FAPI_GET_PARENT_CHIP                   = 0x04,
        MOD_PLAT_ATTR_SVC_GET_TARG_ATTR            = 0x05,
        MOD_PLAT_ATTR_SVC_SET_TARG_ATTR            = 0x06,
        MOD_VERIFY_CFAM_ACCESS_TARGET              = 0x07,
        MOD_ATTR_BASE_ADDR_GET                     = 0x08,
        MOD_GET_CFAM_CHIP_TARGET                   = 0x09,
        MOD_FAPI_GET_ASSOCIATE_DIMMS               = 0x0A,
        MOD_EDI_EI_IO_RUN_TRAINING                 = 0x0B,
        MOD_THREAD_ACTIVATE                        = 0x0C,
        MOD_ATTR_GET_TARGETING_TARGET              = 0x0D,
        MOD_ATTR_GET_TARGET_NAME                   = 0x0E,
        MOD_MVPD_ACCESS                            = 0x0F,
        // empty
        MOD_GET_CACHE_DECONFIG                     = 0x11,
        MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL     = 0x12,
        MOD_MBVPD_ACCESS                           = 0x13,
        MOD_OCC_LOAD_START_ALL_OCCS                = 0x14,
        MOD_VDDR_PROC_MSG                          = 0x15,
        MOD_VDDR_PROC_VDDR_MSG                     = 0x16,
        MOD_VDDR_SEND_MSG                          = 0x17,
        MOD_PLAT_ATTR_SVC_GET_VPD_VERSION          = 0x18,
        MOD_PLAT_ATTR_SVC_GET_SPARE_DATA           = 0x19,
        MOD_PLAT_ATTR_SVC_GET_BADDQ_DATA           = 0x1A,
        MOD_PLAT_ATTR_SVC_SET_BADDQ_DATA           = 0x1B,
        MOD_HOST_COALESCE_HOST                     = 0x1C,
        MOD_ATTR_OVERRIDE                          = 0x1D,
        MOD_PLAT_SPECIAL_WAKEUP                    = 0x1E,
        MOD_PLAT_EN_VDDR                           = 0x1F,
        MOD_GET_OCC_CHIP_TARGET                    = 0x20,
        MOD_ACCESS_OCB_INDIRECT_CHANNEL            = 0x21,
        MOD_GET_RCD_CNTL_WORD                      = 0x22,
        MOD_GET_SYS_FREQ                           = 0x23,
        MOD_GET_POUNDV_BUCKET_DATA                 = 0x24,
        MOD_GET_VER_ONE_VOLTAGE_BUCKET_DATA        = 0x25,
        MOD_PLAT_MVPD_GET_VLTG_BUCKET_ATTR         = 0x26,
        MOD_PLAT_ATTR_SVC_CEN_DQ_TO_DIMM_CONN_DQ   = 0x27,
        MOD_PLAT_ATTR_SVC_GET_MEM_ATTR_DATA        = 0x28,
        MOD_GET_WOF_FREQ_UPLIFT_SELECTED           = 0x29,
        MOD_SET_NEST_FREQ                          = 0x2A,
        MOD_FIND_MIN_DMI_SPD                       = 0x2B,
        MOD_OCC_LOAD_HOST_DATA_TO_SRAM             = 0x2C,
        MOD_START_XZ_PAYLOAD                       = 0x2D,
        MOD_LOAD_OCC_IMAGE_DURING_IPL              = 0x2E,
        MOD_VERIFY_IPC_CONNECTION                  = 0x2F,
    };

    /**
     * @brief Defines the HWPF error log reason codes
     */
    enum hwpfReasonCode
    {
        // FAPI generated errors (must match fapiReturnCodes.H)
        RC_INVALID_ATTR_GET            = HWPF_COMP_ID | 0x01,
        RC_INVALID_CHIP_EC_FEATURE_GET = HWPF_COMP_ID | 0x02,

        // HWP generated errors
        RC_HWP_GENERATED_ERROR        = HWPF_COMP_ID | 0x0f,

        // PLAT Errors generated by HostBoot code
        RC_INVALID_REQUEST            = HWPF_COMP_ID | 0x10,
        RC_UNSUPPORTED_REQUEST        = HWPF_COMP_ID | 0x11,
        RC_NO_SINGLE_PARENT           = HWPF_COMP_ID | 0x12,
        RC_FAILED_TO_ACCESS_ATTRIBUTE = HWPF_COMP_ID | 0x13,
        RC_CFAM_ACCESS_ON_PROC_ERR    = HWPF_COMP_ID | 0x14,
        RC_ATTR_BAD_TARGET_PARAM      = HWPF_COMP_ID | 0x15,
        RC_INVALID_NUM_PARENT_CHIP    = HWPF_COMP_ID | 0x16,
        RC_EMBEDDED_NULL_TARGET_PTR   = HWPF_COMP_ID | 0x17,
        RC_MIXED_PBUS_CONNECTION      = HWPF_COMP_ID | 0x18,
        RC_SAME_CHIP_PBUS_CONNECTION  = HWPF_COMP_ID | 0x19,
        RC_CONFLICT_PBUS_CONNECTION   = HWPF_COMP_ID | 0x1A,
        RC_NO_MASTER_CORE_TARGET      = HWPF_COMP_ID | 0x1B,
        RC_UNEXPECTED_TARGET_TYPE     = HWPF_COMP_ID | 0x1C,
        RC_INVALID_RECORD             = HWPF_COMP_ID | 0x1D,
        RC_INVALID_KEYWORD            = HWPF_COMP_ID | 0x1E,
        // empty
        RC_INCORRECT_KEWORD_SIZE      = HWPF_COMP_ID | 0x20,
        RC_NO_SINGLE_MCS              = HWPF_COMP_ID | 0x21,
        RC_NO_SINGLE_MEMBUFF          = HWPF_COMP_ID | 0x22,
        RC_STATE_MISMATCH             = HWPF_COMP_ID | 0x23,
        RC_MM_UNMAP_ERR               = HWPF_COMP_ID | 0x24,
        RC_VDDR_EMPTY_MSG             = HWPF_COMP_ID | 0x25,
        RC_VDDR_ERROR_MSG             = HWPF_COMP_ID | 0x26,
        RC_VDDR_POWR_ERR              = HWPF_COMP_ID | 0x27,
        RC_INCORRECT_MSG_TYPE         = HWPF_COMP_ID | 0x28,
        RC_NO_SINGLE_MBA              = HWPF_COMP_ID | 0x29,
        RC_HOST_TIMER_EXPIRED         = HWPF_COMP_ID | 0x2A,
        RC_HOST_TIMER_THREAD_FAIL     = HWPF_COMP_ID | 0x2B,
        RC_NULL_POINTER               = HWPF_COMP_ID | 0x2C,
        RC_RT_WAKEUP_FAILED           = HWPF_COMP_ID | 0x2D,
        // empty
        RC_VDDR_INVALID_VOLTAGE       = HWPF_COMP_ID | 0x2F,
        RC_TIMEOUT_EN_VDDR            = HWPF_COMP_ID | 0x30,
        RC_TARGET_UNSUPPORTED         = HWPF_COMP_ID | 0x31,
        RC_INVALID_DATA_BUFFER_LENGTH = HWPF_COMP_ID | 0x32,
        RC_INVALID_DIMM_TYPE          = HWPF_COMP_ID | 0x33,
        RC_INVALID_DATA               = HWPF_COMP_ID | 0x34,
        RC_INVALID_SIZE               = HWPF_COMP_ID | 0x35,
        RC_INVALID_FREQ               = HWPF_COMP_ID | 0x36,
        RC_INVALID_PARAM              = HWPF_COMP_ID | 0x37,
        RC_DATA_MISMATCH              = HWPF_COMP_ID | 0x38,
        RC_DATA_NOT_SUPPORTED         = HWPF_COMP_ID | 0x39,
        RC_NO_SINGLE_NODE             = HWPF_COMP_ID | 0x3A,
        RC_INVALID_ULTRA_TURBO_FREQ   = HWPF_COMP_ID | 0x3B,
        RC_INVALID_WOF_INDEX          = HWPF_COMP_ID | 0x3C,
        RC_ECMD_INSERT_FAILED         = HWPF_COMP_ID | 0x3D,
        RC_INVALID_RETURN_XZ_CODE     = HWPF_COMP_ID | 0x3E,
        RC_ECMD_INSERT_REMAINING_FAILED = HWPF_COMP_ID | 0x3F,
    };

    /**
     * @brief Defines the HWPF error log user detail data sections
     */
    enum hwpfUserDetailDataSubSection
    {
        HWPF_UDT_HWP_RCVALUE        = 0x01,
        HWPF_UDT_HWP_FFDC           = 0x02,
        HWPF_UDT_STEP_ERROR_DETAILS = 0x03,
    };
};

// HostBoot ErrorLog tags for FAPI errors (see fapiReturnCodes.H)
/*@
 * @errortype
 * @moduleid     MOD_FAPI_RC_TO_ERRL
 * @reasoncode   RC_INVALID_ATTR_GET
 * @devdesc      InitFile HW Procedure requested an invalid attribute
 * @custdesc     A problem was detected during the IPL of the system:
 *               A hardware initialization procedure encountered a firmware error.
 */
/*@
 * @errortype
 * @moduleid     MOD_FAPI_RC_TO_ERRL
 * @reasoncode   RC_INVALID_CHIP_EC_FEATURE_GET
 * @devdesc      Request for EC features on an attribute without EC features
 * @custdesc     A problem was detected during the IPL of the system:
 *               A hardware initialization procedure encountered a firmware error.
 */

#endif
