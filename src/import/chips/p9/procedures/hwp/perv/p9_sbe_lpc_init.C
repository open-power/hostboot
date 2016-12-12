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

fapi2::ReturnCode p9_sbe_lpc_init(const
                                  fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
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

    if ((l_use_gpio != 0) && (l_is_fsp == fapi2::ENUM_ATTR_IS_SP_MODE_FSP))
    {
        //LPC Reset active
        l_data64.flush<1>().clearBit<0>();
        FAPI_TRY(fapi2::putScom(i_target_chip, PU_GPIO_OUTPUT_SCOM2, l_data64));

        //Set GPI0 output enable
        FAPI_TRY(fapi2::getScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));
        l_data64.setBit<PU_GPIO_OUTPUT_EN_DO_EN_0>();
        FAPI_TRY(fapi2::putScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));
    }

    //Settting registers to do an LPC functional reset
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

    if ((l_use_gpio != 0) && (l_is_fsp == fapi2::ENUM_ATTR_IS_SP_MODE_FSP))
    {
        //LPC Reset Disabled
        l_data64.flush<0>().setBit<0>();
        FAPI_TRY(fapi2::putScom(i_target_chip, PU_GPIO_OUTPUT_SCOM1, l_data64));

        //Unset GPIO output enable
        FAPI_TRY(fapi2::getScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));
        l_data64.clearBit<PU_GPIO_OUTPUT_EN_DO_EN_0>();
        FAPI_TRY(fapi2::putScom(i_target_chip, PU_GPIO_OUTPUT_EN, l_data64));
    }

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
