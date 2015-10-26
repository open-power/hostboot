/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_setup_bars.C $               */
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
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;

namespace ISTEP_14
{
void* call_proc_setup_bars (void *io_pArgs)
{
    IStepError  l_stepError;
/*
    @TODO RTC:133831
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars entry" );


    // @@@@@    CUSTOM BLOCK:   @@@@@
    // Get all Centaur targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC );

    //  --------------------------------------------------------------------
    //  run mss_setup_bars on all CPUs.
    //  --------------------------------------------------------------------
    for (TargetHandleList::const_iterator
            l_cpu_iter = l_cpuTargetList.begin();
            l_cpu_iter != l_cpuTargetList.end();
            ++l_cpu_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCpuTarget = *l_cpu_iter;

        //  write HUID of target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "mss_setup_bars: proc "
                "target HUID %.8X", TARGETING::get_huid(l_pCpuTarget));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_pCpuTarget( TARGET_TYPE_PROC_CHIP,
                           (const_cast<TARGETING::Target*> (l_pCpuTarget)) );

        TARGETING::TargetHandleList l_membufsList;
        getChildAffinityTargets(l_membufsList, l_pCpuTarget,
                                CLASS_CHIP, TYPE_MEMBUF);
        std::vector<fapi::Target> l_associated_centaurs;

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufsList.begin();
                l_membuf_iter != l_membufsList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pTarget = *l_membuf_iter;

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_centaur_target
            (fapi::TARGET_TYPE_MEMBUF_CHIP,
            (const_cast<TARGETING::Target*>(l_pTarget)) );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            l_associated_centaurs.push_back(l_fapi_centaur_target);
        }

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_errl,
                        mss_setup_bars,
                        l_fapi_pCpuTarget, l_associated_centaurs );
        if ( l_errl )
        {
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCpuTarget).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : mss_setup_bars" );
            // break and return with error
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : mss_setup-bars" );
        }
    }   // endfor


    if ( l_stepError.isNull() )
    {
        //----------------------------------------------------------------------
        //  run proc_setup_bars on all CPUs
        //----------------------------------------------------------------------
        std::vector<proc_setup_bars_proc_chip> l_proc_chips;

        TargetPairs_t l_abusLinks;
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                    l_abusLinks, TYPE_ABUS, false );

        for (TargetHandleList::const_iterator
                l_cpu_iter = l_cpuTargetList.begin();
                l_cpu_iter != l_cpuTargetList.end() && !l_errl;
                ++l_cpu_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pCpuTarget = *l_cpu_iter;

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_pCpuTarget( TARGET_TYPE_PROC_CHIP,
                        (const_cast<TARGETING::Target*> (l_pCpuTarget)) );

            proc_setup_bars_proc_chip l_proc_chip ;
            l_proc_chip.this_chip  = l_fapi_pCpuTarget;
            l_proc_chip.process_f0 = true;
            l_proc_chip.process_f1 = true;

            TARGETING::TargetHandleList l_abuses;
            getChildChiplets( l_abuses, l_pCpuTarget, TYPE_ABUS );

            for (TargetHandleList::const_iterator
                    l_abus_iter = l_abuses.begin();
                    l_abus_iter != l_abuses.end();
                    ++l_abus_iter)
            {
                const TARGETING::Target* l_target = *l_abus_iter;
                uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
                TargetPairs_t::iterator l_itr = l_abusLinks.find(l_target);
                if ( l_itr == l_abusLinks.end() )
                {
                    continue;
                }

                const TARGETING::Target *l_pParent = NULL;
                l_pParent = getParentChip(
                              (const_cast<TARGETING::Target*>(l_itr->second)));
                fapi::Target l_fapiproc_parent( TARGET_TYPE_PROC_CHIP,
                                             (void *)l_pParent );

                switch (l_srcID)
                {
                    case 0: l_proc_chip.a0_chip = l_fapiproc_parent; break;
                    case 1: l_proc_chip.a1_chip = l_fapiproc_parent; break;
                    case 2: l_proc_chip.a2_chip = l_fapiproc_parent; break;
                   default: break;
                }
            }

            l_proc_chips.push_back( l_proc_chip );

        }   // endfor

        if (!l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call proc_setup_bars");

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP( l_errl, proc_setup_bars, l_proc_chips, true );

            if ( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : proc_setup_bars" );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : proc_setup_bars" );
            }
        }
    }   // end if !l_errl

    // @@@@@    END CUSTOM BLOCK:   @@@@@

    if ( l_errl )
    {

        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl);

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars exit" );
*/
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
