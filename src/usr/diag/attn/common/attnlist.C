/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnlist.C $                         */
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
 * @file attnlist.C
 *
 * @brief HBATTN AttentionList function definitions.
 */

#include "common/attnfwd.H"
#include "common/attnlist.H"
#include "common/attnops.H"
#include "common/attntrace.H"
#include <algorithm>

using namespace std;
using namespace PRDF;

namespace ATTN
{

void AttentionList::getAttnList(PRDF::AttnList & o_dest) const
{
    // convert AttentionList to PRDF::AttnList

    const_iterator sit = begin();

    AttnData d;

    while(sit != end())
    {
        sit->getData(d);

        o_dest.push_back(d);
        ATTN_TRACE("getAttnList saving type: %d", d.attnType);

        ++sit;
    }
}

void AttentionList::add(const Attention & i_attn)
{
    insert(lower_bound(begin(), end(), i_attn), i_attn);
}
}
