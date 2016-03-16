/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/test/attntest.C $                       */
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
 * @file attntest.C
 *
 * @brief HBATTN test utility function definitions.
 */

#include <arch/ppc.H>
#include <algorithm>
#include "attntest.H"
#include "../../common/attntrace.H"
#include "../../common/attntarget.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;

namespace ATTN
{

uint64_t randint(uint64_t i_min, uint64_t i_max)
{
    static bool setup = false;
    static uint64_t seed = 0;

    if(!setup)
    {
        uint64_t hapSeed = generate_random();

        if(!hapSeed)
        {
            ATTN_DBG("falling back to timebase seed for PRNG");
        }
        else
        {
            ATTN_DBG("hapseed: %d", hapSeed);
        }

        seed = hapSeed ? hapSeed : getTB() + 1;

        setup = true;
    }

    uint64_t lo, hi;

    seed = seed * seed;
    lo = (seed & 0x0000ffffffff0000ull) >> 16;
    hi = (seed & 0x000000000000ffffull) << 32;
    hi |= (seed & 0xffff000000000000ull);
    seed = (lo | hi) + 2;

    static const uint64_t randMax = 0xfffffffffffffffe;
    uint64_t min = i_min, max = i_max;

    if(i_min > i_max)
    {
        swap(min, max);
    }

    if(max > randMax)
    {
        max = randMax;
    }

    return ((lo | hi) % (max +1 - min)) + min;
}

ATTENTION_VALUE_TYPE getRandomAttentionType()
{
    ATTENTION_VALUE_TYPE a;

    switch (randint(1, 5))
    {
        case 2:
            a = RECOVERABLE;
            break;
        case 3:
            a = SPECIAL;
            break;
        case 4:
            a = UNIT_CS;
            break;
        default:
            a = (ATTENTION_VALUE_TYPE)HOST_ATTN;
            break;
    };

    return a;
}
}
