/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_fbc_no_hp_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include "p10_fbc_no_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_62 = 62;
constexpr uint64_t literal_64 = 64;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_0xB = 0xB;
constexpr uint64_t literal_0b110000 = 0b110000;
constexpr uint64_t literal_0b11000 = 0b11000;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_0x1C = 0x1C;
constexpr uint64_t literal_0x16 = 0x16;
constexpr uint64_t literal_0xC = 0xC;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0xA = 0xA;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x14 = 0x14;
constexpr uint64_t literal_0x8 = 0x8;
constexpr uint64_t literal_0x13 = 0x13;
constexpr uint64_t literal_0x19 = 0x19;
constexpr uint64_t literal_0xD = 0xD;
constexpr uint64_t literal_0x21 = 0x21;
constexpr uint64_t literal_0x29 = 0x29;
constexpr uint64_t literal_0x15 = 0x15;
constexpr uint64_t literal_0xF = 0xF;
constexpr uint64_t literal_0x3A = 0x3A;
constexpr uint64_t literal_0x1D = 0x1D;
constexpr uint64_t literal_0x32 = 0x32;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_0x20 = 0x20;
constexpr uint64_t literal_0x43 = 0x43;
constexpr uint64_t literal_0x56 = 0x56;
constexpr uint64_t literal_0x2B = 0x2B;
constexpr uint64_t literal_0x9 = 0x9;
constexpr uint64_t literal_0x18 = 0x18;
constexpr uint64_t literal_0x2D = 0x2D;
constexpr uint64_t literal_0x11 = 0x11;
constexpr uint64_t literal_0x1E = 0x1E;
constexpr uint64_t literal_0x30 = 0x30;
constexpr uint64_t literal_0x28 = 0x28;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_0x04 = 0x04;
constexpr uint64_t literal_0x0A = 0x0A;
constexpr uint64_t literal_0x03 = 0x03;
constexpr uint64_t literal_0x07 = 0x07;
constexpr uint64_t literal_0x01 = 0x01;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_0xFFF = 0xFFF;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0x400 = 0x400;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_0x2 = 0x2;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0x17 = 0x17;
constexpr uint64_t literal_0b00000 = 0b00000;
constexpr uint64_t literal_0b00101 = 0b00101;
constexpr uint64_t literal_0b00110 = 0b00110;
constexpr uint64_t literal_0b11010 = 0b11010;
constexpr uint64_t literal_0b10101 = 0b10101;

fapi2::ReturnCode p10_fbc_no_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE));
        uint64_t l_def_IS_TWO_HOP = (l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE ==
                                     fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE);
        uint64_t l_def_CHIP_IS_GROUP = (l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE ==
                                        fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);
        fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG));
        uint64_t l_def_NUM_X_LINKS_CFG = l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_TGT1_ATTR_PROC_EPS_TABLE_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, TGT1, l_TGT1_ATTR_PROC_EPS_TABLE_TYPE));
        uint64_t l_def_IS_FLAT_8 = ((l_TGT1_ATTR_PROC_EPS_TABLE_TYPE == fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE)
                                    && (l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP));
        fapi2::ATTR_PROC_FABRIC_A_INDIRECT_Type l_TGT1_ATTR_PROC_FABRIC_A_INDIRECT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_INDIRECT, TGT1, l_TGT1_ATTR_PROC_FABRIC_A_INDIRECT));
        uint64_t l_def_DUAL_VC_MODE = ((l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE ==
                                        fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_2HOP_CHIP_IS_NODE)
                                       || (l_TGT1_ATTR_PROC_FABRIC_A_INDIRECT == fapi2::ENUM_ATTR_PROC_FABRIC_A_INDIRECT_ON));
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG));
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_AX6_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_AX7_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_AX2_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_AX3_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_AX4_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_AX5_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_AX0_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        uint64_t l_def_AX1_ENABLED = ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                                       fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE)
                                      || (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                                          fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301100aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301100aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011013ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011013ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011014ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011014ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011015ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011015ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301101eull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX00_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX00_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX01_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX01_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX02_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX02_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX03_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX03_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301101eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301102aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301102aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301102bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301102bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301104aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301104aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011053ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011053ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011054ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011054ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011055ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011055ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301105eull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX04_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX04_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX05_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX05_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX06_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX06_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX07_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX07_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301105eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301106aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301106aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301106bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301106bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301108aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301108aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011093ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011093ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011094ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011094ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011095ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011095ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301109eull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX08_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX08_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX09_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX09_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX10_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX10_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX11_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX11_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301109eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110aaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30110aaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110abull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30110abull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110caull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30110caull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110d3ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30110d3ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110d4ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30110d4ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110d5ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30110d5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110deull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX12_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX12_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX13_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX13_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX14_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX14_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX15_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX15_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30110deull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110eaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30110eaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110ebull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30110ebull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301110aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301110aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011113ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011113ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011114ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011114ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011115ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011115ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301111eull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX16_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX16_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX17_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX17_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX18_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX18_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX19_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX19_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301111eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301112aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301112aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301112bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301112bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301114aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301114aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011153ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011153ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011154ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011154ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011155ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011155ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301115eull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX20_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX20_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX21_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX21_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX22_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX22_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX23_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX23_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301115eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301116aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301116aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301116bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301116bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301118aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301118aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011193ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011193ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011194ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011194ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011195ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011195ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301119eull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX24_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX24_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX25_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX25_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX26_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX26_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX27_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX27_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301119eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111aaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30111aaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111abull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30111abull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111caull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30111caull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111d3ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30111d3ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111d4ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30111d4ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111d5ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30111d5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111deull, l_scom_buffer ));

            constexpr auto l_PB_PB_COM_PB_CFG_EX28_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX28_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX29_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX29_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX30_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX30_HBUS_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_EX31_HBUS_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_EX31_HBUS_DISABLE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30111deull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111eaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30111eaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111ebull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30111ebull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301120aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301120aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011213ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );

            if (((l_def_AX6_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX6_DON_16_16 = 0x3;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX6_DON_16_16 );
            }
            else if ((l_def_AX6_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX6_DON_32_0 = 0x0;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX6_DON_32_0 );
            }

            if (((l_def_AX7_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX7_DON_16_16 = 0x3;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX7_DON_16_16 );
            }
            else if ((l_def_AX7_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX7_DON_32_0 = 0x0;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX7_DON_32_0 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x04 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011213ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011214ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<24, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<38, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<31, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<45, 7, 57, uint64_t>(literal_0x40 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011214ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011215ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011215ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301122aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301122aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301122bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301122bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301124aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301124aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011253ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011253ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011254ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011254ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011255ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011255ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301126aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301126aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301126bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301126bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301128aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301128aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011293ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011293ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011294ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011294ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011295ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011295ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112aaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112aaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112abull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112abull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112caull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30112caull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112d3ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );

            if (((l_def_AX2_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX2_DON_16_16 = 0x3;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX2_DON_16_16 );
            }
            else if ((l_def_AX2_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX2_DON_32_0 = 0x0;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX2_DON_32_0 );
            }

            if (((l_def_AX3_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX3_DON_16_16 = 0x3;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX3_DON_16_16 );
            }
            else if ((l_def_AX3_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX3_DON_32_0 = 0x0;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX3_DON_32_0 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x04 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112d3ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112d4ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<24, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<38, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<31, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<45, 7, 57, uint64_t>(literal_0x40 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112d4ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112d5ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30112d5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112eaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112eaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112ebull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112ebull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301130aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301130aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011313ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );

            if (((l_def_AX4_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX4_DON_16_16 = 0x3;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX4_DON_16_16 );
            }
            else if ((l_def_AX4_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX4_DON_32_0 = 0x0;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX4_DON_32_0 );
            }

            if (((l_def_AX5_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX5_DON_16_16 = 0x3;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX5_DON_16_16 );
            }
            else if ((l_def_AX5_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX5_DON_32_0 = 0x0;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX5_DON_32_0 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x04 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011313ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011314ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<24, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<38, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<31, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<45, 7, 57, uint64_t>(literal_0x40 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011314ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011315ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011315ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301132aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301132aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301132bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301132bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301134aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301134aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011353ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011353ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011354ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011354ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011355ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011355ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301136aull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301136aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301136bull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301136bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301138aull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x301138aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011393ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011393ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011394ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011394ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011395ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011395ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011396ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 12, 52, uint64_t>(literal_0xFFF );
            l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<24, 12, 52, uint64_t>(literal_0x400 );
            l_scom_buffer.insert<12, 12, 52, uint64_t>(literal_0xFFF );
            l_scom_buffer.insert<51, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<36, 12, 52, uint64_t>(literal_0x400 );

            if ((l_def_CHIP_IS_GROUP == literal_0))
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b101 );
            }
            else if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                l_scom_buffer.insert<55, 3, 61, uint64_t>(literal_0b001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3011396ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011397ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 10, 54, uint64_t>(literal_0x18 );
            l_scom_buffer.insert<10, 10, 54, uint64_t>(literal_0x18 );
            l_scom_buffer.insert<20, 3, 61, uint64_t>(literal_0b111 );
            l_scom_buffer.insert<23, 6, 58, uint64_t>(literal_0x2 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011397ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011398ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<15, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<18, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b101 );
            l_scom_buffer.insert<24, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<27, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<30, 3, 61, uint64_t>(literal_0b000 );
            l_scom_buffer.insert<33, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b001 );
            l_scom_buffer.insert<39, 3, 61, uint64_t>(literal_0b010 );
            l_scom_buffer.insert<42, 3, 61, uint64_t>(literal_0b011 );
            l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b101 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011398ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3011399ull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(literal_0x20 );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(literal_0x17 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<58, 6, 58, uint64_t>(literal_0x20 );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<58, 6, 58, uint64_t>(literal_0x13 );
            }

            l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b00000 );
            l_scom_buffer.insert<5, 5, 59, uint64_t>(literal_0b00101 );
            l_scom_buffer.insert<10, 5, 59, uint64_t>(literal_0b00110 );
            l_scom_buffer.insert<15, 5, 59, uint64_t>(literal_0b00000 );
            l_scom_buffer.insert<20, 5, 59, uint64_t>(literal_0b11010 );
            l_scom_buffer.insert<25, 5, 59, uint64_t>(literal_0b10101 );
            l_scom_buffer.insert<30, 5, 59, uint64_t>(literal_0b00000 );
            constexpr auto l_PB_PB_COM_PB_CFG_USE_SLOW_GO_RATE_OFF = 0x0;
            l_scom_buffer.insert<35, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_USE_SLOW_GO_RATE_OFF );
            FAPI_TRY(fapi2::putScom(TGT0, 0x3011399ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113aaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113aaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113abull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113abull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113caull, l_scom_buffer ));

            if ((l_def_IS_TWO_HOP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP = 0xffff;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_TWO_HOP );
            }
            else if ((l_def_IS_TWO_HOP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP = 0x0;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_HOP_MODE_ONE_HOP );
            }

            if ((l_def_CHIP_IS_GROUP == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP = 0xffff;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_GROUP );
            }
            else if ((l_def_CHIP_IS_GROUP != literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE = 0x0;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_PUMP_MODE_CHIP_IS_NODE );
            }

            l_scom_buffer.insert<16, 7, 57, uint64_t>(literal_62 );
            l_scom_buffer.insert<23, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0x1 );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0xB );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<52, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_OP2_OVERLAP_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF = 0x0;
            l_scom_buffer.insert<53, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_SERIES_ID_DISABLE_OFF );
            constexpr auto l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON = 0xffff;
            l_scom_buffer.insert<54, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_TMGR_TOKEN_ID_RANGE_ON );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30113caull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113d3ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110000 );
            l_scom_buffer.insert<1, 5, 59, uint64_t>(literal_0b11000 );

            if (((l_def_AX0_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX0_DON_16_16 = 0x3;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX0_DON_16_16 );
            }
            else if ((l_def_AX0_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX0_DON_32_0 = 0x0;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK0_DON_PTL_VCINIT_AX0_DON_32_0 );
            }

            if (((l_def_AX1_ENABLED == literal_1) && l_def_DUAL_VC_MODE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX1_DON_16_16 = 0x3;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX1_DON_16_16 );
            }
            else if ((l_def_AX1_ENABLED == literal_1))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX1_DON_32_0 = 0x0;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_PB_COM_PB_CFG_DAT_LINK1_DON_PTL_VCINIT_AX1_DON_32_0 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x04 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_0x0A );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<28, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x03 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x07 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_0x04 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x01 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x04 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113d3ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113d4ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(literal_0b1000 );
            l_scom_buffer.insert<24, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<38, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<31, 7, 57, uint64_t>(literal_0x40 );
            l_scom_buffer.insert<45, 7, 57, uint64_t>(literal_0x40 );

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0x16 );
            }

            if ((l_def_IS_TWO_HOP != literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }
            else if ((l_def_IS_TWO_HOP == literal_1))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0x1C );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113d4ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113d5ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0xC );
            FAPI_TRY(fapi2::putScom(TGT0, 0x30113d5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113eaull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x3 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x14 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x10 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x13 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x19 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x21 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x15 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x29 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0xF );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x29 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x1D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x3A );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x32 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x43 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x2B );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113eaull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113ebull, l_scom_buffer ));

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xF );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0xA );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<8, 8, 56, uint64_t>(literal_0x16 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x7 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x8 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0xB );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<16, 8, 56, uint64_t>(literal_0x18 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x9 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xA );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0xD );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x1C );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x1C );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xB );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0xF );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0x20 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x19 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x2D );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x11 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x32 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x20 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x3A );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x16 );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1E );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if ((((l_def_CHIP_IS_GROUP == literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2))
                      && (l_def_NUM_X_LINKS_CFG < literal_4)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x30 );
            }
            else if (((l_def_CHIP_IS_GROUP == literal_1) && (l_def_IS_FLAT_8 == literal_1)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x1D );
            }
            else if ((((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_0))
                      && (l_def_NUM_X_LINKS_CFG < literal_3)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x28 );
            }
            else if (((l_def_CHIP_IS_GROUP != literal_1) && (l_def_NUM_X_LINKS_CFG > literal_2)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0x56 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113ebull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
