/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_mem_pll_reset.C $  */
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
//------------------------------------------------------------------------------
/// @file  p9_mem_pll_initf.C
///
/// @brief Reset pll for MC Chiplets
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


//## auto_generated
#include <p9_mem_pll_reset.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>

enum P9_MEM_PLL_RESET_Private_Constants
{
    OPCG_ALIGN_SCAN_RATIO = 0b00000,             // 1:1
    OPCG_ALIGN_INOP_ALIGN = 0b0101,              // 8:1
    OPCG_ALIGN_INOP_WAIT = 0x0,
    OPCG_ALIGN_WAIT_CYCLES = 0x020,
    P9_OPCG_DONE_SCAN0_POLL_COUNT = 200,         // Scan0 Poll count
    P9_OPCG_DONE_SCAN0_HW_NS_DELAY = 16000,      // unit is nano seconds [min : 8k cycles x 4 = 8000/2 x 4 = 16000 x 10(-9) = 16 us
    //                       max : 8k cycles  =  (8000/25) x 10 (-6) = 320 us]
    P9_OPCG_DONE_SCAN0_SIM_CYCLE_DELAY = 800000  // unit is cycles, to match the poll count change ( 10000 * 8 )
};


/// @brief Scan0 PLL bndy ring to prepare for PLL re-initialization
///
/// --Write Clock Region Register
/// --Write Scan Select Register
/// --Set OPCG_REG0 register bit 0='0' / 2='1' to trigger scan0
/// --Poll OPCG done bit to check for scan0 completeness
/// --Clear Clock Region register
/// --Clear Scan Select register
///
/// @param[in] i_target Reference to TARGET_TYPE_PERV
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode
p9_mem_pll_reset_scan0_bndy(const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target)
{
    FAPI_DBG("Entering ...");
    uint8_t l_timeout = P9_OPCG_DONE_SCAN0_POLL_COUNT;
    fapi2::buffer<uint64_t> l_clk_region = 0;
    fapi2::buffer<uint64_t> l_scan_region = 0;
    fapi2::buffer<uint64_t> l_opcg_reg0 = 0;
    fapi2::buffer<uint64_t> l_cplt_stat0 = 0;

    // configure clock region register (region=PLL, all tholds)
    l_clk_region.setBit<PERV_1_SCAN_REGION_TYPE_UNIT10>();
    l_clk_region.setBit<PERV_1_CLK_REGION_SEL_THOLD_SL>();
    l_clk_region.setBit<PERV_1_CLK_REGION_SEL_THOLD_NSL>();
    l_clk_region.setBit<PERV_1_CLK_REGION_SEL_THOLD_ARY>();
    FAPI_TRY(fapi2::putScom(i_target, PERV_CLK_REGION, l_clk_region),
             "Error from putScom (PERV_CLK_REGION)");

    // configure scan region register (region=PLL, type=BNDY)
    l_scan_region.setBit<PERV_1_SCAN_REGION_TYPE_UNIT10>();
    l_scan_region.setBit<PERV_1_SCAN_REGION_TYPE_BNDY>();
    FAPI_TRY(fapi2::putScom(i_target, PERV_SCAN_REGION_TYPE, l_scan_region),
             "Error from putScom (PERV_SCAN_REGION_TYPE)");

    // configure OPCG reg0, trigger scan0
    FAPI_TRY(fapi2::getScom(i_target, PERV_OPCG_REG0, l_opcg_reg0),
             "Error from getScom (PERV_OPCG_REG0), clear RUNN");
    l_opcg_reg0.clearBit<PERV_1_OPCG_REG0_RUNN_MODE>();
    FAPI_TRY(fapi2::putScom(i_target, PERV_OPCG_REG0, l_opcg_reg0),
             "Error from putScom (PERV_OPCG_REG0), clear RUNN");
    l_opcg_reg0.setBit<PERV_1_OPCG_REG0_RUN_SCAN0>();
    FAPI_TRY(fapi2::putScom(i_target, PERV_OPCG_REG0, l_opcg_reg0),
             "Error from putScom (PERV_OPCG_REG0), trigger scan0");

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");

    while (l_timeout != 0)
    {
        FAPI_TRY(fapi2::getScom(i_target, PERV_CPLT_STAT0, l_cplt_stat0),
                 "Error from getScom (PERV_CPLT_STAT0)");

        if (l_cplt_stat0.getBit<PERV_1_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>())
        {
            break;
        }

        fapi2::delay(P9_OPCG_DONE_SCAN0_HW_NS_DELAY,
                     P9_OPCG_DONE_SCAN0_SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_ASSERT(l_timeout > 0,
                fapi2::SBE_SCAN0_DONE_POLL_THRESHOLD_ERR()
                .set_TARGET_CHIPLET(i_target)
                .set_PERV_CPLT_STAT0(l_cplt_stat0)
                .set_LOOP_COUNT(P9_OPCG_DONE_SCAN0_POLL_COUNT)
                .set_HW_DELAY(P9_OPCG_DONE_SCAN0_HW_NS_DELAY),
                "Timeout polling for OPCG_DONE for scan0 flush");

    // cleanup, clear clock region & scan select registers
    FAPI_TRY(fapi2::putScom(i_target, PERV_CLK_REGION, 0x0),
             "Error from putScom (PERV_CLK_REGION), clear");
    FAPI_TRY(fapi2::putScom(i_target, PERV_SCAN_REGION_TYPE, 0x0),
             "Error from putScom (PERV_SCAN_REGION_TYPE), clear");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}


fapi2::ReturnCode p9_mem_pll_reset(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chiplet)
{
    uint8_t l_read_attr = 0;
    fapi2::buffer<uint64_t> l_data64;

    FAPI_INF("Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MC_SYNC_MODE, i_target_chiplet, l_read_attr));

    if ( !l_read_attr )
    {
        for (auto l_chplt_trgt :  i_target_chiplet.getChildren<fapi2::TARGET_TYPE_PERV>
             (fapi2::TARGET_FILTER_ALL_MC, fapi2::TARGET_STATE_FUNCTIONAL))
        {
            //Assert endpoint reset
            FAPI_DBG("Asserting endpoint reset");
            l_data64.flush<0>();
            l_data64.setBit<PERV_1_NET_CTRL0_PCB_EP_RESET>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL0_WOR, l_data64));

            //Move MC PLL into reset state
            FAPI_DBG("Move MC PLL into reset state");
            l_data64.flush<0>();
            l_data64.setBit<PERV_1_NET_CTRL0_PLL_BYPASS>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL0_WOR, l_data64));
            l_data64.flush<0>();
            l_data64.setBit<PERV_1_NET_CTRL0_PLL_RESET>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL0_WOR, l_data64));
            l_data64.flush<0>();
            l_data64.setBit<PERV_1_NET_CTRL0_PLL_TEST_EN>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL0_WOR, l_data64));

            //Assert MEM PDLY and DCC  bypass
            FAPI_DBG("Assert MEM PDLY and DCC bypass");
            l_data64.flush<0>();
            l_data64.setBit<PERV_1_NET_CTRL1_CLK_DCC_BYPASS_EN>();
            l_data64.setBit<PERV_1_NET_CTRL1_CLK_PDLY_BYPASS_EN>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL1_WOR, l_data64));

            //Clear endpoint reset
            FAPI_DBG("Dropping endpoint reset");
            l_data64.flush<1>();
            l_data64.clearBit<PERV_1_NET_CTRL0_PCB_EP_RESET>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL0_WAND, l_data64));

            //Disable listen to sync pulse to MC chiplet, when MEM is not in sync to nest
            FAPI_DBG("Disable listen to sync pulse");
            FAPI_TRY(fapi2::getScom(l_chplt_trgt, PERV_SYNC_CONFIG, l_data64));
            l_data64.setBit<PERV_1_SYNC_CONFIG_LISTEN_TO_PULSE_DIS>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_SYNC_CONFIG, l_data64));

            //Initialize OPCG_ALIGN register
            FAPI_DBG("Initalize OPCG_ALIGN register");
            l_data64.flush<0>();
            l_data64.insertFromRight<PERV_1_OPCG_ALIGN_INOP, PERV_1_OPCG_ALIGN_INOP_LEN>(OPCG_ALIGN_INOP_ALIGN);
            l_data64.insertFromRight<PERV_1_OPCG_ALIGN_INOP_WAIT, PERV_1_OPCG_ALIGN_INOP_WAIT_LEN>(OPCG_ALIGN_INOP_WAIT);
            l_data64.insertFromRight<PERV_1_OPCG_ALIGN_WAIT_CYCLES, PERV_1_OPCG_ALIGN_WAIT_CYCLES_LEN>(OPCG_ALIGN_WAIT_CYCLES);
            l_data64.insertFromRight<PERV_1_OPCG_ALIGN_SCAN_RATIO, PERV_1_OPCG_ALIGN_SCAN_RATIO_LEN>(OPCG_ALIGN_SCAN_RATIO);
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_OPCG_ALIGN, l_data64));

            // scan0 flush PLL boundary ring
            FAPI_DBG("Executing scan0 flush for PLL bndy ring");
            FAPI_TRY(p9_mem_pll_reset_scan0_bndy(l_chplt_trgt),
                     "Error from p9_mem_pll_reset_scan0_bndy");
        }
    }

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
