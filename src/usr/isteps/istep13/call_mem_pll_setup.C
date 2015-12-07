/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mem_pll_setup.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] Google Inc.                                                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_13
{
void* call_mem_pll_setup (void *io_pArgs)
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mem_pll_setup HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        //@TODO RTC:133831 Cast to a FAPI type of target.
        //const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
        //         (const_cast<TARGETING::Target*>(l_pCentaur)));

        //call cen_mem_pll_setup to verify lock
        //FAPI_INVOKE_HWP(l_err, cen_mem_pll_setup, l_fapi_centaur);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mem_pll_setup HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: mem_pll_setup HWP( )" );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup exit" );

    return l_StepError.getErrorHandle();
}

};
