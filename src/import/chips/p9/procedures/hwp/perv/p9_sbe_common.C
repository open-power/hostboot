/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_sbe_common.C $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_sbe_common.H"
#include "p9_const_common.H"
#include "p9_misc_scom_addresses_fld.H"
#include "p9_perv_scom_addresses.H"



enum P9_SBE_COMMON_Private_Constants
{
    CLK_REGION_VALUE = 0x498000000000E000,
    EXPECTED_CLOCK_STATUS = 0xF07FDFFFFFFFFFFF,
    NS_DELAY = 100000, // unit in nano seconds
    SIM_CYCLE_DELAY = 1000, // unit in cycles
    CPLT_ALIGN_CHECK_POLL_COUNT = 10 // count to wait for chiplet aligned
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
    FAPI_DBG("Entering ...");

    FAPI_INF("For all chiplets: exit flush");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FLUSHMODE_INH_DC = 1
    l_data64.setBit<PEC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_INF("For all chiplets: enable alignement");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FORCE_ALIGN_DC = 1
    l_data64.setBit<PEC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_CPLT_CTRL0_OR, l_data64));

    fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);

    FAPI_INF("Poll OPCG done bit to check for run-N completeness");
    l_timeout = CPLT_ALIGN_CHECK_POLL_COUNT;

    //UNTIL CPLT_STAT0.CC_CTRL_CHIPLET_IS_ALIGNED_DC == 1
    while (l_timeout != 0)
    {
        //Getting CPLT_STAT0 register value
        FAPI_TRY(fapi2::getScom(i_target_chiplets, PERV_CPLT_STAT0, l_data64));
        bool l_poll_data =
            l_data64.getBit<PEC_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC>();  //bool l_poll_data = CPLT_STAT0.CC_CTRL_CHIPLET_IS_ALIGNED_DC

        if (l_poll_data == 1)
        {
            break;
        }

        fapi2::delay(NS_DELAY, SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_INF("Loop Count :%d", l_timeout);

    FAPI_ASSERT(l_timeout > 0,
                fapi2::CPLT_NOT_ALIGNED_ERR(),
                "ERROR:CHIPLET NOT ALIGNED");

    FAPI_INF("For all chiplets: disable alignement");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FORCE_ALIGN_DC = 0
    l_data64.setBit<PEC_CPLT_CTRL0_CTRL_CC_FORCE_ALIGN_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief --Setting Clock Region Register
/// --Reading Clock status
///
/// @param[in]     i_anychiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_sbe_common_clock_start_allRegions(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_anychiplet)
{
    fapi2::buffer<uint64_t> l_sl_clock_status;
    fapi2::buffer<uint64_t> l_nsl_clock_status;
    fapi2::buffer<uint64_t> l_ary_clock_status;
    FAPI_DBG("Entering ...");

    FAPI_INF("Start remaining pervasive clocks (beyond PIB & NET)");
    //Setting CLK_REGION register value
    //CLK_REGION = CLK_REGION_VALUE
    FAPI_TRY(fapi2::putScom(i_anychiplet, PERV_CLK_REGION, CLK_REGION_VALUE));

    FAPI_INF("Check for clocks running (SL , NSL , ARY)");
    //Getting CLOCK_STAT_SL register value
    FAPI_TRY(fapi2::getScom(i_anychiplet, PERV_CLOCK_STAT_SL,
                            l_sl_clock_status)); //l_sl_clock_status = CLOCK_STAT_SL
    //Getting CLOCK_STAT_NSL register value
    FAPI_TRY(fapi2::getScom(i_anychiplet, PERV_CLOCK_STAT_NSL,
                            l_nsl_clock_status)); //l_nsl_clock_status = CLOCK_STAT_NSL
    //Getting CLOCK_STAT_ARY register value
    FAPI_TRY(fapi2::getScom(i_anychiplet, PERV_CLOCK_STAT_ARY,
                            l_ary_clock_status)); //l_ary_clock_status = CLOCK_STAT_ARY

    FAPI_ASSERT(l_sl_clock_status == EXPECTED_CLOCK_STATUS,
                fapi2::SL_ERR()
                .set_READ_CLK_SL(l_sl_clock_status),
                "CLOCK RUNNING STATUS FOR SL TYPE NOT MATCHING WITH EXPECTED VALUES");

    FAPI_ASSERT(l_nsl_clock_status == EXPECTED_CLOCK_STATUS,
                fapi2::NSL_ERR()
                .set_READ_CLK_NSL(l_nsl_clock_status),
                "CLOCK RUNNING STATUS IS NOT MATCHING WITH EXPECTED VALUE FOR NSL TYPE");

    FAPI_ASSERT(l_ary_clock_status == EXPECTED_CLOCK_STATUS,
                fapi2::ARY_ERR()
                .set_READ_CLK_ARY(l_ary_clock_status),
                "CLOCK RUNNING STATUS IS NOT MATCHING WITH EXPECTED VALUE FOR ARRAY TYPE");

    FAPI_DBG("Exiting ...");

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
    bool l_reg_sl = false;
    bool l_reg_nsl = false;
    bool l_reg_ary = false;
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("Entering ...");

    l_reg_sl = i_clock_types.getBit<5>();
    l_reg_nsl = i_clock_types.getBit<6>();
    l_reg_ary = i_clock_types.getBit<7>();

    FAPI_INF("Chiplet exit flush");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FLUSHMODE_INH_DC = 1
    l_data64.setBit<PEC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_target, PERV_CPLT_CTRL0_OR, l_data64));

    FAPI_INF("Clear Scan region type register");
    //Setting SCAN_REGION_TYPE register value
    //SCAN_REGION_TYPE = 0
    FAPI_TRY(fapi2::putScom(i_target, PERV_SCAN_REGION_TYPE, 0));

    FAPI_INF("Reading the initial status of clock controller");
    //Getting CLOCK_STAT_SL register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_SL,
                            l_sl_clock_status)); //l_sl_clock_status = CLOCK_STAT_SL
    //Getting CLOCK_STAT_NSL register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_NSL,
                            l_nsl_clock_status)); //l_nsl_clock_status = CLOCK_STAT_NSL
    //Getting CLOCK_STAT_ARY register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_ARY,
                            l_ary_clock_status)); //l_ary_clock_status = CLOCK_STAT_ARY
    FAPI_INF("Clock status of SL_Register:%#018lX NSL_Register:%#018lX ARY_Register:%#018lX",
             l_sl_clock_status, l_nsl_clock_status, l_ary_clock_status);

    i_clock_cmd.extractToRight<6, 2>(l_clk_cmd);

    FAPI_INF("Setup all Clock Domains and Clock Types");
    //Setting CLK_REGION register value
    FAPI_TRY(fapi2::getScom(i_target, PERV_CLK_REGION, l_data64));
    l_data64.insertFromRight<PEC_CLK_REGION_CLOCK_CMD, PEC_CLK_REGION_CLOCK_CMD_LEN>
    (l_clk_cmd);  //CLK_REGION.CLOCK_CMD = l_clk_cmd
    //CLK_REGION.SLAVE_MODE = i_startslave
    l_data64.writeBit<PEC_CLK_REGION_SLAVE_MODE>(i_startslave);
    //CLK_REGION.MASTER_MODE = i_startmaster
    l_data64.writeBit<PEC_CLK_REGION_MASTER_MODE>(i_startmaster);
    //CLK_REGION.CLOCK_REGION_PERV = i_regions.getBit<53>()
    l_data64.writeBit<4>(i_regions.getBit<53>());
    //CLK_REGION.CLOCK_REGION_UNIT1 = i_regions.getBit<54>()
    l_data64.writeBit<5>(i_regions.getBit<54>());
    //CLK_REGION.CLOCK_REGION_UNIT2 = i_regions.getBit<55>()
    l_data64.writeBit<6>(i_regions.getBit<55>());
    //CLK_REGION.CLOCK_REGION_UNIT3 = i_regions.getBit<56>()
    l_data64.writeBit<7>(i_regions.getBit<56>());
    //CLK_REGION.CLOCK_REGION_UNIT4 = i_regions.getBit<57>()
    l_data64.writeBit<8>(i_regions.getBit<57>());
    //CLK_REGION.CLOCK_REGION_UNIT5 = i_regions.getBit<58>()
    l_data64.writeBit<9>(i_regions.getBit<58>());
    //CLK_REGION.CLOCK_REGION_UNIT6 = i_regions.getBit<59>()
    l_data64.writeBit<10>(i_regions.getBit<59>());
    //CLK_REGION.CLOCK_REGION_UNIT7 = i_regions.getBit<60>()
    l_data64.writeBit<11>(i_regions.getBit<60>());
    //CLK_REGION.CLOCK_REGION_UNIT8 = i_regions.getBit<61>()
    l_data64.writeBit<12>(i_regions.getBit<61>());
    //CLK_REGION.CLOCK_REGION_UNIT9 = i_regions.getBit<62>()
    l_data64.writeBit<13>(i_regions.getBit<62>());
    //CLK_REGION.CLOCK_REGION_UNIT10 = i_regions.getBit<63>()
    l_data64.writeBit<14>(i_regions.getBit<63>());
    //CLK_REGION.SEL_THOLD_SL = l_reg_sl
    l_data64.writeBit<PEC_CLK_REGION_SEL_THOLD_SL>(l_reg_sl);
    //CLK_REGION.SEL_THOLD_NSL = l_reg_nsl
    l_data64.writeBit<PEC_CLK_REGION_SEL_THOLD_NSL>(l_reg_nsl);
    //CLK_REGION.SEL_THOLD_ARY = l_reg_ary
    l_data64.writeBit<PEC_CLK_REGION_SEL_THOLD_ARY>(l_reg_ary);
    FAPI_TRY(fapi2::putScom(i_target, PERV_CLK_REGION, l_data64));

    //To do do checking only for chiplets that dont have Master-slave mode enabled

    if ( !i_startslave && !i_startmaster )
    {
        // Calculating the Expected clock status

        if ( (l_reg_sl) && (i_clock_cmd == 0b01) )
        {
            l_exp_sl_clock_status = l_sl_clock_status & (~(i_regions << 49));
        }
        else
        {
            if ( (l_reg_sl) && (i_clock_cmd == 0b10) )
            {
                l_exp_sl_clock_status = l_sl_clock_status | (i_regions << 49);
            }
            else
            {
                l_exp_sl_clock_status = l_sl_clock_status;
            }
        }

        if ( (l_reg_nsl) && (i_clock_cmd == 0b01) )
        {
            l_exp_nsl_clock_status = l_nsl_clock_status & (~(i_regions << 49));
        }
        else
        {
            if ( (l_reg_nsl) && (i_clock_cmd == 0b10) )
            {
                l_exp_nsl_clock_status = l_nsl_clock_status | (i_regions << 49);
            }
            else
            {
                l_exp_nsl_clock_status = l_nsl_clock_status;
            }
        }

        if ( (l_reg_ary) && (i_clock_cmd == 0b01) )
        {
            l_exp_ary_clock_status = l_ary_clock_status & (~(i_regions << 49));
        }
        else
        {
            if ( (l_reg_ary) && (i_clock_cmd == 0b10) )
            {
                l_exp_ary_clock_status = l_ary_clock_status | (i_regions << 49);
            }
            else
            {
                l_exp_ary_clock_status = l_ary_clock_status;
            }
        }

        FAPI_INF("Check for clocks running SL");
        //Getting CLOCK_STAT_SL register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_SL,
                                l_sl_clock_status)); //l_sl_clock_status = CLOCK_STAT_SL
        FAPI_INF("Expected value is %#018lX, Actaul value is %#018lX",
                 l_exp_sl_clock_status, l_sl_clock_status);

        FAPI_ASSERT(l_sl_clock_status == l_exp_sl_clock_status,
                    fapi2::SL_ERR()
                    .set_READ_CLK_SL(l_sl_clock_status),
                    "CLOCK RUNNING STATUS FOR SL TYPE NOT MATCHING WITH EXPECTED VALUES");

        FAPI_INF("Check for clocks running NSL");
        //Getting CLOCK_STAT_NSL register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_NSL,
                                l_nsl_clock_status)); //l_nsl_clock_status = CLOCK_STAT_NSL
        FAPI_INF("Expected value is %#018lX, Actaul value is %#018lX",
                 l_exp_nsl_clock_status, l_nsl_clock_status);

        FAPI_ASSERT(l_nsl_clock_status == l_exp_nsl_clock_status,
                    fapi2::NSL_ERR()
                    .set_READ_CLK_NSL(l_nsl_clock_status),
                    "CLOCK RUNNING STATUS IS NOT MATCHING WITH EXPECTED VALUE FOR NSL TYPE");

        FAPI_INF("Check for clocks running ARY");
        //Getting CLOCK_STAT_ARY register value
        FAPI_TRY(fapi2::getScom(i_target, PERV_CLOCK_STAT_ARY,
                                l_ary_clock_status)); //l_ary_clock_status = CLOCK_STAT_ARY
        FAPI_INF("Expected value is %#018lX, Actaul value is %#018lX",
                 l_exp_ary_clock_status, l_ary_clock_status);

        FAPI_ASSERT(l_ary_clock_status == l_exp_ary_clock_status,
                    fapi2::ARY_ERR()
                    .set_READ_CLK_ARY(l_ary_clock_status),
                    "CLOCK RUNNING STATUS IS NOT MATCHING WITH EXPECTED VALUE FOR ARRAY TYPE");
    }

    FAPI_DBG("Exiting ...");

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
    FAPI_DBG("Entering ...");

    //Setting OPCG_ALIGN register value
    FAPI_TRY(fapi2::getScom(i_target_chiplets, PERV_OPCG_ALIGN, l_data64));
    l_data64.insertFromRight<PEC_OPCG_ALIGN_SCAN_RATIO, PEC_OPCG_ALIGN_SCAN_RATIO_LEN>
    (0xE0);  //OPCG_ALIGN.SCAN_RATIO = 0xE0
    FAPI_TRY(fapi2::putScom(i_target_chiplets, PERV_OPCG_ALIGN, l_data64));

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
