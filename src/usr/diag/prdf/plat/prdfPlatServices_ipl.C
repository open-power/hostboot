/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_ipl.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 * @file  prdfPlatServices_ipl.C
 * @brief Wrapper code for external interfaces used by PRD (IPL only).
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfPlatServices.H>

#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

//#include <prdfCenDqBitmap.H> TODO RTC 136126
#include <prdfMemScrubUtils.H>

#include <diag/mdia/mdia.H>
#include <config.h>

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

bool isInMdiaMode()
{
    bool o_isInMdiaMode = false;
#ifndef CONFIG_VPO_COMPILE
    MDIA::waitingForMaintCmdEvents(o_isInMdiaMode);
#endif
    return o_isInMdiaMode;
}

//------------------------------------------------------------------------------

int32_t mdiaSendEventMsg( TargetHandle_t i_trgt,
                          MDIA::MaintCommandEventType i_eventType )
{
    #define PRDF_FUNC "[PlatServices::mdiaSendEventMsg] "

    int32_t o_rc = SUCCESS;

#ifndef CONFIG_VPO_COMPILE

    PRDF_ASSERT( nullptr != i_trgt );

    // Only MCBIST and MBA supported.
    TYPE trgtType = getTargetType( i_trgt );
    PRDF_ASSERT( TYPE_MCBIST == trgtType || TYPE_MBA == trgtType );

    // MDIA must be running.
    PRDF_ASSERT( isInMdiaMode() );

    // Send command complete to MDIA.
    MDIA::MaintCommandEvent mdiaEvent;
    mdiaEvent.target = i_trgt;
    mdiaEvent.type   = i_eventType;

    errlHndl_t errl = MDIA::processEvent( mdiaEvent );
    if ( NULL != errl )
    {
        PRDF_ERR( PRDF_FUNC "MDIA::processEvent() failed: i_target=0x%08x "
                  "i_eventType=%d", getHuid(i_trgt), i_eventType );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

#endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

/* TODO RTC 136126
int32_t mssRestoreDramRepairs( TargetHandle_t i_mbaTarget,
                               uint8_t & o_repairedRankMask,
                               uint8_t & o_badDimmMask )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    FAPI_INVOKE_HWP( errl, mss_restore_DRAM_repairs,
                     fapi::Target(fapi::TARGET_TYPE_MBA_CHIPLET, i_mbaTarget),
                     o_repairedRankMask, o_badDimmMask );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssRestoreDramRepairs] "
                  "mss_restore_dram_repairs() failed. HUID: 0x%08x",
                  getHuid(i_mbaTarget) );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}
*/

//------------------------------------------------------------------------------

/* TODO RTC 136126
int32_t mssIplUeIsolation( TargetHandle_t i_mba, const CenRank & i_rank,
                           CenDqBitmap & o_bitmap )
{
    #define PRDF_FUNC "[PlatServices::mssIplUeIsolation] "

    int32_t o_rc = SUCCESS;

    uint8_t data[MBA_DIMMS_PER_RANK][DIMM_DQ_RANK_BITMAP_SIZE];

    errlHndl_t errl = NULL;
    FAPI_INVOKE_HWP( errl, mss_IPL_UE_isolation, getFapiTarget(i_mba),
                     i_rank.getMaster(), data );
    if ( NULL != errl )
    {
        PRDF_ERR( PRDF_FUNC "mss_IPL_UE_isolation() failed: MBA=0x%08x "
                  "rank=%d", getHuid(i_mba), i_rank.getMaster() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    else
    {
        o_bitmap = CenDqBitmap ( i_mba, i_rank, data );
    }

    return o_rc;

    #undef PRDF_FUNC
}
*/

//##############################################################################
//##                    Nimbus Maintenance Command wrappers
//##############################################################################

template<>
uint32_t startSfRead<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startSfRead<TYPE_MCA>] "

    PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

    PRDF_ASSERT( nullptr != i_mcaChip );
    PRDF_ASSERT( TYPE_MCA == i_mcaChip->getType() );

    uint32_t o_rc = SUCCESS;

    // Get the MCBIST fapi target
    ExtensibleChip * mcbChip = getConnectedParent( i_mcaChip, TYPE_MCBIST );
    PRDF_ASSERT( nullptr != mcbChip );
    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( mcbChip->getTrgt() );

    // Get the stop conditions.
    mss::mcbist::stop_conditions stopCond;
    stopCond.set_pause_on_mpe(mss::ON)
            .set_pause_on_ue(mss::ON)
            .set_nce_inter_symbol_count_enable(mss::ON)
            .set_nce_soft_symbol_count_enable( mss::ON)
            .set_nce_hard_symbol_count_enable( mss::ON);

    // Stop on hard CEs if MNFG CE checking is enable.
    if ( isMfgCeCheckingEnabled() ) stopCond.set_pause_on_nce_hard(mss::ON);

    // Get the first address of the given rank.
    uint32_t port = i_mcaChip->getPos() % MAX_MCA_PER_MCBIST;
    mss::mcbist::address saddr, eaddr;
    mss::mcbist::address::get_srank_range( port,
                                           i_rank.getDimmSlct(),
                                           i_rank.getRankSlct(),
                                           i_rank.getSlave(),
                                           saddr,
                                           eaddr );

    do
    {
        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_MCBIST>( mcbChip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      mcbChip->getHuid() );
            break;
        }

        // Start the super fast read command.
        fapi2::ReturnCode fapi_rc = memdiags::sf_read( fapiTrgt, stopCond,
                                                       saddr );
        errlHndl_t errl = fapi2::rcToErrl( fapi_rc );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "memdiags::sf_read(0x%08x,%d) failed",
                      mcbChip->getHuid(), i_rank.getMaster() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// This specialization only exists to avoid a lot of extra code in some classes.
// The input chip must still be an MCA chip.
template<>
uint32_t startSfRead<TYPE_MCBIST>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    return startSfRead<TYPE_MCA>( i_mcaChip, i_rank );
}

//##############################################################################
//##                   Centaur Maintenance Command wrappers
//##############################################################################

template<>
uint32_t startSfRead<TYPE_MBA>( ExtensibleChip * i_mbaChip,
                                const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startSfRead<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_mbaChip );
    PRDF_ASSERT( TYPE_MBA == i_mbaChip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_MBA>( i_mbaChip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_mbaChip->getHuid() );
            break;
        }

        // Start the background scrub command.
        PRDF_ERR( PRDF_FUNC "function not implemented yet" ); // TODO RTC 136126

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

