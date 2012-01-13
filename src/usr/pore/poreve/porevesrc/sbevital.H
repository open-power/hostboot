//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/porevesrc/sbevital.H $
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
