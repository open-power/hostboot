/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakesys.C $
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
 * @file attnfakesys.C
 *
 * @brief HBATTN fake system class method definitions.
 */

#include "../attnlist.H"
#include "../attntrace.H"
#include "attnfakesys.H"
#include "attntest.H"
#include <sys/msg.h>

using namespace std;
using namespace PRDF;
using namespace TARGETING;

namespace ATTN
{

errlHndl_t FakeSystem::putScom(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data)
{
    mutex_lock(&iv_mutex);

    iv_regs[i_target][i_address] = i_data;

    mutex_unlock(&iv_mutex);

    return 0;
}

errlHndl_t FakeSystem::getScom(
                TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t & o_data)
{
    mutex_lock(&iv_mutex);

    o_data = iv_regs[i_target][i_address];

    mutex_unlock(&iv_mutex);

    return 0;
}

errlHndl_t FakeSystem::modifyScom(
                TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_data,
                uint64_t & o_data,
                ScomOp i_op)
{
    mutex_lock(&iv_mutex);

    o_data = iv_regs[i_target][i_address];

    uint64_t data = iv_regs[i_target][i_address];

    bool changed = (i_op == SCOM_OR
            ? (data | i_data) != data
            : (data & i_data) != data);

    if(changed)
    {
        iv_regs[i_target][i_address] = i_op == SCOM_OR
            ? data | i_data
            : data & i_data;
    }

    mutex_unlock(&iv_mutex);

    return 0;
}

errlHndl_t FakeSystem::mask(const PRDF::AttnData & i_data)
{
    mutex_lock(&iv_mutex);

    // mark the attention as masked and
    // indicate that mask was called in the
    // event history

    iv_map[i_data].mask = true;
    iv_map[i_data].history.push_back(MASK_EVENT);

    mutex_unlock(&iv_mutex);

    return 0;
}

errlHndl_t FakeSystem::unmask(const PRDF::AttnData & i_data)
{
    mutex_lock(&iv_mutex);

    // mark the attention as unmasked and
    // indicate that unmask was called in the
    // event history

    iv_map[i_data].mask = false;
    iv_map[i_data].history.push_back(UNMASK_EVENT);

    mutex_unlock(&iv_mutex);

    return 0;
}

errlHndl_t FakeSystem::query(const PRDF::AttnData & i_data, bool & o_active)
{
    mutex_lock(&iv_mutex);

    // provide the status of the attention and
    // indicate that query was called in the
    // event history

    o_active = iv_map[i_data].active;
    iv_map[i_data].history.push_back(QUERY_EVENT);

    mutex_unlock(&iv_mutex);

    return 0;
}

errlHndl_t FakeSystem::resolve(
        TargetHandle_t i_proc,
        AttentionList & o_attentions)
{
    mutex_lock(&iv_mutex);

    // check each attention in the map
    // and add any marked active
    // to the output list

    map<AttnData, FakeSystemProperties>::iterator it = iv_map.begin();

    while(it != iv_map.end())
    {
        if(it->first.targetHndl == i_proc
                && it->second.active && !it->second.mask)
        {
            o_attentions.add(Attention(it->first, this));
        }

        ++it;
    }

    mutex_unlock(&iv_mutex);

    return 0;
}

errlHndl_t FakeSystem::callPrd(const AttentionList & i_attentions)
{
    AttnList l;

    i_attentions.getAttnList(l);

    AttnList::iterator it = l.begin();

    mutex_lock(&iv_mutex);

    // simulate prd by clearing any attentions passed in and
    // indicate that prd was called in the
    // event history

    while(it != l.end())
    {
        iv_map[*it].active = false;
        iv_map[*it].history.push_back(CALLPRD_EVENT);

        ++it;
    }

    mutex_unlock(&iv_mutex);

    return 0;
}

uint64_t FakeSystem::raiseAttentions(msg_q_t i_q, uint64_t i_count)
{
    AttnList list;

    mutex_lock(&iv_mutex);

    uint64_t count = generateAttentions(i_count, list);

    AttnList::iterator it = list.begin();

    while(it != list.end())
    {
        iv_map[*it].active = true;
        iv_map[*it].count++;

        ++it;
    }

    mutex_unlock(&iv_mutex);

    it = list.begin();

    while(it != list.end())
    {
        msg_t * m = msg_allocate();

        m->type = ATTENTION;
        m->data[0] = reinterpret_cast<uint64_t>(it->targetHndl);

        msg_sendrecv(i_q, m);
        ++it;
    }

    return count;
}

void FakeSystem::install()
{
    // register this objects
    // functions as the
    // resolver and prd implementations

    getResolverWrapper().setImpl(*this);
    getPrdWrapper().setImpl(*this);
}

ATTENTION_VALUE_TYPE getRandomAttentionType()
{
    ATTENTION_VALUE_TYPE a;

    switch (randint(1, 3))
    {
        case 1:
            a = CHECK_STOP;
            break;
        case 2:
            a = RECOVERABLE;
            break;
        case 3:
        default:
            a = SPECIAL;
            break;
    };

    return a;
}

uint64_t FakeSystem::generateAttentions(uint64_t i_count, AttnList & io_list)
{
    static const TargetHandle_t nullTarget = 0;
    static const uint64_t numTypes = 3;
    static const uint64_t maxTargets = 64;

    uint64_t count = 0;

    uint64_t remaining = maxTargets * numTypes;

    while(i_count != 0 && remaining > 0)
    {
        AttnData d;

        // generate a "random" attention on one of maxTargets possible targets

        d.targetHndl = nullTarget + randint(1, maxTargets);
        d.attnType = getRandomAttentionType();

        map<AttnData, FakeSystemProperties>::iterator it
            = iv_map.lower_bound(d);

        if(it != iv_map.end() && !compare(it->first, d)
                && (it->second.active || it->second.mask))
        {
            // the random attention algorithm might
            // generate an attention
            // that is already active or masked...
            // since this class simulates
            // behaving hardware, don't use those

            --remaining;
        }
        else
        {
            // check for a duplicate attention
            // already in the list

            AttnList::iterator lit = io_list.begin();

            while(lit != io_list.end())
            {
                if(!compare(*lit, d))
                {
                    break;
                }

                ++lit;
            }

            if(lit == io_list.end())
            {
                io_list.push_back(d);

                ++count;
                --remaining;
            }
        }

        --i_count;
    }

    return count;
}

bool FakeSystem::validate()
{
    static const uint64_t seq[] = {
        MASK_EVENT,
        CALLPRD_EVENT,
        QUERY_EVENT,
        UNMASK_EVENT,
    };
    static const uint64_t * seqEnd = seq
        +sizeof(seq)/sizeof(*seq);

    // this class simulates behaving hardware,
    // and PRD code that will clear every error.
    // using those assumptions, validate
    // the correct sequence occurred for each attention

    bool valid = true;

    mutex_lock(&iv_mutex);

    map<AttnData, FakeSystemProperties>::const_iterator it = iv_map.begin();

    while(it != iv_map.end())
    {
        vector<uint64_t> & history = it->second.history;

        vector<uint64_t>::const_iterator hit = history.begin();
        const uint64_t * sit = seq;

        uint64_t count = it->second.count;

        while(count > 0 && hit != history.end())
        {
            if(*sit != *hit)
            {
                break;
            }

            ++sit;
            ++hit;

            if(sit == seqEnd)
            {
                sit = seq;
                --count;
            }
        }

        if(count)
        {
            valid = false;
            break;
        }

        ++it;
    }

    mutex_unlock(&iv_mutex);

    return valid;
}

FakeSystem::FakeSystem()
    : iv_map(Comp())
{
    mutex_init(&iv_mutex);
}

FakeSystem::~FakeSystem()
{
    mutex_destroy(&iv_mutex);
}
}
