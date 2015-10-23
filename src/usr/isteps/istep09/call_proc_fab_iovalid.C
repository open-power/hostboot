/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_fab_iovalid.C $              */
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
 *  @file call_proc_fab_iovalid.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <hwas/common/hwasCommon.H>

#include    <sbe/sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

namespace   ISTEP_09
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;
//
//  Wrapper function to call proc_fab_iovalid
//
void*    call_proc_fab_iovalid( void    *io_pArgs )
{
    IStepError l_StepError;
    //@TODO RTC:134079 port to fapi2
/*    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid entry" );

    // Get all chip/chiplet targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    TargetPairs_t l_abusConnections;
    TargetPairs_t l_xbusConnections;
    l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                 l_abusConnections, TYPE_ABUS, false );
    if (!l_errl)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                 l_xbusConnections, TYPE_XBUS, false );
    }

    if ( l_errl )
    {
        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    std::vector<proc_fab_iovalid_proc_chip> l_smp;

    for (TargetHandleList::const_iterator l_cpu_iter = l_cpuTargetList.begin();
         l_StepError.isNull() && (l_cpu_iter != l_cpuTargetList.end());
         ++l_cpu_iter)
    {
        proc_fab_iovalid_proc_chip l_procEntry;

        TARGETING::TargetHandle_t l_pTarget = *l_cpu_iter;
        fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP, l_pTarget);

        l_procEntry.this_chip = l_fapiproc_target;
        l_procEntry.a0 = false;
        l_procEntry.a1 = false;
        l_procEntry.a2 = false;
        l_procEntry.x0 = false;
        l_procEntry.x1 = false;
        l_procEntry.x2 = false;
        l_procEntry.x3 = false;

        TARGETING::TargetHandleList l_abuses;
        getChildChiplets( l_abuses, l_pTarget, TYPE_ABUS );

        for (TargetHandleList::const_iterator l_abus_iter = l_abuses.begin();
            l_abus_iter != l_abuses.end();
            ++l_abus_iter)
        {
            TARGETING::TargetHandle_t l_target = *l_abus_iter;
            uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
            TargetPairs_t::iterator l_itr = l_abusConnections.find(l_target);
            if ( l_itr == l_abusConnections.end() )
            {
                continue;
            }
            switch (l_srcID)
            {
                case 0: l_procEntry.a0 = true; break;
                case 1: l_procEntry.a1 = true; break;
                case 2: l_procEntry.a2 = true; break;
               default: break;
            }
        }

        TARGETING::TargetHandleList l_xbuses;
        getChildChiplets( l_xbuses, l_pTarget, TYPE_XBUS );

        for (TargetHandleList::const_iterator l_xbus_iter = l_xbuses.begin();
            l_xbus_iter != l_xbuses.end();
            ++l_xbus_iter)
        {
            TARGETING::TargetHandle_t l_target = *l_xbus_iter;
            uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
            TargetPairs_t::iterator l_itr = l_xbusConnections.find(l_target);
            if ( l_itr == l_xbusConnections.end() )
            {
                continue;
            }
            switch (l_srcID)
            {
                case 0: l_procEntry.x0 = true; break;
                case 1: l_procEntry.x1 = true; break;
                case 2: l_procEntry.x2 = true; break;
                case 3: l_procEntry.x3 = true; break;
               default: break;
            }
        }

        l_smp.push_back(l_procEntry);
    }

    if (!l_errl)
    {
        //@TODO RTC:133830
        //FAPI_INVOKE_HWP( l_errl, p9_fab_iovalid, l_smp, true );

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "%s : proc_fab_iovalid HWP.",
                (l_errl ? "ERROR" : "SUCCESS"));
    }

    if (l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : call_proc_fab_iovalid encountered an error");

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid exit" );
*/
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}
};   // end namespace
