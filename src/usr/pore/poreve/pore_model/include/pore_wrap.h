/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/include/pore_wrap.h $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __PORE_TRACE_H__
#define __PORE_TRACE_H__

/**
 * @file   pore_interface.h (for HostBoot environment)
 * @Author Thi Tran
 * @date   October, 2011
 *
 * @brief Trace functions for the Virtual Power-On-Reset Engine vPORe.
 * Since different users of this code use different ways of tracing,
 * It should be possible to replace the pore_model tracing with a
 * private version. In this file we use libc printfs to trace the flow
 * of the code if needed.
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <trace/interface.H>
#include <endian.h>

#ifdef __cplusplus
extern "C" {
#endif

extern trace_desc_t* g_poreDbgTd;
extern trace_desc_t* g_poreErrTd;

#ifndef htobe32
# if __BYTE_ORDER == __LITTLE_ENDIAN
#  define htobe32(x) __bswap_32 (x)
#  define htole32(x) (x)
#  define be32toh(x) __bswap_32 (x)
#  define le32toh(x) (x)

#  define htobe64(x) __bswap_64 (x)
#  define htole64(x) (x)
#  define be64toh(x) __bswap_64 (x)
#  define le64toh(x) (x)
# else
#  define htobe32(x) (x)
#  define htole32(x) __bswap_32 (x)
#  define be32toh(x) (x)
#  define le32toh(x) __bswap_32 (x)

#  define htobe64(x) (x)
#  define htole64(x) __bswap_64 (x)
#  define be64toh(x) (x)
#  define le64toh(x) __bswap_64 (x)
# endif
#endif

/** Using the following macros should help to adopt the code to
    different environments. */
#define pore_htobe64(x) htobe64(x)
#define pore_be64toh(x) be64toh(x)
#define pore_htobe32(x) htobe32(x)
#define pore_be32toh(x) be32toh(x)

// Debug trace
// '((void)p);' is to avoid unused variable error when compiling
#define printf(fmt, args...)        TRACFCOMP(g_poreDbgTd, fmt, ##args)
#define aprintf(fmt, args...)       TRACDCOMP(g_poreDbgTd, fmt, ##args)
#define eprintf(p, fmt, args...)    ((void)p); TRACDCOMP(g_poreDbgTd, fmt, ##args)
#define dprintf(p, fmt, args...)    ((void)p); TRACDCOMP(g_poreDbgTd, fmt, ##args)
#define bprintf(p, fmt, args...)    ((void)p); TRACDCOMP(g_poreDbgTd, fmt, ##args)
#define iprintf(p, fmt, args...)    ((void)p); TRACDCOMP(g_poreDbgTd, fmt, ##args)
#define pib_printf(p, fmt, args...) ((void)p); TRACDCOMP(g_poreDbgTd, fmt, ##args)
#define mem_printf(p, fmt, args...) ((void)p); TRACDCOMP(g_poreDbgTd, fmt, ##args)

// Diagnostic aid
#define BUG() \
    TRACFCOMP(g_poreErrTd, ">>> Bug trapped at %s:%d", \
    __FILE__, __LINE__ )

#ifdef __cplusplus
}
#endif

#endif /* __PORE_TRACE_H__ */
