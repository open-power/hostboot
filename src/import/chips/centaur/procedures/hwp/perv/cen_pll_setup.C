/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_pll_setup.C $ */
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
/// @file cen_pll_setup.C
/// @brief Centaur PLL setup (FAPI2)
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
#include <cen_pll_setup.H>
#include <cen_gen_scom_addresses.H>
#include <centaur_misc_constants.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_pll_setup(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint32_t> l_cfam_status_data = 0;
    fapi2::buffer<uint32_t> l_fsi_gp3_data = 0;
    fapi2::buffer<uint32_t> l_fsi_gp4_data = 0;
    fapi2::buffer<uint32_t> l_perv_gp3_data = 0;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    bool l_poll_succeed = false;

    FAPI_DBG("Reset PLL test enable");
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4_data),
             "Error from getCfamRegister (CEN_FSIGP4)");
    l_fsi_gp4_data.clearBit<24>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4_data),
             "Error from putCfamRegister (CEN_FSIGP4)");

    FAPI_DBG( "PLL Leave Reset State" );
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP3, l_fsi_gp3_data),
             "Error from getCfamRegister (CEN_FSIGP3)");
    l_fsi_gp3_data.clearBit<28>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP3, l_fsi_gp3_data),
             "Error from putCfamRegister (CEN_FSIGP3)");

    FAPI_DBG( "Centaur only: Nest PLL Leave Reset State" );
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4_data),
             "Error from getCfamRegister (CEN_FSIGP4)");
    l_fsi_gp4_data.clearBit<16>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_FSIGP4, l_fsi_gp4_data),
             "Error from putCfamRegister (CEN_FSIGP4)");

    FAPI_DBG( "Drop Nest PLL bypass GP3MIR(5)=0  tp_pllbyp_dc" );
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_PERV_GP3, l_perv_gp3_data),
             "Error from getCfamRegister (CEN_PERV_GP3)");
    l_perv_gp3_data.clearBit<5>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (CEN_PERV_GP3)");

    FAPI_DBG( "Poll FSI2PIB-Status(24) for (nest) pll lock bits." );

    for (uint32_t i = 0; i < MAX_FLUSH_LOOPS; i++)
    {
        FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_STATUS_ROX, l_cfam_status_data),
                 "Error from getCfamRegister (CEN_STATUS_ROX)");

        FAPI_DBG( "Polling... FSI2PIB-Status(24)." );

        if (l_cfam_status_data.getBit<24>())
        {
            l_poll_succeed = true;
            break;
        }

        FAPI_TRY(fapi2::delay(NANO_FLUSH_DELAY, SIM_FLUSH_DELAY));
    }

    FAPI_ASSERT(l_poll_succeed,
                fapi2::CEN_PLL_SETUP_POLL_NEST_PLL_LOCK_TIMEOUT().
                set_TARGET(i_target),
                "NEST PLL LOCK TIMEOUT!");

    // Chiplet Init bring-up MEM PLL

    FAPI_DBG( "Bring-up the MEM PLL" );
    FAPI_DBG( "Drop bypass mode before LOCK (tp_pllmem_bypass_en_dc)." );
    FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_PERV_GP3, l_perv_gp3_data),
             "Error from getCfamRegister (CEN_PERV_GP3)");
    l_perv_gp3_data.clearBit<17>();
    FAPI_TRY(fapi2::putCfamRegister(i_target, CEN_PERV_GP3, l_perv_gp3_data),
             "Error from putCfamRegister (CEN_PERV_GP3)");

    FAPI_DBG( "Poll FSI2PIB-Status(25) for (mem) pll lock bits." );
    l_poll_succeed = false;

    for (uint32_t i = 0; i < MAX_FLUSH_LOOPS; i++)
    {
        FAPI_TRY(fapi2::getCfamRegister(i_target, CEN_STATUS_ROX, l_cfam_status_data),
                 "Error from getCfamRegister (CEN_STATUS_ROX)");

        FAPI_DBG( "Polling... FSI2PIB-Status(25)." );

        if (l_cfam_status_data.getBit<25>())
        {
            l_poll_succeed = true;
            break;
        }

        FAPI_TRY(fapi2::delay(NANO_FLUSH_DELAY, SIM_FLUSH_DELAY));
    }

    FAPI_ASSERT(l_poll_succeed,
                fapi2::CEN_PLL_SETUP_POLL_MEM_PLL_LOCK_TIMEOUT().
                set_TARGET(i_target),
                "MEM PLL LOCK TIMEOUT!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
