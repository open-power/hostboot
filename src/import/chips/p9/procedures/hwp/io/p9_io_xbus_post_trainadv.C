/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_post_trainadv.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
///
/// @file p9_io_xbus_post_trainadv.H
/// @brief Post-Training PHY Status Function.
///
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Post-Training PHY Status Function.
///
/// Procedure Prereq:
///   - System clocks are running.
///   - Scominit Procedure is completed.
///   - IO DCCAL Procedure is completed.
///   - IO Run Training Procedure is completed.
/// @endverbatim
///----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "p9_io_xbus_post_trainadv.H"
#include <p9_io_scom.H>
#include <p9_io_regs.H>

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------


fapi2::ReturnCode getDebugInfo(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS> i_tgt,
    const uint8_t i_grp )
{
    FAPI_IMP("Entering...");


    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode checkEyeWidth(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS> i_tgt,
    const uint8_t i_grp )
{
    FAPI_IMP("Entering...");

    const uint32_t ONE_MS        = 1000000; // 1,000,000ns = 1ms
    const uint32_t DELAY_NS      = 100 * ONE_MS; // Delay for 100ms
    const uint32_t DELAY_CYCLES  = 1; // We won't be using this feature in sim.
    const uint8_t LN0            = 0;
    uint64_t      data64         = 0;
    uint8_t       minMfgEyeWidth = 0;
    char tgt_str[fapi2::MAX_ECMD_STRING_LEN];

    fapi2::toString(i_tgt, tgt_str, fapi2::MAX_ECMD_STRING_LEN);

    // Get the minimum manufacturing eye width
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_IO_X_MFG_MIN_EYE_WIDTH, i_tgt, minMfgEyeWidth ) );

    // We need to wait for each lane to get through recal before the historical eye
    //   width values will be valid.  At 2ms per lane * 17 lanes = 34ms.  To be safe
    //   we want this number to get through a few times.  We will wait 100ms
    FAPI_TRY(fapi2::delay(DELAY_NS, DELAY_CYCLES));


    // Read the historical minimum eye width
    FAPI_TRY( io::read( EDIP_RX_CTL_CNTL13_EO_PG, i_tgt, i_grp, LN0, data64 ),
              "Reading EDI+ RX CTL CNTL13 EO PG Failed" );

    FAPI_DBG( "tgt(%s:g%d) Min Eye Width(%d) Lane(%d) Valid(%d) :: MinMfgEyeWidth(%d)",
              tgt_str, i_grp,
              io::get( EDIP_RX_HIST_MIN_EYE_WIDTH      , data64 ),
              io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_LANE , data64 ),
              io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, data64 ),
              minMfgEyeWidth );

    // Check if the historical eye width is less then the manufacturing minimum eye width
    FAPI_ASSERT( ( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH, data64 ) >= minMfgEyeWidth ),
                 fapi2::IO_XBUS_MFG_RX_EYE_WIDTH_FAILURE().set_TARGET( i_tgt ).set_GROUP( i_grp )
                 .set_EYE_WIDTH( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH, data64 ) )
                 .set_EYE_WIDTH_LANE( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_LANE, data64 ) )
                 .set_EYE_WIDTH_VALID( io::get( EDIP_RX_HIST_MIN_EYE_WIDTH_VALID, data64 ) )
                 .set_MIN_EYE_WIDTH( minMfgEyeWidth ),
                 "I/O EDI+ Xbus Manufacturing Eye Width Failure." );


fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief A simple HWP that runs after io_run_trainig.
 *  This function is called on every Xbus.
 * @param[in] i_target   Fapi2 Target
 * @param[in] i_group    Clock Group
 * @param[in] i_ctarget  Fapi2 Connected Target
 * @param[in] i_cgroup   Connected Clock Group
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_post_trainadv(
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_tgt,
    const uint8_t& i_grp,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_ctgt,
    const uint8_t& i_cgrp)
{
    FAPI_IMP("Entering...");
    uint8_t l_status = 0x0;
    char tgt_str[fapi2::MAX_ECMD_STRING_LEN];

    fapi2::toString(i_tgt, tgt_str, fapi2::MAX_ECMD_STRING_LEN);

    FAPI_INF("Checking %s:g%d Post Link Training.", tgt_str, i_grp);

    // Get Debug Info
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_X_DEBUG, i_tgt, l_status));

    if(l_status == fapi2::ENUM_ATTR_IO_X_DEBUG_TRUE)
    {
        FAPI_TRY( getDebugInfo( i_tgt, i_grp ) );
        FAPI_TRY( getDebugInfo( i_ctgt, i_cgrp ) );
    }

    // Run Manufacturing Eye Width Check
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_X_MFG_CHK, i_tgt, l_status));

    if(l_status == fapi2::ENUM_ATTR_IO_X_MFG_CHK_TRUE)
    {
        FAPI_TRY( checkEyeWidth( i_tgt, i_grp ) );
        FAPI_TRY( checkEyeWidth( i_ctgt, i_cgrp ) );
    }



fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

