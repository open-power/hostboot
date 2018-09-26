/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/mux_i2c.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __MUX_I2C_H
#define __MUX_I2C_H

/**
 * @file mux_i2c.H
 *
 * @brief I2C MUX utility functions API
 *
 */

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
//  Integral support
#include <stdint.h>                   // uint64_t

//  Error handling support
#include <errl/errlentry.H>           // errlHndl_t

//  Targeting support
#include <targeting/common/target.H>  // TARGETING::TargetHandle_t

//  Driver support
#include <devicefw/driverif.H>        // DeviceFW::OperationType

namespace MUX_I2C
{

/**
 * @brief Performs a presence detect operation on an I2C MUX.
 *  This is used during the target discovery (hwas.C::discoverTargets) phase
 *
 * @note  As of current needs/requirements this always returns true (present).
 *
 * @param[in]  i_opType        Operation type, see DeviceFW::OperationType
 *                             in driverif.H
 * @param[in]  i_target        I2C MUX target
 * @param[out] o_isPresentBuffer     Pointer to output data storage
 *                                   Output: is present = 1, is not present = 0
 * @param[out] o_isPresentBufferSize Size of o_isPresentBuffer
 *                                   (in bytes, always 1)
 * @param[in]  i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]  i_args          In this function, there are no arguments.
 * @return     errlHndl_t      Returns a pointer to an ErrlEntry if error,
 *                             else nullptr if no error
 */
 errlHndl_t i2cMuxPresenceDetect(DeviceFW::OperationType        i_opType,
                                 TARGETING::TargetHandle_t      i_target,
                                 void*   o_isPresentBuffer,
                                 size_t& o_isPresentBufferSize,
                                 int64_t i_accessType,
                                 va_list i_args);
}  // namespace MUX_I2C

#endif
