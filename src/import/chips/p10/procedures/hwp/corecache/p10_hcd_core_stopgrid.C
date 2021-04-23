/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_core_stopgrid.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file  p10_hcd_core_stopgrid.C
/// @brief
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

#include "p10_hcd_core_stopgrid.H"
#include "p10_hcd_mma_stopclocks.H"
#include "p10_hcd_mma_poweroff.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_ppe_eq.H"
    #include "p10_ppe_c.H"
    using namespace scomt::ppe_eq;
    using namespace scomt::ppe_c;
#else
    #include "p10_scom_eq.H"
    #include "p10_scom_c.H"
    using namespace scomt::eq;
    using namespace scomt::c;
#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_CORE_STOPGRID_CONSTANTS
{
    HCD_ECL2_CLK_SYNC_DROP_POLL_TIMEOUT_HW_NS                   = 10000,   // 10^4ns = 10us timeout
    HCD_ECL2_CLK_SYNC_DROP_POLL_DELAY_HW_NS                     = 100,     // 100ns poll loop delay
    HCD_ECL2_CLK_SYNC_DROP_POLL_DELAY_SIM_CYCLE                 = 3200,    // 3.2k sim cycle delay
    HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_TIMEOUT_HW_NS        = 100000000, // 10^4ns = 10us timeout
    HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_DELAY_HW_NS          = 100,     // 100ns poll loop delay
    HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_DELAY_SIM_CYCLE      = 3200,    // 3.2k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_core_stopgrid
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_core_stopgrid(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > eq_target =
        i_target.getParent < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST > ();
    fapi2::buffer<buffer_t> l_mmioData = 0;
    fapi2::buffer<uint64_t> l_scomData = 0;
    uint32_t                l_timeout  = 0;
    uint32_t                l_core_change_done = 0;
    uint32_t                l_regions  = i_target.getCoreSelect();
    uint8_t                 l_attr_mma_poweroff_disable = 0;
    fapi2::Target < fapi2::TARGET_TYPE_SYSTEM > l_sys;
    fapi2::ATTR_RUNN_MODE_Type                  l_attr_runn_mode;
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_RUNN_MODE, l_sys, l_attr_runn_mode ) );
    FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_SYSTEM_MMA_POWEROFF_DISABLE, l_sys, l_attr_mma_poweroff_disable ) );

    FAPI_INF(">>p10_hcd_core_stopgrid");

    // Also stop mma clocks after/with core clocks
    // not part of core_stopclocks for its pure usage at p10_stopclocks
    // this hwp is shared stop2,3,11 path
    FAPI_TRY( p10_hcd_mma_stopclocks( i_target ) );

    if( !l_attr_mma_poweroff_disable )
    {
        //also shutdown mma power here as for WOF benefit
        //only do so when dynamic mode is enabled
        FAPI_TRY( p10_hcd_mma_poweroff( i_target ) );
    }

    FAPI_DBG("Disable ECL2 Skewadjust via CPMS_CGCSR_[1:CL2_CLK_SYNC_ENABLE]");
    FAPI_TRY( HCD_PUTMMIO_S( i_target, CPMS_CGCSR_WO_CLEAR, BIT64(1) ) );

    FAPI_DBG("Check ECL2 Skewadjust Removed via CPMS_CGCSR[33:CL2_CLK_SYNC_DONE]");
    l_timeout = HCD_ECL2_CLK_SYNC_DROP_POLL_TIMEOUT_HW_NS /
                HCD_ECL2_CLK_SYNC_DROP_POLL_DELAY_HW_NS;

    do
    {
        FAPI_TRY( HCD_GETMMIO_S( i_target, CPMS_CGCSR, l_scomData ) );

        // use multicastOR to check 0
        if( ( !l_attr_runn_mode ) &&
            ( SCOM_GET(33) == 0 ) )
        {
            break;
        }

        fapi2::delay(HCD_ECL2_CLK_SYNC_DROP_POLL_DELAY_HW_NS,
                     HCD_ECL2_CLK_SYNC_DROP_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT( ( l_attr_runn_mode ? ( SCOM_GET(33) == 0 ) : (l_timeout != 0) ),
                 fapi2::ECL2_CLK_SYNC_DROP_TIMEOUT()
                 .set_ECL2_CLK_SYNC_DROP_POLL_TIMEOUT_HW_NS(HCD_ECL2_CLK_SYNC_DROP_POLL_TIMEOUT_HW_NS)
                 .set_CPMS_CGCSR(l_scomData)
                 .set_CORE_TARGET(i_target),
                 "ERROR: ECL2 Clock Sync Drop Timeout");

    FAPI_DBG("Assert CORE_OFF_REQ[0:3] of Resonent Clocking via RCSCR[0:3]");
    FAPI_TRY( HCD_PUTMMIO_Q( eq_target, QME_RCSCR_WO_OR, MMIO_LOAD32H( ( l_regions << SHIFT32(3) ) ) ) );

    FAPI_DBG("Poll for CORE_CHANGE_DONE in RCSR[4:7]");
    l_timeout = HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_TIMEOUT_HW_NS /
                HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_DELAY_HW_NS;

    do
    {
        FAPI_TRY( HCD_GETMMIO_Q( eq_target, QME_RCSCR, l_mmioData ) );

        MMIO_EXTRACT(4, 4, l_core_change_done);

        if( ( !l_attr_runn_mode ) &&
            ( (l_core_change_done & l_regions) == l_regions) )
        {
            break;
        }

        fapi2::delay(HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_DELAY_HW_NS,
                     HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT( ( l_attr_runn_mode ? ((l_core_change_done & l_regions) == l_regions) : (l_timeout != 0)),
                 fapi2::CORE_CHANGE_DONE_RESCLK_ENTRY_TIMEOUT()
                 .set_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_TIMEOUT_HW_NS(HCD_CORE_CHANGE_DONE_RESCLK_ENTRY_POLL_TIMEOUT_HW_NS)
                 .set_CORE_CHANGE_DONE(l_core_change_done)
                 .set_CORE_SELECT(l_regions)
                 .set_CORE_TARGET(i_target),
                 "ERROR: Core Resclk Change Done Entry Timeout");

    FAPI_DBG("Switch glsmux to refclk to save clock grid power via CPMS_CGCSR[11]");
    FAPI_TRY( HCD_PUTMMIO_S( i_target, CPMS_CGCSR_WO_CLEAR, BIT64(11) ) );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_core_stopgrid");

    return fapi2::current_err;

}
