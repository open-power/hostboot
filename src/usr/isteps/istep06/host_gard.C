/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_gard.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

// Hwas
#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlat.H>
#include <hwas/common/deconfigGard.H>

// Initservice
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>

// Targeting
#include <targeting/attrsync.H>
#include <targeting/namedtarget.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/entitypath.H>
#include <targeting/targplatutil.H>

// SBE
#include <sbe/sbeif.H>
#include <sbe/sbe_update.H>
#include <sbeio/sbe_psudd.H>

// Security
#include <trustedbootif.H>
#include <secureboot/phys_presence_if.H>

// Misc
#include <config.h>
#include <errl/errludtarget.H>
#include <console/consoleif.H>
#include <isteps/hwpisteperror.H>
#include <errl/errlmanager.H>
#include <arch/pirformat.H>
#include <algorithm>

#ifdef CONFIG_PLDM
#include <pldm/extended/pdr_manager.H>
#include <isteps/bios_attr_accessors/bios_attr_setters.H>
#endif

namespace ISTEP_06
{

/**
 * @brief Determine if there is a valid boot core and take appropriate
 *        actions if there isn't.  Also will send a message to FSP if
 *        we find one.
 */
errlHndl_t establish_boot_core( void )
{
    errlHndl_t l_err;
    using namespace TARGETING;

    do {
        Target* l_pTopLevel = UTIL::assertGetToplevelTarget();
        const Target* l_bootCore = getBootCore( );

        if (l_bootCore == nullptr)
        {
            Target* l_bootproc = nullptr;
            TARGETING::targetService().masterProcChipTargetHandle( l_bootproc );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"host_gard: "
                       "No functional bootCore Found on %.8X.",
                       TARGETING::get_huid(l_bootproc) );

            // gather some data for FFDC
            TargetHandleList l_coresFunc;
            TargetHandleList l_coresPresent;
            if( l_bootproc )
            {
                getNonEcoCores( l_coresFunc,
                                l_bootproc,
                                true );

                getNonEcoCores( l_coresPresent,
                                l_bootproc,
                                false );
            }

            PIR_t l_pir = PIR_t(task_getcpuid());

            // Check if we have a target but it just isn't functional
            l_bootCore = getBootCore( false );
            if( l_bootCore == nullptr )
            {
                // This indicates that we are running on a physical thread that
                //  we don't think exists.  The most likely scenario is a
                //  mismatch between our interpretation of the PG data in the
                //  module and what the SBE has programmed into it.  We can
                //  try to fix the problem by forcing a SBE update.

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"host_gard: Calling updateProcessorSbeSeeproms to reconcile core list..." );
                l_err = SBE::updateProcessorSbeSeeproms();
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "host_gard: Error calling updateProcessorSbeSeeproms"
                              TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(l_err));
                    break;
                }
                else
                {
                    // This implies that there is not a mismatch but we are still wrong
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              ERR_MRK"host_gard: updateProcessorSbeSeeproms returned "
                              "without an error on processor 0x%08X",
                              TARGETING::get_huid(l_bootproc));

                    /*@
                     * @errortype
                     * @moduleid     ISTEP::MOD_HOST_GARD
                     * @reasoncode   ISTEP::RC_SBE_UPDATE_UNEXPECTEDLY_FAILED
                     * @devdesc      Failed to update the SBE after missing bootcore
                     * @custdesc     Firmware error is preventing IPL.
                     * @userdata1[00:31]  Boot processor HUID
                     * @userdata1[32:63]  Current PIR
                     * @userdata2[00:15]  Number of present cores
                     * @userdata2[16:31]  Number of functional cores
                     * @userdata2[32:63]  HUID of present boot core (if found)
                     */
                    l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  ISTEP::MOD_HOST_GARD,
                                  ISTEP::RC_SBE_UPDATE_UNEXPECTEDLY_FAILED,
                                  TWO_UINT32_TO_UINT64(
                                      TARGETING::get_huid(l_bootproc),
                                      l_pir.word),
                                  TWO_UINT32_TO_UINT64(
                                      TWO_UINT16_TO_UINT32(
                                          l_coresPresent.size(),
                                          l_coresFunc.size()),
                                  TARGETING::get_huid(l_bootCore)));
                    // seems like a bug somewhere
                    l_err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                                HWAS::SRCI_PRIORITY_HIGH );
                    // knock out the failing proc in case it is the cause
                    if( l_bootproc )
                    {
                        l_err->addHwCallout(l_bootproc,
                                            HWAS::SRCI_PRIORITY_LOW,
                                            HWAS::DELAYED_DECONFIG,
                                            HWAS::GARD_NULL);
                    }

                    l_err->collectTrace(TARG_COMP_NAME);
                    l_err->collectTrace(ISTEP_COMP_NAME);
                    break;
                }
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Found a present bootcore at %.8X",
                           TARGETING::get_huid(l_bootCore) );

                // Look for any other core that we could use instead
                uint32_t l_replacementHuid = 0;
                for( auto l_core : l_coresPresent )
                {
                    auto l_hwas = l_core->getAttr<ATTR_HWAS_STATE>();
                    // We can use any functional core
                    if( l_hwas.functional )
                    {
                        l_replacementHuid = TARGETING::get_huid(l_core);
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                   "Found a viable bootcore at %.8X (functional)",
                                   l_replacementHuid );
                        break;
                    }
                    else if( l_hwas.deconfiguredByEid ==
                             HWAS::DeconfigGard::DECONFIGURED_BY_FIELD_CORE_OVERRIDE )
                    {
                        l_replacementHuid = TARGETING::get_huid(l_core);
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                   "Found a viable bootcore at %.8X (FCO)",
                                   l_replacementHuid );
                        break;
                    }
                }

                if( l_replacementHuid )
                {
                    /*@
                     * @errortype
                     * @severity          ERRL_SEV_INFORMATIONAL
                     * @moduleid          ISTEP::MOD_HOST_GARD
                     * @reasoncode        ISTEP::RC_BOOT_CORE_REPLACEMENT
                     * @devdesc           Original bootcore is not functional
                     *                    but we found a viable replacement.
                     *                    Forcing a reconfig loop to boot from
                     *                    the new core.
                     * @custdesc          Informational firmware IPL message.
                     * @userdata1[00:31]  Original boot core HUID
                     * @userdata1[32:63]  Current PIR
                     * @userdata2[00:15]  Number of present cores
                     * @userdata2[16:31]  Number of functional cores
                     * @userdata2[32:63]  HUID of replacement boot core
                     */
                    l_err = new ERRORLOG::ErrlEntry
                      (ERRORLOG::ERRL_SEV_INFORMATIONAL,
                       ISTEP::MOD_HOST_GARD,
                       ISTEP::RC_BOOT_CORE_REPLACEMENT,
                       TWO_UINT32_TO_UINT64(
                           TARGETING::get_huid(l_bootCore),
                           l_pir.word),
                       TWO_UINT32_TO_UINT64(
                           TWO_UINT16_TO_UINT32(
                               l_coresPresent.size(),
                               l_coresFunc.size()),
                           l_replacementHuid));

                    // Force a reconfig loop so the SP picks up our current
                    //  HWAS_STATE and chooses a better boot core.
                    HWAS::setOrClearReconfigLoopReason(HWAS::ReconfigSetOrClear::RECONFIG_SET,
                                                       RECONFIGURE_LOOP_DECONFIGURE);

                    l_err->collectTrace(TARG_COMP_NAME);
                    l_err->collectTrace(ISTEP_COMP_NAME);

                    // Commit this info log for debug
                    errlCommit(l_err, ISTEP_COMP_ID);
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "Could not find a valid bootcore replacement" );
                }
            }

            // If there isn't a reconfig loop triggered, we need to just fail
            if( !(l_pTopLevel->getAttr<ATTR_RECONFIGURE_LOOP>() & RECONFIGURE_LOOP_DECONFIGURE) )
            {
                /*@
                 * @errortype
                 * @severity          ERRL_SEV_CRITICAL_SYS_TERM
                 * @moduleid          ISTEP::MOD_HOST_GARD
                 * @reasoncode        ISTEP::RC_BOOT_CORE_NULL
                 * @devdesc           Could not find a functional boot core.
                 * @custdesc          Firmware error is preventing IPL.
                 * @userdata1[00:31]  Boot processor HUID
                 * @userdata1[32:63]  Current PIR
                 * @userdata2[00:15]  Number of present cores
                 * @userdata2[16:31]  Number of functional cores
                 * @userdata2[32:63]  HUID of present boot core (if found)
                 */
                l_err = new ERRORLOG::ErrlEntry
                  (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                   ISTEP::MOD_HOST_GARD,
                   ISTEP::RC_BOOT_CORE_NULL,
                   TWO_UINT32_TO_UINT64(
                       TARGETING::get_huid(l_bootproc),
                       l_pir.word),
                   TWO_UINT32_TO_UINT64(
                       TWO_UINT16_TO_UINT32(l_coresPresent.size(),
                           l_coresFunc.size()),
                       TARGETING::get_huid(l_bootCore)));

                // seems like a bug somewhere
                l_err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                            HWAS::SRCI_PRIORITY_HIGH );
                // knock out the failing proc in case it is the cause
                if( l_bootproc )
                {
                    l_err->addHwCallout(l_bootproc,
                                        HWAS::SRCI_PRIORITY_LOW,
                                        HWAS::DELAYED_DECONFIG,
                                        HWAS::GARD_NULL);
                }

                l_err->collectTrace(TARG_COMP_NAME);
                l_err->collectTrace(ISTEP_COMP_NAME);
                break;
            }
        }

        // Send message to FSP with HUID of boot core if we found one
        msg_t * core_msg = msg_allocate();
        core_msg->type = SBE::MSG_IPL_MASTER_CORE;
        core_msg->data[0] = get_huid(l_bootCore);
        core_msg->extra_data = NULL;

        //data[1] is unused
        core_msg->data[1] = 0;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"host_gard: "
                  "Sending MSG_MASTER_CORE message with HUID %08x",
                  core_msg->data[0]);
        l_err = MBOX::send(MBOX::IPL_SERVICE_QUEUE,core_msg);
        if (l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"host_gard: "
                       "MBOX::send failed sending Master Core message");
            msg_free(core_msg);
            break;
        }
    } while(0);

    return l_err;
}

/**
 * @brief If there are no guards present in the system, this function will clear ATTR_BLOCK_SPEC_DECONFIG.
 * @note  This was added to address the behavior seen in defects where ATTR_BLOCK_SPEC_DECONFIG was not being cleared
 *        despite no guards present in the system. As a result, on a subsequent IPLs manual guards were being resource
 *        recovered when it wasn't necessary.
 */
errlHndl_t forceClearBlockSpecDeconfig()
{
    errlHndl_t l_err = nullptr;
    do {
        // Get all GARD Records
        HWAS::DeconfigGard::GardRecords_t l_gardRecords;
        l_err = HWAS::theDeconfigGard().platGetGardRecords(nullptr, l_gardRecords);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Error from platGetGardRecords");
            break;
        }
        if (l_gardRecords.size() == 0)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Found no guard records, clearing ATTR_BLOCK_SPEC_DECONFIG system wide.");
            TargetHandleList l_nodelist;
            getEncResources(l_nodelist, TARGETING::TYPE_NODE, TARGETING::UTIL_FILTER_FUNCTIONAL);
            for( auto l_node : l_nodelist )
            {
                l_node->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(0);
            }
        }
    } while(0);

    return l_err;
}

void* host_gard( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard entry" );
    errlHndl_t l_err;
    ISTEP_ERROR::IStepError l_stepError;
    using namespace TARGETING;
    Target* l_pTopLevel = UTIL::assertGetToplevelTarget();

    do {
        // Check whether we're in MPIPL mode
        if (l_pTopLevel->getAttr<ATTR_IS_MPIPL_HB>())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_gard: MPIPL mode");

            PredicateCTM l_coreFilter(CLASS_UNIT, TYPE_CORE);
            PredicateCTM l_fcFilter(CLASS_UNIT, TYPE_FC);
            PredicateCTM l_eqFilter(CLASS_UNIT, TYPE_EQ);

            PredicatePostfixExpr l_coreFcEq;
            l_coreFcEq.push(&l_coreFilter)
                      .push(&l_fcFilter)
                      .push(&l_eqFilter).Or().Or();

            l_err = HWAS::collectGard(&l_coreFcEq);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"host_gard: "
                          "collectGard for core, FC, or EQ targets returned "
                          "error; breaking out");
                break;
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_gard: Normal IPL mode");

            l_err = HWAS::collectGard();
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"host_gard: "
                   "collectGard returned error; breaking out");
                break;
            }
        }

        TargetHandleList l_cores;
        TargetHandleList l_procsFunc;
        getAllChips(l_procsFunc,
                    TYPE_PROC,
                    true);

        for (const auto l_proc : l_procsFunc)
        {
            ATTR_HB_FALLBACK_CORES_type l_funcCoreMask = 0x00000000;
            // for each proc, get the list of its functional non-ECO cores
            l_cores.clear();
            getNonEcoCores( l_cores,
                            l_proc,
                            true);

            // for each functional, non-ECO, ungarded core
            for (const auto l_core : l_cores)
            {
                // set up the valid core mask for the proc
                l_funcCoreMask |= (0x80000000 >> (l_core->getAttr<ATTR_CHIP_UNIT>()));
            }

            l_proc->setAttr<ATTR_HB_FALLBACK_CORES>(l_funcCoreMask);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "host_gard: proc HUID 0x%X has functional core mask: 0x%8X",
                      get_huid(l_proc), l_funcCoreMask);
        }

#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "---------------------------------");
        CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "FUNCTIONAL>");
#endif
        // display func targ bit mask to console and trace
        TARGETING::PredicateIsFunctional l_isFunctional;
        TARGETING::UTIL::displayProcChildrenBitmasks(&l_isFunctional);

#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "---------------------------------");
#endif

        // Hostboot must ensure it does not trigger a reconfig loop at the end
        // of this istep for applying gard records for error logs that came from
        // prior IPLs.  It must therefore flush out all the pending error logs
        // so that the reconfig loop activation gets skipped, then enable
        // reconfiguration loops due to deconfiguration going forward.
        // Non-intervention here could lead to infinite reconfig loops if the
        // checkMinimumHardware check fails below.
        ERRORLOG::ErrlManager::callFlushErrorLogs();
        l_pTopLevel->setAttr<TARGETING::ATTR_ENABLE_RECONFIG_DUE_TO_DECONFIG>(true);

        // If there are no guards present in the system then clear ATTR_BLOCK_SPEC_DECONFIG.
        l_err = forceClearBlockSpecDeconfig();
        if (l_err)
        {
            break;
        }

        // check and see if we still have enough hardware to continue
        // if this checkMinimumHardware() fails then we fail the ipl.
        // This is because collectGard() should have already attempted
        // to Resource Recover targets so that we could still try to boot
        l_err = HWAS::checkMinimumHardware();
        if(l_err)
        {
            // collectGard() was unable to Resource Recover enough HW for HB to boot
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"host_gard: check minimum hardware returned error; breaking out");
            break;
        }

        // Determine if there is a valid boot core and take appropriate
        // actions if there isn't.  Also will send a message to FSP if
        // we find one.
        l_err = establish_boot_core();
        if(l_err)
        {
            break;
        }

    } while (0);

    if (l_err)
    {
        // Create IStep error log and cross reference occurred error
        l_stepError.addErrorDetails( l_err );
        // Commit Error
        errlCommit (l_err, ISTEP_COMP_ID);
    }

    // Process SBE PSU errors that might have occurred before FAPI was
    // initialized.  Early PSU errors must be handled after
    // host_discover_targets because SBE dumps are not possible until after the
    // PDR exchange.  Further, in order to actually deconfig a processor
    // correctly, all the initial target state processing needs to be completed,
    // which implies host_gard is also materially complete.
    SBEIO::SbePsu::getTheInstance().processEarlyError();

    (void)SECUREBOOT::logPlatformSecurityConfiguration();

    // Set Minimum Secure Version Attribute
    // -- safe to do here because targeting is definitely up at this point
    // -- NOTE: API asserts if there's any issues returning the node target
    Target* node_tgt = UTIL::getCurrentNodeTarget();
    node_tgt->setAttr<ATTR_SECURE_VERSION_SEEPROM>(SECUREBOOT::getMinimumSecureVersion());
    // Set the same BMC-related attribute if it's present
    l_pTopLevel->trySetAttr<ATTR_SECURE_VERSION_NUM>(SECUREBOOT::getMinimumSecureVersion());

#ifdef CONFIG_PLDM
    // Notify the BMC via PLDM BIOS attribute hb_effective_secure_version.
    std::vector<uint8_t> string_table, attr_table;
    ISTEP::set_hb_effective_secure_version(string_table, attr_table, l_stepError);
#endif

#ifdef CONFIG_TPMDD
    // Initialize the master TPM
    l_err = (errlHndl_t)TRUSTEDBOOT::host_update_primary_tpm(io_pArgs);
    if (l_err)
    {
        l_stepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit( l_err, TRBOOT_COMP_ID );
    }
#endif
    l_err = SECUREBOOT::traceSecuritySettings(true);
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_update_primary_tpm: Error back from "
                  "SECUREBOOT::traceSecuritySettings: rc=0x%X, plid=0x%X",
                  ERRL_GETRC_SAFE(l_err), ERRL_GETPLID_SAFE(l_err));
        l_stepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit( l_err, SECURE_COMP_ID );
    }
    // Check for Physical Presence
#ifdef CONFIG_PHYS_PRES_PWR_BUTTON
    l_err = SECUREBOOT::detectPhysPresence();
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_update_primary_tpm: Error back from "
                  "SECUREBOOT::detectPhysPresence: "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(l_err));
        l_stepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit( l_err, SECURE_COMP_ID );
    }
#endif


#ifdef CONFIG_PLDM
    PLDM::thePdrManager().sendAllFruFunctionalStates();
#endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_gard exit" );

    return l_stepError.getErrorHandle();
}

};
