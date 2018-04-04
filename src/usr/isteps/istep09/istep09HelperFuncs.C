/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/istep09HelperFuncs.C $                 */
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

#include "istep09HelperFuncs.H"

//  STD support
#include <map>

//  Support for all istep common functions
#include "istepHelperFuncs.H"          // captureError

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace

//  Targeting support
#include <fapi2_target.H>              // fapi2::Target
#include <target.H>                    // Target

//  Error handling support
#include <errl/errlentry.H>            // errlHndl_t

//  HWP call support
#include <fapi2/plat_hwp_invoker.H>    // FAPI_INVOKE_HWP
#include <p9_io_xbus_pre_trainadv.H>   // p9_io_xbus_pre_trainadv
#include <p9_io_xbus_post_trainadv.H>  // p9_io_xbus_post_trainadv
#include <p9_io_obus_dccal.H>          // p9_io_obus_dccal
#include <p9_io_obus_pre_trainadv.H>   // p9_io_obus_pre_trainadv
#include <p9_io_obus_linktrain.H>      // p9_io_obus_link_train
#include <p9_io_obus_post_trainadv.H>  // p9_io_obus_post_trainadv

namespace ISTEP_09
{
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace EDI_EI_INITIALIZATION;
using namespace TARGETING;

 /**
 *  hwpCallToString
 */
const char * hwpCallToString( HWP_CALL_TYPE i_hwpCall )
{
    const static std::map<HWP_CALL_TYPE, const char*> hwpCallToStringMap =
    {
        { P9_IO_XBUS_PRE_TRAINADV, "p9_io_xbus_pre_trainadv" },
        { P9_IO_XBUS_POST_TRAINADV, "p9_io_xbus_post_trainadv" },
        { P9_IO_OBUS_PRE_TRAINADV, "p9_io_obus_pre_trainadv" },
        { P9_IO_OBUS_POST_TRAINADV, "p9_io_obus_post_trainadv" },
        { P9_IO_OBUS_LINKTRAIN, "p9_io_obus_linktrain" },
        { P9_IO_OBUS_DCCAL, "p9_io_obus_dccal" },
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
 *   trainXbus
 */
uint32_t trainXbus(HWP_CALL_TYPE   i_hwpCall,
                   IStepError     &o_stepError,
                   compId_t        i_componentId,
                   const Target*   i_firstTarget,
                   const Target*   i_secondTarget)
{
    // Cache the HWP call in string form
    const char* l_hwpCallStr = hwpCallToString(i_hwpCall);

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"trainXbus (%s) entry", l_hwpCallStr);

    // Make sure target values are valid
    assert(nullptr != i_firstTarget, "The first target cannot be NULL");
    assert(nullptr != i_secondTarget, "The second target cannot be NULL");

    // An error handler
    errlHndl_t l_err(nullptr);

    // Enumerate the train failures that occur
    uint32_t l_numberOfTrainFailures(0);

    // Create Fapi2 targets from the given targets
    const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
        l_firstFapi2Target(
        (const_cast<Target*>(i_firstTarget)));

    const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
        l_secondFapi2Target(
        (const_cast<Target*>(i_secondTarget)));

    // group is either 0 or 1,
    // need to train both groups and allow for them to differ
    uint8_t l_this_group(0), l_connected_group(0);
    for (uint8_t l_group_loop = 0; l_group_loop < 4; ++l_group_loop)
    {
        l_this_group = l_group_loop / 2;      // 0, 0, 1, 1
        l_connected_group = l_group_loop % 2; // 0, 1, 1, 0

        TRACFCOMP(g_trac_isteps_trace,
                  "Running %s HWP on "
                  "this XBUS target 0x%.8X (group %d) and connected "
                  "target 0x%.8X (group %d)",
                  l_hwpCallStr,
                  get_huid(i_firstTarget),
                  l_this_group,
                  get_huid(i_secondTarget),
                  l_connected_group );

        if (P9_IO_XBUS_PRE_TRAINADV == i_hwpCall)
        {
            FAPI_INVOKE_HWP(l_err,
                            p9_io_xbus_pre_trainadv,
                            l_firstFapi2Target,
                            l_this_group,
                            l_secondFapi2Target,
                            l_connected_group );
        }
        else if (P9_IO_XBUS_POST_TRAINADV == i_hwpCall)
        {
            FAPI_INVOKE_HWP(l_err,
                            p9_io_xbus_post_trainadv,
                            l_firstFapi2Target,
                            l_this_group,
                            l_secondFapi2Target,
                            l_connected_group );
        }
        else
        {
            ++l_numberOfTrainFailures;
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR: Invalid/Uknown XBUS HWP call");
            break;
        }

        TRACFCOMP(g_trac_isteps_trace,
                  "%s : XBUS connection %s, "
                  "target 0x%.8X using group %d, connected target 0x%.8X "
                  "using group %d",
                  (l_err ? "ERROR" : "SUCCESS"),
                  l_hwpCallStr,
                  get_huid(i_firstTarget),
                  l_this_group,
                  get_huid(i_secondTarget),
                  l_connected_group );

        if (l_err)
        {
            ++l_numberOfTrainFailures;
            TargetHandleList l_targets =
                  { const_cast<TargetHandle_t>(i_firstTarget),
                    const_cast<TargetHandle_t>(i_secondTarget) };
            // Capture error and continue
            captureError(l_err,
                         o_stepError,
                         i_componentId,
                         l_targets);
        }
    }  // end for (l_group_loop = 0; l_group_loop < 4; l_group_loop++)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"trainXbus (%s) exit", l_hwpCallStr);

    return l_numberOfTrainFailures;
}

/**
 *   trainObus
 */
uint32_t trainObus(HWP_CALL_TYPE   i_hwpCall,
                   IStepError     &o_stepError,
                   compId_t        i_componentId,
                   const Target*   i_firstTarget,
                   const Target*   i_secondTarget)
{

    // Cache the HWP call in string form
    const char* l_hwpCallStr = hwpCallToString(i_hwpCall);

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"trainObus (%s) entry", l_hwpCallStr);

    // Make sure target values are valid
    assert(nullptr != i_firstTarget, "The first target cannot be NULL");
    assert(nullptr != i_secondTarget, "The second target cannot be NULL");

    // An error handler
    errlHndl_t l_err(nullptr);

    // Enumerate the train failures that occur
    uint32_t l_numberOfTrainFailures(0);

    // Put targets in a container that can be traversed
    std::vector<const Target*> l_targets =
                { i_firstTarget,  i_secondTarget };

    // Iterate over the targets
    for (const auto l_target: l_targets)
    {
        // Convert current target to a fapi2 target
        const fapi2::Target <fapi2::TARGET_TYPE_OBUS>
            l_fapi2Target
            (const_cast<Target*>(l_target));

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running %s HWP on this OBUS target 0x%.8X",
                   l_hwpCallStr,
                   l_target);

        // Call the appropriate HWP method
        if (P9_IO_OBUS_DCCAL == i_hwpCall)
        {
            // I have no idea what this value means or how it came to be this
            // particular value.  It was replicated from
            // /fips920/src/hwsv/server/services/hwco/hwcoNodeSMP.C
            uint32_t l_laneVector = 0x00FFFFFF;
            FAPI_INVOKE_HWP(l_err,
                            p9_io_obus_dccal,
                            l_fapi2Target,
                            l_laneVector);
        }
        else if (P9_IO_OBUS_PRE_TRAINADV == i_hwpCall)
        {
            FAPI_INVOKE_HWP(l_err,
                            p9_io_obus_pre_trainadv,
                            l_fapi2Target);
        }
        else if (P9_IO_OBUS_LINKTRAIN == i_hwpCall)
        {
            FAPI_INVOKE_HWP(l_err,
                            p9_io_obus_linktrain,
                            l_fapi2Target);
        }
        else if (P9_IO_OBUS_POST_TRAINADV == i_hwpCall)
        {
            FAPI_INVOKE_HWP(l_err,
                            p9_io_obus_post_trainadv,
                            l_fapi2Target);
        }
        else
        {
            ++l_numberOfTrainFailures;
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR: Invalid/Uknown OBUS HWP call");
            break;
        }

        TRACFCOMP(g_trac_isteps_trace,
                  "%s : OBUS connection %s, target 0x%.8X",
                  (l_err ? "ERROR" : "SUCCESS"),
                  l_hwpCallStr,
                  get_huid(l_target));

        if (l_err)
        {
            ++l_numberOfTrainFailures;
            // Capture error and continue
            captureError(l_err,
                         o_stepError,
                         HWPF_COMP_ID,
                         l_target);

            // Skip training of second end point if doing link train or dccal
            if ( (P9_IO_OBUS_LINKTRAIN == i_hwpCall) ||
                 (P9_IO_OBUS_DCCAL == i_hwpCall) ) break;
        }
    } // end for (const auto l_target: l_targets)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"trainObus (%s) exit", l_hwpCallStr);

    return l_numberOfTrainFailures;
}

/**
 *   trainBusHandler
 */
bool trainBusHandler(TYPE                     i_busType,
                     HWP_CALL_TYPE            i_hwpCall,
                     ISTEP_ERROR::IStepError &o_stepError,
                     compId_t                 i_componentId,
                     const TargetPairs_t     &i_pbusConnections)
{
    bool retSuccess = true;

    if (i_pbusConnections.empty())
    {
        TRACFCOMP(g_trac_isteps_trace, "Connection bus list is empty. "
                  "HWP call %s will not be called.",
                  hwpCallToString(i_hwpCall));
    }

    // Iterate over the pbus connections
    for (const auto & l_pbusConnection: i_pbusConnections)
    {
        TRACFCOMP(g_trac_isteps_trace, "Attempting to train %s %s on "
                  "bus connections 0x%.8X and 0x%.8X",
                  (i_busType == TYPE_OBUS ? "OBUS" : (i_busType == TYPE_XBUS ? "XBUS" : "")),
                  hwpCallToString(i_hwpCall),
                  get_huid(l_pbusConnection.first),
                  get_huid(l_pbusConnection.second));

        uint32_t l_numberOfTrainFailures(0);

        if (TYPE_OBUS == i_busType)
        {
            l_numberOfTrainFailures = trainObus(i_hwpCall,
                                                o_stepError,
                                                i_componentId,
                                                l_pbusConnection.first,
                                                l_pbusConnection.second);
        }
        else if (TYPE_XBUS == i_busType)
        {
            l_numberOfTrainFailures = trainObus(i_hwpCall,
                                                o_stepError,
                                                i_componentId,
                                                l_pbusConnection.first,
                                                l_pbusConnection.second);
        }
        else
        {
            ++l_numberOfTrainFailures;
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR: Invalid/Uknown BUS type");
        }

        if (l_numberOfTrainFailures)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "Running %s HWP resulted in %d errors",
                      hwpCallToString(i_hwpCall),
                      l_numberOfTrainFailures);

            retSuccess = false;
            // stop processing OBUS if encountered an error
            break;
        }
    }  // end  for (const auto & l_pbusConnection: i_pbusConnections)

    return retSuccess;
}


}  // end namespace ISTEP_09

