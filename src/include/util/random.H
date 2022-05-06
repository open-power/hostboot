/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/random.H $                                   */
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

#ifndef __RANDOM_H
#define __RANDOM_H

#include <stdint.h>

/**
 * @file interface for random int generation. NOTE: Can only be used in simics
 */

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

#endif
