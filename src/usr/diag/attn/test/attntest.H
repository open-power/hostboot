/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attntest.H $
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
#ifndef __TEST_ATTNTEST_H
#define __TEST_ATTNTEST_H

/**
 * @file attntest.H
 *
 * @brief HBATTN test utility function declarations.
 */

#include "../attnfwd.H"

namespace ATTN
{

class FakePresenter;

/**
 * @brief randint Generate random integer between bounds.
 *
 * @param[in] i_min The minimum bound.
 * @param[in] i_max The maximum bound.
 *
 * @return uint64_t Generated random integer.
 */
uint64_t randint(uint64_t i_min, uint64_t i_max);

/**
 * @brief generate_random Issue a magic instruction
 *        with a hap callback that fetches a random
 *        number from the simics host.
 *
 * @return uint64_t Random integer from simics host.
 */
extern "C" uint64_t generate_random();
}
#endif
