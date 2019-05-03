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
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------
//
#include "p10_perv_sbe_cmn.H"
#include "p9_const_common.H"

#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_quad_scom_addresses_fld.H>
#include <p10_hang_pulse_mc_setup_tables.H>
#include <target_filters.H>

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
    P10_OPCG_DONE_ARRAYINIT_SIM_CYCLE_DELAY = 1120000 // unit is cycles,to match the poll count change ( 280000 * 4 )
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
        const fapi2::buffer<uint64_t> i_start_abist_match_value)
{
    fapi2::buffer<uint16_t> l_scan_count;
    fapi2::buffer<uint16_t> l_misr_a_value;
    fapi2::buffer<uint16_t> l_misr_b_value;
    fapi2::buffer<uint16_t> l_regions;
    fapi2::buffer<uint64_t> l_read_reg;
    bool l_abist_check = false;
    fapi2::buffer<uint64_t> l_data64;
    int l_timeout = 0;

    FAPI_INF("p10_perv_sbe_cmn_array_init_module: Entering ...");

    i_regions.extractToRight<1, 15>(l_regions);

    FAPI_DBG("Drop vital fence");
    //Setting CPLT_CTRL1 register value
    l_data64.flush<0>()
    .setBit<C_CPLT_CTRL1_TC_VITL_REGION_FENCE>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL1_CLEAR, l_data64));

    FAPI_DBG("Setup ABISTMUX_SEL");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>()
    .setBit<PERV_1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_DBG("setup ABIST modes , BIST REGIONS:%#018lX", i_regions);
    //Setting BIST register value
    l_data64.flush<0>()
    .clearBit<0>()
    .setBit<PERV_1_BIST_TC_SRAM_ABIST_MODE_DC>()
    .insertFromRight<4, 15>(l_regions);
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_BIST, l_data64));
    FAPI_DBG("l_data64 value:%#018lX", l_data64);

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    l_data64.flush<0>()
    .insertFromRight<4, 15>(l_regions)
    .setBit<48, 3>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CLK_REGION, l_data64));

    FAPI_DBG("Drop Region fences");
    //Setting CPLT_CTRL1 register value
    l_data64.flush<0>()
    .insertFromRight<4, 15>(l_regions);
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL1_CLEAR, l_data64));

    i_start_abist_match_value.extractToRight<0, 12>(l_scan_count);
    i_start_abist_match_value.extractToRight<12, 12>(l_misr_a_value);
    i_start_abist_match_value.extractToRight<24, 12>(l_misr_b_value);

    FAPI_DBG("Setup IDLE count");
    //Setting OPCG_REG1 register value
    FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_OPCG_REG1, l_data64));
    l_data64.insertFromRight<PERV_1_OPCG_REG1_SCAN_COUNT, PERV_1_OPCG_REG1_SCAN_COUNT_LEN>
    (l_scan_count);
    l_data64.insertFromRight<PERV_1_OPCG_REG1_MISR_A_VAL, PERV_1_OPCG_REG1_MISR_A_VAL_LEN>
    (l_misr_a_value);
    l_data64.insertFromRight<PERV_1_OPCG_REG1_MISR_B_VAL, PERV_1_OPCG_REG1_MISR_B_VAL_LEN>
    (l_misr_b_value);
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_OPCG_REG1, l_data64));

    FAPI_DBG("Setup: loopcount , OPCG engine start ABIST, run-N mode, OPCG Go");
    //Setting OPCG_REG0 register value
    l_data64.flush<0>()
    .setBit<PERV_1_OPCG_REG0_RUNN_MODE>()
    .setBit<14>()   //OPCG_REG0.OPCG_STARTS_BIST = 1
    .insertFromRight<PERV_1_OPCG_REG0_LOOP_COUNT, PERV_1_OPCG_REG0_LOOP_COUNT_LEN>((
                uint64_t)(i_loop_counter))
    .setBit<1>();  //OPCG_REG0.OPCG_GO = 1
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_OPCG_REG0, l_data64));

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");
    l_timeout = P10_OPCG_DONE_ARRAYINIT_POLL_COUNT;

    //UNTIL CPLT_STAT0.CC_CTRL_OPCG_DONE_DC == 1
    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<PERV_1_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();  //bool l_poll_data = CPLT_STAT0.CC_CTRL_OPCG_DONE_DC

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
    FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_CPLT_STAT0, l_read_reg));

    FAPI_DBG("Checking sram abist done");
    FAPI_ASSERT(l_read_reg.getBit<0>() == 1,
                fapi2::SRAM_ABIST_DONE_BIT_ERR()
                .set_PERV_CPLT_STAT(l_read_reg)
                .set_SELECT_SRAM(true)
                .set_READ_ABIST_DONE(l_abist_check),
                "ERROR:SRAM_ABIST_DONE_BIT_NOT_SET");

    FAPI_DBG("Clear OPCG Reg0");
    //Setting OPCG_REG0 register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_OPCG_REG0, 0));

    FAPI_DBG("clear all clock REGIONS and type");
    //Setting CLK_REGION register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CLK_REGION,  0));

    FAPI_DBG("clear ABISTCLK_MUXSEL");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_DBG("clear BIST REGISTER");
    //Setting BIST register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_BIST, 0));

    FAPI_INF("p10_perv_sbe_cmn_array_init_module: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Seeprom scan0 module
/// --Raise VITAL clock region fence
/// --Write Clock Region Register
/// --Write Scan Select Register
/// --set OPCG_REG0 register bit 0='0'
/// --set OPCG_REG0 register bit 2 = '1'
/// --Poll OPCG done bit to check for scan0 completeness
/// --clear clock region register
/// --clear scan select register
/// --Drop VITAL fence
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
    fapi2::buffer<uint16_t> l_regions;
    fapi2::buffer<uint16_t> l_scan_types;
    fapi2::buffer<uint64_t> l_data64;
    int l_timeout = 0;

    FAPI_INF("p10_perv_sbe_cmn_scan0_module: Entering ...");

    i_regions.extractToRight<1, 15>(l_regions);
    i_scan_types.extractToRight<4, 12>(l_scan_types);

    FAPI_DBG("raise Vital clock region fence");
    //Setting CPLT_CTRL1 register value
    l_data64.flush<0>()
    .setBit<C_CPLT_CTRL1_TC_VITL_REGION_FENCE>();

    FAPI_DBG("Raise region fences for all regions");
    //Setting CPLT_CTRL1 register value
    l_data64.insertFromRight<4, 15>(l_regions);
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL1_OR, l_data64));

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    l_data64.flush<0>()
    .insertFromRight<4, 15>(l_regions)
    .setBit<48, 3>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CLK_REGION, l_data64));

    FAPI_DBG("Write scan select register");
    //Setting SCAN_REGION_TYPE register value
    l_data64.flush<0>()
    .insertFromRight<4, 15>(l_regions)
    .insertFromRight<48, 12>(l_scan_types);
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_SCAN_REGION_TYPE, l_data64));

    FAPI_DBG("set OPCG_REG0 register bit 0='0' and Trigger Scan0");
    //Setting OPCG_REG0 register value
    l_data64.flush<0>()
    .clearBit<PERV_1_OPCG_REG0_RUNN_MODE>()
    .setBit<PERV_1_OPCG_REG0_RUN_SCAN0>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_OPCG_REG0, l_data64));

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");
    l_timeout = P10_OPCG_DONE_SCAN0_POLL_COUNT;

    //UNTIL CPLT_STAT0.CC_CTRL_OPCG_DONE_DC == 1
    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<PERV_1_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();

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
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CLK_REGION, 0));

    FAPI_DBG("Clear Scan Select Register");
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_SCAN_REGION_TYPE, 0));

    FAPI_INF("p10_perv_sbe_cmn_scan0_module: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

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
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_DBG("Clear Scan region type register");
    //Setting SCAN_REGION_TYPE register value
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_SCAN_REGION_TYPE, 0));

    i_clock_cmd.extractToRight<6, 2>(l_clk_cmd);

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    l_data64.flush<0>()
    .insertFromRight<PERV_1_CLK_REGION_CLOCK_CMD, PERV_1_CLK_REGION_CLOCK_CMD_LEN>
    (l_clk_cmd)  //CLK_REGION.CLOCK_CMD = l_clk_cmd
    .writeBit<PERV_1_CLK_REGION_SLAVE_MODE>(i_startslave)    //CLK_REGION.SLAVE_MODE = i_startslave
    .writeBit<PERV_1_CLK_REGION_MASTER_MODE>(i_startmaster) //CLK_REGION.MASTER_MODE = i_startmaster
    .insertFromRight<4, 15>(l_regions) //CLK_REGION.CLOCK_REGION_ALL_UNITS = l_regions
    .insertFromRight<48, 3>(l_reg_all); //CLK_REGION.SEL_THOLD_ALL = l_reg_all
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CLK_REGION, l_data64));

    // To wait until OPCG Done - CPLT_STAT0.cc_cplt_opcg_done_dc = 1
    FAPI_DBG("Poll OPCG done bit to check for completeness");
    l_data64.flush<0>();
    l_timeout = CPLT_OPCG_DONE_DC_POLL_COUNT;

    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(l_mcast_and_target, PERV_CPLT_STAT0, l_data64));
        bool l_poll_data = l_data64.getBit<PERV_1_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();

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
            FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_CLOCK_STAT_SL, l_sl_clock_status));
            FAPI_DBG("regions value:  %#018lX, sl status: %#018lX", l_data64, l_sl_clock_status);

            FAPI_ASSERT(((l_data64 & l_sl_clock_status) == 0),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_SL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_sl_clock_status),
                        "CLOCK RUNNING STATUS FOR SL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_nsl) && (i_clock_cmd == 0b01) )
        {
            FAPI_DBG("Check for clocks running NSL");
            //Getting CLOCK_STAT_NSL register value uisng MULTICAST_OR target for clock start
            FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_CLOCK_STAT_NSL, l_nsl_clock_status));
            FAPI_DBG("regions value:  %#018lX, nsl status: %#018lX", l_data64, l_nsl_clock_status);

            FAPI_ASSERT(((l_data64 & l_nsl_clock_status) == 0),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_NSL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_nsl_clock_status),
                        "CLOCK RUNNING STATUS FOR NSL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_ary) && (i_clock_cmd == 0b01) )
        {
            FAPI_DBG("Check for clocks running ARY");
            //Getting CLOCK_STAT_ARY register value uisng MULTICAST_OR target for clock start
            FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_CLOCK_STAT_ARY, l_ary_clock_status));
            FAPI_DBG("regions value:  %#018lX, ary status: %#018lX", l_data64, l_ary_clock_status);

            FAPI_ASSERT(((l_data64 & l_ary_clock_status) == 0),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_ARY)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_ary_clock_status),
                        "CLOCK RUNNING STATUS FOR ARY TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_sl) && (i_clock_cmd == 0b10) )
        {
            FAPI_DBG("Check for clocks stop SL");
            //Getting CLOCK_STAT_SL register value uisng MULTICAST_AND target for clock stop
            FAPI_TRY(fapi2::getScom(l_mcast_and_target, PERV_CLOCK_STAT_SL, l_sl_clock_status));
            FAPI_DBG("regions value:  %#018lX, sl status: %#018lX", l_data64, l_sl_clock_status);

            FAPI_ASSERT(((l_data64 & l_sl_clock_status) == l_data64),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_SL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_sl_clock_status),
                        "CLOCK STOP STATUS FOR SL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_nsl) && (i_clock_cmd == 0b10) )
        {
            FAPI_DBG("Check for clocks stop NSL");
            //Getting CLOCK_STAT_NSL register value uisng MULTICAST_AND target for clock stop
            FAPI_TRY(fapi2::getScom(l_mcast_and_target, PERV_CLOCK_STAT_NSL, l_nsl_clock_status));
            FAPI_DBG("regions value:  %#018lX, nsl status: %#018lX", l_data64, l_nsl_clock_status);

            FAPI_ASSERT(((l_data64 & l_nsl_clock_status) == l_data64),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_NSL)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_nsl_clock_status),
                        "CLOCK STOP STATUS FOR NSL TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

        if( (l_reg_ary) && (i_clock_cmd == 0b10) )
        {
            FAPI_DBG("Check for clocks stop ARY");
            //Getting CLOCK_STAT_ARY register value uisng MULTICAST_AND target for clock stop
            FAPI_TRY(fapi2::getScom(l_mcast_and_target, PERV_CLOCK_STAT_ARY, l_ary_clock_status));
            FAPI_DBG("regions value:  %#018lX, ary status: %#018lX", l_data64, l_ary_clock_status);

            FAPI_ASSERT(((l_data64 & l_ary_clock_status) == l_data64),
                        fapi2::THOLD_ERR()
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_ARY)
                        .set_REGIONS(l_data64)
                        .set_READ_CLK(l_ary_clock_status),
                        "CLOCK STOP STATUS FOR ARY TYPE NOT MATCHING WITH EXPECTED REGIONS VALUE");
        }

    }

    FAPI_INF("p10_perv_sbe_cmn_clock_start_stop: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Setup Hangpulse counter values
///
/// @param[in]     i_target_chiplet     Reference to TARGET_TYPE_PERV_CHIPLET target
/// @param[in]     base_address         base_address on which hangpulse setup is done
/// @param[in]     pre_divider
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_setup_hangpulse_counters(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
        const uint32_t base_address,
        const uint8_t pre_divider)
{
    fapi2::buffer<uint64_t> l_data64;
    uint32_t l_chipletID;

    FAPI_INF("p10_perv_sbe_cmn_setup_hangpulse_counters: Entering ...");

    auto l_target_chip = i_target_chiplet.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_DBG("Setup the pre_divider values");
    l_data64.flush<0>();
    l_data64.insertFromRight< 0, 8 >(pre_divider);

    if (base_address == 0x000D0070)
    {
        FAPI_TRY(fapi2::putScom(l_target_chip , (base_address + 8), l_data64));
    }
    else
    {
        FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + 8), l_data64));
    }

    l_chipletID = i_target_chiplet.getChipletNumber();

    switch (l_chipletID)
    {
        case 0x1 :
            if (base_address == 0x000D0070)
            {
                for (auto values : SETUP_HANG_PULSE_FREQ )
                {
                    l_data64.flush<0>();
                    l_data64.insert< 0, 6, 2 >(values[1]);
                    values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                    FAPI_TRY(fapi2::putScom(l_target_chip , (base_address + values[0]), l_data64));
                }
            }
            else
            {
                for (auto values : SETUP_HANG_COUNTERS_PERV )
                {
                    l_data64.flush<0>();
                    l_data64.insert< 0, 6, 2 >(values[1]);
                    values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                    FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));
                }
            }

            break;

        case 0x2 :

            // call SETUP_HANG_COUNTER_N0 table
            for (auto values : SETUP_HANG_COUNTERS_N0 )
            {
                l_data64.flush<0>();
                l_data64.insert< 0, 6, 2 >(values[1]);
                values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));
            }

            break;

        case 0x3 :

            // call SETUP_HANG_COUNTER_N1 table
            for (auto values : SETUP_HANG_COUNTERS_N1 )
            {
                l_data64.flush<0>();
                l_data64.insert< 0, 6, 2 >(values[1]);
                values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));
            }

            break;

        case 0x8 :
        case 0x9 :

            // Call SETUP_HANG_COUNTER_PCI table
            for (auto values : SETUP_HANG_COUNTERS_PCI )
            {
                l_data64.flush<0>();
                l_data64.insert< 0, 6, 2 >(values[1]);
                values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));
            }

            break;

        case 0xC :
        case 0xD :
        case 0xE :
        case 0xF :

            // Call SETUP_HANG_COUNTER_MC table
            for (auto values : SETUP_HANG_COUNTERS_MC )
            {
                l_data64.flush<0>();
                l_data64.insert< 0, 6, 2 >(values[1]);
                values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));
            }

            break;

        case 0x10 :
        case 0x11 :
        case 0x12 :
        case 0x13 :

            // Call SETUP_HANG_COUNTER_PAU table
            for (auto values : SETUP_HANG_COUNTERS_PAU )
            {
                l_data64.flush<0>();
                l_data64.insert< 0, 6, 2 >(values[1]);
                values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));
            }

            break;

        case 0x18 :
        case 0x19 :
        case 0x1A :
        case 0x1B :
        case 0x1C :
        case 0x1D :
        case 0x1E :
        case 0x1F :

            // Call SETUP_HANG_COUNTER_IOHS table
            for (auto values : SETUP_HANG_COUNTERS_IOHS )
            {
                l_data64.flush<0>();
                l_data64.insert< 0, 6, 2 >(values[1]);
                values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));

            }

            break;

        case 0x20 :
        case 0x21 :
        case 0x22 :
        case 0x23 :
        case 0x24 :
        case 0x25 :
        case 0x26 :
        case 0x27 :

            // Call SETUP_HANG_COUNTER_EQ table
            for (auto values : SETUP_HANG_COUNTERS_EQ )
            {
                l_data64.flush<0>();
                l_data64.insert< 0, 6, 2 >(values[1]);
                values[2] ? l_data64.setBit<6>() : l_data64.clearBit<6>() ;
                FAPI_TRY(fapi2::putScom(i_target_chiplet , (base_address + values[0]), l_data64));

            }

            break;

        default :
            FAPI_ERR("Invalid Chiplet_id detected : %#010lX ", l_chipletID);

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
fapi2::ReturnCode p10_perv_sbe_cmn_setup_multicast_groups(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{

    fapi2::buffer<uint64_t> mc_data, ignore_pgood_cplt_status_mask, honor_pgood_cplt_status_mask,
          honor_core_pgood_cplt_status_mask ;
    uint64_t cplt_mc_membership = 0xFC00000000000000;
    int mc_count[64] = {0} ;
    int i;
    uint32_t offset = 0;

    FAPI_INF("p10_perv_sbe_cmn_setup_multicast_groups: Entering ...");

    FAPI_DBG("Clear chiplet MC membership (using broadcast)");
    FAPI_TRY(fapi2::putScom(i_target_chip , 0x6F0F0002, cplt_mc_membership));
    FAPI_TRY(fapi2::putScom(i_target_chip , 0x6F0F0003, cplt_mc_membership));
    FAPI_TRY(fapi2::putScom(i_target_chip , 0x6F0F0004, cplt_mc_membership));

    FAPI_DBG("Clear MC member counts in PCBM");
    FAPI_TRY(fapi2::putScom(i_target_chip , PERV_PIB_MCAST_GRP_1_SLAVES_REG, 0x0));
    FAPI_TRY(fapi2::putScom(i_target_chip , PERV_PIB_MCAST_GRP_2_SLAVES_REG, 0x0));
    FAPI_TRY(fapi2::putScom(i_target_chip , PERV_PIB_MCAST_GRP_3_SLAVES_REG, 0x0));
    FAPI_TRY(fapi2::putScom(i_target_chip , PERV_PIB_MCAST_GRP_4_SLAVES_REG, 0x0));
    FAPI_TRY(fapi2::putScom(i_target_chip , PERV_PIB_MCAST_GRP_5_SLAVES_REG, 0x0));
    FAPI_TRY(fapi2::putScom(i_target_chip , PERV_PIB_MCAST_GRP_6_SLAVES_REG, 0x0));

    FAPI_TRY(p10_perv_sbe_cmn_cplt_status(i_target_chip, ignore_pgood, ignore_pgood_cplt_status_mask));
    FAPI_TRY(p10_perv_sbe_cmn_cplt_status(i_target_chip, honor_pgood, honor_pgood_cplt_status_mask));
    FAPI_TRY(p10_perv_sbe_cmn_cplt_status(i_target_chip, honor_core_pgood, honor_core_pgood_cplt_status_mask));

    for (auto group : MC_GROUPS)
    {
        fapi2::buffer<uint64_t> mc_group_members = group[1];
        fapi2::buffer<uint64_t> mc_group_number = group[0];

        if (group[2] == ignore_pgood) // ignore pgood
        {
            mc_group_members = (mc_group_members & ignore_pgood_cplt_status_mask);
        }
        else if (group[2] == honor_pgood) // honor pgood
        {
            mc_group_members = (mc_group_members & honor_pgood_cplt_status_mask);
        }
        else if (group[2] == honor_core_pgood) // honor core pgood
        {
            mc_group_members = (mc_group_members & honor_core_pgood_cplt_status_mask);
        }
        else
        {
            FAPI_ERR("Invalid Pgood option");
        }

        for ( i = 1; i < 64; i++)
        {
            const uint32_t chiplet_id = i;

            if(mc_group_members.getBit(chiplet_id))
            {
                mc_count[i] = mc_count[i] + 1;
                FAPI_ASSERT(!(mc_count[i] > 3),
                            fapi2::MC_GROUP_SETUP_ERR()
                            .set_CHIPLET_ID(chiplet_id),
                            "Error: Chiplet is being added into more 4 groups");

                offset = mc_count[i];

                // Setting chiplet multicast group registers
                uint32_t mc_address = (chiplet_id << 24) + 0xF0000 + offset;
                mc_data.insert< 3, 3, 61 >(mc_group_number);
                mc_data.insertFromRight< 19, 3 > (0xF);
                FAPI_TRY(fapi2::putScom(i_target_chip , mc_address, mc_data));
            }
        }
    }

    FAPI_INF("p10_perv_sbe_cmn_setup_multicast_groups: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Get chiplet status while setting MC groups
///
/// @param[in]     i_target_chip        Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     pgood_option         ignore PGOOD, honor PGOOD, honor CORE PGOOD
/// @param[out]    o_cplt_status_mask   returns 64 bit mask value with each chiplet functional status
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_perv_sbe_cmn_cplt_status(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        uint64_t pgood_option,
        fapi2::buffer<uint64_t>& o_cplt_status_mask)
{

    fapi2::Target<fapi2::TARGET_TYPE_PERV> l_chiplet ;
    fapi2::buffer<uint32_t> l_read_attr_pg;
    fapi2::buffer<uint64_t> l_data64;
    l_data64.flush<0>();

    FAPI_INF("p10_perv_sbe_cmn_cplt_status: Entering ...");

    // honor_pgoog or honor_core_pgood
    auto l_cplts = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(
                       static_cast<fapi2::TargetFilter>(fapi2::TARGET_FILTER_ALL_EQ | fapi2::TARGET_FILTER_TP |
                               fapi2::TARGET_FILTER_ALL_MC  |  fapi2::TARGET_FILTER_ALL_NEST |
                               fapi2::TARGET_FILTER_ALL_PAU |  fapi2::TARGET_FILTER_ALL_PCI  |
                               fapi2::TARGET_FILTER_ALL_IOHS), fapi2::TARGET_STATE_FUNCTIONAL);

    if(pgood_option == ignore_pgood)
    {
        l_cplts = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>(
                      static_cast<fapi2::TargetFilter>(fapi2::TARGET_FILTER_ALL_EQ | fapi2::TARGET_FILTER_TP |
                              fapi2::TARGET_FILTER_ALL_MC  |  fapi2::TARGET_FILTER_ALL_NEST |
                              fapi2::TARGET_FILTER_ALL_PAU |  fapi2::TARGET_FILTER_ALL_PCI  |
                              fapi2::TARGET_FILTER_ALL_IOHS), fapi2::TARGET_STATE_PRESENT);
    }

    for (auto& targ : l_cplts)
    {
        uint32_t l_chipletID = targ.getChipletNumber();

        if(l_chipletID == 0x1)
        {
            l_data64.setBit<1>();
        }
        else if(l_chipletID == 0x2)
        {
            l_data64.setBit<2>();
        }
        else if(l_chipletID == 0x3)
        {
            l_data64.setBit<3>();
        }
        else if(l_chipletID == 0x8)
        {
            l_data64.setBit<8>();
        }
        else if(l_chipletID == 0x9)
        {
            l_data64.setBit<9>();
        }
        else if(l_chipletID == 0xC)
        {
            l_data64.setBit<12>();
        }
        else if(l_chipletID == 0xD)
        {
            l_data64.setBit<13>();
        }
        else if(l_chipletID == 0xE)
        {
            l_data64.setBit<14>();
        }
        else if(l_chipletID == 0xF)
        {
            l_data64.setBit<15>();
        }
        else if(l_chipletID == 0x10)
        {
            l_data64.setBit<16>();
        }
        else if(l_chipletID == 0x11)
        {
            l_data64.setBit<17>();
        }
        else if(l_chipletID == 0x12)
        {
            l_data64.setBit<18>();
        }
        else if(l_chipletID == 0x13)
        {
            l_data64.setBit<19>();
        }
        else if(l_chipletID == 0x18)
        {
            l_data64.setBit<24>();
        }
        else if(l_chipletID == 0x19)
        {
            l_data64.setBit<25>();
        }
        else if(l_chipletID == 0x1A)
        {
            l_data64.setBit<26>();
        }
        else if(l_chipletID == 0x1B)
        {
            l_data64.setBit<27>();
        }
        else if(l_chipletID == 0x1C)
        {
            l_data64.setBit<28>();
        }
        else if(l_chipletID == 0x1D)
        {
            l_data64.setBit<29>();
        }
        else if(l_chipletID == 0x1E)
        {
            l_data64.setBit<30>();
        }
        else if(l_chipletID == 0x1F)
        {
            l_data64.setBit<31>();
        }
        else if(l_chipletID == 0x20)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ0, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<32>() : l_data64.clearBit<32>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<32>();
            }
        }
        else if(l_chipletID == 0x21)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ1, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<33>() : l_data64.clearBit<33>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<33>();
            }
        }
        else if(l_chipletID == 0x22)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ2, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<34>() : l_data64.clearBit<34>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<34>();
            }
        }
        else if(l_chipletID == 0x23)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ3, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<35>() : l_data64.clearBit<35>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<35>();
            }
        }
        else if(l_chipletID == 0x24)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ4, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<36>() : l_data64.clearBit<36>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<36>();
            }
        }
        else if(l_chipletID == 0x25)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ5, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<37>() : l_data64.clearBit<37>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<37>();
            }
        }
        else if(l_chipletID == 0x26)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ6, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<38>() : l_data64.clearBit<38>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<38>();
            }
        }
        else if(l_chipletID == 0x27)
        {
            if(pgood_option == honor_core_pgood)
            {
                l_chiplet = i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
                            (fapi2::TARGET_FILTER_EQ7, fapi2::TARGET_STATE_FUNCTIONAL)[0];
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_chiplet, l_read_attr_pg));
                // Atleast one core should be good in EQ
                ( l_read_attr_pg.getBit<13>() || l_read_attr_pg.getBit<14>() || l_read_attr_pg.getBit<15>()
                  || l_read_attr_pg.getBit<16>() ) ? l_data64.setBit<39>() : l_data64.clearBit<39>();
            }
            else // ignore_pgood and honor_pgood
            {
                l_data64.setBit<39>();
            }
        }

        o_cplt_status_mask = l_data64;

    }

    FAPI_INF("p10_perv_sbe_cmn_cplt_status: Exiting ...");

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
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_data64_sync_cnfg;
    int l_timeout = 0;
    FAPI_INF("p10_perv_sbe_cmn_align_chiplets: Entering ...");

    fapi2::Target < fapi2::TARGET_TYPE_PERV | fapi2::TARGET_TYPE_MULTICAST,
          fapi2::MULTICAST_AND > l_mcast_and_target = i_mcast_target;

    FAPI_DBG("For all chiplets: exit flush");
    l_data64.flush<0>();
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_DBG("For all chiplets: enable alignement");
    l_data64.flush<0>();
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_DBG("Clear chiplet is aligned");
    FAPI_TRY(fapi2::getScom(i_mcast_target, PERV_SYNC_CONFIG, l_data64_sync_cnfg));
    l_data64_sync_cnfg.setBit<PERV_1_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_SYNC_CONFIG, l_data64_sync_cnfg));

    FAPI_DBG("Unset Clear chiplet is aligned");
    l_data64_sync_cnfg.clearBit<PERV_1_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_SYNC_CONFIG, l_data64_sync_cnfg));

    fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");
    l_timeout = CPLT_ALIGN_CHECK_POLL_COUNT;

    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(l_mcast_and_target, PERV_CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<PERV_1_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();

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
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC>();
    FAPI_TRY(fapi2::putScom(i_mcast_target, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_INF("p10_perv_sbe_cmn_align_chiplets: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
