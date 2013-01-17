/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/activate_powerbus.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#include    <initservice/isteps_trace.H>
#include    <hwpisteperror.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "activate_powerbus.H"
#include    <pbusLinkSvc.H>

#include    "proc_build_smp/proc_build_smp.H"

namespace   ACTIVATE_POWERBUS
{

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   EDI_EI_INITIALIZATION;
using   namespace   fapi;

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
            l_StepError.addErrorDetails(ISTEP_ACTIVATE_POWER_BUS_FAILED,
                                        ISTEP_PROC_BUILD_SMP,
                                        l_errl);
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }

        // Get XBUS connections
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                 l_xbusConnections, TYPE_XBUS, false );

        if (l_errl)
        {
            l_StepError.addErrorDetails(ISTEP_ACTIVATE_POWER_BUS_FAILED,
                                        ISTEP_PROC_BUILD_SMP,
                                        l_errl);
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }

        // Populate l_proc_Chips vector for each good processor chip
        //   if a A/X-bus endpoint has a valid connection, then
        //   obtain the proc chip target of the other endpoint of the
        //   connection, build the fapi target to update the corresponding
        //   chip object of this A/X-bus endpoint for the procEntry
        std::vector<proc_build_smp_proc_chip> l_procChips;

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

            TARGETING::TargetHandleList l_abuses;
            getChildChiplets( l_abuses, l_pTarget, TYPE_ABUS );

            for (TARGETING::TargetHandleList::const_iterator
                 l_abusIter = l_abuses.begin();
                 l_abusIter != l_abuses.end();
                 ++l_abusIter)
            {
                const TARGETING::Target * l_target = *l_abusIter;
                uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
                TargetPairs_t::iterator l_itr = l_abusConnections.find(l_target);
                if ( l_itr == l_abusConnections.end() )
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
                    case 0: l_procEntry.a0_chip = l_fapiproc_parent; break;
                    case 1: l_procEntry.a1_chip = l_fapiproc_parent; break;
                    case 2: l_procEntry.a2_chip = l_fapiproc_parent; break;
                   default: break;
                }

                l_procEntry.f0_node_id = static_cast<proc_fab_smp_node_id>(
                        l_pTarget->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>());
                l_procEntry.f1_node_id = static_cast<proc_fab_smp_node_id>(
                        l_pParent->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>());
            }

            TARGETING::TargetHandleList l_xbuses;
            getChildChiplets( l_xbuses, l_pTarget, TYPE_XBUS );

            for (TARGETING::TargetHandleList::const_iterator
                 l_xbusIter = l_xbuses.begin();
                 l_xbusIter != l_xbuses.end();
                 ++l_xbusIter)
            {
                const TARGETING::Target * l_target = *l_xbusIter;
                uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
                TargetPairs_t::iterator l_itr = l_xbusConnections.find(l_target);
                if ( l_itr == l_xbusConnections.end() )
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
                    case 0: l_procEntry.x0_chip = l_fapiproc_parent; break;
                    case 1: l_procEntry.x1_chip = l_fapiproc_parent; break;
                    case 2: l_procEntry.x2_chip = l_fapiproc_parent; break;
                    case 3: l_procEntry.x3_chip = l_fapiproc_parent; break;
                   default: break;
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
            /*@
             * @errortype
             * @reasoncode       ISTEP_ACTIVATE_POWER_BUS_FAILED
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_PROC_BUILD_SMP
             * @userdata1        bytes 0-1: plid identifying first error
             *                   bytes 2-3: reason code of first error
             * @userdata2        bytes 0-1: total number of elogs included
             *                   bytes 2-3: N/A
             * @devdesc          call to proc_build_smp has failed
             */
            l_StepError.addErrorDetails(ISTEP_ACTIVATE_POWER_BUS_FAILED,
                                        ISTEP_PROC_BUILD_SMP,
                                        l_errl);
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_build_smp" );
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

    // call p8_customize_image.C

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_update exit" );

    return l_errl;
}

};   // end namespace
