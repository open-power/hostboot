/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/translateTarget.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
 *  @file translateTarget.C
 *
 *  @brief Contains code that translates a host interface target to a
 *      Hostboot target.  This lookup uses a memoizer to increase
 *      lookup performance.
 */

#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/trace.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/targplatreasoncodes.H>
#include <runtime/customize_attrs_for_payload.H>
#include <arch/pirformat.H>
#include <targeting/translateTarget.H>
#include <map>
#include <util/memoize.H>
#include <util/runtime/util_rt.H>
#include <sys/internode.h>

extern trace_desc_t* g_trac_hbrt;
using namespace TARGETING;

namespace RT_TARG
{


/**
 *  @brief API documentation same as for getHbTarget; this just implements the
 *      core logic (i.e. called when the memoizer doesn't have a cached answer)
 *
 *  @param[in] i_rtTargetId Runtime target ID
 *  @param[out] o_pTarget Equivalent TARGETING::Target
 *
 *  @return errlHndl_t Error log handle which is nullptr on success, !nullptr
 *      otherwise
 */
errlHndl_t _getHbTarget(
    const rtChipId_t          i_rtTargetId,
          TARGETING::Target*& o_pTarget)
{
    errlHndl_t pError = nullptr;

    do
    {
        // Don't even attempt the lookup if the unknown ID is used
        TARGETING::TargetHandle_t pTarget = nullptr;
        if(i_rtTargetId != RUNTIME::HBRT_HYP_ID_UNKNOWN)
        {
#ifdef __HOSTBOOT_RUNTIME
            uint8_t maxNodeId =
                TARGETING::targetService().getNumInitializedNodes();
            for(uint8_t nodeId=NODE0; nodeId<maxNodeId; ++nodeId)
            {
                TRACFCOMP( g_trac_targeting, "Node %d beginning target %p",
                nodeId,
                *(TARGETING::targetService().begin(nodeId)));

                for (TARGETING::TargetIterator pIt =
                        TARGETING::targetService().begin(nodeId);
                     pIt != TARGETING::targetService().end();
                     ++pIt)
                {
#else
                for (TARGETING::TargetIterator pIt =
                        TARGETING::targetService().begin();
                     pIt != TARGETING::targetService().end();
                     ++pIt)
                {

#endif
                    auto rtTargetId = RUNTIME::HBRT_HYP_ID_UNKNOWN;
                    if( (*pIt != nullptr)
                       &&  ((*pIt)->tryGetAttr<
                               TARGETING::ATTR_HBRT_HYP_ID>(rtTargetId))
                       && (rtTargetId == i_rtTargetId))
                    {
                        pTarget = (*pIt);
                        break;
                    }
                }

#ifdef __HOSTBOOT_RUNTIME
                if(pTarget)
                {
                    break;
                }
            }
#endif
        }

        if(pTarget == nullptr)
        {
            TRACFCOMP( g_trac_targeting, ERR_MRK
                "Can't find targeting target for runtime target ID of "
                "0x%16llX",
                i_rtTargetId);
            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_TRANSLATE_TARGET
             * @reasoncode   TARGETING::TARG_RC_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1    Runtime target ID
             * @devdesc      Can't find targeting target for given runtime
             *               target ID
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TARGETING::TARG_TRANSLATE_TARGET,
                TARGETING::TARG_RC_TARGET_TYPE_NOT_SUPPORTED,
                i_rtTargetId,
                0,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        }

        o_pTarget = pTarget;

    } while(0);

    return pError;
}

errlHndl_t getHbTarget(
    const rtChipId_t          i_rtTargetId,
          TARGETING::Target*& o_pTarget)
{
      return Util::Memoize::memoize<errlHndl_t>(_getHbTarget,i_rtTargetId,o_pTarget);
}

}; // End namespace RT_TARG
