//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/model/poremodel.H $
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
#ifndef __VSBE_POREMODEL_H
#define __VSBE_POREMODEL_H

// $Id: poremodel.H,v 1.23 2011/11/11 00:55:26 bcbrock Exp $

/// \file poremodel.H
/// \brief The PORE hardware engine model

#include <stddef.h>
#include <stdint.h>

#include "modelerror.H"
#include "poreinterface.H"
#include "transaction.H"

// This is required for debugging prints only
#if 1
#include <stdio.h>
#endif

namespace vsbe {

    class PoreAddress;
    class PoreInterface;
    class PoreModel;
};


////////////////////////////////////////////////////////////////////////////
// PoreModel
////////////////////////////////////////////////////////////////////////////


/// Abstract base class for the PORE hardware engine model
///
/// PoreModel is an abstract class that specifies the interfaces that a PORE
/// model will use to communicate to the virtual environment, and that the
/// environment will use to control the model.  This class is designed to
/// allow different implementations of PoreModel to be easily interchanged;
/// see the create() method.
///
/// The PoreModel is completely abstracted from the environment, however.  The
/// PoreModel communicates with the environment through a subclass of the
/// PoreInterface class.  This PoreInterface arranges for the implementation
/// of the externalized PoreModel operations.

class 
vsbe::PoreModel {

public:

    /////////////// Common Creation/Control Interface ////////////////////

    /// Create a new instance of a model derived from PoreModel
    ///
    /// \param[in] i_id The IBUF ID (PORE engine type) of the model to
    /// create. 
    ///
    /// \param[in] i_interface A pointer back to the PoreInterface that
    /// creates and owns this object and implements several of the PoreModel
    /// methods.  This parameter must be provided to the base class
    /// constructor.
    ///
    /// To facilitate swapping different PORE hardware models in and out
    /// transparently, this abstract base class declares a static function
    /// that creates an instance of the model to use.  Whoever provides the
    /// implementation of the derived class must define this method to produce
    /// an instance of the derived class the conforms to a PORE hardware
    /// engine of the parameterized type.
    static PoreModel* 
    create(PoreIbufId i_id, PoreInterface *i_interface);

    /// Restart the PORE engine to its scan-flush state
    ///
    /// For PORE-SBE, the engine is reset to begin execution from the OTPROM
    /// at the proper location, with all configuration registers (e.g., the
    /// I2C configuration) flushed to the correct state to begin an IPL.  
    ///
    /// For the other engines, they are reset as documented and will not run
    /// (correctly) until the BASE address and EXE trigger registers are
    /// written.  As a side effect the status of the PoreModel is computed and
    /// returned.  The PoreModel is defined to be in the restart (scan-flush)
    /// state at the end of constructing the model.
    ///
    /// \retval status PORE-SBE returns 0 (running); The other engines return
    /// PORE_STATUS_HARDWARE_STOP. 
    ///
    /// \bug Check to make sure this is true for the SBE.
    virtual int 
    restart();

    /// Step the model by (at most) N instructions
    ///
    /// \param[in] i_instructions The (maximum) number of instructions to
    /// execute. Use the constant RUN_UNLIMITED to run (effectively) forever.
    ///
    /// \param[out] o_ran The number of instructions that actually ran.  This
    /// may be 0 if \a i_instructions is 0, or if the PoreModel was in an
    /// unrunnable state when run() was invoked.  To find the total number of
    /// instructions that have run since model construction (or the last
    /// restart()), use the method getInstructions().
    ///
    /// When this method is invoked it is assumed that the caller wants the
    /// model to run, regardless of its current state. The run() method first
    /// attempts to make a stopped machine runnable, and then attempts to
    /// execute \a i_instructions and returns the final status and the number
    /// of instructions actually completed by this invocation.  
    ///
    /// - If the engine shows an error status before the execution of run()
    /// then no instructions will be executed and \a o_ran will be returned as
    /// 0.  To clear the error status use clearModelError() or
    /// clearHardwareErrors() to continue with restart()-ing the machine.
    ///
    /// - If the engine shows a stopped or error status at any time after the
    /// execution of the first instruction but before the execution of the
    /// final requested instruction, then run() returns at that point and \a
    /// o_ran indicates how many instructions were actually executed.
    ///
    /// - Calling run() with \a i_instructions == 0 simply makes a stopped
    /// machine runnable (if possible).
    ///
    /// Note that executing a single instruction may entail many bus
    /// transactions, especially in the case of the SCAND command which is
    /// treated as single instructions.  WAIT is also considered a single
    /// instruction regardless of the wait count.
    ///
    /// \retval 0 The PORE remains runnable.  In this case \a o_ran == \a
    /// i_instructions.
    ///
    /// \retval status An OR-combination of 1 or more PORE_STATUS_* flags
    /// indicating the final state of the PORE.
    virtual int 
    run(const uint64_t i_instructions, uint64_t& o_ran);
    
    /// Signal a debug-stop
    ///
    /// \param[in] i_stopCode A user-defined integer code to categorize the
    /// reason for the stop. Use \a i_stopCode == 0 to simply stop the
    /// machine.  Use a non-zero stop code to also cause
    /// PORE_STATUS_DEBUG_STOP to be set in the final status. 
    ///
    /// This API is provided for control programs or debugging code
    /// (e.g. hooks) to force the simulation to stop during the execution of
    /// the run() method, or to insure that the PORE engine is stopped and in
    /// the WAIT state prior to updating or examining the state. The effect of
    /// stop() is to terminate any ongoing run() method immediately by writing
    /// the PORE \c stop_start bit with a 1.  Calling the stop() method with a
    /// non-zero \a i_stopCode leaves the PORE abstract status with the
    /// PORE_STATUS_DEBUG_STOP bit set, and the \a i_stopCode provided can be
    /// later recovered with the getStopCode() method. Calling stop() multiple
    /// times with non-zero \a i_stopCode only records the last
    /// instance. Absent any error conditions a subsequent call of run() will
    /// restart the simulation.
    ///
    /// \retval me Returns 0 for success, otherwise any ModelError
    /// encountered during processing of the method.  If the engine has
    /// ModelError status prior to the call the method returns that status
    /// immediately (does not perform the stop() operation).
    virtual ModelError
    stop(const int i_stopCode);

    /// Signal a modeling error
    ///
    /// \param[in] i_modelError A model-defined integer code to categorize the
    /// type of modeling error.  If the model status includes
    /// PORE_STATUS_MODEL_ERROR then the getModelError() method returns this
    /// code, otherwise 0.  If \a i_modelError is 0 then this method has no
    /// effect. If modelError() is called multiple times with non-0 \a
    /// i_modelError during the execution of a single instruction then only
    /// the last non-0 value is recorded.
    ///
    /// This API is provided as a way for the system-level model or
    /// application debugging code (e.g. hooks) to force the simulation to
    /// halt with an error during the execution of the run() method.  The
    /// effect of the modelError() with a non-0 \a i_modelError parameter is
    /// to terminate a run() immediately and leave the PORE abstract status
    /// with the PORE_STATUS_MODEL_ERROR bit set. This is a fatal error; The
    /// model will not run instructions again until restart()-ed or the error
    /// is explicitly cleared with clearModelError().
    ///
    /// \retval i_modelError This routine returns its input \a i_modelError.
    virtual ModelError
    modelError(const ModelError i_modelError);

    /// Clear any ModelError from the model
    ///
    /// Note that the run() method will stop immediately and not continue a
    /// model that has a non-0 ModelError status.  This method allows the user
    /// to clear the ModelError status and continue execution.
    virtual void
    clearModelError();

    /// Clear PORE hardware error status
    ///
    /// PORE hardware error status is stored in the PORE DBG0 and DBG1
    /// registers. This procedure clears both of those registers to allow a
    /// simulation (or run) to continue in the event of a hardware error.
    /// Note that is a second hardware error occurs while the debug registers
    /// are "locked" (i.e., holding an error) the PORE hardware engine will
    /// halt. 
    ///
    /// \retval me Will be non-0 if an error occurs during the procedure.
    virtual ModelError
    clearHardwareErrors();

    /// Set the program counter
    ///
    /// \param i_pc The new program counter
    ///
    /// This method encapsulates the hardware register operations required to
    /// force-set the PORE program counter.  This method first calls stop() to
    /// halt the PORE engine.  If the engine is at a trap or breakpoint the
    /// stop() will take the engine back to the WAIT state, otherwise the new
    /// PC can not be guaranteed to take effect.  The PC is then updated. The
    /// engine is \e not restarted (if it had been running); At the end of
    /// this method the hardware will always be in the stopped state.
    ///
    /// \retval me Returns 0 for success, otherwise any ModelError
    /// encountered during processing of the method.  If the engine has
    /// ModelError status prior to the call the method returns that status
    /// immediately (does not perform the setPc() operation).
    virtual ModelError
    setPc(const PoreAddress& i_pc);

    /// Set the PORE address breakpoint
    ///
    /// \param[in] i_address The breakpoint address
    ///
    /// The PORE supports a single address breakpoint, and calling this API
    /// sets the breakpoint.  If the PC ever matches the breakpoint address
    /// then the PORE engine stops after executing an instruction at that
    /// address.
    ///
    /// The PORE address breakpoint can not be explicitly disabled, however
    /// the constant vsbe::PORE_UNBREAKABLE_ADDRESS contains a phony address
    /// that can be installed as the breakpoint address to effectively disable
    /// the address breakpopint.
    ///
    /// \retval me Returns 0 for success, otherwise any ModelError
    /// encountered during processing of the method.
    virtual ModelError
    setBreakpoint(const PoreAddress& i_address);

    /// Enable or disable the TRAP instruction
    ///
    /// \param[in] i_enable Controls whether TRAP is enabled or disabled.
    ///
    /// By default (or when TRAP is disabled) the TRAP instruction is treated
    /// by the PORE hardware as a NOP.  If enabled the TRAP instruction causes
    /// PORE execution to break in the Address-Breakpoint state, similar to an
    /// address breakpoint.  The run() method automatically restarts execution
    /// if the PORE engine is stopped in this state.
    ///
    /// \retval me Will be returned non-0 if any errors are encountered
    /// executing the procedure.
    virtual ModelError
    enableTrap(const bool i_enable);

    /// Return the current abstract status
    ///
    /// \retval status The current PoreModel abstract status as an
    /// OR-combination of PORE_STATUS_* bits.  See \ref pore_status.
    virtual int
    getStatus();

    /// Return the current PoreModel error code
    ///
    /// \retval error If the PORE status includes the bit
    /// PORE_STATUS_MODEL_ERROR then getModelError() returns the ModelError
    /// responsible, otherwise 0.
    virtual ModelError
    getModelError();

    /// Return the number of executed instructions
    ///
    /// \retval instrctions The total number of instructions executed since
    /// the model was created or restart()-ed.
    virtual uint64_t
    getInstructions();

    /// Return the code supplied with the last stop() method.
    ///
    /// \retval code If the PORE status includes the bit
    /// PORE_STATUS_DEBUG_STOP, then getStopCode() returns the parameter
    /// supplied with the last stop() call that caused the PORE model to stop.
    virtual int
    getStopCode();


    ///////////////////////// Abstract Interface /////////////////////////

    /// Reset the PORE engine to its scan-flush state
    ///
    /// For PORE-SBE, the engine is reset to execute the first instruction of
    /// OTPROM. For the other engines, they are reset as documented and will
    /// not run (correctly) until the BASE address and EXE trigger registers
    /// are written.  The PoreModel is defined to be in the reset
    /// (scan-flush) state at the end of constructing the model.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the reset as defined by the ModelError enumeration. 
    virtual ModelError
    flushReset() = 0;

    /// Step the PORE engine one instruction
    ///
    /// \param[out] o_stepped This parameter is set to true or false depending
    /// on whether the model successfully completed a step.
    ///
    /// Step the model 1 instruction, unless the model is presently in an
    /// unrecoverable error state, or the step itself causes an unrecoverable
    /// error. 
    ///
    /// Executing a single instruction may entail many bus transactions,
    /// especially in the case of the SCAND command which is treated as a
    /// single instruction.  WAIT is also considered a single instruction
    /// regardless of the wait count.  Finally, the PORE hardware may also be
    /// in a state where it can not execute an instruction without an external
    /// control action.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the step as defined by the ModelError enumeration. 
    virtual ModelError
    step(bool& o_stepped) = 0;

    /// Read a user-visible control or data register \e with side effects
    ///
    /// \param[in] i_offset The register offset (see below).
    ///
    /// \param[out] o_data The returned data.  For 4-byte reads the data is
    /// right justified.
    ///
    /// \param[in] i_size The size in bytes (see below).
    ///
    /// In general the PORE supports both 4- and 8-byte access to the control
    /// and data register space.  Registers are specified as an enumerated
    /// offset into the space. Other than 8-byte reads return the data right
    /// justfied in the 64-bit returned value.  8-byte reads are only allowed
    /// for offsets that are 8-byte aligned; 4-byte reads are allowed for any
    /// 4-byte aligned offset.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the access as defined by the ModelError enumeration.
    virtual ModelError
    registerRead(const PoreRegisterOffset i_offset, 
                 uint64_t& o_data, 
                 const size_t i_size = 8) = 0;

    /// Write a user-visible control or data register \e with side effects
    ///
    /// \param[in] i_offset The register offset (see below).
    ///
    /// \param[in] i_data The write data.  For 4-byte writes the data is
    /// right justified.
    ///
    /// \param[in] i_size The size in bytes (see below).
    ///
    /// In general the PORE supports both 4- and 8-byte access to the control
    /// and data register space.  Registers are specified as an enumerated
    /// offset into the space. 4-byte writes expect the data right justfied in
    /// the 64-bit input value.  8-byte writes are only allowed for offsets
    /// that are 8-byte aligned; 4-byte writes are allowed for any 4-byte
    /// aligned offset.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the access as defined by the ModelError enumeration.
    virtual ModelError
    registerWrite(const PoreRegisterOffset i_offset, 
                  const uint64_t i_data, 
                  const size_t i_size = 8) = 0;

    /// Read a user-visible control or data register \e without side effects
    ///
    /// \param[in] i_offset The register offset (see below).
    ///
    /// \param[out] o_data The returned data.  For 4-byte reads the data is
    /// right justified.
    ///
    /// \param[in] i_size The size in bytes (see below).
    ///
    /// In general the PORE supports both 4- and 8-byte access to the control
    /// and data register space.  Registers are specified as an enumerated
    /// offset into the space. Other than 8-byte reads return the data right
    /// justfied in the 64-bit returned value.  8-byte reads are only allowed
    /// for offsets that are 8-byte aligned; 4-byte reads are allowed for any
    /// 4-byte aligned offset.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the access as defined by the ModelError enumeration.
    virtual ModelError
    registerReadRaw(const PoreRegisterOffset i_offset, 
                    uint64_t& o_data, 
                    const size_t i_size = 8) = 0;

    /// Write a user-visible control or data register \e without side effects
    ///
    /// \param[in] i_offset The register offset (see below).
    ///
    /// \param[in] i_data The write data.  For 4-byte writes the data is
    /// right justified.
    ///
    /// \param[in] i_size The size in bytes (see below).
    ///
    /// In general the PORE supports both 4- and 8-byte access to the control
    /// and data register space.  Registers are specified as an enumerated
    /// offset into the space. 4-byte writes expect the data right justfied in
    /// the 64-bit input value.  8-byte writes are only allowed for offsets
    /// that are 8-byte aligned; 4-byte writes are allowed for any 4-byte
    /// aligned offset.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the access as defined by the ModelError enumeration.
    virtual ModelError
    registerWriteRaw(const PoreRegisterOffset i_offset, 
                     const uint64_t i_data, 
                     const size_t i_size = 8) = 0;

    /// Enable or disable the HOOKI instruction
    ///
    /// \param[in] i_enable Either enable or disable the HOOKI instruction.
    ///
    /// The virtual HOOK instruction is disabled by default.  This API enables
    /// or disables the PoreModel to call out using the PoreModel::hook()
    /// interface when it encounters a HOOKI instruction.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the method as defined by the ModelError enumeration. 
    virtual ModelError
    enableHookInstruction(bool i_enable) = 0;

    /// Enable or disable address-based hooks
    ///
    /// \param[in] i_enable Either enable or disable address-based hooks.
    ///
    /// Address-based hooks are disabled by default.  This API enables or
    /// disables the PoreModel to call out using the readHook(), writeHook()
    /// and fetchHook() interfaces whenever the model is about to read, write
    /// or fetch respectively.
    ///
    /// \retval me Return values other than 0 indicate some type of error in
    /// the method as defined by the ModelError enumeration. 
    virtual ModelError
    enableAddressHooks(bool i_enable) = 0;

    /// Extract the PORE state for checkpointing
    ///
    /// \param[out] o_state A reference to a PoreState object to receive the
    /// checkpointed state.
    ///
    /// This method checkpoints the state of a PORE engine into an abstract
    /// PoreState object, in a way that allows the state to be later restored
    /// with installState().  The state that is saved is only the PORE engine
    /// state, and does not include any other state of the PORE virtual
    /// environment.
    ///
    /// This method must be implemented in the derived class that implements
    /// other virtual methods of the PoreModel.  A simulation or software
    /// model should be able to precisely recover to an arbitrary
    /// state. Physical hardware may have limited abilities to do this due to
    /// register side effects, read-only state etc., and may return an error
    /// code if PORE engine is in a state that can't be restored.
    ///
    /// Note: The PORE engine must be in the hardware-stop state
    /// before checkpointing in order to guarantee that the state can be
    /// precisely saved and restored under all conditions.
    ///
    /// \retval me Normally 0 for success, but may be set by a dervied model
    /// that is unable to satisfactorily extract the state for some reason.
    virtual ModelError
    extractState(PoreState& o_state) = 0;

    /// Install a checkpointed state
    ///
    /// \param[in] i_state A PoreState object containing the entire visible
    /// register state of the PORE.
    ///
    /// This method restores a PORE engine state checkpointed with
    /// extractState().  The state that is restored is only the PORE engine
    /// state.  The PoreState object does not include any other state of the
    /// PORE virtual environment.
    ///
    /// This method must be implemented in the derived class that implements
    /// other virtual methods of the PoreModel.  A simulation or software
    /// model should be able to precisely recover to an arbitrary
    /// state. Physical hardware may have limited abilities to do this due to
    /// register side effects, read-only state etc., and may return an error
    /// code if unable to restore the state from the PoreState object.
    ///
    /// \retval me Normally 0 for success, but may be set by a dervied model
    /// that is unable to satisfactorily restore a state for some reason.
    virtual ModelError
    installState(const PoreState& i_state) = 0;

    /// Force the PORE engine to branch (from a hook context)
    ///
    /// \param[in] i_address The address to branch to.
    ///
    /// This method is for use only by hooks, and only by address-based fetch
    /// hooks and hooks attached to the HOOKI instruction.  This method forces
    /// the PORE engine to branch to an address specified in the \a i_address
    /// parameter.  This method is only defined on software simulated models,
    /// and will not work on hardware models (including VHDL PORE models). To
    /// change the PC from a stopped state use the setPc() method which will
    /// work on all underlying models.
    ///
    /// The behavior varies based on the hook context:
    ///
    /// - For address-based fetch hooks, the conceptual model is that the hook
    /// executes before the instruction that follows the hook.  Practically
    /// speaking, the hook may actually be invoked at the beginning of
    /// instruction fetch.  The derived PoreModel will ensure that any fetch
    /// and execution of the instruction following the hook is cleanly
    /// abandoned, and will instead go to fetch and execute the instruction at
    /// \a i_address, including processing any fetch hooks on the new
    /// target. The hook subroutine that invokes forceBranch() will be fully
    /// executed before the forced branch.
    ///
    /// - For HOOKI instruction hooks the, the behavior is as if the HOOKI
    /// instruction were an immediate branch to the absolute target. Again,
    /// the hook subroutine that invokes forceBranch() will be fully executed
    /// before the forced branch.
    ///
    /// If forceBranch() is called from any other context, the PoreModel will
    /// return the ModelError ME_ILLEGAL_FORCED_BRANCH.  Even so, this API is
    /// fraught with potential problems, e.g. ping-pong livelocks between
    /// fetch hooks. forceBranch() should only be used for simple,
    /// straightforward control flow modifications.
    ///
    /// \retval Either 0 for SUCCESS, ME_ILLEGAL_FORCED_BRANCH or any other
    /// non-0 ModelError that might be signalled during execution of the
    /// method.
    virtual ModelError
    forceBranch(const PoreAddress& i_address) = 0;


    ////////////////////  PoreInterface Methods  /////////////////////////

protected:

    /// Master a PIB transaction to the virtual environment
    ///
    /// \param[in,out] io_transaction The abstract PIB transaction
    ///
    /// PIB/PCB transaction status is returned in the \a iv_pcbReturnCode
    /// field of the transaction. A legal API call will always succeed, even
    /// if the underlying bus transaction fails.  If the transaction is
    /// illegal in some way (indicating an issue in the derived PoreModel) then
    /// this must be trapped by the PoreInterface.
    void
    pibMaster(PibTransaction& io_transaction);

    /// Master an OCI transaction to the virtual environment
    ///
    /// \param[in,out] io_transaction The abstract OCI transaction
    ///
    /// OCI transaction status is returned in the \a iv_ociReturnCode field of
    /// the transaction. A legal API call will always succeed, even if the
    /// underlying bus transaction fails.  If the transaction is illegal in
    /// some way (indicating an issue in the derived PoreModel) then this must
    /// be trapped by the PoreInterface.
    void
    ociMaster(OciTransaction& io_transaction);

    /// Implement the WAIT instruction
    ///
    /// \param[in] i_count The number of PORE cycles to wait.
    ///
    /// The PoreModel has no notion of time, so it requires the environment to
    /// model WAIT.  The hardware treats WAIT 0 as a special HALT instruction,
    /// however the concrete model still must still invoke the wait() method
    /// in this case to inform the abstract model that the PORE has halted
    /// (since this generates a hardware interrupt).  Since WAIT can not fail
    /// in the hardware, any errors in the implementation of wait() must be
    /// handled by the PoreInterface.
    void
    wait(const uint32_t i_count);

    /// Implement the HOOKI instruction
    ///
    /// \param[in] i_address The effective address of the HOOKI instruction.
    ///
    /// \param[in] i_hook The low-order 24 bits of the HOOKI instruction, used
    /// to index the hook routine that will process the hook.
    ///
    /// \param[in] i_parameter A 64-bit parameter for the hook routine.
    ///
    /// The HOOKI instruction allows the PORE code to invoke a fixed set of
    /// hooks indexed by a 24-bit integer code, passing each hook routine a
    /// 64-bit parameter.  The underlying hardware model has no dependency on
    /// the outcome of running a hook, therefore any errors in hook processing
    /// must be handled by the PoreInterface.
    void
    hookInstruction(const PoreAddress& i_address, 
                    const uint32_t i_hook,
                    const uint64_t i_parameter);

    /// Notify the environment of a data read
    ///
    /// \param[in] i_address The effective PoreAddress of the data read.
    ///
    /// This method allows the environment to hook data reads.  For direct
    /// memory accesses, this method is called immediately before a bus
    /// transaction is generated to fetch the data at the given effective
    /// address. For indirect PIB transactions, this method is invoked prior
    /// to the I2C transaction that actually reads the data from the I2C
    /// memory. The underlying hardware model has no dependency on the outcome
    /// of running a hook, therefore any errors in hook processing must be
    /// handled by the PoreInterface.
    void
    hookRead(const PoreAddress& i_address);

    /// Notify the environment of a data write
    ///
    /// \param[in] i_address The effective PoreAddress of the data write.
    ///
    /// This method allows the environment to hook data writes.  For direct
    /// memory accesses, this method is called immediately before a bus
    /// transaction is generated to store the data at the given effective
    /// address. For indirect PIB transactions, this method is invoked prior
    /// to the I2C transaction that actually writes the data to the I2C
    /// memory. The underlying hardware model has no dependency on the outcome
    /// of running a hook, therefore any errors in hook processing must be
    /// handled by the PoreInterface.
    void
    hookWrite(const PoreAddress& i_address);

    /// Notify the environment of an instruction fetch
    ///
    /// \param[in] i_address The effective PoreAddress of the instruction.
    ///
    /// This method allows the environment to hook instruction fetches, where
    /// an instruction fetch refers to reading the first 4 (of potentially 12)
    /// bytes that comprise an instruction for the purposes of instruction
    /// execution.  For direct memory accesses, this method is called
    /// immediately before a bus transaction is generated to read the
    /// instruction data at the given effective address. For indirect PIB
    /// transactions, this method is invoked prior to the I2C transaction that
    /// actually fetches the data from the I2C memory. The underlying hardware
    /// model has no dependency on the outcome of running a hook, therefore
    /// any errors in hook processing must be handled by the PoreInterface.
    void
    hookFetch(const PoreAddress& i_address);

    /// Notify the environment of the error interrupt
    ///
    /// This method must be invoked by the deribed PoreModel whenever the
    /// execution of an instruction would pulse the PORE hardware \a
    /// tp_por_error_out signal.
    void
    errorIntr(void);

    /// Notify the environment of the fatal error interrupt
    ///
    /// This method must be invoked by the derived PoreModel whenever the
    /// execution of an instruction would pulse the PORE hardware \a
    /// tp_por_fatal_error_out signal.
    void
    fatalErrorIntr(void);


    ////////////////////////////// Creators //////////////////////////////

public:

    /// Create the PoreModel base class
    ///
    /// The PoreModel is defined to be in the restart (scan-flush) state at
    /// the end of constructing the model.
    ///
    /// \param[in] i_ibufId The IBUF ID (PORE type) of the model.
    ///
    /// \param[in] i_interface A pointer back to the PoreInterface that
    /// created this model.
    PoreModel(const PoreIbufId i_ibufId, PoreInterface* i_interface);

    virtual ~PoreModel();


    ////////////////////////// Implementation ////////////////////////////

protected:

    /// The IBUF ID (engine type) of the PORE being modeled
    PoreIbufId iv_ibufId;

private:

    /// The most recent ModelError generated by the model or by calls of
    /// modelError(), or 0 for no error.
    ModelError iv_modelError;

    /// The total number of instructions executed since the PoreModel
    /// was created, or since the last restart() operation.
    uint64_t iv_instructions;

    /// The most recent stop code provided in a call of stop(), or 0 if the
    /// model is not stopped.
    int iv_stopCode;

    /// Pointer back to the virtual interface containing this hardware model.
    PoreInterface* iv_interface;


    ///////////////////////////// Safety //////////////////////////////////

private:
    PoreModel(const PoreModel& i_rhs);
    PoreModel& operator=(const PoreModel& i_rhs);
};

#endif  // __VSBE_POREMODEL_H
