/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attn.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
 * @file attn.C
 *
 * @brief HBATTN utility function definitions.
 */

#include "attnprd.H"
#include "attnops.H"
#include "attnlist.H"
#include "attntrace.H"
#include "attnsvc.H"
#include "attnproc.H"
#include "attnmem.H"
#include <util/singleton.H>
#include "attntarget.H"
#include <errl/errlmanager.H>

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace Util;

namespace ATTN
{

errlHndl_t startService()
{
    return Singleton<Service>::instance().start();
}

errlHndl_t stopService()
{
    return Singleton<Service>::instance().stop();
}

errlHndl_t checkForIplAttentions()
{
    errlHndl_t err = NULL;

    assert(!Singleton<Service>::instance().running());

    ProcOps & procOps = Singleton<ProcOps>::instance();
    MemOps & memOps = Singleton<MemOps>::instance();

    TargetHandleList list;

    getTargetService().getAllChips(list, TYPE_PROC);

    TargetHandleList::iterator tit = list.begin();

    while(tit != list.end())
    {
        AttentionList attentions;

        do {

            attentions.clear();

            // query the proc resolver for active attentions

            err = procOps.resolve(*tit, 0, attentions);

            if(err)
            {
                break;
            }

            // query the mem resolver for active attentions

            err = memOps.resolve(*tit, attentions);

            if(err)
            {
                break;
            }

            // TODO RTC 51547
            // historically ATTN has enumerated
            // all chips on the entire system so that
            // PRD can figure out who caused a system
            // checkstop.

            // since hostboot won't be handling that
            // its faster to just enumerate attentions one
            // chip at a time

            // The intent of the RTC is to confirm this
            // is the desired behavior

            if(!attentions.empty())
            {
                err = getPrdWrapper().callPrd(attentions);
            }

            if(err)
            {
                break;
            }

        } while(!attentions.empty());

        if(err || attentions.empty())
        {
            tit = list.erase(tit);
        }

        if(err)
        {
            errlCommit(err, ATTN_COMP_ID);
        }
    }

    return 0;
}

void PrdImpl::installPrd()
{
    getPrdWrapper().setImpl(*this);
}

errlHndl_t PrdImpl::callPrd(const AttentionList & i_attentions)
{
    // forward call to the real PRD

    errlHndl_t err = NULL;

    // convert attention list to PRD type

    AttnList attnList;

    i_attentions.getAttnList(attnList);

    if(!attnList.empty())
    {
        // AttentionLists keep themselves sorted by attention type
        // with higher priority attentions
        // appearing before those with lower priority, where the
        // priority is defined by the ATTENTION_VALUE_TYPE enum.
        //
        // When an AttentionList is converted to an AttnList
        // the order is preserved.  In this way, the PRD
        // requirement that the highest priority attention
        // appear first in the argument list is satisfied.

        err = PRDF::main(attnList.front().attnType, attnList);
    }

    return err;
}

PrdWrapper & getPrdWrapper()
{
    // prd wrapper singleton access

    static PrdWrapper w;

    return w;
}

PrdWrapper::PrdWrapper()
    : iv_impl(&Singleton<PrdImpl>::instance())
{
    // default call the real PRD
}

errlHndl_t PrdWrapper::callPrd(const AttentionList & i_attentions)
{
    // forward call to the installed PRD implementation.

    ATTN_DBG("call PRD with %d using: %p", i_attentions.size(), iv_impl);

    return iv_impl->callPrd(i_attentions);
}

ProcOps & getProcOps()
{
    return Singleton<ProcOps>::instance();
}

MemOps & getMemOps()
{
    return Singleton<MemOps>::instance();
}

int64_t Attention::compare(const Attention & i_rhs) const
{
    return ATTN::compare(iv_data, i_rhs.iv_data);
}

int64_t compare(const AttnData & i_l, const AttnData & i_r)
{
    if(i_l.attnType < i_r.attnType)
    {
        return -1;
    }

    if(i_r.attnType < i_l.attnType)
    {
        return 1;
    }

    if(i_l.targetHndl < i_r.targetHndl)
    {
        return -1;
    }

    if(i_r.targetHndl < i_l.targetHndl)
    {
        return 1;
    }

    return 0;
}
}
