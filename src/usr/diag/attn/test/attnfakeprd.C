/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnfakeprd.C $
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
 * @file attnfakeprd.C
 *
 * @brief HBATTN fake PRD class method definitions.
 */

#include "attnfakeprd.H"
#include "attnfakesys.H"
#include "../attnops.H"
#include "../attnlist.H"
#include <sys/time.h>

using namespace PRDF;

namespace ATTN
{

struct Clear
{
    Clear(FakeSystem & i_system) : iv_system(&i_system), err(0) {}

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

                err = iv_system->clearAllAttentions(d);
            }
        }
    }

    FakeSystem * iv_system;
    errlHndl_t err;
};

errlHndl_t FakePrd::callPrd(const AttentionList & i_attentions)
{
    return i_attentions.forEach(Clear(*iv_system)).err;
}

FakePrd::FakePrd(FakeSystem & i_system) :
    iv_system(&i_system)
{

}
}
