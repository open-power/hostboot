/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/expscom_utils.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#ifndef __EXPSCOM_UTILS_H
#define __EXPSCOM_UTILS_H

/** @file expscom_utils.H
 *  @brief Provides the common utility functions for i2c and mmio
 *         Explorer OCMB scom drivers
 */
#include <stdint.h>


namespace EXPSCOM
{

/**
* @brief Performs validation of params passed to i2cScomPerformOp and
*  mmioScomPerformOp functions. This function checks that the target
* model, the buffer lengt, addr format, and the op type are all valid.
* A unique error will be created for each violation. If multiple error
* are found the last error will be returned and all previous errors found
* will be committed as new errors are found (see function).
*
* @param[in]   i_opType      Operation type, see DeviceFW::OperationType
*                            in driverif.H
* @param[in]   i_target      TARGETING::Target passed to mmioscomPerformOp
* @param[in]   i_buflen      size of buffer passed to mmioscomPerformOp
* @param[in]   i_scomAddr    Scom address operation will be performed on

* @return  errlHndl_t
*/
errlHndl_t validateInputs(DeviceFW::OperationType i_opType,
                          const TARGETING::Target* i_target,
                          size_t i_buflen,
                          uint64_t i_scomAddr);

}

#endif