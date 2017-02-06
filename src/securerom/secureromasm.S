# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/securerom/secureromasm.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2017
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

#****************************************************************************
#*  SecureROM info - useful info used by HBBL. Must match ROM.H
#****************************************************************************
.set SECROM_EYECATCHER, 0x23534543524F4D00   ;// uint64_t '#SECROM.'
.set SECROM_VERSION, 0x0000000900000001   ;// uint64_t

# Before the SecureRom code starts there is SecureRomInfo see ROM.H
# - [8 bytes] - eyeCatch
# - [8 bytes] - version
# - [8 bytes] - branchtable offset
# - [16 bytes] - reserved
.section .text.securerominfo

eyeCatch:
    .quad SECROM_EYECATCHER

version:
    .quad SECROM_VERSION

branchtableoffset:
    .quad .text.branchtable

reserved:
    .zero 16 ;// 'reserve 16 bytes'

#****************************************************************************
#*  branch table - a more stable location for software entering rom code
#****************************************************************************
.section .text.branchtable

    .globl _SHA512_Init
_SHA512_Init:
    li r0, .L.SHA512_Init@l
    b springboard

    .globl _SHA512_Update
_SHA512_Update:
    li r0, .L.SHA512_Update@l
    b springboard

    .globl _SHA512_Final
_SHA512_Final:
    li r0, .L.SHA512_Final@l
    b springboard

    .globl _SHA512_Hash
_SHA512_Hash:
    li r0, .L.SHA512_Hash@l
    b springboard

    .globl _ec_verify
_ec_verify:
    li r0, .L.ec_verify@l
    b springboard

    .globl _ROM_verify
_ROM_verify:
    li r0, .L.ROM_verify@l
    b springboard

#define CFAR 28

springboard:
    b boingboing
boingboing:
    # @TODO RTC:156485 ROM blob will have to change to allow PHyp to use,
    #       unless PHyp directly uses
    mfspr r2, CFAR ;// get address of springboard
    addi r2, r2, .text.securerominfo-springboard ;// base address
    add r0, r0, r2 ;// calculate entry relative
    addi r2, r2, 0x4000 ;//TOC+0x8000  part 1
    addi r2, r2, (__toc_start+0x4000)@l ;//TOC+0x8000  part 2
    mtctr r0
    bctr ;// jump

# could put other assembly code routines here to conserve ROM space
# including the sreset routine

# need to align on branchtablebase+0x100 !!!
    .org .text.branchtable+0x100
    .globl _rom_sreset
_rom_sreset:
    li r0, rom_sreset@l
    b springboard
    nop

.section .data

.global hbi_ImageId
hbi_ImageId:
    .space 128
