/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/nvdimmreasoncodes.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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

// SRC Graveyard
// Contains error log descriptions for SRCs that were
// removed from the code but we need to still provide
// backward compatible parser logic for.
/*@
 *@errortype
 *@reasoncode       NVDIMM_NOT_READY
 *@severity         ERRORLOG_SEV_UNRECOVERABLE
 *@moduleid         NVDIMM_CHECK_READY
 *@userdata1[0:31]  Ret value from ready register
 *@userdata1[32:63] Target Huid
 *@userdata2        <UNUSED>
 *@devdesc          Failed to read ready status or NVDIMM not ready
 *                   for host access. (userdata1 != 0xA5)
 *@custdesc         NVDIMM not ready
 */

/*@
 *@errortype
 *@reasoncode       NVDIMM_STATUS_TIMEOUT
 *@severity         ERRORLOG_SEV_PREDICTIVE
 *@moduleid         NVDIMM_POLL_STATUS
 *@userdata1[0:31]  Related ops (0xff = NA)
 *@userdata1[32:63] Target Huid
 *@userdata2[0:31]  Polled value
 *@userdata2[32:63] Timeout value
 *@devdesc          Encountered timeout while performing operation on NVDIMM
 *                   Refer to userdata1 for which operation it timed out.
 *@custdesc         NVDIMM timed out
 */

/*@
 *@errortype
 *@reasoncode       NVDIMM_SET_ES_ERROR
 *@severity         ERRORLOG_SEV_PREDICTIVE
 *@moduleid         NVDIMM_SET_ES
 *@userdata1[0:31]  Related ops (0xff = NA)
 *@userdata1[32:63] Target Huid
 *@userdata2        <UNUSED>
 *@devdesc          Encountered error setting the energy source policy
 *                   Make sure the connection between energy source and
 *                   NVDIMM is intact
 *@custdesc         NVDIMM encountered error setting the energy source policy
 */

/*@
 *@errortype
 *@reasoncode      NVDIMM_RESTORE_FAILED
 *@severity        ERRORLOG_SEV_UNRECOVERABLE
 *@moduleid        NVDIMM_RESTORE
 *@userdata1       Target Huid
 *@userdata2       <UNUSED>
 *@devdesc         NVDIMM failed to restore data. This is likely
 *                  due to failure entering self-refresh and/or
 *                  restore timeout (Controller error)
 *@custdesc        NVDIMM failed to restore data
 */

/*@
 *@errortype
 *@reasoncode       NVDIMM_ERASE_FAILED
 *@severity         ERRORLOG_SEV_PREDICTIVE
 *@moduleid         NVDIMM_CHECK_ERASE
 *@userdata1[0:31]  Related ops (0xff = NA)
 *@userdata1[32:63] Target Huid
 *@userdata2        <UNUSED>
 *@devdesc          Encountered error erasing previously stored data image
 *                   on NVDIMM. Likely due to timeout and/or controller error
 *@custdesc         NVDIMM error erasing data image
 */

/*@
 *@errortype
 *@reasoncode       NVDIMM_OPEN_PAGE_TIMEOUT
 *@severity         ERRORLOG_SEV_UNRECOVERABLE
 *@moduleid         NVDIMM_OPEN_PAGE
 *@userdata1[0:31]  Related ops (0xff = NA)
 *@userdata1[32:63] Target Huid
 *@userdata2[0:31]  Polled value
 *@userdata2[32:63] Timeout value
 *@devdesc          NVDIMM OpenPage timed out, likely due to controller error
 *@custdesc         Encountered error performing internal operaiton
 *                   on NVDIMM
 */

/*@
 *@errortype
 *@moduleid         UPDATE_IMAGE
 *@reasoncode       NVDIMM_OPERATION_IN_PROGRESS
 *@userdata1        NVDIMM Target Huid
 *@userdata2        NVDIMM_CMD_STATUS0
 *@devdesc          NV controller is busy so no update can run
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         UPDATE_IMAGE
 *@reasoncode       NVDIMM_CHECKSUM_ERROR
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:15]  Host checksum calculated
 *@userdata2[16:31] NV checksum returned
 *@userdata2[32:47] size of data for checksum
 *@devdesc          Checksum failure when transferring region
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         UPDATE_IMAGE_DATA
 *@reasoncode       NVDIMM_ZERO_TOTAL_REGIONS
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:15]  Firmware image size
 *@userdata2[16:31] region_size
 *@devdesc          Firmware image size is not large enough
 *                  (needs to be at least region_size)
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         UPDATE_IMAGE_DATA
 *@reasoncode       NVDIMM_CHECKSUM_ERROR
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:15]  Host checksum calculated
 *@userdata2[16:31] NV checksum returned
 *@userdata2[32:47] size of data for checksum
 *@userdata2[48:63] region
 *@devdesc          Checksum failure when transferring region
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         CHANGE_FW_UPDATE_MODE
 *@reasoncode       NVDIMM_UPDATE_MODE_UNCHANGED
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:7]   Mode setting
 *@userdata2[8:15]  FIRMWARE_OPS_STATUS byte
 *@devdesc          Firmware Update Mode not updated
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         WAIT_FW_OPS_BLOCK_RECEIVED
 *@reasoncode       NVDIMM_BLOCK_NOT_RECEIVED
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:15]  Last FIRMWARE_OPS_STATUS read
 *@userdata2[16:31] Timeout (msecs)
 *@devdesc          Firmware Operation timed out waiting for
 *                  data block transfer confirmation
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         WAIT_FW_OPS_COMPLETE
 *@reasoncode       NVDIMM_FW_OPS_IN_PROGRESS_TIMEOUT
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:15]  Last NVDIMM_CMD_STATUS0 read
 *@userdata2[16:31] Timeout (seconds)
 *@devdesc          Firmware Operation timed out
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         BYTE_REGION_BLOCK_TRANSFER
 *@reasoncode       NVDIMM_DATA_SIZE_TOO_LARGE
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:15]  Data size trying to transfer
 *@userdata2[16:31] Maximum data size allowed
 *@userdata2[32:47] Calculated blocks_per_region
 *@userdata2[48-63] Maximum blocks_per_region allowed
 *@devdesc          Data size too big to transfer in one command
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         BYTE_REGION_BLOCK_TRANSFER
 *@reasoncode       NVDIMM_DATA_SIZE_INVALID
 *@userdata1        NVDIMM Target Huid
 *@userdata2[0:15]  Data size trying to transfer
 *@userdata2[16:31] Calculated maximum data size transfer
 *@userdata2[32:47] Blocks per region
 *@userdata2[48-63] Bytes transferred per block
 *@devdesc          Data size too big to transfer
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         COMMIT_FW_REGION
 *@reasoncode       NVDIMM_FW_OPS_NOT_SUCCESSFUL
 *@userdata1        NVDIMM Target Huid
 *@userdata2        Operation command being verified
 *@devdesc          Firmware Operation not successful
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         CLEAR_FW_DATA_BLOCK
 *@reasoncode       NVDIMM_FW_OPS_NOT_SUCCESSFUL
 *@userdata1        NVDIMM Target Huid
 *@userdata2        Operation command being verified
 *@devdesc          Firmware Operation not successful
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@moduleid         VALIDATE_FW_IMAGE
 *@reasoncode       NVDIMM_FW_OPS_NOT_SUCCESSFUL
 *@userdata1        NVDIMM Target Huid
 *@userdata2        Operation command being verified
 *@devdesc          Firmware Operation not successful
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@reasoncode       NVDIMM_UNSUPPORTED_NVDIMM_TYPE
 *@moduleid         NVDIMM_RUN_UPDATE
 *@userdata1[0:31]  Unsupported Type
 *@userdata1[32:63] NVDIMM Target Huid
 *@userdata2[0:31]  Supported nvdimm type
 *@userdata2[32:63] Other supported nvdimm type
 *@devdesc          Unable to update an unsupported NVDIMM type
 *@custdesc         NVDIMM not updated
 */

/*@
 *@errortype
 *@reasoncode       NVDIMM_UPDATE_NOT_SUPPORTED
 *@moduleid         NVDIMM_IS_UPDATE_NEEDED
 *@userdata1[0:31]  NVDIMM version level
 *@userdata1[32:63] NVDIMM Target Huid
 *@userdata2        NVDIMM type (manufacturer and product)
 *@devdesc          Unable to update an NVDIMM at this code level
 *@custdesc         NVDIMM not updated
 */

/*@
 * @errortype
 * @reasoncode       NVDIMM_OVERFLOW_ERROR
 * @severity         ERRL_SEV_UNRECOVERABLE
 * @moduleid         NVDIMM_PERFORM_OP
 * @userdata1[0:31]  Offset
 * @userdata1[32:63] Buffer Length
 * @userdata2        Device Max Size (in KB)
 * @devdesc          I2C Buffer Length + Offset > Max Size
 * @custdesc         A problem occurred during the IPL of the
 *                   system: I2C buffer offset is too large.
 */

/*@
 * @errortype
 * @reasoncode     NVDIMM_INVALID_OPERATION
 * @severity       ERRL_SEV_UNRECOVERABLE
 * @moduleid       NVDIMM_PERFORM_OP
 * @userdata1      Operation Type
 * @userdata2      Chip to Access
 * @devdesc        Invalid operation type.
 */

/*@
 * @errortype
 * @reasoncode       NVDIMM_INVALID_OFFSET
 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
 * @moduleid         NVDIMM_CROSSESNVDIMMPAGEBOUNDARY
 * @userdata1        Offset attempting to access
 * @userdata2        Requested buffer length
 * @devdesc          NVDIMM register offset out of bound
 */

/*@
 * @errortype
 * @reasoncode     NVDIMM_I2C_WRITE_PAGE_SIZE_ZERO
 * @severity       ERRL_SEV_UNRECOVERABLE
 * @moduleid       NVDIMM_WRITE
 * @userdata1      HUID of target
 * @devdesc        I2C write page size is zero.
 */

/*@
 * @errortype
 * @reasoncode       NVDIMM_INVALID_DEVICE_TYPE
 * @severity         ERRL_SEV_UNRECOVERABLE
 * @moduleid         NVDIMM_PREPAREADDRESS
 * @userdata1        Address Size (aka Device Type)
 * @devdesc          The Device type not supported (addrSize)
 * @custdesc         A problem was detected during the IPL of
 *                   the system: Device type not supported.
 */

/*@
 * @errortype
 * @reasoncode       NVDIMM_ATTR_INFO_NOT_FOUND
 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
 * @moduleid         NVDIMM_READATTRIBUTES
 * @userdata1        HUID of target
 * @devdesc          NVDIMM attribute was not found
 */

/*@
 * @errortype
 * @reasoncode       NVDIMM_INVALID_ADDR_OFFSET_SIZE
 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
 * @moduleid         NVDIMM_READATTRIBUTES
 * @userdata1        HUID of target
 * @userdata2        Address Offset Size
 * @devdesc          Invalid address offset size
 */

/*@
 * @errortype
 * @reasoncode       NVDIMM_I2C_MASTER_PATH_ERROR
 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
 * @moduleid         NVDIMM_GETI2CMASTERTARGET
 * @userdata1        HUID of target
 * @userdata2        Compressed Entity Path
 * @devdesc          I2C master entity path doesn't exist.
 */

/*@
 * @errortype
 * @reasoncode       NVDIMM_TARGET_NULL
 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
 * @moduleid         NVDIMM_GETI2CMASTERTARGET
 * @userdata1        HUID of target
 * @userdata2        Compressed Entity Path
 * @devdesc          I2C master path target is null.
 */

/*@
 * @errortype
 * @severity          ERRL_SEV_PREDICTIVE
 * @moduleid          NOTIFY_NVDIMM_PROTECTION_CHG
 * @reasoncode        NVDIMM_NULL_FIRMWARE_REQUEST_PTR
 * @userdata1         HUID of processor target
 * @userdata2[0:31]   Requested protection state
 * @userdata2[32:63]  Current armed state
 * @devdesc           Unable to inform PHYP of NVDIMM protection
 * @custdesc          Internal firmware error
 */

/*@
 *@errortype
 *@reasoncode       NVDIMM_ARM_FAILED
 *@severity         ERRORLOG_SEV_PREDICTIVE
 *@moduleid         NVDIMM_SET_ARM
 *@userdata1[0:31]  Related ops (0xff = NA)
 *@userdata1[32:63] Target Huid
 *@userdata2        <UNUSED>
 *@devdesc          Encountered error arming the catastrophic save
 *                   trigger on NVDIMM. Make sure an energy source
 *                   is connected to the NVDIMM and the ES policy
 *                   is set properly
 *@custdesc         NVDIMM encountered error arming save trigger
 */

#endif
