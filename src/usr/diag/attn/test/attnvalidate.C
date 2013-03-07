/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnvalidate.C $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

    AttnData p;

    p.targetHndl = i_attention.targetHndl;
    p.attnType = i_attention.attnType;

    iv_properties.push_back(p);

    return 0;
}

errlHndl_t Validator::processClearAttention(
        FakeSystem & i_sys,
        const AttnData & i_attention,
        uint64_t i_count)
{
    AttnDataEq comp(i_attention);

    AttnList::iterator pit = find_if(
            iv_properties.begin(),
            iv_properties.end(),
            comp);

    while(pit != iv_properties.end())
    {
            // finished with this attention

            ATTN_DBG("Validator: tgt: %p, type: %d done.",
                    pit->targetHndl, pit->attnType);

            pit = iv_properties.erase(pit);
    }

    return 0;
}

void Validator::install(FakeSystem & i_sys)
{
    i_sys.addSource(TYPE_NA, INVALID_ATTENTION_TYPE, *this);
}

bool Validator::empty() const
{
    return iv_properties.empty();
}

void Validator::dump() const
{
    AttnList::const_iterator it =
        iv_properties.begin();

    while(it != iv_properties.end())
    {
        ATTN_DBG("target: %p, type: %d",
                it->targetHndl, it->attnType);

        ++it;
    }
}
}
