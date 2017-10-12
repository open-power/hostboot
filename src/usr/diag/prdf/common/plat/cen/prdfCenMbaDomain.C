/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/cen/prdfCenMbaDomain.C $        */
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
 * @file prdfCenMbaDomain.C
 * @brief chip Plug-in code for mcbist domain
 */

#include <prdfCenMbaDomain.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#ifdef __HOSTBOOT_RUNTIME
#include <prdfCenMbaDataBundle.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

#ifdef __HOSTBOOT_RUNTIME
void MbaDomain::handleRrFo()
{
    #define PRDF_FUNC "[MbaDomain::handleRrFo] "

    do
    {
        uint32_t domainSize = GetSize();
        // Iterate all MBAs in the domain.
        for ( uint32_t i = 0; i < domainSize; ++i )
        {
            RuleChip * mbaChip = LookUp(i);

            // Start background scrub if required.
            MbaDataBundle * mbadb = getMbaDataBundle( mbaChip );
            int32_t l_rc = mbadb->getTdCtlr()->handleRrFo();
            if ( SUCCESS != l_rc )
            {
                // Let us not fail here. If problem is contained within a MBA
                // we will discover it again during normal TD procedures.
                PRDF_ERR( PRDF_FUNC "handleRrFo() failed: MBA=0x%08x",
                          mbaChip->GetId() );
                continue; // Keep going.
            }
        }

    } while (0);

    #undef PRDF_FUNC
}
#endif

} // end namespace PRDF
