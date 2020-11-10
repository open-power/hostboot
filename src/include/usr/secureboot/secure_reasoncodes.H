/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/secure_reasoncodes.H $             */
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
#ifndef __SECUREBOOT_REASONCODES_H
#define __SECUREBOOT_REASONCODES_H

#include <hbotcompid.H>

namespace SECUREBOOT
{
    enum SECUREModuleId
    {
        MOD_SECURE_INVALID              = 0x00,
        MOD_SECURE_BLINDPURGE           = 0x01,
        MOD_SECURE_ROM_INIT             = 0x02,
        MOD_SECURE_ROM_VERIFY           = 0x03,
        MOD_SECURE_ROM_CLEANUP          = 0x04,
        MOD_SECURE_ROM_SHA512           = 0x05,
        MOD_SECURE_READ_REG             = 0x06,
        MOD_SECURE_WRITE_REG            = 0x07,
        MOD_SECURE_SETTINGS_INIT        = 0x08,
        MOD_SECURE_VERIFY_COMPONENT     = 0x09,
        MOD_SECURE_CONT_HDR_PARSE       = 0x0A,
        MOD_SECURE_CONT_HDR_CPY_INC     = 0x0B,
        MOD_SECURE_CONT_VALIDATE        = 0x0C,
        MOD_SECURE_SET_SBE_SECURE_MODE  = 0x0D,
        MOD_SECURE_GET_ALL_SEC_REGS     = 0x0E,
        MOD_SECURE_LOAD_HEADER          = 0x0F,
        MOD_SECURE_VALIDATE_ECID_COUNT  = 0x10,
   };

    enum SECUREReasonCode
    {
        RC_PURGEOP_PENDING              = SECURE_COMP_ID | 0x01,
        RC_PURGEOP_FAIL_COMPLETE        = SECURE_COMP_ID | 0x02,
        RC_DEV_MAP_FAIL                 = SECURE_COMP_ID | 0x03,
        RC_PAGE_ALLOC_FAIL              = SECURE_COMP_ID | 0x04,
        RC_SET_PERMISSION_FAIL_EXE      = SECURE_COMP_ID | 0x05,
        RC_SET_PERMISSION_FAIL_WRITE    = SECURE_COMP_ID | 0x06,
        //termination_rc
        RC_ROM_VERIFY                   = SECURE_COMP_ID | 0x07,
        RC_ROM_SHA512                   = SECURE_COMP_ID | 0x08,
        RC_SECURE_BAD_TARGET            = SECURE_COMP_ID | 0x09,
        RC_SECURE_BOOT_DISABLED         = SECURE_COMP_ID | 0x0A,
        RC_SECROM_INVALID               = SECURE_COMP_ID | 0x0B,
        RC_CONT_HDR_NO_SPACE            = SECURE_COMP_ID | 0x0C,
        RC_CONT_HDR_INVALID             = SECURE_COMP_ID | 0x0D,
        RC_SBE_INVALID_SEC_MODE         = SECURE_COMP_ID | 0x0E,
        RC_DEVICE_WRITE_ERR             = SECURE_COMP_ID | 0x0F,
        RC_PROC_NOT_SCOMABLE            = SECURE_COMP_ID | 0x10,
        RC_DEVICE_READ_ERR              = SECURE_COMP_ID | 0x11,
        RC_INVALID_BASE_HEADER          = SECURE_COMP_ID | 0x12,
        RC_INVALID_ECID_COUNT           = SECURE_COMP_ID | 0x13,
        // Reason codes 0xA0 - 0xEF reserved for trustedboot_reasoncodes.H
    };

    enum UserDetailsTypes
    {
        // Version(s)
        SECURE_UDT_VERSION_1          = 0x1,

        // Formats/User Detail Sections
        SECURE_UDT_NO_FORMAT          = 0x0,
        SECURE_UDT_SYSTEM_HW_KEY_HASH = 0x1,
        SECURE_UDT_TARGET_HW_KEY_HASH = 0x2,
        SECURE_UDT_SECURITY_SETTINGS  = 0x3,
        SECURE_UDT_VERIFY_INFO        = 0x4,
    };

}

#endif
