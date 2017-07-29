/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9_fbc_ab_hp_scom.C $ */
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
#include "p9_fbc_ab_hp_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_9 = 9;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_13 = 13;
constexpr uint64_t literal_14 = 14;
constexpr uint64_t literal_15 = 15;
constexpr uint64_t literal_2000 = 2000;
constexpr uint64_t literal_1611 = 1611;

fapi2::ReturnCode p9_fbc_ab_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0,
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
        fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE_Type l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE));
        fapi2::ATTR_PROC_FABRIC_CAPI_MODE_Type l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CAPI_MODE, TGT1, l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE));
        fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_Type l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE, TGT0, l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE));
        fapi2::ATTR_CHIP_EC_FEATURE_HW386013_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW386013;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW386013, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW386013));
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG));
        fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID_Type l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID));
        fapi2::ATTR_PROC_FABRIC_A_AGGREGATE_Type l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE));
        uint64_t l_def_LINK_A_AGGREGATE_EN = (l_TGT0_ATTR_PROC_FABRIC_A_AGGREGATE == ENUM_ATTR_PROC_FABRIC_A_AGGREGATE_ON);
        fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS_Type l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS, TGT0, l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS));
        fapi2::ATTR_FREQ_A_MHZ_Type l_TGT1_ATTR_FREQ_A_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_A_MHZ, TGT1, l_TGT1_ATTR_FREQ_A_MHZ));
        fapi2::ATTR_FREQ_PB_MHZ_Type l_TGT1_ATTR_FREQ_PB_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ, TGT1, l_TGT1_ATTR_FREQ_PB_MHZ));
        uint64_t l_def_A_CMD_RATE_4B_R = (((literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611) %
                                          (l_TGT1_ATTR_FREQ_A_MHZ * literal_2000));
        fapi2::ATTR_PROC_FABRIC_A_BUS_WIDTH_Type l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_BUS_WIDTH, TGT1, l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH));
        uint64_t l_def_A_CMD_RATE_D = (l_TGT1_ATTR_FREQ_A_MHZ * literal_2000);
        uint64_t l_def_A_CMD_RATE_4B_N = ((literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611);
        uint64_t l_def_A_CMD_RATE_4B_RA = (((literal_5 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611) %
                                           (l_TGT1_ATTR_FREQ_A_MHZ * literal_2000));
        uint64_t l_def_A_CMD_RATE_4B_NA = ((literal_5 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611);
        uint64_t l_def_A_CMD_RATE_2B_R = (((literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611) %
                                          (l_TGT1_ATTR_FREQ_A_MHZ * literal_2000));
        uint64_t l_def_A_CMD_RATE_2B_N = ((literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611);
        uint64_t l_def_A_CMD_RATE_2B_RA = (((literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611) %
                                           (l_TGT1_ATTR_FREQ_A_MHZ * literal_2000));
        uint64_t l_def_A_CMD_RATE_2B_NA = ((literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ) * literal_1611);
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, TGT0,
                               l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG));
        fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID_Type l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID));
        fapi2::ATTR_PROC_FABRIC_X_AGGREGATE_Type l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE));
        uint64_t l_def_LINK_X_AGGREGATE_EN = (l_TGT0_ATTR_PROC_FABRIC_X_AGGREGATE == ENUM_ATTR_PROC_FABRIC_X_AGGREGATE_ON);
        fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS_Type l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, TGT0, l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS));
        fapi2::ATTR_CHIP_EC_FEATURE_HW407123_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW407123, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123));
        fapi2::ATTR_FREQ_X_MHZ_Type l_TGT1_ATTR_FREQ_X_MHZ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_X_MHZ, TGT1, l_TGT1_ATTR_FREQ_X_MHZ));
        uint64_t l_def_X_CMD_RATE_4B_R = ((literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ) % l_TGT1_ATTR_FREQ_X_MHZ);
        fapi2::ATTR_PROC_FABRIC_X_BUS_WIDTH_Type l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_BUS_WIDTH, TGT1, l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH));
        uint64_t l_def_X_CMD_RATE_D = l_TGT1_ATTR_FREQ_X_MHZ;
        uint64_t l_def_X_CMD_RATE_4B_N = (literal_6 * l_TGT1_ATTR_FREQ_PB_MHZ);
        uint64_t l_def_X_CMD_RATE_4B_RA = ((literal_5 * l_TGT1_ATTR_FREQ_PB_MHZ) % l_TGT1_ATTR_FREQ_X_MHZ);
        uint64_t l_def_X_CMD_RATE_4B_NA = (literal_5 * l_TGT1_ATTR_FREQ_PB_MHZ);
        uint64_t l_def_X_CMD_RATE_2B_R = ((literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ) % l_TGT1_ATTR_FREQ_X_MHZ);
        uint64_t l_def_X_CMD_RATE_2B_N = (literal_12 * l_TGT1_ATTR_FREQ_PB_MHZ);
        uint64_t l_def_X_CMD_RATE_2B_RA = ((literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ) % l_TGT1_ATTR_FREQ_X_MHZ);
        uint64_t l_def_X_CMD_RATE_2B_NA = (literal_10 * l_TGT1_ATTR_FREQ_PB_MHZ);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501180bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 61, uint64_t>(l_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 61, uint64_t>(l_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0x7;
                l_scom_buffer.insert<2, 1, 61, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 61, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0x7;
                l_scom_buffer.insert<3, 1, 61, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 61, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            constexpr auto l_PB_COM_PB_CFG_HOP_MODE_NEXT_OFF = 0x0;
            l_scom_buffer.insert<29, 1, 61, uint64_t>(l_PB_COM_PB_CFG_HOP_MODE_NEXT_OFF );

            if ((l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS))
            {
                constexpr auto l_PB_COM_PB_CFG_SMP_OPTICS_MODE_NEXT_ON = 0x7;
                l_scom_buffer.insert<30, 1, 61, uint64_t>(l_PB_COM_PB_CFG_SMP_OPTICS_MODE_NEXT_ON );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CAPI_MODE_ON))
            {
                constexpr auto l_PB_COM_PB_CFG_CAPI_MODE_NEXT_ON = 0x7;
                l_scom_buffer.insert<31, 1, 61, uint64_t>(l_PB_COM_PB_CFG_CAPI_MODE_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<32, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<32, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<32, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<34, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<34, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<34, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<36, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<36, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<36, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW386013 != literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<38, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<38, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<38, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<38, 2, 58, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<4, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<12, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<5, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<16, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<6, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<20, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<7, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<24, 4, 52, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_15 );
            }

            if (l_def_LINK_A_AGGREGATE_EN)
            {
                constexpr auto l_PB_COM_PB_CFG_A_AGGREGATE_NEXT_ON = 0x7;
                l_scom_buffer.insert<28, 1, 61, uint64_t>(l_PB_COM_PB_CFG_A_AGGREGATE_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA0_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<8, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NA0_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA1_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<9, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NA1_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA2_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<10, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NA2_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA3_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<11, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NA3_ADDR_DIS_NEXT_ON );
            }

            if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                  && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_4B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_4B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_4B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_4B_NA / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_4B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_4B_NA / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_2B_NA / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_2B_NA / l_def_A_CMD_RATE_D) - literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501180bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501180full, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<0, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<16, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<1, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<19, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<2, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<22, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<3, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<25, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<4, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<28, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<5, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<31, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<6, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<34, 3, 55, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_7 );
            }

            if (l_def_LINK_X_AGGREGATE_EN)
            {
                constexpr auto l_PB_COM_PB_CFG_X_AGGREGATE_NEXT_ON = 0x7;
                l_scom_buffer.insert<37, 1, 61, uint64_t>(l_PB_COM_PB_CFG_X_AGGREGATE_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX0_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<8, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NX0_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX1_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<9, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NX1_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX2_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<10, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NX2_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX3_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<11, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NX3_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX4_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<12, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NX4_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX5_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<13, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NX5_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX6_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<14, 1, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_NX6_ADDR_DIS_NEXT_ON );
            }

            constexpr auto l_PB_COM_PB_CFG_X_INDIRECT_EN_NEXT_ON = 0x7;
            l_scom_buffer.insert<49, 1, 61, uint64_t>(l_PB_COM_PB_CFG_X_INDIRECT_EN_NEXT_ON );
            constexpr auto l_PB_COM_PB_CFG_X_GATHER_ENABLE_NEXT_ON = 0x7;
            l_scom_buffer.insert<50, 1, 61, uint64_t>(l_PB_COM_PB_CFG_X_GATHER_ENABLE_NEXT_ON );

            if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                   && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R != literal_0))
                 && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_4) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) - literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501180full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011c0bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 62, uint64_t>(l_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 62, uint64_t>(l_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0x7;
                l_scom_buffer.insert<2, 1, 62, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 62, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0x7;
                l_scom_buffer.insert<3, 1, 62, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 62, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            constexpr auto l_PB_COM_PB_CFG_HOP_MODE_NEXT_OFF = 0x0;
            l_scom_buffer.insert<29, 1, 62, uint64_t>(l_PB_COM_PB_CFG_HOP_MODE_NEXT_OFF );

            if ((l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS))
            {
                constexpr auto l_PB_COM_PB_CFG_SMP_OPTICS_MODE_NEXT_ON = 0x7;
                l_scom_buffer.insert<30, 1, 62, uint64_t>(l_PB_COM_PB_CFG_SMP_OPTICS_MODE_NEXT_ON );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CAPI_MODE_ON))
            {
                constexpr auto l_PB_COM_PB_CFG_CAPI_MODE_NEXT_ON = 0x7;
                l_scom_buffer.insert<31, 1, 62, uint64_t>(l_PB_COM_PB_CFG_CAPI_MODE_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<32, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<32, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<32, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<34, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<34, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<34, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<36, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<36, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<36, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW386013 != literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<38, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<38, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<38, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<38, 2, 60, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<4, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<12, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<5, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<16, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<6, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<20, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<7, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<24, 4, 56, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_15 );
            }

            if (l_def_LINK_A_AGGREGATE_EN)
            {
                constexpr auto l_PB_COM_PB_CFG_A_AGGREGATE_NEXT_ON = 0x7;
                l_scom_buffer.insert<28, 1, 62, uint64_t>(l_PB_COM_PB_CFG_A_AGGREGATE_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA0_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<8, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NA0_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA1_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<9, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NA1_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA2_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<10, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NA2_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA3_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<11, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NA3_ADDR_DIS_NEXT_ON );
            }

            if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                  && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_4B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_4B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_4B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_4B_NA / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_4B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_4B_NA / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_2B_NA / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_2B_NA / l_def_A_CMD_RATE_D) - literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011c0bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x5011c0full, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<0, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<16, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<1, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<19, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<2, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<22, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<3, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<25, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<4, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<28, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<5, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<31, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<6, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<34, 3, 58, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_7 );
            }

            if (l_def_LINK_X_AGGREGATE_EN)
            {
                constexpr auto l_PB_COM_PB_CFG_X_AGGREGATE_NEXT_ON = 0x7;
                l_scom_buffer.insert<37, 1, 62, uint64_t>(l_PB_COM_PB_CFG_X_AGGREGATE_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX0_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<8, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NX0_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX1_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<9, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NX1_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX2_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<10, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NX2_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX3_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<11, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NX3_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX4_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<12, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NX4_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX5_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<13, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NX5_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX6_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<14, 1, 62, uint64_t>(l_PB_COM_PB_CFG_LINK_NX6_ADDR_DIS_NEXT_ON );
            }

            constexpr auto l_PB_COM_PB_CFG_X_INDIRECT_EN_NEXT_ON = 0x7;
            l_scom_buffer.insert<49, 1, 62, uint64_t>(l_PB_COM_PB_CFG_X_INDIRECT_EN_NEXT_ON );
            constexpr auto l_PB_COM_PB_CFG_X_GATHER_ENABLE_NEXT_ON = 0x7;
            l_scom_buffer.insert<50, 1, 62, uint64_t>(l_PB_COM_PB_CFG_X_GATHER_ENABLE_NEXT_ON );

            if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                   && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R != literal_0))
                 && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_4) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) - literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x5011c0full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501200bull, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF = 0x0;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_COM_PB_CFG_MASTER_CHIP_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_COM_PB_CFG_TM_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON = 0x7;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_GP_MASTER_NEXT_OFF );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_TRUE))
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON = 0x7;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_ON );
            }
            else if (literal_1)
            {
                constexpr auto l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF = 0x0;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_COM_PB_CFG_CHG_RATE_SP_MASTER_NEXT_OFF );
            }

            constexpr auto l_PB_COM_PB_CFG_HOP_MODE_NEXT_OFF = 0x0;
            l_scom_buffer.insert<29, 1, 63, uint64_t>(l_PB_COM_PB_CFG_HOP_MODE_NEXT_OFF );

            if ((l_TGT1_ATTR_PROC_FABRIC_SMP_OPTICS_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_A_BUS))
            {
                constexpr auto l_PB_COM_PB_CFG_SMP_OPTICS_MODE_NEXT_ON = 0x7;
                l_scom_buffer.insert<30, 1, 63, uint64_t>(l_PB_COM_PB_CFG_SMP_OPTICS_MODE_NEXT_ON );
            }

            if ((l_TGT1_ATTR_PROC_FABRIC_CAPI_MODE == fapi2::ENUM_ATTR_PROC_FABRIC_CAPI_MODE_ON))
            {
                constexpr auto l_PB_COM_PB_CFG_CAPI_MODE_NEXT_ON = 0x7;
                l_scom_buffer.insert<31, 1, 63, uint64_t>(l_PB_COM_PB_CFG_CAPI_MODE_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT0_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<32, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT0_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT1_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<34, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT1_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<36, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<36, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT2_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<36, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT2_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW386013 != literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<38, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_SMP))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP = 0x0;
                l_scom_buffer.insert<38, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_SMP );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] ==
                      fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_CAPI))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_CAPI = 0x15;
                l_scom_buffer.insert<38, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_CAPI );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_OPTICS_CONFIG_MODE_NV))
            {
                constexpr auto l_PB_COM_PB_CFG_OPT3_MODE_NEXT_NV = 0x2a;
                l_scom_buffer.insert<38, 2, 62, uint64_t>(l_PB_COM_PB_CFG_OPT3_MODE_NEXT_NV );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_0] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<12, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A0_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_1] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<16, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A1_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_2] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<20, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A2_GROUPID_NEXT_ID_15 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<7, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_1 = 0x111;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_2 = 0x222;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_3 = 0x333;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_4 = 0x444;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_5 = 0x555;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_6 = 0x666;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_7 = 0x777;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_7 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_8))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_8 = 0x888;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_8 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_9))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_9 = 0x999;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_9 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_10))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_10 = 0xaaa;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_10 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_11))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_11 = 0xbbb;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_11 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_12))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_12 = 0xccc;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_12 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_13))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_13 = 0xddd;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_13 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_14))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_14 = 0xeee;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_14 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID[literal_3] == literal_15))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_15 = 0xfff;
                l_scom_buffer.insert<24, 4, 60, uint64_t>(l_PB_COM_PB_CFG_LINK_A3_GROUPID_NEXT_ID_15 );
            }

            if (l_def_LINK_A_AGGREGATE_EN)
            {
                constexpr auto l_PB_COM_PB_CFG_A_AGGREGATE_NEXT_ON = 0x7;
                l_scom_buffer.insert<28, 1, 63, uint64_t>(l_PB_COM_PB_CFG_A_AGGREGATE_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA0_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NA0_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA1_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NA1_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA2_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NA2_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_A_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
                 && l_def_LINK_A_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NA3_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NA3_ADDR_DIS_NEXT_ON );
            }

            if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                  && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_4B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_4B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_4B_N / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_4B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_4B_NA / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_4B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_4B_NA / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_0)) && (l_def_A_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_2B_N / l_def_A_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_A_CMD_RATE_2B_NA / l_def_A_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_A_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_A_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_A_AGGREGATE_EN == literal_1)) && (l_def_A_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_A_CMD_RATE_2B_NA / l_def_A_CMD_RATE_D) - literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501200bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x501200full, l_scom_buffer ));

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_0] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<0, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_0] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<16, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X0_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_1] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<1, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_1] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<19, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X1_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_2] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<2, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_2] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<22, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X2_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_3] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<3, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_3] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<25, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X3_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_4] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<4, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_4] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<28, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X4_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_5] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<5, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_5] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<31, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X5_CHIPID_NEXT_ID_7 );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG[literal_6] !=
                 fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_EN_NEXT_ON = 0x7;
                l_scom_buffer.insert<6, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_EN_NEXT_ON );
            }

            if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_0))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_0 = 0x0;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_0 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_1))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_1 = 0x49;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_1 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_2))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_2 = 0x92;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_2 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_3))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_3 = 0xdb;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_3 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_4))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_4 = 0x124;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_4 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_5))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_5 = 0x16d;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_5 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_6))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_6 = 0x1b6;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_6 );
            }
            else if ((l_TGT0_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID[literal_6] == literal_7))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_7 = 0x1ff;
                l_scom_buffer.insert<34, 3, 61, uint64_t>(l_PB_COM_PB_CFG_LINK_X6_CHIPID_NEXT_ID_7 );
            }

            if (l_def_LINK_X_AGGREGATE_EN)
            {
                constexpr auto l_PB_COM_PB_CFG_X_AGGREGATE_NEXT_ON = 0x7;
                l_scom_buffer.insert<37, 1, 63, uint64_t>(l_PB_COM_PB_CFG_X_AGGREGATE_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_0] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX0_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<8, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NX0_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_1] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX1_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<9, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NX1_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_2] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX2_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<10, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NX2_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_3] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX3_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<11, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NX3_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_4] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX4_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<12, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NX4_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_5] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX5_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<13, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NX5_ADDR_DIS_NEXT_ON );
            }

            if (((l_TGT0_ATTR_PROC_FABRIC_X_ADDR_DIS[literal_6] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
                 && l_def_LINK_X_AGGREGATE_EN))
            {
                constexpr auto l_PB_COM_PB_CFG_LINK_NX6_ADDR_DIS_NEXT_ON = 0x7;
                l_scom_buffer.insert<14, 1, 63, uint64_t>(l_PB_COM_PB_CFG_LINK_NX6_ADDR_DIS_NEXT_ON );
            }

            constexpr auto l_PB_COM_PB_CFG_X_INDIRECT_EN_NEXT_ON = 0x7;
            l_scom_buffer.insert<49, 1, 63, uint64_t>(l_PB_COM_PB_CFG_X_INDIRECT_EN_NEXT_ON );
            constexpr auto l_PB_COM_PB_CFG_X_GATHER_ENABLE_NEXT_ON = 0x7;
            l_scom_buffer.insert<50, 1, 63, uint64_t>(l_PB_COM_PB_CFG_X_GATHER_ENABLE_NEXT_ON );

            if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                   && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R != literal_0))
                 && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_4) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA != literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) + literal_3) );
            }
            else if (((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                        && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA == literal_0))
                      && (l_TGT0_ATTR_CHIP_EC_FEATURE_HW407123 != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) + literal_2) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_4B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_N / l_def_X_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) + literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_4_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_4B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_4B_NA / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_0)) && (l_def_X_CMD_RATE_2B_R == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_N / l_def_X_CMD_RATE_D) - literal_1) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA != literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) );
            }
            else if ((((l_TGT1_ATTR_PROC_FABRIC_X_BUS_WIDTH == fapi2::ENUM_ATTR_PROC_FABRIC_X_BUS_WIDTH_2_BYTE)
                       && (l_def_LINK_X_AGGREGATE_EN == literal_1)) && (l_def_X_CMD_RATE_2B_RA == literal_0)))
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(((l_def_X_CMD_RATE_2B_NA / l_def_X_CMD_RATE_D) - literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x501200full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
