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

#include <runtime/rt_targeting.H>

using namespace TARGETING;

namespace RT_TARG
{

errlHndl_t procRtTargetError(const TARGETING::Target * i_target)
{
    errlHndl_t err = NULL;
    uint32_t huid = get_huid(i_target);
    TRACFCOMP(g_trac_targeting,ERR_MRK
              "No proc target found for target. huid: %08x",
              huid);
    /*@
     * @errortype
     * @moduleid     TARG_RT_GET_RT_TARGET
     * @reasoncode   TARG_RT_NO_PROC_TARGET
     * @userdata1    HUID of the UNIT target
     * @devdesc      No processor target found for the UNIT
     */
    err =
        new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                TARGETING::TARG_RT_GET_RT_TARGET,
                                TARGETING::TARG_RT_NO_PROC_TARGET,
                                huid,
                                0,
                                true);

    ERRORLOG::ErrlUserDetailsTarget(i_target,"Runtime Target").
        addToLog(err);

    return err;
}


errlHndl_t getRtTarget(const TARGETING::Target* i_target,
                       rtChipId_t &o_chipId)
{
    errlHndl_t err = NULL;

    do
    {
        if(i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* masterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(masterProcChip);

            i_target = masterProcChip;
        }

        TARGETING::TYPE target_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

        if(target_type == TARGETING::TYPE_PROC)
        {
            uint32_t fabId =
                i_target->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();

            uint32_t procPos =
                i_target->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

            o_chipId = PIR_t::createChipId( fabId, procPos );
        }
        else if( target_type == TARGETING::TYPE_MEMBUF)
        {
            //MEMBUF
            // 0b1000.0000.0000.0000.0000.0GGG.GCCC.MMMM
            // where GGGG is group, CCC is chip, MMMM is memory channel
            //
            TARGETING::TargetHandleList targetList;

            getParentAffinityTargets(targetList,
                                    i_target,
                                    TARGETING::CLASS_UNIT,
                                    TARGETING::TYPE_MCS);

            if( targetList.empty() )
            {
                uint32_t huid = get_huid(i_target);
                TRACFCOMP(g_trac_targeting,ERR_MRK
                          "getRtTarget: No target found for huid: %08x",
                          huid);
                /*@
                 * @errortype
                 * @moduleid     TARG_RT_GET_RT_TARGET
                 * @reasoncode   TARG_RT_UNIT_TARGET_NOT_FOUND
                 * @userdata1    HUID of given MEMBUF target
                 * @devdesc      No MCS target(s) found for the
                 *               given MEMBUF target
                 */
                err =
                    new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     TARGETING::TARG_RT_GET_RT_TARGET,
                     TARGETING::TARG_RT_UNIT_TARGET_NOT_FOUND,
                     huid,
                     0,
                     true);

                ERRORLOG::ErrlUserDetailsTarget(i_target,"Runtime Target").
                    addToLog(err);

                break;
            }

            TARGETING::Target * target = targetList[0];
            uint32_t pos = target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            targetList.clear();
            getParentAffinityTargets(targetList,
                                     target,
                                     TARGETING::CLASS_CHIP,
                                     TARGETING::TYPE_PROC);

            if(targetList.empty())
            {
                err = procRtTargetError(target);
                break;
            }

            TARGETING::Target * proc_target = targetList[0];

            err = getRtTarget(proc_target, o_chipId);
            if(err)
            {
                break;
            }

            o_chipId = (o_chipId << MEMBUF_ID_SHIFT);
            o_chipId += pos;
            o_chipId |= MEMBUF_TYPE;
        }
        else if(target_type == TARGETING::TYPE_CORE)
        {
            // CORE
            // 0b0100.0000.0000.0000.0000.GGGG.CCCP.PPPP
            // GGGG is group, CCC is chip, PPPPP is core
            uint32_t pos = i_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            const TARGETING::Target * proc_target = getParentChip(i_target);
            if(proc_target == NULL)
            {
                err =  procRtTargetError(i_target);
                break;
            }

            err = getRtTarget(proc_target, o_chipId);
            if(err)
            {
                break;
            }

            o_chipId = PIR_t::createCoreId(o_chipId,pos);
            o_chipId |= CORE_TYPE;
        }
        else
        {
            uint32_t huid = get_huid(i_target);
            TRACFCOMP(g_trac_targeting,ERR_MRK
                      "Runtime target type %d not supported."
                      " huid: %08x",
                      target_type,
                      huid);
            /*@
             * @errortype
             * @moduleid     TARG_RT_GET_RT_TARGET
             * @reasoncode   TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1    HUID of the target
             * @userdata2    target_type
             * @devdesc      Target type not supported by HBRT.
             */
            err =
                new ERRORLOG::ErrlEntry
                (ERRORLOG::ERRL_SEV_INFORMATIONAL,
                 TARGETING::TARG_RT_GET_RT_TARGET,
                 TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                 huid,
                 target_type,
                 true);

            ERRORLOG::ErrlUserDetailsTarget(i_target,"Runtime Target").
                addToLog(err);
        }
    } while(0);

    return err;
}


errlHndl_t getHbTarget(rtChipId_t i_rt_chip_id,
                       TARGETING::Target *& o_target)
{
    errlHndl_t err = NULL;
    o_target = NULL;

    do
    {
        uint64_t idType = i_rt_chip_id & CHIPID_TYPE_MASK;

        if(0 != (idType ==  MEMBUF_TYPE))
        {
            //membuf
            uint64_t proc_chip_id = i_rt_chip_id & ~CHIPID_TYPE_MASK;
            uint32_t unitPos = proc_chip_id & MEMBUF_ID_MASK;
            proc_chip_id >>= MEMBUF_ID_SHIFT;
            TARGETING::Target * proc = NULL;
            TARGETING::Target * msc = NULL;

            err = getHbTarget(proc_chip_id, proc);
            if(err)
            {
                break;
            }

            PredicateCTM mcsFilter(CLASS_UNIT, TYPE_MCS);
            PredicateAttrVal<ATTR_CHIP_UNIT> unitAttr(unitPos);
            PredicatePostfixExpr mcsUnitFilter;
            mcsUnitFilter.push(&mcsFilter).push(&unitAttr).And();

            TargetHandleList target_list;

            targetService().getAssociated( target_list,
                                           proc,
                                           TargetService::CHILD_BY_AFFINITY,
                                           TargetService::ALL,
                                           &mcsUnitFilter);

            // should only be one result
            if(target_list.size())
            {
                msc = target_list[0];

                target_list.clear();


                getChildAffinityTargets( target_list,
                                         msc,
                                         TARGETING::CLASS_CHIP,
                                         TARGETING::TYPE_MEMBUF);

                // should only be one result
                if(target_list.size())
                {
                    o_target = target_list[0];
                }
            }

            if(o_target == NULL) // no mcs and/or membuf found
            {
                TRACFCOMP(g_trac_targeting,ERR_MRK "getHbTarget: "
                          "MCS or MEMBUF target not found for chipId %08lx",
                          i_rt_chip_id);
                /*@
                 * @errortype
                 * @moduleid     TARGETING::TARG_RT_GET_HB_TARGET
                 * @reasoncode   TARG_RT_UNIT_TARGET_NOT_FOUND
                 * @userdata1    Runtime chip Id
                 * @devdesc      No MCS or MEMBUF target(s) found for the
                 *               given target
                 */
                err =
                    new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     TARGETING::TARG_RT_GET_HB_TARGET,
                     TARGETING::TARG_RT_UNIT_TARGET_NOT_FOUND,
                     i_rt_chip_id,
                     0,
                     true);
            }

        }
        else if(0 != (idType == CORE_TYPE))
        {
            uint64_t core_id = i_rt_chip_id & ~CHIPID_TYPE_MASK;
            uint32_t unitPos = PIR_t::coreFromCoreId(core_id);
            uint64_t chip_id = PIR_t::chipFromCoreId(core_id);
            TARGETING::Target * proc = NULL;

            err = getHbTarget(chip_id, proc);
            if(err)
            {
                break;
            }

            PredicateCTM exFilter(CLASS_UNIT, TYPE_CORE);
            PredicateAttrVal<ATTR_CHIP_UNIT> unitAttr(unitPos);
            PredicatePostfixExpr exUnitFilter;
            exUnitFilter.push(&exFilter).push(&unitAttr).And();

            TargetHandleList target_list;

            targetService().getAssociated( target_list,
                                           proc,
                                           TargetService::CHILD,
                                           TargetService::ALL,
                                           &exUnitFilter);

            //Should only be one result
            if(target_list.size())
            {
                o_target = target_list[0];
            }
            // o_target not found caught below..
        }
        else if( idType == PROC_TYPE)
        {
            // assume processor chip
            uint32_t fabId = PIR_t::groupFromChipId(i_rt_chip_id);
            uint32_t procPos = PIR_t::chipFromChipId(i_rt_chip_id);

            PredicateCTM procFilter(CLASS_CHIP, TYPE_PROC);
            PredicateAttrVal<ATTR_FABRIC_GROUP_ID> nodeFilter(fabId);
            PredicateAttrVal<ATTR_FABRIC_CHIP_ID> chipFilter(procPos);

            PredicatePostfixExpr theProc, theAttrs;
            theAttrs.push(&nodeFilter).push(&chipFilter).And();
            theProc.push(&procFilter).push(&theAttrs).And();

            TargetRangeFilter procRange(targetService().begin(),
                                        targetService().end(),
                                        &theProc);

            if(procRange)
            {
                o_target = *procRange;
            }
        }

        if(!err && o_target == NULL)
        {
            TRACFCOMP( g_trac_targeting,
                       ERR_MRK"Can't find HB target for chipId 0x%lx",
                       i_rt_chip_id);
            /*@
             * @errortype
             * @moduleid     TARGETING::TARG_RT_GET_HB_TARGET
             * @reasoncode   TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1    runtime procId
             * @userdata2    0
             * @devdesc      Can't find HB Target for chipId provided.
             */
            err =
                new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                 TARGETING::TARG_RT_GET_HB_TARGET,
                 TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                 i_rt_chip_id,
                 0,
                 true);

        }
    } while(0);

    return err;
}

}; // namespace
