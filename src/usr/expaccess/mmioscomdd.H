/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/mmioscomdd.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
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
#ifndef __MMIOSCOMDD_H
#define __MMIOSCOMDD_H

/** @file mmioscomdd.H
 *  @brief Provides the interfaces to perform mmioscom to OCMB chip
 */
#include <stdint.h>
#include <devicefw/driverif.H>
#include <targeting/common/target.H>
#include <errl/errlentry.H>


namespace MMIOSCOMDD
{

/**
 * @brief Performs an IBSCOM (MMIO) access operation
 * This function performs an MMIO-based SCOM access operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Explorer Chip target
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
 * @return  errlHndl_t
 */
errlHndl_t mmioScomPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::Target* i_target,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args);

}

#endif //  __MMIOSCOMDD_H
