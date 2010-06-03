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


.section .data
    .balign 1024
kernel_stack:
    .space 16*1024

.section .text.hreset
hreset:
    b _start
