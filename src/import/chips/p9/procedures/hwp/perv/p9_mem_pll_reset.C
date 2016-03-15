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
// *HWP Level           : 1
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_mem_pll_reset.H"

fapi2::ReturnCode p9_mem_pll_reset(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chiplet)
{
    FAPI_DBG("Entering ...");

    FAPI_DBG("Exiting ...");

    return fapi2::FAPI2_RC_SUCCESS;

}
