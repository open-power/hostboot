//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/pore_model/ibuf/pore_ibuf.h $
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
#ifndef __PORE_IBUF_H__
#define __PORE_IBUF_H__

/******************************************************************************
 *
 * Virtual PORe Engine
 *
 *****************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#include "pore_regs.h"
#include "pore_model.h"
#include "pore_wrap.h"
#include "pore_inline_decode.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \brief Bit manipulation for Big-Endian data

/// A bit mask for a range of bits in a big-endian uint64_t
#define BE64_MASK(begin, end) \
    ((0xffffffffffffffffull >> (64 - ((end) - (begin) + 1))) << (63 - (end)))

/// A single bit mask for a big-endian uint64_t
#define BE64_BIT(n) (BE64_MASK((n), (n)))

/// Extract an unsigned field from a uint64_t
#define BE64_GET_FIELD(x, begin, end) \
    (((x) & BE64_MASK((begin), (end))) >> (63 - (end)))

/// Update an unsigned field in a uint64_t from a right-justified
/// uint64_t value
#define BE64_SET_FIELD(x, begin, end, val)			\
    ((((val) << (63 - (end))) &	 BE64_MASK((begin), (end))) |	\
     ((x) & ~BE64_MASK((begin), (end))))

/// A bit mask for a range of bits in a big-endian uint32_t
#define BE32_MASK(begin, end) \
    ((0xffffffff >> (32 - ((end) - (begin) + 1))) << (31 - (end)))

/// A single bit mask for a big-endian uint32_t
#define BE32_BIT(n) (BE32_MASK((n), (n)))

/// Extract an unsigned field from a uint32_t
#define BE32_GET_FIELD(x, begin, end) \
    (((x) & BE32_MASK((begin), (end))) >> (31 - (end)))

/// Update an unsigned field in a uint32_t from a right-justified
/// uint32_t value
#define BE32_SET_FIELD(x, begin, end, val)			\
    ((((val) << (31 - (end))) &	 BE32_MASK((begin), (end))) |	\
     ((x) & ~BE32_MASK((begin), (end))))

// State Definitions. These are the values of the status register
// 'State machine current state' field, that includes the PORE state
// machine state as bits 3:6. When the PORE is running, we report it
// as being in state EXEC. ABR is the address breakpoint state.

#define PORE_STATE_WAIT			0x02
#define PORE_STATE_EXEC			0x0e
#define PORE_STATE_ABR			0x16

/// The number of PORE error vectors
#define PORE_ERROR_VECTORS		5

/// The number of PORE EXE vectors
#define PORE_EXE_VECTORS		16

/// The size of a PORE BRAI instruction in bytes
#define PORE_VECTOR_SIZE		12

/// Branch modes for Hook implementation
#define FORCED_BRANCH_DISALLOWED	0
#define FORCED_BRANCH_FETCH_HOOK	1
#define FORCED_BRANCH_HOOK_INSTRUCTION	2

/* Main data of the pore_model hidden from the users */
struct pore_model {
	/* PORe State (for backup/restore) ----------------------------------*/
	pore_status_reg status;				/* 0x00000000 */
	pore_control_reg control;			/* 0x00000008 */
	pore_reset_reg reset;				/* 0x00000010 */
	pore_error_mask_reg error_mask;			/* 0x00000018 */
	pore_prv_base_address_reg prv_base[2];		/* 0x00000020 *
							 * 0x00000028 */
	pore_oci_base_address_reg oci_base[2];		/* 0x00000030
							 * 0x00000038 */
	pore_table_base_addr_reg table_base_addr;	/* 0x00000040 */
	pore_exe_trigger_reg exe_trigger;		/* 0x00000048 */
	pore_scratch0_reg scratch0;			/* 0x00000050 */
	uint64_t scratch1;				/* 0x00000058 */
	uint64_t scratch2;				/* 0x00000060 */
	pore_ibuf_01_reg ibuf_01;			/* 0x00000068 */
	pore_ibuf_2_reg ibuf_2;				/* 0x00000070 */
	pore_dbg0_reg dbg0;				/* 0x00000078 */
	pore_dbg1_reg dbg1;				/* 0x00000080 */
	pore_pc_stack0_reg pc_stack[3];			/* 0x00000088 *
							 * 0x00000090 *
							 * 0x00000098 */
	pore_id_flags_reg id_flags;			/* 0x000000a0 */
	uint64_t data0;					/* 0x000000a8 */
	pore_memory_reloc_reg memory_reloc;		/* 0x000000b0 */
	pore_i2c_en_param_reg i2c_e_param[3];		/* 0x000000b8 *
							 * 0x000000c0 *
							 * 0x000000c8 */
	uint64_t branchTaken;	/* last ins branch? pc updated?    d0 */
	uint64_t broken;	/* in case we ran on a breakpoint  d8 */
	uint32_t oci_fetchBufferValid;			/* 0x000000e0 */
	uint32_t oci_fetchBufferCursor;
	uint64_t oci_fetchBuffer;			/* 0x000000e8 */
	/* backup state ends here ------------------------------------------ */

	const char *name;
	void *priv;
	int state;
	int err_code;
	uint64_t trace_flags;

	/* disassembler support */
	unsigned int opcode_len;
	PoreInlineDecode dis;

	int enableTrap;		/* FIXME discuss this interface */
	int singleStep;		/* FIXME discuss this interface */
	uint64_t stack_pointer;

	/* Hook support */
	uint64_t forcedPc;
	int forcedBranch;	/* FIXME discuss this interface */
	int forcedBranchMode;	/* FIXME discuss this interface */

	int enableHookInstruction;
	instrHook_f instrHook;

	int enableAddressHooks;
	readHook_f   readHook;
	writeHook_f  writeHook;
	fetchHook_f  fetchHook;
	decodeHook_f decodeHook;

	waitCallback_f waitCallback;
	errorCallback_f errorCallback;
	errorCallback_f fatalErrorCallback;

	/* address translation objects */
	struct pore_bus *pib;		/* Pervasive Interconnect Bus */
	struct pore_bus *mem;		/* OCI or FI2C */
};

/* address conversion from pore to oci */
struct pore_bus *poreb_create_pore2oci(struct pore_model *pore,
				       const char *name,
				       struct pore_bus *oci);

/* attach the three fi2c-masters to the pore-model */
struct pore_bus *poreb_create_pore2fi2c(struct pore_model *pore,
					const char *name,
					struct pore_bus *fi2c0,
					struct pore_bus *fi2c1,
					struct pore_bus *fi2c2);

/* fast i2cm connected to pib bus */
struct pore_bus *poreb_create_fi2cm(struct pore_model *pm, const char *name,
				    pore_bus_t pib,
				    pore_i2c_en_param_reg *i2c_param);

int pore_handleErrEvent(pore_model_t p, int error_in, int model_err);

/**
 * @brief Attach PIB bus to PORe model.
 *
 * @param [in] p         reference to PORe model
 * @param [in] b         referenct to PIB bus-object
 */
int pore_attach_pib      (pore_model_t p, struct pore_bus *b);

/**
 * @brief Direct read access to PIB bus e.g. for fi2cm or scand
 * operations.
 */
int pore_pib_read  (pore_model_t p, uint64_t pib_addr, uint8_t *buf,
		    unsigned int len, int *err_code);

/**
 * @brief Direct write access to PIB bus e.g. for fi2cm or scand
 * operations.
 */
int pore_pib_write (pore_model_t p, uint64_t pib_addr, const uint8_t *buf,
		    unsigned int len, int *err_code);

#ifdef __cplusplus
}
#endif

#endif	/* __PORE_IBUF_H__ */
