/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_chiplet_enable_ridi.C $       */
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
/// @file  p9_chiplet_enable_ridi.C
///
/// @brief Enable RI/DI chip wide
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_chiplet_enable_ridi.H"

#include "p9_perv_scom_addresses.H"

static fapi2::ReturnCode p9_chiplet_enable_ridi_net_ctrl_action_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet);

fapi2::ReturnCode p9_chiplet_enable_ridi(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    FAPI_DBG("Entering ...");

    for(auto l_target_cplt : i_target_chip.getChildren<fapi2::TARGET_TYPE_PERV>
        (fapi2::TARGET_FILTER_SYNC_MODE_ALL_IO_EXCEPT_NEST, fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_INF("Call p9_chiplet_enable_ridi_net_ctrl_action_function");
        FAPI_TRY(p9_chiplet_enable_ridi_net_ctrl_action_function(l_target_cplt));
    }

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Enable Drivers/Recievers of MC, ABUS, OBUS, XBUS chiplet
///
/// @param[in]     i_target_chiplet   Reference to TARGET_TYPE_PERV target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode p9_chiplet_enable_ridi_net_ctrl_action_function(
    const fapi2::Target<fapi2::TARGET_TYPE_PERV>& i_target_chiplet)
{
    bool l_read_reg = false;
    fapi2::buffer<uint64_t> l_data64;
    FAPI_DBG("Entering ...");

    FAPI_INF("Check for chiplet enable");
    //Getting NET_CTRL0 register value
    FAPI_TRY(fapi2::getScom(i_target_chiplet, PERV_NET_CTRL0, l_data64));
    l_read_reg = l_data64.getBit<0>();  //l_read_reg = NET_CTRL0.CHIPLET_ENABLE

    if ( l_read_reg )
    {
        FAPI_INF("Enable Recievers, Drivers DI1 & DI2");
        //Setting NET_CTRL0 register value
        l_data64.flush<0>();
        l_data64.setBit<19>();  //NET_CTRL0.RI_N = 1
        l_data64.setBit<20>();  //NET_CTRL0.DI1_N = 1
        l_data64.setBit<21>();  //NET_CTRL0.DI2_N = 1
        FAPI_TRY(fapi2::putScom(i_target_chiplet, PERV_NET_CTRL0_WOR, l_data64));
    }

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
