/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_corecache_clock_control.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file  p10_hcd_corecache_clock_control.C
/// @brief
///


// *HWP HWP Owner          : David Du         <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still       <stillgs@us.ibm.com>
// *HWP FW Owner           : Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:QME
// *HWP Level              : 2

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "p10_hcd_corecache_clock_control.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_scom_eq.H"
    using namespace scomt::eq;
#else
    #include "p10_scom_eq.H"
    using namespace scomt::eq;
#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_CORECACHE_CLOCK_CONTROL_CONSTANTS
{
    HCD_CORECACHE_CLK_CTRL_POLL_TIMEOUT_HW_NS              = 1000000, // 10^6ns = 1ms timeout
    HCD_CORECACHE_CLK_CTRL_POLL_DELAY_HW_NS                = 10000,   // 10us poll loop delay
    HCD_CORECACHE_CLK_CTRL_POLL_DELAY_SIM_CYCLE            = 32000    // 320k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_corecache_clock_control
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_corecache_clock_control(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target,
    // 1) The following parameters assume bits already line up with bits in first or
    //    second half word of the scom register, in another word, they are 32-bit-mask,
    //    enum P10_HCD_CLK_CTRL_CONSTANTS in p10_hcd_common.h can be used in the caller
    // 2) Due to PPE compatiablity/cost, number of parameters is minimalized; thus
    //    i_command should OR-in Master/Slave bit should they be used(not common usage)
    //    Example: HCD_CLK_STOP|HCD_CLK_SLAVE|HCD_CLK_MASTER as i_command
    // 3) As conventional usage, this module always assume to operate on all 3 tholds
    //    Therefore, no type parameter is provided as they were never used
    uint32_t i_regions,
    uint32_t i_command,
    bool i_inhibit_flush)

{
    fapi2::buffer<uint64_t> l_scomData              = 0;
    uint32_t                l_timeout               = 0;
#ifndef EQ_CLOCK_STAT_DISABLE
    uint32_t                l_clk_stat              = 0;
    uint32_t                l_clk_stat_expected     = 0;
    fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST > l_mc_or = i_target;//default OR
#endif

    FAPI_INF(">>p10_hcd_corecache_clock_control[%x](b0:stop/b1:start) on regions[0x%08X]", i_command, i_regions);

    FAPI_DBG("Exit Flush (set flushmode inhibit) via CPLT_CTRL4[REGIONS]");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, CPLT_CTRL4_WO_OR, SCOM_LOAD32H(i_regions) ) );

    FAPI_DBG("Clear SCAN_REGION_TYPE Register");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, SCAN_REGION_TYPE, 0 ) );

    FAPI_DBG("Start/Stop ECL2 Clocks via CLK_REGION_TYPE");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, CLK_REGION, SCOM_LOAD64( (i_command | i_regions), HCD_CLK_THOLD_ALL ) ) );

    FAPI_DBG("Poll OPCG done bit to check for completeness via CPLT_STAT0[8:CC_CTRL_OPCG_DONE_DC]");
    l_timeout = HCD_CORECACHE_CLK_CTRL_POLL_TIMEOUT_HW_NS /
                HCD_CORECACHE_CLK_CTRL_POLL_DELAY_HW_NS;

    do
    {
        FAPI_TRY( HCD_GETSCOM_Q( i_target, CPLT_STAT0, l_scomData ) );

        //use multicastAND to check 1
        if( SCOM_GET(8) == 1 )
        {
            break;
        }

        fapi2::delay(HCD_CORECACHE_CLK_CTRL_POLL_DELAY_HW_NS,
                     HCD_CORECACHE_CLK_CTRL_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT((l_timeout != 0),
                fapi2::CORECACHE_CLK_CTRL_TIMEOUT()
                .set_CLK_CTRL_POLL_TIMEOUT_HW_NS(HCD_CORECACHE_CLK_CTRL_POLL_TIMEOUT_HW_NS)
                .set_CPLT_STAT0(l_scomData)
                .set_CLK_COMMAND(i_command)
                .set_CLK_REGIONS(i_regions)
                .set_QUAD_TARGET(i_target),
                "ERROR: Core/Cache Clock Control Timeout");

#ifndef EQ_CLOCK_STAT_DISABLE
    // IF clocks are stopped, check for stat bits ON, use MC_AND target
    // Otherwise, check for bits OFF, use MC_OR target

    // Do not blame me, fapi forces me to write this ugly code below
    // Note, since mc target can either be AND/OR, which is
    // treated as different variables in C++ as different types
    // while you are allowed to name the target with the same name
    // which doesnt really help because compiler doesnt care that
    // 1) Therefore, inline i_command?i_target:l_mc did not work
    //    as compiler disallow different type in comparison outcome
    // 2) Also try to create a "common" target container failed
    //    as there is no generic mc target, the default is always OR
    // 3) and of course, fapi disallow you to change mc type
    //    on the given target, you HAVE to create different target

    FAPI_DBG("Check CLOCK_STAT_SL[bit OFF for clock Started]");

    if( i_command & HCD_CLK_STOP )
    {
        l_clk_stat_expected = i_regions;
        FAPI_TRY( getScom( i_target , CLOCK_STAT_SL, l_scomData ) );
    }
    else
    {
        // stat expected 0s in this case
        FAPI_TRY( getScom( l_mc_or , CLOCK_STAT_SL, l_scomData ) );
    }

    SCOM_GET32H(l_clk_stat);
    FAPI_ASSERT( ( ( l_clk_stat & i_regions ) == l_clk_stat_expected ),
                 fapi2::CORECACHE_CLK_CTRL_SL_FAILED()
                 .set_CLK_STAT_SL(l_clk_stat)
                 .set_CLK_COMMAND(i_command)
                 .set_CLK_REGIONS(i_regions)
                 .set_QUAD_TARGET(i_target),
                 "Core/Cache Clock Control Failed in SL thold");

    FAPI_DBG("Check CLOCK_STAT_NSL[bit OFF for clock Started]");

    if( i_command & HCD_CLK_STOP )
    {
        FAPI_TRY( getScom( i_target , CLOCK_STAT_NSL, l_scomData ) );
    }
    else
    {
        FAPI_TRY( getScom( l_mc_or , CLOCK_STAT_NSL, l_scomData ) );
    }

    SCOM_GET32H(l_clk_stat);
    FAPI_ASSERT( ( ( l_clk_stat & i_regions ) == l_clk_stat_expected ),
                 fapi2::CORECACHE_CLK_CTRL_NSL_FAILED()
                 .set_CLK_STAT_NSL(l_clk_stat)
                 .set_CLK_COMMAND(i_command)
                 .set_CLK_REGIONS(i_regions)
                 .set_QUAD_TARGET(i_target),
                 "Core/Cache Clock Control Failed in NSL thold");

    FAPI_DBG("Check CLOCK_STAT_ARY[bit OFF for clock Started]");

    if( i_command & HCD_CLK_STOP )
    {
        FAPI_TRY( HCD_GETSCOM_Q( i_target, CLOCK_STAT_ARY, l_scomData ) );
    }
    else
    {
        FAPI_TRY( HCD_GETSCOM_Q( l_mc_or,  CLOCK_STAT_ARY, l_scomData ) );
    }

    SCOM_GET32H(l_clk_stat);
    FAPI_ASSERT( ( ( l_clk_stat & i_regions ) == l_clk_stat_expected ),
                 fapi2::CORECACHE_CLK_CTRL_ARY_FAILED()
                 .set_CLK_STAT_ARY(l_clk_stat)
                 .set_CLK_REGIONS(i_regions)
                 .set_QUAD_TARGET(i_target),
                 "Core/Cache Clock Control Failed in ARY thold");
#endif

    FAPI_DBG("Clear CLK_REGION_TYPE Register");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, CLK_REGION, 0 ) );

    if (!i_inhibit_flush)
    {
        FAPI_DBG("Enter Flush (clear flushmode inhibit) via CPLT_CTRL4[REGIONS]");
        FAPI_TRY( HCD_PUTSCOM_Q( i_target, CPLT_CTRL4_WO_CLEAR, SCOM_LOAD32H(i_regions) ) );
    }

fapi_try_exit:

    FAPI_INF("<<p10_hcd_corecache_clock_control");

    return fapi2::current_err;

}
