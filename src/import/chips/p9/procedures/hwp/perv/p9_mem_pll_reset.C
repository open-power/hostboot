/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_mem_pll_reset.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
/// @file  p9_mem_pll_initf.C
///
/// @brief Reset pll buckets for MC Chiplets
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_mem_pll_reset.H"
#include "p9_perv_scom_addresses.H"

enum P9_MEM_PLL_RESET_Private_Constants
{
    MC_PLL_RESET_STATE = 0b111,
    MC_PLDY_DCC_BYPASS = 0b11,
    OPCG_ALIGN_SCAN_RATIO = 0b00000
};

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
            //Disable listen to sync pulse to MC chiplet, when MEM is not in sync to nest
            FAPI_DBG("Disable listen to sync pulse");
            FAPI_TRY(fapi2::getScom(l_chplt_trgt, PERV_SYNC_CONFIG, l_data64));
            //SYNC_CONFIG.listen_to_sync_dis=0b1
            l_data64.setBit<4>();
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_SYNC_CONFIG, l_data64));

            //Move MC PLL into reset state
            FAPI_DBG("Move MC PLL into reset state");
            l_data64.flush<0>();
            l_data64.insertFromRight<3, 3>(MC_PLL_RESET_STATE);
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL0_WOR, l_data64));

            //Assert MEM PDLY and DCC  bypass
            FAPI_DBG("Assert MEM PDLY and DCC  bypass");
            l_data64.flush<0>();
            l_data64.insertFromRight<1, 2>(MC_PLDY_DCC_BYPASS);
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_NET_CTRL1_WOR, l_data64));

            //OPCG_ALIGN.scan_ratio=0b00000 (1:1)
            FAPI_DBG("Set scan ratio to 1:1");
            FAPI_TRY(fapi2::getScom(l_chplt_trgt, PERV_OPCG_ALIGN, l_data64));
            l_data64.insertFromRight<47, 5>(OPCG_ALIGN_SCAN_RATIO);
            FAPI_TRY(fapi2::putScom(l_chplt_trgt, PERV_OPCG_ALIGN, l_data64));

        }
    }

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;
}
