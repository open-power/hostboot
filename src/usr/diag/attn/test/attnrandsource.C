/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attnrandsource.C $
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
 * @file attnrandsource.C
 *
 * @brief HBATTN Random attention source class method definitions.
 */

#include "attnrandsource.H"
#include "attnfakesys.H"
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

void RandSource::main(void * i_source)
{
    RandSource * src = static_cast<RandSource *>(i_source);

    src->run();
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

        iv_system->putAttentions(l);
    }
}

RandSource::RandSource(
        uint64_t i_iterations,
        uint64_t i_maxAttnsPerIteration,
        FakeSystem & i_system,
        TargetHandle_t * i_first,
        TargetHandle_t * i_last)
    : iv_tid(0),
    iv_iterations(i_iterations),
    iv_max(i_maxAttnsPerIteration),
    iv_system(&i_system),
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
