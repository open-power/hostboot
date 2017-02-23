/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_mem_startclocks.C $ */
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
#include "p9_sbe_chiplet_reset.H"  //For MCGR_CNFG_SETTING_GROUP


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

static fapi2::ReturnCode p9_mem_startclocks_fence_setup_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
    const fapi2::buffer<uint64_t> i_pg_vector);

static fapi2::ReturnCode p9_mem_startclocks_cplt_ctrl_action_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet);

static fapi2::ReturnCode p9_mem_startclocks_flushmode(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet);

static fapi2::ReturnCode p9_mem_startclocks_regions_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
    const fapi2::buffer<uint16_t> i_regions_except_vital_pll,
    fapi2::buffer<uint64_t>& o_regions_enabled_after_pg);

fapi2::ReturnCode p9_mem_startclocks(const
                                     fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    uint8_t l_sync_mode = 0;
    fapi2::buffer<uint64_t> l_pg_vector;
    fapi2::buffer<uint64_t> l_scom;
    fapi2::buffer<uint64_t> l_clock_regions;
    FAPI_DBG("Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MC_SYNC_MODE, i_target_chip, l_sync_mode),
             "Error from FAPI_ATTR_GET (ATTR_MC_SYNC_MODE)");

    FAPI_TRY(p9_sbe_common_get_pg_vector(i_target_chip, l_pg_vector));
    FAPI_DBG("pg targets vector: %#018lX", l_pg_vector);

    if (!l_sync_mode)
    {
        uint32_t l_fbc_system_id;
        uint8_t l_fbc_group_id;
        uint8_t l_fbc_chip_id;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_ID, i_target_chip, l_fbc_system_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_SYSTEM_ID)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID, i_target_chip, l_fbc_group_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_GROUP_ID)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID, i_target_chip, l_fbc_chip_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_CHIP_ID)");

        for (auto l_trgt_chplt : i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
             (fapi2::TARGET_FILTER_ALL_MC, fapi2::TARGET_STATE_FUNCTIONAL))
        {

            FAPI_INF("Call p9_mem_startclocks_cplt_ctrl_action_function for Mc chiplets");
            FAPI_TRY(p9_mem_startclocks_cplt_ctrl_action_function(l_trgt_chplt));

            FAPI_INF("Call module align chiplets for Mc chiplets");
            FAPI_TRY(p9_sbe_common_align_chiplets(l_trgt_chplt));

            FAPI_TRY(p9_mem_startclocks_regions_setup(l_trgt_chplt,
                     REGIONS_ALL_EXCEPT_VITAL_NESTPLL, l_clock_regions));

            FAPI_INF("Call module clock start stop for MC01, MC23.");
            FAPI_TRY(p9_sbe_common_clock_start_stop(l_trgt_chplt, CLOCK_CMD,
                                                    DONT_STARTSLAVE, DONT_STARTMASTER, l_clock_regions,
                                                    CLOCK_TYPES));

            FAPI_INF("Call p9_mem_startclocks_fence_setup_function for Mc chiplets ");
            FAPI_TRY(p9_mem_startclocks_fence_setup_function(l_trgt_chplt, l_pg_vector));

            FAPI_INF("Call p9_mem_startclocks_flushmode for Mc chiplets");
            FAPI_TRY(p9_mem_startclocks_flushmode(l_trgt_chplt));

            FAPI_INF("Call p9_sbe_common_configure_chiplet_FIR for MC chiplets");
            FAPI_TRY(p9_sbe_common_configure_chiplet_FIR(l_trgt_chplt));

            FAPI_INF("Reset FBC chiplet configuration");
            fapi2::buffer<uint64_t> l_cplt_conf0;
            FAPI_TRY(fapi2::getScom(l_trgt_chplt, PERV_CPLT_CONF0, l_cplt_conf0),
                     "Error from getScom (PERV_CPLT_CONF0)");
            l_cplt_conf0.insertFromRight<PERV_1_CPLT_CONF0_TC_UNIT_SYS_ID_DC, PERV_1_CPLT_CONF0_TC_UNIT_SYS_ID_DC_LEN>
            (l_fbc_system_id)
            .insertFromRight<PERV_1_CPLT_CONF0_TC_UNIT_GROUP_ID_DC, PERV_1_CPLT_CONF0_TC_UNIT_GROUP_ID_DC_LEN>(l_fbc_group_id)
            .insertFromRight<PERV_1_CPLT_CONF0_TC_UNIT_CHIP_ID_DC, PERV_1_CPLT_CONF0_TC_UNIT_CHIP_ID_DC_LEN>(l_fbc_chip_id);
            FAPI_TRY(fapi2::putScom(l_trgt_chplt, PERV_CPLT_CONF0, l_cplt_conf0),
                     "Error from putScom (PERV_CPLT_CONF0)");

            FAPI_INF("Add to Multicast Group");
            //Setting MULTICAST_GROUP_1 register value
            //Avoid setting if the register is already set -- if so, don't set
            //this prevents the multicast group from being corrupted, and allows
            //repeated calls to this function
            FAPI_TRY(fapi2::getScom(l_trgt_chplt, PERV_MULTICAST_GROUP_1, l_scom));

            if(l_scom == p9SbeChipletReset::MCGR_CNFG_SETTING_EMPTY)
            {
                FAPI_TRY(fapi2::putScom(l_trgt_chplt, PERV_MULTICAST_GROUP_1,
                                        p9SbeChipletReset::MCGR_CNFG_SETTING_GROUP0));
            }

            //Setting MULTICAST_GROUP_2 register value
            //Avoid setting if the register is already set -- if so, don't set
            //this prevents the multicast group from being corrupted, and allows
            //repeated calls to this function
            FAPI_TRY(fapi2::getScom(l_trgt_chplt, PERV_MULTICAST_GROUP_2, l_scom));

            if(l_scom == p9SbeChipletReset::MCGR_CNFG_SETTING_EMPTY)
            {
                FAPI_TRY(fapi2::putScom(l_trgt_chplt, PERV_MULTICAST_GROUP_2,
                                        p9SbeChipletReset::MCGR_CNFG_SETTING_GROUP2));
            }
        }
    }

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief --drop chiplet fence
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p9_mem_startclocks_fence_setup_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
    const fapi2::buffer<uint64_t> i_pg_vector)
{
    uint8_t l_read_attrunitpos = 0;
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_chiplet,
                           l_read_attrunitpos));

    if ( l_read_attrunitpos == 0x07 )
    {
        if ( i_pg_vector.getBit<5>() == 1 )
        {
            FAPI_DBG("Drop chiplet fence");
            //Setting NET_CTRL0 register value
            l_data64.flush<1>();
            l_data64.clearBit<PERV_1_NET_CTRL0_FENCE_EN>();  //NET_CTRL0.FENCE_EN = 0
            FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_NET_CTRL0_WAND, l_data64));
        }
    }

    if ( l_read_attrunitpos == 0x08 )
    {
        if ( i_pg_vector.getBit<3>() == 1 )
        {
            FAPI_DBG("Drop chiplet fence");
            //Setting NET_CTRL0 register value
            l_data64.flush<1>();
            l_data64.clearBit<PERV_1_NET_CTRL0_FENCE_EN>();  //NET_CTRL0.FENCE_EN = 0
            FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_NET_CTRL0_WAND, l_data64));
        }
    }

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
    fapi2::buffer <uint16_t> l_attr_pg;
    fapi2::buffer <uint16_t> l_cplt_ctrl_init;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, i_target_chiplet, l_attr_pg));

    l_attr_pg.invert();
    l_attr_pg.extractToRight<4, 11>(l_cplt_ctrl_init);

    FAPI_DBG("Drop partial good fences");
    //Setting CPLT_CTRL1 register value
    l_data64.flush<0>();
    l_data64.writeBit<PEC_CPLT_CTRL1_TC_VITL_REGION_FENCE>(l_attr_pg.getBit<3>());
    //CPLT_CTRL1.TC_ALL_REGIONS_FENCE = l_cplt_ctrl_init
    l_data64.insertFromRight<4, 11>(l_cplt_ctrl_init);
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL1_CLEAR, l_data64));

    FAPI_DBG("reset abistclk_muxsel and syncclk_muxsel");
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

    FAPI_DBG("Clear flush_inhibit to go in to flush mode");
    //Setting CPLT_CTRL0 register value
    l_data64.flush<0>();
    //CPLT_CTRL0.CTRL_CC_FLUSHMODE_INH_DC = 0
    l_data64.setBit<PEC_CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH_DC>();
    FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_CPLT_CTRL0_CLEAR, l_data64));

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Region value settings : The anding of REGIONS_ALL_EXCEPT_VITAL_NESTPLL, ATTR_PG
//  disables PLL region and retains enabled regions info from chiplet pg attribute.
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @param[in]     i_regions_except_vital_pll   regions except vital and pll
/// @param[out]    o_regions_enabled_after_pg   enabled regions value after anding with ATTR_PG
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p9_mem_startclocks_regions_setup(const
        fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet,
        const fapi2::buffer<uint16_t> i_regions_except_vital_pll,
        fapi2::buffer<uint64_t>& o_regions_enabled_after_pg)
{
    fapi2::buffer<uint16_t> l_read_attr = 0;
    fapi2::buffer<uint16_t> l_read_attr_invert = 0;
    fapi2::buffer<uint16_t> l_read_attr_shift1_right = 0;

    FAPI_DBG("p9_mem_startclocks_regions_setup: Entering ...");

    FAPI_DBG("Reading ATTR_PG");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, i_target_chiplet, l_read_attr));

    if ( l_read_attr == 0x0 )
    {
        o_regions_enabled_after_pg = static_cast<uint64_t>(i_regions_except_vital_pll) ;
    }
    else
    {
        l_read_attr_invert = l_read_attr.invert();
        l_read_attr_shift1_right = (l_read_attr_invert >> 1);
        o_regions_enabled_after_pg = (i_regions_except_vital_pll & l_read_attr_shift1_right);
    }

    FAPI_DBG("p9_mem_startclocks_regions_setup : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
