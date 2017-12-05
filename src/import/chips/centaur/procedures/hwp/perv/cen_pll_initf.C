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
#include <cen_ringId.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_pll_initf(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_CEN_MSS_FREQ_Type l_mem_freq;
    fapi2::ATTR_FREQ_MCA_MHZ_Type l_nest_freq;
    RingId_t l_tp_pll_bndy_ring_id;

    // retreive attributes definining NEST/DMI and MEM PLL frequencies
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MCA_MHZ,
                           FAPI_SYSTEM,
                           l_nest_freq),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_MCA_MHZ)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ,
                           i_target,
                           l_mem_freq),
             "Error from FAPI_ATTR_GET (ATTR_CEN_MSS_FREQ)");

    if ((l_nest_freq == 2000) && (l_mem_freq == 1066))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_1;
    }
    else if ((l_nest_freq == 2000) && (l_mem_freq == 1333))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_2;
    }
    else if ((l_nest_freq == 2000) && (l_mem_freq == 1600))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_3;
    }
    else if ((l_nest_freq == 2000) && (l_mem_freq == 1866))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_4;
    }
    else if ((l_nest_freq == 2400) && (l_mem_freq == 1066))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_5;
    }
    else if ((l_nest_freq == 2400) && (l_mem_freq == 1333))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_6;
    }
    else if ((l_nest_freq == 2400) && (l_mem_freq == 1600))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_7;
    }
    else if ((l_nest_freq == 2400) && (l_mem_freq == 1866))
    {
        l_tp_pll_bndy_ring_id = tp_pll_bndy_bucket_8;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_PLL_INITF_UNSUPPORTED_FREQUENCY().
                    set_TARGET(i_target).
                    set_NEST_FREQ(l_nest_freq).
                    set_MEM_FREQ(l_mem_freq),
                    "Unsupported NEST/MEM frequency combination!");
    }

    // scan init PLL GPTR/FUNC chains
    FAPI_TRY(fapi2::putRing(i_target, tp_pll_gptr),
             "Error from putRing (tp_pll_gptr)");
    FAPI_TRY(fapi2::putRing(i_target, tp_pll_func),
             "Error from putRing (tp_pll_func)");

    // scan init PLL bndy chain
    FAPI_TRY(fapi2::putRing(i_target, l_tp_pll_bndy_ring_id),
             "Error from putRing (tp_pll_bndy, 0x%02X)",
             l_tp_pll_bndy_ring_id);

    // issue setpulse
    {
        fapi2::buffer<uint64_t> l_clk_region = 0;
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
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
