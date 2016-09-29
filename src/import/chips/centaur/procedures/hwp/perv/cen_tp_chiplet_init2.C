/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_tp_chiplet_init2.C $ */
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
/// @file cen_tp_chiplet_init2.C
/// @brief Centaur Pervasive Init Phase 2 (FAPI2)
///
/// General Description : Pervasive Init Procedure 2
///                        - first scan0, scom to clock control PRV chiplet
///
/// @author Peng Fei GOU <shgoupf@us.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_tp_chiplet_init2.H>
#include <cen_common_funcs.H>

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_tp_chiplet_init2(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_pcb_clk_region_data;
    fapi2::buffer<uint64_t> l_pcb_clk_status     ;
    fapi2::buffer<uint32_t> l_fsi_gp3_data       = 0;
    uint64_t  temp_data_64;


    FAPI_DBG("*** Scan Initialization of Pervasive Chiplet (SCAN0 and Scan Repair) ***");
    FAPI_TRY(cen_scan0_module(i_target, SCAN_CHIPLET_TP, SCAN_CLK_ALL_BUT_PLL, SCAN_GPTR_TIME_REP_NO_PLL),
             "Error from calling cen_scan0_module subroutine ");

    FAPI_TRY(cen_scan0_module(i_target, SCAN_CHIPLET_TP, SCAN_CLK_ALL_BUT_PLL, SCAN_ALL_BUT_VITALPLLGPTRTIME),
             "Error from calling cen_scan0_module subroutine ");

    FAPI_DBG("Clock Start command (PIB, NET only). ");
    l_pcb_clk_region_data = CLOCK_START_REGIONS_PIBNET;
    FAPI_TRY(fapi2::putScom(i_target, TP_CLK_REGION, l_pcb_clk_region_data),
             "Error from putScom (TP_CLK_REGION)");

    FAPI_TRY(fapi2::getScom(i_target, TP_CLK_STATUS, l_pcb_clk_status),
             "Error from getScom (TP_CLK_STATUS)");

    FAPI_TRY(l_pcb_clk_status.extract(temp_data_64, 0, 64),
             "Error from l_pcb_clk_status extraction");

    FAPI_ASSERT(temp_data_64 == EXPECTED_CC_STATUS_START_PIBNET,
                fapi2::CEN_TP_CHIPLET_INIT2_ERR_CLK_CNTL().set_TARGET(i_target),
                "ERROR: Clock Control Register: 0x%016llX "
                "does not match the expected value: 0xE07FFFFF",
                temp_data_64);

    FAPI_DBG("PIB, NET running now.");
    FAPI_DBG("Assert PCB reset");
    FAPI_TRY(fapi2::getCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from gettCfamRegister (CFAM_FSI_GP3)");
    l_fsi_gp3_data.setBit<22>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3)");

    FAPI_DBG("PIB2PCB switch mux, set to operational");
    l_fsi_gp3_data.clearBit<20>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3)");

    FAPI_DBG("Deassert PCB reset");
    l_fsi_gp3_data.clearBit<22>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3)");

    FAPI_DBG("Drop global_ep_reset signal");
    l_fsi_gp3_data.clearBit<31>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3)");

    FAPI_DBG("Switch Pervasive Chiplet OOB Mux");
    l_fsi_gp3_data.clearBit<21>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3)");

    FAPI_DBG("Invoking repair loader...");
    FAPI_TRY(cen_repair_loader(i_target, REPAIR_CMD_VALIDATION_ENTRIES, REPAIR_CMD_START_ADDR),
             "Error from calling cen_repair_loader subroutine ");

fapi_try_exit:
    FAPI_DBG("cen_tp_chiplet_init2 Done");
    return fapi2::current_err;
}


