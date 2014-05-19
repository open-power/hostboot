/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/transaction.C $                     */
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
