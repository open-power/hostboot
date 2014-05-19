/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/sbevital.C $                    */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: sbevital.C,v 1.4 2012/10/25 16:36:17 jeshua Exp $

/// \file sbevital.C
/// \brief Emulate the SBE vital register in software
///

#include "sbevital.H"
using namespace vsbe;
using namespace fapi;


////////////////////////////// Creators //////////////////////////////

SbeVital::SbeVital()
{
    iv_data = 0;
}


SbeVital::~SbeVital()
{
}


//////////////////////////// Manipulators ////////////////////////////

fapi::ReturnCode
SbeVital::operation(Transaction& io_transaction)
{
    fapi::ReturnCode rc=FAPI_RC_SUCCESS;
    ModelError       me;

    //On a scom write, put the data into the register
    if( io_transaction.iv_mode == ACCESS_MODE_WRITE)
    {
        iv_data = io_transaction.iv_data >> 32;
        me = ME_SUCCESS;
    }
    //On a scom read, get the data from the register
    else if( io_transaction.iv_mode == ACCESS_MODE_READ )
    {
        io_transaction.iv_data = ((uint64_t)(iv_data)) << 32;
        me = ME_SUCCESS;
    }
    else
    {
        me = ME_FAILURE;
    }

    io_transaction.busError(me);
    return rc;
}

/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
