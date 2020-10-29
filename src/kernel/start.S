# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/kernel/start.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2020
# [+] International Business Machines Corp.
# [+] Joel Stanley
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG

.include "kernel/ppcconsts.S"

.section .text.intvects

.global _start
_start:
    ;// Set thread priority high.
    or 2,2,2

    ;// Clear MSR[TA] (bit 1)
    mfmsr r2
    rldicl r2,r2,1,1    ;// Clear bit 1 - result [1-63,0]
    rotrdi r2,r2,1      ;// Rotate right 1 - result [0,63]
    ;// Set up SRR0 / SRR1 to enable new MSR.
    mtsrr1 r2
    li r2, _start_postmsr@l
    mtsrr0 r2
    lis     r9,49      ;// Want to default the NAP value
    ori     r9,r9,1    ;// Value is 0x0000000000310001
    mtspr   855,r9     ;// set actual PSSCR
    rfid

_start_postmsr:

    ;// Determine if this is the first thread.
    li r4, 2
    ;// Read spinlock value.
    lis r2, kernel_other_thread_spinlock@h
    ori r2, r2, kernel_other_thread_spinlock@l
    lwsync
1:
    ldarx r3, 0, r2
    cmpwi r3, 0 ;// Non-zero means this thread wasn't first.
    bnel cr0, _other_thread_spinlock
    stdcx. r4, 0, r2    ;// Attempt to store 2.
    bne 1b ;// Loop until sucessful at stwcx.
    isync

    b _main
/*
    ;// Relocate code
    bl pre_relocate     ;// fill LR with address
pre_relocate:
    mflr r2
    lis r1,0x0010
    cmpl cr0,r2,r1              ;// Check LR is less than 1MB
    blt finished_relocate       ;// No need to relocate if less than 1MB

    ;// Get addresses for relocation.
    ;// Write address in r5
    ;// Read address in r1
    li r5,0
    lis r1, -1  ;// fill r1 with ffff..ff0000

    and r1,r1,r2 ;// and with pre_relocate's address from r2 to get start of
                 ;// rom section.

    ;// Update LR to low address.
    clrldi r2,r2,48  ;// Equiv to ~(0x0FFFF)
    mtlr 2

    ;// Moving 1MB , so load r2 with (1MB / 8 bytes per word)
    lis r2, 0x2
    mtctr r2
relocate_loop:
    ;// The dcbst/sync/icbi/isync sequence comes from PowerISA
    ld r4, 0(r1)
    std r4, 0(r5)
    dcbst 0,r5
    sync
    icbi 0,r5
    isync
    addi r1,r1,8
    addi r5,r5,8
    bdnz+ relocate_loop

    ;// Now that we've relocated, erase exception prefix.
    mfmsr r11

    rldicl r11,r11,57,1  ;// Erase bit 6 ( equiv to r11 & ~(0x40))
    rotldi r11,r11,7

    mtmsr r11

    ;// Jump to low address.
    blr

finished_relocate:
    ;// Jump to main.
    b _main
*/

;// Interrupt vectors.

#define UNIMPL_INTERRUPT(name, address) \
        .org _start + address; \
        UNIMPL_INTERRUPT_NOADDR(name, address)

#define UNIMPL_INTERRUPT_STUB(name, address) \
        .org _start + address; \
        b intvect_unimpl_##name;

#define UNIMPL_INTERRUPT_NOADDR(name, address) \
    intvect_unimpl_##name: \
        or 2,2,2; /* Ensure thread priority is high. */ \
        mtsprg0 r1; /* Save GRP1 */ \
        li r1, address; /* Save exception address. */ \
        mtsprg2 r1; /* Move exception address to SPRG2 */ \
            ;/* Retrieve processing address for interrupt. */ \
        lis r1, intvect_unhandled_finish_save@h; \
        ori r1, r1, intvect_unhandled_finish_save@l; \
            ;/* Save processing address in SPRG0 */ \
        mtsprg0 r1; \
        mfsprg1 r1; /* Restore GPR1 */ \
        b kernel_save_task ; /* Save current task. */

#define STD_INTERRUPT(name, address) \
        .org _start + address; \
        STD_INTERRUPT_NOADDR(name)

#define STD_INTERRUPT_STUB(name, address) \
        .org _start + address; \
    intvect_stub_##name: \
        b intvect_##name;

#define STD_INTERRUPT_NOADDR(name) \
    intvect_##name: \
        or 2,2,2; /* Ensure thread priority is high. */ \
        mtsprg1 r1; /* Save GPR1 */ \
            ;/* Retrieve processing address for interrupt. */ \
        lis r1, intvect_##name##_finish_save@h; \
        ori r1, r1, intvect_##name##_finish_save@l; \
            ;/* Save interrupt address in SPRG0 */ \
        mtsprg0 r1; \
        mfsprg1 r1; /* Restore GPR1 */ \
        b kernel_save_task ; /* Save current task. */ \
    intvect_##name##_finish_save: \
        ; /* Get TOC entry for kernel C function */ \
        lis r2, kernel_execute_##name##@h; \
        ori r2, r2, kernel_execute_##name##@l; \
        ld r0, 0(r2); /* Load call address */ \
        mtlr r0; \
        ld r2, 8(r2); /* Load TOC base. */ \
        blrl; /* Call kernel function */ \
        nop; \
        b kernel_dispatch_task; /* Return to task */

#define HYP_INTERRUPT(name, address) \
        .org _start + address; \
        HYP_INTERRUPT_NOADDR(name)

#define HYP_INTERRUPT_STUB(name, address) \
        .org _start + address; \
    intvect_stub_hyp_##name: \
        b intvect_hyp_##name;

#define HYP_INTERRUPT_NOADDR(name) \
    intvect_hyp_##name: \
        or 2,2,2; /* Ensure thread priority is high. */ \
        mtsprg1 r1; /* Save GPR1 */ \
            ;/* Retrieve processing address for interrupt. */ \
        lis r1, intvect_hyp_##name##_finish_save@h; \
        ori r1, r1, intvect_hyp_##name##_finish_save@l; \
            ;/* Save interrupt address in SPRG0 */ \
        mtsprg0 r1; \
        mfsprg1 r1; /* Restore GPR1 */ \
        b kernel_save_task ; /* Save current task. */ \
    intvect_hyp_##name##_finish_save: \
        ; /* Get TOC entry for kernel C function */ \
        lis r2, kernel_execute_hyp_##name##@h; \
        ori r2, r2, kernel_execute_hyp_##name##@l; \
        ld r0, 0(r2); /* Load call address */ \
        mtlr r0; \
        ld r2, 8(r2); /* Load TOC base. */ \
        blrl; /* Call kernel function */ \
        nop; \
        b hyp_dispatch_task; /* Return to task */

STD_INTERRUPT_STUB(system_reset, 0x100)

.org _start + 0x180
intvect_inst_start:
    b _start

STD_INTERRUPT(machine_check, 0x200)
STD_INTERRUPT(data_storage, 0x300)
STD_INTERRUPT(data_segment, 0x380)
STD_INTERRUPT(inst_storage, 0x400)
STD_INTERRUPT(inst_segment, 0x480)
STD_INTERRUPT(external, 0x500)
STD_INTERRUPT(alignment, 0x600)
STD_INTERRUPT(prog_ex, 0x700)
STD_INTERRUPT(fp_unavail, 0x800)
STD_INTERRUPT(decrementer, 0x900)
UNIMPL_INTERRUPT(hype_decrementer, 0x980)

;// System Call Exception Vector
;//
;// This exception vector implements the save/restore for normal system calls
;// that require C++ code for handling but also implements a fast-path for
;// some simple calls, such as reading protected SPRs.
;//
;// Since this is called from userspace as a function call (see __syscall*
;// functions) we only need to honor the ELF ABI calling conventions.  That
;// means some registers and condition fields can be considered volatile and
;// modified prior to being saved.
;//
.org _start + 0xC00
intvect_system_call_fast:
    cmpwi cr0, r3, 0x0800
    bge  cr0, system_call_fast_path
STD_INTERRUPT(system_call, 0xC08)

UNIMPL_INTERRUPT_STUB(trace, 0xD00)

.org _start + 0xD80
intvect_inst_trampoline:
   mtspr HSPRG0, r2     ;// Free up a temporary register.

   ;// this is now the case where we need to jump to different exception vector
   ;// route to correct call using hrfid.  HSRR0 is already set correct,
   ;// just need to update HSRR1 with current (escalated privlege) MSR
   mfmsr r2
   mtspr HSRR1, r2

   ;// cleanup our register usage
   mfspr r2, HSPRG0     ;// Restore original value of R2
   hrfid                ;// handle the real exception

UNIMPL_INTERRUPT_STUB(hype_data_storage, 0xE00)
;// Hypervisor Instruction Storage Exception Vector
;// SMF prevents HB userspace from running in UV/HV/PR = 0b111
;// Thus userspace runs in 0b101 -- however that means all
;// exceptions first jump to exception vectors with 0b100
;// and then ALWAYS take a hype inst_storage exception.  Desired
;// exception is always in HSSR0
.org _start + 0xE20
intvect_syscall_hype_inst_storage:
   b intvect_inst_trampoline

STD_INTERRUPT_STUB(hype_emu_assist, 0xE40)
UNIMPL_INTERRUPT_STUB(hype_maint, 0xE60)
HYP_INTERRUPT_STUB(doorbell_stub, 0xE80)
HYP_INTERRUPT_STUB(external_stub, 0xEA0)

UNIMPL_INTERRUPT_STUB(perf_monitor, 0xF00)
UNIMPL_INTERRUPT_STUB(vector_unavail, 0xF20)
UNIMPL_INTERRUPT_STUB(vsx_unavail, 0xF40)
UNIMPL_INTERRUPT_STUB(fac_unavail, 0xF60)

    ;// P8 has a new HFSCR register which allows the hypervisor to disable
    ;// access to facilities such as floating point to a partition, even if
    ;// the partition enables via the MSR bits.  Since the only of these
    ;// facilities we allow is FP, we'll just set the HFSCR bits here if we
    ;// get this exception.
.org _start + 0xF80
hype_fac_unavail:
   mtspr HSPRG1, r0     ;// Free up a temporary register.
   mfspr r0,HFSCR
   ori r0, r0, 1        ;// Set FP=1 (bit 63).
   mtspr HFSCR, r0
   mfspr r0, HSPRG1     ;// Restore temporary
   hrfid

;// Softpatch Exception Vector
;//
;// This exception vector implements the softpatch / denormalization assist
;// for certain floating point instructions which are unable to handle a
;// certain format of floating point numbers.  The softpatch code will run
;// a denormalization assist procedure.
;//
;// The processor sets HSRR0/HSRR1 for this exception instead of SRR0/SRR1
;// because it is a hypervisor-level exception.  It is not possible for us
;// to be in exception state already when this exception is called (since
;// kernel code doesn't use floating-point), so it is safe to just move HSSR0
;// onto SRR0 so that the normal save/restore code can be used.
;//
;// We also need to roll back the HSRR0 1 instruction (4 bytes) since the
;// HSRR0 gets set to the instruction after the exception according to the
;// P7 Book IV.
.org _start + 0x1500
softpatch_stub:
    mtspr HSPRG1, r1     ;// Free up a temporary register (R1)
    mfspr r1, HSRR0     ;// Move HSRR0 -> SRR0.
    subi r1, r1, 4      ;// Roll back SRR0 1 instruction to one taking except.
    mtsrr0 r1
    mfspr r1, HSPRG1     ;// Restore temporary (R1)
STD_INTERRUPT_NOADDR(softpatch)

.section .text.kernelasm

;// Hostboot descriptor pointer.
;//
;// This must be the first entry in the .text.kernelasm section so that it
;// ends up at 0x2000 in our kernel image.
kernel_descriptor:
    .byte 'H', 'O', 'S', 'T', 'B', 'O', 'O', 'T'
    .quad kernel_hbDescriptor

;// Hostboot debug pointers.
;//
;// This points to a table of pointers to be used by the debug tools
;// See debugpointers.H for details
.global debug_pointers
debug_pointers:
    .space 8


;// _main:
;//     Set up stack and TOC and call kernel's main.
_main:
    ;// Set up initial TOC Base
    lis r2, main@h
    ori r2, r2, main@l
    ld r2,8(r2)

    ;// Set up initial stack, space for 8 double-words
    lis r1, kernel_stack@h
    ori r1, r1, kernel_stack@l
    addi r1, r1, 16320

    ;// Call main.
    bl main
_main_loop:
    b _main_loop

;// _other_thread_spinlock:
;//     Used for threads other than first to wait for the system to boot to a
;//     stable point where we can start the other threads.  At this point
;//     nothing is initalized in the thread.
_other_thread_spinlock:
    ;// Read spinlock value.
    lis r2, kernel_other_thread_spinlock@h
    ori r2, r2, kernel_other_thread_spinlock@l
1:
    ld r3, 0(r2)
    ;// Loop until value is 1...
    cmpwi cr0, r3, 1
    beq _other_thread_spinlock_complete
    or 1,1,1 ;// Lower thread priority.
    b 1b
;// Now released by primary thread.
_other_thread_spinlock_complete:
    or 2,2,2 ;// Raise thread priority.
    isync
    ;// Get CPU object from thread ID.
    lis r2, _ZN10CpuManager7cv_cpusE@h
    ori r2, r2, _ZN10CpuManager7cv_cpusE@l
    mfspr r1, PIR               ;// Extract CPU id.
    clrlslwi r1, r1, 20, 3
    ldx r3, r1, r2              ;// Load CPU object.
    cmpwi cr0, r3, 0            ;// Check for NULL CPU object.
    beq- 1f
    ld r1, CPU_KERNEL_STACK(r3) ;// Load initial stack.

    lis r2, smp_slave_main@h    ;// Load TOC base.
    ori r2, r2, smp_slave_main@l
    ld r2, 8(r2)
    bl smp_slave_main           ;// Call smp_slave_main
    b _main_loop
1:
    ;// No CPU object available, nap this CPU.
        ;// We should only get to this point on simics.  SBE will only wake up
        ;// a single core / thread at a time and we are responsible for
        ;// further sequencing.
    nap
    b 1b




    ;// @fn kernel_save_task
    ;// Saves context to task structure and branches back to requested addr.
    ;//
    ;// Requires:
    ;//     * SPRG3 -> Task Structure.
    ;//     * SPRG0 -> Return address.
    ;//     * SPRG1 -> Safe for scratch (temporary save of r1)
kernel_save_task:
    mtsprg1 r1          ;// Save r1.
    mfsprg3 r1          ;// Get task structure.

    std r0, TASK_GPR_0(r1)      ;// Save GPR0
    mfsrr0 r0
    std r0, TASK_NIP(r1)        ;// Save NIP
    mflr r0
    std r0, TASK_LR(r1)         ;// Save LR
    mfcr r0
    std r0, TASK_CR(r1)         ;// Save CR
    mfctr r0
    std r0, TASK_CTR(r1)        ;// Save CTR
    mfxer r0
    std r0, TASK_XER(r1)        ;// Save XER
    mfsprg1 r0
    std r0, TASK_GPR_1(r1)      ;// Save GPR1
    std r2, TASK_GPR_2(r1)      ;// Save GPR2
    std r3, TASK_GPR_3(r1)      ;// Save GPR3
    std r4, TASK_GPR_4(r1)      ;// Save GPR4
    std r5, TASK_GPR_5(r1)      ;// Save GPR5
    std r6, TASK_GPR_6(r1)      ;// Save GPR6
    std r7, TASK_GPR_7(r1)      ;// Save GPR7
    std r8, TASK_GPR_8(r1)      ;// Save GPR8
    std r9, TASK_GPR_9(r1)      ;// Save GPR9
    std r10, TASK_GPR_10(r1)    ;// Save GPR10
    std r11, TASK_GPR_11(r1)    ;// Save GPR11
    std r12, TASK_GPR_12(r1)    ;// Save GPR12
    std r13, TASK_GPR_13(r1)    ;// Save GPR13
    std r14, TASK_GPR_14(r1)    ;// Save GPR14
    std r15, TASK_GPR_15(r1)    ;// Save GPR15
    std r16, TASK_GPR_16(r1)    ;// Save GPR16
    std r17, TASK_GPR_17(r1)    ;// Save GPR17
    std r18, TASK_GPR_18(r1)    ;// Save GPR18
    std r19, TASK_GPR_19(r1)    ;// Save GPR19
    std r20, TASK_GPR_20(r1)    ;// Save GPR20
    std r21, TASK_GPR_21(r1)    ;// Save GPR21
    std r22, TASK_GPR_22(r1)    ;// Save GPR22
    std r23, TASK_GPR_23(r1)    ;// Save GPR23
    std r24, TASK_GPR_24(r1)    ;// Save GPR24
    std r25, TASK_GPR_25(r1)    ;// Save GPR25
    std r26, TASK_GPR_26(r1)    ;// Save GPR26
    std r27, TASK_GPR_27(r1)    ;// Save GPR27
    std r28, TASK_GPR_28(r1)    ;// Save GPR28
    std r29, TASK_GPR_29(r1)    ;// Save GPR29
    std r30, TASK_GPR_30(r1)    ;// Save GPR30
    std r31, TASK_GPR_31(r1)    ;// Save GPR31

    ld r2, TASK_FP_CONTEXT(r1)  ;// Load FP Context pointer.
    cmpwi cr0, r2, 0
    bne- cr0, 1f                ;// Jump to FP-save if != NULL.
2:

    ld r1, TASK_CPUPTR(r1)      ;// Get CPU pointer
    ld r1, CPU_KERNEL_STACK(r1) ;// Get kernel stack pointer.

    mfsprg0 r0          ;// Retrieve return address from SPRG0
    mtlr r0             ;// Call
    blr
        ;// Save FP context.
1:
        ;// Enable FP.
    mfmsr r3
    ori r3,r3,0x2000
    mtmsrd r3
        ;// Save FPRs.
    stfd f0, TASK_FPR_0(r2)
    stfd f1, TASK_FPR_1(r2)
    stfd f2, TASK_FPR_2(r2)
    stfd f3, TASK_FPR_3(r2)
    stfd f4, TASK_FPR_4(r2)
    stfd f5, TASK_FPR_5(r2)
    stfd f6, TASK_FPR_6(r2)
    stfd f7, TASK_FPR_7(r2)
    stfd f8, TASK_FPR_8(r2)
    stfd f9, TASK_FPR_9(r2)
    stfd f10, TASK_FPR_10(r2)
    stfd f11, TASK_FPR_11(r2)
    stfd f12, TASK_FPR_12(r2)
    stfd f13, TASK_FPR_13(r2)
    stfd f14, TASK_FPR_14(r2)
    stfd f15, TASK_FPR_15(r2)
    stfd f16, TASK_FPR_16(r2)
    stfd f17, TASK_FPR_17(r2)
    stfd f18, TASK_FPR_18(r2)
    stfd f19, TASK_FPR_19(r2)
    stfd f20, TASK_FPR_20(r2)
    stfd f21, TASK_FPR_21(r2)
    stfd f22, TASK_FPR_22(r2)
    stfd f23, TASK_FPR_23(r2)
    stfd f24, TASK_FPR_24(r2)
    stfd f25, TASK_FPR_25(r2)
    stfd f26, TASK_FPR_26(r2)
    stfd f27, TASK_FPR_27(r2)
    stfd f28, TASK_FPR_28(r2)
    stfd f29, TASK_FPR_29(r2)
    stfd f30, TASK_FPR_30(r2)
    stfd f31, TASK_FPR_31(r2)
        ;// Save FPSRC
    mffs f0
    stfd f0, TASK_FPSCR(r2)

    b 2b


    ;// @fn dispatch_task
    ;// Loads context from task structure and performs rfi.
    ;//
    ;// Requires:
    ;//     * SPRG3 -> Task Structure.
    ;//     * Current contents of registers are not needed.
kernel_dispatch_task:
.global kernel_dispatch_task
    mfsprg3 r1          ;// Load task structure to r1.

    ldarx r0, TASK_CPUPTR, r1   ;// Clear the reservation by loading / storing
    stdcx. r0, TASK_CPUPTR, r1  ;// the CPU pointer in the task.

    mfmsr r2            ;// Get current MSR
    ori r2,r2, 0xC030   ;// Enable MSR[EE,PR,IR,DR].
    rldicl r2,r2,50,1   ;// Clear ...
    rotldi r2,r2,14     ;//     MSR[FP]
    rldicl r2,r2,3,1    ;// Clear HV bit...
    rotldi r2,r2,61     ;//     MSR[HV]
    ld r3, TASK_MSR_MASK(r1) ;// Load MSR mask.
    xor r2, r2, r3      ;// Apply MSR mask (XOR).
    mtsrr1 r2           ;// Set task MSR (SRR1)

    ld r2, TASK_NIP(r1) ;// Load NIP from context.
    mtsrr0 r2           ;// Set task NIP (SRR0)

                        ;// Check if FP enabled, load context.
    ld r2, TASK_FP_CONTEXT(r1)
    cmpwi cr0, r2, 0
    bne- 1f
2:
                        ;// Restore GPRs from context.
    ld r0, TASK_GPR_0(r1)       ;// GPR0
    ld r2, TASK_GPR_2(r1)       ;// GPR2
    ld r3, TASK_GPR_3(r1)       ;// GPR3
    ld r4, TASK_GPR_4(r1)       ;// GPR4
    ld r5, TASK_GPR_5(r1)       ;// GPR5
    ld r6, TASK_GPR_6(r1)       ;// GPR6
    ld r7, TASK_GPR_7(r1)       ;// GPR7
    ld r8, TASK_GPR_8(r1)       ;// GPR8
    ld r9, TASK_GPR_9(r1)       ;// GPR9
    ld r10, TASK_GPR_10(r1)     ;// GPR10
    ld r11, TASK_GPR_11(r1)     ;// GPR11
    ld r12, TASK_GPR_12(r1)     ;// GPR12
    ld r13, TASK_GPR_13(r1)     ;// GPR13
    ld r14, TASK_GPR_14(r1)     ;// GPR14
    ld r15, TASK_GPR_15(r1)     ;// GPR15
    ld r16, TASK_GPR_16(r1)     ;// GPR16
    ld r17, TASK_GPR_17(r1)     ;// GPR17
    ld r18, TASK_GPR_18(r1)     ;// GPR18
    ld r19, TASK_GPR_19(r1)     ;// GPR19
    ld r20, TASK_GPR_20(r1)     ;// GPR20
    ld r21, TASK_GPR_21(r1)     ;// GPR21
    ld r22, TASK_GPR_22(r1)     ;// GPR22
    ld r23, TASK_GPR_23(r1)     ;// GPR23
    ld r24, TASK_GPR_24(r1)     ;// GPR24
    ld r25, TASK_GPR_25(r1)     ;// GPR25
    ld r26, TASK_GPR_26(r1)     ;// GPR26
    ld r27, TASK_GPR_27(r1)     ;// GPR27

    ld r28, TASK_LR(r1)     ;// Load from context: LR, CR, CTR, XER
    ld r29, TASK_CR(r1)
    ld r30, TASK_CTR(r1)
    ld r31, TASK_XER(r1)
    mtlr  r28           ;// Restore LR
    mtcr  r29           ;// Restore CR
    mtctr r30           ;// Restore CTR
    mtxer r31           ;// Restore XER

    ld r28, TASK_GPR_28(r1)     ;// GPR28
    ld r29, TASK_GPR_29(r1)     ;// GPR29
    ld r30, TASK_GPR_30(r1)     ;// GPR30
    ld r31, TASK_GPR_31(r1)     ;// GPR31
    ld r1, TASK_GPR_1(r1)       ;// GPR1

    rfid                        ;// Execute task.

        ;// Load FP context.
1:
        ;// Set MSR[FP] and also in SRR1.
    mfmsr r3
    ori r3,r3,0x2000
    mtmsrd r3
    mfsrr1 r3
    ori r3,r3,0x2000
    mtsrr1 r3
        ;// Restore FPSCR
    lfd f0, TASK_FPSCR(r2)
    mtfsf f0,f0,1,1
        ;// Restore FPRs
    lfd f0, TASK_FPR_0(r2)
    lfd f1, TASK_FPR_1(r2)
    lfd f2, TASK_FPR_2(r2)
    lfd f3, TASK_FPR_3(r2)
    lfd f4, TASK_FPR_4(r2)
    lfd f5, TASK_FPR_5(r2)
    lfd f6, TASK_FPR_6(r2)
    lfd f7, TASK_FPR_7(r2)
    lfd f8, TASK_FPR_8(r2)
    lfd f9, TASK_FPR_9(r2)
    lfd f10, TASK_FPR_10(r2)
    lfd f11, TASK_FPR_11(r2)
    lfd f12, TASK_FPR_12(r2)
    lfd f13, TASK_FPR_13(r2)
    lfd f14, TASK_FPR_14(r2)
    lfd f15, TASK_FPR_15(r2)
    lfd f16, TASK_FPR_16(r2)
    lfd f17, TASK_FPR_17(r2)
    lfd f18, TASK_FPR_18(r2)
    lfd f19, TASK_FPR_19(r2)
    lfd f20, TASK_FPR_20(r2)
    lfd f21, TASK_FPR_21(r2)
    lfd f22, TASK_FPR_22(r2)
    lfd f23, TASK_FPR_23(r2)
    lfd f24, TASK_FPR_24(r2)
    lfd f25, TASK_FPR_25(r2)
    lfd f26, TASK_FPR_26(r2)
    lfd f27, TASK_FPR_27(r2)
    lfd f28, TASK_FPR_28(r2)
    lfd f29, TASK_FPR_29(r2)
    lfd f30, TASK_FPR_30(r2)
    lfd f31, TASK_FPR_31(r2)

    b 2b

    ;// @fn dispatch_task
    ;// Loads context from task structure and performs rfi.
    ;//
    ;// Requires:
    ;//     * SPRG3 -> Task Structure.
    ;//     * Current contents of registers are not needed.
hyp_dispatch_task:
.global hyp_dispatch_task
    mfsprg3 r1          ;// Load task structure to r1.

    ldarx r0, TASK_CPUPTR, r1   ;// Clear the reservation by loading / storing
    stdcx. r0, TASK_CPUPTR, r1  ;// the CPU pointer in the task.

    ;// Check if FP enabled, load context.
    ld r2, TASK_FP_CONTEXT(r1)
    cmpwi cr0, r2, 0
    bne- 1f
2:
    ;// Restore GPRs from context.
    ld r0, TASK_GPR_0(r1)       ;// GPR0
    ld r2, TASK_GPR_2(r1)       ;// GPR2
    ld r3, TASK_GPR_3(r1)       ;// GPR3
    ld r4, TASK_GPR_4(r1)       ;// GPR4
    ld r5, TASK_GPR_5(r1)       ;// GPR5
    ld r6, TASK_GPR_6(r1)       ;// GPR6
    ld r7, TASK_GPR_7(r1)       ;// GPR7
    ld r8, TASK_GPR_8(r1)       ;// GPR8
    ld r9, TASK_GPR_9(r1)       ;// GPR9
    ld r10, TASK_GPR_10(r1)     ;// GPR10
    ld r11, TASK_GPR_11(r1)     ;// GPR11
    ld r12, TASK_GPR_12(r1)     ;// GPR12
    ld r13, TASK_GPR_13(r1)     ;// GPR13
    ld r14, TASK_GPR_14(r1)     ;// GPR14
    ld r15, TASK_GPR_15(r1)     ;// GPR15
    ld r16, TASK_GPR_16(r1)     ;// GPR16
    ld r17, TASK_GPR_17(r1)     ;// GPR17
    ld r18, TASK_GPR_18(r1)     ;// GPR18
    ld r19, TASK_GPR_19(r1)     ;// GPR19
    ld r20, TASK_GPR_20(r1)     ;// GPR20
    ld r21, TASK_GPR_21(r1)     ;// GPR21
    ld r22, TASK_GPR_22(r1)     ;// GPR22
    ld r23, TASK_GPR_23(r1)     ;// GPR23
    ld r24, TASK_GPR_24(r1)     ;// GPR24
    ld r25, TASK_GPR_25(r1)     ;// GPR25
    ld r26, TASK_GPR_26(r1)     ;// GPR26
    ld r27, TASK_GPR_27(r1)     ;// GPR27

    ld r28, TASK_LR(r1)     ;// Load from context: LR, CR, CTR, XER
    ld r29, TASK_CR(r1)
    ld r30, TASK_CTR(r1)
    ld r31, TASK_XER(r1)
    mtlr  r28           ;// Restore LR
    mtcr  r29           ;// Restore CR
    mtctr r30           ;// Restore CTR
    mtxer r31           ;// Restore XER

    ld r28, TASK_GPR_28(r1)     ;// GPR28
    ld r29, TASK_GPR_29(r1)     ;// GPR29
    ld r30, TASK_GPR_30(r1)     ;// GPR30
    ld r31, TASK_GPR_31(r1)     ;// GPR31
    ld r1, TASK_GPR_1(r1)       ;// GPR1

                                ;//On HYP exceptions we don't task
                                ;//switch -- just jump back to where
                                ;//we came from in HSRR0/HSRR1
    hrfid                       ;// Execute task.

        ;// Load FP context.
1:
        ;// Set MSR[FP] and also in SRR1.
    mfmsr r3
    ori r3,r3,0x2000
    mtmsrd r3
    mfsrr1 r3
    ori r3,r3,0x2000
    mtsrr1 r3
        ;// Restore FPSCR
    lfd f0, TASK_FPSCR(r2)
    mtfsf f0,f0,1,1
        ;// Restore FPRs
    lfd f0, TASK_FPR_0(r2)
    lfd f1, TASK_FPR_1(r2)
    lfd f2, TASK_FPR_2(r2)
    lfd f3, TASK_FPR_3(r2)
    lfd f4, TASK_FPR_4(r2)
    lfd f5, TASK_FPR_5(r2)
    lfd f6, TASK_FPR_6(r2)
    lfd f7, TASK_FPR_7(r2)
    lfd f8, TASK_FPR_8(r2)
    lfd f9, TASK_FPR_9(r2)
    lfd f10, TASK_FPR_10(r2)
    lfd f11, TASK_FPR_11(r2)
    lfd f12, TASK_FPR_12(r2)
    lfd f13, TASK_FPR_13(r2)
    lfd f14, TASK_FPR_14(r2)
    lfd f15, TASK_FPR_15(r2)
    lfd f16, TASK_FPR_16(r2)
    lfd f17, TASK_FPR_17(r2)
    lfd f18, TASK_FPR_18(r2)
    lfd f19, TASK_FPR_19(r2)
    lfd f20, TASK_FPR_20(r2)
    lfd f21, TASK_FPR_21(r2)
    lfd f22, TASK_FPR_22(r2)
    lfd f23, TASK_FPR_23(r2)
    lfd f24, TASK_FPR_24(r2)
    lfd f25, TASK_FPR_25(r2)
    lfd f26, TASK_FPR_26(r2)
    lfd f27, TASK_FPR_27(r2)
    lfd f28, TASK_FPR_28(r2)
    lfd f29, TASK_FPR_29(r2)
    lfd f30, TASK_FPR_30(r2)
    lfd f31, TASK_FPR_31(r2)

    b 2b

intvect_system_reset:
    ;// Need to identify reason for SRESET and then perform appropriate
    ;// action.
    ;// Current support:
    ;//         - Initial sreset.
    ;//         - Decrementer wake-up from nap.
    ;//         - External interrupt from nap or winkle.
    ;//         - IPI wake-up from winkle of slave core.

    ;// Raise priority to high.
    or 2,2,2

    ;// Need to send a msgysnc to prevent weak consistency issues
    ;// with doorbells (they execute this path prior to dbell intr)
    .long 0x7C0006EC

    ;// Free up two registers temporarily.
    mtsprg0 r1
    mtsprg1 r2

    ;// Check spinlock for 0, which implies we haven't started yet.
    lis r2, kernel_other_thread_spinlock@h
    ori r2, r2, kernel_other_thread_spinlock@l
    ld r2, 0(r2)
    cmpwi cr0, r2, 0
    beq- _start

    ;// Get CPU object from thread ID, check for NULL which implies not
    ;// started yet.
    lis r2, _ZN10CpuManager7cv_cpusE@h
    ori r2, r2, _ZN10CpuManager7cv_cpusE@l
    mfspr r1, PIR               ;// Extract CPU id.
    clrlslwi r1, r1, 20, 3
    ldx r2, r1, r2              ;// Load CPU object.
    cmpwi cr0, r2, 0            ;// Check for NULL CPU object.
    beq- _start

    ;// Check for inactive CPU.
    ld r1, CPU_STATUS(r2)
    extrdi. r1, r1, 1, CPU_STATUS_ACTIVE
    beq- intvect_system_reset_inactive

    ;// Now we were an active processor so this must be a nap-wakeup.

    ;// Find bit 42:44 of SRR1 (reason for SRESET).
    mfsrr1 r2
    extrdi r2, r2, 3, 42
    ;// Check for decrementer (bits = 011).
    cmpwi cr0, r2, 0x3
    beq+ intvect_system_reset_decrementer
    ;// Check for external interrupt (bits = 010).
    cmpwi cr0, r2, 0x4
    beq+ intvect_system_reset_external
    ;// Check for HMI (bits = 101).
    cmpwi cr0, r2, 0x5
    beq+ 1f ;// Unable to handle HMI, jump to 'unknown reason'.

1:  ;// Unknown reason, call as unhandled_exception.
    sldi r1, r2, 32     ;// Save 42:44 of SRR1 and
    ori r1, r1, 0x100   ;// SRESET address to
    mtsprg2 r1          ;// SPRG2 for unhandled_exception.
        ;/* Restore R2 and R1 */
    mfsprg1 r2
    mfsprg0 r1
        ;/* Need to load unhandled_exception into SPRG0 for kernel_save_task */
    mtsprg1 r1  ;/* Save off R1 again. */
    lis r1, intvect_unhandled_finish_save@h
    ori r1, r1, intvect_unhandled_finish_save@l
    mtsprg0 r1;
    mfsprg1 r1; /* Restore GPR1 */
    b kernel_save_task ; /* Save current task, call unhandled_exception */

    ;// @fn intvect_system_reset_inactive
    ;// Handle SRESET on an inactive processor.
    ;//     This is due to either instruction start or winkle-wakeup.
intvect_system_reset_inactive:
    ;// Check winkle state in CPU.
    ld r1, CPU_STATUS(r2)
    extrdi. r1, r1, 1, CPU_STATUS_WINKLED
    beq+ _start

    ;// Now we are a winkled processor that is awoken.

    ld r1, CPU_KERNEL_STACK_BOTTOM(r2)
    ld r1, 0(r1)
    mtsprg3 r1
    b kernel_dispatch_task

    ;// @fn intvect_system_reset_decrementer
    ;// Handle SRESET due to decrementer wake-up.
    ;//     This is a wake-up from 'nap'.
    ;//
    ;//     When entering nap, all thread-state is lost (GPRs, etc).  In order
    ;//     to execute nap the task had to first make a system call to raise
    ;//     priviledge which has the side effect of saving state in the task
    ;//     struct.  None of the state can be changed by the nap instruction
    ;//     itself.  Therefore, we need to remove priviledge escalation,
    ;//     increment the NIA (past the nap instruction), and execute the
    ;//     post-task-save portion of the decrementer vector.
intvect_system_reset_decrementer:
    ;// Clear MSR mask, since privilaged instruction was now executed (nap).
    mfsprg3 r1  ;// Load task structure to r1.
    li r2, 0    ;// Zero r2.
    std r2, TASK_MSR_MASK(r1) ;// Zero msr_mask.

    ;// Advance saved NIA (past nap).
    ld r2, TASK_NIP(r1)
    addi r2, r2, 4
    std r2, TASK_NIP(r1)

    ;// Restore kernel stack.
    ld r1, TASK_CPUPTR(r1)      ;// Get CPU pointer
    ld r1, CPU_KERNEL_STACK(r1) ;// Get kernel stack pointer.

    ;// Jump to post-save portion of decrementer.
    b intvect_decrementer_finish_save

    ;// @fn intvect_system_reset_external
    ;// Handle SRESET due to wake-up from external interrupt.
    ;//     This is a wake-up from 'nap', but not due to the decrementer
    ;//     itself firing.  Therefore, leave 'nap' process state alone
    ;//     including NIA and handle the external interrupt.
intvect_system_reset_external:
    ;// Restore save registers.
    mfsprg0 r1
    mfsprg1 r2

    b intvect_external

    ;// @fn intvect_hypervisor_external
    ;// Handle hypervisor external interrupt
    ;//    This function moves the hypervisor external interrupt regs
    ;//    into the external interrupt regs and then branches to the
    ;//    external interrupt handler
intvect_hyp_external_stub:
HYP_INTERRUPT_NOADDR(external)

    ;// @fn system_call_fast_path
    ;// Handle fast path system calls.
    ;//         0x800 = HMER read (HMER -> r3).
    ;//         0x801 = HMER write (r4 -> HMER).
    ;//         0x802 = SCRATCH read (r4 -> SPRC, SPRD -> r3).
    ;//         0x803 = SCRATCH write (r4 -> SPRC, r5 -> SPRD).
    ;//         0x804 = PVR read (PVR -> r3).
system_call_fast_path:
        ;// Check if this is HMER read (0x800).
        ;// Compare was already done in system call path.
    bne cr0, 2f
    mfspr r3, HMER
        ;// Do XSCOM workaround for Errata HW822317.
        ;// If the done bit (10) is on in HMER, it could take another cycle
        ;// for any error status to show up.  Perform another HMER read.
    rldicr. r0, r3, 10, 0
    beq cr0, 1f                 ;// Done bit not set, jump to exit.
    mfspr r0, HMER              ;// Read HMER again and OR results.
    or r3, r3, r0
        ;// --- end workaround HW822317
    b 1f                        ;// Jump to exit point.
        ;// Check if this is HMER write (0x801).
2:
    cmpwi cr0, r3, 0x801
    bne cr0, 3f
    mtspr HMER, r4
    li r3, 0
    b 1f                        ;// Jump to exit point.
        ;// Check if this is SCRATCH read (0x802).
3:
    cmpwi cr0, r3, 0x802
    bne cr0, 4f
        ;// Check for being on master processor.
    mfsprg3 r6          ;// Get task structure.
    ld r6, TASK_CPUPTR(r6)        ;// Get CPU structure.
    ld r6, CPU_STATUS(r6)       ;// Read master boolean.
    extrdi. r6, r6, 1, CPU_STATUS_MASTER
    beq cr0, 300f       ;// Call TASK_MIGRATE_TO_MASTER if not on master.
        ;// Read scratch.
    mtspr SPRC, r4
    isync
    mfspr r3, SPRD
    b 1f                        ;// Jump to exit point.
        ;// Migrate task via TASK_MIGRATE_TO_MASTER
300:
        ;// Roll back NIA one instruction.
    mfsrr0 r6
    addi r6, r6, -4
    mtsrr0 r6
        ;// Move our syscall number to r6 (for TASK_MIGRATE_TO_MASTER handler).
    mr r6, r3
        ;// Set up TASK_MIGRATE_TO_MASTER syscall number.
    li r3, 3
        ;// Call back to syscall handler.
    b intvect_system_call
        ;// Check if this is SCRATCH write (0x803).
4:
    cmpwi cr0, r3, 0x803
    bne cr0, 5f
        ;// Check for master processor.
    mfsprg3 r6          ;// Get task structure.
    ld r6, TASK_CPUPTR(r6)        ;// Get CPU structure.
    ld r6, CPU_STATUS(r6)       ;// Read master boolean.
    extrdi. r6, r6, 1, CPU_STATUS_MASTER
    beq cr0, 300b       ;// Call TASK_MIGRATE_TO_MASTER if not on master.
        ;// Write scratch.
    mtspr SPRC, r4
    isync
    mtspr SPRD, r5
    b 1f                        ;// Jump to exit point.
        ;// Check if this is PVR read (0x804).
5:
    cmpwi cr0, r3, 0x804
    bne cr0, 6f
    mfspr r3, PVR
    b 1f                        ;// Jump to exit point.
        ;// Invalid system call, loop for debug.
6:
    b 6b
1:
    rfid                        ;// Return from interrupt.


    ;// @fn userspace_task_entry
    ;// Stub to load the function address and TOC base from userspace and
    ;// jump to task entry point.  Used so the kernel doesn't need to
    ;// dereference userspace addresses (which could be bad).
    ;//
    ;// Requires:
    ;//     * GPR4 -> Function pointer.
    ;//     * LR -> task_end stub.
    ;//     * GPR3 -> Task argument.
    ;//     * GPR1 -> Task stack pointer.
    ;// Results:
    ;//     * TOC base -> GPR2
    ;//     * Function Address -> CTR
    ;//     * GPR3 preserved.
    ;//     * Initial stack-frame created.
    ;//     * Branch to CTR (no link).
.global userspace_task_entry
userspace_task_entry:
        ;// Skip stack frame if GPR1 == NULL.
    cmpwi cr0, r1, 0
    beq- 1f
        ;// Create frame.
        ;//     NULL back-chain + 48 bytes + quad-word alignment.  See ABI.
    stdu r1, -56(r1)
1:
    ld r5, 0(r4)
    mtctr r5
    ld r2, 8(r4)
    bctr

    ;// @fn task_end_stub
    ;// Stub to call a TASK_END syscall in the event that a task 'returns' from
    ;// its entry point.  We cannot call task_end() directly because profiling
    ;// inserts garbage code into the task_end C function.
.global task_end_stub
task_end_stub:
        // Check for a NULL stack pointer and skip TLS cleanup.
    cmpwi cr0, r1, 0
    beq 1f
        // Check for a NULL TLS-context and skip TLS cleanup.
    ld r0, TASK_TLS_CONTEXT(r13)
    cmpwi cr0, r0, 0
    beq 1f
        // Save off r3.
    mr r31, r3
        // Set up TOC for __tls_cleanup
    lis r2, __tls_cleanup@h
    ori r2, r2, __tls_cleanup@l
    ld r2, 8(r2)
        // Call __tls_cleanup
    mr r3, r0
    bl __tls_cleanup
        // Restore r3.
    mr r3, r31
1:
        // Call task-end syscall.
    mr r4, r3 ;// Move current rc (r3) to status value (r4)
    li r3, 2  ;// TASK_END -> r3 (syscall number)
    sc

    ;// @fn intvect_unhandled_finish_save
    ;// Tail-end of a intvect_*_finish_save code block generated by
    ;// STD_INTERRUPT_NOADDR for use by the unhandled interrupt code.  This is
    ;// used by the UNIMPL_INTERRUPT_* macros so that we have a single C
    ;// function to deal with the unhandled / unimplemented interrupt.
intvect_unhandled_finish_save: \
    ; /* Get TOC entry for kernel C function */
    lis r2, kernel_execute_unhandled_exception@h;
    ori r2, r2, kernel_execute_unhandled_exception@l;
    ld r0, 0(r2); /* Load call address */
    mtlr r0;
    ld r2, 8(r2); /* Load TOC base. */
    blrl; /* Call kernel function */
    nop;
    b kernel_dispatch_task; /* Return to task */

STD_INTERRUPT_NOADDR(hype_emu_assist)
UNIMPL_INTERRUPT_NOADDR(trace, 0xD00)
UNIMPL_INTERRUPT_NOADDR(hype_data_storage, 0xE00)
UNIMPL_INTERRUPT_NOADDR(hype_inst_storage, 0xE20)
UNIMPL_INTERRUPT_NOADDR(hype_maint, 0xE60)

;// Hypervisor Doorbell Exception (part 2).
;//
;// Doorbells come in with the HSSR[01] registers, since they are Hypervisor
;// exceptions, instead of the SRR[01] registers that the normal exception
;// code deals with.  Copy the contents of HSSR[01] -> SRR[01] first.
;//
intvect_hyp_doorbell_stub:
HYP_INTERRUPT_NOADDR(doorbell)

UNIMPL_INTERRUPT_NOADDR(perf_monitor, 0xF00)
UNIMPL_INTERRUPT_NOADDR(vector_unavail, 0xF20)
UNIMPL_INTERRUPT_NOADDR(vsx_unavail, 0xF40)
UNIMPL_INTERRUPT_NOADDR(fac_unavail, 0xF60)

    ;// @fn kernel_execute_stop
    ;//
    ;// Saves kernel state into a specified task structure and then executes
    ;// the stop instruction.
    ;//
    ;// @param r3 - task_t* to save kernel state into.
    ;//
.global kernel_execute_stop
kernel_execute_stop:
    ;// Move save area to SPRG3 for kernel_save_task.
    mtsprg3 r3

    ;// Copy LR to SRR0 (since that is where kernel_save_task gets it from).
    mflr r3
    mtsrr0 r3

    ;// Load stop instruction address into the "return to" address (SPRG0).
    lis r3, 1f@h
    ori r3, r3, 1f@l
    mtsprg0 r3

    ;// Save kernel state.
    b kernel_save_task

    ;// Execute stop.
1:
    stop

    ;// @fn enable_machine_check
    ;//
    ;// Sets MSR[ME]=1 to enable the regular machine check handling
    ;//
.global enable_machine_check
enable_machine_check:
    mflr  %r0
    bcl 20,31,$+4
0:  mflr  %r3
    addi  %r3,%r3,(1f - 0b)
    mtspr HSRR0,%r3
    mfmsr %r3

    ;// Load ME bit 51
    ori %r3,%r3,0x01000
    mtspr HSRR1,%r3
    hrfid
1:  mtlr  %r0
    blr


.section .data
    .balign 1024
kernel_stack:
    .space 16*1024

.global kernel_other_thread_spinlock
kernel_other_thread_spinlock:
    .space 8

.global hbi_ImageId
hbi_ImageId:
    .space 128
