# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/securerom/branchtable.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2016,2017
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
#****************************************************************************
#*  branch table - a more stable location for software entering rom code
#****************************************************************************
#  adr function
#	0 instruction_start
#	2 .SHA512_Init
#	4 .SHA512_Update
#	6 .SHA512_Final
#	8 .SHA512_Hash
#	A .ec_verify
#	C .ROM_verify
#	100 rom_sreset

branchtable:
	.section	".branchtable","ax"

	.globl _instruction_start
_instruction_start:
	b	instruction_start
	nop

	.globl	_SHA512_Init
_SHA512_Init:
	li	r0,	.L.SHA512_Init@l
	b	springboard

	.globl	_SHA512_Update
_SHA512_Update:
	li	r0,	.L.SHA512_Update@l
	b	springboard

	.globl	_SHA512_Final
_SHA512_Final:
	li	r0,	.L.SHA512_Final@l
	b	springboard

	.globl	_SHA512_Hash
_SHA512_Hash:
	li	r0,	.L.SHA512_Hash@l
	b	springboard

	.globl	_ec_verify
_ec_verify:
	li	r0,	.L.ec_verify@l
	b	springboard

	.globl	_ROM_verify
_ROM_verify:
	li	r0,	.L.ROM_verify@l
	b	springboard

#define CFAR 28

springboard:
	b		boingboing
boingboing:
	mfspr   r2, CFAR             // get address of springboard
	addi	r2, r2, _instruction_start-springboard  // base address
	add		r0,	r0, r2           // calculate entry relative
	addi	r2, r2,              0x4000    //TOC+0x8000  part 1
	addi	r2, r2, (__toc_start+0x4000)@l //TOC+0x8000  part 2
	mtctr	r0
	bctr						// jump

# could put other assembly ocde routines here to conserver ROM space
# including the sreset routine

# need to align on bootrombase+0x100 !!!
	.org    .branchtable+0x100
	.globl	_rom_sreset
_rom_sreset:
	li	r0,	rom_sreset@l
	b	springboard
	nop
