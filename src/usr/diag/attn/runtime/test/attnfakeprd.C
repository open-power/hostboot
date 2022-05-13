/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/test/attnfakeprd.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#include "diag/attn/attnreasoncodes.H"
#include "../../common/attnops.H"
#include "../../common/attnlist.H"
#include "../../common/attntrace.H"

using namespace PRDF;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ATTN
{

errlHndl_t FakePrd::callPrd(const AttentionList & i_attentions)
{
    errlHndl_t err = NULL;
    PRDF::AttnList attns;
    PRDF::AttnList expectedAttns;
    int32_t rc = 0;

    do
    {
        i_attentions.getAttnList( attns );
        iv_expectedAttns.getAttnList( expectedAttns );
        if( attns.size() != expectedAttns.size() )
        {
            ATTN_ERR("callPrd():: Test case failed. attns.size():%u, "
                      "expectedAttns.size():%u",
                      attns.size(), expectedAttns.size() );
            rc = -1; break;
        }
        for( uint32_t i=0; i < attns.size(); i++ )
        {
           ATTN_SLOW("callPrd():: Input Attention HUID:0x%08X type:%u "
                     "Expected Attention HUID:0x%08X type:%u",
                     get_huid( attns[i].targetHndl), attns[i].attnType,
                     get_huid( expectedAttns[i].targetHndl),
                     expectedAttns[i].attnType);
            if( (attns[i].targetHndl != expectedAttns[i].targetHndl ) ||
                 (attns[i].attnType != expectedAttns[i].attnType) )
            {
                ATTN_ERR("callPrd():: Test case failed as attention did "
                         " not match. ");
                rc =-1;     break;
            }
        }
    }while(0);
    if( 0 != rc )
    {
        /*@
         * @errortype
         * @reasoncode       ATTN_TEST_ATTN_FAIL
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         ATTN_TEST_FAKE_CALL_PRD
         * @userdata1        Input attention list size
         * @userdata2        Expected attention list size
         * @devdesc          ATTN test case failed
         * @custdesc         An internal firmware error occurred
         */

         err = new ErrlEntry(
               ERRL_SEV_UNRECOVERABLE,
               ATTN::ATTN_TEST_FAKE_CALL_PRD,
               ATTN::ATTN_TEST_ATTN_FAIL,
               attns.size(),
               expectedAttns.size() );
    }
    return err;
}

void FakePrd::setExpectedAttn(AttentionList & i_expectAttns)
{
    iv_expectedAttns = i_expectAttns;
}
}
