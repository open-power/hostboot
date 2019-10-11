/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_adu_ctrl.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// ----------------------------------------------------------------------------
/// @file  p10_htm_adu_ctrl.C
///
/// @brief Provides ADU control functions that help with HTM collection actions.
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Owner    : Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_htm_adu_ctrl.H>
//TODO: Update with Scom headers, remove unnecessary constants, remove P9 HW specific
//      bug workarounds, make P10 specific changes.

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
// Status time-out
const uint32_t P10_HTM_START_MAX_STATUS_POLLS = 100;

///
/// See doxygen in p10_htm_adu_ctrl.H
///
fapi2::ReturnCode aduNHTMControl(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_addr)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    //uint8_t l_num_attempts = 2;
    //bool l_adu_is_dirty = false;
    //uint32_t l_num_polls = 0;
    //bool l_busy_bit_status = false;
    //adu_status_busy_handler l_busy_handling = EXIT_ON_BUSY;

    //// validate input action, set ADU operation parameters
    //p10_ADU_oper_flag l_adu_oper_flag;

    //// Setup ADU operation
    //l_adu_oper_flag.setOperationType(p10_ADU_oper_flag::PMISC_OPER);
    //l_adu_oper_flag.setTransactionSize(p10_ADU_oper_flag::TSIZE_2);

    //// Acquire ADU lock
    //FAPI_TRY(p10_adu_coherent_manage_lock( i_target,
    //                                      false,
    //                                      true,           // Acquire lock
    //                                      l_num_attempts),
    //         "Error from p10_adu_coherent_manage_lock (acquire all)");

    //// NOTE: lock is now held, if an operation fails from this point
    ////       to the end of the procedure, need to reset and unlock.
    //l_adu_is_dirty = true;

    //// Reset ADU

    //if (l_rc)
    //{
    //    goto adu_reset_unlock;
    //}

    //// Issue operation
    //l_rc = p10_adu_coherent_setup_adu(i_target,
    //                                 i_addr,
    //                                 false,      // write
    //                                 l_adu_oper_flag.setFlag());

    //if (l_rc)
    //{
    //    FAPI_ERR("Error from p10_adu_coherent_setup_adu (op)");
    //    goto adu_reset_unlock;
    //}

    //// Check status
    //// Wait for operation to be completed (busy bit cleared)
    //l_busy_bit_status = false;

    //while (l_num_polls < P10_HTM_START_MAX_STATUS_POLLS)
    //{
    //    l_rc = p10_adu_coherent_status_check(i_target,
    //                                        l_busy_handling,
    //                                        true,
    //                                        l_busy_bit_status);

    //    if (l_rc)
    //    {
    //        FAPI_ERR("p10_adu_coherent_status_check() returns error");
    //        goto adu_reset_unlock;
    //    }

    //    if (l_busy_bit_status == true)
    //    {
    //        l_num_polls++;

    //        // last try, set handler to expect busy bit clear, if not then
    //        // p10_adu_coherent_status_check() will log an error so that
    //        // we don't have to deal with the error separately here.
    //        if (l_num_polls == (P10_HTM_START_MAX_STATUS_POLLS - 1))
    //        {
    //            l_busy_handling = EXPECTED_BUSY_BIT_CLEAR;
    //        }
    //    }
    //    else
    //    {
    //        // Operation done, break out
    //        break;
    //    }
    //}

    //// Unlock ADUs
    //FAPI_DBG("Operation complete, releasing lock for all ADU units in drawer");
    //l_rc = p10_adu_coherent_manage_lock(i_target,
    //                                   false,
    //                                   false, // Release lock
    //                                   l_num_attempts);

    //if (l_rc)
    //{
    //    FAPI_ERR("Error from p10_adu_coherent_manage_lock (release all)");
    //    goto adu_reset_unlock;
    //}

    //FAPI_DBG("All ADU locks released");
    //// No error for entire operation
    //l_adu_is_dirty = false;

adu_reset_unlock:

    // if error has occurred and any ADU is dirty,
    // attempt to reset all ADUs and free locks (propogate rc of original fail)
    //if (l_rc && l_adu_is_dirty)
    //{
    //    FAPI_INF("Attempting to reset/free lock on all ADUs");
    //    // Unlock ADUs
    //    // ignore return codes
    //    (void) p10_adu_coherent_manage_lock(i_target,
    //                                       false, // No lock pick
    //                                       false, // Lock release
    //                                       1);    // Attempt 1 time
    //}

fapi_try_exit:
    FAPI_DBG("Exiting");
    return l_rc;
}
