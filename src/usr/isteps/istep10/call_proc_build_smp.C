/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_build_smp.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <fsi/fsiif.H>
#include <arch/magic.H>


//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>
#include <pbusLinkSvc.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <intr/interrupt.H>

#include <spi/spi.H>

//@TODO RTC:150562 - Remove when BAR setting handled by INTRRP
#include <devicefw/userif.H>
#include <sys/misc.h>
#include <sbeio/sbeioif.H>
#include <usr/vmmconst.h>
#include <p10_build_smp.H>

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;

namespace ISTEP_10
{
void* call_proc_build_smp (void *io_pArgs)
{

    IStepError l_StepError;

    do
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_proc_build_smp entry" );

        errlHndl_t  l_errl  =   nullptr;
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        //
        //  Identify the master processor
        //
        TARGETING::Target * l_masterProc =   nullptr;
        TARGETING::Target * l_masterNode =   nullptr;
        bool l_onlyFunctional = true; // Make sure masterproc is functional
        l_errl = TARGETING::targetService().queryMasterProcChipTargetHandle(
                                                 l_masterProc,
                                                 l_masterNode,
                                                 l_onlyFunctional);

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call_proc_build_smp: "
                       "queryMasterProcChipTargetHandle() returned PLID=0x%x",
                       l_errl->plid() );
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails(l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }

        std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_procList;

        // Loop through all proc chips and convert them to FAPI targets
        for (const auto & curproc: l_cpuTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    l_fapi2_proc_target (curproc);
            l_procList.push_back(l_fapi2_proc_target);
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                            l_fapi2_master_proc (l_masterProc);

        // Call PHASE1
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_master_proc,
                         SMP_ACTIVATE_PHASE1 );

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_build_smp(SMP_ACTIVATE_PHASE1), PLID=0x%x", l_errl->plid());
            //@FIXME-RTC:254475-Remove once this works everywhere
            if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__IGNORESMPFAIL) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WORKAROUND> Ignoring error for now - p10_build_smp" );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                // Create IStep error log and cross reference error that occurred
                l_StepError.addErrorDetails(l_errl);
                // Commit error
                errlCommit( l_errl, HWPF_COMP_ID );
                break;
            }
        }


        // Call SMP_ACTIVATE_SWITCH
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_master_proc,
                         SMP_ACTIVATE_SWITCH );
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_build_smp(SMP_ACTIVATE_SWITCH), PLID=0x%x", l_errl->plid());
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails(l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }


        // Call SMP_ACTIVATE_POST
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_master_proc,
                         SMP_ACTIVATE_POST );
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_build_smp(SMP_ACTIVATE_POST), PLID=0x%x", l_errl->plid());
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails(l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }


        // At the point where we can now change the proc chips to use
        // XSCOM rather than SBESCOM which is the default.

        TARGETING::TargetHandleList procChips;
        getAllChips(procChips, TYPE_PROC);

        TARGETING::TargetHandleList::iterator curproc = procChips.begin();

        // Loop through all proc chips
        while(curproc != procChips.end())
        {
            TARGETING::Target*  l_proc_target = *curproc;

            // If the proc chip supports xscom..
            if (l_proc_target->getAttr<ATTR_PRIMARY_CAPABILITIES>()
                .supportsXscom)
            {
                ScomSwitches l_switches =
                  l_proc_target->getAttr<ATTR_SCOM_SWITCHES>();

                // If Xscom is not already enabled.
                if ((l_switches.useXscom != 1) || (l_switches.useSbeScom != 0))
                {
                    l_switches.useSbeScom = 0;
                    l_switches.useXscom = 1;

                    // Turn off SBE scom and turn on Xscom.
                    l_proc_target->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
                }
            }

            if (l_proc_target != l_masterProc)
            {
                // Switch from FSI to PIB SPI access for slave processors
                l_errl = SPI::spiSetAccessMode(l_proc_target, SPI::PIB_ACCESS);
                if(l_errl)
                {
                    // Since this is a hard failure to detect later
                    // (via SPI failures), error out here
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                      "call_proc_build_smp> Unable to switch SPI access to "
                      "PIB_ACCESS for 0x%.8X",
                      TARGETING::get_huid(l_proc_target) );
                    l_StepError.addErrorDetails(l_errl);
                    errlCommit( l_errl, HWPF_COMP_ID );
                    break;
                }

                //Enable PSIHB Interrupts for slave proc -- moved from above
                l_errl = INTR::enablePsiIntr(l_proc_target);
                if(l_errl)
                {
                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );
                    l_StepError.addErrorDetails(l_errl);
                    errlCommit( l_errl, HWPF_COMP_ID );
                    break;
                }

                // Now that the SMP is connected, it's possible to establish
                // untrusted memory windows for non-master processor SBEs.  Open
                // up the Hostboot read-only memory range for each one to allow
                // Hostboot dumps / attention handling via any processor chip.
                const auto hbHrmor = cpu_spr_value(CPU_SPR_HRMOR);
                l_errl = SBEIO::openUnsecureMemRegion(
                    hbHrmor,
                    VMM_MEMORY_SIZE,
                    false, // False = read-only
                    l_proc_target);
                if(l_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK "Failed attempting to open Hostboot's "
                              "VMM region in SBE of non-master processor chip "
                              "with HUID=0x%08X.  Requested address=0x%016llX, "
                              "size=0x%08X",
                              TARGETING::get_huid(l_proc_target),
                              hbHrmor,VMM_MEMORY_SIZE);

                    ErrlUserDetailsTarget(l_proc_target).addToLog(l_errl);
                    l_StepError.addErrorDetails(l_errl);
                    errlCommit(l_errl,HWPF_COMP_ID);
                    break;
                }
            }

            ++curproc;
        }

        // Set a flag so that the ATTN code will check ALL processors
        // the next time it gets called versus just the master proc.
        uint8_t    l_useAllProcs = 1;
        TARGETING::Target  *l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( l_sys );
        assert(l_sys != nullptr);
        l_sys->setAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_useAllProcs);

    } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_build_smp exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
