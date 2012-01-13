//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/porevesrc/pore.H $
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
#ifndef __VSBE_PORE_H
#define __VSBE_PORE_H

// $Id: pore.H,v 1.14 2011/11/17 19:04:47 jeshua Exp $

/// \file pore.H
/// \brief The implementation of the PoreInterface for the PoreVe environment

#include <fapi.H>

#include "bus.H"
#include "poremodel.H"
#include "hookmanager.H"

 #ifdef VBU_HACKS
 #include "fapiSharedUtils.H"
 #include "ecmdUtils.H"
 #endif  // VBU_HACKS


namespace vsbe {
    
    class Pore;

    /// This is the putative tick frequency of the simulation environment,
    /// used to model the wait() method.
    const double SIMULATOR_TICK_FREQUENCY = 12e9;

    /// This is the expected operating frequency of the PORE hardware engine,
    /// used to model the wait() method.
    const double PORE_FREQUENCY = 600e6;
};


/// The implementation of the PoreInterface for the PoreVe environment
///
/// This class provides implementations of the virtual interface to the
/// PoreModel for the PoreVe environment.  The Pore is configured by providing
/// pointers to the PIB and OCI bus models of the environment.  The Pore also
/// contains the last FAPI return code produced by an operation in the virtual
/// environment.
///
/// The Pore class is also derived from the PibSlave class.  This enables the
/// PORE engine to 'self-SCOM' PORE control registers that are not visible as
/// part of the architected state.  Since our PoreVe environment does not
/// included a generic OCB bridge, all self-SCOM must be programmed using PIB
/// addresses.

class 
vsbe::Pore : public PoreInterface, 
             public PibSlave 
{

public:

    ///////////////////////// Control Interface  /////////////////////////

    /// Force a branch to a global symbol name
    ///
    /// \param[in] i_symbol A global symbol name; the branch target
    ///
    /// Pore provides a variant of PoreModel::forceBranch() that forces a
    /// branch to a global symbol, assuming the global symbol is known to
    /// HookManager.  The error code ME_ILLEGAL_FORCED_BRANCH is returned if
    /// the symbol is not known to the HookManager.
    ///
    /// See PoreModel::forceBranch() for more information
    ///
    /// \retval me Either 0 for success or a ModelError code.
    virtual ModelError
    forceBranch(const char* i_symbol);


    ////////////////////  PoreInterface Methods  /////////////////////////

    /// See PoreModel::pibMaster() for the interface specification
    ///
    /// Run the transaction on the PoreVe PIB Bus model.  FAPI errors from
    /// running PIB/PCB transactions are converted to PCB return codes and
    /// stored in the \a iv_pcbReturnCode field of the \a io_transaction.
    void
    pibMaster(PibTransaction& io_transaction);

    /// See PoreModel::ociMaster() for the interface specification
    ///
    /// Run the transaction on the PoreVe OCI Bus model.  FAPI errors from
    /// running OCI transactions are converted to abstract return codes and
    /// stored in the \a iv_ociReturnCode field of the \a io_transaction.

    void
    ociMaster(OciTransaction& io_transaction);

    /// See PoreModel::wait() for the interface specification
    ///
    /// Simulate a WAIT of \a i_count PORE cycles.  The implementation
    /// attempts to accurately model the wait based on the assumed PORE clock
    /// frequency, and for simulation, the assumed simulation clock frequency.
    /// If execution of the WAIT results in a FAPI error, the FAPI error is
    /// stored in the \a iv_fapiReturnCode.

    void
    wait(const uint32_t i_count);

    /// See PoreModel::hookInstruction() for the interface specification
    ///
    /// Use the HookManager to run the numbered hook called out by a PORE
    /// HOOKI instruction. It is not considered an error to request a hook
    /// that is not mapped in the HookManager.  If execution of the hook
    /// results in a FAPI error, the FAPI error is stored in the
    /// \a iv_fapiReturnCode.
    void
    hookInstruction(const PoreAddress& i_address, 
                    const uint32_t i_hook,
                    const uint64_t i_parameter);

    /// See PoreModel::hookRead() for the interface specification
    ///
    /// Run any hooks associated with a read of the given effective address.
    /// If execution of the hook results in a FAPI error, the FAPI error is
    /// stored in the \a iv_fapiReturnCode.
    void
    hookRead(const PoreAddress& i_address);

    /// See PoreModel::hookWrite() for the interface specification
    ///
    /// Run any hooks associated with a write of the given effective address.
    /// If execution of the hook results in a FAPI error, the FAPI error is
    /// stored in the \a iv_fapiReturnCode.
    void
    hookWrite(const PoreAddress& i_address);

    /// See PoreModel::hookFetch() for the interface specification
    ///
    /// Run any hooks associated with an instruction fetch of the given
    /// effective address.  If execution of the hook results in a FAPI error,
    /// the FAPI error is stored in the \a iv_fapiReturnCode.
    void
    hookFetch(const PoreAddress& i_address);

    /// See PoreModel::errorIntr() for the interface specification
    ///
    /// Currently not implemented by Pore.
    void
    errorIntr(void) {}
    
    /// See PoreModel::fatalErrorIntr() for the interface specification
    ///
    /// Currently not implemented by Pore.
    void
    fatalErrorIntr(void) {}
    

    ////////////////////////  PibSlave Methods ////////////////////////////

    /// See Slave::operation() for the interface specification
    virtual fapi::ReturnCode
    operation(Transaction& io_transaction);


    ////////////////////////////// Creators //////////////////////////////

    /// Create the Pore
    ///
    /// \param[in] i_id The IBUF ID (PORE engine type) of the PORE model to
    /// create.
    Pore(PoreIbufId i_id);

    virtual ~Pore();

    ////////////////////  Interface Extensions  /////////////////////////

    /// Configure the Pore model by providing pointers to the Bus models
    ///
    /// \param[in] i_target A pointer to the FAPI target object associated
    /// with the PORE model, for use in hooks and for purposes of the
    /// PibSlave. 
    ///
    /// \param[in] i_pib A Bus model (to be) configured as a PIB bus.
    ///
    /// \param[in] i_oci A Bus model (to be) configured as an OCI bus.
    ///
    /// \param[in] i_dataBuffer See Slave::configure()
    ///
    /// \param[in] i_base See Slave::configure()
    ///
    /// \param[in] i_size See Slave::configure()
    ///
    /// \param[in] i_permissions See Slave::configure()
    ///
    /// This interface is introduced simply to encapsulate everything about
    /// the Pore that needs to be configured to create a system.  
    void
    configure(fapi::Target* i_target, Bus* i_pib, Bus* i_oci,
              ecmdDataBufferBase* i_dataBuffer,
              uint32_t i_base, uint64_t i_size, int i_permissions);

    /// Get the FAPI return code from the model
    ///
    /// \retval rc The last FAPI return code from any PORE operations in the
    /// environment. 
    fapi::ReturnCode
    getFapiReturnCode();


    ////////////////////////// Implementation ////////////////////////////

protected:

    /// The PoreVe PIB Bus model
    Bus* iv_pib;

    /// The PoreVe OCI Bus model
    Bus* iv_oci;

    /// The last FAPI return code
    ///
    /// Operations in the PoreVe environment return FAPI ReturnCode objects.
    /// The FAPI return code is stored here, and the ModelError returned to
    /// the PoreModel dependson the type of error.
    fapi::ReturnCode iv_fapiReturnCode;

    /// A pointer to the FAPI target associated with this PORE engine
    ///
    /// The Pore object holds this pointer for use as an argument to hook
    /// routines. 
    fapi::Target* iv_target;


    ///////////////////////////// Safety //////////////////////////////////

private:

    Pore(const Pore& i_rhs);
    Pore& operator=(const Pore& i_rhs);
};

#endif  // __VSBE_PORE_H
