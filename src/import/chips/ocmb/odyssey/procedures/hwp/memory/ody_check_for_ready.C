/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_check_for_ready.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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

///
/// @file ody_check_for_ready.C
/// @brief FW polls I2C slave interface to determine when it is ready
///
/// *HWP HWP Owner: Thi Tran thi@us.ibm.com
/// *HWP HWP Backup: <none>
/// *HWP Team: VBU
/// *HWP Level: 2
/// *HWP Consumed by: Hostboot / Cronus

#include <fapi2.H>
#include <ody_scom_ody.H>
#include <ody_check_for_ready.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C"
{

    SCOMT_ODY_USE_T_CFAM_FSI_W_FSI2PIB_STATUS;

// Constant definitions
    const uint8_t  MAX_I2C_ACTIVE_POLL = 2;  // Max # of polls waiting for I2C active
    const uint64_t SIM_CYC_DELAY = 0;
    const uint64_t MICRO_SEC_DELAY = 1000;

///
/// @brief Checks if the Odyssey I2C is ready to receive commands
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS if ok
///
    fapi2::ReturnCode ody_check_for_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        FAPI_DBG("ody_check_for_ready: Entering...");

        // scomt definitions
        using namespace scomt;
        using namespace scomt::ody;
        T_CFAM_FSI_W_FSI2PIB_STATUS_t FSI2PIB_STATUS;

        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        fapi2::ATTR_IS_SIMULATION_Type l_sim_env;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        // Skip delay polls if running on sim
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_sim_env),
                 "Error from FAPI_ATTR_GET (ATTR_IS_SIMULATION)");

        if (l_sim_env)
        {
            FAPI_INF("Sim environment, skipping ody_check_for_ready %s", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }
        else
        {
            // Polling until CFAM logic is active
            uint8_t l_poll = 0;

            while (l_poll < MAX_I2C_ACTIVE_POLL)
            {
                FAPI_DBG("Loop count: %d", l_poll);
                FAPI_TRY(fapi2::delay(MICRO_SEC_DELAY, SIM_CYC_DELAY), "fapiDelay error.");
                l_rc = FSI2PIB_STATUS.getCfam(i_target);

                if (l_rc == fapi2::FAPI2_RC_SUCCESS)
                {
                    FAPI_INF("OCMB %s is active.", mss::c_str(i_target));
                    break;
                }

                l_poll++;
            }

            FAPI_ASSERT(!l_rc,
                        fapi2::ODYSSEY_I2C_ERROR()
                        .set_OCMB_TARGET(i_target),
                        "Odyssey I2C is not active for target %s.", mss::c_str(i_target));
        }

    fapi_try_exit:
        FAPI_DBG("ody_check_for_ready: Exiting.");
        return fapi2::current_err;
    }

}// extern C
