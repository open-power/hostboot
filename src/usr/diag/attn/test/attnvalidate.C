/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnvalidate.C $
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
 * @file attnvalidate.C
 *
 * @brief HBATTN fake system validation class method definitions.
 */

#include "attncomp.H"
#include "attnvalidate.H"
#include "attnfakesys.H"
#include "../attntarget.H"
#include "../attntrace.H"

using namespace PRDF;
using namespace TARGETING;
using namespace std;

namespace ATTN
{

errlHndl_t Validator::processPutAttention(
        FakeSystem & i_sys,
        const AttnData & i_attention,
        uint64_t i_count)
{
    // add this new attention to the list

    Properties p;

    p.targetHndl = i_attention.targetHndl;
    p.attnType = i_attention.attnType;

    TargetHandle_t target = 0;

    uint64_t ipollCheckbits;

    if(getTargetService().getType(i_attention.targetHndl) == TYPE_PROC)
    {
        IPOLL::getCheckbits(i_attention.attnType, ipollCheckbits);
        target = i_attention.targetHndl;
    }
    else
    {
        IPOLL::getCheckbits(HOST, ipollCheckbits);

        target = getTargetService().getProc(i_attention.targetHndl);
    }

    bool masked = i_sys.getReg(target, IPOLL::address) & ipollCheckbits;

    if(!masked)
    {
        p.next = MASK;
    }
    else
    {
        p.next = CLEAR;
    }

    iv_properties.push_back(p);

    return 0;
}

errlHndl_t Validator::processClearAttention(
        FakeSystem & i_sys,
        const AttnData & i_attention,
        uint64_t i_count)
{
    do {

        AttnDataEq comp(i_attention);

        // there should be at least one matching
        // attention ready to be cleared

        vector<Properties>::iterator it = find_if(
                iv_properties.begin(),
                iv_properties.end(),
                comp);

        while(it != iv_properties.end())
        {
            if(it->next == CLEAR)
            {
                // this attention now ready to be unmasked

                it->next = UNMASK;
                break;
            }

            it = find_if(++it, iv_properties.end(), comp);
        }

        if(it == iv_properties.end())
        {
            ATTN_ERR("Validator: tgt: %p, type %d not ready to be cleared",
                    i_attention.targetHndl, i_attention.attnType);
        }
    }
    while(0);

    return 0;
}

struct AppendInnerLoopArgs
{
    AttnList * list;
    TargetHandleList mcsList;
};

void appendInnerLoop(
        uint64_t i_type,
        void * i_args)
{
    AppendInnerLoopArgs * args = static_cast<AppendInnerLoopArgs *>(i_args);

    AttnList & list = *args->list;
    TargetHandleList & mcsList = args->mcsList;

    AttnData d;

    TargetHandleList::iterator it = mcsList.begin();

    while(it != mcsList.end())
    {
        d.attnType = static_cast<ATTENTION_VALUE_TYPE>(i_type);
        d.targetHndl = getTargetService().getMembuf(*it);

        list.push_back(d);

        ++it;
    }
}

struct AppendOuterLoopArgs
{
    TargetHandle_t target;
    AttnList list;
};


void appendOuterLoop(
        uint64_t i_type,
        void * i_args)
{
    AppendOuterLoopArgs * args = static_cast<AppendOuterLoopArgs *>(i_args);

    AttnList & list = args->list;

    AttnData d;
    uint64_t hostmask;

    IPOLL::getCheckbits(HOST, hostmask);

    // assemble a list of all attentions to check

    if(i_type == HOST)
    {
        // for host attn bit changed, check any attention
        // type on any membufs behind this proc

        AppendInnerLoopArgs innerLoopArgs;

        innerLoopArgs.list = &args->list;

        getTargetService().getMcsList(args->target, innerLoopArgs.mcsList);

        IPOLL::forEach(
                0xffffffffffffffffull & ~hostmask,
                &innerLoopArgs,
                &appendInnerLoop);
    }
    else
    {
        // for other attn types, just check the proc

        d.attnType = static_cast<ATTENTION_VALUE_TYPE>(i_type);
        d.targetHndl = args->target;

        list.push_back(d);
    }
}

errlHndl_t Validator::processPutReg(
            FakeSystem & i_sys,
            TargetHandle_t i_target,
            uint64_t i_address,
            uint64_t i_new,
            uint64_t i_old)
{
    AppendOuterLoopArgs args;

    args.target = i_target;

    // these bits turned off

    IPOLL::forEach(i_old & ~i_new, &args, &appendOuterLoop);

    AttnList::iterator it = args.list.begin();

    while(it != args.list.end())
    {
        processUnmask(*it);
        ++it;
    }

    args.list.clear();

    // these bits turned on

    IPOLL::forEach(i_new & ~i_old, &args, &appendOuterLoop);

    it = args.list.begin();

    while(it != args.list.end())
    {
        processMask(*it);
        ++it;
    }

    return 0;
}


void Validator::processUnmask(const AttnData & i_data)
{
    AttnDataEq comp(i_data);

    vector<Properties>::iterator pit = find_if(
            iv_properties.begin(),
            iv_properties.end(),
            comp);

    while(pit != iv_properties.end())
    {
        if(pit->next == UNMASK)
        {
            // finished with this attention

            ATTN_DBG("Validator: tgt: %p, type: %d done.",
                    pit->targetHndl, pit->attnType);

            pit = iv_properties.erase(pit);
        }
        else
        {
            ++pit;
        }

        pit = find_if(pit,
                iv_properties.end(),
                comp);
    }
}

void Validator::processMask(const AttnData & i_data)
{
    AttnDataEq comp(i_data);

    vector<Properties>::iterator pit = find_if(
            iv_properties.begin(),
            iv_properties.end(),
            comp);

    while(pit != iv_properties.end())
    {
        if(pit->next == MASK)
        {
            // this attention now ready to be cleared

            pit->next = CLEAR;
        }

        pit = find_if(++pit,
                iv_properties.end(),
                comp);
    }
}

void Validator::install(FakeSystem & i_sys)
{
    i_sys.addSource(TYPE_NA, INVALID_ATTENTION_TYPE, *this);

    // monitor changes to ipoll
    i_sys.addReg(IPOLL::address, *this);
}

bool Validator::empty() const
{
    return iv_properties.empty();
}

void Validator::dump() const
{
    vector<Properties>::const_iterator it =
        iv_properties.begin();

    while(it != iv_properties.end())
    {
        ATTN_DBG("target: %p, type: %d, next: %d",
                it->targetHndl, it->attnType, it->next);

        ++it;
    }
}
}
