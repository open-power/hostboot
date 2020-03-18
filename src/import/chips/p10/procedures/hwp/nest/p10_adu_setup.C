/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_setup.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <fapi2.H>
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
    adu_operationFlag l_flags;
    bool l_aduIsDirty = false;

    // set default output value, modify only if handling
    // auto-increment
    o_numGranules = 1;

    ////////////////////////////////////////////////////////
    // Process and check input arguments/flags
    ////////////////////////////////////////////////////////

    FAPI_TRY(p10_adu_utils_check_args(i_target, i_address, i_flags, l_flags),
             "Error from p10_adu_utils_check_args");

    ////////////////////////////////////////////////////////
    // For pre/post switch operations, modify the adu
    // switch AB/CD controls only; this does not result
    // in a fabric transaction being broadcast so skip
    // any following checks
    ////////////////////////////////////////////////////////

    if ((l_flags.getOperationType() == adu_operationFlag::PRE_SWITCH_AB) ||
        (l_flags.getOperationType() == adu_operationFlag::PRE_SWITCH_CD) ||
        (l_flags.getOperationType() == adu_operationFlag::POST_SWITCH))
    {
        FAPI_TRY(p10_adu_utils_set_switch_action(i_target,
                 (l_flags.getOperationType() == adu_operationFlag::PRE_SWITCH_AB),
                 (l_flags.getOperationType() == adu_operationFlag::PRE_SWITCH_CD)),
                 "Error from p10_adu_utils_set_switch_action");
        goto fapi_try_exit;
    }

    ////////////////////////////////////////////////////////
    // Adjust granule count for auto-increment cases only
    ////////////////////////////////////////////////////////

    if (l_flags.getAutoIncrement() == true)
    {
        FAPI_TRY(p10_adu_utils_get_num_granules(i_address, o_numGranules),
                 "Error from p10_adu_utils_get_num_granules");
    }

    ////////////////////////////////////////////////////////
    // Check fabric state, acquire lock, setup adu command
    // Note: Skip fabric state check for pbinit, since
    ///      the fabric will potentially be unitialized
    ////////////////////////////////////////////////////////

    if (l_flags.getOperationType() != adu_operationFlag::PB_INIT_OPER)
    {
        FAPI_TRY(p10_adu_utils_check_fbc_state(i_target),
                 "Error from p10_adu_utils_check_fbc_status");
    }

    FAPI_TRY(p10_adu_utils_manage_lock(i_target, l_flags.getLockControl(), true, l_flags.getNumLockAttempts()),
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

    if (l_rc && l_aduIsDirty && l_flags.getOperFailCleanup())
    {
        (void) p10_adu_utils_reset_adu(i_target);
        (void) p10_adu_utils_manage_lock(i_target, false, false, l_flags.getNumLockAttempts());
    }

    FAPI_DBG("Exiting...");
    return l_rc;
}
