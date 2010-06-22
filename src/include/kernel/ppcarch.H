#ifndef __KERNEL_PPCARCH_H
#define __KERNEL_PPCARCH_H

#include <kernel/types.h>

__attribute__((always_inline))
inline uint64_t ppc_getSRR1() 
{
    register uint64_t srr1 = 0;
    asm volatile("mfsrr1 %0" : "=r" (srr1));
    return srr1;
} 

#endif
