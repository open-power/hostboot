/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_build_smp.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>
#include    <fsi/fsiif.H>


//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>
#include    <pbusLinkSvc.H>

#include    <fapi2/target.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <intr/interrupt.H>

//@TODO RTC:150562 - Remove when BAR setting handled by INTRRP
#include <devicefw/userif.H>

#include <p9_build_smp.H>

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;



namespace ISTEP_10
{
void* call_proc_build_smp (void *io_pArgs)
{

    IStepError l_StepError;

    errlHndl_t  l_errl  =   NULL;
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    //
    //  Identify the master processor
    //
    TARGETING::Target * l_masterProc =   NULL;
    (void)TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_procList;

    // Loop through all proc chips
    for (const auto & curproc: l_cpuTargetList)
    {
        if (curproc != l_masterProc)
        {
            //---PHBBAR - PSI Host Bridge Base Address Register
            //Get base BAR Value from attribute
            uint64_t l_baseBarValue = curproc->
              getAttr<TARGETING::ATTR_PSI_BRIDGE_BASE_ADDR>();

            uint64_t l_barValue = l_baseBarValue;
            uint64_t size = sizeof(l_barValue);
            l_errl = deviceWrite(curproc,
                                 &l_barValue,
                                 size,
                                 DEVICE_SCOM_ADDRESS(0x0501290A));

            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                          "Unable to set PSI BRIDGE BAR Address");
                break;
            }

            //Now set the enable bit
            l_barValue += 0x0000000000000001ULL; //PSI BRIDGE BAR ENABLE Bit
            size = sizeof(l_barValue);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Setting PSI BRIDGE Bar enable value for Target with "
                      "huid: 0x%x, PSI BRIDGE BAR value: 0x%016lx",
                      TARGETING::get_huid(curproc),l_barValue);

            l_errl = deviceWrite(curproc,
                                 &l_barValue,
                                 size,
                                 DEVICE_SCOM_ADDRESS(0x0501290A));

            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"Error enabling FSP BAR");
                break;
            }

            //---FSPBAR - FSP Base Address Register
            //Get base BAR Value from attribute
            l_baseBarValue = curproc->
              getAttr<TARGETING::ATTR_FSP_BASE_ADDR>();

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Setting FSP Bar enable value for Target with "
                      "huid: 0x%x, FSP BAR value: 0x%016lx",
                      TARGETING::get_huid(curproc),l_baseBarValue);

            l_errl = deviceWrite(curproc,
                                 &l_baseBarValue,
                                 size,
                                 DEVICE_SCOM_ADDRESS(0x0501290B));

            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"Error enabling FSP BAR");
                break;
            }

        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (curproc);
        l_procList.push_back(l_fapi2_proc_target);
    }
    if(l_errl)
    {
        l_StepError.addErrorDetails( l_errl);
        errlCommit( l_errl, ISTEP_COMP_ID );
    }


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_build_smp entry" );

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_master_proc (l_masterProc);

    do
    {

        FAPI_INVOKE_HWP( l_errl, p9_build_smp,
                         l_procList,
                         l_fapi2_master_proc,
                         SMP_ACTIVATE_PHASE1 );

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p9_build_smp, PLID=0x%x", l_errl->plid() );
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


            if (l_proc_target != l_masterProc)
            {
                //Enable PSIHB Interrupts for slave proc -- moved from above
                l_errl = INTR::enablePsiIntr(l_proc_target);
                if(l_errl)
                {
                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );
                    break;
                }
            }


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

                    // Reset the FSI2OPB logic on the new chips
                    l_errl = FSI::resetPib2Opb(l_proc_target);
                    if(l_errl)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "ERROR : resetPib2Opb on %.8X",
                                  TARGETING::get_huid(l_proc_target));
                        // Create IStep error log and
                        // cross reference error that occurred
                        l_StepError.addErrorDetails(l_errl);
                        // Commit error
                        errlCommit( l_errl, HWPF_COMP_ID );
                        break;
                    }
                }
            }

            ++curproc;
        }

    } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_build_smp exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
