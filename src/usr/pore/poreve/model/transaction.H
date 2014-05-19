/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/transaction.H $                     */
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
#ifndef __VSBE_TRANSACTION_H
#define __VSBE_TRANSACTION_H

// $Id: transaction.H,v 1.4 2011/06/06 15:35:15 bcbrock Exp $

/// \file transaction.H
/// \brief PORE abstract bus transactions

#include <stddef.h>
#include <stdint.h>

#include "modelerror.H"


namespace vsbe {

    class Transaction;
    class PibTransaction;
    class OciTransaction;


    /// \defgroup pore_transaction_modes PORE Transaction Modes
    ///
    /// Each PORE transaction is tagged with a one-hot mask indicating whether
    /// the transaction is a read, write or instruction fetch.  The Slave
    /// and MemoryImage models also include a bit-set of these masks to
    /// indicate whether the Slave or MemoryImage supports the indicated
    /// access.
    ///
    /// @{

    /// A data read; Allow read access
    const int ACCESS_MODE_READ = 0x1; 
    /// A data write; Allow write access
    const int ACCESS_MODE_WRITE = 0x2;
    /// An instruction fetch; Allow execute access
    const int ACCESS_MODE_EXECUTE = 0x4;
    
    /// @}

    /// The byte size of a transaction on the bus
    const int TRANSACTION_SIZE_IN_BYTES = 0x8;

    /// \enum PcbReturnCode
    ///
    /// This enumeration follows the 3-bit return code as specified in the
    /// Pervasive Workbook
    enum PcbReturnCode {
        PCB_SUCCESS           = 0,
        PCB_RESOURCE_OCCUPIED = 1,
        PCB_CHIPLET_OFFLINE   = 2,
        PCB_PARTIAL_GOOD      = 3,
        PCB_ADDRESS_ERROR     = 4,
        PCB_CLOCK_ERROR       = 5,
        PCB_PACKET_ERROR      = 6,
        PCB_TIMEOUT           = 7
    };


    /// \enum OciReturnCode
    ///
    /// These return codes are abstractions; The OCI_BUS_ERROR is a catch-all
    /// for now.
    enum OciReturnCode {
        OCI_SUCCESS   = 0,
        OCI_BUS_ERROR = 1
    };
};


/// PORE abstract transaction
///
/// This abstract transaction model is loosely based on the Simics model of a
/// 'generic transaction', plus experience from the PMX model.  It takes
/// advantage of the fact that (currently) both the PIB and OCI interfaces use
/// 32-bit addresses and (maximum) 8-byte data.  The Pore model supports
/// separate interfaces for PIB and OCI, and the base Transaction is an
/// abstract class that is subclassed for PIB and OCI error reporting
/// purposes.
///
/// The Transaction is part of the pure abstract PORE model, and is not tied
/// to any particular virtual environment.  The Transaction is originaly
/// generated within the PoreModel, moves through the virtual environment, and
/// eventually returns to the PoreModel with read data (for reads) and return
/// codes.  For simplicity all of the data members are declared public, and
/// comments with the members indicate which system element is responsible for
/// setting them and when.

class 
vsbe::Transaction {

public:

    ///////////////////////// Abstract Interface /////////////////////////

    /// Install \a i_me as the \a modelError field of the transaction and also
    /// insert a bus-model specific error code.
    ///
    /// \param[in] i_me The ModelError associated with this generic bus error.
    /// If \a i_me != ME_SUCCESS (0) then this method sets a bus-specific
    /// error code in the transaction.  If \a i_me == ME_SUCCESS (0) then this
    /// method clears the bus-specific error code in the transaction.
    /// 
    /// This method allows the common Bus model or memory models to signal a
    /// generic catostrophic error (e.g., no slave or installed memory maps
    /// the address) without knowing the derived type of the Transaction.  The
    /// \a i_me provides as a more descriptive reason for the bus error.
    ///
    /// \retval i_me This method returns its input parameter, \a i_me.
    virtual ModelError
    busError(const ModelError i_me) = 0;

    ////////////////////////////// Creators //////////////////////////////

    Transaction();
    virtual ~Transaction();

    ////////////////////////// Implementation ////////////////////////////

    /// The access mode (one of the MODE_* constants) set by PoreModel when
    /// the transaction is mastered.
    int iv_mode;

    /// The 32-bit physical bus address, set by PoreModel when the transaction
    /// is mastered.
    uint32_t iv_address;

    /// The 64-bit data, set by PoreModel for writes, and by the virtual
    /// environment for reads.
    ///
    /// Data is manipulated by the PORE models in host byte order.  The memory
    /// models must translate host byte order to and from Big-Endian ordering
    /// used in the PORE memory implementations.  This implies that for
    /// transaction sizes less than 8 bytes (which are all transactions for
    /// now), the data is right justified in the data field, and can be
    /// interpreted as if the hardware had loaded or stored an unsigned
    /// integer of the given \a size.
    uint64_t iv_data;

    /// A PORE model error code
    ///
    /// The virtual environment is responsible for setting the \a modelError
    /// for every transaction to a value selected from the ModelError
    /// enumeration.
    ModelError iv_modelError;

    /// The address offset within the bus slave
    ///
    /// This field is added for the convenience of bus/slave models.  It is
    /// designed as a place for the bus/slave model to store the offset of the
    /// addressed register/memory from a base address of a memory region or
    /// set of registers.  The PORE bus masters ignore this field.  The PORE
    /// bus slaves expect the environment to set this before sending a
    /// Transaction into the PIB and OCI slaves.
    uint32_t iv_offset;

    ///////////////////////////// Safety //////////////////////////////////

private:
    Transaction(const Transaction& rhs);
    Transaction& operator=(const Transaction& rhs);

};


/// Refine the Transaction for PIB/PCB-specific error reporting

class 
vsbe::PibTransaction : public vsbe::Transaction {

public:

    ///////////////////////// Abstract Interface /////////////////////////

    /// For the PIB bus, a bus error is treated as a PCB_TIMEOUT.  See
    /// Transaction::busError() for further details.
    virtual ModelError busError(const ModelError i_me);

    ////////////////////////////// Creators //////////////////////////////

    PibTransaction();
    virtual ~PibTransaction();

    ////////////////////////// Implementation ////////////////////////////

    /// The PIB/PCB return code associated with the transaction, set by the
    /// memory subsystem on every operation.
    PcbReturnCode iv_pcbReturnCode;

    ///////////////////////////// Safety //////////////////////////////////

private:
    PibTransaction(const PibTransaction& rhs);
    PibTransaction& operator=(const PibTransaction& rhs);
};


/// Refine the Transaction for OCI-specific error reporting

class 
vsbe::OciTransaction : public vsbe::Transaction {

public:

    ///////////////////////// Abstract Interface /////////////////////////

    /// For the OCI bus, a bus error is treated as the generic OCI_BUS_ERROR.
    /// See Transaction::busError() for further details.
    virtual ModelError busError(const ModelError i_me);

    ////////////////////////////// Creators //////////////////////////////

    OciTransaction();
    virtual ~OciTransaction();

    ////////////////////////// Implementation ////////////////////////////

    /// The OCI return code associated with the transaction, set by the
    /// memory subsystem on every operation.
    OciReturnCode iv_ociReturnCode;

    ///////////////////////////// Safety //////////////////////////////////

private:
    OciTransaction(const OciTransaction& rhs);
    OciTransaction& operator=(const OciTransaction& rhs);
};

#endif  // __VSBE_TRANSACTION_H
