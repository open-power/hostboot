#ifndef __SYS_TASK_H
#define __SYS_TASK_H

#include <stdint.h>
#include <kernel/types.h>

#ifdef __cplusplus
extern "C" 
{
#endif

void task_yield();
tid_t task_create(void(*)(void*), void*);
void task_end();

tid_t task_gettid();
cpuid_t task_getcpuid();

tid_t task_exec(const char*, void*);

#ifdef __cplusplus
}
#endif
#endif
