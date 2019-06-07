/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_chiplet_fabric_scominit.C $ */
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
///
/// @file p10_chiplet_fabric_scominit.C
/// @brief Apply fabric scom inits to prepare for xlink enablement
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_chiplet_fabric_scominit.H>
#include <p10_smp_link_firs.H>
#include <p10_fbc_utils.H>
#include <p10_fbc_no_hp_scom.H>
#include <p10_fbc_ptl_scom.H>
#include <p10_fbc_dlp_scom.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_fbc_no_hp_scom(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_data;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_cnfg;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_cnfg;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_num_x_links;
    fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_num_a_links;
    fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_num_chips;
    fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_eps_table_type;
    fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_is_flat_8;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_cnfg),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_cnfg),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, i_target, l_num_x_links),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_LINKS_CNFG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG, i_target, l_num_a_links),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_LINKS_CNFG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, FAPI_SYSTEM, l_eps_table_type),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_TABLE_TYPE)");

    l_is_flat_8 = (l_eps_table_type == fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE) &&
                  (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);
    l_num_chips = (l_num_a_links + 1) * (l_num_x_links + 1);

    FAPI_DBG("Configuring pb_mode register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_MODE_REG, l_data));
    l_data
    .insertFromRight<PB_CFG_HOP_MODE, PB_CFG_HOP_MODE_LEN>(0)
    .insertFromRight<PB_CFG_PUMP_MODE, PB_CFG_PUMP_MODE_LEN>(1)
    .insertFromRight<PB_CFG_SP_HW_MARK, PB_CFG_SP_HW_MARK_LEN>(64)
    .insertFromRight<PB_CFG_GP_HW_MARK, PB_CFG_GP_HW_MARK_LEN>(64)
    .insertFromRight<PB_CFG_TMGR_MAX_SLBI_TOKENS, PB_CFG_TMGR_MAX_SLBI_TOKENS_LEN>(0x1)
    .insertFromRight<PB_CFG_TMGR_MAX_TLBI_TOKENS, PB_CFG_TMGR_MAX_TLBI_TOKENS_LEN>(0xB)
    .insertFromRight<PB_CFG_TMGR_OP2_OVERLAP_DISABLE, PB_CFG_TMGR_OP2_OVERLAP_DISABLE_LEN>(0)
    .insertFromRight<PB_CFG_TMGR_SERIES_ID_DISABLE, PB_CFG_TMGR_SERIES_ID_DISABLE_LEN>(0)
    .insertFromRight<PB_CFG_TMGR_TOKEN_ID_RANGE, PB_CFG_TMGR_TOKEN_ID_RANGE_LEN>(1);
    p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_MODE_REG, l_data);

    FAPI_DBG("Configuring pb_station_cfg1 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_STATION_CFG1_REG, l_data));
    l_data
    .insertFromRight<PB_CFG_OC_EXPIRATION_TIME, PB_CFG_OC_EXPIRATION_TIME_LEN>(0b10000);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_STATION_CFG1_REG, l_data));

    FAPI_DBG("Configuring pb_station_cfg1/pb_station_cfg2 register...");

    for(uint8_t l_iohs = 0; l_iohs < FABRIC_NUM_IOHS_LINKS; l_iohs++)
    {
        if(l_x_cnfg[l_iohs] || l_a_cnfg[l_iohs])
        {
            uint64_t l_station_cfg1_reg = 0;
            uint64_t l_station_cfg2_reg = 0;
            fapi2::buffer<uint64_t> l_data1;
            fapi2::buffer<uint64_t> l_data2;

            switch(l_iohs)
            {
                case 0:
                case 1:
                    l_station_cfg1_reg = PB_ES4_STATION_CFG1_REG;
                    l_station_cfg2_reg = PB_ES4_STATION_CFG2_REG;
                    break;

                case 2:
                case 3:
                    l_station_cfg1_reg = PB_EN4_STATION_CFG1_REG;
                    l_station_cfg2_reg = PB_EN4_STATION_CFG2_REG;
                    break;

                case 4:
                case 5:
                    l_station_cfg1_reg = PB_ES1_STATION_CFG1_REG;
                    l_station_cfg2_reg = PB_ES1_STATION_CFG2_REG;
                    break;

                case 6:
                case 7:
                    l_station_cfg1_reg = PB_EN1_STATION_CFG1_REG;
                    l_station_cfg2_reg = PB_EN1_STATION_CFG2_REG;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::P10_CHIPLET_FABRIC_SCOMINIT_INVALID_IOHS_LINK()
                                .set_IOHS_LINK_NUM(l_iohs),
                                "Invalid iohs link when configuring pb_station_cfg1/pb_station_cfg2");
                    break;
            }

            FAPI_TRY(getScom(i_target, l_station_cfg1_reg, l_data1));
            FAPI_TRY(getScom(i_target, l_station_cfg2_reg, l_data2));

            switch(l_iohs)
            {
                case 0:
                case 2:
                case 4:
                case 6:
                    l_data1
                    .insertFromRight<PB_CFG_DAT_LINK0_DON_PTL_VCINIT, PB_CFG_DAT_LINK0_DON_PTL_VCINIT_LEN>(ENUM_DON_32_0);

                    //pb_cfm
                    if(l_a_cnfg[l_iohs])
                    {
                        l_data1
                        .insertFromRight<PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_LIMIT, PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_LIMIT_LEN>(0x04)
                        .insertFromRight<PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MAX, PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MAX_LEN>(0x03)
                        .insertFromRight<PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MIN, PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MIN_LEN>(0x01);
                    }
                    else if(l_x_cnfg[l_iohs])
                    {
                        l_data1
                        .insertFromRight<PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_LIMIT, PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_LIMIT_LEN>(0x0A)
                        .insertFromRight<PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MAX, PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MAX_LEN>(0x07)
                        .insertFromRight<PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MIN, PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MIN_LEN>(0x04);
                    }

                    l_data2
                    .insertFromRight<PB_CFG_DAT_LINK0_DOB_VC0_LIMIT, PB_CFG_DAT_LINK0_DOB_VC0_LIMIT_LEN>(0x40)
                    .insertFromRight<PB_CFG_DAT_LINK0_DOB_VC1_LIMIT, PB_CFG_DAT_LINK0_DOB_VC1_LIMIT_LEN>(0x40);
                    break;

                case 1:
                case 3:
                case 5:
                case 7:
                    l_data1
                    .insertFromRight<PB_CFG_DAT_LINK1_DON_PTL_VCINIT, PB_CFG_DAT_LINK1_DON_PTL_VCINIT_LEN>(ENUM_DON_32_0);

                    //pb_cfm
                    if(l_a_cnfg[l_iohs])
                    {
                        l_data1
                        .insertFromRight<PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_LIMIT, PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_LIMIT_LEN>(0x04)
                        .insertFromRight<PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MAX, PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MAX_LEN>(0x03)
                        .insertFromRight<PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MIN, PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MIN_LEN>(0x01);
                    }
                    else if(l_x_cnfg[l_iohs])
                    {
                        l_data1
                        .insertFromRight<PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_LIMIT, PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_LIMIT_LEN>(0x0A)
                        .insertFromRight<PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MAX, PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MAX_LEN>(0x07)
                        .insertFromRight<PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MIN, PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MIN_LEN>(0x04);
                    }

                    l_data2
                    .insertFromRight<PB_CFG_DAT_LINK1_DOB_VC0_LIMIT, PB_CFG_DAT_LINK1_DOB_VC0_LIMIT_LEN>(0x40)
                    .insertFromRight<PB_CFG_DAT_LINK1_DOB_VC1_LIMIT, PB_CFG_DAT_LINK1_DOB_VC1_LIMIT_LEN>(0x40);
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::P10_CHIPLET_FABRIC_SCOMINIT_INVALID_IOHS_LINK()
                                .set_IOHS_LINK_NUM(l_iohs),
                                "Invalid iohs link when configuring pb_station_cfg1 register");
                    break;
            }

            FAPI_TRY(putScom(i_target, l_station_cfg1_reg, l_data1));
            FAPI_TRY(putScom(i_target, l_station_cfg2_reg, l_data2));
        }
    }

    FAPI_DBG("Configuring pb_station_cfg3 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_STATION_CFG3_REG, l_data));
    l_data
    .insertFromRight<PB_CFG_CHIP_TSNOOP_DELAY, PB_CFG_CHIP_TSNOOP_DELAY_LEN>(0xC);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_STATION_CFG3_REG, l_data));

    FAPI_DBG("Configuring pb_snooper_cfg1 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_SNOOPER_CFG1_REG, l_data));
    l_data
    .insertFromRight<PB_CFG_CHG_RATE_GP_CRESP_SAMPLE_TIME, PB_CFG_CHG_RATE_GP_CRESP_SAMPLE_TIME_LEN>(0x141)
    .insertFromRight<PB_CFG_CHG_RATE_GP_JUMP, PB_CFG_CHG_RATE_GP_JUMP_LEN>(0b010)
    .insertFromRight<PB_CFG_CHG_RATE_GP_REQ_SAMPLE_TIME, PB_CFG_CHG_RATE_GP_REQ_SAMPLE_TIME_LEN>(0x400)
    .insertFromRight<PB_CFG_CHG_RATE_SP_CRESP_SAMPLE_TIME, PB_CFG_CHG_RATE_SP_CRESP_SAMPLE_TIME_LEN>(0x30D)
    .insertFromRight<PB_CFG_CHG_RATE_SP_JUMP, PB_CFG_CHG_RATE_SP_JUMP_LEN>(0b010)
    .insertFromRight<PB_CFG_CHG_RATE_SP_REQ_SAMPLE_TIME, PB_CFG_CHG_RATE_SP_REQ_SAMPLE_TIME_LEN>(0x400);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_SNOOPER_CFG1_REG, l_data));

    FAPI_DBG("Configuring pb_snooper_cfg2 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_SNOOPER_CFG2_REG, l_data));
    l_data
    .insertFromRight<PB_CFG_CHG_RATE_GP_RTY_THRESHOLD, PB_CFG_CHG_RATE_GP_RTY_THRESHOLD_LEN>(0x5)
    .insertFromRight<PB_CFG_CHG_RATE_SP_RTY_THRESHOLD, PB_CFG_CHG_RATE_SP_RTY_THRESHOLD_LEN>(0x4)
    .insertFromRight<PB_CFG_CPO_JUMP_LEVEL, PB_CFG_CPO_JUMP_LEVEL_LEN>(0b111)
    .insertFromRight<PB_CFG_CPO_RTY_LEVEL, PB_CFG_CPO_RTY_LEVEL_LEN>(0x2);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_SNOOPER_CFG2_REG, l_data));

    FAPI_DBG("Configuring pb_snooper_cfg3 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_SNOOPER_CFG3_REG, l_data));
    l_data
    .insertFromRight<PB_CFG_GP_LVL0_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b000)
    .insertFromRight<PB_CFG_GP_LVL1_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b000)
    .insertFromRight<PB_CFG_GP_LVL2_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b000)
    .insertFromRight<PB_CFG_GP_LVL3_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b001)
    .insertFromRight<PB_CFG_GP_LVL4_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b001)
    .insertFromRight<PB_CFG_GP_LVL5_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b010)
    .insertFromRight<PB_CFG_GP_LVL6_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b011)
    .insertFromRight<PB_CFG_GP_LVL7_CHGRATE_CLK_DIV, PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN>(0b101)
    .insertFromRight<PB_CFG_SP_LVL0_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b000)
    .insertFromRight<PB_CFG_SP_LVL1_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b000)
    .insertFromRight<PB_CFG_SP_LVL2_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b000)
    .insertFromRight<PB_CFG_SP_LVL3_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b001)
    .insertFromRight<PB_CFG_SP_LVL4_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b001)
    .insertFromRight<PB_CFG_SP_LVL5_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b010)
    .insertFromRight<PB_CFG_SP_LVL6_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b011)
    .insertFromRight<PB_CFG_SP_LVL7_CHGRATE_CLK_DIV, PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN>(0b101);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_SNOOPER_CFG3_REG, l_data));

    FAPI_DBG("Configuring pb_snooper_cfg4 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_SNOOPER_CFG4_REG, l_data));
    l_data
    .insertFromRight<PB_CFG_HANG0_CMD_RATE, PB_CFG_HANG_CMD_RATE_LEN>(0b00000)
    .insertFromRight<PB_CFG_HANG1_CMD_RATE, PB_CFG_HANG_CMD_RATE_LEN>(0b00110)
    .insertFromRight<PB_CFG_HANG2_CMD_RATE, PB_CFG_HANG_CMD_RATE_LEN>(0b01101)
    .insertFromRight<PB_CFG_HANG3_CMD_RATE, PB_CFG_HANG_CMD_RATE_LEN>(0b00000)
    .insertFromRight<PB_CFG_HANG4_CMD_RATE, PB_CFG_HANG_CMD_RATE_LEN>(0b11110)
    .insertFromRight<PB_CFG_HANG5_CMD_RATE, PB_CFG_HANG_CMD_RATE_LEN>(0b11001)
    .insertFromRight<PB_CFG_HANG6_CMD_RATE, PB_CFG_HANG_CMD_RATE_LEN>(0b00000)
    .insertFromRight<PB_CFG_USE_SLOW_GO_RATE, PB_CFG_USE_SLOW_GO_RATE_LEN>(0x0000);
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_SNOOPER_CFG4_REG, l_data));

    FAPI_DBG("Configuring pb_gp_cmd_rate register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_GP_CMD_RATE_REG, l_data));

    if(l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
    {
        l_data
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL0, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips)
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL1, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips)
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL2, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips)
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL3, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips)
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL4, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips)
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL5, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips)
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL6, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips)
        .insertFromRight<PB_CFG_G_CMD_RATE_LVL7, PB_CFG_G_CMD_RATE_LVL_LEN>(l_num_chips);
    }
    else
    {
        if((l_num_x_links > 0) && (l_num_x_links < 3))
        {
            l_data
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL0, PB_CFG_G_CMD_RATE_LVL_LEN>(0x03)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL1, PB_CFG_G_CMD_RATE_LVL_LEN>(0x04)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL2, PB_CFG_G_CMD_RATE_LVL_LEN>(0x06)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL3, PB_CFG_G_CMD_RATE_LVL_LEN>(0x17)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL4, PB_CFG_G_CMD_RATE_LVL_LEN>(0x1C)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL5, PB_CFG_G_CMD_RATE_LVL_LEN>(0x24)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL6, PB_CFG_G_CMD_RATE_LVL_LEN>(0x34)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL7, PB_CFG_G_CMD_RATE_LVL_LEN>(0x48);
        }
        else if(l_num_x_links > 2)
        {
            l_data
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL0, PB_CFG_G_CMD_RATE_LVL_LEN>(0x03)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL1, PB_CFG_G_CMD_RATE_LVL_LEN>(0x04)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL2, PB_CFG_G_CMD_RATE_LVL_LEN>(0x06)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL3, PB_CFG_G_CMD_RATE_LVL_LEN>(0x28)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL4, PB_CFG_G_CMD_RATE_LVL_LEN>(0x32)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL5, PB_CFG_G_CMD_RATE_LVL_LEN>(0x40)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL6, PB_CFG_G_CMD_RATE_LVL_LEN>(0x5C)
            .insertFromRight<PB_CFG_G_CMD_RATE_LVL7, PB_CFG_G_CMD_RATE_LVL_LEN>(0x80);
        }
    }

    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_GP_CMD_RATE_REG, l_data));

    FAPI_DBG("Configuring pb_sp_cmd_rate register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_SP_CMD_RATE_REG, l_data));

    if(l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP)
    {
        if(l_num_x_links == 0)
        {
            l_data
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL0, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL1, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL2, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL3, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL4, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL5, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL6, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL7, PB_CFG_R_CMD_RATE_LVL_LEN>(l_num_chips);
        }
        else if((l_num_x_links > 0) && (l_num_x_links < 3))
        {
            l_data
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL0, PB_CFG_R_CMD_RATE_LVL_LEN>(0x03)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL1, PB_CFG_R_CMD_RATE_LVL_LEN>(0x04)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL2, PB_CFG_R_CMD_RATE_LVL_LEN>(0x06)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL3, PB_CFG_R_CMD_RATE_LVL_LEN>(0x08)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL4, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0A)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL5, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0C)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL6, PB_CFG_R_CMD_RATE_LVL_LEN>(0x12)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL7, PB_CFG_R_CMD_RATE_LVL_LEN>(0x18);
        }
        else if((l_num_x_links > 2) && (l_num_x_links < 4))
        {
            l_data
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL0, PB_CFG_R_CMD_RATE_LVL_LEN>(0x05)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL1, PB_CFG_R_CMD_RATE_LVL_LEN>(0x07)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL2, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0A)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL3, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0D)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL4, PB_CFG_R_CMD_RATE_LVL_LEN>(0x10)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL5, PB_CFG_R_CMD_RATE_LVL_LEN>(0x14)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL6, PB_CFG_R_CMD_RATE_LVL_LEN>(0x1D)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL7, PB_CFG_R_CMD_RATE_LVL_LEN>(0x28);
        }
        else if(l_is_flat_8)
        {
            l_data
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL0, PB_CFG_R_CMD_RATE_LVL_LEN>(0x08)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL1, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0C)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL2, PB_CFG_R_CMD_RATE_LVL_LEN>(0x12)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL3, PB_CFG_R_CMD_RATE_LVL_LEN>(0x17)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL4, PB_CFG_R_CMD_RATE_LVL_LEN>(0x1C)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL5, PB_CFG_R_CMD_RATE_LVL_LEN>(0x24)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL6, PB_CFG_R_CMD_RATE_LVL_LEN>(0x34)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL7, PB_CFG_R_CMD_RATE_LVL_LEN>(0x48);
        }
    }
    else
    {
        if(l_num_x_links == 0)
        {
            l_data
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL0, PB_CFG_R_CMD_RATE_LVL_LEN>(0x05)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL1, PB_CFG_R_CMD_RATE_LVL_LEN>(0x07)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL2, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0A)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL3, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0D)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL4, PB_CFG_R_CMD_RATE_LVL_LEN>(0x10)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL5, PB_CFG_R_CMD_RATE_LVL_LEN>(0x14)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL6, PB_CFG_R_CMD_RATE_LVL_LEN>(0x1D)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL7, PB_CFG_R_CMD_RATE_LVL_LEN>(0x28);
        }
        else if ((l_num_x_links > 0) && (l_num_x_links < 3))
        {
            l_data
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL0, PB_CFG_R_CMD_RATE_LVL_LEN>(0x08)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL1, PB_CFG_R_CMD_RATE_LVL_LEN>(0x0C)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL2, PB_CFG_R_CMD_RATE_LVL_LEN>(0x12)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL3, PB_CFG_R_CMD_RATE_LVL_LEN>(0x17)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL4, PB_CFG_R_CMD_RATE_LVL_LEN>(0x1C)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL5, PB_CFG_R_CMD_RATE_LVL_LEN>(0x24)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL6, PB_CFG_R_CMD_RATE_LVL_LEN>(0x34)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL7, PB_CFG_R_CMD_RATE_LVL_LEN>(0x48);
        }
        else if (l_num_x_links > 2)
        {
            l_data
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL0, PB_CFG_R_CMD_RATE_LVL_LEN>(0x08)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL1, PB_CFG_R_CMD_RATE_LVL_LEN>(0x14)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL2, PB_CFG_R_CMD_RATE_LVL_LEN>(0x1F)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL3, PB_CFG_R_CMD_RATE_LVL_LEN>(0x28)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL4, PB_CFG_R_CMD_RATE_LVL_LEN>(0x32)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL5, PB_CFG_R_CMD_RATE_LVL_LEN>(0x40)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL6, PB_CFG_R_CMD_RATE_LVL_LEN>(0x5C)
            .insertFromRight<PB_CFG_R_CMD_RATE_LVL7, PB_CFG_R_CMD_RATE_LVL_LEN>(0x80);
        }
    }

    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_SP_CMD_RATE_REG, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

fapi2::ReturnCode p10_chiplet_fabric_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();
    auto l_iohs_targets = i_target.getChildren<fapi2::TARGET_TYPE_IOHS>();
    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::ReturnCode l_rc;

    // shadow iohs attributes to proc scope for initfiles
    for (auto l_iohs : l_iohs_targets)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_pos;
        fapi2::ATTR_PROC_FABRIC_IOHS_CONFIG_MODE_Type l_fabric_iohs_config_mode;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs, l_iohs_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs, l_fabric_iohs_config_mode[l_iohs_pos]),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_IOHS_CONFIG_MODE, i_target, l_fabric_iohs_config_mode),
                 "Error form FAPI_ATTR_GET (ATTR_PROC_FABRIC_IOHS_CONFIG_MODE)");
    }

    // @TODO FIXME HW468835 temporarily set scoms manually until figtree is updated
    // apply FBC non-hotplug scom initfile
    //fapi2::toString(i_target, l_tgt_str, sizeof(l_tgt_str));
    //FAPI_DBG("Invoking p10.fbc.no_hp.scom.initfile on target %s...", l_tgt_str);
    //FAPI_EXEC_HWP(l_rc, p10_fbc_no_hp_scom, i_target, FAPI_SYSTEM);
    //
    //if (l_rc)
    //{
    //    FAPI_ERR("Error from p10_fbc_no_hp_scom");
    //    fapi2::current_err = l_rc;
    //    goto fapi_try_exit;
    //}
    FAPI_TRY(p10_fbc_no_hp_scom(i_target), "Error from p10_fbc_no_hp_scom");

    // mask FIRs on proc/pauc scope if there are no valid links
    if(!l_iohs_targets.size())
    {
        auto l_iohs_present = i_target.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_PRESENT);

        for(auto l_iohs : l_iohs_present)
        {
            FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_t::BOTH, action_t::INACTIVE),
                     "Error from p10_smp_link_firs when masking firs for all links");
        }

        goto fapi_try_exit;
    }

    for (auto l_pauc : l_pauc_targets)
    {
        // @TODO RTC213923 Revisit PTL init values
        // Use values from first available iohs chiplet under this pauc for now.
        // Check with fbc team on which iohs value should be used for iohs_mhz/iohs_bus_width per ptl
        auto l_iohs = l_pauc.getChildren<fapi2::TARGET_TYPE_IOHS>().front();

        // apply FBC TL scom initfile
        fapi2::toString(l_pauc, l_tgt_str, sizeof(l_tgt_str));
        FAPI_DBG("Invoking p10.fbc.ptl.scom.initfile on target %s...", l_tgt_str);
        FAPI_EXEC_HWP(l_rc, p10_fbc_ptl_scom, l_pauc, i_target, FAPI_SYSTEM, l_iohs);

        if (l_rc)
        {
            FAPI_ERR("Error from p10_fbc_ptl_scom");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

    for (auto l_iohs : l_iohs_targets)
    {
        fapi2::ATTR_IOHS_CONFIG_MODE_Type l_iohs_config_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs, l_iohs_config_mode),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

        if(l_iohs_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
        {
            fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
            sublink_t sublink_opt;

            // apply FBC DL scom initfile
            fapi2::toString(l_iohs, l_tgt_str, sizeof(l_tgt_str));
            FAPI_DBG("Invoking p10.fbc.dlp.scom.initfile on target %s...", l_tgt_str);
            FAPI_EXEC_HWP(l_rc, p10_fbc_dlp_scom, l_iohs, i_target, FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_fbc_dlp_scom");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs, l_link_train),
                     "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

            switch(l_link_train)
            {
                case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH:
                    sublink_opt = sublink_t::BOTH;
                    break;

                case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY:
                    sublink_opt = sublink_t::EVEN;
                    break;

                case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY:
                    sublink_opt = sublink_t::ODD;
                    break;

                default:
                    sublink_opt = sublink_t::NONE;
                    break;
            }

            // setup and unmask TL/DL FIRs
            FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_opt, action_t::RUNTIME),
                     "Error from p10_smp_link_firs when configuring both sublinks for runtime operations");
        }
        else
        {
            // mask TL/DL FIRs for links that are not configured for xbus operations
            FAPI_TRY(p10_smp_link_firs(l_iohs, sublink_t::BOTH, action_t::INACTIVE),
                     "Error from p10_smp_link_firs when configuring both sublinks for inactive operations");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
