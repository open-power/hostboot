/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/targreasoncodes.H $          */
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
#ifndef __TARGETING_COMMON_TARGREASONCODES_H
#define __TARGETING_COMMON_TARGREASONCODES_H

/**
 *  @file targeting/common/targetreasoncodes.H
 *
 *  @brief Provides reason codes for various targeting errors
 */

#include <targeting/adapters/types.H>

namespace TARGETING
{

enum TargetingModuleId
{
    TARG_MOD_TEST                   = 0x01,
    TARG_MOD_ATTR_SYNC              = 0x02,
    TARG_RT_GET_RT_TARGET           = 0x03,
    TARG_RT_GET_HB_TARGET           = 0x04,
    TARG_GET_ATTR_OVER              = 0x05,
    TARG_WRITE_PERM_ATTR            = 0x06,
    TARG_PARSE_ATTR_SECT_HEADER     = 0x07,
    TARG_MSG_SERVICE_TASK           = 0x08,
    TARG_CREATE_VMM_SECTIONS        = 0x09,
    TARG_APPLY_ATTR_OVER            = 0x0A,
    TARG_HANDLE_ENUM_CHECK_FAILURE  = 0x0B,
    TARG_HANDLE_RANGE_CHECK_FAILURE = 0x0C,
    TARG_EDIT_PAGE_PERMISSIONS      = 0x0D,
    TARG_NOTIFY_RESOURCE_READY      = 0x0E,
    TARG_ATTR_SYNC_TASK             = 0x0F,
    TARG_SEND_ATTR_SYNC_MSG         = 0x10,
    TARG_TRANSLATE_TARGET           = 0x11,
    TARG_GET_ATTR_METADATA_PTR      = 0x12,
    TARG_PARSE_RW_ATTR_DATA         = 0x13,
    TARG_PARSE_ATTR_METADATA        = 0x14,
};

enum TargetingReasonCode
{
    TARG_RC_TEST_TARGET_FFDC                = TARG_COMP_ID | 0x01,
    TARG_RC_BAD_EYECATCH                    = TARG_COMP_ID | 0x02,
    TARG_RC_MM_BLOCK_FAIL                   = TARG_COMP_ID | 0x03,
    TARG_RC_MM_PERM_FAIL                    = TARG_COMP_ID | 0x04,
    TARG_RC_ATTR_MSG_FAIL                   = TARG_COMP_ID | 0x05,
    TARG_RC_UNHANDLED_ATTR_SEC_TYPE         = TARG_COMP_ID | 0x06,
    TARG_RC_ATTR_SYNC_TO_FSP_FAIL           = TARG_COMP_ID | 0x07,
    TARG_RC_ATTR_SYNC_REQUEST_TO_HB_FAIL    = TARG_COMP_ID | 0x08,
    TARG_RC_ATTR_SYNC_TO_HB_FAIL            = TARG_COMP_ID | 0x09,
    TARG_RT_UNIT_TARGET_NOT_FOUND           = TARG_COMP_ID | 0x0a,
    TARG_RT_NO_PROC_TARGET                  = TARG_COMP_ID | 0x0b,
    TARG_RT_TARGET_TYPE_NOT_SUPPORTED       = TARG_COMP_ID | 0x0c,
    TARG_RC_ATTR_OVER_PNOR_SEC_SPACE_FAIL   = TARG_COMP_ID | 0x0d,
    TARG_RC_ATTR_OVER_ATTR_DATA_SIZE_FAIL   = TARG_COMP_ID | 0x0e,
    TARG_RC_WRITE_PERM_ATTR_FAIL            = TARG_COMP_ID | 0x0f,
    TARG_RC_WRITE_PERM_ATTR_TARGET_FAIL     = TARG_COMP_ID | 0x10,
    TARG_RC_WRITE_ATTR_OVER_WRONG_PNOR_SEC  = TARG_COMP_ID | 0x11,
    TARG_RC_WRITE_ATTR_OVER_NO_TANK_LAYER   = TARG_COMP_ID | 0x12,
    TARG_RC_MM_BLOCK_MAP_FAIL               = TARG_COMP_ID | 0x13,
    TARG_RC_APPLY_ATTR_OVER_NOT_ALLOWED     = TARG_COMP_ID | 0x14,
    TARG_RC_MM_BLOCK_UNMAP_FAIL             = TARG_COMP_ID | 0x15,
    TARG_RC_ATTRIBUTE_ENUM_CHECK_FAIL       = TARG_COMP_ID | 0x16,
    TARG_RC_ATTRIBUTE_RANGE_CHECK_FAIL      = TARG_COMP_ID | 0x17,
    TARG_RC_CONCURRENT_CODE_UPDATE_FAIL     = TARG_COMP_ID | 0x18,
    TARG_RC_ATTR_OVER_FAPI_TANK_NOT_SUPPORTED = TARG_COMP_ID | 0x19,
    TARG_RC_UNSUPPORTED_ATTR_SYNC_MSG       = TARG_COMP_ID | 0x1A,
    TARG_RC_ATTR_SYNC_SERVICE_DOWN          = TARG_COMP_ID | 0x1B,
    TARG_RC_TARGET_TYPE_NOT_SUPPORTED       = TARG_COMP_ID | 0x1C,
    TARG_RC_TOC_MAPPING_FAIL                = TARG_COMP_ID | 0x1D,
    TARG_RC_RSVD_MEM_LABEL_FAIL             = TARG_COMP_ID | 0x1E,
    TARG_RC_NO_METADATA                     = TARG_COMP_ID | 0x1F,
    TARG_RC_BAD_TARGETING_PTR               = TARG_COMP_ID | 0x20,
    TARG_RC_BAD_RW_ATTR_PTR                 = TARG_COMP_ID | 0x21,
    TARG_RC_BAD_METADATA_PTR                = TARG_COMP_ID | 0x22,
};

}; // End TARGETING namespace

#endif // __TARGETING_COMMON_TARGREASONCODES_H
