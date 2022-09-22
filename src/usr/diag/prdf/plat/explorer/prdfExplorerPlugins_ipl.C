/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/explorer/prdfExplorerPlugins_ipl.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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

    // FARB0[54] = 1, i.e. RCD recovery disabled
    if (farb0->IsBitSet(54))
    {
        // If maint RCD/IRCD (RDFFIR[35,38]) are found to be on at the same
        // time, mask them so they won't be logged as a separate event.
        SCAN_COMM_REGISTER_CLASS * rdffir = i_chip->getRegister( "RDFFIR" );
        SCAN_COMM_REGISTER_CLASS * rdffir_mask_or =
            i_chip->getRegister( "RDFFIR_MASK_OR" );
        rdffir_mask_or->clearAllBits();
        l_rc = rdffir->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on RDFFIR");
        }
        else
        {
            if ( rdffir->IsBitSet(35) ) rdffir_mask_or->SetBit(35);
            if ( rdffir->IsBitSet(38) ) rdffir_mask_or->SetBit(38);
        }

        if (!rdffir_mask_or->BitStringIsZero())
        {
            l_rc = rdffir_mask_or->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_MASK_OR: "
                          "i_chip=0x%08x", i_chip->getHuid() );
            }
        }

        // Recovery is disabled. Issue a reconfig loop. Make the error log
        // predictive if threshold is reached.
        if ( rcdParityErrorReconfigLoop(i_chip->getTrgt()) )
            io_sc.service_data->setServiceCall();

        if ( isInMdiaMode() )
        {
            SCAN_COMM_REGISTER_CLASS * mask = nullptr;

            // Stop any further commands on this OCMB to avoid subsequent RCD
            // errors or potential AUEs.
            l_rc = mdiaSendEventMsg( i_chip->getTrgt(), MDIA::STOP_TESTING );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );
            }

            // Mask the maintenance AUE/IAUE attentions on this OCMB because
            // they are potential side-effects of the RCD parity errors.
            mask = i_chip->getRegister( "RDFFIR_MASK_OR" );
            mask->SetBit(33); // maintenance AUE
            mask->SetBit(36); // maintenance IAUE
            l_rc = mask->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_MASK_OR: "
                          "i_chip=0x%08x", i_chip->getHuid() );
            }

            // Mask the maintenance command complete bits to avoid false
            // attentions.
            mask = i_chip->getRegister( "MCBISTFIR_MASK_OR" );
            mask->SetBit(10); // Command complete
            l_rc = mask->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR_MASK_OR: "
                          "i_chip=0x%08x", i_chip->getHuid() );
            }
        }
    }
    // FARB0[54] = 0, i.e. RCD recovery enabled
    else
    {
        // FARB[54] should be set during IPL, print an error.
        PRDF_ERR( PRDF_FUNC "FARB0[54] not set at IPL" );

        // Increment the RCD parity error count, set predictive at threshold.
        if ( getOcmbDataBundle(i_chip)->iv_rcdParityTh.inc(io_sc) )
            io_sc.service_data->setServiceCall();
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE(explorer_ocmb, RcdParityError);

} // end namespace explorer_ocmb

} // end namespace PRDF
