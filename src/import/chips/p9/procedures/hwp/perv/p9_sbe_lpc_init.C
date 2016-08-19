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

fapi2::ReturnCode p9_sbe_lpc_init(const
                                  fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{

    const uint64_t C_OADRNB_ADDR = 0x00400000F0000C90ull;
    // bits 0:31 are the starting byte address of flash locations directly accessible by the second interface. Must be a multiple of the size of the address rangei
    // I have 0xF0000000 since we expect the PNOR address window to be from 0xFXXXXXXX (FW ops) and LPC IO ops from 0xDXXXXXXX
    // This makes the "direct accessible address range" to 0xC000000  to  0xFFFFFFF because of he 64MB size
    const uint64_t C_OADRNB_DATA = 0x0C00000000000000ull;
    const uint64_t C_OADRNS_ADDR = 0x00400000F0000C94ull;
    // bits 27:31 are the OPB window size this should be a multiple of the ECC granule if ECC is enbled and the large erase block size
    // Currently I have this set to be 64 MB
    const uint64_t C_OADRNS_DATA = 0x000000000000000Full;
    const uint64_t C_ADRCBF_ADDR = 0x00400000F0000C80ull;
    // bits 0:31 are the starting byte address of flash locations accessble by the first interface. Must be a multiple of the size of the address range accessible by the first interface.
    // I have 0xF0000000 since we expect the PNOR address window to be from 0xFXXXXXXX (FW ops) and LPC IO ops from 0xDXXXXXXX
    // This makes the "direct accessible address range" to 0xC000000  to  0xFFFFFFF because of the 64MB size
    const uint64_t C_ADRCBF_DATA = 0x0C00000000000000ull;
    const uint64_t C_ADRCMF_ADDR = 0x00400000F0000C84ull;
    // bits 27:31 are the size of the first interfaces flash allocation
    // Currently I have this set to be 64 MB
    const uint64_t C_ADRCMF_DATA = 0x000000000000000Full;
    const uint64_t C_CONF_ADDR = 0x00400000F0000C10ull;
    // Set the direct access cache disable bit (bit 30)
    const uint64_t C_CONF_DATA = 0x0000000200000000ull;
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("p9_sbe_lpc_init: Entering ...");

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

    //Settting registers to do an LPC functional reset
    l_data64.flush<0>().setBit<CPLT_CONF1_TC_LP_RESET>();
    FAPI_TRY(fapi2::putScom(i_target_chip, PERV_N3_CPLT_CONF1_OR, l_data64));
    FAPI_TRY(fapi2::putScom(i_target_chip, PERV_N3_CPLT_CONF1_CLEAR, l_data64));

    //Sets the register OADRNB (0x90) of the nore flash master (sets a base address for direct access)
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, C_OADRNB_ADDR), "Error setting the OADRNB address");
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, C_OADRNB_DATA), "Error setting the OADRNB data");
    //Sets the register OADRNS (0x94) of the flash master (window size setting)
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, C_OADRNS_ADDR), "Error setting the OADRNS address");
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, C_OADRNS_DATA), "Error setting the OADRNS data");
    //Sets the ADRCBF (0x80) of the nor flash master (NOR Address offset)
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, C_ADRCBF_ADDR), "Error setting the ADRCBF address");
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, C_ADRCBF_DATA), "Error setting the ADRCBF data");
    //Sets the register ADRCMF (0x84) of the nor flash master (size setting)
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, C_ADRCMF_ADDR), "Error setting the ADRCMF address");
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, C_ADRCMF_DATA), "Error setting the ADRCMF data");
    //Sets the register CONF(0x10) of the nor flash master (direct access)
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_CMD_REG, C_CONF_ADDR), "Error setting the CONF address");
    FAPI_TRY(fapi2::putScom(i_target_chip, PU_LPC_DATA_REG, C_CONF_DATA), "Error setting the CONF data");


    FAPI_DBG("p9_sbe_lpc_init: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
