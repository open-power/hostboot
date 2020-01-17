/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_corecache_realign.C $ */
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
    HCD_CORECACHE_CHIPLET_ALIGN_DELAY_HW_NS               = 100,     // 100ns quiesce delay
    HCD_CORECACHE_CHIPLET_ALIGN_DELAY_SIM_CYCLE           = 400,     // 400 sim cycle delay
    HCD_CORECACHE_FORCE_ALIGN_DELAY_HW_NS                 = 50,      // 50ns quiesce delay
    HCD_CORECACHE_FORCE_ALIGN_DELAY_SIM_CYCLE             = 200      // 200 sim cycle delay
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

    FAPI_DBG("Delay 100 Mesh Cycles");
    fapi2::delay(HCD_CORECACHE_CHIPLET_ALIGN_DELAY_HW_NS,
                 HCD_CORECACHE_CHIPLET_ALIGN_DELAY_SIM_CYCLE);

#ifdef __PPE_PLAT
    asm("sync");
#endif

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
