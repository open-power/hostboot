/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_ipl.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

#include <prdfMemDqBitmap.H>
#include <prdfMemScrubUtils.H>
#include <prdfMfgThresholdMgr.H>

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

    // Only MCBIST, MBA, and OCMB_CHIP supported.
    TYPE trgtType = getTargetType( i_trgt );
    PRDF_ASSERT( TYPE_MCBIST == trgtType ||
                 TYPE_MBA == trgtType    ||
                 TYPE_OCMB_CHIP == trgtType );

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

bool rcdParityErrorReconfigLoop( TargetHandle_t i_trgt )
{
    TargetHandle_t top = getSystemTarget();

    // Get the current reconfig count and increment.
    uint8_t count = i_trgt->getAttr<ATTR_RCD_PARITY_RECONFIG_LOOP_COUNT>() + 1;

    // Get the reconfig threshold and check MNFG threshold, if needed.
    uint8_t th = top->getAttr<ATTR_RCD_PARITY_RECONFIG_LOOPS_ALLOWED>() + 1;
    if ( mfgMode() )
    {
        uint8_t mnfgTh = MfgThresholdMgr::getInstance()->
                                   getThreshold(ATTR_MNFG_TH_RCD_PARITY_ERRORS);
        if ( mnfgTh < th )
            th = mnfgTh;
    }

    // If the count is under threshold, trigger a reconfig loop.
    if ( count < th )
    {
        // Set the RCD parity error flag in the reconfig loop attribute. This
        // will trigger a reconfig loop at the end of the current istep.
        ATTR_RECONFIGURE_LOOP_type attr = top->getAttr<ATTR_RECONFIGURE_LOOP>();
        if ( 0 == (attr & RECONFIGURE_LOOP_RCD_PARITY_ERROR) )
        {
            attr |= RECONFIGURE_LOOP_RCD_PARITY_ERROR;
            top->setAttr<ATTR_RECONFIGURE_LOOP>(attr);
        }

        // Write the new count to the attribute.
        i_trgt->setAttr<ATTR_RCD_PARITY_RECONFIG_LOOP_COUNT>(count);

        return false;
    }

    return true;
}

//------------------------------------------------------------------------------

template<>
uint32_t mssRestoreDramRepairs<TYPE_MCA>( TargetHandle_t i_target,
                                          uint8_t & o_repairedRankMask,
                                          uint8_t & o_badDimmMask )
{
    uint32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;


    fapi2::buffer<uint8_t> tmpRepairedRankMask, tmpBadDimmMask;
    FAPI_INVOKE_HWP( errl, mss::restore_repairs,
                     fapi2::Target<fapi2::TARGET_TYPE_MCA>( i_target ),
                     tmpRepairedRankMask, tmpBadDimmMask );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssRestoreDramRepairs] "
                  "restore_repairs() failed. HUID: 0x%08x",
                  getHuid(i_target) );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    o_repairedRankMask = (uint8_t)tmpRepairedRankMask;
    o_badDimmMask = (uint8_t)tmpBadDimmMask;

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
uint32_t mssRestoreDramRepairs<TYPE_MEM_PORT>( TargetHandle_t i_target,
                                               uint8_t & o_repairedRankMask,
                                               uint8_t & o_badDimmMask )
{
    uint32_t o_rc = SUCCESS;

    /* TODO RTC 207273 - no HWP support yet
    errlHndl_t errl = NULL;


    fapi2::buffer<uint8_t> tmpRepairedRankMask, tmpBadDimmMask;
    FAPI_INVOKE_HWP( errl, mss::restore_repairs,
                     fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>( i_target ),
                     tmpRepairedRankMask, tmpBadDimmMask );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssRestoreDramRepairs] "
                  "restore_repairs() failed. HUID: 0x%08x",
                  getHuid(i_target) );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    o_repairedRankMask = (uint8_t)tmpRepairedRankMask;
    o_badDimmMask = (uint8_t)tmpBadDimmMask;
    */

    return o_rc;
}

//##############################################################################
//##                    Nimbus Maintenance Command wrappers
//##############################################################################

template<>
bool isBroadcastModeCapable<TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( i_chip->getTrgt() );

    mss::states l_ret = mss::states::NO;
    FAPI_CALL_HWP( l_ret, mss::mcbist::is_broadcast_capable, fapiTrgt );
    return ( mss::states::YES == l_ret );
}

//------------------------------------------------------------------------------

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
    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( mcbChip->getTrgt() );

    // Get the stop conditions.
    mss::mcbist::stop_conditions<> stopCond;
    stopCond.set_pause_on_mpe(mss::ON)
            .set_pause_on_ue(mss::ON)
            .set_pause_on_aue(mss::ON)
            .set_nce_inter_symbol_count_enable(mss::ON)
            .set_nce_soft_symbol_count_enable( mss::ON)
            .set_nce_hard_symbol_count_enable( mss::ON);

    // Stop on hard CEs if MNFG CE checking is enabled.
    if ( isMfgCeCheckingEnabled() ) stopCond.set_pause_on_nce_hard(mss::ON);

    do
    {
        // Get the first address of the given rank.
        mss::mcbist::address saddr, eaddr;
        o_rc = getMemAddrRange<TYPE_MCA>( i_mcaChip, i_rank, saddr, eaddr,
                                          SLAVE_RANK );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_mcaChip->getHuid(), i_rank.getKey() );
            break;
        }

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_MCBIST>( mcbChip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      mcbChip->getHuid() );
            break;
        }

        // Start the super fast read command.
        errlHndl_t errl;
        FAPI_INVOKE_HWP( errl, mss::memdiags::sf_read, fapiTrgt, stopCond,
                         saddr );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss::memdiags::sf_read(0x%08x,%d) failed",
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

//------------------------------------------------------------------------------

template<>
uint32_t cleanupSfRead<TYPE_MCBIST>( ExtensibleChip * i_mcbChip )
{
    return SUCCESS; // Not needed for MCBIST commands.
}

//##############################################################################
//##                Explorer/Axone Maintenance Command wrappers
//##############################################################################

template<>
bool isBroadcastModeCapable<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    /* TODO RTC 207273 - no HWP support yet
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt ( i_chip->getTrgt() );

    mss::states l_ret = mss::states::NO;
    FAPI_CALL_HWP( l_ret, mss::mcbist::is_broadcast_capable, fapiTrgt );
    return ( mss::states::YES == l_ret );
    */
    return false;
}

//------------------------------------------------------------------------------

template<>
uint32_t startSfRead<TYPE_MEM_PORT>( ExtensibleChip * i_memPort,
                                     const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startSfRead<TYPE_MCA>] "

    PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

    PRDF_ASSERT( nullptr != i_memPort );
    PRDF_ASSERT( TYPE_MEM_PORT == i_memPort->getType() );

    uint32_t o_rc = SUCCESS;

    /* TODO RTC 207273 - no HWP support yet
    // Get the OCMB_CHIP fapi target
    ExtensibleChip * ocmbChip = getConnectedParent( i_memPort, TYPE_OCMB_CHIP );
    fapi2::Target<fapi2::TYPE_OCMB_CHIP> fapiTrgt ( ocmbChip->getTrgt() );

    // Get the stop conditions.
    mss::mcbist::stop_conditions<> stopCond;
    stopCond.set_pause_on_mpe(mss::ON)
            .set_pause_on_ue(mss::ON)
            .set_pause_on_aue(mss::ON)
            .set_nce_inter_symbol_count_enable(mss::ON)
            .set_nce_soft_symbol_count_enable( mss::ON)
            .set_nce_hard_symbol_count_enable( mss::ON);

    // Stop on hard CEs if MNFG CE checking is enabled.
    if ( isMfgCeCheckingEnabled() ) stopCond.set_pause_on_nce_hard(mss::ON);

    do
    {
        // Get the first address of the given rank.
        mss::mcbist::address saddr, eaddr;
        o_rc = getMemAddrRange<TYPE_MEM_PORT>( i_memPort, i_rank, saddr, eaddr,
                                               SLAVE_RANK );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_memPort->getHuid(), i_rank.getKey() );
            break;
        }

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>( ocmbChip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      ocmbChip->getHuid() );
            break;
        }

        // Start the super fast read command.
        errlHndl_t errl;
        FAPI_INVOKE_HWP( errl, mss::memdiags::sf_read, fapiTrgt, stopCond,
                         saddr );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss::memdiags::sf_read(0x%08x,%d) failed",
                      ocmbChip->getHuid(), i_rank.getMaster() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    */

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// This specialization only exists to avoid a lot of extra code in some classes.
// The input chip must still be an MEM_PORT chip.
template<>
uint32_t startSfRead<TYPE_OCMB_CHIP>( ExtensibleChip * i_memPort,
                                      const MemRank & i_rank )
{
    return startSfRead<TYPE_MEM_PORT>( i_memPort, i_rank );
}

//------------------------------------------------------------------------------

template<>
uint32_t cleanupSfRead<TYPE_OCMB_CHIP>( ExtensibleChip * i_ocmbChip )
{
    return SUCCESS; // Not needed for MCBIST commands.
}

//------------------------------------------------------------------------------

template<>
uint32_t startTdSteerCleanup<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
    const MemRank & i_rank, AddrRangeType i_rangeType,
    mss::mcbist::stop_conditions<> i_stopCond )
{
    #define PRDF_FUNC "[PlatServices::startTdSteerCleanup<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Default speed is to run as fast as possible.
    //mss_MaintCmd::TimeBaseSpeed cmdSpeed = mss_MaintCmd::FAST_MAX_BW_IMPACT;

    // Set stop-on-AUE for all target scrubs. See explanation in startBgScrub()
    // for the reasons why.
    i_stopCond.set_pause_on_aue(mss::ON);

    do
    {
        // Get the address range of the given rank.
        mss::mcbist::address saddr, eaddr;
        o_rc = getMemAddrRange<TYPE_OCMB_CHIP>( i_chip, i_rank, saddr, eaddr,
                                                i_rangeType );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        /* TODO RTC 207273 - sparing support
        // Get the MBA fapi target.
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );

        // Start the steer cleanup command.
        mss_TimeBaseSteerCleanup cmd { fapiTrgt, saddr, eaddr, cmdSpeed,
                                       i_stopCond, false };
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, cmd.setupAndExecuteCmd );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "setupAndExecuteCmd() on 0x%08x,0x%02x failed",
                      i_chip->getHuid(), i_rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }
        */

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t startTdSfRead<TYPE_OCMB_CHIP>(ExtensibleChip * i_chip,
                                      const MemRank & i_rank,
                                      AddrRangeType i_rangeType,
                                      mss::mcbist::stop_conditions<> i_stopCond)
{
    #define PRDF_FUNC "[PlatServices::startTdSfRead<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Set stop-on-AUE for all target scrubs. See explanation in startBgScrub()
    // for the reasons why.
    i_stopCond.set_pause_on_aue(mss::ON);

    do
    {
        // Get the address range of the given rank.
        mss::mcbist::address saddr, eaddr;
        o_rc = getMemAddrRange<TYPE_OCMB_CHIP>( i_chip, i_rank, saddr, eaddr,
                                                i_rangeType );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        /* TODO RTC 207273 - HWP support
        // Get the MBA fapi target.
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );

        // Create the new command. Store a pointer to the command in the MBA
        // data bundle so that we can call the cleanup function after the
        // command has completed.
        MbaDataBundle * db = getMbaDataBundle( i_chip );
        PRDF_ASSERT( nullptr == db->iv_sfCmd ); // Code bug.
        db->iv_sfCmd = new mss_SuperFastRead { fapiTrgt, saddr, eaddr,
                                               i_stopCond, false };

        // Start the super fast read command.
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, db->iv_sfCmd->setupAndExecuteCmd );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "setupAndExecuteCmd() on 0x%08x,0x%02x failed",
                      i_chip->getHuid(), i_rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }
        */

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

