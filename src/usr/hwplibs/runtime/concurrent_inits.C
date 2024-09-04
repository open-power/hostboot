/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwplibs/runtime/concurrent_inits.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/**
 * @file concurrent_inits.C
 * @brief Contains logic related to executing any HWPs that need to run
 *        as part of a concurrent code update.
 */

#include <hbotcompid.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fapi2/plat_hwp_invoker.H>
#include <runtime/interface.h>


// targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/targplatutil.H>
#include    <targeting/odyutil.H>     // isOdysseyChip

// HWP
#include  <chipids.H>
#include  <devicefw/driverif.H>
#include  <devicefw/userif.H>

using   namespace   ERRORLOG;
using   namespace   TARGETING;

extern trace_desc_t* g_trac_hbrt;

// This function is a hostboot workaround to
// unmask bit 12 of Odyssey chips to prevent
// unwanted SBE updates.
void do_ody_pll_unlock_errors_workaround(void)
{
    constexpr uint64_t CHIPLET1_REGISTER  = 0x010f001e;
    constexpr uint64_t UNMASK_BIT12 = 0xFFF7FFFFFFFFFFFF;
    size_t l_numBytes = 8;
    uint8_t l_buf[8] = {0};
    uint64_t l_data = 0ULL;
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_hbrt,
              ENTER_MRK "do_ody_pll_unlock_errors_workaround" );

    // Get all OCMB targets
    TARGETING::TargetHandleList l_ocmbTargetList;
    TARGETING::getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto l_ocmb_target : l_ocmbTargetList)
    {
        if (TARGETING::UTIL::isOdysseyChip(l_ocmb_target))
        {
            // To prevent undesirable SBE updates, we need to unmask (bit 12 of 0x010F001E).
            // To unmask we need to set that bit to 0 (as MASK bit is 1). We will do a
            // read modify write to set the 12th bit to 0.

            // First read the value...
            l_err = DeviceFW::deviceOp(DeviceFW::READ, l_ocmb_target, l_buf, l_numBytes,
                                       DEVICE_SCOM_ADDRESS(CHIPLET1_REGISTER));
            if (!l_err)
            {
                // Unmask the 12th bit
                l_data = *(reinterpret_cast<uint64_t *>(l_buf));
                l_data &= UNMASK_BIT12;

                // Now write the data back to the register
                l_err = DeviceFW::deviceOp(DeviceFW::WRITE, l_ocmb_target,
                                   reinterpret_cast<uint8_t *>(&l_data),
                                   l_numBytes,
                                   DEVICE_SCOM_ADDRESS(CHIPLET1_REGISTER));
                if (l_err)
                {
                    TRACFCOMP(g_trac_hbrt,
                              ERR_MRK"ERROR from do_ody_pll_unlock_errors_workaround: Scom write to tgt HUID 0x%.8X"
                              "Address=0x%x Data=0x%16x",
                              get_huid(l_ocmb_target), CHIPLET1_REGISTER, l_data);
                }
            }
            else
            {
                TRACFCOMP(g_trac_hbrt,
                          ERR_MRK"ERROR from do_ody_pll_unlock_errors_workaround: Scom Read from tgt HUID 0x%.8X"
                          "Address=0x%x", get_huid(l_ocmb_target), CHIPLET1_REGISTER);
            }

            if (l_err)
            {
                //Commit the log and keep going
                errlCommit(l_err, HWPF_COMP_ID);
            }

        } // end of check for Ody
    } // end of for loop

    TRACFCOMP(g_trac_hbrt,
              EXIT_MRK "do_ody_pll_unlock_errors_workaround" );

}


void do_concurrent_inits( void )
{

    TRACFCOMP(g_trac_hbrt,
              ENTER_MRK "do_concurrent_inits" );

    //-----------------------------------------------------
    // Insert HWP calls here
    //-----------------------------------------------------

    // Invoke the function to unmask bit 12 for Odyssey chips
    do_ody_pll_unlock_errors_workaround();

    TRACFCOMP(g_trac_hbrt,
              EXIT_MRK "do_concurrent_inits" );
}



// Create static object in order to register a callback
//  when the library is loaded
struct register_callDoConcurrentInits
{
    register_callDoConcurrentInits()
    {
        // Register interface for Host to call
        postInitCalls_t * rt_post = getPostInitCalls();
        rt_post->callDoConcurrentInits = &do_concurrent_inits;
    }

};
register_callDoConcurrentInits g_register_callDoConcurrentInits;
