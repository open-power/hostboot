/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/porevesrc/create.C $                      */
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
// $Id: create.C,v 1.4 2013/11/27 19:57:47 thi Exp $
/// \file create.C
/// \brief The create method for PoreVe
///
/// The PoreVe class declares a static create() method that allows link-time
/// selection of a normal vs. debug version of PoreVe.  This is similar to the
/// same idea used to make a link-time selection of the Pore hardware model
/// (PMX vs. BOE).  This create() method is linked into the poreve.so.  The
/// create() method for PoreVeDbg is defined in dbg.C

#include "poreve.H"

using namespace vsbe;

PoreVe*
PoreVe::create(const PoreIbufId i_id, 
               const fapi::Target i_masterTarget,
               const void* i_arg)
{
    return new PoreVe(i_id, i_masterTarget);
}

