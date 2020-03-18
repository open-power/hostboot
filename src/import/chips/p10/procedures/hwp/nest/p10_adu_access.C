/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_access.C $   */
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
/// @file p10_adu_access.C
/// @brief Read coherent state of memory via the adu
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE
///

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p10_adu_access.H>
#include <p10_adu_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// ADU operation delay/polling constants for hw/sim
const uint32_t P10_ADU_ACCESS_ADU_OPER_HW_NS_DELAY     = 10000;
const uint32_t P10_ADU_ACCESS_ADU_OPER_SIM_CYCLE_DELAY = 50000;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode p10_adu_access(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_address,
    const bool i_rnw,
    const uint32_t i_flags,
    const bool i_firstGranule,
    const bool i_lastGranule,
    uint8_t io_data[])
{
    FAPI_DBG("Entering...");

    ////////////////////////////////////////////////////////
    // Local variables
    ////////////////////////////////////////////////////////
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    adu_operationFlag l_flags;

    ////////////////////////////////////////////////////////
    // Process and check input arguments/flags
    ////////////////////////////////////////////////////////

    FAPI_TRY(p10_adu_utils_check_args(i_target, i_address, i_flags, l_flags),
             "Error from p10_adu_utils_check_args");

    ////////////////////////////////////////////////////////
    // Exit if operation request is for a pre/post switch
    // These modify the adu switch AB/CD controls but do not
    // actually broadcast a fabric transaction
    ////////////////////////////////////////////////////////

    if ((l_flags.getOperationType() == adu_operationFlag::PRE_SWITCH_AB) ||
        (l_flags.getOperationType() == adu_operationFlag::PRE_SWITCH_CD) ||
        (l_flags.getOperationType() == adu_operationFlag::POST_SWITCH))
    {
        goto fapi_try_exit;
    }

    ////////////////////////////////////////////////////////
    // Clear autoinc flag if enabled and on last granule
    ////////////////////////////////////////////////////////

    if (l_flags.getAutoIncrement() && i_lastGranule)
    {
        FAPI_TRY(p10_adu_utils_clear_autoinc(i_target),
                 "Error from p10_adu_utils_clear_autoinc");
    }

    ////////////////////////////////////////////////////////
    // Execute the read/write operation
    ////////////////////////////////////////////////////////

    if (l_flags.isAddressOnly())
    {
        FAPI_TRY(fapi2::delay(P10_ADU_ACCESS_ADU_OPER_HW_NS_DELAY, P10_ADU_ACCESS_ADU_OPER_SIM_CYCLE_DELAY),
                 "Error with fapiDelay while waiting for an address-only adu operation");

        FAPI_TRY(p10_adu_utils_status_check(i_target, false, true));
    }
    else
    {
        if (i_rnw)
        {
            FAPI_TRY(p10_adu_utils_adu_read(i_target, i_firstGranule, i_lastGranule, i_address, l_flags, io_data),
                     "Error doing an adu read via p10_adu_utils_adu_read");
        }
        else
        {
            FAPI_TRY(p10_adu_utils_adu_write(i_target, i_firstGranule, i_lastGranule, i_address, l_flags, io_data),
                     "Error doing an adu write via p10_adu_utils_adu_write");
        }
    }

    // Cleanup the adu if the last read/write operation
    if (i_lastGranule)
    {
        FAPI_TRY(p10_adu_utils_cleanup_adu(i_target),
                 "Error cleaning up adu via p10_adu_utils_cleanup_adu");
    }

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
    // Note: Clean up if an error has occurred unless
    //       flags indicate that the ADU status register
    //       should be left dirty
    ////////////////////////////////////////////////////////

    l_rc = fapi2::current_err; // Save current_err

    if (l_rc && l_flags.getOperFailCleanup())
    {
        (void) p10_adu_utils_reset_adu(i_target);
        (void) p10_adu_utils_manage_lock(i_target, false, false, l_flags.getNumLockAttempts());
    }

    FAPI_DBG("Exiting...");
    return l_rc;
}
