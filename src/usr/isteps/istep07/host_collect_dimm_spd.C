/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/host_collect_dimm_spd.C $              */
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
/**
 *  @file host_collect_dimm_spd.C
 *  Contains the wrapper for istep 7.1
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <isteps/hwpisteperror.H>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <initservice/isteps_trace.H>

#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <config.h>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//
//  Wrapper function to call host_collect_dimm_spd
//
void* call_host_collect_dimm_spd( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd entry" );

    // Get a list of all present Centaurs
    TargetHandleList l_presCentaurs;
    getChipResources(l_presCentaurs, TYPE_MEMBUF, UTIL_FILTER_PRESENT);
    // Associated MBA targets
    TARGETING::TargetHandleList l_mbaList;

    // Define predicate for associated MBAs
    PredicateCTM predMba(CLASS_UNIT, TYPE_MBA);
    PredicatePostfixExpr presMba;
    PredicateHwas predPres;
    predPres.present(true);
    presMba.push(&predMba).push(&predPres).And();

    for (TargetHandleList::const_iterator
            l_cenIter = l_presCentaurs.begin();
            l_cenIter != l_presCentaurs.end();
            ++l_cenIter)
    {
        //  make a local copy of the target for ease of use
        TARGETING::Target * l_pCentaur = *l_cenIter;
        // Retrieve HUID of current Centaur
        TARGETING::ATTR_HUID_type l_currCentaurHuid =
            TARGETING::get_huid(l_pCentaur);

        // Dump current run on target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_attr_cleanup HWP on "
                "target HUID %.8X", l_currCentaurHuid);

        // find all present MBAs associated with this Centaur
        TARGETING::TargetHandleList l_presMbas;
        targetService().getAssociated(l_presMbas,
                                      l_pCentaur,
                                      TargetService::CHILD,
                                      TargetService::IMMEDIATE,
                                      &presMba);

        // If not at least two MBAs found
        if (l_presMbas.size() < 2)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Not enough MBAs found for Centaur target HUID %.8X, "
              "skipping this Centaur.",
              l_currCentaurHuid);
            continue;
        }

        // Create FAPI Targets.
        /* @TODO: RTC:133830 use fapi2 targets
        const fapi::Target l_fapiCentaurTarget(TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)));
        const fapi::Target l_fapiMba0Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[0])));
        const fapi::Target l_fapiMba1Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[1])));
        */
        //@TODO  RTC:133830 call the HWP with each fapi::Target
        //FAPI_INVOKE_HWP(l_err, p9_mss_attr_cleanup, l_fapiCentaurTarget,
        //                l_fapiMba0Target, l_fapiMba1Target);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mss_attr_cleanup HWP returns error",
                      l_err->reasonCode());
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);
            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(l_err);
            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            // Success
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran mss_attr_cleanup HWP on "
                    "CENTAUR target HUID %.8X "
                    "and associated MBAs",
                    l_currCentaurHuid);
        }
    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}
};
