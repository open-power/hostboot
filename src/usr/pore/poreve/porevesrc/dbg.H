/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/dbg.H $                         */
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
#ifndef __VSBE_POREVEDBG_H
#define __VSBE_POREVEDBG_H

// $Id: dbg.H,v 1.2 2011/06/03 19:50:19 jeshua Exp $

/// \file dbg.H
/// \brief The PORE Virtual Environment - Debugged

#include "poreve.H"

namespace vsbe {
    class PoreVeDbg;
};


////////////////////////////////////////////////////////////////////////////
// PoreVeDbg
////////////////////////////////////////////////////////////////////////////

/// The PoreVe Debug configuration
///
/// This derivation from PoreVe supports the Tcl debug environment for
/// PoreVe. The constructor takes an extra argument which is a character
/// string containing the name of a script (file) to run when the debugger
/// starts. 

class
vsbe::PoreVeDbg : public vsbe::PoreVe {

public:

    ////////////////////////////// Creators //////////////////////////////

    /// Construct the PoreVeDbg
    ///
    /// \param[in] i_id The PORE IBUF_ID (engine type) of the Pore component.
    /// This will be PORE_SBE for host boot/SBE applications, and PORE_SLW for
    /// testing Sleep/Winkle applications. 
    ///
    /// \param[in] i_masterTarget  The fapi::Target associated with the master
    /// chip in an HBI master/slave configuration.  This target is also
    /// installed into \a iv_slaveTarget by the constructor.
    ///
    /// \param[in] i_arg A private argument for the created model.  In the
    /// case of this debugged model this is a character string naming a script
    /// to be run when the debugger starts.
    PoreVeDbg(const PoreIbufId i_id, 
              const fapi::Target i_masterTarget,
              const void* i_arg);

    virtual ~PoreVeDbg();


    ////////////////////  Simulation Interface    /////////////////////////

    /// See PoreModel::run()
    ///
    /// This API is provided as a convenience.  Currently the only model in
    /// the system that is 'clocked' is the PoreModel.
    virtual int
    run(const uint64_t i_instructions, uint64_t& o_ran);


    ////////////////////  Public Implementation ////////////////////////////

    /// PoreVeDbg is a singleton class, and this is the singleton instance.
    static PoreVeDbg* cv_instance;


    //////////////////// Protected Implementation //////////////////////////

protected:

    /// The argument passed at creation
    char* iv_arg;

    /// Used by the run() method.  
    ///
    /// The first time run() is called on the debug model the debugging
    /// environment is initialized and any script specified at creation is
    /// executed. 
    bool iv_initialized;

    
    ///////////////////////////// Safety //////////////////////////////////

private:
    PoreVeDbg(const PoreVeDbg& i_rhs);
    PoreVeDbg& operator=(const PoreVeDbg& i_rhs);
};

#endif  // __VSBE_POREVEDBG_H
