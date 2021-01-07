# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/bootloader/bl_start.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2021
# [+] Google Inc.
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
#include <config.h>

# .set SBE_HB_VERSION,      sbe_hb_structures    ;// uint32_t
# .set SBE_HB_SBEBOOTSIDE,  sbe_hb_structures+4  ;// uint8_t
# .set SBE_HB_PNORBOOTSIDE, sbe_hb_structures+5  ;// uint8_t
# .set SBE_HB_PNORSIZEMB,   sbe_hb_structures+6  ;// uint16_t
.set SBE_HB_BLLOADSIZE,   sbe_hb_structures+8  ;// uint64_t
# .set SBE_HB_SECUREACCESSBIT, sbe_hb_structures+16  ;// uint8_t
# .set SBE_HB_XSCOMMMIOBAR, sbe_hb_structures+24 ;// uint64_t
# .set SBE_HB_LPCMMIOBAR,   sbe_hb_structures+32 ;// uint64_t
.set HBBL_BASE_ADDRESS,   base_load_address
.set HBBL_END_ADDRESS,    end_load_address

# @HBBL_SIZE_SYNC@
# Should be HBBL_MAX_SIZE + 12K (0xB000 currently)
.set HBBL_DATA_ADDR_OFFSET,      0x0000B000 ;// offset of external data

# @sync_ti_area_size if bl_TIDataArea moves from the start of blData struct,
# HBBL_TI_OFFSET will need to be updated to the new offset of the TI Data.
.set HBBL_TI_OFFSET,             0x0        ;// offset within external data
.set HBBL_SCRATCH_ADDR_OFFSET,   0x00010000 ;// offset of scratch space
.set HBBL_system_reset,          0x100
.set HBBL_machine_check,         0x200
.set HBBL_data_storage,          0x300
.set HBBL_data_segment,          0x380
.set HBBL_inst_storage,          0x400
.set HBBL_inst_segment,          0x480
.set HBBL_external,              0x500
.set HBBL_alignment,             0x600
.set HBBL_prog_ex,               0x700
.set HBBL_fp_unavail,            0x800
.set HBBL_decrementer,           0x900
.set HBBL_hype_decrementer,      0x980
.set HBBL_privileged_doorbell,   0xA00
.set HBBL_system_call,           0xC00
.set HBBL_trace,                 0xD00
.set HBBL_hype_data_storage,     0xE00
.set HBBL_hype_inst_storage,     0xE20
.set HBBL_hype_emu_assist,       0xE40
.set HBBL_hype_maint,            0xE60
.set HBBL_syscall_hype_doorbell, 0xE80
.set HBBL_perf_monitor,          0xF00
.set HBBL_vector_unavail,        0xF20
.set HBBL_vsx_unavail,           0xF40
.set HBBL_fac_unavail,           0xF60
.set HBBL_hype_fac_unavail,      0xF80
.set HBBL_softpatch,             0x1500
.set HBBL_debug,                 0x1600
.set P9N_URMOR_HACK,             0x7C797BA6
.set MSR_SMF_MASK,               0x0000000000400000
.set MSR_SMF_AND_MASK,           0x40 ;// used to isolate the SMF bit with andis

.section .text.bootloaderasm

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

_start_postmsr:

    lwsync
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

    ;// Save HRMOR in r11 for use in multiple places
    mfspr r11, HRMOR    ;// save HRMOR

    ;// Do dcbz from end of Bootloader load to end of HBB ECC working space
_dcbz_after_bl:
    lis r5, SBE_HB_BLLOADSIZE@h
    ori r5, r5, SBE_HB_BLLOADSIZE@l
    ld r5, 0(r5)       ;// get ending EA from SBE HB structure
    lis r6, 0
    addis r6, r6, 32   ;// 2M (32 * 0x10000)
    addi r6, r6, -1    ;// end before 2M
;// Do not erase the memory in VPO, since the PNOR/HBB is placed there
;// prior to starting
#ifndef CONFIG_VPO_COMPILE
_dcbz_after_bl_loop:
    dcbz 0,r5
    addi r5, r5, 128
    cmpld cr7, r5, r6
    blt cr7, _dcbz_after_bl_loop
#endif

    ;// Do dcbz from start of HBB running space to start of Bootloader load
_dcbz_before_bl:
    li r7, 1
    rotldi r7, r7, 63  ;// set bit mask for ignoring HRMOR

    subis r5, r11, 32  ;// start of HBB is HRMOR - 2MB (32 * 0x10000)
    or r5, r5, r7      ;// ignore HRMOR
    addi r8, r5, 0x2000 ;// add offset of TI info, save in r8 for later

    addi r6, r11, -1   ;// use HRMOR as Bootloader start, end before Bootloader
    or r6, r6, r7      ;// ignore HRMOR
;// Do not erase the memory in VPO, since the PNOR/HBB is placed there
;// prior to starting
#ifndef CONFIG_VPO_COMPILE
_dcbz_before_bl_loop:
    dcbz 0,r5
    addi r5, r5, 128
    cmpld cr7, r5, r6
    blt cr7, _dcbz_before_bl_loop
#endif


_updates_and_setup:
    ;// Update external data address with HRMOR
    lis r5, g_blData@h
    ori r5, r5, g_blData@l
    ld r7, 0(r5)       ;// get data address offset
    or r7, r7, r11     ;// or HRMOR with offset to calculate address
    addi r9, r7, HBBL_TI_OFFSET ;// add offset of HBBL's TI data, save in r9
    std r7, 0(r5)      ;// set external data address


    ;// Update scratch address with HRMOR
    lis r5, g_blScratchSpace@h
    ori r5, r5, g_blScratchSpace@l
    ld r7, 0(r5)       ;// get scratch address offset
    or r7, r7, r11     ;// or HRMOR with offset to calculate address
    std r7, 0(r5)      ;// set scratch address


    ;// Set up TI info
    lis r5, hbb_ti_descriptor@h
    ori r5, r5, hbb_ti_descriptor@l
    ld r7, 0(r5)       ;// get TI magic signature
    std r7, 0(r8)      ;// save using pointer for TI info put in r8 earlier
    std r9, 8(r8)      ;// store pointer to HBBL's TI data in next location


    ;// Set r5 to base load address where exception vectors are loaded
_load_exception_vectors:
    lis r5, HBBL_BASE_ADDRESS@h
    ori r5, r5, HBBL_BASE_ADDRESS@l

    ;// Set r6 to branch instruction
    lis r6, 0x4800
    ori r6, r6, 0

    ;// Create and store system reset handler branch instruction
    ori r7, r6, intvect_system_reset - HBBL_system_reset
    st r7, HBBL_system_reset(r5)

    ;// Create and store machine check handler branch instruction
    ori r7, r6, intvect_machine_check - HBBL_machine_check
    st r7, HBBL_machine_check(r5)

    ;// Create and store data storage handler branch instruction
    ori r7, r6, intvect_data_storage - HBBL_data_storage
    st r7, HBBL_data_storage(r5)

    ;// Create and store data segment handler branch instruction
    ori r7, r6, intvect_data_segment - HBBL_data_segment
    st r7, HBBL_data_segment(r5)

    ;// Create and store inst storage handler branch instruction
    ori r7, r6, intvect_inst_storage - HBBL_inst_storage
    st r7, HBBL_inst_storage(r5)

    ;// Create and store inst segment handler branch instruction
    ori r7, r6, intvect_inst_segment - HBBL_inst_segment
    st r7, HBBL_inst_segment(r5)

    ;// Create and store external handler branch instruction
    ori r7, r6, intvect_external - HBBL_external
    st r7, HBBL_external(r5)

    ;// Create and store alignment handler branch instruction
    ori r7, r6, intvect_alignment - HBBL_alignment
    st r7, HBBL_alignment(r5)

    ;// Create and store prog ex handler branch instruction
    ori r7, r6, intvect_prog_ex - HBBL_prog_ex
    st r7, HBBL_prog_ex(r5)

    ;// Create and store fp unavail handler branch instruction
    ori r7, r6, intvect_fp_unavail - HBBL_fp_unavail
    st r7, HBBL_fp_unavail(r5)

    ;// Create and store decrementer handler branch instruction
    ori r7, r6, intvect_decrementer - HBBL_decrementer
    st r7, HBBL_decrementer(r5)

    ;// Create and store hype decrementer handler branch instruction
    ori r7, r6, intvect_hype_decrementer - HBBL_hype_decrementer
    st r7, HBBL_hype_decrementer(r5)

    ;// Create and store privileged doorbell handler branch instruction
    ori r7, r6, intvect_privileged_doorbell - HBBL_privileged_doorbell
    st r7, HBBL_privileged_doorbell(r5)

    ;// Create and store system call handler branch instruction
    ori r7, r6, intvect_system_call - HBBL_system_call
    st r7, HBBL_system_call(r5)

    ;// Create and store trace handler branch instruction
    ori r7, r6, intvect_trace - HBBL_trace
    st r7, HBBL_trace(r5)

    ;// Create and store hype data storage handler branch instruction
    ori r7, r6, intvect_hype_data_storage - HBBL_hype_data_storage
    st r7, HBBL_hype_data_storage(r5)

    ;// Create and store hype inst storage handler branch instruction
    ori r7, r6, intvect_hype_inst_storage - HBBL_hype_inst_storage
    st r7, HBBL_hype_inst_storage(r5)

    ;// Create and store hype emu assist handler branch instruction
    ori r7, r6, intvect_hype_emu_assist - HBBL_hype_emu_assist
    st r7, HBBL_hype_emu_assist(r5)

    ;// Create and store hype maint handler branch instruction
    ori r7, r6, intvect_hype_maint - HBBL_hype_maint
    st r7, HBBL_hype_maint(r5)

    ;// Create and store syscall hype doorbell handler branch instruction
    ori r7, r6, intvect_syscall_hype_doorbell - HBBL_syscall_hype_doorbell
    st r7, HBBL_syscall_hype_doorbell(r5)

    ;// Create and store perf monitor handler branch instruction
    ori r7, r6, intvect_perf_monitor - HBBL_perf_monitor
    st r7, HBBL_perf_monitor(r5)

    ;// Create and store vector unavail handler branch instruction
    ori r7, r6, intvect_vector_unavail - HBBL_vector_unavail
    st r7, HBBL_vector_unavail(r5)

    ;// Create and store vsx unavail handler branch instruction
    ori r7, r6, intvect_vsx_unavail - HBBL_vsx_unavail
    st r7, HBBL_vsx_unavail(r5)

    ;// Create and store fac unavail handler branch instruction
    ori r7, r6, intvect_fac_unavail - HBBL_fac_unavail
    st r7, HBBL_fac_unavail(r5)

    ;// Create and store hype fac unavail handler branch instruction
    ori r7, r6, intvect_hype_fac_unavail - HBBL_hype_fac_unavail
    st r7, HBBL_hype_fac_unavail(r5)

    ;// Create and store softpatch handler branch instruction
    ori r7, r6, intvect_softpatch - HBBL_softpatch
    st r7, HBBL_softpatch(r5)

    ;// Create and store debug handler branch instruction
    ori r7, r6, intvect_debug - HBBL_debug
    st r7, HBBL_debug(r5)


    ;// Call main.
    bl main
_main_loop:
    b _main_loop


;// Interrupt vectors.
#define STD_INTERRUPT(name, address) \
    intvect_##name: \
        or 2,2,2; /* Ensure thread priority is high. */ \
        li r17, address; /* Save exception address. */ \
        mtsprg2 r17; /* Move exception address to SPRG2 */ \
        b kernel_std_exception; /* Process interrupt. */

#define STD_INTERRUPT_WITH(name, address, with) \
    intvect_##name: \
        or 2,2,2; /* Ensure thread priority is high. */ \
        li r17, address; /* Save exception address. */ \
        mtsprg2 r17; /* Move exception address to SPRG2 */ \
        b kernel_std_exception_w_##with; /* Process interrupt. */

#define HYPE_INTERRUPT(name, address) \
    intvect_##name: \
        or 2,2,2; /* Ensure thread priority is high. */ \
        li r17, address; /* Save exception address. */ \
        mtsprg2 r17; /* Move exception address to SPRG2 */ \
        b kernel_hype_exception; /* Process interrupt. */

STD_INTERRUPT(system_reset, HBBL_system_reset)
STD_INTERRUPT_WITH(machine_check, HBBL_machine_check, srr1)
STD_INTERRUPT_WITH(data_storage, HBBL_data_storage, dsisr)
STD_INTERRUPT(data_segment, HBBL_data_segment)
STD_INTERRUPT_WITH(inst_storage, HBBL_inst_storage, srr1)
STD_INTERRUPT(inst_segment, HBBL_inst_segment)
STD_INTERRUPT(external, HBBL_external)
STD_INTERRUPT(alignment, HBBL_alignment)
STD_INTERRUPT_WITH(prog_ex, HBBL_prog_ex, srr1)
STD_INTERRUPT(fp_unavail, HBBL_fp_unavail)
STD_INTERRUPT(decrementer, HBBL_decrementer)
HYPE_INTERRUPT(hype_decrementer, HBBL_hype_decrementer)
STD_INTERRUPT(privileged_doorbell, HBBL_privileged_doorbell)
STD_INTERRUPT(system_call, HBBL_system_call)
STD_INTERRUPT(trace, HBBL_trace)
HYPE_INTERRUPT(hype_data_storage, HBBL_hype_data_storage)
HYPE_INTERRUPT(hype_inst_storage, HBBL_hype_inst_storage)
HYPE_INTERRUPT(hype_emu_assist, HBBL_hype_emu_assist)
HYPE_INTERRUPT(hype_maint, HBBL_hype_maint)
HYPE_INTERRUPT(syscall_hype_doorbell, HBBL_syscall_hype_doorbell)
STD_INTERRUPT(perf_monitor, HBBL_perf_monitor)
STD_INTERRUPT(vector_unavail, HBBL_vector_unavail)
STD_INTERRUPT(vsx_unavail, HBBL_vsx_unavail)
STD_INTERRUPT(fac_unavail, HBBL_fac_unavail)
HYPE_INTERRUPT(hype_fac_unavail, HBBL_hype_fac_unavail)
STD_INTERRUPT(softpatch, HBBL_softpatch)
STD_INTERRUPT(debug, HBBL_debug)


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
        ;// Update HRMOR and URMOR
        ;// for secure systems URMOR must == HRMOR for HBB
        ;// Since SBE always keeps HRMOR == URMOR, HBBL uses
        ;// HRMOR for backward compatibility, but it must
        ;// adjust URMOR when jumping to HBB
    mtspr HRMOR, r3

        ;// Check to see if SMF bit is off... if so skip
        ;// URMOR set as don't have permissions
    mfmsr r6
    andis. r6, r6, MSR_SMF_AND_MASK    ;// Check if 41 (SMF) is on
    beq skip_urmor       ;// if result of AND = zero then CR[EQ] bit set
    mtspr URMOR, r3

skip_urmor:

        ;// Clear out SLBs, ERATs, etc.
    isync
    slbia
    isync

        ;// Enter Hostboot Base (HBB).
    mtsrr0 r4
    rfid


.section .data

    .balign 16
    .byte 'H', 'B', 'B', 'L', ' ', 'I', 'D', ' '
    .byte 'S', 'T', 'R', 'I', 'N', 'G', ' ', '='
.global hbi_ImageId
hbi_ImageId:
    .space 128

.global bootloader_end_address
bootloader_end_address:
    .quad HBBL_END_ADDRESS

.global g_blData
g_blData:
    .quad HBBL_DATA_ADDR_OFFSET

.global g_blScratchSpace
g_blScratchSpace:
    .quad HBBL_SCRATCH_ADDR_OFFSET

hbb_ti_descriptor:
    .byte 'H', 'O', 'S', 'T', 'B', 'O', 'O', 'T'
