/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_pll_initf.C $ */
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
/// @file cen_pll_initf.C
/// @brief Centaur PLL initf (FAPI2)
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
#include <cen_pll_initf.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fixes.H>
#include <centaur_misc_constants.H>

#ifndef __HOSTBOOT_MODULE
    #include <centaur_cleanup_pll_scan.H>
    #include <centaur_nest_pll_scan.H>
    #include <centaur_mem_pll_scan.H>
#endif

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_pll_initf(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_clk_region = 0;

#ifndef __HOSTBOOT_MODULE
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ReturnCode l_rc;
    // apply initfiles
    ecmdChipTarget l_ecmd_target;
    fapiTargetToEcmdTarget(i_target, l_ecmd_target);
    ecmdEnableRingCache(l_ecmd_target);
    FAPI_EXEC_HWP(l_rc, centaur_cleanup_pll_scan, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from centaur_cleanup_pll_scan");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    FAPI_EXEC_HWP(l_rc, centaur_mem_pll_scan, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from centaur_mem_pll_scan");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    FAPI_EXEC_HWP(l_rc, centaur_nest_pll_scan, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from centaur_nest_pll_scan");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    ecmdDisableRingCache(l_ecmd_target);
#endif

    // issue setpulse
    l_clk_region.setBit<0, 2>();  // CLOCK_CMD = pulse
    l_clk_region.setBit<4>();     // CLOCK_REGION_PERV
    l_clk_region.setBit<11>();    // CLOCK_REGION_PLL
    l_clk_region.setBit<21>();    // SEL_THOLD_NSL
    FAPI_TRY(fapi2::putScom(i_target, CEN_CLK_REGION_PCB, l_clk_region),
             "Error from putScom (CEN_CLK_REGION_PCB, setpulse)");

    FAPI_TRY(fapi2::delay(0, 10000));

    l_clk_region.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, CEN_CLK_REGION_PCB, l_clk_region),
             "Error from putScom (CEN_CLK_REGION_PCB, clear)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
