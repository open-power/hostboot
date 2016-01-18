/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/config/prdfMbaDomain.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

#include <prdfMbaDomain.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

// Pegasus includes
//#include <prdfCenMbaDataBundle.H> TODO RTC 136126

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

int32_t MbaDomain::startScrub()
{
    #define PRDF_FUNC "[MbaDomain::startScrub] "

    int32_t o_rc = SUCCESS;

    do
    {
/* TODO RTC 136126
        // Iterate all MBAs in the domain.
        for ( uint32_t i = 0; i < GetSize(); ++i )
        {
            RuleChip * mbaChip = LookUp(i);

            // Start background scrub
            CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );
            int32_t l_rc = mbadb->iv_tdCtlr.startInitialBgScrub();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "startInitialBgScrub() failed: MBA=0x%08x",
                          mbaChip->GetId() );
                o_rc = FAIL; continue; // Keep going.
            }
        }
*/

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF

