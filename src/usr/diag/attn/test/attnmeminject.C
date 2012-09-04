/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnmeminject.C $
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
#include "attnmeminject.H"
#include "../attnscom.H"
#include "../attntarget.H"

using namespace PRDF;
using namespace TARGETING;
using namespace std;

namespace ATTN
{

errlHndl_t MemInjectSink::putAttention(const AttnData & i_attn)
{
    return putScom(
            getTargetService().getMcs(i_attn.targetHndl),
            MCI::address,
            ~0);
}

errlHndl_t MemInjectSink::putAttentions(
        const AttnList & i_list)
{
    errlHndl_t err = 0;

    AttnList::const_iterator it = i_list.begin();

    while(it != i_list.end())
    {
        err = putAttention(*it);

        if(err)
        {
            break;
        }

        ++it;
    }

    return err;
}

errlHndl_t MemInjectSink::clearAttention(
                const AttnData & i_attn)
{
    return putScom(
            getTargetService().getMcs(i_attn.targetHndl),
            MCI::address,
            0);
}

errlHndl_t MemInjectSink::clearAllAttentions(
                const AttnData & i_attn)
{
    return clearAttention(i_attn);
}
}
