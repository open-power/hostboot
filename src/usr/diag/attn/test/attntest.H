/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attntest.H $                           */
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
#ifndef __TEST_ATTNTEST_H
#define __TEST_ATTNTEST_H

/**
 * @file attntest.H
 *
 * @brief HBATTN test utility function declarations.
 */

#include "../attnfwd.H"
#include <map>

namespace ATTN
{

class FakePresenter;
struct AttnDataSwo;
struct AttnDataEq;
class FakeSystem;
class FakeReg;
class FakeSource;
class InjectSink;

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

/**
 * @brief AttnDataMap
 *
 * AttnData as key map template.
 */
template <typename T>
    class AttnDataMap :
        public std::map<PRDF::AttnData, T, AttnDataSwo>
    {

    };

/**
 * @brief getRandomAttentionType
 *
 * Obtain a random attention type.
 *
 * @return The generated attention type.
 */
PRDF::ATTENTION_VALUE_TYPE getRandomAttentionType();
}
#endif
