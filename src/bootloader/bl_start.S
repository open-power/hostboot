# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/bootloader/bl_start.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2016
# [+] International Business Machines Corp.
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

.section .text.bootloaderasm

.global _start
_start:
    ;// Set thread priority high.
    or 2,2,2

    ;// Clear MSR[TA] (bit 1) and enable MSR[ME] (bit 51).
    mfmsr r2
    rldicl r2,r2,1,1    ;// Clear bit 1 - result [1-63,0]
    rotrdi r2,r2,1      ;// Rotate right 1 - result [0,63]
    ori r2,r2,4096      ;// Set bit 51
    ;// Set up SRR0 / SRR1 to enable new MSR.
    mtsrr1 r2
    li r2, _start_postmsr@l
    mtsrr0 r2
    b _start_postmsr

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
    bnel cr0, _other_thread_error ;// Handle having multiple threads started
    stdcx. r4, 0, r2    ;// Attempt to store 2.
    bne 1b ;// Loop until sucessful at stwcx.
    isync

    b _main


/* @TODO RTC:133821 might not be needed
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
@TODO RTC:133821 might not be needed */


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


;// @fn _other_thread_error:
;//     Used for threads other than first to handle this unexpected condition.
_other_thread_error:
    ;// Read spinlock value.
    lis r2, kernel_other_thread_spinlock@h
    ori r2, r2, kernel_other_thread_spinlock@l
1:
    ld r3, 0(r2)
    ;// Loop until value is 1...
    cmpi cr0, r3, 1
    beq task_end_stub ;// End the multiple threads
    or 1,1,1 ;// Lower thread priority.
    b 1b


    ;// @fn task_end_stub
    ;// Stub to call a TASK_END syscall in the event that a task 'returns' from
    ;// its entry point.  We cannot call task_end() directly because profiling
    ;// inserts garbage code into the task_end C function.
.global task_end_stub
task_end_stub:
    mr r4, r3 ;// Move current rc (r3) to status value (r4)
    li r3, 2  ;// TASK_END -> r3 (syscall number)
    sc


.section .data

    .balign 1024
kernel_stack:
    .space 4*1024

    .balign 8
.global data_sandbox
data_sandbox:
    .space 64

.global kernel_other_thread_spinlock
kernel_other_thread_spinlock:
    .space 8

.global g_blScratchSpace
g_blScratchSpace:
    .space 8

