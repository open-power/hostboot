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

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

//@TODO RTC:150562 - Remove when BAR setting handled by INTRRP
#include <devicefw/userif.H>

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;


namespace ISTEP_10
{
void* call_proc_build_smp (void *io_pArgs)
{

    IStepError l_StepError;


    //@TODO RTC:133830 - This should be relocated to the below TODO as it
    //                 will do a similar loop
    //@TODO RTC:150562 - Long term the INTRRP will set the BARs. This will
    //                 be signaled via the INTRP::enablePsiIntr() function call
    //                 and the INTRP will set this BAR like all the others
    errlHndl_t  l_errl  =   NULL;
    uint64_t l_psihbBarAddr = 0x0501290A;
    TARGETING::TargetHandleList procChips;
    getAllChips(procChips, TYPE_PROC);
    TARGETING::TargetHandleList::iterator curproc = procChips.begin();

    // Get the master proc
    TARGETING::Target * l_masterProc =   NULL;
    (void)TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );

    // Loop through all proc chips
    while(curproc != procChips.end())
    {
        TARGETING::Target*  l_proc_target = *curproc;
        if (l_proc_target != l_masterProc)
        {
            uint64_t l_baseBarValue =
                 l_proc_target->getAttr<TARGETING::ATTR_PSI_BRIDGE_BASE_ADDR>();

            do {
                //Get base BAR Value from attribute
                uint64_t l_barValue = l_baseBarValue;
                uint64_t size = sizeof(l_barValue);
                l_errl = deviceWrite(l_proc_target,
                              &l_barValue,
                              size,
                              DEVICE_SCOM_ADDRESS(l_psihbBarAddr));

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
                          TARGETING::get_huid(l_proc_target),l_barValue);

                l_errl = deviceWrite(l_proc_target,
                                 &l_barValue,
                                 size,
                                 DEVICE_SCOM_ADDRESS(l_psihbBarAddr));

                if(l_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK"Error enabling PSIHB BAR");
                    break;
                }

            } while(0);


            if(l_errl)
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );
                break;
            }
        }
        ++curproc;
    }


    //@TODO RTC:133830
/*    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_build_smp entry" );

    do
    {
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        // Collect all valid abus connections and xbus connections
        TargetPairs_t l_abusConnections;
        TargetPairs_t l_xbusConnections;
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                     l_abusConnections, TYPE_ABUS, false );
        if (l_errl)
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        // Get XBUS connections
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                 l_xbusConnections, TYPE_XBUS, false );

        if (l_errl)
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        // Populate l_proc_Chips vector for each good processor chip
        //   if a A/X-bus endpoint has a valid connection, then
        //   obtain the proc chip target of the other endpoint of the
        //   connection, build the fapi target to update the corresponding
        //   chip object of this A/X-bus endpoint for the procEntry
        std::vector<proc_build_smp_proc_chip> l_procChips;

        // Get the master proc
        TARGETING::Target * l_masterProc =   NULL;
        (void)TARGETING::targetService().
                   masterProcChipTargetHandle( l_masterProc );

        for (TARGETING::TargetHandleList::const_iterator
             l_cpuIter = l_cpuTargetList.begin();
             l_cpuIter != l_cpuTargetList.end();
             ++l_cpuIter)
        {
            const TARGETING::Target* l_pTarget = *l_cpuIter;
            fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP,
                 (const_cast<TARGETING::Target*>(l_pTarget)));

            proc_build_smp_proc_chip l_procEntry;
            l_procEntry.this_chip = l_fapiproc_target;
            l_procEntry.enable_f0  = false;
            l_procEntry.enable_f1  = false;

            if (l_pTarget == l_masterProc)
            {
                l_procEntry.master_chip_sys_next = true;
            }
            else
            {
                l_procEntry.master_chip_sys_next = false;
            }

            // Get A-BUS
            //abus connections were found so can get the a-bus
            TARGETING::TargetHandleList l_abuses;
               getChildChiplets( l_abuses, l_pTarget, TYPE_ABUS );

            for (TARGETING::TargetHandleList::const_iterator
                    l_abusIter = l_abuses.begin();
                    l_abusIter != l_abuses.end();
                    ++l_abusIter)
            {
                const TARGETING::Target * l_target = *l_abusIter;
                uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
                TargetPairs_t::iterator l_itr =
                                        l_abusConnections.find(l_target);
                if ( l_itr == l_abusConnections.end() )
                {
                    continue;
                }

                fapi::Target l_fapiEndpointTarget(TARGET_TYPE_ABUS_ENDPOINT,
                          (const_cast<TARGETING::Target*>(l_itr->second)) );

                switch (l_srcID)
                {
                    case 0:
                        l_procEntry.a0_chip = l_fapiEndpointTarget;
                        break;
                    case 1:
                        l_procEntry.a1_chip = l_fapiEndpointTarget;
                        break;
                    case 2:
                        l_procEntry.a2_chip = l_fapiEndpointTarget;
                        break;
                    default:
                        break;
                }

                const TARGETING::Target *l_pParent =
                           getParentChip(
                             (const_cast<TARGETING::Target*>(l_itr->second)));

                l_procEntry.f0_node_id = static_cast<proc_fab_smp_node_id>(
                        l_pTarget->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>());
                l_procEntry.f1_node_id = static_cast<proc_fab_smp_node_id>(
                        l_pParent->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>());
            }

            // Get X-BUS
            TARGETING::TargetHandleList l_xbuses;
            getChildChiplets( l_xbuses, l_pTarget, TYPE_XBUS );

            for (TARGETING::TargetHandleList::const_iterator
                    l_xbusIter = l_xbuses.begin();
                    l_xbusIter != l_xbuses.end();
                    ++l_xbusIter)
            {
                const TARGETING::Target * l_target = *l_xbusIter;
                uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
                TargetPairs_t::iterator l_itr =
                                l_xbusConnections.find(l_target);
                if ( l_itr == l_xbusConnections.end() )
                {
                    continue;
                }

                fapi::Target l_fapiEndpointTarget(TARGET_TYPE_XBUS_ENDPOINT,
                            (const_cast<TARGETING::Target*>(l_itr->second)) );

                switch (l_srcID)
                {
                    case 0:
                        l_procEntry.x0_chip = l_fapiEndpointTarget;
                        break;
                    case 1:
                        l_procEntry.x1_chip = l_fapiEndpointTarget;
                        break;
                    case 2:
                        l_procEntry.x2_chip = l_fapiEndpointTarget;
                        break;
                    case 3:
                        l_procEntry.x3_chip = l_fapiEndpointTarget;
                        break;
                    default:
                        break;
                }
            }

            l_procChips.push_back( l_procEntry );
        }

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl, proc_build_smp, l_procChips,
                         SMP_ACTIVATE_PHASE1 );

        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_build_smp" );
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails(l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_build_smp" );
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

                    // Reset the FSI2OPB logic on the new chips                    
                    l_errl = FSI::resetPib2Opb(l_proc_target); // An SBE reset equivalent?
                    if(l_errl)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "ERROR : resetPib2Opb on %.8X",
                                  TARGETING::get_huid(l_proc_target));
                        // Create IStep error log and cross reference error that occurred
                        l_StepError.addErrorDetails(l_errl);
                        // Commit error
                        errlCommit( l_errl, HWPF_COMP_ID );
                        break;
                    }
                }
            }

            // Enable PSI interrupts even if can't Xscom as
            // Pbus is up and interrupts can flow
            l_errl = INTR::enablePsiIntr(l_proc_target); 
            if(l_errl)
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );

                break;
            }

            ++curproc;
        }


    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_build_smp exit" );
*/
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
