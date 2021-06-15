/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/scomreasoncodes.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#ifndef __SCOM_REASONCODES_H
#define __SCOM_REASONCODES_H

#include <hbotcompid.H>

namespace SCOM
{
    enum scomModuleId
    {
        SCOM_PERFORM_OP                 = 0x00,
        SCOM_TRANSLATE                  = 0x01,
        SCOM_PERFORM_TRANSLATE          = 0x02,
        SCOM_FIND_PARENT_TARGET         = 0x03,
        SCOM_CHECK_INDIRECT_AND_DO_SCOM = 0x04,
        SCOM_DO_FORM_1_INDIRECT_SCOM    = 0x06,
        SCOM_HANDLE_SPECIAL_WAKEUP      = 0x07,
        // 0x08 unused
        SCOM_RT_SEND_SCOM_TO_HYP        = 0x09,
        SCOM_OP_SANITY_CHECK            = 0x0A,
        // 0x0B->0x0D unused
        SCOM_CALL_WAKEUP_HYP            = 0x0E,
        SCOM_CALL_WAKEUP_HWP            = 0x0F,
        SCOM_DO_MULTICAST_WORKAROUND    = 0x10,
        SCOM_TRANSLATE_P10              = 0x11,
    };

    enum scomReasonCode
    {
        SCOM_INVALID_ADDR              = SCOM_COMP_ID | 0x01,
        SCOM_NO_MATCHING_PARENT        = SCOM_COMP_ID | 0x02,
        SCOM_TRANS_INVALID_TYPE        = SCOM_COMP_ID | 0x03,
        SCOM_TRANS_UNSUPPORTED         = SCOM_COMP_ID | 0x04,
        SCOM_INDIRECT_READ_FAIL        = SCOM_COMP_ID | 0x05,
        SCOM_INDIRECT_READ_TIMEOUT     = SCOM_COMP_ID | 0x06,
        SCOM_INDIRECT_WRITE_FAIL       = SCOM_COMP_ID | 0x07,
        SCOM_INDIRECT_WRITE_TIMEOUT    = SCOM_COMP_ID | 0x08,
        SCOM_INVALID_TRANSLATION       = SCOM_COMP_ID | 0x0A,
        SCOM_TRANS_CANT_FIND_PARENT    = SCOM_COMP_ID | 0x0B,
        SCOM_TARGET_ADDR_MISMATCH      = SCOM_COMP_ID | 0x0C,
        SCOM_ISCHIPUNITSCOM_INVALID    = SCOM_COMP_ID | 0x0D,
        SCOM_INVALID_FORM              = SCOM_COMP_ID | 0x0E,
        SCOM_FORM_1_INVALID_DATA       = SCOM_COMP_ID | 0x0F,
        SCOM_FORM_1_READ_REQUEST       = SCOM_COMP_ID | 0x10,
        SCOM_RUNTIME_WAKEUP_ERR        = SCOM_COMP_ID | 0x11,
        SCOM_RUNTIME_INTERFACE_ERR     = SCOM_COMP_ID | 0x12,
        SCOM_SPCWKUP_COUNT_ERR         = SCOM_COMP_ID | 0x13,
        SCOM_CEN_TRANS_INVALID_TYPE    = SCOM_COMP_ID | 0x14,
        SCOM_RUNTIME_HYP_ERR           = SCOM_COMP_ID | 0x15,
        SCOM_INVALID_DATA_BUFFER       = SCOM_COMP_ID | 0x16,
        SCOM_INVALID_OP_TYPE           = SCOM_COMP_ID | 0x17,
        SCOM_BAD_CACHE_VERIFY_SEQ      = SCOM_COMP_ID | 0x18,
        SCOM_CACHE_VERIFY_FAILURE      = SCOM_COMP_ID | 0x19,
        SCOM_SENSITIVE_REG_READ_FAIL   = SCOM_COMP_ID | 0x1A,
        SCOM_BAD_TARGET                = SCOM_COMP_ID | 0x1B,
        SCOM_CACHE_SEQ_ERROR           = SCOM_COMP_ID | 0x1C,
        SCOM_INVALID_WAKEUP_PARM       = SCOM_COMP_ID | 0x1D,
        SCOM_UNEXPECTED_FORCE_WAKEUP   = SCOM_COMP_ID | 0x1E,
        SCOM_UNSUPPORTED_MULTICAST_OP  = SCOM_COMP_ID | 0x1F,
        SCOM_P10_TRANS_INVALID_TYPE    = SCOM_COMP_ID | 0x20,
        SCOM_MULTICAST_MISCOMPARE      = SCOM_COMP_ID | 0x21,
        SCOM_INVALID_ECO_TYPE          = SCOM_COMP_ID | 0x22,
    };

    enum UserDetailsTypes
    {
        SCOM_UDT_PIB                    = 0x01,
    };

    enum UserDetailsVersions
    {
        SCOM_UDT_VERSION_1              = 0x01,
    };
};

#endif
