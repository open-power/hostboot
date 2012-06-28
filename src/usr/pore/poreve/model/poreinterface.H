/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pore/poreve/model/poreinterface.H $
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
#ifndef __VSBE_POREINTERFACE_H
#define __VSBE_POREINTERFACE_H

// $Id: poreinterface.H,v 1.11 2012/06/18 13:56:57 bcbrock Exp $

/// \file poreinterface.H
/// \brief The PORE hardware interface class

#include <stddef.h>
#include <stdint.h>

#include "bebits.H"
#include "modelerror.H"
#include "poreaddress.H"
#include "transaction.H"
#include "poreconstants.H"
#include "poreregister.H"
#include "porestate.H"

// This is required for debugging prints only
#if 1
#include <stdio.h>
#endif

namespace vsbe {

    class PoreAddress;
    class PoreInterface;
    class PoreModel;
    class PoreState;
}


////////////////////////////////////////////////////////////////////////////
// PoreInterface
////////////////////////////////////////////////////////////////////////////


/// Abstract base class for the PORE hardware engine virtual environment
///
/// PoreInterface is an abstract class that specifies the interfaces that a
/// virtual environment must implement on behalf of the abstract PoreModel,
/// and provides the control interfaces into the PoreModel. Applications will
/// never operate on the PoreModel directly, but instead will operate
/// exclusively on classes derived from PoreInterface.

class 
vsbe::PoreInterface {

public:

    ///////////////////////// Control Interface  /////////////////////////

    /// See PoreModel::restart()
    virtual int 
    restart();

    /// See PoreModel::run()
    virtual int 
    run(const uint64_t i_instructions, uint64_t& o_ran);
    
    /// See PoreModel::stop()
    virtual ModelError
    stop(const int i_stopCode);

    /// See PoreModel::modelError()
    virtual ModelError 
    modelError(const ModelError i_modelError);

    /// See PoreModel::clearModelError()
    virtual void
    clearModelError();

    /// See PoreModel::clearHardwareErrors()
    virtual ModelError
    clearHardwareErrors();

    /// See PoreModel::registerRead()
    virtual ModelError
    registerRead(const PoreRegisterOffset i_offset, 
                 uint64_t& o_data, 
                 const size_t i_size = 8);

    /// See PoreModel::registerWrite()
    virtual ModelError
    registerWrite(const PoreRegisterOffset i_offset, 
                  const uint64_t i_data, 
                  const size_t i_size = 8);

    /// See PoreModel::registerReadRaw()
    virtual ModelError
    registerReadRaw(const PoreRegisterOffset i_offset, 
                    uint64_t& o_data, 
                    const size_t i_size = 8);

    /// See PoreModel::registerWriteRaw()
    virtual ModelError
    registerWriteRaw(const PoreRegisterOffset i_offset, 
                     const uint64_t i_data, 
                     const size_t i_size = 8);

    /// See PoreModel::enableHookInstruction()
    virtual void
    enableHookInstruction(bool i_enable);

    /// See PoreModel::enableAddressHooks()
    virtual void
    enableAddressHooks(bool i_enable);

    /// See PoreModel::extractState()
    virtual ModelError
    extractState(PoreState& o_state);

    /// See PoreModel::installState()
    virtual ModelError
    installState(const PoreState& i_state);

    /// See PoreModel::forceBranch()
    virtual ModelError
    forceBranch(const PoreAddress& i_address);

    /// See PoreModel::setPc()
    virtual ModelError
    setPc(const PoreAddress& I_pc);

    /// See PoreModel::setBreakpoint()
    virtual ModelError
    setBreakpoint(const PoreAddress& i_address);

    /// Effectively disable the PORE address breakpoint
    ///
    /// \retval 0 Success
    ///
    /// \retval non-0 Any ModelError returned by underlying hardware
    /// operations. 
    virtual ModelError
    disableBreakpoint();

    /// See PoreModel::enableTrap()
    virtual ModelError
    enableTrap(const bool i_enable);

    /// See PoreModel::getStatus()
    virtual int
    getStatus();

    /// See PoreModel::getModelError()
    virtual ModelError
    getModelError();

    /// See PoreModel::getInstructions()
    virtual uint64_t 
    getInstructions();

    /// See PoreModel::getStopCode()
    virtual int
    getStopCode();

    /// See PoreModel::getmemInteger()
    virtual ModelError
    getmemInteger(const PoreAddress i_address,
                  uint64_t& o_data,
                  const size_t i_size);

    /// See PoreModel::putmemInteger()
    virtual ModelError
    putmemInteger(const PoreAddress i_address,
                  uint64_t i_data,
                  const size_t i_size);


    ////////////////////  Abstract Interface  /////////////////////////

    /// See PoreModel::pibMaster()
    virtual void
    pibMaster(PibTransaction& io_transaction) = 0;

    /// See PoreModel::ociMaster()
    virtual void
    ociMaster(OciTransaction& io_transaction) = 0;

    /// See PoreModel::wait()
    virtual void
    wait(const uint32_t i_count) = 0;

    /// See PoreModel::hookInstruction()
    virtual void
    hookInstruction(const PoreAddress& i_address, 
                    const uint32_t i_hook,
                    const uint64_t i_parameter) = 0;

    /// See PoreModel::hookRead()
    virtual void
    hookRead(const PoreAddress& i_address) = 0;

    /// See PoreModel::hookWrite()
    virtual void
    hookWrite(const PoreAddress& i_address) = 0;

    /// See PoreModel::hookFetch()
    virtual void
    hookFetch(const PoreAddress& i_address) = 0;

    /// See PoreModel::errorIntr()
    virtual void
    errorIntr(void) = 0;

    /// See PoreModel::fatalErrorIntr()
    virtual void
    fatalErrorIntr(void) = 0;


    ////////////////////////////// Creators //////////////////////////////

    /// Create the PoreInterface 
    ///
    /// \param[in] i_id The IBUF ID (PORE engine type) of the PORE model to
    /// create.
    PoreInterface(PoreIbufId i_id);

    virtual ~PoreInterface();


    ///////////////////// Register Interface  ////////////////////////////

    /// \defgroup pore_register_access PORE Register Access
    ///
    /// These data members of PoreInterface provide easy access to
    /// programmer-visible and abstract registers for use by procedures and
    /// hooks. Unless otherwise indicated in the brief comment the register is
    /// both readable and writable. Data registers, address registers, the
    /// counter register and some control register values are right justfied,
    /// and only the indicated number of bits are writable. Other hardware
    /// control registers have unique layouts. See the detailed comments for
    /// each register and the comments for the PoreRegister class for more
    /// information.
    ///
    /// @{

    /// 64-bit data register D0
    PoreDataBuffer d0;
    /// 64-bit data register D1
    PoreDataBuffer d1;
    /// 32-bit address register A0
    PoreRegisterWritable a0;
    /// 32-bit address register A1
    PoreRegisterWritable a1;
    /// 7-bit pervasive chiplet register P0
    PoreRegisterWritable p0;
    /// 7-bit pervasive chiplet register P1
    PoreRegisterWritable p1;
    /// 24-bit counter CTR
    PoreRegisterWritable ctr;
    /// 21-bit error mask register
    ///
    /// The EMR is implemented as a 64-bit registers, however only the
    /// high-order 21 bits contain information.
    PoreRegisterWritable emr;
    /// 64-bit EXE-Trigger Register - Partially writable
    ///
    /// The low-order 32 bits of the EXE-Trigger register are writable from a
    /// PORE program.  The register is fully writable externally, however this
    /// has the major side effect of kicking off a new PORE program if the
    /// high-order 32-bits are written.  The write implementation here only
    /// writes the low-order 32 bits; to write the entire register call
    /// registerWrite() directly.
    PoreRegisterWritable etr;
    /// 32-bit Special-Purpose General Register 0
    PoreRegisterWritable sprg0;
    /// PC - Read-only
    /// 
    /// The 48-bit PC is read-only using the PoreRegister interface.  Setting
    /// the PC requires using the setPc() procedure on the PoreInterface.
    /// It's likely that a hook programmer should actually be using the
    /// abstract \c CIA register.
    PoreRegister pc;
    /// ID-Flags Register - Partial read-only
    ///
    /// Note that from inside a PORE program this register is read-only.
    /// Externally the ALU flags fields of the register are writable, so this
    /// behavior is supported.  The writable portion (the flags) are bits
    /// 48:55. 
    PoreRegisterWritable ifr;
    /// Current instruction address - Read-Only
    ///
    /// This is an abstract register. If the PORE engine is running or stopped
    /// at a breakpoint or trap then reading the CIA returns the address of
    /// the currently executing instruction.  If the PORE engine is stopped in
    /// a wait state then reading the CIA returns the address of the last
    /// instruction executed.
    ///
    /// This register is read-only.  If the intention is to force a branch
    /// then the forceBranch() or setPc() methods of the PoreInterface should
    /// be used.
    PoreRegister cia;

    /// @}

    ////////////////////////// Implementation ////////////////////////////

protected:

    /// Create a new underlying model
    ///
    /// \param[in] i_id The IBUF ID (PORE engine type) of the PORE model to
    /// create.
    ///
    /// This method creates and installs an instance of the PoreModel with a
    /// specific PoreIbufId.  This method is provided separately from the
    /// constructor to support use of the PoreInterface in the Simics
    /// environment.  In Simics, the type of the engine (GPE0, SLW, etc.) is
    /// not known until after model construction, but before actual simulation
    /// begins.  In Simics models are created with a default type, then later
    /// recreated using newModel() once the actual type is known.
    virtual void
    newModel(PoreIbufId i_id);

    /// The IBUF ID (engine type) of the PORE being modeled
    PoreIbufId iv_ibufId;
    
private:

    /// The associated PoreModel
    ///
    /// This object is created and destroyed by the PoreInterface.
    PoreModel* iv_model;

    ///////////////////////////// Safety //////////////////////////////////

private:
    PoreInterface(const PoreInterface& rhs);
    PoreInterface& operator=(const PoreInterface& rhs);
};


#endif  // __VSBE_POREINTERFACE_H
