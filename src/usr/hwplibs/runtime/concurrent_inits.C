/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwplibs/runtime/concurrent_inits.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

extern trace_desc_t* g_trac_hbrt;

void do_concurrent_inits( void )
{
    TRACFCOMP(g_trac_hbrt,
              ENTER_MRK "do_concurrent_inits" );

    //-----------------------------------------------------
    // Insert HWP calls here

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
