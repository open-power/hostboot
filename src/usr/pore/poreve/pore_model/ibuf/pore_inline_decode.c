//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/pore_model/ibuf/pore_inline_decode.c $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include <stdint.h>
#include "pore_inline_decode.h"

// From a uint32_t, extract a big-endian bit x[i] as either 0 or 1

#define BE_BIT_32(x, i) (((x) >> (31 - (i))) & 1)


// From a uint32_t, extract big-endian bits x[first:last] as unsigned to
// create a uint32_t.

#define BE_BITS_32_UNSIGNED(x, first, last) \
    (((x) >> (31 - (last))) & (0xffffffff >> (32 - (last - first + 1))))


// From a uint32_t, extract big-endian bits x[first:last] as signed to create
// an int32_t.

#define BE_BITS_32_SIGNED(x, first, last) \
    (((x) & (1 << (31 - (first)))) ? \
     (BE_BITS_32_UNSIGNED(x, first, last) | (0xffffffff << (31 - first))) : \
     BE_BITS_32_UNSIGNED(x, first, last))

/// Install and decode an instruction into the PoreInlineDissassembly object
///
/// \param dis A PoreInlineDisassembly structure to contain the disassembled
/// instruction.
///
/// \param instruction The initial (or only) 32 bits of a PORE instruction
///
/// For simplicity, instructions are currently (almost) fully decoded for all
/// possible formats. It is up to the application using this API to further
/// decode the actual opcode to determine which of these fields are valid for
/// the current instruction.
///
/// To simplify parity calculations the \a imd64 field is cleared here. A
/// companion API pore_inline_decode_imd64() is used to decode the final 64
/// bits of long instructions.
///
/// This API is designed to be called independently of the full disassembler,
/// in which case any fields of \a dis not explicitly set will be undefined.

void
pore_inline_decode_instruction(PoreInlineDecode *dis, uint32_t instruction)
{
	dis->instruction = instruction;

	// Generic decoding
	dis->opcode	  = BE_BITS_32_UNSIGNED(instruction, 0, 6);
	dis->long_instruction = BE_BIT_32(instruction, 0);
	dis->parity	  = BE_BITS_32_UNSIGNED(instruction, 7, 7);
	dis->memory_space = BE_BIT_32(instruction, 8);
	dis->update	  = BE_BIT_32(instruction, 8);
	dis->capture	  = BE_BIT_32(instruction, 9);
	dis->imd16	  = BE_BITS_32_SIGNED(instruction, 16, 31);
	dis->scan_length  = BE_BITS_32_UNSIGNED(instruction, 16, 31);
	dis->imd20	  = BE_BITS_32_SIGNED(instruction, 12, 31);
	dis->imd24 = dis->ima24 = BE_BITS_32_UNSIGNED(instruction, 8, 31);
	dis->impco20	  = BE_BITS_32_SIGNED(instruction, 12, 31);
	dis->impco24	  = BE_BITS_32_SIGNED(instruction, 8, 31);
	dis->tR = dis->r0 = BE_BITS_32_UNSIGNED(instruction, 8, 11);
	dis->sR = dis->r1 = BE_BITS_32_UNSIGNED(instruction, 12, 15);
	dis->imd64	  = 0;

	// imA24 decoding
	if (dis->memory_space) {
		dis->base_register =
			BE_BIT_32(instruction, 9) ?
			PORE_OCI_MEMORY_BASE_ADDR1_ENC :
			PORE_OCI_MEMORY_BASE_ADDR0_ENC;

		dis->memory_offset =
			BE_BITS_32_UNSIGNED(dis->instruction, 10, 31);
	} else {
		dis->base_register =
			BE_BIT_32(instruction, 9) ?
			PORE_PRV_BASE_ADDR1_ENC :
			PORE_PRV_BASE_ADDR0_ENC;

		dis->pib_offset =
			BE_BITS_32_UNSIGNED(dis->instruction, 12, 31);
	}
}


/// Install and decode an imd64 into a PoreInlineDissassembly object
///
/// \param dis A PoreInlineDisassembly structure to contain the disassembled
/// data
///
/// \param imd64 The final 64 bits of a 12-byte PORE instruction
///
/// For simplicity, instructions are currently (almost) fully decoded for all
/// possible formats. It is up to the application to determine which if any of
/// these fields are valid for the current instruction.
///
/// This API is designed to be called independently of the full disassembler,
/// in which case any fields of \a dis not explicitly set will be undefined.

void
pore_inline_decode_imd64(PoreInlineDecode *dis, uint64_t imd64)
{
	dis->imd64 = imd64;
	dis->impc48 = dis->imd64 & 0xffffffffffffull;
	dis->scan_select = imd64 >> 32;
	dis->scan_offset = imd64 & 0xffffffff;
}
