/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnmeminject.C $                      */
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
