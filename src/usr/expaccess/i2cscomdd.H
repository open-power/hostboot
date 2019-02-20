/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/i2cscomdd.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#ifndef __I2CSCOMDD_H
#define __I2CSCOMDD_H

/** @file i2cscomdd.H
 *  @brief Provides the interfaces to perform I2Cscom
 */
#include <stdint.h>


namespace I2CSCOMDD
{

/**
 * @brief Performs an I2CSCOM access operation
 * This function performs an I2CSCOM access operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        I2CSCOM Explorer Chip target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the IBM scom address
 * @return  errlHndl_t          nullptr on success, non-null ptr on error
 */
errlHndl_t i2cScomPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::Target* i_target,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args);

}

#endif //  __I2CSCOMDD_H