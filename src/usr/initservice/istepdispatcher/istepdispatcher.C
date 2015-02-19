/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istepdispatcher.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
//@TODO RTC:128106 port to fapi2 plat attribute service
//#include <hwpf/plat/fapiPlatAttributeService.H>
#include <mbox/mbox_queues.H>            // HB_ISTEP_MSGQ
#include <mbox/mboxif.H>                 // register mailbox
#include <intr/interrupt.H>
#include <isteps/istepmasterlist.H>
#include "istepdispatcher.H"
#include "istep_mbox_msgs.H"
#include "splesscommon.H"
#include <diag/attn/attn.H>
#include <isteps/istep_reasoncodes.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas.H>
#include <hwas/hwasPlat.H>
#include <targeting/attrPlatOverride.H>
#include <console/consoleif.H>
#include <isteps/hwpisteperror.H>
#include <pnor/pnorif.H>
#include <ipmi/ipmiwatchdog.H>      //IPMI watchdog timer
#include <ipmi/ipmipowerstate.H>    //IPMI System ACPI Power State
#include <config.h>
#include <ipmi/ipmisensor.H>

#include <initservice/bootconfigif.H>

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

// @todo RTC 124679 - Remove Once BMC Monitors Shutdown Attention
// Set Watchdog Timer To 15 seconds before calling doShutdown()
const uint16_t SET_WD_TIMER_IN_SECS = 15;

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
    iv_shutdown(false),
    iv_futureShutdown(false),
    iv_istepToCompleteBeforeShutdown(0),
    iv_substepToCompleteBeforeShutdown(0),
    iv_acceptIstepMessages(true)

{
    mutex_init(&iv_bkPtMutex);
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cond);

    TARGETING::Target* l_pSys = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pSys);
    iv_mpiplMode = l_pSys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>();
    TRACFCOMP(g_trac_initsvc, "IStepDispatcher: MPIPL Mode: %d", iv_mpiplMode);
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

    //  Read the and process the Hostboot configuration flags
    BOOTCONFIG::readAndProcessBootConfig();

    TARGETING::Target* l_pTopLevelTarget = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevelTarget);

    assert(l_pTopLevelTarget != NULL );

    do
    {
        //Need to get ATTR overides first if non FSP system
        if(!iv_spBaseServicesEnabled)
        {
            PNOR::SectionInfo_t l_sectionInfo;
            // Get temporary attribute overrides from pnor
            err = PNOR::getSectionInfo(PNOR::ATTR_TMP, l_sectionInfo);
            // Attr override sections are optional so just delete error
            if (err)
            {
                delete err;
                err = NULL;
            }
            else
            {
                TRACFCOMP(g_trac_initsvc,"init: processing temporary "
                          "overrides");
                err = TARGETING::getAttrOverrides(l_sectionInfo);
                if (err)
                {
                    TRACFCOMP(g_trac_initsvc,"Failed getAttrOverrides: "
                              "getting temporary overrides");
                    break;
                }
            }
            // Get permanent attribute overrides from pnor
            err = PNOR::getSectionInfo(PNOR::ATTR_PERM, l_sectionInfo);
            // Attr override sections are optional so just delete error
            if (err)
            {
                delete err;
                err = NULL;
            }
            else
            {
                TRACFCOMP(g_trac_initsvc,"init: processing permanent"
                          " overrides");
                err = TARGETING::getAttrOverrides(l_sectionInfo);
                if (err)
                {
                    TRACFCOMP(g_trac_initsvc,"Failed getAttrOverrides: "
                              "getting permanent overrides");
                    break;
                }
            }
        }

        iv_istepMode = l_pTopLevelTarget->getAttr<TARGETING::ATTR_ISTEP_MODE>();

        TRACFCOMP(g_trac_initsvc, "IStepDispatcher: IStep Mode: %d", iv_istepMode);


        if(iv_mailboxEnabled)
        {
            // Register message Q with FSP Mailbox
            err = MBOX::msgq_register( MBOX::HB_ISTEP_MSGQ, iv_msgQ );

            if(err)
            {
                if (err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
                {
                    err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }
                TRACFCOMP(g_trac_initsvc,
                          "ERROR: Failed to register mailbox, terminating");
                break;
            }
        }
#ifdef CONFIG_BMC_IPMI
        //set ACPI power state
        errlHndl_t err_ipmi = IPMI::setACPIPowerState();

        if(err_ipmi)
        {
           TRACFCOMP(g_trac_initsvc,
                          "init: ERROR: IPMI set ACPI Power State Failed");
            err_ipmi->collectTrace("INITSVC", 1024);
            errlCommit(err_ipmi, INITSVC_COMP_ID );
        }
#endif


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

#ifdef CONFIG_BMC_IPMI
            //run the ipmi watchdog in non istep mode only
            errlHndl_t err_ipmi = IPMIWATCHDOG::setWatchDogTimer(
                                  IPMIWATCHDOG::DEFAULT_WATCHDOG_COUNTDOWN);

            if(err_ipmi)
            {
               TRACFCOMP(g_trac_initsvc,
                              "init: ERROR: Set IPMI watchdog Failed");
                err_ipmi->collectTrace("INITSVC", 1024);
                errlCommit(err_ipmi, INITSVC_COMP_ID );

            }
#endif

            // Non-IStep mode (run all isteps automatically)
            if(iv_spBaseServicesEnabled)
            {
                // Base Services available. Figure out if HWSV has overrides
                uint8_t l_attrOverridesExist = 0;

                l_attrOverridesExist = l_pTopLevelTarget->
                    getAttr<TARGETING::ATTR_PLCK_IPL_ATTR_OVERRIDES_EXIST>();

                if (l_attrOverridesExist)
                {
                    //@TODO RTC:128106 port to fapi2 plat attribute service
                    //fapi::theAttrOverrideSync().getAttrOverridesFromFsp();
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
            if(iv_spBaseServicesEnabled)
            {
                //@TODO RTC:128106 port to fapi2 plat attribute service
                //fapi::theAttrOverrideSync().sendAttrOverridesAndSyncsToFsp();
            }
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

            if (l_doReconfig)
            {
                // Something occurred that requires a reconfig loop
                TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps:"
                          " Reconfig required after IStep %d:%d",
                          istep, substep);

                // Find out if in manufacturing mode
                bool l_manufacturingMode = false;
                TARGETING::Target* l_pTopLevel = NULL;
                TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
                TARGETING::ATTR_MNFG_FLAGS_type l_mnfgFlags =
                    l_pTopLevel->getAttr<TARGETING::ATTR_MNFG_FLAGS>();
                if (l_mnfgFlags & TARGETING::MNFG_FLAG_SRC_TERM)
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps:"
                              " In manufacturing mode");
                    l_manufacturingMode = true;
                }

                // Find out if in MPIPL mode
                bool l_MPIPLMode = false;
                if   (l_pTopLevel->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps:"
                              " In MPIPL mode");
                    l_MPIPLMode = true;
                }

                uint8_t newIstep = 0;
                uint8_t newSubstep = 0;

                if ((checkReconfig(istep, substep, newIstep, newSubstep)) &&
                    (numReconfigs < MAX_NUM_RECONFIG_ATTEMPTS) &&
                    (!l_manufacturingMode) &&
                    (!l_MPIPLMode) )
                {
                    // Within the Reconfig Loop, going to loop back
                    // first, check to make sure we still have a bootable system
                    errlHndl_t l_errl = HWAS::checkMinimumHardware();
                    if (l_errl)
                    {
                        // non-bootable system - we want to return this error.
                        TRACFCOMP(g_trac_initsvc,
                            ERR_MRK"Error from checkMinimumHardware");

                        if (err == NULL)
                        {
                            err = l_errl;
                            l_errl = NULL;
                        }
                        else
                        {
                            // The IStep returned an error and this is likely
                            // the generic 'IStep failed' from the
                            // IStepError class; real errors detailing the
                            // failure have already been committed. Record the
                            // PLID and delete it if 'Istep failed' or
                            // commit it otherwised. This will be replaced by
                            // the checkMinimumHardware error with the same
                            // plid that matches the real errors
                            const uint32_t l_plid = err->plid();
                            if (ISTEP::RC_FAILURE == err->reasonCode())
                            {
                                delete err;
                            }
                            else
                            {
                                errlCommit(err, INITSVC_COMP_ID);
                            }
                            err = l_errl;
                            l_errl = NULL;
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
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps: "
                              "Reconfig Loop: Back to %d:%d",
                              istep, substep);
                    continue;
                }
                else
                {

                    if (!err)
                    {
                        // Reconfig loop required, but the istep is either outside
                        // of the reconfig loop, too many reconfigs have been
                        // attempted, in manufacturing mode, or in MPIPL.
                        // Return an error to cause termination on FSP systems
                        if (iv_spBaseServicesEnabled)
                        {
                            err = failedDueToDeconfig(istep, substep,
                                                      newIstep, newSubstep);
                        }
                        // Otherwise shut down. The BMC watchdog reset will
                        // cause the system to reboot.  The BMC allows 2
                        // boot attempts from the primary side of PNOR and 1
                        // from the golden side. After that the system would
                        // shut down and halt.
                        else
                        {
                            #ifdef CONFIG_BMC_IPMI
                            // @TODO RTC:124679 - Remove Once BMC Monitors
                            // Shutdown Attention
                            // Set Watchdog Timer before calling doShutdown()
                            TRACFCOMP( g_trac_initsvc,"executeAllISteps: "
                                       "Set Watch Dog Timer To %d Seconds",
                                       SET_WD_TIMER_IN_SECS);

                            err = IPMIWATCHDOG::setWatchDogTimer(
                               SET_WD_TIMER_IN_SECS,  // new time
                               static_cast<uint8_t>
                                          (IPMIWATCHDOG::DO_NOT_STOP |
                                           IPMIWATCHDOG::BIOS_FRB2), // default
                                           IPMIWATCHDOG::TIMEOUT_HARD_RESET);
                            #endif
                            #ifdef CONFIG_CONSOLE
                            #ifdef CONFIG_BMC_IPMI
                            CONSOLE::displayf(NULL,
                               "System Shutting Down In %d Seconds "
                               "To Perform Reconfiguration\n",
                               SET_WD_TIMER_IN_SECS);
                            #else
                            CONSOLE::displayf(NULL,
                               "System Shutting Down "
                               "To Perform Reconfiguration\n");
                            #endif
                            CONSOLE::flush();
                            #endif
                            shutdownDuringIpl();
                        }
                    }
                    // else return the error from doIstep
                }
            }

            if (err)
            {
                TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps: "
                          "IStep Error on %d:%d", istep, substep);
                break;
            }
            substep++;
        }

        if (err)
        {
            // Ensure severity reflects IPL will be terminated
            if (err->sev() != ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM)
            {
                err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            }
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
        TRACFCOMP(g_trac_initsvc,ENTER_MRK"doIstep: step %d, substep %d, "
                  "task %s", i_istep, i_substep, theStep->taskname);

        // Send progress codes if in run-all mode
        if (!iv_istepMode)
        {
            mutex_lock(&iv_mutex);
            // Record current IStep, SubStep
            iv_curIStep = i_istep;
            iv_curSubStep = i_substep;
            mutex_unlock(&iv_mutex);

            // If a shutdown request has been received
            if (isShutdownRequested())
            {
                // Do not begin new IStep and shutdown
                shutdownDuringIpl();
            }
            else
            {
                mutex_lock(&iv_mutex);
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

        // Read ATTR_ISTEP_PAUSE_ENABLE attribute
        TARGETING::ATTR_ISTEP_PAUSE_ENABLE_type l_istepPauseEn =
            l_pTopLevel->getAttr<TARGETING::ATTR_ISTEP_PAUSE_ENABLE>();

        // If istep pause is enabled then call istepPauseSet
        if (l_istepPauseEn)
        {
            TRACFCOMP(g_trac_initsvc, INFO_MRK"doIstep: Pause before "
                    "istep is enabled");
            istepPauseSet(i_istep, i_substep);
        }

#ifdef CONFIG_BMC_IPMI

        if(theStep->taskflags.fwprogtype != PHASE_NA)
        {
            SENSOR::FirmwareProgressSensor l_progressSensor;
            errlHndl_t err_fwprog = l_progressSensor.setBootProgressPhase(
                theStep->taskflags.fwprogtype);

            if(err_fwprog)
            {
                TRACFCOMP(g_trac_initsvc,
                    "init: ERROR: Update FW Progress Phase Failed");
                errlCommit(err_fwprog, INITSVC_COMP_ID);
            }
        }

#endif

        err = InitService::getTheInstance().executeFn(theStep, NULL);

        //  flush contTrace immediately after each i_istep/substep  returns
        TRAC_FLUSH_BUFFERS();

        // sync the attributes to fsp in single step mode but only after step 6
        // is complete to allow discoverTargets() to run before the sync is done
        if(iv_istepMode && (i_istep > HB_START_ISTEP))
        {
            if(isAttrSyncEnabled())
            {
                TRACFCOMP(g_trac_initsvc,
                          INFO_MRK"doIstep: sync attributes to FSP");

                errlHndl_t l_errl = TARGETING::syncAllAttributesToFsp();

                if(l_errl)
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: sync attributes"
                             " failed see %x for details", l_errl->eid());
                    errlCommit(l_errl, INITSVC_COMP_ID);
                }
            }
        }

        if(err)
        {
            TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: Istep failed, plid 0x%x",
                      err->plid());
        }

// @todo RTC:145353 - Restore testprdf and testattn in p9 branch
#if (0)
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
                TRACFCOMP( g_trac_initsvc, ERR_MRK"doIstep: error from "
                          "checkForIplAttentions");
            }
        }
#endif

#ifdef CONFIG_RECONFIG_LOOP_TESTS_ENABLE
        // Read ATTR_RECONFIG_LOOP_TESTS_ENABLE attribute
        TARGETING::ATTR_RECONFIG_LOOP_TESTS_ENABLE_type l_reconfigAttrTestsEn =
            l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIG_LOOP_TESTS_ENABLE>();

        // If ATTR_RECONFIG_LOOP_TESTS_ENABLE is non-zero and if there is no
        // previous error then call the reconfig loop test runner
        if ((l_reconfigAttrTestsEn) && (!err))
        {
            TRACFCOMP(g_trac_initsvc, INFO_MRK"doIstep: "
                    "Reconfig Loop Tests Enabled");
            reconfigLoopTestRunner(i_istep, i_substep, err);
        }
#endif // CONFIG_RECONFIG_LOOP_TESTS_ENABLE

        // now that HWP and PRD have run, check for deferred deconfig work.

        // Check for Power Line Disturbance (PLD)
        if (HWAS::hwasPLDDetection())
        {
            // There was a PLD, clear any deferred deconfig records
            TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: PLD, clearing deferred "
                      "deconfig records");
            HWAS::theDeconfigGard().clearDeconfigureRecords(NULL);
        }
        else
        {
            // There was no PLD, process any deferred deconfig records (i.e.
            // actually do the deconfigures)
            HWAS::theDeconfigGard().processDeferredDeconfig();
        }

        // Check if ATTR_RECONFIGURE_LOOP is non-zero
        TARGETING::ATTR_RECONFIGURE_LOOP_type l_reconfigAttr =
                       l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();

        if (l_reconfigAttr)
        {
            TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: Reconfigure needed, "
                      "ATTR_RECONFIGURE_LOOP = %d", l_reconfigAttr);
            o_doReconfig = true;
        }

        TRACFCOMP(g_trac_initsvc, EXIT_MRK"doIstep: step %d, substep %d",
                  i_istep, i_substep);
    }
    else
    {
        TRACDCOMP( g_trac_initsvc,
                  INFO_MRK"doIstep: Empty Istep, nothing to do!" );
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
                ( g_isteps[istepNumber].depModules->modulename[i] != NULL) )
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
                ( g_isteps[istepNumber].depModules->modulename[i] != NULL) )
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
                handleIStepRequestMsg(pMsg);
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
                // Further process the shutdown message
                handleShutdownMsg(pMsg);
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
            if (err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
            {
                err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            }
            TRACFCOMP( g_trac_initsvc, ERR_MRK"sendSyncPoint:"
                                      " Error sending message");
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
        const bool hbSwError = true;
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       ISTEP_INITSVC_MOD_ID,
                                       NO_MSG_PRESENT,
                                       curIStep, curSubStep, hbSwError );
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

    // find the step/substep. The step is in the top 32bits, the substep is in
    // the bottom 32bits and is a byte
    uint8_t istep = ((io_pMsg->data[0] & 0x000000FF00000000) >> 32);
    uint8_t substep = (io_pMsg->data[0] & 0x00000000000000FF);

    if (istep == 0 && substep == 0)
    {
        //Immediate shutdown - Set iv_shutdown and signal any IStep waiting for
        //    a sync point
        mutex_lock(&iv_mutex);
        iv_shutdown = true;
        sync_cond_broadcast(&iv_cond);
        mutex_unlock(&iv_mutex);
    }
    else
    {
        mutex_lock(&iv_mutex);
        if (iv_futureShutdown)
        {
            //Multiple shutdown messages have been received use the one that
            // will happen first
            if ((istep < iv_istepToCompleteBeforeShutdown) ||
                (istep == iv_istepToCompleteBeforeShutdown
                     && substep < iv_substepToCompleteBeforeShutdown) )
            {
                TRACFCOMP(g_trac_initsvc, INFO_MRK"handleShutdownMsg: Future "
                  "shutdown msg rcvd, updating future poweroff to istep"
                  " [%d], substep [%d]", istep, substep);
                iv_istepToCompleteBeforeShutdown = istep;
                iv_substepToCompleteBeforeShutdown = substep;
            }
            else
            {
                TRACFCOMP(g_trac_initsvc, INFO_MRK"handleShutdownMsg: Future "
                  "shutdown msg rcvd, but istep [%d], substep [%d] is after "
                  "previous future shutdown request. This request will be "
                  "ignored.", istep, substep);
            }
        }
        else
        {
            TRACFCOMP(g_trac_initsvc, INFO_MRK"handleShutdownMsg: Future"
                          " Shutdown Message for istep [%d], substep [%d]",
                          istep, substep);
            iv_istepToCompleteBeforeShutdown = istep;
            iv_substepToCompleteBeforeShutdown = substep;
            iv_futureShutdown = true;
        }
        mutex_unlock(&iv_mutex);
    }

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

    if (iv_istepMode)
    {
        TRACFCOMP(g_trac_initsvc, INFO_MRK"ShutdownMsg received in istepMode,"
                                  " call shutdownDuringIPL() directly");
        shutdownDuringIpl();
    }

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleShutdownMsg");
}


// ----------------------------------------------------------------------------
// IStepDispatcher::shutdownDuringIpl()
// ----------------------------------------------------------------------------
void IStepDispatcher::shutdownDuringIpl()
{

    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::shutdownDuringIpl");

    // Create and commit error log for FFDC and call doShutdown with the RC
    // to initiate a TI
    if (iv_spBaseServicesEnabled)
    {
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
        INITSERVICE::doShutdown(SHUTDOWN_REQUESTED_BY_FSP);
    }
    else
    {
        /*@
         * @errortype
         * @reasoncode       SHUTDOWN_NOT_RECONFIG_LOOP
         * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
         * @moduleid         ISTEP_INITSVC_MOD_ID
         * @userdata1        Current IStep
         * @userdata2        Current SubStep
         * @devdesc          Received shutdown request due to deconfigure
         *                   outside of reconfig loop
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            ISTEP_INITSVC_MOD_ID,
            SHUTDOWN_NOT_RECONFIG_LOOP,
            this->iv_curIStep, this->iv_curSubStep);

        errlCommit(err, INITSVC_COMP_ID);
        INITSERVICE::doShutdown(SHUTDOWN_NOT_RECONFIG_LOOP);
    }

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
            if (err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
            {
                err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            }
            TRACFCOMP(g_trac_initsvc, ERR_MRK"handleBreakpointMsg:"
                                         " Error sending message");
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
    TRACDCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::isShutdownRequested");

    mutex_lock(&iv_mutex);
    bool isShutdownRequested = iv_shutdown;
    mutex_unlock(&iv_mutex);

    if (!isShutdownRequested)
    {
        isShutdownRequested = isFutureShutdownRequested();
    }

    TRACDCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::isShutdownRequested");
    return isShutdownRequested;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::isFutureShutdownRequested()
// ----------------------------------------------------------------------------
bool IStepDispatcher::isFutureShutdownRequested()
{
    TRACDCOMP(g_trac_initsvc,
                  ENTER_MRK"IStepDispatcher::isFutureShutdownRequested");

    bool isFutureShutdownRequested = false;
    mutex_lock(&iv_mutex);

    if (iv_futureShutdown)
    {
        if (iv_curIStep == iv_istepToCompleteBeforeShutdown)
        {
            if (iv_curSubStep > iv_substepToCompleteBeforeShutdown)
            {
                isFutureShutdownRequested = true;
            }
            else
            {
                isFutureShutdownRequested = false;
            }
        }
        else if (iv_curIStep > iv_istepToCompleteBeforeShutdown)
        {
            isFutureShutdownRequested = true;
        }
        else
        {
            isFutureShutdownRequested = false;
        }
    }
    else
    {
        //No Future shutdown set, always return false
        isFutureShutdownRequested = false;
    }
    mutex_unlock(&iv_mutex);

    TRACDCOMP(g_trac_initsvc,
                  EXIT_MRK"IStepDispatcher::isFutureShutdownRequested");
    return isFutureShutdownRequested;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::acceptIstepMessages()
// ----------------------------------------------------------------------------
void IStepDispatcher::setAcceptIstepMessages(bool i_accept)
{
    TRACDCOMP(g_trac_initsvc,
                  ENTER_MRK"IStepDispatcher::setAcceptIstepMessages");

    mutex_lock(&iv_mutex);
    iv_acceptIstepMessages = i_accept;
    mutex_unlock(&iv_mutex);

    TRACDCOMP(g_trac_initsvc,
                  EXIT_MRK"IStepDispatcher::setAcceptIstepMessages");
    return;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::handleIStepRequestMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleIStepRequestMsg(msg_t * & io_pMsg)
{
    errlHndl_t err = NULL;
    bool l_doReconfig = false;
    bool l_acceptMessages = false;

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
    l_acceptMessages = iv_acceptIstepMessages;
    mutex_unlock(&iv_mutex);

    if (l_acceptMessages)
    {
        err = doIstep (istep, substep, l_doReconfig);
    }
    else
    {
        /*@
             * @errortype
             * @reasoncode       ISTEP_NON_MASTER_NODE_MSG
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_INITSVC_MOD_ID
             * @userdata1        Istep Requested
             * @userdata2        Substep Requested
             * @devdesc          Istep messaged received by non-master node.
        */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP_INITSVC_MOD_ID,
                                      ISTEP_NON_MASTER_NODE_MSG,
                                      iv_curIStep,
                                      iv_curSubStep);
    }

    // If there was no IStep error, but something happened that requires a
    // reconfigure
    if ((!err) && l_doReconfig)
    {
        uint8_t newIstep = 0;
        uint8_t newSubstep = 0;

        // Even though we cannot do a reconfig in istep mode, call function
        // to get FFDC on where we might have gone.
        checkReconfig(istep, substep, newIstep, newSubstep);

        // In istep mode we cannot do a reconfigure of any sort, so create
        // an error.
        TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIstepRequestMsg: IStep success and deconfigs, creating error");
        err = failedDueToDeconfig(istep, substep, newIstep, newSubstep);

    }

    uint64_t status = 0;
    if (err)
    {
        // Commit the error and record the plid as status in the top 32bits
        status = err->plid();
        status <<= 32;
        errlCommit(err, INITSVC_COMP_ID);
    }

    // Send the potentially modified set of Attribute overrides and any
    // Attributes to sync (to Cronus) to the FSP
    //@TODO RTC:128106 port to fapi2 plat attribute service
    //fapi::theAttrOverrideSync().sendAttrOverridesAndSyncsToFsp();

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
        //Intentionally fail this message on MPIPL
        TARGETING::Target* l_pSys = NULL;
        TARGETING::targetService().getTopLevelTarget(l_pSys);
        bool l_mpiplMode = l_pSys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>();
        if(l_mpiplMode)
        {
            /*@
             * @errortype
             * @reasoncode       ISTEP_INVALID_ON_MPIPL
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_INITSVC_MOD_ID
             * @userdata1[0:31]  MPIPL State
             * @userdata1[32:63] N/A
             * @userdata2[0:31]  N/A
             * @userdata2[32:63] N/A.
             * @devdesc          handleProcFabIovalidMsg called during MPIPL,
             *                   which is illegal.
             * @custdesc    A problem occurred during the IPL
             *              of the system.
             */
            err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          ISTEP_INITSVC_MOD_ID,
                                          ISTEP_INVALID_ON_MPIPL,
                                          TWO_UINT32_TO_UINT64(l_mpiplMode,0x0),
                                          0x0);

            TRACFCOMP(g_trac_initsvc, "handleProcFabIovalidMsg: Not a valid on MPIPL, PLID = 0x%x",
                      err->plid());

            io_pMsg->data[0] = err->plid();
            errlCommit(err, INITSVC_COMP_ID);
            break;
        }

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
        //  @TODO RTC:133831
        //tid_t l_progTid = task_create(
        //        ESTABLISH_SYSTEM_SMP::host_sys_fab_iovalid_processing,io_pMsg);
        tid_t l_progTid = 1;
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

            //All interrupt sources are blocked, but intrp could have
            //pending EOI in message queue.  Send message to drain
            //the interrupt queue
            INTR::drainQueue();

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

            // Re-enable p8_cpu_special_wakeup
            // @TODO RTC:133831
            //err = ESTABLISH_SYSTEM_SMP::enableSpecialWakeup();
            if (err)
            {
                TRACFCOMP( g_trac_initsvc,
                           "ERROR: ESTABLISH_SYSTEM_SMP::enableSpecialWakeup");
                errlCommit(err, INITSVC_COMP_ID);
            }

            err = MBOX::resume();
            if (err)
            {
                if (err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
                {
                    err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }
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
    // If we send this multiple times, we may need to eliminate the console
    // write on subsequent.  RTC: 84794

#ifdef CONFIG_CONSOLE_OUTPUT_PROGRESS
    CONSOLE::displayf(NULL, "ISTEP %2d.%2d", iv_curIStep, iv_curSubStep);
    CONSOLE::flush();
#endif

#ifdef CONFIG_BMC_IPMI
    //Reset the watchdog before every istep
    errlHndl_t err_ipmi = IPMIWATCHDOG::resetWatchDogTimer();

    if(err_ipmi)
    {
       TRACFCOMP(g_trac_initsvc,
                      "init: ERROR: reset IPMI watchdog Failed");
        err_ipmi->collectTrace("INITSVC", 1024);
        errlCommit(err_ipmi, INITSVC_COMP_ID );
    }

#endif

    msg_t * myMsg = msg_allocate();
    myMsg->type = IPL_PROGRESS_CODE;
    myMsg->data[0] = iv_curIStep;
    myMsg->data[1] = iv_curSubStep;
    myMsg->extra_data = NULL;
    err = MBOX::send(HWSVRQ, myMsg);
    if (err && err->sev() == ERRORLOG::ERRL_SEV_INFORMATIONAL)
    {
        err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
    }
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
            mutex_unlock( &iv_mutex );
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

    // TODO RTC:101925. PRD enables FIRs in Istep 11. If Istep 12 deconfigures
    // HW that is asserting FIRs and performs the Inner Reconfig Loop then PRD
    // ends up logging errors when it sees FIR bits for the deconfigured HW.
    // The fix is to dispense with the Inner Reconfig Loop, if the code loops
    // back to Istep 10 then everything is cleaned up. This issue will be
    // resolved with RTC 101925
    const bool INNER_LOOP_ENABLED = false;

    // If current step is within major step 12
    if ( INNER_LOOP_ENABLED &&
         ((current >= INNER_START) && (current <= INNER_STOP)) )
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

void setAcceptIstepMessages(bool i_accept)
{
    return IStepDispatcher::getTheInstance().setAcceptIstepMessages(i_accept);
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
        //@TODO RTC:133831
        //err = ESTABLISH_SYSTEM_SMP::call_host_coalesce_host();
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

// ----------------------------------------------------------------------------
// IStepDispatcher::failedDueToDeconfig()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::failedDueToDeconfig(
                                          uint8_t i_step, uint8_t i_substep,
                                          uint8_t i_dStep, uint8_t i_dSubstep)
{
    errlHndl_t err = NULL;

    /*@
     * @errortype
     * @reasoncode       ISTEP_FAILED_DUE_TO_DECONFIG
     * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
     * @moduleid         ISTEP_INITSVC_MOD_ID
     * @userdata1[0:31]  Istep that failed
     * @userdata1[32:63] SubStep that failed
     * @userdata2[0:31]  Desired istep for reconfig loop.
     * @userdata2[32:63] Desired substep for reconfig loop.
     * @devdesc          Deconfigured occurred during an istep. The reconfig loop
     *                   was not performed by Hostboot because either the Istep
     *                   is outside the reconfig loop (desired steps 0), too
     *                   many reconfig loops were attempted, in manufacturing
     *                   mode or in istep mode.
     * @custdesc    A hardware error occurred during the IPL. See previous logs
     *              for details.
     */
    err = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            ISTEP_INITSVC_MOD_ID,
            ISTEP_FAILED_DUE_TO_DECONFIG,
            TWO_UINT32_TO_UINT64(i_step, i_substep),
            TWO_UINT32_TO_UINT64(i_dStep, i_dSubstep));
    err->collectTrace("HWAS_I", 1024);
    err->collectTrace("INITSVC", 1024);
    err->addProcedureCallout(HWAS::EPUB_PRC_FIND_DECONFIGURED_PART,
                             HWAS::SRCI_PRIORITY_HIGH);
    return err;
}

#ifdef CONFIG_RECONFIG_LOOP_TESTS_ENABLE
// ----------------------------------------------------------------------------
// IStepDispatcher::reconfigLoopTestRunner()
// ----------------------------------------------------------------------------
void IStepDispatcher::reconfigLoopTestRunner(   uint8_t i_step,
                                                uint8_t i_substep,
                                                errlHndl_t & o_err )
{
    // Acquire top level handle
    TARGETING::Target* l_pTopLevel = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

    // Local target pointer
    TARGETING::Target* l_pTarget = NULL;

    // Method for checking whether a target is functional
    TARGETING::PredicateIsFunctional l_functional;

    // Read reconfig loop (RL) tests attribute data and only run tests
    // if ATTR_RECONFIG_LOOP_TESTS is read successfully otherwise
    // print an error message and return
    TARGETING::ATTR_RECONFIG_LOOP_TESTS_type l_RLTests = {0};
    if(l_pTopLevel->tryGetAttr<TARGETING::ATTR_RECONFIG_LOOP_TESTS>(l_RLTests))
    {

        // Create pointer to reconfig loop tests data and point to data obtained
        // from test attribute
        reconfigLoopTests_t *l_p_reconfigLoopTests =
            reinterpret_cast<reconfigLoopTests_t *>(&l_RLTests);

        // Loop through all the tests until we find a valid matching test
        for (uint64_t i = 0 ; i < MAX_RCL_TESTS ; i++)
        {
            if ( (l_p_reconfigLoopTests->test[i].majorStep == i_step) &&
                 (l_p_reconfigLoopTests->test[i].minorStep == i_substep) )
            {
                // Acquire target handle for requested HUID
                l_pTarget = l_pTopLevel->getTargetFromHuid(
                         l_p_reconfigLoopTests->test[i].deconfigTargetHuid);

                // If the target associated with the test is functional
                // then induce the reconfig loop otherwise skip since the target
                // may have been deconfigured by a previous test.
                // This way we don't run the same test again.
                if(l_functional(l_pTarget))
                {
                    reconfigLoopInduce (l_pTarget, o_err);
                    TRACFCOMP(g_trac_initsvc, INFO_MRK"reconfigLoopTestRunner: "
                        "Inducing Reconfig Loop. Step: %d.%d, HUID: 0x%08X",
                        i_step, i_substep,
                        l_p_reconfigLoopTests->test[i].deconfigTargetHuid);
                }
                else
                {
                    TRACFCOMP(g_trac_initsvc, INFO_MRK"reconfigLoopTestRunner: "
                        "Step: %d.%d, "
                        "Target HUID: 0x%08X not functional, skiping test.",
                        i_step, i_substep,
                        l_p_reconfigLoopTests->test[i].deconfigTargetHuid);
                }

                // Stop looking for another test and return to istepdispatcher
                // code
                break;
            }

            // Stop looking for tests if the last test is found
            if (l_p_reconfigLoopTests->test[i].lastTest)
            {
                break;
            }
        }
    }
    else
    {
        TRACFCOMP(g_trac_initsvc, ERR_MRK"reconfigLoopTestRunner: "
                "Failed to read ATTR_RECONFIG_LOOP_TESTS attribute data. "
                "SKIPPING TEST!");
    }

    return;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::reconfigLoopInduce()
// ----------------------------------------------------------------------------
void IStepDispatcher::reconfigLoopInduce(TARGETING::Target* i_pDeconfigTarget,
                                         errlHndl_t & o_err)
{

    // Create an error log to induce reconfig loop
    ISTEP_ERROR::IStepError l_StepError;

    /*@
     * @errortype
     * @reasoncode       RECONFIG_LOOP_TEST_RC
     * @severity         ERRL_SEV_UNRECOVERABLE
     * @moduleid         RECONFIG_LOOP_TEST_ID
     * @devdesc          This error log was intentionally created in order to
     *                   induce a reconfigure loop for testing purposes.
     * @custdesc         A reconfigure loop is being induced for testing
     *                   purposes.
     */
    errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           RECONFIG_LOOP_TEST_ID,
                           RECONFIG_LOOP_TEST_RC);

    // Using DELAYED_DECONFIG in the HW callout allows registering the target
    // for deferred deconfiguration.  The actual deconfiguration must be
    // handled externally, specifically by IStepDispatcher::doIstep().
    l_err->addHwCallout(i_pDeconfigTarget,
            HWAS::SRCI_PRIORITY_LOW,
            HWAS::DELAYED_DECONFIG,
            HWAS::GARD_Fatal);
    l_StepError.addErrorDetails(l_err);
    errlCommit(l_err, ISTEP_COMP_ID);
    o_err = l_StepError.getErrorHandle();

    TRACFCOMP(g_trac_initsvc, INFO_MRK"reconfigLoopInduce: "
           "Created reconfig loop induce errorlog");

    return;
}
#endif // CONFIG_RECONFIG_LOOP_TESTS_ENABLE

// ----------------------------------------------------------------------------
// IStepDispatcher::istepPauseSet()
// ----------------------------------------------------------------------------
void IStepDispatcher::istepPauseSet(uint8_t i_step, uint8_t i_substep)
{
    // Acquire top level handle
    TARGETING::Target* l_pTopLevel = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

    // Read ATTR_ISTEP_PAUSE_CONFIG attribute
    TARGETING::ATTR_ISTEP_PAUSE_CONFIG_type l_istepPauseCfgAttr =
        l_pTopLevel->getAttr<TARGETING::ATTR_ISTEP_PAUSE_CONFIG>();

    if(l_istepPauseCfgAttr == 0)
    {
        TRACFCOMP(g_trac_initsvc, ERR_MRK"istepPauseSet: "
                "ATTR_ISTEP_PAUSE_CONFIG not set. Pause will not be applied!");
    }
    else
    {
        // Overlay ATTR_ISTEP_PAUSE_CONFIG data on top of structure
        istepPauseConfig_t *l_p_pauseCfg =
            reinterpret_cast<istepPauseConfig_t *>(&l_istepPauseCfgAttr);

        // Apply pause only if current istep matches requested istep
        if( (i_step == l_p_pauseCfg->majorStep) &&
            (i_substep == l_p_pauseCfg->minorStep))
        {
            TRACFCOMP(g_trac_initsvc, INFO_MRK"istepPauseSet: "
                        "Applying pause before step: %d.%d, "
                        "Pause duration=%d seconds, Full Stop Enable=0x%02X, "
                        "Breakpoint info tag=0x%08X",
                        l_p_pauseCfg->majorStep,
                        l_p_pauseCfg->minorStep,
                        l_p_pauseCfg->pauseLen,
                        l_p_pauseCfg->fullStopEn,
                        l_p_pauseCfg->bpTagInfo
                        );

            // Disable watchdog action to prevent the system from shutting down
#ifdef CONFIG_BMC_IPMI
            errlHndl_t err_ipmi = IPMIWATCHDOG::setWatchDogTimer(
                               IPMIWATCHDOG::DEFAULT_WATCHDOG_COUNTDOWN,
                               static_cast<uint8_t>
                                          (IPMIWATCHDOG::DO_NOT_STOP |
                                           IPMIWATCHDOG::BIOS_FRB2), // default
                               IPMIWATCHDOG::NO_ACTIONS); // do nothing when
                                                          // timeout occurs
            if(err_ipmi)
            {
               TRACFCOMP(g_trac_initsvc,
                              "init: ERROR: Failed to disable IPMI watchdog");
                err_ipmi->collectTrace("INITSVC", 1024);
                errlCommit(err_ipmi, INITSVC_COMP_ID );

            }
#endif
            // If full stop is requested then send breakpoint message to FSP.
            // This stop can be resumed via external command from FSP.
            if(l_p_pauseCfg->fullStopEn)
            {
                iStepBreakPoint(l_p_pauseCfg->bpTagInfo);
            }
            // If infinite pause is set then hang in a tight loop indefinitely.
            // This is a permanent stop that cannot be resumed via any command.
            else if(l_p_pauseCfg->pauseLen == ISTEP_PAUSE_SET_INFINITE)
            {
                TRACFCOMP(g_trac_initsvc, INFO_MRK"istepPauseSet: "
                        "pauseLen=0x%02X, Permanent pause enabled.",
                        l_p_pauseCfg->pauseLen
                        );

#ifdef CONFIG_CONSOLE
                CONSOLE::displayf(NULL, "istepPauseSet: "
                        "pauseLen=0x%02X, Permanent pause enabled.",
                        l_p_pauseCfg->pauseLen
                        );
                CONSOLE::flush();
#endif
                while(1)
                {
                    nanosleep(1,0);
                }
            }
            // Otherwise sleep for the requested number of seconds
            else
            {
                nanosleep(l_p_pauseCfg->pauseLen,0);
            }

#ifdef CONFIG_BMC_IPMI
            // Re-enable the watchdog timer with default settings
            err_ipmi = IPMIWATCHDOG::setWatchDogTimer(
                       IPMIWATCHDOG::DEFAULT_WATCHDOG_COUNTDOWN);

            if(err_ipmi)
            {
               TRACFCOMP(g_trac_initsvc,
                              "init: ERROR: Set IPMI watchdog Failed");
                err_ipmi->collectTrace("INITSVC", 1024);
                errlCommit(err_ipmi, INITSVC_COMP_ID );

            }
#endif

        }
    }
}

}; // namespace
