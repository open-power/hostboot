/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_sbe_common.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_sbe_common.C
///
/// @brief Common Modules for SBE
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_sbe_common.H"
//## auto_generated
#include "p9_const_common.H"

#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_const_common.H>


enum P9_SBE_COMMON_Private_Constants
{
    NS_DELAY = 100000, // unit in nano seconds
    SIM_CYCLE_DELAY = 1000, // unit in cycles
    CPLT_ALIGN_CHECK_POLL_COUNT = 10, // count to wait for chiplet aligned
    CPLT_OPCG_DONE_DC_POLL_COUNT = 10 // count to wait for chiplet opcg done
};

// chiplet pervasive FIR constants
const uint64_t PERV_LFIR_ACTION0[15] =
{
    0x0000000000000000ULL, // TP
    0x0000000000000000ULL, // N0
    0x0000000000000000ULL, // N1
    0x0000000000000000ULL, // N2
    0x0000000000000000ULL, // N3
    0x0000000000000000ULL, // X
    0x0000000000000000ULL, // MC0
    0x0000000000000000ULL, // MC1
    0x0000000000000000ULL, // OB0
    0x0000000000000000ULL, // OB1
    0x0000000000000000ULL, // OB2
    0x0000000000000000ULL, // OB3
    0x0000000000000000ULL, // PCI0
    0x0000000000000000ULL, // PCI1
    0x0000000000000000ULL  // PCI2
};

const uint64_t PERV_LFIR_ACTION1[15] =
{
    0xF000000000000000ULL, // TP
    0xF000000000000000ULL, // N0
    0xF000000000000000ULL, // N1
    0xF000000000000000ULL, // N2
    0xF000000000000000ULL, // N3
    0xF000000000000000ULL, // X
    0xF000000000000000ULL, // MC0
    0xF000000000000000ULL, // MC1
    0xF000000000000000ULL, // OB0
    0xF000000000000000ULL, // OB1
    0xF000000000000000ULL, // OB2
    0xF000000000000000ULL, // OB3
    0xF000000000000000ULL, // PCI0
    0xF000000000000000ULL, // PCI1
    0xF000000000000000ULL  // PCI2
};

const uint64_t PERV_LFIR_MASK[15] =
{
    0x0FFFBC2BFC400000ULL, // TP
    0x0FFFFFFFFFC00000ULL, // N0
    0x0FFFFFFFFFC00000ULL, // N1
    0x0FFFFFFFFFC00000ULL, // N2
    0x0FFFFFFF1FC00000ULL, // N3
    0x0FFFFFFFFFC00000ULL, // X
    0x0FFFFFFFFFC00000ULL, // MC0
    0x0FFFFFFFFFC00000ULL, // MC1
    0x0FFFFFFFFFC00000ULL, // OB0
    0x0FFFFFFFFFC00000ULL, // OB1
    0x0FFFFFFFFFC00000ULL, // OB2
    0x0FFFFFFFFFC00000ULL, // OB3
    0x0FFFFFFFFFC00000ULL, // PCI0
    0x0FFFFFFFFFC00000ULL, // PCI1
    0x0FFFFFFFFFC00000ULL  // PCI2
};

// chiplet XIR constants
const uint64_t PERV_XFIR_MASK[15] =
{
    0x0000000000000000ULL, // TP
    0x0000000000000000ULL, // N0
    0x0000000000000000ULL, // N1
    0x0000000000000000ULL, // N2
    0x0000000000000000ULL, // N3
    0x0000000000000000ULL, // X
    0x0000000000000000ULL, // MC0
    0x0000000000000000ULL, // MC1
    0x0000000000000000ULL, // OB0
    0x0000000000000000ULL, // OB1
    0x0000000000000000ULL, // OB2
    0x0000000000000000ULL, // OB3
    0x0000000000000000ULL, // PCI0
    0x0000000000000000ULL, // PCI1
    0x0000000000000000ULL  // PCI2
};

/// @brief --For all chiplets exit flush
/// --For all chiplets enable alignment
/// --For all chiplets disable alignemnt
///
/// @param[in]     i_target_chiplets   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_align_chiplets(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplets)
{
    fapi2::buffer<uint64_t> l_data64;
    int l_timeout = 0;
    FAPI_INF("p9_sbe_common_align_chiplets: Entering ...");

    FAPI_DBG("For all chiplets: exit flush");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FLUSHMODE_INH_DC = 1
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_DBG("For all chiplets: enable alignement");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FORCE_ALIGN_DC = 1
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_DBG("Clear chiplet is aligned");
    //Setting SYNC_CONFIG register value
    FAPI_TRY(fapi2::getScom(i_target_chiplets, PERV_SYNC_CONFIG, l_data64));
    //SYNC_CONFIG.CLEAR_CHIPLET_IS_ALIGNED = 0b1
    l_data64.setBit<PERV_1_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_SYNC_CONFIG, l_data64));

    FAPI_DBG("Unset Clear chiplet is aligned");
    //Setting SYNC_CONFIG register value
    FAPI_TRY(fapi2::getScom(i_target_chiplets, PERV_SYNC_CONFIG, l_data64));
    //SYNC_CONFIG.CLEAR_CHIPLET_IS_ALIGNED = 0b0
    l_data64.clearBit<PERV_1_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_SYNC_CONFIG, l_data64));

    fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_DBG("Poll OPCG done bit to check for run-N completeness");
    l_timeout = CPLT_ALIGN_CHECK_POLL_COUNT;

    //UNTIL CPLT_STAT0.CC_CTRL_CHIPLET_IS_ALIGNED_DC == 1
    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(i_target_chiplets, PERV_CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<PERV_1_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();  //bool l_poll_data = CPLT_STAT0.CC_CTRL_CHIPLET_IS_ALIGNED_DC

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
                .set_TARGET_CHIPLET(i_target_chiplets)
                .set_PERV_CPLT_STAT0(l_data64)
                .set_LOOP_COUNT(l_timeout)
                .set_HW_DELAY(NS_DELAY),
                "ERROR:CHIPLET NOT ALIGNED");

    FAPI_DBG("For all chiplets: disable alignement");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FORCE_ALIGN_DC = 0
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_INF("p9_sbe_common_align_chiplets: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief To do check on Clock controller status for chiplets
///
/// @param[in]     i_target        Reference to TARGET_TYPE_PERV target Reference to TARGET_TYPE_PERV target
/// @param[in]     i_clock_cmd     Issue clock controller command (START/STOP)
/// @param[in]     i_regions       Enable required REGIONS
/// @param[in]     i_clock_types   Clock Types to be selected (SL/NSL/ARY)
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_check_cc_status_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
    const fapi2::buffer<uint8_t> i_clock_cmd,
    const fapi2::buffer<uint16_t> i_regions,
    const fapi2::buffer<uint8_t> i_clock_types)
{
    bool l_reg_sl = false;
    bool l_reg_nsl = false;
    bool l_reg_ary = false;
    fapi2::buffer<uint64_t> l_sl_clock_status;
    fapi2::buffer<uint64_t> l_nsl_clock_status;
    fapi2::buffer<uint64_t> l_ary_clock_status;
    fapi2::buffer<uint16_t> l_sl_clkregion_status;
    fapi2::buffer<uint16_t> l_nsl_clkregion_status;
    fapi2::buffer<uint16_t> l_ary_clkregion_status;
    fapi2::buffer<uint16_t> l_regions;
    FAPI_INF("p9_sbe_common_check_cc_status_function: Entering ...");

    l_reg_sl = i_clock_types.getBit<5>();
    l_reg_nsl = i_clock_types.getBit<6>();
    l_reg_ary = i_clock_types.getBit<7>();
    i_regions.extractToRight<5, 11>(l_regions);

    if ( l_reg_sl )
    {
        FAPI_DBG("Check for Clocks running SL");
        //Getting CLOCK_STAT_SL register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_SL,
                                l_sl_clock_status)); //l_sl_clock_status = CLOCK_STAT_SL
        FAPI_DBG("SL Clock status register is %#018lX", l_sl_clock_status);

        if ( i_clock_cmd == 0b01 )
        {
            FAPI_DBG("Checking for clock start command");
            l_sl_clkregion_status.flush<1>();
            l_sl_clock_status.extractToRight<4, 11>(l_sl_clkregion_status);
            l_sl_clkregion_status.invert();
            l_sl_clkregion_status &= l_regions;

            FAPI_ASSERT(l_sl_clkregion_status == l_regions,
                        fapi2::THOLD_ERR()
                        .set_TARGET_CHIPLET(i_target)
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_SL)
                        .set_REGIONS(i_regions)
                        .set_READ_CLK(l_sl_clock_status),
                        "Clock running for sl type not matching with expected values");
        }

        if ( i_clock_cmd == 0b10 )
        {
            FAPI_DBG("Checking for clock stop command");
            l_sl_clkregion_status.flush<0>();
            l_sl_clock_status.extractToRight<4, 11>(l_sl_clkregion_status);
            l_sl_clkregion_status &= l_regions;

            FAPI_ASSERT(l_sl_clkregion_status == l_regions,
                        fapi2::THOLD_ERR()
                        .set_TARGET_CHIPLET(i_target)
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_SL)
                        .set_REGIONS(i_regions)
                        .set_READ_CLK(l_sl_clock_status),
                        "Clock running for sl type not matching with expected values");
        }
    }

    if ( l_reg_nsl )
    {
        FAPI_DBG("Check for clocks running NSL");
        //Getting CLOCK_STAT_NSL register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_NSL,
                                l_nsl_clock_status)); //l_nsl_clock_status = CLOCK_STAT_NSL
        FAPI_DBG("NSL Clock status register is %#018lX", l_nsl_clock_status);

        if ( i_clock_cmd == 0b01 )
        {
            FAPI_DBG("Checking for clock start command");
            l_nsl_clkregion_status.flush<1>();
            l_nsl_clock_status.extractToRight<4, 11>(l_nsl_clkregion_status);
            l_nsl_clkregion_status.invert();
            l_nsl_clkregion_status &= l_regions;

            FAPI_ASSERT(l_nsl_clkregion_status == l_regions,
                        fapi2::THOLD_ERR()
                        .set_TARGET_CHIPLET(i_target)
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_NSL)
                        .set_REGIONS(i_regions)
                        .set_READ_CLK(l_nsl_clock_status),
                        "Clock running for nsl type not matching with expected values");
        }

        if ( i_clock_cmd == 0b10 )
        {
            FAPI_DBG("Checking for clock stop command");
            l_nsl_clkregion_status.flush<0>();
            l_nsl_clock_status.extractToRight<4, 11>(l_nsl_clkregion_status);
            l_nsl_clkregion_status &= l_regions;

            FAPI_ASSERT(l_nsl_clkregion_status == l_regions,
                        fapi2::THOLD_ERR()
                        .set_TARGET_CHIPLET(i_target)
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_NSL)
                        .set_REGIONS(i_regions)
                        .set_READ_CLK(l_nsl_clock_status),
                        "Clock running for nsl type not matching with expected values");
        }
    }

    if ( l_reg_ary )
    {
        FAPI_DBG("Check for clocks running ARY");
        //Getting CLOCK_STAT_ARY register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_ARY,
                                l_ary_clock_status)); //l_ary_clock_status = CLOCK_STAT_ARY
        FAPI_DBG("ARY Clock status register is %#018lX", l_ary_clock_status);

        if ( i_clock_cmd == 0b01 )
        {
            FAPI_DBG("Checking for clock start command");
            l_ary_clkregion_status.flush<1>();
            l_ary_clock_status.extractToRight<4, 11>(l_ary_clkregion_status);
            l_ary_clkregion_status.invert();
            l_ary_clkregion_status &= l_regions;

            FAPI_ASSERT(l_ary_clkregion_status == l_regions,
                        fapi2::THOLD_ERR()
                        .set_TARGET_CHIPLET(i_target)
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_ARY)
                        .set_REGIONS(i_regions)
                        .set_READ_CLK(l_ary_clock_status),
                        "Clock running for ary type not matching with expected values");
        }

        if ( i_clock_cmd == 0b10 )
        {
            FAPI_DBG("Checking for clock stop command");
            l_ary_clkregion_status.flush<0>();
            l_ary_clock_status.extractToRight<4, 11>(l_ary_clkregion_status);
            l_ary_clkregion_status &= l_regions;

            FAPI_ASSERT(l_ary_clkregion_status == l_regions,
                        fapi2::THOLD_ERR()
                        .set_TARGET_CHIPLET(i_target)
                        .set_CLOCK_CMD(i_clock_cmd)
                        .set_CLOCK_TYPE(PERV_CLOCK_STAT_ARY)
                        .set_REGIONS(i_regions)
                        .set_READ_CLK(l_ary_clock_status),
                        "Clock running for ary type not matching with expected values");
        }
    }

    FAPI_INF("p9_sbe_common_check_cc_status_function: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}


/// @brief check clocks status
///
/// @param[in]     i_regions            regions from upper level input
/// @param[in]     i_clock_status       clock status
/// @param[in]     i_reg                bit status
/// @param[in]     i_clock_cmd          clock command
/// @param[out]    o_exp_clock_status   expected clock status
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_check_status(const fapi2::buffer<uint64_t>
        i_regions,
        const fapi2::buffer<uint64_t> i_clock_status,
        const bool i_reg,
        const fapi2::buffer<uint8_t> i_clock_cmd,
        fapi2::buffer<uint64_t>& o_exp_clock_status)
{
    FAPI_INF("p9_sbe_common_check_status: Entering ...");

    if ( (i_reg) && (i_clock_cmd == 0b01) )
    {
        o_exp_clock_status = i_clock_status & (~(i_regions << 49));
    }
    else
    {
        if ( (i_reg) && (i_clock_cmd == 0b10) )
        {
            o_exp_clock_status = i_clock_status | (i_regions << 49);
        }
        else
        {
            o_exp_clock_status = i_clock_status;
        }
    }

    FAPI_INF("p9_sbe_common_check_status: Exiting ...");

    return fapi2::FAPI2_RC_SUCCESS;

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
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_clock_start_stop(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target,
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
    FAPI_INF("p9_sbe_common_clock_start_stop: Entering ...");

    i_regions.extractToRight<53, 11>(l_regions);
    i_clock_types.extractToRight<5, 3>(l_reg_all);
    l_reg_sl = i_clock_types.getBit<5>();
    l_reg_nsl = i_clock_types.getBit<6>();
    l_reg_ary = i_clock_types.getBit<7>();

    FAPI_DBG("Chiplet exit flush");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FLUSHMODE_INH_DC = 1
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_target, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_DBG("Clear Scan region type register");
    //Setting SCAN_REGION_TYPE register value
    //SCAN_REGION_TYPE = 0
    FAPI_TRY(fapi2::putScom(i_target, PERV_SCAN_REGION_TYPE, 0));

    FAPI_DBG("Reading the initial status of clock controller");
    //Getting CLOCK_STAT_SL register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_SL,
                            l_sl_clock_status)); //l_sl_clock_status = CLOCK_STAT_SL
    //Getting CLOCK_STAT_NSL register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_NSL,
                            l_nsl_clock_status)); //l_nsl_clock_status = CLOCK_STAT_NSL
    //Getting CLOCK_STAT_ARY register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_ARY,
                            l_ary_clock_status)); //l_ary_clock_status = CLOCK_STAT_ARY
    FAPI_DBG("Clock status of SL_Register:%#018lX NSL_Register:%#018lX ARY_Register:%#018lX",
             l_sl_clock_status, l_nsl_clock_status, l_ary_clock_status);

    i_clock_cmd.extractToRight<6, 2>(l_clk_cmd);

    FAPI_DBG("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLK_REGION, l_data64));
    l_data64.insertFromRight<PERV_1_CLK_REGION_CLOCK_CMD, PERV_1_CLK_REGION_CLOCK_CMD_LEN>
    (l_clk_cmd);  //CLK_REGION.CLOCK_CMD = l_clk_cmd
    //CLK_REGION.SLAVE_MODE = i_startslave
    l_data64.writeBit<PERV_1_CLK_REGION_SLAVE_MODE>(i_startslave);
    //CLK_REGION.MASTER_MODE = i_startmaster
    l_data64.writeBit<PERV_1_CLK_REGION_MASTER_MODE>(i_startmaster);
    //CLK_REGION.CLOCK_REGION_ALL_UNITS = l_regions
    l_data64.insertFromRight<4, 11>(l_regions);
    //CLK_REGION.SEL_THOLD_ALL = l_reg_all
    l_data64.insertFromRight<48, 3>(l_reg_all);
    FAPI_TRY(fapi2::putScom(i_target, PERV_CLK_REGION, l_data64));

    // To wait until OPCG Done - CPLT_STAT0.cc_cplt_opcg_done_dc = 1
    FAPI_DBG("Poll OPCG done bit to check for completeness");
    l_data64.flush<0>();
    l_timeout = CPLT_OPCG_DONE_DC_POLL_COUNT;

    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<PERV_1_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>();

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
                .set_TARGET_CHIPLET(i_target)
                .set_PERV_CPLT_STAT0(l_data64)
                .set_LOOP_COUNT(l_timeout)
                .set_HW_DELAY(NS_DELAY),
                "ERROR:CHIPLET OPCG DONE NOT SET AFTER CLOCK START STOP CMD");

    //To do do checking only for chiplets that dont have Master-slave mode enabled

    if ( !i_startslave && !i_startmaster )
    {
        // Calculating the Expected clock status

        FAPI_TRY(p9_sbe_common_check_status(i_regions, l_sl_clock_status, l_reg_sl,
                                            i_clock_cmd, l_exp_sl_clock_status));

        FAPI_TRY(p9_sbe_common_check_status(i_regions, l_nsl_clock_status, l_reg_nsl,
                                            i_clock_cmd, l_exp_nsl_clock_status));

        FAPI_TRY(p9_sbe_common_check_status(i_regions, l_ary_clock_status, l_reg_ary,
                                            i_clock_cmd, l_exp_ary_clock_status));

        FAPI_DBG("Check for clocks running SL");
        //Getting CLOCK_STAT_SL register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_SL,
                                l_sl_clock_status)); //l_sl_clock_status = CLOCK_STAT_SL
        FAPI_DBG("Expected value is %#018lX, Actaul value is %#018lX",
                 l_exp_sl_clock_status, l_sl_clock_status);

        FAPI_ASSERT(l_sl_clock_status == l_exp_sl_clock_status,
                    fapi2::THOLD_ERR()
                    .set_TARGET_CHIPLET(i_target)
                    .set_CLOCK_CMD(i_clock_cmd)
                    .set_CLOCK_TYPE(PERV_CLOCK_STAT_SL)
                    .set_REGIONS(i_regions)
                    .set_READ_CLK(l_sl_clock_status),
                    "CLOCK RUNNING STATUS FOR SL TYPE NOT MATCHING WITH EXPECTED VALUES");

        FAPI_DBG("Check for clocks running NSL");
        //Getting CLOCK_STAT_NSL register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_NSL,
                                l_nsl_clock_status)); //l_nsl_clock_status = CLOCK_STAT_NSL
        FAPI_DBG("Expected value is %#018lX, Actaul value is %#018lX",
                 l_exp_nsl_clock_status, l_nsl_clock_status);

        FAPI_ASSERT(l_nsl_clock_status == l_exp_nsl_clock_status,
                    fapi2::THOLD_ERR()
                    .set_TARGET_CHIPLET(i_target)
                    .set_CLOCK_CMD(i_clock_cmd)
                    .set_CLOCK_TYPE(PERV_CLOCK_STAT_NSL)
                    .set_REGIONS(i_regions)
                    .set_READ_CLK(l_nsl_clock_status),
                    "CLOCK RUNNING STATUS IS NOT MATCHING WITH EXPECTED VALUE FOR NSL TYPE");

        FAPI_DBG("Check for clocks running ARY");
        //Getting CLOCK_STAT_ARY register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_ARY,
                                l_ary_clock_status)); //l_ary_clock_status = CLOCK_STAT_ARY
        FAPI_DBG("Expected value is %#018lX, Actaul value is %#018lX",
                 l_exp_ary_clock_status, l_ary_clock_status);

        FAPI_ASSERT(l_ary_clock_status == l_exp_ary_clock_status,
                    fapi2::THOLD_ERR()
                    .set_TARGET_CHIPLET(i_target)
                    .set_CLOCK_CMD(i_clock_cmd)
                    .set_CLOCK_TYPE(PERV_CLOCK_STAT_ARY)
                    .set_REGIONS(i_regions)
                    .set_READ_CLK(l_ary_clock_status),
                    "CLOCK RUNNING STATUS IS NOT MATCHING WITH EXPECTED VALUE FOR ARRAY TYPE");
    }

    FAPI_INF("p9_sbe_common_clock_start_stop: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief --drop vital fence
/// --reset abstclk muxsel,syncclk_muxsel
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @param[in]     i_attr_pg          ATTR_PG for the corresponding chiplet
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_cplt_ctrl_action_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
    const fapi2::buffer<uint16_t> i_attr_pg)
{
    // Local variable and constant definition
    fapi2::buffer <uint16_t> l_cplt_ctrl_init;
    fapi2::buffer<uint16_t> l_attr_pg;
    fapi2::buffer<uint64_t> l_data64;
    FAPI_INF("p9_sbe_common_cplt_ctrl_action_function: Entering ...");

    l_attr_pg = i_attr_pg;
    l_attr_pg.invert();
    l_attr_pg.extractToRight<4, 11>(l_cplt_ctrl_init);

    // Not needed as have only nest chiplet (no dual clock controller) Bit 62 ->0
    //
    FAPI_DBG("Drop partial good fences");
    //Setting CPLT_CTRL1 register value
    l_data64.flush<0>();
    l_data64.writeBit<PERV_1_CPLT_CTRL1_TC_VITL_REGION_FENCE>
    (l_attr_pg.getBit<3>());
    //CPLT_CTRL1.TC_ALL_REGIONS_FENCE = l_cplt_ctrl_init
    l_data64.insertFromRight<4, 11>(l_cplt_ctrl_init);
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL1_CLEAR, l_data64));

    FAPI_DBG("reset abistclk_muxsel and syncclk_muxsel");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_ABSTCLK_MUXSEL_DC = 1
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>();
    //CPLT_CTRL0.TC_UNIT_SYNCCLK_MUXSEL_DC = 1
    l_data64.setBit<PERV_1_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_INF("p9_sbe_common_cplt_ctrl_action_function: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief will force all chiplets out of flush
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_flushmode(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet)
{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_INF("p9_sbe_common_flushmode: Entering ...");

    FAPI_DBG("Clear flush_inhibit to go in to flush mode");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FLUSHMODE_INH_DC = 0
    l_data64.setBit<PERV_1_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_INF("p9_sbe_common_flushmode: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief get children for all chiplets
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @param[out]    o_pg_vector     vector of targets
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_get_pg_vector(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        fapi2::buffer<uint64_t>& o_pg_vector)
{
    fapi2::buffer<uint8_t> l_read_attrunitpos;
    FAPI_INF("p9_sbe_common_get_pg_vector: Entering ...");

    for (auto& l_target_cplt : i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV> (fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_target_cplt, l_read_attrunitpos));
        uint8_t bitPos = l_read_attrunitpos;
        o_pg_vector.setBit(bitPos);
    }

    FAPI_INF("p9_sbe_common_get_pg_vector: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief --Setting Scan ratio
///
/// @param[in]     i_target_chiplets   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_set_scan_ratio(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplets)
{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_INF("p9_sbe_common_set_scan_ratio: Entering ...");

    //Setting OPCG_ALIGN register value
    FAPI_TRY(fapi2::getScom(i_target_chiplets, PERV_OPCG_ALIGN, l_data64));
    l_data64.insertFromRight<PERV_1_OPCG_ALIGN_SCAN_RATIO, PERV_1_OPCG_ALIGN_SCAN_RATIO_LEN>
    (0xE0);  //OPCG_ALIGN.SCAN_RATIO = 0xE0
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_OPCG_ALIGN, l_data64));

    FAPI_INF("p9_sbe_common_set_scan_ratio: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief configure chiplet pervasive FIRs / XFIRs
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_configure_chiplet_FIR(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet)
{
    uint8_t l_unit_idx;
    fapi2::buffer<uint64_t> l_scom_data;
    FAPI_INF("p9_sbe_common_configure_chiplet_FIR: Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_chiplet, l_unit_idx),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    l_unit_idx--;

    // PERV LFIR
    FAPI_DBG("Configuring PERV LFIR (chiplet ID: %02X)", l_unit_idx + 1);

    // reset pervasive FIR
    l_scom_data = 0;
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_LOCAL_FIR, l_scom_data),
             "Error from putScom (PERV_LOCAL_FIR)");

    // configure pervasive FIR action/mask
    l_scom_data = PERV_LFIR_ACTION0[l_unit_idx];
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_LOCAL_FIR_ACTION0, l_scom_data),
             "Error from putScom (PERV_LOCAL_FIR_ACTION0)");

    l_scom_data = PERV_LFIR_ACTION1[l_unit_idx];
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_LOCAL_FIR_ACTION1, l_scom_data),
             "Error from putScom (PERV_LOCAL_FIR_ACTION1)");

    l_scom_data = PERV_LFIR_MASK[l_unit_idx];
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_LOCAL_FIR_MASK, l_scom_data),
             "Error from putScom (PERV_LOCAL_FIR_MASK)");

    // XFIR
    FAPI_DBG("Configuring chiplet XFIR (chiplet ID: %02X)", l_unit_idx + 1);
    // reset XFIR
    l_scom_data = 0;
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_XFIR, l_scom_data),
             "Error from putScom (PERV_XFIR)");

    // configure XFIR mask
    l_scom_data = PERV_XFIR_MASK[l_unit_idx];
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_FIR_MASK, l_scom_data),
             "Error from putScom (PERV_FIR_MASK");

    FAPI_INF("p9_sbe_common_configure_chiplet_FIR: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
