/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_adu_access.C $   */
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
    FAPI_DBG("Entering ...");

    ////////////////////////////////////////////////////////
    // Local variables
    ////////////////////////////////////////////////////////
    adu_operationFlag l_aduFlag;
    bool l_expBusyState;

    ////////////////////////////////////////////////////////
    // Read input flags and fix unsupported conditions
    // Note: Auto increment is only supported for dma
    ////////////////////////////////////////////////////////

    l_aduFlag.getFlag(i_flags);

    if (l_aduFlag.getOperationType() != adu_operationFlag::DMA_PARTIAL)
    {
        l_aduFlag.setAutoIncrement(false);
    }

    ////////////////////////////////////////////////////////
    // Exit if operation request is for a pre/post switch
    // These modify the adu switch AB/CD controls but do not
    // actually broadcast a fabric transaction
    ////////////////////////////////////////////////////////

    if ((l_aduFlag.getOperationType() == adu_operationFlag::PRE_SWITCH_AB) ||
        (l_aduFlag.getOperationType() == adu_operationFlag::PRE_SWITCH_CD) ||
        (l_aduFlag.getOperationType() == adu_operationFlag::POST_SWITCH))
    {
        goto fapi_try_exit;
    }

    ////////////////////////////////////////////////////////
    // Clear autoinc flag if enabled and on last granule
    ////////////////////////////////////////////////////////

    if (l_aduFlag.getAutoIncrement() && i_lastGranule)
    {
        FAPI_TRY(p10_adu_utils_clear_autoinc(i_target), "Error from p10_adu_utils_clear_autoinc");
    }

    ////////////////////////////////////////////////////////
    // Execute the read/write operation
    ////////////////////////////////////////////////////////

    if (l_aduFlag.isAddressOnly())
    {
        FAPI_TRY(fapi2::delay(P10_ADU_ACCESS_ADU_OPER_HW_NS_DELAY, P10_ADU_ACCESS_ADU_OPER_SIM_CYCLE_DELAY),
                 "Error with fapiDelay while waiting for an address-only adu operation");
    }
    else
    {
        // If we are doing a read operation read the data
        if (i_rnw)
        {
            FAPI_TRY(p10_adu_utils_adu_read(i_target, i_firstGranule, i_address, l_aduFlag, io_data),
                     "Error doing an adu read via p10_adu_utils_adu_read");
        }
        // Otherwise this is a write operation write the data
        else
        {
            FAPI_TRY(p10_adu_utils_adu_write(i_target, i_firstGranule, i_address, l_aduFlag, io_data),
                     "Error doing an adu write via p10_adu_utils_adu_write");
        }
    }

    ////////////////////////////////////////////////////////
    // Check the adu status after operation is complete
    ////////////////////////////////////////////////////////

    // If we are not in fastmode or this is the last granule, check the status
    if (!l_aduFlag.getFastMode() || i_lastGranule)
    {
        // If using autoincrement and this is not the last granule we expect the busy bit to still be set
        if ((l_aduFlag.getAutoIncrement()) && !i_lastGranule)
        {
            l_expBusyState = true;
        }
        // Otherwise we expect the busy bit to be cleared
        else
        {
            l_expBusyState = false;
        }

        // Only do the status check if this is not a ci operation
        if (l_aduFlag.getOperationType() != adu_operationFlag::CACHE_INHIBIT)
        {
            FAPI_TRY(p10_adu_utils_status_check(i_target, l_expBusyState, l_aduFlag.isAddressOnly()),
                     "Error checking adu status via p10_adu_utils_status_check");
        }

        // Cleanup the adu if the last read/write operation
        if (i_lastGranule)
        {
            FAPI_TRY(p10_adu_utils_cleanup_adu(i_target),
                     "Error cleaning up adu via p10_adu_utils_cleanup_adu");
        }
    }

fapi_try_exit:

    ////////////////////////////////////////////////////////
    // Cleanup ADU registers
    // Note: Clean up regardless of error/success unless
    //       flags indicate that the ADU status register
    //       should be left dirty
    ////////////////////////////////////////////////////////

    if (l_aduFlag.getOperFailCleanup())
    {
        (void) p10_adu_utils_reset_adu(i_target);
        (void) p10_adu_utils_manage_lock(i_target, false, false, l_aduFlag.getNumLockAttempts());
    }

    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}
