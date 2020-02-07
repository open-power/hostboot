/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_setup_ref_clock.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
//------------------------------------------------------------------------------
/// @file  p10_setup_ref_clock.C
///
/// @brief Setup the clock termination correctly for system/chip type
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------


#include "p10_setup_ref_clock.H"
#include "p10_scom_perv_0.H"
#include "p10_scom_perv_3.H"
#include "p10_scom_perv_4.H"
#include "p10_scom_perv_7.H"
#include "p10_scom_perv_b.H"
#include "p10_scom_perv_d.H"
#include "p10_scom_perv_e.H"
#include "p10_scom_perv_f.H"

enum P10_SETUP_REF_CLOCK_Private_Constants
{
    NS_DELAY = 10000000, // unit is nano seconds
    SIM_CYCLE_DELAY = 1000, // unit is sim cycles
};

fapi2::ReturnCode p10_setup_ref_clock(const
                                      fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_read_reg;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::buffer<uint8_t> mux0_val;
    uint8_t l_sys0_term, l_sys1_term, l_pci0_term, l_pci1_term, l_cp_refclck_select ;
    fapi2::buffer<uint8_t> l_attr_mux0a_rcs_pll, l_attr_mux0b_rcs_pll, l_attr_mux0c_rcs_pll, l_attr_mux0d_rcs_pll,
          l_attr_mux_dpll, l_attr_mux_omi_lcpll, l_attr_mux_input,
          l_attr_clock_pll_mux_tod;

    FAPI_INF("p10_setup_ref_clock: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS0_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_sys0_term),
             "Error from FAPI_ATTR_GET (ATTR_SYS0_REFCLOCK_RCVR_TERM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYS1_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_sys1_term),
             "Error from FAPI_ATTR_GET (ATTR_SYS1_REFCLOCK_RCVR_TERM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PCI0_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_pci0_term),
             "Error from FAPI_ATTR_GET (ATTR_PCI0_REFCLOCK_RCVR_TERM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PCI1_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_pci1_term),
             "Error from FAPI_ATTR_GET (ATTR_PCI1_REFCLOCK_RCVR_TERM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_REFCLOCK_SELECT, i_target_chip, l_cp_refclck_select),
             "Error from FAPI_ATTR_GET (ATTR_CP_REFCLOCK_SELECT)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0A_RCS_PLL_INPUT, i_target_chip, l_attr_mux0a_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0A_RCS_PLL)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0B_RCS_PLL_INPUT, i_target_chip, l_attr_mux0b_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0B_RCS_PLL)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0C_RCS_PLL_INPUT, i_target_chip, l_attr_mux0c_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0C_RCS_PLL)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0D_RCS_PLL_INPUT, i_target_chip, l_attr_mux0d_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0D_RCS_PLL)");

    FAPI_DBG("Disable Write Protection for Root/Perv Control registers");
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_GPWRP_FSI,
                                    p10SetupRefClock::DISABLE_WRITE_PROTECTION));

    FAPI_DBG("Assert PERST#");
    l_read_reg.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL1_SET_FSI, l_read_reg));

    fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);

    // -----------------------------------------------------------------------------------
    // ROOT CONTROL 5 and its COPY
    // -----------------------------------------------------------------------------------

    FAPI_DBG("Set RCS control signals to CFAM reset values");
    l_read_reg.flush<0>();
    l_read_reg.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC>();  //Bit0 : RCS_RESET = 1
    l_read_reg.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC>();  //Bit1 : RCS_BYPASS = 1

    if ( (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC1) ||
         (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_BOTH_OSC1))
    {
        l_read_reg.setBit<FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC>(); //Bit2 : RCS_BYPASS_CLKSEL = 1
    }

    mux0_val = (l_attr_mux0a_rcs_pll | l_attr_mux0b_rcs_pll | l_attr_mux0c_rcs_pll | l_attr_mux0d_rcs_pll);
    l_read_reg.writeBit<30>(mux0_val & fapi2::ENUM_ATTR_CLOCK_MUX0A_RCS_PLL_INPUT_RCS_SYNC_OUT);
    l_read_reg.writeBit<31>(mux0_val & fapi2::ENUM_ATTR_CLOCK_MUX0A_RCS_PLL_INPUT_RCS_ASYNC_OUT);

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL5_FSI, l_read_reg));
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL5_COPY_FSI, l_read_reg));

    // -----------------------------------------------------------------------------------
    // ROOT CONTROL 6 and its COPY
    // -----------------------------------------------------------------------------------

    FAPI_DBG("Setup receiver termination");
    l_read_reg.flush<0>();
    l_read_reg.insertFromRight<0, 2>(l_sys0_term);
    l_read_reg.insertFromRight<2, 2>(l_sys1_term);
    l_read_reg.insertFromRight<4, 2>(l_pci0_term);
    l_read_reg.insertFromRight<6, 2>(l_pci1_term);

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL6_FSI, l_read_reg));
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL6_COPY_FSI, l_read_reg));

    // -----------------------------------------------------------------------------------
    // ROOT CONTROL 4 and its COPY
    // -----------------------------------------------------------------------------------

    FAPI_DBG("Setup clocking");
    l_read_reg.flush<0>();

    // RC4 bits 0:7
    l_read_reg.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC,
                               FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN>(l_attr_mux0a_rcs_pll);

    l_read_reg.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC,
                               FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN>(l_attr_mux0b_rcs_pll);

    l_read_reg.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC,
                               FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN>(l_attr_mux0c_rcs_pll);

    l_read_reg.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC,
                               FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN>(l_attr_mux0d_rcs_pll);

    // RC4 bit 8
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX10_PAU_DPLL_INPUT, i_target_chip, l_attr_mux_dpll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX10_PAU_DPLL_INPUT)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC>
    (l_attr_mux_dpll.getBit<7>());

    // RC4 bit 9
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX11_NEST_DPLL_INPUT, i_target_chip, l_attr_mux_dpll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX11_NEST_DPLL_INPUT)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC>
    (l_attr_mux_dpll.getBit<7>());

    // RC4 bits 10:11
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX12_OMI_LCPLL_INPUT, i_target_chip, l_attr_mux_omi_lcpll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX12_OMI_LCPLL_INPUT)");

    l_read_reg.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC,
                               FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN>(l_attr_mux_omi_lcpll);

    // RC4 bits 12:13
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX13_OPT_133_SOURCE_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX13_OPT_133_SOURCE_INPUT)");

    l_read_reg.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC,
                               FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN>(l_attr_mux_input);

    // RC4 bit 14
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX14_OPT_156_SOURCE_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX14_OPT_156_SOURCE_INPUT)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC>
    (l_attr_mux_input.getBit<7>());

    // RC4 bits 15:16
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX23_PCI_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX23_PCI_INPUT)");

    l_read_reg.insertFromRight<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC,
                               FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN>(l_attr_mux_input);

    // RC4 bit 17
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_PLL_MUX_TOD, i_target_chip, l_attr_clock_pll_mux_tod),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_PLL_MUX_TOD)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC>
    (l_attr_clock_pll_mux_tod.getBit<7>());

    // RC4 bits 20:24
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX1_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX1_INPUT)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC>
    (l_attr_mux_input.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX2A_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX2A_INPUT)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC>
    (l_attr_mux_input.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX2B_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX2B_INPUT)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC>
    (l_attr_mux_input.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX3_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX3_INPUT)");

    l_read_reg.writeBit<FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC>
    (l_attr_mux_input.getBit<7>());

    // statically set bits 24:26 and 29 to match HW flush state
    // nest mesh needs to start at 1:1 to permit scan of the PLL rings, switch to 2:1
    // will occur in switch_gears
    l_read_reg.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC>();
    l_read_reg.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC>();
    l_read_reg.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC>();
    l_read_reg.setBit<FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC>();

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL4_FSI, l_read_reg));
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_FSI, l_read_reg));

    FAPI_INF("p10_setup_ref_clock: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
