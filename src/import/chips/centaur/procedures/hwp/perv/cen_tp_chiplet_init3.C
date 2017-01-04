/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_tp_chiplet_init3.C $ */
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
///
/// @file cen_tp_chiplet_init3.C
/// @brief : Centaur PRV Chiplet Init Phase 3 (FAPI2)
///
/// General Description:
///          *part of "logic prv init 2" after arrayinit (tp)*
///          bring-up PCB network (all clock domains started)
///          initialize PRV hang counters
///

///
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_tp_chiplet_init3.H>
#include <cen_gen_scom_addresses.H>
#include <centaur_misc_constants.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_tp_chiplet_init3(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_master_pcb_int_data = 0;
    fapi2::buffer<uint64_t> l_prv_pib_pcbms_reset_reg_data = 0x2000000000000000;
    fapi2::buffer<uint64_t> l_tp_gp0_data = 0;
    fapi2::buffer<uint64_t> l_tp_clk_region_data = CLOCK_START_REGIONS_all;
    fapi2::buffer<uint64_t> l_tp_clk_status_data = 0;
    fapi2::buffer<uint32_t> l_fsi_gp3_data = 0;
    fapi2::buffer<uint32_t> l_fsi_status_data = 0;

    FAPI_DBG( "*** Init. remaining Pervasive Chiplet, "
              "Start Clocks on Pervasive Region *** " );

    FAPI_DBG("Reset PCB Master interrupt register");
    FAPI_TRY(fapi2::putScom(i_target, CEN_INTERRUPT_TYPE_REG, l_master_pcb_int_data));

    FAPI_DBG("TP_Chiplet, drop pervasive fence");
    FAPI_TRY(fapi2::getScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));
    l_tp_gp0_data.clearBit<63>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));

    FAPI_DBG("enable PIB trace mode");
    FAPI_TRY(fapi2::getScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));
    l_tp_gp0_data.setBit<23>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));
    FAPI_TRY(fapi2::getScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));
    l_tp_gp0_data.setBit<55>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));

    FAPI_DBG("Write CC, Clock Start command (all other clock domains)");
    FAPI_TRY(fapi2::putScom(i_target, CEN_CLK_REGION_PCB, l_tp_clk_region_data));

    FAPI_DBG("Clock Start command (all other clock domains)");

    FAPI_DBG("Read Clock Status Register, check tholds");
    FAPI_TRY(fapi2::getScom(i_target, CEN_CLOCK_STAT_PCB, l_tp_clk_status_data));
    l_tp_clk_status_data ^= EXPECTED_CC_STATUS_START_all;

    FAPI_ASSERT((l_tp_clk_status_data == 0),
                fapi2::CEN_TP_CHIPLET_INIT3_ERR_CLK_STATUS().set_TARGET(i_target),
                "ERROR: Clock Status Register: 0x%016llX "
                "does not match the expected value: 0x000007FFFFFFFFFF ",
                l_tp_clk_status_data());

    FAPI_DBG("ALL other clocks are running now...");

    FAPI_DBG("Write GP0, clear force_align");
    FAPI_TRY(fapi2::getScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));
    l_tp_gp0_data.clearBit<3>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));

    FAPI_DBG("Write GP0, clear flushmode_inhibit");
    l_tp_gp0_data.clearBit<2>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_GP0_PCB, l_tp_gp0_data));

    FAPI_DBG("Pervasive chiplet drop FSI fence 5 (checkstop, interrupt conditions)");
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP3, l_fsi_gp3_data));
    l_fsi_gp3_data.clearBit<26>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP3, l_fsi_gp3_data));

    FAPI_DBG( "Check FSI2PIB-Status(31) if any clock region is stopped." );
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_STATUS_ROX, l_fsi_status_data));

    FAPI_ASSERT(!l_fsi_status_data.getBit<31>(),
                fapi2::CEN_TP_CHIPLET_INIT3_NOT_ALL_CLK_RUNNING().set_TARGET(i_target),
                "FSI Status register bit(31) indicates, not all clocks are running");

    FAPI_DBG("Setup automatic PCB network, reset on a hang");
    FAPI_TRY(fapi2::putScom(i_target, CEN_RESET_REG, l_prv_pib_pcbms_reset_reg_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

