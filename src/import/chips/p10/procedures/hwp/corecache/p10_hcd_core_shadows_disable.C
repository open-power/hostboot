/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_core_shadows_disable.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file  p10_hcd_core_shadows_disable.C
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

#include "p10_hcd_core_shadows_disable.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_ppe_c.H"
    using namespace scomt::ppe_c;
#else
    #include "p10_scom_c.H"
    using namespace scomt::c;
#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_CORE_SHADOWS_DISABLE_CONSTANTS
{
    HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_TIMEOUT_HW_NS   = 100000, // 10^5ns = 100us timeout
    HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_DELAY_HW_NS     = 1000,   // 1us poll loop delay
    HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_DELAY_SIM_CYCLE = 32000,  // 32k sim cycle delay
    HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_TIMEOUT_HW_NS   = 100000, // 10^5ns = 100us timeout
    HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_DELAY_HW_NS     = 1000,   // 1us poll loop delay
    HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_DELAY_SIM_CYCLE = 32000,  // 32k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_core_shadows_disable
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_core_shadows_disable(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::buffer<buffer_t> l_mmioData = 0;
    uint32_t                l_timeout  = 0;
    uint32_t                l_shadow_states = 0;

    FAPI_INF(">>p10_hcd_core_shadows_disable");

    FAPI_DBG("Disable CORE_SHADOW and CORE_SAMPLE via CUCR[0, 1]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, CPMS_CUCR_WO_CLEAR, MMIO_LOAD32H(BITS32(0, 2)) ) );

    FAPI_DBG("Wait for FTC/PP/DPT_SHADOW_STATE to be Idle via CUCR[33-35,40-41,45-46]");
    l_timeout = HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_TIMEOUT_HW_NS /
                HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_DELAY_HW_NS;

    do
    {
        FAPI_TRY( HCD_GETMMIO_C( i_target, MMIO_LOWADDR(CPMS_CUCR), l_mmioData ) );

        // use multicastAND to check 0
        MMIO_GET32L(l_shadow_states);

        if( !( l_shadow_states & ( BITS64SH(33, 3) | BITS64SH(40, 2) | BITS64SH(45, 2) ) ) )
        {
            break;
        }

        fapi2::delay(HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_DELAY_HW_NS,
                     HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT((l_timeout != 0),
                fapi2::SHADOW_DIS_CORE_SHADOW_STATE_TIMEOUT()
                .set_SHADOW_DIS_CORE_SHADOW_STATE_POLL_TIMEOUT_HW_NS(HCD_SHADOW_DIS_CORE_SHADOW_STATE_POLL_TIMEOUT_HW_NS)
                .set_CPMS_CUCR(l_mmioData)
                .set_CORE_TARGET(i_target),
                "Shadow Disable FTC/PP/DPT Shadow State Timeout");

#ifndef XFER_SENT_DONE_DISABLE

    FAPI_DBG("Wait on XFER_RECEIVE_DONE via PCR_TFCSR[32]");
    l_timeout = HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_TIMEOUT_HW_NS /
                HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_DELAY_HW_NS;

    do
    {
        FAPI_TRY( HCD_GETMMIO_C( i_target, MMIO_LOWADDR(QME_TFCSR), l_mmioData ) );

        // use multicastAND to check 1
        if( MMIO_GET(MMIO_LOWBIT(32)) == 1 )
        {
            break;
        }

        fapi2::delay(HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_DELAY_HW_NS,
                     HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT((l_timeout != 0),
                fapi2::SHADOW_DIS_XFER_RECEIVE_DONE_TIMEOUT()
                .set_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_TIMEOUT_HW_NS(HCD_SHADOW_DIS_XFER_RECEIVE_DONE_POLL_TIMEOUT_HW_NS)
                .set_QME_TFCSR(l_mmioData)
                .set_CORE_TARGET(i_target),
                "Shadow Disable Xfer Receive Done Timeout");

    FAPI_DBG("Drop XFER_RECEIVE_DONE via PCR_TFCSR[32]");
    FAPI_TRY( HCD_GETMMIO_C( i_target, MMIO_LOWADDR(QME_TFCSR_WO_CLEAR), MMIO_1BIT( MMIO_LOWBIT(32) ) ) );

#endif

    FAPI_DBG("Assert CTFS_WKUP_ENABLE via PCR_SCSR[27]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_SCSR_WO_OR, MMIO_1BIT(27) ) );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_core_shadows_disable");

    return fapi2::current_err;

}
