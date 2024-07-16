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
#include <p10_omi_ddr4_edpl.H>
#include <targeting/common/mfgFlagAccessors.H>

extern trace_desc_t* g_trac_hbrt;

void do_concurrent_inits( void )
{
    TRACFCOMP(g_trac_hbrt,
              ENTER_MRK "do_concurrent_inits" );
    errlHndl_t l_err = nullptr;

    //-----------------------------------------------------
    // Insert HWP calls here

    //-----------------------------------------------------
    // Apply P10 OMI DDR4 EDPL changes to active systems
    if (!TARGETING::isMfgOmiCrcEdplScreen())
    {
        TRACFCOMP(g_trac_hbrt,
                "Executing p10_omi_ddr4_edpl on all OCMBs" );

        TARGETING::TargetHandleList l_ocmbList;
        TARGETING::getAllChips( l_ocmbList,
                                TARGETING::TYPE_OCMB_CHIP,
                                true );
        for( const auto & l_ocmb : l_ocmbList )
        {
            const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
            l_fapiOcmb( l_ocmb );
            FAPI_INVOKE_HWP( l_err,
                            p10_omi_ddr4_edpl,
                            l_fapiOcmb,
                            false );
            if( l_err )
            {
                TRACFCOMP(g_trac_hbrt,
                        "FAILURE: p10_omi_ddr4_edpl on OCMB %.8X",
                        TARGETING::get_huid( l_ocmb ) );
                //Commit the log and keep going
                errlCommit(l_err, HWPF_COMP_ID);
            }
        }
    }
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
