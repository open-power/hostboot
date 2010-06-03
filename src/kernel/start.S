.include "kernel/ppcconsts.S"

.section .text.intvects

.global _start
_start:
    ;// Enter 64 bit mode
    mfmsr r0
    lis r11, 0x8000
    sldi r11,r11, 32
    or r11,r11,r0
    mtmsr r11
    isync
    
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

.org _start + 0x100
intvect_system_reset:
    b _start

.org _start + 0x200
intvect_machine_check:
    b intvect_machine_check;

.org _start + 0x300
intvect_data_storage:
    b intvect_data_storage;

.org _start + 0x380
intvect_data_segment:
    b intvect_data_segment;

.org _start + 0x400
intvect_inst_storage:
    b intvect_inst_storage;

.org _start + 0x480
intvect_inst_segment:
    b intvect_inst_segment;

.org _start + 0x500
intvect_external:
    b intvect_external;

.org _start + 0x600
intvect_alignment:
    b intvect_alignment;

.org _start + 0x700
intvect_program:
    b intvect_program;

.org _start + 0x800
intvect_fp_unavail:
    b intvect_fp_unavail;

.org _start + 0x900
intvect_decrementer:
    mtsprg1 r1 	;// Save GPR1
	
	;// Retrieve processing address for interrupt.
    lis r1,intvect_decrementer_finish_save@h
    ori r1,r1,intvect_decrementer_finish_save@l
	;// Save interrupt address in SPRG0
    mtsprg0 r1
    
    mfsprg1 r1 			;// Restore GPR1
    b kernel_save_task 		;// Save current task.

intvect_decrementer_finish_save:
	;// Get TOC entry for kernel_execute_systemcall
    lis r2, kernel_execute_decrementer@h
    ori r2, r2, kernel_execute_decrementer@l
    ld r0,0(r2)	;// Load call addr.
    mtlr r0
    ld r2,8(r2)	;// Load TOC base.

    blrl			;// Call kernel_execute_systemcall
    nop
    b kernel_dispatch_task	;// Return to task.


.org _start + 0x980
intvect_hype_decrementer:
    b intvect_decrementer;

.org _start + 0xC00
intvect_system_call:
    mtsprg1 r1 	;// Save GPR1
	
	;// Retrieve processing address for interrupt.
    lis r1,intvect_system_call_finish_save@h
    ori r1,r1,intvect_system_call_finish_save@l
	;// Save interrupt address in SPRG0
    mtsprg0 r1
    
    mfsprg1 r1 			;// Restore GPR1
    b kernel_save_task 		;// Save current task.

intvect_system_call_finish_save:
	;// Get TOC entry for kernel_execute_systemcall
    lis r2, kernel_execute_systemcall@h
    ori r2, r2, kernel_execute_systemcall@l
    ld r0,0(r2)	;// Load call addr.
    mtlr r0
    ld r2,8(r2)	;// Load TOC base.

    blrl			;// Call kernel_execute_systemcall
    nop
    b kernel_dispatch_task	;// Return to task.

.org _start + 0xD00
intvect_trace:
    b intvect_trace;

.org _start + 0xE00
intvect_hype_data_storage:
    b intvect_hype_data_storage;

.org _start + 0xE20
intvect_hype_inst_storage:
    b intvect_hype_inst_storage;

.org _start + 0xE40
intvect_hype_emu_assist:
    b intvect_hype_emu_assist;

.org _start + 0xE60
intvect_hype_maint:
    b intvect_hype_maint;

.org _start + 0xF00
intvect_perf_monitor:
    b intvect_perf_monitor;

.org _start + 0xF20
intvect_vector_unavail:
    b intvect_vector_unavail;

.org _start + 0xF40
intvect_vsx_unavail:
    b intvect_vsx_unavail;

.section .text
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
    std r0, TASK_CTR(r1)	;// Save XER
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

    ld r28, TASK_LR(r1)     ;// Load from context: LR, CR, CTR, XER
    ld r29, TASK_CR(r1)	
    ld r30, TASK_CTR(r1)
    ld r31, TASK_XER(r1)
    mtlr  r28		;// Restore LR
    mtcr  r29		;// Restore CR
    mtctr r30		;// Restore CTR
    mtxer r23		;// Restore XER
    
    mfmsr r2		;// Get current MSR
    ori r2,r2, 0xC000	;// Enable MSR[EE,PR].
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
    ld r28, TASK_GPR_28(r1)	;// GPR28
    ld r29, TASK_GPR_29(r1)	;// GPR29
    ld r30, TASK_GPR_30(r1)	;// GPR30
    ld r31, TASK_GPR_31(r1)	;// GPR31
    ld r1, TASK_GPR_1(r1)	;// GPR1
			
    rfi				;// Execute task.

.section .data
    .balign 1024
kernel_stack:
    .space 16*1024

.section .text.hreset
hreset:
    b _start
