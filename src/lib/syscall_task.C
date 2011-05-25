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
    // Even though we have a syscall for GETTID, we also have the task in 
    // GRP13.

    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));
    return task->tid;
    //return (tid_t)_syscall0(TASK_GETTID);
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
