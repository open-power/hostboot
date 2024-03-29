/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_ipl.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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

#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>
#include <plat_hwp_invoker.H>

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

    // Only OCMB_CHIP supported.
    TYPE trgtType = getTargetType( i_trgt );
    PRDF_ASSERT( TYPE_OCMB_CHIP == trgtType );

    // MDIA must be running.
    PRDF_ASSERT( isInMdiaMode() );

    // Send command complete to MDIA.
    MDIA::MaintCommandEvent mdiaEvent;
    mdiaEvent.target = i_trgt;
    mdiaEvent.type   = i_eventType;

    errlHndl_t errl = MDIA::processEvent( mdiaEvent );
    if ( nullptr != errl )
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

template<>
uint32_t mssRestoreDramRepairs<TYPE_OCMB_CHIP>( TargetHandle_t i_target,
                                                uint8_t & o_repairedRankMask,
                                                uint8_t & o_badDimmMask )
{
    uint32_t o_rc = SUCCESS;

    errlHndl_t errl = nullptr;

    fapi2::buffer<uint8_t> tmpRepairedRankMask, tmpBadDimmMask;

    if (isOdysseyOcmb(i_target))
    {
        FAPI_INVOKE_HWP( errl, ody_restore_repairs,
                         fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
                         tmpRepairedRankMask, tmpBadDimmMask );
    }
    else
    {
        FAPI_INVOKE_HWP( errl, exp_restore_repairs,
                         fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target),
                         tmpRepairedRankMask, tmpBadDimmMask );
    }

    if ( nullptr != errl )
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
            getThreshold(ATTR_MNFG_TH_MEMORY_RCD_PARITY_ERRORS);
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

//##############################################################################
//##                Explorer Maintenance Command wrappers
//##############################################################################

template<>
bool isBroadcastModeCapable<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    mss::states l_ret = mss::states::NO;

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt ( i_chip->getTrgt() );

    // Check for an Odyssey OCMB
    if (isOdysseyOcmb(i_chip->getTrgt()))
    {
        FAPI_CALL_HWP( l_ret, ody_is_broadcast_capable, fapiTrgt );
    }
    // Default to Explorer OCMB
    else
    {
        FAPI_CALL_HWP( l_ret, exp_is_broadcast_capable, fapiTrgt );
    }

    return ( mss::states::YES == l_ret );
    return false;
}

//------------------------------------------------------------------------------

template<>
uint32_t startSfRead<TYPE_OCMB_CHIP>( ExtensibleChip * i_ocmb,
                                      const MemRank & i_rank,
                                      const uint8_t& i_port )
{
    #define PRDF_FUNC "[PlatServices::startSfRead<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_ocmb->getType() );

    uint32_t o_rc = SUCCESS;

    // Get the OCMB_CHIP fapi target
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt ( i_ocmb->getTrgt() );

    do
    {
        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>( i_ocmb );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_ocmb->getHuid() );
            break;
        }

        // Start the super fast read command.
        errlHndl_t errl;

        if (isOdysseyOcmb(i_ocmb->getTrgt()))
        {
            // Get the first address of the given rank.
            mss::mcbist::address<mss::mc_type::ODYSSEY> saddr, eaddr;
            o_rc = getMemAddrRange<TYPE_OCMB_CHIP>( i_ocmb, i_rank, i_port,
                                                    saddr, eaddr, SLAVE_RANK );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                          i_ocmb->getHuid(), i_rank.getKey() );
                break;
            }
            // Get the stop conditions.
            mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY> stopCond;
            stopCond.set_pause_on_mpe(mss::ON)
                    .set_pause_on_ue(mss::ON)
                    .set_pause_on_aue(mss::ON)
                    .set_nce_inter_symbol_count_enable(mss::ON)
                    .set_nce_soft_symbol_count_enable( mss::ON)
                    .set_nce_hard_symbol_count_enable( mss::ON);

            // Stop on hard CEs if MNFG CE checking is enabled.
            if ( isMfgCeCheckingEnabled() )
            {
                stopCond.set_pause_on_nce_hard(mss::ON);
            }

            FAPI_INVOKE_HWP( errl, ody_sf_read, fapiTrgt, stopCond,
                             saddr );
        }
        else
        {
            // Get the first address of the given rank.
            mss::mcbist::address<mss::mc_type::EXPLORER> saddr, eaddr;
            o_rc = getMemAddrRange<TYPE_OCMB_CHIP>( i_ocmb, i_rank, i_port,
                                                    saddr, eaddr, SLAVE_RANK );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                          i_ocmb->getHuid(), i_rank.getKey() );
                break;
            }

            // Get the stop conditions.
            mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> stopCond;
            stopCond.set_pause_on_mpe(mss::ON)
                    .set_pause_on_ue(mss::ON)
                    .set_pause_on_aue(mss::ON)
                    .set_nce_inter_symbol_count_enable(mss::ON)
                    .set_nce_soft_symbol_count_enable( mss::ON)
                    .set_nce_hard_symbol_count_enable( mss::ON);

            // Stop on hard CEs if MNFG CE checking is enabled.
            if ( isMfgCeCheckingEnabled() )
            {
                stopCond.set_pause_on_nce_hard(mss::ON);
            }

            FAPI_INVOKE_HWP( errl, exp_sf_read, fapiTrgt, stopCond,
                             saddr );
        }

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "sf_read(0x%08x,%d) failed",
                      i_ocmb->getHuid(), i_rank.getMaster() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

