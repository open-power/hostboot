/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCenPll.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

    TargetHandle_t cenTrgt = i_cenChip->GetChipHandle();

    do
    {
        // Check to make sure we are at threshold and have something garded.
        if ( !i_sc.service_data->IsAtThreshold() ||
             (GardAction::NoGard == i_sc.service_data->QueryGard()) )
        {
            break; // nothing to do
        }

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

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( Membuf, PllPostAnalysis );

} // end namespace Membuf

} // end namespace PRDF
