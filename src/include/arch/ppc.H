/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/ppc.H $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
/* [+] Google Inc.                                                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
inline uint64_t getHSRR0()
{
    register uint64_t hsrr0 = 0;
    asm volatile("mfspr %0, 314" : "=r" (hsrr0));
    return hsrr0;
}

ALWAYS_INLINE
inline uint64_t getHSRR1()
{
    register uint64_t hsrr1 = 0;
    asm volatile("mfspr %0, 315" : "=r" (hsrr1));
    return hsrr1;
}

ALWAYS_INLINE
inline void setHSRR0(uint64_t _hsrr0)
{
    register uint64_t hsrr0 = _hsrr0;
    asm volatile("mtspr 314, %0" : : "r" (hsrr0));
}

ALWAYS_INLINE
inline void setHSRR1(uint64_t _hsrr1)
{
    register uint64_t hsrr1 = _hsrr1;
    asm volatile("mtspr 315, %0" : : "r" (hsrr1));
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
inline uint64_t getSPRG2()
{
    register uint64_t sprg2 = 0;
    asm volatile("mfsprg2 %0" : "=r" (sprg2));
    return sprg2;
}

ALWAYS_INLINE
inline void setSPRG2(uint64_t _sprg2)
{
    register uint64_t sprg2 = _sprg2;
    asm volatile("mtsprg2 %0" : : "r" (sprg2));
    return;
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
inline void setTB(uint64_t _tb)
{
    // The bottom 24 bits of the timebase can't be written so round it up.
    register uint64_t tb = (_tb + 0x1000000);
    // Note that SPR 286 is intended (while getTB is 268) here.
    // This is the mttbu40 instruction and not the mttb, which doesn't exist.
    asm volatile("mtspr 286, %0" :: "r" (tb));
}

ALWAYS_INLINE
inline void setDEC(uint64_t _dec)
{
    register uint64_t dec = _dec;
    asm volatile("mtdec %0" :: "r" (dec));
}

ALWAYS_INLINE
inline void setRPR(uint64_t _rpr)
{
    register uint64_t rpr = _rpr;
    asm volatile("mtspr 186, %0" :: "r"(rpr));
}

ALWAYS_INLINE
inline void sync()
{
    asm volatile("sync" ::: "memory");
}

ALWAYS_INLINE
inline void lwsync()
{
    asm volatile("lwsync" ::: "memory");
}

ALWAYS_INLINE
inline void isync()
{
    asm volatile("isync" ::: "memory");
}

ALWAYS_INLINE
inline void eieio()
{
    asm volatile("eieio" ::: "memory");
}

ALWAYS_INLINE
inline void msgsync()
{
    // See POWER ISA 5.9.2 for details
    asm volatile("msgsync" ::: "memory");

    // TODO RTC 245393: Still needed for p10?
    // There is a P9 DD2 workaround that a lwsync is also required
    //  after a msgsync
    asm volatile("lwsync" ::: "memory");
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
inline uint64_t getHEIR()
{
    register uint64_t heir = 0;
    asm volatile("mfspr %0, 339" : "=r" (heir));
    return heir;
}

ALWAYS_INLINE
inline uint64_t getLPCR()
{
    register uint64_t lpcr = 0;
    asm volatile("mfspr %0, 318" : "=r" (lpcr));
    return lpcr;
}

ALWAYS_INLINE
inline void setLPCR(uint64_t _lpcr)
{
    register uint64_t lpcr = _lpcr;
    asm volatile("mtspr 318, %0; isync" :: "r" (lpcr));
}

ALWAYS_INLINE
inline uint64_t getLPIDR()
{
    register uint64_t lpidr = 0;
    asm volatile("mfspr %0, 319" : "=r" (lpidr));
    return lpidr;
}

ALWAYS_INLINE
inline void setLPIDR(uint64_t _lpidr)
{
    register uint64_t lpidr = _lpidr;
    asm volatile("mtspr 319, %0; isync" :: "r" (lpidr));
}

ALWAYS_INLINE
inline uint64_t getHRMOR()
{
    register uint64_t hrmor = 0;
    asm volatile("mfspr %0, 313" : "=r" (hrmor));
    return hrmor;
}

ALWAYS_INLINE
inline uint64_t getURMOR()
{
    register uint64_t urmor = 0;
    asm volatile("mfspr %0, 505" : "=r" (urmor));
    return urmor;
}

ALWAYS_INLINE
inline uint64_t getPTCR()
{
    register uint64_t ptcr = 0;
    asm volatile("mfspr %0, 464" : "=r" (ptcr));
    return ptcr;
}

ALWAYS_INLINE
inline void setPTCR(uint64_t _ptcr)
{
    register uint64_t ptcr = _ptcr;
    asm volatile("mtspr 464, %0; isync" :: "r" (ptcr));
}

ALWAYS_INLINE
inline void setThreadPriorityLow()
{
    asm volatile("or 1,1,1");
}

ALWAYS_INLINE
inline void setThreadPriorityHigh()
{
    asm volatile("or 2,2,2");
}

ALWAYS_INLINE
inline void setThreadPriorityVeryHigh()
{
    asm volatile("or 7,7,7");
}


ALWAYS_INLINE
inline void dcbf(void* _ptr)
{
    register void* ptr = _ptr;
    asm volatile("dcbf 0, %0" : : "b" (ptr) : "memory");
}

ALWAYS_INLINE
inline void dcbst(void* _ptr)
{
    register void* ptr = _ptr;
    asm volatile("dcbst 0, %0" : : "b" (ptr) : "memory");
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

ALWAYS_INLINE
inline void nap()
{
    asm volatile("stop");
}

ALWAYS_INLINE
inline void setPSSCR(uint64_t _psscr)
{
    register uint64_t psscr = _psscr;
    asm volatile("mtspr 855, %0; isync" :: "r" (psscr));
}

ALWAYS_INLINE
inline uint64_t getPSSCR()
{
    register uint64_t psscr = 0;
    asm volatile("mfspr %0, 855" : "=r" (psscr));
    return psscr;
}

ALWAYS_INLINE
inline uint64_t getHID()
{
    register uint64_t hid = 0;
    asm volatile("mfspr %0, 1008" : "=r" (hid));
    return hid;
}

ALWAYS_INLINE
inline void setHID(uint64_t _hid)
{
    register uint64_t hid = _hid;
    asm volatile("mtspr 1008, %0; isync" :: "r" (hid));
}

ALWAYS_INLINE
inline size_t getCacheLineBytes()
{
    return 128;
}

ALWAYS_INLINE
inline size_t getCacheLineWords()
{
    return getCacheLineBytes() / sizeof(uint64_t);
}

ALWAYS_INLINE
inline void writeScratchReg(uint64_t _scratch_addr, uint64_t _data)
{
    register uint64_t scratch_addr = _scratch_addr;
    register uint64_t data = _data;

    asm volatile("mtspr 276, %0\n"
                 "isync\n"
                 "mtspr 277, %1"
                 :: "r" (scratch_addr), "r" (data));

}

// The DARN instruction produces this value upon failure (even in 32-bit
// mode).
static const uint64_t DARN_FAILURE = 0xFFFFFFFFFFFFFFFFull;

/* @note The NCU for the core that executes this instruction must be set up
 *       beforehand with p10_ncu_enable_darn, otherwise the core will checkstop.
 */
ALWAYS_INLINE
inline uint64_t darn()
{
    uint64_t value = 0;

    // Use the DARN instruction to generate a 64-bit random number. The
    // value 1 as the second operand requests a 64-bit "conditioned" random
    // number (other values are 0 for 32-bit conditioned number, and 2 for
    // 64-bit unconditioned number). The "volatile" qualifier is imperative
    // on this asm block, as without it GCC will assume that DARN produces
    // the same output on repeated executions and possibly optimize it
    // incorrectly.
    asm volatile ("darn %0, 1" : "=r" (value));

    return value;
}

#endif
