/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_rt.C $                */
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
 * @file  prdfPlatServices_rt.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

// Framework includes
#include <prdfErrlUtil.H>
#include <prdfTrace.H>
#include <prdfRegisterCache.H>

// Platform includes
#include <prdfCenMbaDataBundle.H>
#include <prdfMemScrubUtils.H>
#include <prdfPlatServices.H>

// Other includes
#include <runtime/interface.h>
#include <p9_l3err_extract.H>
#include <p9_l2err_extract.H>
#include <p9_l3err_linedelete.H>
#include <p9_l2err_linedelete.H>
#include <p9_proc_gettracearray.H>
#include <pm_common_ext.H>
#include <p9_stop_api.H>
#include <rt_todintf.H>

//------------------------------------------------------------------------------

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

void __dyndealloc( uint64_t i_saddr, uint64_t i_eaddr, MemoryError_t i_type )
{
    #define PRDF_FUNC "[PlatServices::__dyndealloc] "

    do
    {
        if ( !g_hostInterfaces || !g_hostInterfaces->memory_error )
        {
            PRDF_ERR( PRDF_FUNC "memory_error() interface is not defined" );
            break;
        }

        int32_t rc = g_hostInterfaces->memory_error( i_saddr, i_eaddr, i_type );
        if ( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "memory_error() failed" );
            break;
        }

    } while (0);

    #undef PRDF_FUNC
}

void sendPageGardRequest( uint64_t i_saddr )
{
    // Note that both addresses will be the same for a page gard.
    __dyndealloc( i_saddr, i_saddr, MEMORY_ERROR_CE );
}

void sendDynMemDeallocRequest( uint64_t i_saddr, uint64_t i_eaddr )
{
    __dyndealloc( i_saddr, i_eaddr, MEMORY_ERROR_UE );
}

void sendPredDeallocRequest( uint64_t i_saddr, uint64_t i_eaddr )
{
    __dyndealloc( i_saddr, i_eaddr, MEMORY_ERROR_PREDICTIVE );
}

//##############################################################################
//##                    Nimbus Maintenance Command wrappers
//##############################################################################

template<>
uint32_t stopBgScrub<TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[PlatServices::stopBgScrub<TYPE_MCBIST>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    uint32_t rc = SUCCESS;

    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( i_chip->getTrgt() );

    errlHndl_t errl;
    FAPI_INVOKE_HWP( errl, mss::memdiags::stop, fapiTrgt );

    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "mss::memdiags::stop(0x%08x) failed", i_chip->getHuid());
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        rc = FAIL;
    }

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t stopBgScrub<TYPE_MCA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    return stopBgScrub<TYPE_MCBIST>( getConnectedParent(i_chip, TYPE_MCBIST) );
}

//------------------------------------------------------------------------------

template<>
uint32_t resumeBgScrub<TYPE_MCBIST>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[PlatServices::resumeBgScrub<TYPE_MCBIST>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Get the MCBIST fapi target
    fapi2::Target<fapi2::TARGET_TYPE_MCBIST> fapiTrgt ( i_chip->getTrgt() );

    do
    {
        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_MCBIST>( i_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Resume the command on the next address.
        errlHndl_t errl;
        FAPI_INVOKE_HWP( errl, mss::memdiags::continue_cmd, fapiTrgt );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "mss::memdiags::continue_cmd(0x%08x) failed",
                      i_chip->getHuid() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t resumeBgScrub<TYPE_MCA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    return resumeBgScrub<TYPE_MCBIST>(getConnectedParent(i_chip, TYPE_MCBIST));
}

//##############################################################################
//##                   Centaur Maintenance Command wrappers
//##############################################################################

template<>
uint32_t stopBgScrub<TYPE_MBA>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[PlatServices::stopBgScrub<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );
    errlHndl_t errl = nullptr;

    // It is safe to create a dummy command object because runtime commands do
    // not store anything for cleanupCmd() and the stopCmd() function is generic
    // for all command types. Also, since we are only stopping the command, all
    // of the parameters for the command object are junk except for the target.
    fapi2::buffer<uint64_t> startAddr, endAddr;
    mss_TimeBaseScrub cmd { fapiTrgt, startAddr, endAddr,
                            mss_MaintCmd::FAST_MAX_BW_IMPACT, 0, false };
    FAPI_INVOKE_HWP( errl, cmd.stopCmd );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "mss_TimeBaseScrub::stop(0x%08x) failed",
                  i_chip->getHuid() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __resumeScrub( ExtensibleChip * i_chip,
                        AddrRangeType i_rangeType, uint32_t i_stopCond,
                        mss_MaintCmd::TimeBaseSpeed i_cmdSpeed );

template<>
uint32_t __resumeScrub<TYPE_MBA>( ExtensibleChip * i_chip,
                                  AddrRangeType i_rangeType,
                                  uint32_t i_stopCond,
                                  mss_MaintCmd::TimeBaseSpeed i_cmdSpeed )
{
    #define PRDF_FUNC "[PlatServices::__resumeScrub<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    // Make sure there is a command complete attention when the command stops.
    i_stopCond |= mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

    // Make sure the command stops immediately on error or on the end address if
    // there are no errors.
    i_stopCond |= mss_MaintCmd::STOP_IMMEDIATE;
    i_stopCond |= mss_MaintCmd::STOP_ON_END_ADDRESS;

    if ( getMbaDataBundle(i_chip)->iv_scrubResumeCounter.atTh() )
    {
        // We have resumed scrubbing on this rank too many times. We still want
        // the scrub to continue to the end of the rank, if possible, but we
        // need to prevent flooding. So mask off all the CE/UE stop-on-error
        // conditions. Note that there is only one chip mark per rank so we
        // don't need to worry about getting flooded with those attentions.

        i_stopCond &= ~mss_MaintCmd::STOP_ON_HARD_NCE_ETE;
        i_stopCond &= ~mss_MaintCmd::STOP_ON_INT_NCE_ETE;
        i_stopCond &= ~mss_MaintCmd::STOP_ON_SOFT_NCE_ETE;
        i_stopCond &= ~mss_MaintCmd::STOP_ON_RETRY_CE_ETE;
        i_stopCond &= ~mss_MaintCmd::STOP_ON_UE;
    }

    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiTrgt ( i_chip->getTrgt() );
    errlHndl_t errl = nullptr;

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
        MemAddr addr;
        o_rc = getMemMaintAddr<TYPE_MBA>( i_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }
        fapi2::buffer<uint64_t> saddr = addr.toMaintAddr<TYPE_MBA>();

        // Get the end address of the current rank.
        fapi2::buffer<uint64_t> eaddr, junk;
        MemRank rank = addr.getRank();
        o_rc = getMemAddrRange<TYPE_MBA>( i_chip, rank, junk, eaddr,
                                          i_rangeType );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%2x) failed",
                      i_chip->getHuid(), rank.getKey() );
            break;
        }

        // Resume the scrub command.
        mss_TimeBaseScrub scrubCmd { fapiTrgt, saddr, eaddr, i_cmdSpeed,
                                     i_stopCond, false };
        FAPI_INVOKE_HWP( errl, scrubCmd.setupAndExecuteCmd );
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "setupAndExecuteCmd() on 0x%08x,0x%02x failed",
                      i_chip->getHuid(), rank.getKey() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

        // Resume successful. So increment the resume counter.
        getMbaDataBundle(i_chip)->iv_scrubResumeCounter.inc();

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t resumeBgScrub<TYPE_MBA>( ExtensibleChip * i_chip )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t stopCond = mss_MaintCmd::STOP_ON_HARD_NCE_ETE |
                        mss_MaintCmd::STOP_ON_INT_NCE_ETE  |
                        mss_MaintCmd::STOP_ON_SOFT_NCE_ETE |
                        mss_MaintCmd::STOP_ON_RETRY_CE_ETE |
                        mss_MaintCmd::STOP_ON_MPE          |
                        mss_MaintCmd::STOP_ON_UE;

    mss_MaintCmd::TimeBaseSpeed cmdSpeed = enableFastBgScrub()
                                            ? mss_MaintCmd::FAST_MED_BW_IMPACT
                                            : mss_MaintCmd::BG_SCRUB;

    // Because of the Centaur workarounds, we have to limit the number of times
    // a command has been resumed on a rank. Therefore, we must always resume
    // the command to the end of the current slave rank.

    return __resumeScrub<TYPE_MBA>( i_chip, SLAVE_RANK, stopCond, cmdSpeed );
}

//------------------------------------------------------------------------------

template<>
uint32_t resumeTdScrub<TYPE_MBA>( ExtensibleChip * i_chip,
                                  AddrRangeType i_rangeType,
                                  uint32_t i_stopCond )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    mss_MaintCmd::TimeBaseSpeed cmdSpeed = enableFastBgScrub()
                                            ? mss_MaintCmd::FAST_MAX_BW_IMPACT
                                            : mss_MaintCmd::FAST_MIN_BW_IMPACT;

    return __resumeScrub<TYPE_MBA>( i_chip, i_rangeType, i_stopCond, cmdSpeed );
}

//##############################################################################
//##                       Line Delete Functions
//##############################################################################
int32_t extractL3Err( TargetHandle_t i_exTgt,
                      p9_l3err_extract_err_data &o_errorAddr)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = nullptr;
    bool errFound = false;

    fapi2::Target<fapi2::TARGET_TYPE_EX> fapiTrgt (i_exTgt);
    FAPI_INVOKE_HWP( err,
                     p9_l3err_extract,
                     i_exTgt,
                     o_errorAddr,
                     errFound );

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::extractL3Err] huid: 0x%08x failed",
                  getHuid(i_exTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    if ( !errFound )
    {
        PRDF_ERR( "[PlatServices::extractL3Err] huid: 0x%08x No Error Found",
                  getHuid(i_exTgt));
        o_rc = FAIL;
    }

    return o_rc;
}

int32_t l3LineDelete(TargetHandle_t i_exTgt,
                     const p9_l3err_extract_err_data& i_l3_err_data)
{
    using namespace stopImageSection;
    errlHndl_t err = NULL;
    const uint64_t retryCount = 100;

    // Apply Line Delete
    fapi2::Target<fapi2::TARGET_TYPE_EX> fapiTrgt (i_exTgt);
    FAPI_INVOKE_HWP( err,
                     p9_l3err_linedelete,
                     fapiTrgt,
                     i_l3_err_data,
                     retryCount);
    if(NULL != err)
    {
        PRDF_ERR( "[PlatServices::l3LineDelete] HUID: 0x%08x failed",
                  getHuid(i_exTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    // Do HCODE update to preserve line delete
    BitStringBuffer ldData(64);
    ldData.setBit(0); //Trigger
    ldData.setFieldJustify(1, 4, 0x2); // Purge Type (LD=0x2)
    ldData.setFieldJustify(12, 5, i_l3_err_data.member);
    ldData.setFieldJustify(17, 12, i_l3_err_data.hashed_real_address_45_56);

    uint64_t scomVal = (((uint64_t)ldData.getFieldJustify(0, 32)) << 32) |
                        ((uint64_t)ldData.getFieldJustify(32, 32));

    err = RTPM::hcode_update(P9_STOP_SECTION_L3, P9_STOP_SCOM_APPEND,
                             i_exTgt, 0x1001180E, scomVal);
    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::l3LineDelete] HUID: 0x%08x hcode_update "
                  "failed", getHuid(i_exTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    return SUCCESS;
}

int32_t extractL2Err( TargetHandle_t i_exTgt, bool i_ce,
                      p9_l2err_extract_err_data &o_errorAddr)
{
    errlHndl_t err = nullptr;
    bool errFound = false;
    fapi2::variable_buffer ta_data( P9_TRACEARRAY_NUM_ROWS *
                                    P9_TRACEARRAY_BITS_PER_ROW);
    proc_gettracearray_args args;

    args.trace_bus = PROC_TB_L20;
    args.stop_pre_dump = true;
    args.ignore_mux_setting = false;
    args.collect_dump = true;
    args.reset_post_dump = false;
    args.restart_post_dump = false;

    fapi2::Target<fapi2::TARGET_TYPE_EX> fapiTrgt (i_exTgt);

    FAPI_INVOKE_HWP( err,
                     p9_proc_gettracearray,
                     i_exTgt,
                     args,
                     ta_data);
    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::extractL2Err] huid: 0x%08x gettracearray "
                  "failed", getHuid(i_exTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    FAPI_INVOKE_HWP( err,
                     p9_l2err_extract,
                     i_exTgt,
                     ta_data,
                     i_ce ? L2ERR_CE : L2ERR_CE_UE,
                     o_errorAddr,
                     errFound );

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::extractL2Err] huid: 0x%08x failed",
                  getHuid(i_exTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    if ( !errFound )
    {
        PRDF_ERR( "[PlatServices::extractL2Err] huid: 0x%08x No Error Found",
                  getHuid(i_exTgt));
        return FAIL;
    }

    return SUCCESS;
}

int32_t l2LineDelete(TargetHandle_t i_exTgt,
                     const p9_l2err_extract_err_data& i_l2_err_data)
{
    using namespace stopImageSection;
    errlHndl_t err = nullptr;
    const uint64_t retryCount = 100;

    // Apply Line Delete
    fapi2::Target<fapi2::TARGET_TYPE_EX> fapiTrgt (i_exTgt);
    FAPI_INVOKE_HWP( err,
                     p9_l2err_linedelete,
                     fapiTrgt,
                     i_l2_err_data,
                     retryCount);
    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::l2LineDelete] HUID: 0x%08x failed",
                  getHuid(i_exTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    // Do HCODE update to preserve line delete
    BitStringBuffer ldData(64);
    ldData.setBit(0); //Trigger
    ldData.setFieldJustify(1, 4, 0x2); // Purge Type (LD=0x2)
    ldData.setFieldJustify(17, 3, i_l2_err_data.member);
    ldData.setFieldJustify(20, 8, i_l2_err_data.address);
    if (i_l2_err_data.bank)
        ldData.setBit(28);

    uint64_t scomVal = (((uint64_t)ldData.getFieldJustify(0, 32)) << 32) |
                        ((uint64_t)ldData.getFieldJustify(32, 32));

    err = RTPM::hcode_update(P9_STOP_SECTION_L2, P9_STOP_SCOM_APPEND,
                             i_exTgt, 0x1001080E, scomVal);
    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::l2LineDelete] HUID: 0x%08x hcode_update "
                  "failed", getHuid(i_exTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    return SUCCESS;
}


int32_t pmCallout( TargetHandle_t i_tgt,
                   RasAction& o_ra,
                   uint32_t &o_deadCores,
                   std::vector < StopErrLogSectn >& o_ffdcList )
{
    errlHndl_t err = nullptr;
    fapi2::buffer <uint32_t> deadCores;

    //Get homer image buffer
    uint64_t l_homerPhysAddr = 0x0;
    l_homerPhysAddr = i_tgt->getAttr<ATTR_HOMER_PHYS_ADDR>();
    void* l_homerVAddr = HBPM::convertHomerPhysToVirt(i_tgt,l_homerPhysAddr);

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> fapiTrgt (i_tgt);

    FAPI_INVOKE_HWP( err,
                     p9_pm_callout,
                     l_homerVAddr,
                     fapiTrgt,
                     deadCores,
                     o_ffdcList,
                     o_ra );

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::pmCallout] HUID: 0x%08x failed",
                  getHuid(i_tgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    o_deadCores = (uint32_t) deadCores;
    return SUCCESS;
}

void requestNewTODTopology( uint32_t i_oscPos,
                            const TargetHandle_t& i_procOscTgt,
                            const TargetHandleList& i_badChipList,
                            bool i_informPhyp)
{
    #define PRDF_FUNC "[PlatServices::requestNewTODTopology] "
    if ( i_badChipList.size() > 0 || i_procOscTgt != NULL )
    {
        errlHndl_t err = TOD::resetBackupTopology( i_oscPos, i_procOscTgt,
                                               i_badChipList, i_informPhyp );

        if (nullptr != err)
        {
            PRDF_ERR( PRDF_FUNC " failed. oscPos: %d "
                      "oscTgt: 0x%08x, chip blacklist size: %d",
                      i_oscPos, getHuid(i_procOscTgt), i_badChipList.size() );
            PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        }
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "No chips in black list");
    }
    #undef PRDF_FUNC
}

int32_t getTodPortControlReg ( const TARGETING::TargetHandle_t& i_procTgt,
                               bool i_slvPath0,  uint32_t &o_regValue )
{
    #define PRDF_FUNC "[PlatServices::getTodPortControlReg] "
    errlHndl_t err = nullptr;
    int32_t l_rc = SUCCESS;
    TOD::TodChipDataContainer todRegData;
    bool foundChip = false;
    uint32_t ordId = i_procTgt->getAttr<ATTR_ORDINAL_ID>();

    do {
        err = TOD::readTodProcDataFromFile( todRegData );
        if ( err )
        {
            PRDF_ERR( PRDF_FUNC"failed to get TOD reg data from hwsv. "
                               "i_procTgt 0x%08x", getHuid(i_procTgt) );
            l_rc = FAIL;
            PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
            break;
        }

        for ( auto &chip : todRegData )
        {
            if ( chip.header.chipID == ordId )
            {
                o_regValue = i_slvPath0 ? chip.regs.pcrp0 : chip.regs.scrp1;
                foundChip = true;
                break;
            }
        }

        if ( !foundChip )
        {
            PRDF_ERR( PRDF_FUNC"Could not find TOD chip Data for "
                               "i_procTgt 0x%08x with ordId %d",
                                getHuid(i_procTgt), ordId );
            l_rc = FAIL;
        }
    } while (0);

    return l_rc;
    #undef PRDF_FUNC
}
//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

