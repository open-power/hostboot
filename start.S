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
    cmp 0,2,1		;// Check LR is less than 1MB
    bc 0,0,finished_relocate	;// No need to relocate if less than 1MB
    
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
    
    ;// Moving 1MB , so load r2 with (1MB / 8 bytes per word)
    lis 2, 0x2
    mtctr 2
relocate_loop:
    ld 4, 0(1)
    std 4, 0(5)
    dcbst 0,5
    sync
    icbi 0,5
    sync
    addi 1,1,8
    addi 5,5,8
    bdnz+ relocate_loop
    isync
    
    ;// Now that we've relocated, erase exception prefix.
    mfmsr 11
    li 10, 0x40 ;// bit 6 is MSR_EP
    not 10,10
    and 11,11,10
    mtmsr 11

finished_relocate: 
    b _main

.org _start + 0x100
intvect_system_reset:
    b _start

.section .text.hreset
hreset:
    b _start
