/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_adu_access.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
// *HWP HWP Owner Joe McGill jmcgill@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: SBE
//
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_adu_access.H>
#include <p9_adu_coherent_utils.H>

// ADU operation delay times for HW/sim
const uint32_t P9_ADU_ACCESS_ADU_OPER_HW_NS_DELAY = 10000;
const uint32_t P9_ADU_ACCESS_ADU_OPER_SIM_CYCLE_DELAY = 50000;


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

        bool l_busyBitStatus = false;
        adu_status_busy_handler l_busyHandling;

        // mark HWP entry
        FAPI_DBG("Entering ...\n");

        // Process input flag
        p9_ADU_oper_flag l_myAduFlag;
        l_myAduFlag.getFlag(i_flags);

        //If autoinc is set and this is not a DMA operation unset autoinc before passing the flags through since autoinc is only allowed for DMA operations
        if (l_myAduFlag.getOperationType() != p9_ADU_oper_flag::DMA_PARTIAL)
        {
            l_myAduFlag.setAutoIncrement(false);
        }

        // don't generate fabric command
        if ((l_myAduFlag.getOperationType() == p9_ADU_oper_flag::PRE_SWITCH_AB) ||
            (l_myAduFlag.getOperationType() == p9_ADU_oper_flag::PRE_SWITCH_CD) ||
            (l_myAduFlag.getOperationType() == p9_ADU_oper_flag::POST_SWITCH))
        {
            goto fapi_try_exit;
        }

        //If we were using autoinc and this is the last granule we need to clear autoinc before the last read/write
        if( i_lastGranule && l_myAduFlag.getAutoIncrement() )
        {
            FAPI_TRY(p9_adu_coherent_clear_autoinc(i_target), "Error from p9_adu_coherent_clear_autoinc");
        }

        if (l_myAduFlag.isAddressOnly())
        {
            FAPI_TRY(fapi2::delay(P9_ADU_ACCESS_ADU_OPER_HW_NS_DELAY,
                                  P9_ADU_ACCESS_ADU_OPER_SIM_CYCLE_DELAY),
                     "fapiDelay error");
        }
        else
        {
            //If we are doing a read operation read the data
            if (i_rnw)
            {
                FAPI_TRY(p9_adu_coherent_adu_read(i_target, i_firstGranule, i_address, l_myAduFlag, io_data),
                         "Error from p9_adu_coherent_adu_read");
            }
            //Otherwise this is a write and write the data
            else
            {
                FAPI_TRY(p9_adu_coherent_adu_write(i_target, i_firstGranule, i_address, l_myAduFlag, io_data),
                         "Error from p9_adu_coherent_adu_write");
            }
        }

        //If we are not in fastmode or this is the last granule, we want to check the status
        if ( (i_lastGranule) || (l_myAduFlag.getFastMode() == false) )
        {
            //If we are using autoincrement and this is not the last granule we expect the busy bit to still be set
            if ( (l_myAduFlag.getAutoIncrement()) && !i_lastGranule )
            {
                l_busyHandling = EXPECTED_BUSY_BIT_SET;
            }
            //Otherwise we expect the busy bit to be cleared
            else
            {
                l_busyHandling = EXPECTED_BUSY_BIT_CLEAR;
            }

            //We only want to do the status check if this is not a ci operation
            if (l_myAduFlag.getOperationType() != p9_ADU_oper_flag::CACHE_INHIBIT)
            {
                FAPI_TRY(p9_adu_coherent_status_check(i_target, l_busyHandling, l_myAduFlag.isAddressOnly(),
                                                      l_busyBitStatus),
                         "Error from p9_adu_coherent_status_check");
            }

            //If it's the last read/write cleanup the adu
            if (i_lastGranule)
            {
                FAPI_TRY(p9_adu_coherent_cleanup_adu(i_target),
                         "Error doing p9_adu_coherent_cleanup_adu");
            }
        }

    fapi_try_exit:

        //If there is an error and we want to cleanup the ADU
        if ( fapi2::current_err && l_myAduFlag.getOperFailCleanup() )
        {
            //reset the ADU
            (void) p9_adu_coherent_utils_reset_adu(i_target);
            uint32_t num_attempts = l_myAduFlag.getNumLockAttempts();
            //Unlock the ADU
            (void) p9_adu_coherent_manage_lock(i_target, false, false, num_attempts);
        }

        //Append the input data to an error if we got an error back
#ifndef __PPE__

        if (fapi2::current_err)
        {
            p9_adu_coherent_append_input_data(i_address, i_rnw, i_flags, fapi2::current_err);
        }

#endif

        FAPI_DBG("Exiting...");
        //Return the error that we got from up above
        return fapi2::current_err;
    }

} // extern "C"
