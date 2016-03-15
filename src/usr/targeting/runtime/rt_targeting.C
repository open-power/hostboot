/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/rt_targeting.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>
#include <targeting/common/targreasoncodes.H>
#include <arch/pirformat.H>
#include <runtime/customize_attrs_for_payload.H>
#include <runtime/rt_targeting.H>
#include <map>
#include <util/memoize.H>

using namespace TARGETING;

namespace RT_TARG
{

errlHndl_t getRtTarget(
    const TARGETING::Target* i_pTarget,
          rtChipId_t&        o_rtTargetId)
{
    errlHndl_t pError = NULL;

    do
    {
        if(i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* masterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(masterProcChip);
            i_pTarget = masterProcChip;
        }

        auto hbrtHypId = RUNTIME::HBRT_HYP_ID_UNKNOWN;
        if(   (!i_pTarget->tryGetAttr<TARGETING::ATTR_HBRT_HYP_ID>(hbrtHypId))
           || (hbrtHypId == RUNTIME::HBRT_HYP_ID_UNKNOWN))
        {
            auto huid = get_huid(i_pTarget);
            auto targetingTargetType =
                i_pTarget->getAttr<TARGETING::ATTR_TYPE>();
            TRACFCOMP(g_trac_targeting, ERR_MRK
                "Targeting target type of 0x%08X not supported. "
                "HUID: 0x%08X",
                targetingTargetType,
                huid);
            /*@
             * @errortype
             * @moduleid    TARG_RT_GET_RT_TARGET
             * @reasoncode  TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1   Target's HUID
             * @userdata2   target's targeting type
             * @devdesc     Targeting target's type not supported by runtime
             *              code
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                TARGETING::TARG_RT_GET_RT_TARGET,
                TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                huid,
                targetingTargetType,
                true);

            ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
                addToLog(pError);
        }

        o_rtTargetId = hbrtHypId;

    } while(0);

    return pError;
}

/**
 *  @brief API documentation same as for getHbTarget; this just implements the
 *      core logic (i.e. called when the memoizer doesn't have a cached answer)
 */
errlHndl_t _getHbTarget(
    const rtChipId_t          i_rtTargetId,
          TARGETING::Target*& o_target)
{
    errlHndl_t pError = NULL;

    do
    {
        // Don't even attempt the lookup if the unknown ID is used
        TARGETING::TargetHandle_t pTarget = NULL;
        if(i_rtTargetId != RUNTIME::HBRT_HYP_ID_UNKNOWN)
        {
            for (TARGETING::TargetIterator pIt =
                    TARGETING::targetService().begin();
                 pIt != TARGETING::targetService().end();
                 ++pIt)
            {
                auto rtTargetId = RUNTIME::HBRT_HYP_ID_UNKNOWN;
                if(   ((*pIt)->tryGetAttr<
                           TARGETING::ATTR_HBRT_HYP_ID>(rtTargetId))
                   && (rtTargetId == i_rtTargetId))
                {
                    pTarget = (*pIt);
                    break;
                }
            }
        }

        if(pTarget == NULL)
        {
            TRACFCOMP( g_trac_targeting, ERR_MRK
                "Can't find targeting target for runtime target ID of "
                "0x%16llX",
                i_rtTargetId);
            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_RT_GET_HB_TARGET
             * @reasoncode   TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1    Runtime target ID
             * @userdata2    0
             * @devdesc      Can't find targeting target for given runtime
             *               target ID
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                TARGETING::TARG_RT_GET_HB_TARGET,
                TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                i_rtTargetId,
                0,
                true);
        }

        o_target = pTarget;

    } while(0);

    return pError;
}

errlHndl_t getHbTarget(
    const rtChipId_t          i_rtTargetId,
          TARGETING::Target*& o_target)
{
      return Util::Memoize::memoize(_getHbTarget,i_rtTargetId,o_target);
}

}; // End namespace RT_TARG
