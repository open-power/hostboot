/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_activate_secondary_cores.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#include <config.h>
#include <errl/errlentry.H>
#include <errno.h>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>

#include <arch/pirformat.H>
#include <arch/magic.H>
#include <console/consoleif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <fapi2/target.H>
#include <errl/errlmanager.H>
#include <sys/task.h>
#include <sys/misc.h>

#include <fapi2/plat_hwp_invoker.H>
#include <p10_query_core_stop_state.H>
#include <p10_core_special_wakeup.H>

#include <pm/pm_common.H>
#include <scom/scomif.H>
#include <errl/errludprintk.H>
#include <intr/intr_reasoncodes.H>
#include <initservice/istepdispatcherif.H>
#include <secureboot/smf_utils.H>
#include <util/misc.H>
#include <sys/misc.h>
#include <algorithm>
#include <scom/wakeup.H>

#ifdef CONFIG_PLDM
#include <pldm/requests/pldm_pdr_requests.H>
#endif

using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEP;
using namespace ISTEP_ERROR;

// 15 is the deepest sleep state, used because it loses state and forces the
// core to reload all hardware settings.
const int EXPECTED_STOP_STATE = 15;

namespace ISTEP_16
{

void* call_host_activate_secondary_cores(void* const io_pArgs)
{
    IStepError  l_stepError;
    errlHndl_t  l_timeout_errl =   nullptr;
    errlHndl_t  l_errl         =   nullptr;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_activate_secondary_cores entry" );

#ifdef CONFIG_PLDM
    PLDM::sendProgressStateChangeEvent(PLDM_STATE_SET_BOOT_PROG_STATE_SEC_PROC_INITIALIZATION);
#endif

    //track boot group/chip/core (no threads)
    const uint64_t l_bootPIR = PIR_t(task_getcpuid()).word;
    const uint64_t l_bootPIR_wo_thread =
        (l_bootPIR & ~PIR_t::THREAD_MASK);

    TargetHandleList l_cores;
    // Don't want to attempt to wake COREs that have been marked for use as "Extended Cache-Only" cores.
    getNonEcoCores(l_cores);

    TARGETING::Target* sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(sys);
    assert(sys != nullptr, "Toplevel target must not be null");
    uint32_t l_numCores = 0;

    // Force some updates in Simics if the QME model isn't enabled
    if(Util::requiresSecondaryCoreWorkaround())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Triggering Simics QME workaround");
        const auto smfEnabled = SECUREBOOT::SMF::isSmfEnabled();
        MAGIC_INST_SETUP_THREADS(smfEnabled);
    }

    do
    {
        if (sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            // Restore the ability to do special wakeups now that the
            //  PM complex is alive again
            // Note that this doesn't affect the HWP execution, but
            //  it will allow wakeups due to other scoms, and enable
            //  things at runtime later on
            WAKEUP::controlWakeupLogic(WAKEUP::ENABLE_SPECIAL_WAKEUP);

            //In an MPIPL we need to issue a special wakeup to all functional cores
            // prior to sending the doorbell messages
            TargetHandleList l_procTargetList;
            getAllChips(l_procTargetList, TYPE_PROC);

            for (const auto & l_proc: l_procTargetList)
            {
                // Do not call special wakeup for procs with no PG-good cores
                // Find all PRESENT CORE chiplets of the proc
                TargetHandleList l_coreTargetList;
                getCoreChiplets( l_coreTargetList,
                                 UTIL_FILTER_CORE_ALL,
                                 UTIL_FILTER_PRESENT,
                                 l_proc);
                if (l_coreTargetList.empty())
                {
                    // No PRESENT cores, continue
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Proc 0x%x has no PG-good cores, not calling p10_core_special_wakeup (ENABLE)",
                        l_proc->getAttr<ATTR_HUID>());
                    continue;
                }

                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "Calling p10_core_special_wakeup (ENABLE) for all cores on proc: 0x%x",
                             l_proc->getAttr<TARGETING::ATTR_HUID>());

                fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST >  l_core_mc =
                             l_fapiProc.getMulticast< fapi2::MULTICAST_OR >
                                        (fapi2::MCGROUP_GOOD_EQ, fapi2::MCCORE_ALL);

                FAPI_INVOKE_HWP(l_errl,
                                p10_core_special_wakeup,
                                l_core_mc,
                                p10specialWakeup::SPCWKUP_ENABLE,
                                p10specialWakeup::HOST);

                if (l_errl != nullptr)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK "call_host_activate_secondary_cores> Failed in call to "
                               "p10_core_special_wakeup (ENABLE) for all cores on proc: 0x%x",
                               l_proc->getAttr<TARGETING::ATTR_HUID>());
                    //break out of processor loop
                    break;
                }
            }

            //if there was an error enabling special wakeup, do not continue with
            // secondary core wakeup
            if (l_errl != nullptr)
            {
                l_stepError.addErrorDetails(l_errl);
                errlCommit(l_errl, HWPF_COMP_ID);
                break;
            }
        } // if (sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())

        // keep track of which cores started
        TargetHandleList l_startedCores;

        for (const auto& l_core : l_cores)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Iterating all cores in system - This is core: %d",
                      l_numCores);

            l_numCores += 1;

            ConstTargetHandle_t l_processor = getParentChip(l_core);

            const auto coreId = l_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            const auto topologyId =
                l_processor->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();

            const fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapi2_coreTarget(l_core);

            const auto core_dead_state = l_core->getAttr<TARGETING::ATTR_DEAD_CORE_MODE>();

            if ( core_dead_state )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Skipping this DEAD core : 0x%X", l_core->getAttr<TARGETING::ATTR_HUID>());
                continue;
            }

            // Determine PIR and threads to enable for this core
            const uint64_t pir = PIR_t(topologyId, coreId).word;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "pir for this core is: 0x%016llX", pir);

            //Skip the boot core that is already running
            if ((pir & ~PIR_t::THREAD_MASK) == l_bootPIR_wo_thread)
            {
                continue;
            }

            int rc = 0;
            const uint64_t en_threads = sys->getAttr<ATTR_ENABLED_THREADS>();
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_activate_secondary_cores: Waking 0x%016llX.",
                      pir);

            rc = cpu_start_core(pir, en_threads);

            // Handle time out error
            uint32_t l_checkidle_eid = 0;
            if (-ETIME == rc)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_activate_secondary_cores: "
                          "Time out rc from kernel %d on core 0x%016llX",
                          rc,
                          pir);

                // only called if the core doesn't report in
                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                  l_fapi2ProcTarget(l_processor);

                TARGETING::ATTR_FAPI_NAME_type l_targName { };
                fapi2::toString(l_fapi2ProcTarget,
                                l_targName,
                                sizeof(l_targName));

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Call p10_check_idle_stop_done on processor %s",
                          l_targName);

                FAPI_INVOKE_HWP(l_timeout_errl,
                                p10_query_core_stop_state,
                                l_fapi2_coreTarget,
                                EXPECTED_STOP_STATE);

                if (l_timeout_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR : p10_check_idle_stop_done: "
                              TRACE_ERR_FMT,
                              TRACE_ERR_ARGS(l_timeout_errl));

                    // Add chip target info
                    ErrlUserDetailsTarget(l_processor).addToLog(l_timeout_errl);

                    // Create IStep error log
                    l_stepError.addErrorDetails(l_timeout_errl);

                    l_checkidle_eid = l_timeout_errl->eid();

                    // Commit error
                    errlCommit(l_timeout_errl, HWPF_COMP_ID);
                }
            } // End of handle time out error

            // Create unrecoverable error log ourselves to knock out the
            //  core in case the HWP didn't do a HW callout or if there
            //  was no HWP error at all
            if( 0 != rc )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "call_host_activate_secondary_cores: "
                           "Core errors during wakeup on core 0x%016llX",
                           pir);
                /*@
                 * @errortype
                 * @reasoncode  RC_SECONDARY_CORE_WAKEUP_ERROR
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    MOD_HOST_ACTIVATE_SECONDARY_CORES
                 * @userdata1[00:31]   PIR of failing core.
                 * @userdata2[32:63]   HUID of failing core.
                 * @userdata2[00:31]   EID from p10_check_idle_stop_done().
                 * @userdata2[32:63]   rc of cpu_start_core().
                 *
                 * @devdesc Kernel returned error when trying to activate
                 *          core.
                 * @custdesc Unable to activate all hardware during boot.
                 */
                l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                 MOD_HOST_ACTIVATE_SECONDARY_CORES,
                                                 RC_SECONDARY_CORE_WAKEUP_ERROR,
                                                 TWO_UINT32_TO_UINT64(pir,
                                                         TARGETING::get_huid(l_core)),
                                                 TWO_UINT32_TO_UINT64(l_checkidle_eid,
                                                                      rc));

                // Callout and gard core that failed to wake up.
                l_errl->addHwCallout(l_core,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DECONFIG,
                                     HWAS::GARD_Predictive);

                // Could be an interrupt issue
                l_errl->collectTrace(INTR_TRACE_NAME,256);

                // Throw printk in there too in case it is a kernel issue
                ERRORLOG::ErrlUserDetailsPrintk().addToLog(l_errl);

                // Add interesting ISTEP traces
                l_errl->collectTrace(ISTEP_COMP_NAME,256);

                l_stepError.addErrorDetails(l_errl);
                errlCommit(l_errl, HWPF_COMP_ID);

                break;
            }


            // Skip calling a second time on boot's fused core
            // This was already called in 16.1 for the fused core
            if ( !is_fused_mode() ||
                 ((l_bootPIR & ~PIR_t::THREAD_MASK_FUSED) != (pir & ~PIR_t::THREAD_MASK_FUSED)) )
            {
                // Save off original checkstop values and override them
                // to disable core xstops and enable sys xstops.
                l_errl = HBPM::core_checkstop_helper_hwp(l_core, true);
                if (l_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "core_checkstop_helper_hwp on core 0x%08X ERROR: returning.",
                            get_huid(l_core));
                    l_stepError.addErrorDetails(l_errl);
                    errlCommit(l_errl, HWPF_COMP_ID);
                    break;
                }
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Already enabled sys xstops on fused boot core 0x%08X",
                    get_huid(l_core));
            }
        }

        // Break out if we've already hit an error
        if ( !l_stepError.isNull() )
        {
            break;
        }

        // Disable Special Wakeup in MPIPL (allows stop states to work)
        if (sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            TargetHandleList l_procTargetList;
            getAllChips(l_procTargetList, TYPE_PROC);

            for (const auto & l_proc: l_procTargetList)
            {
                // Do not call special wakeup for procs with no PG-good cores
                // Find all PRESENT CORE chiplets of the proc
                TargetHandleList l_coreTargetList;
                getCoreChiplets( l_coreTargetList,
                                 UTIL_FILTER_CORE_ALL,
                                 UTIL_FILTER_PRESENT,
                                 l_proc);
                if (l_coreTargetList.empty())
                {
                    // No PRESENT cores, continue
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Proc 0x%x has no PG-good cores, not calling p10_core_special_wakeup (DISABLE)",
                        l_proc->getAttr<ATTR_HUID>());
                    continue;
                }

                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                "Calling p10_core_special_wakeup (DISABLE) for all cores on proc: 0x%x",
                                 l_proc->getAttr<TARGETING::ATTR_HUID>());

                fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST >  l_core_mc =
                      l_fapiProc.getMulticast< fapi2::MULTICAST_OR >
                                      (fapi2::MCGROUP_GOOD_EQ, fapi2::MCCORE_ALL);


                FAPI_INVOKE_HWP(l_errl,
                                p10_core_special_wakeup,
                                l_core_mc,
                                p10specialWakeup::SPCWKUP_DISABLE,
                                p10specialWakeup::HOST);

                if (l_errl != nullptr)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK "call_host_activate_secondary_cores> Failed in call to "
                               "p10_core_special_wakeup DISABLE for all cores on proc: 0x%x",
                               l_proc->getAttr<TARGETING::ATTR_HUID>());
                    l_stepError.addErrorDetails(l_errl);
                    errlCommit(l_errl, HWPF_COMP_ID);
                }
            }
        }

        // Take new checkstop values and insert them into the homer image
        l_errl = HBPM::core_checkstop_helper_homer();

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_activate_secondary_cores ERROR: returning.");
            l_stepError.addErrorDetails(l_errl);
            errlCommit(l_errl, HWPF_COMP_ID);
            break;
        }

    } while (0);

    //Set SKIP_WAKEUP to false after all cores are powered on (16.2)
    //If this is not set false, PM_RESET will fail to enable special wakeup.
    // PM_RESET is expected to enable special_wakeup after all the cores powered on
    sys->setAttr<ATTR_SKIP_WAKEUP>(0);

    // Now that the slave cores are running, we need to include them in
    //  multicast scom operations
    SCOM::enableSlaveCoreMulticast();

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_activate_secondary_cores exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
} // end call_host_activate_secondary_cores

} // end namespace ISTEP_16
