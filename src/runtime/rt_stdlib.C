/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_stdlib.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <stdlib.h>
#include <runtime/interface.h>
#include <string.h>

void* malloc(size_t s)
{
    return g_hostInterfaces->malloc(s);
}

void free(void* p)
{
    g_hostInterfaces->free(p);
}

void* realloc(void* p, size_t s)
{
    return g_hostInterfaces->realloc(p, s);
}

void* calloc(size_t num, size_t size)
{
    // Allocate a block of memory for an array of 'num' elements, each of them
    // 'size' bytes long and initialize to zero
    size_t total_size = num * size;
    void* mem = NULL;

    if (total_size)
    {
        mem = malloc(total_size);
        memset(mem, 0, total_size);
    }

    return mem;
}
