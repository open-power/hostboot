/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attntarget.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 * @file attntarget.C
 *
 * @brief HBATTN Target service wrapper class method definitions.
 */

#include "attntarget.H"
#include "targeting/common/predicates/predicates.H"
#include "targeting/common/utilFilter.H"
#include <util/singleton.H>

using namespace TARGETING;

namespace ATTN
{

void TargetServiceImpl::getMcsList(
        TargetHandle_t i_proc,
        TargetHandleList & o_list)
{
    getChildChiplets(o_list, i_proc, TYPE_MCS);
}

TargetHandle_t TargetServiceImpl::getProc(
        TargetHandle_t i_membuf)
{
    TargetHandle_t proc = NULL;

    TargetHandleList list;
    PredicateCTM pred(CLASS_CHIP, TYPE_PROC);

    targetService().getAssociated(
            list,
            i_membuf,
            TARGETING::TargetService::PARENT_BY_AFFINITY,
            TARGETING::TargetService::ALL,
            &pred);

    if(list.size() == 1)
    {
        proc = list[0];
    }

    return proc;
}

TargetHandle_t TargetServiceImpl::getMcs(
        TargetHandle_t i_membuf)
{
    TargetHandle_t mcs = NULL;

    TargetHandleList list;
    PredicateCTM pred(CLASS_UNIT, TYPE_MCS);

    targetService().getAssociated(
            list,
            i_membuf,
            TARGETING::TargetService::PARENT_BY_AFFINITY,
            TARGETING::TargetService::IMMEDIATE,
            &pred);

    if(list.size() == 1)
    {
        mcs = list[0];
    }

    return mcs;
}

TargetHandle_t TargetServiceImpl::getMcs(
        TargetHandle_t i_proc,
        uint64_t i_pos)
{
    class ChipUnitMatch : public PredicateBase
    {
        uint64_t iv_pos;

        public:

        bool operator()(const Target * i_target) const
        {
            return i_target->getAttr<ATTR_CHIP_UNIT>() == iv_pos;
        }

        explicit ChipUnitMatch(uint64_t i_pos) : iv_pos(i_pos) {}

    } chipUnitMatch(i_pos);

    PredicateCTM classTypeMatch(CLASS_UNIT, TYPE_MCS);
    PredicateIsFunctional functionalMatch;

    PredicatePostfixExpr pred;

    pred.push(&chipUnitMatch).push(&classTypeMatch).And().push(
            &functionalMatch).And();

    TargetHandleList list;
    TargetHandle_t mcs = NULL;

    targetService().getAssociated(
            list,
            i_proc,
            TARGETING::TargetService::CHILD_BY_AFFINITY,
            TARGETING::TargetService::IMMEDIATE,
            &pred);

    if(list.size() == 1)
    {
        mcs = list[0];
    }

    return mcs;
}

void TargetServiceImpl::getMcsPos(
        TargetHandle_t i_mcs,
        uint64_t & o_pos)
{
    o_pos = i_mcs->getAttr<ATTR_CHIP_UNIT>();
}

TargetHandle_t TargetServiceImpl::getMembuf(
        TargetHandle_t i_mcs)
{
    TargetHandle_t membuf = NULL;

    TargetHandleList list;
    getAffinityChips(list, i_mcs, TYPE_MEMBUF);

    if(list.size() == 1)
    {
        membuf = list[0];
    }

    return membuf;
}

TYPE TargetServiceImpl::getType(TargetHandle_t i_target)
{
    return i_target->getAttr<ATTR_TYPE>();
}

TargetService & getTargetService()
{
    return Singleton<TargetService>::instance();
}
}
