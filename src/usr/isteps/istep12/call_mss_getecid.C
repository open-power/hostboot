/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_mss_getecid.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 * @file    call_mss_getecid.C
 *
 *  Contains the wrapper for Istep 12.1 exp_getecid
 *
 */

#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <istepHelperFuncs.H>          // captureError

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/targplatutil.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

//HWP
#include  <chipids.H>
#include  <exp_getecid.H>
#include  <p10_scom_proc.H>
#include  <p10_init_mem_encryption.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;
using   namespace   scomt::proc;

namespace ISTEP_12
{

/* @brief Determine whether memory encryption should be enabled.
 *
 * @param[in] i_procs    Processor targets to consider
 * @param[out] o_enable  True if memory encryption should be enabled on
 *                       all given processors, false otherwise.
 * @return errlHndl_t    Error if any, otherwise nullptr.
 */
static errlHndl_t should_enable_memory_encryption(TargetHandleList const i_procs,
                                                  bool& o_enable)
{
    errlHndl_t errl = nullptr;

    o_enable = true;

    // If any processor disables encryption, then we won't enable it on any
    // processor.
    for (const auto proc : i_procs)
    {
        bool encryption_export_controlled = false;

        // Check for export controls on memory encryption
        {
            // Read the Export Control Status register to check whether we're
            // allowed to use cryptography.
            uint64_t export_ctl = 0;
            size_t export_ctl_size = sizeof(export_ctl);
            errl = deviceRead(proc,
                              &export_ctl,
                              export_ctl_size,
                              DEVICE_SCOM_ADDRESS(TP_TPCHIP_PIB_OTP_OTPC_M_EXPORT_REGL_STATUS));

            if (errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          ERR_MRK"Memory encryption: Failed to read export status SCOM register");
                break;
            }

            const uint64_t EXPORT_STATUS_TP_MC_ALLOW_CRYPTO_DC_MASK
                = 1ull << (63 - TP_TPCHIP_PIB_OTP_OTPC_M_EXPORT_REGL_STATUS_TP_MC_ALLOW_CRYPTO_DC);

            encryption_export_controlled = (export_ctl & EXPORT_STATUS_TP_MC_ALLOW_CRYPTO_DC_MASK) == 0;
        }

        if (encryption_export_controlled)
        {
            // Do not enable encryption if export controls are in place on any
            // processor.
            o_enable = false;
        }
        else
        {
            // If no export controls are in place, then check whether this
            // processor's attribute disables encryption.
            o_enable = o_enable && (proc->getAttr<ATTR_PROC_MEMORY_ENCRYPTION_ENABLED>()
                                    != PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED);
        }
    }

    return errl;
}

/* @brief Check whether memory encryption should be enabled, and initialize it
 *        if so. Also set the PROC_MEMORY_ENCRYPTION_ENABLED attribute to
 *        reflect the final decision.
 *
 * @return errlHndl_t  Error if any, otherwise nullptr.
 */
static errlHndl_t init_memory_encryption()
{
    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"init_memory_encryption" );

    errlHndl_t errl = nullptr;

    do
    {

    Target* const node = UTIL::getCurrentNodeTarget();

    TargetHandleList procs;
    getChildAffinityTargetsByState(procs,
                                   node,
                                   CLASS_NA,
                                   TYPE_PROC,
                                   UTIL_FILTER_FUNCTIONAL);

    bool enable_encryption { };
    errl = should_enable_memory_encryption(procs, enable_encryption);

    if (errl)
    {
        break;
    }

    if (enable_encryption)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "Memory encryption: Initializing encryption on %lu processors",
                  procs.size());

        // Set up the encryption SCOMs
        Target* failproc = nullptr;
        errl = hwp_for_each(p10_init_mem_encryption, procs, &failproc);

        if (errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"Memory encryption: p10_init_mem_encryption failed on processor 0x%08x",
                      get_huid(failproc));
            break;
        }
    }
    else
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "Memory encryption: Disabling encryption on %lu processors",
                  procs.size());

        for (const auto proc : procs)
        {
            proc->setAttr<ATTR_PROC_MEMORY_ENCRYPTION_ENABLED>(PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED);
        }
    }

    } while (false);

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK"init_memory_encryption" );

    return errl;
}

void* call_mss_getecid (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    compId_t  l_componentId = HWPF_COMP_ID;

    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_mss_getecid entry" );

    // Get all OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
            l_fapi_ocmb_target(l_ocmb_target);

        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "Running exp_getecid HWP on target HUID 0x%.8X",
                get_huid(l_ocmb_target) );
            FAPI_INVOKE_HWP(l_err, exp_getecid, l_fapi_ocmb_target);

            if ( l_err )
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "ERROR : call exp_getecid HWP(): failed on target 0x%08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_ocmb_target),
                    TRACE_ERR_ARGS(l_err));
                l_componentId = HWPF_COMP_ID;

                // Capture error and continue to the next chip
                captureError(l_err, l_StepError, l_componentId, l_ocmb_target);
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "SUCCESS running %s_getecid HWP on target HUID 0x%.8X",
                    "exp", get_huid(l_ocmb_target) );
            }
        }
        else // Not an Explorer, continue to the next chip.
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_mss_getecid: Unknown chip ID 0x%X on target HUID 0x%.8X",
                chipId, get_huid(l_ocmb_target) );
        }
    } // OCMB loop

    l_err = init_memory_encryption();

    if (l_err)
    {
        captureError(l_err, l_StepError, l_componentId);
    }

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK"call_mss_getecid exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
