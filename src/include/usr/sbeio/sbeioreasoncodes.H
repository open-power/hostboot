/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbeioreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2024                        */
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
#ifndef __SBEIOREASONCODES_H
#define __SBEIOREASONCODES_H

// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace SBEIO
{

/**
* @enum SbeioModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum sbeioModuleId
{
    SBEIO_INVALID_MODULE                = 0x00,
    SBEIO_PSU                           = 0x01,
    SBEIO_FIFO                          = 0x02,
    SBEIO_FFDC_PARSER                   = 0x03,
    SBEIO_FIFO_CONTINUE_MPIPL           = 0x04,
    SBEIO_RUNTIME                       = 0x05,
    SBEIO_MEM_REGION                    = 0x06,
    SBEIO_RUNTIME_ATTR_OVERRIDE         = 0x07,
    SBEIO_FIFO_GET_SBE_FFDC             = 0x08,
    SBEIO_THRESHOLD_FSM                 = 0x09,
    SBEIO_EXTRACT_RC_HANDLER            = 0x0A,
    SBEIO_HANDLE_SBE_REG_VALUE          = 0x0B,
    SBEIO_GET_FFDC_HANDLER              = 0x0C,
    SBEIO_GET_SBE_RC                    = 0x0D,
    SBEIO_HANDLE_VITAL_ATTN             = 0x0E,
    SBEIO_SEND_PSU_QUIESCE_SBE          = 0x0F,
    SBEIO_DEAD_MAN_TIMER                = 0x10,
    SBEIO_PSU_GET_HW_REG                = 0x11,
    SBEIO_GET_FIFO_SBE_CAPABILITIES     = 0x12,
    SBEIO_PSUSYNCFABTOPOIDTABLE         = 0x13,
    SBEIO_FIFO_HALT                     = 0x14,
    SBEIO_RT_PSU                        = 0x15,
    SBEIO_PSU_PMIC_HEALTH_CHECK         = 0x16,
    SBEIO_RT_SCOM                       = 0x17,
    SBEIO_PROCESS_ATTR_ARRAY            = 0x18,
    SBEIO_FIFO_ODY_CHECKS               = 0x19,
    SBEIO_FIFO_SBE_FFDC                 = 0x1A,
    SBEIO_ODY_RECOVERY                  = 0x1B,
    SBEIO_ERRLUD_SPPE_CODE_LEVELS       = 0x1C,
    SBEIO_TEST_INJECT                   = 0x1D,
    SBEIO_ODY_CHECK_FLASH               = 0x1E,
    SBEIO_ODY_READ_SCRATCH_DATA         = 0x1F,
};

/**
 * @enum sbeioErrorType
 *
 * @brief Codes describing classes of errors.
 *
 */
enum sbeioErrorType
{
    // Errors will have this error type if they caused an HRESET to be
    // performed on the hardware involved.
    SBEIO_ERROR_TYPE_HRESET_PERFORMED   = SBEIO_COMP_ID | 1
};

/**
 * @enum sbeReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum sbeioReasonCode
{
    SBEIO_INVALID_REASONCODE           = SBEIO_COMP_ID | 0x00,   // Invalid RC

    // SBE PSU error codes
    SBEIO_PSU_RESPONSE_TIMEOUT         = SBEIO_COMP_ID | 0x01,
    SBEIO_PSU_RESPONSE_ERROR           = SBEIO_COMP_ID | 0x02,
    SBEIO_PSU_NOT_READY                = SBEIO_COMP_ID | 0x03,
    SBEIO_PSU_FFDC_MISSING             = SBEIO_COMP_ID | 0x04,
    SBEIO_PSU_SEND                     = SBEIO_COMP_ID | 0x05,
    SBEIO_PSU_INVALID_TARGET           = SBEIO_COMP_ID | 0x06,
    SBEIO_PSU_INVALID_OPERATION        = SBEIO_COMP_ID | 0x07,
    SBEIO_PSU_INVALID_MM_VIRT_TO_PHYS  = SBEIO_COMP_ID | 0x08,
    SBEIO_PSU_COUNT_UNEXPECTED         = SBEIO_COMP_ID | 0x09,
    SBEIO_PSU_RESPONSE_SBE_NOT_RESPONDING = SBEIO_COMP_ID | 0x0A,

    // SBE FIFO error codes
    SBEIO_FIFO_UPSTREAM_TIMEOUT        = SBEIO_COMP_ID | 0x10,
    SBEIO_FIFO_NO_DOWNSTREAM_EOT       = SBEIO_COMP_ID | 0x11,
    SBEIO_FIFO_INVALID_STATUS_DISTANCE = SBEIO_COMP_ID | 0x12,
    SBEIO_FIFO_RESPONSE_ERROR          = SBEIO_COMP_ID | 0x13,
    SBEIO_FIFO_DOWNSTREAM_TIMEOUT      = SBEIO_COMP_ID | 0x14,
    SBEIO_FIFO_INVALID_LENGTH          = SBEIO_COMP_ID | 0x15,
    SBEIO_FIFO_INVALID_OPERATION       = SBEIO_COMP_ID | 0x16,
    SBEIO_FIFO_NULL_TARGET             = SBEIO_COMP_ID | 0x17,
    SBEIO_FIFO_MASTER_TARGET           = SBEIO_COMP_ID | 0x18,
    SBEIO_FIFO_SENTINEL_TARGET         = SBEIO_COMP_ID | 0x19,

    // SBE FFDC Parser error codes
    SBEIO_FFDC_PARSER_BUFF_OVERFLOW    = SBEIO_COMP_ID | 0x1A,

    // Note - HWSV keys off of this to trigger a reconfig
    //   loop to recover the SBE
    //termination_rc
    SBEIO_DEAD_SBE                     = SBEIO_COMP_ID | 0x1B,

    // SBE FIFO error codes (continued...)
    SBEIO_UNSUPPORTED_CAPABILITIES_VERSION = SBEIO_COMP_ID | 0x1C,
    SBEIO_FIFO_NOT_ODYSSEY_OCMB        = SBEIO_COMP_ID | 0x1D,
    SBEIO_FIFO_NOT_ODYSSEY_OR_NOT_OCMB = SBEIO_COMP_ID | 0x1E,
    SBEIO_FIFO_PLATFORM_ERROR          = SBEIO_COMP_ID | 0x1F,

    // SBEIO Runtime error codes
    SBEIO_RT_INVALID_COMMAND           = SBEIO_COMP_ID | 0x30,
    SBEIO_RT_FUNCTION_NOT_SET          = SBEIO_COMP_ID | 0x31,
    SBEIO_RT_RSP_DATA_TOO_LARGE        = SBEIO_COMP_ID | 0x32,
    SBEIO_RT_INVALID_VERSION           = SBEIO_COMP_ID | 0x33,
    SBEIO_RT_MSG_SIZE_TOO_LARGE        = SBEIO_COMP_ID | 0x34,
    SBEIO_RT_DATA_OFFSET_TOO_SMALL     = SBEIO_COMP_ID | 0x35,
    SBEIO_RT_DATA_TOO_LARGE            = SBEIO_COMP_ID | 0x36,
    SBEIO_RT_RSP_FIELD_ALTERED         = SBEIO_COMP_ID | 0x37,
    SBEIO_RT_NO_SBE_COMM_BUFFER        = SBEIO_COMP_ID | 0x38,
    SBEIO_RT_FUNCTION_NOT_FOUND        = SBEIO_COMP_ID | 0x39,
    SBEIO_RT_NO_INTERFACE_POINTER      = SBEIO_COMP_ID | 0x3A,
    SBEIO_RT_NO_INTERFACE_FUNCTION     = SBEIO_COMP_ID | 0x3B,
    SBEIO_RT_NO_APPLY_ATTR_FUNCTION    = SBEIO_COMP_ID | 0x3C,
    SBEIO_RT_NULL_FIRMWARE_REQUEST_PTR = SBEIO_COMP_ID | 0x3D,

    // SBE Unsecure Memory Region error codes
    SBEIO_MEM_REGION_DOES_NOT_EXIST    = SBEIO_COMP_ID | 0x50,
    SBEIO_EXCEEDS_MAXIMUM_MEM_REGIONS  = SBEIO_COMP_ID | 0x51,

    SBEIO_BOOTED_UNEXPECTED_SIDE       = SBEIO_COMP_ID | 0x52,
    SBEIO_NO_RECOVERY_ACTION           = SBEIO_COMP_ID | 0x53,
    SBEIO_EXTRACT_RC_ERROR             = SBEIO_COMP_ID | 0x54,
    SBEIO_BOOT_FROM_BKP_SEEPROM        = SBEIO_COMP_ID | 0x55,
    SBEIO_INCORRECT_FCN_CALL           = SBEIO_COMP_ID | 0x56,
    SBEIO_RETURNED_FFDC                = SBEIO_COMP_ID | 0x57,
    SBEIO_SLAVE_TIMEOUT                = SBEIO_COMP_ID | 0x58,
    SBEIO_ATTEMPTING_REBOOT            = SBEIO_COMP_ID | 0x59,
    SBEIO_MORE_FFDC_THAN_EXPECTED      = SBEIO_COMP_ID | 0x5B,
    SBEIO_EXCEED_MAX_SIDE_SWITCHES     = SBEIO_COMP_ID | 0x5C,
    SBEIO_EXCEED_MAX_SIDE_BOOTS        = SBEIO_COMP_ID | 0x5D,
    SBEIO_SLAVE_FAILED_TO_BOOT         = SBEIO_COMP_ID | 0x5E,
    SBEIO_RECEIVED_UNEXPECTED_MSG      = SBEIO_COMP_ID | 0x5F,
    // SBE Vital Attention error code
    SBEIO_SBE_RC_VALUE_INFO            = SBEIO_COMP_ID | 0x60,
    // Init error codes
    SBEIO_RC_KERNEL_REG_FAILED         = SBEIO_COMP_ID | 0x61,
    SBEIO_SEEPROM_VERSION_MISMATCH     = SBEIO_COMP_ID | 0x62,
    SBEIO_START_DMT_CALLED_TWICE       = SBEIO_COMP_ID | 0x63,
    SBEIO_NO_PARENT_PROC               = SBEIO_COMP_ID | 0x64,
    SBEIO_COMMAND_NOT_SUPPORTED        = SBEIO_COMP_ID | 0x65,
    SBEIO_MVPD_READ_FAILURE            = SBEIO_COMP_ID | 0x66,
    SBEIO_MVPD_WRITE_FAILURE           = SBEIO_COMP_ID | 0x67,
    SBEIO_NO_RUNTIME_BUFFER            = SBEIO_COMP_ID | 0x68,
    SBEIO_EARLY_ERROR                  = SBEIO_COMP_ID | 0x69,
    // PMIC Health Check Data Logs
    SBEIO_PMIC_HEALTH_CHECK_DATA       = SBEIO_COMP_ID | 0x6A, // Do NOT alter the value, HMC dependency
    SBEIO_PMIC_FAILED_HEALTH_CHECK     = SBEIO_COMP_ID | 0x6B,
    SBEIO_RECONFIG_WITH_CLOCK_GUARD    = SBEIO_COMP_ID | 0x6C,
    // SBE Runtime Odyssey support
    SBEIO_SCOM_SUPPORT_READ            = SBEIO_COMP_ID | 0x6D,
    SBEIO_SCOM_SUPPORT_WRITE           = SBEIO_COMP_ID | 0x6E,
    // Attr exchange errors
    SBEIO_ATTR_MISMATCH_DETECTED       = SBEIO_COMP_ID | 0x6F,

    SBEIO_RECEIVE_CODE_LEVELS_BAD_MSG  = SBEIO_COMP_ID | 0x70,
    SBEIO_FIFO_SBE_ASYNC_FFDC_REQUEST  = SBEIO_COMP_ID | 0x71,
    SBEIO_ODY_RECOVERY_NOT_AVAILABLE   = SBEIO_COMP_ID | 0x72,
    SBEIO_OCMB_NULL_TARGET             = SBEIO_COMP_ID | 0x73,
    SBEIO_TEST_INJECT_HRESET           = SBEIO_COMP_ID | 0x74,
    SBEIO_ODY_FLASH_CHECK_ERR          = SBEIO_COMP_ID | 0x75,
    SBEIO_PMIC_TELEMETRY_DATA_DDR5     = SBEIO_COMP_ID | 0x76, // Do NOT alter the value, HMC dependency
    SBEIO_PMIC_HEALTH_CHECK_DATA_DDR5  = SBEIO_COMP_ID | 0x77, // Do NOT alter the value, HMC dependency
    SBEIO_HRESET_CHECK_FOR_READY_FAIL  = SBEIO_COMP_ID | 0x78,
    SBEIO_ODY_SCRATCH_DATA             = SBEIO_COMP_ID | 0x79,

    // Remove once we collect the FFDC ourselves - @todo-RTC:144313
    //termination_rc
    SBEIO_HWSV_COLLECT_SBE_RC          = SBEIO_COMP_ID | 0xFF,
};

enum UserDetailsTypes
{
        SBEIO_UDT_NO_FORMAT        = 0x0,
        SBEIO_UDT_PARAMETERS       = 0x1, // SBE Proc format, calls o3500.py
        SBEIO_UDT_SPPE_CODE_LEVELS = 0x2,
        SBEIO_UDT_SPPE_FORMAT      = 0x3, // SPPE Odyssey format, calls o4500.py
        SBEIO_UDT_SCRATCH_DATA     = 0x4, //reserved for future/offline parsing
        SBEIO_UDT_LOC              = 0x5, //reserved for future/offline parsing
        SBEIO_UDT_PMIC_HEALTH      = 0x6, //reserved for future/offline parsing
};


};  // end SBEIO

//*****************************************************
// SRC Graveyard
// Contains error log descriptions for SRCs that were
// removed from the code but we need to still provide
// backward compatible parser logic for.


/*@
 * @errortype
 * @moduleid     SBEIO_FIFO
 * @reasoncode   SBEIO_FIFO_NOT_ODYSSEY_OR_NOT_OCMB
 * @userdata1[0:31]  HUID of OCMB chip
 * @userdata1[32:63] ATTR_CHIP_ID of OCMB chip
 * @userdata2[0:7]   SBE FIFO Command Class
 * @userdata2[8:15]  SBE FIFO Command
 * @devdesc      Odyssey target is expected
 * @custdesc     Firmware error communicating with a chip
 */

/*@
 * @errortype    ERRORLOG::ERRL_SEV_INFORMATIONAL
 * @moduleid     SBEIO_GET_FFDC_HANDLER
 * @reasoncode   SBEIO_MORE_FFDC_THAN_EXPECTED
 * @userdata1    Maximum expected packages
 * @userdata2    Number of FFDC packages
 * @devdesc      Unexpected number of FFDC packages in buffer
 * @custdesc     Extra FFDC gathered, marked information event
 */

#endif
