/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/sbevital.C $                    */
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
