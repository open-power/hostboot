/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/rt_targeting.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
            // use 0b0000.0000.0000.0000.0000.0000.00NN.NCCC:
            uint32_t fabId =
                i_target->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();

            uint32_t procPos =
                i_target->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

            o_chipId = (fabId << CHIPID_NODE_SHIFT) + procPos;
        }
        else if( target_type == TARGETING::TYPE_MEMBUF)
        {
            //MEMBUF
            // 0b1000.0000.0000.0000.0000.00NN.NCCC.MMMM
            // where NNN id node, CCC is chip, MMMM is memory channel
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

            o_chipId = (o_chipId << UNIT_ID_SHIFT);
            o_chipId += pos;
            o_chipId |= MEMBUF_ID_TYPE;
        }
        else if(target_type == TARGETING::TYPE_EX ||
                target_type == TARGETING::TYPE_CORE)
        {
            // EX/CORE
            // 0b0100.0000.0000.0000.0000.00NN.NCCC.PPPP
            // NNN is node, CCC is chip, PPPP is core
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

            o_chipId = (o_chipId << UNIT_ID_SHIFT);
            o_chipId += pos;
            o_chipId |= CORE_ID_TYPE;
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
        uint64_t idType = i_rt_chip_id & CHIPID_ID_MASK;

        if(0 != (idType ==  MEMBUF_ID_TYPE))
        {
            //membuf
            uint64_t chip_id = i_rt_chip_id & UNIT_ID_MASK;
            uint32_t unitPos = chip_id & 0x0000000f;
            chip_id >>= UNIT_ID_SHIFT;
            TARGETING::Target * proc = NULL;
            TARGETING::Target * msc = NULL;

            err = getHbTarget(chip_id, proc);
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
        else if(0 != (idType == CORE_ID_TYPE))
        {
            // core/ex  will alway return EX chiplet as there is no concept
            //  (yet) of a core in fapi
            uint64_t chip_id = i_rt_chip_id & UNIT_ID_MASK;
            uint32_t unitPos = chip_id & 0x0000000f;
            chip_id >>= UNIT_ID_SHIFT;
            TARGETING::Target * proc = NULL;

            err = getHbTarget(chip_id, proc);
            if(err)
            {
                break;
            }

            PredicateCTM exFilter(CLASS_UNIT, TYPE_EX);
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
        else if( idType == PROC_ID_TYPE)
        {
            // assume processor chip
            // chip_id  = 'NNNCCC'b
            uint32_t fabId = i_rt_chip_id >> CHIPID_NODE_SHIFT;
            uint32_t procPos = i_rt_chip_id & 0x7;

            PredicateCTM procFilter(CLASS_CHIP, TYPE_PROC);
            PredicateAttrVal<ATTR_FABRIC_NODE_ID> nodeFilter(fabId);
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
