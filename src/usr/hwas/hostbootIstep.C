/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hostbootIstep.C $                                */
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
 *  @file hostbootIstep.C
 *
 *  @brief hostboot istep-called functions
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlat.H>

#include <hwas/hostbootIstep.H>
#include <hwas/common/deconfigGard.H>

#include <fsi/fsiif.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <hwpisteperror.H>

#include <targeting/attrsync.H>
#include <targeting/namedtarget.H>
#include <diag/prdf/prdfMain.H>
#include <intr/interrupt.H>
#include <ibscom/ibscomif.H>

#include <sbe/sbeif.H>
#include <sbe_update.H>

//  fapi support
#include  <fapi.H>
#include  <fapiPlatHwpInvoker.H>

//  targeting support.
#include  <targeting/common/utilFilter.H>
#include  <targeting/common/commontargeting.H>

#include  <errl/errludtarget.H>

#include <proc_enable_reconfig.H>

namespace HWAS
{

using namespace TARGETING;
using namespace fapi;
using namespace ISTEP;
using namespace ISTEP_ERROR;

// functions called from the istep dispatcher -- hostboot only

//******************************************************************************
// host_init_fsi function
//******************************************************************************
void* host_init_fsi( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi entry" );

    errlHndl_t errl = FSI::initializeHardware( );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi exit" );

    return errl;
}

//******************************************************************************
// host_set_ipl_parms function
//******************************************************************************
void* host_set_ipl_parms( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms entry" );
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_set_ipl_parms exit" );

    return errl;
}

//******************************************************************************
// host_discover_targets function
//******************************************************************************
void* host_discover_targets( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets entry" );

    errlHndl_t errl = NULL;

    // Check whether we're in MPIPL mode
    TARGETING::Target* l_pTopLevel = NULL;
    targetService().getTopLevelTarget( l_pTopLevel );
    HWAS_ASSERT(l_pTopLevel, "HWAS host_discover_targets: no TopLevelTarget");

    if (l_pTopLevel->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "MPIPL mode");

        // Sync attributes from Fsp
        errl = syncAllAttributesFromFsp();
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Normal IPL mode");

        errl = discoverTargets();

        // also if SP doesn't support change detection, call
        // function to do it here.
        if (!errl &&
            !l_pTopLevel->getAttr<ATTR_SP_FUNCTIONS>()
                .hardwareChangeDetection)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "calling hwasChangeDetection");
            errl = hwasChangeDetection();
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets exit" );

    return errl;
}

//******************************************************************************
// host_gard function
//******************************************************************************
void* host_gard( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard entry" );

    errlHndl_t errl;

    // Check whether we're in MPIPL mode
    TARGETING::Target* l_pTopLevel = NULL;
    targetService().getTopLevelTarget( l_pTopLevel );
    HWAS_ASSERT(l_pTopLevel, "HWAS host_gard: no TopLevelTarget");

    if (l_pTopLevel->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "MPIPL mode");

        // we only want EX units to be processed
        TARGETING::PredicateCTM l_exFilter(TARGETING::CLASS_UNIT,
                                           TARGETING::TYPE_EX);
        errl = collectGard(&l_exFilter);
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Normal IPL mode");

        errl = collectGard();

        if (errl == NULL)
        {
            //  check and see if we still have enough hardware to continue
            errl = checkMinimumHardware();
        }
        // If targets are deconfigured as a result of host_gard, they are
        // done so using the PLID as the reason for deconfiguration.  This
        // triggers the reconfigure loop attribute to be set, which causes
        // undesirable behavior, so we need to reset it here:

        // Read current value
        TARGETING::ATTR_RECONFIGURE_LOOP_type l_reconfigAttr =
            l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
        // Turn off deconfigure bit
        l_reconfigAttr &= ~TARGETING::RECONFIGURE_LOOP_DECONFIGURE;
        // Write back to attribute
        l_pTopLevel->setAttr<TARGETING::ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);
    }

    // Send message to FSP sending HUID of EX chip associated with master core
    msg_t * core_msg = msg_allocate();
    core_msg->type = SBE::MSG_IPL_MASTER_CORE;
    const TARGETING::Target*  l_masterCore  = TARGETING::getMasterCore( );
    HWAS_ASSERT(l_masterCore, "HWAS host_gard: no masterCore found");
    // Get the EX chip associated with the master core as that is the chip that 
    //   has the IS_MASTER_EX attribute associated with it
    TARGETING::TargetHandleList targetList;
    getParentAffinityTargets(targetList,
                             l_masterCore,
                             TARGETING::CLASS_UNIT,
                             TARGETING::TYPE_EX);
    HWAS_ASSERT(targetList.size() == 1, 
             "HWAS host_gard: Incorrect EX chip(s) associated with masterCore");
    core_msg->data[0] = 0;
    core_msg->data[1] = TARGETING::get_huid( targetList[0] );
    core_msg->extra_data = NULL;
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, 
              "Sending MSG_MASTER_CORE message with HUID %08x",
              core_msg->data[1]);
    errl = MBOX::send(MBOX::IPL_SERVICE_QUEUE,core_msg);
    if (errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                      ERR_MRK"MBOX::send failed sending Master Core message");
        msg_free(core_msg);

    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard exit" );
    return errl;
}

//******************************************************************************
// host_cancontinue_clear function
//******************************************************************************
void* host_cancontinue_clear( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_cancontinue_clear entry" );
    errlHndl_t errl = NULL;

    // stub -- nothing here currently

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_cancontinue_clear exit" );

    return errl;
}

//******************************************************************************
// host_prd_hwreconfig function
//******************************************************************************
void* host_prd_hwreconfig( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_prd_hwreconfig entry" );

    errlHndl_t errl = NULL;
    IStepError l_stepError;
    do
    {
        // Flip the scom path back to FSI in case we enabled IBSCOM previously
        IBSCOM::enableInbandScoms(IBSCOM_DISABLE);

        // Call PRDF to remove non-function chips from its system model
        errl = PRDF::refresh();

        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_prd_hwreconfig ERROR 0x%.8X returned from"
                      "  call to PRDF::refresh", errl->reasonCode());

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(errl);

            // Commit Error
            errlCommit(errl, HWPF_COMP_ID);

            break;
        }

        // Lists for functional MCS/Centaurs
        TARGETING::TargetHandleList l_fncMcsList;
        TARGETING::TargetHandleList l_fncCentaurList;

        // find all functional MCS chiplets of all procs
        getChipletResources(l_fncMcsList, TYPE_MCS, UTIL_FILTER_FUNCTIONAL);

        for (TargetHandleList::const_iterator
             l_mcs_iter = l_fncMcsList.begin();
             l_mcs_iter != l_fncMcsList.end();
             ++l_mcs_iter)
        {
            // make a local copy of the MCS target
            const TARGETING::Target * l_pMcs = *l_mcs_iter;
            // Retrieve HUID of current MCS
            TARGETING::ATTR_HUID_type l_currMcsHuid =
                TARGETING::get_huid(l_pMcs);

            // Find all the functional Centaurs that are associated with this MCS
            getChildAffinityTargets(l_fncCentaurList, l_pMcs,
                           CLASS_CHIP, TYPE_MEMBUF);

            // There will always be 1 Centaur associated with a MCS.
            if(1 != l_fncCentaurList.size())
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "No functional Centaurs found for "
                        "MCS target HUID %.8X , skipping this MCS",
                        l_currMcsHuid);
                continue;
            }

            // Make a local copy
            const TARGETING::Target * l_pCentaur = l_fncCentaurList[0];
            // Retrieve HUID of current Centaur
            TARGETING::ATTR_HUID_type l_currCentaurHuid =
                TARGETING::get_huid(l_pCentaur);

            // Dump current run on target
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_enable_reconfig HWP on "
                    "MCS target HUID %.8X CENTAUR target HUID %.8X",
                    l_currMcsHuid, l_currCentaurHuid);

            // Create FAPI Targets.
            fapi::Target l_fapiMcsTarget(TARGET_TYPE_MCS_CHIPLET,
                    (const_cast<TARGETING::Target*>(l_pMcs)));
            fapi::Target l_fapiCentaurTarget(TARGET_TYPE_MEMBUF_CHIP,
                    (const_cast<TARGETING::Target*>(l_pCentaur)));

            // Call the HWP with each fapi::Target
            FAPI_INVOKE_HWP(errl, proc_enable_reconfig,
                            l_fapiMcsTarget, l_fapiCentaurTarget);

            if (errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: proc_enable_reconfig HWP returns error",
                          errl->reasonCode());

                // Capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(l_pMcs).addToLog( errl );

                // Create IStep error log and cross reference error that occurred
                l_stepError.addErrorDetails(errl);

                // Commit Error
                errlCommit(errl, HWPF_COMP_ID);
            }
            else
            {
                // Success
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Successfully ran proc_enable_reconfig HWP on "
                        "MCS target HUID %.8X CENTAUR target HUID %.8X",
                        l_currMcsHuid,
                        l_currCentaurHuid);
            }
        }
    }
    while(0);
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_prd_hwreconfig exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// host_stub function
//******************************************************************************
void* host_stub( void *io_pArgs )
{
    errlHndl_t errl = NULL;
    // no function required
    return errl;
}

} // namespace HWAS
