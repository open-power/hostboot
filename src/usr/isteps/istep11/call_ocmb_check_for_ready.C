/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_ocmb_check_for_ready.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 *  @file call_ocmb_check_for_ready.C
 *
 *  Support file for IStep: ocmb_check_for_ready
 *    Check that OCMB is ready
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

//  Error handling support
#include <errl/errlentry.H>                     // errlHndl_t
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>                  // ErrlUserDetailsTarget
#include <istepHelperFuncs.H>                   // captureError

//  FAPI support
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <isteps/hwpisteperror.H>               // IStepError

//  Tracing support
#include <initservice/isteps_trace.H>           // g_trac_isteps_trace

//  Targeting support
#include <attributeenums.H>                     // TYPE_PROC
#include <targeting/common/utilFilter.H>        // getAllChips
#include <sbeio/sbeioif.H>
#include <util/misc.H>
#include <sys/time.h>

//  HWP call support
#include <exp_check_for_ready.H>

// Explorer error logs
#include <expscom/expscom_errlog.H>

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_11
{
void* call_ocmb_check_for_ready (void *io_pArgs)
{
    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_ocmb_check_for_ready");

    errlHndl_t  l_errl = nullptr;
    IStepError l_StepError;

    TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);

    // loop thru the list of processors
    for (TargetHandleList::const_iterator
            l_proc_iter = functionalProcChipList.begin();
            l_proc_iter != functionalProcChipList.end();
            ++l_proc_iter)
    {

        TargetHandleList l_functionalOcmbChipList;
        getChildAffinityTargets( l_functionalOcmbChipList,
                                 const_cast<Target*>(*l_proc_iter),
                                 CLASS_CHIP,
                                 TYPE_OCMB_CHIP,
                                 true);

        for (const auto & l_ocmb : l_functionalOcmbChipList)
        {
            TRACFCOMP(g_trac_isteps_trace,
                        "Start : exp_check_for_ready "
                        "for 0x%.08X", get_huid(l_ocmb));

            fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
                                    l_fapi_ocmb_target(l_ocmb);

            // Keeping this loop in here just in case we need it later
            uint8_t NUM_LOOPS = 1;
            if( Util::isSimicsRunning() )
            {
                NUM_LOOPS = 1;
            }

            // Save the original timeout (to be restored after
            // exp_check_for_ready
            const auto original_timeout
                = l_ocmb->getAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>();

            // Break the timeout into small chunks. This is a hack to avoid
            // running out of memory in the polling code.
            const ATTR_MSS_CHECK_FOR_READY_TIMEOUT_type timeout_chunk_size = 10;

            // exp_check_for_ready will read this attribute to know how long to
            // poll. If this number is too large and we get too many I2C error
            // logs between calls to FAPI_INVOKE_HWP, we will run out of memory.
            l_ocmb->setAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>(timeout_chunk_size);

            for(uint8_t i = 0; i < NUM_LOOPS; i++)
            {
                // Retry exp_check_for_ready as many times as it takes to either
                // succeed or time out (in timeout_chunk_size-duration attempts)
                for (size_t timeout_counter = 0;
                     timeout_counter < original_timeout;
                     timeout_counter += timeout_chunk_size)
                {
                    // Delete the log from the previous iteration
                    if( l_errl )
                    {
                        delete l_errl;
                        l_errl = nullptr;
                    }

                    // Catch the last iteration in the case where
                    // original_timeout is not evenly divisible by
                    // timeout_chunk_size.
                    const size_t chunk_size = original_timeout - timeout_counter;
                    if (chunk_size < timeout_chunk_size)
                    {
                        l_ocmb->setAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>(chunk_size);
                    }

                    FAPI_INVOKE_HWP(l_errl,
                                    exp_check_for_ready,
                                    l_fapi_ocmb_target);

                    // On success, quit retrying.
                    if (!l_errl)
                    {
                        break;
                    }
                }
            }

            l_ocmb->setAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>(original_timeout);

            if (l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : call_ocmb_check_for_ready HWP(): "
                          "exp_check_for_ready failed on target 0x%08X."
                          TRACE_ERR_FMT,
                          get_huid(l_ocmb),
                          TRACE_ERR_ARGS(l_errl));

                // Capture error and continue to next OCMB
                captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
            }
            else
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "SUCCESS : exp_check_for_ready "
                          "completed ok");

                size_t size = 0;

                TRACFCOMP(g_trac_isteps_trace,
                          "Read IDEC from OCMB 0x%.8X",
                          get_huid(l_ocmb));

                // This write gets translated into a read of the explorer chip
                // in the device driver. First, a read of the chip's IDEC
                // register occurs then ATTR_EC, ATTR_HDAT_EC, and ATTR_CHIP_ID
                // are set with the values found in that register. So, this
                // deviceWrite functions more as a setter for an OCMB target's
                // attributes.
                // Pass 2 as a va_arg to signal the ocmbIDEC function to execute
                // phase 2 of its read process.
                const uint64_t Phase2 = 2;
                l_errl = DeviceFW::deviceWrite(l_ocmb,
                                   nullptr,
                                   size,
                                   DEVICE_IDEC_ADDRESS(),
                                   Phase2);
                if (l_errl)
                {
                    // read of ID/EC failed even though we THOUGHT we were
                    // present.
                    TRACFCOMP(g_trac_isteps_trace,
                              "ERROR : call_ocmb_check_for_ready HWP(): "
                              "read IDEC failed on target 0x%08X (eid 0x%X)."
                              TRACE_ERR_FMT,
                              get_huid(l_ocmb),
                              l_errl->eid(),
                              TRACE_ERR_ARGS(l_errl));

                    // Capture error and continue to next OCMB
                    captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
                }
            }
        }

        // Grab informational Explorer logs (early IPL = true)
        EXPSCOM::createExplorerLogs(l_functionalOcmbChipList, true);
    }

    // Loop thru the list of processors and send the OCMB config info to SBE
    for (auto &l_procTarget: functionalProcChipList)
    {
        l_errl = SBEIO::psuSendSbeOcmbConfig(l_procTarget);

        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"ERROR : call_proc_ocmb_enable HWP(): "
                      "psuSendSbeOcmbConfig failed for target 0x%.08X."
                      TRACE_ERR_FMT,
                      get_huid(l_procTarget),
                      TRACE_ERR_ARGS(l_errl));

            // Commit the error and not fail this istep due to this failure
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(g_trac_isteps_trace,
                      INFO_MRK"SUCCESS : call_proc_ocmb_enable HWP(): "
                      "psuSendSbeOcmbConfig completed ok for target 0x%.08X.",
                      get_huid(l_procTarget));
        }
    } // for (auto &l_procTarget: functionalProcChipList)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_ocmb_check_for_ready");
    return l_StepError.getErrorHandle();
}

};
