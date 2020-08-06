/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/extern/alloc.c $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */

#include <assert.h>

#include "libmctp.h"
#include "libmctp-alloc.h"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


struct {
    void *(*m_alloc)(size_t);
    void (*m_free)(void *);
    void *(*m_realloc)(void *, size_t);
} alloc_ops = {
    malloc,
    free,
    realloc,
};

/* internal-only allocation functions */
void *__mctp_alloc(size_t size)
{
	if (alloc_ops.m_alloc)
		return alloc_ops.m_alloc(size);
	if (alloc_ops.m_realloc)
		return alloc_ops.m_realloc(NULL, size);
	assert(0);
}

void __mctp_free(void *ptr)
{
	if (alloc_ops.m_free)
		alloc_ops.m_free(ptr);
	else if (alloc_ops.m_realloc)
		alloc_ops.m_realloc(ptr, 0);
	else
		assert(0);
}

void *__mctp_realloc(void *ptr, size_t size)
{
	if (alloc_ops.m_realloc)
		return alloc_ops.m_realloc(ptr, size);
	assert(0);
}

void mctp_set_alloc_ops(void *(*m_alloc)(size_t),
		void (*m_free)(void *),
		void *(m_realloc)(void *, size_t))
{
	alloc_ops.m_alloc = m_alloc;
	alloc_ops.m_free = m_free;
	alloc_ops.m_realloc = m_realloc;
}
