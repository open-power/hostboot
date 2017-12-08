/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_mmu_scom.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x04047C0000000000 = 0x04047C0000000000;
constexpr uint64_t literal_0x04247C0000000000 = 0x04247C0000000000;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;
constexpr uint64_t literal_0x409B000000000000 = 0x409B000000000000;
constexpr uint64_t literal_0x4092000000000000 = 0x4092000000000000;
constexpr uint64_t literal_0x40DB000000000000 = 0x40DB000000000000;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0x0000FAF800FF = 0x0000FAF800FF;
constexpr uint64_t literal_0x0400FAFC00FF = 0x0400FAFC00FF;
constexpr uint64_t literal_0x000000000000 = 0x000000000000;
constexpr uint64_t literal_0x910000040F00 = 0x910000040F00;
constexpr uint64_t literal_0x911100000F00 = 0x911100000F00;
constexpr uint64_t literal_0x991100000F00 = 0x991100000F00;
constexpr uint64_t literal_0b11111 = 0b11111;
constexpr uint64_t literal_0x00E = 0x00E;
constexpr uint64_t literal_0x000 = 0x000;
constexpr uint64_t literal_0x0258 = 0x0258;

fapi2::ReturnCode p9_mmu_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_CHIP_EC_FEATURE_NMMU_NDD1_Type l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_NMMU_NDD1, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1));
        fapi2::ATTR_CHIP_EC_FEATURE_HW414700_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700));
        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c03ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 != literal_0))
            {
                l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x04047C0000000000 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0))
            {
                l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x04247C0000000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c03ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c06ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x0000000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c06ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c07ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 != literal_0))
            {
                l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x409B000000000000 );
            }
            else if (((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0) && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0)))
            {
                l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x4092000000000000 );
            }
            else if (((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0) && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0)))
            {
                l_scom_buffer.insert<0, 22, 0, uint64_t>(literal_0x40DB000000000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c07ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c15ull, l_scom_buffer ));

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

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<8, 3, 61, uint64_t>(literal_0x3 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_GROUP_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_GROUP_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_GROUP_ON = 0x1;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_GROUP_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_VG_NOT_SYS_ON = 0x1;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_VG_NOT_SYS_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_VG_NOT_SYS_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_NMMU_MM_FBC_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_VG_NOT_SYS_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c15ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5012c1dull, l_scom_buffer ));

                l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0x1 );
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x1 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x5012c1dull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c43ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 != literal_0))
            {
                l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x0000FAF800FF );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0))
            {
                l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x0400FAFC00FF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c43ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c46ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x000000000000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c46ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c47ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 != literal_0))
            {
                l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x910000040F00 );
            }
            else if (((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0) && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0)))
            {
                l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x911100000F00 );
            }
            else if (((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0) && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0)))
            {
                l_scom_buffer.insert<0, 48, 16, uint64_t>(literal_0x991100000F00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c47ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c52ull, l_scom_buffer ));

            l_scom_buffer.insert<30, 1, 59, uint64_t>(literal_0b11111 );
            l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b11111 );

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 != literal_0))
            {
                l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0x00E );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0))
            {
                l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0x000 );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS_ON = 0x1;
                l_scom_buffer.insert<52, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TW_RDX_PWC_DIS_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN_ON = 0x1;
                l_scom_buffer.insert<44, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TW_LCO_RDX_EN_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN_ON = 0x1;
                l_scom_buffer.insert<51, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TW_LCO_RDX_PDE_EN_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c52ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c53ull, l_scom_buffer ));

            l_scom_buffer.insert<32, 16, 48, uint64_t>(literal_0x0258 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c53ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                FAPI_TRY(fapi2::getScom( TGT0, 0x5012c54ull, l_scom_buffer ));

                constexpr auto l_NMMU_MM_CFG_TWSM_SPLIT_MODE_TWSM_SPLIT_08_TLB_04_SLB = 0x0;
                l_scom_buffer.insert<57, 1, 62, uint64_t>(l_NMMU_MM_CFG_TWSM_SPLIT_MODE_TWSM_SPLIT_08_TLB_04_SLB );
                FAPI_TRY(fapi2::putScom(TGT0, 0x5012c54ull, l_scom_buffer));
            }
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5012c55ull, l_scom_buffer ));

            constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN_ON = 0x1;
            l_scom_buffer.insert<53, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TLB_ISS543B_FIX_EN_ON );

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NMMU_MM_MPSS_MODE_MPSS_ENA_PREF_PGSZ_ENA_G_64KB_H_64KB = 0x155;
                l_scom_buffer.insert<19, 1, 54, uint64_t>(l_NMMU_MM_MPSS_MODE_MPSS_ENA_PREF_PGSZ_ENA_G_64KB_H_64KB );
                l_scom_buffer.insert<56, 1, 55, uint64_t>(l_NMMU_MM_MPSS_MODE_MPSS_ENA_PREF_PGSZ_ENA_G_64KB_H_64KB );
                l_scom_buffer.insert<44, 8, 56, uint64_t>(l_NMMU_MM_MPSS_MODE_MPSS_ENA_PREF_PGSZ_ENA_G_64KB_H_64KB );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 != literal_0))
            {
                constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_ON = 0x1;
                l_scom_buffer.insert<21, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_ON );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_NMMU_NDD1 == literal_0))
            {
                constexpr auto l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_OFF = 0x0;
                l_scom_buffer.insert<21, 1, 63, uint64_t>(l_NMMU_MM_CFG_NMMU_CTL_TLB_HASH_PID_DIS_OFF );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11))
                || ((l_chip_id == 0x7) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NMMU_MM_CFG_TWSM_SPLIT_MODE_TWSM_SPLIT_08_TLB_04_SLB = 0x0;
                l_scom_buffer.insert<57, 1, 63, uint64_t>(l_NMMU_MM_CFG_TWSM_SPLIT_MODE_TWSM_SPLIT_08_TLB_04_SLB );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5012c55ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
