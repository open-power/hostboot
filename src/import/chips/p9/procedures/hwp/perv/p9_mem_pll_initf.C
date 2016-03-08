/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_mem_pll_initf.C $             */
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
/// @file  p9_mem_pll_initf.C
///
/// @brief Scan MC ring bucket based on ATTR_MSS_FREQ.
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : HB
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_mem_pll_initf.H"

fapi2::ReturnCode p9_mem_pll_initf(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chiplet)
{
    uint64_t l_read_attr = 0;
    RingID ringID = mc_pll_bndy_bucket_1;
    FAPI_INF("Entering p9_mem_pll_initf ...");

    for (auto l_trgt_chplt : i_target_chiplet.getChildren<fapi2::TARGET_TYPE_MCBIST>
         (fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_INF("get the attribute ATTR_MSS_FREQ");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_FREQ, l_trgt_chplt, l_read_attr));

        switch(l_read_attr)
        {
            case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
                ringID = mc_pll_bndy_bucket_1;
                break;

            case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
                ringID = mc_pll_bndy_bucket_2;
                break;

            case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
                ringID = mc_pll_bndy_bucket_3;
                break;

            case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
                ringID = mc_pll_bndy_bucket_4;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::MSS_FREQ_VALUE_NOT_VALID()
                            .set_MSS_FREQ(l_read_attr)
                            .set_MCBIST_TARGET(l_trgt_chplt),
                            "Invalid value of ATTR_MSS_FREQ");
        }

        FAPI_TRY(fapi2::putRing(l_trgt_chplt, ringID, fapi2::RING_MODE_SET_PULSE_NSL));
    }

    FAPI_INF("Exiting p9_mem_pll_initf ...");

fapi_try_exit:
    return fapi2::current_err;
}

