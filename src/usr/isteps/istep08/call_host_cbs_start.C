/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_cbs_start.C $                */
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
/**
 *  @file call_host_cbs_start.C
 *
 *  Support file for IStep: host_cbs_start
 *   CFAM Boot Sequencer
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <hbotcompid.H>           // HWPF_COMP_ID
#include <attributeenums.H>       // TYPE_PROC
#include <isteps/hwpisteperror.H> //ISTEP_ERROR:IStepError
#include <istepHelperFuncs.H>     // captureError
#include <fapi2/plat_hwp_invoker.H>
#include <sbeio/sbeioif.H>
#include <spi/spi.H> // for SPI lock support
#include <p10_start_cbs.H>
#include <p10_clock_test.H>
#include <p10_setup_ref_clock.H>
#include <p10_scom_perv.H>
#include <sbe/sbe_update.H>
#include <targeting/targplatutil.H>
#include <errl/errludattribute.H>
#include <hwas/common/hwas.H>
#include <errl/errludtarget.H>
#include <errl/errlreasoncodes.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace SBEIO;
using namespace HWAS;

namespace ISTEP_08
{

#ifndef CONFIG_FSP_BUILD
/* @brief Converts a clock callout type (e.g. OSCREFCLK0_TYPE) to a clock
 *        deconfig state (e.g. SYS_CLOCK_DECONFIG_STATE_A_DECONFIG). If the
 *        clock callout type is "unknown" (represented by OSCREFCLK_TYPE), then
 *        this function will return the clock type that isn't currently
 *        deconfigured.
 */
SYS_CLOCK_DECONFIG_STATE clock_callout_to_deconfig_state(const SYS_CLOCK_DECONFIG_STATE i_current_clock_state,
                                                         const clockTypeEnum i_clock_callout_type)
{
    SYS_CLOCK_DECONFIG_STATE state = SYS_CLOCK_DECONFIG_STATE_NO_DECONFIG;

    switch (i_clock_callout_type)
    {
    case OSCREFCLK0_TYPE:
        state = SYS_CLOCK_DECONFIG_STATE_A_DECONFIG;
        break;
    case OSCREFCLK1_TYPE:
        state = SYS_CLOCK_DECONFIG_STATE_B_DECONFIG;
        break;
    case OSCREFCLK_TYPE:
        if (i_current_clock_state == SYS_CLOCK_DECONFIG_STATE_A_DECONFIG)
        {
            state = SYS_CLOCK_DECONFIG_STATE_B_DECONFIG;
        }
        else // If no clocks are deconfigured, or if clock B is
             // deconfigured, we blame clock A for the problem.
        {
            state = SYS_CLOCK_DECONFIG_STATE_A_DECONFIG;
        }
        break;
    default:
        // There are other types of clocks that we don't care about; return
        // NO_DECONFIG.
        break;
    }

    return state;
}

/* @brief Deconfigure the next available clock based on the given clock
 *        callout. This function will never deconfigure all the clocks on the
 *        system. Note that this call is idempotent on a per-IPL basis.
 *
 * @param[in] i_errl                The error log that called out the clock.
 * @param[in] i_proc                The processor on which the clock operation failed.
 * @param[in] i_clock_callout_type  The clock that was called out.
 */
void deconfigure_redundant_clock(errlHndl_t i_errl,
                                 Target* const i_proc,
                                 const clockTypeEnum i_clock_callout_type)
{
    const auto sys = UTIL::assertGetToplevelTarget();

    const SYS_CLOCK_DECONFIG_STATE initial_clock_deconfig_state
        = sys->getAttr<ATTR_SYS_CLOCK_DECONFIG_STATE_INITIAL>();
    const SYS_CLOCK_DECONFIG_STATE this_clock_deconfig_state
        = clock_callout_to_deconfig_state(initial_clock_deconfig_state, i_clock_callout_type);

    if (this_clock_deconfig_state != SYS_CLOCK_DECONFIG_STATE_NO_DECONFIG)
    {
        const SYS_CLOCK_DECONFIG_STATE current_clock_deconfig_state
            = sys->getAttr<ATTR_SYS_CLOCK_DECONFIG_STATE>();
        const auto new_clock_deconfig_state
            = static_cast<SYS_CLOCK_DECONFIG_STATE>(initial_clock_deconfig_state | this_clock_deconfig_state);

        // Call out the node, because the clocks are actually provided by the
        // backplane (i.e. there is one set of clocks for the entire backplane,
        // not per-processor).
        const auto node = TARGETING::UTIL::assertGetMasterNodeTarget();
        i_errl->addHwCallout(node, HWAS::SRCI_PRIORITY_HIGH, HWAS::NO_DECONFIG, HWAS::GARD_NULL);

        // Call out the offending clock
        i_errl->addClockCallout(i_proc, i_clock_callout_type, SRCI_PRIORITY_LOW, NO_DECONFIG, GARD_NULL);

        /*
         We NEVER deconfigure all the clocks in the system. If there would be no
         clocks left after deconfiguring the called out clock, we deconfigure
         the processor instead. This allows us to try IPLing again without one
         processor in hopes that that will solve the issue.
        */

        if (new_clock_deconfig_state != SYS_CLOCK_DECONFIG_STATE_ALL_DECONFIG)
        {
            // Call out the processor but don't deconfigure it if we have more
            // clocks to try
            i_errl->addHwCallout(i_proc, HWAS::SRCI_PRIORITY_LOW, HWAS::NO_DECONFIG, HWAS::GARD_NULL);

            // Severity should be "recovered" since there's no action for the
            // system owners to take.
            i_errl->setSev(ERRORLOG::ERRL_SEV_RECOVERED);

            TRACFCOMP(g_trac_isteps_trace,
                      "Changing ATTR_SYS_CLOCK_DECONFIG_STATE from %d -> %d due to clock callout on oscillator %d "
                      "(initial state at boot was %d).",
                      current_clock_deconfig_state,
                      new_clock_deconfig_state,
                      i_clock_callout_type,
                      initial_clock_deconfig_state);

            sys->setAttr<ATTR_SYS_CLOCK_DECONFIG_STATE>(new_clock_deconfig_state);

            TRACFCOMP(g_trac_isteps_trace,
                      "Explicitly Requesting a reconfig loop because a clock was deconfigured "
                      "(but no target was deconfigured) and there are more spare clocks to boot with.");

            // Since we don't have a real target for the clocks we won't trigger
            // a reconfig loop automatically when a clock is marked for deconfig.
            // To emulate that behavior we will manually set the flag that is
            // checked at the end of each istep.
            HWAS::setOrClearReconfigLoopReason(ReconfigSetOrClear::RECONFIG_SET,
                                               RECONFIGURE_LOOP_DECONFIGURE);
        }
        else
        {
            // If we don't have any more clocks to deconfigure, we deconfigure
            // the proc instead to increase our chances of being able to boot on
            // the next IPL.
            i_errl->addHwCallout(i_proc, HWAS::SRCI_PRIORITY_LOW, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);

            // Severity should be visible to the system owners
            i_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);

            TRACFCOMP(g_trac_isteps_trace,
                      "A clock was called out to be deconfigured, but we are not deconfiguring "
                      "it because it would leave the system with no functional clocks. "
                      "Deconfiguring processor 0x%08x instead.",
                      get_huid(i_proc));
        }

        // Add the clock deconfig attributes to the error log to help debug
        ERRORLOG::ErrlUserDetailsAttribute attrud(i_proc);
        attrud.addData(ATTR_SYS_CLOCK_DECONFIG_STATE_INITIAL);
        attrud.addData(ATTR_SYS_CLOCK_DECONFIG_STATE);
        attrud.addToLog(i_errl);
    }
}
#endif

//******************************************************************************
// call_host_cbs_start()
//******************************************************************************
void* call_host_cbs_start(void *io_pArgs)
{
    IStepError  l_stepError;
    errlHndl_t l_errl = nullptr;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_host_cbs_start");

    do {

    //
    //  get a list of all the procs in the system
    //
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    //
    //  Identify the master processor
    //
    Target* l_pMasterProcTarget = nullptr;
    targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

#ifndef CONFIG_FSP_BUILD
    // Get the sys_clock_near_end_termination_site value from
    // master proc root control reg 7.  This will be used later to
    // set the corresponding secondary proc attr.
    uint64_t l_root_ctrl_data = 0;
    size_t l_root_ctrl_size = sizeof(l_root_ctrl_data);
    l_errl = deviceRead(l_pMasterProcTarget,
                        &l_root_ctrl_data,
                        l_root_ctrl_size,
                        DEVICE_SCOM_ADDRESS(
                            scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL7_RW));
    if (l_errl)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "ERROR : failed to read root control 7 reg for target %.8X"
                  TRACE_ERR_FMT,
                  get_huid(l_pMasterProcTarget),
                  TRACE_ERR_ARGS(l_errl));
        captureError(l_errl,
                     l_stepError,
                     HWPF_COMP_ID,
                     l_pMasterProcTarget);
        break;
    }

    // Save the planar or proc value for later
    constexpr uint64_t BIT_30_MASK = 0x0000000200000000ull;
    uint64_t l_ne_term_enable =
        fapi2::ENUM_ATTR_SYS_CLK_NE_TERMINATION_SITE_PLANAR;
    if ( l_root_ctrl_data & BIT_30_MASK)
    {
        l_ne_term_enable = fapi2::ENUM_ATTR_SYS_CLK_NE_TERMINATION_SITE_PROC;
    }
#endif

    // loop thru all processors, only call procedure on non-master processors
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        if (l_cpu_target == l_pMasterProcTarget)
        {
            continue;
        }

        // Prevent HB SPI operations to this slave processor during SBE boot
        l_errl = SPI::spiLockProcessor(l_cpu_target, true);
        if (l_errl)
        {
            // This would be a firmware bug that would be hard to
            // find later so terminate with this failure
            TRACFCOMP(g_trac_isteps_trace,
                        "ERROR : SPI lock failed to target %.8X"
                        TRACE_ERR_FMT,
                        get_huid(l_cpu_target),
                        TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            break;
        }

        //Before starting the CBS (and thus the SBE) on slave procs
        //Make sure the SBE FIFO is clean by doing a full reset of
        //the fifo
        l_errl = sendFifoReset(l_cpu_target);
        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                        "ERROR : call sendFifoReset target %.8X"
                        TRACE_ERR_FMT,
                        get_huid(l_cpu_target),
                        TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            continue; //Don't continue on this chip if failed
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target (l_cpu_target);

#ifndef CONFIG_FSP_BUILD
        l_cpu_target->setAttr<ATTR_SYS_CLK_NE_TERMINATION_SITE_PREVENT_SYNC>
                                                    (l_ne_term_enable);

        // Run p10_setup_ref_clock before clock_test
        TRACFCOMP(g_trac_isteps_trace,
                    "Running p10_setup_ref_clock HWP on processor target %.8X",
                    get_huid(l_cpu_target));

        FAPI_INVOKE_HWP(l_errl, p10_setup_ref_clock, l_fapi2_proc_target);
        if(l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                        "ERROR : call p10_setup_ref_clock target %.8X"
                        TRACE_ERR_FMT,
                        get_huid(l_cpu_target),
                        TRACE_ERR_ARGS(l_errl));

            l_errl->addHwCallout(l_cpu_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::DELAYED_DECONFIG,
                                 HWAS::GARD_NULL);

            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            continue; //Don't continue on this chip if p10_setup_ref_clock failed
        }
#endif

        // Run the clock_test before start_cbs
        // to reduce the window for clock failure
        TRACFCOMP(g_trac_isteps_trace,
                    "Running p10_clock_test HWP on processor target %.8X",
                    get_huid(l_cpu_target));

        FAPI_INVOKE_HWP(l_errl, p10_clock_test, l_fapi2_proc_target);
        if(l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                        "ERROR : call p10_clock_test target %.8X"
                        TRACE_ERR_FMT,
                        get_huid(l_cpu_target),
                        TRACE_ERR_ARGS(l_errl));

            // BMC systems may have spare clocks, so we don't deconfigure
            // the processor; we'll deconfigure the clock, and the BMC is
            // responsible for examining which clocks are available and
            // determining whether it's possible to boot.
#ifdef CONFIG_FSP_BUILD
            l_errl->addHwCallout(l_cpu_target, SRCI_PRIORITY_LOW, DELAYED_DECONFIG, GARD_NULL);
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
#else
            // Search the error log for callouts to determine which clock is at
            // fault.

            HWAS::clockTypeEnum clock_callout_type = OSCREFCLK_TYPE;

            for(const auto callout : l_errl->getUDSections(ERRL_COMP_ID, ERRORLOG::ERRL_UDT_CALLOUT))
            {
                const auto ud = reinterpret_cast<HWAS::callout_ud_t*>(callout);
                if (ud->type == HWAS::CLOCK_CALLOUT && ud->clockType != OSCREFCLK_TYPE)
                {
                    clock_callout_type = ud->clockType;
                    break;
                }
            }
                deconfigure_redundant_clock(l_errl, l_cpu_target, clock_callout_type);
            ERRORLOG::ErrlUserDetailsTarget(l_cpu_target).addToLog(l_errl);
            l_errl->collectTrace("ISTEPS_TRACE");

            // Don't add the log to the istep log in this path, so that (1) the
            // severity won't be upgraded to UNRECOVERABLE, and (2) the istep
            // will succeed but perform a reconfig loop because of
            // deconfigure_redundant_clock's processing.
            errlCommit(l_errl, HWPF_COMP_ID);
#endif

            continue; //Don't continue on this chip if p10_clock_test failed
        }

        // Trace Measurement and Boot Seeproms
        SBE::sbeSeepromSide_t l_boot_side = SBE::SBE_SEEPROM_INVALID;
        SBE::sbeMeasurementSeepromSide_t l_measurement_side =
                                            SBE::SBE_MEASUREMENT_SEEPROM_INVALID;
        l_errl = getSbeBootSeeprom(l_cpu_target, l_boot_side, l_measurement_side);
        if(l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                        "ERROR : call getSbeBootSeeprom target %.8X"
                        TRACE_ERR_FMT,
                        get_huid(l_cpu_target),
                        TRACE_ERR_ARGS(l_errl));

            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            continue; // Don't continue if a simple scom/cfam access failed
        }

        TRACFCOMP(g_trac_isteps_trace,
                    "Running p10_start_cbs HWP on processor target %.8X, bootSide=%d, mSide=%d",
                    get_huid(l_cpu_target), l_boot_side, l_measurement_side);

        FAPI_INVOKE_HWP(l_errl, p10_start_cbs, l_fapi2_proc_target, true);
        if(l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                        "ERROR : call p10_start_cbs target %.8X"
                        TRACE_ERR_FMT,
                        get_huid(l_cpu_target),
                        TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
        }
    }

    // For recovery, attempt to unlock all slave processor SPI engines
    if (!l_stepError.isNull())
    {
        // loop thru all processors, only call procedure on non-master processors
        for (const auto & l_cpu_target: l_cpuTargetList)
        {
            if (l_cpu_target != l_pMasterProcTarget)
            {
                // Allow SPI operations again, as this step is failing
                l_errl = SPI::spiLockProcessor(l_cpu_target, false);
                if (l_errl)
                {
                    // unlock should never fail unless coding issue
                    // since this is just a recovery attempt, delete error
                    delete l_errl;
                    l_errl = nullptr;
                }
            }
        }
    }

    }while(0);

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_cbs_start");
    return l_stepError.getErrorHandle();
}
};
