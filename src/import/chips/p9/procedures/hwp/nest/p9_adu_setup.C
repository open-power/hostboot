/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_adu_setup.C $      */
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
//--------------------------------------------------------------------------
//
/// @file p9_adu_setup.C
/// @brief Setup the registers for a read/write to the ADU
//
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE
//
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_adu_setup.H>
#include <p9_adu_coherent_utils.H>

extern "C"
{

//--------------------------------------------------------------------------
//  HWP entry point
//--------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_setup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                   & i_target,
                                   const uint64_t i_address,
                                   const bool i_rnw,
                                   const uint32_t i_flags,
                                   uint32_t& o_numGranules)
    {
        //return code
        uint32_t num_attempts = 1;
        bool lock_pick = false;

        // mark HWP entry
        FAPI_DBG("Entering ...\n");

        //ADU status/control information
        bool adu_is_dirty = false;
        bool adu_leave_dirty = i_flags & FLAG_LEAVE_DIRTY;

        //check arguments
        FAPI_TRY(p9_adu_coherent_utils_check_args(i_target, i_address),
                 "Error from p9_adu_coherent_utils_check_args");

        //ensure fabric is running
        FAPI_TRY(p9_adu_coherent_utils_check_fbc_state(i_target),
                 "Error from p9_adu_coherent_utils_check_fbc_status");

        //reset ADU state machines and status register
        FAPI_TRY(p9_adu_coherent_utils_reset_adu(i_target), "p9_adu_setup: Error from p9_adu_coherent_utils_reset_adu");

        //acquire ADU lock to guarantee exclusive use of the ADU resources
        lock_pick = i_flags & FLAG_LOCK_PICK;
        num_attempts = i_flags & FLAG_LOCK_TRIES;
        FAPI_TRY(p9_adu_coherent_manage_lock(i_target, lock_pick, true, num_attempts),
                 "Error from p9_adu_coherent_manage_lock");

        //figure out how many granules can be requested before setup needs to be run again
        FAPI_TRY(p9_adu_coherent_utils_get_num_granules(i_address, o_numGranules),
                 "Error from p9_adu_coherent_utils_get_num_granules");

        //Set dirty since we need to attempt to cleanup/release the lock so the ADU is not in a locked state if operation fails from this point
        adu_is_dirty = true;

        //setup the ADU registers for the read/write
        FAPI_TRY(p9_adu_coherent_setup_adu(i_target, i_address, i_rnw, i_flags),
                 "Error from p9_adu_coherent_setup_registers");

    fapi_try_exit:
        fapi2::ReturnCode saveError = fapi2::current_err;

        //if an error has occurred, ADU is dirty, and instructed to clean up,
        //attempt to reset ADU and free lock (propogate rc of original fail)
        if (fapi2::current_err && adu_is_dirty && !adu_leave_dirty)
        {
            (void) p9_adu_coherent_utils_reset_adu(i_target);
            (void) p9_adu_coherent_manage_lock(i_target, false, false, num_attempts);
        }

        FAPI_DBG("Exiting...");
        return saveError;
    }

} // extern "C"
