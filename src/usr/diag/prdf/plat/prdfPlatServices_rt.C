/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_rt.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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
#include "targeting/common/util.H"
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

// Platform includes
#include <prdfOcmbDataBundle.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemUtils.H>
#include <prdfPlatServices.H>

// Other includes
#include <runtime/interface.h>
#include <p10_l3err_extract.H>
#include <p10_l2err_extract.H>
#include <p10_l3err_linedelete.H>
#include <p10_l2err_linedelete.H>
#include <p10_proc_gettracearray.H>
#include <pm_common_ext.H>
#include <p10_stop_api.H>

#include <rt_todintf.H>

#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>
#include <plat_hwp_invoker.H>

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
//##                Explorer Maintenance Command wrappers
//##############################################################################

template<>
uint32_t stopBgScrub<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[PlatServices::stopBgScrub<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    uint32_t rc = SUCCESS;

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt ( i_chip->getTrgt() );

    errlHndl_t errl;

    if (isOdysseyOcmb(i_chip->getTrgt()))
    {
        FAPI_INVOKE_HWP( errl, ody_stop, fapiTrgt );
    }
    else
    {
        FAPI_INVOKE_HWP( errl, exp_stop, fapiTrgt );
    }

    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "stop(0x%08x) failed", i_chip->getHuid());
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        rc = FAIL;
    }

    return rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t resumeBgScrub<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[PlatServices::resumeBgScrub<TYPE_OCMB_CHIP>] "

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

        if (isOdysseyOcmb(i_chip->getTrgt()))
        {
            // Check UE and CE stop counters to determine stop conditions
            mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY> stopCond;
            if ( getOcmbDataBundle(i_chip)->iv_ueStopCounter.thReached(io_sc) )
            {
                // If we've reached the limit of UEs we're allowed to stop on
                // per rank, only set the stop on mpe stop condition.
                stopCond.set_pause_on_mpe(mss::ON);
            }
            else if (
                getOcmbDataBundle(i_chip)->iv_ceStopCounter.thReached(io_sc))
            {
                // If we've reached the limit of CEs we're allowed to stop on
                // per rank, set all the normal stop conditions except stop on
                // CE
                stopCond.set_pause_on_aue(mss::ON);

                #ifdef CONFIG_HBRT_PRD

                stopCond.set_pause_on_mpe(mss::ON)
                        .set_pause_on_ue(mss::ON);

                // In MNFG mode, stop on RCE_ETE to get an accurate callout for
                // IUEs
                if ( mfgMode() ) stopCond.set_thresh_rce(1);

                #endif
            }
            else
            {
                // If we haven't reached threshold on the number of UEs or CEs
                // we have stopped on, do not change the stop conditions.
                stopCond = mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>(
                mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>::DONT_CHANGE);
            }

            FAPI_INVOKE_HWP( errl, ody_continue_cmd, fapiTrgt,
                mss::mcbist::end_boundary::DONT_CHANGE, stopCond );
        }
        else
        {
            // Check UE and CE stop counters to determine stop conditions
            mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> stopCond;
            if ( getOcmbDataBundle(i_chip)->iv_ueStopCounter.thReached(io_sc) )
            {
                // If we've reached the limit of UEs we're allowed to stop on
                // per rank, only set the stop on mpe stop condition.
                stopCond.set_pause_on_mpe(mss::ON);
            }
            else if (
                getOcmbDataBundle(i_chip)->iv_ceStopCounter.thReached(io_sc))
            {
                // If we've reached the limit of CEs we're allowed to stop on
                // per rank, set all the normal stop conditions except stop on
                // CE
                stopCond.set_pause_on_aue(mss::ON);

                #ifdef CONFIG_HBRT_PRD

                stopCond.set_pause_on_mpe(mss::ON)
                        .set_pause_on_ue(mss::ON);

                // In MNFG mode, stop on RCE_ETE to get an accurate callout for
                // IUEs
                if ( mfgMode() ) stopCond.set_thresh_rce(1);

                #endif
            }
            else
            {
                // If we haven't reached threshold on the number of UEs or CEs
                // we have stopped on, do not change the stop conditions.
                stopCond = mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>(
                mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>::DONT_CHANGE);
            }

            FAPI_INVOKE_HWP( errl, exp_continue_cmd, fapiTrgt,
                mss::mcbist::end_boundary::DONT_CHANGE, stopCond );
        }

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "continue_cmd(0x%08x) failed",
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
uint32_t restartBgSteerOnNextAddr<TYPE_OCMB_CHIP>(ExtensibleChip * i_ocmb,
    const MemAddr & i_addr, STEP_CODE_DATA_STRUCT & io_sc)
{
    #define PRDF_FUNC "[restartBgSteerOnNextAddr<TYPE_OCMB_CHIP>] "

    PRDF_ASSERT(nullptr != i_ocmb);
    PRDF_ASSERT(TYPE_OCMB_CHIP == i_ocmb->getType());
    PRDF_ASSERT(isOdysseyOcmb(i_ocmb->getTrgt()));

    // Odyssey:
    // Format of mss::mcbist::address, bits in ascending order
    // 0:1   unused
    // 2     port select
    // 3     prank
    // 4:6   srank(0 to 2)
    // 7:24  row(0 to 17)
    // 25:32 col(3 to 10)
    // 33:34 bank(0 to 1)
    // 35:37 bank_group(0 to 2)

    uint32_t o_rc;

    // Pull apart the individual parts of the address;
    uint8_t port    = i_addr.getPort() & 0x1;
    uint8_t prank   = i_addr.getRank().getRankSlct() & 0x1;
    uint8_t srank   = i_addr.getRank().getSlave() & 0x7;
    uint32_t row    = i_addr.getRow() & 0x3ffff;
    uint32_t col    = i_addr.getCol() & 0xff;
    uint32_t bnk    = (i_addr.getBank() >> 3) & 0x3;
    uint32_t bnkGrp = i_addr.getBank() & 0x7;

    bool twoPortConfig, col3Config, col10Config, bank1Config, bankGrp2Config;
    uint8_t prnkBits, srnkBits, extraRowBits;

    int32_t rc = MemUtils::odyGetAddrConfig( i_ocmb, port,
        twoPortConfig, prnkBits, srnkBits, extraRowBits, col3Config,
        col10Config, bank1Config, bankGrp2Config );
    if ( SUCCESS != rc )
    {
        PRDF_ERR( PRDF_FUNC "odyGetAddrConfig(0x%08x, %d)", i_ocmb->getHuid(),
                  port );
    }

    // Determine the last possible value for each part of the address, dependent
    // on what bits are configured.
    uint8_t lastPort = 0x1;
    uint8_t lastPrank = 0x1;
    uint8_t lastSrank = 0x7;
    uint32_t lastRow = 0x3ffff;
    uint32_t lastCol = 0xff;
    uint32_t lastBnk = 0x3;
    uint32_t lastBnkGrp = 0x7;

    uint8_t prankShift = 1 - prnkBits;
    lastPrank = (lastPrank >> prankShift) << prankShift;

    uint8_t srankShift = 3 - srnkBits;
    lastSrank = (lastSrank >> srankShift) << srankShift;

    uint8_t rowShift = 2 - extraRowBits;
    lastRow = (lastRow >> rowShift) << rowShift;

    if (!col3Config)
    {
        lastCol = lastCol & 0x7f;
    }
    if (!col10Config)
    {
        lastCol = lastCol & 0xfe;
    }

    if (!bank1Config)
    {
        lastBnk = lastBnk & 0x2;
    }

    if (!bankGrp2Config)
    {
        lastBnkGrp = lastBnkGrp & 0x6;
    }

    // Check each part of the address to determine where to increment. The
    // address is incremented right to left, but cannot be blindly incremented
    // due to potential bits not being configured.
    do
    {
        // bank_group(0 to 2)
        if (bnkGrp != lastBnkGrp)
        {
            // Increment bank group, adjusting if bank group 2 is not configured
            if (!bankGrp2Config)
            {
                bnkGrp = (((bnkGrp >> 1) + 1) << 1) & 0x7;
            }
            else
            {
                bnkGrp = (bnkGrp + 1) & 0x7;
            }
            break;
        }
        else
        {
            // Bank group is at it's last possible value, some next part of the
            // address will need to the incremented. Zero out bank group.
            bnkGrp = 0;
        }

        // bank(0 to 1)
        if (bnk != lastBnk)
        {
            // Increment bank, adjusting if bank 1 is not configured
            if (!bank1Config)
            {
                bnk = (((bnk >> 1) +  1) << 1) & 0x3;
            }
            else
            {
                bnk = (bnk + 1) & 0x3;
            }
            break;
        }
        else
        {
            // Bank is at it's last possible value, some next part of the
            // address will need to the incremented. Zero out bank.
            bnk = 0;
        }

        // col(3 to 10)
        if (col != lastCol)
        {
            // Increment column, adjusting if column 10 is not configured
            if (!col10Config)
            {
                col = (((col >> 1) + 1) << 1) & 0xff;
            }
            else
            {
                col = (col + 1) & 0xff;
            }
            break;
        }
        else
        {
            // Column is at it's last possible value, some next part of the
            // address will need to the incremented. Zero out column.
            col = 0;
        }

        // row(0 to 17)
        if (row != lastRow)
        {
            row = (((row >> rowShift) + 1) << rowShift) & 0x3ffff;
            break;
        }
        else
        {
            // Row is at it's last possible value, some next part of the
            // address will need to the incremented. Zero out row.
            row = 0;
        }

        // srank(0 to 2)
        if (srank != lastSrank)
        {
            srank = (((srank >> srankShift) + 1) << srankShift) & 0x7;
            break;
        }
        else
        {
            // Srank is at it's last possible value, some next part of the
            // address will need to the incremented. Zero out srank.
            srank = 0;
        }

        // prank
        if (prank != lastPrank)
        {
            prank = (((prank >> prankShift) + 1) << prankShift) & 0x1;
            break;
        }
        else
        {
            // Prank is at it's last possible value, some next part of the
            // address will need to the incremented. Zero out prank.
            prank = 0;
        }

        // port select
        // If only one port is configured, just use the port value as is.
        if (twoPortConfig)
        {
            if (port != lastPort)
            {
                port++;
                break;
            }
            else
            {
                // Port is at it's last possible value, some next part of the
                // address will need to the incremented. Zero out port.
                port = 0;
            }
        }

    }while (0);

    // Note: the uint64_t will be right justified as that is the format needed
    // for passing into the constructor of mss::mcbist::address.
    uint8_t fullBank = ((bnk << 3) | bnkGrp) & 0x1f;
    uint64_t addr64 =
    (
        ((uint64_t)(port     & 0x1    ) << 35) | // 2
        ((uint64_t)(prank    & 0x1    ) << 34) | // 3
        ((uint64_t)(srank    & 0x7    ) << 31) | // 4:6
        ((uint64_t)(row      & 0x3ffff) << 13) | // 7:24
        ((uint64_t)(col      & 0xff   ) <<  5) | // 25:32
        ((uint64_t)(fullBank & 0x1f   ))         // 33:37
    );

    mss::mcbist::address<mss::mc_type::ODYSSEY> mssAddr(addr64);

    // Get the OCMB fapi target
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt (i_ocmb->getTrgt());

    do
    {
        // Clear all of the counters and maintenance ECC attentions.
        o_rc = prepareNextCmd<TYPE_OCMB_CHIP>(i_ocmb);
        if (SUCCESS != o_rc)
        {
            PRDF_ERR(PRDF_FUNC "prepareNextCmd(0x%08x) failed",
                     i_ocmb->getHuid());
            break;
        }

        // Start the background steer command.
        errlHndl_t errl = nullptr;

        // Get the stop conditions. See startBgScrub for more details on
        // why these stop conditions are set.
        mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY> stopCond;


        if (getOcmbDataBundle(i_ocmb)->iv_ueStopCounter.thReached(io_sc))
        {
            // If we've reached the limit of UEs we're allowed to stop on
            // per rank, only set the stop on mpe stop condition.
            stopCond.set_pause_on_mpe(mss::ON);
        }
        else if (getOcmbDataBundle(i_ocmb)->iv_ceStopCounter.thReached(io_sc))
        {
            // If we've reached the limit of CEs we're allowed to stop on
            // per rank, set all the normal stop conditions except stop on
            // CE
            stopCond.set_pause_on_aue(mss::ON);

            #ifdef CONFIG_HBRT_PRD

            stopCond.set_pause_on_mpe(mss::ON)
                    .set_pause_on_ue(mss::ON);

            // In MNFG mode, stop on RCE_ETE to get an accurate callout for
            // IUEs
            if (mfgMode()) stopCond.set_thresh_rce(1);

            #endif
        }
        else
        {
            // If we haven't reached threshold on the number of UEs or CEs we
            // have stopped on, use the default stop conditions.
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
            if (mfgMode()) stopCond.set_thresh_rce(1);

            #endif
        }

        FAPI_INVOKE_HWP(errl, ody_background_steer, fapiTrgt, stopCond,
                        mss::mcbist::BG_SCRUB, mssAddr);
        if (nullptr != errl)
        {
            PRDF_ERR(PRDF_FUNC "background_steer(0x%08x,0x%016llx) "
                     "failed", i_ocmb->getHuid(), addr64);
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
            o_rc = FAIL;
            break;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//##                       Core/cache functions
//##############################################################################

bool queryEcoMode(TARGETING::TargetHandle_t i_trgt)
{
    PRDF_ASSERT(nullptr != i_trgt);
    PRDF_ASSERT(TYPE_CORE == getTargetType(i_trgt));

    fapi2::Target<fapi2::TARGET_TYPE_CORE> fapiTrgt{i_trgt};

    fapi2::ATTR_ECO_MODE_Type attr;

    fapi2::ReturnCode rc = FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE, fapiTrgt, attr);

    errlHndl_t errl = fapi2::rcToErrl(rc, TARGETING::get_huid(i_trgt));
    if (nullptr != errl)
    {
        PRDF_ERR("[PlatServices::queryEcoMode] Failed to get ATTR_ECO_MODE: "
                 "i_trgt=0x%08X", getHuid(i_trgt));
        PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);

        return false; // assume ECO mode is not enabled.
    }

    return fapi2::ENUM_ATTR_ECO_MODE_ENABLED == attr;
}

//##############################################################################
//##                       Line Delete Functions
//##############################################################################

int32_t extractL3Err( TargetHandle_t i_coreTgt, bool i_ce,
                      p10_l3err_extract_err_data &o_errorAddr)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = nullptr;
    bool errFound = false;

    fapi2::variable_buffer ta_data( P10_TRACEARRAY_NUM_ROWS *
                                    P10_TRACEARRAY_BITS_PER_ROW);
    proc_gettracearray_args args;

    args.trace_bus = PROC_TB_L3_1;
    args.stop_pre_dump = true;
    args.ignore_mux_setting = false;
    args.collect_dump = true;
    args.reset_post_dump = false;
    args.restart_post_dump = false;

    fapi2::Target<fapi2::TARGET_TYPE_CORE> fapiTrgt (i_coreTgt);

    FAPI_INVOKE_HWP( err,
                     p10_proc_gettracearray,
                     fapiTrgt,
                     args,
                     ta_data);
    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::extractL2Err] huid: 0x%08x gettracearray "
                  "failed", getHuid(i_coreTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    FAPI_INVOKE_HWP( err,
                     p10_l3err_extract,
                     fapiTrgt,
                     ta_data,
                     i_ce ? L3ERR_CE : L3ERR_CE_UE,
                     o_errorAddr,
                     errFound );

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::extractL3Err] huid: 0x%08x failed",
                  getHuid(i_coreTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    if ( !errFound )
    {
        PRDF_ERR( "[PlatServices::extractL3Err] huid: 0x%08x No Error Found",
                  getHuid(i_coreTgt));
        o_rc = FAIL;
    }

    return o_rc;
}


int32_t l3LineDelete(TargetHandle_t i_coreTgt,
                     const p10_l3err_extract_err_data& i_l3_err_data)
{
    using namespace stopImageSection;
    errlHndl_t err = nullptr;
    const uint64_t retryCount = 100;

    // Apply Line Delete
    fapi2::Target<fapi2::TARGET_TYPE_CORE> fapiTrgt (i_coreTgt);
    FAPI_INVOKE_HWP( err,
                     p10_l3err_linedelete,
                     fapiTrgt,
                     i_l3_err_data,
                     retryCount);
    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::l3LineDelete] HUID: 0x%08x failed",
                  getHuid(i_coreTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    // Cannot write HCODE in ECO mode.
    if (queryEcoMode(i_coreTgt))
        return SUCCESS; // nothing more to do

    // Do HCODE update to preserve line delete
    BitStringBuffer ldData(64);
    ldData.setBit(0); //Trigger
    ldData.setFieldJustify(1, 4, 0x2); // Purge Type (LD=0x2)
    ldData.setFieldJustify(12, 5, i_l3_err_data.member);
    ldData.setFieldJustify(17, 12, i_l3_err_data.real_address_46_57);

    uint64_t scomVal = (((uint64_t)ldData.getFieldJustify(0, 32)) << 32) |
                        ((uint64_t)ldData.getFieldJustify(32, 32));

    err = RTPM::hcode_update(PROC_STOP_SECTION_L3, PROC_STOP_SCOM_APPEND,
                             i_coreTgt, 0x2001860E, scomVal);
    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::l3LineDelete] HUID: 0x%08x hcode_update "
                  "failed", getHuid(i_coreTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    return SUCCESS;
}

int32_t extractL2Err( TargetHandle_t i_coreTgt, bool i_ce,
                      p10_l2err_extract_err_data &o_errorAddr)
{
    errlHndl_t err = nullptr;
    bool errFound = false;
    fapi2::variable_buffer ta_data( P10_TRACEARRAY_NUM_ROWS *
                                    P10_TRACEARRAY_BITS_PER_ROW);
    proc_gettracearray_args args;

    args.trace_bus = PROC_TB_L20;
    args.stop_pre_dump = true;
    args.ignore_mux_setting = false;
    args.collect_dump = true;
    args.reset_post_dump = false;
    args.restart_post_dump = false;

    fapi2::Target<fapi2::TARGET_TYPE_CORE> fapiTrgt (i_coreTgt);

    FAPI_INVOKE_HWP( err,
                     p10_proc_gettracearray,
                     fapiTrgt,
                     args,
                     ta_data);
    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::extractL2Err] huid: 0x%08x gettracearray "
                  "failed", getHuid(i_coreTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    FAPI_INVOKE_HWP( err,
                     p10_l2err_extract,
                     fapiTrgt,
                     ta_data,
                     i_ce ? L2ERR_CE : L2ERR_CE_UE,
                     o_errorAddr,
                     errFound );

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::extractL2Err] huid: 0x%08x failed",
                  getHuid(i_coreTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    if ( !errFound )
    {
        PRDF_ERR( "[PlatServices::extractL2Err] huid: 0x%08x No Error Found",
                  getHuid(i_coreTgt));
        return FAIL;
    }

    return SUCCESS;
}

int32_t l2LineDelete(TargetHandle_t i_coreTgt,
                     const p10_l2err_extract_err_data& i_l2_err_data)
{
    using namespace stopImageSection;
    errlHndl_t err = nullptr;
    const uint64_t retryCount = 100;

    // Apply Line Delete
    fapi2::Target<fapi2::TARGET_TYPE_CORE> fapiTrgt (i_coreTgt);
    FAPI_INVOKE_HWP( err,
                     p10_l2err_linedelete,
                     fapiTrgt,
                     i_l2_err_data,
                     retryCount);
    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::l2LineDelete] HUID: 0x%08x failed",
                  getHuid(i_coreTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        return FAIL;
    }

    // Cannot write HCODE in ECO mode.
    if (queryEcoMode(i_coreTgt))
        return SUCCESS; // nothing more to do

    // Do HCODE update to preserve line delete
    BitStringBuffer ldData(64);
    ldData.setBit(0); //Trigger
    ldData.setFieldJustify(1, 4, 0x2); // Purge Type (LD=0x2)
    ldData.setFieldJustify(17, 3, i_l2_err_data.member);
    ldData.setFieldJustify(20, 8, i_l2_err_data.real_address_47_56);
    if (i_l2_err_data.bank)
        ldData.setBit(28);

    uint64_t scomVal = (((uint64_t)ldData.getFieldJustify(0, 32)) << 32) |
                        ((uint64_t)ldData.getFieldJustify(32, 32));

    err = RTPM::hcode_update(PROC_STOP_SECTION_L2, PROC_STOP_SCOM_APPEND,
                             i_coreTgt, 0x2002800E, scomVal);
    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::l2LineDelete] HUID: 0x%08x hcode_update "
                  "failed", getHuid(i_coreTgt));
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
                     p10_pm_callout,
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

//##############################################################################
//##                         TOD functions
//##############################################################################

void requestNewTODTopology( uint32_t i_oscPos,
                            const TargetHandle_t& i_procOscTgt,
                            const TargetHandleList& i_badChipList,
                            bool i_informPhyp)
{
    #define PRDF_FUNC "[PlatServices::requestNewTODTopology] "
    if ( i_badChipList.size() > 0 || i_procOscTgt != nullptr )
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

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

