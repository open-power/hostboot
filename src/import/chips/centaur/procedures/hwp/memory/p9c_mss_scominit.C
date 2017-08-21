/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9c_mss_scominit.C
/// @brief Calls the various memory initfiles
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB


//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------
#include <p9c_mss_scominit.H>
#include <centaur_mba_scom.H>
#include <centaur_mbs_scom.H>
#include <centaur_ddrphy_scom.H>
#include <fapi2.H>
#include <dimmConsts.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C" {
    /// @brief p9c_mss_scominit procedure: Calls the various memory initfiles
    /// @param[in] i_target [Reference to target, expecting centaur(MEMBUF) target]
    /// @return ReturnCode
    fapi2::ReturnCode p9c_mss_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
    {
        fapi2::buffer<uint64_t> l_scom_buffer;
        fapi2::ReturnCode l_rc;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        uint8_t l_unitPos = 0;
        FAPI_DBG("Performing HWP: mss_scominit");

        // Get a vector of the functional MBA targets
        const auto l_mba_targets = i_target.getChildren<fapi2::TARGET_TYPE_MBA>();
        const auto l_l4_targets = i_target.getChildren<fapi2::TARGET_TYPE_L4>(fapi2::TARGET_STATE_PRESENT);

        FAPI_ASSERT(l_l4_targets.size() > 0,
                    fapi2::CEN_MSS_SCOMINIT_NUM_L4_ERROR().
                    set_MEMBUF(i_target).
                    set_NUM_L4S(l_l4_targets.size()),
                    "No present L4 found on centaur %s", mss::c_str(i_target));

        //################ DDRPHY ######################
        for (const auto& mba : l_mba_targets)
        {
            // Find the position of the MBA chiplet
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, mba, l_unitPos));
            FAPI_DBG("MBA%i valid\n", l_unitPos);

            FAPI_EXEC_HWP(l_rc, centaur_ddrphy_scom, mba , FAPI_SYSTEM, i_target);

            if (l_rc)
            {
                FAPI_ERR("  !!!  Error running ddrphy scom initfile on %s, RC = 0x%x\n",
                         mss::c_str(mba), static_cast<uint32_t>(l_rc));
                return (l_rc);
            }
            else
            {
                FAPI_DBG("%s ddrphy scom initfile passed\n", mss::c_str(mba));
            }

        }

        //################ MBS ######################
        for (const auto& mba : l_mba_targets)
        {
            FAPI_DBG("Running MBS scom initfile\n");
            FAPI_EXEC_HWP(l_rc, centaur_mbs_scom, i_target, mba, l_l4_targets[0], FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("  !!!  Error running MBS scom initfile on %s\n", mss::c_str(i_target));
                return (l_rc);
            }
            else
            {
                FAPI_DBG("MBS scom initfile passed on %s\n", mss::c_str(i_target));
            }
        }

        //################ MBA ######################
        // Iterate through the returned chiplets
        for (const auto& mba : l_mba_targets)
        {
            // Find the position of the MBA chiplet
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, mba, l_unitPos));
            FAPI_DBG("MBA%i valid\n", l_unitPos);

            FAPI_EXEC_HWP(l_rc, centaur_mba_scom, mba, i_target, FAPI_SYSTEM);

            if (l_rc)
            {
                FAPI_ERR("  !!!  Error running MBA %s, RC = 0x%x\n",
                         mss::c_str(mba), static_cast<uint32_t>(l_rc));
                return (l_rc);
            }
            else
            {
                FAPI_DBG("%s MBA scom initfile passed\n", mss::c_str(mba));
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    } // end mss_scominit
} // extern "C"
