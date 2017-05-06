/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfP9Mca.C $                      */
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
    if ( SUCCESS != MemEcc::iuePortFail<TYPE_MCA>(i_chip, io_sc) )
    {
        PRDF_ERR( PRDF_FUNC "iuePortFail(0x%08x) failed", i_chip->getHuid() );
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
    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
        return SUCCESS;

    #ifdef __HOSTBOOT_RUNTIME // TPS only supported at runtime.

    // Recovery is always enabled during runtime. Start TPS on all slave ranks
    // behind the MCA if the recovery threshold is reached.
    if ( getMcaDataBundle(i_mcaChip)->iv_rcdParityTh.inc(io_sc) )
    {
        ExtensibleChip * mcbChip = getConnectedParent( i_mcaChip, TYPE_MCBIST );

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
        if ( rcdParityErrorReconfigLoop() )
            io_sc.service_data->setServiceCall();
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

