/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_sbe_lpc_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file  p10_sbe_lpc_init.C
///
/// @brief procedure to initialize LPC to enable communictation to PNOR
//------------------------------------------------------------------------------
// *HWP HW Maintainer : Chris Riedl (cmr@ibm.com)
// *HWP FW Maintainer : Raja Das    (rajadas2@in.ibm.com)
// *HWP Consumed by   : SBE
//------------------------------------------------------------------------------
#include "p10_sbe_lpc_init.H"
#include "p10_scom_proc.H"
#include "p10_lpc_utils.H"

static fapi2::ReturnCode switch_lpc_clock_mux(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    bool use_nest_clock)
{
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_data64;
    l_data64.setBit<TP_TCN1_N1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
    return fapi2::putScom(i_target_chip, use_nest_clock ? TP_TCN1_N1_CPLT_CTRL0_WO_OR
                          : TP_TCN1_N1_CPLT_CTRL0_WO_CLEAR, l_data64);
}

static fapi2::ReturnCode reset_lpc_master(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_data64 = 0;

    //Do the functional reset that resets the internal registers
    //Setting registers to do an LPC functional reset
    PREP_TP_TCN1_N1_CPLT_CONF1_WO_OR(i_target_chip);

    SET_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(l_data64);
    FAPI_TRY(PUT_TP_TCN1_N1_CPLT_CONF1_WO_OR(i_target_chip, l_data64));

    //Turn off the LPC functional reset
    l_data64 = 0;
    PREP_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(i_target_chip);

    SET_TP_TCN1_N1_CPLT_CONF1_C_LP_RESET(l_data64);
    FAPI_TRY(PUT_TP_TCN1_N1_CPLT_CONF1_WO_CLEAR(i_target_chip, l_data64));

fapi_try_exit:
    return fapi2::current_err;
}

static fapi2::ReturnCode reset_lpc_bus_via_master(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const bool i_leave_asserted)
{
    fapi2::buffer<uint32_t> l_control;

    //Set register bit 23 lpc_lreset_oe to b'1' and set lpc_lreset_out to b'0' to drive a low reset
    FAPI_TRY(lpc_read(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_control),
             "Error reading the OPB master control register");
    l_control.setBit<LPC_LRESET_OE>().clearBit<LPC_LRESET_OUT>();
    FAPI_TRY(lpc_write(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_control), "Error asserting LPC reset");

    //Give the bus some time to reset
    fapi2::delay(LPC_LRESET_DELAY_NS, LPC_LRESET_DELAY_NS);

    if (!i_leave_asserted)
    {
        //Clear bit 23 lpc_lreset_oe to stop driving the low reset
        l_control.clearBit<LPC_LRESET_OE>();
        FAPI_TRY(lpc_write(i_target_chip, LPCM_OPB_MASTER_CONTROL_REG, l_control), "Error deasserting LPC reset");

        //Give the bus some time after deassert
        fapi2::delay(LPC_LRESET_DELAY_NS, LPC_LRESET_DELAY_NS);
    }

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode p10_sbe_lpc_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint32_t> l_data32;
    uint8_t l_is_fsp = 0;
    uint8_t l_is_primary_proc = 0;
    FAPI_DBG("p10_sbe_lpc_init: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SP_MODE, i_target_chip, l_is_fsp), "Error getting ATTR_IS_SP_MODE");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target_chip, l_is_primary_proc));

    /* The next two steps have to take place with the nest clock muxed into the LPC clock so all the logic sees its resets */
    FAPI_TRY(switch_lpc_clock_mux(i_target_chip, true));

    //------------------------------------------------------------------------------------------
    //--- STEP 1: Functional reset of LPC Master
    //------------------------------------------------------------------------------------------
    FAPI_TRY(reset_lpc_master(i_target_chip));

    //------------------------------------------------------------------------------------------
    //--- STEP 2: Issue an LPC bus reset
    //------------------------------------------------------------------------------------------
    FAPI_TRY(reset_lpc_bus_via_master(i_target_chip, !l_is_primary_proc));

    /* We can flip the LPC clock back to the external clock input now */
    FAPI_TRY(switch_lpc_clock_mux(i_target_chip, false));

    if (!l_is_primary_proc)
    {
        // On secondary processors, leave the LPC bus in reset and skip initialization
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Sanity check: Is LPC held in reset?
    FAPI_TRY(lpc_read(i_target_chip, LPCM_OPB_MASTER_INTR_IN_REG, l_data32),
             "Error reading OPB master interrupt input register");
    FAPI_ASSERT(!l_data32.getBit<LPCM_OPB_MASTER_INTR_IN_REG_LRESET>(),
                fapi2::LPC_HELD_IN_RESET().set_TARGET_CHIP(i_target_chip),
                "LPC bus is held in reset");

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

    FAPI_DBG("p10_sbe_lpc_init: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
