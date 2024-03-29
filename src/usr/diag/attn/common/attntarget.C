/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attntarget.C $                       */
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
 * @file attntarget.C
 *
 * @brief HBATTN Target service wrapper class method definitions.
 */

#include "common/attntarget.H"
#include "common/attntrace.H"
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>
#include <util/singleton.H>

using namespace TARGETING;

namespace ATTN
{

void TargetServiceImpl::getAllChips(
        TARGETING::TargetHandleList & o_list,
        TARGETING::TYPE i_type,
        bool i_functional)
{
    TARGETING::getAllChips(o_list, i_type, i_functional);
}

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
    PredicateCTM classTypeMatch(CLASS_UNIT, TYPE_MCS);
    PredicateIsFunctional functionalMatch;
    PredicatePostfixExpr pred;

    class ChipUnitMatch : public PredicateBase
    {
        uint8_t iv_pos;

        public:

        bool operator()(const Target * i_target) const
        {
            uint8_t pos;

            bool match = false;

            if(i_target->tryGetAttr<ATTR_CHIP_UNIT>(pos))
            {
                match = iv_pos == pos;
            }

            return match;
        }

        explicit ChipUnitMatch(uint8_t i_pos)
            : iv_pos(i_pos) {}

    } chipUnitMatch(i_pos);

    pred.push(&classTypeMatch).push(
            &functionalMatch).And();

    pred.push(&chipUnitMatch).And();

    TargetHandleList list;
    TargetHandle_t mcs = NULL;

    targetService().getAssociated(
            list,
            i_proc,
            TARGETING::TargetService::CHILD_BY_AFFINITY,
            TARGETING::TargetService::ALL,
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
    getChildAffinityTargets(list, i_mcs, CLASS_CHIP, TYPE_MEMBUF);

    if(list.size() == 1)
    {
        membuf = list[0];
    }

    return membuf;
}

bool TargetServiceImpl::getAttribute(
        ATTRIBUTE_ID i_attribute,
        TargetHandle_t i_target,
        uint64_t & o_val)
{
    bool found = false;
    uint8_t u8;

    switch (i_attribute)
    {
        case ATTR_PROC_FABRIC_TOPOLOGY_ID:

            found = i_target->tryGetAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>(u8);
            o_val = u8;

            break;
        default:

            break;
    }

    return found;
}

void TargetServiceImpl::masterProcChipTargetHandle(
                  TARGETING::Target*& o_masterProcChipTargetHandle,
                  const TARGETING::Target* i_pNodeTarget) const
{
    TARGETING::targetService().masterProcChipTargetHandle(
                                     o_masterProcChipTargetHandle);
}

TYPE TargetServiceImpl::getType(TargetHandle_t i_target)
{
    return i_target->getAttr<ATTR_TYPE>();
}

TargetServiceImpl::~TargetServiceImpl()
{
    // restore the default

    getTargetService().setImpl(Singleton<TargetServiceImpl>::instance());

    TargetService & wrapper = getTargetService();
    TargetServiceImpl * defaultImpl = &Singleton<TargetServiceImpl>::instance();

    if(wrapper.iv_impl == this)
    {
        if(this != defaultImpl)
        {
            wrapper.setImpl(*defaultImpl);
        }
    }
}

TargetService & getTargetService()
{
    return Singleton<TargetService>::instance();
}
}
