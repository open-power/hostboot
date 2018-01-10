/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfP9Mca.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
#include <prdfMemEccAnalysis.H>
#include <prdfP9McaDataBundle.H>
#include <prdfP9McbistDataBundle.H>
#include <prdfPlatServices.H>
#ifdef __HOSTBOOT_RUNTIME
  #include <prdfMemTps.H>
#endif


using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p9_mca
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip An MCA chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::PostAnalysis] "

    #ifdef __HOSTBOOT_RUNTIME

    // If the IUE threshold in our data bundle has been reached, we trigger
    // a port fail. Once we trigger the port fail, the system may crash
    // right away. Since PRD is running in the hypervisor, it is possible we
    // may not get the error log. To better our chances, we trigger the port
    // fail here after the error log has been committed.
    if ( MemEcc::queryIueTh<TYPE_MCA>(i_chip, io_sc) )
    {
        if ( SUCCESS != MemEcc::triggerPortFail<TYPE_MCA>(i_chip) )
        {
            PRDF_ERR( PRDF_FUNC "triggerPortFail(0x%08x) failed",
            i_chip->getHuid() );
        }
    }

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS; // Always return SUCCESS for this plugin.

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, PostAnalysis );


//##############################################################################
//
//                               MCACALFIR
//
//##############################################################################

/**
 * @brief  MCACALFIR[4] - RCD Parity Error.
 * @param  i_mcaChip A P9 MCA chip.
 * @param  io_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t RcdParityError( ExtensibleChip * i_mcaChip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::RcdParityError] "

    // The callouts have already been made in the rule code. All other actions
    // documented below.

    // Nothing more to do if this is a checkstop attention.
    if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
        return SUCCESS;

    uint32_t l_rc = SUCCESS;

    // If MCBISTFIR[3] is found to be on at the same time, mask it so it won't
    // be logged as a separate event.
    ExtensibleChip * mcbChip = getConnectedParent( i_mcaChip, TYPE_MCBIST );

    SCAN_COMM_REGISTER_CLASS * mcbistfir = mcbChip->getRegister( "MCBISTFIR" );
    l_rc = mcbistfir->Read();
    if ( SUCCESS != l_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MCBISTFIR");
    }
    else if ( mcbistfir->IsBitSet(3) )
    {
        SCAN_COMM_REGISTER_CLASS * mcbistfir_mask_or =
            mcbChip->getRegister( "MCBISTFIR_MASK_OR" );
        mcbistfir_mask_or->SetBit(3);
        l_rc = mcbistfir_mask_or->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCBIST_MASK_OR: "
                      "mcbChip=0x%08x", mcbChip->getHuid() );
        }
    }

    #ifdef __HOSTBOOT_RUNTIME // TPS only supported at runtime.

    // Recovery is always enabled during runtime. If the threshold is reached,
    // make the error log predictive and start TPS on all slave ranks behind
    // the MCA.
    if ( getMcaDataBundle(i_mcaChip)->iv_rcdParityTh.inc(io_sc) )
    {
        io_sc.service_data->setServiceCall();

        McbistDataBundle * mcbdb = getMcbistDataBundle( mcbChip );

        std::vector<MemRank> list;
        getSlaveRanks<TYPE_MCA>( i_mcaChip->getTrgt(), list );
        PRDF_ASSERT( !list.empty() ); // target configured with no ranks

        for ( auto & r : list )
        {
            TdEntry * entry = new TpsEvent<TYPE_MCA>( i_mcaChip, r );
            uint32_t rc = mcbdb->getTdCtlr()->handleTdEvent( io_sc, entry );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "handleTdEvent() failed on 0x%08x",
                          i_mcaChip->getHuid() );

                continue; // Try the other ranks.
            }
        }
    }

    #else // IPL

    SCAN_COMM_REGISTER_CLASS * farb0 = i_mcaChip->getRegister("FARB0");
    if ( SUCCESS != farb0->Read() )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MCAECCFIR: i_mcaChip=0x%08x",
                  i_mcaChip->getHuid() );

        // Ensure the reg is zero so that we will use the recovery threshold and
        // guarantee we don't try to do a reconfig.
        farb0->clearAllBits();
    }

    if ( farb0->IsBitSet(54) )
    {
        // Recovery is disabled. Issue a reconfig loop. Make the error log
        // predictive if threshold is reached.
        if ( rcdParityErrorReconfigLoop(i_mcaChip->getTrgt()) )
            io_sc.service_data->setServiceCall();

        if ( isInMdiaMode() )
        {
            SCAN_COMM_REGISTER_CLASS * mask = nullptr;

            // Stop any further commands on this MCBIST to avoid subsequent RCD
            // errors or potential AUEs.
            l_rc = mdiaSendEventMsg( mcbChip->getTrgt(), MDIA::STOP_TESTING );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );
            }

            // Mask the maintenance AUE/IAUE attentions on this MCA because they
            // are potential side-effects of the RCD parity errors.
            mask = i_mcaChip->getRegister( "MCAECCFIR_MASK_OR" );
            mask->SetBit(33); // maintenance AUE
            mask->SetBit(36); // maintenance IAUE
            l_rc = mask->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_MASK_OR: "
                          "i_mcaChip=0x%08x", i_mcaChip->getHuid() );
            }

            // Mask the maintenance command complete bits to avoid false
            // attentions.
            mask = mcbChip->getRegister( "MCBISTFIR_MASK_OR" );
            mask->SetBit(10); // Command complete
            mask->SetBit(12); // WAT workaround
            l_rc = mask->Write();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR_MASK_OR: "
                          "mcbChip=0x%08x", mcbChip->getHuid() );
            }
        }
    }
    else
    {
        // Make the error log predictive if the recovery threshold is reached.
        // Don't bother with TPS on all ranks because it is too complicated to
        // handle during Memory Diagnostics and we don't have time to complete
        // the procedures at any other point during the IPL. The DIMMs will be
        // deconfigured during the IPL anyways. So not really much benefit
        // except for extra FFDC.
        if ( getMcaDataBundle(i_mcaChip)->iv_rcdParityTh.inc(io_sc) )
            io_sc.service_data->setServiceCall();
    }

    #endif

    if ( io_sc.service_data->queryServiceCall() )
    {
        // Mask both RCD parity error bits to prevent any flooding.
        SCAN_COMM_REGISTER_CLASS * mask
                                = i_mcaChip->getRegister( "MCACALFIR_MASK_OR" );
        mask->SetBit( 4);
        mask->SetBit(14);
        if ( SUCCESS != mask->Write() )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCACALFIR_MASK_OR: "
                      "i_mcaChip=0x%08x", i_mcaChip->getHuid() );
        }
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, RcdParityError );

//------------------------------------------------------------------------------

/**
 * @brief  MCACALFIR[13] - Persistent RCD error, port failed.
 * @param  i_chip MCA chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t MemPortFailure( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[p9_mca::MemPortFailure] "

    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
    {
        // The port is dead. Mask off the entire port.
        uint32_t l_rc = MemEcc::maskMemPort<TYPE_MCA>( i_chip );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemEcc::maskMemPort<TYPE_MCA>(0x%08x) failed",
                      i_chip->getHuid() );
        }
    }

    return SUCCESS; // nothing to return to rule code

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p9_mca, MemPortFailure );

} // end namespace p9_mca

} // end namespace PRDF

