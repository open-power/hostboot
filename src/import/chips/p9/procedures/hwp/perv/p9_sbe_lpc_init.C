/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_lpc_init.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
/// @file  p9_sbe_lpc_init.C
///
/// @brief procedure to initialize LPC to enable communictation to PNOR
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_sbe_lpc_init.H"

#include "p9_perv_scom_addresses.H"
#include "p9_perv_scom_addresses_fld.H"
#include "p9_misc_scom_addresses.H"
#include "p9_misc_scom_addresses_fld.H"

static fapi2::ReturnCode reset_lpc_master(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint64_t> l_data64;

    //Do the functional reset that resets the internal registers
    //Setting registers to do an LPC functional reset
    l_data64.flush<0>().setBit<CPLT_CONF1_TC_LP_RESET>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PERV_N3_CPLT_CONF1_OR, l_data64));

    // set LPC clock mux select to internal clock
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    l_data64.setBit<1>();  //PERV.CPLT_CTRL0.TC_UNIT_SYNCCLK_MUXSEL_DC = 1
    FAPI_TRY(fapi2::putScom(i_target_chip, PERV_TP_CPLT_CTRL0_OR, l_data64));

    // set LPC clock mux select to external clock
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    l_data64.setBit<1>();  //PERV.CPLT_CTRL0.TC_UNIT_SYNCCLK_MUXSEL_DC = 0
    FAPI_TRY(fapi2::putScom(i_target_chip, PERV_TP_CPLT_CTRL0_CLEAR, l_data64));

    //Turn off the LPC functional reset
    l_data64.flush<0>().setBit<CPLT_CONF1_TC_LP_RESET>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PERV_N3_CPLT_CONF1_CLEAR, l_data64));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

static fapi2::ReturnCode reset_lpc_bus_via_master(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_lpcm_opb_master_control_register_data(0);

    //Write to the LPCM OPB Master Control Register (address x'C001 0008')
    l_lpcm_opb_master_control_register_data.setBit<PU_LPC_CMD_REG_RNW>().insertFromRight<PU_LPC_CMD_REG_ADR, PU_LPC_CMD_REG_ADR_LEN>
    (LPCM_OPB_MASTER_CONTROL_REG).insertFromRight<PU_LPC_CMD_REG_SIZE, PU_LPC_CMD_REG_SIZE_LEN>(0x4);
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, l_lpcm_opb_master_control_register_data),
             "Erro writing the LPC_CMD_REG to get the current reset value");
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_LPC_DATA_REG, l_data64), "Error getting the reset value");

    //Set register bit 23 lpc_lreset_oe to b'1' and set lpc_lreset_out to b'0' to drive a low reset
    l_data64.setBit<LPC_LRESET_OE>().clearBit<LPC_LRESET_OUT>();
    l_lpcm_opb_master_control_register_data.clearBit<PU_LPC_CMD_REG_RNW>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, l_lpcm_opb_master_control_register_data),
             "Error writing to the LPC_CMD_REG to set lpc_lreset_oe");
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, l_data64), "Error setting lpc_lreset_oe");

    //Give the bus some time to reset
    fapi2::delay(LPC_LRESET_DELAY_NS, LPC_LRESET_DELAY_NS);

    //Clear bit 23 lpc_lreset_oe to stop driving the low reset
    l_data64.clearBit<LPC_LRESET_OE>();
    l_lpcm_opb_master_control_register_data.clearBit<PU_LPC_CMD_REG_RNW>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, l_lpcm_opb_master_control_register_data),
             "Error writing to the LPC_CMD_REG to clear lpc_lreset_oe");
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, l_data64), "Error clearing lpc_lreset_oe");

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

static fapi2::ReturnCode reset_lpc_bus_via_gpio(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint64_t> l_data64;

    //LPC Reset active
    l_data64.flush<1>().clearBit<0>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_GPIO_OUTPUT_SCOM2, l_data64));

    //Set GPI0 output enable
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));
    l_data64.setBit<PU_GPIO_OUTPUT_EN_DO_EN_0>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));

    //Give the bus some time to reset
    fapi2::delay(LPC_LRESET_DELAY_NS, LPC_LRESET_DELAY_NS);

    //Unset GPIO output enable
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));
    l_data64.clearBit<PU_GPIO_OUTPUT_EN_DO_EN_0>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


fapi2::ReturnCode p9_sbe_lpc_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    const uint64_t C_LPC_TIMEOUT_ADDR = 0x00400000C001202C;
    const uint64_t C_LPC_TIMEOUT_DATA = 0x00000000FE000000;
    const uint64_t C_OPB_TIMEOUT_ADDR = 0x00400000C0010040;
    const uint64_t C_OPB_TIMEOUT_DATA = 0x00000000FFFFFFFE;
    fapi2::buffer<uint64_t> l_data64;
    uint8_t l_use_gpio = 0;
    uint8_t l_is_fsp = 0;
    FAPI_DBG("p9_sbe_lpc_init: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_LPC_RESET_GPIO, i_target_chip, l_use_gpio),
             "Error getting the use_gpio_attr");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SP_MODE, i_target_chip, l_is_fsp), "Error getting ATTR_IS_SP_MODE");

    //------------------------------------------------------------------------------------------
    //--- STEP 1: Functional reset of LPC Master
    //------------------------------------------------------------------------------------------
    FAPI_TRY(reset_lpc_master(i_target_chip));

    //------------------------------------------------------------------------------------------
    //--- STEP 2: Issue an LPC bus reset
    //------------------------------------------------------------------------------------------
    //For DD2 and beyond we want to use the lpc reset that will reset the external LPC Bus attached devices -- this is what was broken in DD1
    if (l_use_gpio == 0)
    {
        FAPI_TRY(reset_lpc_bus_via_master(i_target_chip));
    }
    else if (l_is_fsp == fapi2::ENUM_ATTR_IS_SP_MODE_FSP)
    {
        FAPI_TRY(reset_lpc_bus_via_gpio(i_target_chip));
    }

    //------------------------------------------------------------------------------------------
    //--- STEP 3: Program settings in LPC Master and FPGA
    //------------------------------------------------------------------------------------------

    //Set up the LPC timeout settings
    l_data64 = C_LPC_TIMEOUT_ADDR;
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, l_data64), "Error tring to set LPC timeout address");
    l_data64 = C_LPC_TIMEOUT_DATA;
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, l_data64), "Error trying to set LPC timeout data");
    //Set up the OPB timeout settings
    l_data64 = C_OPB_TIMEOUT_ADDR;
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, l_data64), "Error trying to set OPB timeout address");
    l_data64 = C_OPB_TIMEOUT_DATA;
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, l_data64), "Error trying to set OPB timeout data");

    FAPI_DBG("p9_sbe_lpc_init: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
