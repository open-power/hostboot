/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_core_shadows_disable.C $ */
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
/// @file  p10_hcd_core_shadows_disable.C
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

#include "p10_hcd_core_shadows_disable.H"
#include "p10_hcd_common.H"
#include "p10_pm_hcd_flags.h"

#ifdef __PPE_QME
    #include "p10_scom_c_9.H"
    #include "p10_ppe_c.H"
    #include "p10_ppe_eq.H"
    using namespace scomt::c;
    using namespace scomt::ppe_c;
    using namespace scomt::ppe_eq;
    #define QME_FLAGS_TOD_COMPLETE QME_FLAGS_TOD_SETUP_COMPLETE
    #define QME_FLAGS_DDS_ENABLED  QME_FLAGS_DDS_OPERABLE
#else
    #include "p10_scom_c.H"
    #include "p10_scom_eq.H"
    using namespace scomt::c;
    using namespace scomt::eq;
    #define QME_FLAGS_TOD_COMPLETE p10hcd::QME_FLAGS_TOD_SETUP_COMPLETE
    #define QME_FLAGS_DDS_ENABLED  p10hcd::QME_FLAGS_DDS_OPERABLE
#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_CORE_SHADOWS_DISABLE_CONSTANTS
{
    HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_TIMEOUT_HW_NS   = 100000, // 10^5ns = 100us timeout
    HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_DELAY_HW_NS     = 1000,   // 1us poll loop delay
    HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_DELAY_SIM_CYCLE = 32000,  // 32k sim cycle delay
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
    uint32_t                l_tfcsr_errors = 0;
    uint32_t                l_dds_operable = 0;

    FAPI_INF(">>p10_hcd_core_shadows_disable");

    fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > l_mc_or = i_target;//default OR
    fapi2::Target < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > l_eq_target =
        i_target.getParent < fapi2::TARGET_TYPE_EQ | fapi2::TARGET_TYPE_MULTICAST > ();

    FAPI_TRY(HCD_GETMMIO_Q( l_eq_target, QME_FLAGS_RW, l_mmioData ) );
    l_dds_operable = MMIO_GET(QME_FLAGS_DDS_ENABLED);

    if ( MMIO_GET ( QME_FLAGS_TOD_COMPLETE ) == 1 )
    {
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
                    "ERROR: Shadow Disable Xfer Receive Done Timeout");

        FAPI_DBG("Check INCOMING/RUNTIME/STATE_ERR == 0 via PCR_TFCSR[34-36]");
        FAPI_TRY( HCD_GETMMIO_C( l_mc_or, MMIO_LOWADDR(QME_TFCSR), l_mmioData ) );

        MMIO_EXTRACT(MMIO_LOWBIT(34), 3, l_tfcsr_errors);

        if( l_tfcsr_errors != 0 )
        {
            FAPI_DBG("Clear INCOMING/RUNTIME/STATE_ERR[%x] via PCR_TFCSR[34-36]", l_tfcsr_errors);
            FAPI_TRY( HCD_PUTMMIO_C( i_target, MMIO_LOWADDR(QME_TFCSR_WO_CLEAR), MMIO_LOAD32L( BITS64SH(34, 3) ) ) );

            FAPI_DBG("Assert TFAC_RESET via PCR_TFCSR[1]");
            FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_TFCSR_WO_OR, MMIO_1BIT(1) ) );

            FAPI_DBG("Reset the core timefac to INACTIVE via PC.COMMON.TFX[1]");
            FAPI_TRY( HCD_PUTSCOM_C( i_target, EC_PC_TFX_SM, BIT64(1) ) );
        }

        FAPI_ASSERT((l_tfcsr_errors == 0),
                    fapi2::SHADOW_DIS_TFCSR_ERROR_CHECK_FAILED()
                    .set_QME_TFCSR(l_tfcsr_errors)
                    .set_CORE_TARGET(i_target),
                    "ERROR: Shadow Disable TFCSR Error Check Failed");

        FAPI_DBG("Drop XFER_RECEIVE_DONE via PCR_TFCSR[32]");
        FAPI_TRY( HCD_PUTMMIO_C( i_target, MMIO_LOWADDR(QME_TFCSR_WO_CLEAR), MMIO_1BIT( MMIO_LOWBIT(32) ) ) );
    }
    else
    {
        FAPI_INF("TOD not enabled.  Resetting TimeFac Shadow");

        FAPI_DBG("Assert TFAC_RESET via PCR_TFCSR[1]");
        FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_TFCSR_WO_OR, BIT32(1) ) );

        FAPI_DBG("Reset the core timefac to INACTIVE via PC.COMMON.TFX[1]");
        FAPI_TRY( HCD_PUTSCOM_C( i_target, EC_PC_TFX_SM, BIT64(1) ) );
    }

    FAPI_DBG("Disable CORE_SAMPLE via CUCR[1]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, CPMS_CUCR_WO_CLEAR, MMIO_LOAD32H(BIT32(1)) ) );

    if( l_dds_operable )
    {
        FAPI_DBG("Disable Droop Detection and Cancel Active Droop Response via FDCR[0,2-3]");
        FAPI_TRY( HCD_PUTMMIO_C( i_target, CPMS_FDCR_WO_OR, MMIO_LOAD32H( (BIT32(0) | BITS32(2, 2)) ) ) );

        FAPI_DBG("Wait for FDCR_UPDATE_IN_PROGRESS to be 0x0 via CUCR[31]");
        l_timeout = HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_TIMEOUT_HW_NS /
                    HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_DELAY_HW_NS;

        do
        {
            FAPI_TRY( HCD_GETMMIO_C( i_target, CPMS_CUCR, l_mmioData ) );

            // use multicastAND to check 0
            if( MMIO_GET(31) == 0 )
            {
                break;
            }

            fapi2::delay(HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_DELAY_HW_NS,
                         HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_DELAY_SIM_CYCLE);
        }
        while( (--l_timeout) != 0 );

        FAPI_ASSERT((l_timeout != 0),
                    fapi2::SHADOW_DIS_FDCR_UPDATE_IN_PROG_TIMEOUT()
                    .set_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_TIMEOUT_HW_NS(HCD_SHADOW_DIS_FDCR_UPDATE_IN_PROG_POLL_TIMEOUT_HW_NS)
                    .set_CPMS_CUCR(l_mmioData)
                    .set_CORE_TARGET(i_target),
                    "ERROR: FDCR Update Timeout");
    }

    FAPI_DBG("Disable CORE_SHADOW via CUCR[0]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, CPMS_CUCR_WO_CLEAR, MMIO_LOAD32H(BIT32(0)) ) );

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
                "ERROR: Shadow Disable FTC/PP/DPT Shadow State Timeout");

    FAPI_DBG("Assert CTFS_WKUP_ENABLE via PCR_SCSR[27]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_SCSR_WO_OR, MMIO_1BIT(27) ) );

fapi_try_exit:
    FAPI_INF("<<p10_hcd_core_shadows_disable");
    return fapi2::current_err;
}
