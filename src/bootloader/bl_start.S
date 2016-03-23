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

.set SBE_HB_VERSION,      sbe_hb_structures    ;// uint32_t
.set SBE_HB_SBEBOOTSIDE,  sbe_hb_structures+4  ;// uint8_t
.set SBE_HB_PNORBOOTSIDE, sbe_hb_structures+5  ;// uint8_t
.set SBE_HB_PNORSIZEMB,   sbe_hb_structures+6  ;// uint16_t
.set SBE_HB_BLLOADSIZE,   sbe_hb_structures+8  ;// uint64_t

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

;// _main:
;//     Set up stack and TOC and call kernel's main.
_main:
    ;// Set up initial TOC Base
    lis r2, main@h
    ori r2, r2, main@l
    ld r2,8(r2)

    ;// Set up initial stack just before scratch space at 64k offset into HBBL
    lis r1, _start@h
    addis r1, r1, 1 ;// 64k (1 * 0x10000)

    ;// Do dcbz from end of Bootloader load to end of HBB ECC working space
_dcbz_after_bl:
    lis r5, SBE_HB_BLLOADSIZE@h
    ori r5, r5, SBE_HB_BLLOADSIZE@l
    ld r5, 0(r5)       ;// get ending EA from SBE HB structure
    lis r6, 0
    addis r6, r6, 32   ;// 2M (32 * 0x10000)
    addi r6, r6, -1    ;// end before 2M
_dcbz_after_bl_loop:
    dcbz 0,r5
    addi r5, r5, 128
    cmpld cr7, r5, r6
    blt cr7, _dcbz_after_bl_loop

    ;// Do dcbz from start of HBB running space to start of Bootloader load
_dcbz_before_bl:
    li r7, 1
    rotldi r7, r7, 63  ;// set bit mask for ignoring HRMOR

    lis r5, 0
    addis r5, r5, 2048 ;// 128M (2048 * 0x10000) is start of HBB
    or r5, r5, r7      ;// ignore HRMOR

    mfspr r6, HRMOR    ;// use HRMOR as start of Bootloader
    addi r6, r6, -1    ;// end before Bootloader
    or r6, r6, r7      ;// ignore HRMOR
_dcbz_before_bl_loop:
    dcbz 0,r5
    addi r5, r5, 128
    cmpld cr7, r5, r6
    blt cr7, _dcbz_before_bl_loop

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


    ;// @fn enterHBB
    ;// Leave the Bootloader and switch to the Hostboot Base (HBB).
    ;//
    ;// Steps:
    ;//     Retrieve existing HRMOR.
    ;//     Determine physical address of EA[0]=1 mode instruction.
    ;//     Jump to enter EA[0]=1 mode.
    ;//     Update HRMOR.
    ;//     Execute isync.
    ;//     Enter Hostboot Base (HBB).
    ;//
    ;// @param[in] r3 - Hostboot HRMOR
    ;// @param[in] r4 - Hostboot Entry
    ;//
.global enterHBB
enterHBB:
        ;// Set R10 to 0x8000000000000000 so we can set "EA[0]=1" for addrs.
    li r10, 1
    rotldi r10, r10, 63

        ;// Retrieve existing HRMOR.
    mfspr r0, HRMOR

        ;// Determine physical address of EA[0]=1 mode instruction.
    lis r9, switchToHBB@h
    ori r9, r9, switchToHBB@l
    or r9, r9, r0       ;// Apply HRMOR.
    or r9, r9, r10      ;// Apply EA[0]=1.

        ;// Jump to enter EA[0]=1
    mtlr r9
    blr

switchToHBB:
        ;// Update HRMOR
    mtspr HRMOR, r3

        ;// Execute isync
    isync

        ;// Enter Hostboot Base (HBB).
    mtsrr0 r4
    rfid


.section .data

    .balign 8
.global kernel_other_thread_spinlock
kernel_other_thread_spinlock:
    .space 8

    ;// @name bootloader_trace_index
    ;// @brief Index for Bootloader Trace entries
    ;// One-byte index for next entry to use in bootloader_trace.
.global bootloader_trace_index
bootloader_trace_index:
    .space 1

    .balign 16
    ;// @name bootloader_trace
    ;// @brief Buffer for Bootloader Trace data
    ;// Buffer with bootloader trace entries.  There are 64 one-byte entries
    ;// in the buffer.  They are used to track events that have occurred in
    ;// the bootloader code.  After all entries have been used, the buffer
    ;// wraps and the oldest entry is overwritten by the newest trace data.
.global bootloader_trace
bootloader_trace:
    .space 64

.global bootloader_hbbSection
bootloader_hbbSection:
    .space 32
