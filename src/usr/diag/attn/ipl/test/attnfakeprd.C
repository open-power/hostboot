/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attnfakeprd.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
 * @file attnfakeprd.C
 *
 * @brief HBATTN fake PRD class method definitions.
 */

#include "attnfakeprd.H"
#include "attninject.H"
#include "../../common/attnops.H"
#include "../../common/attnlist.H"
#include <sys/time.h>

using namespace PRDF;

namespace ATTN
{

struct Clear
{
    Clear(InjectSink & i_injectSink) : iv_injectSink(&i_injectSink), err(0) {}

    void operator()(const Attention & i_attention)
    {
        if(!err)
        {
            AttnData d;

            i_attention.getData(d);

            // sleep for a random interval to simulate
            // real prd processing time

            nanosleep(0, randint(TEN_CTX_SWITCHES_NS, TEN_CTX_SWITCHES_NS * 10));

            if(randint(0, 10) < 8)
            {
                // periodically do nothing to force the main service
                // to see attentions that were not cleared and call PRD
                // again

                err = iv_injectSink->clearAllAttentions(d);
            }
        }
    }

    InjectSink * iv_injectSink;
    errlHndl_t err;
};

errlHndl_t FakePrd::callPrd(const AttentionList & i_attentions)
{
    return i_attentions.forEach(Clear(*iv_injectSink)).err;
}

FakePrd::FakePrd(InjectSink & i_injectSink) :
    iv_injectSink(&i_injectSink)
{

}
}
