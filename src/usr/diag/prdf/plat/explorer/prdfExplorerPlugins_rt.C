/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/explorer/prdfExplorerPlugins_rt.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfMemDbUtils.H>
#include <prdfMemEccAnalysis.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace explorer_ocmb
{

//##############################################################################
//
//                                 SRQFIR
//
//##############################################################################

/**
 * @brief  SRQFIR[4] - RCD Parity Error.
 * @param  i_chip An OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t RcdParityError( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[explorer_ocmb::RcdParityError] "

    // The callouts have already been made in the rule code. All other actions
    // documented below.

    uint32_t l_rc = SUCCESS;

    // Check FARB0[54] to see if RCD recovery is disabled or not.
    SCAN_COMM_REGISTER_CLASS * farb0 = i_chip->getRegister( "FARB0" );
    l_rc = farb0->Read();
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on FARB0");

        // Ensure the reg is zero so that we will use the recovery threshold and
        // guarantee we don't try to do a reconfig.
        farb0->clearAllBits();
    }

    // Increment the RCD parity error count, set predictive at threshold.
    if ( getOcmbDataBundle(i_chip)->iv_rcdParityTh.inc(io_sc) )
        io_sc.service_data->setServiceCall();

    // FARB0[54] = 1, RCD recovery disabled
    if (farb0->IsBitSet(54))
    {
        // FARB[54] should not be set at runtime, print an error.
        PRDF_ERR( PRDF_FUNC "FARB0[54] set at runtime" );
    }
    // FARB0[54] = 0, RCD recovery enabled
    else
    {
        // Trigger TPS on all ranks at threshold to quickly find any AUE
        // that may have resulted in a possible double bit flip that evaded
        // the parity check.
        if (getOcmbDataBundle(i_chip)->iv_rcdParityTh.thReached(io_sc))
        {
            std::vector<MemRank> list;
            getSlaveRanks<TYPE_OCMB_CHIP>( i_chip->getTrgt(), list );
            PRDF_ASSERT( !list.empty() ); // target configured with no ranks

            for ( const auto & r : list )
            {
                TdEntry * entry = new TpsEvent<TYPE_OCMB_CHIP>( i_chip, r );
                MemDbUtils::pushToQueue<TYPE_OCMB_CHIP>( i_chip, entry );
                uint32_t rc = MemDbUtils::handleTdEvent<TYPE_OCMB_CHIP>(i_chip,
                                                                        io_sc);
                if ( SUCCESS != rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleTdEvent() failed on 0x%08x",
                              i_chip->getHuid() );
                    continue; // Try the other ranks.
                }
            }
        }
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE(explorer_ocmb, RcdParityError);

} // end namespace explorer_ocmb

} // end namespace PRDF

