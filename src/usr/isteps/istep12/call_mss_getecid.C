/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_mss_getecid.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
#include    <ocmbupd_helpers.H>

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
#include  <ody_getecid.H>
#include  <hwpThreadHelper.H>
#include  <p10_scom_proc.H>
#include  <p10_init_mem_encryption.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;
using   namespace   scomt::proc;
using   namespace   ocmbupd;

namespace ISTEP_12
{

/* @brief Determine whether memory encryption should be enabled.
 *
 * @param[in] i_procs    Processor targets to consider
 * @param[out] o_enable  True if memory encryption should be enabled on
 *                       all given processors, false otherwise.
 * @return errlHndl_t    Error if any, otherwise nullptr.
 */
static errlHndl_t should_enable_memory_encryption(const TargetHandleList& i_procs,
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
                TRACISTEP(ERR_MRK"Memory encryption: Failed to read export status SCOM register");
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
            break;
        }
        else
        {
            // If no export controls are in place, then check whether this
            // processor's attribute disables encryption.
            o_enable = (proc->getAttr<ATTR_PROC_MEMORY_ENCRYPTION_ENABLED>()
                        != PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED);

            if (!o_enable)
            {
                break;
            }
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
    TRACISTEP(ENTER_MRK"init_memory_encryption" );

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
        TRACISTEP("Memory encryption: Initializing encryption on %lu processors",
                  procs.size());

        // Set up the encryption SCOMs
        Target* failproc = nullptr;
        errl = hwp_for_each(p10_init_mem_encryption, procs, &failproc);

        if (errl)
        {
            TRACISTEP(ERR_MRK"Memory encryption: p10_init_mem_encryption failed on processor 0x%08x",
                      get_huid(failproc));
            break;
        }
    }
    else
    {
        TRACISTEP("Memory encryption: Disabling encryption on %lu processors",
                  procs.size());

        for (const auto proc : procs)
        {
            proc->setAttr<ATTR_PROC_MEMORY_ENCRYPTION_ENABLED>(PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED);
        }
    }

    } while (false);

    TRACISTEP(EXIT_MRK"init_memory_encryption" );

    return errl;
}

#define CONTEXT call_mss_getecid

void* call_mss_getecid(void* io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    constexpr uint64_t CHIPLET1_REGISTER  = 0x010f001e;
    constexpr uint64_t UNMASK_BIT12 = 0xFFF7FFFFFFFFFFFF;
    size_t l_numBytes = 8;
    uint8_t l_buf[8] = {0};
    uint64_t l_data = 0ULL;

    TRACISTEP(ENTER_MRK"call_mss_getecid entry" );

    const auto l_runOdyHwpFromHost =
      TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // Get all OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto l_ocmb_target : l_ocmbTargetList)
    {
        if (TARGETING::UTIL::isOdysseyChip(l_ocmb_target))
        {
            TRACISTEP("ody_getecid: UNMASKING 12th bit for target HUID 0x%.8X l_runOdyHwpFromHost:%d",
                      get_huid(l_ocmb_target), l_runOdyHwpFromHost);

            // To prevent undesirable SBE updates, we need to unmask (bit 12 of 0x010F001E).
            // To unmask we need to set that bit to 0 (as MASK bit is 1). We will do a
            // read modify write to set the 12th bit to 0.

            // First read the value...
            l_err = DeviceFW::deviceOp(DeviceFW::READ, l_ocmb_target, l_buf, l_numBytes,
                                       DEVICE_SCOM_ADDRESS(CHIPLET1_REGISTER));
            if (!l_err)
            {
                // Unmask the 12th bit
                l_data = *(reinterpret_cast<uint64_t *>(l_buf));
                TRACISTEP("ody_getecid: Read value=0x%llx from target=0x%.8X", l_data,
                           get_huid(l_ocmb_target));

                l_data &= UNMASK_BIT12;
                TRACISTEP("ody_getecid: Value after Anding with unmask value=0x%llx", l_data);

                // Now write the data back to the register
                l_err = DeviceFW::deviceOp(DeviceFW::WRITE, l_ocmb_target,
                                   reinterpret_cast<uint8_t *>(&l_data),
                                   l_numBytes,
                                   DEVICE_SCOM_ADDRESS(CHIPLET1_REGISTER));
                if (!l_err)
                {
                    TRACISTEP("ody_getecid: Wrote value=0x%llx to target=0x%.8X", l_data,
                               get_huid(l_ocmb_target));
                    TRACISTEP("Running ody_getecid HWP on target HUID 0x%.8X l_runOdyHwpFromHost:%d",
                               get_huid(l_ocmb_target), l_runOdyHwpFromHost);
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, l_ocmb_target,
                                ody_getecid, { l_ocmb_target });
                }
                else
                {
                    TRACISTEP(ERR_MRK"ERROR from ody_getecid: Scom write to target HUID 0x%.8X"
                              "Address=0x%x Data=0x%16x",
                              get_huid(l_ocmb_target), CHIPLET1_REGISTER, l_data);
                }
            }
            else
            {
                TRACISTEP(ERR_MRK"ERROR from ody_getecid: Scom Read from target HUID 0x%.8X"
                          "Address=0x%x", get_huid(l_ocmb_target), CHIPLET1_REGISTER);
            }

        ERROR_EXIT: // used by RUN_ODY_HWP
            if (l_err)
            {
                HANDLE_ODY_HWP_ERROR(CONTEXT, ody_getecid, l_StepError, l_ocmb_target, l_err);
            }
        }
        else
        {
            TRACISTEP("Running exp_getecid HWP on target HUID 0x%.8X",
                      get_huid(l_ocmb_target));
            FAPI_INVOKE_HWP(l_err, exp_getecid, { l_ocmb_target });

            if (l_err)
            {
                TRACISTEP(ERR_MRK"call exp_getecid HWP(): failed on target 0x%08X. "
                          TRACE_ERR_FMT,
                          get_huid(l_ocmb_target),
                          TRACE_ERR_ARGS(l_err));

                captureError(l_err, l_StepError, HWPF_COMP_ID, l_ocmb_target);
            }
            else
            {
                TRACISTEP("SUCCESS running exp_getecid HWP on target HUID 0x%.8X",
                          get_huid(l_ocmb_target) );
            }
        }
    }

    l_err = init_memory_encryption();

    if (l_err)
    {
        captureError(l_err, l_StepError, HWPF_COMP_ID);
    }

    TRACISTEP(EXIT_MRK"call_mss_getecid exit");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
