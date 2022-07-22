/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_activate_boot_core.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
// Error Handling
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>
#include <intr/interrupt.H>
#include <console/consoleif.H>
#include <arch/pirformat.H>
#include <arch/pvrformat.H>
#include <sys/task.h>
#include <sys/mmio.h>
#include <arch/ppc.H>
#include <pldm/requests/pldm_datetime_requests.H>
#include <util/utiltime.H>

//targeting support
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>
#include <fapi2/target.H>

// SBE interfacing
#include <sbeio/sbeioif.H>
#include <sys/misc.h>
#include <pm/pm_common.H>

#include <p10_block_wakeup_intr.H>
#include <p10_gen_fbc_rt_settings.H>

#include <scom/scomif.H>

// HWP invoker
#include <fapi2/plat_hwp_invoker.H>

#include <iterator>

using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEP;
using namespace ISTEP_ERROR;

namespace ISTEP_16
{

/**
 * @brief Reestablish the base timestamp value
 */
void resetBaseTime( void )
{
#ifdef CONFIG_PLDM
    // Fetch the current date/time from the BMC
    date_time_t l_currentTime{};
    errlHndl_t l_errl = PLDM::getDateTime(l_currentTime);
    if(l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_activate_boot_core saw PLDM::getDateTime() error");
        errlCommit( l_errl, ISTEP_COMP_ID );
    }
    else
    {
        // Save the value to be used later
        Util::setBaseDateTime(l_currentTime);
    }
#endif
}

void* call_host_activate_boot_core(void* const io_pArgs)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_activate_boot_core entry");

    errlHndl_t l_errl = nullptr;
    bool l_attempt_mbox_resume = false; // do a resume outside the loop

    do
    {
        const bool l_isFusedMode = is_fused_mode();

        // find the boot core, i.e. the one we are running on
        TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_activate_boot_core: Find boot core:");

        // Determine top-level system target
        Target* l_sys = nullptr;
        targetService().getTopLevelTarget(l_sys);
        assert(l_sys != nullptr, "Toplevel target must not be null");

        const Target* const l_bootCore = getBootCore();
        assert(l_bootCore != nullptr, "Boot core must not be null");

        const Target* const l_proc_target = getParentChip(l_bootCore);
        assert(l_proc_target, "Parent chip of boot core must not be null");

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_chip(l_proc_target);

        // Cast OUR type of target to a FAPI2 type of target.
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>
            l_fapi2_coreTarget(l_bootCore);

        fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapi2_fusedTarget(nullptr);
        const Target* l_fusedCore = nullptr;

        if (l_isFusedMode)
        {
            const uint64_t cpuid = task_getcpuid();
            const uint64_t l_bootCoreID = PIR_t::coreFromPir(cpuid);
            const uint64_t l_fusedCoreID = l_bootCoreID + 1;

            // get the list of core targets for this proc chip
            TargetHandleList l_coreTargetList;
            getChildChiplets(l_coreTargetList,
                             l_proc_target,
                             TYPE_CORE,
                             false);

            // Find the core that matched with the fusedCoreID we
            // calculated above. This core is the core that will
            // be fused with the bootcore.
            for (const auto& l_core : l_coreTargetList)
            {
                const ATTR_CHIP_UNIT_type l_coreId =
                    l_core->getAttr<ATTR_CHIP_UNIT>();

                if (l_coreId == l_fusedCoreID)
                {
                    l_fusedCore = l_core;
                    break;
                }
            }

            if (l_fusedCore == nullptr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Could not find a target for core %d",
                          l_fusedCoreID);
                /*@
                * @errortype
                * @moduleid     ISTEP::MOD_HOST_ACTIVATE_BOOT_CORE
                * @reasoncode   ISTEP::RC_NO_FUSED_CORE_TARGET
                * @userdata1    Boot-fused core id
                * @userdata2    Boot-fused processor chip huid
                * @devdesc      activate_boot_core> Could not find a target
                *               for the boot-fused core
                * @custdesc     A problem occurred during the IPL
                *               of the system.
                */
                l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                 ISTEP::MOD_HOST_ACTIVATE_BOOT_CORE,
                                                 ISTEP::RC_NO_FUSED_CORE_TARGET,
                                                 l_fusedCoreID,
                                                 get_huid(l_proc_target));

                l_errl->collectTrace("TARG");
                l_errl->collectTrace(FAPI_TRACE_NAME);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME);

                break;
            }

            // Cast OUR type of target to a FAPI2 type of target.
            l_fapi2_fusedTarget = { l_fusedCore };
        }

        // @TODO RTC 245393: Still necessary?
        // Because of a bug in how the SBE injects the IPI used to wake
        // up the boot core, need to ensure no mailbox traffic
        // or even an interrupt in the interrupt presenter
        // 1) Reclaim all DMA bfrs from the FSP
        // 2) suspend the mailbox with interrupt disable
        // 3) tell the SBE to start the deadman timer
        // 4) ensure that interrupt presenter is drained
        l_errl = MBOX::reclaimDmaBfrsFromFsp();
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_activate_boot_core ERROR : "
                      "MBOX::reclaimDmaBfrsFromFsp");

            // If it not complete then thats okay, but we want to store the
            // log away somewhere. Since we didn't get all the DMA buffers
            // back its not a big deal to commit a log, even if we lose a
            // DMA buffer because of it it doesn't matter that much.
            // this will generate more traffic to the FSP
            l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            errlCommit( l_errl, HWPF_COMP_ID );

            // (Do not break. Keep going to suspend)
        }

        l_errl = MBOX::suspend(true, true);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_activate_boot_core ERROR : MBOX::suspend");
            break;
        }
        l_attempt_mbox_resume = true; //attempt to resume if we fail out

        std::vector<std::pair<uint64_t, uint64_t>> l_regInits;

        // Send a list of pairs of fully formed XSCOM register addresses and
        // data to write to those registers when the core enters sleep 15.
        {
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_fapiProcs;

            TARGETING::TargetHandleList l_procsList;
            TARGETING::getAllChips(l_procsList, TARGETING::TYPE_PROC);

            assert(l_procsList.size() > 0, "Must have at least one proc");

            std::transform(l_procsList.cbegin(), l_procsList.cend(),
                           std::back_inserter(l_fapiProcs),
                           [](const auto target) {
                               return fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>(target);
                           });

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_activate_boot_core: calling p10_gen_fbc_rt_settings "
                      "for %d procs",
                      std::size(l_fapiProcs));

            FAPI_INVOKE_HWP(l_errl,
                            p10_gen_fbc_rt_settings,
                            l_fapiProcs,
                            l_regInits);

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"call_host_activate_boot_core: Error in "
                          "p10_gen_fbc_rt_settings: "
                          TRACE_ERR_FMT,
                          TRACE_ERR_ARGS(l_errl));

                break;
            }
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_activate_boot_core: About to start deadman loop... "
                  "Target HUID %.8X",
                  get_huid(l_proc_target));

        //In the future possibly move default "waitTime" value to SBEIO code
        uint64_t waitTimeMs = 10500; // wait time 10.5 sec, anything larger than 10737 ms can cause
                                     // overflow on SBE side of the timeout calculations
        l_errl = SBEIO::startDeadmanLoop(waitTimeMs,l_regInits.data(),l_regInits.size());

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "startDeadmanLoop ERROR : Returning errorlog, reason=0x%x",
                      l_errl->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog(l_errl);

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "startDeadManLoop SUCCESS");
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Draining interrupt queue");
        INTR::drainQueue();

        // Call p10_block_wakeup_intr to prevent stray interrupts from
        // popping core out of winkle before SBE sees it.

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_activate_boot_core: call p10_block_wakeup_intr(SET) "
                  "Target HUID %.8x",
                  get_huid(l_fapi2_coreTarget.get()));

        FAPI_INVOKE_HWP(l_errl,
                        p10_block_wakeup_intr,
                        l_fapi2_coreTarget,
                        p10pmblockwkup::ENABLE_BLOCK_EXIT);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "p10_block_wakeup_intr ERROR : Returning errorlog, "
                      "reason=0x%x: "
                      TRACE_ERR_FMT,
                      l_errl->reasonCode(),
                      TRACE_ERR_ARGS(l_errl));

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_bootCore).addToLog(l_errl);

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "p10_block_wakeup_intr SUCCESS");
        }

        if (l_fusedCore != nullptr)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_activate_boot_core: call p10_block_wakeup_intr(SET) "
                      "Target HUID %.8x",
                      get_huid(l_fapi2_fusedTarget.get()));

            FAPI_INVOKE_HWP(l_errl,
                            p10_block_wakeup_intr,
                            l_fapi2_fusedTarget,
                            p10pmblockwkup::ENABLE_BLOCK_EXIT);

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "p10_block_wakeup_intr ERROR : Returning errorlog, "
                          "reason=0x%x: "
                          TRACE_ERR_FMT,
                          l_errl->reasonCode(),
                          TRACE_ERR_ARGS(l_errl));

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_fusedCore).addToLog(l_errl);

                break;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "p10_block_wakeup_intr SUCCESS");
            }
        }

        //  put the bootcore into winkle.
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_activate_boot_core: put boot core into winkle...");

        // Flush any lingering console traces first
        CONSOLE::flush();

        const int l_rc = cpu_master_winkle(l_isFusedMode);
        if (l_rc)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : failed to winkle boot core, rc=0x%x",
                      l_rc);
            /*@
             * @errortype
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @reasoncode  RC_FAIL_BOOT_CORE_WINKLE
             * @moduleid    MOD_HOST_ACTIVATE_BOOT_CORE
             * @userdata1   return code from cpu_master_winkle
             * @userdata2   Fused core indicator
             * @devdesc     cpu_master_winkle returned an error
             * @custdesc    A problem occurred during the IPL
             *              of the system.
             */
            l_errl =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        MOD_HOST_ACTIVATE_BOOT_CORE,
                                        RC_FAIL_BOOT_CORE_WINKLE,
                                        l_rc, l_isFusedMode);
            break;
        }


        //  --------------------------------------------------------
        //  should return from Winkle at this point
        //  --------------------------------------------------------
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Returned from Winkle.");

        l_errl = SBEIO::stopDeadmanLoop();
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "stopDeadmanLoop ERROR : "
                      "Returning errorlog, reason=0x%x",
                      l_errl->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog(l_errl);

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "stopDeadmanLoop SUCCESS");
        }

        // While the bootcore is stopped we don't have any elapsed timebase
        // so we will get a little out of sync with the real time that we
        // cached earlier.  We will reset the base time to start over fresh.
        resetBaseTime();

        //Re-enable the mailbox
        l_attempt_mbox_resume = false; // no need to attempt this again below
        l_errl = MBOX::resume();
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call_host_activate_boot_core ERROR : MBOX::resume");
            break;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Call proc_stop_deadman_timer. Target %.8X",
                  get_huid(l_proc_target));

        // Save off original checkstop values and override them
        // to disable core xstops and enable sys xstops.
        l_errl = HBPM::core_checkstop_helper_hwp(l_bootCore, true);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "core_checkstop_helper_hwp on bootcore ERROR: returning.");
            break;
        }

        // We want to make sure the fused pair is also setting the
        // core firs to handle checkstops at system level and not
        // at the local level
        if (l_fusedCore != nullptr)
        {
            l_errl = HBPM::core_checkstop_helper_hwp(l_fusedCore, true);

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "core_checkstop_helper_hwp on fused pair ERROR: returning.");
                break;
            }
        }

    } while (0);

    //In case we take an error prior to resuming the MBOX in the normal flow
    //  we should resume it here to flow messsages to the service processor
    if( l_attempt_mbox_resume )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_activate_boot_core: attempting to resume mbox after error occurred");
        errlHndl_t l_errl_mbox = MBOX::resume();
        if (l_errl_mbox)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call_host_activate_boot_core ERROR : MBOX::resume");
            errlCommit(l_errl_mbox,  HWPF_COMP_ID);
        }
    }

    IStepError l_stepError;

    if (l_errl)
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails(l_errl);

        // Commit Error
        errlCommit(l_errl, HWPF_COMP_ID);
    }

    // Flush the console to correct the timestamp on istep 16.2
    CONSOLE::flush();

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_activate_boot_core exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
} // end call_host_activate_boot_core

} // end namespace ISTEP_16
