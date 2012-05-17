/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnlist.C $
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
 * @file attnlist.C
 *
 * @brief HBATTN AttentionList function definitions.
 */

#include "attnfwd.H"
#include "attnlist.H"
#include "attnops.H"
#include <algorithm>

using namespace std;
using namespace PRDF;

namespace ATTN
{

AttentionList & AttentionList::merge(const AttentionList & i_src)
{
    // union of two attention lists

    const_iterator sit = i_src.begin();
    iterator dit = begin();

    while(sit != i_src.end())
    {
        dit = insert(lower_bound(dit, end(), *sit), *sit);
        ++sit;
    }

    return *this;
}

void AttentionList::getAttnList(PRDF::AttnList & o_dest) const
{
    // convert AttentionList to PRDF::AttnList

    const_iterator sit = begin();

    AttnData d;

    while(sit != end())
    {
        sit->getData(d);

        o_dest.push_back(d);

        ++sit;
    }
}

void AttentionList::add(const Attention & i_attn)
{
    insert(lower_bound(begin(), end(), i_attn), i_attn);
}
}
