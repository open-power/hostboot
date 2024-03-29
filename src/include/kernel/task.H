/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/task.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2020                        */
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
/** @file task.H
 *  @brief Defines kernel information about tasks.
 */
#ifndef __KERNEL_TASK_H
#define __KERNEL_TASK_H

#include <kernel/types.h>


// Stop/Nap instruction
#define STOP_INSTRUCTION   0x4C0002E4
// Default PSSCR value for "STOP 2"
#define PSSCR_STOP2_VALUE  0x0000000000310002ull


/** @struct context_t
 *  @brief Defines the save-restore context for the task.
 *
 *  See PowerISA for information on registers listed.
 */
struct context_t
{
    void* stack_ptr;
    void* nip;
    uint64_t gprs[32];
    uint64_t lr;
    uint64_t cr;
    uint64_t ctr;
    uint64_t xer;
    uint64_t msr_mask; // XOR mask applied to MSR.
};

/** @struct context_fp_t
 *  @brief Defines the save-restore context for the floating point registers
 *         associated with a task.
 *
 *  See PowerISA for information on registers listed.
 */
struct context_fp_t
{
    uint64_t fprs[32];
    uint64_t fpscr;
};

enum task_states
{
        /** Task is currently running. */
    TASK_STATE_RUNNING          = 'R',
        /** Task is on scheduler queue ready to run. */
    TASK_STATE_READY            = 'r',
        /** Task has ended or crashed. */
    TASK_STATE_ENDED            = 'E',

        /** Task is blocked on a futex. */
    TASK_STATE_BLOCK_FUTEX      = 'f',
        /** Task is blocked on a message queue. */
    TASK_STATE_BLOCK_MSG        = 'M',
        /** Task is defered due to a kernel->userspace request. */
    TASK_STATE_BLOCK_USRSPACE   = 'u',
        /** Task is blocked sleeping. */
    TASK_STATE_BLOCK_SLEEP      = 's',
        /** Task is blocked on join. */
    TASK_STATE_BLOCK_JOIN       = 'j',
};

    // Forward declaration.
struct task_tracking_t;

/** @struct task_t
 *  @brief The kernel-level task structure.
 */
struct task_t
{
        /** Pointer to the CPU this task is assigned to. */
    cpu_t* cpu;
        /** Context information.  This MUST stay here due to
         *  save-restore asm code. */
    context_t context;
        /** Pointer to optional floating point context. */
    context_fp_t* fp_context;
        /** Thread-local-storage area for userspace. */
    void* tls_context;

        /** Task ID */
    tid_t tid;
        /** Determines if user-space would like this task pinned to a CPU.
         *  This value is considered a count of the number of times the pinned
         *  as been requested, so pinning can be used recursively. */
    uint64_t affinity_pinned;

        /** State of task */
    task_states state:8;
        /** Extra info about the state.
         *  This is used when the task is blocked to give a pointer to the
         *  object the task is blocked on. */
    void* state_info;

        /** Pointer to tracking tree for joining, parent info, etc. */
    task_tracking_t* tracker;

        /** Detached state of the task. */
    bool detached;

        /** Determine if the task should tolerate memory UEs. */
    bool tolerate_ue;

        // Pointers for queue containers.
    task_t* prev;
    task_t* next;
};

// Macros for manipulating task's saved contexts.
#define TASK_GETARGN(t, n) (t->context.gprs[n+4])
#define TASK_GETARG0(t) (TASK_GETARGN(t,0))
#define TASK_GETARG1(t) (TASK_GETARGN(t,1))
#define TASK_GETARG2(t) (TASK_GETARGN(t,2))
#define TASK_GETARG3(t) (TASK_GETARGN(t,3))
#define TASK_GETARG4(t) (TASK_GETARGN(t,4))
#define TASK_GETARG5(t) (TASK_GETARGN(t,5))
#define TASK_GETARG6(t) (TASK_GETARGN(t,6))
#define TASK_GETARG7(t) (TASK_GETARGN(t,7))
#define TASK_SETRTN(t, n) (t->context.gprs[3] = (n))


#endif
