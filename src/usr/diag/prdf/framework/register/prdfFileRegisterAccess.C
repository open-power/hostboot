/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/register/prdfFileRegisterAccess.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include "prdfFileRegisterAccess.H"
#include <prdfTrace.H>
#include <prdfPnorFirDataReader.H>
#include <prdfBitString.H>

using namespace TARGETING;

namespace PRDF
{

errlHndl_t FileScomAccessor::Access(
                            TargetHandle_t i_target,
                            BIT_STRING_CLASS & bs,
                            uint64_t registerId,
                            MopRegisterAccess::Operation operation) const
{
    #define PRDF_FUNC "[FileScomAccessor::Access()] "

    errlHndl_t errlH = NULL;

    PnorFirDataReader & firData = PnorFirDataReader::getPnorFirDataReader();
    uint64_t data = 0;

    switch (operation)
    {
        case MopRegisterAccess::WRITE:
            data = bs.GetFieldJustify(0, 64);
            firData.putScom( i_target, registerId, data);
            break;
        case MopRegisterAccess::READ:
            firData.getScom( i_target, registerId, data);
            bs.SetFieldJustify( 0, 64, data);
            break;
        default:
            PRDF_ERR(PRDF_FUNC"Wrong Operation:%u", operation);
    }

    return errlH;

    #undef PRDF_FUNC
}

} // End namespace PRDF
