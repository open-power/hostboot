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
#endif

#include <kernel/syscalls.H>
#endif
