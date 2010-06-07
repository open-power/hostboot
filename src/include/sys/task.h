#ifndef __SYS_TASK_H
#define __SYS_TASK_H

#include <sys/syscall.h>

#ifdef __cplusplus
extern "C" 
{
#endif

void task_yield();
int task_create(void(*)(void*), void*);
void task_end();

uint64_t task_gettid();

#ifdef __cplusplus
}
#endif
#endif
