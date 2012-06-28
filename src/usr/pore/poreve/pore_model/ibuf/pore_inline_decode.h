/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pore/poreve/pore_model/ibuf/pore_inline_decode.h $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __PORE_INLINE_DECODE_H__
#define __PORE_INLINE_DECODE_H__

#include <stdint.h>
#include "pore_inline_decode.h"

#ifdef __cplusplus
extern "C" {
#endif

/* latest definitions can be found in pgas.h */
#define PORE_OPCODE_NOP     0x0f
#define PORE_OPCODE_WAIT    0x01
#define PORE_OPCODE_TRAP    0x02
#define PORE_OPCODE_HOOK    0x4f

#define PORE_OPCODE_BRA     0x10
#define PORE_OPCODE_BRAZ    0x12
#define PORE_OPCODE_BRANZ   0x13
#define PORE_OPCODE_BRAI    0x51
#define PORE_OPCODE_BSR     0x14
#define PORE_OPCODE_BRAD    0x1c
#define PORE_OPCODE_BSRD    0x1d
#define PORE_OPCODE_RET     0x15
#define PORE_OPCODE_CMPBRA  0x56
#define PORE_OPCODE_CMPNBRA 0x57
#define PORE_OPCODE_CMPBSR  0x58
#define PORE_OPCODE_LOOP    0x1f

#define PORE_OPCODE_ANDI    0x60
#define PORE_OPCODE_ORI     0x61
#define PORE_OPCODE_XORI    0x62

#define PORE_OPCODE_AND     0x25
#define PORE_OPCODE_OR      0x26
#define PORE_OPCODE_XOR     0x27

#define PORE_OPCODE_ADD     0x23
#define PORE_OPCODE_ADDI    0x24
#define PORE_OPCODE_SUB     0x29
#define PORE_OPCODE_SUBI    0x28
#define PORE_OPCODE_NEG     0x2a

#define PORE_OPCODE_COPY    0x2c
#define PORE_OPCODE_ROL     0x2e

#define PORE_OPCODE_LOAD20  0x30
#define PORE_OPCODE_LOAD64  0x71
#define PORE_OPCODE_SCR1RD  0x32
#define PORE_OPCODE_SCR1RDA 0x73
#define PORE_OPCODE_SCR2RD  0x36
#define PORE_OPCODE_SCR2RDA 0x77
#define PORE_OPCODE_WRI     0x78
#define PORE_OPCODE_BS      0x74
#define PORE_OPCODE_BC      0x75
#define PORE_OPCODE_SCR1WR  0x39
#define PORE_OPCODE_SCR2WR  0x3a
#define PORE_OPCODE_SCAND   0x7c

#ifndef __ASSEMBLER__

/* Internal register encodings for the execution engine */
typedef enum {
	PORE_PRV_BASE_ADDR0_ENC		= 0x00,
	PORE_PRV_BASE_ADDR1_ENC		= 0x01,
	PORE_OCI_MEMORY_BASE_ADDR0_ENC	= 0x02,
	PORE_OCI_MEMORY_BASE_ADDR1_ENC	= 0x03,
	PORE_SCRATCH0_ENC		= 0x04,
	PORE_SCRATCH1_ENC		= 0x05,
	PORE_SCRATCH2_ENC		= 0x06,
	PORE_ERROR_MASK_ENC		= 0x07,
	/* PORE_MEM_RELOC_ENC		= 0x07, */
	PORE_TABLE_BASE_ADDR_ENC	= 0x08,
	PORE_EXE_TRIGGER_ENC		= 0x09,
	PORE_DATA0_ENC			= 0x0a,
	/* PORE_I2C_E0_PARAM_ENC	= 0x0b, */
	/* PORE_I2C_E1_PARAM_ENC	= 0x0c, */
	/* PORE_I2C_E2_PARAM_ENC	= 0x0d, */
	PORE_PC_ENC			= 0x0e,
	PORE_ALU_IBUF_ID_ENC		= 0x0f
} pore_internal_reg_t;

typedef struct {

    /// The first 32 bits of every instruction
    uint32_t instruction;

    /// The opcode; bits 0..6 of the instruction
    int opcode;

    // Is this instruction 4 or 12 bytes long; bit 0 of the instruction
    int long_instruction;

    // bit 8 of the instruction which is within the ima24 address
    int memory_space;

    /// The parity bit; bit 7 of the instruction
    int parity;

    /// The register specifier at bits 8..11 of the instruction
    ///
    /// This register is sometimes called the source, sometimes the target,
    /// depending on the opcode.
    int tR;
    int r0;

    /// The register specifier at bits 12..15 of the instruction
    ///
    /// This register is always called the 'source' but is named generically
    /// here since sometimes the specifier at bits 8..11 is also called a
    /// 'source'.
    int sR;
    int r1;

    /// 'ImD16' is the signed 16-bit immediate for short immediate adds and
    /// subtracts.  For the rotate instruction this field also contains the
    /// rotate count which is either 1, 4, 8, 16 or 32.
    int16_t imd16;

    /// 'ImD20' is the 20-bit unsigned immediate for the LOAD20 instruction
    int32_t imd20;

    /// 'ImD24' is the 24-bit unsigned immediate for the WAIT instruction
    uint32_t imd24;

    /// 'ImA24' is the 24-bit unsigned immediate representing an address
    uint32_t ima24;

    /// 'ImD64' is the 64-bit immediate for data immediates and BRAI.  This
    /// field is only set for 3-word instructions.
    uint64_t imd64;

    /// 'ImPCO20' is a signed, 20-bit word offset for branch instructions
    int32_t impco20;

    /// 'ImPCO24' is a signed, 24-bit word offset for branch instructions
    int32_t impco24;

    /// 'ImPC48' is a signed, 48-bit word offset for branch instructions
    int64_t impc48;

    /// This is the base register specifier - either a memory (OCI) base
    /// register or a pervasive base register - for Read/Write operations.
    int base_register;

    /// This is the 22-bit signed offset for memory (OCI) addressing
    int32_t memory_offset;

    /// This field contains the port number and local address portions of the
    /// PIB/PCB address for load/store operations that target the PIB/PCB.
    /// Note that bits 0..11 will always be 0 in this address.  Bits 1..7 (the
    /// multicast bit and chiplet id) are sourced from the associated
    /// pervasive base register when the instruction executes.
    uint32_t pib_offset;

    /// The update bit of the SCAND instruction
    int update;

    /// The capture bit of the SCAND instruction
    int capture;

    /// The scan length from a SCAND instruction
    int scan_length;

    /// The scan select from a SCAND instruction
    uint32_t scan_select;

    /// The address offset from a SCAND instruction
    uint32_t scan_offset;

} PoreInlineDecode;

void
vpore_inline_decode_instruction(PoreInlineDecode *dis, uint32_t instruction);

void
vpore_inline_decode_imd64(PoreInlineDecode *dis, uint64_t imd64);

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif /* __ASSEMBLER__ */

#endif /* __PORE_INLINE_DECODE_H__ */
