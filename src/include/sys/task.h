#ifndef __SYS_TASK_H
#define __SYS_TASK_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" 
{
#endif

typedef uint64_t tid_t;

void task_yield();
tid_t task_create(void(*)(void*), void*);
void task_end();

tid_t task_gettid();

#ifdef __cplusplus
}
#endif
#endif
