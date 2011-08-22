.include "kernel/ppcconsts.S"

.section .text.intvects

.global _start
_start:
    ;// Set thread priority high.
    or 3,3,3

    ;// Determine if this is the first thread.
    li r4, 2
    ;// Read spinlock value.
    lis r2, kernel_other_thread_spinlock@h
    ori r2, r2, kernel_other_thread_spinlock@l
    lwsync
1:
    ldarx r3, 0, r2
    cmpwi r3, 0	;// Non-zero means this thread wasn't first.
    bnel cr0, _other_thread_spinlock
    stdcx. r4, 0, r2	;// Attempt to store 2.
    bne 1b ;// Loop until sucessful at stwcx.
    isync

    b _main
/*
    ;// Relocate code
    bl pre_relocate	;// fill LR with address
pre_relocate:
    mflr r2
    lis r1,0x0010
    cmpl cr0,r2,r1		;// Check LR is less than 1MB
    blt finished_relocate	;// No need to relocate if less than 1MB

    ;// Get addresses for relocation.
    ;// Write address in r5
    ;// Read address in r1
    li r5,0
    lis r1, -1	;// fill r1 with ffff..ff0000

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
    intvect_##name: \
	or 1,1,1; /* Drop thread priority while in loop. */ \
	b intvect_##name

#define STD_INTERRUPT(name, address) \
        .org _start + address; \
        STD_INTERRUPT_NOADDR(name)

#define STD_INTERRUPT_NOADDR(name) \
    intvect_##name: \
	or 3,3,3; /* Ensure thread priority is high. */ \
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

.org _start + 0x100
intvect_system_reset:
    b _start

.org _start + 0x17C
hbi_pre_phyp_breakpoint:
    attn;   /* TODO: Add actual breakpoint attention. */
    b _start

UNIMPL_INTERRUPT(machine_check, 0x200)
STD_INTERRUPT(data_storage, 0x300)
STD_INTERRUPT(data_segment, 0x380)
STD_INTERRUPT(inst_storage, 0x400)
STD_INTERRUPT(inst_segment, 0x480)
UNIMPL_INTERRUPT(external, 0x500)
STD_INTERRUPT(alignment, 0x600)
STD_INTERRUPT(prog_ex, 0x700)
UNIMPL_INTERRUPT(fp_unavail, 0x800)
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
    cmpi cr0, r3, 0x0800
    bge  cr0, system_call_fast_path
STD_INTERRUPT(system_call, 0xC08)

UNIMPL_INTERRUPT(trace, 0xD00)
UNIMPL_INTERRUPT(hype_data_storage, 0xE00)
UNIMPL_INTERRUPT(hype_inst_storage, 0xE20)

.org _start + 0xE40
hype_emu_assist_stub:
    b intvect_hype_emu_assist

UNIMPL_INTERRUPT(hype_maint, 0xE60)
UNIMPL_INTERRUPT(perf_monitor, 0xF00)
UNIMPL_INTERRUPT(vector_unavail, 0xF20)
UNIMPL_INTERRUPT(vsx_unavail, 0xF40)

.section .text
;// _main:
;//	Set up stack and TOC and call kernel's main.
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
;//	Used for threads other than first to wait for the system to boot to a
;//	stable point where we can start the other threads.  At this point
;//	nothing is initalized in the thread.
_other_thread_spinlock:
    ;// Read spinlock value.
    lis r2, kernel_other_thread_spinlock@h
    ori r2, r2, kernel_other_thread_spinlock@l
1:
    ld r3, 0(r2)
    ;// Loop until value is 1...
    li r4, 1
    cmp cr0, r3, r4
    beq _other_thread_spinlock_complete
    or 1,1,1 ;// Lower thread priority.
    b 1b
;// Now released by primary thread.
_other_thread_spinlock_complete:
    or 3,3,3 ;// Raise thread priority.
    isync
    ;// Get CPU object from thread ID.
    mfspr r1, PIR
    lis r2, _ZN10CpuManager7cv_cpusE@h
    ori r2, r2, _ZN10CpuManager7cv_cpusE@l
    muli r3, r1, 8
    add r2, r3, r2
    ld r3, 0(r2)		;// Load CPU object.
    cmpi cr0, r3, 0             ;// Check for NULL CPU object.
    beq- cr0, 1f                ;// Jump to handling if no CPU object found.
    ld r1, 0(r3)		;// Load initial stack.

    lis r2, smp_slave_main@h 	;// Load TOC base.
    ori r2, r2, smp_slave_main@l
    ld r2, 8(r2)
    bl smp_slave_main		;// Call smp_slave_main
    b _main_loop
1:
    ;// No CPU object available, doze this CPU.
        ;// We should only get to this point on simics.  SBE will only wake up
        ;// a single core / thread at a time and we are responsible for
        ;// further sequencing.
    doze
    b 1b




    ;// @fn kernel_save_task
    ;// Saves context to task structure and branches back to requested addr.
    ;//
    ;// Requires:
    ;//     * SPRG3 -> Task Structure.
    ;//     * SPRG0 -> Return address.
    ;//     * SPRG1 -> Safe for scratch (temporary save of r1)
kernel_save_task:
    mtsprg1 r1		;// Save r1.
    mfsprg3 r1		;// Get task structure.

    std r0, TASK_GPR_0(r1)	;// Save GPR0
    mfsrr0 r0
    std r0, TASK_NIP(r1)	;// Save NIP
    mflr r0
    std r0, TASK_LR(r1)		;// Save LR
    mfcr r0
    std r0, TASK_CR(r1)		;// Save CR
    mfctr r0
    std r0, TASK_CTR(r1)	;// Save CTR
    mfxer r0
    std r0, TASK_XER(r1)	;// Save XER
    mfsprg1 r0
    std r0, TASK_GPR_1(r1)	;// Save GPR1
    std r2, TASK_GPR_2(r1)	;// Save GPR2
    std r3, TASK_GPR_3(r1)	;// Save GPR3
    std r4, TASK_GPR_4(r1)	;// Save GPR4
    std r5, TASK_GPR_5(r1)	;// Save GPR5
    std r6, TASK_GPR_6(r1)	;// Save GPR6
    std r7, TASK_GPR_7(r1)	;// Save GPR7
    std r8, TASK_GPR_8(r1)	;// Save GPR8
    std r9, TASK_GPR_9(r1)	;// Save GPR9
    std r10, TASK_GPR_10(r1)	;// Save GPR10
    std r11, TASK_GPR_11(r1)	;// Save GPR11
    std r12, TASK_GPR_12(r1)	;// Save GPR12
    std r13, TASK_GPR_13(r1)	;// Save GPR13
    std r14, TASK_GPR_14(r1)	;// Save GPR14
    std r15, TASK_GPR_15(r1)	;// Save GPR15
    std r16, TASK_GPR_16(r1)	;// Save GPR16
    std r17, TASK_GPR_17(r1)	;// Save GPR17
    std r18, TASK_GPR_18(r1)	;// Save GPR18
    std r19, TASK_GPR_19(r1)	;// Save GPR19
    std r20, TASK_GPR_20(r1)	;// Save GPR20
    std r21, TASK_GPR_21(r1)	;// Save GPR21
    std r22, TASK_GPR_22(r1)	;// Save GPR22
    std r23, TASK_GPR_23(r1)	;// Save GPR23
    std r24, TASK_GPR_24(r1)	;// Save GPR24
    std r25, TASK_GPR_25(r1)	;// Save GPR25
    std r26, TASK_GPR_26(r1)	;// Save GPR26
    std r27, TASK_GPR_27(r1)	;// Save GPR27
    std r28, TASK_GPR_28(r1)	;// Save GPR28
    std r29, TASK_GPR_29(r1)	;// Save GPR29
    std r30, TASK_GPR_30(r1)	;// Save GPR30
    std r31, TASK_GPR_31(r1)	;// Save GPR31

    ld r1, 0(r1)	;// Get CPU pointer
    ld r1, 0(r1)	;// Get kernel stack pointer.

    mfsprg0 r0		;// Retrieve return address from SPRG0
    mtlr r0		;// Call
    blr

    ;// @fn dispatch_task
    ;// Loads context from task structure and performs rfi.
    ;//
    ;// Requires:
    ;//     * SPRG3 -> Task Structure.
    ;//     * Current contents of registers are not needed.
kernel_dispatch_task:
.global kernel_dispatch_task
    mfsprg3 r1		;// Load task structure to r1.

    ldarx r0, 0, r1	;// Clear the reservation by loading / storing
    stdcx. r0, 0, r1	;// the CPU pointer in the task.

    mfmsr r2		;// Get current MSR
    ori r2,r2, 0xC030	;// Enable MSR[EE,PR,IR,DR].
    rldicl r2,r2,1,1	;// Clear ...
    rotldi r2,r2,63	;// 	MSR[TA]
    mtsrr1 r2		;// Set task MSR (SRR1)

    ld r2, TASK_NIP(r1)	;// Load NIP from context.
    mtsrr0 r2		;// Set task NIP (SRR0)

			;// Restore GPRs from context.
    ld r0, TASK_GPR_0(r1)	;// GPR0
    ld r2, TASK_GPR_2(r1)	;// GPR2
    ld r3, TASK_GPR_3(r1)	;// GPR3
    ld r4, TASK_GPR_4(r1)	;// GPR4
    ld r5, TASK_GPR_5(r1)	;// GPR5
    ld r6, TASK_GPR_6(r1)	;// GPR6
    ld r7, TASK_GPR_7(r1)	;// GPR7
    ld r8, TASK_GPR_8(r1)	;// GPR8
    ld r9, TASK_GPR_9(r1)	;// GPR9
    ld r10, TASK_GPR_10(r1)	;// GPR10
    ld r11, TASK_GPR_11(r1)	;// GPR11
    ld r12, TASK_GPR_12(r1)	;// GPR12
    ld r13, TASK_GPR_13(r1)	;// GPR13
    ld r14, TASK_GPR_14(r1)	;// GPR14
    ld r15, TASK_GPR_15(r1)	;// GPR15
    ld r16, TASK_GPR_16(r1)	;// GPR16
    ld r17, TASK_GPR_17(r1)	;// GPR17
    ld r18, TASK_GPR_18(r1)	;// GPR18
    ld r19, TASK_GPR_19(r1)	;// GPR19
    ld r20, TASK_GPR_20(r1)	;// GPR20
    ld r21, TASK_GPR_21(r1)	;// GPR21
    ld r22, TASK_GPR_22(r1)	;// GPR22
    ld r23, TASK_GPR_23(r1)	;// GPR23
    ld r24, TASK_GPR_24(r1)	;// GPR24
    ld r25, TASK_GPR_25(r1)	;// GPR25
    ld r26, TASK_GPR_26(r1)	;// GPR26
    ld r27, TASK_GPR_27(r1)	;// GPR27

    ld r28, TASK_LR(r1)     ;// Load from context: LR, CR, CTR, XER
    ld r29, TASK_CR(r1)
    ld r30, TASK_CTR(r1)
    ld r31, TASK_XER(r1)
    mtlr  r28		;// Restore LR
    mtcr  r29		;// Restore CR
    mtctr r30		;// Restore CTR
    mtxer r31		;// Restore XER

    ld r28, TASK_GPR_28(r1)	;// GPR28
    ld r29, TASK_GPR_29(r1)	;// GPR29
    ld r30, TASK_GPR_30(r1)	;// GPR30
    ld r31, TASK_GPR_31(r1)	;// GPR31
    ld r1, TASK_GPR_1(r1)	;// GPR1

    rfid			;// Execute task.

    ;// @fn system_call_fast_path
    ;// Handle fast path system calls.
    ;//         0x800 = HMER read (HMER -> r3).
    ;//         0x801 = HMER write (r4 -> HMER).
    ;//         0x802 = SCRATCH read (r4 -> SPRC, SPRD -> r3).
    ;//         0x803 = SCRATCH write (r4 -> SPRC, r5 -> SPRD).
system_call_fast_path:
        ;// Check if this is HMER read (0x800).
        ;// Compare was already done in system call path.
    bne cr0, 2f
    mfspr r3, HMER
    b 1f                        ;// Jump to exit point.
        ;// Check if this is HMER write (0x801).
2:
    cmpi cr0, r3, 0x801
    bne cr0, 3f
    mtspr HMER, r4
    li r3, 0
    b 1f                        ;// Jump to exit point.
        ;// Check if this is SCRATCH read (0x802).
3:
    cmpi cr0, r3, 0x802
    bne cr0, 4f
    mtspr 276, r4
    isync
    mfspr r3, 277
    b 1f                        ;// Jump to exit point.
        ;// Check if this is SCRATCH write (0x803).
4:
    cmpi cr0, r3, 0x803
    bne cr0, 5f
    mtspr 276, r4
    isync
    mtspr 277, r5
    b 1f                        ;// Jump to exit point.
        ;// Invalid system call, loop for debug.
5:
    b 5b
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
    cmpi cr0, r1, 0
    beq- 1f
        ;// Create frame.
        ;//     NULL back-chain + 48 bytes + quad-word alignment.  See ABI.
    stdu r1, -56(r1)
1:
    ld r5, 0(r4)
    mtctr r5
    ld r2, 8(r4)
    bctr

STD_INTERRUPT_NOADDR(hype_emu_assist)

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
