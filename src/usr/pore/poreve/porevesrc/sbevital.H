/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/sbevital.H $                    */
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
#ifndef __VSBE_SBEVITAL_H
#define __VSBE_SBEVITAL_H

// $Id: sbevital.H,v 1.1 2011/09/19 00:25:32 jeshua Exp $

/// \file sbevital.H
/// \brief A hack to intercept scan operations and make them broadside

#include "bus.H"

namespace vsbe {
    
    class SbeVital;
    
    /// PIB base address of PIB range mapped by SbeVital
    const uint32_t SBEVITAL_PIB_BASE = 0x0005001C;

    /// Number of PIB addresses mapped by SbeVital
    const int SBEVITAL_PIB_SIZE = 1;

}


/// Map PIB accesses to CFAM accesses

class
vsbe::SbeVital : public PibSlave {

public:

    ////////////////////////////// Creators //////////////////////////////

    SbeVital();

    virtual ~SbeVital();


    //////////////////////////// Manipulators ////////////////////////////

    /// SbeVital operation
    ///
    /// \param[in,out] io_transaction A PIB transaction object
    ///
    /// This object converts PIB transactions in a certain range in the
    /// virtual environment to broadside getRing and putRing operations,
    /// returning the FAPI return code from the translated calls.
    ///
    /// \retval rc The fapi::ReturnCode returned by the underlying
    /// getRing() or putRing() call.
    fapi::ReturnCode
    operation(Transaction& io_transaction);


    ///////////////////////////// Safety //////////////////////////////////

private:
    SbeVital(const SbeVital& rhs);
    SbeVital& operator=(const SbeVital& rhs);

    uint32_t iv_data;
};

#endif  // __VSBE_SBEVITAL_H
