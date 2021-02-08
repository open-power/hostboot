/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <p10_proc_gettracearray.H>
#include <fapi2_spd_access.H>
#include <prdfParserUtils.H>
#include <fapi2_hwp_executor.H>
#include <errl/errludlogregister.H>

#include <exp_defaults.H>
#include <exp_rank.H>
#include <kind.H>
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
    errlHndl_t errl = nullptr;
    uint32_t rc = SUCCESS;
    size_t bsize = (io_bs.getBitLen()+7)/8;
    CPU_WORD* buffer = io_bs.getBufAddr();

    errl = deviceWrite(i_target, buffer, bsize, DEVICE_SCOM_ADDRESS(i_address));

    if( nullptr != errl )
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
            errl = nullptr;
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
                 const uint16_t i_wordAddr,
                 uint32_t & o_data)
{
    #define PRDF_FUNC "[PlatServices::getCfam] "

    int32_t rc = SUCCESS;

    uint16_t byteAddr = (i_wordAddr & 0xfe00) | ((i_wordAddr & 0x01ff) * 4);

    do
    {
        // HB doesn't allow cfam access on master proc
        TargetHandle_t l_procTgt = i_chip->getTrgt();

        if( TYPE_PROC == getTargetType(l_procTgt) )
        {
            TargetHandle_t l_pMasterProcChip = nullptr;
            targetService().
                masterProcChipTargetHandle( l_pMasterProcChip );

            if( l_pMasterProcChip == l_procTgt )
            {
                PRDF_DTRAC( PRDF_FUNC "can't access CFAM from master "
                            "proc: 0x%.8X", i_chip->GetId() );
                break;
            }
        }

        errlHndl_t errH = nullptr;
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

//##############################################################################
//##                        Fabric/Memory bus functions
//##############################################################################

void calloutBus(STEP_CODE_DATA_STRUCT& io_sc,
                TargetHandle_t i_rxTrgt, TargetHandle_t i_txTrgt,
                HWAS::busTypeEnum i_busType, HWAS::CalloutFlag_t i_flags)
{
    PRDF_ASSERT(nullptr != i_rxTrgt);
    PRDF_ASSERT(nullptr != i_txTrgt);

    // Add both endpoints to the callout list, priority medium group A.
    io_sc.service_data->SetCallout(i_rxTrgt, MRU_MEDA);
    io_sc.service_data->SetCallout(i_txTrgt, MRU_MEDA);

    // Callout the rest of the bus, priority low.
    errlHndl_t errl = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
    PRDF_ASSERT(nullptr != errl);
    errl->addBusCallout(i_rxTrgt, i_txTrgt, i_busType,
                        HWAS::SRCI_PRIORITY_LOW, i_flags);
}

//##############################################################################
//##                        Memory specific functions
//##############################################################################

template<>
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          mss::mcbist::address & o_startAddr,
                                          mss::mcbist::address & o_endAddr,
                                          AddrRangeType i_rangeType )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange<TYPE_OCMB_CHIP>] "

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

    return SUCCESS;

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
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          mss::mcbist::address & o_startAddr,
                                          mss::mcbist::address & o_endAddr,
                                          uint8_t i_dimmSlct );

template
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          MemAddr & o_startAddr,
                                          MemAddr & o_endAddr,
                                          uint8_t i_dimmSlct );


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
//##                Explorer Maintenance Command wrappers
//##############################################################################

template<>
uint32_t startBgScrub<TYPE_OCMB_CHIP>( ExtensibleChip * i_ocmb,
                                       const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startBgScrub<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_ocmb->getType() );

    uint32_t o_rc = SUCCESS;

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

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

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

//##############################################################################
//##                  Core/cache trace array functions
//##############################################################################

int32_t restartTraceArray(TargetHandle_t i_tgt)
{
    int32_t o_rc = SUCCESS;

    PRDF_TRAC( "restartTraceArray currently disabled because of problems "
               "with the p10_proc_gettracearray procedure" );
    /* TODO p10_proc_gettracearray currently not working
    errlHndl_t err = nullptr;
    TYPE tgtType = getTargetType(i_tgt);
    proc_gettracearray_args taArgs;
    TargetHandle_t l_tgt = nullptr;

    // We can use the PROC_TB_L20 trace array bus ID passed into the
    // p10_proc_gettracearray procedure to restart the core trace arrays on
    // all four cores of the EQ. The procedure will take in a core target.
    // Which core you pass in shouldn't matter as it will still restart all
    // the core traces within the EQ.
    taArgs.trace_bus = PROC_TB_L20;

    if (TYPE_CORE == tgtType)
    {
        l_tgt = i_tgt;
    }
    else if (TYPE_EQ == tgtType)
    {
        // It doesn't matter which core we pass in, so just get the first.
        TargetHandleList lst = getConnectedChildren( i_tgt, TYPE_CORE );
        if (lst.size() > 0)
        {
            l_tgt = lst[0];
        }
        else
        {
            PRDF_ERR( "restartTraceArray: no functional CORE for EQ 0x%08x",
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
                     p10_proc_gettracearray,
                     fapiTrgt,
                     taArgs,
                     taData);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::RestartTraceArray] HUID: 0x%08x"
                  "RestartTraceArray failed", getHuid(i_tgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    */

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

