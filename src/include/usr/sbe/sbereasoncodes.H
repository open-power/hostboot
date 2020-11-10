/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbe/sbereasoncodes.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#ifndef __SBEREASONCODES_H
#define __SBEREASONCODES_H

// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace SBE
{

/**
* @enum SbeModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum sbeModuleId
{
    SBE_INVALID_MODULE                  = 0x00,
    SBE_FIND_IN_PNOR                    = 0x01,
    SBE_UPDATE_SEEPROMS                 = 0x02,
    SBE_GETSET_MVPD_VERSION             = 0x03,
    SBE_READ_PNOR_VERSION               = 0x04,
    SBE_READ_SBE_FROM_PNOR              = 0x05,
    SBE_CREATE_TEST_SPACE               = 0x06,
    SBE_CLEANUP_TEST_SPACE              = 0x07,
    SBE_GET_TARGET_INFO_STATE           = 0x08,
    SBE_GET_SEEPROM_INFO                = 0x09,
    SBE_DECISION_TREE                   = 0x0A,
    SBE_CUSTOMIZE_IMG                   = 0x0B,
    SBE_PERFORM_UPDATE_ACTIONS          = 0x0C,
    SBE_MASTER_VERSION_COMPARE          = 0x0D,
    SBE_RESOLVE_HBB_ADDR                = 0x0E,
    SBE_READ_SBE_IMAGE                  = 0x0F,
    SBE_WRITE_SBE_IMAGE                 = 0x10,
    SBE_GET_SBE_IMAGE_SIZE              = 0x11,
    SBE_APPEND_HBBL                     = 0x13,
    SBE_GET_HW_KEY_HASH                 = 0x14,
};

/**
 * @enum sbeReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum sbeReasonCode
{
    SBE_INVALID_REASONCODE              = SBE_COMP_ID | 0x00,   // Invalid RC
    SBE_ALLOC_BLOCK_FAIL                = SBE_COMP_ID | 0x01,
    SBE_SET_PERMISSION_FAIL             = SBE_COMP_ID | 0x02,
    SBE_REMOVE_PAGES_FAIL               = SBE_COMP_ID | 0x03,
    SBE_REMOVE_PAGES_FOR_EC             = SBE_COMP_ID | 0x04,
    SBE_REMOVE_PAGES_CLEANUP            = SBE_COMP_ID | 0x05,
    SBE_UNSUPPORTED_TOC                 = SBE_COMP_ID | 0x06,
    SBE_INVALID_EYECATCHER              = SBE_COMP_ID | 0x07,
    SBE_EC_NOT_FOUND                    = SBE_COMP_ID | 0x08,
    SBE_XIP_IMG_SIZE_FAIL               = SBE_COMP_ID | 0x09,
    SBE_MVPD_LEN_INVALID                = SBE_COMP_ID | 0x0A,
    SBE_VERSION_NOT_FOUND               = SBE_COMP_ID | 0x0B,

    // SBE_UPDATE_REQUEST_REIPL Must have one unique use
    //   for Shutdown path. FSP relies on it.
    // termination_rc
    SBE_UPDATE_REQUEST_REIPL            = SBE_COMP_ID | 0x0C,

    SBE_INVALID_INPUT                   = SBE_COMP_ID | 0x0D,
    SBE_INVALID_SEEPROM_SIDE            = SBE_COMP_ID | 0x0E,
    SBE_ECC_FAIL                        = SBE_COMP_ID | 0x0F,
    SBE_PERM_SIDE_DIRTY_BAD_PATH        = SBE_COMP_ID | 0x10,
    SBE_P9_XIP_CUSTOMIZE_UNSUCCESSFUL   = SBE_COMP_ID | 0x11,
    SBE_INFO_LOG                        = SBE_COMP_ID | 0x12,
    SBE_MISCOMPARE_WITH_MASTER_VERSION  = SBE_COMP_ID | 0x13,
    SBE_ERROR_ON_UPDATE                 = SBE_COMP_ID | 0x14,
    SBE_MASTER_VERSION_DOWNLEVEL        = SBE_COMP_ID | 0x15,
    SBE_IMAGE_GET_SET_SCALAR_FAIL       = SBE_COMP_ID | 0x16,

    ERROR_FROM_XIP_DELETE               = SBE_COMP_ID | 0x18,
    ERROR_FROM_XIP_FIND                 = SBE_COMP_ID | 0x19,
    SBE_MISMATCHED_HW_KEY_HASH          = SBE_COMP_ID | 0x1A,
    SBE_UPDATE_DURING_MPIPL             = SBE_COMP_ID | 0x1B,
    SBE_BOOT_SIDE_DIRTY_BAD_PATH        = SBE_COMP_ID | 0x1C,
};

};  // end SBE

#endif
