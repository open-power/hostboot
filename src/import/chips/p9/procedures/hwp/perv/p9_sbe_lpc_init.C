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
// *HWP HW Owner        : Joachim Fenkes <fenkes@de.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_sbe_lpc_init.H"

#include "p9_perv_scom_addresses.H"
#include "p9_perv_scom_addresses_fld.H"
#include "p9_misc_scom_addresses.H"
#include "p9_misc_scom_addresses_fld.H"

const bool LPC_UTILS_TIMEOUT_FFDC = true;
#include "p9_lpc_utils.H"

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
    fapi2::buffer<uint32_t> l_control;

    //Set register bit 23 lpc_lreset_oe to b'1' and set lpc_lreset_out to b'0' to drive a low reset
    FAPI_TRY(lpc_read(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_control),
             "Error reading the OPB master control register");
    l_control.setBit<LPC_LRESET_OE>().clearBit<LPC_LRESET_OUT>();
    FAPI_TRY(lpc_write(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_control), "Error asserting LPC reset");

    //Give the bus some time to reset
    fapi2::delay(LPC_LRESET_DELAY_NS, LPC_LRESET_DELAY_NS);

    //Clear bit 23 lpc_lreset_oe to stop driving the low reset
    l_control.clearBit<LPC_LRESET_OE>();
    FAPI_TRY(lpc_write(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_control), "Error deasserting LPC reset");

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
    fapi2::buffer<uint32_t> l_data32;
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

    // Set up the LPC timeout settings - OPB master first, in case the LPC HC hangs
    FAPI_TRY(lpc_write(i_target_chip, LPCM_OPB_MASTER_TIMEOUT_REG, LPCM_OPB_MASTER_TIMEOUT_VALUE),
             "Error trying to set up the OPB master timeout");
    FAPI_TRY(lpc_read(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_data32), "Error reading OPB master control register");
    l_data32.setBit<LPCM_OPB_MASTER_CONTROL_REG_TIMEOUT_ENABLE>();
    FAPI_TRY(lpc_write(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_data32), "Error enabling OPB master timeout");

    FAPI_TRY(lpc_write(i_target_chip, LPCM_LPC_MASTER_TIMEOUT_REG, LPCM_LPC_MASTER_TIMEOUT_VALUE),
             "Error trying to set up the LPC host controller timeout");

    //------------------------------------------------------------------------------------------
    //--- STEP 4: Check that everyone is happy
    //------------------------------------------------------------------------------------------
    FAPI_TRY(lpc_read(i_target_chip, LPCM_OPB_MASTER_STATUS_REG, l_data32),
             "Error reading OPB master status register");
    FAPI_ASSERT(0 == (l_data32 & LPCM_OPB_MASTER_STATUS_ERROR_BITS),
                fapi2::LPC_OPB_ERROR().
                set_FFDC_TARGET_CHIP(i_target_chip).
                set_TARGET_CHIP(i_target_chip),
                "The OPB master indicated an error after LPC setup");

    FAPI_DBG("p9_sbe_lpc_init: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
