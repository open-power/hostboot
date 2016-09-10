/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_cd_hp_scom.C $ */
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
#include "p9_fbc_cd_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr auto literal_0b111 = 0b111;
constexpr auto literal_0x4 = 0x4;
constexpr auto literal_0b000 = 0b000;
constexpr auto literal_0x0 = 0x0;
constexpr auto literal_0x1 = 0x1;
constexpr auto literal_0x2 = 0x2;
constexpr auto literal_0x3 = 0x3;
constexpr auto literal_0x7 = 0x7;
constexpr auto literal_0x00 = 0x00;
constexpr auto literal_0x06 = 0x06;
constexpr auto literal_0x0D = 0x0D;
constexpr auto literal_0x1E = 0x1E;
constexpr auto literal_0x19 = 0x19;
constexpr auto literal_1 = 1;
constexpr auto literal_0b00 = 0b00;
constexpr auto literal_0b0 = 0b0;
constexpr auto literal_0b1 = 0b1;
constexpr auto literal_0b01 = 0b01;
constexpr auto literal_0b10 = 0b10;
constexpr auto literal_0b11 = 0b11;
constexpr auto literal_0x400 = 0x400;
constexpr auto literal_0b010 = 0b010;
constexpr auto literal_0x141 = 0x141;
constexpr auto literal_0x21B = 0x21B;
constexpr auto literal_0x30D = 0x30D;
constexpr auto literal_0x5 = 0x5;
constexpr auto literal_0x000 = 0x000;

fapi2::ReturnCode p9_fbc_cd_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    fapi2::ReturnCode l_rc = 0;

    do
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            {
                l_scom_buffer.insert<uint64_t> (literal_0b111, 49, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x4, 52, 6, 58 );
            }
            {
                constexpr auto l_PB_CMD_PB_CFG_P7_SLEEP_BACKOFF_NEXT_BACKOFF_1K = 0x2;
                l_scom_buffer.insert<uint64_t> (l_PB_CMD_PB_CFG_P7_SLEEP_BACKOFF_NEXT_BACKOFF_1K, 58, 2, 62 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0b000, 60, 3, 61 );
            }
            {
                constexpr auto l_PB_CMD_PB_CFG_INCLUDE_LPC_RTY_NEXT_OFF = 0x0;
                l_scom_buffer.insert<uint64_t> (l_PB_CMD_PB_CFG_INCLUDE_LPC_RTY_NEXT_OFF, 63, 1, 63 );
            }
            l_rc = fapi2::putScom(TGT0, 0x90000cf405011c11ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000cf405011c11ull)");
                break;
            }
        }
        {
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 32, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 35, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 38, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x1, 41, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x1, 44, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x2, 47, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x3, 50, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x7, 53, 3, 61 );
            }
            l_rc = fapi2::putScom(TGT0, 0x90000e0605011c11ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000e0605011c11ull)");
                break;
            }
        }
        {
            {
                l_scom_buffer.insert<uint64_t> (literal_0x00, 28, 5, 59 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x06, 33, 5, 59 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0D, 38, 5, 59 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x00, 43, 5, 59 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x1E, 48, 5, 59 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x19, 53, 5, 59 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x00, 58, 5, 59 );
            }
            {
                constexpr auto l_PB_CMD_PB_CFG_USE_SLOW_GO_RATE_NEXT_ON = 0x1;
                l_scom_buffer.insert<uint64_t> (l_PB_CMD_PB_CFG_USE_SLOW_GO_RATE_NEXT_ON, 63, 1, 63 );
            }
            l_rc = fapi2::putScom(TGT0, 0x90000e4305011c11ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000e4305011c11ull)");
                break;
            }
        }
        fapi2::ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_Type l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ASYNC_SAFE_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_ASYNC_SAFE_MODE)");
            break;
        }

        auto l_def_TRUE = ((l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE == ENUM_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_SAFE_MODE)
                           || (l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE == ENUM_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_PERFORMANCE_MODE));
        auto l_def_SAFE_MODE = (l_TGT1_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE == ENUM_ATTR_PROC_FABRIC_ASYNC_SAFE_MODE_SAFE_MODE);
        fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_Type l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO, TGT1, l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_CORE_FLOOR_RATIO)");
            break;
        }

        auto l_def_CORE_FLOOR_RATIO_2_8 = (l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO ==
                                           ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_2_8);
        auto l_def_CORE_FLOOR_RATIO_4_8 = (l_TGT1_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO ==
                                           ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_4_8);
        {
            {
                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 26, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 28, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 29, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 31, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 33, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 34, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 35, 1, 63 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 35, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 36, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01, 36, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 38, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 39, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 39, 2, 62 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 41, 2, 62 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_2_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 41, 2, 62 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 41, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01, 41, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 43, 1, 63 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_FLOOR_RATIO_2_8 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 44, 2, 62 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 44, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 44, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 46, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 48, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 49, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 49, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 51, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 52, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01, 52, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 54, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 55, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 56, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 57, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 59, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 60, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 62, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 63, 1, 63 );
                }
            }
            {
                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 26, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 28, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 29, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 31, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 33, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 34, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 35, 1, 63 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 35, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 36, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01, 36, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 38, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 39, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 39, 2, 62 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 41, 2, 62 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_2_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 41, 2, 62 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 41, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01, 41, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 43, 1, 63 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_FLOOR_RATIO_2_8 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 44, 2, 62 );
                }
                else if ((l_def_CORE_FLOOR_RATIO_4_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 44, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 44, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 46, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 48, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 49, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 49, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 51, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 52, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b01, 52, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 54, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 55, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 56, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 57, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 59, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 60, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 62, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 63, 1, 63 );
                }
            }
            l_rc = fapi2::putScom(TGT0, 0x90000e6105011811ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000e6105011811ull)");
                break;
            }
        }
        {
            {
                l_scom_buffer.insert<uint64_t> (literal_0x400, 22, 12, 52 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x400, 34, 12, 52 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 46, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 49, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 52, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 55, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 58, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0b010, 61, 3, 61 );
            }
            l_rc = fapi2::putScom(TGT0, 0x90000ea205011c11ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000ea205011c11ull)");
                break;
            }
        }
        {
            {
                l_scom_buffer.insert<uint64_t> (literal_0x4, 18, 10, 54 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x141, 28, 12, 52 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x21B, 40, 12, 52 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x30D, 52, 12, 52 );
            }
            l_rc = fapi2::putScom(TGT0, 0x90000ee105011c11ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000ee105011c11ull)");
                break;
            }
        }
        {
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 16, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 19, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 22, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x1, 25, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x1, 28, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x2, 31, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x3, 34, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x7, 37, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 40, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 43, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x0, 46, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x1, 49, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x1, 52, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x2, 55, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x3, 58, 3, 61 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x7, 61, 3, 61 );
            }
            l_rc = fapi2::putScom(TGT0, 0x90000f0505011c11ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000f0505011c11ull)");
                break;
            }
        }
        {
            {
                l_scom_buffer.insert<uint64_t> (literal_0x7, 14, 10, 54 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x5, 24, 10, 54 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x5, 34, 10, 54 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x4, 44, 10, 54 );
            }
            {
                l_scom_buffer.insert<uint64_t> (literal_0x5, 54, 10, 54 );
            }
            l_rc = fapi2::putScom(TGT0, 0x90000f2005011c11ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000f2005011c11ull)");
                break;
            }
        }
        fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO_Type l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO;
        l_rc = FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO, TGT1, l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO);

        if (l_rc)
        {
            FAPI_ERR("ERROR executing: FAPI_ATTR_GET (ATTR_PROC_FABRIC_CORE_CEILING_RATIO)");
            break;
        }

        auto l_def_CORE_CEILING_RATIO_8_8 = (l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO ==
                                             ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_8_8);
        {
            {
                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000, 12, 3, 61 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 15, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 16, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 18, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 19, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 20, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 21, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_CEILING_RATIO_8_8 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 24, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 24, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 26, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 27, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 28, 2, 62 );
                }
                else if ((l_def_CORE_CEILING_RATIO_8_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 28, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 28, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 30, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 31, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 32, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 32, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b111, 34, 3, 61 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 37, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 37, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 39, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 40, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 41, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 42, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 43, 1, 63 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_CEILING_RATIO_8_8 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 44, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 44, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 46, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 47, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 48, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 50, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 51, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 52, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 53, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x000, 54, 10, 54 );
                }
            }
            {
                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b000, 12, 3, 61 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 15, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 16, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 18, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 19, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 20, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 21, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 23, 1, 63 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_CEILING_RATIO_8_8 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 24, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 24, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 26, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 27, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 28, 2, 62 );
                }
                else if ((l_def_CORE_CEILING_RATIO_8_8 == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 28, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b10, 28, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 30, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 31, 1, 63 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 32, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 32, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b111, 34, 3, 61 );
                }

                if ((l_def_SAFE_MODE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 37, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 37, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 39, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 40, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 41, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b1, 42, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 43, 1, 63 );
                }

                if (((l_def_SAFE_MODE == literal_1) || (l_def_CORE_CEILING_RATIO_8_8 == literal_1)))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 44, 2, 62 );
                }
                else if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b11, 44, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 46, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 47, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b00, 48, 2, 62 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 50, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 51, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 52, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0b0, 53, 1, 63 );
                }

                if ((l_def_TRUE == literal_1))
                {
                    l_scom_buffer.insert<uint64_t> (literal_0x000, 54, 10, 54 );
                }
            }
            l_rc = fapi2::putScom(TGT0, 0x90000f4005011811ull, l_scom_buffer);

            if (l_rc)
            {
                FAPI_ERR("ERROR executing: putScom (0x90000f4005011811ull)");
                break;
            }
        }
    }
    while (0);

    return l_rc;
}
