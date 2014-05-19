/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/dbg.C $                         */
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
// $Id: dbg.C,v 1.3 2011/06/07 03:10:45 bcbrock Exp $

/// \file dbg.C
/// \brief The PORE Virtual Environment - Debugged
///
/// This file includes the PoreVeDbg constructor and the create() and run()
/// methods for PoreVeDbg.  The pdbg::entryPoint is left as an unresolved
/// external at link time and defined in the debugging environment code.

#include <stdio.h>
#include <string.h>
#include "dbg.H"

using namespace vsbe;

namespace pdbg {
    /// Start the \c pdbg debugger
    ///
    /// \param[in] i_instructions Currently ignored
    ///
    /// \param[out] o_ran Currently ignored
    ///
    /// \param[in] i_arg The name of a debugger script to run at
    /// initialization. 
    ///
    /// This is the entry point used to initiate the pdbg interactive
    /// debugger. It is called from the PoreVeDbg::run() method the first time
    /// that method is called. Note: pdbg::entryPoint currently doesn't
    /// return.
    int entryPoint(const uint64_t i_instructions,
                   uint64_t& o_ran,
                   const char* i_arg);
}


////////////////////////////////////////////////////////////////////////////
// PoreVeDbg
////////////////////////////////////////////////////////////////////////////

PoreVeDbg* PoreVeDbg::cv_instance = 0;


PoreVeDbg::PoreVeDbg(const PoreIbufId i_id, 
                     const fapi::Target i_masterTarget,
                     const void* i_arg) :
    PoreVe(i_id, i_masterTarget),
    iv_initialized(false)
{
    iv_arg = strdup((char*)i_arg);
    cv_instance = this;
}


PoreVeDbg::~PoreVeDbg() 
{
    free(iv_arg);
}


int
PoreVeDbg::run(const uint64_t i_instructions, uint64_t& o_ran)
{
    if (iv_initialized) {
        return PoreVe::run(i_instructions, o_ran);
    } else {
        iv_initialized = true;
        return pdbg::entryPoint(i_instructions, o_ran, iv_arg);
    }
}


PoreVe*
PoreVe::create(const PoreIbufId i_id, 
               const fapi::Target i_masterTarget,
               const void* i_arg)
{
    return new PoreVeDbg(i_id, i_masterTarget, i_arg);
}

    
        
        
        
        
        
