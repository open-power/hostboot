/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnrandsource.C $                     */
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
/**
 * @file attnrandsource.C
 *
 * @brief HBATTN Random attention source class method definitions.
 */

#include "attnrandsource.H"
#include "attninject.H"
#include "../attntrace.H"
#include "sys/time.h"

using namespace PRDF;
using namespace TARGETING;
using namespace std;

namespace ATTN
{

bool RandSource::start()
{
    bool success = false;

    mutex_lock(&iv_mutex);

    if(!iv_tid)
    {
        iv_tid = task_create(&main, this);
    }

    success = iv_tid != 0;

    ATTN_DBG("RandSource started: %d", iv_tid);

    mutex_unlock(&iv_mutex);

    return success;
}

bool RandSource::wait()
{
    mutex_lock(&iv_mutex);

    tid_t t = iv_tid;
    iv_tid = 0;

    mutex_unlock(&iv_mutex);

    if(t)
    {
        task_wait_tid(t, 0, 0);
    }

    return true;
}

void* RandSource::main(void * i_source)
{
    RandSource * src = static_cast<RandSource *>(i_source);

    src->run();
    return NULL;
}

void RandSource::run()
{
    mutex_lock(&iv_mutex);

    uint64_t iterations = iv_iterations, delay, count;

    mutex_unlock(&iv_mutex);

    while(iterations--)
    {
        delay = randint(TEN_CTX_SWITCHES_NS, TEN_CTX_SWITCHES_NS * 10) / iv_iterations +1;
        count = randint(1, iv_max);

        nanosleep(0, delay);

        AttnList l;
        AttnData d;

        while(count--)
        {
            // select a random target

            // generate a random attention

            d.targetHndl = *(iv_first + randint(0, distance(iv_first, iv_last) -1));
            d.attnType = getRandomAttentionType();

            l.push_back(d);
        }

        iv_injectSink->putAttentions(l);
    }
}

RandSource::RandSource(
        uint64_t i_iterations,
        uint64_t i_maxAttnsPerIteration,
        InjectSink & i_injectSink,
        TargetHandle_t * i_first,
        TargetHandle_t * i_last)
    : iv_tid(0),
    iv_iterations(i_iterations),
    iv_max(i_maxAttnsPerIteration),
    iv_injectSink(&i_injectSink),
    iv_first(i_first),
    iv_last(i_last)
{
    mutex_init(&iv_mutex);
}

RandSource::~RandSource()
{
    mutex_destroy(&iv_mutex);
}
}
