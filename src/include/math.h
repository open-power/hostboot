/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/math.h $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
#include <stdint.h>
#include <builtins.h>

#ifndef _MATH_H
#define _MATH_H

#ifdef __cplusplus
extern "C"
{
#endif

ALWAYS_INLINE
static inline int64_t log2(uint64_t s)
{
    int64_t n = cntlzd(s);
    return 63-n;
}

double sqrt(double) __attribute__((const));

/**
 * @brief  power function
 *
 * @param[in] base - value of base
 * @param[in] exp  - value of exponential
 *
 * @return value of the value of base raised to the power of exp.
 *
 */
uint64_t pow(const uint32_t base, const uint32_t exp);

#ifdef __cplusplus
};
#endif

#endif
