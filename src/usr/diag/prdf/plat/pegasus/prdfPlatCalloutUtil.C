/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCalloutUtil.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/** @file prdfPlatCalloutUtil.C */

#include <prdfPlatCalloutUtil.H>

// Framework includes
#include <prdfErrlUtil.H>
#include <prdfPfa5Data.h>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfMemoryMru.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CalloutUtil
{

void calloutMemoryMru( errlHndl_t io_errl, const MemoryMru & i_memmru,
                       const HWAS::callOutPriority i_priority,
                       const HWAS::DeconfigEnum    i_deconfigState,
                       const HWAS::GARD_ErrorType  i_gardType )
{
    // Add all parts to the error log.
    TargetHandleList partList = i_memmru.getCalloutList();
    for ( TargetHandleList::iterator it = partList.begin();
          it != partList.end(); it++ )
    {
        io_errl->addHwCallout( *it, i_priority, i_deconfigState, i_gardType );
    }

    // Add the MemoryMru to the capture data.
    uint32_t tmpMru = i_memmru.toUint32();
    PRDF_ADD_FFDC( io_errl, &tmpMru, sizeof(tmpMru), ErrlVer1, ErrlMruData_1 );
}

} // end namespace CalloutUtil

} // end namespace PRDF

