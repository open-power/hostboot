/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_activate_secondary_cores.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
#include <p10_pm_elog.H>
#include <p10_hcd_memmap_base.H>
#include <p10_pm_generate_elog.H>

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
#include <stdio.h>

#ifdef CONFIG_PLDM
#include <pldm/requests/pldm_pdr_requests.H>
#endif

using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEP;
using namespace ISTEP_ERROR;

const int ELOG_BUF_SIZE  = 3072;
const int SECTN_HCODE_LOG_IN_HB = 0x01;

namespace ISTEP_16
{

/**
 * @brief   finds error log in PM engine's SRAM and reproduces it in HB context
 * @param[in]   i_procChip      fapi2 target for processor chip
 * @param[in]   i_coreTgt       HB target handle for failing core
 * @param[out]  o_stepError     an instance of IStepError
 * @return      none
 */
void lookup_and_commit_pm_elog( fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_procChip, 
        TargetHandle_t i_coreTgt, IStepError  &o_stepError )
{
    // 1)    first let us determine if  there is an error log waiting to be collected
    // 2)    Once an error log is found, identify its source
    // 3)    create an error log  instance and package the PM elog as user data payload
    // 4)    creator should be PM Complex component.
    fapi2::ReturnCode rc_fapi( fapi2::FAPI2_RC_SUCCESS );
    ERRORLOG::ErrlEntry* l_errl = nullptr;
    ERRORLOG::ErrlEntry* l_hwpErrl = nullptr;
    ElogDissectionSum l_elogDissectionSum;
    uint32_t l_logLength = ELOG_BUF_SIZE;
    uint8_t * l_pHcdLogBuf = new uint8_t[ ELOG_BUF_SIZE ];

    do
    {
        const auto l_coreId = i_coreTgt->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Core Pos %d", l_coreId );

        FAPI_INVOKE_HWP( l_hwpErrl, p10_pm_generate_elog, i_procChip, l_coreId, l_elogDissectionSum, 
                         l_pHcdLogBuf, l_logLength );
        if( l_hwpErrl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK "Failed to read hcode elog" );
            l_hwpErrl->setSev( ERRORLOG::ERRL_SEV_INFORMATIONAL );
            errlCommit( l_hwpErrl, HWPF_COMP_ID );
            break;
        }

        uint64_t l_elogUsrdata12 = l_elogDissectionSum.iv_userData1;
        l_elogUsrdata12 = l_elogUsrdata12 << 32;
        l_elogUsrdata12 = l_elogUsrdata12 | l_elogDissectionSum.iv_userData2;
        uint64_t l_elogUsrdata3 = l_elogDissectionSum.iv_userData3;
        l_elogUsrdata3 = l_elogUsrdata3 << 32;
            
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Creating Log On Behalf of QME" );

        l_errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          l_elogDissectionSum.iv_moduleId,
                                          l_elogDissectionSum.iv_compId | l_elogDissectionSum.iv_reasonCode,
                                          l_elogUsrdata12,
                                          l_elogUsrdata3,
                                          SECTN_HCODE_LOG_IN_HB );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Adding FFDC" );

        // Add OCC response data to user details
        l_errl->addFFDC( l_elogDissectionSum.iv_compId,
                         l_pHcdLogBuf,
                         l_logLength,
                         l_elogDissectionSum.iv_version,  // version
                         0 );

        l_errl->collectTrace( ISTEP_COMP_NAME,256 );
        l_errl->collectTrace( FAPI_TRACE_NAME, 512 );
        l_errl->addHwCallout( i_coreTgt, HWAS::SRCI_PRIORITY_HIGH, HWAS::DECONFIG, HWAS::GARD_Fatal ); 
        o_stepError.addErrorDetails( l_errl );
        errlCommit( l_errl, l_elogDissectionSum.iv_compId );

    }while( 0 );

    delete[] l_pHcdLogBuf;
}

void* call_host_activate_secondary_cores(void* const io_pArgs)
{
    IStepError  l_stepError;
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
                // Do not call special wakeup for procs with no functional cores
                TargetHandleList l_coreTargetList;
                getCoreChiplets( l_coreTargetList,
                                 UTIL_FILTER_CORE_ALL,
                                 UTIL_FILTER_FUNCTIONAL,
                                 l_proc);
                if (l_coreTargetList.empty())
                {
                    // No FUNCTIONAL cores, continue
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Proc 0x%x has no functional cores, not calling p10_core_special_wakeup (ENABLE)",
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
                          "Time out rc from kernel %d on core Id: 0x%016llX",
                          rc,
                          coreId );

                // only called if the core doesn't report in
                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                  l_fapi2ProcTarget(l_processor);

                lookup_and_commit_pm_elog( l_fapi2ProcTarget, l_core, l_stepError );


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
                l_errl->collectTrace(INTR_TRACE_NAME,512);

                // Throw printk in there too in case it is a kernel issue
                ERRORLOG::ErrlUserDetailsPrintk().addToLog(l_errl);

                // Add interesting ISTEP traces
                l_errl->collectTrace(FAPI_TRACE_NAME, 512);

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
                // Do not call special wakeup for procs with no functional cores
                TargetHandleList l_coreTargetList;
                getCoreChiplets( l_coreTargetList,
                                 UTIL_FILTER_CORE_ALL,
                                 UTIL_FILTER_FUNCTIONAL,
                                 l_proc);
                if (l_coreTargetList.empty())
                {
                    // No FUNCTIONAL cores, continue
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
