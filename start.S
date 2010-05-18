.section .text.intvects

.global _start
_start:
    ;// Enter 64 bit mode
    mfmsr 0
    lis 11, 0x8000
    sldi 11,11, 32
    or 11,11,0
    mtmsr 11
    isync
    
    ;// Relocate code
    bl pre_relocate	;// fill LR with address
pre_relocate:
    mflr 2
    lis 1,0x0010
    cmpl 0,2,1		;// Check LR is less than 1MB
    blt finished_relocate	;// No need to relocate if less than 1MB
    
    ;// Get addresses for relocation.
    ;// Write address in r5
    ;// Read address in r1
    li 5,0
    li 1, -1	;// fill r1 with ffff..ffffff
    lis 3, 0x1
    subi 3,3,1	;// fill r3 with 0000..00ffff
    xor 1,1,3	;// mask off r1  ffff..ff0000

    and 1,1,2	;// and with pre_relocate's address from r2 to get start of
		;// rom section.
    
    ;// Update LR to low address.
    and 6,2,3
    mtlr 6

    ;// Moving 1MB , so load r2 with (1MB / 8 bytes per word)
    lis 2, 0x2
    mtctr 2
relocate_loop:		
    ;// The dcbst/sync/icbi/isync sequence comes from PowerISA
    ld 4, 0(1)
    std 4, 0(5)
    dcbst 0,5
    sync
    icbi 0,5
    isync
    addi 1,1,8
    addi 5,5,8
    bdnz+ relocate_loop
    
    ;// Now that we've relocated, erase exception prefix.
    mfmsr 11
    li 10, 0x40 ;// bit 6 is MSR_EP
    not 10,10
    and 11,11,10
    mtmsr 11
    
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
    lis 2, main@h
    ori 2, 2, main@l
    ld 2,8(2)
    
    ;// Set up initial stack
    lis 1, kernel_stack@h
    ori 1, 1, kernel_stack@l
    addi 1, 1, 16368

    ;// Set up exception stack
    lis 3, exception_stack@h
    ori 3, 3, exception_stack@l
    addi 3, 3, 16368
    mtsprg0 3

    ;// Call main.
    bl main
_main_loop:
    b _main_loop


.section .data
    .balign 1024
kernel_stack:
    .space 16*1024
exception_stack:
    .space 16*1024

.section .text.hreset
hreset:
    b _start
