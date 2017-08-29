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

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b10100 = 0b10100;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0b00110 = 0b00110;
constexpr uint64_t literal_0b01000 = 0b01000;
constexpr uint64_t literal_0b01010 = 0b01010;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0b01100 = 0b01100;
constexpr uint64_t literal_0b00011 = 0b00011;
constexpr uint64_t literal_120 = 120;
constexpr uint64_t literal_100 = 100;
constexpr uint64_t literal_0b01001 = 0b01001;
constexpr uint64_t literal_115 = 115;
constexpr uint64_t literal_110 = 110;
constexpr uint64_t literal_105 = 105;
constexpr uint64_t literal_0b01011 = 0b01011;
constexpr uint64_t literal_125 = 125;
constexpr uint64_t literal_0b11000 = 0b11000;
constexpr uint64_t literal_0b11001 = 0b11001;
constexpr uint64_t literal_0b11010 = 0b11010;
constexpr uint64_t literal_0b11011 = 0b11011;
constexpr uint64_t literal_0b11100 = 0b11100;
constexpr uint64_t literal_0b11101 = 0b11101;
constexpr uint64_t literal_0b11111 = 0b11111;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b1110 = 0b1110;
constexpr uint64_t literal_0b1100 = 0b1100;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_0x00000 = 0x00000;
constexpr uint64_t literal_0b00100000 = 0b00100000;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0x00 = 0x00;
constexpr uint64_t literal_0x06 = 0x06;
constexpr uint64_t literal_0x0D = 0x0D;
constexpr uint64_t literal_0x1E = 0x1E;
constexpr uint64_t literal_0x19 = 0x19;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0x400 = 0x400;
constexpr uint64_t literal_0b00001100 = 0b00001100;
constexpr uint64_t literal_0b00000000 = 0b00000000;
constexpr uint64_t literal_0x0C = 0x0C;
constexpr uint64_t literal_0x141 = 0x141;
constexpr uint64_t literal_0x21B = 0x21B;
constexpr uint64_t literal_0x30D = 0x30D;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x000 = 0x000;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b11111110 = 0b11111110;

fapi2::ReturnCode p9_fbc_cd_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_TGT1_ATTR_PROC_EPS_TABLE_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, TGT1, l_TGT1_ATTR_PROC_EPS_TABLE_TYPE));
        uint64_t l_def_IS_FLAT_8 = (l_TGT1_ATTR_PROC_EPS_TABLE_TYPE == fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE_F8);
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_NUM_X_LINKS_CFG = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] +
                                           l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1]) + l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2]);
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ));
        fapi2::ATTR_FREQ_X_MHZ_Type l_TGT1_ATTR_FREQ_X_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_X_MHZ, TGT1, l_TGT1_ATTR_FREQ_X_MHZ));
        uint64_t l_def_X_RATIO_120_100 = ((literal_100 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_120 * l_TGT1_ATTR_FREQ_PB_MHZ));
        fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE_Type l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE));
        uint64_t l_def_SMP_OPTICS_MODE = (l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE ==
                                          fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS);
        uint64_t l_def_X_RATIO_115_100 = ((literal_100 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_115 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_110_100 = ((literal_100 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_110 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_105_100 = ((literal_100 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_105 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_100_100 = ((literal_100 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_100 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_100_105 = ((literal_105 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_100 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_100_110 = ((literal_110 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_100 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_100_115 = ((literal_115 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_100 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_100_120 = ((literal_120 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_100 * l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_X_RATIO_100_125 = ((literal_125 * l_TGT1_ATTR_FREQ_X_MHZ) >= (literal_100 * l_TGT1_ATTR_FREQ_PB_MHZ));
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
        fapi2::ATTR_CHIP_EC_FEATURE_HW409019_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW409019;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW409019, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW409019));
        fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO_Type l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO, TGT1, l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO));
        uint64_t l_def_CORE_CEILING_RATIO_8_8 = (l_TGT1_ATTR_PROC_FABRIC_CORE_CEILING_RATIO ==
                                                ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_8_8);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if (literal_1)
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
                }

                if (l_def_IS_FLAT_8)
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b10100 );
                }
                else if ((l_def_NUM_X_LINKS_CFG == literal_0))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b00110 );
                }
                else if ((l_def_NUM_X_LINKS_CFG == literal_1))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01000 );
                }
                else if ((l_def_NUM_X_LINKS_CFG == literal_2))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01010 );
                }
                else if ((l_def_NUM_X_LINKS_CFG == literal_3))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01100 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b00011 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000cb205012011ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if (literal_1)
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
                }

                if (l_def_IS_FLAT_8)
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b10100 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_120_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01001 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_115_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01010 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_110_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01010 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_105_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01010 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_100_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01010 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_100_105))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01011 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_100_110))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01011 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_100_115))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01011 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_100_120))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01011 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_X_RATIO_100_125))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01100 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_120_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11000 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_115_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11001 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_110_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11010 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_105_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11011 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_100_100))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11100 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_100_105))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11101 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_100_110))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11101 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_100_115))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11111 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_100_120))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11111 );
                }
                else if ((l_def_SMP_OPTICS_MODE && l_def_X_RATIO_100_125))
                {
                    l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b11111 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b00011 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000cb305012011ull, l_scom_buffer));
            }
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<52, 6, 58, uint64_t>(literal_0x4 );
            l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x90000cf405011c11ull, l_scom_buffer));
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<45, 4, 60, uint64_t>(literal_0b1110 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<45, 4, 60, uint64_t>(literal_0b1100 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0b100 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0b000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b101 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && l_def_IS_FLAT_8))
                {
                    l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b001 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && ( ! l_def_IS_FLAT_8)))
                {
                    l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b01 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<59, 2, 62, uint64_t>(literal_0b00 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<61, 3, 61, uint64_t>(literal_0b100 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<61, 3, 61, uint64_t>(literal_0b000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000d3f05011c11ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();
                l_scom_buffer.insert<41, 2, 62, uint64_t>(literal_0b11 );
                l_scom_buffer.insert<43, 2, 62, uint64_t>(literal_0b01 );
                l_scom_buffer.insert<45, 19, 45, uint64_t>(literal_0x00000 );
                FAPI_TRY(fapi2::putScom(TGT0, 0x90000d7805011c11ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if (literal_1)
                {
                    l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b100 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<40, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<41, 8, 56, uint64_t>(literal_0b00100000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b1 );
                }

                if ((l_def_SMP_OPTICS_MODE || l_def_IS_FLAT_8))
                {
                    l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
                }
                else if ((( ! l_def_SMP_OPTICS_MODE) && ( ! l_def_IS_FLAT_8)))
                {
                    l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b1000 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000dcc05011c11ull, l_scom_buffer));
            }
        }
        {
            l_scom_buffer.flush<0> ();
            l_scom_buffer.insert<32, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<35, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<38, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<41, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<44, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<47, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<50, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<53, 3, 61, uint64_t>(literal_0b101 );
            l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x00 );
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
            l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
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

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                if (literal_1)
                {
                    l_scom_buffer.insert<20, 8, 56, uint64_t>(literal_0b00001100 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<28, 8, 56, uint64_t>(literal_0b00000000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<36, 8, 56, uint64_t>(literal_0b00000000 );
                }

                if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW409019 == literal_1))
                {
                    l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0b1 );
                }
                else if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW409019 != literal_1))
                {
                    l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<45, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<46, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0b000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<53, 3, 61, uint64_t>(literal_0b000 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x00 );
                }
            }

            if (((l_chip_id == 0x5) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.insert<20, 8, 56, uint64_t>(literal_0x0C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x90000ec705011c11ull, l_scom_buffer));
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
            l_scom_buffer.insert<16, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<19, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<22, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<25, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<28, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<31, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<34, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<37, 3, 61, uint64_t>(literal_0b101 );
            l_scom_buffer.insert<40, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<43, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<46, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<49, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<58, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<61, 3, 61, uint64_t>(literal_0b101 );
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
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
            {
                l_scom_buffer.flush<0> ();

                if (literal_1)
                {
                    l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0100 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<17, 4, 60, uint64_t>(literal_0b0100 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<21, 4, 60, uint64_t>(literal_0b0100 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<25, 3, 61, uint64_t>(literal_0b011 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<25, 3, 61, uint64_t>(literal_0b001 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<28, 3, 61, uint64_t>(literal_0b001 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<31, 3, 61, uint64_t>(literal_0b010 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<31, 3, 61, uint64_t>(literal_0b001 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<34, 8, 56, uint64_t>(literal_0b11111110 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<42, 8, 56, uint64_t>(literal_0b11111110 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
                }

                if (l_def_SMP_OPTICS_MODE)
                {
                    l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
                }
                else if (( ! l_def_SMP_OPTICS_MODE))
                {
                    l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b010 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
                }

                if (literal_1)
                {
                    l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
                }

                FAPI_TRY(fapi2::putScom(TGT0, 0x90000f4d05011c11ull, l_scom_buffer));
            }
        }
        {
            if (((l_chip_id == 0x5) && (l_chip_ec == 0x20)) || ((l_chip_id == 0x5) && (l_chip_ec == 0x21)) || ((l_chip_id == 0x5)
                    && (l_chip_ec == 0x22)) || ((l_chip_id == 0x6) && (l_chip_ec == 0x10)) )
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
