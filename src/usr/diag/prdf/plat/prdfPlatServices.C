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
#include <prdfMemUtils.H>

#include <iipServiceDataCollector.h>
#include <UtilHash.H>

#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <initservice/initserviceif.H>
#include <devicefw/userif.H>
#include <prdfHomRegisterAccess.H>
#include <mmio/mmio_reasoncodes.H>
#include <scom/scomreasoncodes.H>
#include <p10_proc_gettracearray.H>
#include <fapi2_spd_access.H>
#include <prdfParserUtils.H>
#include <fapi2_hwp_executor.H>
#include <errl/errludlogregister.H>
#include <prdfP10IohsExtraSig.H>

#include <exp_defaults.H>
#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>
#include <exp_deploy_row_repairs.H>
#include <plat_hwp_invoker.H>

#include <p10_rcs_transient_check.H>

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

        // Check the RC to see if the memory channel has failed.
        // Hostboot will have switched over to FSI SCOMs. So retry.
        if ( MMIO::RC_MMIO_CHAN_CHECKSTOP == errl->reasonCode() )
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
                HWAS::busTypeEnum i_busType, HWAS::CalloutFlag_t i_flags,
                PRDpriority i_rxPriority, PRDpriority i_txPriority)
{
    PRDF_ASSERT(nullptr != i_rxTrgt);
    PRDF_ASSERT(nullptr != i_txTrgt);

    // Add both endpoints to the callout list, priority medium group A.
    io_sc.service_data->SetCallout(i_rxTrgt, i_rxPriority);
    io_sc.service_data->SetCallout(i_txTrgt, i_txPriority);

    // Callout the rest of the bus, priority low.
    errlHndl_t errl = ServiceGeneratorClass::ThisServiceGenerator().getErrl();
    PRDF_ASSERT(nullptr != errl);
    errl->addBusCallout(i_rxTrgt, i_txTrgt, i_busType,
                        HWAS::SRCI_PRIORITY_LOW, i_flags);
}

//------------------------------------------------------------------------------

int32_t smp_callout( ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc,
                     uint8_t i_link )
{
    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_IOHS == i_chip->getType());
    PRDF_ASSERT(i_link < MAX_LINK_PER_IOHS);

    // SMP callouts need to determine if the link is down. This can be done by
    // querying the link quality status register. A zero value indicates the
    // link has failed.

    HWAS::CalloutFlag_t calloutFlag = HWAS::FLAG_NONE;

    const char* reg_str = (0 == i_link) ? "IOHS_DLP_LINK0_QUALITY"
                                        : "IOHS_DLP_LINK1_QUALITY";
    SCAN_COMM_REGISTER_CLASS* reg = i_chip->getRegister(reg_str);
    if (SUCCESS == reg->Read() && reg->BitStringIsZero())
    {
        calloutFlag = HWAS::FLAG_LINK_DOWN;

        // Indicate in the multi-signature section that the link has failed.
        io_sc.service_data->AddSignatureList(i_chip->getTrgt(),
                                             PRDFSIG_LinkFailed);

        // Make the error log predictive.
        io_sc.service_data->setPredictive();
    }

    // Get the connected SMPGROUP target.
    TargetHandle_t rxTrgt = getConnectedChild(i_chip->getTrgt(), TYPE_SMPGROUP,
                                              i_link);
    PRDF_ASSERT(nullptr != rxTrgt);

    // Get the peer SMPGROUP target.
    TargetHandle_t txTrgt = getConnectedPeerTarget(rxTrgt);

    // If this SMPGROUP does not have a peer, just callout this target.
    if ( nullptr == txTrgt )
    {
        PRDF_TRAC( "p10_iohs::__smp_callout: No peer SMPGROUP found" );
        io_sc.service_data->SetCallout( rxTrgt, MRU_MED );
        return SUCCESS;
    }

    // Check the IOHS config.
    const auto configMode = i_chip->getTrgt()->getAttr<ATTR_IOHS_CONFIG_MODE>();
    HWAS::busTypeEnum busType = HWAS::FSI_BUS_TYPE; // invalid bus type

    switch( configMode )
    {
        // XBUS
        case fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX:
            busType = HWAS::X_BUS_TYPE;
            break;
        // ABUS
        case fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA:
            busType = HWAS::A_BUS_TYPE;
            break;
        default:
            PRDF_TRAC( "p10_iohs::__smp_callout: invalid IOHS config mode" );
            break;
    }

    if ( HWAS::X_BUS_TYPE == busType || HWAS::A_BUS_TYPE == busType )
    {
        // Callout the entire bus interface.
        calloutBus(io_sc, rxTrgt, txTrgt, busType, calloutFlag);
    }

    return SUCCESS;
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

uint64_t __maskBits( uint64_t i_val, uint64_t i_numBits )
{
    uint64_t mask = (0xffffffffffffffffull >> i_numBits) << i_numBits;
    return i_val & ~mask;
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t __convertMssMcbistAddr( ExtensibleChip * i_chip,
                                 const mss::mcbist::address & i_addr,
                                 MemAddr & o_addr );


template<>
uint32_t __convertMssMcbistAddr<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
        const mss::mcbist::address & i_addr, MemAddr & o_addr )
{
    #define PRDF_FUNC "[PlatServices::__convertMssMcbistAddr] "

    uint32_t o_rc = SUCCESS;

    uint64_t dslct   = i_addr.get_dimm();
    uint64_t rslct   = i_addr.get_master_rank();
    uint64_t srnk    = i_addr.get_slave_rank();
    uint64_t bnk     = i_addr.get_bank();
    uint64_t bnk_grp = i_addr.get_bank_group();
    uint64_t row     = i_addr.get_row();
    uint64_t col     = i_addr.get_column();

    // Adjust the address components based on what is configured.
    bool twoDimmConfig, col3Config;
    uint8_t prnkBits, srnkBits, extraRowBits;
    o_rc = MemUtils::getAddrConfig<TYPE_OCMB_CHIP>( i_chip, dslct,
            twoDimmConfig, prnkBits, srnkBits, extraRowBits, col3Config );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failure from getAddrConfig" );
    }
    else
    {
        // Mask off the non-configured bits. If this address came from
        // hardware,this would not be a problem. However, the get_mrank_range()
        // and get_srank_range() HWPS got lazy, just set the entire fields
        // and did not take into account the actual bit ranges.
        rslct = __maskBits( rslct, prnkBits );
        srnk  = __maskBits( srnk, srnkBits );
        row = (row >> (3-extraRowBits)) << (3-extraRowBits);

        if ( !col3Config )
        {
            col = col & 0xffffffffffffffbfull;
        }
        bnk = (bnk >> 1) << 1; //bnk2 not used
    }

    uint64_t bnkFull = (bnk << 2) | bnk_grp;
    uint64_t prnk    = (dslct << 2) | rslct;
    o_addr = MemAddr ( MemRank ( prnk, srnk ), bnkFull, row, col );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemAddrRange<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank,
                                          MemAddr & o_startAddr,
                                          MemAddr & o_endAddr,
                                          AddrRangeType i_rangeType )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange] "

    uint32_t o_rc = SUCCESS;
    mss::mcbist::address saddr, eaddr;

    do
    {
        uint32_t o_rc = getMemAddrRange<TYPE_OCMB_CHIP>( i_chip, i_rank, saddr,
                                                         eaddr, i_rangeType );
        if ( SUCCESS != o_rc )
        {
            PRDF_TRAC( PRDF_FUNC "Fail from getMemAddrRange(0x%08x,0x%02x,%d)",
                       i_chip->getHuid(), i_rank.getKey(), i_rangeType );
            break;
        }

        o_rc = __convertMssMcbistAddr<TYPE_OCMB_CHIP>( i_chip, saddr,
                                                       o_startAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_TRAC( PRDF_FUNC "Could not convert start address from "
                       "chip=0x%08x, rank=0x%02x.", i_chip->getHuid(),
                       i_rank.getKey() );
            break;
        }

        o_rc = __convertMssMcbistAddr<TYPE_OCMB_CHIP>( i_chip, eaddr,
                                                       o_endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_TRAC( PRDF_FUNC "Could not convert end address from "
                       "chip=0x%08x, rank=0x%02x.", i_chip->getHuid(),
                       i_rank.getKey() );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
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

    // Row repair is supported for OCMBs
    // TODO - change back to true once the below hwp is enabled
    return false;

    #undef PRDF_FUNC
}

template<>
uint32_t deployRowRepair<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::deployRowRepair<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;
    //errlHndl_t errl = nullptr;

    PRDF_TRAC( PRDF_FUNC "exp_deploy_row_repairs not yet enabled" );

    /* TODO

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiOcmb( i_chip->getTrgt() );
    FAPI_INVOKE_HWP( errl, exp_deploy_row_repairs, fapiOcmb );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "exp_deploy_row_repairs(0x%08x) failed",
                  i_chip->getHuid() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    */

    return o_rc;

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

//------------------------------------------------------------------------------

template<>
uint32_t resumeTdScrub<TYPE_OCMB_CHIP>(ExtensibleChip * i_chip,
        mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> i_stopCond)
{
    #define PRDF_FUNC "[PlatServices::resumeTdScrub<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Get the OCMB fapi target
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt ( i_chip->getTrgt() );

    do
    {
        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Resume the command on the next address.
        errlHndl_t errl;
        FAPI_INVOKE_HWP( errl, exp_continue_cmd, fapiTrgt,
            mss::mcbist::end_boundary::DONT_CHANGE, i_stopCond );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "exp_continue_cmd(0x%08x) failed",
                      i_chip->getHuid() );
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
    PRDF_ASSERT(nullptr != i_tgt);
    PRDF_ASSERT(TYPE_CORE == getTargetType(i_tgt));

    int32_t o_rc = SUCCESS;
    errlHndl_t err = nullptr;
    proc_gettracearray_args taArgs;

    // We can use the PROC_TB_L20 trace array bus ID passed into the
    // p10_proc_gettracearray procedure to restart the core trace arrays on
    // all four cores of the EQ. The procedure will take in a core target.
    // Which core you pass in shouldn't matter as it will still restart all
    // the core traces within the EQ.
    taArgs.trace_bus = PROC_TB_L20;

    taArgs.stop_pre_dump = false;
    taArgs.ignore_mux_setting = true;
    taArgs.collect_dump = false;
    taArgs.reset_post_dump = true;
    taArgs.restart_post_dump = true; //Restart all chiplet trace arrays

    fapi2::variable_buffer taData;

    fapi2::Target<PROC_GETTRACEARRAY_TARGET_TYPES> fapiTrgt (i_tgt);
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

//##############################################################################
//##                       RCS/PLL/Clock functions
//##############################################################################

void rcsTransientErrorRecovery(ExtensibleChip* i_chip, uint32_t i_clkPos)
{
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> fapiTrgt{i_chip->getTrgt()};

    // Check for RCS transient errors.
    errlHndl_t errl = nullptr;
    bool transientError = false;
    FAPI_INVOKE_HWP(errl, p10_rcs_transient_check, fapiTrgt, i_clkPos,
                    transientError);
    if (nullptr != errl)
    {
        PRDF_ERR("p10_rcs_transient_check(0x%08x, %d) failed",
                 i_chip->getHuid(), i_clkPos);
        PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
    }
    else
    {
        // Check for hard errors. If so, set the alternate ref clock signal.
        if (!transientError)
        {
            // Set ROOT_CTRL3 bit 3 (OCS0) or bit 7 (OSC1)
            SCAN_COMM_REGISTER_CLASS* reg = i_chip->getRegister("ROOT_CTRL3");
            if (SUCCESS == reg->Read())
            {
                reg->SetBit((0 == i_clkPos) ? 3 : 7);
                reg->Write();
            }
        }
    }
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

