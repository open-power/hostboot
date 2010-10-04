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

__attribute__((always_inline))
inline uint64_t ppc_getPVR() 
{
    register uint64_t pvr = 0;
    asm volatile("mfspr %0, 287" : "=r" (pvr));
    return pvr;
}

__attribute__((always_inline))
inline uint64_t ppc_getPIR() 
{
    register uint64_t pir = 0;
    asm volatile("mfspr %0, 1023" : "=r" (pir));
    return pir;
}

__attribute__((always_inline))
inline uint64_t ppc_getSPRG3()
{
    register uint64_t sprg3 = 0;
    asm volatile("mfsprg3 %0" : "=r" (sprg3));
    return sprg3;
}

__attribute__((always_inline))
inline void ppc_setSPRG3(uint64_t _sprg3)
{
    register uint64_t sprg3 = _sprg3;
    asm volatile("mtsprg3 %0" : : "r" (sprg3));
    return;
}

__attribute__((always_inline))
inline uint64_t ppc_getMSR()
{
    register uint64_t msr = 0;
    asm volatile("mfmsr %0" : "=r" (msr));
    return msr;
}

__attribute__((always_inline))
inline void ppc_setMSR(uint64_t _msr)
{
    register uint64_t msr = _msr;
    asm volatile("mtmsr %0; isync" :: "r" (msr));
}

__attribute__((always_inline))
inline uint64_t ppc_getDSISR()
{
    register uint64_t dsisr = 0;
    asm volatile("mfspr %0, 18" : "=r" (dsisr));
    return dsisr;
}

__attribute__((always_inline))
inline uint64_t ppc_getDAR()
{
    register uint64_t dar = 0;
    asm volatile("mfspr %0, 19" : "=r" (dar));
    return dar;
}

__attribute__((always_inline))
inline uint64_t ppc_getTB()
{
    register uint64_t tb = 0;
    asm volatile("mfspr %0, 268" : "=r" (tb));
    return tb;
}



#endif
