/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/pibmem.H $                      */
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
#ifndef __VSBE_PIBMEM_H
#define __VSBE_PIBMEM_H

// $Id: pibmem.H,v 1.3 2013/11/27 21:23:21 thi Exp $

/// \file pib2mem.H
/// \brief A model of the P8 "PIB-attached Memory"
///
/// PIBMEM is a PIB-attached memory that provides direct SCOM access to its
/// memory array starting at PIB local address 0, as well as indirect
/// addressing modes through control/data registers at offset 0x8000.
/// Addressing modes include simple indirect addressing as well as
/// configurable pre/post increment/decrement addressing.
///
/// Pibmem is derived from PibMemory - which provides the low-level
/// configuration and memory accesses.  This model extends PibMemory by the
/// addition of a set of control and status registers.
///
/// \todo Nail down why the spec. has separate error bits for illegal
/// addresses, and non-read(write)able addresses.

#include "bebits.H"
#include "bus.H"

namespace vsbe {
    
    class Pibmem;
    
    // PIBMEM register offsets

    const uint32_t PIBMEM_CONTROL_BASE = 0x8000;

    const uint32_t PIBMEM_CONTROL  = 0x8000;
    const uint32_t PIBMEM_ADDRESS  = 0x8001;
    const uint32_t PIBMEM_DATA     = 0x8002;
    const uint32_t PIBMEM_DATA_INC = 0x8003;
    const uint32_t PIBMEM_DATA_DEC = 0x8004;
    const uint32_t PIBMEM_STATUS   = 0x8005;
    const uint32_t PIBMEM_RESET    = 0x8006;
    const uint32_t PIBMEM_REPAIR   = 0x8007;

    /// The PIBMEM maps this many SCOM addresses, including its control space
    const uint32_t PIBMEM_PIB_SIZE = 0x8008;

    /// The value to write to control.reset_code to cause a reset.
    const uint32_t PIBMEM_RESET_CODE = 2;
    
    /// The encoding of the PIBMEM FSM idle state
    const uint32_t PIBMEM_FSM_IDLE = 0x40;


    /// The Pibmem control register controls auto inc/dec modes
    typedef union {
        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t auto_pre_increment : 1;
            uint64_t auto_post_decrement : 1;
            uint64_t reserved : 62;
#else 
            uint64_t reserved : 62;    
            uint64_t auto_post_decrement : 1;
            uint64_t auto_pre_increment : 1;
#endif
        } fields;
    } PibmemControl;

    const uint64_t PIBMEM_CONTROL_DEFINED = BE64_MASK(0, 1);


    /// The Pibmem address register only defines 16 address bits
    typedef union {
        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t reserved : 48;
            uint64_t address_pointer : 16;
#else 
            uint64_t address_pointer : 16;
            uint64_t reserved : 48;
#endif
        } fields;
    } PibmemAddress;

    const uint64_t PIBMEM_ADDRESS_DEFINED = BE64_MASK(48, 63);


    /// We model the PIBMEM status register, except for the ECC error bits and
    /// the FSM state (which always reports as IDLE in this model).  The
    /// status register is read-only, and only reset by a hard reset.
    typedef union {
        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t addr_invalid : 1;
            uint64_t write_invalid : 1;
            uint64_t read_invalid : 1;
            uint64_t ecc_uncorrected_error : 1;
            uint64_t ecc_corrected_error : 1;
            uint64_t bad_array_address : 1;
            uint64_t reserved0 : 5;
            uint64_t fsm_present_state : 7;
            uint64_t reserved1 : 46;
#else 
            uint64_t reserved1 : 46;
            uint64_t fsm_present_state : 7;
            uint64_t reserved0 : 5;
            uint64_t bad_array_address : 1;
            uint64_t ecc_corrected_error : 1;
            uint64_t ecc_uncorrected_error : 1;
            uint64_t read_invalid : 1;
            uint64_t write_invalid : 1;
            uint64_t addr_invalid : 1;
#endif
        } fields;
    } PibmemStatus;


    /// The 'reset_code' must be written with 0b10 to reset the memory
    typedef union {
        uint64_t value;
        struct {
#ifdef _BIG_ENDIAN
            uint64_t reset_code : 2;
            uint64_t reserved1 : 62;
#else 
            uint64_t reserved : 62;
            uint64_t reset_code : 2;
#endif
        } fields;
    } PibmemReset;

    const uint64_t PIBMEM_RESET_DEFINED = BE64_MASK(0, 1);
}


class
vsbe::Pibmem : public PibMemory {

public:

    ////////////////////////////// Creators //////////////////////////////

    /// Pibmem constructor
    ///
    /// \param[in] i_memorySize The maximum size of the memory in units of
    /// 8-byte doublewords.
    Pibmem(const size_t i_memorySize);

    virtual ~Pibmem();


    //////////////////////////// Manipulators ////////////////////////////

    /// Pibmem operation
    ///
    /// \param[in,out] io_transaction A PIB transaction object
    ///
    /// Read/write of addresses below the control range are direct SCOM access
    /// to the PIBMEM memory itself.  Indirect accesses use the indirect
    /// address and data register. 
    ///
    /// \retval rc A fapi::ReturnCode denoting success or a problem.
    fapi::ReturnCode
    operation(Transaction& io_transaction);


    //////////////////// Implementation  //////////////////////////////////

protected:

    /// Implements the PIBMEM reset sequence - all state is cleared
    void reset();

    /// Pibmem memory read/write operation
    ///
    /// \param[in,out] io_transaction A PIB transaction object
    ///
    /// \param[in] i_direct Indicates whether this is a direct or indirect
    /// access (for error reporting).  For indirect access the address comes
    /// from the address register.
    ///
    /// \retval rc A fapi::ReturnCode denoting success or a problem.
    fapi::ReturnCode memoryOperation(Transaction& io_transaction, 
                                     const bool i_direct);

    /// Increment/decrement the indirect address register
    ///
    /// \param[in] i_incr The (signed) increment/decrement
    void incrAddress(const int i_incr);

    /// The size of the memory in units of 8-byte doublewords
    uint32_t iv_memorySize;

    // Control/status register state.  Data registers have no substructure.

    PibmemControl iv_control;
    PibmemAddress iv_address;
    PibmemStatus iv_status;
    PibmemReset iv_reset;

    uint64_t iv_data, iv_dataInc, iv_dataDec, iv_repair;


    ///////////////////////////// Safety //////////////////////////////////

private:
    Pibmem(const Pibmem& rhs);
    Pibmem& operator=(const Pibmem& rhs);
};

/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */

#endif  // __VSBE_PIBMEM_H
