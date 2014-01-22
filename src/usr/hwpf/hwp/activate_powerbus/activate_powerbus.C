/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/activate_powerbus.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 *  @file activate_powerbus.C
 *
 *  Support file for IStep: activate_powerbus
 *   Activate PowerBus
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <hwpisteperror.H>

#include    <sbe/sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "activate_powerbus.H"
#include    <pbusLinkSvc.H>

#include    "proc_build_smp/proc_build_smp.H"
#include    <intr/interrupt.H>

namespace   ACTIVATE_POWERBUS
{

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   EDI_EI_INITIALIZATION;
using   namespace   fapi;
using   namespace   ERRORLOG;

//******************************************************************************
// wrapper function to call proc_build_smp
//******************************************************************************
void*    call_proc_build_smp( void    *io_pArgs )
{

    errlHndl_t  l_errl  =   NULL;
    IStepError l_StepError;

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
                        l_pTarget->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>());
                l_procEntry.f1_node_id = static_cast<proc_fab_smp_node_id>(
                        l_pParent->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>());
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
        // XSCOM rather than FSISCOM which is the default.

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
                if ((l_switches.useXscom != 1) || (l_switches.useFsiScom != 0))
                {
                    l_switches.useFsiScom = 0;
                    l_switches.useXscom = 1;

                    // Turn off FSI scom and turn on Xscom.
                    l_proc_target->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
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

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//******************************************************************************
// wrapper function to call host_slave_sbe_update
//******************************************************************************
void * call_host_slave_sbe_update( void * io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_update entry" );

    // Call to check state of Processor SBE SEEPROMs and
    // make any necessary updates
    l_errl = SBE::updateProcessorSbeSeeproms();

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_update exit" );

    return l_errl;
}

};   // end namespace
