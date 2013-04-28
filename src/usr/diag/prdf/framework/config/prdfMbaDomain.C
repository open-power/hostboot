/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/config/prdfMbaDomain.C $          */
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

#include <prdfMbaDomain.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

// Pegasus includes
#include <prdfCenMbaDataBundle.H>

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
        // Iterate all MBAs in the domain.
        for ( uint32_t i = 0; i < GetSize(); ++i )
        {
            RuleChip * mbaChip = LookUp(i);

            // Start background scrub
            CenMbaDataBundle * mbadb = getMbaDataBundle( mbaChip );
            int32_t l_rc = mbadb->iv_tdCtlr.startInitialBgScrub();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC"startInitialBgScrub() failed: MBA=0x%08x",
                          mbaChip->GetId() );
                o_rc = FAIL; continue; // Keep going.
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF

