//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/sys/syscall.h $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __SYS_SYSCALL_H
#define __SYS_SYSCALL_H

#ifdef __cplusplus
extern "C" 
{
#endif

#include <stdint.h>

void* _syscall0(uint64_t);
void* _syscall1(uint64_t, void*);
void* _syscall2(uint64_t, void*, void*);
void* _syscall3(uint64_t, void*, void*, void*);
void* _syscall4(uint64_t, void*, void*, void*, void*);
void* _syscall5(uint64_t, void*, void*, void*, void*, void*);
void* _syscall6(uint64_t, void*, void*, void*, void*, void*, void*);
void* _syscall7(uint64_t, void*, void*, void*, void*, void*, void*, void*);

#ifdef __cplusplus
}
#include <kernel/syscalls.H>
#endif

#endif
