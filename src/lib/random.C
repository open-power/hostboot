/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/random.C $                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

#include <arch/ppc.H>
#include <algorithm>
#include <util/random.H>

uint64_t randint(uint64_t i_min, uint64_t i_max)
{
    static bool setup = false;
    static uint64_t seed = 0;

    if(!setup)
    {
        uint64_t hapSeed = generate_random();

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
        std::swap(min, max);
    }

    if(max > randMax)
    {
        max = randMax;
    }

    return ((lo | hi) % (max +1 - min)) + min;
}
