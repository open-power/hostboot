/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp_fbc_ab.C $ */
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
/// @file p10_build_smp_fbc_ab.C
/// @brief Fabric configuration (hotplug, AB) functions.
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_build_smp_fbc_ab.H>
#include <p10_build_smp_adu.H>
#include <p10_fbc_ab_hp_scom.H>
#include <p10_fbc_utils.H>
#include <p10_scom_proc.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Read and consistency check hotplug racetrack registers
///
/// @param[in] i_target       Processor chip target
/// @param[in] i_addr         Address for EQ0 instance of racetrack regs
/// @param[out] o_data        Hotplug register data
///
/// @return fapi2:ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_get_hp_ab_racetrack(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target,
    const uint64_t i_scom_addr,
    fapi2::buffer<uint64_t>& o_data)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_scom_data;

    // check consistency of racetrack register copies
    for (uint8_t l_station = 0; l_station < FABRIC_NUM_STATIONS; l_station++)
    {
        FAPI_TRY(fapi2::getScom(i_target, i_scom_addr + (l_station << 6), l_scom_data),
                 "Error from getScom (0x%016llX)", i_scom_addr + (l_station << 6));

        // raise error if racetrack copies are not equal
        FAPI_ASSERT((l_station == 0) || (l_scom_data == o_data),
                    fapi2::P10_BUILD_SMP_HOTPLUG_CONSISTENCY_ERR()
                    .set_TARGET(i_target)
                    .set_ADDRESS0(i_scom_addr + ((l_station - 1) << 6))
                    .set_ADDRESS1(i_scom_addr + (l_station << 6))
                    .set_DATA0(o_data)
                    .set_DATA1(l_scom_data),
                    "Fabric hotplug racetrack registers are not consistent");

        // set output (will be used to compare with next HW read)
        o_data = l_scom_data;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Copy all hotplug content from NEXT->CURR
///
/// @param[in] i_target       Reference to processor chip target
/// @return fapi2:ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_copy_hp_ab_next_curr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_hp_mode1;
    fapi2::buffer<uint64_t> l_hp_mode2;
    fapi2::buffer<uint64_t> l_hp_mode3;
    fapi2::buffer<uint64_t> l_hp_mode4;

    // read NEXT
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT, l_hp_mode1),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE1_NEXT)");
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT, l_hp_mode2),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE2_NEXT)");
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT, l_hp_mode3),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE3_NEXT)");
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT, l_hp_mode4),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE4_NEXT)");

    // write CURR
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR, l_hp_mode1),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE1_CURR)");
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR, l_hp_mode2),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE2_CURR)");
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR, l_hp_mode3),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE3_CURR)");
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR, l_hp_mode4),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE4_CURR)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Copy all hotplug content from CURR->NEXT
///
/// @param[in] i_target       Reference to processor chip target
/// @return fapi2:ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_build_smp_copy_hp_ab_curr_next(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_hp_mode1;
    fapi2::buffer<uint64_t> l_hp_mode2;
    fapi2::buffer<uint64_t> l_hp_mode3;
    fapi2::buffer<uint64_t> l_hp_mode4;

    // read CURR
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_CURR, l_hp_mode1),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE1_CURR)");
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_CURR, l_hp_mode2),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE2_CURR)");
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_CURR, l_hp_mode3),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE3_CURR)");
    FAPI_TRY(p10_build_smp_get_hp_ab_racetrack(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_CURR, l_hp_mode4),
             "Error from p10_build_smp_get_hp_ab_racetrack (HP_MODE4_CURR)");

    // write NEXT
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE1_NEXT, l_hp_mode1),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE1_NEXT)");
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE2_NEXT, l_hp_mode2),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE2_NEXT)");
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE3_NEXT, l_hp_mode3),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE3_NEXT)");
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_COM_SCOM_EQ0_STATION_HP_MODE4_NEXT, l_hp_mode4),
             "Error from p10_fbc_utils_set_racetrack_regs (HP_MODE4_NEXT)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// @TODO FIXME HW468835 temporarily set scoms manually until figtree is updated
fapi2::ReturnCode p10_fbc_ab_hp1(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM)
{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_data;
    fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_Type l_sys_master_chip;
    fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_Type l_grp_master_chip;
    fapi2::ATTR_PROC_FABRIC_X_AGGREGATE_Type l_x_aggregate;
    fapi2::ATTR_PROC_FABRIC_A_AGGREGATE_Type l_a_aggregate;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG_Type l_num_x_links;
    fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_num_a_links;
    fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG_Type l_num_chips;
    bool l_chip_is_group;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP, i_target, l_sys_master_chip),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_MASTER_CHIP, i_target, l_grp_master_chip),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_GROUP_MASTER_CHIP)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, i_target, l_x_aggregate),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_AGGREGATE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, i_target, l_a_aggregate),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_AGGREGATE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINKS_CNFG, i_target, l_num_x_links),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_LINKS_CNFG)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINKS_CNFG, i_target, l_num_a_links),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_LINKS_CNFG)");

    l_num_chips = (l_num_a_links + 1) * (l_num_x_links + 1);
    l_chip_is_group = (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP);

    FAPI_DBG("Configuring pb_hp_mode1 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_HP_MODE1_NEXT_REG, l_data));

    if(l_sys_master_chip == fapi2::ENUM_ATTR_PROC_FABRIC_SYSTEM_MASTER_CHIP_FALSE)
    {
        l_data.insertFromRight<PB_CFG_MASTER_CHIP_NEXT, PB_CFG_MASTER_CHIP_NEXT_LEN>(ENUM_OFF);
        l_data.insertFromRight<PB_CFG_TM_MASTER_NEXT, PB_CFG_TM_MASTER_NEXT_LEN>(ENUM_OFF);
        l_data.insertFromRight<PB_CFG_CHG_RATE_SP_MASTER_NEXT, PB_CFG_CHG_RATE_SP_MASTER_NEXT_LEN>(ENUM_OFF);
    }
    else
    {
        l_data.insertFromRight<PB_CFG_CHG_RATE_SP_MASTER_NEXT, PB_CFG_CHG_RATE_SP_MASTER_NEXT_LEN>(ENUM_ON);
    }

    if(l_grp_master_chip == fapi2::ENUM_ATTR_PROC_FABRIC_GROUP_MASTER_CHIP_TRUE)
    {
        l_data.insertFromRight<PB_CFG_CHG_RATE_GP_MASTER_NEXT, PB_CFG_CHG_RATE_GP_MASTER_NEXT_LEN>(ENUM_ON);
    }
    else
    {
        l_data.insertFromRight<PB_CFG_CHG_RATE_GP_MASTER_NEXT, PB_CFG_CHG_RATE_GP_MASTER_NEXT_LEN>(ENUM_OFF);
    }

    if((l_a_aggregate == fapi2::ENUM_ATTR_PROC_FABRIC_A_AGGREGATE_ON) && !l_chip_is_group)
    {
        l_data.insertFromRight<PB_CFG_G_AGGREGATE_NEXT, PB_CFG_G_AGGREGATE_NEXT_LEN>(ENUM_ON);
    }

    if((l_x_aggregate == fapi2::ENUM_ATTR_PROC_FABRIC_X_AGGREGATE_ON) && l_chip_is_group)
    {
        l_data.insertFromRight<PB_CFG_R_AGGREGATE_NEXT, PB_CFG_R_AGGREGATE_NEXT_LEN>(ENUM_ON);
    }

    l_data.insertFromRight<PB_CFG_NP_CMD_RATE_NEXT, PB_CFG_NP_CMD_RATE_NEXT_LEN>(l_num_chips);
    l_data.insertFromRight<PB_CFG_MIN_G_CMD_RATE_NEXT, PB_CFG_MIN_G_CMD_RATE_NEXT_LEN>(0x0C);

    if((l_num_x_links < 2) && l_chip_is_group)
    {
        l_data.insertFromRight<PB_CFG_MIN_R_CMD_RATE_NEXT, PB_CFG_MIN_R_CMD_RATE_NEXT_LEN>(0x08);
    }
    else if((l_num_x_links > 1) && l_chip_is_group)
    {
        l_data.insertFromRight<PB_CFG_MIN_R_CMD_RATE_NEXT, PB_CFG_MIN_R_CMD_RATE_NEXT_LEN>(l_num_x_links * 4);
    }
    else if((l_num_chips < 8) && !l_chip_is_group)
    {
        l_data.insertFromRight<PB_CFG_MIN_R_CMD_RATE_NEXT, PB_CFG_MIN_R_CMD_RATE_NEXT_LEN>(l_num_chips * 4);
    }
    else if((l_num_chips > 7) && !l_chip_is_group)
    {
        l_data.insertFromRight<PB_CFG_MIN_R_CMD_RATE_NEXT, PB_CFG_MIN_R_CMD_RATE_NEXT_LEN>(0x20);
    }

    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_HP_MODE1_NEXT_REG, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// @TODO FIXME HW468835 temporarily set scoms manually until figtree is updated
fapi2::ReturnCode p10_fbc_ab_hp2(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM)
{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_data;
    fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_broadcast_mode;
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_attached_chip_cnfg;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_attached_chip_cnfg;
    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID_Type l_x_attached_chip_id;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID_Type l_a_attached_chip_id;
    fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS_Type l_x_addr_dis;
    fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS_Type l_a_addr_dis;
    fapi2::ATTR_PROC_FABRIC_X_AGGREGATE_Type l_x_aggregate;
    fapi2::ATTR_PROC_FABRIC_A_AGGREGATE_Type l_a_aggregate;
    bool l_ax_enabled[8];

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_broadcast_mode),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_BROADCAST_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_attached_chip_cnfg),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_attached_chip_cnfg),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID, i_target, l_x_attached_chip_id),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_ATTACHED_CHIP_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID, i_target, l_a_attached_chip_id),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_ATTACHED_CHIP_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS, i_target, l_x_addr_dis),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_ADDR_DIS)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_AGGREGATE, i_target, l_x_aggregate),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_X_AGGREGATE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_AGGREGATE, i_target, l_a_aggregate),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_A_AGGREGATE)");

    FAPI_DBG("Configuring pb_hp_mode2 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_HP_MODE2_NEXT_REG, l_data));

    for(uint8_t i = 0; i < 8; i++)
    {
        FAPI_DBG("  l_xa_attached_chip_cnfg[%d] = 0x%x 0x%x", i, l_x_attached_chip_cnfg[i], l_a_attached_chip_cnfg[i]);
        FAPI_DBG(" force setting ax0_en on both chips..");
        l_data.setBit(0);

        if((l_a_attached_chip_cnfg[i] != fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) ||
           (l_x_attached_chip_cnfg[i] != fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE))
        {
            l_data.setBit(PB_CFG_LINK_AX0_EN_NEXT + (i * PB_CFG_LINK_AX_EN_NEXT_LEN));
        }

        l_ax_enabled[i] = ((l_a_attached_chip_cnfg[i] != fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) ||
                           (l_x_attached_chip_cnfg[i] != fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_FALSE));

        for(uint8_t j = 0; j < 8; j++)
        {
            if(((l_a_attached_chip_id[i] == j) || (l_x_attached_chip_id[i] == j)) && l_ax_enabled[i])
            {
                switch(i)
                {
                    case 0:
                        l_data.insertFromRight<PB_CFG_LINK_AX0_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    case 1:
                        l_data.insertFromRight<PB_CFG_LINK_AX1_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    case 2:
                        l_data.insertFromRight<PB_CFG_LINK_AX2_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    case 3:
                        l_data.insertFromRight<PB_CFG_LINK_AX3_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    case 4:
                        l_data.insertFromRight<PB_CFG_LINK_AX4_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    case 5:
                        l_data.insertFromRight<PB_CFG_LINK_AX5_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    case 6:
                        l_data.insertFromRight<PB_CFG_LINK_AX6_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    case 7:
                        l_data.insertFromRight<PB_CFG_LINK_AX7_ID_NEXT, PB_CFG_LINK_AX_ID_NEXT_LEN>(j);
                        break;

                    default:
                        break;
                }
            }
        }

        if((l_a_attached_chip_cnfg[i] != fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_FALSE) ||
           (l_broadcast_mode == fapi2::ENUM_ATTR_PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP))
        {
            l_data.setBit(PB_CFG_LINK_AX0_MODE_NEXT + (4 * i * PB_CFG_LINK_AX_MODE_NEXT_LEN));
        }

        if(((l_a_addr_dis[i] == fapi2::ENUM_ATTR_PROC_FABRIC_A_ADDR_DIS_ON)
            && (l_a_aggregate == fapi2::ENUM_ATTR_PROC_FABRIC_A_AGGREGATE_ON)) ||
           ((l_x_addr_dis[i] == fapi2::ENUM_ATTR_PROC_FABRIC_X_ADDR_DIS_ON)
            && (l_x_aggregate == fapi2::ENUM_ATTR_PROC_FABRIC_X_AGGREGATE_ON)))
        {
            l_data.setBit(PB_CFG_LINK_AX0_ADDR_DIS_NEXT + (i * PB_CFG_LINK_AX_ADDR_DIS_NEXT_LEN));
        }
    }

    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_HP_MODE2_NEXT_REG, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// @TODO FIXME HW468835 temporarily set scoms manually until figtree is updated
fapi2::ReturnCode p10_fbc_ab_hp3_hp4(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM)
{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_hp3_data;
    fapi2::buffer<uint64_t> l_hp4_data;
    fapi2::ATTR_PROC_FABRIC_TID_TABLE_ENTRY_VALID_Type l_tid_table_entry_valid;
    fapi2::ATTR_PROC_FABRIC_TID_TABLE_ENTRY_ID_Type l_tid_table_entry_id;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TID_TABLE_ENTRY_VALID, i_target, l_tid_table_entry_valid),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_TID_TABLE_ENTRY_VALID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TID_TABLE_ENTRY_ID, i_target, l_tid_table_entry_id),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_TID_TABLE_ENTRY_ID)");

    FAPI_DBG("Configuring pb_hp_mode3/4 register...");
    FAPI_TRY(getScom(i_target, PB_EQ0_HP_MODE3_NEXT_REG, l_hp3_data));
    FAPI_TRY(getScom(i_target, PB_EQ0_HP_MODE4_NEXT_REG, l_hp4_data));

    for(uint8_t i = 0; i < 32; i++)
    {
        if(l_tid_table_entry_valid[i] != fapi2::ENUM_ATTR_PROC_FABRIC_TID_TABLE_ENTRY_VALID_FALSE)
        {
            if(i >= 16)
            {
                l_hp4_data.setBit(i - 16);
            }
            else
            {
                l_hp3_data.setBit(i);
            }
        }

        for(uint64_t j = 0; j < 8; j++)
        {
            if(l_tid_table_entry_id[i] == j)
            {
                if(i >= 16)
                {
                    l_hp4_data &= ~(0x7ull << (64 - ((PB_CFG_TID_ENTRY16_AX_NUM_NEXT + (i * PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)) +
                                                     PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)));
                    l_hp4_data |= (j << (64 - ((PB_CFG_TID_ENTRY16_AX_NUM_NEXT + (i * PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)) +
                                               PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)));
                }
                else
                {
                    l_hp3_data &= ~(0x7ull << (64 - ((PB_CFG_TID_ENTRY0_AX_NUM_NEXT + (i * PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)) +
                                                     PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)));
                    l_hp3_data |= (j << (64 - ((PB_CFG_TID_ENTRY0_AX_NUM_NEXT + (i * PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)) +
                                               PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN)));
                }
            }
        }
    }

    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_HP_MODE3_NEXT_REG, l_hp3_data));
    FAPI_TRY(p10_fbc_utils_set_racetrack_regs(i_target, PB_EQ0_HP_MODE4_NEXT_REG, l_hp4_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_build_smp_set_fbc_ab(
    p10_build_smp_system& i_smp,
    const p10_build_smp_operation i_op)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // quiesce 'slave' fabrics in preparation for joining
    //   PHASE1 -> quiesce all chips except the chip which is the new fabric master
    //   PHASE2 -> quiesce all drawers except the drawer containing the new fabric master
    FAPI_TRY(p10_build_smp_sequence_adu(i_smp, i_op, QUIESCE),
             "Error from p10_build_smp_sequence_adu (QUIESCE)");

    // program NEXT register set for all chips via initfile
    // program CURR register set only for chips which were just quiesced
    for (auto g_iter = i_smp.groups.begin();
         g_iter != i_smp.groups.end();
         ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin();
             p_iter != g_iter->second.chips.end();
             ++p_iter)
        {
            //// run initfile HWP (sets NEXT)
            //FAPI_EXEC_HWP(l_rc, p10_fbc_ab_hp_scom, *(p_iter->second.target), FAPI_SYSTEM);

            //if (l_rc)
            //{
            //    FAPI_ERR("Error from p10_fbc_ab_hp_scom");
            //    fapi2::current_err = l_rc;
            //    goto fapi_try_exit;
            //}

            // @TODO FIXME HW468835 temporarily set scoms manually until figtree is updated
            FAPI_TRY(p10_fbc_ab_hp1(*(p_iter->second.target), FAPI_SYSTEM));
            FAPI_TRY(p10_fbc_ab_hp2(*(p_iter->second.target), FAPI_SYSTEM));
            FAPI_TRY(p10_fbc_ab_hp3_hp4(*(p_iter->second.target), FAPI_SYSTEM));

            // for chips just quiesced, copy NEXT->CURR
            if (p_iter->second.quiesced_next)
            {
                FAPI_TRY(p10_build_smp_copy_hp_ab_next_curr(*(p_iter->second.target)),
                         "Error from p10_build_smp_copy_hp_ab_next_curr");
            }
        }
    }

    // issue switch AB reconfiguration from chip designated as new master
    // (which is guaranteed to be a master now)
    FAPI_TRY(p10_build_smp_sequence_adu(i_smp, i_op, SWITCH_AB),
             "Error from p10_build_smp_sequence_adu (SWITCH_AB)");

    // reset NEXT register set (copy CURR->NEXT) for all chips
    for (auto g_iter = i_smp.groups.begin();
         g_iter != i_smp.groups.end();
         ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin();
             p_iter != g_iter->second.chips.end();
             ++p_iter)
        {

            FAPI_TRY(p10_build_smp_copy_hp_ab_curr_next(*(p_iter->second.target)),
                     "Error from p10_build_smp_copy_hp_ab_curr_next");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
