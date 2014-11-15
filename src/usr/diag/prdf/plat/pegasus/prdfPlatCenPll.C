/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCenPll.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

/** @file  prdfPlatCenPLL.C
 *  @brief Contains all Hostboot-only plugin code for the Centaur PLL logic.
 */

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>
#include <prdfPlatServices.H>
#include <prdfCenMemUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Membuf
{

/**
 * @brief  Optional plugin function called after analysis is complete but
 *         before PRD exits.
 * @param  i_cenChip A Centaur MBA chip.
 * @param  i_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PllPostAnalysis( ExtensibleChip * i_cenChip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    #define PRDF_FUNC "[Membuf::PllPostAnalysis] "

    int32_t o_rc = SUCCESS;


    do
    {
        // need to clear associated bits in the MCIFIR bits.
        o_rc = MemUtils::mcifirCleanup( i_cenChip, i_sc );
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mcifirCleanup() failed");
            break;
        }

        // Check to make sure we are at threshold and have something garded.
        if ( !i_sc.service_data->IsAtThreshold() ||
             (GardAction::NoGard == i_sc.service_data->QueryGard()) )
        {
            break; // nothing to do
        }

        #ifndef __HOSTBOOT_RUNTIME

        TargetHandle_t cenTrgt = i_cenChip->GetChipHandle();
        TargetHandleList list = getConnected( cenTrgt, TYPE_MBA );
        if ( 0 == list.size() )
        {
            PRDF_ERR( PRDF_FUNC"getConnected(0x%08x, TYPE_MBA) failed",
                      getHuid(cenTrgt) );
            o_rc = FAIL; break;
        }

        // Send SKIP_MBA message for each MBA.
        for ( TargetHandleList::iterator mbaIt = list.begin();
              mbaIt != list.end(); ++mbaIt )
        {
            int32_t l_rc = mdiaSendEventMsg( *mbaIt, MDIA::SKIP_MBA );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC"mdiaSendEventMsg(0x%08x, SKIP_MBA) failed",
                          getHuid(*mbaIt) );
                o_rc |= FAIL;
                continue; // keep going
            }
        }

        #endif

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, PllPostAnalysis );

} // end namespace Membuf

} // end namespace PRDF
