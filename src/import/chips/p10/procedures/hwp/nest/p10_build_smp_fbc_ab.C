/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp_fbc_ab.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

/// See doxygen comments in header file
fapi2::ReturnCode p10_build_smp_pre_fbc_ab(
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
    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); ++p_iter)
        {
            // run initfile HWP (sets NEXT)
            FAPI_EXEC_HWP(l_rc, p10_fbc_ab_hp_scom, *(p_iter->second.target), FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_fbc_ab_hp_scom");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            // for chips just quiesced, copy NEXT->CURR
            if (p_iter->second.quiesced_next)
            {
                FAPI_TRY(p10_build_smp_copy_hp_ab_next_curr(*(p_iter->second.target)),
                         "Error from p10_build_smp_copy_hp_ab_next_curr");
            }
        }
    }

    // confirm from hardware that master chip is currently a master,
    // and setup to be a master after the switch
    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); ++p_iter)
        {
            if (p_iter->second.master_chip_sys_next)
            {
                using namespace scomt::proc;

                fapi2::buffer<uint64_t> l_hp_mode1_reg;
                uint64_t l_master_chip_curr = 0;
                uint64_t l_master_chip_next = 0;

                FAPI_TRY(GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR(*(p_iter->second.target), l_hp_mode1_reg),
                         "Error from getScom (PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR)");
                GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(l_hp_mode1_reg, l_master_chip_curr);

                FAPI_TRY(GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT(*(p_iter->second.target), l_hp_mode1_reg),
                         "Error from getScom (PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT)");
                GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_NEXT_PB_CFG_MASTER_CHIP_NEXT_ES3(l_hp_mode1_reg, l_master_chip_next);

                FAPI_ASSERT(l_master_chip_curr && l_master_chip_next,
                            fapi2::P10_BUILD_SMP_MASTER_CONFIGURATION_ERR()
                            .set_TARGET(*(p_iter->second.target))
                            .set_OP(i_op)
                            .set_MASTER_CHIP_CURR(l_master_chip_curr)
                            .set_MASTER_CHIP_NEXT(l_master_chip_next),
                            "Designated master chip is not properly configured as current/next master (curr: %d, next: %d)",
                            l_master_chip_curr, l_master_chip_next);
            }
        }
    }

    // set adu action switch
    FAPI_TRY(p10_build_smp_sequence_adu(i_smp, i_op, PRE_SWITCH_AB),
             "Error from p10_build_smp_sequence_adu (PRE_SWITCH_AB)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_build_smp_switch_fbc_ab(
    p10_build_smp_system& i_smp,
    const p10_build_smp_operation i_op)
{
    FAPI_DBG("Start");

    // issue switch AB reconfiguration from chip designated as new master
    // (which is guaranteed to be a master now, confirmed by p10_build_smp_pre_fbc_ab)
    FAPI_TRY(p10_build_smp_sequence_adu(i_smp, i_op, SWITCH_AB),
             "Error from p10_build_smp_sequence_adu (SWITCH_AB)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_build_smp_post_fbc_ab(
    p10_build_smp_system& i_smp,
    const p10_build_smp_operation i_op)
{
    FAPI_DBG("Start");

    // reset adu action switch
    FAPI_TRY(p10_build_smp_sequence_adu(i_smp, i_op, RESET_SWITCH),
             "Error from p10_build_smp_sequence_adu (RESET_SWITCH)");

    // reset NEXT register set (copy CURR->NEXT) for all chips
    for (auto g_iter = i_smp.groups.begin(); g_iter != i_smp.groups.end(); ++g_iter)
    {
        for (auto p_iter = g_iter->second.chips.begin(); p_iter != g_iter->second.chips.end(); ++p_iter)
        {
            FAPI_TRY(p10_build_smp_copy_hp_ab_curr_next(*(p_iter->second.target)),
                     "Error from p10_build_smp_copy_hp_ab_curr_next");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
