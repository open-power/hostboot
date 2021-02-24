/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_dl_setup_training.C $      */
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
 *  @file call_fabric_dl_setup_training.C
 *
 *  Support file for IStep: fabric_dl_setup_training
 *   Setup training on internal node buses
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

// Standard library
#include <stdint.h>

// Trace
#include <trace/interface.H>

// Initservice
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>

// Error logs
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>

// IStep-related
#include <isteps/hwpisteperror.H>
#include <istepHelperFuncs.H>
#include <pbusLinkSvc.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/trace.H>

// FAPI
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

// HWP
#include <p10_fabric_dl_setup_linktrain.H>

namespace ISTEP_09
{

using namespace ISTEP;
using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace HWAS;

// Helper function for entry point below; invokes HWP on argument and collects error
static void invoke_hwp(fapi2::Target<fapi2::TARGET_TYPE_IOHS> i_iohs, IStepError& i_stepError)
{
    TRACFCOMP(g_trac_isteps_trace,
              "call_fabric_dl_setup_training: Invoking p10_fabric_dl_setup_linktrain on "
              "IOHS HUID=0x%08x",
              get_huid(i_iohs.get()));

    errlHndl_t l_errl = nullptr;
    FAPI_INVOKE_HWP(l_errl,
                    p10_fabric_dl_setup_linktrain,
                    i_iohs);

    if (l_errl)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_fabric_dl_setup_training: p10_fabric_dl_setup_linktrain failed on "
                  "IOHS HUID 0x%08x"
                  TRACE_ERR_FMT,
                  get_huid(i_iohs.get()),
                  TRACE_ERR_ARGS(l_errl));

        captureError(l_errl, i_stepError, HWPF_COMP_ID, i_iohs.get());
    }
}

void* call_fabric_dl_setup_training(void* const io_pArgs)
{
    IStepError l_stepError;
    TRACFCOMP(g_trac_isteps_trace, "call_fabric_dl_setup_training entry");

    EDI_EI_INITIALIZATION::TargetPairs_t l_xbuses, l_abuses;

    {
        const bool INCLUDE_DUPLICATES = false; // flag for getPbusConnections

        errlHndl_t l_xbusError =
            EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                l_xbuses,
                IOHS_CONFIG_MODE_SMPX,
                INCLUDE_DUPLICATES);

        errlHndl_t l_abusError =
            EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                l_abuses,
                IOHS_CONFIG_MODE_SMPA,
                INCLUDE_DUPLICATES);

        if (l_xbusError || l_abusError)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_fabric_dl_setup_training: getPbusConnections failed");

            captureError(l_xbusError, l_stepError, HWPF_COMP_ID);
            captureError(l_abusError, l_stepError, HWPF_COMP_ID);
        }
    }

    // For SMPGROUP targets, we train their parent IOHS. Use this map to keep
    // track of which IOHSes have already been trained.
    std::map<const Target*, bool> l_alreadyTrained;

    // Iterate over every bus target and call the HWP on each. The pairs are
    // duplicated (i.e. we have map[A] = B and map[B] = A), so we just iterate
    // the keys and ignore the values, and that way we get all the targets.
    for (const auto l_pair : l_xbuses)
    {
        const Target* l_train = l_pair.first;

        if (l_train->getAttr<ATTR_TYPE>() == TYPE_SMPGROUP)
        {
            l_train = getImmediateParentByAffinity(l_train);
        }

        if (l_alreadyTrained.find(l_train) != end(l_alreadyTrained))
        {
            continue;
        }

        l_alreadyTrained[l_train] = true;

        invoke_hwp({ l_train }, l_stepError);

        // Continue even when the HWP fails, so that we collect all the errors
        // and report them at the end all at once.
    }

    for (const auto l_pair : l_abuses)
    {
        const Target* l_train = l_pair.first;

        if (l_train->getAttr<ATTR_TYPE>() == TYPE_SMPGROUP)
        {
            l_train = getImmediateParentByAffinity(l_train);
        }

        if (l_alreadyTrained.find(l_train) != end(l_alreadyTrained))
        {
            continue;
        }

        l_alreadyTrained[l_train] = true;

        invoke_hwp({ l_train }, l_stepError);
    }

    TRACFCOMP( g_trac_isteps_trace, "call_fabric_dl_setup_training exit" );

    return l_stepError.getErrorHandle();
}

}
