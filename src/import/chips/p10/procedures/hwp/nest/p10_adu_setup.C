/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_setup.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_adu_setup.C
/// @brief Setup the adu to issue powerbus commands or coherent reads/writes
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_adu_setup.H>
#include <p10_adu_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_adu_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_address,
    const bool i_rnw,
    const uint32_t i_flags,
    uint32_t& o_numGranules)
{
    FAPI_DBG("Entering...");

    ////////////////////////////////////////////////////////
    // Local variables
    ////////////////////////////////////////////////////////
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    adu_operationFlag l_aduFlag;
    uint32_t l_flags;
    bool l_aduIsDirty = false;

    ////////////////////////////////////////////////////////
    // Read input flags and fix unsupported conditions
    // Note: Auto increment is only supported for dma
    ////////////////////////////////////////////////////////

    l_aduFlag.getFlag(i_flags);

    if (l_aduFlag.getOperationType() != adu_operationFlag::DMA_PARTIAL)
    {
        l_aduFlag.setAutoIncrement(false);
    }

    l_flags = l_aduFlag.setFlag();

    ////////////////////////////////////////////////////////
    // For pre/post switch operations, modify the adu
    // switch AB/CD controls only; this does not result
    // in a fabric transaction being broadcast so skip
    // any following checks
    ////////////////////////////////////////////////////////

    if ((l_aduFlag.getOperationType() == adu_operationFlag::PRE_SWITCH_AB) ||
        (l_aduFlag.getOperationType() == adu_operationFlag::PRE_SWITCH_CD) ||
        (l_aduFlag.getOperationType() == adu_operationFlag::POST_SWITCH))
    {
        FAPI_TRY(p10_adu_utils_set_switch_action(i_target,
                 (l_aduFlag.getOperationType() == adu_operationFlag::PRE_SWITCH_AB),
                 (l_aduFlag.getOperationType() == adu_operationFlag::PRE_SWITCH_CD)),
                 "Error from p10_adu_utils_set_switch_action");
        o_numGranules = 1;
        goto fapi_try_exit;
    }

    ////////////////////////////////////////////////////////
    // Process coherent read/write options
    // Note: Check the address alignment and figure out how
    //       many granules can be requested before setup
    //       needs to be run again
    ////////////////////////////////////////////////////////

    if ((l_aduFlag.getOperationType() == adu_operationFlag::CACHE_INHIBIT) ||
        (l_aduFlag.getOperationType() == adu_operationFlag::DMA_PARTIAL))
    {
        FAPI_TRY(p10_adu_utils_check_args(i_target, i_address, l_flags),
                 "Error from p10_adu_utils_check_args");
    }

    if (l_aduFlag.getAutoIncrement() == true)
    {
        FAPI_TRY(p10_adu_utils_get_num_granules(i_address, o_numGranules),
                 "Error from p10_adu_utils_get_num_granules");
    }
    else
    {
        o_numGranules = 1;
    }

    ////////////////////////////////////////////////////////
    // Check fabric state, acquire lock, setup adu command
    // Note: Only check fabric state if not doing a pbinit
    ////////////////////////////////////////////////////////

    if (l_aduFlag.getOperationType() != adu_operationFlag::PB_INIT_OPER)
    {
        FAPI_TRY(p10_adu_utils_check_fbc_state(i_target),
                 "Error from p10_adu_utils_check_fbc_status");
    }

    FAPI_TRY(p10_adu_utils_manage_lock(i_target, l_aduFlag.getLockControl(), true, l_aduFlag.getNumLockAttempts()),
             "Error from p10_adu_utils_manage_lock");

    // Indicate that ADU lock needs to be released in case we fail after this point
    l_aduIsDirty = true;

    FAPI_TRY(p10_adu_utils_setup_adu(i_target, i_address, i_rnw, l_flags),
             "Error from p10_adu_utils_setup_registers");

fapi_try_exit:

    //Append the input data to an error if we got an error back
#ifndef __PPE__

    if (fapi2::current_err)
    {
        p10_adu_utils_append_input_data(i_address, i_rnw, i_flags, fapi2::current_err);
    }

#endif

    ////////////////////////////////////////////////////////
    // Cleanup ADU registers
    // Note: Clean up if an error has occurred after the
    //       ADU was locked unless flags indicate that the
    //       ADU status register should be left dirty
    ////////////////////////////////////////////////////////

    l_rc = fapi2::current_err; // Save current_err

    if (l_rc && l_aduIsDirty && l_aduFlag.getOperFailCleanup())
    {
        (void) p10_adu_utils_reset_adu(i_target);
        (void) p10_adu_utils_manage_lock(i_target, false, false, l_aduFlag.getNumLockAttempts());
    }

    FAPI_DBG("Exiting...");
    return l_rc;
}
