/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlreasoncodes.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#ifndef __ERRL_REASON_CODES_H
#define __ERRL_REASON_CODES_H

/**
 *  @file errlreasoncodes.H
 *
 *  @brief  Reason code and Module ID definitions for ERRL component.
 *
 */

#include <hbotcompid.H>

namespace ERRORLOG
{
    // Module IDs for ERRL component
    enum errlModuleId
    {
        ERRL_FIRST_MODULE_ID           = 0x00,
        ERRL_USERDATA_TEST_MOD_ID      = 0x01,
        ERRL_TEST_MOD_ID               = 0x02,
        ERRL_RT_TEST_MOD_ID            = 0x03,
        ERRL_ADD_HW_CALLOUT_ID         = 0x04,
        ERRL_COMMIT_EXTRA_LOGS_ID      = 0x05,
        ERRL_GET_CURRENT_DATE_TIME     = 0x06,
        ERRL_GET_MARKER_LID_MI_KEYWORD = 0x07,
        //........
        ERRL_LAST_MODULE_ID         = 0xFF
    };

    // Reason codes for ERRL component
    enum errlReasonCode
    {
        ERRL_FIRST_ERR            = ERRL_COMP_ID | 0x01,
        ERRL_TEST_STRING_UD       = ERRL_COMP_ID | 0x02,
        ERRL_TEST_REASON_CODE     = ERRL_COMP_ID | 0x03,
        ERRL_TEST_ATTRIBUTE_UD    = ERRL_COMP_ID | 0x04,
        ERRL_TEST_LOGREGISTER_UD  = ERRL_COMP_ID | 0x05,
        ERRL_TEST_CALLOUT_UD      = ERRL_COMP_ID | 0x06,
        ERRL_CORE_EX_TARGET_NULL  = ERRL_COMP_ID | 0x07,
        ERRL_TEST_DUPLICATE_TRACE = ERRL_COMP_ID | 0x08,
        ERRL_EXTRA_LOG_RC         = ERRL_COMP_ID | 0x09,
        RC_PLDM_SEND_LOG_FAILED   = ERRL_COMP_ID | 0x0A,
        ERRL_RT_NO_INTERFACE      = ERRL_COMP_ID | 0x0B,
        ERRL_MARKER_LID_INVALID_BUFFER_SIZE = ERRL_COMP_ID | 0x0C,
        ERRL_MARKER_LID_INVALID_BUFFER      = ERRL_COMP_ID | 0x0D,
        //........
        ERRL_LAST_ERR             = ERRL_COMP_ID | 0xFF
    };

    // Identifiers for ERRL user data subsections.
    enum errlUserDetailDataSubsection
    {
        ERRL_UDT_NOFORMAT         = 0x00,
        ERRL_UDT_STRING           = 0x01,
        ERRL_UDT_TARGET           = 0x02,
        ERRL_UDT_BACKTRACE        = 0x03,
        ERRL_UDT_ATTRIBUTE        = 0x04,
        ERRL_UDT_LOGREGISTER      = 0x05,
        ERRL_UDT_CALLOUT          = 0x06,
        ERRL_UDT_PRINTK           = 0x07,
        ERRL_UDT_SENSOR           = 0x08,
        ERRL_UDT_STRING_SET       = 0x09,
        ERRL_UDT_BUILD            = 0x0A,
        ERRL_UDT_SYSSTATE         = 0x0B,
        ERRL_UDT_WOFDATA          = 0x0C,
    };

    // Identifiers for ERRL user data subsection versions
    enum errlUserDetailDataSubsectionVersion
    {
        ERRL_UDT_STRING_SET_VER_1 = 0x01,
    };
};

#endif
