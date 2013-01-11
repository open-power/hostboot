/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/pib2cfam.H $                    */
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
#ifndef __VSBE_PIB2CFAM_H
#define __VSBE_PIB2CFAM_H

// $Id: pib2cfam.H,v 1.4 2013/01/11 15:53:49 thi Exp $

/// \file pib2cfam.H
/// \brief A temporary hack while waiting for hardware updates - a simple
/// PibSlave that maps a small range of PIB addresses to CFAM addresses.

#include "bus.H"

namespace vsbe {
    
    class Pib2Cfam;
    
    /// PIB base address of PIB range mapped by Pib2Cfam
    const uint32_t PIB2CFAM_PIB_BASE = 0x00050007;

    /// Number of PIB addresses mapped by Pib2Cfam
    const int PIB2CFAM_PIB_SIZE = ((0x0005001b - 0x00050007) + 1);
}


/// Map PIB accesses to CFAM accesses

class
vsbe::Pib2Cfam : public PibSlave {

public:

    ////////////////////////////// Creators //////////////////////////////

    Pib2Cfam();

    virtual ~Pib2Cfam();


    //////////////////////////// Manipulators ////////////////////////////

    /// Pib2Cfam operation
    ///
    /// \param[in,out] io_transaction A PIB transaction object
    ///
    /// This object converts PIB transactions in a certain range in the
    /// virtual environment to FAPI PutCfamregister() and GetCfamRegister()
    /// calls, returning the FAPI return code from the translated calls.
    ///
    /// The following PIB registers are mapped to CFAM registers:
    ///
    /// - PIB 0x00050007 -> CFAM 0x1007, FSI2PIB.STATUS, R
    /// - PIB 0x00050012 -> CFAM 0x1012, FSIGP3, R/W
    /// - PIB 0x00050013 -> CFAM 0x1013, FSIGP4, R/W
    /// - PIB 0x00050014 -> CFAM 0x1014, FSIGP5, R/W
    /// - PIB 0x00050015 -> CFAM 0x1015, FSIGP6, R/W
    /// - PIB 0x00050016 -> CFAM 0x1016, FSIGP7, R/W
    /// - PIB 0x00050019 -> CFAM 0x1019, OSC switch sense 1, R 
    /// - PIB 0x0005001A -> CFAM 0x101A, OSC switch sense 2, R 
    /// - PIB 0x0005001B -> CFAM 0x101B, GP3 Mirror, R/W
    ///
    /// \retval rc The fapi::ReturnCode returned by the underlying
    /// PutCfamRegister() or GetCfamRegister() call.
    fapi::ReturnCode
    operation(Transaction& io_transaction);


    ///////////////////////////// Safety //////////////////////////////////

private:
    Pib2Cfam(const Pib2Cfam& rhs);
    Pib2Cfam& operator=(const Pib2Cfam& rhs);
};

#endif  // __VSBE_PIB2CFAM_H
