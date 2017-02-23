/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices.C $                   */
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
    #ifdef __HOSTBOOT_RUNTIME

    return false; // Should never have an FSP when using HBRT.

    #else

    return INITSERVICE::spBaseServicesEnabled();

    #endif
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

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t getMasterCore( TARGETING::TargetHandle_t i_procTgt )
{
    #define PRDF_FUNC "[PlatServices::getMasterCore] "

    PRDF_ERR( PRDF_FUNC "MasterCore info not available in hostboot: PROC = "
              "0x%08x ",getHuid( i_procTgt ) );
    return NULL;

    #undef PRDF_FUNC
}

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
    mss::mcbist::stop_conditions stopCond;
    stopCond.set_thresh_nce_int(1)
            .set_thresh_nce_soft(1)
            .set_thresh_nce_hard(1)
            .set_pause_on_mpe(mss::ON)
            .set_pause_on_ue(mss::ON)
            .set_nce_hard_symbol_count_enable(mss::ON);

    // In MNFG mode, stop on RCE_ETE to get an accurate callout for IUEs.
    if ( mfgMode() ) stopCond.set_thresh_rce(1);

    // Get the scrub speed.
    mss::mcbist::speed scrubSpeed = enableFastBgScrub() ? mss::mcbist::LUDICROUS
                                                        : mss::mcbist::BG_SCRUB;

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

        // Start the background scrub command.
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, memdiags::background_scrub, fapiTrgt, stopCond,
                         scrubSpeed, saddr );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "memdiags::background_scrub(0x%08x,%d) failed",
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
uint32_t startBgScrub<TYPE_MCBIST>( ExtensibleChip * i_mcaChip,
                                    const MemRank & i_rank )
{
    return startBgScrub<TYPE_MCA>( i_mcaChip, i_rank );
}

//------------------------------------------------------------------------------

uint32_t __startTdScrub_mca( ExtensibleChip * i_mcaChip,
                             mss::mcbist::address i_saddr,
                             mss::mcbist::address i_eaddr,
                             const mss::mcbist::stop_conditions & i_stopCond )
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

        // Start the super fast read command.
        errlHndl_t errl;
        FAPI_INVOKE_HWP( errl, memdiags::targeted_scrub, fapiTrgt, i_stopCond,
                         i_saddr, i_eaddr, mss::mcbist::NONE );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "memdiags::targeted_scrub(0x%08x) failed",
                      mcbChip->getHuid() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t __startTdScrubMaster_mca( ExtensibleChip * i_mcaChip,
                              const MemRank & i_rank,
                              const mss::mcbist::stop_conditions & i_stopCond )
{
    // Get the address rank of the master rank.
    uint32_t port = i_mcaChip->getPos() % MAX_MCA_PER_MCBIST;
    mss::mcbist::address saddr, eaddr;
    mss::mcbist::address::get_mrank_range( port,
                                           i_rank.getDimmSlct(),
                                           i_rank.getRankSlct(),
                                           saddr, eaddr );

    return __startTdScrub_mca( i_mcaChip, saddr, eaddr, i_stopCond );
}

//------------------------------------------------------------------------------

uint32_t __startTdScrubSlave_mca( ExtensibleChip * i_mcaChip,
                              const MemRank & i_rank,
                              const mss::mcbist::stop_conditions & i_stopCond )
{
    // Get the address rank of the slave rank.
    uint32_t port = i_mcaChip->getPos() % MAX_MCA_PER_MCBIST;
    mss::mcbist::address saddr, eaddr;
    mss::mcbist::address::get_srank_range( port,
                                           i_rank.getDimmSlct(),
                                           i_rank.getRankSlct(),
                                           i_rank.getSlave(),
                                           saddr, eaddr );

    return __startTdScrub_mca( i_mcaChip, saddr, eaddr, i_stopCond );
}

//------------------------------------------------------------------------------

template<>
uint32_t startVcmPhase1<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;

    return __startTdScrubMaster_mca( i_mcaChip, i_rank, stopCond );
}

//------------------------------------------------------------------------------

template<>
uint32_t startVcmPhase2<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;

    return __startTdScrubMaster_mca( i_mcaChip, i_rank, stopCond );
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsPhase1<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;
    stopCond.set_nce_soft_symbol_count_enable(mss::ON)
            .set_nce_inter_symbol_count_enable(mss::ON);

    return __startTdScrubSlave_mca( i_mcaChip, i_rank, stopCond );
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsPhase2<TYPE_MCA>( ExtensibleChip * i_mcaChip,
                                   const MemRank & i_rank )
{
    mss::mcbist::stop_conditions stopCond;
    stopCond.set_nce_hard_symbol_count_enable(mss::ON);

    return __startTdScrubSlave_mca( i_mcaChip, i_rank, stopCond );
}

//##############################################################################
//##                   Centaur Maintenance Command wrappers
//##############################################################################

template<>
uint32_t startBgScrub<TYPE_MBA>( ExtensibleChip * i_mbaChip,
                                 const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startBgScrub<TYPE_MBA>] "

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

template<>
uint32_t startVcmPhase1<TYPE_MBA>( ExtensibleChip * i_mbaChip,
                                   const MemRank & i_rank )
{
    PRDF_ERR( "function not implemented yet" ); // TODO RTC 136126
    return SUCCESS;
}

//------------------------------------------------------------------------------

template<>
uint32_t startVcmPhase2<TYPE_MBA>( ExtensibleChip * i_mbaChip,
                                   const MemRank & i_rank )
{
    PRDF_ERR( "function not implemented yet" ); // TODO RTC 136126
    return SUCCESS;
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsPhase1<TYPE_MBA>( ExtensibleChip * i_mbaChip,
                                   const MemRank & i_rank )
{
    PRDF_ERR( "function not implemented yet" ); // TODO RTC 136126
    return SUCCESS;
}

//------------------------------------------------------------------------------

template<>
uint32_t startTpsPhase2<TYPE_MBA>( ExtensibleChip * i_mbaChip,
                                   const MemRank & i_rank )
{
    PRDF_ERR( "function not implemented yet" ); // TODO RTC 136126
    return SUCCESS;
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

