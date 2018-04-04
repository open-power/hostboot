/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices.C $                   */
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

/**
 * @file  prdfPlatServices.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <prdfPlatServices.H>

#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>
#include <prdfAssert.h>

#include <prdfMemScrubUtils.H>

#include <iipServiceDataCollector.h>
#include <UtilHash.H>

#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <initservice/initserviceif.H>
#include <devicefw/userif.H>
#include <iipMopRegisterAccess.h>
#include <ibscomreasoncodes.H>
#include <p9_proc_gettracearray.H>

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
//##############################################################################

void getCurrentTime( Timer & o_timer )
{
    timespec_t curTime;
    PRDF_ASSERT(0 == clock_gettime(CLOCK_MONOTONIC, &curTime))

    // Hostboot uptime in seconds
    o_timer = curTime.tv_sec;

    // Since Hostboot doesn't have any system checkstop, we don't have to worry
    // about the detailed time struct for system checkstop timestamp.
}

//------------------------------------------------------------------------------

void milliSleep( uint32_t i_seconds, uint32_t i_milliseconds )
{
    nanosleep( i_seconds, i_milliseconds * 1000000 );
}

//------------------------------------------------------------------------------

/* TODO RTC 144705
void initiateUnitDump( TargetHandle_t i_target,
                       errlHndl_t i_errl,
                       uint32_t i_errlActions )
{
    // no-op in Hostboot but just go ahead and commit
    // the errorlog in case it's not null.
    if ( NULL != i_errl )
    {
        PRDF_COMMIT_ERRL(i_errl, i_errlActions);
    }
}
*/

//------------------------------------------------------------------------------

bool isSpConfigFsp()
{
    return INITSERVICE::spBaseServicesEnabled();
}

//------------------------------------------------------------------------------

uint32_t getScom(TARGETING::TargetHandle_t i_target, BitString& io_bs,
                   uint64_t i_address)
{
    errlHndl_t errl = NULL;
    uint32_t rc = SUCCESS;
    size_t bsize = (io_bs.getBitLen()+7)/8;
    CPU_WORD* buffer = io_bs.getBufAddr();

    errl = deviceRead(i_target, buffer, bsize, DEVICE_SCOM_ADDRESS(i_address));

    if(( NULL != errl ) && ( IBSCOM::IBSCOM_BUS_FAILURE == errl->reasonCode() ))
    {
        PRDF_SET_ERRL_SEV(errl, ERRL_SEV_INFORMATIONAL);
        PRDF_COMMIT_ERRL(errl, ERRL_ACTION_HIDDEN);
        PRDF_INF( "Register access failed with reason code IBSCOM_BUS_FAILURE."
                  " Trying again, Target HUID:0x%08X Register 0x%016X Op:%u",
                  PlatServices::getHuid( i_target), i_address,
                  MopRegisterAccess::READ );

        errl = deviceRead(i_target, buffer, bsize,
                          DEVICE_SCOM_ADDRESS(i_address));
    }

    if( NULL != errl )
    {
        PRDF_ERR( "getScom() failed on i_target=0x%08x i_address=0x%016llx",
                  getHuid(i_target), i_address );

        rc = PRD_SCANCOM_FAILURE;
        PRDF_ADD_SW_ERR(errl, rc, PRDF_HOM_SCOM, __LINE__);

        bool l_isAbort = false;
        PRDF_ABORTING(l_isAbort);
        if (!l_isAbort)
        {
            PRDF_SET_ERRL_SEV(errl, ERRL_SEV_INFORMATIONAL);
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_HIDDEN);
        }
        else
        {
            delete errl;
            errl = NULL;
        }
    }

    return rc;
}

//------------------------------------------------------------------------------

uint32_t putScom(TARGETING::TargetHandle_t i_target, BitString& io_bs,
                   uint64_t i_address)
{
    errlHndl_t errl = NULL;
    uint32_t rc = SUCCESS;
    size_t bsize = (io_bs.getBitLen()+7)/8;
    CPU_WORD* buffer = io_bs.getBufAddr();

    errl = deviceWrite(i_target, buffer, bsize, DEVICE_SCOM_ADDRESS(i_address));

    if( NULL != errl )
    {
        PRDF_ERR( "putScom() failed on i_target=0x%08x i_address=0x%016llx",
                  getHuid(i_target), i_address );

        rc = PRD_SCANCOM_FAILURE;
        PRDF_ADD_SW_ERR(errl, rc, PRDF_HOM_SCOM, __LINE__);

        bool l_isAbort = false;
        PRDF_ABORTING(l_isAbort);
        if (!l_isAbort)
        {
            PRDF_SET_ERRL_SEV(errl, ERRL_SEV_INFORMATIONAL);
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_HIDDEN);
        }
        else
        {
            delete errl;
            errl = NULL;
        }
    }

    return rc;
}


//##############################################################################
//##                       Processor specific functions
//##############################################################################

/* TODO RTC 136050
void collectSBE_FFDC(TARGETING::TargetHandle_t i_procTarget)
{
    // Do nothing for Hostboot
}
*/

//##############################################################################
//##                        util functions
//##############################################################################

int32_t getCfam( ExtensibleChip * i_chip,
                 const uint32_t i_addr,
                 uint32_t & o_data)
{
    #define PRDF_FUNC "[PlatServices::getCfam] "

    int32_t rc = SUCCESS;

    do
    {
        // HB doesn't allow cfam access on master proc
        TargetHandle_t l_procTgt = i_chip->GetChipHandle();

        if( TYPE_PROC == getTargetType(l_procTgt) )
        {
            TargetHandle_t l_pMasterProcChip = NULL;
            targetService().
                masterProcChipTargetHandle( l_pMasterProcChip );

            if( l_pMasterProcChip == l_procTgt )
            {
                PRDF_DTRAC( PRDF_FUNC "can't access CFAM from master "
                            "proc: 0x%.8X", i_chip->GetId() );
                break;
            }
        }

        errlHndl_t errH = NULL;
        size_t l_size = sizeof(uint32_t);
        errH = deviceRead(l_procTgt, &o_data, l_size,
                          DEVICE_FSI_ADDRESS((uint64_t) i_addr));
        if (errH)
        {
            rc = FAIL;
            PRDF_ERR( PRDF_FUNC "chip: 0x%.8X, failed to get cfam address: "
                      "0x%X", i_chip->GetId(), i_addr );
            PRDF_COMMIT_ERRL(errH, ERRL_ACTION_SA|ERRL_ACTION_REPORT);
            break;
        }


    } while(0);


    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getActiveRefClk(TARGETING::TargetHandle_t
                            i_procTarget,
                            TARGETING::TYPE i_connType,
                            uint32_t i_oscPos)
{
    return PlatServices::getClockId( i_procTarget,
                                     i_connType,
                                     i_oscPos );
}

//##############################################################################
//##                        Memory specific functions
//##############################################################################

template<>
uint32_t getMemAddrRange<TYPE_MCA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    mss::mcbist::address & o_startAddr,
                                    mss::mcbist::address & o_endAddr,
                                    AddrRangeType i_rangeType )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange<TYPE_MCA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    uint32_t port = i_chip->getPos() % MAX_MCA_PER_MCBIST;

    if ( SLAVE_RANK == i_rangeType )
    {
        FAPI_CALL_HWP_NORETURN( mss::mcbist::address::get_srank_range,
                                port, i_rank.getDimmSlct(),
                                i_rank.getRankSlct(), i_rank.getSlave(),
                                o_startAddr, o_endAddr );
    }
    else if ( MASTER_RANK == i_rangeType )
    {
        FAPI_CALL_HWP_NORETURN( mss::mcbist::address::get_mrank_range,
                                port, i_rank.getDimmSlct(),
                                i_rank.getRankSlct(), o_startAddr, o_endAddr );
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "unsupported range type %d", i_rangeType );
        PRDF_ASSERT(false);
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemAddrRange<TYPE_MBA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    fapi2::buffer<uint64_t> & o_startAddr,
                                    fapi2::buffer<uint64_t> & o_endAddr,
                                    AddrRangeType i_rangeType )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    errlHndl_t errl = nullptr;
    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );

    if ( SLAVE_RANK == i_rangeType )
    {
        FAPI_INVOKE_HWP( errl, mss_get_slave_address_range, fapiTrgt,
                         i_rank.getMaster(), i_rank.getSlave(),
                         o_startAddr, o_endAddr );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_get_slave_address_range(0x%08x,0x%02x) "
                      "failed", i_chip->getHuid(), i_rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }
    }
    else if ( MASTER_RANK == i_rangeType )
    {
        FAPI_INVOKE_HWP( errl, mss_get_address_range, fapiTrgt,
                         i_rank.getMaster(), o_startAddr, o_endAddr );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_get_address_range(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "unsupported range type %d", i_rangeType );
        PRDF_ASSERT(false);
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

MemAddr __convertMssMcbistAddr( const mss::mcbist::address & i_addr )
{
    uint64_t dslct = i_addr.get_dimm();
    uint64_t rslct = i_addr.get_master_rank();
    uint64_t srnk  = i_addr.get_slave_rank();
    uint64_t bnk   = i_addr.get_bank();
    uint64_t row   = i_addr.get_row();
    uint64_t col   = i_addr.get_column();

    uint64_t mrnk  = (dslct << 2) | rslct;

    return MemAddr ( MemRank ( mrnk, srnk ), bnk, row, col );
}

template<>
uint32_t getMemAddrRange<TYPE_MCA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    MemAddr & o_startAddr,
                                    MemAddr & o_endAddr,
                                    AddrRangeType i_rangeType )
{
    mss::mcbist::address saddr, eaddr;
    uint32_t o_rc = getMemAddrRange<TYPE_MCA>( i_chip, i_rank, saddr, eaddr,
                                               i_rangeType );
    if ( SUCCESS == o_rc )
    {
        o_startAddr = __convertMssMcbistAddr( saddr );
        o_endAddr   = __convertMssMcbistAddr( eaddr );
    }

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemAddrRange<TYPE_MBA>( ExtensibleChip * i_chip,
                                    const MemRank & i_rank,
                                    MemAddr & o_startAddr,
                                    MemAddr & o_endAddr,
                                    AddrRangeType i_rangeType )
{
    fapi2::buffer<uint64_t> saddr, eaddr;
    uint32_t o_rc = getMemAddrRange<TYPE_MBA>( i_chip, i_rank, saddr, eaddr,
                                               i_rangeType );
    if ( SUCCESS == o_rc )
    {
        o_startAddr = MemAddr::fromMaintAddr<TYPE_MBA>( (uint64_t)saddr );
        o_endAddr   = MemAddr::fromMaintAddr<TYPE_MBA>( (uint64_t)eaddr );
    }

    return o_rc;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE TT, typename VT>
uint32_t getMemAddrRange( ExtensibleChip * i_chip, VT & o_startAddr,
                          VT & o_endAddr, uint8_t i_dimmSlct )
{
    #define PRDF_FUNC "[PlatServices::__getMemAddrRange] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the rank list.
        std::vector<MemRank> rankList;
        getMasterRanks<TT>( i_chip->getTrgt(), rankList, i_dimmSlct );
        if ( rankList.empty() )
        {
            PRDF_ERR( PRDF_FUNC "i_chip=0x%08x configured with no ranks",
                      i_chip->getHuid() );
            o_rc = FAIL;
            break;
        }

        // rankList is guaranteed to be sorted. So get the first and last rank.
        MemRank firstRank = rankList.front();
        MemRank lastRank  = rankList.back();

        // Get the address range of the first rank.
        o_rc = getMemAddrRange<TT>( i_chip, firstRank, o_startAddr, o_endAddr,
                                    MASTER_RANK );
        if ( SUCCESS != o_rc ) break;

        // Check if there is only one rank configured.
        if ( firstRank == lastRank ) break;

        // Get the end address of the last rank.
        VT junk;
        o_rc = getMemAddrRange<TT>( i_chip, lastRank, junk, o_endAddr,
                                    MASTER_RANK );
        if ( SUCCESS != o_rc ) break;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t getMemAddrRange<TYPE_MCA>( ExtensibleChip * i_chip,
                                    mss::mcbist::address & o_startAddr,
                                    mss::mcbist::address & o_endAddr,
                                    uint8_t i_dimmSlct );

template
uint32_t getMemAddrRange<TYPE_MBA>( ExtensibleChip * i_chip,
                                    fapi2::buffer<uint64_t> & o_startAddr,
                                    fapi2::buffer<uint64_t> & o_endAddr,
                                    uint8_t i_dimmSlct );

template
uint32_t getMemAddrRange<TYPE_MBA>( ExtensibleChip * i_chip,
                                    MemAddr & o_startAddr, MemAddr & o_endAddr,
                                    uint8_t i_dimmSlct );

template
uint32_t getMemAddrRange<TYPE_MCA>( ExtensibleChip * i_chip,
                                    MemAddr & o_startAddr, MemAddr & o_endAddr,
                                    uint8_t i_dimmSlct );

//##############################################################################
//##                    Nimbus Maintenance Command wrappers
//##############################################################################

template<>
uint32_t startBgScrub<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                 const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startBgScrub<TYPE_MCA>] "

    PRDF_ASSERT( nullptr != i_mcaChip );
    PRDF_ASSERT( TYPE_MCA == i_mcaChip->getType() );

    uint32_t o_rc = SUCCESS;

    // Get the MCBIST fapi target
    ExtensibleChip * mcbChip = getConnectedParent( i_mcaChip, TYPE_MCBIST );
    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( mcbChip->getTrgt() );

    // Get the stop conditions.
    // NOTE: If HBRT_PRD is not configured, we want to use the defaults so that
    //       background scrubbing never stops.
    mss::mcbist::stop_conditions stopCond;

    // AUEs are checkstop attentions. Unfortunately, MCBIST commands do not stop
    // when the system checkstops. Therefore, we must set the stop condition for
    // AUEs so that we can use the MCBMCAT register to determine where the error
    // occurred. Note that there isn't a stop condition specifically for IAUEs.
    // Instead, there is the RCE threshold. Unfortunately, the RCE counter is a
    // combination of IUE, IAUE, IMPE, and IRCD errors. It is possible to use
    // this threshold and simply restart background scrubbing each time there is
    // an IUE, IMPE, or IRCD but there is concern that PRD might get stuck
    // handling those attentions on every address even after thresholds have
    // been reached. Therefore, we simplified the design and will simply call
    // out both DIMMs for maintenance IAUEs.
    stopCond.set_pause_on_aue(mss::ON);

    #ifdef CONFIG_HBRT_PRD

    stopCond.set_thresh_nce_int(1)
            .set_thresh_nce_soft(1)
            .set_thresh_nce_hard(1)
            .set_pause_on_mpe(mss::ON)
            .set_pause_on_ue(mss::ON)
            .set_nce_inter_symbol_count_enable(mss::ON)
            .set_nce_soft_symbol_count_enable(mss::ON)
            .set_nce_hard_symbol_count_enable(mss::ON);

    // In MNFG mode, stop on RCE_ETE to get an accurate callout for IUEs.
    if ( mfgMode() ) stopCond.set_thresh_rce(1);

    #endif

    // Get the scrub speed.
    mss::mcbist::speed scrubSpeed = enableFastBgScrub() ? mss::mcbist::LUDICROUS
                                                        : mss::mcbist::BG_SCRUB;

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

        // Start the background scrub command.
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, mss::memdiags::background_scrub, fapiTrgt,
                         stopCond, scrubSpeed, saddr );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss::memdiags::background_scrub(0x%08x,%d) "
                      "failed", mcbChip->getHuid(), i_rank.getMaster() );
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
uint32_t startBgScrub<TYPE_MCBIST>( ExtensibleChip * i_mcaChip,
                                    const MemRank & i_rank )
{
    return startBgScrub<TYPE_MCA>( i_mcaChip, i_rank );
}

//------------------------------------------------------------------------------

uint32_t __startTdScrub_mca( ExtensibleChip * i_mcaChip,
                             mss::mcbist::address i_saddr,
                             mss::mcbist::address i_eaddr,
                             mss::mcbist::stop_conditions & i_stopCond )
{
    #define PRDF_FUNC "[PlatServices::__startTdScrub_mca] "

    PRDF_ASSERT( nullptr != i_mcaChip );
    PRDF_ASSERT( TYPE_MCA == i_mcaChip->getType() );

    uint32_t o_rc = SUCCESS;

    // Get the MCBIST fapi target
    ExtensibleChip * mcbChip = getConnectedParent( i_mcaChip, TYPE_MCBIST );
    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( mcbChip->getTrgt() );

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

        // Set stop-on-AUE for all target scrubs. See explanation in
        // startBgScrub() for the reasons why.
        i_stopCond.set_pause_on_aue(mss::ON);

        // Start targeted scrub command.
        errlHndl_t errl;
        FAPI_INVOKE_HWP( errl, mss::memdiags::targeted_scrub, fapiTrgt, i_stopCond,
                         i_saddr, i_eaddr, mss::mcbist::NONE );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss::memdiags::targeted_scrub(0x%08x) failed",
                      mcbChip->getHuid() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t __startTdScrub_mca( ExtensibleChip * i_mcaChip, const MemRank & i_rank,
                             mss::mcbist::stop_conditions & i_stopCond,
                             AddrRangeType i_rangeType )
{
    #define PRDF_FUNC "[PlatServices::__startTdScrub_mca] "

    mss::mcbist::address saddr, eaddr;
    uint32_t o_rc = getMemAddrRange<TYPE_MCA>( i_mcaChip, i_rank, saddr, eaddr,
                                               i_rangeType );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                  i_mcaChip->getHuid(), i_rank.getKey() );
    }
    else
    {
        o_rc = __startTdScrub_mca( i_mcaChip, saddr, eaddr, i_stopCond );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t startVcmPhase1<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;

    return __startTdScrub_mca( i_mcaChip, i_rank, stopCond, MASTER_RANK );
}

//------------------------------------------------------------------------------

template<>
uint32_t startVcmPhase2<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;

    return __startTdScrub_mca( i_mcaChip, i_rank, stopCond, MASTER_RANK );
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsPhase1<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;
    stopCond.set_nce_soft_symbol_count_enable(mss::ON)
            .set_nce_inter_symbol_count_enable(mss::ON);

    return __startTdScrub_mca( i_mcaChip, i_rank, stopCond, SLAVE_RANK );
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsPhase2<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;
    stopCond.set_nce_hard_symbol_count_enable(mss::ON);

    return __startTdScrub_mca( i_mcaChip, i_rank, stopCond, SLAVE_RANK );
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsRuntime<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                    const MemRank & i_rank,
                                    bool i_countAllCes )
{
    mss::mcbist::stop_conditions stopCond;
    stopCond.set_nce_hard_symbol_count_enable(mss::ON);

    // If the TPS false alarms count is one or more, enable per-symbol counters
    // for soft and intermittent CEs.
    if ( i_countAllCes )
    {
        stopCond.set_nce_soft_symbol_count_enable(mss::ON)
                .set_nce_inter_symbol_count_enable(mss::ON);
    }

    return __startTdScrub_mca( i_mcaChip, i_rank, stopCond, SLAVE_RANK );
}

//##############################################################################
//##                   Centaur Maintenance Command wrappers
//##############################################################################

template<>
uint32_t startBgScrub<TYPE_MBA>( ExtensibleChip * i_chip,
                                 const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startBgScrub<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Get the MBA fapi target
    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );

    // Get the stop conditions.
    // NOTE: If HBRT_PRD is not configured, we want to use the defaults so that
    //       background scrubbing never stops.
    uint32_t stopCond = mss_MaintCmd::NO_STOP_CONDITIONS;

    #ifdef CONFIG_HBRT_PRD

    stopCond = mss_MaintCmd::STOP_ON_HARD_NCE_ETE           |
               mss_MaintCmd::STOP_ON_INT_NCE_ETE            |
               mss_MaintCmd::STOP_ON_SOFT_NCE_ETE           |
               mss_MaintCmd::STOP_ON_RETRY_CE_ETE           |
               mss_MaintCmd::STOP_ON_MPE                    |
               mss_MaintCmd::STOP_ON_UE                     |
               mss_MaintCmd::STOP_IMMEDIATE                 |
               mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

    #endif

    // Get the command speed.
    mss_MaintCmd::TimeBaseSpeed cmdSpeed = enableFastBgScrub()
                                            ? mss_MaintCmd::FAST_MED_BW_IMPACT
                                            : mss_MaintCmd::BG_SCRUB;
    do
    {
        // Get the first address of the given rank.
        fapi2::buffer<uint64_t> saddr, eaddr;
        o_rc = getMemAddrRange<TYPE_MBA>( i_chip, i_rank, saddr, eaddr,
                                          SLAVE_RANK );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // Set the required thresholds for background scrubbing.
        o_rc = setBgScrubThresholds<TYPE_MBA>( i_chip, i_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBgScrubThresholds(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_MBA>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Start the background scrub command.
        mss_TimeBaseScrub cmd { fapiTrgt, saddr, eaddr, cmdSpeed,
                                stopCond, false };
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, cmd.setupAndExecuteCmd );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "setupAndExecuteCmd() on 0x%08x,0x%02x failed",
                      i_chip->getHuid(), i_rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsRuntime<TYPE_MBA>( ExtensibleChip * i_mbaChip,
                                    const MemRank & i_rank,
                                    bool i_countAllCes )
{
    PRDF_ERR( "function not implemented yet" ); // TODO RTC 157888
    return SUCCESS;
}

//##############################################################################
//##                  Core/cache trace array functions
//##############################################################################

int32_t restartTraceArray(TargetHandle_t i_tgt)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = nullptr;
    TYPE tgtType = getTargetType(i_tgt);
    proc_gettracearray_args taArgs;
    TargetHandle_t l_tgt = nullptr;

    if (TYPE_CORE == tgtType)
    {
        taArgs.trace_bus = PROC_TB_CORE0;
        l_tgt = i_tgt;
    }
    else if (TYPE_EQ == tgtType)
    {
        taArgs.trace_bus = PROC_TB_L20;
        // HWP requires an EX tgt here, all the traces within EQ/EX start/stop
        // so it doesn't matter which one, just use the first
        TargetHandleList lst = getConnected(i_tgt, TYPE_EX);
        if (lst.size() > 0)
        {
            l_tgt = lst[0];
        }
        else
        {
            PRDF_ERR( "restartTraceArray: no functional EX for EQ 0x%08x",
                      getHuid(i_tgt) );
            return FAIL;
        }
    }
    else
    {
        PRDF_ASSERT(false); // should only call this on EC/EQ/EX
    }

    taArgs.stop_pre_dump = false;
    taArgs.ignore_mux_setting = true;
    taArgs.collect_dump = false;
    taArgs.reset_post_dump = true;
    taArgs.restart_post_dump = true; //Restart all chiplet trace arrays

    fapi2::variable_buffer taData;

    fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES> fapiTrgt (l_tgt);
    FAPI_INVOKE_HWP( err,
                     p9_proc_gettracearray,
                     fapiTrgt,
                     taArgs,
                     taData);

    if(NULL != err)
    {
        PRDF_ERR( "[PlatServices::RestartTraceArray] HUID: 0x%08x"
                  "RestartTraceArray failed", getHuid(i_tgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    return o_rc;
}

//------------------------------------------------------------------------------

// For handling DEADMAN timer callouts (FSP uses HWSV routine)
void deadmanTimerFFDC( TargetHandle_t  i_target, STEP_CODE_DATA_STRUCT & io_sc )
{
    // Hostboot Code - no HWSV is running here ( self_th_1 )
    io_sc.service_data->SetCallout( i_target, MRU_MED );
    io_sc.service_data->SetThresholdMaskId(0);
} // end deadmanTimerFFDC

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

