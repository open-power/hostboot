/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbeioreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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

    // Remove once we collect the FFDC ourselves - @todo-RTC:144313
    //termination_rc
    SBEIO_HWSV_COLLECT_SBE_RC          = SBEIO_COMP_ID | 0xFF,
};

enum UserDetailsTypes
{
        SBEIO_UDT_NO_FORMAT       = 0x0,
        SBEIO_UDT_PARAMETERS      = 0x1,
};


};  // end SBE

#endif
