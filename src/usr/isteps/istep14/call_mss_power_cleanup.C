/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_power_cleanup.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{
void* call_mss_power_cleanup (void *io_pArgs)
{
    errlHndl_t  l_err  =   NULL;
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_power_cleanup entry" );

    // Get a list of all present Centaurs
    TargetHandleList l_presCentaurs;
    getChipResources(l_presCentaurs, TYPE_MEMBUF, UTIL_FILTER_PRESENT);

    // For each present Centaur
    for (TargetHandleList::const_iterator
            l_cenIter = l_presCentaurs.begin();
            l_cenIter != l_presCentaurs.end();
            ++l_cenIter)
    {
        // Make a local copy of the target for ease of use
        TARGETING::Target * l_pCentaur = *l_cenIter;
        // Retrieve HUID of current Centaur
        TARGETING::ATTR_HUID_type l_currCentaurHuid =
            TARGETING::get_huid(l_pCentaur);

        // Find all present MBAs associated with this Centaur
        TARGETING::TargetHandleList l_presMbas;
        getChildAffinityTargetsByState(l_presMbas,
                                       l_pCentaur,
                                       CLASS_UNIT,
                                       TYPE_MBA,
                                       UTIL_FILTER_PRESENT);

        // If not at least two MBAs found
        if (l_presMbas.size() < 2)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Not enough MBAs found for Centaur target HUID %.8X, "
              "skipping this Centaur.",
               l_currCentaurHuid);
            continue;
        }

        // Cache current MBA HUIDs for tracing
        TARGETING::ATTR_HUID_type l_currMBA0Huid =
                    TARGETING::get_huid(l_presMbas[0]);
        TARGETING::ATTR_HUID_type l_currMBA1Huid =
                    TARGETING::get_huid(l_presMbas[1]);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_power_cleanup HWP on "
                "Centaur HUID %.8X, MBA0 HUID %.8X, "
                "MBA1 HUID %.8X, ", l_currCentaurHuid,
                        l_currMBA0Huid, l_currMBA1Huid);

        // Create FAPI Targets.
        // @TODO RTC:133831
        /*const fapi::Target l_fapiCentaurTarget(TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)));
        const fapi::Target l_fapiMba0Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[0])));
        const fapi::Target l_fapiMba1Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[1])));

        //  Call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_power_cleanup, l_fapiCentaurTarget,
                        l_fapiMba0Target, l_fapiMba1Target);
        */
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "mss_power_cleanup HWP failed to perform"
                      " cleanup on centaur: 0x%.8X HWP_ERROR: 0x%.8X",
                      l_currCentaurHuid,l_err->reasonCode());
            // Capture the target data in the error log
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);
            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(l_err);
            // Commit error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            // Success
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran mss_power_cleanup HWP on "
                    "Centaur HUID %.8X, MBA0 HUID %.8X, "
                    "MBA1 HUID %.8X, ", l_currCentaurHuid,
                           l_currMBA0Huid, l_currMBA1Huid);
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_power_cleanup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
