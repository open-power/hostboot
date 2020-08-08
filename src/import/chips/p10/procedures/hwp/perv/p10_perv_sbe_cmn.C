/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_perv_sbe_cmn.C $ */
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
/// @file  p10_perv_sbe_cmn.C
///
/// @brief Modules for scan 0 and array init
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : SBE/HB
//------------------------------------------------------------------------------
//
#include <p10_perv_sbe_cmn.H>
#include <p10_scom_perv.H>
#ifndef __PPE_QME
    #include <multicast_group_defs.H>
#endif
#include <target_filters.H>
#include <p10_ringId.H>

enum P10_PERV_SBE_CMN_Private_Constants
{
    NS_DELAY = 100000, // unit in nano seconds
    SIM_CYCLE_DELAY = 1000, // unit in cycles
    CPLT_ALIGN_CHECK_POLL_COUNT = 10, // count to wait for chiplet aligned
    CPLT_OPCG_DONE_DC_POLL_COUNT = 10, // count to wait for chiplet opcg done
    P10_OPCG_DONE_SCAN0_POLL_COUNT = 200, // Scan0 Poll count
    P10_OPCG_DONE_SCAN0_HW_NS_DELAY = 16000, // unit is nano seconds [min : 8k cycles x 4 = 8000/2 x 4 = 16000 x 10(-9) = 16 us
    //                       max : 8k cycles  =  (8000/25) x 10 (-6) = 320 us]
    P10_OPCG_DONE_SCAN0_SIM_CYCLE_DELAY = 800000, // unit is cycles, to match the poll count change ( 10000 * 8 )
    P10_OPCG_DONE_ARRAYINIT_HW_NS_DELAY = 200000, // unit is nano seconds [min : 400k/2 = 200k ns = 200 us
    //                       max : 200k /25 = 8000 us = 8 ms]
    P10_OPCG_DONE_ARRAYINIT_POLL_COUNT = 400, // Arrayinit Poll count
    P10_OPCG_DONE_ARRAYINIT_SIM_CYCLE_DELAY = 1120000, // unit is cycles,to match the poll count change ( 280000 * 4 )
    PLL_LOCK_DELAY_NS = 100000,
    PLL_LOCK_DELAY_CYCLES = 100000,
    PLL_LOCK_DELAY_LOOPS = 50,
};

/// @brief Seeprom array Init Module
/// --ABISTCLK_MUXSEL
/// --ABIST modes
/// --Setup BIST regions
/// --Setup all Clock Regions and Types
/// --Setup:
///    - loopcount
///    - OPCG engine start ABIST
///    - run-N mode
/// --Setup IDLE count
/// --OPCG go
/// --Poll OPCG done bit to check for completeness
/// --Clear:
///    - loopcount
///    - OPCG engine start ABIST
///    - run-N mode
/// --Clear all Clock Regions and Types
/// --Clear ABISTCLK_MUXSEL
/// --Clear BIST register
///
///
///
/// @param[in]     i_target_chiplets           Reference to TARGET_TYPE_PERV target Targets all chiplets
/// @param[in]     i_regions                   select clk regions
/// @param[in]     i_loop_counter              loop count value to set opcg run-N mode
/// @param[in]     i_start_abist_match_value   match setup idle count value
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_array_init_module(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_mcast_target,
        const fapi2::buffer<uint16_t> i_regions,
        const fapi2::buffer<uint64_t> i_loop_counter,
        const fapi2::buffer<uint64_t> i_start_abist_match_value,
        bool i_drop_fences)
{

    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint16_t> l_scan_count;
    fapi2::buffer<uint16_t> l_misr_a_value;
    fapi2::buffer<uint16_t> l_misr_b_value;
    fapi2::buffer<uint16_t> l_regions;
    fapi2::buffer<uint64_t> l_read_reg;
    fapi2::buffer<uint64_t> l_data64;
    int l_timeout = 0;

    FAPI_INF("p10_perv_sbe_cmn_array_init_module: Entering ...");

    i_regions.extractToRight<1, 15>(l_regions);

    // no need to drop Vital fence

    FAPI_DBG("Setup ABISTMUX_SEL");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>()
    .setBit<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL0_WO_OR, l_data64));

    FAPI_DBG("setup ABIST modes , BIST REGIONS:%#018lX", i_regions);
    //Setting BIST register value
    l_data64.flush<0>()
    .clearBit<0>()
    .setBit<BIST_TC_SRAM_ABIST_MODE_DC>()
    .insertFromRight<4, 15>(l_regions);
    FAPI_TRY(fapi2::putScom(i_mcast_target, BIST, l_data64));
    FAPI_DBG("l_data64 value:%#018lX", l_data64);

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    l_data64.flush<0>()
    .insertFromRight<4, 15>(l_regions)
    .setBit<48, 3>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CLK_REGION, l_data64));

    if (i_drop_fences)
    {
        FAPI_DBG("Drop Region fences");
        //Setting CPLT_CTRL1 register value
        l_data64.flush<0>()
        .insertFromRight<4, 15>(l_regions);
        FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL1_WO_CLEAR, l_data64));
    }

    i_start_abist_match_value.extractToRight<0, 12>(l_scan_count);
    i_start_abist_match_value.extractToRight<12, 12>(l_misr_a_value);
    i_start_abist_match_value.extractToRight<24, 12>(l_misr_b_value);

    FAPI_DBG("Setup IDLE count");
    //Setting OPCG_REG1 register value
    FAPI_TRY(fapi2::getScom(i_mcast_target, OPCG_REG1, l_data64));
    l_data64.insertFromRight<OPCG_REG1_SCAN_COUNT, OPCG_REG1_SCAN_COUNT_LEN>(l_scan_count);
    l_data64.insertFromRight<OPCG_REG1_MISR_A_VAL, OPCG_REG1_MISR_A_VAL_LEN>(l_misr_a_value);
    l_data64.insertFromRight<OPCG_REG1_MISR_B_VAL, OPCG_REG1_MISR_B_VAL_LEN>(l_misr_b_value);
    FAPI_TRY(fapi2::putScom(i_mcast_target, OPCG_REG1, l_data64));

    FAPI_DBG("Setup: loopcount , OPCG engine start ABIST, run-N mode, OPCG Go");
    //Setting OPCG_REG0 register value
    l_data64.flush<0>()
    .setBit<OPCG_REG0_RUNN_MODE>()
    .setBit<OPCG_REG0_OPCG_STARTS_BIST>()
    .insertFromRight<OPCG_REG0_LOOP_COUNT, OPCG_REG0_LOOP_COUNT_LEN>((uint64_t)(i_loop_counter))
    .setBit<OPCG_REG0_OPCG_GO>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, OPCG_REG0, l_data64));

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");
    l_timeout = P10_OPCG_DONE_ARRAYINIT_POLL_COUNT;

    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(i_mcast_target, CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();

        if (l_poll_data == 1)
        {
            break;
        }

        fapi2::delay(P10_OPCG_DONE_ARRAYINIT_HW_NS_DELAY,
                     P10_OPCG_DONE_ARRAYINIT_SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_DBG("Loop Count :%d", l_timeout);

    FAPI_ASSERT(l_timeout > 0,
                fapi2::SBE_ARRAYINIT_POLL_THRESHOLD_ERR()
                .set_PERV_CPLT_STAT0(l_data64)
                .set_LOOP_COUNT(l_timeout)
                .set_HW_DELAY(P10_OPCG_DONE_ARRAYINIT_HW_NS_DELAY),
                "ERROR:OPCG DONE BIT NOT SET");

    //Getting CPLT_STAT0 register value
    FAPI_TRY(fapi2::getScom(i_mcast_target, CPLT_STAT0, l_read_reg));

    FAPI_DBG("Checking sram abist done");
    FAPI_ASSERT(l_read_reg.getBit<CPLT_STAT0_ABIST_DONE_DC>() == 1,
                fapi2::SRAM_ABIST_DONE_BIT_ERR()
                .set_PERV_CPLT_STAT(l_read_reg)
                .set_SELECT_SRAM(true),
                "ERROR:SRAM_ABIST_DONE_BIT_NOT_SET");

    FAPI_DBG("Clear OPCG Reg0");
    //Setting OPCG_REG0 register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, OPCG_REG0, 0));

    FAPI_DBG("clear all clock REGIONS and type");
    //Setting CLK_REGION register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, CLK_REGION,  0));

    FAPI_DBG("clear ABISTCLK_MUXSEL");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    l_data64.setBit<CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL0_WO_CLEAR, l_data64));

    FAPI_DBG("clear BIST REGISTER");
    //Setting BIST register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, BIST, 0));

    FAPI_INF("p10_perv_sbe_cmn_array_init_module: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Seeprom scan0 module
/// --Write Clock Region Register
/// --Write Scan Select Register
/// --set OPCG_REG0 register bit 0='0'
/// --set OPCG_REG0 register bit 2 = '1'
/// --Poll OPCG done bit to check for scan0 completeness
/// --clear clock region register
/// --clear scan select register
///
///
/// @param[in]     i_target_chiplets   Reference to TARGET_TYPE_PERV target Targets for all chiplets
/// @param[in]     i_regions           set the clk region
/// @param[in]     i_scan_types        set scan types region
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_scan0_module(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_mcast_target,
        const fapi2::buffer<uint16_t> i_regions,
        const fapi2::buffer<uint16_t> i_scan_types)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint16_t> l_regions;
    fapi2::buffer<uint16_t> l_scan_types;
    fapi2::buffer<uint64_t> l_data64;
    int l_timeout = 0;

    FAPI_INF("p10_perv_sbe_cmn_scan0_module: Entering ...");

    i_regions.extractToRight<1, 15>(l_regions);
    i_scan_types.extractToRight<4, 12>(l_scan_types);

    // no need to raise Vital fence

    FAPI_DBG("Raise region fences for all regions");
    //Setting CPLT_CTRL1 register value
    l_data64.insertFromRight<4, 15>(l_regions);
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL1_WO_OR, l_data64));

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    l_data64.flush<0>()
    .insertFromRight<4, 15>(l_regions)
    .setBit<48, 3>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CLK_REGION, l_data64));

    FAPI_DBG("Write scan select register");
    //Setting SCAN_REGION_TYPE register value
    l_data64.flush<0>()
    .insertFromRight<4, 15>(l_regions)
    .insertFromRight<48, 12>(l_scan_types);
    FAPI_TRY(fapi2::putScom(i_mcast_target, SCAN_REGION_TYPE, l_data64));

    FAPI_DBG("set OPCG_REG0 register bit 0='0' and Trigger Scan0");
    //Setting OPCG_REG0 register value
    l_data64.flush<0>()
    .clearBit<OPCG_REG0_RUNN_MODE>()
    .setBit<OPCG_REG0_RUN_SCAN0>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, OPCG_REG0, l_data64));

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");
    l_timeout = P10_OPCG_DONE_SCAN0_POLL_COUNT;

    //UNTIL CPLT_STAT0.CC_CTRL_OPCG_DONE_DC == 1
    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(i_mcast_target, CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();

        if (l_poll_data == 1)
        {
            break;
        }

        fapi2::delay(P10_OPCG_DONE_SCAN0_HW_NS_DELAY,
                     P10_OPCG_DONE_SCAN0_SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_DBG("Loop Count :%d", l_timeout);

    FAPI_ASSERT(l_timeout > 0,
                fapi2::SBE_SCAN0_DONE_POLL_THRESHOLD_ERR()
                .set_PERV_CPLT_STAT0(l_data64)
                .set_LOOP_COUNT(l_timeout)
                .set_HW_DELAY(P10_OPCG_DONE_SCAN0_HW_NS_DELAY),
                "ERROR:OPCG DONE BIT NOT SET");


    FAPI_DBG("clear all clock REGIONS and type");
    FAPI_TRY(fapi2::putScom(i_mcast_target, CLK_REGION, 0));

    FAPI_DBG("Clear Scan Select Register");
    FAPI_TRY(fapi2::putScom(i_mcast_target, SCAN_REGION_TYPE, 0));

    FAPI_INF("p10_perv_sbe_cmn_scan0_module: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

#ifndef __PPE_QME

/// @brief -- Utility function that can be used to start clocks for a specific input regions
/// -- i_regions is to input regions
///
///
/// @param[in]     i_target        Reference to TARGET_TYPE_PERV target
/// @param[in]     i_clock_cmd     Issue clock controller command (START/STOP)
/// @param[in]     i_startslave    Bit to configure to start Slave
/// @param[in]     i_startmaster   Bit to configure to start Master
/// @param[in]     i_regions       Enable required REGIONS
/// @param[in]     i_clock_types   Clock Types to be selected (SL/NSL/ARY)
/// @param[in]     i_unicast       true if input target is unicast, else its multicast target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_clock_start_stop(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_OR > & i_mcast_target,
        const fapi2::buffer<uint8_t> i_clock_cmd,
        const bool i_startslave,
        const bool i_startmaster,
        const fapi2::buffer<uint64_t> i_regions,
        const fapi2::buffer<uint8_t> i_clock_types)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint64_t> l_sl_clock_status;
    fapi2::buffer<uint64_t> l_nsl_clock_status;
    fapi2::buffer<uint64_t> l_ary_clock_status;
    fapi2::buffer<uint64_t> l_exp_sl_clock_status;
    fapi2::buffer<uint64_t> l_exp_nsl_clock_status;
    fapi2::buffer<uint64_t> l_exp_ary_clock_status;
    fapi2::buffer<uint8_t> l_clk_cmd;
    fapi2::buffer<uint16_t> l_regions;
    fapi2::buffer<uint8_t> l_reg_all;
    bool l_reg_sl = false;
    bool l_reg_nsl = false;
    bool l_reg_ary = false;
    fapi2::buffer<uint64_t> l_data64;
    int l_timeout = 0;

    FAPI_INF("p10_perv_sbe_cmn_clock_start_stop: Entering ...");

    fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST,
          fapi2::MULTICAST_AND > l_mcast_and_target = i_mcast_target;

    i_regions.extractToRight<49, 15>(l_regions);
    i_clock_types.extractToRight<5, 3>(l_reg_all);
    l_reg_sl = i_clock_types.getBit<5>();
    l_reg_nsl = i_clock_types.getBit<6>();
    l_reg_ary = i_clock_types.getBit<7>();

    FAPI_DBG("Exit flush (set flushmode inhibit)");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    l_data64.setBit<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL0_WO_OR, l_data64));

    FAPI_DBG("Clear Scan region type register");
    //Setting SCAN_REGION_TYPE register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, SCAN_REGION_TYPE, 0));

    i_clock_cmd.extractToRight<6, 2>(l_clk_cmd);

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    l_data64.flush<0>()
    .insertFromRight<CLK_REGION_CLOCK_CMD, CLK_REGION_CLOCK_CMD_LEN>(l_clk_cmd)
    .writeBit<CLK_REGION_SLAVE_MODE>(i_startslave)
    .writeBit<CLK_REGION_MASTER_MODE>(i_startmaster)
    .insertFromRight<4, 15>(l_regions)
    .insertFromRight<48, 3>(l_reg_all);
    FAPI_TRY(fapi2::putScom(i_mcast_target, CLK_REGION, l_data64));

    // To wait until OPCG Done - CPLT_STAT0.cc_cplt_opcg_done_dc = 1
    FAPI_DBG("Poll OPCG done bit to check for completeness");
    l_data64.flush<0>();
    l_timeout = CPLT_OPCG_DONE_DC_POLL_COUNT;

    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(l_mcast_and_target, CPLT_STAT0, l_data64));
        bool l_poll_data = l_data64.getBit<CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();

        if (l_poll_data == 1)
        {
            break;
        }

        fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_DBG("Loop Count after CPLT_OPCG_DONE_DC polling:%d", l_timeout);

    FAPI_ASSERT(l_timeout > 0,
                fapi2::CPLT_OPCG_DONE_NOT_SET_ERR()
                .set_PERV_CPLT_STAT0(l_data64)
                .set_LOOP_COUNT(l_timeout)
                .set_HW_DELAY(NS_DELAY),
                "ERROR:CHIPLET OPCG DONE NOT SET AFTER CLOCK START STOP CMD");

    // check clock status SL, NSL, ARY
    if ( !i_startslave && !i_startmaster )
    {
        l_data64.flush<0>().insertFromRight<4, 15>(l_regions);

        if( (l_reg_sl) && (i_clock_cmd == 0b01) )
        {
            FAPI_DBG("Check for clocks running SL");
            //Getting CLOCK_STAT_SL register value uisng MULTICAST_OR target for clock start
            FAPI_TRY(fapi2::getScom(i_mcast_target, CLOCK_STAT_SL, l_sl_clock_status));
            FAPI_DBG("regions value:  %#018lX, sl status: %#018lX", l_data64, l_sl_clock_status);

            FAPI_ASSERT(((l_data64 & l_sl_clock_status) == 0),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(CLOCK_STAT_SL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_sl_clock_status),
                        "CLOCK RUNNING STATUS FOR SL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_nsl) && (i_clock_cmd == 0b01) )
        {
            FAPI_DBG("Check for clocks running NSL");
            //Getting CLOCK_STAT_NSL register value uisng MULTICAST_OR target for clock start
            FAPI_TRY(fapi2::getScom(i_mcast_target, CLOCK_STAT_NSL, l_nsl_clock_status));
            FAPI_DBG("regions value:  %#018lX, nsl status: %#018lX", l_data64, l_nsl_clock_status);

            FAPI_ASSERT(((l_data64 & l_nsl_clock_status) == 0),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(CLOCK_STAT_NSL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_nsl_clock_status),
                        "CLOCK RUNNING STATUS FOR NSL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_ary) && (i_clock_cmd == 0b01) )
        {
            FAPI_DBG("Check for clocks running ARY");
            //Getting CLOCK_STAT_ARY register value uisng MULTICAST_OR target for clock start
            FAPI_TRY(fapi2::getScom(i_mcast_target, CLOCK_STAT_ARY, l_ary_clock_status));
            FAPI_DBG("regions value:  %#018lX, ary status: %#018lX", l_data64, l_ary_clock_status);

            FAPI_ASSERT(((l_data64 & l_ary_clock_status) == 0),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(CLOCK_STAT_ARY)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_ary_clock_status),
                        "CLOCK RUNNING STATUS FOR ARY TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_sl) && (i_clock_cmd == 0b10) )
        {
            FAPI_DBG("Check for clocks stop SL");
            //Getting CLOCK_STAT_SL register value uisng MULTICAST_AND target for clock stop
            FAPI_TRY(fapi2::getScom(l_mcast_and_target, CLOCK_STAT_SL, l_sl_clock_status));
            FAPI_DBG("regions value:  %#018lX, sl status: %#018lX", l_data64, l_sl_clock_status);

            FAPI_ASSERT(((l_data64 & l_sl_clock_status) == l_data64),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(CLOCK_STAT_SL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_sl_clock_status),
                        "CLOCK STOP STATUS FOR SL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_nsl) && (i_clock_cmd == 0b10) )
        {
            FAPI_DBG("Check for clocks stop NSL");
            //Getting CLOCK_STAT_NSL register value uisng MULTICAST_AND target for clock stop
            FAPI_TRY(fapi2::getScom(l_mcast_and_target, CLOCK_STAT_NSL, l_nsl_clock_status));
            FAPI_DBG("regions value:  %#018lX, nsl status: %#018lX", l_data64, l_nsl_clock_status);

            FAPI_ASSERT(((l_data64 & l_nsl_clock_status) == l_data64),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(CLOCK_STAT_NSL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_nsl_clock_status),
                        "CLOCK STOP STATUS FOR NSL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_ary) && (i_clock_cmd == 0b10) )
        {
            FAPI_DBG("Check for clocks stop ARY");
            //Getting CLOCK_STAT_ARY register value uisng MULTICAST_AND target for clock stop
            FAPI_TRY(fapi2::getScom(l_mcast_and_target, CLOCK_STAT_ARY, l_ary_clock_status));
            FAPI_DBG("regions value:  %#018lX, ary status: %#018lX", l_data64, l_ary_clock_status);

            FAPI_ASSERT(((l_data64 & l_ary_clock_status) == l_data64),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(CLOCK_STAT_ARY)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_ary_clock_status),
                        "CLOCK STOP STATUS FOR ARY TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

    }

    FAPI_DBG("Clear clock region");
    FAPI_TRY(fapi2::putScom(i_mcast_target, CLK_REGION, 0));

    FAPI_DBG("Enter flush (clear flushmode inhibit)");
    l_data64.flush<0>().insertFromRight<4, 15>(l_regions);
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL4_WO_CLEAR, l_data64));

    FAPI_INF("p10_perv_sbe_cmn_clock_start_stop: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Setup Hangpulse counter values
///
/// @param[in]     i_target_chiplet     Reference to TARGET_TYPE_PERV_CHIPLET target
/// @param[in]     i_target_parent_chip true if i_base_address is relative to the parent chip of i_target_chiplet
/// @param[in]     i_base_address       base_address on which hangpulse setup is done
/// @param[in]     i_pre_divider        Pre divider value
/// @param[in]     i_hang_pulse_table   Table of hang pulse parameters to set up; the last element must have .last set
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_setup_hangpulse_counters(
    const fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST > & i_target_chiplet,
    const bool i_target_parent_chip,
    const uint32_t i_base_address,
    const uint8_t i_pre_divider,
    const hang_pulse_t* i_hang_pulse_table)
{
    fapi2::buffer<uint64_t> l_data64;
    const hang_pulse_t* l_cur_entry = i_hang_pulse_table;

    FAPI_INF("p10_perv_sbe_cmn_setup_hangpulse_counters: Entering ...");

    auto l_target_chip = i_target_chiplet.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_DBG("Setup the pre_divider values");
    l_data64.flush<0>();
    l_data64.insertFromRight< 0, 8 >(i_pre_divider);

    if (i_target_parent_chip)
    {
        FAPI_TRY(fapi2::putScom(l_target_chip , (i_base_address + 8), l_data64));
    }
    else
    {
        FAPI_TRY(fapi2::putScom(i_target_chiplet , (i_base_address + 8), l_data64));
    }

    while (true)
    {
        l_data64.flush<0>();
        l_data64.insertFromRight< 0, 6 >(l_cur_entry->value);

        if (l_cur_entry->stop_on_xstop)
        {
            l_data64.setBit<6>();
        }

        if (i_target_parent_chip)
        {
            FAPI_TRY(fapi2::putScom(l_target_chip , (i_base_address + l_cur_entry->id), l_data64));
        }
        else
        {
            FAPI_TRY(fapi2::putScom(i_target_chiplet , (i_base_address + l_cur_entry->id), l_data64));
        }

        if (l_cur_entry->last)
        {
            break;
        }

        l_cur_entry++;
    }

    FAPI_INF("p10_perv_sbe_cmn_setup_hangpulse_counters: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Setup Multicast groups for Istep3
///
/// @param[in]     i_target_chip        Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     Group                uint64_t mc group value
/// @param[in]     pgood                ignore PGOOD, honor PGOOD, honor CORE PGOOD
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_setup_multicast_groups(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const mc_setup_t* i_setup_table)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint64_t> present_chiplets, functional_chiplets,
          eqs_with_good_cores_attr, eqs_with_good_cores_reg;
    fapi2::buffer<uint64_t> pgood_cplt_status_masks[NUM_PGOOD_CHOICES];
    bool l_core_pgood_reg_known = false;
    const uint64_t CPLT_MC_MEMBERSHIP = 0xFC00000000000000;
    const uint64_t EQ_CHIPLET_MASK    = 0x00000000FF000000;
    int mc_count[64] = {0} ;
    uint32_t offset = 0;
    const mc_setup_t* l_group = i_setup_table;
    std::vector<fapi2::MulticastGroupMapping> l_group_map;

    FAPI_INF("p10_perv_sbe_cmn_setup_multicast_groups: Entering ...");

    FAPI_DBG("Clear chiplet MC membership (using broadcast)");

    for (int i = 0; i < 4; i++)
    {
        FAPI_TRY(fapi2::putScom(i_target_chip , 0x6F0F0001 + i, CPLT_MC_MEMBERSHIP));
    }

    FAPI_DBG("Clear MC member counts in PCBM");

    for (int i = 0; i < 7; i++)
    {
        FAPI_TRY(fapi2::putScom(i_target_chip , MCAST_GRP_0_SLAVES_REG + i, 0x0));
    }

    FAPI_TRY(p10_perv_sbe_cmn_cplt_status(i_target_chip, fapi2::TARGET_STATE_PRESENT, present_chiplets));
    FAPI_TRY(p10_perv_sbe_cmn_cplt_status(i_target_chip, fapi2::TARGET_STATE_FUNCTIONAL, functional_chiplets));
    FAPI_TRY(p10_perv_sbe_cmn_eqs_with_good_cores(i_target_chip, false, eqs_with_good_cores_attr));

    pgood_cplt_status_masks[IGNORE_PGOOD]          = present_chiplets;
    pgood_cplt_status_masks[HONOR_PGOOD]           = functional_chiplets;
    pgood_cplt_status_masks[HONOR_CORE_PGOOD_ATTR] = (functional_chiplets & ~EQ_CHIPLET_MASK) | eqs_with_good_cores_attr;
    pgood_cplt_status_masks[HONOR_PGOOD_FORCE_EQ]  = functional_chiplets | (present_chiplets & EQ_CHIPLET_MASK);

    while (true)
    {
        if (l_group->pgood_type == HONOR_CORE_PGOOD_REG && !l_core_pgood_reg_known)
        {
            // We calculate this valud only if it is requested since we're doing SCOMs to determine it,
            // and at the beginning of istep 3 the chiplets are not initialized yet so we'd fail horribly
            FAPI_TRY(p10_perv_sbe_cmn_eqs_with_good_cores(i_target_chip, true, eqs_with_good_cores_reg));
            pgood_cplt_status_masks[HONOR_CORE_PGOOD_REG]  = (functional_chiplets & ~EQ_CHIPLET_MASK) | eqs_with_good_cores_reg;
            l_core_pgood_reg_known = true;
        }

        fapi2::buffer<uint64_t> mc_group_members =
            l_group->members & pgood_cplt_status_masks[l_group->pgood_type];

        for (int i = 1; i < 64; i++)
        {
            const uint32_t chiplet_id = i;

            if(mc_group_members.getBit(chiplet_id))
            {
                fapi2::buffer<uint64_t> mc_data = 0;

                offset = mc_count[chiplet_id];
                mc_count[chiplet_id]++;
                FAPI_ASSERT(!(offset > 3),
                            fapi2::MC_GROUP_SETUP_ERR()
                            .set_CHIPLET_ID(chiplet_id),
                            "Error: Chiplet is being added into more than 4 groups");

                // Setting chiplet multicast group registers
                uint32_t mc_address = (chiplet_id << 24) | (MULTICAST_GROUP_1 + offset);
                mc_data.insertFromRight<  3, 3 > (l_group->hw_group);
                mc_data.insertFromRight< 19, 3 > (0xF);
                FAPI_TRY(fapi2::putScom(i_target_chip , mc_address, mc_data));

            }
        }

        l_group_map.push_back((fapi2::MulticastGroupMapping)
        {
            l_group->group, l_group->hw_group
        });

        if (l_group->last)
        {
            break;
        }

        l_group++;
    }

    /* Always map the broadcast group */
    l_group_map.push_back((fapi2::MulticastGroupMapping)
    {
        fapi2::MCGROUP_ALL, 7
    });
#ifndef __HOSTBOOT_MODULE
    FAPI_TRY(fapi2::setMulticastGroupMap(i_target_chip, l_group_map));
#endif

    FAPI_INF("p10_perv_sbe_cmn_setup_multicast_groups: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Query a bitmask representing present / functional chiplets
///
/// @param[in]     i_target_chip        Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     pgood_option         ignore PGOOD, honor PGOOD, honor CORE PGOOD
/// @param[out]    o_cplt_status_mask   returns 64 bit mask value with each chiplet functional status
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_cplt_status(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    fapi2::TargetState i_target_state,
    fapi2::buffer<uint64_t>& o_cplt_status_mask)
{

    fapi2::Target<fapi2::TARGET_TYPE_PERV> l_chiplet ;
    fapi2::buffer<uint64_t> l_data64 = 0;

    auto l_cplts = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(
                       static_cast<fapi2::TargetFilter>(fapi2::TARGET_FILTER_ALL_EQ | fapi2::TARGET_FILTER_TP |
                               fapi2::TARGET_FILTER_ALL_MC  |  fapi2::TARGET_FILTER_ALL_NEST |
                               fapi2::TARGET_FILTER_ALL_PAU |  fapi2::TARGET_FILTER_ALL_PCI  |
                               fapi2::TARGET_FILTER_ALL_IOHS), i_target_state);

    for (auto& targ : l_cplts)
    {
        l_data64.setBit(targ.getChipletNumber());
    }

    o_cplt_status_mask = l_data64;
    return fapi2::FAPI2_RC_SUCCESS;
}

/// @brief Query a bitmask representing EQs with at least one good core
///
/// @param[in]     i_target_chip        Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     i_use_reg_not_attr   If false, look at ATTR_PG; if true, look at CPLT_CTRL2
/// @param[out]    o_cplt_status_mask   returns 64 bit mask value with each chiplet functional status
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_eqs_with_good_cores(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    bool i_use_reg_not_attr,
    fapi2::buffer<uint64_t>& o_cplt_status_mask)
{
    using namespace scomt::perv;

    fapi2::Target<fapi2::TARGET_TYPE_PERV> l_chiplet ;
    fapi2::buffer<uint64_t> l_data64 = 0;
    fapi2::buffer<uint32_t> l_read_attr_pg;

    auto l_cplts = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(
                       static_cast<fapi2::TargetFilter>(fapi2::TARGET_FILTER_ALL_EQ), fapi2::TARGET_STATE_FUNCTIONAL);

    for (auto& targ : l_cplts)
    {
        uint8_t l_good_cores = 0;

        if (i_use_reg_not_attr)
        {
            FAPI_TRY(fapi2::getScom(targ, CPLT_CTRL2_RW, l_data64));
            l_data64.extract<5, 4>(l_good_cores);
        }
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, targ, l_read_attr_pg));
            // ATTR_PG indicates a "good" core with 0b0
            l_read_attr_pg.invert().extract<13, 4>(l_good_cores);
        }

        if (l_good_cores)
        {
            o_cplt_status_mask.setBit(targ.getChipletNumber());
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief --For all chiplets exit flush
/// --For all chiplets enable alignment
/// --For all chiplets disable alignemnt
///
/// @param[in]     i_target_cplt    Reference to TARGET_TYPE_PERV target
/// @return        FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_align_chiplets(const
        fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_COMPARE > & i_mcast_target)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_data64_sync_cnfg;
    int l_timeout = 0;
    FAPI_INF("p10_perv_sbe_cmn_align_chiplets: Entering ...");

    fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST,
          fapi2::MULTICAST_AND > l_mcast_and_target = i_mcast_target;

    FAPI_DBG("For all chiplets: exit flush");
    l_data64.flush<0>();
    l_data64.setBit<CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL0_WO_OR, l_data64));

    FAPI_DBG("For all chiplets: enable alignement");
    l_data64.flush<0>();
    l_data64.setBit<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL0_WO_OR, l_data64));

    FAPI_DBG("Clear chiplet is aligned");
    FAPI_TRY(fapi2::getScom(i_mcast_target, SYNC_CONFIG, l_data64_sync_cnfg));
    l_data64_sync_cnfg.setBit<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, SYNC_CONFIG, l_data64_sync_cnfg));

    FAPI_DBG("Unset Clear chiplet is aligned");
    l_data64_sync_cnfg.clearBit<SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, SYNC_CONFIG, l_data64_sync_cnfg));

    fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");
    l_timeout = CPLT_ALIGN_CHECK_POLL_COUNT;

    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(l_mcast_and_target, CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();

        if (l_poll_data == 1)
        {
            break;
        }

        fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_DBG("Loop Count :%d", l_timeout);

    FAPI_ASSERT(l_timeout > 0,
                fapi2::CPLT_NOT_ALIGNED_ERR()
                .set_PERV_CPLT_STAT0(l_data64)
                .set_LOOP_COUNT(l_timeout)
                .set_HW_DELAY(NS_DELAY),
                "ERROR:CHIPLET NOT ALIGNED");

    FAPI_DBG("For all chiplets: disable alignement");
    l_data64.flush<0>();
    l_data64.setBit<CPLT_CTRL0_CTRL_CC_FORCE_ALIGN>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, CPLT_CTRL0_WO_CLEAR, l_data64));

    FAPI_INF("p10_perv_sbe_cmn_align_chiplets: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief putring call from initf procedures
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     i_ring_table input ring table with list of rings on which putring call
/// @param[in]     i_tp_chiplet true for istep S2 putring calls on Tp chiplet, else false.
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_setup_putring(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const ring_setup_t* i_ring_table,
    bool  i_tp_chiplet)
{
    using namespace scomt;
    using namespace scomt::perv;

    const ring_setup_t* ring;
    fapi2::buffer<uint64_t> l_data64;

    FAPI_DBG("p10_perv_sbe_cmn_setup_putring : Entering");

    auto l_chiplet_targets = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(
                                 static_cast<fapi2::TargetFilter>( fapi2::TARGET_FILTER_ALL_NEST      |
                                         fapi2::TARGET_FILTER_ALL_PCI | fapi2::TARGET_FILTER_ALL_MC   |
                                         fapi2::TARGET_FILTER_ALL_PAU | fapi2::TARGET_FILTER_ALL_IOHS |
                                         fapi2::TARGET_FILTER_ALL_EQ), fapi2::TARGET_STATE_FUNCTIONAL);

    if(i_tp_chiplet)
    {
        l_chiplet_targets = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(
                                static_cast<fapi2::TargetFilter>( fapi2::TARGET_FILTER_TP), fapi2::TARGET_STATE_FUNCTIONAL);
    }

    for (auto& l_cplt_target : l_chiplet_targets)
    {
        uint32_t l_chipletID = l_cplt_target.getChipletNumber();
        FAPI_TRY(fapi2::getScom(l_cplt_target, CPLT_CTRL2_RW, l_data64));

        ring = i_ring_table;

        while(true)
        {
            if((l_chipletID >= ring->min_cplt_id) && (l_chipletID <= ring->max_cplt_id))
            {
                if((ring->pg_bit == IGNORE_PG) || (l_data64.getBit(ring->pg_bit)))
                {
                    FAPI_DBG("Calling putRing on %s, Chiplet ID: %#010lX",
                             ringid_get_ring_name(ring->ring_id), l_chipletID);

                    if(ring->targ == TARGET_CHIP)
                    {
                        FAPI_TRY(fapi2::putRing(i_target_chip, ring->ring_id),
                                 "Error from Putring on %s, ChipletID : %#010lX",
                                 ringid_get_ring_name(ring->ring_id), l_chipletID);
                    }
                    else
                    {
                        FAPI_TRY(fapi2::putRing(l_cplt_target, ring->ring_id),
                                 "Error from Putring on %s, ChipletID : %#010lX",
                                 ringid_get_ring_name(ring->ring_id), l_chipletID);
                    }
                }
            }

            if (ring->last)
            {
                break;
            }

            ring++;
        }
    }

    FAPI_DBG("p10_perv_sbe_cmn_setup_putring : Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief putring call from initf procedures
///
/// @param[in]     i_target     Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     i_group      Multicast group to target
/// @param[in]     i_ring_table Input ring table with list of rings on which putring call
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_setup_putring_multicast(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    const fapi2::MulticastGroup i_group,
    const mc_ring_setup_t* i_ring_table)
{
    using namespace scomt;
    using namespace scomt::perv;

    const mc_ring_setup_t* ring = i_ring_table;

    auto l_mc_target = i_target_chip.getMulticast<fapi2::TARGET_TYPE_PERV>(i_group);

    FAPI_DBG("p10_perv_sbe_cmn_setup_putring_multicast : Entering");

    while(true)
    {
        FAPI_TRY(fapi2::putRing(l_mc_target, ring->ring_id),
                 "Error from Putring on %s",
                 ringid_get_ring_name(ring->ring_id));

        if (ring->last)
        {
            break;
        }

        ring++;
    }

    FAPI_DBG("p10_perv_sbe_cmn_setup_putring_multicast : Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Check if the run is on sim or actual HW
///
/// @param[out]    is_simulation   Returns true if in Simulation, else false
fapi2::ReturnCode p10_perv_sbe_cmn_is_simulation_check(bool& is_simulation)
{
    uint8_t l_attr_is_simulation;

    FAPI_DBG("p10_perv_sbe_cmn_is_simulation_check : Entering");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_attr_is_simulation));

    if (l_attr_is_simulation)
    {
        FAPI_DBG("ATTR_IS_SIMULATION is true, in SIM mode");
        is_simulation = true;
    }
    else
    {
        FAPI_DBG("ATTR_IS_SIMULATION is false, in HW mode");
        is_simulation = false;
    }

    FAPI_DBG("p10_perv_sbe_cmn_is_simulation_check : Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief mux setup
//
/// @param[in]     i_target_chip      Reference to TARGET_TYPE_PROC_CHIP
/// @param[in]     i_mux_setup        mux type to switch the mux settings(FSI2PCB(16), PIB2PCB(18), PCB2PCB(19))
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_switch_mux_scom(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip, mux_type i_mux_setup)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint64_t> l_data64_root_ctrl0;

    FAPI_DBG("p10_perv_sbe_cmn_switch_mux_scom : Entering");

    FAPI_DBG("Raise OOB Mux");
    l_data64_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX>();
    FAPI_TRY(fapi2::putScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_WO_OR, l_data64_root_ctrl0));

    FAPI_DBG("Enabling PCB_RESET");
    l_data64_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_WO_OR, l_data64_root_ctrl0));

    // FSI2PCB (Bit16: 1, Bit18: 0, Bit19: 0)
    // PIB2PCB (Bit16: 0, Bit18: 1, Bit19: 0)
    // PCB2PCB (Bit16: 0, Bit18: 0, Bit19: 1)
    l_data64_root_ctrl0.flush<0>().setBit(i_mux_setup);
    FAPI_TRY(fapi2::putScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_WO_OR, l_data64_root_ctrl0));

    l_data64_root_ctrl0.flush<0>()
    .setBit<16>()
    .setBit<18>()
    .setBit<19>()
    .clearBit(i_mux_setup);
    FAPI_TRY(fapi2::putScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR, l_data64_root_ctrl0));

    FAPI_DBG("Clearing PCB RESET bit in  ROOT_CTRL0_REG");
    l_data64_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR, l_data64_root_ctrl0));

    FAPI_DBG("Drop OOB Mux");
    l_data64_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX>();
    FAPI_TRY(fapi2::putScom(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR, l_data64_root_ctrl0));

    FAPI_DBG("p10_perv_sbe_cmn_switch_mux_scom : Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode p10_perv_sbe_cmn_poll_pll_lock(
    const fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST,
    fapi2::MULTICAST_AND > & i_target,
    const fapi2::buffer<uint64_t> i_bits_to_check,
    fapi2::buffer<uint64_t>& o_read_value)
{
    uint64_t l_timeout = PLL_LOCK_DELAY_LOOPS;

    while (l_timeout)
    {
        FAPI_TRY(fapi2::getScom(i_target, scomt::perv::PLL_LOCK_REG, o_read_value));

        if ((o_read_value & i_bits_to_check) == i_bits_to_check)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }

        l_timeout--;
        fapi2::delay(PLL_LOCK_DELAY_NS, PLL_LOCK_DELAY_CYCLES);
    }

    return fapi2::FAPI2_RC_FALSE;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief mux setup
//
/// @param[in]     i_target_chip      Reference to TARGET_TYPE_PROC_CHIP
/// @param[in]     i_mux_setup        mux type to switch the mux settings(FSI2PCB(16), PIB2PCB(18), PCB2PCB(19))
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_switch_mux_cfam(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip, mux_type i_mux_setup)
{
    using namespace scomt;
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_data32_root_ctrl0;

    FAPI_DBG("p10_perv_sbe_cmn_switch_mux_cfam : Entering");

    FAPI_DBG("Raise OOB Mux");
    l_data32_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI, l_data32_root_ctrl0));

    FAPI_DBG("Enabling PCB_RESET");
    l_data32_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI, l_data32_root_ctrl0));

    // FSI2PCB (Bit16: 1, Bit18: 0, Bit19: 0)
    // PIB2PCB (Bit16: 0, Bit18: 1, Bit19: 0)
    // PCB2PCB (Bit16: 0, Bit18: 0, Bit19: 1)
    l_data32_root_ctrl0.flush<0>().setBit(i_mux_setup);
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI, l_data32_root_ctrl0));

    l_data32_root_ctrl0.flush<0>()
    .setBit<16>()
    .setBit<18>()
    .setBit<19>()
    .clearBit(i_mux_setup);
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, l_data32_root_ctrl0));

    FAPI_DBG("Clearing PCB RESET bit in  ROOT_CTRL0_REG");
    l_data32_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_PCB_RESET_DC>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, l_data32_root_ctrl0));

    FAPI_DBG("Drop OOB Mux");
    l_data32_root_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_ROOT_CTRL0_OOB_MUX>();
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI, l_data32_root_ctrl0));

    FAPI_DBG("p10_perv_sbe_cmn_switch_mux_cfam : Exiting");

fapi_try_exit:
    return fapi2::current_err;
}


#endif
