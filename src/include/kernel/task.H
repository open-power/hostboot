#ifndef __KERNEL_TASK_H
#define __KERNEL_TASK_H

#include <kernel/types.h>

struct context_t
{
    void* stack_ptr;
    void* nip;
    uint64_t gprs[32];
    uint64_t lr;
    uint64_t cr;
    uint64_t ctr;
    uint64_t xer;
};

struct task_t
{
    cpu_t* cpu;
    context_t context;
    
    tid_t tid;
    task_t* prev;
    task_t* next;
};

enum { TASK_DEFAULT_STACK_SIZE = 4 };

#endif
