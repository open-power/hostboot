//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/porevesrc/sbevital.C $
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: sbevital.C,v 1.1 2011/09/19 00:25:32 jeshua Exp $

/// \file sbevital.C
/// \brief A temporary hack to create the SBE vital reg before HW has it
///
#ifdef VBU_HACKS

#include "sbevital.H"
#include "fapiSharedUtils.H"
#include "ecmdUtils.H"
using namespace vsbe;


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
    fapi::ReturnCode rc=0;
    ModelError       me;

    FAPI_INF("In sbeVital\n");

    //On a ring write, put the data into the ring
    if( io_transaction.iv_mode == ACCESS_MODE_WRITE)
    {
        iv_data = io_transaction.iv_data >> 32;
        me = ME_SUCCESS;
    }
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
#endif
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
