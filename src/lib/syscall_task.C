//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/lib/syscall_task.C $
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
#include <sys/task.h>
#include <sys/syscall.h>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>
#include <sys/vfs.h>
#include <sys/msg.h>

using namespace Systemcalls;

void task_yield()
{
    _syscall0(TASK_YIELD);
    return;
}

tid_t task_create(void(*fn)(void*), void* ptr)
{
    // Verify we have (memory) permissions to load the function pointer so
    // we don't load bad memory from kernel space.
    register uint64_t function = (uint64_t) fn;
    asm volatile("ld %0, 0(%1)" : "=b"(function) : "b" (function));

    return (tid_t)(uint64_t) _syscall2(TASK_START, (void*)fn, ptr);
}

void task_end()
{
    _syscall0(TASK_END); // no return.
    return;
}

tid_t task_gettid()
{
    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));
    return task->tid;
}

cpuid_t task_getcpuid()
{
    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));
    return task->cpu->cpu;
}

tid_t task_exec(const char* file, void* ptr)
{
    // The VFS process is responsible for finding the module and creating the
    // new process.  So, we send a message over to that process.
    
    tid_t child = -1; 
    
    // Create message, send.
    msg_q_t vfsQ = (msg_q_t)_syscall0(MSGQ_RESOLVE_ROOT);
    msg_t* msg = msg_allocate();
    msg->type = VFS_MSG_EXEC;
    msg->data[0] = (uint64_t) file;
    msg->data[1] = (uint64_t) ptr;
    int rc = msg_sendrecv(vfsQ, msg);

    if (0 == rc)
    {
	// Get child ID from message data 0.
	child = (tid_t) msg->data[0];
    }
    else
    {
	child = rc;
    }
    
    msg_free(msg);
    return child;
}

void task_affinity_pin()
{
    // Get task structure.
    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));

    // Increment pin count.
    __sync_add_and_fetch(&task->affinity_pinned, 1);
}

void task_affinity_unpin()
{
    // Get task structure.
    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));

    // Decrement pin count.
    __sync_sub_and_fetch(&task->affinity_pinned, 1);
}
