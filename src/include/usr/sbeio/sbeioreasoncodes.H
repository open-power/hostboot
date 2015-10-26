/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbeioreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

};

};  // end SBE

#endif
