#ifndef __KERNEL_USERMUTEX_H
#define __KERNEL_USERMUTEX_H

#include <util/locked/queue.H>
#include <kernel/spinlock.H>
#include <kernel/task.H>

struct UserMutex
{
    uint64_t value;
    bool unlock_pend;
    Spinlock lock;
    Util::Locked::Queue<task_t> waiting;

    UserMutex() : value(0), unlock_pend(false) {};
};

#endif
