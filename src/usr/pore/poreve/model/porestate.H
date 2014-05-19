/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/porestate.H $                       */
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
