/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nest/nestHwpHelperFuncs.C $                    */
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
 *  @file nestHwpHelperFuncs.C
 *
 *  Helper HWP functions
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include "nestHwpHelperFuncs.H"

//  STD support
#include <map>

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace

#include <pnor/pnorif.H>

//  Error handling support
#include <istepHelperFuncs.H>          // captureError
#include <errl/errlentry.H>            // errlHndl_t

#include <p10_fbc_eff_config_links.H>
#include <p10_chiplet_fabric_scominit.H>
#include <p10_io_iohs_firmask_save_restore.H>
#include <fapi2/plat_hwp_invoker.H>

namespace ISTEP
{
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;

// Size of string that contains "ERROR" or "SUCCESS" message
constexpr const int l_errorSuccesStrSize = 40;

 /**
 *
 *  hwpCallToString
 */
const char * hwpCallToString( HWP_CALL_TYPE i_hwpCall )
{
    const static std::map<HWP_CALL_TYPE, const char*> hwpCallToStringMap =
    {
        { P10_CHIPLET_FABRIC_SCOMINIT, "p10_chiplet_fabric_scominit" },
        { P10_FBC_EFF_CONFIG_LINKS_ELECTRICAL, "p10_fbc_eff_config_links" },
        { P10_FBC_EFF_CONFIG_LINKS_OPTICAL, "p10_fbc_eff_config_links" },
        { P10_IO_IOHS_FIRMASK_SAVE_RESTORE, "p10_io_iohs_firmask_save_restore" },
    };

    if (hwpCallToStringMap.count(i_hwpCall) > 0)
    {
        return hwpCallToStringMap.at(i_hwpCall);
    }
    else
    {
        return "";
    }
}

/**
 *  fapiHWPCallWrapper
 */
void fapiHWPCallWrapper(HWP_CALL_TYPE    i_hwpCall,
                        IStepError      &o_stepError,
                        compId_t         i_componentId,
                        TARGETING::TYPE  i_targetType)
{
    // Cache the HWP call in string form
    const char* l_hwpCallStr = hwpCallToString(i_hwpCall);

    TRACFCOMP(g_trac_isteps_trace,
              ENTER_MRK"fapiHWPCallWrapper (%s) entry", l_hwpCallStr);

    // An error handler
    errlHndl_t l_err(nullptr);
    TARGETING::TargetHandleList l_targetList;

    do {

        // Get a list of all the processors in the system
        if (TARGETING::TYPE_PROC == i_targetType)
        {
            getAllChips(l_targetList, i_targetType);
        }
        else
        {
            assert(0, "ERROR: Invalid target type %d", i_targetType);
        }

        if (l_targetList.empty())
        {
            TRACFCOMP(g_trac_isteps_trace, "Target list empty, no targets "
                      "found. HWP call %s will not be called", l_hwpCallStr);
        }
        // Loop through all processors including master
        for (const auto & l_target: l_targetList)
        {
            // A string to contain an error or success message, defaulted to success
            char l_errorSuccesStr[l_errorSuccesStrSize] = "SUCCESS";

            TRACFCOMP(g_trac_isteps_trace,
                      "Running %s HWP on target HUID %.8X",
                      l_hwpCallStr,
                      TARGETING::get_huid(l_target));

            // Call HWP calls for chips (target type: TYPE_PROC)
            if (TARGETING::TYPE_PROC == i_targetType)
            {
                // Get a FAPI2 target of type PROC
                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2Target(l_target);

                if (P10_FBC_EFF_CONFIG_LINKS_OPTICAL == i_hwpCall)
                {
                    FAPI_INVOKE_HWP(l_err,
                                    p10_fbc_eff_config_links,
                                    l_fapi2Target,
                                    SMP_ACTIVATE_PHASE2); // P10 build SMP operation
                }
                else if (P10_FBC_EFF_CONFIG_LINKS_ELECTRICAL == i_hwpCall)
                {
                    FAPI_INVOKE_HWP(l_err,
                                    p10_fbc_eff_config_links,
                                    l_fapi2Target,
                                    SMP_ACTIVATE_PHASE1); // P10 build SMP operation
                }
                else if (P10_CHIPLET_FABRIC_SCOMINIT == i_hwpCall)
                {
                    const bool l_train_internode = false,
                               l_train_intranode = true;

                    FAPI_INVOKE_HWP(l_err,
                                    p10_chiplet_fabric_scominit,
                                    l_fapi2Target,
                                    l_train_intranode,
                                    l_train_internode);
                }
                else if (P10_IO_IOHS_FIRMASK_SAVE_RESTORE == i_hwpCall)
                {
                    FAPI_INVOKE_HWP(l_err,
                                    p10_io_iohs_firmask_save_restore,
                                    l_fapi2Target, p10iofirmasksaverestore::SAVE);
                }
                else
                {
                    TRACFCOMP(g_trac_isteps_trace, "ERROR: Invalid/Unknown HWP call");
                    break;
                }
            }  // end if (TARGETING::TYPE_PROC == i_targetType)
            else
            {
               assert(0, "ERROR: Invalid target type %d", i_targetType);
            }


            // If an error ocurred with HWP call, setup error message
            if (l_err)
            {
                snprintf(l_errorSuccesStr, l_errorSuccesStrSize,
                         "ERROR 0x%.8X", l_err->plid());
            }

            TRACFCOMP(g_trac_isteps_trace,
                      "%s: %s HWP returned %s with target HUID 0x%.8X"
                      TRACE_ERR_FMT,
                      l_errorSuccesStr,
                      l_hwpCallStr,
                      (l_err ? "an error" : "success"),
                      get_huid(l_target),
                      TRACE_ERR_ARGS(l_err));

            if (l_err)
            {
                // Capture error and continue
                captureError(l_err,
                             o_stepError,
                             i_componentId,
                             l_target);
            }

        } // end for (const auto & l_target: l_targetList)

    } while (0);

    TRACFCOMP(g_trac_isteps_trace,
              EXIT_MRK"fapiHWPCallWrapper (%s) exit", l_hwpCallStr);
    return;
}

/**
 *  fapiHWPCallWrapperHandler
 */
bool fapiHWPCallWrapperHandler(HWP_CALL_TYPE    i_hwpCall,
                               IStepError      &o_stepError,
                               compId_t         i_componentId,
                               TARGETING::TYPE  i_targetType)
{
    bool l_retSuccess = true;

    fapiHWPCallWrapper(i_hwpCall, o_stepError, i_componentId, i_targetType);

    if (!o_stepError.isNull())
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "ERROR from %s", hwpCallToString(i_hwpCall));

        l_retSuccess = false;
    }

    return l_retSuccess;
}

};   // end namespace ISTEP
