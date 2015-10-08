/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_adu_access.C $     */
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
//
/// @file p9_adu_access.C
/// @brief Read coherent state of memory via the ADU (FAPI)
///
// *HWP HWP Owner Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE
//
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_adu_access.H>
#include <p9_adu_coherent_utils.H>

extern "C" {

//--------------------------------------------------------------------------
//  HWP entry point
//--------------------------------------------------------------------------
    fapi2::ReturnCode p9_adu_access(const
                                    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                    const uint64_t i_address,
                                    const bool i_rnw,
                                    const uint32_t i_flags,
                                    const bool i_firstGranule,
                                    const bool i_lastGranule,
                                    uint8_t io_data[])
    {
        // mark HWP entry
        FAPI_DBG("Entering ...\n");

        if(i_lastGranule && (i_flags & FLAG_AUTOINC))
        {
            //call this function to clear the altd_auto_inc bit before the last iteration
            FAPI_TRY(p9_adu_coherent_clear_autoinc(i_target), "Error from p9_adu_coherent_clear_autoinc");
        }

        if (i_rnw)
        {
            //read the data
            FAPI_TRY(p9_adu_coherent_adu_read(i_target, i_firstGranule, i_address, i_flags, io_data),
                     "Error from p9_adu_coherent_adu_read");
        }
        else
        {
            //write the data
            FAPI_TRY(p9_adu_coherent_adu_write(i_target, i_firstGranule, i_address, i_flags, io_data),
                     "Error from p9_adu_coherent_adu_write");
        }

        //If we are not in fastmode or this is the last granule, we want to check the status
        if ((i_lastGranule) || !(i_flags & FLAG_FASTMODE))
        {
            FAPI_TRY(p9_adu_coherent_status_check(i_target, ((i_flags & FLAG_AUTOINC)
                                                  && !i_lastGranule)), "Error from p9_adu_coherent_status_check");

            //If it's the last read/write
            if (i_lastGranule)
            {
                FAPI_TRY(p9_adu_coherent_cleanup_adu(i_target),
                         "Error doing p9_adu_coherent_cleanup_adu");
            }
        }

    fapi_try_exit:

        if (fapi2::current_err
            && !(i_flags & FLAG_LEAVE_DIRTY))
        {
            (void) p9_adu_coherent_utils_reset_adu(i_target);
            uint32_t num_attempts = i_flags & FLAG_LOCK_TRIES;
            (void) p9_adu_coherent_manage_lock(i_target, false, false, num_attempts);
        }

        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

} // extern "C"
