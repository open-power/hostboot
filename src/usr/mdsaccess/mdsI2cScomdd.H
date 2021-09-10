/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mdsaccess/mdsI2cScomdd.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#ifndef MDS_I2C_SCOMDD_H
#define MDS_I2C_SCOMDD_H

/**
 *  @file mdsI2cScomdd.H
 *
 *  @brief Provides the interfaces to perform an I2C SCOM on the MDS
 *         (Microarchitectural Data Sampling) controller.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>                     // size_t, int64_t
#include <devicefw/driverif_common.H>   // DeviceFW::OperationType
#include <targeting/common/target.H>    // TARGETING::Target
#include <errl/errlentry.H>             // errlHndl_t

namespace MDS_I2C_SCOMDD
{

/**
 * @brief Performs an I2C SCOM access operation via the MDS controller.
 *
 * @details This function performs an I2C SCOM access operation. It follows a
 *          pre-defined prototype functions in order to be registered with the
 *          device-driver framework.
 *
 * @param[in] i_opType       Operation type, see DeviceFW::OperationType
 *                           in driverif_common.H.
 * @param[in] i_target       MDS Controller target
 * @param[in/out] io_buffer  Read:  Pointer to output data storage
 *                           Write: Pointer to input data storage
 * @param[in] i_buflen       Read/Write: Size of the data storage
 * @param[in] i_accessType   DeviceFW::AccessType enum (driverif.H)
 * @param[in] i_args         This is an argument list from the DD framework.
 *                           In this function, there's only one argument,
 *                           which is the SCOM address
 * @return  errlHndl_t       nullptr on success, non-null ptr on an error
 *
 * @pre i_target must be of type TYPE_MDS_CTRL else error will result
 * @pre i_opType must be of DeviceFW::READ or DeviceFW::WRITE else error will result
 * @pre io_buffer cannot be a nullptr else error will result
 * @pre i_buflen must be of size 32 bits (4 bytes) else error will result
 * @pre scom address, although being received as a 64 bit integer, must be a a 32 bit
 *                    value i.e. the first 4 bytes must be 0 else error will result
 */
errlHndl_t mdsI2cScomPerformOp(DeviceFW::OperationType i_opType,
                               TARGETING::Target*      i_target,
                               void*   io_buffer,
                               size_t& i_buflen,
                               int64_t i_accessType,
                               va_list i_args);

} // namespace MDS_I2C_SCOMDD

#endif // #ifndef MDS_I2C_SCOMDD_H
