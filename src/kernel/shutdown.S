# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/kernel/shutdown.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2012,2017
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

#define KERNEL_BARRIER(addr, count, temp) \
        /*     Increment thread count. */ \
    1: \
        ldarx temp, 0, addr; \
        addi temp, temp, 1; \
        stdcx. temp, 0, addr; \
        bne- 1b; \
        isync; \
        /*     Wait for count to reach CPU count. */ \
    2: \
    1: \
        or 1,1,1;    /* Drop thread priority */ \
        ld temp, 0(addr); \
        cmpd cr0, temp, count; \
        bne 1b; \
        /*     Instruction barrier to ensure exit. */ \
        isync; \
        or 2,2,2;    /* Increase thread priority */


.section .text

    ;// @fn kernel_shutdown
    ;// Leave the Hostboot kernel and switch to the payload.
    ;//
    ;// There are four stages to switching to the payload, all of which
    ;// must be synchronized across all of the threads.
    ;// Steps:
    ;//     All threads enter "EA[0]=1" mode.
    ;//     <sync barrier 1>
    ;//     All nodes have reported cpu_count
    ;//     <sync barrier 2>
    ;//     Thread0 on each core updates HRMOR.
    ;//     <sync barrier 3>
    ;//     All threads execute - isync ; slbia ; isync
    ;//     <sync barrier 4>
    ;//     All threads except "last thread" enters payload.
    ;//         * last thread waits for all other threads to leave.
    ;//
    ;// The design of the barrier stages comes from the BookIV chapter
    ;// titled "HRMOR Update Sequence".
    ;//
    ;// @param[in] r3 - Number of Host boot instances (nodes) on the system
    ;// @param[in] r4 - Payload Base
    ;// @param[in] r5 - Payload Entry
    ;// @param[in] r6 - Payload Data
    ;// @param[in] r7 - PIR of local master cpu - only set by local master
    ;// @param[in] r8 - System address of start_payload_data_area
    ;//
.global kernel_shutdown
kernel_shutdown:
        ;// Set R10 to 0x8000000000000000 so we can set "EA[0]=1" for addrs.
    li r10, 1
    rotldi r10, r10, 63
        ;// Retrieve existing HRMOR.
    mfspr r0, HRMOR
        ;// Determine physical address of EA[0]=1 mode instruction.
    lis r9, kernel_shutdown_ea0_1_mode@h
    ori r9, r9, kernel_shutdown_ea0_1_mode@l
    or r9, r9, r0       ;// Apply HRMOR.
    or r9, r9, r10      ;// Apply EA[0] = 1.
        ;// Jump to enter EA[0] = 1
    mtlr r9
    blr
kernel_shutdown_ea0_1_mode:

        ;// Only master cpu on the node should increment barrier for node count
        ;// as it was the one that updated the cpu_count & lowest_pir
        ;// barrier - 1 wait for all nodes to report
    mfspr  r10, PIR
    cmpw    cr0, r10, r7
    bne+ 2f       ;// inside KERNEL_BARRIER below

        ;// Perform barrier - 1
    KERNEL_BARRIER(r8, r3, r11)

    ;// safe now to access system cpu_count and  lowest_PIR
    ld  r3, 48(r8)   ;// cpu_count for whole system
    ld  r7, 40(r8)   ;// lowest PIR for whole system

    addi  r8, r8, 8  ;// next barrier

        ;// Perform barrier - 2
    KERNEL_BARRIER(r8, r3, r11)

        ;// Update HRMOR on master.
    mfspr r10, PIR
    andi. r10, r10, 7
    bne+ 1f
    mtspr HRMOR, r4
1:
        ;// Perform barrier - 3
    addi r8, r8, 8
    KERNEL_BARRIER(r8, r3, r11)

        ;// Clear out SLBs, ERATs, etc.
    isync
    slbia
    isync

        ;// Perform barrier - 4
    addi r8, r8, 8
    KERNEL_BARRIER(r8, r3, r11)

        ;// "Barrier" 5:
        ;//     Increment counter as leaving, except PIR == r7 waits.
    addi r8, r8, 8
            ;// Check for PIR == r7.
    mfspr r10, PIR
    cmpw cr0, r10, r7
    beq 3f
        ;// Increment thread count.
1:
    ldarx r11, 0, r8
    addi r11, r11, 1
    stdcx. r11, 0, r8
    bne- 1b
    isync
2:
    ;// Clear "Hostboot active" scratch register.
    li r3, (0x40 + 0x18) ;// See sys/mmio.h
    mtspr SPRC, r3
    li r3, 0x0
    mtspr SPRD, r3

    ;// Enter Payload.
        ;// Set HSRR0 to entry point.
    mtspr HSRR0, r5
        ;// Save MSR, move to HSRR1.
    mfmsr r10
    mtspr HSRR1, r10
        ;// Move payload data to r3
    mr  r3,r6
        ;// Jump to entry point. Causes HSRR0 -> NIA, HSSR1 -> MSR.
    hrfid

        ;// PIR == r7 waits here for all others to leave.
3:
    subi r3, r3, 1
1:
    or 1,1,1
    ld r11, 0(r8)
    cmpw cr0, r3, r11
    bne+ 1b
    isync
        ;// All other threads have left, so wait a little bit...
            ;// Set CTR to 512.
    li r11, 512
    mtctr r11
            ;// Execute thread-priority-low until CTR is 0.
1:
    or 1,1,1
    bdnz 1b
    isync
        ;// Raise thread priority and leave ourselves.
    or 2,2,2
    b 2b

