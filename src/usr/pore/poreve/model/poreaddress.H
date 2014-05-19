/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/poreaddress.H $                     */
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
#ifndef __VSBE_POREADDRESS_H
#define __VSBE_POREADDRESS_H

// $Id: poreaddress.H,v 1.2 2012/01/06 21:25:15 bcbrock Exp $

/// \file poreaddress.H
/// \brief A simple abstract PORE address that separates the memory space from
/// the offset.

#include <stdint.h>

namespace vsbe {

    class PoreAddress;
}


////////////////////////////////////////////////////////////////////////////
// PoreAddress
////////////////////////////////////////////////////////////////////////////

/// A PORE address
///
/// PORE implements a segmented memory architecure.  An address consists of a
/// 16-bit memory space identifier and a 32-bit byte offset within the memory
/// space.  The memory space identifer denotes the physical memory interface
/// used for the memory (PIB or OCI).  For PIB addresses, the memory space
/// also encodes direct vs. indirect memory access protocols.
///
/// Inside the PORE the memory space Id is held in the 16 high-order bits of
/// the program counter.  Relative branches and relative subroutine branches
/// do not modify the memory space.  All other branches, including immediate
/// branches, indirect (dereferenced) branches and return from subroutine
/// update the entire 48-bit PC, and hence change the default memory space.
///
/// The address registers also include an incomplete memory space field; the
/// field is incomplete because it does not include the PIB/Memory bit which
/// is implied. These memory space Ids are set by loading the registers.  The
/// address register memory spaces are only valid for the SBE engine; for all
/// of the OCI-attached PORE engines the address registers only allow OCI
/// access and ignore the memory space Id.
///
/// Since this is a simple type (equivalent to a uint64_t) we allow the
/// compiler to create the copy and assignment operators for the class. 

class 
vsbe::PoreAddress {

public:

    ////////////////////////////// Creators //////////////////////////////

    /// Construct an uninitialized PoreAddress
    PoreAddress ();

    /// Construct a PoreAddress from a memory space Id + offset
    ///
    /// \param[in] i_memorySpace The 16-bit memory space descriptor
    ///
    /// \param[in] i_offset The 32-bit byte address within the memory space
    PoreAddress(uint16_t i_memorySpace, uint32_t i_offset);

    /// Construct a PoreAddress from a right-justified uint64_t
    ///
    /// \param[in] i_address;
    PoreAddress(uint64_t i_address);

    ~PoreAddress();

    //////////////////////////// Operators    ////////////////////////////

    /// Convert a PoreAddress to a uint64_t
    operator uint64_t () const;

    //////////////////////////// Manipulators ////////////////////////////

    /// Convert a PIB address into a PoreAddress
    ///
    /// \param[in] i_pibAddress Assumed to be the PIB address of a location in
    /// a direct access PIB memory, the address is converted to the equivalent
    /// PORE address form
    ///
    /// \retval address A reference to the object
    PoreAddress& setFromPibAddress(uint32_t i_pibAddress);

    ////////////////////////// Implementation ////////////////////////////

    /// The byte offset within the memory space
    uint32_t iv_offset;

    /// The memory space identifier
    uint16_t iv_memorySpace;
};

#endif  // __VSBE_POREADDRESS_H
