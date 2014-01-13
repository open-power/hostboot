/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istepdispatcher.C $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 *  @file istepdispatcher.C
 *
 *  IStep Dispatcher code.  Launched from Extended Initialization Service
 *
 *  PNOR Driver and Trace should be available by the time this is launched.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <sys/time.h>                    //nanosleep
#include <kernel/console.H>              // printk status
#include <vfs/vfs.H>                     // for VFS::module_load
#include <sys/task.h>                    //  tid_t, task_create, etc
#include <sys/misc.h>                    //  cpu_all_winkle
#include <errl/errlentry.H>              //  errlHndl_t
#include <initservice/isteps_trace.H>    //  ISTEPS_TRACE buffer
#include <initservice/initsvcudistep.H>  //  InitSvcUserDetailsIstep
#include <initservice/taskargs.H>        //  TASK_ENTRY_MACRO
#include <targeting/common/targetservice.H>
#include <targeting/attrsync.H>
#include <establish_system_smp.H>
#include <hwpf/plat/fapiPlatAttributeService.H>
#include <mbox/mbox_queues.H>            // HB_ISTEP_MSGQ
#include <mbox/mboxif.H>                 // register mailbox
#include <isteps/istepmasterlist.H>
#include "istepdispatcher.H"
#include "istep_mbox_msgs.H"
#include "splesscommon.H"
#include <diag/attn/attn.H>
#include <hwpf/istepreasoncodes.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas.H>
#include <hwas/hwasPlat.H>

namespace ISTEPS_TRACE
{
    // declare storage for isteps_trace!
    trace_desc_t * g_trac_isteps_trace = NULL;
    TRAC_INIT(&ISTEPS_TRACE::g_trac_isteps_trace, "ISTEPS_TRACE", 2*KILOBYTE);
}

namespace   INITSERVICE
{
/******************************************************************************/
// Globals/Constants
/******************************************************************************/
extern trace_desc_t *g_trac_initsvc;
const MBOX::queue_id_t HWSVRQ = MBOX::IPL_SERVICE_QUEUE;
const uint8_t INNER_START_STEP = 12;
const uint8_t INNER_START_SUBSTEP = 1;
const uint8_t INNER_STOP_STEP = 12;
const uint8_t INNER_STOP_SUBSTEP = 5;
const uint8_t OUTER_START_STEP = 10;
const uint8_t OUTER_START_SUBSTEP = 1;
const uint8_t OUTER_STOP_STEP = 14;
const uint8_t OUTER_STOP_SUBSTEP = 5;
const uint8_t HB_START_ISTEP = 6;

/**
 * _start() task entry procedure using the macro in taskargs.H
 */
TASK_ENTRY_MACRO( IStepDispatcher::getTheInstance().init );

// ----------------------------------------------------------------------------
// IstepDispatcher()
// ----------------------------------------------------------------------------
IStepDispatcher::IStepDispatcher() :
    iv_syncPointReached(false),
    iv_istepModulesLoaded(0),
    iv_progressThreadStarted(false),
    iv_curIStep(0),
    iv_curSubStep(0),
    iv_pIstepMsg(NULL),
    iv_shutdown(false)
{
    mutex_init(&iv_bkPtMutex);
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cond);

    TARGETING::Target* l_pSys = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pSys);
    iv_mpiplMode = l_pSys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>();
    TRACFCOMP(g_trac_initsvc, "IStepDispatcher: MPIPL Mode: %d", iv_mpiplMode);
    iv_istepMode = l_pSys->getAttr<TARGETING::ATTR_ISTEP_MODE>();
    TRACFCOMP(g_trac_initsvc, "IStepDispatcher: IStep Mode: %d", iv_istepMode);
    iv_spBaseServicesEnabled = spBaseServicesEnabled();
    TRACFCOMP(g_trac_initsvc, "IStepDispatcher: SP base Services Enabled: %d",
              iv_spBaseServicesEnabled);
    iv_mailboxEnabled = MBOX::mailbox_enabled();
    TRACFCOMP(g_trac_initsvc, "IStepDispatcher: Mailbox Enabled: %d",
              iv_mailboxEnabled);

    if (iv_spBaseServicesEnabled)
    {
        // SP Base Services Enabled implies that HWSV is running. If this is
        // true then the mailbox must be enabled
        assert(iv_mailboxEnabled);
    }

    // Note that if SP Base Services are not enabled and the Mailbox is enabled
    // then Cronus is sending messages to Hostboot.

    clock_gettime(CLOCK_MONOTONIC, &iv_lastProgressMsgTime);
    iv_msgQ = msg_q_create();
}

// ----------------------------------------------------------------------------
// ~IstepDispatcher()
// ----------------------------------------------------------------------------
IStepDispatcher::~IStepDispatcher ()
{
    TRACFCOMP( g_trac_initsvc, ENTER_MRK "IStepDispatcher::~IStepDispatcher "
               "destructor" );

    // Singleton destructor gets run when module gets unloaded.
    // The istepdispatcher module never gets unloaded. So rather to send a
    // message to error log daemon and tell it to shutdow and delete
    // the queue we will assert here because the destructor never gets
    // call.
    assert(0);
}

// ----------------------------------------------------------------------------
// IstepDispatcher::getTheInstance()
// ----------------------------------------------------------------------------
IStepDispatcher& IStepDispatcher::getTheInstance()
{
    return Singleton<IStepDispatcher>::instance();
}

// ----------------------------------------------------------------------------
// IStepDispatcher::init()
// ----------------------------------------------------------------------------
void IStepDispatcher::init(errlHndl_t &io_rtaskRetErrl)
{
    errlHndl_t err = NULL;

    printk( "IStepDispatcher entry.\n" );
    TRACFCOMP( g_trac_initsvc, "IStepDispatcher entry." );

    do
    {
        if(iv_mailboxEnabled)
        {
            // Register message Q with FSP Mailbox
            err = MBOX::msgq_register( MBOX::HB_ISTEP_MSGQ, iv_msgQ );

            if(err)
            {
                TRACFCOMP(g_trac_initsvc,
                          "ERROR: Failed to register mailbox, terminating");
                break;
            }
        }

        if(iv_istepMode)
        {
            // IStep mode (receive messages to run individual steps)
            if (!iv_mailboxEnabled)
            {
                // Cannot get messages from either HWSV or Cronus. Launch SPTask
                // to accept messages from the SPless user console
                TRACFCOMP(g_trac_initsvc, "IStep mode and SPLESS");
                tid_t spTaskTid = task_create(spTask, iv_msgQ);
                assert(spTaskTid > 0);
            }

            // Call the message handler to handle messages from FSP or SPless
            // user console, these messages include the IStep messages. This
            // function never returns.
            msgHndlr();
        }
        else
        {
            // Non-IStep mode (run all isteps automatically)
            if(iv_spBaseServicesEnabled)
            {
                // Base Services available. Figure out if HWSV has overrides
                uint8_t l_attrOverridesExist = 0;
                TARGETING::Target* l_pTopLevelTarget = NULL;
                TARGETING::targetService().getTopLevelTarget(l_pTopLevelTarget);

                if (l_pTopLevelTarget == NULL)
                {
                    TRACFCOMP(g_trac_initsvc,
                              "init: ERROR: Top level target not found");
                }
                else
                {
                    l_attrOverridesExist = l_pTopLevelTarget->
                    getAttr<TARGETING::ATTR_PLCK_IPL_ATTR_OVERRIDES_EXIST>();
                }

                if (l_attrOverridesExist)
                {
                    fapi::theAttrOverrideSync().getAttrOverridesFromFsp();
                }

                // Start a new thread to handle non-IStep messages from the FSP
                // (e.g. sync point reached)
                tid_t msgHndlrTaskTid = task_create(startMsgHndlrThread, this);
                assert(msgHndlrTaskTid > 0);
            }

            err = executeAllISteps();

            if(err)
            {
                TRACFCOMP(g_trac_initsvc, "ERROR: Failed executing all isteps,"
                          " see %x for details", err->eid());
                break;
            }

            // Send the potentially modified set of Attribute overrides and any
            // Attributes to sync to the FSP
            fapi::theAttrOverrideSync().sendAttrOverridesAndSyncsToFsp();
        }
    } while(0);

    TRACFCOMP( g_trac_initsvc, "IStepDispatcher finished.");
    printk( "IStepDispatcher exit.\n" );
    io_rtaskRetErrl = err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::executeAllISteps()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::executeAllISteps()
{
    errlHndl_t err = NULL;
    uint32_t istep = 0;
    uint32_t substep = 0;
    bool l_doReconfig = false;
    uint32_t numReconfigs = 0;
    const uint32_t MAX_NUM_RECONFIG_ATTEMPTS = 30;

    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::executeAllISteps()");

    while (istep < MaxISteps)
    {
        substep = 0;
        while (substep < g_isteps[istep].numitems)
        {
            err = doIstep(istep, substep, l_doReconfig);

            // Something occurred that requires a reconfig loop
            if (l_doReconfig)
            {
                TRACFCOMP(g_trac_initsvc,
                    ERR_MRK"executeAllISteps: Deconfigure(s) during IStep %d:%d",
                          istep, substep);

                // we had deconfigures lets see if we do the reconfigure loop
                uint8_t newIstep = 0;
                uint8_t newSubstep = 0;

                if ((checkReconfig(istep, substep, newIstep, newSubstep)) &&
                    (numReconfigs < MAX_NUM_RECONFIG_ATTEMPTS))
                {
                    // Within the Reconfig Loop, going to loop back
                    // first, check to make sure we still have a bootable system
                    errlHndl_t l_errl = HWAS::checkMinimumHardware();
                    if (l_errl)
                    {
                        // non-bootable system - we want to return our error.
                        TRACFCOMP(g_trac_initsvc,
                            ERR_MRK"Error from checkMinimumHardware");

                        if (err == NULL)
                        {
                            err = l_errl;   // use this error
                        }
                        else
                        {
                            // The IStep returned an error, This is the generic
                            // 'IStep failed' from the IStepError class, real
                            // errors detailing the failure have already been
                            // committed. Record the PLID and delete it. This
                            // will be replaced by the checkMinimumHardware
                            // error with the same plid that matches the real
                            // errors
                            const uint32_t l_plid = err->plid();
                            delete err;

                            // use this error instead
                            err = l_errl;
                            // and use the same plid as the IStep error
                            err->plid(l_plid);
                        }

                        // Break out of the istep loop with the error
                        break;
                    } // if error from checkMinimumHardware

                    // we have a bootable system, so loop back
                    numReconfigs++;
                    uint32_t l_plid = 0;

                    if (err)
                    {
                        // The IStep returned an error, This is the generic
                        // 'IStep failed' from the IStepError class, the real
                        // errors detailing the failure have already been
                        // committed. Record the PLID and delete it. This will
                        // be replaced by the ReconfigLoop info error with the
                        // same plid that matches the real errors
                        l_plid = err->plid();
                        delete err;
                        err = NULL;
                    }

                    // Create a new info error stating that a reconfig loop is
                    // about to be performed
                    uint64_t errWord = FOUR_UINT16_TO_UINT64(
                        istep, substep, newIstep, newSubstep);
                    /*@
                     * @errortype
                     * @reasoncode       ISTEP_RECONFIG_LOOP_ENTERED
                     * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
                     * @moduleid         ISTEP_INITSVC_MOD_ID
                     * @userdata1[0:15]  Istep that failed
                     * @userdata1[16:31] Substep that failed
                     * @userdata1[32:47] Istep that reconfig looped back to
                     * @userdata1[48:63] Substep that reconfig looped back to
                     * @userdata2        The number of reconfigs loops tried
                     * @devdesc          IStep failed and HW deconfigured.
                     *                   Looped back to an earlier istep
                     *                   (Reconfigure loop).
                     */
                    err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        ISTEP_INITSVC_MOD_ID,
                        ISTEP_RECONFIG_LOOP_ENTERED,
                        errWord,
                        numReconfigs);
                    err->collectTrace("HWAS_I", 1024);

                    if (l_plid != 0)
                    {
                        // Use the same plid as the IStep error
                        err->plid(l_plid);
                    }
                    errlCommit(err, INITSVC_COMP_ID);
                    istep = newIstep;
                    substep = newSubstep;
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps: Reconfig Loop: Back to %d:%d",
                              istep, substep);
                    continue;
                }
            }

            if (err)
            {
                TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps: IStep Error on %d:%d",
                          istep, substep);
                break;
            }
            substep++;
        }

        if (err)
        {
            break;
        }
        istep++;
    }

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::executeAllISteps()");

    return err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::doIstep()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::doIstep(uint32_t i_istep,
                                    uint32_t i_substep,
                                    bool & o_doReconfig)
{
    errlHndl_t err = NULL;
    o_doReconfig = false;

    // Get the Task Info for this step
    const TaskInfo * theStep = findTaskInfo(i_istep, i_substep);

    // If the step has valid work to be done, then execute it.
    if(NULL != theStep)
    {
        TRACFCOMP(g_trac_initsvc,ENTER_MRK"doIstep: step %d, substep %d, task %s",
                  i_istep, i_substep, theStep->taskname);

        // Send progress codes if in run-all mode
        if (!iv_istepMode)
        {
            mutex_lock(&iv_mutex);
            // Record current IStep, SubStep
            iv_curIStep = i_istep;
            iv_curSubStep = i_substep;

            // If a shutdown request has been received
            if (iv_shutdown)
            {
                mutex_unlock(&iv_mutex);
                // Do not begin new IStep and shutdown
                shutdownDuringIpl();
            }
            else
            {
                // Send Progress Code
                err = this->sendProgressCode(false);
                mutex_unlock(&iv_mutex);

                if(err)
                {
                    // Commit the error and continue
                    errlCommit(err, INITSVC_COMP_ID);
                }

                // Start progress thread, if not yet started
                if (!iv_progressThreadStarted)
                {
                    tid_t l_progTid = task_create(startProgressThread,this);
                    assert( l_progTid > 0 );
                    iv_progressThreadStarted = true;
                }
            }
        }

        if(iv_istepModulesLoaded != i_istep)
        {
            // unload the modules from the previous step
            unLoadModules(iv_istepModulesLoaded);

            // load modules for this step
            loadModules(i_istep);
            iv_istepModulesLoaded = i_istep;
        }

        // Zero ATTR_RECONFIGURE_LOOP
        TARGETING::Target* l_pTopLevel = NULL;
        TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
        l_pTopLevel->setAttr<TARGETING::ATTR_RECONFIGURE_LOOP>(0);

        err = InitService::getTheInstance().executeFn(theStep, NULL);

        //  flush contTrace immediately after each i_istep/substep  returns
        TRAC_FLUSH_BUFFERS();

        // sync the attributes to fsp in single step mode but only after step 6
        // is complete to allow discoverTargets() to run before the sync is done
        if(iv_istepMode && (i_istep > HB_START_ISTEP))
        {
            if(isAttrSyncEnabled())
            {
                TRACFCOMP(g_trac_initsvc, INFO_MRK"doIstep: sync attributes to FSP");

                errlHndl_t l_errl = TARGETING::syncAllAttributesToFsp();

                if(l_errl)
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: syncattributes failed see %x for details",
                              l_errl->eid());
                    errlCommit(l_errl, INITSVC_COMP_ID);
                }
            }
        }

        if(err)
        {
            TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: Istep failed, plid 0x%x",
                      err->plid());
        }
        // Check for any attentions and invoke PRD for analysis
        // if not in MPIPL mode
        else if ((true == theStep->taskflags.check_attn) &&
                 (false == iv_mpiplMode))
        {
            TRACDCOMP(g_trac_initsvc,
                      INFO_MRK"Check for attentions and invoke PRD" );

            err = ATTN::checkForIplAttentions();

            if ( err )
            {
                TRACFCOMP( g_trac_initsvc, ERR_MRK"doIstep: error from checkForIplAttentions");
            }
        }

        // now that HWP and PRD have run, check for deferred deconfig work.

        // Check for Power Line Disturbance (PLD)
        if (HWAS::hwasPLDDetection())
        {
            // There was a PLD, clear any deferred deconfig records
            TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: PLD, clearing deferred deconfig records");
            HWAS::theDeconfigGard().clearDeconfigureRecords(NULL);
        }
        else
        {
            // There was no PLD, process any deferred deconfig records (i.e.
            // actually do the deconfigures)
            HWAS::theDeconfigGard().processDeferredDeconfig();
        }

        // Check if ATTR_RECONFIGURE_LOOP is non-zero
        TARGETING::ATTR_RECONFIGURE_LOOP_type l_reconfigAttr = l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
        if (l_reconfigAttr)
        {
            TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: Reconfigure needed, ATTR_RECONFIGURE_LOOP = %d",
                      l_reconfigAttr);
            o_doReconfig = true;
        }

        TRACFCOMP(g_trac_initsvc, EXIT_MRK"doIstep: step %d, substep %d",
                  i_istep, i_substep);
    }
    else
    {
        TRACDCOMP( g_trac_initsvc, INFO_MRK"doIstep: Empty Istep, nothing to do!" );
    }

    return err;
}

// ----------------------------------------------------------------------------
// findTaskInfo()
// ----------------------------------------------------------------------------
const TaskInfo * IStepDispatcher::findTaskInfo(const uint32_t i_IStep,
                                               const uint32_t i_SubStep)
{
   //  default return is NULL
    const TaskInfo *l_pistep = NULL;

    //  apply filters
    do
    {
        //  Sanity check / dummy IStep
        if(g_isteps[i_IStep].pti == NULL)
        {
            TRACDCOMP( g_trac_initsvc,
                       "g_isteps[%d].pti == NULL (substep=%d)",
                       i_IStep,
                       i_SubStep );
            break;
        }

        // check input range - IStep
        if( i_IStep >= MaxISteps )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d out of range. (substep=%d) ",
                       i_IStep,
                       i_SubStep );
            break;      // break out with l_pistep set to NULL
        }

        //  check input range - ISubStep
        if( i_SubStep >= g_isteps[i_IStep].numitems )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d Substep %d out of range.",
                       i_IStep,
                       i_SubStep );
            break;      // break out with l_pistep set to NULL
        }

        //   check for end of list.
        if( g_isteps[i_IStep].pti[i_SubStep].taskflags.task_type
            == END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d SubStep %d task_type==END_TASK_LIST.",
                       i_IStep,
                       i_SubStep );
            break;
        }

        //  check to see if the pointer to the function is NULL.
        //  This is possible if some of the substeps aren't working yet
        //  and are just placeholders.
        if( g_isteps[i_IStep].pti[i_SubStep].taskfn == NULL )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d SubStep %d fn ptr is NULL.",
                       i_IStep,
                       i_SubStep );
            break;
        }

        //  check to see if we should skip this istep
        //  This is possible depending on which IPL mode we're in
        uint8_t l_ipl_op = g_isteps[i_IStep].pti[i_SubStep].taskflags.ipl_op;
        if (true == iv_mpiplMode)
        {
            if (!(l_ipl_op & MPIPL_OP))
            {
                TRACDCOMP( g_trac_initsvc,
                           "Skipping IStep %d SubStep %d for MPIPL mode",
                           i_IStep,
                           i_SubStep );
                break;
            }
        }
        else
        {
            if (!(l_ipl_op & NORMAL_IPL_OP))
            {
                TRACDCOMP( g_trac_initsvc,
                           "Skipping IStep %d SubStep %d for non MPIPL mode",
                           i_IStep,
                           i_SubStep );
                break;
            }
        }

        //  we're good, set the istep & return it to caller
        l_pistep = &( g_isteps[i_IStep].pti[i_SubStep] );
    } while( 0 );

    return  l_pistep;
}

// ----------------------------------------------------------------------------
// loadModules()
// ----------------------------------------------------------------------------
void IStepDispatcher::loadModules(uint32_t istepNumber) const
{
    errlHndl_t l_errl = NULL;
    do
    {
        //  if no dep modules then just exit out, let the call to
        //  executeFN load the module based on the function being
        //  called.
        if( g_isteps[istepNumber].depModules == NULL)
        {
            TRACDCOMP( g_trac_initsvc,
                    "g_isteps[%d].depModules == NULL",
                    istepNumber );
            break;
        }
        uint32_t i = 0;

        while( ( l_errl == NULL ) &&
                ( g_isteps[istepNumber].depModules->modulename[i][0] != 0) )
        {
            TRACFCOMP( g_trac_initsvc,
                    "loading [%s]",
                    g_isteps[istepNumber].depModules->modulename[i]);

            l_errl = VFS::module_load(
                    g_isteps[istepNumber].depModules->modulename[i] );
            i++;
        }

        if( l_errl )
        {
            errlCommit( l_errl, ISTEP_COMP_ID );
            assert(0);
        }

    }while(0);
}
// ----------------------------------------------------------------------------
// unloadModules()
// ----------------------------------------------------------------------------
void IStepDispatcher::unLoadModules(uint32_t istepNumber) const
{
    errlHndl_t l_errl = NULL;

    do
    {
        //  if no dep modules then just exit out
        if( g_isteps[istepNumber].depModules == NULL)
        {
            TRACDCOMP( g_trac_initsvc,
                    "g_isteps[%d].depModules == NULL",
                    istepNumber );
            break;
        }
        uint32_t i = 0;

        while( ( l_errl == NULL ) &&
                ( g_isteps[istepNumber].depModules->modulename[i][0] != 0) )
        {
            TRACFCOMP( g_trac_initsvc,
                    "unloading [%s]",
                    g_isteps[istepNumber].depModules->modulename[i]);

            l_errl = VFS::module_unload(
                    g_isteps[istepNumber].depModules->modulename[i] );

            i++;
        }

        if( l_errl )
        {
            TRACFCOMP( g_trac_initsvc,
                    " failed to unload module, commit error and move on");
            errlCommit(l_errl, INITSVC_COMP_ID );
            l_errl = NULL;
        }

    }while(0);
}

// ----------------------------------------------------------------------------
// IStepDispatcher::isAttrSyncEnabled()
// ----------------------------------------------------------------------------
bool IStepDispatcher::isAttrSyncEnabled() const
{
    TARGETING::Target* l_pTopLevel = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
    uint8_t l_syncEnabled =
                l_pTopLevel->getAttr<TARGETING::ATTR_SYNC_BETWEEN_STEPS>();
    return l_syncEnabled;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::msgHndlr()
// ----------------------------------------------------------------------------
void IStepDispatcher::msgHndlr()
{
    TRACFCOMP( g_trac_initsvc, ENTER_MRK"IStepDispatcher::msgHndlr");

    // Loop forever
    while(1)
    {
        msg_t * pMsg = NULL;
        pMsg = msg_wait(iv_msgQ);
        errlHndl_t l_errLog = NULL;

        switch(pMsg->type)
        {
            case SYNC_POINT_REACHED:
                // Sync point reached from Fsp
                TRACFCOMP(g_trac_initsvc, INFO_MRK"msgHndlr: SYNC_POINT_REACHED");
                handleSyncPointReachedMsg(pMsg);
                break;
            case PROCESS_IOVALID_REQUEST:
                TRACFCOMP(g_trac_initsvc, INFO_MRK"msgHndlr: PROCESS_IOVALID_REQUEST");
                handleProcFabIovalidMsg(pMsg);
                break;
            case ISTEP_MSG_TYPE:
                TRACFCOMP(g_trac_initsvc, INFO_MRK"msgHndlr: ISTEP_MSG_TYPE");
                if (iv_istepMode)
                {
                    handleIStepRequestMsg(pMsg);
                }
                else
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"msgHndlr: Ignoring IStep msg in non-IStep mode!");
                }
                break;
            case COALESCE_HOST:
                TRACFCOMP(g_trac_initsvc, INFO_MRK"msgHndlr: COALESCE_HOST");
                l_errLog = handleCoalesceHostMsg();
                if (l_errLog)
                {
                    errlCommit(l_errLog, INITSVC_COMP_ID);

                    // Send the message back as a response
                    pMsg->data[0] = HWSVR_MSG_ERROR;
                }
                else
                {
                    pMsg->data[0] = HWSVR_MSG_SUCCESS;
                }

                msg_respond(iv_msgQ, pMsg);
                pMsg = NULL;

                break;

            case SHUTDOWN:
                // Shutdown requested from Fsp
                TRACFCOMP(g_trac_initsvc, INFO_MRK"msgHndlr: SHUTDOWN");
                // If not in IStep mode, further process the shutdown message
                // otherwise, ignore it
                if (!iv_istepMode)
                {
                    handleShutdownMsg(pMsg);
                }
                else
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"msgHndlr: Ignoring shutdown msg in IStep mode!");
                }
                break;
            default:
                TRACFCOMP(g_trac_initsvc, ERR_MRK"msgHndlr: Ignoring unknown message 0x%08x",
                          pMsg->type);
                break;
        };
    }

    TRACFCOMP( g_trac_initsvc, EXIT_MRK"IStepDispatcher::msgHndlr");
}

// ----------------------------------------------------------------------------
// IStepDispatcher::waitForSyncPoint()
// ----------------------------------------------------------------------------
void IStepDispatcher::waitForSyncPoint()
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::waitForSyncPoint");

    if(iv_istepMode || (!iv_spBaseServicesEnabled))
    {
        TRACFCOMP(g_trac_initsvc, INFO_MRK"waitForSyncPoint: Istep mode or no base services, returning");
    }
    else
    {
        // Wait for the condition variable to be signalled
        mutex_lock(&iv_mutex);
        while((!iv_syncPointReached) && (!iv_shutdown))
        {
            sync_cond_wait(&iv_cond, &iv_mutex);
        }
        // If shutdown request has been received from the FSP
        if (iv_shutdown)
        {
            mutex_unlock(&iv_mutex);
            shutdownDuringIpl();
        }
        else
        {
            iv_syncPointReached = false;
            mutex_unlock(&iv_mutex);
        }
    }

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::waitForSyncPoint");
}

// ----------------------------------------------------------------------------
// IStepDispatcher::sendSyncPoint()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::sendSyncPoint()
{
    errlHndl_t err = NULL;

    TRACFCOMP(g_trac_initsvc,  ENTER_MRK"IStepDispatcher::sendSyncPoint");

    if(iv_istepMode || (!iv_spBaseServicesEnabled))
    {
        TRACFCOMP( g_trac_initsvc, INFO_MRK"sendSyncPoint: Istep mode or no base services, returning");
    }
    else
    {
        msg_t * myMsg = msg_allocate();
        myMsg->type = SYNC_POINT_REACHED;
        mutex_lock(&iv_mutex);
        uint64_t tmpVal = iv_curIStep;
        tmpVal = tmpVal << 32;
        tmpVal |= iv_curSubStep;
        mutex_unlock(&iv_mutex);
        myMsg->data[0] = tmpVal;
        myMsg->data[1] = 0x0;
        myMsg->extra_data = NULL;

        err = MBOX::send(HWSVRQ, myMsg);

        if (err)
        {
            TRACFCOMP( g_trac_initsvc, ERR_MRK"sendSyncPoint: Error sending message");
        }
    }

    TRACFCOMP( g_trac_initsvc, EXIT_MRK"IStepDispatcher::sendSyncPoint");
    return err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::sendIstepCompleteMsg()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::sendIstepCompleteMsg()
{
    errlHndl_t err = NULL;

    TRACFCOMP( g_trac_initsvc, ENTER_MRK"IStepDispatcher::sendIstepCompleteMsg");

    //Send progress code and update clock in thread
    /* 15 sec msg constraint not planned for GA1
    err = this->sendProgressCode();
    if( err )
    {
        break;
    }
    */

    // Respond to the IStep message stashed in iv_pIstepMsg
    mutex_lock(&iv_mutex);
    uint8_t curIStep = iv_curIStep;
    uint8_t curSubStep = iv_curSubStep;
    msg_t * pMsg = iv_pIstepMsg;
    iv_pIstepMsg = NULL;
    mutex_unlock(&iv_mutex);

    if(pMsg)
    {
        pMsg->data[0] = 0;
        msg_respond(iv_msgQ, pMsg );
        pMsg = NULL;
    }
    else
    {
        TRACFCOMP(g_trac_initsvc, ERR_MRK"sendIstepCompleteMsg: No message to respond to!");

        /*@
         * @errortype
         * @reasoncode       NO_MSG_PRESENT
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         ISTEP_INITSVC_MOD_ID
         * @userdata1        Current Istep
         * @userdata2        Current SubStep
         * @devdesc          Request to send Istep Complete msg to Fsp, but
         *                   no outstanding message from Fsp found.
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       ISTEP_INITSVC_MOD_ID,
                                       NO_MSG_PRESENT,
                                       curIStep,
                                       curSubStep );
    }

    TRACFCOMP( g_trac_initsvc, EXIT_MRK"IStepDispatcher::sendIstepCompleteMsg");
    return err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::handleSyncPointReachedMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleSyncPointReachedMsg(msg_t * & io_pMsg)
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::handleSyncPointReachedMsg");

    // Signal any IStep waiting for a sync point
    mutex_lock(&iv_mutex);
    iv_syncPointReached = true;
    sync_cond_signal(&iv_cond);
    mutex_unlock(&iv_mutex);

    if (msg_is_async(io_pMsg))
    {
        // It is expected that Sync Point Reached messages are async
        msg_free(io_pMsg);
        io_pMsg = NULL;
    }
    else
    {
        // Send the message back as a response
        msg_respond(iv_msgQ, io_pMsg);
        io_pMsg = NULL;
    }

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleSyncPointReachedMsg");
}

// ----------------------------------------------------------------------------
// IStepDispatcher::handleShutdownMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleShutdownMsg(msg_t * & io_pMsg)
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::handleShutdownMsg");

    // Set iv_shutdown and signal any IStep waiting for a sync point
    mutex_lock(&iv_mutex);
    iv_shutdown = true;
    sync_cond_broadcast(&iv_cond);
    mutex_unlock(&iv_mutex);

    if (msg_is_async(io_pMsg))
    {
        // It is expected shutdown request messages are async
        msg_free(io_pMsg);
        io_pMsg = NULL;
    }
    else
    {
        // Send the message back as a response
        msg_respond(iv_msgQ, io_pMsg);
        io_pMsg = NULL;
    }

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleShutdownMsg");
}

// ----------------------------------------------------------------------------
// IStepDispatcher::shutdownDuringIpl()
// ----------------------------------------------------------------------------
void IStepDispatcher::shutdownDuringIpl()
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::shutdownDuringIpl");

    // Create and commit error log for FFDC

    /*@
     * @errortype
     * @reasoncode       SHUTDOWN_REQUESTED_BY_FSP
     * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
     * @moduleid         ISTEP_INITSVC_MOD_ID
     * @userdata1        Current IStep
     * @userdata2        Current SubStep
     * @devdesc          Received shutdown request from FSP
     */
    errlHndl_t err = new ERRORLOG::ErrlEntry(
        ERRORLOG::ERRL_SEV_INFORMATIONAL,
        ISTEP_INITSVC_MOD_ID,
        SHUTDOWN_REQUESTED_BY_FSP,
        this->iv_curIStep, this->iv_curSubStep);

    errlCommit(err, INITSVC_COMP_ID);

    // Call doShutdown with the RC to initiate a TI
    INITSERVICE::doShutdown(SHUTDOWN_REQUESTED_BY_FSP);

}

// ----------------------------------------------------------------------------
// IStepDispatcher::iStepBreakPoint()
// ----------------------------------------------------------------------------
void IStepDispatcher::iStepBreakPoint(uint32_t i_info)
{
    // Throttle the breakpoints by locking here.
    mutex_lock(&iv_bkPtMutex);
    errlHndl_t err = NULL;
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::handleBreakpointMsg");

    // Breakpoints are only supported when FSP is attached

    if(iv_mailboxEnabled)
    {
        // Send a breakpoint message to the FSP and wait for response
        msg_t * pMsg = msg_allocate();
        pMsg->type = BREAKPOINT;
        pMsg->data[0] = i_info;
        pMsg->data[1] = 0x0;
        pMsg->extra_data = NULL;

        err = MBOX::sendrecv(HWSVRQ, pMsg);

        if(err)
        {
            TRACFCOMP(g_trac_initsvc, ERR_MRK"handleBreakpointMsg: Error sending message");
            errlCommit(err, INITSVC_COMP_ID);
            msg_free(pMsg);
            pMsg = NULL;
        }
    }


    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleBreakpointMsg");
    mutex_unlock(&iv_bkPtMutex);
}

// ----------------------------------------------------------------------------
// IStepDispatcher::isShutdownRequested()
// ----------------------------------------------------------------------------
bool IStepDispatcher::isShutdownRequested()
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::isShutdownRequested");

    mutex_lock(&iv_mutex);
    bool isShutdownRequested = iv_shutdown;
    mutex_unlock(&iv_mutex);

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::isShutdownRequested");
    return isShutdownRequested;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::handleIStepRequestMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleIStepRequestMsg(msg_t * & io_pMsg)
{
    errlHndl_t err = NULL;
    bool l_doReconfig = false;

    // find the step/substep. The step is in the top 32bits, the substep is in
    // the bottom 32bits and is a byte
    uint8_t istep = ((io_pMsg->data[0] & 0x000000FF00000000) >> 32);
    uint8_t substep = (io_pMsg->data[0] & 0x00000000000000FF);

    TRACFCOMP(g_trac_initsvc, ENTER_MRK"handleIstepRequestMsg: 0x%016x, istep: %d, substep: %d",
              io_pMsg->data[0], istep, substep);

    // Transfer ownership of the message pointer to iv_pIstepMsg because if the
    // IStep doesn't return (start_payload), it will call sendIstepCompleteMsg
    // which will respond to iv_pIstepMsg
    mutex_lock(&iv_mutex);
    iv_curIStep = istep;
    iv_curSubStep = substep;
    iv_pIstepMsg = io_pMsg;
    io_pMsg = NULL;
    mutex_unlock(&iv_mutex);

    err = doIstep (istep, substep, l_doReconfig);

    // If there was no IStep error, but something happened that requires a
    // reconfigure
    if ((!err) && l_doReconfig)
    {
        uint8_t newIstep = 0;
        uint8_t newSubstep = 0;

        if (checkReconfig(istep, substep, newIstep, newSubstep))
        {
            // Within the Reconfig Loop. In non-istep-mode it would loop back
            // to the start of the loop, this cannot be done here (this is
            // istep-mode) so create an error.
            TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIstepRequestMsg: IStep success and deconfigs, creating error");

            /*@
             * @errortype
             * @reasoncode       ISTEP_FAILED_DUE_TO_DECONFIG
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_INITSVC_MOD_ID
             * @userdata1        Istep that failed
             * @userdata2        SubStep that failed
             * @devdesc          IStep Mode. IStep reported success but HW
             *                   deconfigured within Reconfig Loop.
             */
            err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                ISTEP_INITSVC_MOD_ID,
                ISTEP_FAILED_DUE_TO_DECONFIG,
                istep, substep);
            err->collectTrace("HWAS_I", 1024);
        }
        else
        {
            // Not within the Reconfig Loop. In non-istep-mode it is considered
            // a success so it is the same here
            TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIstepRequestMsg: IStep success and deconfigs, returning success");
        }

    }

    uint64_t status = 0;
    if (err)
    {
        // Commit the error and record the plid as status in the top 32bits
        status = err->plid();
        status <<= 32;
        errlCommit(err, INITSVC_COMP_ID);
    }

    // Transfer ownership of the message pointer back from iv_pIstepMsg
    mutex_lock(&iv_mutex);
    io_pMsg = iv_pIstepMsg;
    iv_pIstepMsg = NULL;
    mutex_unlock(&iv_mutex);

    if (io_pMsg == NULL)
    {
        // An IStep already responded to the message!!
        TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIstepRequestMsg: message response already sent!");
    }
    else
    {
        if (msg_is_async(io_pMsg))
        {
            // Unexpected
            TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIstepRequestMsg: async istep message!");
        }
        else
        {
            io_pMsg->data[0] = status;
            io_pMsg->data[1] = 0x0;
            io_pMsg->extra_data = NULL;
            msg_respond(iv_msgQ, io_pMsg);
            io_pMsg = NULL;
        }
    }

    TRACFCOMP( g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleIStepRequestMsg");
}

// ----------------------------------------------------------------------------
// IStepDispatcher::handleProcFabIovalidMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleProcFabIovalidMsg(msg_t * & io_pMsg)
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::handleProcFabIovalidMsg");

    errlHndl_t err = NULL;
    do
    {
        // Ensure the libraries needed are loaded
        err = VFS::module_load("libestablish_system_smp.so");
        if (err)
        {
            TRACFCOMP(g_trac_initsvc, "handleProcFabIovalidMsg: Error loading libestablish_system_smp, PLID = 0x%x",
                      err->plid());

            io_pMsg->data[0] = err->plid();
            errlCommit(err, INITSVC_COMP_ID);
            break;
        }
        err = VFS::module_load("libedi_ei_initialization.so");
        if (err)
        {
            TRACFCOMP(g_trac_initsvc, "handleProcFabIovalidMsg: Error loading libedi_ei_initialization, PLID = 0x%x",
                      err->plid());

            io_pMsg->data[0] = err->plid();
            errlCommit(err, INITSVC_COMP_ID);
            break;
        }

        // Create child thread so that if there are problems, the istep
        //  dispatcher code continues
        tid_t l_progTid = task_create(
                ESTABLISH_SYSTEM_SMP::host_sys_fab_iovalid_processing,io_pMsg);
        assert( l_progTid > 0 );
        //  wait here for the task to end.
        //  status of the task ( OK or Crashed ) is returned in l_childsts
        int l_childsts    = 0;
        void *l_childrc = NULL;
        tid_t l_tidretrc  = task_wait_tid( l_progTid,
                                &l_childsts, &l_childrc );
        if ((static_cast<int16_t>(l_tidretrc) < 0 ) ||
            (l_childsts != TASK_STATUS_EXITED_CLEAN )
           )
        {
            TRACFCOMP(g_trac_initsvc, "task_wait_tid failed; l_tidretrc=0x%x, l_childsts=0x%x",
                      l_tidretrc, l_childsts);
            // the launched task failed or crashed,
        } // endif tidretrc

        // if there wasn't an error, winkle
        if(io_pMsg->data[0] == HWSVR_MSG_SUCCESS)
        {
            // Send the message back as a response
            free(io_pMsg->extra_data);
            io_pMsg->extra_data = NULL;
            msg_respond(iv_msgQ, io_pMsg);
            io_pMsg = NULL;

            // call to suspend the MBOX so that all messages are flushed
            err = MBOX::suspend();
            if (err)
            {
                TRACFCOMP( g_trac_initsvc, "ERROR : MBOX::suspend");
                errlCommit(err, INITSVC_COMP_ID);
                // keep going, since we already responded back to the FSP
            }

            TRACFCOMP( g_trac_initsvc, "winkle all cores");
            uint32_t l_rc = cpu_all_winkle();
            if ( l_rc )
            {
                // failed to winkle
                TRACFCOMP( g_trac_initsvc,
                      "ERROR : failed cpu_all_winkle, rc=0x%x", l_rc  );
            }
            else
            {
                // something woke us up, we'll return and see what msg is there
                TRACFCOMP( g_trac_initsvc,
                   "Returned from cpu_all_winkle." );
            }

            err = MBOX::resume();
            if (err)
            {
                TRACFCOMP( g_trac_initsvc, "ERROR : MBOX::resume");
                errlCommit(err, INITSVC_COMP_ID);
            }
        }
    } while (0);

    // if there was an error send back that msg
    if(io_pMsg && (io_pMsg->data[0] != HWSVR_MSG_SUCCESS))
    {
        // Send the message back as a response
        free(io_pMsg->extra_data);
        io_pMsg->extra_data = NULL;
        msg_respond(iv_msgQ, io_pMsg);
        io_pMsg = NULL;
    }

    TRACFCOMP( g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleProcFabIovalidMsg");
}

// ----------------------------------------------------------------------------
// IStepDispatcher::sendProgressCode()
// This method has a default of true for i_needsLock
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::sendProgressCode(bool i_needsLock)
{
    if (i_needsLock)
    {
        mutex_lock( &iv_mutex );
    }

    TRACDCOMP( g_trac_initsvc,ENTER_MRK"IStepDispatcher::sendProgressCode()");
    errlHndl_t err = NULL;

    // Put in rolling bit RTC: 84794

    msg_t * myMsg = msg_allocate();
    myMsg->type = IPL_PROGRESS_CODE;
    myMsg->data[0] = iv_curIStep;
    myMsg->data[1] = iv_curSubStep;
    myMsg->extra_data = NULL;
    err = MBOX::send(HWSVRQ, myMsg);
    clock_gettime(CLOCK_MONOTONIC, &iv_lastProgressMsgTime);
    TRACFCOMP( g_trac_initsvc,INFO_MRK"Progress Code %d.%d Sent",
               myMsg->data[0],myMsg->data[1]);
    TRACDCOMP( g_trac_initsvc,EXIT_MRK"IStepDispatcher::sendProgressCode()" );

    if (i_needsLock)
    {
        mutex_unlock( &iv_mutex );
    }

    return err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::runProgressThread()
// ----------------------------------------------------------------------------
void IStepDispatcher::runProgressThread()
{
    TRACDCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::runProgressThread");

    timespec_t l_CurTime;
    timespec_t l_PrevTime;
    //errlHndl_t err = NULL;

    mutex_lock( &iv_mutex );
    while(1)
    {
        l_PrevTime = iv_lastProgressMsgTime;
        clock_gettime(CLOCK_MONOTONIC, &l_CurTime);
        if( (l_CurTime.tv_sec - l_PrevTime.tv_sec) < MAX_WAIT_TIME_SEC )
        {
            mutex_unlock( &iv_mutex );
            nanosleep( MAX_WAIT_TIME_SEC - (l_CurTime.tv_sec -
                       l_PrevTime.tv_sec), 0 );
            mutex_lock( &iv_mutex );
        }
        // If shutdown has been requested by FSP, stop ProgressThread
        if(iv_shutdown)
        {
            break;
        }
        if( l_PrevTime.tv_sec == iv_lastProgressMsgTime.tv_sec &&
            l_PrevTime.tv_nsec == iv_lastProgressMsgTime.tv_nsec)
        {
#if 0
            /* 15 sec msg constraint not planned for GA1
            err = this->sendProgressCode(false);
            commit error in future
            */
#else
        // Normally this would be done in sendProgressCode but do it here
        // to prevent thread from becoming a CPU hog.
        clock_gettime(CLOCK_MONOTONIC, &iv_lastProgressMsgTime);
#endif
        }
    }

    TRACDCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::runProgressThread");
}

// ----------------------------------------------------------------------------
// IStepDispatcher::startProgressThread()
// ----------------------------------------------------------------------------
void * IStepDispatcher::startProgressThread(void * p)
{
    IStepDispatcher * l_pDispatcher = reinterpret_cast<IStepDispatcher *>(p);
    TRACDCOMP(g_trac_initsvc,INFO_MRK"startProgressThread: runProgressThread");
    l_pDispatcher->runProgressThread();
    return NULL;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::startMsgHndlrThread()
// ----------------------------------------------------------------------------
void * IStepDispatcher::startMsgHndlrThread(void * p)
{
    IStepDispatcher * l_pDispatcher = reinterpret_cast<IStepDispatcher *>(p);
    TRACDCOMP(g_trac_initsvc,INFO_MRK"msgHndlrThread");
    l_pDispatcher->msgHndlr();
    return NULL;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::checkReconfig()
// ----------------------------------------------------------------------------
bool IStepDispatcher::checkReconfig(const uint8_t i_curIstep,
                                    const uint8_t i_curSubstep,
                                    uint8_t & o_newIstep,
                                    uint8_t & o_newSubstep)
{
    bool doReconfigure = false;
    TRACDCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::checkReconfig(): istep %d.%d",
              i_curIstep, i_curSubstep);

    uint16_t current = (i_curIstep << 8) | i_curSubstep;
    const uint16_t INNER_START = (INNER_START_STEP << 8) | INNER_START_SUBSTEP;
    const uint16_t INNER_STOP = (INNER_STOP_STEP << 8) | INNER_STOP_SUBSTEP;
    const uint16_t OUTER_START = (OUTER_START_STEP << 8) | OUTER_START_SUBSTEP;
    const uint16_t OUTER_STOP = (OUTER_STOP_STEP << 8) | OUTER_STOP_SUBSTEP;

    // If current step is within major step 12
    if ((current >= INNER_START) && (current <= INNER_STOP))
    {
        doReconfigure = true;
        // Loop back to 12.1
        o_newIstep = INNER_START_STEP;
        o_newSubstep = INNER_START_SUBSTEP;
    }
    // Else if current step is outside of 12 but in step 10, 11, 13 or
    // 14 (up to 14.5)
    else if ((current >= OUTER_START) && (current <= OUTER_STOP))
    {
        doReconfigure = true;
        // Loop back to 10.1
        o_newIstep = OUTER_START_STEP;
        o_newSubstep = OUTER_START_SUBSTEP;
    }

    TRACDCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::checkReconfig: reconfig new istep/substep: %d %d.%d",
              doReconfigure, o_newIstep, o_newSubstep);

    return doReconfigure;
}

// ----------------------------------------------------------------------------
// Extarnal functions defined that map directly to IStepDispatcher public member
// functions.
// Defined in istepdispatcherif.H, initsvcbreakpoint.H
// ----------------------------------------------------------------------------
void waitForSyncPoint()
{
    IStepDispatcher::getTheInstance().waitForSyncPoint();
}

errlHndl_t sendSyncPoint()
{
    return IStepDispatcher::getTheInstance().sendSyncPoint();
}

errlHndl_t sendIstepCompleteMsg()
{
    return IStepDispatcher::getTheInstance().sendIstepCompleteMsg();
}

void iStepBreakPoint(uint32_t i_info)
{
    IStepDispatcher::getTheInstance().iStepBreakPoint( i_info );
}

bool isShutdownRequested()
{
    return IStepDispatcher::getTheInstance().isShutdownRequested();
}

// ----------------------------------------------------------------------------
// IStepDispatcher::getIstepInfo()
// ----------------------------------------------------------------------------
void IStepDispatcher::getIstepInfo ( uint8_t & o_iStep,
                                     uint8_t & o_subStep )
{
    mutex_lock( &iv_mutex );
    o_iStep = iv_curIStep;
    o_subStep = iv_curSubStep;
    mutex_unlock( &iv_mutex );
}

// ----------------------------------------------------------------------------
// IStepDispatcher::handleCoalesceHostMsg()
// ----------------------------------------------------------------------------
errlHndl_t  IStepDispatcher::handleCoalesceHostMsg()
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::handleCoalesceHostMsg");

    // Ensure the library is loaded
    errlHndl_t err = VFS::module_load("libestablish_system_smp.so");

    if (err)
    {
        TRACFCOMP(g_trac_initsvc, "handleCoalesceHostMsg: Error loading module, PLID = 0x%x",
                  err->plid());
    }
    else
    {
        err = ESTABLISH_SYSTEM_SMP::call_host_coalesce_host();
        if (err)
        {
            TRACFCOMP(g_trac_initsvc, "handleCoalesceHostMsg: Error with "
                      "call_host_coalese_host function LID = 0x%x",
                      err->plid());
        }
    }

    TRACFCOMP( g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleCoalesceHostMsg");

    return err;
}

} // namespace
