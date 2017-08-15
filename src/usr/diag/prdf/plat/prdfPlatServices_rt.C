/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_rt.C $                */
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
 * @file  prdfPlatServices_rt.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

// Framework includes
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

// Platform includes
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

//------------------------------------------------------------------------------

using namespace TARGETING;

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

void sendPageGardRequest( uint64_t i_systemAddress )
{
    #define PRDF_FUNC "[PlatServices::sendPageGardRequest] "

    do
    {
        if( !g_hostInterfaces || !g_hostInterfaces->memory_error )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() interface is not defined");
            break;
        }

        int32_t rc = g_hostInterfaces->memory_error( i_systemAddress,
                                                      i_systemAddress,
                                                      MEMORY_ERROR_CE );
        if( SUCCESS != rc )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() failed");
            break;
        }
    }while(0);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void sendLmbGardRequest( uint64_t i_systemAddress, bool i_isFetchUE )
{
    //NO-OP for OPAL
}
//------------------------------------------------------------------------------

void sendDynMemDeallocRequest( uint64_t i_startAddr, uint64_t i_endAddr )
{
    #define PRDF_FUNC "[PlatServices::sendDynMemDeallocRequest] "

    do
    {
        if( !g_hostInterfaces || !g_hostInterfaces->memory_error )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() interface is not defined");
            break;
        }

        int32_t rc = g_hostInterfaces->memory_error( i_startAddr,
                                                     i_endAddr,
                                                     MEMORY_ERROR_UE );
        if( SUCCESS != rc )
        {
            PRDF_ERR(PRDF_FUNC " memory_error() failed");
            break;
        }
    }while(0);

    #undef PRDF_FUNC
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

    uint32_t rc = SUCCESS;

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );
/* TODO RTC 157888
    // It is safe to create a dummy command object because runtime commands do
    // not store anything for cleanupCmd() and the stopCmd() function is generic
    // for all command types. Also, since we are only stopping the command, all
    // of the parameters for the command object are junk except for the target.
    ecmdDataBufferBase i_startAddr, i_endAddr;
    mss_TimeBaseScrub cmd { getFapiTarget(i_trgt), i_startAddr, i_endAddr,
                            mss_MaintCmd::FAST_MAX_BW_IMPACT, 0, false };

    errlHndl_t errl = fapi::fapiRcToErrl( cmd.stopCmd() );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "mss_TimeBaseScrub::stop(0x%08x) failed",
                  getHuid(i_trgt) );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        rc = FAIL;
    }
*/

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t resumeBgScrub<TYPE_MBA>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[PlatServices::resumeBgScrub<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    uint32_t rc = SUCCESS;

    PRDF_ERR( PRDF_FUNC "function not implemented yet" );

    /* TODO: RTC 157888 - Not entirely sure how to do this. Will require a inc
     *       command followed by a start command. May need the stop conditions
     *       for the start command. */

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t startVcmPhase1<TYPE_MBA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startVcmPhase1<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    // TODO RTC 157888
    //  - Start a time based scrub.
    //  - If fast scrub is enabled use FAST_MAX_BW_IMPACT speed, otherwise use
    //    FAST_MIN_BW_IMPACT speed.
    //  - Stop on UE.
    //  - Stop on RCE ETE (threshold 2047 field, 1 mnfg).
    //  - The command should stop immediately on error, or at the end of the
    //    master rank if no errors are found.

    PRDF_ERR( "function not implemented yet" );

    return SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t startVcmPhase2<TYPE_MBA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::startVcmPhase2<TYPE_MBA>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    // TODO RTC 157888
    //  - Start a time based scrub.
    //  - If fast scrub is enabled use FAST_MAX_BW_IMPACT speed, otherwise use
    //    FAST_MIN_BW_IMPACT speed.
    //  - Stop on UE.
    //  - Stop on MCE.
    //  - Stop on RCE ETE (threshold 2047 field, 1 mnfg).
    //  - The command should stop immediately on error, or at the end of the
    //    master rank if no errors are found.

    PRDF_ERR( "function not implemented yet" );

    return SUCCESS;

    #undef PRDF_FUNC
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


//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

