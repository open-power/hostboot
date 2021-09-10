/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mdsaccess/mdsAccessUtils.H $                          */
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

#ifndef MDS_ACCESS_UTILS_H
#define MDS_ACCESS_UTILS_H

/**
 * @file mdsAccessUtils.H
 *
 * @brief Provides common utility functions for the MDS controller
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>                   // size_t, int64_t
#include <devicefw/driverif_common.H> // DeviceFW::OperationType
#include <targeting/common/target.H>  // TARGETING::Target
#include <errl/errlentry.H>           // errlHndl_t

namespace MDS_ACCESS
{

/**
 * @file mdsI2cScomdd.H
 *
 * @brief Performs validation of params passed to i2cScomPerformOp.
 *
 * @details This function checks the inputs parameters - operation type, target
 *          type, the buffer length and the SCOM address format are all valid -
 *          for the method call mdsI2cScomPerformOp.
 *
 * @param[in] i_opType    Operation type, see DeviceFW::OperationType in driverif_common.H.
 * @param[in] i_target    TARGETING::Target passed to i2cScomPerformOp.
 * @param[in] i_buffer    The data buffer passed to i2cScomPerformOp.
 * @param[in] i_buflen    Size of the buffer passed to i2cScomPerformOp.
 * @param[in] i_scomAddr  The SCOM address to write to/read from
 *
 * @return  errlHndl_t    nullptr on success, non-null ptr on an invalid input
 */
errlHndl_t validateMdsI2cScomInputs(DeviceFW::OperationType  i_opType,
                                    const TARGETING::Target* i_target,
                                    const void* const        i_buffer,
                                    size_t                   i_buflen,
                                    uint64_t                 i_scomAddr);

}

#endif  // #ifndef MDS_ACCESS_UTILS_H
