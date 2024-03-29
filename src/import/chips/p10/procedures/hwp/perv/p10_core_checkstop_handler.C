/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_core_checkstop_handler.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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

//--------------------------------------------------------------------------
//
/// @file p10_core_checkstop_handler.C
/// @brief Depending on input flag, trun local xstops into system xstops.
///
/// *HWP HW Maintainer: Manish Chowdhary  <manichow@in.ibm.com>
/// *HWP FW Maintainer: Dan Crowell <dcrowell@us.ibm.com>
/// *HWP Consumed by: HB
///

#include "p10_core_checkstop_handler.H"
#include "p10_scom_c_b.H"
#include "p10_scom_c_d.H"
#include <p10_scom_c.H>
#include <p10_scom_proc_7.H>
#include <p10_scom_proc_4.H>

using namespace scomt;
using namespace scomt::c;
using namespace scomt::proc;

fapi2::ReturnCode p10_core_checkstop_handler(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target_core,
    bool i_override_restore)
{
    FAPI_INF("Entering ...");

    fapi2::buffer<uint64_t> l_action0;
    fapi2::buffer<uint64_t> l_action1;
    fapi2::buffer<uint64_t> l_data;

    uint8_t l_core_unit_pos = 0;
    uint8_t l_dead_core = 0;

    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_DEAD_CORE_MODE,
                            i_target_core,
                            l_dead_core));

    FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                   i_target_core,
                   l_core_unit_pos);

    if ( l_dead_core )
    {
        FAPI_IMP("p10_core_checkstop_handler: Skipping Phyp Marked dead core %d ", l_core_unit_pos);
        goto fapi_try_exit;
    }


    //if true, save off the original action, and turn local xstops into system xstops.
    if(i_override_restore == CORE_XSTOP_HNDLR__SAVE_AND_ESCALATE)
    {

        // Getting ACTION0
        FAPI_TRY(GET_EC_PC_FIR_CORE_ACTION0(i_target_core, l_action0));


        // Getting ACTION1
        FAPI_TRY(GET_EC_PC_FIR_CORE_ACTION1(i_target_core, l_action1));

        // We want to save the original actions into an attribute for a save-restore
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION0, i_target_core, l_action0),
                 "Error from FAPI_ATTR_SET (ATTR_ORIG_FIR_SETTINGS_ACTION0)");

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION1, i_target_core, l_action1),
                 "Error from FAPI_ATTR_SET (ATTR_ORIG_FIR_SETTINGS_ACTION1)");

        // For every bit, turn every local xstop (0b11) into system xstops (0b00)
        uint64_t l_local_xstop = l_action0 & l_action1; //gets bits that are both set to 1
        l_action0 &= ~l_local_xstop;
        l_action1 &= ~l_local_xstop;

        // Mask PC TimeBase Facility for TOD setup in istep 18.
        // It's done here because security doesn't allow SCOMs to FIR reg in istep 18.
        FAPI_TRY(PREP_EC_PC_FIR_CORE_FIRMASK_WO_OR(i_target_core));
        l_data.flush<0>();
        SET_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(l_data);
        FAPI_TRY(PUT_EC_PC_FIR_CORE_FIRMASK_WO_OR(i_target_core, l_data));
    }
    else
    {
        auto l_target_chip = i_target_core.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        fapi2::buffer<uint64_t> l_es_hp_mode1_curr = 0;

        // We want to pull out the original actions, and restore them
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION0, i_target_core, l_action0),
                 "Error from FAPI_ATTR_GET (ATTR_ORIG_FIR_SETTINGS_ACTION0)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION1, i_target_core, l_action1),
                 "Error from FAPI_ATTR_GET (ATTR_ORIG_FIR_SETTINGS_ACTION1)");

        // Clear error and unmask PC TimeBase Facility
        FAPI_TRY(PREP_EC_PC_FIR_CORE_WO_AND(i_target_core));
        l_data.flush<1>();
        CLEAR_EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR(l_data);
        FAPI_TRY(PUT_EC_PC_FIR_CORE_WO_AND(i_target_core, l_data));

        FAPI_TRY(PREP_EC_PC_FIR_CORE_FIRMASK_WO_AND(i_target_core));
        l_data.flush<1>();
        CLEAR_EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR(l_data);
        FAPI_TRY(PUT_EC_PC_FIR_CORE_FIRMASK_WO_AND(i_target_core, l_data));

        FAPI_TRY(GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR(l_target_chip, l_es_hp_mode1_curr));

        if (!GET_PB_COM_SCOM_ES3_STATION_HP_MODE1_CURR_PB_CFG_MASTER_CHIP_CURR_ES3(l_es_hp_mode1_curr))
        {
            fapi2::buffer<uint64_t> l_es_fir_mask = 0;
            FAPI_TRY(PREP_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR(l_target_chip));
            SET_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_HANG_RECOVERY_GTE_LEVEL1_MASK(l_es_fir_mask);
            FAPI_TRY(PUT_PB_COM_SCOM_ES3_STATION_FIR_MASK_REG_WO_OR(l_target_chip, l_es_fir_mask));
        }
    }

    // Save off the current values of actions into the register
    FAPI_TRY(PREP_EC_PC_FIR_CORE_ACTION0(i_target_core));
    FAPI_TRY(PUT_EC_PC_FIR_CORE_ACTION0(i_target_core, l_action0));
    FAPI_TRY(PREP_EC_PC_FIR_CORE_ACTION1(i_target_core));
    FAPI_TRY(PUT_EC_PC_FIR_CORE_ACTION1(i_target_core, l_action1));

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
