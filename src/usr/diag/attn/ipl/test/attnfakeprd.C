/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/test/attnfakeprd.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#include "../../common/attntrace.H"
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
    errlHndl_t  l_elog = i_attentions.forEach(Clear(*iv_injectSink)).err;

    AttnList    l_attnList;
    i_attentions.getAttnList(l_attnList);


    ATTN_TRACE("fakeCallPrd with Attn Count of %d", l_attnList.size());

    // -----------------------------------------------------
    // This is FAKE code only.
    // If you do the EC/MODEL check, it crashes in CXX testcase.
    // Kind of thinking some library missing that is needed when
    // adding these calls, For now, I will just leave them out
    // and we could probably scrap this test now that it runs
    // successfully  (see attntestproc.H)
    // (Maybe add to 'fake target service' for these ATTRs)
    // -----------------------------------------------------
    // For the initial NIMBUS chip, there is a HW issue
    // which requires us to clear the "Combined Global
    // interrupt register" on recoverable errors.
    // This also affects Checkstop/Special Attns, but
    // the FSP handles those and already clears the reg.
    // The issue does not apply to host/unit cs attns.
//    uint8_t l_ecLevel = 0;
    AttnList::iterator  l_attnIter = l_attnList.begin();

    // Shouldn't be mixing NIMBUS with CUMULUS,etc...
    // so probably don't need to repeat this call per chip.
//    bool l_isNimbus = ( (*l_attnIter).targetHndl->
//                        getAttr<ATTR_MODEL>() == MODEL_NIMBUS );

    // Iterate thru all chips in case PRD handled
    // a chip other than the first one.
    while(l_attnIter != l_attnList.end())
    {
//        l_ecLevel = (*l_attnIter).targetHndl->getAttr<ATTR_EC>();


        if ( (RECOVERABLE == (*l_attnIter).attnType)
//             && (true == l_isNimbus) && (l_ecLevel < 0x11)
           )
        {
            errlHndl_t l_scomErr = NULL;
            uint64_t   l_clrAllBits = 0;

            l_scomErr = putScom( (*l_attnIter).targetHndl,
                                  PIB_INTR_TYPE_REG,
                                  l_clrAllBits
                                );

            if (NULL != l_scomErr)
            {
                 ATTN_ERR("Clear PibIntrReg failed, HUID:0X%08X",
                          get_huid( (*l_attnIter).targetHndl) );
                 errlCommit(l_scomErr, ATTN_COMP_ID);
            } // failed to clear PIB intr reg

        } // if recoverable attn

        ++l_attnIter;

    } // end while looping thru attn list


    return l_elog;
}

FakePrd::FakePrd(InjectSink & i_injectSink) :
    iv_injectSink(&i_injectSink)
{

}
}
