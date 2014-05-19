/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/syscall.h $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
#ifndef __SYS_SYSCALL_H
#define __SYS_SYSCALL_H

/** @file syscall.h
 *  @brief Defines syscall wrapper functions to get C-caller to put syscall
 *         parameters in the correct spots for ABI so kernel can pull them
 *         from the right position in the task structs.
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <builtins.h>

// Normal system calls.
void* _syscall0(uint64_t);
void* _syscall1(uint64_t, void*);
void* _syscall2(uint64_t, void*, void*);
void* _syscall3(uint64_t, void*, void*, void*);
void* _syscall4(uint64_t, void*, void*, void*, void*);
void* _syscall5(uint64_t, void*, void*, void*, void*, void*);
void* _syscall6(uint64_t, void*, void*, void*, void*, void*, void*);
void* _syscall7(uint64_t, void*, void*, void*, void*, void*, void*, void*);

// System calls which never return.  Marked NO_RETURN so the compiler
// can make additional optimizations.
void* _syscall0_nr(uint64_t) NO_RETURN;
void* _syscall1_nr(uint64_t, void*) NO_RETURN;
void* _syscall2_nr(uint64_t, void*, void*) NO_RETURN;
void* _syscall3_nr(uint64_t, void*, void*, void*) NO_RETURN;
void* _syscall4_nr(uint64_t, void*, void*, void*, void*) NO_RETURN;
void* _syscall5_nr(uint64_t, void*, void*, void*, void*, void*) NO_RETURN;
void* _syscall6_nr(uint64_t, void*, void*, void*, void*, void*, void*)
            NO_RETURN;
void* _syscall7_nr(uint64_t, void*, void*, void*, void*, void*, void*, void*)
            NO_RETURN;

#ifdef __cplusplus
}
#include <kernel/syscalls.H>
#endif

#endif
