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

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace SBEIO;

namespace ISTEP_08
{

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

            l_errl->addHwCallout(l_cpu_target, HWAS::SRCI_PRIORITY_LOW, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);

            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
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
