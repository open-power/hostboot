/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attn.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace Util;

namespace ATTN
{

/**
 * @brief DisableProcResolver
 *
 * FIXME:  Temp turn off the proc
 *  resolver until the proc global
 *  FIRs can be scomed in simics.
 *  RTC: 47750
 */
static struct DisableProcResolver
{
    DisableProcResolver()
    {
        Singleton<ProcOps>::instance().disable();
    }

} disableProcResolver;

errlHndl_t startService()
{
    return Singleton<Service>::instance().start();
}

errlHndl_t stopService()
{
    return Singleton<Service>::instance().stop();
}

void PrdImpl::installPrd()
{
    getPrdWrapper().setImpl(*this);
}

errlHndl_t PrdImpl::callPrd(const AttentionList & i_attentions)
{
    // forward call to the real PRD

    errlHndl_t err = 0;

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
