/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimmreasoncodes.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/**
 * @file nvdimmreasoncodes.H
 *
 * @brief Reason codes and module ids for the NVDIMM
 *
 */
#ifndef __NVDIMMREASONCODES_H
#define __NVDIMMREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace NVDIMM
{

/**
* @enum nvdimmModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum nvdimmModuleId
{
    NVDIMM_INVALID_MODULE                   = 0x00,     // Invalid Module Id
    NVDIMM_PERFORM_OP                       = 0x01,
    NVDIMM_READ                             = 0x02,
    NVDIMM_WRITE                            = 0x03,
    NVDIMM_PREPAREADDRESS                   = 0x04,
    NVDIMM_READATTRIBUTES                   = 0x05,
    NVDIMM_GETI2CMASTERTARGET               = 0x06,
    NVDIMM_CROSSESNVDIMMPAGEBOUNDARY        = 0x07,
    NVDIMM_POLL_BACKUP                      = 0x08,
    NVDIMM_POLL_RESTORE                     = 0x09,
    NVDIMM_POLL_ERASE                       = 0x0A,
    NVDIMM_POLL_ARM                         = 0x0B,
    NVDIMM_POLL_CHARGE                      = 0x0C,
    NVDIMM_CHECK_RESTORE                    = 0x0D,
    NVDIMM_CHECK_IMAGE                      = 0x0E,
    NVDIMM_SET_ES                           = 0x0F,
    NVDIMM_SET_ARM                          = 0x10,
    NVDIMM_SET_PAGE                         = 0x11,
    NVDIMM_GET_TIMEOUT                      = 0x12,
    NVDIMM_RESTORE                          = 0x13,
    NVDIMM_OPEN_PAGE                        = 0x14,
    NVDIMM_POLL_STATUS                      = 0x15,
    NVDIMM_CHECK_ERASE                      = 0x16,
    NVDIMM_ARM_ERASE                        = 0x17,
    NVDIMM_CHECK_READY                      = 0x18,
    NOTIFY_NVDIMM_PROTECTION_CHG            = 0x19,
    NVDIMM_RUN_UPDATE                       = 0x1A,
    UPDATE_IMAGE                            = 0x1B,
    UPDATE_IMAGE_DATA                       = 0x1C,
    CHANGE_FW_UPDATE_MODE                   = 0x1D,
    WAIT_FW_OPS_COMPLETE                    = 0x1E,
    BYTE_REGION_BLOCK_TRANSFER              = 0x1F,
    VALIDATE_FW_HEADER                      = 0x20,
    COMMIT_FW_REGION                        = 0x21,
    CLEAR_FW_DATA_BLOCK                     = 0x22,
    VALIDATE_FW_IMAGE                       = 0x23,
    WAIT_FW_OPS_BLOCK_RECEIVED              = 0x24,
    NVDIMM_IS_UPDATE_NEEDED                 = 0x25,
    NVDIMM_RUN_UPDATE_USING_LID             = 0x26,
    NVDIMM_GET_TPM                          = 0x27,
    NVDIMM_SET_KEY_REG                      = 0x28,
    NVDIMM_ENCRYPT_ENABLE                   = 0x29,
    NVDIMM_CRYPTO_ERASE                     = 0x2A,
    NVDIMM_CHECK_VALID_ATTR_DATA            = 0x2B,
    NVDIMM_HANDLE_CONFLICTING_KEYS          = 0x2C,
    NVDIMM_ENCRYPT_UNLOCK                   = 0x2D,
    NVDIMM_GET_DARN_NUMBER                  = 0x2E,
    NVDIMM_KEYIFY_RANDOM_NUMBER             = 0x2F,
    SET_ATTR_NVDIMM_ENCRYPTION_KEYS_FW      = 0x30,
    SEND_ATTR_NVDIMM_ARMED                  = 0x31,
    NVDIMM_FACTORY_RESET                    = 0x32,
    NVDIMM_ES_HEALTH_CHECK                  = 0x33, // Health check on the ES (energy source)/backup power module
    NVDIMM_CHECK_RESETN                     = 0x34,
    NVDIMM_CHECK_CSAVE                      = 0x35,
    NVDIMM_MODULE_HEALTH_STATUS_CHECK       = 0x36,
    NVDIMM_SET_EVENT_NOTIFICATION           = 0x37,
    NVDIMM_NVM_HEALTH_CHECK                 = 0x38, // Health check on the NVM (non-volatile memory)/flash
    NVDIMM_WAIT_OPER_OPS_COMPLETE           = 0x39,
    NVDIMM_COMPARE_CKSUM                    = 0x3A,
    NVDIMM_CHECK_FW_SLOT                    = 0x3B,
    NVDIMM_ARM_PRE_CHECK                    = 0x3C,
    NVDIMM_ARM                              = 0x3D,
    CLEAR_FW_OPS_STATUS                     = 0x3E,
    NVDIMM_SECURE_ERASE_VERIFY_STATUS       = 0x3F,
    NVDIMM_STATS                            = 0x40,
};

/**
 * @enum nvdimmReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum nvdimmReasonCode
{
    NVDIMM_INVALID_REASONCODE                  = NVDIMM_COMP_ID | 0x00,   // Invalid Reasoncode
    NVDIMM_INVALID_OPERATION                   = NVDIMM_COMP_ID | 0x01,
    NVDIMM_INVALID_DEVICE_TYPE                 = NVDIMM_COMP_ID | 0x02,
    NVDIMM_ATTR_INFO_NOT_FOUND                 = NVDIMM_COMP_ID | 0x03,
    NVDIMM_INVALID_CHIP                        = NVDIMM_COMP_ID | 0x04,
    NVDIMM_I2C_MASTER_PATH_ERROR               = NVDIMM_COMP_ID | 0x05,
    NVDIMM_TARGET_NULL                         = NVDIMM_COMP_ID | 0x06,
    NVDIMM_INVALID_ADDR_OFFSET_SIZE            = NVDIMM_COMP_ID | 0x07,
    NVDIMM_OVERFLOW_ERROR                      = NVDIMM_COMP_ID | 0x08,
    NVDIMM_I2C_WRITE_PAGE_SIZE_ZERO            = NVDIMM_COMP_ID | 0x09,
    NVDIMM_INVALID_OFFSET                      = NVDIMM_COMP_ID | 0x0A,
    NVDIMM_READ_FAILURE                        = NVDIMM_COMP_ID | 0x0B,   // NV Controller read failure
    NVDIMM_WRITE_FAILURE                       = NVDIMM_COMP_ID | 0x0C,   // NV Controller write failure
    NVDIMM_BACKUP_TIMEOUT                      = NVDIMM_COMP_ID | 0x0D,   // Backup/save timeout
    NVDIMM_RESTORE_TIMEOUT                     = NVDIMM_COMP_ID | 0x0E,   // Restore timeout
    NVDIMM_ERASE_TIMEOUT                       = NVDIMM_COMP_ID | 0x0F,   // Erase timeout
    NVDIMM_CHARGE_TIMEOUT                      = NVDIMM_COMP_ID | 0x10,   // Battery charging timeout
    NVDIMM_ARM_TIMEOUT                         = NVDIMM_COMP_ID | 0x11,   // Arming timeout
    NVDIMM_SET_ES_ERROR                        = NVDIMM_COMP_ID | 0x12,   // Failure to set the ES policy
    NVDIMM_MSS_STR_ENTRY_ERROR                 = NVDIMM_COMP_ID | 0x13,   // Failure to enter STR
    NVDIMM_MSS_STR_EXIT_ERROR                  = NVDIMM_COMP_ID | 0x14,   // Failure to exit STR
    NVDIMM_MSS_POST_RSTR_ERROR                 = NVDIMM_COMP_ID | 0x15,   // Failure to perform post restore work
    NVDIMM_OPEN_PAGE_TIMEOUT                   = NVDIMM_COMP_ID | 0x16,   // Open page timeout
    NVDIMM_STATUS_TIMEOUT                      = NVDIMM_COMP_ID | 0x17,   // Status timeout
    NVDIMM_ARM_FAILED                          = NVDIMM_COMP_ID | 0x18,   // Failure to arm reset_n
    NVDIMM_ERASE_FAILED                        = NVDIMM_COMP_ID | 0x19,   // Failure to erase
    NVDIMM_RESTORE_FAILED                      = NVDIMM_COMP_ID | 0x1A,   // Failure to restore
    NVDIMM_NOT_READY                           = NVDIMM_COMP_ID | 0x1B,   // NVDIMM not ready for host to access
    NVDIMM_NULL_FIRMWARE_REQUEST_PTR           = NVDIMM_COMP_ID | 0x1C,   // Firmware request is NULL
    NVDIMM_UNSUPPORTED_NVDIMM_TYPE             = NVDIMM_COMP_ID | 0x1D,   // Unsupported NVDIMM type for update
    NVDIMM_OPERATION_IN_PROGRESS               = NVDIMM_COMP_ID | 0x1E,   // NV controller is busy
    NVDIMM_CHECKSUM_ERROR                      = NVDIMM_COMP_ID | 0x1F,   // Checksum error between host and nv calculated
    NVDIMM_ZERO_TOTAL_REGIONS                  = NVDIMM_COMP_ID | 0x20,   // Zero write regions calculated
    NVDIMM_UPDATE_MODE_UNCHANGED               = NVDIMM_COMP_ID | 0x21,   // Unable to change update mode
    NVDIMM_FW_OPS_IN_PROGRESS_TIMEOUT          = NVDIMM_COMP_ID | 0x22,   // Operations In Progress timeout
    NVDIMM_DATA_SIZE_TOO_LARGE                 = NVDIMM_COMP_ID | 0x23,   // Trying to write too much data
    NVDIMM_DATA_SIZE_INVALID                   = NVDIMM_COMP_ID | 0x24,   // Data size is invalid
    NVDIMM_BLOCK_NOT_RECEIVED                  = NVDIMM_COMP_ID | 0x25,   // Block data not received
    NVDIMM_FW_OPS_NOT_SUCCESSFUL               = NVDIMM_COMP_ID | 0x26,   // Unsuccessful Firmware Operation
    NVDIMM_UPDATE_NOT_SUPPORTED                = NVDIMM_COMP_ID | 0x27,   // NV controller cannot be updated
    NVDIMM_START_UPDATE                        = NVDIMM_COMP_ID | 0x28,   // start update
    NVDIMM_UPDATE_COMPLETE                     = NVDIMM_COMP_ID | 0x29,   // update completed
    NVDIMM_TPM_NOT_FOUND                       = NVDIMM_COMP_ID | 0x2A,   // TPM not found
    NVDIMM_POWER_SAVE_FAILURE                  = NVDIMM_COMP_ID | 0x2B,   // Save failed due to power loss
    NVDIMM_CSAVE_ERROR                         = NVDIMM_COMP_ID | 0x2C,   // CSave failed due to error
    NVDIMM_VOLTAGE_REGULATOR_FAILED            = NVDIMM_COMP_ID | 0x2D,
    NVDIMM_VDD_LOST                            = NVDIMM_COMP_ID | 0x2E,
    NVDIMM_VPP_LOST                            = NVDIMM_COMP_ID | 0x2F,
    NVDIMM_VTT_LOST                            = NVDIMM_COMP_ID | 0x30,
    NVDIMM_DRAM_NOT_SELF_REFRESH               = NVDIMM_COMP_ID | 0x31,
    NVDIMM_CONTROLLER_HARDWARE_ERROR           = NVDIMM_COMP_ID | 0x32,
    NVDIMM_NVM_CONTROLLER_ERROR                = NVDIMM_COMP_ID | 0x33,
    NVDIMM_NVM_LIFETIME_ERROR                  = NVDIMM_COMP_ID | 0x34,
    NVDIMM_NOT_ENOUGH_ENERGY_FOR_CSAVE         = NVDIMM_COMP_ID | 0x35,
    NVDIMM_INVALID_FIRMWARE_ERROR              = NVDIMM_COMP_ID | 0x36,   // Module Health Status Registers
    NVDIMM_CONFIG_DATA_ERROR                   = NVDIMM_COMP_ID | 0x37,
    NVDIMM_NO_ES_PRESENT                       = NVDIMM_COMP_ID | 0x38,
    NVDIMM_ES_POLICY_NOT_SET                   = NVDIMM_COMP_ID | 0x39,
    NVDIMM_ES_HARDWARE_FAILURE                 = NVDIMM_COMP_ID | 0x3A,
    NVDIMM_ES_HEALTH_ASSESSMENT_ERROR          = NVDIMM_COMP_ID | 0x3B,
    NVDIMM_ES_LIFETIME_ERROR                   = NVDIMM_COMP_ID | 0x3C,
    NVDIMM_ES_TEMP_ERROR                       = NVDIMM_COMP_ID | 0x3D,
    NVDIMM_SET_EVENT_NOTIFICATION_ERROR        = NVDIMM_COMP_ID | 0x3E,
    NVDIMM_VERIF_BYTE_CHECK_FAILED             = NVDIMM_COMP_ID | 0x3F,   // Encryption key reg verif failed
    NVDIMM_ENCRYPTION_ENABLE_FAILED            = NVDIMM_COMP_ID | 0x40,   // Encryption enable failed
    NVDIMM_ENCRYPTION_ERASE_PENDING_FAILED     = NVDIMM_COMP_ID | 0x41,   // Encryption crypto erase pending failed
    NVDIMM_ENCRYPTION_ERASE_FAILED             = NVDIMM_COMP_ID | 0x42,   // Encryption crypto erase failed
    NVDIMM_ENCRYPTION_UNLOCK_FAILED            = NVDIMM_COMP_ID | 0x43,   // Encryption unlock failed
    NVDIMM_ENCRYPTION_INVALID_ATTRIBUTE        = NVDIMM_COMP_ID | 0x44,   // Encryption attribute key data invalid
    NVDIMM_ENCRYPTION_KEY_ATTRS_INVALID        = NVDIMM_COMP_ID | 0x45,   // Encryption key attributes are both invalid
    NVDIMM_ENCRYPTION_MAX_DARN_ERRORS          = NVDIMM_COMP_ID | 0x46,   // Darn random key gen reached max errors
    NVDIMM_ENCRYPTION_BAD_RANDOM_DATA          = NVDIMM_COMP_ID | 0x47,   // Generated key data not valid
    NVDIMM_CANNOT_MAKE_ATTRIBUTE               = NVDIMM_COMP_ID | 0x48,   // Cannot make Attribute
    NVDIMM_ES_HEALTH_CHECK_IN_PROGRESS_FAILURE = NVDIMM_COMP_ID | 0x49,   // !< pertains to ES_CMD_STATUS0[0]; the ES health check in progress flag
    NVDIMM_ES_HEALTH_CHECK_REPORTED_FAILURE    = NVDIMM_COMP_ID | 0x4A,   // !< pertains to ES_CMD_STATUS0[2]; the ES health check reported a failure flag
    NVDIMM_ES_LIFETIME_MIN_REQ_NOT_MET         = NVDIMM_COMP_ID | 0x4B,   // !< pertains to ES_LIFETIME; BPM does not meet minimum requirement for a new BPM
    NVDIMM_ES_HEALTH_CHECK_NEVER_INITIATED     = NVDIMM_COMP_ID | 0x4C,   // !< An ES health check was never initiated at start of IPL
    NVDIMM_NVM_HEALTH_CHECK_FAILED             = NVDIMM_COMP_ID | 0x4D,   // !< An NVM health check on the NVDIMM failed
    NVDIMM_VENDOR_LOG_TIMEOUT                  = NVDIMM_COMP_ID | 0x4E,   // Vendor log for FFDC timeout
    NVDIMM_VENDOR_LOG_CKSUM_FAILED             = NVDIMM_COMP_ID | 0x4F,   // Vendor log for FFDC checksum fail
    NVDIMM_INVALID_FW_SLOT                     = NVDIMM_COMP_ID | 0x50,
    NVDIMM_ERASE_ERROR                         = NVDIMM_COMP_ID | 0x51,
    NVDIMM_ARM_PRE_CHECK_FAILED                = NVDIMM_COMP_ID | 0x52,
    NVDIMM_ARM_ENCRYPTION_UNLOCK_FAILED        = NVDIMM_COMP_ID | 0x53,
    NVDIMM_ARM_RETRY                           = NVDIMM_COMP_ID | 0x54,
    NVDIMM_CLEAR_FW_OPS_STATUS_TIMEOUT         = NVDIMM_COMP_ID | 0x55,   // Failed to clear FW_OPS_STATUS
    NVDIMM_NOT_RUNNING_LATEST_LEVEL            = NVDIMM_COMP_ID | 0x56,   // Either running from slot 0 or level was not updated
    NVDIMM_ERASE_VERIFY_STATUS_NONZERO         = NVDIMM_COMP_ID | 0x57,
    NVDIMM_ERASE_VERIFY_RESULT_NONZERO         = NVDIMM_COMP_ID | 0x58,
    NVDIMM_INVALID_DIMM_SLOT                   = NVDIMM_COMP_ID | 0x59,
};

enum UserDetailsTypes
{
        NVDIMM_UDT_NO_FORMAT       = 0x0,
        NVDIMM_UDT_PARAMETERS      = 0x1,
        NVDIMM_OP_PARAMETERS       = 0x2,
};

};  // end NVDIMM

#endif
