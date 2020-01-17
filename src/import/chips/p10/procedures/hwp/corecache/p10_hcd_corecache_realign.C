/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_corecache_realign.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file  p10_hcd_corecache_realign.C
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

#include "p10_hcd_corecache_realign.H"
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

enum P10_HCD_CORECACHE_REALIGN_CONSTANTS
{
    HCD_CORECACHE_REALIGN_POLL_TIMEOUT_HW_NS              = 1000000, // 10^6ns = 1ms timeout
    HCD_CORECACHE_REALIGN_POLL_DELAY_HW_NS                = 10000,   // 10us poll loop delay
    HCD_CORECACHE_REALIGN_POLL_DELAY_SIM_CYCLE            = 32000,   // 320k sim cycle delay
    HCD_CORECACHE_FORCE_ALIGN_DELAY_HW_NS                 = 10,      // 10ns quiesce delay
    HCD_CORECACHE_FORCE_ALIGN_DELAY_SIM_CYCLE             = 50       // 50 sim cycle delay
};


//------------------------------------------------------------------------------
// Procedure: p10_hcd_corecache_realign
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_corecache_realign(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target,
    uint32_t i_regions)
{
    fapi2::buffer<uint64_t> l_scomData = 0;
    uint32_t                l_timeout  = 0;

    FAPI_INF(">>p10_hcd_corecache_realign on regions[0x%08X]", i_regions);

    FAPI_DBG("Exit Flush (set flushmode inhibit) via CPLT_CTRL4[REGIONS]");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, CPLT_CTRL4_WO_OR, SCOM_LOAD32H(i_regions) ) );

    FAPI_DBG("Enable Alignment via CPLT_CTRL0[3:CTRL_CC_FORCE_ALIGN]");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, CPLT_CTRL0_WO_OR, SCOM_1BIT(3) ) );

    FAPI_TRY( HCD_GETSCOM_Q( i_target, SYNC_CONFIG, l_scomData ) );

    FAPI_DBG("Assert CLEAR_CHIPLET_IS_ALIGNED via SYNC_CONFIG[7:CLEAR_CHIPLET_IS_ALIGNED]");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, SYNC_CONFIG, SCOM_SET(7) ) );

    FAPI_DBG("Drop CLEAR_CHIPLET_IS_ALIGNED via SYNC_CONFIG[7:CLEAR_CHIPLET_IS_ALIGNED]");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, SYNC_CONFIG, SCOM_UNSET(7) ) );

    FAPI_DBG("Poll CC_CTRL_CHIPLET_IS_ALIGNED_DC via CPLT_STAT0[9:CC_CTRL_CHIPLET_IS_ALIGNED_DC]");
    l_timeout = HCD_CORECACHE_REALIGN_POLL_TIMEOUT_HW_NS /
                HCD_CORECACHE_REALIGN_POLL_DELAY_HW_NS;

    do
    {
        FAPI_TRY( HCD_GETSCOM_Q( i_target, CPLT_STAT0, l_scomData ) );

        //use multicastAND to check 1
        if( SCOM_GET(9) == 1 )
        {
            break;
        }

        fapi2::delay(HCD_CORECACHE_REALIGN_POLL_DELAY_HW_NS,
                     HCD_CORECACHE_REALIGN_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT((l_timeout != 0),
                fapi2::CORECACHE_REALIGN_TIMEOUT()
                .set_REALIGN_POLL_TIMEOUT_HW_NS(HCD_CORECACHE_REALIGN_POLL_TIMEOUT_HW_NS)
                .set_CPLT_STAT0(l_scomData)
                .set_CLK_REGIONS(i_regions)
                .set_QUAD_TARGET(i_target),
                "ERROR: Core/Cache Realign Timeout");

    FAPI_DBG("Disable Alignment via CPLT_CTRL0[3:CTRL_CC_FORCE_ALIGN]");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, CPLT_CTRL0_WO_CLEAR, SCOM_1BIT(3) ) );

    FAPI_DBG("Delay 50 Core Cycles");
    fapi2::delay(HCD_CORECACHE_FORCE_ALIGN_DELAY_HW_NS,
                 HCD_CORECACHE_FORCE_ALIGN_DELAY_SIM_CYCLE);

#ifdef __PPE_PLAT
    asm("sync");
#endif

    FAPI_DBG("Enter Flush (clear flushmode inhibit) via CPLT_CTRL4[REGIONS]");
    FAPI_TRY( HCD_PUTSCOM_Q( i_target, CPLT_CTRL4_WO_CLEAR, SCOM_LOAD32H(i_regions) ) );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_corecache_realign");

    return fapi2::current_err;

}
