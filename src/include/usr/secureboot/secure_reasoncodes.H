/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/secure_reasoncodes.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
        MOD_SECURE_INVALID                      = 0x00,
        MOD_SECURE_BLINDPURGE                   = 0x01,
        MOD_SECURE_ROM_INIT                     = 0x02,
        MOD_SECURE_ROM_VERIFY                   = 0x03,
        MOD_SECURE_ROM_CLEANUP                  = 0x04,
        MOD_SECURE_ROM_SHA512                   = 0x05,
        MOD_SECURE_READ_REG                     = 0x06,
        MOD_SECURE_WRITE_REG                    = 0x07,
        MOD_SECURE_SETTINGS_INIT                = 0x08,
        MOD_SECURE_VERIFY_COMPONENT             = 0x09,
        MOD_SECURE_CONT_HDR_PARSE               = 0x0A,
        MOD_SECURE_CONT_HDR_CPY_INC             = 0x0B,
        MOD_SECURE_CONT_VALIDATE                = 0x0C,
        MOD_SECURE_SET_SBE_SECURE_MODE          = 0x0D,
        MOD_SECURE_GET_ALL_SEC_REGS             = 0x0E,
        MOD_SECURE_LOAD_HEADER                  = 0x0F,
        MOD_SECURE_VALIDATE_ECID_COUNT          = 0x10,
        MOD_LOCK_SECURE_MAILBOXES               = 0x11,
        MOD_SECURE_LOG_PLAT_SECURITY_CONFIG     = 0x12,
        MOD_CHECK_RISK_LEVEL_FOR_SMF            = 0x13,
        MOD_SMF_SPLIT_SMF_MEM                   = 0x14,
        MOD_SECURE_GET_SBE_MEASUREMENT_REGS     = 0x15,
        MOD_VERIFY_MEASUREMENT_SEEPROM_SECURITY = 0x16,
        MOD_CAN_XSCOM_PROC                      = 0x17,
        MOD_READ_SBE_MEASUREMENT_REGISTER       = 0x18,

        // Use 0x20-0x3F range for Node Communications
        MOD_NCDD_CHECK_FOR_ERRORS           = 0x20,
        MOD_NCDD_WAIT_FOR_CMD_COMP          = 0x21,
        MOD_NC_XBUS_TEST                    = 0x22,
        MOD_NC_MAP_ATTN                     = 0x23,
        MOD_NCDD_PERFORM_OP                 = 0x24,
        MOD_NCDD_WRITE                      = 0x25,
        MOD_NCEX_MAIN                       = 0x26,
        MOD_NCEX_MASTER                     = 0x27,
        MOD_NCEX_SLAVE                      = 0x28,
        MOD_NCEX_GET_RANDOM                 = 0x29,
        MOD_NC_RECV                         = 0x2A,
        MOD_NC_GEN_QUOTE_RESPONSE           = 0x2B,
        MOD_NC_GEN_QUOTE_REQUEST            = 0x2C,
        MOD_NC_PROCESS_QUOTE                = 0x2D,
        MOD_NCT_SEND                        = 0x2E,
        MOD_NCT_RECEIVE                     = 0x2F,
        MOD_NCT_REQUEST_QUOTE               = 0x30,

        // Use 0x40-0x4F range for Physical Presence Detection and Key Clear
        // Requests
        MOD_DETECT_PHYS_PRES                = 0x40,
        MOD_HANDLE_PHYS_PRES_WINDOW         = 0x41,
        MOD_CLEAR_KEY_CLEAR_SENSOR          = 0x42,
    };

    enum SECUREReasonCode
    {
        RC_PURGEOP_PENDING                 = SECURE_COMP_ID | 0x01,
        RC_PURGEOP_FAIL_COMPLETE           = SECURE_COMP_ID | 0x02,
        RC_DEV_MAP_FAIL                    = SECURE_COMP_ID | 0x03,
        RC_PAGE_ALLOC_FAIL                 = SECURE_COMP_ID | 0x04,
        RC_SET_PERMISSION_FAIL_EXE         = SECURE_COMP_ID | 0x05,
        RC_SET_PERMISSION_FAIL_WRITE       = SECURE_COMP_ID | 0x06,
        //termination_rc
        RC_ROM_VERIFY                      = SECURE_COMP_ID | 0x07,
        RC_ROM_SHA512                      = SECURE_COMP_ID | 0x08,
        RC_SECURE_BAD_TARGET               = SECURE_COMP_ID | 0x09,
        RC_SECURE_BOOT_DISABLED            = SECURE_COMP_ID | 0x0A,
        RC_SECROM_INVALID                  = SECURE_COMP_ID | 0x0B,
        RC_CONT_HDR_NO_SPACE               = SECURE_COMP_ID | 0x0C,
        RC_CONT_HDR_INVALID                = SECURE_COMP_ID | 0x0D,
        RC_SBE_INVALID_SEC_MODE            = SECURE_COMP_ID | 0x0E,
        RC_DEVICE_WRITE_ERR                = SECURE_COMP_ID | 0x0F,
        RC_PROC_NOT_SCOMABLE               = SECURE_COMP_ID | 0x10,
        RC_DEVICE_READ_ERR                 = SECURE_COMP_ID | 0x11,
        RC_INVALID_BASE_HEADER             = SECURE_COMP_ID | 0x12,
        RC_INVALID_ECID_COUNT              = SECURE_COMP_ID | 0x13,
        RC_LOCK_MAILBOXES_FAILED           = SECURE_COMP_ID | 0x14,
        RC_SECURE_LOG_PLAT_SECURITY_CONFIG = SECURE_COMP_ID | 0x15,
        RC_RISK_LEVEL_TOO_LOW              = SECURE_COMP_ID | 0x16,
        RC_COULD_NOT_ALLOCATE_SMF_MEM      = SECURE_COMP_ID | 0x17,
        RC_ALLOCATED_NE_REQUESTED          = SECURE_COMP_ID | 0x18,
        RC_UNSECURE_MEASUREMENT_VERSION    = SECURE_COMP_ID | 0x19,
        RC_UNBLOWN_MEASUREMENT_FUSE        = SECURE_COMP_ID | 0x1A,

        // Use 0x20-0x3F range for Node Communications
        RC_NCDD_HW_ERROR_FOUND             = SECURE_COMP_ID | 0x20,
        RC_NCDD_CMD_COMP_TIMEOUT           = SECURE_COMP_ID | 0x21,
        RC_NC_DATA_MISCOMPARE              = SECURE_COMP_ID | 0x22,
        RC_NC_NO_ATTN_FOUND                = SECURE_COMP_ID | 0x23,
        RC_NC_TOO_MANY_ATTNS_FOUND         = SECURE_COMP_ID | 0x24,
        RC_NCDD_INVALID_ARGS               = SECURE_COMP_ID | 0x25,
        RC_NCDD_DATA_NOT_SENT              = SECURE_COMP_ID | 0x26,
        RC_NCEX_MISMATCH_RECV_LINKS        = SECURE_COMP_ID | 0x27,
        RC_NCEX_NO_FUNCTIONAL_TPMS         = SECURE_COMP_ID | 0x28,
        RC_NCEX_INVALID_PHYS_PATH          = SECURE_COMP_ID | 0x29,
        RC_NCEX_INVALID_INSTANCE_COUNT     = SECURE_COMP_ID | 0x2A,
        RC_NC_WAITING_TIMEOUT              = SECURE_COMP_ID | 0x2B,
        RC_NC_BAD_REQUESTER_TPM            = SECURE_COMP_ID | 0x2C,
        RC_NC_NO_PRIMARY_TPM_LOG           = SECURE_COMP_ID | 0x2D,
        RC_NC_BAD_REQUESTER_EYE_CATCH      = SECURE_COMP_ID | 0x2E,
        RC_NC_BAD_QUOTE                    = SECURE_COMP_ID | 0x2F,
        RC_NCDD_INVALID_OP_TYPE            = SECURE_COMP_ID | 0x30,
        RC_NCT_TYPE_SIZE_MISMATCH          = SECURE_COMP_ID | 0x31,
        RC_NCT_ACK_MISMATCH                = SECURE_COMP_ID | 0x32,
        RC_NCT_INITIATION_MISMATCH         = SECURE_COMP_ID | 0x33,
        RC_NCEX_NO_FUNCTIONAL_PRIMARY_TPM  = SECURE_COMP_ID | 0x34,

        // Use 0x40-0x4F range for Physical Presence Detection and Key Clear
        // Requests

        // RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN Must have one unique use
        //  for Shutdown path since FSP relies on it.
        // termination_rc
        RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN = SECURE_COMP_ID | 0x40,
        RC_PHYS_PRES_ATTR_NOT_FOUND         = SECURE_COMP_ID | 0x41,
        RC_PHYS_PRES_WINDOW_NOT_CLOSED      = SECURE_COMP_ID | 0x42,
        RC_PHYS_PRES_WINDOW_NOT_OPENED      = SECURE_COMP_ID | 0x43,
        RC_PHYS_PRES_ASSERTED               = SECURE_COMP_ID | 0x44,
        RC_PHYS_PRES_REIPL                  = SECURE_COMP_ID | 0x45,
        RC_CLEARING_KEY_CLEAR_SENSOR_FAILED = SECURE_COMP_ID | 0x46,
        RC_KEY_CLEAR_REQUEST_MFG            = SECURE_COMP_ID | 0x47,

        // Reason codes 0xA0 - 0xEF reserved for trustedboot_reasoncodes.H
    };

    enum UserDetailsTypes
    {
        // Version(s)
        SECURE_UDT_VERSION_1          = 0x1,
        SECURE_UDT_VERSION_2          = 0x2,
        SECURE_UDT_VERSION_3          = 0x3,

        // Formats/User Detail Sections
        SECURE_UDT_NO_FORMAT          = 0x0,
        SECURE_UDT_SYSTEM_HW_KEY_HASH = 0x1,
        SECURE_UDT_TARGET_HW_KEY_HASH = 0x2,
        SECURE_UDT_SECURITY_SETTINGS  = 0x3,
        SECURE_UDT_VERIFY_INFO        = 0x4,
        SECURE_UDT_NODECOMM_INFO      = 0x5,
    };

}

#endif
