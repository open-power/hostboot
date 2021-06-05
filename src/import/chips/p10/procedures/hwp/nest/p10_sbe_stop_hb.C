/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_stop_hb.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_sbe_stop_hb.C
/// @brief Stop instructions on any active cores, as part of HB cache contained
///        exit sequence

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by  : SBE
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_sbe_stop_hb.H>
#include <p10_thread_control.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_sbe_stop_hb(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& i_active_core_targets)
{
    FAPI_DBG("Start");

    fapi2::ReturnCode l_rc;
    ThreadSpecifier l_thread_list[MAX_NUM_OF_THREADS] =
    { THREAD0, THREAD1, THREAD2, THREAD3 };

    // determine running threads and stop them
    for (auto l_core_target : i_active_core_targets)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_core_num;
        fapi2::ATTR_ECO_MODE_Type l_eco_mode;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_core_target,
                               l_core_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE,
                               l_core_target,
                               l_eco_mode),
                 "Error from FAPI_ATTR_GET (ATTR_ECO_MODE)");

        FAPI_ASSERT(l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_DISABLED,
                    fapi2::P10_SBE_STOP_HB_ECO_MODE_ERR()
                    .set_TARGET(l_core_target),
                    "Core %d is marked as ECO, but is in set of active cores!",
                    l_core_num);

        for (auto l_thread_num = 0; l_thread_num < MAX_NUM_OF_THREADS; l_thread_num++)
        {
            FAPI_DBG("Processing active core: %d, thread: %d",
                     l_core_num, l_thread_num);

            fapi2::buffer<uint64_t> l_ras_status;
            uint64_t l_thread_state;

            FAPI_DBG("Querying current thread state");
            FAPI_EXEC_HWP(l_rc,
                          p10_thread_control,
                          l_core_target,
                          l_thread_list[l_thread_num],
                          PTC_CMD_QUERY,
                          false,
                          l_ras_status,
                          l_thread_state);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_thread_control (query, pre-stop)");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            if ((l_thread_state & THREAD_STATE_STOP) == THREAD_STATE_STOP)
            {
                FAPI_DBG("Thread is already stopped");
                continue;
            }

            FAPI_DBG("Requesting stop");
            FAPI_EXEC_HWP(l_rc,
                          p10_thread_control,
                          l_core_target,
                          l_thread_list[l_thread_num],
                          PTC_CMD_STOP,
                          false,
                          l_ras_status,
                          l_thread_state);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_thread_control (stop)");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            FAPI_DBG("Confirming current thread state");
            FAPI_EXEC_HWP(l_rc,
                          p10_thread_control,
                          l_core_target,
                          l_thread_list[l_thread_num],
                          PTC_CMD_QUERY,
                          false,
                          l_ras_status,
                          l_thread_state);

            if (l_rc)
            {
                FAPI_ERR("Error from p10_thread_control (query, post-stop)");
                fapi2::current_err = l_rc;
                goto fapi_try_exit;
            }

            FAPI_ASSERT((l_thread_state & THREAD_STATE_STOP) == THREAD_STATE_STOP,
                        fapi2::P10_SBE_EXIT_CACHE_CONTAINED_THREAD_STOP_ERR()
                        .set_TARGET(l_core_target)
                        .set_THREAD_NUM(l_thread_num)
                        .set_RAS_STATUS(l_ras_status),
                        "Core: %d thread: %d did not reach expected state after stop request!",
                        l_core_num, l_thread_num);
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
