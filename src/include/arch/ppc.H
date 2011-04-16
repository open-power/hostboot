#ifndef __KERNEL_PPCARCH_H
#define __KERNEL_PPCARCH_H

#include <kernel/types.h>
#include <builtins.h>

ALWAYS_INLINE
inline uint64_t getSRR0() 
{
    register uint64_t srr0 = 0;
    asm volatile("mfsrr0 %0" : "=r" (srr0));
    return srr0;
} 

ALWAYS_INLINE
inline uint64_t getSRR1() 
{
    register uint64_t srr1 = 0;
    asm volatile("mfsrr1 %0" : "=r" (srr1));
    return srr1;
}

ALWAYS_INLINE
inline void setSRR0(uint64_t _srr0) 
{
    register uint64_t srr0 = _srr0;
    asm volatile("mtsrr0 %0" : : "r" (srr0));
} 

ALWAYS_INLINE
inline void setSRR1(uint64_t _srr1) 
{
    register uint64_t srr1 = _srr1;
    asm volatile("mtsrr1 %0" : : "r" (srr1));
} 

ALWAYS_INLINE
inline uint64_t getPVR() 
{
    register uint64_t pvr = 0;
    asm volatile("mfspr %0, 287" : "=r" (pvr));
    return pvr;
}

ALWAYS_INLINE
inline uint64_t getPIR() 
{
    register uint64_t pir = 0;
    asm volatile("mfspr %0, 1023" : "=r" (pir));
    return pir;
}

ALWAYS_INLINE
inline uint64_t getSPRG3()
{
    register uint64_t sprg3 = 0;
    asm volatile("mfsprg3 %0" : "=r" (sprg3));
    return sprg3;
}

ALWAYS_INLINE
inline void setSPRG3(uint64_t _sprg3)
{
    register uint64_t sprg3 = _sprg3;
    asm volatile("mtsprg3 %0" : : "r" (sprg3));
    return;
}

ALWAYS_INLINE
inline uint64_t getMSR()
{
    register uint64_t msr = 0;
    asm volatile("mfmsr %0" : "=r" (msr));
    return msr;
}

ALWAYS_INLINE
inline void setMSR(uint64_t _msr)
{
    register uint64_t msr = _msr;
    asm volatile("mtmsr %0; isync" :: "r" (msr));
}

ALWAYS_INLINE
inline uint64_t getDSISR()
{
    register uint64_t dsisr = 0;
    asm volatile("mfspr %0, 18" : "=r" (dsisr));
    return dsisr;
}

ALWAYS_INLINE
inline uint64_t getDAR()
{
    register uint64_t dar = 0;
    asm volatile("mfspr %0, 19" : "=r" (dar));
    return dar;
}

ALWAYS_INLINE
inline uint64_t getTB()
{
    register uint64_t tb = 0;
    asm volatile("mfspr %0, 268" : "=r" (tb));
    return tb;
}

ALWAYS_INLINE
inline void setDEC(uint64_t _dec)
{
    register uint64_t dec = _dec;
    asm volatile("mtdec %0" :: "r" (dec));
}

ALWAYS_INLINE
inline void sync()
{
    asm volatile("sync");
}

ALWAYS_INLINE
inline void lwsync()
{
    asm volatile("lwsync");
}

ALWAYS_INLINE
inline void isync()
{
    asm volatile("isync");
}

ALWAYS_INLINE
inline void eieio()
{
    asm volatile("eieio");
}

ALWAYS_INLINE
inline uint64_t getHMER() 
{
    register uint64_t hmer = 0;
    asm volatile("mfspr %0, 336" : "=r" (hmer));
    return hmer;
}

ALWAYS_INLINE
inline void setHMER(uint64_t _hmer)
{
    register uint64_t hmer = _hmer;
    asm volatile("mtspr 336, %0" : : "r" (hmer));
    return;
}

ALWAYS_INLINE
inline void setThreadPriorityLow()
{	
    asm volatile("or 1,1,1");
}

ALWAYS_INLINE
inline void setThreadPriorityHigh()
{
    asm volatile("or 3,3,3");
}

ALWAYS_INLINE
inline void dcbf(void* _ptr)
{
    register void* ptr = _ptr;
    asm volatile("dcbf 0, %0" : : "b" (ptr) : "memory");
}

ALWAYS_INLINE
inline void dcbz(void* _ptr)
{
    register void* ptr = _ptr;
    asm volatile("dcbz 0, %0" : : "b" (ptr) : "memory");
}

ALWAYS_INLINE
inline void icbi(void* _ptr)
{
    register void* ptr = _ptr;
    asm volatile("icbi 0, %0" : : "b" (ptr) : "memory");
}

#endif
