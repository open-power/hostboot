/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attntest.C $
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
 * @file attntest.C
 *
 * @brief HBATTN test utility function definitions.
 */

#include <arch/ppc.H>
#include <algorithm>
#include "attntest.H"
#include "../attntrace.H"

using namespace std;

namespace ATTN
{

uint64_t randint(uint64_t i_min, uint64_t i_max)
{
    static bool setup = false;
    static uint64_t hapSeed = generate_random();

    if(!setup)
    {
        if(!hapSeed)
        {
            ATTN_DBG("falling back to timebase seed for PRNG");
        }
        else
        {
            ATTN_DBG("hapseed: %d", hapSeed);
        }

        setup = true;
    }

    static uint64_t seed = hapSeed ? hapSeed : getTB() + 1;

    uint64_t lo, hi;

    seed = seed * seed;
    lo = (seed & 0x0000ffffffff0000ull) >> 16;
    hi = (seed & 0x000000000000ffffull) << 32;
    hi |= (seed & 0xffff000000000000ull);
    seed = lo;

    uint64_t min = i_min, max = i_max;

    if(i_min > i_max)
    {
        swap(min, max);
    }

    return ((lo | hi) % (i_max +1 - i_min)) + i_min;
}
}
