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
#include "../attntarget.H"
#include "attnfakeelement.H"
#include "attnfakesys.H"
#include "attntest.H"
#include <sys/msg.h>
#include <sys/time.h>

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
    errlHndl_t err = 0;

    mutex_lock(&iv_mutex);

    err = putReg(i_target, i_address, i_data);

    mutex_unlock(&iv_mutex);

    return err;
}

errlHndl_t FakeSystem::getScom(
                TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t & o_data)
{
    mutex_lock(&iv_mutex);

    o_data = getReg(i_target, i_address);

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
    errlHndl_t err = 0;

    mutex_lock(&iv_mutex);

    o_data = iv_regs[i_target][i_address];

    err = modifyReg(i_target, i_address, i_data, i_op);

    mutex_unlock(&iv_mutex);

    return err;
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

bool FakeSystem::wait(uint64_t i_maxWaitNs)
{
    uint64_t count = 0;
    uint64_t previous = 0;
    uint64_t elapsedNs = 0;

    do
    {
        mutex_lock(&iv_mutex);

        previous = count;
        count = iv_attentions.size();

        mutex_unlock(&iv_mutex);

        if(!count)
        {
            break;
        }

        nanosleep(0, TEN_CTX_SWITCHES_NS);

        if(count == previous)
        {
            elapsedNs += TEN_CTX_SWITCHES_NS;
        }
    }
    while(elapsedNs < i_maxWaitNs);

    return count == 0;
}

void FakeSystem::wait()
{
    mutex_lock(&iv_mutex);

    while(!iv_attentions.empty())
    {
        sync_cond_wait(&iv_cond, &iv_mutex);
    }

    mutex_unlock(&iv_mutex);
}

void FakeSystem::addReg(uint64_t i_address, FakeReg & i_element)
{
    // register a new implemenation element

    mutex_lock(&iv_mutex);

    iv_regImpl.push_back(make_pair(i_address, &i_element));

    mutex_unlock(&iv_mutex);
}

void FakeSystem::addSource(
        TYPE i_targetType,
        ATTENTION_VALUE_TYPE i_type,
        FakeSource & i_element)
{
    // register a new implemenation element

    mutex_lock(&iv_mutex);

    iv_sources.push_back(make_pair(make_pair(i_targetType, i_type), &i_element));

    mutex_unlock(&iv_mutex);
}

errlHndl_t FakeSystem::putReg(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data)
{
    uint64_t data = iv_regs[i_target][i_address];

    putRegUnsafe(i_target, i_address, i_data);

    return makeRegCallbacks(
            i_target, i_address, i_data, data);
}

void FakeSystem::putRegUnsafe(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data)
{
    ATTN_DBG("FakeSystem::putReg: tgt: %p, add: %016x, data: %016x",
            i_target, i_address, i_data);

    iv_regs[i_target][i_address] = i_data;
}

uint64_t FakeSystem::getReg(
        TargetHandle_t i_target,
        uint64_t i_address)
{
    uint64_t data = iv_regs[i_target][i_address];

    return data;
}

errlHndl_t FakeSystem::modifyReg(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_data,
        ScomOp i_op)
{
    errlHndl_t err = 0;

    uint64_t data = iv_regs[i_target][i_address];


    uint64_t changedData = i_op == SCOM_OR
        ? (data | i_data)
        : (data & i_data);

    bool changed = changedData != data;

    if(changed)
    {
        putRegUnsafe(
                i_target,
                i_address,
                changedData);

        err = makeRegCallbacks(
                i_target,
                i_address,
                changedData,
                data);
    }

    return err;
}

errlHndl_t FakeSystem::makeRegCallbacks(
        TargetHandle_t i_target,
        uint64_t i_address,
        uint64_t i_new,
        uint64_t i_old)
{
    // inform each element of the update

    errlHndl_t err = 0;

    vector<pair<uint64_t, FakeReg *> >::iterator it =
        iv_regImpl.begin();

    while(!err && it != iv_regImpl.end())
    {
        if(it->first == i_address
                || it->first == 0)
        {
            err = (*it->second).processPutReg(
                    *this,
                    i_target,
                    i_address,
                    i_new,
                    i_old);
        }

        ++it;
    }

    return err;
}

errlHndl_t FakeSystem::makeAttnCallbacks(
        const AttnList & i_list,
        bool i_set)
{
    errlHndl_t err = 0;

    AttnList::const_iterator ait = i_list.begin();

    while(ait != i_list.end())
    {
        vector<Entry>::iterator it =
            iv_sources.begin();

        TYPE type = getTargetService().getType(ait->targetHndl);

        AttnDataMap<uint64_t>::iterator tit = iv_attentions.find(*ait);

        uint64_t count = tit == iv_attentions.end() ? 0 : tit->second;

        while(!err && it != iv_sources.end())
        {
            Key & k = it->first;

            if(k.first == TYPE_NA
                    || (k.first == type && k.second == ait->attnType))
            {
                if(i_set)
                {
                    err = (*it->second).processPutAttention(
                            *this,
                            *ait,
                            count);
                }
                else
                {
                    err = (*it->second).processClearAttention(
                            *this,
                            *ait,
                            count);
                }
            }
            ++it;
        }

        ++ait;
    }

    return err;
}

errlHndl_t FakeSystem::putAttentions(
        const AttnList & i_list)
{
    errlHndl_t err = 0;

    // inject the attentions and then
    // inform each element

    mutex_lock(&iv_mutex);

    AttnList::const_iterator ait = i_list.begin();

    while(ait != i_list.end())
    {
        ATTN_DBG("FakeSystem::putAttention: tgt: %p, type: %d",
                ait->targetHndl, ait->attnType);

        iv_attentions[*ait]++;
        ++ait;
    }

    err = makeAttnCallbacks(i_list, true);

    mutex_unlock(&iv_mutex);

    return err;
}

void FakeSystem::clearAttentionUnsafe(
        const AttnData & i_attn)
{
    ATTN_DBG("FakeSystem::clearAttention: tgt: %p, type: %d",
            i_attn.targetHndl, i_attn.attnType);

    // clear the attention and then
    // inform each element

    iv_attentions[i_attn]--;

    if(!iv_attentions[i_attn])
    {
        iv_attentions.erase(i_attn);
    }
}

errlHndl_t FakeSystem::clearAttention(
                const PRDF::AttnData & i_attn)
{
    errlHndl_t err = 0;

    mutex_lock(&iv_mutex);

    clearAttentionUnsafe(i_attn);

    bool done = iv_attentions.empty();

    err = makeAttnCallbacks(AttnList(1, i_attn), false);

    mutex_unlock(&iv_mutex);

    if(done)
    {
        sync_cond_signal(&iv_cond);
    }

    return err;
}

errlHndl_t FakeSystem::clearAllAttentions(
                const PRDF::AttnData & i_attn)
{
    errlHndl_t err = 0;

    mutex_lock(&iv_mutex);

    AttnDataMap<uint64_t>::iterator it = iv_attentions.find(i_attn);

    uint64_t count = it == iv_attentions.end() ? 0 : it->second,
             cit = count;

    while(cit--)
    {
        clearAttentionUnsafe(i_attn);
    }

    bool done = iv_attentions.empty();

    err = makeAttnCallbacks(AttnList(count, i_attn), false);

    mutex_unlock(&iv_mutex);

    if(done)
    {
        sync_cond_signal(&iv_cond);
    }

    return err;
}

uint64_t FakeSystem::count(const AttnData & i_attention)
{
    AttnDataMap<uint64_t>::iterator it = iv_attentions.find(i_attention);

    uint64_t count = it == iv_attentions.end() ? 0 : it->second;

    return count;
}

void FakeSystem::dump()
{
    AttnDataMap<uint64_t>::iterator it = iv_attentions.begin();

    while(it != iv_attentions.end())
    {
        ATTN_DBG("target: %p, type: %d, count: %d",
                it->first.targetHndl, it->first.attnType, it->second);

        ++it;
    }
}

FakeSystem::FakeSystem()
{
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cond);
}

FakeSystem::~FakeSystem()
{
    sync_cond_destroy(&iv_cond);
    mutex_destroy(&iv_mutex);
}
}
