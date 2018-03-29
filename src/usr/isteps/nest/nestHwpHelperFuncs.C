/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nest/nestHwpHelperFuncs.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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

/******************************************************************************/
// Includes
/******************************************************************************/
#include "nestHwpHelperFuncs.H"

//  STD support
#include <map>

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace

//  Targeting support
#include <fapi2_target.H>              // fapi2::Target
#include <target.H>                    // TARGETING::Target

//  Error handling support
#include <istepHelperFuncs.H>          // captureError
#include <errl/errlentry.H>            // errlHndl_t

//  HWP call support
#include <fapi2/plat_hwp_invoker.H>    // FAPI_INVOKE_HWP
#include <p9_chiplet_enable_ridi.H>
#include <p9_chiplet_scominit.H>
#include <p9_psi_scominit.H>
#include <p9_npu_scominit.H>
#include <p9_io_obus_scominit.H>
#include <p9_xbus_enable_ridi.H>
#include <p9_fbc_eff_config_links.H>
#include <p9_sys_chiplet_scominit.H>
#include <p9_chiplet_fabric_scominit.H>

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
        { P9_CHIPLET_ENABLE_RIDI, "p9_chiplet_enable_ridi"},
        { P9_CHIPLET_FABRIC_SCOMINIT, "p9_chiplet_fabric_scominit" },
        { P9_CHIPLET_SCOMINIT, "p9_chiplet_scominit" },
        { P9_FBC_EFF_CONFIG_LINKS_T_F, "p9_fbc_eff_config_links" },
        { P9_FBC_EFF_CONFIG_LINKS_F_T, "p9_fbc_eff_config_links" },
        { P9_IO_OBUS_SCOMINIT, "p9_io_obus_scominit" },
        { P9_NPU_SCOMINIT, "p9_npu_scominit" },
        { P9_PSI_SCOMINIT, "p9_psi_scominit" },
        { P9_SYS_CHIPLET_SCOMINIT, "p9_sys_chiplet_scominit" },
        { P9_XBUS_ENABLE_RIDI, "p9_xbus_enable_ridi" },
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

    // Get a list of all the processors in the system
    TARGETING::TargetHandleList l_targetList;
    if (TARGETING::TYPE_PROC == i_targetType)
    {
        getAllChips(l_targetList, i_targetType);
    }
    else if (TARGETING::TYPE_OBUS == i_targetType)
    {
        getAllChiplets(l_targetList, i_targetType);
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

            if (P9_XBUS_ENABLE_RIDI == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_xbus_enable_ridi,
                                l_fapi2Target);
            }
            else if (P9_CHIPLET_ENABLE_RIDI == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_chiplet_enable_ridi,
                                l_fapi2Target);
            }
            else if (P9_CHIPLET_SCOMINIT == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_chiplet_scominit,
                                l_fapi2Target);
            }
            else if (P9_PSI_SCOMINIT == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_psi_scominit,
                                l_fapi2Target);
            }
            else if (P9_NPU_SCOMINIT == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_npu_scominit,
                                l_fapi2Target);
            }
            else if (P9_FBC_EFF_CONFIG_LINKS_F_T == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_fbc_eff_config_links,
                                l_fapi2Target,
                                SMP_ACTIVATE_PHASE2, // P9 build SMP operation
                                false,  // process electrical
                                true);  // process optical
            }
            else if (P9_FBC_EFF_CONFIG_LINKS_T_F == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_fbc_eff_config_links,
                                l_fapi2Target,
                                SMP_ACTIVATE_PHASE1, // P9 build SMP operation
                                true,    // process electrical
                                false);  // process optical
            }
            else if (P9_SYS_CHIPLET_SCOMINIT == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_sys_chiplet_scominit,
                                l_fapi2Target);
            }
            else if (P9_CHIPLET_FABRIC_SCOMINIT == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_chiplet_fabric_scominit,
                                l_fapi2Target);
            }
            else
            {
                TRACFCOMP(g_trac_isteps_trace, "ERROR: Invalid/Uknown HWP call");
                break;
            }
        }  // end if (TARGETING::TYPE_PROC == i_targetType)
        // Call HWP calls for chiplets (target type: TYPE_OBUS)
        else if (TARGETING::TYPE_OBUS == i_targetType)
        {
            // Get a FAPI2 target of type OBUS
            const fapi2::Target<fapi2::TARGET_TYPE_OBUS>l_fapi2Target(l_target);

            if (P9_IO_OBUS_SCOMINIT == i_hwpCall)
            {
                FAPI_INVOKE_HWP(l_err,
                                p9_io_obus_scominit,
                                l_fapi2Target);
            }
            else
            {
                TRACFCOMP(g_trac_isteps_trace,"ERROR: Invalid/Uknown HWP call");
                break;
            }
        }  // end else if (TARGETING::TYPE_OBUS == i_targetType)
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
                  "%s: %s HWP returned %s with target HUID 0x%.8X",
                  l_errorSuccesStr,
                  l_hwpCallStr,
                  (l_err ? "an error" : "success"),
                  TARGETING::get_huid(l_target));

        if (l_err)
        {
            // Capture error and continue
            captureError(l_err,
                         o_stepError,
                         i_componentId,
                         l_target);
        }
    } // end for (const auto & l_target: l_targetList)

    TRACFCOMP(g_trac_isteps_trace,
              EXIT_MRK"fapiHWPCallWrapper (%s) exit", l_hwpCallStr);
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

