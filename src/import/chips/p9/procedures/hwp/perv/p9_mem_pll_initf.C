/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_mem_pll_initf.C $  */
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
#include <p9_ring_id.h>



fapi2::ReturnCode p9_mem_pll_initf(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    FAPI_INF("Entering ...");

    uint8_t l_sync_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MC_SYNC_MODE, i_target_chip, l_sync_mode),
             "Error from FAPI_ATTR_GET (ATTR_MC_SYNC_MODE)");

    if (l_sync_mode == 0)
    {
        FAPI_DBG("Re-scanning PLL ring to set final frequency");

        for (auto l_mcbist_target : i_target_chip.getChildren<fapi2::TARGET_TYPE_MCBIST>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            uint64_t l_mss_freq = 0;
            RingID l_ring_id = mc_pll_bndy_bucket_1;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_FREQ, l_mcbist_target, l_mss_freq),
                     "Error from FAPI_ATTR_GET (ATTR_MSS_FREQ)");

            switch (l_mss_freq)
            {
                case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
                    FAPI_DBG("Scan mc_pll_bndy_bucket_1 ring");
                    l_ring_id = mc_pll_bndy_bucket_1;
                    break;

                case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
                    FAPI_DBG("Scan mc_pll_bndy_bucket_2 ring");
                    l_ring_id = mc_pll_bndy_bucket_2;
                    break;

                case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
                    FAPI_DBG("Scan mc_pll_bndy_bucket_3 ring");
                    l_ring_id = mc_pll_bndy_bucket_3;
                    break;

                case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
                    FAPI_DBG("Scan mc_pll_bndy_bucket_4 ring");
                    l_ring_id = mc_pll_bndy_bucket_4;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::P9_MEM_PLL_INITF_UNSUPPORTED_FREQ().
                                set_TARGET(l_mcbist_target).
                                set_MSS_FREQ(l_mss_freq),
                                "Unsupported MSS_FREQ attribute value!");
            }

            FAPI_TRY(fapi2::putRing(l_mcbist_target, l_ring_id, fapi2::RING_MODE_SET_PULSE_NSL),
                     "Error from putRing (mc_pll_bndy, ringID: %d)", l_ring_id);
        }
    }
    else
    {
        FAPI_DBG("Skipping PLL re-scan");
    }

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return fapi2::current_err;
}
