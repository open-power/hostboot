/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfP9McbistDomain.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

/**
 * @file prdfP9McbistDomain.C
 * @brief chip Plug-in code for mcbist domain
 */

#include <prdfP9McbistDomain.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <prdfMemBgScrub.H>
#include <prdfP9McbistDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

#ifndef __HOSTBOOT_RUNTIME
int32_t McbistDomain::startScrub()
{
    #define PRDF_FUNC "[McbistDomain::startScrub] "

    PRDF_ENTER( PRDF_FUNC );

    int32_t o_rc = SUCCESS;

    // Iterate all MCBISTs in the domain.
    for ( uint32_t i = 0; i < GetSize(); ++i )
    {
        RuleChip * mcbistChip = LookUp(i);

        // Start background scrub
        int32_t l_rc = PRDF::startInitialBgScrub<TYPE_MCBIST>(mcbistChip);
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "startInitialBgScrub() failed: "
                    "MCBIST=0x%08x", mcbistChip->GetId() );
            o_rc = FAIL; continue; // Keep going.
        }
    }

    PRDF_EXIT( PRDF_FUNC "prdf: McbistDomain::startScrub exit" );

    return o_rc;

    #undef PRDF_FUNC
}
#endif

#ifdef __HOSTBOOT_RUNTIME
void McbistDomain::handleRrFo()
{
    #define PRDF_FUNC "[McbistDomain::handleRrFo] "

    do
    {
        uint32_t domainSize = GetSize();
        // Iterate all MCBISTs in the domain.
        for ( uint32_t i = 0; i < domainSize; ++i )
        {
            RuleChip * mcbChip = LookUp(i);

            // Start background scrub if required.
            McbistDataBundle * mcbdb = getMcbistDataBundle( mcbChip );
            int32_t l_rc = mcbdb->getTdCtlr()->handleRrFo();
            if ( SUCCESS != l_rc )
            {
                // Let us not fail here. If problem is contained within a MCBIST
                // we will discover it again during normal TD procedures.
                PRDF_ERR( PRDF_FUNC "handleRrFo() failed: MCBIST=0x%08x",
                          mcbChip->GetId() );
                continue; // Keep going.
            }
        }

    } while (0);

    #undef PRDF_FUNC
}
#endif

} // end namespace PRDF
