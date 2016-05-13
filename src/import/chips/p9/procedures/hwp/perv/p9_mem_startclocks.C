/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_mem_startclocks.C $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
/// @file  p9_mem_startclocks.C
///
/// @brief Start clocks on MBA/MCAs
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_mem_startclocks.H"
#include "p9_const_common.H"
#include "p9_misc_scom_addresses_fld.H"
#include "p9_perv_scom_addresses.H"
#include "p9_perv_scom_addresses_fld.H"
#include "p9_quad_scom_addresses_fld.H"
#include "p9_sbe_common.H"


enum P9_MEM_STARTCLOCKS_Private_Constants
{
    CLOCK_CMD = 0x1,
    STARTSLAVE = 0x1,
    STARTMASTER = 0x1,
    REGIONS_ALL_EXCEPT_VITAL_NESTPLL = 0x7FE,
    CLOCK_TYPES = 0x7,
    DONT_STARTMASTER = 0x0,
    DONT_STARTSLAVE = 0x0
};

static fapi2::ReturnCode p9_mem_startclocks_check_checkstop_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet);

static fapi2::ReturnCode p9_mem_startclocks_cplt_ctrl_action_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet);

static fapi2::ReturnCode p9_mem_startclocks_flushmode(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet);

fapi2::ReturnCode p9_mem_startclocks(const
                                     fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    uint8_t l_sync_mode = 0;

    FAPI_DBG("Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MC_SYNC_MODE, i_target_chip, l_sync_mode),
             "Error from FAPI_ATTR_GET (ATTR_MC_SYNC_MODE)");

    if (!l_sync_mode)
    {
        for (auto l_trgt_chplt : i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
             (fapi2::TARGET_FILTER_ALL_MC, fapi2::TARGET_STATE_FUNCTIONAL))
        {

            FAPI_INF("Call p9_mem_startclocks_cplt_ctrl_action_function for Mc chiplets");
            FAPI_TRY(p9_mem_startclocks_cplt_ctrl_action_function(l_trgt_chplt));

            FAPI_INF("Call module align chiplets for Mc chiplets");
            FAPI_TRY(p9_sbe_common_align_chiplets(l_trgt_chplt));

            FAPI_INF("Call module clock start stop for MC01, MC23.");
            FAPI_TRY(p9_sbe_common_clock_start_stop(l_trgt_chplt, CLOCK_CMD,
                                                    DONT_STARTSLAVE, DONT_STARTMASTER, REGIONS_ALL_EXCEPT_VITAL_NESTPLL,
                                                    CLOCK_TYPES));

            FAPI_INF("Call p9_mem_startclocks_check_checkstop_function for Mc chiplets ");
            FAPI_TRY(p9_mem_startclocks_check_checkstop_function(l_trgt_chplt));

            FAPI_INF("Call p9_mem_startclocks_flushmode for Mc chiplets");
            FAPI_TRY(p9_mem_startclocks_flushmode(l_trgt_chplt));

        }
    }

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief --drop chiplet fence
/// --check checkstop register
/// --clear flush inhibit to go into flush mode
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p9_mem_startclocks_check_checkstop_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet)
{
    fapi2::buffer<uint64_t> l_read_reg;
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("Entering ...");

    FAPI_INF("Drop chiplet fence");
    //Setting NET_CTRL0 register value
    l_data64.flush<1>();
    l_data64.clearBit<PEC_STACK0_NET_CTRL0_FENCE_EN>();  //NET_CTRL0.FENCE_EN = 0
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_NET_CTRL0_WAND, l_data64));

    FAPI_INF("Check checkstop register");
    //Getting XFIR register value
    FAPI_TRY(fapi2::getScom(i_target_chiplet, PERV_XFIR,
                            l_read_reg)); //l_read_reg = XFIR

    FAPI_ASSERT(l_read_reg == 0,
                fapi2::READ_ALL_CHECKSTOP_ERR()
                .set_READ_ALL_CHECKSTOP(l_read_reg),
                "ERROR: COMBINE ALL CHECKSTOP ERROR");

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief --drop vital fence
/// --reset abstclk muxsel and syncclk muxsel
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p9_mem_startclocks_cplt_ctrl_action_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet)
{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("Entering ...");

    // Local variable and constant definition
    fapi2::buffer <uint32_t> l_attr_pg;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, i_target_chiplet, l_attr_pg));

    l_attr_pg.invert();

    FAPI_INF("Drop partial good fences");
    //Setting CPLT_CTRL1 register value
    l_data64.flush<0>();
    //CPLT_CTRL1.TC_VITL_REGION_FENCE = l_attr_pg.getBit<19>()
    l_data64.writeBit<PEC_CPLT_CTRL1_TC_VITL_REGION_FENCE>(l_attr_pg.getBit<19>());
    //CPLT_CTRL1.TC_PERV_REGION_FENCE = l_attr_pg.getBit<20>()
    l_data64.writeBit<PEC_CPLT_CTRL1_TC_PERV_REGION_FENCE>(l_attr_pg.getBit<20>());
    //CPLT_CTRL1.TC_REGION1_FENCE = l_attr_pg.getBit<21>()
    l_data64.writeBit<PEC_CPLT_CTRL1_TC_REGION1_FENCE>(l_attr_pg.getBit<21>());
    //CPLT_CTRL1.TC_REGION2_FENCE = l_attr_pg.getBit<22>()
    l_data64.writeBit<PEC_CPLT_CTRL1_TC_REGION2_FENCE>(l_attr_pg.getBit<22>());
    //CPLT_CTRL1.TC_REGION3_FENCE = l_attr_pg.getBit<23>()
    l_data64.writeBit<PERV_1_CPLT_CTRL1_TC_REGION3_FENCE>(l_attr_pg.getBit<23>());
    //CPLT_CTRL1.TC_REGION4_FENCE = l_attr_pg.getBit<24>()
    l_data64.writeBit<EQ_CPLT_CTRL1_TC_REGION4_FENCE>(l_attr_pg.getBit<24>());
    //CPLT_CTRL1.TC_REGION5_FENCE = l_attr_pg.getBit<25>()
    l_data64.writeBit<EQ_CPLT_CTRL1_TC_REGION5_FENCE>(l_attr_pg.getBit<25>());
    //CPLT_CTRL1.TC_REGION6_FENCE = l_attr_pg.getBit<26>()
    l_data64.writeBit<EQ_CPLT_CTRL1_TC_REGION6_FENCE>(l_attr_pg.getBit<26>());
    //CPLT_CTRL1.TC_REGION7_FENCE = l_attr_pg.getBit<27>()
    l_data64.writeBit<EQ_CPLT_CTRL1_TC_REGION7_FENCE>(l_attr_pg.getBit<27>());
    //CPLT_CTRL1.UNUSED_12B = l_attr_pg.getBit<28>()
    l_data64.writeBit<PEC_CPLT_CTRL1_UNUSED_12B>(l_attr_pg.getBit<28>());
    //CPLT_CTRL1.UNUSED_13B = l_attr_pg.getBit<29>()
    l_data64.writeBit<PEC_CPLT_CTRL1_UNUSED_13B>(l_attr_pg.getBit<29>());
    //CPLT_CTRL1.UNUSED_14B = l_attr_pg.getBit<30>()
    l_data64.writeBit<PEC_CPLT_CTRL1_UNUSED_14B>(l_attr_pg.getBit<30>());
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL1_CLEAR, l_data64));

    FAPI_INF("reset abistclk_muxsel and syncclk_muxsel");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_ABSTCLK_MUXSEL_DC = 1
    l_data64.writeBit<PEC_CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC>(1);
    //CPLT_CTRL0.TC_UNIT_SYNCCLK_MUXSEL_DC = 1
    l_data64.writeBit<PEC_CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC>(1);
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief will force all chiplets out of flush
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p9_mem_startclocks_flushmode(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet)
{
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("Entering ...");

    FAPI_INF("Clear flush_inhibit to go in to flush mode");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FLUSHMODE_INH_DC = 0
    l_data64.setBit<PEC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
