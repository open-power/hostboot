/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimmreasoncodes.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
};

/**
 * @enum nvdimmReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum nvdimmReasonCode
{
    NVDIMM_INVALID_REASONCODE               = NVDIMM_COMP_ID | 0x00,   // Invalid Reasoncode
    NVDIMM_INVALID_OPERATION                = NVDIMM_COMP_ID | 0x01,
    NVDIMM_INVALID_DEVICE_TYPE              = NVDIMM_COMP_ID | 0x02,
    NVDIMM_ATTR_INFO_NOT_FOUND              = NVDIMM_COMP_ID | 0x03,
    NVDIMM_INVALID_CHIP                     = NVDIMM_COMP_ID | 0x04,
    NVDIMM_I2C_MASTER_PATH_ERROR            = NVDIMM_COMP_ID | 0x05,
    NVDIMM_TARGET_NULL                      = NVDIMM_COMP_ID | 0x06,
    NVDIMM_INVALID_ADDR_OFFSET_SIZE         = NVDIMM_COMP_ID | 0x07,
    NVDIMM_OVERFLOW_ERROR                   = NVDIMM_COMP_ID | 0x08,
    NVDIMM_I2C_WRITE_PAGE_SIZE_ZERO         = NVDIMM_COMP_ID | 0x09,
    NVDIMM_INVALID_OFFSET                   = NVDIMM_COMP_ID | 0x0A,
    NVDIMM_READ_FAILURE                     = NVDIMM_COMP_ID | 0x0B,   // NV Controller read failure
    NVDIMM_WRITE_FAILURE                    = NVDIMM_COMP_ID | 0x0C,   // NV Controller write failure
    NVDIMM_BACKUP_TIMEOUT                   = NVDIMM_COMP_ID | 0x0D,   // Backup/save timeout
    NVDIMM_RESTORE_TIMEOUT                  = NVDIMM_COMP_ID | 0x0E,   // Restore timeout
    NVDIMM_ERASE_TIMEOUT                    = NVDIMM_COMP_ID | 0x0F,   // Erase timeout
    NVDIMM_CHARGE_TIMEOUT                   = NVDIMM_COMP_ID | 0x10,   // Battery charging timeout
    NVDIMM_ARM_TIMEOUT                      = NVDIMM_COMP_ID | 0x11,   // Arming timeout
    NVDIMM_SET_ES_ERROR                     = NVDIMM_COMP_ID | 0x12,   // Failure to set the ES policy
    NVDIMM_MSS_STR_ENTRY_ERROR              = NVDIMM_COMP_ID | 0x13,   // Failure to enter STR
    NVDIMM_MSS_STR_EXIT_ERROR               = NVDIMM_COMP_ID | 0x14,   // Failure to exit STR
    NVDIMM_MSS_POST_RSTR_ERROR              = NVDIMM_COMP_ID | 0x15,   // Failure to perform post restore work
    NVDIMM_OPEN_PAGE_TIMEOUT                = NVDIMM_COMP_ID | 0x16,   // Open page timeout
    NVDIMM_STATUS_TIMEOUT                   = NVDIMM_COMP_ID | 0x17,   // Status timeout
    NVDIMM_ARM_FAILED                       = NVDIMM_COMP_ID | 0x18,   // Failure to arm reset_n
    NVDIMM_ERASE_FAILED                     = NVDIMM_COMP_ID | 0x19,   // Failure to erase
    NVDIMM_RESTORE_FAILED                   = NVDIMM_COMP_ID | 0x1A,   // Failure to restore
    NVDIMM_NOT_READY                        = NVDIMM_COMP_ID | 0x1B,   // NVDIMM not ready for host to access
    NVDIMM_NULL_FIRMWARE_REQUEST_PTR        = NVDIMM_COMP_ID | 0x1C,   // Firmware request is NULL
    NVDIMM_UNSUPPORTED_NVDIMM_TYPE          = NVDIMM_COMP_ID | 0x1D,   // Unsupported NVDIMM type for update
    NVDIMM_OPERATION_IN_PROGRESS            = NVDIMM_COMP_ID | 0x1E,   // NV controller is busy
    NVDIMM_CHECKSUM_ERROR                   = NVDIMM_COMP_ID | 0x1F,   // Checksum error between host and nv calculated
    NVDIMM_ZERO_TOTAL_REGIONS               = NVDIMM_COMP_ID | 0x20,   // Zero write regions calculated
    NVDIMM_UPDATE_MODE_UNCHANGED            = NVDIMM_COMP_ID | 0x21,   // Unable to change update mode
    NVDIMM_FW_OPS_IN_PROGRESS_TIMEOUT       = NVDIMM_COMP_ID | 0x22,   // Operations In Progress timeout
    NVDIMM_DATA_SIZE_TOO_LARGE              = NVDIMM_COMP_ID | 0x23,   // Trying to write too much data
    NVDIMM_DATA_SIZE_INVALID                = NVDIMM_COMP_ID | 0x24,   // Data size is invalid
    NVDIMM_BLOCK_NOT_RECEIVED               = NVDIMM_COMP_ID | 0x25,   // Block data not received
    NVDIMM_FW_OPS_NOT_SUCCESSFUL            = NVDIMM_COMP_ID | 0x26,   // Unsuccessful Firmware Operation
    NVDIMM_UPDATE_NOT_SUPPORTED             = NVDIMM_COMP_ID | 0x27,   // NV controller cannot be updated
};

enum UserDetailsTypes
{
        NVDIMM_UDT_NO_FORMAT       = 0x0,
        NVDIMM_UDT_PARAMETERS      = 0x1,
};

};  // end NVDIMM

#endif
