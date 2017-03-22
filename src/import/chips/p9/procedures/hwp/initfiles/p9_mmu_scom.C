/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mmu_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "p9_mmu_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x04047C0000000000 = 0x04047C0000000000;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0x409B000000000000 = 0x409B000000000000;
constexpr uint64_t literal_0x0000FAF800FF = 0x0000FAF800FF;
constexpr uint64_t literal_0x000000000000 = 0x000000000000;
constexpr uint64_t literal_0x910000040B00 = 0x910000040B00;
constexpr uint64_t literal_0b11111 = 0b11111;
constexpr uint64_t literal_0x00E = 0x00E;
constexpr uint64_t literal_0x0258 = 0x0258;

fapi2::ReturnCode p9_mmu_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c03ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x04047C0000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c03ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c06ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c06ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c07ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x409B000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c07ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c15ull, l_scom_buffer ));

            constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF = 0x0;
            l_scom_buffer.insert<33, 1, 63, uint64_t>(l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF );

            if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
            {
                constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_ON = 0x1;
                l_scom_buffer.insert<39, 1, 63, uint64_t>(l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_ON );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
            {
                constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_OFF = 0x0;
                l_scom_buffer.insert<39, 1, 63, uint64_t>(l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_OFF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c15ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c43ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x0000FAF800FF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c43ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c46ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c46ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c47ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x910000040B00 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c47ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c52ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<20, 1, 57, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
                l_scom_buffer.insert<24, 1, 62, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
                l_scom_buffer.insert<26, 1, 63, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0xe00;
                l_scom_buffer.insert<20, 1, 52, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
                l_scom_buffer.insert<24, 1, 57, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
                l_scom_buffer.insert<26, 1, 58, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }

            l_scom_buffer.insert<30, 1, 59, uint64_t>(literal_0b11111 );
            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b11111 );
            l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0x00E );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c52ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c53ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<2, 2, 60, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0xe00;
                l_scom_buffer.insert<2, 2, 55, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }

            l_scom_buffer.insert<32, 16, 48, uint64_t>(literal_0x0258 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c53ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c54ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<16, 1, 58, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0xe00;
                l_scom_buffer.insert<16, 1, 53, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
                l_scom_buffer.insert<58, 2, 59, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c54ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c55ull, l_scom_buffer ));

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<16, 1, 59, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }
            else if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0xe00;
                l_scom_buffer.insert<16, 1, 54, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
                l_scom_buffer.insert<58, 2, 61, uint64_t>(l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV );
            }

            constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_ON = 0x1;
            l_scom_buffer.insert<21, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_ON );
            constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN_ON = 0x1;
            l_scom_buffer.insert<53, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c55ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
