/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_l3_purge.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file  p10_hcd_l3_purge.C
/// @brief Purge the L3 cache
///


// *HWP HWP Owner          : David Du         <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still       <stillgs@us.ibm.com>
// *HWP FW Owner           : Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:QME
// *HWP Level              : 2
///
// EKB-Mirror-To: hw/ppe


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "p10_hcd_l3_purge.H"
#include "p10_hcd_common.H"

#include "p10_scom_c.H"
using namespace scomt::c;


//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_L3_PURGE_CONSTANTS
{
    HCD_L3_PURGE_DONE_POLL_TIMEOUT_HW_NS    = 100000000, // 10^5ns = 100us timeout
    HCD_L3_PURGE_DONE_POLL_DELAY_HW_NS      = 1000,   // 1us poll loop delay
    HCD_L3_PURGE_DONE_POLL_DELAY_SIM_CYCLE  = 32000,  // 32k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_l3_purge
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_l3_purge(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_OR > & i_target)
{
    fapi2::buffer<uint64_t> l_scomData = 0;
    uint32_t                l_timeout  = 0;

    FAPI_INF(">>p10_hcd_l3_purge");

    FAPI_DBG("Assert L3_PM_LCO_DIS_CFG via PM_LCO_DIS_REG[0]");
    // This register doesnt have OR/CLR interface and having two functional bits
    // [0] L3_PM_LCO_DIS_CFG
    // [1] L3_PM_RCMD_DIS_CFG
    // Here set bit0 while keep bit1 unset until after powerbus purge
    FAPI_TRY( HCD_PUTSCOM_C( i_target, L3_MISC_L3CERRS_PM_LCO_DIS_REG, SCOM_1BIT(0) ) );

    FAPI_DBG("Assert L3_PURGE_REQ via PM_PURGE_REG[0]");
    FAPI_TRY( HCD_PUTSCOM_C( i_target, L3_MISC_L3CERRS_PM_PURGE_REG, SCOM_1BIT(0) ) );

    FAPI_DBG("Wait for L3_PURGE_REQ to drop via PM_PURGE_REG[0]");
    l_timeout = HCD_L3_PURGE_DONE_POLL_TIMEOUT_HW_NS /
                HCD_L3_PURGE_DONE_POLL_DELAY_HW_NS;

    do
    {

        FAPI_TRY( HCD_GETSCOM_C( i_target, L3_MISC_L3CERRS_PM_PURGE_REG, l_scomData ) );

        // use multicastOR to check 0
        if( SCOM_GET(0) == 0 )
        {
            break;
        }

        fapi2::delay(HCD_L3_PURGE_DONE_POLL_DELAY_HW_NS,
                     HCD_L3_PURGE_DONE_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT((l_timeout != 0),
                fapi2::L3_PURGE_DONE_TIMEOUT()
                .set_L3_PURGE_DONE_POLL_TIMEOUT_HW_NS(HCD_L3_PURGE_DONE_POLL_TIMEOUT_HW_NS)
                .set_PM_PURGE_REG(l_scomData)
                .set_CORE_TARGET(i_target),
                "ERROR: L3 Purge Done Timeout");

fapi_try_exit:

    FAPI_INF("<<p10_hcd_l3_purge");

    return fapi2::current_err;

}
