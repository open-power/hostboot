/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/include/vsbe.H $               */
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
// $Id: vsbe.H,v 1.9 2013/11/27 17:21:19 thi Exp $
#ifndef __VSBE_H
#define __VSBE_H

/**
 * @file   vsbe.H
 * @Author Andre Hertwig with additions by Frank Haverkamp
 * @date   October, 2011
 *
 * @brief The interface between the vsbe::PoreModel and the virtual
 * pore engine model.
 */

#include "transaction.H"
#include "modelerror.H"
#include "poremodel.H"
#include "poreinterface.H"
#include "pore_model.h"

#define PORE_UNRUNNABLE "The PORE engine is not runnable without some control action"

namespace vsbe {
	/** Hooks */
	int vsbeHookReadCallBack  (pore_model_t p, uint64_t i_address);
	int vsbeHookWriteCallBack (pore_model_t p, uint64_t i_address);
	int vsbeHookFetchCallBack (pore_model_t p, uint64_t i_address);
	int vsbeHookDecodeCallBack(pore_model_t p, uint8_t *instr,
				   unsigned int size);
	int vsbeHookInstructionCallBack(pore_model_t p, uint64_t i_address,
					uint32_t i_hook, uint64_t i_parameter);


	/** Signals */
	void stoppedIntrCallBack(pore_model_t p);
	void fatalErrorIntrCallBack(pore_model_t p);
	void errorIntrCallBack(pore_model_t p);
	void waitIntrCallBack(pore_model_t p, uint32_t delay);

	/** Data transfer */
	int vsbePibReadCallBack(pore_bus_t p, uint64_t addr, uint8_t *buf,
				unsigned int size, int *err_code);

	int vsbePibWriteCallBack(pore_bus_t p, uint64_t addr,
				 const uint8_t *buf, unsigned int size,
				 int *err_code);

	int vsbeOciReadCallBack(pore_bus_t p, uint64_t addr, uint8_t *buf,
				unsigned int size, int *err_code);

	int vsbeOciWriteCallBack(pore_bus_t p, uint64_t addr,
				 const uint8_t *buf, unsigned int size,
				 int *err_code);
}

///////////////////////////////////////////////////////////////////////////////
// Vsbe
///////////////////////////////////////////////////////////////////////////////


/// Implementation of the vsbe::PoreModel class.
///
/// For interface documentation see vsbe::PoreModel.


class Vsbe : public vsbe::PoreModel {

public:

	///////////// vsbe::PoreModel Abstract Interface //////////////////////

	virtual vsbe::ModelError flushReset();
	virtual vsbe::ModelError step(bool& o_stepped);

	/// @brief Register access with real hardware behavior
	///
	///   Access upper 32-bit:
	///     registerRead(i_offset, data, 4);
	///   Access lower 32-bit:
	///     registerRead(i_offset + 4, data, 4);
	///   Access 64-bit:
	///     registerRead(i_offset, data, 8);
	///
	virtual vsbe::ModelError
	registerRead(const vsbe::PoreRegisterOffset i_offset,
		     uint64_t& o_data, const size_t i_size);

	virtual vsbe::ModelError
	registerWrite(const vsbe::PoreRegisterOffset i_offset,
		      const uint64_t i_data, const size_t i_size);

	/// @brief Register access without hardware side effects
	///
	///   Access upper 32-bit:
	///     registerReadRaw(i_offset, data, 4);
	///   Access lower 32-bit:
	///     registerReadRaw(i_offset + 4, data, 4);
	///   Access 64-bit:
	///     registerReadRaw(i_offset, data, 8);
	///
	virtual vsbe::ModelError
	registerReadRaw(const vsbe::PoreRegisterOffset i_offset,
			uint64_t& o_data, const size_t i_size);

	virtual vsbe::ModelError
	registerWriteRaw(const vsbe::PoreRegisterOffset i_offset,
			 const uint64_t i_data, const size_t i_size);

	virtual vsbe::ModelError enableHookInstruction(bool i_enable);
	virtual vsbe::ModelError enableAddressHooks(bool i_enable);

	virtual vsbe::ModelError extractState(vsbe::PoreState& o_state);
	virtual vsbe::ModelError installState(const vsbe::PoreState& i_state);
	virtual vsbe::ModelError forceBranch(const vsbe::PoreAddress&
					     i_address);

	//////////////// Pmx::Pore Abstract Interface /////////////////////////

	// BB virtual vsbe::ModelError
	// BB ociTransport(vsbe::OciTransaction *transaction);
        // BB 
	// BB virtual vsbe::ModelError
	// BB pibTransport(vsbe::PibTransaction *transaction);

	virtual vsbe::ModelError
	hookInstruction(const vsbe::PoreAddress& i_address,
			const uint32_t i_hook,
			const uint64_t i_parameter);

	virtual vsbe::ModelError hookRead(const vsbe::PoreAddress& i_address);
	virtual vsbe::ModelError hookWrite(const vsbe::PoreAddress& i_address);
	virtual vsbe::ModelError hookFetch(const vsbe::PoreAddress& i_address);

	virtual void wait(const uint32_t i_count);
	virtual void fatalErrorIntr(void);
	virtual void errorIntr(void);

	////////////////////////////// Creators ///////////////////////////////

	Vsbe(vsbe::PoreIbufId i_id, vsbe::PoreInterface* i_interface);

	virtual ~Vsbe();

	////////////////////////////// Manipulators ///////////////////////////

	int pibReadCallBack(pore_bus_t p, uint64_t addr, uint8_t *buf,
			    unsigned int size, int *err_code);

	int pibWriteCallBack(pore_bus_t p, uint64_t addr, const uint8_t *buf,
			     unsigned int size, int *err_code);

	int ociReadCallBack(pore_bus_t p, uint64_t addr, uint8_t *buf,
			    unsigned int size, int *err_code);

	int ociWriteCallBack(pore_bus_t p, uint64_t addr, const uint8_t *buf,
			     unsigned int size, int *err_code);

	////////////////////////// Implementation /////////////////////////////


	/// A vsbe::PibTransaction for PIB mastering
	vsbe::PibTransaction d_pibTransaction;

	/// A vsbe::OciTransaction for OCI mastering
	vsbe::OciTransaction d_ociTransaction;

private:
	struct pore_model *iv_engine;
	pore_reg_t PoreRegOffs_to_pore(vsbe::PoreRegisterOffset reg);
	vsbe::PoreRegisterOffset pore_to_PoreRegOffs(pore_reg_t reg);
};

#endif // __VSBE_H
