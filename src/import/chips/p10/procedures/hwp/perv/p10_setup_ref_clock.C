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
#include "p9_perv_scom_addresses.H"
#include "p9_perv_scom_addresses_fld.H"

enum P10_SETUP_REF_CLOCK_Private_Constants
{
    RCS_CONTRL_DC_CFAM_RESET_VAL = 0x0200004,
    TP_MUX0A_CLKIN_SEL = 0,
    TP_MUX0B_CLKIN_SEL = 1,
    TP_MUX0C_CLKIN_SEL = 2,
    TP_MUX0C_CLKIN_SEL_LENGTH = 2,
    TP_MUX0D_CLKIN_SEL = 4,

    TP_MUX10_CLKIN_SEL = 6,

    TP_MUX11_CLKIN_SEL = 7,

    TP_MUX12_CLKIN_SEL = 8,
    TP_MUX12_CLKIN_SEL_LENGTH = 2,

    TP_MUX13_CLKIN_SEL = 10,
    TP_MUX13_CLKIN_SEL_LENGTH = 2,

    TP_MUX14_CLKIN_SEL = 12,

    TP_MUX23_CLKIN_SEL = 14,
    TP_MUX23_CLKIN_SEL_LENGTH = 2,

    TP_TOD_MUX_CLKIN_SEL = 16,

    TP_MUX1_CLKIN_SEL = 20,

    TP_MUX2A_CLKIN_SEL = 21,
    TP_MUX2B_CLKIN_SEL = 22,

    TP_MUX3_CLKIN_SEL = 23,

    TP_MUX4A_CLKIN_SEL = 24,

    TP_CLKGLM_NEST_ASYNC_RESET = 25,

    TP_PLL_FORCE_OUT = 29,
};

fapi2::ReturnCode p10_setup_ref_clock(const
                                      fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint32_t> l_read_reg;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t l_cp_term, l_io_term, l_cp_refclck_select ;
    fapi2::buffer<uint8_t> l_attr_mux0_rcs_pll, l_attr_mux_dpll, l_attr_mux_omi_lcpll, l_attr_mux_input,
          l_attr_clock_pll_mux_tod;

    FAPI_INF("p10_setup_ref_clock: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_cp_term),
             "Error from FAPI_ATTR_GET (ATTR_CP_REFCLOCK_RCVR_TERM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_REFCLOCK_RCVR_TERM, FAPI_SYSTEM, l_io_term),
             "Error from FAPI_ATTR_GET (ATTR_IO_REFCLOCK_RCVR_TERM)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_REFCLOCK_SELECT, i_target_chip, l_cp_refclck_select),
             "Error from FAPI_ATTR_GET (ATTR_CP_REFCLOCK_SELECT)");

    FAPI_DBG("Disable Write Protection for Root/Perv Control registers");
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_GPWRP_FSI, p10SetupRefClock::DISABLE_WRITE_PROTECTION));

    FAPI_DBG("Assert PERST#");
    l_read_reg.flush<0>().setBit<26>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL1_CLEAR_FSI, l_read_reg));

    // -----------------------------------------------------------------------------------
    // ROOT CONTROL 5 and its COPY
    // -----------------------------------------------------------------------------------

    FAPI_DBG("Set RCS control signals to CFAM reset values");
    l_read_reg.flush<0>();
    l_read_reg.setBit<0>();  // RCS_RESET = 1
    l_read_reg.setBit<1>();  // RCS_BYPASS = 1

    if ( (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_OSC1) ||
         (l_cp_refclck_select == fapi2::ENUM_ATTR_CP_REFCLOCK_SELECT_BOTH_OSC1))
    {
        l_read_reg.setBit<2>(); //RCS_BYPASS_CLKSEL = 1
    }

    l_read_reg.insertFromRight<4, 28>(RCS_CONTRL_DC_CFAM_RESET_VAL);

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL5_FSI, l_read_reg));
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL5_COPY_FSI, l_read_reg));

    // -----------------------------------------------------------------------------------
    // ROOT CONTROL 6 and its COPY
    // -----------------------------------------------------------------------------------

    FAPI_DBG("Setup receiver termination");
    l_read_reg.flush<0>();
    l_read_reg.insertFromRight<PERV_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC,
                               PERV_ROOT_CTRL6_TP_PLLREFCLK_RCVR_TERM_DC_LEN>(l_cp_term);
    l_read_reg.insertFromRight<PERV_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC,
                               PERV_ROOT_CTRL6_TP_PCIREFCLK_RCVR_TERM_DC_LEN>(l_io_term);

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL6_FSI, l_read_reg));
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL6_COPY_FSI, l_read_reg));

    // -----------------------------------------------------------------------------------
    // ROOT CONTROL 4 and its COPY
    // -----------------------------------------------------------------------------------

    FAPI_DBG("Setup clocking");
    l_read_reg.flush<0>();

    // RC4 bits 0:4
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0A_RCS_PLL_INPUT, i_target_chip, l_attr_mux0_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0A_RCS_PLL)");
    l_read_reg.writeBit<TP_MUX0A_CLKIN_SEL>(l_attr_mux0_rcs_pll.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0B_RCS_PLL_INPUT, i_target_chip, l_attr_mux0_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0B_RCS_PLL)");
    l_read_reg.writeBit<TP_MUX0B_CLKIN_SEL>(l_attr_mux0_rcs_pll.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0C_RCS_PLL_INPUT, i_target_chip, l_attr_mux0_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0C_RCS_PLL)");
    l_read_reg.insertFromRight< TP_MUX0C_CLKIN_SEL,
                                TP_MUX0C_CLKIN_SEL_LENGTH >(l_attr_mux0_rcs_pll);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX0D_RCS_PLL_INPUT, i_target_chip, l_attr_mux0_rcs_pll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX0D_RCS_PLL)");
    l_read_reg.writeBit<TP_MUX0D_CLKIN_SEL>(l_attr_mux0_rcs_pll.getBit<7>());

    // RC4 bit 6
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX10_PAU_DPLL_INPUT, i_target_chip, l_attr_mux_dpll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX10_PAU_DPLL_INPUT)");

    l_read_reg.writeBit<TP_MUX10_CLKIN_SEL>(l_attr_mux_dpll.getBit<7>());

    // RC4 bit 7
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX11_NEST_DPLL_INPUT, i_target_chip, l_attr_mux_dpll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX11_NEST_DPLL_INPUT)");

    l_read_reg.writeBit<TP_MUX11_CLKIN_SEL>(l_attr_mux_dpll.getBit<7>());

    // RC4 bits 8:9
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX12_OMI_LCPLL_INPUT, i_target_chip, l_attr_mux_omi_lcpll),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX12_OMI_LCPLL_INPUT)");

    l_read_reg.insertFromRight< TP_MUX12_CLKIN_SEL,
                                TP_MUX12_CLKIN_SEL_LENGTH >(l_attr_mux_omi_lcpll);

    // RC4 bits 10:11
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX13_OPT_133_SOURCE_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX13_OPT_133_SOURCE_INPUT)");

    l_read_reg.insertFromRight< TP_MUX13_CLKIN_SEL,
                                TP_MUX13_CLKIN_SEL_LENGTH >(l_attr_mux_input);

    // RC4 bit 12
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX14_OPT_156_SOURCE_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX14_OPT_156_SOURCE_INPUT)");

    l_read_reg.writeBit<TP_MUX14_CLKIN_SEL>(l_attr_mux_input.getBit<7>());

    // RC4 bits 14:15
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX23_PCI_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX23_PCI_INPUT)");

    l_read_reg.insertFromRight< TP_MUX23_CLKIN_SEL,
                                TP_MUX23_CLKIN_SEL_LENGTH >(l_attr_mux_input);

    // RC4 bit 16
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_PLL_MUX_TOD, i_target_chip, l_attr_clock_pll_mux_tod),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_PLL_MUX_TOD)");

    l_read_reg.writeBit<TP_TOD_MUX_CLKIN_SEL>(l_attr_clock_pll_mux_tod.getBit<7>());

    // RC4 bits 20:24
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX1_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX1_INPUT)");

    l_read_reg.writeBit<TP_MUX1_CLKIN_SEL>(l_attr_mux_input.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX2A_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX2A_INPUT)");

    l_read_reg.writeBit<TP_MUX2A_CLKIN_SEL>(l_attr_mux_input.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX2B_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX2B_INPUT)");

    l_read_reg.writeBit<TP_MUX2B_CLKIN_SEL>(l_attr_mux_input.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX3_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX3_INPUT)");

    l_read_reg.writeBit<TP_MUX3_CLKIN_SEL>(l_attr_mux_input.getBit<7>());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX4A_INPUT, i_target_chip, l_attr_mux_input),
             "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX4A_INPUT)");

    l_read_reg.writeBit<TP_MUX4A_CLKIN_SEL>(l_attr_mux_input.getBit<7>());

    l_read_reg.setBit<TP_CLKGLM_NEST_ASYNC_RESET>();
    l_read_reg.setBit<TP_PLL_FORCE_OUT>();

    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL4_FSI, l_read_reg));
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_ROOT_CTRL4_COPY_FSI, l_read_reg));

    FAPI_INF("p10_setup_ref_clock: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
