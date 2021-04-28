/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwplibs/runtime/concurrent_inits.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#include <p9_fbc_tl_disable_gathering.H>

extern trace_desc_t* g_trac_hbrt;

void do_concurrent_inits( void )
{
    TRACFCOMP(g_trac_hbrt,
              ENTER_MRK "do_concurrent_inits" );

    errlHndl_t l_err = NULL;

    //-----------------------------------------------------
    // Dynamically disable TL data gathering

    TARGETING::TargetHandleList l_procList;
    // Get the system's procs
    TARGETING::getAllChips( l_procList,
                            TARGETING::TYPE_PROC,
                            true ); // true: return functional procs
    // Iterate over the found procs calling p9_fbc_tl_disable_gathering
    for( const auto & l_procTarget : l_procList )
    {
        // Cast to fapi2 target
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
          l_fapiProcTarget( l_procTarget );

        TRACFCOMP(g_trac_hbrt,
                  "Running p9_fbc_tl_disable_gathering HWP on processor target %.8X",
                  get_huid( l_procTarget ) );

        FAPI_INVOKE_HWP(l_err,
                        p9_fbc_tl_disable_gathering,
                        l_fapiProcTarget);

        if( l_err )
        {
            TRACFCOMP(g_trac_hbrt,
                      "FAILURE: p9_fbc_tl_disable_gathering on processor %.8X",
                      TARGETING::get_huid( l_procTarget ) );

            //Commit the log and keep going
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP(g_trac_hbrt,
                      "SUCCESS: p9_fbc_tl_disable_gathering" );
        }
    } // Processor Loop
    //-----------------------------------------------------


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
