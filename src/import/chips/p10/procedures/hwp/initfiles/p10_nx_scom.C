/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_nx_scom.C $ */
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
#include "p10_nx_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0xFC = 0xFC;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_2 = 2;

fapi2::ReturnCode p10_nx_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                              const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE));
        fapi2::ATTR_SMF_CONFIG_Type l_TGT1_ATTR_SMF_CONFIG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SMF_CONFIG, TGT1, l_TGT1_ATTR_SMF_CONFIG));
        fapi2::ATTR_CHIP_EC_FEATURE_HW544290_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW544290;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW544290, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW544290));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011041ull, l_scom_buffer ));

            constexpr auto l_NX_DMA_CH0_EFT_ENABLE_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>(l_NX_DMA_CH0_EFT_ENABLE_ON );
            constexpr auto l_NX_DMA_CH1_EFT_ENABLE_ON = 0x1;
            l_scom_buffer.insert<62, 1, 63, uint64_t>(l_NX_DMA_CH1_EFT_ENABLE_ON );
            constexpr auto l_NX_DMA_CH2_SYM_ENABLE_ON = 0x1;
            l_scom_buffer.insert<58, 1, 63, uint64_t>(l_NX_DMA_CH2_SYM_ENABLE_ON );
            constexpr auto l_NX_DMA_CH3_SYM_ENABLE_ON = 0x1;
            l_scom_buffer.insert<57, 1, 63, uint64_t>(l_NX_DMA_CH3_SYM_ENABLE_ON );
            constexpr auto l_NX_DMA_CH4_GZIP_ENABLE_ON = 0x1;
            l_scom_buffer.insert<61, 1, 63, uint64_t>(l_NX_DMA_CH4_GZIP_ENABLE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011041ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011042ull, l_scom_buffer ));

            constexpr auto l_NX_DMA_EFTCOMP_MAX_INRD_MAX_15_INRD = 0xf;
            l_scom_buffer.insert<33, 4, 60, uint64_t>(l_NX_DMA_EFTCOMP_MAX_INRD_MAX_15_INRD );
            constexpr auto l_NX_DMA_EFTDECOMP_MAX_INRD_MAX_15_INRD = 0xf;
            l_scom_buffer.insert<37, 4, 60, uint64_t>(l_NX_DMA_EFTDECOMP_MAX_INRD_MAX_15_INRD );
            constexpr auto l_NX_DMA_GZIPCOMP_MAX_INRD_MAX_15_INRD = 0xf;
            l_scom_buffer.insert<8, 4, 60, uint64_t>(l_NX_DMA_GZIPCOMP_MAX_INRD_MAX_15_INRD );
            constexpr auto l_NX_DMA_GZIPDECOMP_MAX_INRD_MAX_15_INRD = 0xf;
            l_scom_buffer.insert<12, 4, 60, uint64_t>(l_NX_DMA_GZIPDECOMP_MAX_INRD_MAX_15_INRD );
            constexpr auto l_NX_DMA_SYM_MAX_INRD_MAX_3_INRD = 0x3;
            l_scom_buffer.insert<25, 4, 60, uint64_t>(l_NX_DMA_SYM_MAX_INRD_MAX_3_INRD );
            constexpr auto l_NX_DMA_EFT_COMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<23, 1, 63, uint64_t>(l_NX_DMA_EFT_COMP_PREFETCH_ENABLE_ON );
            constexpr auto l_NX_DMA_EFT_DECOMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<24, 1, 63, uint64_t>(l_NX_DMA_EFT_DECOMP_PREFETCH_ENABLE_ON );
            constexpr auto l_NX_DMA_GZIP_COMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<16, 1, 63, uint64_t>(l_NX_DMA_GZIP_COMP_PREFETCH_ENABLE_ON );
            constexpr auto l_NX_DMA_GZIP_DECOMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<17, 1, 63, uint64_t>(l_NX_DMA_GZIP_DECOMP_PREFETCH_ENABLE_ON );
            constexpr auto l_NX_DMA_EFT_SPBC_WRITE_ENABLE_OFF = 0x0;
            l_scom_buffer.insert<56, 1, 63, uint64_t>(l_NX_DMA_EFT_SPBC_WRITE_ENABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011042ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201105cull, l_scom_buffer ));

            constexpr auto l_NX_DMA_CH0_WATCHDOG_REF_DIV_DIVIDE_BY_8 = 0x3;
            l_scom_buffer.insert<1, 4, 60, uint64_t>(l_NX_DMA_CH0_WATCHDOG_REF_DIV_DIVIDE_BY_8 );
            constexpr auto l_NX_DMA_CH1_WATCHDOG_REF_DIV_DIVIDE_BY_8 = 0x3;
            l_scom_buffer.insert<6, 4, 60, uint64_t>(l_NX_DMA_CH1_WATCHDOG_REF_DIV_DIVIDE_BY_8 );
            constexpr auto l_NX_DMA_CH2_WATCHDOG_REF_DIV_DIVIDE_BY_8 = 0x3;
            l_scom_buffer.insert<11, 4, 60, uint64_t>(l_NX_DMA_CH2_WATCHDOG_REF_DIV_DIVIDE_BY_8 );
            constexpr auto l_NX_DMA_CH3_WATCHDOG_REF_DIV_DIVIDE_BY_8 = 0x3;
            l_scom_buffer.insert<16, 4, 60, uint64_t>(l_NX_DMA_CH3_WATCHDOG_REF_DIV_DIVIDE_BY_8 );
            constexpr auto l_NX_DMA_CH4_WATCHDOG_REF_DIV_DIVIDE_BY_8 = 0x3;
            l_scom_buffer.insert<21, 4, 60, uint64_t>(l_NX_DMA_CH4_WATCHDOG_REF_DIV_DIVIDE_BY_8 );
            constexpr auto l_NX_DMA_CH0_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<0, 1, 63, uint64_t>(l_NX_DMA_CH0_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH1_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<5, 1, 63, uint64_t>(l_NX_DMA_CH1_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH2_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_NX_DMA_CH2_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH3_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<15, 1, 63, uint64_t>(l_NX_DMA_CH3_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH4_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<20, 1, 63, uint64_t>(l_NX_DMA_CH4_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_DMA_HANG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<25, 1, 63, uint64_t>(l_NX_DMA_DMA_HANG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_DMA_HANG_TIMER_REF_DIV_DIVIDE_BY_8 = 0x1;
            l_scom_buffer.insert<26, 4, 60, uint64_t>(l_NX_DMA_DMA_HANG_TIMER_REF_DIV_DIVIDE_BY_8 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x201105cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011095ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_ON = 0x1;
                l_scom_buffer.insert<24, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_ON );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE != fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_OFF = 0x0;
                l_scom_buffer.insert<24, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_OFF );
            }

            if ((l_TGT1_ATTR_SMF_CONFIG != fapi2::ENUM_ATTR_SMF_CONFIG_ENABLED))
            {
                l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((l_TGT1_ATTR_SMF_CONFIG == fapi2::ENUM_ATTR_SMF_CONFIG_ENABLED))
            {
                l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            }

            constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_RD_GO_M_QOS_ON = 0x1;
            l_scom_buffer.insert<22, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_RD_GO_M_QOS_ON );
            l_scom_buffer.insert<25, 2, 62, uint64_t>(literal_1 );
            l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xFC );
            l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0xFC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011095ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20110a8ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_1 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_1 );
            l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_4 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x20110a8ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20110c3ull, l_scom_buffer ));

            l_scom_buffer.insert<27, 9, 55, uint64_t>(literal_8 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x20110c3ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20110c4ull, l_scom_buffer ));

            l_scom_buffer.insert<27, 9, 55, uint64_t>(literal_8 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x20110c4ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20110c5ull, l_scom_buffer ));

            l_scom_buffer.insert<27, 9, 55, uint64_t>(literal_8 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x20110c5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20110d5ull, l_scom_buffer ));

            constexpr auto l_NX_PBI_PBI_UMAC_CRB_READS_ENBL_ON = 0x1;
            l_scom_buffer.insert<1, 1, 63, uint64_t>(l_NX_PBI_PBI_UMAC_CRB_READS_ENBL_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x20110d5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20110d6ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW544290 == literal_1))
            {
                l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_2 );
            }

            constexpr auto l_NX_PBI_DISABLE_PROMOTE_ON = 0x1;
            l_scom_buffer.insert<6, 1, 63, uint64_t>(l_NX_PBI_DISABLE_PROMOTE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x20110d6ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
