/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9OcmbChipDomain.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
 * @file prdfP9OcmbChipDomain.C
 * @brief chip Plug-in code for OCMB domain
 */

#include <prdfP9OcmbChipDomain.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <prdfOcmbDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

#ifdef __HOSTBOOT_RUNTIME
void OcmbChipDomain::handleRrFo()
{
    #define PRDF_FUNC "[OcmbChipDomain::handleRrFo] "

    do
    {
        uint32_t domainSize = GetSize();
        // Iterate all OCMBs in the domain.
        for ( uint32_t i = 0; i < domainSize; ++i )
        {
            RuleChip * ocmbChip = LookUp(i);

            // Start background scrub if required.
            OcmbDataBundle * ocmbdb = getOcmbDataBundle( ocmbChip );
            int32_t l_rc = ocmbdb->getTdCtlr()->handleRrFo();
            if ( SUCCESS != l_rc )
            {
                // Let us not fail here. If problem is contained within an OCMB
                // we will discover it again during normal TD procedures.
                PRDF_ERR( PRDF_FUNC "handleRrFo() failed: OCMB=0x%08x",
                          ocmbChip->GetId() );
                continue; // Keep going.
            }
        }

    } while (0);

    #undef PRDF_FUNC
}
#endif

} // end namespace PRDF
