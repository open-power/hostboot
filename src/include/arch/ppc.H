/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/arch/ppc.H $                                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
inline uint64_t getHRMOR()
{
    register uint64_t hrmor = 0;
    asm volatile("mfspr %0, 313" : "=r" (hrmor));
    return hrmor;
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
    asm volatile("nap");
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

/** @brief  This is a special assembler instruction that is a nop on
 *  regular hardware, but has special meaning to Simics.  Code that
 *  executes this instruction in Simics will cause a "hap," a
 *  Simics term.  If there is no hap handler registered, and magic
 *  breakpoints have not been enabled with
 *      simics> enable-magic-breakpoint
 *  then this instruction is also a nop in Simics.
 *
 *  If magic breakpoints are enabled, and there is no hap handler, then
 *  when Hostboot code executes this instruction in Simics, Simics will
 *  stop the simulation. (Prompt changes from running> to simics> )
 *
 *  If a hap is registered, then Simics will call the hap handler.  Hap
 *  handlers are written in Python, and the best place for them is
 *
 *     src/build/debug/simics-debug-framework.py
 *
 *  Sample code to register the hap handler:
 *        # arg contains the integer parameter n passed to MAGIC_INSTRUCTION(n)
 *        def magic_instruction_callback(user_arg, cpu, arg):
 *            # print to console works...
 *            print "Hit magic instruction ", arg
 *            # Or else stop the simulation...
 *            SIM_break_simulation( "Stopped at magic instruction" )
 *
 *        # Register the magic instruction callback.
 *        SIM_hap_add_callback( "Core_Magic_Instruction", magic_instruction_callback, None )
 *
 *        # Better to register the Hostboot range 7000-7999
 *        # so that PHYP and others won't be affected.
 *        SIM_hap_add_callback_range( "Core_Magic_Instruction", magic_instruction_callback, None, 7000, 7999 )
 *
 *  The argument n is an integer from 0..8191 which Simics passes to the hap
 *  handler in parameter 3, or "arg" in the sample code above.
 */
ALWAYS_INLINE
inline void MAGIC_INSTRUCTION(int _n)
{
    register int n = _n;
    asm volatile("rlwimi %0,%0,0,%1,%2"       \
        :: "i" (((n) >> 8) & 0x1f),           \
        "i" (((n) >> 4) & 0xf),               \
        "i" ((((n) >> 0) & 0xf) | 16));
}

// Arguments to MAGIC_INSTRUCTION().
// To ensure they do not conflict with haps from other groups (PHYP
// for example), assign hap numbers in the range 7000..7999 (decimal).
// Presently, the hap handler for magic instruction is found in
// src/build/debug/simics-debug-framework.py
// Jan 2012 Monte

enum
{
    MAGIC_SIMICS_CORESTATESAVE = 10, // Indicate to the PHYP model of simics
                                     // that we are preparing to wake up a core
                                     // or thread.  This allows them to save
                                     // some state from the core doing the
                                     // wakeup to apply into the woken one.

    MAGIC_SHUTDOWN            =  7006, // KernelMisc::shutdown() called.
    MAGIC_BREAK               =  7007, // hard-code a breakpoint
    MAGIC_RANDOM              =  7008, // generate random number
    MAGIC_MEMORYLEAK_FUNCTION =  7009, // A memory was function called.
    MAGIC_FAKEPAYLOAD_ENTER   =  7010, // Entered the fake payload.
    MAGIC_CONTINUOUS_TRACE    =  7055, // extract mixed trace buffer
};


#endif
