/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/wrapper/vsbe.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: vsbe.C,v 1.17 2013/11/27 17:24:37 thi Exp $
/******************************************************************************
 *
 * \file vsbe.C
 * \brief The interface between the vsbe::PoreModel and the Pmx::Pore
 *
 *****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "vsbe.H"
#include "pore_model.h"
#include "pore_wrap.h"

using namespace vsbe;

int vsbe::vsbeHookReadCallBack(pore_model_t p, uint64_t i_address)
{
	void *i_vsbe = pore_getpriv(p);
	return ((Vsbe*)i_vsbe)->hookRead( PoreAddress(i_address) );
}

int vsbe::vsbeHookWriteCallBack(pore_model_t p, uint64_t i_address)
{
	void *i_vsbe = pore_getpriv(p);
	return ((Vsbe*)i_vsbe)->hookWrite( PoreAddress(i_address) );
}

int vsbe::vsbeHookFetchCallBack(pore_model_t p, uint64_t i_address)
{
	void *i_vsbe = pore_getpriv(p);
	return ((Vsbe*)i_vsbe)->hookFetch( PoreAddress(i_address) );
}

void vsbe::fatalErrorIntrCallBack(pore_model_t p)
{
	void *i_vsbe = pore_getpriv(p);
	((Vsbe*)i_vsbe)->fatalErrorIntr();
}

void vsbe::errorIntrCallBack(pore_model_t p)
{
	void *i_vsbe = pore_getpriv(p);
	((Vsbe*)i_vsbe)->errorIntr();
}

void vsbe::waitIntrCallBack(pore_model_t p, uint32_t delay)
{
	void *i_vsbe = pore_getpriv(p);
	/** delay == 0 means engine is halted on a WAIT instruction */
	((Vsbe*)i_vsbe)->wait(delay);
}

int vsbe::vsbeHookInstructionCallBack(pore_model_t p, uint64_t i_address,
				      uint32_t i_hook, uint64_t i_parameter)
{
	void* i_vsbe = pore_getpriv(p);
	return ((Vsbe*)i_vsbe)->hookInstruction( PoreAddress(i_address),
						 i_hook, i_parameter );
}

////// OCI and PIB Transactions //////////////////////////////////////////////

int vsbe::vsbePibReadCallBack(pore_bus_t b, uint64_t addr, uint8_t *buf,
			      unsigned int size, int *err_code)
{
	Vsbe *vsbe = *(Vsbe **)poreb_get_priv(b);
	return vsbe->pibReadCallBack(b, addr, buf, size, err_code);
}

int
Vsbe::pibReadCallBack(pore_bus_t b, uint64_t addr, uint8_t *buf,
		      unsigned int size, int *err_code)
{
	PibTransaction pibTransaction;

	pibTransaction.iv_address = addr;
	pibTransaction.iv_offset  = 0;
	pibTransaction.iv_data    = 0;
	pibTransaction.iv_mode    = vsbe::ACCESS_MODE_READ;

	pibMaster(pibTransaction);
	*err_code = pibTransaction.iv_pcbReturnCode;

	if (pibTransaction.iv_pcbReturnCode) {
		size = PORE_ERR_READ;
	}

	*((uint64_t *)buf) = (*((uint64_t *)(void *)&pibTransaction.iv_data));
	return size;
}


int vsbe::vsbePibWriteCallBack(pore_bus_t b, uint64_t addr,
			       const uint8_t *buf,
			       unsigned int size,
			       int *err_code)
{
	Vsbe *vsbe = *(Vsbe **)poreb_get_priv(b);
	return vsbe->pibWriteCallBack(b, addr, buf, size, err_code);
}


int
Vsbe::pibWriteCallBack(pore_bus_t b, uint64_t addr, const uint8_t *buf,
		       unsigned int size, int *err_code)
{
	PibTransaction pibTransaction;

	pibTransaction.iv_address = addr;
	pibTransaction.iv_offset  = 0;
	pibTransaction.iv_mode    = vsbe::ACCESS_MODE_WRITE;
	*(uint64_t *)(void *)&pibTransaction.iv_data = (*((uint64_t *)buf));

	pibMaster(pibTransaction);
	*err_code = pibTransaction.iv_pcbReturnCode;

	if (pibTransaction.iv_pcbReturnCode) {
		size = PORE_ERR_WRITE;
	}
	return size;
}

int vsbe::vsbeOciReadCallBack(pore_bus_t b, uint64_t addr, uint8_t *buf,
			      unsigned int size, int *err_code)
{
	Vsbe *vsbe = *(Vsbe **)poreb_get_priv(b);
	return vsbe->ociReadCallBack(b, addr, buf, size, err_code);
}

int
Vsbe::ociReadCallBack(pore_bus_t b, uint64_t addr, uint8_t *buf,
		      unsigned int size, int *err_code)
{
	OciTransaction ociTransaction;

	ociTransaction.iv_address = addr;
	ociTransaction.iv_offset  = 0;
	ociTransaction.iv_data    = 0;
	ociTransaction.iv_mode    = vsbe::ACCESS_MODE_READ;

	ociMaster(ociTransaction);
	*err_code = ociTransaction.iv_ociReturnCode;

	if (ociTransaction.iv_ociReturnCode) {
		size = PORE_ERR_READ;
	}

	*((uint64_t *)buf) = (*((uint64_t *)(void *)&ociTransaction.iv_data));
	return size;
}

int vsbe::vsbeOciWriteCallBack(pore_bus_t b, uint64_t addr,
			       const uint8_t *buf, unsigned int size,
			       int *err_code)
{
	Vsbe *vsbe = *(Vsbe **)poreb_get_priv(b);
	return vsbe->ociWriteCallBack(b, addr, buf, size, err_code);
}


int
Vsbe::ociWriteCallBack(pore_bus_t b, uint64_t addr, const uint8_t *buf,
		       unsigned int size, int *err_code)
{
	OciTransaction ociTransaction;

	ociTransaction.iv_address = addr;
	ociTransaction.iv_offset  = 0;
	ociTransaction.iv_mode    = vsbe::ACCESS_MODE_WRITE;
	*(uint64_t *)(void *)&ociTransaction.iv_data = (*((uint64_t *)buf));

	ociMaster(ociTransaction);
	*err_code = ociTransaction.iv_ociReturnCode;

	if (ociTransaction.iv_ociReturnCode) {
		size = PORE_ERR_WRITE;
	}
	return size;
}

///////////// vsbe::PoreModel Abstract Interface /////////////////////////////

/// Create a PoreModel
///
/// This is the static create() method required to create an
/// implementation-specific instance of a vsbe::PoreModel.

PoreModel* PoreModel::create(PoreIbufId i_id, PoreInterface *i_interface)
{
	return new Vsbe(i_id, i_interface);
}

ModelError Vsbe::flushReset()
{
	return ModelError( pore_flush_reset(iv_engine) );
}

pore_reg_t Vsbe::PoreRegOffs_to_pore(vsbe::PoreRegisterOffset reg)
{
	switch (reg) {
	case PORE_STATUS:		 return PORE_R_STATUS;
	case PORE_CONTROL:		 return PORE_R_CONTROL;
	case PORE_RESET:		 return PORE_R_RESET;
	case PORE_ERROR_MASK:		 return PORE_R_ERROR_MASK;
	case PORE_PRV_BASE_ADDR0:	 return PORE_R_PRV_BASE_ADDR0;
	case PORE_PRV_BASE_ADDR1:	 return PORE_R_PRV_BASE_ADDR1;
	case PORE_OCI_MEMORY_BASE_ADDR0: return PORE_R_OCI_MEMORY_BASE_ADDR0;
	case PORE_OCI_MEMORY_BASE_ADDR1: return PORE_R_OCI_MEMORY_BASE_ADDR1;
	case PORE_TABLE_BASE_ADDR:	 return PORE_R_TABLE_BASE_ADDR;
	case PORE_EXE_TRIGGER:		 return PORE_R_EXE_TRIGGER;
	case PORE_SCRATCH0:		 return PORE_R_SCRATCH0;
	case PORE_SCRATCH1:		 return PORE_R_SCRATCH1;
	case PORE_SCRATCH2:		 return PORE_R_SCRATCH2;
	case PORE_IBUF_01:		 return PORE_R_IBUF_01;
	case PORE_IBUF_2:		 return PORE_R_IBUF_2;
	case PORE_DBG0:			 return PORE_R_DBG0;
	case PORE_DBG1:			 return PORE_R_DBG1;
	case PORE_PC_STACK0:		 return PORE_R_PC_STACK0;
	case PORE_PC_STACK1:		 return PORE_R_PC_STACK1;
	case PORE_PC_STACK2:		 return PORE_R_PC_STACK2;
	case PORE_ID_FLAGS:		 return PORE_R_ID_FLAGS;
	case PORE_DATA0:		 return PORE_R_DATA0;
	case PORE_MEM_RELOC:		 return PORE_R_MEM_RELOC;
	case PORE_I2C_E0_PARAM:		 return PORE_R_I2C_E0_PARAM;
	case PORE_I2C_E1_PARAM:		 return PORE_R_I2C_E1_PARAM;
	case PORE_I2C_E2_PARAM:		 return PORE_R_I2C_E2_PARAM;
	default:			 return PORE_R_ILLEGAL;
	}
	return PORE_R_ILLEGAL;
}


vsbe::PoreRegisterOffset Vsbe::pore_to_PoreRegOffs(pore_reg_t reg)
{
	switch (reg) {
	case PORE_R_STATUS:		 return PORE_STATUS;
	case PORE_R_CONTROL:		 return PORE_CONTROL;
	case PORE_R_RESET:		 return PORE_RESET;
	case PORE_R_ERROR_MASK:		 return PORE_ERROR_MASK;
	case PORE_R_PRV_BASE_ADDR0:	 return PORE_PRV_BASE_ADDR0;
	case PORE_R_PRV_BASE_ADDR1:	 return PORE_PRV_BASE_ADDR1;
	case PORE_R_OCI_MEMORY_BASE_ADDR0: return PORE_OCI_MEMORY_BASE_ADDR0;
	case PORE_R_OCI_MEMORY_BASE_ADDR1: return PORE_OCI_MEMORY_BASE_ADDR1;
	case PORE_R_TABLE_BASE_ADDR:	 return PORE_TABLE_BASE_ADDR;
	case PORE_R_EXE_TRIGGER:	 return PORE_EXE_TRIGGER;
	case PORE_R_SCRATCH0:		 return PORE_SCRATCH0;
	case PORE_R_SCRATCH1:		 return PORE_SCRATCH1;
	case PORE_R_SCRATCH2:		 return PORE_SCRATCH2;
	case PORE_R_IBUF_01:		 return PORE_IBUF_01;
	case PORE_R_IBUF_2:		 return PORE_IBUF_2;
	case PORE_R_DBG0:		 return PORE_DBG0;
	case PORE_R_DBG1:		 return PORE_DBG1;
	case PORE_R_PC_STACK0:		 return PORE_PC_STACK0;
	case PORE_R_PC_STACK1:		 return PORE_PC_STACK1;
	case PORE_R_PC_STACK2:		 return PORE_PC_STACK2;
	case PORE_R_ID_FLAGS:		 return PORE_ID_FLAGS;
	case PORE_R_DATA0:		 return PORE_DATA0;
	case PORE_R_MEM_RELOC:		 return PORE_MEM_RELOC;
	case PORE_R_I2C_E0_PARAM:	 return PORE_I2C_E0_PARAM;
	case PORE_R_I2C_E1_PARAM:	 return PORE_I2C_E1_PARAM;
	case PORE_R_I2C_E2_PARAM:	 return PORE_I2C_E2_PARAM;
	default:			 return PORE_ILLEGAL;;
	}
	return PORE_ILLEGAL;
}


//TODO Do we really need o_stepped. Ask Bishop if we can change the interface
ModelError Vsbe::step(bool& o_stepped)
{
	int rc, me;

	o_stepped = false;
	rc = pore_step(iv_engine);
	if ((rc == PORE_SUCCESS)     ||	// Normal execution
	    (rc == PORE_ERROR_IGNORED))	// An error was ignored!
		o_stepped = true;

	if (rc < 0) {
		/* FIXME Translate internal to external error codes nicely */
		switch (rc) {
		case PORE_ERR_HOOK_FAILED:
			me = ME_HOOK_INSTRUCTION_ERROR; break;
		case PORE_ERR_READ:
			me = ME_PORE_MODEL_GENERIC_ERROR; break;
		case PORE_ERR_WRITE:
			me = ME_PORE_MODEL_GENERIC_ERROR; break;

		case PORE_ERR_INVALID_OPCODE:
		default:
			me = ME_FAILURE; break;
		}
		return ModelError(me);
	}

	return ModelError(ME_SUCCESS);
}

ModelError Vsbe::registerRead(const vsbe::PoreRegisterOffset i_offset,
			      uint64_t& o_data, const size_t i_size)
{
	pore_reg_t reg =
		PoreRegOffs_to_pore(vsbe::PoreRegisterOffset(i_offset & ~0x7));

	if (((i_offset & 0x7) == 0x4) && (i_size == 4)) { // lower 32-bit
		o_data = pore_readReg(iv_engine, reg, PORE_BITS_32_63);
		o_data &= 0xffffffffull;
		return ME_SUCCESS;
	}
	if (((i_offset & 0x7) == 0x0) && (i_size == 4)) { // upper 32-bit
		o_data = pore_readReg(iv_engine, reg, PORE_BITS_0_31);
		o_data >>= 32;
		o_data &= 0xffffffffull;
		return ME_SUCCESS;
	}
	o_data = pore_readReg(iv_engine, reg, PORE_BITS_0_63);
	return ME_SUCCESS;
}

ModelError Vsbe::registerWrite(const vsbe::PoreRegisterOffset i_offset,
			       const uint64_t i_data, const size_t i_size)
{
        int rc;

	pore_reg_t reg =
		PoreRegOffs_to_pore(vsbe::PoreRegisterOffset(i_offset & ~0x7));

	if (((i_offset & 0x7) == 0x4) && (i_size == 4)) { // lower 32-bit
		rc = pore_writeReg(iv_engine, reg, i_data, PORE_BITS_32_63);
	} else if (((i_offset & 0x7) == 0x0) && (i_size == 4)) { // upper 32-bit
                rc = pore_writeReg(iv_engine, reg, i_data << 32, PORE_BITS_0_31);
	} else {
         	rc = pore_writeReg(iv_engine, reg, i_data, PORE_BITS_0_63);
        }
        return (rc ? ME_REGISTER_WRITE_ERROR : ME_SUCCESS);
}

ModelError Vsbe::registerReadRaw(const vsbe::PoreRegisterOffset i_offset,
				 uint64_t& o_data, const size_t i_size)
{
	pore_reg_t reg =
		PoreRegOffs_to_pore(vsbe::PoreRegisterOffset(i_offset & ~0x7));

	if (((i_offset & 0x7) == 0x4) && (i_size == 4)) { // lower 32-bit
		o_data = pore_readRegRaw(iv_engine, reg, PORE_BITS_32_63);
		o_data &= 0xffffffffull;
		return ME_SUCCESS;
	}
	if (((i_offset & 0x7) == 0x0) && (i_size == 4)) { // upper 32-bit
		o_data = pore_readRegRaw(iv_engine, reg, PORE_BITS_0_31);
		o_data >>= 32;
		o_data &= 0xffffffffull;
		return ME_SUCCESS;
	}
	o_data = pore_readRegRaw(iv_engine, reg, PORE_BITS_0_63);
	return ME_SUCCESS;
}

ModelError Vsbe::registerWriteRaw(const vsbe::PoreRegisterOffset i_offset,
			       const uint64_t i_data, const size_t i_size)
{
        int rc;
 
	pore_reg_t reg =
		PoreRegOffs_to_pore(vsbe::PoreRegisterOffset(i_offset & ~0x7));

	if (((i_offset & 0x7) == 0x4) && (i_size == 4)) { // lower 32-bit
		rc = pore_writeRegRaw(iv_engine, reg, i_data, PORE_BITS_32_63);
	} else if (((i_offset & 0x7) == 0x0) && (i_size == 4)) { // upper 32-bit
		rc =  pore_writeRegRaw(iv_engine, reg, i_data << 32, PORE_BITS_0_31);
	} else {
                rc = pore_writeRegRaw(iv_engine, reg, i_data, PORE_BITS_0_63);
        }
        return (rc ? ME_REGISTER_WRITE_ERROR : ME_SUCCESS);
}

ModelError Vsbe::enableHookInstruction(bool i_enable)
{
	pore_set_enableHookInstr(iv_engine, i_enable);
	return ME_SUCCESS;
}


ModelError Vsbe::enableAddressHooks(bool i_enable)
{
	pore_set_enableAddressHooks(iv_engine, i_enable);
	return ME_SUCCESS;
}


// To extract the state we simply read out the current register values.
//TODO Check what to do with some state registers like BRANCH_TAKEN, ...
ModelError Vsbe::extractState(vsbe::PoreState& o_state)
{
	pore_state_t s;
	unsigned int reg_id;
	uint64_t *reg;

	if (PORE_R_SIZEOF_PORE_STATE > (pore_reg_t)SIZEOF_PORE_STATE) {
		BUG();
	}

	pore_extractState(iv_engine, &s);
	for (reg_id = PORE_R_STATUS; reg_id < PORE_R_SIZEOF_PORE_STATE;
	     reg_id += 8) {
		reg = (uint64_t *)((uint8_t *)&s + reg_id);
		o_state.put((vsbe::PoreRegisterOffset)reg_id, *reg);
	}

	return ME_SUCCESS;
}


// To install the state we simply restore the saved register values.
//TODO Check what to do with some state registers like BRANCH_TAKEN, ...

ModelError Vsbe::installState(const vsbe::PoreState& i_state)
{
	uint64_t data;
	pore_state_t s;
	unsigned int reg_id;
	uint64_t *reg;

	if (PORE_R_SIZEOF_PORE_STATE > (pore_reg_t)SIZEOF_PORE_STATE) {
		BUG();
	}

	for (reg_id = PORE_R_STATUS; reg_id < PORE_R_SIZEOF_PORE_STATE;
	     reg_id += 8) {
		reg = (uint64_t *)((uint8_t *)&s + reg_id);
		i_state.get((vsbe::PoreRegisterOffset)reg_id, data);
		*reg = data;
	}
	pore_installState(iv_engine, &s);

	return ME_SUCCESS;
}


ModelError Vsbe::forceBranch(const vsbe::PoreAddress& i_address)
{
	return ModelError ( pore_forceBranch(iv_engine,
					     (uint64_t)i_address) );
}

#if 0
/// \bug We can't distinguish READ from EXECUTE
// Convert a PMX transaction to a VSBE transaction and master it
ModelError Vsbe::ociTransport(OciTransaction *inTransaction)
{
	ModelError me;
	vsbe::ModelError vsbe_me;
	OciTransaction transaction;
	do {

		transaction.iv_address = inTransaction->iv_address;

		if (inTransaction->iv_mode == ACCESS_MODE_READ) {
			transaction.iv_mode = vsbe::ACCESS_MODE_READ;
		} else {
			transaction.iv_mode = vsbe::ACCESS_MODE_WRITE;
			transaction.iv_data = inTransaction->iv_data;
		}

		vsbe_me = ociMaster(transaction);
		if (vsbe_me != 0) {
			break;
		}

		if (inTransaction->iv_mode == ACCESS_MODE_READ) {
			inTransaction->iv_data = transaction.iv_data;
		}
	} while (0);

	if (vsbe_me != 0) {
		modelError(vsbe_me);
		//TODO What is the right return value for me?
		//        me = OCI_TIMEOUT;
		me = ME_FAILURE;

		//TODO What is this ?
		//        DUAL_ERROR(vsbe_me, me);
	} else {
		me = ME_SUCCESS;
	}
	return me;
}


/// \bug We can't distinguish READ from EXECUTE
// Convert a PMX transaction to a VSBE transaction and master it
ModelError Vsbe::pibTransport(PibTransaction *inPibTransaction)
{
	ModelError me;
	vsbe::ModelError vsbe_me;
	PibTransaction pibTransaction;

	do {
		pibTransaction.iv_address = inPibTransaction->iv_address;

		if (inPibTransaction->iv_mode == vsbe::ACCESS_MODE_READ) {
			pibTransaction.iv_mode = vsbe::ACCESS_MODE_READ;
		} else {
			pibTransaction.iv_mode = vsbe::ACCESS_MODE_WRITE;
			pibTransaction.iv_data = inPibTransaction->iv_data;
		}

		vsbe_me = pibMaster(pibTransaction);
		if (vsbe_me != 0) {
			break;
		}

		inPibTransaction->iv_pcbReturnCode =
			pibTransaction.iv_pcbReturnCode;
		if (inPibTransaction->iv_mode == vsbe::ACCESS_MODE_READ) {
			inPibTransaction->iv_data = pibTransaction.iv_data;
		}
	} while (0);

	if (vsbe_me != 0) {
		modelError(vsbe_me);
		me = inPibTransaction->busError(ME_FAILURE);
		//TODO What is this ?
		//        DUAL_ERROR(vsbe_me, me);
	} else {
		me = ME_SUCCESS;
	}
	return me;
 }
#endif

ModelError Vsbe::hookInstruction(const PoreAddress& i_address,
				 const uint32_t i_hook,
				 const uint64_t i_parameter)
{
	PoreAddress vsbe_address;

	vsbe_address.iv_memorySpace = i_address.iv_memorySpace;
	vsbe_address.iv_offset = i_address.iv_offset;

	vsbe::PoreModel::hookInstruction(vsbe_address,
					 i_hook,
					 i_parameter);
	return ME_SUCCESS;
}


ModelError Vsbe::hookRead(const PoreAddress& i_address)
{
	vsbe::PoreAddress vsbe_address;

	vsbe_address.iv_memorySpace = i_address.iv_memorySpace;
	vsbe_address.iv_offset = i_address.iv_offset;

	vsbe::PoreModel::hookRead(vsbe_address);
	return ME_SUCCESS;
}


ModelError Vsbe::hookWrite(const PoreAddress& i_address)
{
	vsbe::PoreAddress vsbe_address;

	vsbe_address.iv_memorySpace = i_address.iv_memorySpace;
	vsbe_address.iv_offset = i_address.iv_offset;

	vsbe::PoreModel::hookWrite(vsbe_address);
	return ME_SUCCESS;
}


ModelError Vsbe::hookFetch(const PoreAddress& i_address)
{
	vsbe::PoreAddress vsbe_address;

	vsbe_address = i_address;
	//    vsbe_address.iv_memorySpace = i_address.iv_memorySpace;
	//    vsbe_address.iv_offset = i_address.iv_offset;

	vsbe::PoreModel::hookFetch(vsbe_address);
	return ME_SUCCESS;
}

void Vsbe::fatalErrorIntr(void)
{
	/* aprintf("PORe Model has hit fatalError\n"); */
	vsbe::PoreModel::fatalErrorIntr();
}

void Vsbe::errorIntr(void)
{
	/* aprintf("PORe Model has hit Error\n"); */
	vsbe::PoreModel::errorIntr();
}

void Vsbe::wait(const uint32_t i_count)
{
	/* aprintf("PORe Model waits for %d ticks\n", i_count); */
	vsbe::PoreModel::wait(i_count);
}

////////////////////////////// Creators //////////////////////////////

Vsbe::Vsbe(PoreIbufId i_id, PoreInterface* i_interface) :
	PoreModel(i_id, i_interface)
{
	struct pore_bus *pibBus, *ociBus;
	Vsbe **vsbe_p;

	pibBus = poreb_create("PIB_Bus",
			      sizeof(Vsbe *),
			      vsbePibReadCallBack,
			      vsbePibWriteCallBack,
			      NULL,     // fetch
			      NULL);    // reset
	if (pibBus == NULL) {
		BUG();
		return;
	}
	vsbe_p = (Vsbe **)poreb_get_priv(pibBus);
	*vsbe_p = this;

	ociBus = poreb_create("OCI_Bus",
			      sizeof(Vsbe *),
			      vsbeOciReadCallBack,
			      vsbeOciWriteCallBack,
			      NULL,     // fetch
			      NULL);    // reset
	if (pibBus == NULL) {
		BUG();
		return;
	}
	vsbe_p = (Vsbe **)poreb_get_priv(ociBus);
	*vsbe_p = this;

	switch (i_id) {
	case PORE_GPE0:
		iv_engine = pore_gpe0_create(pibBus, ociBus);
		break;
	case PORE_GPE1:
		iv_engine = pore_gpe1_create(pibBus, ociBus);
		break;
	case PORE_SLW:
		iv_engine = pore_slw_create(pibBus, ociBus);
		break;
	case PORE_SBE:
		iv_engine = pore_sbe_create(pibBus); /* pib */
		break;
	default:
		break;
	}

	pore_setpriv(iv_engine, (void *)this);
	pore_registerHooks(iv_engine,
			   vsbeHookInstructionCallBack,
			   vsbeHookReadCallBack,
			   vsbeHookWriteCallBack,
			   vsbeHookFetchCallBack,
			   NULL);

	pore_registerCallbacks(iv_engine,
			       waitIntrCallBack,
			       errorIntrCallBack,
			       fatalErrorIntrCallBack);
}

Vsbe::~Vsbe()
{
	pore_model_destroy(iv_engine); /* done */
}
