/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <prdfRegisterCache.H>

#include <prdfCenMbaDataBundle.H>
#include <prdfP9McbistDataBundle.H>
#include <prdfOcmbDataBundle.H>
#include <prdfMemScrubUtils.H>

#include <iipServiceDataCollector.h>
#include <UtilHash.H>

#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <initservice/initserviceif.H>
#include <devicefw/userif.H>
#include <prdfHomRegisterAccess.H>
#include <ibscomreasoncodes.H>
#include <scom/scomreasoncodes.H>
#include <p9_proc_gettracearray.H>
#include <fapi2_spd_access.H>
#include <p9c_mss_maint_cmds.H>
#include <prdfParserUtils.H>
#include <p9c_mss_rowRepairFuncs.H>
#include <errl/errludlogregister.H>

#include <hwp_wrappers.H>

#ifdef CONFIG_NVDIMM
#include <nvdimm.H>
#endif

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

bool isSpConfigFsp()
{
    return INITSERVICE::spBaseServicesEnabled();
}

//------------------------------------------------------------------------------

uint32_t getScom(TARGETING::TargetHandle_t i_target, BitString& io_bs,
                   uint64_t i_address)
{
    errlHndl_t errl = nullptr;
    uint32_t rc = SUCCESS;
    size_t bsize = (io_bs.getBitLen()+7)/8;
    CPU_WORD* buffer = io_bs.getBufAddr();

    errl = deviceRead(i_target, buffer, bsize, DEVICE_SCOM_ADDRESS(i_address));

    if ( nullptr != errl )
    {
        bool doRetry = false;

        #ifdef __HOSTBOOT_RUNTIME

        // We don't have a good mechanism at this time to determine if the SCOM
        // failed because of a channel failure. So we will just assume any SCOM
        // error on the Centaur means there is a channel failure and that we
        // will need to retry.
        if ( SCOM::SCOM_RUNTIME_HYP_ERR == errl->reasonCode() &&
             ( (TYPE_MEMBUF == getTargetType(i_target)) ||
               (TYPE_MBA    == getTargetType(i_target)) ) )
        {
            doRetry = true;
        }

        #else

        // An inband SCOM failure likely means the memory channel has failed.
        // Hostboot will have switched over to FSI SCOMs. So retry.
        if ( IBSCOM::IBSCOM_BUS_FAILURE == errl->reasonCode() )
        {
            doRetry = true;
        }

        #endif

        if ( doRetry )
        {
            PRDF_INF( "deviceRead(0x%08x,0x%016x) failed with reason code "
                      "0x%04x, retrying...", PlatServices::getHuid(i_target),
                      i_address, errl->reasonCode() );

            PRDF_SET_ERRL_SEV( errl, ERRL_SEV_INFORMATIONAL );
            PRDF_COMMIT_ERRL(  errl, ERRL_ACTION_HIDDEN     );

            errl = deviceRead( i_target, buffer, bsize,
                               DEVICE_SCOM_ADDRESS(i_address) );
        }
    }

    if ( nullptr != errl )
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
            errl = nullptr;
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

//------------------------------------------------------------------------------
uint32_t getSpdData(TARGETING::TargetHandle_t i_target,
                      uint8_t *& o_data,
                      size_t & o_len)
{
#define PRDF_FUNC "[PlatServices::getSPDdata] "
    uint32_t o_rc = SUCCESS;
    errlHndl_t l_errl = nullptr;

    o_len = 0;

    const fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_fapi2_dimm(i_target);

    do {
      // SPD interface call with NULL blob to get size data
      FAPI_INVOKE_HWP(l_errl, fapi2::getSPD, l_fapi2_dimm, NULL, o_len);

      // Check for a valid size returned without an error
      if(nullptr != l_errl)
      {
          PRDF_ERR( PRDF_FUNC "Failed to get SPD size from DIMM with HUID=0x%x",
                    TARGETING::get_huid(i_target) );
          PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );

          o_rc = FAIL;
          break;
      }
      else if (o_len == 0)
      {
         PRDF_ERR( PRDF_FUNC "SPD size data of DIMM with HUID=0x%x returned 0",
                    TARGETING::get_huid(i_target) );
         o_rc = FAIL;
         break;
      }

      //  allocate the blob data of mem size length to hold data
      o_data = reinterpret_cast<uint8_t *>(malloc(o_len));
      memset(o_data, 0, o_len);

      FAPI_INVOKE_HWP(l_errl, fapi2::getSPD, l_fapi2_dimm, o_data, o_len);
      if ( nullptr != l_errl )
      {
          PRDF_ERR( PRDF_FUNC "Failed to read data from DIMM with HUID= 0x%x",
                    TARGETING::get_huid(i_target) );
          PRDF_COMMIT_ERRL( l_errl, ERRL_ACTION_REPORT );
          o_rc = FAIL;
          break;
      }
    } while (0);

    return o_rc;
#undef PRDF_FUNC
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
                 const uint16_t i_wordAddr,
                 uint32_t & o_data)
{
    #define PRDF_FUNC "[PlatServices::getCfam] "

    int32_t rc = SUCCESS;

    uint16_t byteAddr = (i_wordAddr & 0xfe00) | ((i_wordAddr & 0x01ff) * 4);

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
                          DEVICE_FSI_ADDRESS((uint64_t) byteAddr));
        if (errH)
        {
            rc = FAIL;
            PRDF_ERR( PRDF_FUNC "chip: 0x%.8X, failed to get cfam byte addr: "
                      "0x%X", i_chip->GetId(), byteAddr );
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
                            TARGETING::TYPE i_connType)
{
    return nullptr;
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
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          mss::mcbist::address & o_startAddr,
                                          mss::mcbist::address & o_endAddr,
                                          AddrRangeType i_rangeType )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange<TYPE_OCMB_CHIP>] "

    #ifdef CONFIG_AXONE

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    // TODO RTC 210072 - support for multiple ports
    if ( SLAVE_RANK == i_rangeType )
    {
        FAPI_CALL_HWP_NORETURN( mss::mcbist::address::get_srank_range,
                                0, i_rank.getDimmSlct(),
                                i_rank.getRankSlct(), i_rank.getSlave(),
                                o_startAddr, o_endAddr );
    }
    else if ( MASTER_RANK == i_rangeType )
    {
        FAPI_CALL_HWP_NORETURN( mss::mcbist::address::get_mrank_range,
                                0, i_rank.getDimmSlct(),
                                i_rank.getRankSlct(), o_startAddr, o_endAddr );
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "unsupported range type %d", i_rangeType );
        PRDF_ASSERT(false);
    }

    #endif

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
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          MemAddr & o_startAddr,
                                          MemAddr & o_endAddr,
                                          AddrRangeType i_rangeType )
{
    mss::mcbist::address saddr, eaddr;
    uint32_t o_rc = getMemAddrRange<TYPE_OCMB_CHIP>( i_chip, i_rank, saddr,
                                                     eaddr, i_rangeType );
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
        o_endAddr   = MemAddr::fromMaintEndAddr<TYPE_MBA>( (uint64_t)eaddr );
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

template
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          mss::mcbist::address & o_startAddr,
                                          mss::mcbist::address & o_endAddr,
                                          uint8_t i_dimmSlct );

template
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          MemAddr & o_startAddr,
                                          MemAddr & o_endAddr,
                                          uint8_t i_dimmSlct );

//------------------------------------------------------------------------------

template<>
bool isRowRepairEnabled<TYPE_MBA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::isRowRepairEnabled<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    bool o_isEnabled = false;

    do
    {
        // Don't do row repair if DRAM repairs is disabled.
        if ( areDramRepairsDisabled() ) break;

        // The HWP will check both DIMMs on rank pair. So we could can use
        // either one.
        TargetHandleList list = getConnectedDimms( i_chip->getTrgt(), i_rank );
        PRDF_ASSERT( !list.empty() );

        TargetHandle_t dimm = list.front();

        errlHndl_t errl = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> fapiDimm(dimm);
        FAPI_INVOKE_HWP( errl, is_sPPR_supported, fapiDimm, o_isEnabled );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "is_sPPR_supported(0x%08x) failed",
                      getHuid(dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_isEnabled = false; // just in case
            break;
        }

    } while (0);

    return o_isEnabled;

    #undef PRDF_FUNC
}

template<>
bool isRowRepairEnabled<TYPE_MCA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    return false; // Not supported at this time.
}

template<>
bool isRowRepairEnabled<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                         const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::isRowRepairEnabled<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    bool o_isEnabled = false;
    /* TODO RTC 199035
    do
    {
        // Don't do row repair if DRAM repairs is disabled.
        if ( areDramRepairsDisabled() ) break;

        // The HWP will check both DIMMs on rank pair. So we could can use
        // either one.
        TargetHandleList list = getConnectedDimms( i_chip->getTrgt(), i_rank );
        PRDF_ASSERT( !list.empty() );

        TargetHandle_t dimm = list.front();

        errlHndl_t errl = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> fapiDimm(dimm);
        FAPI_INVOKE_HWP( errl, is_sPPR_supported, fapiDimm, o_isEnabled );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "is_sPPR_supported(0x%08x) failed",
                      getHuid(dimm) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_isEnabled = false; // just in case
            break;
        }

    }while(0);
    */

    return o_isEnabled;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

#ifdef CONFIG_NVDIMM
uint32_t nvdimmNotifyProtChange( TARGETING::TargetHandle_t i_target,
                                 const NVDIMM::nvdimm_protection_t i_state )
{
    #define PRDF_FUNC "[PlatServices::nvdimmNotifyProtChange] "

    uint32_t o_rc = SUCCESS;

    errlHndl_t errl = NVDIMM::notifyNvdimmProtectionChange( i_target, i_state );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "NVDIMM::notifyNvdimmProtectionChange(0x%08x) "
                  "failed.", getHuid(i_target) );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC

}

void nvdimmAddFfdc( TARGETING::TargetHandle_t i_nvdimm, errlHndl_t & io_errl  )
{
    #define PRDF_FUNC "[PlatServices::nvdimmAddFfdc] "
    // Add Page 4 Regs and Vendor Log using external Hostboot interfaces.
    NVDIMM::nvdimmAddPage4Regs( i_nvdimm, io_errl );
    NVDIMM::nvdimmAddVendorLog( i_nvdimm, io_errl );

    // Add PRD specific registers relevant to runtime NVDIMM analysis.
    const uint16_t regList[] =
    {
        // Module health registers
        NVDIMM::i2cReg::MODULE_HEALTH,
        NVDIMM::i2cReg::MODULE_HEALTH_STATUS0,
        NVDIMM::i2cReg::MODULE_HEALTH_STATUS1,

        // Threshold status registers
        NVDIMM::i2cReg::ERROR_THRESHOLD_STATUS,
        NVDIMM::i2cReg::WARNING_THRESHOLD_STATUS,

        // ES_TEMP registers
        NVDIMM::i2cReg::ES_TEMP0,
        NVDIMM::i2cReg::ES_TEMP1,
        NVDIMM::i2cReg::ES_TEMP_WARNING_HIGH_THRESHOLD0,
        NVDIMM::i2cReg::ES_TEMP_WARNING_HIGH_THRESHOLD1,
        NVDIMM::i2cReg::ES_TEMP_WARNING_LOW_THRESHOLD0,
        NVDIMM::i2cReg::ES_TEMP_WARNING_LOW_THRESHOLD1,

        // NVM Lifetime registers
        NVDIMM::i2cReg::NVM_LIFETIME,
        NVDIMM::i2cReg::NVM_LIFETIME_ERROR_THRESHOLD,
        NVDIMM::i2cReg::NVM_LIFETIME_WARNING_THRESHOLD,

        // ES Lifetime registers
        NVDIMM::i2cReg::ES_LIFETIME,
        NVDIMM::i2cReg::ES_LIFETIME_ERROR_THRESHOLD,
        NVDIMM::i2cReg::ES_LIFETIME_WARNING_THRESHOLD,

        // Status registers
        NVDIMM::i2cReg::ERASE_STATUS,
        NVDIMM::i2cReg::ARM_STATUS,
        NVDIMM::i2cReg::SET_EVENT_NOTIFICATION_STATUS,
    };

    ERRORLOG::ErrlUserDetailsLogRegister regUd( i_nvdimm );
    for ( auto const & reg : regList )
    {
        // NVDIMM register size = 1 byte
        size_t NVDIMM_SIZE = 1;

        uint8_t data = 0;
        errlHndl_t errl = deviceRead( i_nvdimm, &data, NVDIMM_SIZE,
                                      DEVICE_NVDIMM_ADDRESS(reg) );
        if ( errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to read register 0x%X on "
                      "NVDIMM HUID: 0x%08x", reg, getHuid(i_nvdimm) );
            // Don't commit, just delete the error and continue
            delete errl; errl = nullptr;
            continue;
        }
        // Only add registers that have non-zero data.
        if ( 0 == data ) continue;

        regUd.addDataBuffer( &data, sizeof(data), DEVICE_NVDIMM_ADDRESS(reg) );
    }

    regUd.addToLog( io_errl );

    #undef PRDF_FUNC
}

#endif

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

    #ifdef __HOSTBOOT_RUNTIME
    // Starting a new command. Clear the UE and CE scrub stop counters
    getMcbistDataBundle( mcbChip )->iv_ueStopCounter.reset();
    getMcbistDataBundle( mcbChip )->iv_ceStopCounter.reset();
    #endif

    // Get the stop conditions.
    // NOTE: If HBRT_PRD is not configured, we want to use the defaults so that
    //       background scrubbing never stops.
    mss::mcbist::stop_conditions<> stopCond;

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

#ifndef CONFIG_AXONE
template<>
uint32_t startTdScrub<TYPE_MCA>( ExtensibleChip * i_chip,
        const MemRank & i_rank, AddrRangeType i_rangeType,
        mss::mcbist::stop_conditions<mss::mc_type::NIMBUS> i_stopCond )
{
    #define PRDF_FUNC "[PlatServices::startTdScrub<TYPE_MCA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Set stop-on-AUE for all target scrubs. See explanation in startBgScrub()
    // for the reasons why.
    i_stopCond.set_pause_on_aue(mss::ON);

    do
    {
        // Get the address range of the given rank.
        mss::mcbist::address saddr, eaddr;
        o_rc = getMemAddrRange<TYPE_MCA>( i_chip, i_rank, saddr, eaddr,
                                          i_rangeType );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // Get the MCBIST fapi target.
        ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );
        fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt (mcbChip->getTrgt());

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_MCBIST>( mcbChip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Start targeted scrub command.
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, mss::memdiags::targeted_scrub, fapiTrgt,
                         i_stopCond, saddr, eaddr, mss::mcbist::NONE );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss::memdiags::targeted_scrub(0x%08x,0x%02x) "
                      "failed", mcbChip->getHuid(),  i_rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
#endif

//##############################################################################
//##                   Centaur Maintenance Command wrappers
//##############################################################################

template<TARGETING::TYPE T>
uint32_t __startScrub( ExtensibleChip * i_chip, const MemRank & i_rank,
                       AddrRangeType i_rangeType, uint32_t i_stopCond,
                       mss_MaintCmd::TimeBaseSpeed i_cmdSpeed );

template<>
uint32_t __startScrub<TYPE_MBA>( ExtensibleChip * i_chip,
                                 const MemRank & i_rank,
                                 AddrRangeType i_rangeType,
                                 uint32_t i_stopCond,
                                 mss_MaintCmd::TimeBaseSpeed i_cmdSpeed )
{
    #define PRDF_FUNC "[PlatServices::__startScrub<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );
    errlHndl_t errl = nullptr;

    do
    {
        #ifdef __HOSTBOOT_RUNTIME
        // Starting a new command. So clear the resume counter.
        getMbaDataBundle(i_chip)->iv_scrubResumeCounter.reset();
        #endif

        // Get the address range of the given rank.
        fapi2::buffer<uint64_t> saddr, eaddr;
        o_rc = getMemAddrRange<TYPE_MBA>( i_chip, i_rank, saddr, eaddr,
                                          i_rangeType );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
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

        // Start the scrub command.
        mss_TimeBaseScrub cmd { fapiTrgt, saddr, eaddr, i_cmdSpeed,
                                i_stopCond, false };
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
        // Set the required thresholds for background scrubbing.
        o_rc = setBgScrubThresholds<TYPE_MBA>( i_chip, i_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBgScrubThresholds(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = __startScrub<TYPE_MBA>( i_chip, i_rank, SLAVE_RANK, stopCond,
                                       cmdSpeed );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t startTdScrub<TYPE_MBA>( ExtensibleChip * i_chip,
                                 const MemRank & i_rank,
                                 AddrRangeType i_rangeType,
                                 uint32_t i_stopCond )
{
    #define PRDF_FUNC "[PlatServices::startTdScrub<TYPE_MBA>] "

    #ifndef __HOSTBOOT_RUNTIME // IPL only
    PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.
    #endif

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    // Make sure there is a command complete attention when the command stops.
    i_stopCond |= mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

    // Make sure the command stops on the end address if there are no errors.
    i_stopCond |= mss_MaintCmd::STOP_ON_END_ADDRESS;

    // IPL:
    //   IUEs (reported via RCE ETE) are reported as UEs during read operations.
    //   Therefore, we will treat IUEs like UEs for scrub operations simply to
    //   maintain consistency during all of Memory Diagnostics. Note that MDIA
    //   sets the threshold to 1 when it starts the first command on this MBA
    //   and that threshold should never change throughout all of Memory
    //   Diagnostics.
    // Runtime:
    //   The runtime strategy for IUEs (reported via RCE ETE) is slightly
    //   different than IPL. For the most part we want to ignore them. However,
    //   we must have a threshold just incase they are causing problems. Note
    //   that the threshold this is set (field:2047, mnfg:1) when background
    //   scrubbing is started and that threshold should never change throughout
    //   all of runtime diagnostics.

    i_stopCond |= mss_MaintCmd::STOP_ON_RETRY_CE_ETE;

    // Default speed is to run as fast as possible.
    mss_MaintCmd::TimeBaseSpeed cmdSpeed = mss_MaintCmd::FAST_MAX_BW_IMPACT;

    #ifdef __HOSTBOOT_RUNTIME

    // There is a Centaur bug preventing us from running at full speed because
    // it will reduce mainline bandwidth to almost 10%. Customers won't like
    // this. So we will have to use a slower speed.
    if ( !enableFastBgScrub() ) cmdSpeed = mss_MaintCmd::FAST_MIN_BW_IMPACT;

    #endif

    return __startScrub<TYPE_MBA>( i_chip, i_rank, i_rangeType, i_stopCond,
                                   cmdSpeed );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE>
uint32_t __incMaintAddr( ExtensibleChip * i_chip, MemAddr & o_addr );

template<>
uint32_t __incMaintAddr<TYPE_MBA>( ExtensibleChip * i_chip, MemAddr & o_addr )
{
    #define PRDF_FUNC "[PlatServices::__incMaintAddr<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;

    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );
    errlHndl_t errl = nullptr;

    do
    {
        // Increment the current maintenance address.
        mss_IncrementAddress incCmd { fapiTrgt };
        FAPI_INVOKE_HWP( errl, incCmd.setupAndExecuteCmd );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss_IncrementAddress setupAndExecuteCmd() on "
                      "0x%08x failed", i_chip->getHuid() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
            break;
        }

        // Clear the maintenance FIRs again. This time do not clear the CE
        // counters.
        o_rc = clearEccFirs<TYPE_MBA>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccFirs(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = clearCmdCompleteAttn<TYPE_MBA>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearCmdCompleteAttn(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // The address register has been updated so we need to clear our cache
        // to ensure we can do a new read.
        SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MBMACA" );
        RegDataCache::getCachedRegisters().flush( i_chip, reg );

        // Read the new start address from hardware.
        o_rc = getMemMaintAddr<TYPE_MBA>( i_chip, o_addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE>
uint32_t __incMaintRowAddr( ExtensibleChip * i_chip, MemAddr & o_addr );

template<>
uint32_t __incMaintRowAddr<TYPE_MBA>( ExtensibleChip * i_chip,
                                      MemAddr & o_addr )
{
    #define PRDF_FUNC "[PlatServices::__incMaintRowAddr<TYPE_MBA>] "

    // This is a special case for row repair where we want to increment to the
    // next row instead of the next address.

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the current address.
        MemAddr saddr;
        o_rc = getMemMaintAddr<TYPE_MBA>( i_chip, saddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Get the end address.
        MemAddr eaddr;
        o_rc = getMemMaintEndAddr<TYPE_MBA>( i_chip, eaddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Start building the new address.
        uint32_t smaster = saddr.getRank().getMaster();
        uint32_t sslave  = saddr.getRank().getSlave();
        uint32_t srow    = saddr.getRow();

        // First, check if we are on the last row on a slave rank.
        if ( srow == eaddr.getRow() )
        {
            // If the slave ranks are the same, this would be a bug because we
            // should have already checked if we were on the last row of this
            // master rank before calling this procedure.
            PRDF_ASSERT( sslave < eaddr.getRank().getSlave() );

            // We've reached the last row on a slave rank. So we need to
            // increment the slave rank and zero out row.
            sslave++;
            srow = 0;
        }
        else
        {
            // We have not reached the end of a slave rank. So just increment
            // the row.
            srow++;
        }

        // Get the new start address with the new rank and row. Also, zero out
        // the bank and column.
        saddr = MemAddr( MemRank(smaster, sslave), 0, srow, 0 );

        // Write the address to hardware.
        o_rc = setMemMaintAddr<TYPE_MBA>( i_chip, saddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Return the new address.
        o_addr = saddr;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t incMaintAddr<TYPE_MBA>( ExtensibleChip * i_chip,
                                 MemAddr & o_addr, bool i_incRow )
{

    #define PRDF_FUNC "[PlatServices::incMaintAddr<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    do
    {
        // Manually clear the CE counters based on the error type and clear the
        // maintenance FIRs. Note that we only want to clear counters that are
        // at attention to allow the other CE types the opportunity to reach
        // threshold, if possible.
        o_rc = conditionallyClearEccCounters<TYPE_MBA>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "conditionallyClearEccCounters(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = clearEccFirs<TYPE_MBA>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearEccFirs(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        o_rc = clearCmdCompleteAttn<TYPE_MBA>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearCmdCompleteAttn(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Increment the address as needed.
        o_rc = ( i_incRow ) ? __incMaintRowAddr<TYPE_MBA>( i_chip, o_addr )
                            : __incMaintAddr   <TYPE_MBA>( i_chip, o_addr );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//##                Explorer/Axone Maintenance Command wrappers
//##############################################################################

template<>
uint32_t startBgScrub<TYPE_OCMB_CHIP>( ExtensibleChip * i_ocmb,
                                       const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startBgScrub<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_ocmb->getType() );

    uint32_t o_rc = SUCCESS;

    #ifdef CONFIG_AXONE

    // Get the OCMB fapi target
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt (i_ocmb->getTrgt());

    #ifdef __HOSTBOOT_RUNTIME
    // Starting a new command. Clear the UE and CE scrub stop counters
    getOcmbDataBundle( i_ocmb )->iv_ueStopCounter.reset();
    getOcmbDataBundle( i_ocmb )->iv_ceStopCounter.reset();
    #endif

    // Get the stop conditions.
    // NOTE: If HBRT_PRD is not configured, we want to use the defaults so that
    //       background scrubbing never stops.
    mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> stopCond;

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
        o_rc = getMemAddrRange<TYPE_OCMB_CHIP>( i_ocmb, i_rank, saddr, eaddr,
                                                SLAVE_RANK );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_ocmb->getHuid(), i_rank.getKey() );
            break;
        }

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>( i_ocmb );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_ocmb->getHuid() );
            break;
        }

        // Start the background scrub command.
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, exp_background_scrub, fapiTrgt,
                         stopCond, scrubSpeed, saddr );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "exp_background_scrub(0x%08x,%d) "
                      "failed", i_ocmb->getHuid(), i_rank.getMaster() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

#ifdef CONFIG_AXONE
template<>
uint32_t startTdScrub<TYPE_OCMB_CHIP>(ExtensibleChip * i_chip,
        const MemRank & i_rank, AddrRangeType i_rangeType,
        mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> i_stopCond)
{
    #define PRDF_FUNC "[PlatServices::startTdScrub<TYPE_OCMB_CHIP>] "

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

        // Get the OCMB_CHIP fapi target.
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt(i_chip->getTrgt());

        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Start targeted scrub command.
        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP( errl, exp_targeted_scrub, fapiTrgt,
                         i_stopCond, saddr, eaddr, mss::mcbist::NONE );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "exp_targeted_scrub(0x%08x,0x%02x) "
                      "failed", i_chip->getHuid(),  i_rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
#endif

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

