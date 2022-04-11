/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istepdispatcher.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
/* [+] Google Inc.                                                        */
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
#include <errl/errlmanager.H>
#include <initservice/isteps_trace.H>    //  ISTEPS_TRACE buffer
#include <initservice/initsvcudistep.H>  //  InitSvcUserDetailsIstep
#include <initservice/taskargs.H>        //  TASK_ENTRY_MACRO
#include <initservice/initserviceif.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/attrsync.H>
#include <targeting/attrrp.H>
#include <fapi2/plat_attr_override_sync.H>
#include <mbox/mbox_queues.H>            // HB_ISTEP_MSGQ
#include <mbox/mboxif.H>                 // register mailbox
#include <intr/interrupt.H>
#include <isteps/istepmasterlist.H>
#include "istepdispatcher.H"
#include "istep_mbox_msgs.H"
#include "splesscommon.H"
#include "progressSrc.H"
#include <diag/attn/attn.H>
#include <isteps/istep_reasoncodes.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas.H>
#include <hwas/hwasPlat.H>
#include <targeting/attrPlatOverride.H>
#include <console/consoleif.H>
#include <isteps/hwpisteperror.H>
#include <pnor/pnorif.H>
#include <lpc/lpcif.H>
#include <istep18/establish_system_smp.H>
#include <arch/magic.H>

#ifdef CONFIG_PLDM
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/extended/pldm_watchdog.H>
#include <isteps/bios_attr_accessors/bios_attr_parsers.H>
#include <targeting/common/mfgFlagAccessors.H>
#endif

#include <initservice/bootconfigif.H>
#include <trace/trace.H>
#include <util/utilmbox_scratch.H>
#include <secureboot/service.H>
#include <secureboot/trustedbootif.H>
// FIXME RTC: 210975
//#include <p9_perst_phb.H>
//#include <plat_hwp_invoker.H>
#include <ipcSp.H>
// ---------------------------
// Used to grab SBE boot side
#include <sbe/sbe_update.H>
#include <devicefw/userif.H>
//#include <p9_perv_scom_addresses.H>
// ---------------------------
#include <initservice/extinitserviceif.H>
#include <kernel/terminate.H>

#ifdef CONFIG_PLDM
#include <pldm/extended/pdr_manager.H>
#endif

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
const uint8_t SW_RECONFIG_START_STEP = 7;
const uint8_t SW_RECONFIG_START_SUBSTEP = 1;
const uint8_t HB_START_ISTEP = 6;

// STEP and SUBSTEP must -NOT- be defined within the same FINAL
// STEP (e.g. today is STEP 21, since STEP 21.4 is the final istep),
// due to the current algorithm design.
// As designed (review the related logic on logStats for details)
// STEP and SUBSTEP should also avoid being moved to -ANY- STEP/SUBSTEP
// that may not complete within the doIstep loop (i.e. caution on STEP/SUBSTEP
// being a hostboot termination point (where hostboot gets shutdown).
// Any STEP/SUBSTEP which disrupts the normal doIstep loop logic from fully
// executing should be avoided if accurate times are desired.

const uint8_t STATS_COMPLETE_STEP = 16;   // host_ipl_complete 16.5
const uint8_t STATS_COMPLETE_SUBSTEP = 5; // host_ipl_complete 16.5

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
    iv_highestIStepDone(0),
    iv_highestSubstepDone(0),
    iv_curIStep(0),
    iv_curSubStep(0),
    iv_pIstepMsg(NULL),
    iv_shutdown(false),
    iv_futureShutdown(false),
    iv_istepToCompleteBeforeShutdown(0),
    iv_substepToCompleteBeforeShutdown(0),
    iv_acceptIstepMessages(true),
    iv_newGardRecord(false),
    iv_p9_phbPerstLibLoaded(false)

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
    // message to error log daemon and tell it to shutdown and delete
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

#ifdef CONFIG_PLDM
void IStepDispatcher::parsePLDMBiosAttrs(ISTEP_ERROR::IStepError & io_stepError)
{
    using bios_attribute_parser = void(*)(std::vector<uint8_t>&,
                                        std::vector<uint8_t>&,
                                        ISTEP_ERROR::IStepError &);

    const std::vector<bios_attribute_parser> bios_attr_parsers
    {
        ISTEP::parse_hb_tpm_required,
        ISTEP::parse_hb_field_core_override,
        ISTEP::parse_hb_memory_mirror_mode,
        ISTEP::parse_hb_key_clear_request,
        ISTEP::parse_hb_number_huge_pages,
        ISTEP::parse_hb_huge_page_size,
        ISTEP::parse_hb_memory_region_size,
        ISTEP::parse_hb_mfg_flags,
        ISTEP::parse_hb_hyp_switch,
        ISTEP::parse_pvm_fw_boot_side,
        ISTEP::parse_hb_host_usb_enablement,
        ISTEP::parse_hb_ioadapter_enlarged_capacity,
        ISTEP::parse_hb_inhibit_bmc_reset,
        ISTEP::parse_hb_lateral_cast_out_mode
    };

    std::vector<uint8_t> bios_string_table, bios_attr_table;
    for(auto parser_fn : bios_attr_parsers)
    {
        // if parser_fn generates any errors it will attach them to
        // i_stepError if neccessary and commit the log itself.
        parser_fn(bios_string_table, bios_attr_table, io_stepError);
    }

    return;
}
#endif

// ----------------------------------------------------------------------------
// IStepDispatcher::init()
// ----------------------------------------------------------------------------
void IStepDispatcher::init(errlHndl_t &io_rtaskRetErrl)
{
    errlHndl_t err = NULL;

    printk( "IStepDispatcher entry.\n" );
    TRACFCOMP( g_trac_initsvc, "IStepDispatcher entry." );

    //  Read and process the Hostboot configuration flags
    BOOTCONFIG::readAndProcessBootConfig();

    TARGETING::Target* l_pTopLevelTarget = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevelTarget);

    assert(l_pTopLevelTarget != NULL );

    do
    {
        // Need to get ATTR overrides first if non FSP system
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

#ifdef CONFIG_PLDM
            const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
            if(!sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
            {
                // All error logs that occur while parsing the PLDM bios attributes will be
                // committed within the function. If the error that occurs should TI the system,
                // then the parser should attach the errlog to the step error.
                ISTEP_ERROR::IStepError l_stepError;
                parsePLDMBiosAttrs(l_stepError);
                if(!l_stepError.isNull())
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK
                              "IStepDispatcher::init: Error(s) occurred while "
                              "parsing a PLDM BIOS Attribute that requires "
                              "Hostboot to TI.");
                    err = l_stepError.getErrorHandle();
                    break;
                }

                //Look at the MFG_FLAGS attribute on the system target
                //and decide if we need to update the CDM Policy attribute
                //to ignore all gards.
                if (TARGETING::isNoGardSet())
                {
                    TRACFCOMP(g_trac_initsvc, INFO_MRK
                            "MNFG_NO_GARD bit is set - setting CDM_POLICIES_MANUFACTURING_DISABLED in ATTR_CDM_POLICIES");
                    sys->setAttr<TARGETING::ATTR_CDM_POLICIES>(
                            l_pTopLevelTarget->getAttr<TARGETING::ATTR_CDM_POLICIES>() | TARGETING::CDM_POLICIES_MANUFACTURING_DISABLED);
                }
            }
            else
            {
                TRACFCOMP(g_trac_initsvc, INFO_MRK
                          "IStepDispatcher::init: MPIPL detected, using PLDM "
                          "BIOS attrs values from previous boot");
            }
#endif
            // Inform ErrlManager to reread any attribute values that it may
            // have cached away in the event that those values were overridden.
            TRACFCOMP( g_trac_initsvc, "IStepDispatcher: init: calling "
                      "ERRORLOG::ErrlManager::errlResourceReady"
                      "(ERRORLOG::UPDATE_ATTRIB_VARS(0x%02X))",
                      ERRORLOG::UPDATE_ATTRIB_VARS );
            ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::UPDATE_ATTRIB_VARS);

        }  // end if(!iv_spBaseServicesEnabled)

        iv_istepMode = l_pTopLevelTarget->getAttr<TARGETING::ATTR_ISTEP_MODE>();

        TRACFCOMP(g_trac_initsvc, "IStepDispatcher: IStep Mode: %d", iv_istepMode);

        // Only consider Tracelite if OpenPOWER XML is used
#ifdef CONFIG_INCLUDE_XML_OPENPOWER
        bool l_tlEnabled = false;
#ifdef CONFIG_PLDM
        // first check if the BMC has told us the debug
        // console is enabled
        std::vector<uint8_t> string_table, attr_table;
        errlHndl_t err_pldm = PLDM::getDebugConsoleEnabled(string_table, attr_table, l_tlEnabled);
        if(err_pldm)
        {
           TRACFCOMP(g_trac_initsvc,
                          ERR_MRK"init: Attempt to see if debug console is enabled via PLDM failed");
            err_pldm->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            err_pldm->collectTrace("INITSVC", 1024);
            errlCommit(err_pldm, INITSVC_COMP_ID );
        }
#endif // CONFIG_PLDM

#ifdef CONFIG_CONSOLE_TRACE_LITE
        // If this config flag is set the user always ways tracelite data
        // sent to the debug console (UART2)
        l_tlEnabled = true;
#endif // CONFIG_CONSOLE_TRACE_LITE

        // Support legacy OP_TRACE_LITE attribute by checking
        // it if the BMC/config flags have not told us to enable
        // debug console already. If the BMC/config are already telling us
        // to enable the debug console just ignore this attribute.
        if(!l_tlEnabled)
        {
            // Get tracelite setting from top level target attributes
            l_tlEnabled = l_pTopLevelTarget->getAttr<TARGETING::ATTR_OP_TRACE_LITE>();
        }
        TRACE::setTraceLite(l_tlEnabled);
#endif // CONFIG_INCLUDE_XML_OPENPOWER


        //////////////////
        // Send to console which SBE side we are currently on
        //////////////////
        SBE::sbeSeepromSide_t l_bootside = SBE::SBE_SEEPROM_INVALID;
        TARGETING::Target * l_masterTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(l_masterTarget);

        // NOTE: can't just call SBE::getSbeBootSeeprom(..) as it isn't loaded

        uint64_t scomData = 0x0;
        // Read Selfboot Control/Status register
        size_t op_size = sizeof(scomData);
        err = deviceRead( l_masterTarget,
                          &scomData,
                          op_size,
                          DEVICE_SCOM_ADDRESS(0x00050008) );
        if( err )
        {
            TRACFCOMP( g_trac_initsvc, ERR_MRK"IStepDispatcher() - "
                       "Unable to find SBE boot side, Error "
                       "reading SB CS SCOM (0x00050008) from Target :"
                       "HUID=0x%.8X, RC=0x%X, PLID=0x%lX",
                       TARGETING::get_huid(l_masterTarget),
                       ERRL_GETRC_SAFE(err),
                       ERRL_GETPLID_SAFE(err));
            err->collectTrace("INITSVC", 1024);
            errlCommit(err, INITSVC_COMP_ID );
        }
        else
        {
            if(scomData & SBE::SBE_BOOT_SELECT_MASK)
            {
                l_bootside = SBE::SBE_SEEPROM1;
            }
            else
            {
                l_bootside = SBE::SBE_SEEPROM0;
            }

            TRACFCOMP( g_trac_initsvc,
                INFO_MRK"IStepDispatcher(): SBE boot side %d for proc=%.8X",
                l_bootside, TARGETING::get_huid(l_masterTarget) );
            printk( "SBE Boot Side = %d\n", l_bootside );

            // Sending to console SBE side
            CONSOLE::displayf(CONSOLE::VUART1,  NULL,
                    "Booting from SBE side %d on master proc=%.8X",
                    l_bootside, TARGETING::get_huid(l_masterTarget) );
            CONSOLE::flush();
        }
        ////////////////


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

        if(iv_istepMode)
        {
            // Note: PLDM watchdog is never armed in istep mode

            // In IStep mode (receive messages to run individual steps)
            // always listen to debug interface.  If on FSP this allows
            // both HWSV, Cronus, and debug tools to control the IPL
            TRACFCOMP(g_trac_initsvc, "IStep mode, start debug 'spless' interface");
            tid_t spTaskTid = task_create(spTask, iv_msgQ);
            assert(spTaskTid > 0);

            // Call the message handler to handle messages from FSP or SPless
            // user console, these messages include the IStep messages. This
            // function never returns.
            msgHndlr();
        }
        else
        {
            // Reset watchdog timer
            sendProgressCode();

            // Non-IStep mode (run all isteps automatically)
            if(iv_spBaseServicesEnabled)
            {
                // Base Services available. Figure out if HWSV has overrides
                uint8_t l_attrOverridesExist = 0;

                l_attrOverridesExist = l_pTopLevelTarget->
                    getAttr<TARGETING::ATTR_PLCK_IPL_ATTR_OVERRIDES_EXIST>();

                if (l_attrOverridesExist && SECUREBOOT::allowAttrOverrides())
                {

                    fapi2::theAttrOverrideSync().getAttrOverridesFromFsp();
                }

                // Start a new thread to handle non-IStep messages from the FSP
                // (e.g. sync point reached)
                tid_t msgHndlrTaskTid = task_create(startMsgHndlrThread, this);
                assert(msgHndlrTaskTid > 0);
            }

            //Update Targeting in the Event Attribute Overrides apply to that logic
            //    This will refresh cached values for attrs like
            //    ATTR_HIDDEN_ERRLOGS_ENABLE
            ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::TARG);

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
                fapi2::theAttrOverrideSync().sendAttrOverridesAndSyncsToFsp();
            }
        }
    } while(0);

    TRACFCOMP( g_trac_initsvc, "IStepDispatcher finished.");
    printk( "IStepDispatcher exit.\n" );
    io_rtaskRetErrl = err;
    err = nullptr;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::executeAllISteps()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::executeAllISteps()
{
    errlHndl_t errhdl = NULL;
    uint32_t istep = 0;
    uint32_t substep = 0;
    bool l_doReconfig = false;
    uint32_t numReconfigs = 0;
    bool l_manufacturingMode = false;

    // We are terminating in order to trigger a reconfig loop on the FSP
    bool l_termToReconfig = false;

    // soft reconfig loops happen really fast
    // and since for scale-out systems it only happens for istep 7
    // there is no significant max time delay to recover the system
    // because all in all other steps it will result in TI
    const uint32_t MAX_NUM_RECONFIG_ATTEMPTS = 30;

    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::executeAllISteps()");

    // Find out if in manufacturing mode
    TARGETING::Target* l_pTopLevel = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
    // Assert if we still have a nullptr target
    assert(l_pTopLevel != nullptr,"IstepDispatcher::executeAllISteps()"
        " expected top level target, but got nullptr.");

    // Check to see if SRC_TERM bit is set in MFG flags
    if (TARGETING::areAllSrcsTerminating())
    {
        TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps:"
                  " In manufacturing mode");
        l_manufacturingMode = true;
    }

    // Set the collection point across the various platforms in order
    // to collect per Node statistics
    // If we collect any later we cannot gather across all the Nodes
    // since only the Primary Node will handle the final RUNTIME setup steps
    g_ipl_stats[STATS_COMPLETE_STEP].substeps[STATS_COMPLETE_SUBSTEP].exit = 1;

    while (istep < MaxISteps)
    {
        INITSERVICE::start_istep_timer(istep);
        substep = 0;
        while (substep < g_isteps[istep].numitems)
        {
            INITSERVICE::start_substep_timer(istep, substep);
            if( INITSERVICE::isIplStopped() == true )
            {
                // if we came in here and we are connected to a BMC, then
                // we are in the process of an orderly shutdown, reset the
                // watchdog to give ample time for the graceful shutdown
                // to proceed.
                sendProgressCode();
                stop();
            }

            // Keep track of each call since the last one will not return here
            // and we need to know this at completion time in initservice.C
            INITSERVICE::start_substep_inprogress(istep, substep);

            //-----------------------------------------
            // Issue the Istep
            errhdl = doIstep(istep, substep, l_doReconfig);
            //-----------------------------------------

            INITSERVICE::stop_substep_inprogress(istep, substep);

            if (l_doReconfig)
            {
                // Something occurred that requires a reconfig loop
                TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps:"
                          " Reconfig required after IStep %d:%d",
                          istep, substep);

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
#ifdef CONFIG_PLDM
                    PLDM::thePdrManager().sendAllFruFunctionalStates();
#endif

                    // Within the Reconfig Loop, going to loop back
                    // first, check to make sure we still have a bootable system
                    errlHndl_t l_errl = HWAS::checkMinimumHardware();
                    if (l_errl)
                    {
                        // non-bootable system - we want to return this error.
                        TRACFCOMP(g_trac_initsvc,
                            ERR_MRK"Error from checkMinimumHardware");

                        if (errhdl == NULL)
                        {
                            errhdl = l_errl;
                            l_errl = NULL;
                        }
                        else
                        {
                            // The IStep returned an error and this is likely
                            // the generic 'IStep failed' from the
                            // IStepError class; real errors detailing the
                            // failure have already been committed. Record the
                            // PLID and delete it if 'Istep failed' or
                            // commit it otherwise. This will be replaced by
                            // the checkMinimumHardware error with the same
                            // plid that matches the real errors
                            const uint32_t l_plid = errhdl->plid();
                            if (ISTEP::RC_FAILURE == errhdl->reasonCode())
                            {
                                delete errhdl;
                                errhdl = nullptr;
                            }
                            else
                            {
                                errlCommit(errhdl, INITSVC_COMP_ID);
                            }
                            errhdl = l_errl;
                            l_errl = NULL;
                            errhdl->plid(l_plid);
                        }

                        // Break out of the istep loop with the error
                        break;
                    } // if error from checkMinimumHardware

                    // we have a bootable system, so loop back
                    numReconfigs++;
                    uint32_t l_plid = 0;

                    if (errhdl)
                    {
                        // The IStep returned an error, This is the generic
                        // 'IStep failed' from the IStepError class, the real
                        // errors detailing the failure have already been
                        // committed. Record the PLID and commit it. This will
                        // be replaced by the ReconfigLoop info error with the
                        // same plid that matches the real errors
                        l_plid = errhdl->plid();

                        // Commit the istep log as informational since it
                        // might include some useful information
                        errhdl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                        errlCommit(errhdl, INITSVC_COMP_ID);
                        errhdl = NULL;
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
                    errhdl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        ISTEP_INITSVC_MOD_ID,
                        ISTEP_RECONFIG_LOOP_ENTERED,
                        errWord,
                        numReconfigs);
                    errhdl->collectTrace("HWAS_I", 1024);

                    if (l_plid != 0)
                    {
                        // Use the same plid as the IStep error
                        errhdl->plid(l_plid);
                    }
                    errlCommit(errhdl, INITSVC_COMP_ID);
                    istep = newIstep;
                    substep = newSubstep;
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps: "
                              "Reconfig Loop: Back to %d:%d",
                              istep, substep);
                    continue;
                }
                else
                {
                    // Reconfig loop required, but the istep is either outside
                    // of the reconfig loop, too many reconfigs have been
                    // attempted, in manufacturing mode, or in MPIPL

                    // FSP and not a doIstep error then
                    // return an error to cause termination
                    if (!errhdl && iv_spBaseServicesEnabled)
                    {
                        l_termToReconfig = true;
                        errhdl = failedDueToDeconfig(istep, substep,
                                                     newIstep, newSubstep);
                    }
                    // Not FSP and not in mfg mode,
                    // still want to do the reconfig
                    else if (!iv_spBaseServicesEnabled && !l_manufacturingMode)
                    {
                        // If there was a doIstep error then commit it
                        // before the reconfig loop
                        if (errhdl)
                        {
                            errlCommit(errhdl, INITSVC_COMP_ID);
                        }

                        #ifdef CONFIG_CONSOLE
                        auto l_reconfigAttr =
                            l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
                        bool l_deconfig = false;
                        if( l_reconfigAttr ==
                            TARGETING::RECONFIGURE_LOOP_DECONFIGURE )
                        {
                            l_deconfig = true;
                        }

                        CONSOLE::displayf(CONSOLE::VUART1, NULL,
                            "System Shutting Down To Perform Reconfiguration After %s",
                            l_deconfig ? "Deconfig" : "Recoverable Error" );
                        CONSOLE::flush();
                        #endif

                        TRACFCOMP(g_trac_initsvc, INFO_MRK"executeAllISteps: sending reboot request");
                        // Request BMC to do power cycle that sends shutdown
                        // and reset the host
                        requestReboot("reconfig loop");
                    }
                }
            }

#ifdef CONFIG_BMC_PLDM
            if(l_manufacturingMode &&
                (ERRORLOG::ErrlManager::errlCommittedThisBoot()))
            {
                TRACFCOMP(g_trac_initsvc, "Manufacturing Mode is set and an "
                    "error log has been committed. Stopping the IPL.");

                #ifdef CONFIG_CONSOLE
                CONSOLE::displayf(CONSOLE::VUART1, NULL, "Manufacturing Mode is set and an "
                    "error log has been committed. Stopping the IPL.");
                CONSOLE::flush();
                #endif

                // Flush out the error logs so we can get as much info as
                // possible
                ERRORLOG::ErrlManager::callFlushErrorLogs();

                // Quiesce new isteps, including external requests
                INITSERVICE::stopIpl();

#ifdef CONFIG_HANG_ON_MFG_SRC_TERM
                // Stop the IPL
                stop();
#else
                // Shutdown with a TI
                doShutdown( SHUTDOWN_MFG_TERM );
#endif

            }
#endif

            if (errhdl)
            {
                TRACFCOMP(g_trac_initsvc, ERR_MRK"executeAllISteps: "
                          "IStep Error on %d:%d", istep, substep);
                break;
            }

            INITSERVICE::stop_substep_timer(istep, substep);

            // Call logStats after the stop_substep timer
            // We do it here versus after the istep timer stop to capture
            // the substep we are triggering from (STATS_COMPLETE_SUBSTEP)
            // this does add the computation time of logStats within
            // the STATS_COMPLETE_SUBSTEP
            if (g_ipl_stats[istep].substeps[substep].exit == 1)
            {
                TRACFCOMP(g_trac_initsvc, INFO_MRK"logStats host_ipl_complete");
                INITSERVICE::logStats();
            }
            substep++;
        }

        if (errhdl)
        {
            // If we are terminating the IPL to force a reconfig loop on the
            //  FSP then leave the severity alone
            if( !l_termToReconfig )
            {
                // Ensure severity reflects IPL will be terminated
                if (errhdl->sev() != ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM)
                {
                    errhdl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }
            }
            break;
        }

        INITSERVICE::stop_istep_timer( istep );
        istep++;

        // the very last istep stop time is captured in initservice.C in _doShutdown

    }

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::executeAllISteps()");

    return errhdl;
}



//-----------------------------------------------------------------------------
// IStepDispatcher::stop()
// ---------------------------------------------------------------------------
void IStepDispatcher::stop()
{

#ifdef CONFIG_CONSOLE
    CONSOLE::displayf(CONSOLE::VUART1, NULL,"Stopping istep dispatcher");
    CONSOLE::flush();
#endif

    TRACFCOMP(g_trac_initsvc, "IStepDispatcher::stop() - Stopping istep"
            "dispatcher.");

    printk( "IStepDispatcher stopping" );
    while(1)
    {
        task_yield();
    }
}

// ----------------------------------------------------------------------------
// IStepDispatcher::doIstep()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::doIstep(uint32_t i_istep,
                                    uint32_t i_substep,
                                    bool & o_doReconfig)
{
    errlHndl_t err = nullptr;
    o_doReconfig = false;

    INITSERVICE::ShadowIstepData( static_cast<uint8_t>(i_istep),
                                  static_cast<uint8_t>(i_substep) );

    // Get the Task Info for this step
    const TaskInfo * theStep = findTaskInfo(i_istep, i_substep);

    do {

    TARGETING::Target* l_pTopLevel = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

    // If the step has valid work to be done, then execute it.
    if(NULL != theStep)
    {
        INITSERVICE::set_substep_valid(i_istep, i_substep, theStep->taskname);
#ifdef CONFIG_P9_VPO_COMPILE //extra traces to printk for vpo debug
        printk("doIstep: step %d, substep %d, "
                  "task %s\n", i_istep, i_substep, theStep->taskname);
#endif
        TRACFCOMP(g_trac_initsvc,ENTER_MRK"doIstep: step %d, substep %d, "
                  "task %s", i_istep, i_substep, theStep->taskname);

        #ifdef CONFIG_SECUREBOOT
        if (SECUREBOOT::enabled())
        {
            auto nextIStepAllowed = iv_highestIStepDone;
            auto nextSubstepAllowed = iv_highestSubstepDone;
            auto rc = getNextIStep(nextIStepAllowed, nextSubstepAllowed);
            if (rc && (i_istep > nextIStepAllowed ||
                      (i_istep == nextIStepAllowed &&
                        i_substep > nextSubstepAllowed))
            )
            {
                TRACFCOMP(g_trac_initsvc,
                    ERR_MRK"doIstep: failed on requested step %d,"
                        " and substep %d, next allowed by secure boot is "
                        "step %d and substep %d", i_istep, i_substep,
                         nextIStepAllowed, nextSubstepAllowed);

                /*@
                 * @errortype
                 * @reasoncode       ISTEP_SKIP_ATTEMPTED
                 * @moduleid         ISTEP_INITSVC_MOD_ID
                 * @userdata1[00:31] istep requested
                 * @userdata1[32:64] substep requested
                 * @userdata2[00:31] highest istep allowed
                 * @userdata2[32:64] highest substep allowed
                 * @devdesc          Istep skip prevented in secure mode
                 * @custdesc         An internal firmware error occured
                 */
                err = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         ISTEP_INITSVC_MOD_ID,
                                         ISTEP_SKIP_ATTEMPTED,
                                         TWO_UINT32_TO_UINT64(
                                            i_istep,
                                            i_substep),
                                         TWO_UINT32_TO_UINT64(
                                            nextIStepAllowed,
                                            nextSubstepAllowed));
                break;
            }
        }
        #endif // CONFIG_SECUREBOOT

        mutex_lock(&iv_mutex);

        // Record current IStep, SubStep
        iv_curIStep = i_istep;
        iv_curSubStep = i_substep;

        // Send Progress Code
        err = this->sendProgressCode(false);

        mutex_unlock(&iv_mutex);

        if(err)
        {
            // Commit the error and continue
            errlCommit(err, INITSVC_COMP_ID);
        }

        // Handle shutdown and start progress thread
        if (!iv_istepMode)
        {
            // If a shutdown request has been received
            if (isShutdownRequested())
            {
                // Do not begin new IStep and shutdown
                shutdownDuringIpl();
            }
            else
            {
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

        //---------------------------------------------------------
        // Run the Istep
        err = InitService::getTheInstance().executeFn(theStep, NULL);
        if( err )
        {
            TRACFCOMP(g_trac_initsvc,"Error returned from istep : %.8X=%.4X",
                      err->eid(), err->reasonCode());
        }

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

                errlHndl_t l_errl =
                    TARGETING::AttrRP::syncAllAttributesToSP();

                if(l_errl)
                {
                    TRACFCOMP(g_trac_initsvc, ERR_MRK"doIstep: sync attributes"
                             " failed, see 0x%08X for details", l_errl->eid());
                    errlCommit(l_errl, INITSVC_COMP_ID);
                }
            }
        }

        // Run check attention if system attribute is set
        bool runCheckAttn = l_pTopLevel->getAttr<TARGETING::ATTR_CHECK_ATTN_AFTER_ISTEP_FAIL>();

        // Check for any attentions and invoke PRD for analysis
        // if not in MPIPL mode and no istep error
        if (true == iv_mpiplMode)
        {
            runCheckAttn = false;
        }
        else if ((true == theStep->taskflags.check_attn) && !err)
        {
            runCheckAttn = true;
        }

        // Run check attention if flag is set
        if (runCheckAttn)
        {
            TRACDCOMP(g_trac_initsvc,
                      INFO_MRK"Check for attentions and invoke PRD" );

            errlHndl_t l_errl = ATTN::checkForIplAttentions();

            if (l_errl)
            {
                TRACFCOMP( g_trac_initsvc, ERR_MRK"doIstep: error from "
                          "checkForIplAttentions");

                if (err)
                {
                    l_errl->plid(err->plid());
                    errlCommit(l_errl, INITSVC_COMP_ID);
                }
                else
                {
                    err = l_errl;
                    l_errl = nullptr;
                }
            }

            // Zero out attribute to handle reconfig loops
            l_pTopLevel->setAttr<TARGETING::ATTR_CHECK_ATTN_AFTER_ISTEP_FAIL>(0);
        }

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
            // We need to flush the errl buffer first
            ERRORLOG::ErrlManager::callFlushErrorLogs();

            // Regardless of the way the flush came back, we need to try to
            // process the deferred deconfigs
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


        //--- Mark we have finished the istep in the scratch reg
        SPLESS::MboxScratch5_t l_scratch5;
        l_scratch5.debug.magic = SPLESS::MboxScratch5_t::ISTEP_PROGRESS_MAGIC;
        l_scratch5.debug.stepFinish = 1;
        l_scratch5.debug.majorStep = iv_curIStep;
        l_scratch5.debug.minorStep = iv_curSubStep;
        Util::writeScratchReg( SPLESS::MboxScratch5_t::REG_ADDR,
                               l_scratch5.data32 );

        TRACFCOMP(g_trac_initsvc, EXIT_MRK"doIstep: step %d, substep %d",
                  i_istep, i_substep);
    }
    else
    {
        TRACDCOMP( g_trac_initsvc,
                  INFO_MRK"doIstep: Empty Istep, nothing to do!" );
    }

#ifdef CONFIG_EARLY_TESTCASES
    // Check to see if we should run testcases here
    TARGETING::ATTR_EARLY_TESTCASES_ISTEP_type l_runCxxIstep =
      l_pTopLevel->getAttr<TARGETING::ATTR_EARLY_TESTCASES_ISTEP>();
    if( (((i_istep & 0xFF) << 8) | (i_substep & 0xFF))
        == l_runCxxIstep )
    {
        TRACFCOMP(g_trac_initsvc, "doIstep: Executing CXX testcases!");
        uint32_t l_status = SHUTDOWN_STATUS_GOOD;

        //  - Run CXX testcases
        errlHndl_t l_errl = INITSERVICE::executeUnitTests();
        if (l_errl)
        {
            l_status = SHUTDOWN_STATUS_UT_FAILED;
            if (err)
            {
                l_errl->plid(err->plid());
                errlCommit(l_errl, INITSVC_COMP_ID);
            }
            else
            {
                err = l_errl;
                l_errl = nullptr;
            }
        }

        //  - Call shutdown using payload base, and payload entry.
        // NOTE: this call will not return if successful.
        TARGETING::Target* l_pSys = NULL;
        TARGETING::targetService().getTopLevelTarget( l_pSys );
        uint64_t payloadBase =
          l_pSys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        payloadBase = (payloadBase * MEGABYTE);
        uint64_t payloadEntry =
          l_pSys->getAttr<TARGETING::ATTR_PAYLOAD_ENTRY>();
        INITSERVICE::doShutdown( l_status,
                                 false,
                                 payloadBase,
                                 payloadEntry );
    }
#endif

    } while (0); // if there was an error break here

    if (!err && theStep)
    {
        // update high watermark for istep and substep but don't ever
        // decrease it. Note: this code assumes you were allowed to execute
        // the istep (we just got done with it after all).
        if (i_substep > iv_highestSubstepDone &&
            i_istep == iv_highestIStepDone)
        {
            iv_highestSubstepDone = i_substep;
        }
        else if (i_istep > iv_highestIStepDone)
        {
            iv_highestIStepDone = i_istep;
            iv_highestSubstepDone = i_substep;
        }
        // else we do nothing, because we just did an istep that is lower
        // than the watermark
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

            case PERST_ASSERT:
                // PERST Assert requested from Fsp
                TRACFCOMP(g_trac_initsvc, INFO_MRK"msgHndlr: PERST_ASSERT");
                // Further process the PERST Assert message
                handlePerstMsg(pMsg);
                break;

            case PERST_NEGATE:
                // PERST Negate requested from Fsp
                TRACFCOMP(g_trac_initsvc, INFO_MRK"msgHndlr: PERST_NEGATE");
                // Further process the PERST Negate message
                handlePerstMsg(pMsg);
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
        // Tell Simics we are waiting for the FSP to do something
        MAGIC_WAITING_FOR_FSP();

        // Wait for the condition variable to be signalled
        mutex_lock(&iv_mutex);
        while((!iv_syncPointReached) && (!iv_shutdown) && (!iv_futureShutdown))
        {
            sync_cond_wait(&iv_cond, &iv_mutex);
        }
        // If shutdown request has been received from the FSP
        if (iv_shutdown || iv_futureShutdown)
        {
            mutex_unlock(&iv_mutex);
            shutdownDuringIpl();
        }
        else
        {
            iv_syncPointReached = false;
            mutex_unlock(&iv_mutex);
        }

        // Tell Simics we are done waiting
        MAGIC_DONE_WAITING_FOR_FSP();
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

errlHndl_t IStepDispatcher::sendAttnMonitorChipIdMsg(
                    const std::vector<TARGETING::ATTR_HUID_type> & i_huid_list )
{
    errlHndl_t l_err = NULL;

    TRACFCOMP(g_trac_initsvc,
        ENTER_MRK"IStepDispatcher::sendAttnMonitorChipIdMsg");

    if( !iv_spBaseServicesEnabled )
    {
        TRACFCOMP( g_trac_initsvc,
            INFO_MRK"sendAttnMonitorChipIdMsg: The ATTN service runs on the "
            "FSP and no FSP was found so we are skipping sending message to "
            "ATTN service.");
    }
    else if (i_huid_list.empty())
    {
       TRACFCOMP( g_trac_initsvc, INFO_MRK"sendAttnMonitorChipIdMsg: empty huid list" );
    }
    else
    {
        INITSERVICE::attn_chipid_msg * l_data_ptr = nullptr;

        msg_t * myMsg = msg_allocate();
        myMsg->type = INITSERVICE::ATTN_MONITOR_CHIPID_LIST;

        // Contains the full size of the extra_data field of myMsg
        // extra_data includes attn_chipid_msg + list of HUIDs.
        // attn_chipid_msg.data is the start of the huid list so
        // need to remove that variable's size from the total
        uint16_t l_total_size =
            (sizeof(INITSERVICE::attn_chipid_msg) - sizeof(l_data_ptr->data)) +
            (sizeof(TARGETING::ATTR_HUID_type) * i_huid_list.size());

        myMsg->data[0] = 0;
        myMsg->data[1] = l_total_size;
        myMsg->extra_data = MBOX::allocate(l_total_size);

        l_data_ptr = reinterpret_cast<INITSERVICE::attn_chipid_msg *>
                        (myMsg->extra_data);

        // total chip huid's in list
        l_data_ptr->chipIdCount = i_huid_list.size();

        // data length in bytes of the list (sizeof(huid) * Number of huids)
        l_data_ptr->size = sizeof(TARGETING::ATTR_HUID_type) *
                           i_huid_list.size();

        // now fill in the list with huids
        std::copy(i_huid_list.begin(), i_huid_list.end(), &(l_data_ptr->data));

        TRACFCOMP( g_trac_initsvc,
                  "sendAttnMonitorChipIdMsg: Sending ATTN_MONITOR_CHIPID_LIST"
                  " (0x%.8X) msg", myMsg->type );
        TRACFBIN(g_trac_initsvc, "msg data", myMsg->extra_data, myMsg->data[1]);

        // send message to alert ATTN to start monitoring these chips
        l_err = MBOX::sendrecv(HWSVRQ, myMsg);
        if (l_err)
        {
            TRACFCOMP(g_trac_initsvc,
                ERR_MRK"sendAttnMonitorChipIdMsg: error 0x%.8X from msg send",
                l_err->reasonCode() );
            l_err->collectTrace("INITSVC", 1024);

            // clean up any allocated memory of failed msg
            if((myMsg != nullptr) && (myMsg->extra_data != nullptr))
            {
                free( myMsg->extra_data );
                myMsg->extra_data = nullptr;
            }
        }
        else
        {
            // Check if msg failed at the FSP level by looking at data[0]
            // A non-zero value implies something went wrong
            if (myMsg->data[0] != HWSVR_MSG_SUCCESS)
            {
                TRACFCOMP(g_trac_initsvc, ERR_MRK"sendAttnMonitorChipIdMsg: "
                    "msg failed at HWSV/ATTN level, see plid %.8X",
                    myMsg->data[0] );

                /*@
                 * @errortype
                 * @reasoncode       ISTEP_ATTN_MONITOR_MSG_FAILED
                 * @severity         ERRORLOG::ERRL_SEV_PREDICTIVE
                 * @moduleid         ISTEP_INITSVC_MOD_ID
                 * @userdata1        PLID of failure on FSP
                 * @userdata2        Number of huids in msg
                 * @devdesc          sendAttnMonitorChipIdMsg failed at
                 *                   the FSP level.  Potential checkstops
                 *                   may not be properly handled.
                 * @custdesc         Firmware error during boot
                 */
                l_err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_PREDICTIVE,
                              ISTEP_INITSVC_MOD_ID,
                              ISTEP_ATTN_MONITOR_MSG_FAILED,
                              myMsg->data[0],
                              i_huid_list.size(),
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_err->collectTrace("INITSVC", 1024);

                // Use the same plid as the HWSV/ATTN error
                l_err->plid(myMsg->data[0]);
            }
        }

        // msg cleanup
        // NOTE: extra_data is cleaned up by the receiver
        msg_free(myMsg);
        myMsg = nullptr;
    }

    TRACFCOMP( g_trac_initsvc,
        EXIT_MRK"IStepDispatcher::sendAttnMonitorChipIdMsg");

    return l_err;
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

    // Before triggering the shutdown, disable the automatic attribute sync
    //  that we would normally do.  This is to prevent hangs on the FSP if they
    //  tried to shut us down due to some kind of SBE or MBOX issue.  In these
    //  cases HB could get hung waiting for a response from the FSP that will
    //  never come.
    errlHndl_t l_errhdl = TARGETING::AttrRP::disableAttributeSyncToSP();
    if( l_errhdl )
    {
        TRACFCOMP(g_trac_initsvc,
                  "IStepDispatcher::handleShutdownMsg> Error disabling shutdown");
        errlCommit(l_errhdl, INITSVC_COMP_ID);
    }

    // find the step/substep. The step is in the top 32bits, the substep is in
    // the bottom 32bits and is a byte
    uint8_t istep = ((io_pMsg->data[0] & 0x000000FF00000000) >> 32);
    uint8_t substep = (io_pMsg->data[0] & 0x00000000000000FF);

    if (istep == 0 && substep == 0)
    {
        //Immediate shutdown - Set iv_shutdown (signal will be done below)
        mutex_lock(&iv_mutex);
        iv_shutdown = true;
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

    if (iv_istepMode || iv_syncPointReached)
    {
        TRACFCOMP(g_trac_initsvc,
                  INFO_MRK"ShutdownMsg received %s,"
                  " call shutdownDuringIPL() directly",
                  iv_istepMode ? "while in istep mode" : "after sync point has been reached");
        shutdownDuringIpl();
    }

    // Wake up any thread that might be waiting on a sync point so it will
    //  re-evaluate the new state of the world
    mutex_lock(&iv_mutex);
    sync_cond_broadcast(&iv_cond);
    mutex_unlock(&iv_mutex);

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::handleShutdownMsg");
}

void IStepDispatcher::requestReboot(const char* i_reason)
{
    const auto l_istepMode = TARGETING::UTIL::assertGetToplevelTarget()->
                                getAttr<TARGETING::ATTR_ISTEP_MODE>();

#ifdef CONFIG_CONSOLE
    if(i_reason)
    {
        CONSOLE::displayf(CONSOLE::VUART1, NULL, "Triggering graceful reboot for %s", i_reason);
    }
#endif

    if(l_istepMode)
    {
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::VUART1, NULL, "Reboot prevented in istep mode. Shutting down instead");
#endif
        // Do not issue a reboot - just shut HB down
        shutdownDuringIpl();
    }
    else
    {
        // Always stop dispatching isteps before calling for the reboot
        INITSERVICE::stopIpl();

#ifdef CONFIG_PLDM
        PLDM::thePdrManager().sendAllFruFunctionalStates();

        // Issue a PLDM request for a graceful restart
        errlHndl_t l_errl = PLDM::sendGracefulRestartRequest();
        if(l_errl)
        {
            TRACFCOMP(g_trac_initsvc, ERR_MRK"IStepDispatcher::requestReboot(): Could not request PLDM reboot");
            errlCommit(l_errl, INITSVC_COMP_ID);
        }
#else
        // Non-PLDM shutdown
        shutdownDuringIpl();
#endif
    }
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
// -----------------------------------------------------------------------------
// IStepDispatcher::setNewGardRecord()
// -----------------------------------------------------------------------------
void IStepDispatcher::setNewGardRecord()
{
    TRACDCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::setNewGardRecord");

    mutex_lock(&iv_mutex);
    iv_newGardRecord = true;
    mutex_unlock(&iv_mutex);

    TRACDCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::setNewGardRecord");
    return;
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

    TRACFCOMP(g_trac_initsvc, ENTER_MRK"handleIStepRequestMsg: 0x%016x, istep: %d, substep: %d",
              io_pMsg->data[0], istep, substep);

    // Transfer ownership of the message pointer to iv_pIstepMsg because if the
    // IStep doesn't return (start_payload), it will call sendIstepCompleteMsg
    // which will respond to iv_pIstepMsg
    mutex_lock(&iv_mutex);
    iv_pIstepMsg = io_pMsg;
    io_pMsg = NULL;
    l_acceptMessages = iv_acceptIstepMessages;
    mutex_unlock(&iv_mutex);

    // If istep dispatching has ceased, prevent new isteps from executing
    if(INITSERVICE::isIplStopped() == true)
    {
        /*@
         * @errortype
         * @reasoncode  ISTEP_PROCESSING_DISABLED
         * @severity    ERRORLOG::ERRL_SEV_INFORMATIONAL
         * @moduleid    ISTEP_INITSVC_MOD_ID
         * @userdata1   Istep Requested
         * @userdata2   Substep Requested
         * @devdesc     Istep processing has terminated due to normal shutdown
         *   activity, secure boot key transition, or terminating error
         * @custdesc    Node is no longer accepting istep requests
         */
        err = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            ISTEP_INITSVC_MOD_ID,
            ISTEP_PROCESSING_DISABLED,
            istep,
            substep);
    }
    else if (l_acceptMessages)
    {
        err = doIstep (istep, substep, l_doReconfig);
    }
    else
    {
        /*@
         * @errortype
         * @reasoncode  ISTEP_NON_MASTER_NODE_MSG
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_INITSVC_MOD_ID
         * @userdata1   Istep Requested
         * @userdata2   Substep Requested
         * @devdesc     Istep messaged received by non-master node.
         */
        err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP_INITSVC_MOD_ID,
                                      ISTEP_NON_MASTER_NODE_MSG,
                                      istep,
                                      substep);
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
        TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIStepRequestMsg: IStep success and deconfigs, creating error");
        err = failedDueToDeconfig(istep, substep, newIstep, newSubstep, true);

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
    errlHndl_t l_errl = TARGETING::AttrRP::sendAttrOverridesAndSyncs();

    if (l_errl)
    {
        TRACFCOMP(g_trac_initsvc, ERR_MRK
                  "doIstep: send attr overrides and syncs to FSP"
                  " failed, see 0x%08X for details", l_errl->eid());
        errlCommit(l_errl, INITSVC_COMP_ID);
    }

    // Transfer ownership of the message pointer back from iv_pIstepMsg
    mutex_lock(&iv_mutex);
    io_pMsg = iv_pIstepMsg;
    iv_pIstepMsg = NULL;
    mutex_unlock(&iv_mutex);

    if (io_pMsg == NULL)
    {
        // An IStep already responded to the message!!
        TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIStepRequestMsg: message response already sent!");
    }
    else
    {
        if (msg_is_async(io_pMsg))
        {
            // Unexpected
            TRACFCOMP(g_trac_initsvc, ERR_MRK"handleIStepRequestMsg: async istep message!");
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
#ifndef CONFIG_VPO_COMPILE
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
        err = VFS::module_load("libistep18.so");
        if (err)
        {
            TRACFCOMP(g_trac_initsvc, "handleProcFabIovalidMsg: Error loading libistep18,"
                    " PLID = 0x%x",
                      err->plid());

            io_pMsg->data[0] = err->plid();
            errlCommit(err, INITSVC_COMP_ID);
            break;
        }

        err = VFS::module_load("libfab_iovalid.so");
        if (err)
        {
            TRACFCOMP(g_trac_initsvc, "handleProcFabIovalidMsg: Error loading libfab_iovalid.so,"
                    " PLID = 0x%x",
                      err->plid());

            io_pMsg->data[0] = err->plid();
            errlCommit(err, INITSVC_COMP_ID);
            break;
        }

        // Create child thread so that if there are problems, the istep
        //  dispatcher code continues
        tid_t l_progTid = task_create(ESTABLISH_SYSTEM_SMP::host_sys_fab_iovalid_processing,io_pMsg);

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

            //Setup for IPC messages to continue after we come out of winkle
            //This stores the location of IPC messages of current drawer in the mbox scratch
            //register.
            IPC::IpcSp::distributeLocalNodeAddr();

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

            //Before stopping all the cores, we need to disable interrupts
            err = ESTABLISH_SYSTEM_SMP::blockInterrupts();
            if (err)
            {
                TRACFCOMP( g_trac_initsvc,
                           "ERROR: ESTABLISH_SYSTEM_SMP::blockInterrupts");
                errlCommit(err, INITSVC_COMP_ID);
            }

            err = TRUSTEDBOOT::flushTpmQueue();
            if(err)
            {
                TRACFCOMP(g_trac_initsvc,
                          "ERROR: TPM message queue flushing failed. The system"
                          " may experience a hang condition.");
                errlCommit(err, INITSVC_COMP_ID);
            }

            //cpu_all_winkle is a system call.. After the system call,
            //the cpu are all hung at that instruction. After the fsp
            //wake us up, we will resume execution from the next instruction
            //in this function as the PC will be pointing to the next
            //instruction after the cpu_all_winkle function.
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
#endif
}


// ----------------------------------------------------------------------------
// IStepDispatcher::handlePerstMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handlePerstMsg(msg_t * & io_pMsg)
{
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::handlePerstMsg");

    // assume the HWP will succeed (0=success)
    io_pMsg->data[1] = 0;

    errlHndl_t l_errl = NULL;

    do
    {
        if // HWP Perst Libraries have not yet been loaded
          ( iv_p9_phbPerstLibLoaded == false )
        {
            // load the libraries
            l_errl = VFS::module_load( "libp9_phbPerst.so" );

            if (l_errl)
            {
                TRACFCOMP( g_trac_initsvc,
                           "handlePerstMsg: Error loading libp9_phbPerst, "
                           "PLID = 0x%x",
                           l_errl->plid() );

                io_pMsg->data[1] = ERRL_GETRC_SAFE(l_errl);
                errlCommit( l_errl, INITSVC_COMP_ID );
                break;
            }
            else
            {
                iv_p9_phbPerstLibLoaded = true;
            }
        } // end load libraries

/* FIXME RTC: 210975
        // translate message inputs to fapi target and HWP Perst action
        const TARGETING::ATTR_HUID_type huid =
                static_cast <const TARGETING::ATTR_HUID_type>(io_pMsg->data[0]);
        TARGETING::Target * pInputTarget =
                TARGETING::Target::getTargetFromHuid( huid );
*/

/* FIXME RTC: 210975
        const fapi2::Target<fapi2::TARGET_TYPE_PHB> fapi2_target(pInputTarget);

        uint32_t msgPerstAction = io_pMsg->type;

        PERST_ACTION hwpPerstAction = (msgPerstAction == PERST_ASSERT) ?
                ACTIVATE_PERST : DEACTIVATE_PERST;

        // Execute the PERST directive
        FAPI_INVOKE_HWP( l_errl,
                         p9_perst_phb,
                         fapi2_target,
                         hwpPerstAction );

        if(l_errl)
        {
            TRACFCOMP( g_trac_initsvc,
                       "ERROR : call p9_perst_phb, PLID=0x%x",
                       l_errl->plid()  );
            l_errl->collectTrace("INITSVC",256);
            l_errl->collectTrace("FAPI",256);
            errlCommit(l_errl, HWPF_COMP_ID);

            io_pMsg->data[1] = ERRL_GETRC_SAFE(l_errl);
        }
*/
    } while(0);

    if (msg_is_async(io_pMsg))
    {
        // It is expected that handle Perst messages are sync.
        //  otherwise we don't have a way to send the results
        //  back to the FSP.
        // This leg drops results on the floor
        TRACFBIN( g_trac_initsvc,
                  INFO_MRK
                 "IStepDispatcher::handlePerstMsg :"
                 "Async msg, no Response to FSP, Msg = ",
                 io_pMsg,
                 sizeof(*io_pMsg) );

        msg_free(io_pMsg);
        io_pMsg = NULL;
    }
    else
    {
        // Send the message back as a response
        msg_respond(iv_msgQ, io_pMsg);
        io_pMsg = NULL;
    }

    TRACFCOMP(g_trac_initsvc, EXIT_MRK"IStepDispatcher::handlePerstMsg");

    return;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::sendProgressCode()
// This method has a default of true for i_needsLock
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::sendProgressCode(bool i_needsLock)
{
    static uint8_t lastIstep = 0, lastSubstep = 0;
    static uint8_t internalStep = 0;
    errlHndl_t err = NULL;

    if (i_needsLock)
    {
        mutex_lock( &iv_mutex );
    }

    // Reduce output to once per step/substep
    if ((iv_curIStep != lastIstep) || (iv_curSubStep != lastSubstep))
    {
        TRACDCOMP( g_trac_initsvc,
                   ENTER_MRK"IStepDispatcher::sendProgressCode()");

        //--- Display istep in Simics console
        MAGIC_INST_PRINT_ISTEP( iv_curIStep, iv_curSubStep );

        // Reset internalStep counter since we are on a new istep
        internalStep = 0;
    }

    //--- Save step to a scratch reg
    SPLESS::MboxScratch5_t l_scratch5;
    l_scratch5.debug.magic = SPLESS::MboxScratch5_t::ISTEP_PROGRESS_MAGIC;
    l_scratch5.debug.stepStart = 1;
    l_scratch5.debug.internalStep = internalStep++; //increment on each call
    l_scratch5.debug.majorStep = iv_curIStep;
    l_scratch5.debug.minorStep = iv_curSubStep;
    Util::writeScratchReg( SPLESS::MboxScratch5_t::REG_ADDR,
                           l_scratch5.data32 );

    //--- Push the scratch reg into kernel to be added into TI area
    termSetIstep(l_scratch5.data32);

#ifdef CONFIG_ISTEP_LPC_PORT80_DEBUG
    // Starting port 80h value for hostboot isteps.  Each step started will
    // increase the value by one.
    static uint8_t port80_val = 0x30;
    static size_t port80_len = sizeof(port80_val);
    err = deviceWrite(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                      &port80_val, port80_len,
                      DEVICE_LPC_ADDRESS(LPC::TRANS_IO, 0x80));
    delete err; // this is debug only, ignore any errors
    err = NULL;
    port80_val++;
#endif

#ifdef CONFIG_CONSOLE_OUTPUT_PROGRESS
    //--- Display step on serial console
    if ((iv_curIStep != lastIstep) || (iv_curSubStep != lastSubstep))
    {
        const TaskInfo *taskinfo = findTaskInfo(iv_curIStep, iv_curSubStep);
        CONSOLE::displayf(CONSOLE::VUART1, NULL, "ISTEP %2d.%2d - %s",
                     iv_curIStep, iv_curSubStep,
                     taskinfo && taskinfo->taskname ? taskinfo->taskname : "");
        CONSOLE::flush();
    }
#endif


    //--- Reset the watchdog before every istep
#ifdef CONFIG_PLDM
    errlHndl_t err_pldm = PLDM::resetWatchdogTimer();

    if(err_pldm)
    {
       TRACFCOMP(g_trac_initsvc,
                 "init: ERROR: reset PLDM watchdog Failed");
        err_pldm->collectTrace(PLDM_COMP_NAME);
        err_pldm->collectTrace(INITSVC_COMP_NAME);
        errlCommit(err_pldm, INITSVC_COMP_ID );
    }
#endif


    //--- Send the progress code to the FSP
    if( iv_spBaseServicesEnabled )
    {
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
        if ((iv_curIStep != lastIstep) || (iv_curSubStep != lastSubstep))
        {
            TRACFCOMP( g_trac_initsvc,INFO_MRK"Progress Code %d.%d Sent",
                       myMsg->data[0],myMsg->data[1]);
        }
    }

    // -- Send the progress code src to the BMC;
    // do not send the internal step/counter
#ifdef CONFIG_PLDM
    ProgressCodeSrc l_progressSrc(iv_curIStep, iv_curSubStep, 0);
    err_pldm = l_progressSrc.sendProgressCodeToBmc();
    if (err_pldm)
    {
        TRACFCOMP(g_trac_initsvc, ERR_MRK"sendProgressCodeToBmc() failed for istep %d:%d",
            iv_curIStep, iv_curSubStep);
        err_pldm->collectTrace(PLDM_COMP_NAME);
        err_pldm->collectTrace(INITSVC_COMP_NAME);
        // make sure it is just informational, sending progress code shouldn't stop the IPL
        err_pldm->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        errlCommit(err_pldm, INITSVC_COMP_ID);
    }
#endif

    if ((iv_curIStep != lastIstep) || (iv_curSubStep != lastSubstep))
    {
        TRACDCOMP( g_trac_initsvc,
                   EXIT_MRK"IStepDispatcher::sendProgressCode()" );
    }

    lastIstep = iv_curIStep;
    lastSubstep = iv_curSubStep;

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
    TRACDCOMP(g_trac_initsvc,
              ENTER_MRK"IStepDispatcher::checkReconfig(): istep %d.%d",
              i_curIstep, i_curSubstep);

    //@TODO-RTC:158411 for Cumulus support reconfig logic needs to be updated
    // Software reconfig loop happens in istep 7 only.
    // The rest of the isteps should result in TI path for scale-out systems
    if( (i_curIstep == SW_RECONFIG_START_STEP)
            && (i_curSubstep >= SW_RECONFIG_START_SUBSTEP ) )
    {
        TRACDCOMP(g_trac_initsvc, "checkReconfig(): SW RECONFIGURE is ON at istep %d.%d",
           i_curIstep, i_curSubstep);
        doReconfigure = true;
        o_newIstep = SW_RECONFIG_START_STEP;
        o_newSubstep = SW_RECONFIG_START_SUBSTEP;
    }else
     {
        //remember that TI will be requested for all other steps outside
        //software reconfig istep 7 in NIMBUS for scale-out systems
     }

     TRACDCOMP(g_trac_initsvc,
       EXIT_MRK"IStepDispatcher::checkReconfig: new istep/substep: %d %d.%d",
              doReconfigure, o_newIstep, o_newSubstep);

    return doReconfigure;
}

// ----------------------------------------------------------------------------
// External functions defined that map directly to IStepDispatcher public member
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

errlHndl_t sendAttnMonitorChipIdMsg(
                    const std::vector<TARGETING::ATTR_HUID_type> & i_huid_list)
{
    return IStepDispatcher::getTheInstance().
              sendAttnMonitorChipIdMsg(i_huid_list);
}

void sendProgressCode(bool i_needsLock)
{
    errlHndl_t err = NULL;

    err = IStepDispatcher::getTheInstance().sendProgressCode(i_needsLock);

    if (err)
    {
        // Commit the error and continue
        errlCommit(err, INITSVC_COMP_ID);
    }
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
void setNewGardRecord()
{
    return IStepDispatcher::getTheInstance().setNewGardRecord();
}

void requestReboot(const char* i_reason)
{
    IStepDispatcher::getTheInstance().requestReboot(i_reason);
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
    errlHndl_t err(nullptr);

#ifndef CONFIG_VPO_COMPILE
    TRACFCOMP(g_trac_initsvc, ENTER_MRK"IStepDispatcher::handleCoalesceHostMsg");

    // Ensure the library is loaded
    err = VFS::module_load("libistep18.so");

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
#endif

    return err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::failedDueToDeconfig()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::failedDueToDeconfig(
                                          uint8_t i_step, uint8_t i_substep,
                                          uint8_t i_dStep, uint8_t i_dSubstep,
                                          const bool istepMode)
{
    errlHndl_t err = NULL;

    auto l_severity = istepMode? ERRORLOG::ERRL_SEV_UNRECOVERABLE:
                                 ERRORLOG::ERRL_SEV_INFORMATIONAL;

    using namespace TARGETING;
    TARGETING::Target* l_pTopLevel = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
    assert( l_pTopLevel != nullptr );
    auto l_reconfigAttr =
      l_pTopLevel->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
    bool l_mfgMode = TARGETING::areAllSrcsTerminating();

    /*@
     * @errortype
     * @reasoncode       ISTEP_FAILED_DUE_TO_DECONFIG
     * @moduleid         ISTEP_INITSVC_MOD_ID
     * @userdata1[00:15] Istep that failed
     * @userdata1[16:31] SubStep that failed
     * @userdata1[32:47] Desired istep
     * @userdata1[48:63] Desired substep
     * @userdata2[00:07] Value of ATTR_RECONFIGURE_LOOP
     *                   - 0x01 = DECONFIGURE;
     *                   - 0x02 = BAD_DQ_BIT_SET;
     *                   - 0x08 = OCMB_FW_UPDATE;
     *                   - 0x10 = TOPOLOGY_SWAP;
     * @userdata2[08:15] Manufacturing Mode (MNFG_FLAG_SRC_TERM)
     * @userdata2[16:63] Unused
     * @devdesc          Hostboot has requested a reconfig loop due to a
     *                   hardware error. Causes could be:
     *                   - deconfiguration during an istep outside of the
     *                     the reconfig loop
     *                   - deconfiguration while running in istep mode
     *                   - deconfiguration in mfg mode
     *                   - exceeded the number of allowed reconfig attempts
     *                   - recoverable hardware error that requires a
     *                     reboot to clear out
     * @custdesc    A hardware error occurred during the IPL. Check previous logs
     *              for details.
     */
    err = new ERRORLOG::ErrlEntry(
            l_severity,
            ISTEP_INITSVC_MOD_ID,
            ISTEP_FAILED_DUE_TO_DECONFIG,
            FOUR_UINT16_TO_UINT64(i_step, i_substep,
                                  i_dStep, i_dSubstep),
            FOUR_UINT16_TO_UINT64(
                TWO_UINT8_TO_UINT16(l_reconfigAttr,
                                    l_mfgMode),
                                  0,
                                  0,
                                  0
                                  ) );
    err->collectTrace("HWAS_I", 1024);
    err->collectTrace("INITSVC", 1024);
    err->addProcedureCallout(HWAS::EPUB_PRC_FIND_DECONFIGURED_PART,
                             HWAS::SRCI_PRIORITY_HIGH);


    INITSERVICE::doShutdown(SHUTDOWN_DO_RECONFIG_LOOP, true);

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
// IStepDispatcher::doWait
// ----------------------------------------------------------------------------
void IStepDispatcher::doWait(uint16_t i_waitSec)
{
    // If infinite pause is set then hang in a tight loop indefinitely.
    // This is a permanent stop that cannot be resumed via any command.
    if(i_waitSec == ISTEP_PAUSE_SET_INFINITE)
    {
        TRACFCOMP(g_trac_initsvc, INFO_MRK"doWait: pauseLen=0x%02X, Permanent pause enabled.",
                  i_waitSec);
#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::VUART1, NULL, "doWait: pauseLen=0x%02X, Permanent pause enabled.",
                          i_waitSec);
        CONSOLE::flush();
#endif
        while(1)
        {
#ifdef CONFIG_PLDM
            // Continuously send out heartbeats while we're waiting.
            // Send heartbeats in intervals of min watchdog timeout / 2 so that
            // there is enough time for processing and propagation of the message
            // to BMC.
            sendProgressCode();
            nanosleep(PLDM::HB_MIN_WATCHDOG_TIMEOUT_SEC / 2,0);
#else
            nanosleep(1,0);
#endif
        }
    }
    // Otherwise sleep for the requested number of seconds
    else
    {
#ifdef CONFIG_PLDM
        // Send heartbeats in intervals of min watchdog timeout / 2 so that
        // there is enough time for processing and propagation of the message
        // to BMC.
        if(i_waitSec > (PLDM::HB_MIN_WATCHDOG_TIMEOUT_SEC / 2))
        {
            uint16_t l_totalElapsed = 0;
            // Send heartbeats at regular intervals while we wait
            while(l_totalElapsed < i_waitSec)
            {
                sendProgressCode();
                auto l_sleepAmtSec = (i_waitSec - l_totalElapsed) > (PLDM::HB_MIN_WATCHDOG_TIMEOUT_SEC / 2) ?
                                     (PLDM::HB_MIN_WATCHDOG_TIMEOUT_SEC / 2) :
                                     (i_waitSec - l_totalElapsed);
                nanosleep(l_sleepAmtSec, 0);
                l_totalElapsed += l_sleepAmtSec;
            }
        }
        else
#endif
        {
            nanosleep(i_waitSec, 0);
        }
    }
}

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

            // If full stop is requested then send breakpoint message to FSP.
            // This stop can be resumed via external command from FSP.
            if(l_p_pauseCfg->fullStopEn)
            {
                iStepBreakPoint(l_p_pauseCfg->bpTagInfo);
            }
            else
            {
                doWait(l_p_pauseCfg->pauseLen);
            }
            // Send one last hearbeat before returning
            sendProgressCode();
        }
    }
}

int IStepDispatcher::getNextIStep(uint8_t& io_istep, uint8_t& io_substep)
{
    int rc = 0; // defaults to failure

    do
    {
        rc = 0; // defaults to failure again unless a valid istep/substep
                // is found
        uint8_t l_numSubsteps = g_isteps[io_istep].numitems;

        if (l_numSubsteps != 0 &&
            (io_substep + 1u) < l_numSubsteps)
        {
            io_substep++;
            rc = 1;
        }
        else if ((io_istep + 1u) < MaxISteps)
        {
            io_substep = 0;
            io_istep++;
            rc = 1;
        }
        else
        {
            // avoid infinite loop scenario
            break;
        }
    } while (nullptr == findTaskInfo(io_istep, io_substep));

    return rc;
}

}; // namespace
