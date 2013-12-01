/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/ibuf/pore_model.c $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: pore_model.c,v 1.26 2013/11/27 15:52:41 thi Exp $
/******************************************************************************
 *
 * Virtual PORe Engine
 *
 *****************************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pore_regs.h"
#include "pore_ibuf.h"
#include "pore_model.h"
#include "pore_inline_decode.h"

static int fetch(pore_model_t p);
static int decode(pore_model_t p);
static int execute(pore_model_t p);
static int finishBrokenInstruction(pore_model_t p);
static int __pore_flush_reset(pore_model_t p);

#define PORE_GET_BITS(X,S,N)						\
	((((~(0xFFFFFFFFFFFFFFFFull >> (N))) >> (S))			\
	  & (X)) >> (64 - (S)-(N)))
#define PORE_SET_BITS(Y,X,S,N,V)					\
	Y = (((X) & (~((~((~0x0)<<(N))) << (64-(S)-(N))))) |		\
	     (((~(0xFFFFFFFFFFFFFFFFull << (N))) & (V)) << (64 - (S)-(N))))

#define PORE_GET_BIT(X,S)     PORE_GET_BITS((X),(S),1)
#define PORE_SET_BIT(Y,X,S,V) PORE_SET_BITS(Y,(X),(S),1,(V))

/* Exception handling ********************************************************/

/// Set the PC to the Nth combined vector
static int
pore_vectorThroughTable(pore_model_t p, unsigned vector)
{
	uint32_t offset;

	if (vector >= (PORE_ERROR_VECTORS + PORE_EXE_VECTORS)) {
		BUG();
		return PORE_ERR_BUG_INVALID_VECTOR;
	}
	offset = p->table_base_addr.table_base_address +
		(vector * PORE_VECTOR_SIZE);

	p->status.pc = ((uint64_t)p->table_base_addr.memory_space << 32) +
		offset;

	dprintf(p, "%s: Jumping to vector %d @ %016llx\n",
		__func__, vector, (long long)p->status.pc);

	return PORE_SUCCESS;
}

/// Set the PC to an error vector
static inline int
pore_errorVector(pore_model_t p, unsigned error)
{
	return pore_vectorThroughTable(p, error);
}

/// Set the PC to an EXE vector
static int
pore_exeVector(pore_model_t p, unsigned vector)
{
	return pore_vectorThroughTable(p, PORE_ERROR_VECTORS + vector);
}

/* Support read/write registers with side effects ****************************/

static inline int
pore_stack0_reg_write(pore_model_t p, uint64_t val, uint64_t mask)
{
	int me = PORE_SUCCESS;
	int newSp;
	pore_pc_stack0_reg pps0;

	val &= PORE_PC_STACK0_VALID_BITS;
	p->pc_stack[0].val = ((val		  &  mask) |
			      (p->pc_stack[0].val & ~mask));
	p->pc_stack[0].set_stack_pointer = 0;
	p->pc_stack[0].new_stack_pointer = 0;

	pps0.val = val & mask;
	if (pps0.set_stack_pointer) {
		newSp = pps0.new_stack_pointer;
		if ((newSp != 1) &&
		    (newSp != 2) &&
		    (newSp != 4) &&
		    (newSp != 8)) {
			me = PORE_ERR_INVALID_STACK_POINTER;
		} else {
			p->status.stack_pointer = newSp;
		}
	}
	return me;
}

// NB: Technically, if the PORE is being held in reset no other
// register updates should go through or have effect. We don't model
// that, however, and instead just catch cases where firmware tries to
// execute PORE programs while PORE or the OCI master are in reset.

static inline int
pore_reset_reg_write(pore_model_t p, uint64_t val, uint64_t mask)
{
	pore_reset_reg reset;

	dprintf(p, "%s: val=%016llx mask=%016llx\n", __func__,
		(long long)val, (long long)mask);

	val &= PORE_RESET_VALID_BITS;
	reset.val = ((val	   &  mask) |
		     (p->reset.val & ~mask));

	if (mask & PORE_BITS_0_31) {
		if (reset.fn_reset)
			return pore_flush_reset(p);
		if (reset.oci_reset)
			return poreb_reset(p->mem);
		if (reset.restart_sbe_trigger) {
			/* FIXME SBE will reset and restart initial
			 * boot code execution
			 */
			return pore_flush_reset(p);
		}
	}

	/* The bits of this register are self clearing after the
	 * resets have been performed. Don't write bits back.
	 */
	return PORE_SUCCESS;
}

static inline void
pore_status_reg_print(pore_status_reg *status)
{
	aprintf("  PORE_STATUS %016llx\n"
		"      cur_state     = %02x freeze_action = %x\n"
		"      stack_pointer = %x  pc            = %llx\n",
		(long long)status->val,
		(unsigned int)status->cur_state,
		(unsigned int)status->freeze_action,
		(unsigned int)status->stack_pointer,
		(long long)status->pc);
}

static inline void
pore_control_reg_print(pore_control_reg *poreControl)
{
	aprintf("  PORE_CONTROL %016llx\n"
		"      start_stop    = %x continue_step = %x\n"
		"      skip	    = %x set_pc        = %x\n"
		"      lock_exe_trig = %x trap_enable   = %x\n"
		"      pc_brk_pt	    = %llx\n",
		(long long)poreControl->val,
		(unsigned int)poreControl->start_stop,
		(unsigned int)poreControl->continue_step,
		(unsigned int)poreControl->skip,
		(unsigned int)poreControl->set_pc,
		(unsigned int)poreControl->lock_exe_trig,
		(unsigned int)poreControl->trap_enable,
		(long long)poreControl->pc_brk_pt);
}


/// Control register write side effects
///
/// \bug This model is not correct (does not implement) all cases
/// regarding stopping/starting/continue/breakpoints/traps. This is a
/// low priority since OCC firmware is not expected to use these
/// features.

static inline int
pore_control_reg_write(pore_model_t p, uint64_t val, uint64_t mask)
{
	int me = PORE_SUCCESS;
	int squashWrite = 0;
	pore_control_reg poreControl;

	poreControl.val = val;

	if (p->trace_flags & PORE_TRACE_IBUF)
		pore_control_reg_print(&poreControl);

	if (p->reset.fn_reset == 1) {
		return PORE_ERR_IN_RESET;
	}

	// Move the value to a local base register for field decoding,
	// then process control actions.
	if (mask & PORE_BITS_0_31) {

		// Processing Set PC. This only happens on 64-bit
		// writes!!! And if it happens, everything else is
		// ignored. It is considered a firmware error to set
		// the PC when the hardware is not in the wait state.
		if (poreControl.set_pc && (mask & PORE_BITS_32_63)) {
			squashWrite = 1;
			if ((p->control.start_stop != 1) ||
			    (p->status.cur_state != PORE_STATE_WAIT)) {
				me = PORE_ERR_NOT_STOPPED_WAIT;
			} else {
				p->status.pc = poreControl.pc_brk_pt;
			}
		} else {
			// Processing START/STOP bit.  If this bit is
			// set the PORE stops in the WAIT state.  If
			// we were in the ABR state we have to finish
			// the instruction first.

			if (poreControl.start_stop) {
				p->status.cur_state = PORE_STATE_WAIT;
			} else if (p->status.cur_state == PORE_STATE_WAIT) {
				p->status.cur_state = PORE_STATE_EXEC;
			}

			// Hitting the continue bit will restart a
			// machine in the ABR (address breakpoint)
			// state. If in any other state we punt.

			if (poreControl.continue_step) {
				if (p->status.cur_state == PORE_STATE_ABR) {
					p->status.cur_state = PORE_STATE_EXEC;
					finishBrokenInstruction(p);

				} else {
					me = PORE_ERR_BEHAVIOR_NOT_MODELED;
				}
			}

			if (poreControl.skip) {
				me = PORE_ERR_BEHAVIOR_NOT_MODELED;
			}
		}
	}

	if (!me && !squashWrite) {

		// Clear any 'pulse-mode' bits in the register before writing
		poreControl.continue_step = 0;
		poreControl.skip = 0;
		poreControl.set_pc = 0;

		p->control.val = ((poreControl.val &  mask) | /* new val */
				  (p->control.val  & ~mask)); /* old val */

		dprintf(p, "  new control reg val=%016llx\n",
			(long long)p->control.val);
	}

	return me;
}

/// EXE_Trigger Register Write Function
///
/// This function writes to the Exe trigger register and also schedules
/// the instruction for execution when LO order word is written. No side
/// effect when HI order word is written.

static inline int
pore_exe_trigger_reg_write(pore_model_t p, uint64_t val, uint64_t mask)
{
	val &= PORE_EXE_TRIGGER_VALID_BITS;
	if (p->reset.fn_reset == 1) {
		return PORE_ERR_IN_RESET;

	}

	if (p->control.lock_exe_trig &&
	    !p->control.interrupt_sequencer_enabled) {
		return PORE_ERR_REGISTER_LOCKED;
	}

	if (mask == PORE_BITS_32_63) {
		p->exe_trigger.val = ((val		  &  mask) |
				      (p->exe_trigger.val & ~mask));
		return PORE_SUCCESS;
	}

	if (p->control.interrupt_sequencer_enabled) {
		if (p->control.pore_interruptible == 0) {
			/* enque request, remember desired exe_trigger_reg */
			p->pore_interrupt_request = 1;
			p->dbg0.interrupt_counter = 0x00;
			p->exe_trigger.val = ((val		  &  mask) |
					      (p->exe_trigger.val & ~mask));

			return PORE_SUCCESS;
		} else {
			/* else do the trigger, and wipe out the request */
			p->pore_interrupt_request = 0;
		}
	}

	p->exe_trigger.val = ((val		  &  mask) |
			      (p->exe_trigger.val & ~mask));

	/* Lock the EXE_TRIGGER register, compute the new starting PC,
	 * and begin execution.
	 */
	p->control.lock_exe_trig = 1;
	p->control.start_stop = 0;
	pore_exeVector(p, p->exe_trigger.start_vector);

	return PORE_SUCCESS;
}

/// write method for IBUF_01 register. Upon write to the ibuf_0 part
/// it executes the instruction.
/// The PORE IBUF0,1,2 registers are read-only, when Instruction
/// engine is in automatic run-mode (Control Register(0) = 0).

static int
pore_ibuf_01_reg_write(pore_model_t p, uint64_t val, uint64_t mask)
{
	int me = PORE_SUCCESS;

	if (p->reset.fn_reset == 1) {
		return PORE_ERR_IN_RESET;
	}
	if (p->control.start_stop != 1) {
		return PORE_ERR_NOT_STOPPED;
	}

	p->ibuf_01.val = ((val		  &  mask) |
			  (p->ibuf_01.val & ~mask));

	if (mask & PORE_BITS_0_31) {
		me = decode(p);
		if (me != PORE_SUCCESS)
			return me;

		me = execute(p);
		if (me != PORE_SUCCESS)
			return me;

		/* Extension for interruptible operation of SLW instance */
		if (p->control.interrupt_sequencer_enabled &&
		    p->pore_interrupt_request) {

			if (p->control.pore_interruptible) {
				__pore_flush_reset(p);
				pore_exe_trigger_reg_write(p,
							   p->exe_trigger.val,
							   PORE_BITS_0_63);
			} else {
				if (p->dbg0.interrupt_counter != 0xff)
					p->dbg0.interrupt_counter++;
			}
		}

		/* FIXME In case of stuffing instructions I strongly
		   assume that the PC must not be upated. */
	}
	return me;
}

void pore_set_trace(pore_model_t pm, uint64_t trace)
{
	pm->trace_flags = trace;
}

uint64_t pore_get_trace(pore_model_t pm)
{
	return pm->trace_flags;
}

int pore_instrHook(pore_model_t p, uint64_t addr,
		   uint32_t im24, uint64_t im64)
{
	if (!p->instrHook)
		return 0;
	return p->instrHook(p, addr, im24, im64);
}

int pore_readHook(pore_model_t p, uint64_t addr)
{
	if (!p->readHook)
		return 0;
	return p->readHook(p, addr);
}

int pore_writeHook(pore_model_t p, uint64_t addr)
{
	if (!p->writeHook)
		return 0;
	return p->writeHook(p, addr);
}

int pore_fetchHook(pore_model_t p, uint64_t addr)
{
	if (!p->fetchHook)
		return 0;
	return p->fetchHook(p, addr);
}

static int pore_decodeHook(pore_model_t p, uint8_t *instr, unsigned int size)
{
	if (!p->decodeHook)
		return 0;
	return p->decodeHook(p, instr, size);
}

static void pore_waitCallback(pore_model_t p, uint32_t delay)
{
	if (!p->waitCallback)
		return;
	p->waitCallback(p, delay);
}

static void incrPc(pore_model_t p)
{
	p->status.pc += p->opcode_len;
}

static void setJmpTarget(int offset, _PoreAddress *next_pc)
{
	next_pc->offset += offset * 4;
}

/**
 * Implements Add Operation with Status Flag Set.
 * This function received the pre constructed operands for ADD and calculates
 * ALU Status flags. It also updates the id_flags register.
 * \param op1      operand 1
 * \param op2      operand 2
 * \param result   result of operaton
 * \param opcode   opcode which was executed
 *                 (e.g. SUBx will change g* and s* flags)
 * \retval         PORE_SUCCESS
 * \todo Make match VHDL model - several issues to resolve.
 *
 * See also: Table 4.7: Ibuf internal register: ALU flags and Ibuf-ID.
 */
static int setAluFlags(pore_model_t p, int64_t op1, int64_t op2,
		       int64_t result, int opcode)
{
	PoreInlineDecode *dis = &p->dis;
	pore_id_flags_reg *id_flags = &p->id_flags;

	/* Flags are updated only when target is scr1 or src2 */
	if (dis->tR != PORE_SCRATCH1_ENC && dis->tR != PORE_SCRATCH2_ENC) {
		return PORE_SUCCESS;
	}

	/* N: bit 0 of result goes to N; is result negative? */
	id_flags->n = PORE_GET_BIT(result, 0);

	/* Z: set zero bit */
	if (result == 0) {
		id_flags->z = 1;
	} else {
		id_flags->z = 0;
	}

	/* O: check for overflows */
	if ((~((op1 ^ op2) >> 63) & 0x1ull) &
	    (((result ^ op1) >> 63) & 0x1ull)) {
		id_flags->o = 1;
	} else {
		id_flags->o = 0;
	}

	/* C: set carry bit */
	if( op2 == 0) {
	  id_flags->c = 1;
	} else if (((op1 & 0x7fffffffffffffffull) +
	            (op2 & 0x7FFFFFFFFFFFFFFFull)) & (0x1ull << 63)) {

		if ((PORE_GET_BIT(op1,0) + PORE_GET_BIT(op2,0) + 1 ) >> 1) {
			id_flags->c = 1;
		} else {
			id_flags->c = 0;
		}
	} else {
		if ((PORE_GET_BIT(op1,0) + PORE_GET_BIT(op2,0) ) >> 1) {
			id_flags->c = 1;
		} else {
			id_flags->c = 0;
		}

	}

	/* UGT, ULT, SGT, SLT */
	if ((opcode == PORE_OPCODE_SUB) ||
	    (opcode == PORE_OPCODE_SUBI)) {
		/* UGT = C AND !Z */
		id_flags->ugt = ((id_flags->c  & ~id_flags->z) & 0x1);

		/* ULT = !C AND !Z */
		id_flags->ult = ((~id_flags->c & ~id_flags->z) & 0x1);

		/* SGT = (N AND V AND !Z) OR (!N AND !V AND !Z)
		 */
		id_flags->sgt = (((id_flags->n &
				   id_flags->o &
				   ~id_flags->z) & 0x1) |
				 ((~id_flags->n &
				   ~id_flags->o &
				   ~id_flags->z) & 0x1));

		/* SLT = (N AND !V) OR (!N AND V) */
		id_flags->slt = (((id_flags->n & ~id_flags->o) & 0x1 ) |
				 ((~id_flags->n & id_flags->o) & 0x1 ));
	}
	/* If the instruction is an ADD, then by specification the
	 * UGT/ULT/SGT/SLT bits are cleared.
	 */
	else if ((opcode == PORE_OPCODE_ADD) ||
		 (opcode == PORE_OPCODE_ADDI)) {
		id_flags->ugt = 0;
		id_flags->ult = 0;
		id_flags->sgt = 0;
		id_flags->slt = 0;
	}

	return 0;
}

/*** Address Decoding ********************************************************/

/// Relocate a memory address if it's in the relocation region
void pore_relocateAddress(pore_model_t p, uint64_t *addr)
{
	_PoreAddress address;

	address.val = *addr;

	if (p->memory_reloc.memory_reloc_region == (address.offset >> 30)) {
		address.offset += (p->memory_reloc.memory_reloc_base << 12);
	}
	*addr = address.val;
}

/// Compute OCI effective and real addresses and handle hooks. The
/// returned address is the real (physical) _PoreAddress.
static int computeOciDataAddress(pore_model_t p, uint32_t ima24,
				 _PoreAddress *address, int read_not_write)
{
	uint32_t base_select = ima24 & 0x400000;
	pore_oci_base_address_reg oci_base;

	// First compute an effective address.  The 'oci_mem_route' is
	// in the form of a memory space descriptor, minus the
	// high-order bit. This memory route is only used in the
	// PORE-SBE.

	if (base_select) {
		oci_base.val = p->oci_base[1].val;
	} else {
		oci_base.val = p->oci_base[0].val;
	}

	address->memorySpace = oci_base.oci_mem_route | 0x8000;
	address->offset = oci_base.oci_base_address + (ima24 & 0x003FFFFF);

	if (pore_get_enableAddressHooks(p)) {
		if (read_not_write) {
			pore_readHook(p, address->val);
		} else {
			pore_writeHook(p, address->val);
		}
	}

	// Return the relocated address
	pore_relocateAddress(p, &address->val);
	return 0;
}

/* Internal register encodings ***********************************************/

static uint64_t __readReg(pore_model_t p, pore_internal_reg_t reg)
{
	switch (reg) {
	case PORE_PRV_BASE_ADDR0_ENC:	return p->prv_base[0].val >> 32;
	case PORE_PRV_BASE_ADDR1_ENC:	return p->prv_base[1].val >> 32;
	case PORE_OCI_MEMORY_BASE_ADDR0_ENC: return p->oci_base[0].val;
	case PORE_OCI_MEMORY_BASE_ADDR1_ENC: return p->oci_base[1].val;
	case PORE_TABLE_BASE_ADDR_ENC:	return p->table_base_addr.val;
	case PORE_EXE_TRIGGER_ENC:	return p->exe_trigger.val;
	case PORE_SCRATCH0_ENC:		return p->scratch0.val >> 32;
	case PORE_SCRATCH1_ENC:		return p->scratch1;
	case PORE_SCRATCH2_ENC:		return p->scratch2;
	case PORE_DATA0_ENC:		return p->data0 >> 32;
	case PORE_ERROR_MASK_ENC:	return p->error_mask.val;
	case PORE_PC_ENC:		return p->status.pc;
	case PORE_ALU_IBUF_ID_ENC:	return p->id_flags.val;
	}

	eprintf(p, "%s: err: illegal reg %x\n", __func__, reg);
	return PORE_ERR_INVALID_PARAM;
}

static int __writeReg(pore_model_t p, pore_internal_reg_t reg, uint64_t val)
{
	switch (reg) {
	case PORE_PRV_BASE_ADDR0_ENC:
		p->prv_base[0].val =
			(val << 32) & PORE_PRV_BASE_ADDRESS_VALID_BITS;
		break;
	case PORE_PRV_BASE_ADDR1_ENC:
		p->prv_base[1].val =
			(val << 32) & PORE_PRV_BASE_ADDRESS_VALID_BITS;
		break;

	case PORE_OCI_MEMORY_BASE_ADDR0_ENC:
		p->oci_base[0].val =
			val & PORE_OCI_BASE_ADDRESS_VALID_BITS;
		break;
	case PORE_OCI_MEMORY_BASE_ADDR1_ENC:
		p->oci_base[1].val =
			val & PORE_OCI_BASE_ADDRESS_VALID_BITS;
		break;

	case PORE_TABLE_BASE_ADDR_ENC:
		p->table_base_addr.val = val;
		break;

	case PORE_EXE_TRIGGER_ENC:
		/**
		 * A COPY instruction to the EXE_Trigger register will
		 * only update the upper half of the register and not
		 * trigger a new start vector execution.
		 */
		p->exe_trigger.mc_chiplet_select_mask = val & 0xffffffff;
		break;

	case PORE_SCRATCH0_ENC:
		p->scratch0.val = (val << 32) & PORE_SCRATCH0_VALID_BITS;
		break;

	case PORE_SCRATCH1_ENC:
		p->scratch1 = val;
		break;
	case PORE_SCRATCH2_ENC:
		p->scratch2 = val;
		break;

	case PORE_DATA0_ENC:
		p->data0 = (val << 32) & PORE_DATA0_VALID_BITS;
		break;
	case PORE_ERROR_MASK_ENC:
		p->error_mask.val = val & PORE_ERROR_MASK_VALID_BITS;
		break;
	case PORE_PC_ENC:		p->status.pc = val; break;
	case PORE_ALU_IBUF_ID_ENC:
		p->id_flags.val = val & PORE_ID_FLAGS_VALID_BITS;
		break;
	default:
		eprintf(p, "%s: err: illegal reg %x\n", __func__, reg);
		return PORE_ERR_INVALID_PARAM;
	}
	return PORE_SUCCESS;
}

/*** Stack operations ********************************************************/

/**
 * Stack push. Only in the event of an error push do we allow the 3rd
 * level to be used.
 *
 * 0001: Stack empty
 * 0010: Stack filled up to level 1
 * 0100: Stack filled up to level 2
 * 1000: Stack filled up to level 3 (error handler only)
 */
static int push(pore_model_t p, uint64_t next_pc, int error)
{
	int rc = PORE_SUCCESS;
	pore_pc_stack0_reg pc_stack0;

	if (p->status.stack_pointer == 0x8) {
		BUG();
		p->dbg1.pc_stack_ovflw_undrn_err = 1;
		p->control.start_stop = 1; /* FIXME This is brute force */
		return PORE_ERR_STACK_OVERFLOW;
	}

	if ((p->status.stack_pointer == 0x4) && !error) {
		p->dbg1.pc_stack_ovflw_undrn_err = 1;
		rc = pore_handleErrEvent(p, 2, PORE_ERR_STACK_OVERFLOW);
		if (rc < 0) {
			return rc;
		}
	}

	pc_stack0.val = p->pc_stack[0].val;

	switch (p->status.stack_pointer) {
	case 0x1:
	case 0x2:
	case 0x4:
		p->pc_stack[2].pc_stack = p->pc_stack[1].pc_stack;
		p->pc_stack[1].pc_stack = p->pc_stack[0].pc_stack;
		pc_stack0.pc_stack	= next_pc;
		pore_stack0_reg_write(p, pc_stack0.val, PORE_BITS_0_63);

		p->status.stack_pointer = (p->status.stack_pointer << 1);
		break;
	default:
		return PORE_ERR_INVALID_STACK_POINTER;
	}

	return PORE_SUCCESS;
}

/**
 * Stack pop.
 *
 * 0001: Stack empty
 * 0010: Stack filled up to level 1
 * 0100: Stack filled up to level 2
 * 1000: Stack filled up to level 3 (error handler only)
 */
static int pop(pore_model_t p, _PoreAddress *next_pc)
{
	int rc;
	pore_pc_stack0_reg pc_stack0;

	pc_stack0.val = p->pc_stack[0].val;
	switch (p->status.stack_pointer) {
	case 0x1:
		p->dbg1.pc_stack_ovflw_undrn_err = 1;
		rc = pore_handleErrEvent(p, 2, PORE_ERR_STACK_UNDERFLOW);
		if (rc < 0)
			return rc;

	case 0x2:
	case 0x4:
	case 0x8:
		next_pc->val		= pc_stack0.pc_stack;
		pc_stack0.pc_stack	= p->pc_stack[1].pc_stack;
		pore_stack0_reg_write(p, pc_stack0.val, PORE_BITS_0_63);
		p->pc_stack[1].pc_stack = p->pc_stack[2].pc_stack;
		p->status.stack_pointer = p->status.stack_pointer >> 1;
		break;
	default:
		return PORE_ERR_INVALID_STACK_POINTER;
	}

	return PORE_SUCCESS;
}

/* Error handling ************************************************************/

/// Take Action Based on Error event and Error Mask setting.  If PORE
/// is programmed to stop on the error and d_errorBreak is true (the
/// default), we break simulation.

static void signalError(pore_model_t p)
{
	dprintf(p, "%s()\n", __func__);

	if (!p->errorCallback)
		return;
	p->errorCallback(p);
}

static void signalFatalError(pore_model_t p)
{
	dprintf(p, "%s()\n", __func__);

	if (!p->fatalErrorCallback)
		return;
	return p->fatalErrorCallback(p);
}

/**
 * Error event 0: During instruction execution phase, a non-zero
 * return code was received from PORE's pervasive PIB Master interface
 * or parity error detected in PIB read data.  The SBE will also use
 * this error event in case of a Fast I2C protocol hang (poll count
 * for SEEPROM/Flash/OTPROM access completion reached threshold as
 * defined in).  If error mask register bit20 is set, then the
 * return-code chiplet offline (0b010) does not trigger this error
 * event.
 *
 * Error event 1: During instruction execution phase, a non-zero
 * return code was received from PORE's OCI Master interface or parity
 * error detected in OCI read data (PORE_SBE has a pervasive PIB
 * Master IF only. So this error event is unused.)
 *
 * Error event 2: Error during instruction fetching or decode, which
 * is either:
 *  - bad instruction parity, if instruction parity checking is enabled
 *  - invalid instruction code
 *  - invalid start vector (SV) trigger
 *  - invalid instruction path (I2CM parameter miss)
 *  - invalid instruction operand (any other register selected than
 *    documented in (Table 4.8))
 *  - instruction counter (PC) overflow or underrun in relative addressing
 *  - PC stack overflow/underrun: BSR/BSRD to a full stack/RET on empty stack
 *  - instruction fetching error: a non-zero return-code was received
 *    during instruction fetching (single for short instruction or up to
 *    three times for long operations)
 *  - SBE only: Fast I2C protocol hang (poll count for SEEPROM/Flash/OTPROM
 *    access completion reached threshold during an instruction fetch).
 *
 * Each error cause is indicated by a corresponding bit in DBG
 * Register1.  Since errors on this event are fatal for PORE, it is
 * highly recommended to configure the actions âStop IBUF execution
 * and IBUF fatal error in the IBUF Error Mask register.  This is
 * the default setting.
 *
 * Error event 3: Internal data error during instruction execution:
 * Detected bad data consistency checking, e.g. bad scan-data CRC
 *
 * Error event 4: Error-on-Error. Any error occurred when DBG Regs0-1
 * are already locked: DBG_Reg1(63) = 1.
 *
 * Error events 2 and 3 will always freeze the DBG registers while
 * error event 0 and 1 will only freeze the DBG registers if the
 * corresponding Error Handler is enabled in the Error_Mask register.
 */
int
pore_handleErrEvent(pore_model_t p, int error_in, int model_err)
{
	int me, pc_offs;
	int error = error_in;

	// Check for error on error. If yes change to err event
	// 4. Else lock the debug registers for events 2, 3 and
	// 0, 1 only if err_handler is enabled.

	if (p->dbg1.debug_regs_locked == 1)
		error = 4;

	pc_offs = p->opcode_len;
	if ((pc_offs != 0) && (pc_offs != 4) && (pc_offs != 12))
		eprintf(p, "%s: err: illegal pc_offs=%d\n", __func__, pc_offs);

	switch (error) {
	case 0:
		if ((p->error_mask.enable_err_output0  == 0) &&
		    (p->error_mask.enable_fatal_error0 == 0) &&
		    (p->error_mask.stop_exe_on_error0  == 0) &&
		    (p->error_mask.enable_err_handler0 == 0))
			return PORE_ERROR_IGNORED;

		if (p->error_mask.enable_err_output0)
			signalError(p);
		if (p->error_mask.enable_fatal_error0)
			signalFatalError(p);
		if (p->error_mask.stop_exe_on_error0) {
			p->control.start_stop = 1;
		}
		else if (p->error_mask.enable_err_handler0) {
			p->dbg1.debug_regs_locked = 1;

			/* push pc onto stack, only if there is space */
			me = push(p, p->status.pc + pc_offs, 1);
			if (me < 0) {
				model_err = me;
				break;
			}
			pore_errorVector(p, 0);
			model_err = PORE_ERR_HANDLED_BY_CODE;
		}
		break;
	case 1:
		if ((p->error_mask.enable_err_output1  == 0) &&
		    (p->error_mask.enable_fatal_error1 == 0) &&
		    (p->error_mask.stop_exe_on_error1  == 0) &&
		    (p->error_mask.enable_err_handler1 == 0))
			return PORE_ERROR_IGNORED;

		if (p->error_mask.enable_err_output1)
			signalError(p);
		if (p->error_mask.enable_fatal_error1)
			signalFatalError(p);
		if (p->error_mask.stop_exe_on_error1) {
			p->control.start_stop = 1;
		}
		else if (p->error_mask.enable_err_handler1) {
			p->dbg1.debug_regs_locked = 1;

			/* push pc onto stack, only if there is space */
			me = push(p, p->status.pc + pc_offs, 1);
			if (me < 0) {
				model_err = me;
				break;
			}
			pore_errorVector(p, 1);
			model_err = PORE_ERR_HANDLED_BY_CODE;
		}
		break;
	case 2:
		p->dbg1.debug_regs_locked = 1;

		if ((p->error_mask.enable_err_output2  == 0) &&
		    (p->error_mask.enable_fatal_error2 == 0) &&
		    (p->error_mask.stop_exe_on_error2  == 0) &&
		    (p->error_mask.enable_err_handler2 == 0))
			return PORE_ERROR_IGNORED;

		if (p->error_mask.enable_err_output2)
			signalError(p);
		if (p->error_mask.enable_fatal_error2)
			signalFatalError(p);
		if (p->error_mask.stop_exe_on_error2) {
			p->control.start_stop = 1;
		}
		else if (p->error_mask.enable_err_handler2) {
			/* push pc onto stack, only if there is space */
			me = push(p, p->status.pc + pc_offs, 1);
			if (me < 0) {
				model_err = me;
				break;
			}
			pore_errorVector(p, 2);
			model_err = PORE_ERR_HANDLED_BY_CODE;
		}
		break;
	case 3:
		p->dbg1.debug_regs_locked = 1;

		if ((p->error_mask.enable_err_output3  == 0) &&
		    (p->error_mask.enable_fatal_error3 == 0) &&
		    (p->error_mask.stop_exe_on_error3  == 0) &&
		    (p->error_mask.enable_err_handler3 == 0))
			return PORE_ERROR_IGNORED;

		if (p->error_mask.enable_err_output3)
			signalError(p);
		if (p->error_mask.enable_fatal_error3)
			signalFatalError(p);
		if (p->error_mask.stop_exe_on_error3) {
			p->control.start_stop = 1;
		}
		else if (p->error_mask.enable_err_handler3) {
			/* push pc onto stack, only if there is space */
			me = push(p, p->status.pc + pc_offs, 1);
			if (me < 0) {
				model_err = me;
				break;
			}
			pore_errorVector(p, 3);
			model_err = PORE_ERR_HANDLED_BY_CODE;
		}
		break;
	case 4:
		if ((p->error_mask.enable_err_output4  == 0) &&
		    (p->error_mask.enable_fatal_error4 == 0) &&
		    (p->error_mask.stop_exe_on_error4  == 0) &&
		    (p->error_mask.enable_err_handler4 == 0))
			return PORE_ERROR_IGNORED;

		if (p->error_mask.enable_err_output4)
			signalError(p);
		if (p->error_mask.enable_fatal_error4)
			signalFatalError(p);
		if (p->error_mask.stop_exe_on_error4) {
			p->control.start_stop = 1;
		}
		else if (p->error_mask.enable_err_handler4) {
			me = push(p, p->status.pc + pc_offs, 1);
			if (me < 0) {
				model_err = me;
				break;
			}
			pore_errorVector(p, 4);
			model_err = PORE_ERR_HANDLED_BY_CODE;
		}
		break;
	default:
		return PORE_ERR_NOT_IMPLEMENTED;
	}
	return model_err;
}

/* External register encodings ***********************************************/

uint64_t pore_readReg(pore_model_t p, pore_reg_t reg, uint64_t msk)
{
	uint64_t val;

	switch (reg) {
	case PORE_R_STATUS:		val = p->status.val; break;
	case PORE_R_CONTROL:		val = p->control.val; break;
	case PORE_R_RESET:		val = p->reset.val; break;
	case PORE_R_ERROR_MASK:		val = p->error_mask.val; break;
	case PORE_R_PRV_BASE_ADDR0:	val = p->prv_base[0].val; break;
	case PORE_R_PRV_BASE_ADDR1:	val = p->prv_base[1].val; break;
	case PORE_R_OCI_MEMORY_BASE_ADDR0: val = p->oci_base[0].val; break;
	case PORE_R_OCI_MEMORY_BASE_ADDR1: val = p->oci_base[1].val; break;
	case PORE_R_TABLE_BASE_ADDR:	val = p->table_base_addr.val; break;
	case PORE_R_EXE_TRIGGER:	val = p->exe_trigger.val; break;
	case PORE_R_SCRATCH0:		val = p->scratch0.val; break;
	case PORE_R_SCRATCH1:		val = p->scratch1; break;
	case PORE_R_SCRATCH2:		val = p->scratch2; break;
	case PORE_R_IBUF_01:		val = p->ibuf_01.val; break;
	case PORE_R_IBUF_2:		val = p->ibuf_2.val; break;
	case PORE_R_DBG0:		val = p->dbg0.val; break;
	case PORE_R_DBG1:		val = p->dbg1.val; break;
	case PORE_R_PC_STACK0:		val = p->pc_stack[0].val; break;
	case PORE_R_PC_STACK1:		val = p->pc_stack[1].val; break;
	case PORE_R_PC_STACK2:		val = p->pc_stack[2].val; break;
	case PORE_R_ID_FLAGS:		val = p->id_flags.val; break;
	case PORE_R_DATA0:		val = p->data0; break;
	case PORE_R_MEM_RELOC:		val = p->memory_reloc.val; break;
	case PORE_R_I2C_E0_PARAM:	val = p->i2c_e_param[0].val; break;
	case PORE_R_I2C_E1_PARAM:	val = p->i2c_e_param[1].val; break;
	case PORE_R_I2C_E2_PARAM:	val = p->i2c_e_param[2].val; break;
	default:
		eprintf(p, "%s: err: illegal reg %x\n", __func__, reg);
		return PORE_ERR_INVALID_PARAM;
	}

	dprintf(p, "<== %s:  reg=%02x val=%016llx mask=%016llx\n",
		__func__, reg, (long long)val, (long long)msk);

	return val & msk;
}

uint64_t pore_readRegRaw(pore_model_t p, pore_reg_t reg,
			 uint64_t msk __attribute__((unused)))
{
	return pore_readReg(p, reg, msk);
}

static void write_under_mask(uint64_t *reg, uint64_t n_val, uint64_t mask)
{
	uint64_t o_val = *reg;
	*reg = ((n_val &  mask) | /* new val */
		(o_val & ~mask)); /* old val */
}

/**
 * Writing any data to either PIBMS_DBG Reg0 or Reg1 unsets their lock
 * and resets PIBMS_DBG1(63).
 */
int pore_writeReg(pore_model_t p, pore_reg_t reg, uint64_t val, uint64_t msk)
{
	dprintf(p, "==> %s: reg=%02x val=%016llx mask=%016llx\n",
		__func__, reg, (long long)val, (long long)msk);

	switch (reg) {
	case PORE_R_STATUS:
		write_under_mask(&p->status.val, val, msk);
		break;
	case PORE_R_CONTROL:				/* SIDE EFFECTS */
		return pore_control_reg_write(p, val, msk);

	case PORE_R_RESET:                              /* SIDE EFFECTS */
                return pore_reset_reg_write(p, val, msk);

	case PORE_R_ERROR_MASK:
		write_under_mask(&p->error_mask.val,
				 val & PORE_ERROR_MASK_VALID_BITS, msk);
		break;

	case PORE_R_PRV_BASE_ADDR0:
		write_under_mask(&p->prv_base[0].val,
				 val & PORE_PRV_BASE_ADDRESS_VALID_BITS, msk);
		break;
	case PORE_R_PRV_BASE_ADDR1:
		write_under_mask(&p->prv_base[1].val,
				 val & PORE_PRV_BASE_ADDRESS_VALID_BITS, msk);
		break;

	case PORE_R_OCI_MEMORY_BASE_ADDR0:
		write_under_mask(&p->oci_base[0].val,
				 val & PORE_OCI_BASE_ADDRESS_VALID_BITS, msk);
		break;
	case PORE_R_OCI_MEMORY_BASE_ADDR1:
		write_under_mask(&p->oci_base[1].val,
				 val & PORE_OCI_BASE_ADDRESS_VALID_BITS, msk);
		break;

	case PORE_R_TABLE_BASE_ADDR:
		write_under_mask(&p->table_base_addr.val, val, msk);
		break;
	case PORE_R_EXE_TRIGGER:		/* SIDE EFFECTS */
		return pore_exe_trigger_reg_write(p, val, msk);
	case PORE_R_SCRATCH0:
		write_under_mask(&p->scratch0.val,
				 val & PORE_SCRATCH0_VALID_BITS, msk);
		break;
	case PORE_R_SCRATCH1:
		write_under_mask(&p->scratch1, val, msk);
		break;
	case PORE_R_SCRATCH2:
		write_under_mask(&p->scratch2, val, msk);
		break;
	case PORE_R_IBUF_01:			/* SIDE EFFECTS */
		return pore_ibuf_01_reg_write(p, val, msk);
	case PORE_R_IBUF_2:
		write_under_mask(&p->ibuf_2.val, val, msk);
		break;
	case PORE_R_DBG0:
		p->dbg1.debug_regs_locked = 0; /* Writing will unlock */
		write_under_mask(&p->dbg0.val, val& PORE_DBG0_VALID_BITS, msk);
		break;
	case PORE_R_DBG1:
		p->dbg1.debug_regs_locked = 0; /* Writing will unlock */
		write_under_mask(&p->dbg1.val, val& PORE_DBG1_VALID_BITS, msk);
		break;
	case PORE_R_PC_STACK0:			/* SIDE EFFECTS */
		return pore_stack0_reg_write(p, val, msk);
	case PORE_R_PC_STACK1:
		write_under_mask(&p->pc_stack[1].val,
				 val & PORE_PC_STACK1_VALID_BITS, msk);
		break;
	case PORE_R_PC_STACK2:
		write_under_mask(&p->pc_stack[2].val,
				 val & PORE_PC_STACK2_VALID_BITS, msk);
		break;
	case PORE_R_ID_FLAGS:
		write_under_mask(&p->id_flags.val,
				 val & PORE_ID_FLAGS_VALID_BITS, msk);
		break;
	case PORE_R_DATA0:
		write_under_mask(&p->data0,
				 val & PORE_DATA0_VALID_BITS, msk);
		break;
	case PORE_R_MEM_RELOC:
		write_under_mask(&p->memory_reloc.val,
				 val & PORE_MEMORY_RELOC_VALID_BITS, msk);
		break;
	case PORE_R_I2C_E0_PARAM:
		write_under_mask(&p->i2c_e_param[0].val,
				 val & PORE_I2C_E0_PARAM_VALID_BITS, msk);
		break;
	case PORE_R_I2C_E1_PARAM:
		write_under_mask(&p->i2c_e_param[1].val,
				 val & PORE_I2C_E1_PARAM_VALID_BITS, msk);
		break;
	case PORE_R_I2C_E2_PARAM:
		write_under_mask(&p->i2c_e_param[2].val,
				 val & PORE_I2C_E2_PARAM_VALID_BITS, msk);
		break;
	default:
		eprintf(p, "%s: err: illegal reg %x\n", __func__, reg);
		return PORE_ERR_INVALID_PARAM;
	}
	return PORE_SUCCESS;
}

int pore_writeRegRaw(pore_model_t p, pore_reg_t reg, uint64_t val,
		     uint64_t msk)
{
	switch (reg) {
	case PORE_R_CONTROL:
		write_under_mask(&p->control.val, val, msk);
		break;
	case PORE_R_EXE_TRIGGER:
		write_under_mask(&p->exe_trigger.val,
				 val & PORE_EXE_TRIGGER_VALID_BITS, msk);
		break;
	case PORE_R_IBUF_01:
		write_under_mask(&p->ibuf_01.val, val, msk);
		break;
	case PORE_R_PC_STACK0:
		write_under_mask(&p->pc_stack[0].val, val, msk);
		break;
	case PORE_R_DBG0:
		write_under_mask(&p->dbg0.val, val& PORE_DBG0_VALID_BITS, msk);
		break;
	case PORE_R_DBG1:
		write_under_mask(&p->dbg1.val, val& PORE_DBG1_VALID_BITS, msk);
		break;

	default:
		return pore_writeReg(p, reg, val, msk);
	}
	return PORE_SUCCESS;
}

/*** PIB Bus with correct address translation using PORe offset regs *********/

/**
 * See Table 4.53: PRV address arithmetic.
 */
static int
computeDirectPibDataAddress(pore_model_t p, uint32_t ima24,
			    uint32_t *pibAddress, int read_not_write)
{
	int me = 0;
	_PoreAddress address;
	uint32_t baseSelect, localAddress, chipletId, mc, port;
	pore_prv_base_address_reg *prv_base;

	if (!p)
		return PORE_ERR_INVALID_PARAM;

	localAddress = ima24 & 0xffff;
	port = (ima24 >> 16) & 0xf;
	address.val = 0;
	address.offset = localAddress << 2;

	baseSelect = ima24 & 0x400000;
	if (baseSelect) {
		prv_base = &p->prv_base[1];
	} else {
		prv_base = &p->prv_base[0];
	}

	chipletId = prv_base->chiplet_id;
	mc = prv_base->mc;			/* multicast */
	address.memorySpace = (mc << 14) | (chipletId << 8) | port;

	if (pore_get_enableAddressHooks(p)) {
		if (read_not_write) {
			pore_readHook(p, address.val);
		} else {
			pore_writeHook(p, address.val);
		}
	}

	*pibAddress = (address.memorySpace << 16) | localAddress;
	return me;
}

int pore_pib_write(pore_model_t p, uint64_t addr, const uint8_t *buf,
		   unsigned int len, int *err_code)
{
	int rc;
	struct pore_bus *pib = p->pib;

	if (!pib)
		return PORE_ERR_UNCONNECTED_BUS;
	if (len != 8) {
		BUG();
		return PORE_ERR_INVALID_PARAM;
	}

	rc = poreb_write(pib, addr, buf, len, err_code);

	if (p->dbg1.debug_regs_locked == 0) {
		p->dbg0.last_completed_address = addr & 0xFFFFFFFF;
		p->dbg0.last_ret_code_prv = *err_code;
	}

	p->id_flags.pib_status = *err_code;
	p->id_flags.pib_parity_fail = 0;

	pib_printf(p, "  putScom: addr=%016llx data=%016llx err_code=%x\n",
		   (long long)addr, *(long long *)buf, *err_code);

	return rc;
}

int pore_pib_read(pore_model_t p, uint64_t addr, uint8_t *buf,
		  unsigned int len, int *err_code)
{
	int rc;
	struct pore_bus *pib = p->pib;

	if (!pib)
		return PORE_ERR_UNCONNECTED_BUS;
	if (len != 8) {
		BUG();
		return PORE_ERR_INVALID_PARAM;
	}

	rc = poreb_read(pib, addr, buf, len, err_code);
	if (p->dbg1.debug_regs_locked == 0) {
		p->dbg0.last_completed_address = addr & 0xFFFFFFFF;
		p->dbg0.last_ret_code_prv = *err_code;
	}

	p->id_flags.pib_status = *err_code;
	p->id_flags.pib_parity_fail = 0;

	pib_printf(p, "  getScom: addr=%016llx data=%016llx err_code=%x\n",
		   (long long)addr, *(long long *)buf, *err_code);

	return rc;
}

/// Fetch an instruction word using PIB direct addressing. This is
/// somewhat analogous to the OCI fetch buffer case in that we fetch 8
/// bytes but only return 4, however for some reason they don't buffer
/// PIB fetches.

static int
fetchInstructionWordPibDirect(pore_model_t p, _PoreAddress *pc,
			      uint32_t *word, int *err_code)
{
	int rc = 0;
	uint64_t data;
	uint32_t offset = pc->offset;
	uint32_t pibAddress = (pc->memorySpace << 16) | (offset >> 3);
	struct pore_bus *pib = p->pib;

	if (!pib)
		return PORE_ERR_UNCONNECTED_BUS;

	/* always fetch 8 byte on the PIB */
	rc = poreb_read(pib, pibAddress, (uint8_t *)&data, sizeof(data),
			err_code);

	if (p->dbg1.debug_regs_locked == 0) {
		p->dbg0.last_completed_address = pibAddress & 0xFFFFFFFF;
		p->dbg0.last_ret_code_prv = *err_code;
	}

	p->id_flags.pib_status = *err_code;
	p->id_flags.pib_parity_fail = 0;

	pib_printf(p, "  getScom: addr=%016llx data=%016llx err_code=%x\n",
		   (long long)pibAddress, (long long)data, *err_code);

	if (rc != sizeof(data)) {
		return PORE_ERR_FETCH;
	}

	*word = ((offset & 0x7) == 0) ?	data >> 32 : data & 0xffffffff;
	return rc;
}

static int pore_pib_fetch(pore_model_t p, uint64_t _pc,
			  uint64_t *ibuf_01,
			  uint64_t *ibuf_2,
			  unsigned int *size,
			  int *err_code)
{
	int me;
	uint32_t i_word;
	_PoreAddress pc;

	*ibuf_01 = *ibuf_2 = 0;
	pc.val = _pc;
	me = fetchInstructionWordPibDirect(p, &pc, &i_word, err_code);
	if (me < 0)
		return me;

	*ibuf_01 = (uint64_t)i_word << 32;
	*size = 4;
	if (i_word & 0x80000000) {
		pc.offset += 4;
		me = fetchInstructionWordPibDirect(p, &pc, &i_word, err_code);
		if (me < 0)
			return me;
		*size += 4;
		*ibuf_01 |= i_word;
		pc.offset += 4;
		me = fetchInstructionWordPibDirect(p, &pc, &i_word, err_code);
		if (me < 0)
			return me;
		*size += 4;
		*ibuf_2 = (uint64_t)i_word << 32;
	}
	return PORE_SUCCESS;
}

/*****************************************************************************/

/// The Instruction Fetch Routine
///
/// This function computes the effective address and fetches the
/// instructions from the fetch buffer to IBUF.

static int fetch(pore_model_t p)
{
	int rc;
	int recursion_stop = 0;

 redo_fetch:
	if (recursion_stop == 2)
		return PORE_ERR_INVALID_PARAM; /* STOP calling myself */

	if (!p)
		return PORE_ERR_INVALID_PARAM;

	if (p->enableAddressHooks && p->fetchHook) {
		int _rc;

		/* FIXME There is some more done in the existing model
		 * e.g. setting forchedBranchMode ...  Need to
		 * understand it before I will reintegrate.
		 */
		p->forcedBranch = 0;
		p->forcedBranchMode = FORCED_BRANCH_FETCH_HOOK;
		_rc = pore_fetchHook(p, p->status.pc);
		p->forcedBranchMode = FORCED_BRANCH_DISALLOWED;

		/* Model was modified from outside!!! */
		if (!_rc) {
			if (p->forcedBranch) {
				p->status.pc = p->forcedPc;
				recursion_stop++;
				goto redo_fetch;
			}
		}
	}

	/* zero the input buffers, such that we see 0s even on errors */
	p->ibuf_01.val = 0;
	p->ibuf_2.val = 0;

	if (p->status.pc & 0x0000800000000000ull) {
		rc = poreb_fetch(p->mem, p->status.pc,
				 &p->ibuf_01.val, &p->ibuf_2.val,
				 &p->opcode_len, &p->err_code);
	} else {
		rc = pore_pib_fetch(p, p->status.pc,
				    &p->ibuf_01.val, &p->ibuf_2.val,
				    &p->opcode_len, &p->err_code);

		/* Error occured during transaction try to handle it */
		if ((rc < 0) && (p->id_flags.pib_status != PORE_PCB_SUCCESS)) {
			dprintf(p, "PCB ERROR %x occured\n",
				(unsigned int)p->id_flags.pib_status);

			if ((p->id_flags.pib_status != PORE_PCB_CHIPLET_OFFLINE) ||
			    (p->error_mask.gate_chiplet_offline_err == 0)) {
				rc = pore_handleErrEvent(p, 2, rc);
			} else {
				/* HW190098: PORE Model not handling
				   mask of offline cores correctly */
				rc = PORE_SUCCESS;
			}
		}
	}

	if (p->dbg1.debug_regs_locked == 0)
		p->dbg1.pc_last_access = p->status.pc;
	if (rc < 0) {
		if (p->dbg1.debug_regs_locked == 0)
			p->dbg1.instruction_fetch_error = 1;
		rc = pore_handleErrEvent(p, 2, rc);
		return rc;
	}
	return rc;
}

static int decode(pore_model_t p)
{
	uint32_t *q;
	PoreInlineDecode *dis;

	if (!p)
		return PORE_ERR_INVALID_PARAM;

	dis = &p->dis;
	vpore_inline_decode_instruction(dis, p->ibuf_01.ibuf0);
	vpore_inline_decode_imd64(dis, ((uint64_t)p->ibuf_01.ibuf1 << 32 |
					(uint64_t)p->ibuf_2.ibuf2));

	p->opcode_len = 4;
	if (dis->long_instruction)
		p->opcode_len = 12;

	if (p->decodeHook) {
		unsigned int i;
		uint8_t instr[12];

		/* data was temporarily turned into the host format */
		q = (uint32_t *)instr;
		q[0] = htobe32(p->ibuf_01.ibuf0);
		q[1] = htobe32(p->ibuf_01.ibuf1);
		q[2] = htobe32(p->ibuf_2.ibuf2);

		dprintf(p, "  IBUF[0..2]=");
		for (i = 0; i < p->opcode_len; i++)
			dprintf(p, "%02x", instr[i]);

		dprintf(p, "\n"
			"  STAT %016llx CONT %016llx\n"
			"  D0   %016llx D1   %016llx CTR  %016llx\n"
			"  P0   %016llx P1   %016llx EMR  %016llx\n"
			"  A0   %016llx A1   %016llx ETR  %016llx\n"
			"  I2C0 %016llx I2C0 %016llx I2C0 %016llx\n"
			"  DBG0 %016llx DBG1 %016llx\n",
			(long long)p->status.val,
			(long long)p->control.val,

			(long long)p->scratch1,
			(long long)p->scratch2,
			(long long)p->scratch0.val,

			(long long)p->prv_base[0].val,
			(long long)p->prv_base[1].val,
			(long long)p->error_mask.val,

			(long long)p->oci_base[0].val,
			(long long)p->oci_base[1].val,
			(long long)p->exe_trigger.val,

			(long long)p->i2c_e_param[0].val,
			(long long)p->i2c_e_param[1].val,
			(long long)p->i2c_e_param[2].val,

			(long long)p->dbg0.val,
			(long long)p->dbg1.val);

		pore_decodeHook(p, instr, p->opcode_len);
	}
	return 0;
}

static int inExeInterfaceWrite(pore_model_t p, uint64_t write_data)
{
	int rc;
	PoreInlineDecode *dis = &p->dis;
	uint32_t addr_space, pib_addr;
	_PoreAddress address;
	uint64_t addr = dis->ima24;

	/* OCI/MEM Address Space *********************************************/
	addr_space = addr & 0x800000;
	if (addr_space) {
		address.val = 0;
		computeOciDataAddress(p, addr & 0xFFFFFF, &address, 0);
		rc = poreb_write(p->mem, address.val, (uint8_t *)&write_data,
				 sizeof(write_data), &p->err_code);

		if (p->dbg1.debug_regs_locked == 0) {
			p->dbg1.oci_master_rd_parity_err = 0;
			p->dbg1.last_ret_code_oci = p->err_code;
		}
		mem_printf(p, "  putMem:  addr=%016llx data=%016llx "
			   "err_code=%x\n", (long long)address.val,
			   (long long)write_data, p->err_code);

		if (rc == sizeof(write_data))
			return PORE_SUCCESS;

		rc = pore_handleErrEvent(p, 1, rc);
		return rc;
	}

	/* PIB Address Space *************************************************/
	address.val = 0;
	computeDirectPibDataAddress(p, addr, &pib_addr, 0);
	rc = pore_pib_write(p, pib_addr, (uint8_t *)&write_data,
			    sizeof(write_data), &p->err_code);
	if (rc == sizeof(write_data))
		rc = PORE_SUCCESS;

	/* Error occured during transaction try to handle it */
	if ((rc < 0) && (p->id_flags.pib_status != PORE_PCB_SUCCESS)) {
		if ((p->id_flags.pib_status != PORE_PCB_CHIPLET_OFFLINE) ||
		    (p->error_mask.gate_chiplet_offline_err == 0)) {

			rc = pore_handleErrEvent(p, 0, rc);
		} else {
			/* HW190098: PORE Model not handling mask of
			   offline cores correctly */
			rc = PORE_SUCCESS;
		}
	}
	return rc;
}

static int inExeInterfaceRead(pore_model_t p, uint64_t *read_data)
{
	int rc;
	PoreInlineDecode *dis = &p->dis;
	uint32_t addr_space, pib_addr;
	_PoreAddress address;
	uint64_t addr = dis->ima24;

	*read_data = 0;

	/* OCI/MEM Address Space *********************************************/
	addr_space = addr & 0x800000;
	if (addr_space) {
		address.val = 0;
		computeOciDataAddress(p, addr & 0xFFFFFF, &address, 1);
		rc = poreb_read(p->mem, address.val, (uint8_t *)read_data,
				sizeof(*read_data), &p->err_code);

		if (p->dbg1.debug_regs_locked == 0) {
			p->dbg1.oci_master_rd_parity_err = 0;
			p->dbg1.last_ret_code_oci = p->err_code;
		}

		mem_printf(p, "  getMem:  addr=%016llx data=%016llx "
			   "err_code=%x\n", (long long)address.val,
			   (long long)*read_data, p->err_code);

		if (rc == sizeof(*read_data))
			return PORE_SUCCESS;

		rc = pore_handleErrEvent(p, 1, rc);
		return rc;
	}

	/* PIB Address Space *************************************************/
	address.val = 0;
	computeDirectPibDataAddress(p, addr, &pib_addr, 1);
	rc = pore_pib_read(p, pib_addr, (uint8_t *)read_data,
			   sizeof(*read_data), &p->err_code);
	if (rc == sizeof(*read_data))
		rc = PORE_SUCCESS;

	/* Error occured during transaction try to handle it */
	if ((rc < 0) && (p->id_flags.pib_status != PORE_PCB_SUCCESS)) {
		if ((p->id_flags.pib_status != PORE_PCB_CHIPLET_OFFLINE) ||
		    (p->error_mask.gate_chiplet_offline_err == 0)) {
			rc = pore_handleErrEvent(p, 0, rc);
		} else {
			/* HW190098: PORE Model not handling mask of
			   offline cores correctly */
			rc = PORE_SUCCESS;
		}
	}
	return rc;
}


/**
 * Example how to do scan a chain via the FSI Scan engine.
 *
 * General approach:
 *
 * 1. Write the length of the scan chain to be shifted (in this case
 * '1') and the control bits into the Front End Length Register
 * putcfam pu 0c02 00000001
 *
 * you might also want to set bit2 (setpulse) or bit4 (header check)
 * ... but that depends.
 *
 * 2. Setup the Command Register with the address of the scan chain
 * and the desired operation
 *
 * Now it gets a little more tricky: Bit 0 of the Command Register is
 * a write/not_read bit. We will take the write case. The following
 * 31 bits is the address of the scan chain.
 *
 * There are three easy ways to find that:
 *   - CRONUS: do a getringdump to that ring, and see what is in
 *     0c01 => getcfam pu 0c01
 *   - CRONUS: do a getringdump pu RINGNAME -debug5.15.f and check
 *     for the mentioned address take a look at the scandef
 *
 * 3. Write to the FIFO with the scan info.
 *   putcfam pu 0c00 00000000
 *
 * Repeat step 3. for the length of the scan chain ( => length/32 times ).
 *
 * 4. Check the status (not mandatory :-) )
 * getcfam pu 0c07
 *
 * Example: Scan of ex_dpll_gptr chain on P7
 *
 * # scan in
 * putcfam pu 0c02 00000147
 * putcfam pu 0c01 88030402
 *
 * putcfam pu 0c00 DEADBEEF
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 * putcfam pu 0c00 00000000
 *
 * # scan out
 * putcfam pu 0c02 00000147
 * putcfam pu 0c01 08030402
 *
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 * getcfam pu 0c00
 *
 * Here and example doing the scan via SCOM commands:
 * 1.) Configure Clock Control of respective chiplet
 * 2.) Write data packets
 *
 * Example of EN_LBST Chain with manual 'Headercheck' (DEADBEEF as Header)
 *
 * en_lbst_scan
 * putscom pu 03030007 5E000800
 *
 * putscom pu 03038020 deadbeef
 * putscom pu 03038020 11112222
 * putscom pu 03038020 33334444
 * putscom pu 03038020 55556666
 * putscom pu 03038020 77778888
 * putscom pu 03038020 9999aaaa
 * putscom pu 03038020 bbbbcccc
 * putscom pu 03038020 ddddeeee
 * putscom pu 03038020 ffff1212
 * putscom pu 03038020 23233434
 * putscom pu 03038020 FE000000
 * putscom pu 03038020 23233434
 * putscom pu 03038020 23233434
 * putscom pu 03038020 23233434
 * putscom pu 03038020 23233434
 * putscom pu 0303801C 23233434
 *
 * echo "HEADERCHECK:"
 * getscom pu 03038000
 *
 * putscom pu 03038020 deadbeef
 * getscom pu 03038000
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 03038020
 * getscom pu 0303801C
 *
 * Binary to Unary Translation of scan_sel:
 *  WHEN 11 scantype_allf => result := "1101.1100.1110.0000";
 *  WHEN 12 scantype_ccvf => result := "0010.1000.0000.0000";
 *  WHEN 13 scantype_lbcm => result := "0000.1000.0010.0000";
 *  WHEN 14 scantype_abfa => result := "0000.0100.0100.0000";
 *  WHEN 15 scantype_fure => result := "1001.0000.0000.0000";
 */
static const uint16_t bin_2_unary[] = {
	/* unary                binary */
	0x8000,			/* 0x0  0 */
	0x4000,			/* 0x1  1 */
	0x2000,			/* 0x2  2 */
	0x1000,			/* 0x3  3 */
	0x0800,			/* 0x4  4 */
	0x0400,			/* 0x5  5 */
	0x0200,			/* 0x6  6 */
	0x0100,			/* 0x7  7 */
	0x0080,			/* 0x8  8 */
	0x0040,			/* 0x9  9 */
	0x0020,			/* 0xa 10 */
	0xdce0,			/* 0xb 11 */
	0x2800,			/* 0xc 12 */
	0x0820,			/* 0xd 13 */
	0x0440,			/* 0xe 14 */
	0x9000,			/* 0xf 15 */
};

static int pore_scand_read(pore_model_t p, _PoreAddress *addr, uint32_t *word)
{
	int rc;
	uint64_t data;

	if (addr->val & 0x0000800000000000ull) {
		uint64_t memAddress;

		memAddress = addr->val;
		pore_relocateAddress(p, &memAddress);
		rc = poreb_read(p->mem, memAddress, (uint8_t *)word,
				sizeof(*word), &p->err_code);

		if (p->dbg1.debug_regs_locked == 0) {
			p->dbg1.oci_master_rd_parity_err = 0;
			p->dbg1.last_ret_code_oci = p->err_code;
		}

		mem_printf(p, "  getMem:  addr=%016llx data=%016llx "
			   "err_code=%x\n", (long long)memAddress,
			   (long long)*word, p->err_code);

		if (rc != sizeof(*word))
			return rc;

	} else {
		uint32_t pibAddress = ((addr->memorySpace << 16) |
				       (addr->offset >> 3));

		/* always read 8 byte on the PIB */
		rc = poreb_read(p->pib, pibAddress, (uint8_t *)&data,
				sizeof(data), &p->err_code);

		if (p->dbg1.debug_regs_locked == 0) {
			p->dbg0.last_completed_address = pibAddress;
			p->dbg0.last_ret_code_prv = p->err_code;
		}

		mem_printf(p, "  getScom: addr=%016llx data=%016llx "
			   "err_code=%x\n", (long long)pibAddress,
			   (long long)data, p->err_code);

		if (rc != sizeof(data)) {
			return rc;
		}
		*word = ((addr->offset & 0x7) == 0) ?
			data >> 32 : data & 0xffffffff;
	}
	return PORE_SUCCESS;
}

static int pore_scand(pore_model_t p)
{
	int bits, rem, rc;
	PoreInlineDecode *dis = &p->dis;
	pore_scratch0_reg *scr0 = &p->scratch0;
	uint32_t scan_data = 0, crc32_data = 0;
	uint64_t write_data;
	_PoreAddress addr;
	PibAddress pib_addr;
	shift_eng_cmd_reg scan_sel;
	scan_type_select_reg scan_type_sel;

	pib_addr.val = 0;
	scan_sel.val = dis->scan_select;

	addr.val = p->status.pc;
	addr.offset += dis->scan_offset * 4;

	/**
	 * Setup scan region register to select correct chains,
	 * e.g. write scom 0x02030007 0x0100000800000000 (chiplet 2,
	 * non-vital region 3, type bndy)
	 */
	pib_addr.mc	    = scan_sel.bc;
	pib_addr.chiplet_id = scan_sel.chiplet_select;
	pib_addr.prv_port   = scan_sel.port;
	pib_addr.local_addr = SCAN_REGION_OFFSET;

	scan_type_sel.val = 0;
	scan_type_sel.region_select = scan_sel.region_select;
	scan_type_sel.type_sel_unary = bin_2_unary[scan_sel.type_sel_bin];
	write_data = scan_type_sel.val;

	rc = pore_pib_write(p, pib_addr.val, (uint8_t *)&write_data,
			    sizeof(write_data), &p->err_code);
	if (rc < 0)
		return rc;

	for (bits = 0, rem = dis->scan_length,
		     scr0->scratch0 = dis->scan_length / 32;
	     bits < dis->scan_length;
	     bits += 32, rem -= 32,
	     scr0->scratch0--) {

		int num_bits = rem > 32 ? 32 : rem;

		rc = pore_scand_read(p, &addr, &scan_data);
		if (rc < 0)
			return rc;

		/**
		 * Send PCB scan packets which have the following
		 * layout:
		 *   Address is 0x0<chiplet_id>0x0380<num_bits>
		 *   Data is the left aligned values to get scanned in
		 *   (up to 32 bit).
		 *
		 * The last scan packet should have the updateDR bit
		 * set in the address, i.e. 0x03A0 instead of 0x380.
		 *
		 * This will clear the scan region register if scan
		 * protection is active (default).  E.g. write scom
		 * 0x02038020 0xFFFFFFFF00000000 (scan 32 bit in
		 * chiplet 2, all '1')).
		 *
		 * cDR: See JTAG standard, capture data from scanlatch
		 * uDR:          "         update data to scanlatch
		 * Is used for PLL settings.
		 */

		if (scr0->scratch0 == dis->scan_length / 32) {
			/* Need to set cDR on 1st data access */
			pib_addr.local_addr =
				SCAN_DATA_OFFSET(dis->capture, 0, num_bits);

		} else if (scr0->scratch0 == 0) {
			/* Need to set uDR on last data access */
			pib_addr.local_addr =
				SCAN_DATA_OFFSET(0, dis->update, num_bits);
		} else {
			pib_addr.local_addr =
				SCAN_DATA_OFFSET(0, 0, num_bits);
		}

		write_data = (uint64_t)scan_data << 32;
		rc = pore_pib_write(p, pib_addr.val, (uint8_t *)&write_data,
				    sizeof(write_data), &p->err_code);
		if (rc < 0)
			return rc;

		addr.offset += 4;
	}
	rc = pore_scand_read(p, &addr, &crc32_data);
	if (rc < 0)
		return rc;
	p->scratch1 = crc32_data;

	return PORE_SUCCESS;
}

static int execute(pore_model_t p)
{
	int me = PORE_SUCCESS;
	int next_state = PORE_STATE_EXEC;
	int trapBreakpoint = 0;
	int addressBreakpoint = 0;
	PoreInlineDecode *dis;
	uint64_t write_data, read_data = 0;
	int64_t op1, op2;
	_PoreAddress next_pc;

	if (!p)
		return PORE_ERR_INVALID_PARAM;

	dis = &p->dis;
	next_pc.val = p->status.pc;
	p->branchTaken = 0;

	switch (dis->opcode) {

	case PORE_OPCODE_NOP:
		break;

	case PORE_OPCODE_TRAP:
		// PORE hardware trap leaves the machine in the
		// address breakpoint state.
		if (p->control.trap_enable) {
			trapBreakpoint = 1;
			next_state = PORE_STATE_ABR;
		}
		break;

	case PORE_OPCODE_HOOK:
		if (p->enableHookInstruction) {
			int _rc;

			p->forcedBranch = 0;
			p->forcedBranchMode = FORCED_BRANCH_HOOK_INSTRUCTION;
			_rc = pore_instrHook(p, p->status.pc, dis->imd24,
					     dis->imd64);
			p->forcedBranchMode = FORCED_BRANCH_DISALLOWED;
			if (_rc) {
				me = PORE_ERR_HOOK_FAILED;
				break;
			}
			if (p->forcedBranch) {
				next_pc.val = p->forcedPc;
				p->branchTaken = 1;
			}
		}
		break;

	case PORE_OPCODE_WAIT:
		if (p->dis.imd24 == 0) {
			// Invalidate fetch buffer for OCI access
			/// \bug Buffer is invalidated on reset
			p->oci_fetchBufferValid = 0;
			p->oci_fetchBufferCursor = 0;
			p->oci_fetchBuffer = 0;

			// This is the stop command. Raise the
			// pore_stopped signal
			p->control.start_stop = 1;

			//unlockRegisters();
			p->control.lock_exe_trig = 0;
		}
		pore_waitCallback(p, dis->imd24);
		break;

		/* Branch Instructions */
	case PORE_OPCODE_BRA:
		p->branchTaken = 1;
		setJmpTarget(dis->impco24, &next_pc);
		break;

	case PORE_OPCODE_BRAD:
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		p->branchTaken = 1;
		next_pc.val = __readReg(p, (pore_internal_reg_t)dis->tR);
		break;

	case PORE_OPCODE_BRAZ:
		if (dis->tR != PORE_SCRATCH0_ENC &&
		    dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		if (__readReg(p, (pore_internal_reg_t)dis->tR) == 0) {
			p->branchTaken = 1;
			setJmpTarget(dis->impco20, &next_pc);
		}
		break;

	case PORE_OPCODE_BRANZ:
		if (dis->tR != PORE_SCRATCH0_ENC &&
		    dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		if (__readReg(p, (pore_internal_reg_t)dis->tR) != 0) {
			p->branchTaken = 1;
			setJmpTarget(dis->impco20, &next_pc);
		}
		break;

	case PORE_OPCODE_BRAI:
		p->branchTaken = 1;
		next_pc.val = dis->impc48;
		break;

	case PORE_OPCODE_BSR:
		me = push(p, p->status.pc + 4, 0);
		if (me < 0) {
			break;
		}

		p->branchTaken = 1;
		setJmpTarget(dis->impco24 , &next_pc);
		break;

	case PORE_OPCODE_BSRD:
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		me = push(p, p->status.pc + 4, 0);
		if (me < 0)
			break;

		p->branchTaken = 1;
		next_pc.val = __readReg(p, (pore_internal_reg_t)dis->tR);
		break;

	case PORE_OPCODE_RET:
		me = pop(p, &next_pc);
		if (me < 0)
			break;

		p->branchTaken = 1;
		break;

	case PORE_OPCODE_CMPBRA:
		if (p->scratch1 == dis->imd64) {
			p->branchTaken = 1;
			setJmpTarget(dis->impco24, &next_pc);
		}
		break;

	case PORE_OPCODE_CMPNBRA:
		if (p->scratch1 != dis->imd64) {
			p->branchTaken = 1;
			setJmpTarget(dis->impco24, &next_pc);
		}
		break;

	case PORE_OPCODE_CMPBSR:
		if (p->scratch1 == dis->imd64) {
			me = push(p, p->status.pc + 12, 0);
			if (me < 0)
				break;

			p->branchTaken = 1;
			setJmpTarget(dis->impco24, &next_pc);
		}
		break;

	case PORE_OPCODE_LOOP:
		if (p->scratch0.scratch0 > 0) {
			p->scratch0.scratch0 = p->scratch0.scratch0 - 1;
			p->branchTaken = 1;
			setJmpTarget(dis->impco24, &next_pc);
		}
		break;

		/* ALU Instructions */
	case PORE_OPCODE_ANDI:
		if (dis->sR != PORE_SCRATCH1_ENC &&
		    dis->sR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		__writeReg(p, (pore_internal_reg_t)dis->tR,
			   __readReg(p, (pore_internal_reg_t)
				     dis->sR) & dis->imd64);
	    break;

	case PORE_OPCODE_ORI:
		if (dis->sR != PORE_SCRATCH1_ENC &&
		    dis->sR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		__writeReg(p, (pore_internal_reg_t)dis->tR,
			   __readReg(p, (pore_internal_reg_t)dis->sR) |
			   dis->imd64);
		break;

	case PORE_OPCODE_XORI:
		if (dis->sR != PORE_SCRATCH1_ENC &&
		    dis->sR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		__writeReg(p, (pore_internal_reg_t)dis->tR,
			   __readReg(p, (pore_internal_reg_t)dis->sR) ^
			   dis->imd64);
		break;

	case PORE_OPCODE_AND:
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		__writeReg(p, (pore_internal_reg_t)dis->tR,
			   p->scratch1 & p->scratch2);
		break;

	case PORE_OPCODE_OR:
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		__writeReg(p, (pore_internal_reg_t)dis->tR,
			   p->scratch1 | p->scratch2);
		break;

	case PORE_OPCODE_XOR:
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		__writeReg(p, (pore_internal_reg_t)dis->tR,
			   p->scratch1 ^ p->scratch2);
		break;

	case PORE_OPCODE_ADDI: {
		int64_t add_result;

		if (dis->tR == PORE_EXE_TRIGGER_ENC ||
		    dis->tR == PORE_ALU_IBUF_ID_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}

		op1 = __readReg(p, (pore_internal_reg_t)dis->tR);
		op2 = dis->imd16;
		add_result = op1 + op2;

		setAluFlags(p, op1, op2, add_result, dis->opcode);
		__writeReg(p, (pore_internal_reg_t)dis->tR, add_result);
		break;
	}
	case PORE_OPCODE_SUBI: {
		int64_t sub_result;

		if (dis->tR == PORE_EXE_TRIGGER_ENC ||
		    dis->tR == PORE_ALU_IBUF_ID_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}

		op1 = __readReg(p, (pore_internal_reg_t)dis->tR);
		op2 = dis->imd16;
		op2 = ~op2 + 1;
		sub_result = op1 + op2;

		setAluFlags(p, op1, op2, sub_result, dis->opcode);
		__writeReg(p, (pore_internal_reg_t)dis->tR, sub_result);
		break;
	}
	case PORE_OPCODE_ADD: {
		int64_t add_result;

		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}

		op1 = p->scratch1;
		op2 = p->scratch2;
		add_result = op1 + op2;

		setAluFlags(p, op1, op2, add_result, dis->opcode);
		__writeReg(p, (pore_internal_reg_t)dis->tR, add_result);
		break;
	}
	case PORE_OPCODE_SUB: {
		int64_t sub_result;

		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}

		op1 = p->scratch1;
		op2 = p->scratch2;
		op2 = ~op2 + 1;
		sub_result = op1 + op2;
		setAluFlags(p, op1, op2, sub_result, dis->opcode);
		__writeReg(p, (pore_internal_reg_t)dis->tR, sub_result);
		break;
	}
	case PORE_OPCODE_NEG: {
		int64_t neg_result;

		if (dis->sR != PORE_SCRATCH1_ENC &&
		    dis->sR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		if (dis->tR != PORE_SCRATCH1_ENC &&
		    dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}

		op1 = __readReg(p, (pore_internal_reg_t)dis->sR);
		neg_result = ~op1 + 1;
		__writeReg(p, (pore_internal_reg_t)dis->tR, neg_result);
		break;
	}
	case PORE_OPCODE_COPY:
		__writeReg(p, (pore_internal_reg_t)dis->tR,
			   __readReg(p, (pore_internal_reg_t)dis->sR));
		break;

	case PORE_OPCODE_ROL: {
		uint16_t rmask = 0;
		uint64_t result = 0;
		uint64_t src = 0;

		// Operand Check
		rmask = dis->imd16;
		if (rmask != 0x1 && rmask != 0x4 && rmask != 0x8
		    && rmask != 0x10 && rmask != 0x20 ) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;

		} else if (
			   dis->sR != PORE_SCRATCH1_ENC &&
			   dis->sR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;

		} else if (dis->tR != PORE_SCRATCH1_ENC &&
			   dis->tR != PORE_SCRATCH2_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;

		} else {
			src = __readReg(p, (pore_internal_reg_t)dis->sR);
			result = ( src << rmask ) |
				(((~(0xFFFFFFFFFFFFFFFFull >> rmask)) & src )
				 >> (64 - rmask));
		}

		__writeReg(p, (pore_internal_reg_t)dis->tR, result);
		break;
	}
		/* Load/Store Instructions */
	case PORE_OPCODE_LOAD20: {
		if (dis->tR == PORE_EXE_TRIGGER_ENC ||
		    dis->tR == PORE_ALU_IBUF_ID_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}
		/**
		 * ImD20 will be signed extended to 64b (on MSB side)
		 * and then truncated to the width of <tR>.
		 */
		__writeReg(p, (pore_internal_reg_t)dis->tR, dis->imd20);
		break;
	}
	case PORE_OPCODE_LOAD64:
		if (dis->tR == PORE_PRV_BASE_ADDR0_ENC ||
		    dis->tR == PORE_PRV_BASE_ADDR1_ENC ||
		    dis->tR == PORE_EXE_TRIGGER_ENC ||
		    dis->tR == PORE_ALU_IBUF_ID_ENC) {
			BUG();
			if (p->dbg1.debug_regs_locked == 0)
				p->dbg1.invalid_instruction_operand = 1;
			me = pore_handleErrEvent(p, 2,
						 PORE_ERR_INVALID_OPERAND);
			break;
		}

		__writeReg(p, (pore_internal_reg_t)dis->tR, dis->imd64);
		break;

	case PORE_OPCODE_SCR1RD: {
		me = inExeInterfaceRead(p, &read_data);
		if (me < 0)
			break;
		p->scratch1 = read_data;
		break;
	}
	case PORE_OPCODE_SCR2RD: {
		me  = inExeInterfaceRead(p, &read_data);
		if (me < 0)
			break;
		p->scratch2 = read_data;
		break;
	}
	case PORE_OPCODE_SCR1RDA: {
		// Read DATA from OCI/PRV Address Space using effective addr
		me = inExeInterfaceRead(p, &read_data);
		if (me < 0)
			break;
		// Apply imd64 AND mask
		read_data &= dis->imd64;
		p->scratch1 = read_data;
		break;
	}
	case PORE_OPCODE_SCR2RDA: {
		// Read DATA from OCI/PRV Address Space using effective addr
		me = inExeInterfaceRead(p, &read_data);
		if (me < 0)
			break;
		// Apply imd64 AND mask
		read_data &= dis->imd64;
		p->scratch2 = read_data;
		break;
	}
	case PORE_OPCODE_WRI: {
		write_data = dis->imd64;
		// Write DATA to OCI/PRV Address Space using effective addr
		me = inExeInterfaceWrite(p, write_data);
		if (me < 0)
			break;
		break;
	}
	case PORE_OPCODE_BS: {
		// Read OCI/PRV space from effective address to read_data
		me = inExeInterfaceRead(p, &read_data);
		if (me < 0)
			break;
		// Apply OR mask to read_data
		read_data |= dis->imd64;
		// update scratch register
		p->scratch1 = read_data;
		// Write the data back to effective address in OCI/PRV
		me = inExeInterfaceWrite(p, read_data);
		if (me < 0)
			break;
		break;
	}
	case PORE_OPCODE_BC: {
		// Read OCI/PRV space from effective address to read_data
		me = inExeInterfaceRead(p, &read_data);
		if (me < 0)
			break;
		// Apply Inverted AND mask to read_data
		read_data &= ~(dis->imd64);
		// Update scratch register
		p->scratch1 = read_data;
		// Write the data back to effective address in OCI/PRV
		me = inExeInterfaceWrite(p, read_data);
		if (me < 0)
			break;
		break;
	}
	case PORE_OPCODE_SCR1WR: {
		write_data = p->scratch1;
		// Write DATA to OCI/PRV Address Space using effective addr
		me = inExeInterfaceWrite(p, write_data);
		if (me < 0)
			break;
		break;
	}
	case PORE_OPCODE_SCR2WR: {
		write_data = p->scratch2;
		// Write DATA to OCI/PRV Address Space using effective addr
		me = inExeInterfaceWrite(p, write_data);
		if (me < 0)
			break;
		break;
	}
	case PORE_OPCODE_SCAND:
		me = pore_scand(p);
		if (me < 0) {
			me = pore_handleErrEvent(p, 2, me);
			break;
		}
		break;

	default:
		/* Disabled printout as requested in HW218122 */
		/* eprintf(p, "err: Invalid Instruction Encoding: "
			"     %08x %08x %08x\n",
			(unsigned int)p->ibuf_01.ibuf0,
			(unsigned int)p->ibuf_01.ibuf0,
			(unsigned int)p->ibuf_2.ibuf2); */

		if (p->dbg1.debug_regs_locked == 0)
			p->dbg1.invalid_instr_code = 1;
		me = pore_handleErrEvent(p, 2, PORE_ERR_INVALID_OPCODE);
		break;
	}

	// Check for address, trap, magic breakpoints and single-step.
	// Note that we do the dumps

	addressBreakpoint = (p->status.pc == p->control.pc_brk_pt);

	if (addressBreakpoint) {
		pore_dump(p);
		next_state = PORE_STATE_ABR;
		p->broken = 1;
		dprintf(p, "PORE Address Breakpoint @ 0x%012llx\n",
			(long long)p->status.pc);
	} else if (trapBreakpoint) {
		pore_dump(p);
		next_state = PORE_STATE_ABR;
		p->broken = 1;
		dprintf(p, "PORE Trap Breakpoint @ 0x%012llx\n",
			(long long)p->status.pc);
	}

	// Branches have already updated the PC so the assignment to
	// the PC is done here. Otherwise we increment the PC for the
	// next step unless we're broken.
	//
	// In case of me < 0 the pore_handeErrEvent() function has set
	// a new PC by jumping into the appropriate Error Vector. In
	// this case we do not update the current PC instead it was
	// pushed onto the stack. After the error handler has tidied
	// up, it can jump back to the failing instruction.

	if (me >= 0) {
		if (p->branchTaken) {
			p->status.pc = next_pc.val;
		} else if (!p->broken) {
			incrPc(p);
		}
	}

	/**
	 * The vPORE has been setup to handle this error via the
	 * exception handler code. Therefore ignore this failure and
	 * continue.
	 */
	if (me == PORE_ERR_HANDLED_BY_CODE) {
		me = PORE_ERROR_IGNORED;
	}

	// Step mode. don't update state and don't schedule next step
	// Condition can occur when we are hitting an error during
	// instruction execution, e.g. a pib_read failed.

	if (p->control.start_stop == 1) {
		dprintf(p, "PORE was stopped during execution!\n");
		p->status.cur_state = PORE_STATE_WAIT;

	} else if (p->reset.fn_reset) {
		dprintf(p, "PORE is being held in reset!\n");
		me = PORE_ERR_IN_RESET;

	} else{
		p->status.cur_state = next_state;
	}

	return me;
}

/// If the instruction was broken, finish it.
///
/// If the PORE is an a 'broken' state, then we first need to update
/// the PC by re-decoding the current instruction.  Taken branches
/// have already updated the PC.
///
/// The situation occurs if we have hit a breakpoint. In this case the
/// PC has still the value of the breakpoint instruction, but needs to
/// be updated when the user writes 1 to control.continue_step.

static int finishBrokenInstruction(pore_model_t p)
{
	if (!p)
		return PORE_ERR_INVALID_PARAM;

	if (p->broken && !p->branchTaken) {
		decode(p);
		incrPc(p);
	}

	p->branchTaken = 0;
	p->broken = 0;
	return PORE_SUCCESS;
}

int pore_step(pore_model_t p)
{
	int rc = PORE_SUCCESS;

	if (!p)
		return PORE_ERR_INVALID_PARAM;

	dprintf(p, "(0) ensure we are in correct state to do a step ...\n");
	if (p->reset.fn_reset == 1) {
		dprintf(p, "  no: engine is in reset\n");
		return PORE_IN_RESET;
	}
	if (p->control.start_stop == 1) {
		dprintf(p, "  no: engine is stopped\n");
		return PORE_STOPPED;
	}
	if (p->status.cur_state == PORE_STATE_ABR) {
		dprintf(p, "  no: engine has hit a breakpoint\n");
		return PORE_BREAKPOINT_HIT;
	}

	p->branchTaken = 0;	/* reset internal state */
	p->broken = 0;

	dprintf(p, "(1) fetch @ %016llx ...\n", (long long)p->status.pc);
	rc = fetch(p);
	if (rc < 0) {
		eprintf(p, "%s: err: fetch rc=%d\n", __func__, rc);
		return rc;
	}

	dprintf(p, "(2) decode ...\n");
	rc = decode(p);
	if (rc < 0) {
		eprintf(p, "%s: err: decode rc=%d\n", __func__, rc);
		return rc;
	}

	dprintf(p, "(3) execute ...\n");
	rc = execute(p);
	if (rc < 0) {
		eprintf(p, "%s: err: execute rc=%d\n", __func__, rc);
		return rc;
	}

	/* Extension for interruptible operation of SLW instance */
	if (p->control.interrupt_sequencer_enabled &&
	    p->pore_interrupt_request) {

		if (p->control.pore_interruptible) {
			__pore_flush_reset(p);
			pore_exe_trigger_reg_write(p, p->exe_trigger.val,
						   PORE_BITS_0_63);
		} else {
			if (p->dbg0.interrupt_counter != 0xff)
				p->dbg0.interrupt_counter++;
		}
	}

	return rc;
}

void pore_dump(pore_model_t p)
{
	_PoreAddress a0, a1;
	_PoreAddress sp0, sp1, sp2;
	int sp;
	uint32_t p0, p1;

	sp0.val = p->pc_stack[0].pc_stack;
	sp1.val = p->pc_stack[1].pc_stack;
	sp2.val = p->pc_stack[2].pc_stack;

	a0.val = __readReg(p, PORE_OCI_MEMORY_BASE_ADDR0_ENC);
	a1.val = __readReg(p, PORE_OCI_MEMORY_BASE_ADDR1_ENC);
	p0 = __readReg(p, PORE_PRV_BASE_ADDR0_ENC);
	p1 = __readReg(p, PORE_PRV_BASE_ADDR1_ENC);

	aprintf("-------------------------------------"
		"-------------------------------------\n"
		"%s : PORE Id %d.\n"
		"-------------------------------------"
		"-------------------------------------\n"
		"  IBUF: %08llx %08x.%08x.%08x\n"
		"-------------------------------------"
		"-------------------------------------\n"
		"  D0: %016llx   D1: %016llx\n"
		"  A0: %04x:%08x      A1: %04x:%08x\n"
		"  P0: %02x P1: %02x          CTR: %06x\n"
		"-------------------------------------"
		"-------------------------------------\n",
		__func__,
		(uint32_t)(p->id_flags.ibuf_id),
		(long long)p->status.pc,
		p->ibuf_01.ibuf0,
		p->ibuf_01.ibuf1,
		p->ibuf_2.ibuf2,
		(long long)p->scratch1,
		(long long)p->scratch2,
		(unsigned int)a0.memorySpace, (unsigned int)a0.offset,
		(unsigned int)a1.memorySpace, (unsigned int)a1.offset,
		p0, p1,	(uint32_t)p->scratch0.scratch0);

	sp = p->status.stack_pointer;
	/* pore_status_reg_print(&p->status); */
	/* pore_control_reg_print(&p->control); */

	if (sp == 0) {
		aprintf("The stack is empty\n");
	} else {
		aprintf("Stack Trace\n"
			"  Level 0 : %04x:%08x\n",
			(unsigned int)sp0.memorySpace,
			(unsigned int)sp0.offset);
		if (sp > 0x1) {
			aprintf("  Level 1 : %04x:%08x\n",
				(unsigned int)sp1.memorySpace,
				(unsigned int)sp1.offset);
		}
		if (sp > 0x2) {
			aprintf("  Level 2 : %04x:%08x\n",
				(unsigned int)sp2.memorySpace,
				(unsigned int)sp2.offset);
		}
	}

	aprintf("-------------------------------------"
		"-------------------------------------\n"
		"Last pervasive access @ %08x returned error code %d\n"
		"-------------------------------------"
		"-------------------------------------\n",
		(uint32_t)p->dbg0.last_completed_address,
		(int)p->dbg0.last_ret_code_prv);

	aprintf("  PORe Registers\n"
		"    STATUS:       %016llx CONTROL:	 %016llx\n"
		"    RESET:        %016llx ERR_MASK:	 %016llx\n"
		"    PVR_BASE0/P0: %016llx PVR_BASE1/P1: %016llx\n"
		"    OCI_BASE0/A0: %016llx OCI_BASE1/A1: %016llx\n"
		"    TBL_BASE:     %016llx EXE_TRIGGER:	 %016llx\n"
		"    SCR0/CTR:     %016llx SCR1/D0:	 %016llx\n"
		"    SCR2/D1:      %016llx IBUF012: %08llx.%08llx.%08llx\n"
		"    DBG0:         %016llx DBG1:         %016llx\n"
		"    PC_STACK0:    %016llx PC_STACK1:    %016llx\n"
		"    PC_STACK2:    %016llx ID_FLAGS:     %016llx\n"
		"    DATA0:        %016llx MEM_RELOC:	 %016llx\n"
		"    I2C_E0:       %016llx I2C_E1:	 %016llx\n"
		"    I2C_E2:       %016llx PC:		 %016llx\n"
		"  Internal State\n"
		"    branchTaken/broken:       %lld/%lld\n"
		"    pore_interrupt_request:   %lld\n"
		"    oci_fetchBufValid/Cursor: %lld/%lld\n"
		"    oci_fetchBuf:             %016llx\n"
		"-------------------------------------"
		"-------------------------------------\n",
		(long long)p->status.val,	(long long)p->control.val,
		(long long)p->reset.val,	(long long)p->error_mask.val,
		(long long)p->prv_base[0].val,	(long long)p->prv_base[1].val,
		(long long)p->oci_base[0].val,	(long long)p->oci_base[1].val,
		(long long)p->table_base_addr.val,
		(long long)p->exe_trigger.val,
		(long long)p->scratch0.val,	(long long)p->scratch1,
		(long long)p->scratch2,		(long long)p->ibuf_01.ibuf0,
		(long long)p->ibuf_01.ibuf1,	(long long)p->ibuf_2.ibuf2,
		(long long)p->dbg0.val,		(long long)p->dbg1.val,
		(long long)p->pc_stack[0].val,	(long long)p->pc_stack[1].val,
		(long long)p->pc_stack[2].val,	(long long)p->id_flags.val,
		(long long)p->data0,		(long long)p->memory_reloc.val,
		(long long)p->i2c_e_param[0].val,
		(long long)p->i2c_e_param[1].val,
		(long long)p->i2c_e_param[2].val,
		(long long)p->status.pc,
		(long long)p->branchTaken, (long long)p->broken,
		(long long)p->pore_interrupt_request,
		(long long)p->oci_fetchBufferValid,
		(long long)p->oci_fetchBufferCursor,
		(long long)p->oci_fetchBuffer);
}

/* Model Creation and Reset **************************************************/

void pore_model_destroy(pore_model_t p)
{
	poreb_destroy(p->pib);
	poreb_destroy(p->mem);
	free(p);
}

int pore_registerHooks (pore_model_t p,
			instrHook_f  instrHook,
			readHook_f   readHook,
			writeHook_f  writeHook,
			fetchHook_f  fetchHook,
			decodeHook_f decodeHook)
{
	p->instrHook = instrHook;
	p->readHook = readHook;
	p->writeHook = writeHook;
	p->fetchHook = fetchHook;
	p->decodeHook = decodeHook;
	return 0;
}

int pore_registerCallbacks(pore_model_t p,
			   waitCallback_f waitCallback,
			   errorCallback_f errorCallback,
			   errorCallback_f fatalErrorCallback)
{
	p->waitCallback = waitCallback;
	p->errorCallback = errorCallback;
	p->fatalErrorCallback = fatalErrorCallback;
	return 0;
}

void pore_setpriv(pore_model_t p, void *priv)
{
	p->priv = priv;
}

void *pore_getpriv(pore_model_t p)
{
	return p->priv;
}

/* recursive function to setup the pore pointer in all bus attachements */
static void poreb_set_pore(struct pore_bus *b, pore_model_t p)
{
	unsigned int i;

	if (b == NULL)
		return;
	b->pore = p;
	for (i = 0; i < PORE_MAX_BUS; i++)
		poreb_set_pore(b->slaves[i], p);
}

int pore_attach_mem(pore_model_t p, struct pore_bus *b)
{
	p->mem = b;
	poreb_set_pore(b, p);
	return 0;
}

int pore_attach_pib(pore_model_t p, struct pore_bus *b)
{
	p->pib = b;
	poreb_set_pore(b, p);
	return 0;
}

int pore_extractState(pore_model_t p, struct pore_state *s)
{
	memcpy(s, p, sizeof(*s));
	return 0;
}

int pore_installState(pore_model_t p, const struct pore_state *s)
{
	memcpy(p, s, sizeof(*s));
	return 0;
}

void pore_set_enableHookInstr(pore_model_t p, int enabled)
{
	p->enableHookInstruction = enabled;
}

int pore_get_enableHookInstr(pore_model_t p)
{
	return p->enableHookInstruction;
}

void pore_set_enableAddressHooks(pore_model_t p, int enabled)
{
	p->enableAddressHooks = enabled;
}

int pore_get_enableAddressHooks(pore_model_t p)
{
	return p->enableAddressHooks;
}

int
pore_forceBranch(pore_model_t p, uint64_t addr)
{
	switch (p->forcedBranchMode) {

	case FORCED_BRANCH_DISALLOWED:
		return PORE_ERR_ILLEGAL_FORCED_BRANCH;

	case FORCED_BRANCH_FETCH_HOOK:
	case FORCED_BRANCH_HOOK_INSTRUCTION:
		p->forcedPc = addr;
		p->forcedBranch = 1;
		break;
	}
	return PORE_SUCCESS;
}

int pore_stop(pore_model_t p)
{
	uint64_t control;
	control = pore_readReg(p, PORE_R_CONTROL, PORE_BITS_0_63);
	/* set start_stop bit[0] */
	pore_writeReg(p, PORE_R_CONTROL, control | BE64_BIT(0),
		      PORE_BITS_0_63);
	return PORE_SUCCESS;
}

int pore_start(pore_model_t p)
{
	uint64_t control;
	control = pore_readReg(p, PORE_R_CONTROL, PORE_BITS_0_63);
	/* clear start_stop bit[0] */
	pore_writeReg(p, PORE_R_CONTROL, control & ~BE64_BIT(0),
		      PORE_BITS_0_63);
	return PORE_SUCCESS;
}

int pore_setPc(pore_model_t p, uint64_t pc)
{
	pore_stop(p);
	pore_writeReg(p, PORE_R_CONTROL, BE64_BIT(3) |
		      (pc & BE64_MASK(16, 63)), PORE_BITS_0_63);
	return PORE_SUCCESS;
}

int pore_setBreakpoint(pore_model_t p, uint64_t bp)
{
	uint64_t control;

	control = pore_readReg(p, PORE_R_CONTROL, PORE_BITS_0_63);
	control &= ~BE64_MASK(16, 63);
	control |= (bp & BE64_MASK(16, 63));
	pore_writeReg(p, PORE_R_CONTROL, control, PORE_BITS_0_63);
	return PORE_SUCCESS;
}

int pore_enableTrap(pore_model_t p, int enable)
{
    uint64_t control;

    control = pore_readReg(p, PORE_R_CONTROL, PORE_BITS_0_63);
    if (enable) {
	    control |= BE64_BIT(11);
    } else {
	    control &= ~BE64_BIT(11);
    }
    pore_writeReg(p, PORE_R_CONTROL, control, PORE_BITS_0_63);
    return PORE_SUCCESS;
}

static int __fake_read(struct pore_bus *b, uint64_t addr,
		       uint8_t *buf, unsigned int len,
		       int *err_code __attribute__((unused)))
{
	unsigned int i;

	memset(buf, 0xff, len);
	dprintf(b->pore, "  %-12s: %s(%p, 0x%08llx, ...)\n	 read:	",
		b->name, __func__, b, (long long)addr);

	for (i = 0; i < len; i++)
		dprintf(b->pore, "%02x ", buf[i]);
	dprintf(b->pore, "\n");

	return len;
}

static int __fake_write(struct pore_bus *b, uint64_t addr,
			const uint8_t *buf, unsigned int len,
			int *err_code __attribute__((unused)))
{
	unsigned int i;

	dprintf(b->pore, "  %-12s: %s(%p, 0x%08llx, ...)\n	 write:	 ",
		b->name, __func__, b, (long long)addr);
	for (i = 0; i < len; i++)
		dprintf(b->pore, "%02x ", buf[i]);
	dprintf(b->pore, "\n");

	return len;
}

static int __fake_fetch(struct pore_bus *b, uint64_t pc,
			uint64_t *ibuf_01 __attribute__((unused)),
			uint64_t *ibuf_2  __attribute__((unused)),
			unsigned int *size,
			int *err_code __attribute__((unused)))
{
	dprintf(b->pore, "  %-12s: %s(%p, 0x%08llx, ...)\n	 fetch: ",
		b->name, __func__, b, (long long)pc);

	*size = 4;
	return *size;
}

static int __fake_reset(struct pore_bus *b)
{
	dprintf(b->pore, "  %s: %s(%p)\n", b->name, __func__, b);
	return 0;
}

/**
 * @brief Here we are setting the engine type and those registers
 * which are only setup on engine creation. Also model internal states
 * are reset to their start values.
 */
pore_model_t pore_model_create(const char *name)
{
	pore_model_t p;

	p = (pore_model_t)malloc(sizeof(*p));
	if (!p)
		return NULL;
	memset(p, 0, sizeof(*p));


	/* Some registers must only be set at model creation time */
	/* Setup depends on model type ------------------------------------- */
	p->name = name;

	/* ERROR_MASK ... only at 1st init */
	/* page 74: IBUF Err Mask, not altered during PORE reset. */
	p->error_mask.val = 0x00BFF00000000000ull;

	/* I2C_PARAM0/1/2 ... only at 1st init */
	p->i2c_e_param[0].val = 0x0;
	p->i2c_e_param[1].val = 0x0;
	p->i2c_e_param[2].val = 0x0;

	if	  (strcmp(p->name, "SBE")  == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_SBE;

		/* I2C_PARAM0/1/2 only at 1st init */
		p->i2c_e_param[0].i2c_engine_speed = 0x0f;

	} else if (strcmp(p->name, "SLW")  == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_SLW;
	} else if (strcmp(p->name, "GPE0") == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_GPE0;
	} else if (strcmp(p->name, "GPE1") == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_GPE1;
	}

	/* Setup register default values */
	pore_flush_reset(p);

	p->enableHookInstruction = 0;
	p->enableAddressHooks = 0;
	p->trace_flags = PORE_TRACE_ERR;
	return p;
}

/**
 * @brief The interruptible PORe implementation does not reset all
 * registers to their default state. Therefore this function only
 * resets those, which must be reset in that specific case.
 */
static int __pore_flush_reset(pore_model_t p)
{
	/* --------------- always ------------------------------------------ */

	/* STATUS */
	p->status.val = 0;
	p->status.cur_state = PORE_STATE_WAIT;
	p->status.stack_pointer = 0x1; /* HW218121 */
	p->status.pc = 0;

	/* OCI/MEM Route */
	p->prv_base[0].val = 0;
	p->prv_base[1].val = 0;
	p->oci_base[0].val = 0;
	p->oci_base[1].val = 0;

	/* SCR0, SRC1, IBUF01, IBUF2 */
	p->scratch0.val = 0;
	p->scratch1 = 0;
	p->scratch2 = 0;
	p->ibuf_01.val = 0;
	p->ibuf_2.val = 0;

	/* ID_FLAGS, DBG0, DBG1, PC_STACK0/1/2, DATA0 */
	p->id_flags.val = p->id_flags.ibuf_id; /* keep ibuf_id */
	p->dbg0.val = 0;
	p->dbg1.val = 0;
	p->pc_stack[0].val = 0; /* clears one bits on a write */
	p->pc_stack[1].val = 0;
	p->pc_stack[2].val = 0;
	p->data0 = 0;

	/* Internal model state */
	p->err_code = 0;
	p->branchTaken = 0;
	p->broken = 0;
	p->singleStep = 0;
	p->forcedBranchMode = FORCED_BRANCH_DISALLOWED;
	p->forcedPc = 0;

	/* Externally attached busses */
	poreb_reset(p->pib);	/* reset bus models, e.g. clear buffers */
	poreb_reset(p->mem);

	return 0;
}

/**
 * @brief This is the regular PORe reset case. Some registers depend
 * on the type of the engine, other don't. Note that there are even
 * registers which are not reset here, but only in case of engine
 * instance creation. See specifiction.
 */
int pore_flush_reset(pore_model_t p)
{
	dprintf(p, "%s: %s\n", __func__, p->name);

	/* --------------- exclude those regs for interruptible PORE case -- */
	/* EXE_TRIGGER */
	p->exe_trigger.val = 0;

	/* CONTROL */
	p->control.val = 0;
	p->control.start_stop = 1;
	p->control.lock_exe_trig = 0;
	p->control.check_parity = 0;
	p->control.prv_parity = 0;
	p->control.pc_brk_pt = 0xffffffffffffull;

	/* TABLE_BASE */
	p->table_base_addr.val = 0;

	/* ERROR_MASK ... only at 1st init */
	/* page 74: IBUF Err Mask, not altered during functional PORE reset. */

	/* MEMORY_RELOC */
	p->memory_reloc.val = 0;

	/* I2C_PARAM0/1/2 ... only at 1st init, see pore_model_create() */

	/* Setup depends on model type ------------------------------------- */
	if	  (strcmp(p->name, "SBE")  == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_SBE;

		/* CONTROL */
		p->control.interrupt_sequencer_enabled = 0;
		p->control.pore_interruptible = 0;

		/* The 0x00040000 in the SBE address space translates
		 * to the 0x00008000 (>>3) on the PIB bus.
		 */
		/* TABLE_BASE */
		p->table_base_addr.memory_space = 0x00001; /* SBE */
		p->table_base_addr.table_base_address = 0x00040028; /* SBE */

	} else {
		/* TABLE_BASE */
		p->table_base_addr.memory_space = 0x0; /* SLW/GPE */
		p->table_base_addr.table_base_address = 0x0; /* SLW/GPE */
	}

	if (strcmp(p->name, "SLW")  == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_SLW;

		/* CONTROL */
		p->control.interrupt_sequencer_enabled = 1; /* SLW */
		p->control.pore_interruptible = 1; /* SLW */

	} else if (strcmp(p->name, "GPE0") == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_GPE0;

	} else if (strcmp(p->name, "GPE1") == 0) {
		p->id_flags.ibuf_id = PORE_IBUF_ID_GPE1;
	}

	__pore_flush_reset(p);
	return 0;
}

pore_model_t
pore_sbe_create(pore_bus_t pib)
{
	pore_model_t p;
	pore_bus_t fi2cm[3], pore2fi2cm;

	p = pore_model_create("SBE");
	if (!p)
		return NULL;

	/* setup reference for the case it is not yet done. */
	if (pib)
		pib->pore = p;

	/* underlying busses which finally implement functionality */
	if (!pib)
		pib = poreb_create("PIB", 0, __fake_read, __fake_write,
				   __fake_fetch, __fake_reset);

	fi2cm[0] = poreb_create_fi2cm(p, "FI2CM0", pib, &p->i2c_e_param[0]);
	fi2cm[1] = poreb_create_fi2cm(p, "FI2CM1", pib, &p->i2c_e_param[1]);
	fi2cm[2] = poreb_create_fi2cm(p, "FI2CM2", pib, &p->i2c_e_param[2]);

	/* view of PORe engine which goes through remappings
	   before the underlying busses are accessed */

	/* SBE: 3 FI2C masters are servicing this memory range */
	pore2fi2cm = poreb_create_pore2fi2c(p, "PORE2FI2C",
					    fi2cm[0], fi2cm[1], fi2cm[2]);
	if (!pore2fi2cm)
		return NULL;

	pore_attach_mem(p, pore2fi2cm);
	pore_attach_pib(p, pib);

	return p;
}

static pore_model_t
__slw_gpe_create(const char *name, pore_bus_t pib, pore_bus_t oci)
{
	pore_model_t p;
	struct pore_bus *pore2oci_b;

	p = pore_model_create(name);
	if (!p)
		return NULL;

	/* setup reference for the case it is not yet done. */
	if (pib)
		pib->pore = p;
	if (oci)
		oci->pore = p;

	/* underlying busses which finally implement functionality */
	if (!pib)
		pib = poreb_create("PIB", 0, __fake_read, __fake_write,
				   __fake_fetch, __fake_reset);

	if (!oci)
		oci = poreb_create("OCI", 0, __fake_read, __fake_write,
				   __fake_fetch, __fake_reset);

	/* view of PORe engine which goes through remappings
	   before the underlying busses are accessed */

	/* SLW/GPE0/GPE1: OCI is servicing this memory range */
	pore2oci_b = poreb_create_pore2oci(p, "PORE2OCI", oci);
	if (!pore2oci_b)
		return NULL;

	pore_attach_mem(p, pore2oci_b);
	pore_attach_pib(p, pib);
	return p;
}

pore_model_t
pore_slw_create(pore_bus_t pib, pore_bus_t oci)
{
	return __slw_gpe_create("SLW", pib, oci);
}

pore_model_t
pore_gpe0_create(pore_bus_t pib, pore_bus_t oci)
{
	return __slw_gpe_create("GPE0", pib, oci);
}

pore_model_t
pore_gpe1_create(pore_bus_t pib, pore_bus_t oci)
{
	return __slw_gpe_create("GPE1", pib, oci);
}
