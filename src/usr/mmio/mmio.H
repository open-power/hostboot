/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
#ifndef __MMIO_H
#define __MMIO_H

#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <targeting/common/target.H>

/** @file  mmio.H
 *  @brief Provides interface to perform MMIO operations to OCMB chips
 *  */

#define IGNORE_HRMOR 0x8000000000000000

namespace MMIO
{
/**
 * @brief Complete the MMIO operation.
 * This function performs read or write operations on OCMBs by accessing
 * virtual memory that was previously memory mapped to the OCMBs.
 * It follows a pre-defined function prototype in order to be registered
 * with the device driver framework.
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_target    MMIO target
 * @param[in/out] io_buffer   Read:   Pointer to output data storage
 *                            Write:  Pointer to input data storage
 * @param[in/out] io_buflen   Input:  Read:  size of data to read (in bytes)
 *                                    Write: Size of data to write
 *                            Output: Read:  Size of output data
 *                                    Write: Size of data written
 * @param[in]   i_accessType  Access type
 * @param[in]   i_args        This is an argument list for DD framework.
 *                            In this function, there are two arguments,
 *                            the offset (bytes) into the device, and the number
 *                            of bytes to read at a time (device limitation).
 * @return  errlHndl_t
 */
errlHndl_t ocmbMmioPerformOp(DeviceFW::OperationType i_opType,
                             TARGETING::TargetHandle_t i_target,
                             void* io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args);
}; // End namespace

#endif
