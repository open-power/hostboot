/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimHomRegisterAccess.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#include "prdfsimHomRegisterAccess.H"
#include "prdfsimServices.H"
#include "prdfsimScrDB.H"
#include <prdfTrace.H>

namespace PRDF
{

SimScomAccessor::SimScomAccessor()
: ScomAccessor()
{}

SimScomAccessor::~SimScomAccessor()
{

}

errlHndl_t SimScomAccessor::Access(TARGETING::TargetHandle_t i_target,
                                     BIT_STRING_CLASS & bs,
                                     uint64_t registerId,
                                     MopRegisterAccess::Operation operation) const
{
    PRDF_DENTER("SimScomAccessor::Access()");
    errlHndl_t errlH = NULL;
    ScrDB::SimOp l_op = ScrDB::MAX_OP;

    do
    {
        switch (operation)
            {
        case MopRegisterAccess::WRITE: l_op = ScrDB::WRITE; break;
        case MopRegisterAccess::READ:  l_op = ScrDB::READ;  break;
        default:
            PRDF_ERR( "SimScomAccessor::Access() unsupported operation: 0x%X", operation );
            break;
            }
        getSimServices().processCmd(i_target, bs, registerId, l_op);

    } while(0);

    PRDF_DEXIT("SimScomAccessor::Access()");

    return errlH;
}

} // End namespace PRDF
