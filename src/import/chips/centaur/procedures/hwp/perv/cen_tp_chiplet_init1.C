/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_tp_chiplet_init1.C $ */
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
/// @file cen_tp_chiplet_init1.C
/// @brief Centaur Pervasive Init Phase 1 (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

// TODO: RTC 163585 (replace SCOM address constants/fields with auto-generated
//                   contents from headers)

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_tp_chiplet_init1.H>

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

// CFAM register addresses
const uint32_t FSI2PIB_STATUS = 0x1007;
const uint32_t FSI2PIB_RESET  = 0x1006;
const uint32_t CFAM_FSI_GP3   = 0x1012;
const uint32_t CFAM_FSI_GP4   = 0x1013;
const uint32_t CFAM_FSI_GP5   = 0x1014;
const uint32_t CFAM_FSI_GP6   = 0x1015;
const uint32_t CFAM_FSI_GP7   = 0x1016;
const uint32_t PERV_GP3       = 0x101B;

// Reset values for FSI GP Registers
constexpr uint32_t CFAM_STATUS_RESET_DATA  = 0xFFFFFFFF;
constexpr uint32_t CFAM_FSI_GP3_RESET_DATA = 0x00000FFB;
constexpr uint32_t CFAM_FSI_GP4_RESET_DATA = 0x0000C280;
constexpr uint32_t CFAM_FSI_GP5_RESET_DATA = 0x00000100;
constexpr uint32_t CFAM_FSI_GP6_RESET_DATA = 0x00000000;
constexpr uint32_t CFAM_FSI_GP7_RESET_DATA = 0x00000000;

// Reset value for Pervasive Gp3 Register
constexpr uint32_t PERV_GP3_RESET_DATA = 0x44166000;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_tp_chiplet_init1(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_INF("Start");
    fapi2::buffer<uint32_t> l_cfam_status_data = CFAM_STATUS_RESET_DATA;
    fapi2::buffer<uint32_t> l_fsi_gp3_data = CFAM_FSI_GP3_RESET_DATA;
    fapi2::buffer<uint32_t> l_fsi_gp4_data = CFAM_FSI_GP4_RESET_DATA;
    fapi2::buffer<uint32_t> l_perv_gp3_data = PERV_GP3_RESET_DATA;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_CEN_DMI_REFCLOCK_RCVR_TERM_Type l_dmi_refclock_term;
    fapi2::ATTR_CEN_DDR_REFCLOCK_RCVR_TERM_Type l_ddr_refclock_term;
    fapi2::ATTR_CEN_EC_FEATURE_SWITCH_DIV24_RUN_MODE_Type l_div24_run_mode;

    FAPI_DBG("Fix PIBABORT during warmstart via MAILBOX");
    FAPI_TRY(fapi2::putCfamRegister(i_target, FSI2PIB_STATUS, l_cfam_status_data),
             "Error from putCfamRegister (FSI2PIB_STATUS)");
    FAPI_TRY(fapi2::putCfamRegister(i_target, FSI2PIB_RESET, l_cfam_status_data),
             "Error from putCfamRegister (FSI2PIB_RESET)");

    // initialize FSI GP registers
    FAPI_DBG("Initialize FSI GP Registers");
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3, init)");

    // insert customized refclock termination attribute data
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_DMI_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_dmi_refclock_term),
             "Error from FAPI_ATTR_GET (ATTR_CEN_DMI_REFCLOCK_RCVR_TERM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_DDR_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_ddr_refclock_term),
             "Error from FAPI_ATTR_GET (ATTR_CEN_DDR_REFCLOCK_RCVR_TERM)");
    l_fsi_gp4_data.insertFromRight<8, 2>(l_dmi_refclock_term & 0x3);
    l_fsi_gp4_data.insertFromRight<10, 2>(l_ddr_refclock_term & 0x3);
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP4, l_fsi_gp4_data),
             "Error from putCfamRegister (CFAM_FSI_GP4, init)");

    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP5, CFAM_FSI_GP5_RESET_DATA),
             "Error from putCfamRegister (CFAM_FSI_GP5, init)");
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP6, CFAM_FSI_GP6_RESET_DATA),
             "Error from putCfamRegister (CFAM_FSI_GP6, init)");
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP7, CFAM_FSI_GP7_RESET_DATA),
             "Error from putCfamRegister (CFAM_FSI_GP7, init)");

    // initialze Pervasive GP3 register
    FAPI_DBG("Initialize Pervasive GP3 Register");
    FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (PERV_GP3, init");

    // drop fences, check VDD
    FAPI_DBG("Drop VDD2VIO fence");
    l_fsi_gp3_data.clearBit<27>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3, drop VDD2VIO fence)");

    FAPI_DBG("Drop FSI Fence2");
    l_fsi_gp3_data.clearBit<23>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3, drop FSI Fence2)");

    FAPI_DBG("Check VDD indicator");
    FAPI_TRY(fapi2::getCfamRegister(i_target, FSI2PIB_STATUS, l_cfam_status_data),
             "Error from getCfamRegister (FSI2PIB_STATUS)");
    FAPI_ASSERT(l_cfam_status_data.getBit<16>(),
                fapi2::CEN_TP_CHIPLET_INIT1_VDD_SENSE_ERR().
                set_TARGET(i_target),
                "FSI Status indicates VDD power is OFF!");

    FAPI_DBG("Set PLL output enable");
    l_fsi_gp3_data.setBit<29>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3, set PLL output enable");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EC_FEATURE_SWITCH_DIV24_RUN_MODE, i_target, l_div24_run_mode),
             "Error from FAPI_ATTR_GET (ATTR_CEN_EC_FEATURE_SWITCH_DIV24_RUN_MODE)");

    if (l_div24_run_mode)
    {
        FAPI_DBG("Switch DIV24 into run mode");
        l_fsi_gp4_data.clearBit<16>();
        FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP4, l_fsi_gp4_data),
                 "Error from putCfamRegister (CFAM_FSI_GP4, DIV24 run mode)");
    }

    FAPI_DBG("Release Pervasive Chiplet endpoint reset");
    l_perv_gp3_data.clearBit<1>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (PERV_GP3, release endpoint reset");

    FAPI_DBG("Set PLL test enable");
    l_fsi_gp4_data.setBit<24>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP4, l_fsi_gp4_data),
             "Error from putCfamRegister (CFAM_FSI_GP4, PLL test enable)");

    FAPI_DBG("Assert Pervasive Chiplet endpoint reset");
    l_perv_gp3_data.setBit<1>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (PERV_GP3, set endpoint reset");

    FAPI_DBG("Start VITL clocks in Pervasive Chiplet");
    l_perv_gp3_data.clearBit<16>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (PERV_GP3, start VITL clocks");

    FAPI_DBG("Release Pervasive Chiplet endpoint reset");
    l_perv_gp3_data.clearBit<1>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (PERV_GP3, release endpoint reset");

    FAPI_DBG("Release PCB reset");
    l_fsi_gp3_data.clearBit<22>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3, release PCB reset");

    FAPI_DBG("Set Pervasive Chiplet enable");
    l_perv_gp3_data.setBit<0>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (PERV_GP3, chiplet enable");

    FAPI_DBG("Drop FSI Fence4");
    l_fsi_gp3_data.clearBit<25>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3, drop FSI Fence4)");

    FAPI_DBG("Drop Pervasive Chiplet fence");
    l_perv_gp3_data.clearBit<18>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (PERV_GP3, drop chiplet fence");

    FAPI_DBG("Drop FSI Fence3");
    l_fsi_gp3_data.clearBit<24>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CFAM_FSI_GP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CFAM_FSI_GP3, drop FSI Fence3)");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
