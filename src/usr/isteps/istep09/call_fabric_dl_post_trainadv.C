/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_dl_post_trainadv.C $       */
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
 *  @file call_fabric_dl_post_trainadv.C
 *
 *  Support file for IStep: fabric_dl_post_trainadv
 *   Advanced post training
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

// Error log
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>

// IStep-related
#include <isteps/hwpisteperror.H>
#include <istepHelperFuncs.H>
#include <pbusLinkSvc.H>

// Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>
#include <targeting/common/mfgFlagAccessors.H>

// FAPI
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

// HWP
#include <p10_fabric_dl_post_trainadv.H>

namespace ISTEP_09
{

using namespace ISTEP;
using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

// Helper function for entry point below; calls HWP on arguments and collects
// error.
static void invoke_hwp(fapi2::Target<fapi2::TARGET_TYPE_IOHS> i_iohsA,
                       fapi2::Target<fapi2::TARGET_TYPE_IOHS> i_iohsB,
                       IStepError& i_stepError)
{
    errlHndl_t l_errl = nullptr;
    FAPI_INVOKE_HWP(l_errl,
                    p10_fabric_dl_post_trainadv,
                    i_iohsA,
                    i_iohsB);

    if (l_errl)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "call_fabric_dl_post_trainadv: p10_fabric_dl_post_trainadv failed on "
                  "IOHS HUIDs (0x%08x, 0x%08x)"
                  TRACE_ERR_FMT,
                  get_huid(i_iohsA.get()),
                  get_huid(i_iohsB.get()),
                  TRACE_ERR_ARGS(l_errl));

        captureError(l_errl, i_stepError, HWPF_COMP_ID, { i_iohsA.get(), i_iohsB.get() });
    }
}

void* call_fabric_dl_post_trainadv(void* const io_pArgs)
{
    IStepError l_stepError;
    TRACFCOMP(g_trac_isteps_trace, "call_fabric_dl_post_trainadv entry");

    // Get intranode buses
    EDI_EI_INITIALIZATION::TargetPairs_t l_xbuses, l_abuses;

    {
        const bool EXCLUDE_DUPLICATES = true; // flag for getPbusConnections

        errlHndl_t l_xbusError =
            EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                l_xbuses,
                IOHS_CONFIG_MODE_SMPX,
                EXCLUDE_DUPLICATES);

        errlHndl_t l_abusError =
            EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                l_abuses,
                IOHS_CONFIG_MODE_SMPA,
                EXCLUDE_DUPLICATES);

        if (l_xbusError || l_abusError)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_fabric_dl_post_trainadv: getPbusConnections failed");

            captureError(l_xbusError, l_stepError, HWPF_COMP_ID);
            captureError(l_abusError, l_stepError, HWPF_COMP_ID);
        }
    }

    // Iterate over every unique pair of IOHS targets and call the HWP on them.
    for (const auto l_pair : l_xbuses)
    {
        invoke_hwp({ l_pair.first }, { l_pair.second }, l_stepError);
    }

    for (const auto l_pair : l_abuses)
    {
        invoke_hwp({ l_pair.first }, { l_pair.second }, l_stepError);
    }

    TRACFCOMP( g_trac_isteps_trace, "call_fabric_dl_post_trainadv exit" );

    return l_stepError.getErrorHandle();
}

}
