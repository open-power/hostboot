/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/initfiles/p10_fbc_ab_hp_scom.C $ */
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
#include "p10_fbc_ab_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x0C = 0x0C;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_0x08 = 0x08;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_0x20 = 0x20;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_6 = 6;

fapi2::ReturnCode p10_fbc_ab_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
                                     const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_Type l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP, TGT0, l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP));
        fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_Type l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP, TGT0, l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP));
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE));
        uint64_t l_def_CHIP_IS_GROUP = (l_TGT1_ATTR_PROC_FABRIC_BROADCAST_MODE ==
                                        fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);
        fapi2::ATTR_PROC_FABRIC_A_AGGREGATE_Type l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE));
        uint64_t l_def_LINK_A_AGGREGATE_EN = (l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE ==
                                              fapi2::ENUM_ATTR_PROC_FABRIC_A_AGGREGATE_ON);
        fapi2::ATTR_PROC_FABRIC_X_AGGREGATE_Type l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE));
        uint64_t l_def_LINK_X_AGGREGATE_EN = (l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE ==
                                              fapi2::ENUM_ATTR_PROC_FABRIC_X_AGGREGATE_ON);
        fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG));
        fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_LINKS_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_LINKS_CNFG));
        uint64_t l_def_NUM_CHIPS_CFG = ((l_TGT0_ATTR_PROC_FABRIC_A_LINKS_CNFG + literal_1) *
                                        (l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG + literal_1));
        uint64_t l_def_NUM_X_LINKS_CFG = l_TGT0_ATTR_PROC_FABRIC_X_LINKS_CNFG;
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG));
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        uint64_t l_def_A0_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID));
        uint64_t l_def_X0_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID));
        fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS_Type l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS));
        fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS_Type l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS));
        uint64_t l_def_A1_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X1_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_A2_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X2_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_A3_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X3_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_A4_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X4_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_A5_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X5_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_A6_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X6_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_A7_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE);
        uint64_t l_def_X7_ENABLED = (l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                                     fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301100bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301100bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301100dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 16, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 48, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301100dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301104bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301104bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301104dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 19, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301104dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301108bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301108bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301108dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 22, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 50, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301108dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110cbull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30110cbull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30110cdull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 25, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 51, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30110cdull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301110bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301110bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301110dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 28, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301110dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301114bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301114bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301114dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 31, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 53, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301114dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301118bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301118bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301118dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 34, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 54, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301118dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111cbull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30111cbull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30111cdull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 37, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30111cdull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301120bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301120bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301120dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 40, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 56, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301120dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301124bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301124bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301124dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 43, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 57, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301124dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301128bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301128bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301128dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 46, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301128dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112cbull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112cbull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30112cdull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 49, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 59, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30112cdull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301130bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301130bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301130dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 52, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 60, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301130dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301134bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301134bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301134dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 55, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301134dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301138bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301138bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301138dull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 58, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 62, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301138dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113cbull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            if (((l_def_LINK_A_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<16, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_G_AGGREGATE_NEXT_ON );
            }

            if (((l_def_LINK_X_AGGREGATE_EN == literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON = 0xffff;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_R_AGGREGATE_NEXT_ON );
            }

            l_scom_buffer.insert<8, 8, 56, uint64_t>(l_def_NUM_CHIPS_CFG );
            l_scom_buffer.insert<24, 8, 56, uint64_t>(literal_0x0C );

            if (((l_def_NUM_X_LINKS_CFG < literal_2) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (((l_def_NUM_X_LINKS_CFG > literal_1) && (l_def_CHIP_IS_GROUP == literal_1)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_X_LINKS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG < literal_8) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>((l_def_NUM_CHIPS_CFG * literal_4) );
            }
            else if (((l_def_NUM_CHIPS_CFG > literal_7) && (l_def_CHIP_IS_GROUP == literal_0)))
            {
                l_scom_buffer.insert<40, 8, 56, uint64_t>(literal_0x20 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113cbull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30113cdull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_A0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7) && l_def_X0_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<17, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<16, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX0_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_A1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7) && l_def_X1_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<21, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<20, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX1_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_A2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7) && l_def_X2_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<24, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX2_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_A3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7) && l_def_X3_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<29, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<28, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX3_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_A4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7) && l_def_X4_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<33, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_4] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<32, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<12, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX4_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_A5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7) && l_def_X5_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<37, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_5] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<36, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<13, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX5_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_A6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7) && l_def_X6_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<41, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_6] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<40, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX6_ADDR_DIS_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_7] !=
                      fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON = 0xffff;
                l_scom_buffer.insert<7, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_EN_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_0) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_0 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_1) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 = 0x249249249249;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_1 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_2) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 = 0x492492492492;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_2 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_3) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 = 0x6db6db6db6db;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_3 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_4) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 = 0x924924924924;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_4 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_5) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 = 0xb6db6db6db6d;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_5 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_6) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 = 0xdb6db6db6db6;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_6 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_A7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_7] == literal_7) && l_def_X7_ENABLED))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 = 0xffffffffffff;
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ID_NEXT_ID_7 );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_7] !=
                  fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) || (l_def_CHIP_IS_GROUP == literal_1)))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS = 0xffff;
                l_scom_buffer.insert<44, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_MODE_NEXT_RBUS );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }
            else if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_7] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                      && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON = 0xffff;
                l_scom_buffer.insert<15, 1, 63, uint64_t>(l_PB_PB_COM_PB_CFG_LINK_AX7_ADDR_DIS_NEXT_ON );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30113cdull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
