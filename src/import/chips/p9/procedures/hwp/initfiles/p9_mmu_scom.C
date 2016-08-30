/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mmu_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

constexpr auto literal_0x04047C0000000000 = 0x04047C0000000000;
constexpr auto literal_0x0000000000000000 = 0x0000000000000000;
constexpr auto literal_0x409B000000000000 = 0x409B000000000000;
constexpr auto literal_0x0000FAF800FF = 0x0000FAF800FF;
constexpr auto literal_0x000000000000 = 0x000000000000;
constexpr auto literal_0x910000040B00 = 0x910000040B00;
constexpr auto literal_0b11111 = 0b11111;
constexpr auto literal_0x0258 = 0x0258;

fapi2::ReturnCode p9_mmu_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x5012c03ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c03ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x04047C0000000000, 0, 22, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c03ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c03ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5012c06ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c06ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0000000000000000, 0, 22, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c06ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c06ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x5012c07ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c07ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x409B000000000000, 0, 22, 0 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c07ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c07ull)");
                break;
            }
        }
        fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_ADDR_BAR_MODE)");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_PUMP_MODE)");
            break;
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c15ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c15ull)");
                break;
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
                {
                    constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_ON, 33, 1, 63 );
                }
                else if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM))
                {
                    constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF, 33, 1, 63 );
                }
            }

            {
                if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
                {
                    constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_ON = 0x1;
                    l_scom_buffer.insert<uint64_t> (l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_ON, 39, 1, 63 );
                }
                else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
                {
                    constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_OFF = 0x0;
                    l_scom_buffer.insert<uint64_t> (l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_CFG_PUMP_MODE_OFF, 39, 1, 63 );
                }
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c15ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c15ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c43ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c43ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0000FAF800FF, 0, 48, 16 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c43ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c43ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c46ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c46ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x000000000000, 0, 48, 16 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c46ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c46ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c47ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c47ull)");
                break;
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x910000040B00, 0, 48, 16 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c47ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c47ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c52ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c52ull)");
                break;
            }

            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV, 20, 1, 57 );
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV, 24, 1, 62 );
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV, 26, 1, 63 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0b11111, 30, 1, 59 );
                l_scom_buffer.insert<uint64_t> (literal_0b11111, 60, 4, 60 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c52ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c52ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c53ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c53ull)");
                break;
            }

            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV, 2, 2, 60 );
            }

            {
                l_scom_buffer.insert<uint64_t> (literal_0x0258, 32, 16, 48 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c53ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c53ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c54ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c54ull)");
                break;
            }

            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV, 16, 1, 58 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c54ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c54ull)");
                break;
            }
        }

        {
            l_rc = fapi2::getScom( TGT0, 0x5012c55ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x5012c55ull)");
                break;
            }

            {
                constexpr auto l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV = 0x70;
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_PIPE_THREAD_MODE_SINGLE_THREAD_MODE_ST_INV, 16, 1, 59 );
            }

            {
                constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_ON, 21, 1, 63 );
            }

            {
                constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_NMMU_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN_ON, 53, 1, 63 );
            }

            l_rc = fapi2::putScom(TGT0, 0x5012c55ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x5012c55ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
