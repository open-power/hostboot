/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/stdlib.h $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#ifndef __STDLIB_H
#define __STDLIB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void* malloc(size_t) __attribute__((malloc));
void free(void*);
void* realloc(void*, size_t);
void* calloc(size_t, size_t) __attribute__((malloc));

/**
 * @brief converts a given char string to uint64_t
 *
 * @param[in] nptr input string in the form of pointer to char
 * @param[in] endptr UNUSED
 * @param[in] base UNUSED (always base 16)
 * @return the uint64_t representation of the input string or 0
 *         if the function failed to convert
 */
uint64_t strtoul(const char *nptr, char **endptr, int base);

/**
 * @brief Returns the absolute value of parameter n ( /n/ )
 * See C spec for details
 */
int abs(int n);

#ifdef __cplusplus
};
#endif

#endif
