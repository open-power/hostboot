/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_lpc_utils.H $      */
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
/// @file  p9_lpc_utils.H
///
/// @brief Helper functions for indirect reads/writes to the LPC register space
/// @author Joachim Fenkes <fenkes@de.ibm.com>
#ifndef P9_LPC_UTILS_H_
#define P9_LPC_UTILS_H_

const uint32_t LPC_CMD_TIMEOUT_DELAY_NS = 1000000;
const uint32_t LPC_CMD_TIMEOUT_DELAY_CYCLE = 1000000;
const uint32_t LPC_CMD_TIMEOUT_COUNT = 20;

static fapi2::ReturnCode lpc_rw(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t i_addr, bool i_read_notwrite, fapi2::buffer<uint32_t>& io_data)
{
    const int l_bit_offset = (i_addr & 4) << 3;
    fapi2::buffer<uint64_t> l_command;
    l_command.writeBit<PU_LPC_CMD_REG_RNW>(i_read_notwrite)
    .insertFromRight<PU_LPC_CMD_REG_SIZE, PU_LPC_CMD_REG_SIZE_LEN>(0x4)
    .insertFromRight<PU_LPC_CMD_REG_ADR, PU_LPC_CMD_REG_ADR_LEN>(i_addr);
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, l_command), "Error writing LPC command register");

    if (!i_read_notwrite)
    {
        fapi2::buffer<uint64_t> l_data;
        l_data.insert(io_data, l_bit_offset, 32);
        FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, l_data), "Error writing LPC data");
    }

    {
        fapi2::buffer<uint64_t> l_status;
        int timeout = LPC_CMD_TIMEOUT_COUNT;

        while (timeout--)
        {
            FAPI_TRY(fapi2::getScom(i_target_chip, PU_LPC_STATUS_REG, l_status), "Error reading LPC status");

            if (l_status.getBit<PU_LPC_STATUS_REG_DONE>())
            {
                break;
            }

            fapi2::delay(LPC_CMD_TIMEOUT_DELAY_NS, LPC_CMD_TIMEOUT_DELAY_CYCLE);
        }

        if (LPC_UTILS_TIMEOUT_FFDC)
        {
            FAPI_ASSERT(l_status.getBit<PU_LPC_STATUS_REG_DONE>(), fapi2::LPC_ACCESS_TIMEOUT()
                        .set_TARGET_CHIP(i_target_chip)
                        .set_COUNT(LPC_CMD_TIMEOUT_COUNT)
                        .set_COMMAND(l_command)
                        .set_DATA(io_data)
                        .set_STATUS(l_status),
                        "LPC access timed out");
        }
        else if (!l_status.getBit<PU_LPC_STATUS_REG_DONE>())
        {
            return fapi2::RC_LPC_ACCESS_TIMEOUT;
        }
    }

    if (i_read_notwrite)
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(i_target_chip, PU_LPC_DATA_REG, l_data), "Error reading LPC data");
        l_data.extract(io_data, l_bit_offset, 32);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

static inline fapi2::ReturnCode lpc_read(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t i_addr, fapi2::buffer<uint32_t>& o_data)
{
    return lpc_rw(i_target_chip, i_addr, true, o_data);
}

static inline fapi2::ReturnCode lpc_write(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t i_addr, fapi2::buffer<uint32_t> i_data)
{
    return lpc_rw(i_target_chip, i_addr, false, i_data);
}

#endif /* P9_LPC_UTILS_H_ */
