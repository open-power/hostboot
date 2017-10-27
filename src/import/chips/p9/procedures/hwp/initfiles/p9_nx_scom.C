/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_nx_scom.C $   */
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
#include "p9_nx_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0xFC = 0xFC;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0b111111 = 0b111111;
constexpr uint64_t literal_0b11111111 = 0b11111111;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_0b00000000 = 0b00000000;

fapi2::ReturnCode p9_nx_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                             const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_CHIP_EC_FEATURE_HW403701_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW403701;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW403701, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW403701));
        fapi2::ATTR_CHIP_EC_FEATURE_HW414700_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700));
        fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE));
        fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID_Type l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID, TGT1, l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID));
        fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID_Type l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID, TGT1, l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID));
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

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                constexpr auto l_NX_DMA_SYM_CPB_CHECK_DISABLE_ON = 0x1;
                l_scom_buffer.insert<48, 1, 63, uint64_t>(l_NX_DMA_SYM_CPB_CHECK_DISABLE_ON );
            }

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

            constexpr auto l_NX_DMA_CH0_WATCHDOG_REF_DIV_DIVIDE_BY_512 = 0x9;
            l_scom_buffer.insert<1, 4, 60, uint64_t>(l_NX_DMA_CH0_WATCHDOG_REF_DIV_DIVIDE_BY_512 );
            constexpr auto l_NX_DMA_CH0_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<0, 1, 63, uint64_t>(l_NX_DMA_CH0_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH1_WATCHDOG_REF_DIV_DIVIDE_BY_512 = 0x9;
            l_scom_buffer.insert<6, 4, 60, uint64_t>(l_NX_DMA_CH1_WATCHDOG_REF_DIV_DIVIDE_BY_512 );
            constexpr auto l_NX_DMA_CH1_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<5, 1, 63, uint64_t>(l_NX_DMA_CH1_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH2_WATCHDOG_REF_DIV_DIVIDE_BY_512 = 0x9;
            l_scom_buffer.insert<11, 4, 60, uint64_t>(l_NX_DMA_CH2_WATCHDOG_REF_DIV_DIVIDE_BY_512 );
            constexpr auto l_NX_DMA_CH2_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_NX_DMA_CH2_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH3_WATCHDOG_REF_DIV_DIVIDE_BY_512 = 0x9;
            l_scom_buffer.insert<16, 4, 60, uint64_t>(l_NX_DMA_CH3_WATCHDOG_REF_DIV_DIVIDE_BY_512 );
            constexpr auto l_NX_DMA_CH3_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<15, 1, 63, uint64_t>(l_NX_DMA_CH3_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_CH4_WATCHDOG_REF_DIV_DIVIDE_BY_512 = 0x9;
            l_scom_buffer.insert<21, 4, 60, uint64_t>(l_NX_DMA_CH4_WATCHDOG_REF_DIV_DIVIDE_BY_512 );
            constexpr auto l_NX_DMA_CH4_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<20, 1, 63, uint64_t>(l_NX_DMA_CH4_WATCHDOG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_DMA_HANG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<25, 1, 63, uint64_t>(l_NX_DMA_DMA_HANG_TIMER_ENBL_ON );
            constexpr auto l_NX_DMA_DMA_HANG_TIMER_REF_DIV_DIVIDE_BY_1024 = 0x8;
            l_scom_buffer.insert<26, 4, 60, uint64_t>(l_NX_DMA_DMA_HANG_TIMER_REF_DIV_DIVIDE_BY_1024 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x201105cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011083ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW403701 == literal_1))
            {
                l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW403701 != literal_1))
            {
                l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW403701 == literal_1))
            {
                l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW403701 != literal_1))
            {
                l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011083ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011086ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<40, 2, 62, uint64_t>(literal_0b00 );
            l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011086ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011087ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<25, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011087ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011095ull, l_scom_buffer ));

            if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_GROUP))
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_ON = 0x1;
                l_scom_buffer.insert<24, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_ON );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_PUMP_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE))
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_OFF = 0x0;
                l_scom_buffer.insert<24, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_SKIP_G_OFF );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x11)) )
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID );
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT1_ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_GROUP_ON = 0x1;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_GROUP_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_GROUP_ON = 0x1;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_GROUP_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_WR_DISABLE_GROUP_ON = 0x1;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_WR_DISABLE_GROUP_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_RD_DISABLE_GROUP_ON = 0x1;
                l_scom_buffer.insert<13, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_RD_DISABLE_GROUP_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_VG_NOT_SYS_ON = 0x1;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_WR_DISABLE_VG_NOT_SYS_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_VG_NOT_SYS_ON = 0x1;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_DMA_RD_DISABLE_VG_NOT_SYS_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_WR_DISABLE_VG_NOT_SYS_ON = 0x1;
                l_scom_buffer.insert<10, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_WR_DISABLE_VG_NOT_SYS_ON );
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x22)) )
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_RD_DISABLE_VG_NOT_SYS_ON = 0x1;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_UMAC_RD_DISABLE_VG_NOT_SYS_ON );
            }

            constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_RD_GO_M_QOS_ON = 0x1;
            l_scom_buffer.insert<22, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_RD_GO_M_QOS_ON );
            constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF = 0x0;
            l_scom_buffer.insert<23, 1, 63, uint64_t>(l_NX_PBI_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF );
            l_scom_buffer.insert<25, 2, 62, uint64_t>(literal_1 );
            l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xFC );
            l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0xFC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011095ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20110a8ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<16, 4, 60, uint64_t>(literal_8 );
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

            l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_2 );
            constexpr auto l_NX_PBI_DISABLE_PROMOTE_ON = 0x1;
            l_scom_buffer.insert<6, 1, 63, uint64_t>(l_NX_PBI_DISABLE_PROMOTE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x20110d6ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011103ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<25, 6, 58, uint64_t>(literal_0b111111 );
            l_scom_buffer.insert<2, 2, 62, uint64_t>(literal_0b11 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0b11111111 );
            l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b1 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011103ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011106ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<25, 6, 58, uint64_t>(literal_0b000000 );
            l_scom_buffer.insert<2, 2, 62, uint64_t>(literal_0b00 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0b00000000 );
            l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x2011106ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011107ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<13, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<14, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0))
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<25, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<32, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0b00000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0))
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 != literal_0))
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW414700 == literal_0))
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011107ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
