/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_lpc_utils.C $    */
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
#include "p10_lpc_utils.H"
#include "p10_scom_proc.H"

fapi2::ReturnCode lpc_rw(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const uint32_t i_addr,
    const size_t i_size,
    const bool i_read_notwrite,
    const bool i_generate_ffdc,
    fapi2::buffer<uint32_t>& io_data)
{
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_command;
    const int l_bit_offset = (i_addr & 7 & ~(i_size - 1)) << 3;
    l_command.writeBit<TP_TPBR_AD_LPC_CMD_REG_RNW>(i_read_notwrite)
    .insertFromRight<TP_TPBR_AD_LPC_CMD_REG_SIZE, TP_TPBR_AD_LPC_CMD_REG_SIZE_LEN>(i_size)
    .insertFromRight<TP_TPBR_AD_LPC_CMD_REG_ADR, TP_TPBR_AD_LPC_CMD_REG_ADR_LEN>(i_addr);
    FAPI_TRY(fapi2::putScom(i_target_chip, TP_TPBR_AD_LPC_CMD_REG, l_command), "Error writing LPC command register");

    if (!i_read_notwrite)
    {
        fapi2::buffer<uint64_t> l_data;
        l_data.insert(io_data, l_bit_offset, 8 * i_size);
        FAPI_TRY(fapi2::putScom(i_target_chip, TP_TPBR_AD_LPC_DATA_REG, l_data), "Error writing LPC data");
    }

    {
        fapi2::buffer<uint64_t> l_status;
        int timeout = LPC_CMD_TIMEOUT_COUNT;

        while (timeout--)
        {
            FAPI_TRY(GET_TP_TPBR_AD_LPC_STATUS_REG(i_target_chip, l_status));

            if (GET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(l_status))
            {
                break;
            }

            fapi2::delay(LPC_CMD_TIMEOUT_DELAY_NS, LPC_CMD_TIMEOUT_DELAY_CYCLE);
        }

        if (i_generate_ffdc)
        {
            FAPI_ASSERT(GET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(l_status), fapi2::LPC_ACCESS_TIMEOUT()
                        .set_TARGET_CHIP(i_target_chip)
                        .set_COUNT(LPC_CMD_TIMEOUT_COUNT)
                        .set_COMMAND(l_command)
                        .set_DATA(io_data)
                        .set_STATUS(l_status),
                        "LPC access timed out");
        }
        else if (!GET_TP_TPBR_AD_LPC_STATUS_REG_DONE_STATUS(l_status))
        {
            return fapi2::RC_LPC_ACCESS_TIMEOUT;
        }
    }

    if (i_read_notwrite)
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(i_target_chip, TP_TPBR_AD_LPC_DATA_REG, l_data), "Error reading LPC data");
        l_data.extract(io_data, l_bit_offset, 8 * i_size);
    }

fapi_try_exit:
    return fapi2::current_err;
}
