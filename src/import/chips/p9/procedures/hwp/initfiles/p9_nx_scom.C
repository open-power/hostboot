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

constexpr auto literal_0b0 = 0b0;
constexpr auto literal_0b1 = 0b1;
constexpr auto literal_0b11 = 0b11;
constexpr auto literal_0b00 = 0b00;
constexpr auto literal_1 = 1;
constexpr auto literal_0xFC = 0xFC;
constexpr auto literal_8 = 8;
constexpr auto literal_2 = 2;
constexpr auto literal_0b111111 = 0b111111;
constexpr auto literal_0b11111111 = 0b11111111;
constexpr auto literal_0b000000 = 0b000000;
constexpr auto literal_0b00000000 = 0b00000000;

fapi2::ReturnCode p9_nx_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                             const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id);

        if (l_rc)
        {
            FAPI_ERR("ERROR getting ATTR_NAME");
            break;
        }

        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec);

        if (l_rc)
        {
            FAPI_ERR("ERROR getting ATTR_EC");
            break;
        }

        fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_ADDR_BAR_MODE)");
            break;
        }

        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_rc = fapi2::getScom( TGT0, 0x2011041ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011041ull)");
                break;
            }

            constexpr auto l_NX_DMA_CH0_EFT_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH0_EFT_ENABLE_ON, 63, 1, 63 );
            constexpr auto l_NX_DMA_CH1_EFT_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH1_EFT_ENABLE_ON, 62, 1, 63 );
            constexpr auto l_NX_DMA_CH2_SYM_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH2_SYM_ENABLE_ON, 58, 1, 63 );
            constexpr auto l_NX_DMA_CH3_SYM_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH3_SYM_ENABLE_ON, 57, 1, 63 );
            constexpr auto l_NX_DMA_CH4_GZIP_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH4_GZIP_ENABLE_ON, 61, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011041ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011041ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011042ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011042ull)");
                break;
            }

            constexpr auto l_NX_DMA_EFTCOMP_MAX_INRD_MAX_13_INRD = 0xd;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_EFTCOMP_MAX_INRD_MAX_13_INRD, 33, 4, 60 );
            constexpr auto l_NX_DMA_EFTDECOMP_MAX_INRD_MAX_7_INRD = 0x7;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_EFTDECOMP_MAX_INRD_MAX_7_INRD, 37, 4, 60 );
            constexpr auto l_NX_DMA_GZIPCOMP_MAX_INRD_MAX_13_INRD = 0xd;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_GZIPCOMP_MAX_INRD_MAX_13_INRD, 8, 4, 60 );
            constexpr auto l_NX_DMA_GZIPDECOMP_MAX_INRD_MAX_7_INRD = 0x7;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_GZIPDECOMP_MAX_INRD_MAX_7_INRD, 12, 4, 60 );
            constexpr auto l_NX_DMA_SYM_MAX_INRD_MAX_3_INRD = 0x3;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_SYM_MAX_INRD_MAX_3_INRD, 25, 4, 60 );
            constexpr auto l_NX_DMA_SYM_CPB_CHECK_DISABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_SYM_CPB_CHECK_DISABLE_ON, 48, 1, 63 );
            constexpr auto l_NX_DMA_EFT_COMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_EFT_COMP_PREFETCH_ENABLE_ON, 23, 1, 63 );
            constexpr auto l_NX_DMA_EFT_DECOMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_EFT_DECOMP_PREFETCH_ENABLE_ON, 24, 1, 63 );
            constexpr auto l_NX_DMA_GZIP_COMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_GZIP_COMP_PREFETCH_ENABLE_ON, 16, 1, 63 );
            constexpr auto l_NX_DMA_GZIP_DECOMP_PREFETCH_ENABLE_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_GZIP_DECOMP_PREFETCH_ENABLE_ON, 17, 1, 63 );
            constexpr auto l_NX_DMA_EFT_SPBC_WRITE_ENABLE_OFF = 0x0;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_EFT_SPBC_WRITE_ENABLE_OFF, 56, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011042ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011042ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x201105cull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x201105cull)");
                break;
            }

            constexpr auto l_NX_DMA_CH0_WATCHDOG_REF_DIV_DIVIDE_BY_4 = 0x2;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH0_WATCHDOG_REF_DIV_DIVIDE_BY_4, 1, 4, 60 );
            constexpr auto l_NX_DMA_CH0_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH0_WATCHDOG_TIMER_ENBL_ON, 0, 1, 63 );
            constexpr auto l_NX_DMA_CH1_WATCHDOG_REF_DIV_DIVIDE_BY_4 = 0x2;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH1_WATCHDOG_REF_DIV_DIVIDE_BY_4, 6, 4, 60 );
            constexpr auto l_NX_DMA_CH1_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH1_WATCHDOG_TIMER_ENBL_ON, 5, 1, 63 );
            constexpr auto l_NX_DMA_CH2_WATCHDOG_REF_DIV_DIVIDE_BY_4 = 0x2;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH2_WATCHDOG_REF_DIV_DIVIDE_BY_4, 11, 4, 60 );
            constexpr auto l_NX_DMA_CH2_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH2_WATCHDOG_TIMER_ENBL_ON, 10, 1, 63 );
            constexpr auto l_NX_DMA_CH3_WATCHDOG_REF_DIV_DIVIDE_BY_4 = 0x2;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH3_WATCHDOG_REF_DIV_DIVIDE_BY_4, 16, 4, 60 );
            constexpr auto l_NX_DMA_CH3_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH3_WATCHDOG_TIMER_ENBL_ON, 15, 1, 63 );
            constexpr auto l_NX_DMA_CH4_WATCHDOG_REF_DIV_DIVIDE_BY_4 = 0x2;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH4_WATCHDOG_REF_DIV_DIVIDE_BY_4, 21, 4, 60 );
            constexpr auto l_NX_DMA_CH4_WATCHDOG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_CH4_WATCHDOG_TIMER_ENBL_ON, 20, 1, 63 );
            constexpr auto l_NX_DMA_DMA_HANG_TIMER_ENBL_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_DMA_HANG_TIMER_ENBL_ON, 25, 1, 63 );
            constexpr auto l_NX_DMA_DMA_HANG_TIMER_REF_DIV_DIVIDE_BY_32 = 0x3;
            l_scom_buffer.insert<uint64_t> (l_NX_DMA_DMA_HANG_TIMER_REF_DIV_DIVIDE_BY_32, 26, 4, 60 );
            l_rc = fapi2::putScom(TGT0, 0x201105cull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x201105cull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011083ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011083ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 10, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 11, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 12, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 13, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 14, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 15, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 16, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 17, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 18, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 19, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 1, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 20, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 21, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 22, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 24, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 25, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 26, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 27, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 28, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 29, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 2, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 30, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 31, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 32, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 33, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 34, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 35, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 36, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 37, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 38, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 39, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 3, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b11, 40, 2, 62 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 42, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 43, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 4, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 5, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 6, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 7, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 8, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 9, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011083ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011083ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011086ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011086ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 10, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 11, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 12, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 13, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 14, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 15, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 16, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 17, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 18, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 19, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 1, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 20, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 21, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 22, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 24, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 25, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 26, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 27, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 28, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 29, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 2, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 30, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 31, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 32, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 33, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 34, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 35, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 36, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 37, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 38, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 39, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 3, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b00, 40, 2, 62 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 42, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 43, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 4, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 5, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 6, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 7, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 8, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 9, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011086ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011086ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011087ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011087ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 10, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 11, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 12, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 13, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 14, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 15, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 16, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 17, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 18, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 19, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 1, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 20, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 21, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 22, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 24, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 25, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 26, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 27, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 28, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 29, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 2, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 30, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 31, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 32, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 33, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 34, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 35, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 36, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 37, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 38, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 39, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 3, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b00, 40, 2, 62 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 42, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 43, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 4, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 5, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 6, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 7, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 8, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 9, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011087ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011087ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011095ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011095ull)");
                break;
            }

            constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_RD_GO_M_QOS_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_PBI_CQ_WRAP_NXCQ_SCOM_RD_GO_M_QOS_ON, 22, 1, 63 );

            if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_SMALL_SYSTEM))
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_NX_PBI_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_ON, 23, 1, 63 );
            }
            else if ((l_TGT1_ATTR_PROC_FABRIC_ADDR_BAR_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM))
            {
                constexpr auto l_NX_PBI_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_NX_PBI_CQ_WRAP_NXCQ_SCOM_ADDR_BAR_MODE_OFF, 23, 1, 63 );
            }

            l_scom_buffer.insert<uint64_t> (literal_1, 25, 2, 62 );
            l_scom_buffer.insert<uint64_t> (literal_0xFC, 40, 8, 56 );
            l_scom_buffer.insert<uint64_t> (literal_0xFC, 48, 8, 56 );
            l_rc = fapi2::putScom(TGT0, 0x2011095ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011095ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x20110a8ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x20110a8ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_8, 8, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_8, 4, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_8, 12, 4, 60 );
            l_scom_buffer.insert<uint64_t> (literal_8, 16, 4, 60 );
            l_rc = fapi2::putScom(TGT0, 0x20110a8ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x20110a8ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x20110c3ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x20110c3ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_8, 27, 9, 55 );
            l_rc = fapi2::putScom(TGT0, 0x20110c3ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x20110c3ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x20110c4ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x20110c4ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_8, 27, 9, 55 );
            l_rc = fapi2::putScom(TGT0, 0x20110c4ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x20110c4ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x20110c5ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x20110c5ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_8, 27, 9, 55 );
            l_rc = fapi2::putScom(TGT0, 0x20110c5ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x20110c5ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x20110d5ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x20110d5ull)");
                break;
            }

            constexpr auto l_NX_PBI_PBI_UMAC_CRB_READS_ENBL_ON = 0x1;
            l_scom_buffer.insert<uint64_t> (l_NX_PBI_PBI_UMAC_CRB_READS_ENBL_ON, 1, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x20110d5ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x20110d5ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x20110d6ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x20110d6ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_2, 9, 3, 61 );
            l_rc = fapi2::putScom(TGT0, 0x20110d6ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x20110d6ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011103ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011103ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 10, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 11, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 12, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 13, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 14, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 15, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 16, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 17, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 18, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 19, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 1, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 20, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 21, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 22, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 24, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b111111, 25, 6, 58 );
            l_scom_buffer.insert<uint64_t> (literal_0b11, 2, 2, 62 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 31, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 32, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 33, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 34, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 35, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 36, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 37, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 38, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 39, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b11111111, 40, 8, 56 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 48, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 49, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 4, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 5, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 6, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 7, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 8, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 9, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011103ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011103ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011106ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011106ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 10, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 11, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 12, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 13, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 14, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 15, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 16, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 17, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 18, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 19, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 1, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 20, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 21, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 22, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 24, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b000000, 25, 6, 58 );
            l_scom_buffer.insert<uint64_t> (literal_0b00, 2, 2, 62 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 31, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 32, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 33, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 34, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 35, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 36, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 37, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 38, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 39, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b00000000, 40, 8, 56 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 48, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 49, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 4, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 5, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 6, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 7, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 8, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 9, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011106ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011106ull)");
                break;
            }
        }
        {
            l_rc = fapi2::getScom( TGT0, 0x2011107ull, l_scom_buffer );

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: getScom (0x2011107ull)");
                break;
            }

            l_scom_buffer.insert<uint64_t> (literal_0b0, 0, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 10, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 11, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 12, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 13, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 14, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 15, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 16, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 17, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 18, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 19, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 1, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 20, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 21, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 22, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 24, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b000000, 25, 6, 58 );
            l_scom_buffer.insert<uint64_t> (literal_0b00, 2, 2, 62 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 31, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 32, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 33, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 34, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 35, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 36, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 37, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 38, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 39, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b00000000, 40, 8, 56 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 48, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 49, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 4, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 5, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 6, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 7, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b0, 8, 1, 63 );
            l_scom_buffer.insert<uint64_t> (literal_0b1, 9, 1, 63 );
            l_rc = fapi2::putScom(TGT0, 0x2011107ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x2011107ull)");
                break;
            }
        }

    }
    while(0);

    return l_rc;
}
