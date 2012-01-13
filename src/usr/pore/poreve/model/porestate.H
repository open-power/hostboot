//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/model/porestate.H $
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
#ifndef __VSBE_PORE_STATE_H
#define __VSBE_PORE_STATE_H

// $Id: porestate.H,v 1.1 2011/06/12 13:14:03 bcbrock Exp $

/// \file porestate.H
/// \brief A structure defining the state of a PORE engine for
/// checkpoint/restart purposes.

#include "poreinterface.H"

namespace vsbe {
    
    class PoreState;
};


/// The state of a PORE engine
///
/// The PoreState class represents the state of the PORE engine for
/// checkpoint/restore purposes.  The state is stored as an endian-neutral
/// checkpoint of the register space of the PORE engine, therefore the object
/// can be saved and restored to/from a file regardless of the endianess of
/// the save and restore hosts. Methods are provided to access the hardware
/// register images using the PoreRegisterOffset enumeration offsets.
///
/// This object is used as a parameter of the PoreInterface::extractState()
/// and poreInterface::installState() methods.  Please see the documentation
/// of those methods for information on how the PoreState is checkpointed and
/// restored.

class
vsbe::PoreState {

public:

    ////////////////////////////// Creators //////////////////////////////

    PoreState();

    virtual ~PoreState();


    ///////////////////////////// Accessors //////////////////////////////

    /// Get a register image from the state
    ///
    /// \param[in] i_offset The PoreRegisterOffset of the requested register.
    ///
    /// \param[out] o_reg The requested register value obtained from the state.
    ///
    /// \retval me Either 0 for success, or a ModelError error code.
    virtual ModelError
    get(const PoreRegisterOffset i_offset, uint64_t& o_reg) const;


    ///////////////////////////// Manipulators ///////////////////////////

    /// Put a register image into the state
    ///
    /// \param[in] i_offset The PoreRegisterOffset of the requested register.
    ///
    /// \param[in] i_reg The new value of the requested register to store in
    /// the state. value. 
    ///
    /// \retval me Either 0 for success, or a ModelError error code.
    virtual ModelError
    put(const PoreRegisterOffset i_offset, const uint64_t i_reg);


    ////////////////////////// Implementation ////////////////////////////

protected:

    /// The register state
    uint8_t state[SIZEOF_PORE_STATE];


    ///////////////////////////// Safety //////////////////////////////////

private:
    PoreState(const PoreState& rhs);
    PoreState& operator=(const PoreState& rhs);
};

#endif  // __VSBE_PORE_STATE
