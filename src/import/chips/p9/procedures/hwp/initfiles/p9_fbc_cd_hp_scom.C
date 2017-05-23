/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_cd_hp_scom.C $ */
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
#include "p9_fbc_cd_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0x2 = 0x2;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x00 = 0x00;
constexpr uint64_t literal_0x06 = 0x06;
constexpr uint64_t literal_0x0D = 0x0D;
constexpr uint64_t literal_0x1E = 0x1E;
constexpr uint64_t literal_0x19 = 0x19;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_0x400 = 0x400;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0x141 = 0x141;
constexpr uint64_t literal_0x21B = 0x21B;
constexpr uint64_t literal_0x30D = 0x30D;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_0x000 = 0x000;

fapi2::ReturnCode p9_fbc_cd_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ASYNC_SAFE_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE));
        uint64_t l_def_TRUE = ((l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE == ENUM_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_SAFE_MODE)
                               || (l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE == ENUM_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_PERFORMANCE_MODE));
        uint64_t l_def_SAFE_MODE = (l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE == ENUM_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_SAFE_MODE);
        fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_Type l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO, TGT1, l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO));
        uint64_t l_def_CORE_FLOOR_RATIO_2_8 = (l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO ==
                                               ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_2_8);
        uint64_t l_def_CORE_FLOOR_RATIO_4_8 = (l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO ==
                                               ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_4_8);
        fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO_Type l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO, TGT1, l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO));
        uint64_t l_def_CORE_CEILING_RATIO_8_8 = (l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO ==
                                                ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_8_8);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<52, 6, 58, uint64_t>(literal_0x4 );
            constexpr auto l_PB_CMD_PB_CFG_P7_SLEEP_BACKOFF_NEXT_DISABLED = 0x0;
            l_scom_buffer.insert<58, 2, 62, uint64_t>(l_PB_CMD_PB_CFG_P7_SLEEP_BACKOFF_NEXT_DISABLED );
            l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            constexpr auto l_PB_CMD_PB_CFG_INCLUDE_LPC_RTY_NEXT_OFF = 0x0;
            l_scom_buffer.insert<63, 1, 63, uint64_t>(l_PB_CMD_PB_CFG_INCLUDE_LPC_RTY_NEXT_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000cf405011c11ull, l_scom_buffer));
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<32, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<35, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<38, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<41, 3, 61, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<44, 3, 61, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<47, 3, 61, uint64_t>(literal_0x2 );
            l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0x3 );
            l_scom_buffer.insert<53, 3, 61, uint64_t>(literal_0x5 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000e0605011c11ull, l_scom_buffer));
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<28, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0x06 );
            l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0x0D );
            l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0x00 );
            l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0x1E );
            l_scom_buffer.insert<53, 5, 59, uint64_t>(literal_0x19 );
            l_scom_buffer.insert<58, 5, 59, uint64_t>(literal_0x00 );
            constexpr auto l_PB_CMD_PB_CFG_USE_SLOW_GO_RATE_NEXT_ON = 0x1;
            l_scom_buffer.insert<63, 1, 63, uint64_t>(l_PB_CMD_PB_CFG_USE_SLOW_GO_RATE_NEXT_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000e4305011c11ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<26, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<29, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<31, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<39, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<39, 2, 62, uint64_t>(literal_0b10 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_2_8 == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b11 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b10 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_FLOOR_RATIO_2_8 == literal_1)))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b11 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b10 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<46, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000e6105011811ull, l_scom_buffer));
                FAPI_TRY(fapi2::putScom(TGT0, 0x90000e6105012011ull, l_scom_buffer));
            }
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<22, 12, 52, uint64_t>(literal_0x400 );
            l_scom_buffer.insert<34, 12, 52, uint64_t>(literal_0x400 );
            l_scom_buffer.insert<46, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<61, 3, 61, uint64_t>(literal_0b010 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000ea205011c11ull, l_scom_buffer));
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<18, 10, 54, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<28, 12, 52, uint64_t>(literal_0x141 );
            l_scom_buffer.insert<40, 12, 52, uint64_t>(literal_0x21B );
            l_scom_buffer.insert<52, 12, 52, uint64_t>(literal_0x30D );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000ee105011c11ull, l_scom_buffer));
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<16, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<19, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<22, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<25, 3, 61, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<28, 3, 61, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<31, 3, 61, uint64_t>(literal_0x2 );
            l_scom_buffer.insert<34, 3, 61, uint64_t>(literal_0x3 );
            l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_0x5 );
            l_scom_buffer.insert<40, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<43, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<46, 3, 61, uint64_t>(literal_0x0 );
            l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0x2 );
            l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0x3 );
            l_scom_buffer.insert<61, 3, 61, uint64_t>(literal_0x5 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000f0505011c11ull, l_scom_buffer));
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<14, 10, 54, uint64_t>(literal_0x7 );
            l_scom_buffer.insert<24, 10, 54, uint64_t>(literal_0x5 );
            l_scom_buffer.insert<34, 10, 54, uint64_t>(literal_0x5 );
            l_scom_buffer.insert<44, 10, 54, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<54, 10, 54, uint64_t>(literal_0x5 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000f2005011c11ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                l_scom_buffer.flush<0> ();

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b000 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<15, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<16, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<21, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_CEILING_RATIO_8_8 == literal_1)))
                {
                    l_scom_buffer.insert<24, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<24, 2, 62, uint64_t>(literal_0b11 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<28, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_CORE_CEILING_RATIO_8_8 == literal_1))
                {
                    l_scom_buffer.insert<28, 2, 62, uint64_t>(literal_0b11 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<28, 2, 62, uint64_t>(literal_0b10 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<30, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<31, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<32, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<32, 2, 62, uint64_t>(literal_0b11 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<34, 3, 61, uint64_t>(literal_0b111 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<37, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<37, 2, 62, uint64_t>(literal_0b11 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<41, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_CEILING_RATIO_8_8 == literal_1)))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b11 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<46, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<54, 10, 54, uint64_t>(literal_0x000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000f4005011811ull, l_scom_buffer));
                FAPI_TRY(fapi2::putScom(TGT0, 0x90000f4005012011ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) )
            {
                l_scom_buffer.flush<0> ();

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<26, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<28, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<29, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<31, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<33, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<34, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<39, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<39, 2, 62, uint64_t>(literal_0b10 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_2_8 == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b11 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b10 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_FLOOR_RATIO_2_8 == literal_1)))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b11 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b10 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<46, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b01 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000e6105011811ull, l_scom_buffer));
                FAPI_TRY(fapi2::putScom(TGT0, 0x90000e6105012011ull, l_scom_buffer));
            }
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
