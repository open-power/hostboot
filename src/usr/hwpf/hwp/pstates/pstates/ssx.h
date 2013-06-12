/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/ssx.h $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __SSX_H__
#define __SSX_H__

// $ID$

/// \file ssx.h
/// \brief Dummy "ssx.h" for X86 testing

#define __SSX__

#ifndef __ASSEMBLER__
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#endif    /* __ASSEMBLER__ */

#ifndef __ASSEMBLER__

#define MIN(X, Y) \
    ({ \
    typeof (X) __x = (X); \
    typeof (Y) __y = (Y); \
    (__x < __y) ? __x : __y; })

#define MAX(X, Y) \
    ({ \
    typeof (X) __x = (X); \
    typeof (Y) __y = (Y); \
    (__x > __y) ? __x : __y; \
    })

#endif    /* __ASSEMBLER__ */


#define SSX_ERROR_CHECK_API    1
#define SSX_ERROR_CHECK_KERNEL 1
#define SSX_ERROR_PANIC        1

#define SSX_NONCRITICAL 0
#define SSX_CRITICAL    1

#define SSX_INVALID_ARGUMENT           0x00888005
#define SSX_INVALID_OBJECT             0x0088800e

typedef int SsxMachineContext;

static inline void
ssx_critical_section_enter(int priority, SsxMachineContext *ctx)
{}

static inline void
ssx_critical_section_exit(SsxMachineContext *ctx)
{}


#define SSX_PANIC(code) \
    do { \
    fprintf(stderr, "%s : %d  : PANIC : 0x%08x\n", \
        __FUNCTION__, __LINE__, code);           \
    exit(1); \
    } while (0)


/// This macro encapsulates error handling boilerplate in the SSX API
/// functions, for errors that do not occur in critical sections.

#define SSX_ERROR_IF(condition, code) \
    if (condition) { \
    if (SSX_ERROR_PANIC) { \
        SSX_PANIC(code);   \
    } else { \
        return -(code); \
    } \
    }

#define printk(...) printf(__VA_ARGS__)

#endif    /* __SSX_H__ */
