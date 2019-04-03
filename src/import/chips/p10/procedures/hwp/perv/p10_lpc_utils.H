/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_lpc_utils.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file  p10_lpc_utils.H
///
/// @brief Helper functions for indirect reads/writes to the LPC register space
/// @author Joachim Fenkes <fenkes@de.ibm.com>
#ifndef P10_LPC_UTILS_H_
#define P10_LPC_UTILS_H_

#include "fapi2.H"

const uint32_t LPC_CMD_TIMEOUT_DELAY_NS = 1000000;
const uint32_t LPC_CMD_TIMEOUT_DELAY_CYCLE = 1000000;
const uint32_t LPC_CMD_TIMEOUT_COUNT = 20;

/*
 * lpc_rw   read or write on a LPC bus address
 *
 * i_target_chip    reference to PROC target
 * i_addr           address on LPC bus to read or write to
 * i_size           size in bytes, currently supported 1 or 4 bytes
 * i_read_notwrite  is read and not write, default to true
 * i_generate_ffdc  if ffdc to be generated, default to true
 * io_data          reference to a buffer to hold requested data, upto 4bytes
 *
 * FAPI2_RC_SUCCESS if success, else error code
 */
fapi2::ReturnCode lpc_rw(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const uint32_t i_addr,
    const size_t i_size,
    const bool i_read_notwrite,
    const bool i_generate_ffdc,
    fapi2::buffer<uint32_t>& io_data);

/*
 * lpc_read     Read uint32_t register on LPC bus
 *
 * i_target_chip    reference to PROC target
 * i_addr           address of the register
 * o_data           reference to output buffer
 * i_generate_ffdc  generate ffdc, default to true
 *
 * FAPI2_RC_SUCCESS if success, else error code
 */
static inline fapi2::ReturnCode lpc_read(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t i_addr, fapi2::buffer<uint32_t>& o_data, bool i_generate_ffdc = true)
{
    return lpc_rw(i_target_chip, i_addr, sizeof(uint32_t), true, i_generate_ffdc, o_data);
}

/*
 * lpc_write    Write to uint32_t register on LPC bus
 *
 * i_target_chip    reference to PROC target
 * i_addr           address of the register
 * i_data           data to be written
 * i_generate_ffdc  generate ffdc, default to true
 *
 * FAPI2_RC_SUCCESS if success, else error code
 */
static inline fapi2::ReturnCode lpc_write(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t i_addr, fapi2::buffer<uint32_t> i_data, bool i_generate_ffdc = true)
{
    return lpc_rw(i_target_chip, i_addr, sizeof(uint32_t), false, i_generate_ffdc, i_data);
}

#endif /* P10_LPC_UTILS_H_ */
