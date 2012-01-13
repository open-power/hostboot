//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/poreve/model/transaction.C $
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
// $Id: transaction.C,v 1.1 2011/05/06 23:29:00 bcbrock Exp $

/// \file transaction.C
/// \brief PORE abstract bus transactions

#include "transaction.H"

using namespace vsbe;


// There are no 'obvious' constructors for these classes; Likely the PORE
// model will build one of each type and resuse it over and over, changing the
// fields on each use.

Transaction::Transaction()
{
}


Transaction::~Transaction()
{
}


PibTransaction::PibTransaction()
{
}


PibTransaction::~PibTransaction()
{
}


ModelError
PibTransaction::busError(ModelError i_me) 
{
    iv_modelError = i_me;
    if (i_me == ME_SUCCESS) {
        iv_pcbReturnCode = PCB_SUCCESS;
    } else {
        iv_pcbReturnCode = PCB_TIMEOUT;
    }
    return i_me;
}


OciTransaction::OciTransaction()
{
}


OciTransaction::~OciTransaction()
{
}


ModelError
OciTransaction::busError(ModelError i_me) 
{
    iv_modelError = i_me;
    if (i_me == ME_SUCCESS) {
        iv_ociReturnCode = OCI_SUCCESS;
    } else {
        iv_ociReturnCode = OCI_BUS_ERROR;
    }
    return i_me;
}
