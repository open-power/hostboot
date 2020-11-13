/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bl_xscom.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef __BL_XSCOM_H
#define __BL_XSCOM_H

/** @file bl_xscom.H
 *  @brief Provides the interfaces to perform XSCOM ops in HBBL
 */

#include <devicefw/driverif_common.H>
#include <xscom/xscom_common.H>
#include <hbblreasoncodes.H>
#include <stdint.h>

namespace XSCOM
{

/**
 * @brief Performs an XSCOM operation
 *
 * @param[in] i_opType the type of operation to perform (read/write)
 * @param[in/out] io_buffer Read: pointer to location where output data is to be stored
 *                          Write: pointer to input data to be written
 * @param[in/out] io_buflen Input: size of the io_buffer in bytes
 *                          Output: size of read or written data
 * @param[in] i_addr the XSCOM address to read to or to write from
 */
Bootloader::hbblReasonCode xscomPerformOp(DeviceFW::OperationType i_opType,
                                          void* io_buffer,
                                          size_t& io_buflen,
                                          uint64_t i_addr);

} // namespace XSCOM
#endif
