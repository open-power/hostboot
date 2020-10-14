/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_l2_purge.C $ */
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
/// @file  p10_hcd_l2_purge.C
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

#include "p10_hcd_l2_purge.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_ppe_c.H"
    using namespace scomt::ppe_c;
    extern void qme_l2_purge_catchup_detect(uint32_t&);
    extern void qme_l2_purge_abort_detect();
#else
    #include <multicast_group_defs.H>
    #include "p10_scom_c.H"
    using namespace scomt::c;
#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_L2_PURGE_CONSTANTS
{
    HCD_L2_PURGE_DONE_POLL_TIMEOUT_HW_NS          = 100000000, // 10^5ns = 100us timeout
    HCD_L2_PURGE_DONE_POLL_DELAY_HW_NS            = 1000,   // 1us poll loop delay
    HCD_L2_PURGE_DONE_POLL_DELAY_SIM_CYCLE        = 32000,  // 32k sim cycle delay
    HCD_PMSR_SHIFT_INACTIVE_POLL_TIMEOUT_HW_NS    = 100000, // 10^5ns = 100us timeout
    HCD_PMSR_SHIFT_INACTIVE_POLL_DELAY_HW_NS      = 1000,   // 1us poll loop delay
    HCD_PMSR_SHIFT_INACTIVE_POLL_DELAY_SIM_CYCLE  = 32000,  // 32k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_l2_purge
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_l2_purge(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > l_target  = i_target;
    fapi2::buffer<buffer_t> l_mmioData = 0;
    uint32_t                l_timeout  = 0;
    uint32_t                l_l2_purge_done = 0;

    FAPI_INF(">>p10_hcd_l2_purge");

    FAPI_DBG("Assert HBUS_DISABLE/L2_PURGE_REQ/AUTO_PMSR_SHIFT_DIS via PCR_SCSR[4,5,22]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_SCSR_WO_OR, MMIO_LOAD32H( (BITS32(4, 2) | BIT32(22)) ) ) );

    FAPI_DBG("Wait for L2_PURGE_DONE/HBUS_INACTIVE via PCR_SCSR[36,37]");
    l_timeout = HCD_L2_PURGE_DONE_POLL_TIMEOUT_HW_NS /
                HCD_L2_PURGE_DONE_POLL_DELAY_HW_NS;

    do
    {

#ifdef __PPE_QME

        fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > l_chip =
            i_target.getParent< fapi2::TARGET_TYPE_PROC_CHIP >();
        uint32_t l_core_select = 0;

        qme_l2_purge_catchup_detect(l_core_select);

        if (!l_core_select)
        {
            l_core_select = l_target.getCoreSelect();
        }

        l_target = l_chip.getMulticast<fapi2::MULTICAST_AND>(fapi2::MCGROUP_GOOD_EQ,
                   static_cast<fapi2::MulticastCoreSelect>(l_core_select));

        qme_l2_purge_abort_detect();

        FAPI_TRY( HCD_GETMMIO_C( l_target, MMIO_LOWADDR(QME_SCSR), l_mmioData ) );
#else

        FAPI_TRY( HCD_GETMMIO_C( l_target, MMIO_LOWADDR(QME_SCSR), l_mmioData ) );

#endif

        // use multicastAND to check 1
        MMIO_GET32L(l_l2_purge_done);

        if( ( l_l2_purge_done & BITS64SH(36, 2) ) == BITS64SH(36, 2) )
        {
            break;
        }

        fapi2::delay(HCD_L2_PURGE_DONE_POLL_DELAY_HW_NS,
                     HCD_L2_PURGE_DONE_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    /*debug only
    #ifdef __PPE_QME
        if( l_timeout == 0)
        {
            uint32_t temp[4] = {0,0,0,0};
            fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > tar  = i_target;
            fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP > l_chip =
                i_target.getParent< fapi2::TARGET_TYPE_PROC_CHIP >();

            for( int i=0; i<4; i++ )
            {
                tar = l_chip.getMulticast<fapi2::MULTICAST_AND>(fapi2::MCGROUP_GOOD_EQ,
                       static_cast<fapi2::MulticastCoreSelect>(i));
                FAPI_TRY( HCD_GETMMIO_C( tar, MMIO_LOWADDR(QME_SCSR), l_mmioData ) );
                temp[i] = l_mmioData;
            }
            FAPI_IMP("L2 Purge Done Timeout %x %x %x %x", temp[0], temp[1], temp[2], temp[3]);
        }
    #endif
    */
    FAPI_ASSERT((l_timeout != 0),
                fapi2::L2_PURGE_DONE_TIMEOUT()
                .set_L2_PURGE_DONE_POLL_TIMEOUT_HW_NS(HCD_L2_PURGE_DONE_POLL_TIMEOUT_HW_NS)
                .set_QME_SCSR(l_mmioData)
                .set_CORE_TARGET(i_target),
                "ERROR: L2 Purge Done Timeout");

    FAPI_DBG("Wait for PMSR_SHIFT_INACTIVE to assert via PCR_SCSR[56]");
    l_timeout = HCD_PMSR_SHIFT_INACTIVE_POLL_TIMEOUT_HW_NS /
                HCD_PMSR_SHIFT_INACTIVE_POLL_DELAY_HW_NS;

    do
    {
        FAPI_TRY( HCD_GETMMIO_C( l_target, MMIO_LOWADDR(QME_SCSR), l_mmioData ) );

        // use multicastOR to check 0
        if( MMIO_GET(MMIO_LOWBIT(56)) == 1 )
        {
            break;
        }

        fapi2::delay(HCD_PMSR_SHIFT_INACTIVE_POLL_DELAY_HW_NS,
                     HCD_PMSR_SHIFT_INACTIVE_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    FAPI_ASSERT((l_timeout != 0),
                fapi2::PMSR_SHIFT_INACTIVE_TIMEOUT()
                .set_PMSR_SHIFT_INACTIVE_POLL_TIMEOUT_HW_NS(HCD_PMSR_SHIFT_INACTIVE_POLL_TIMEOUT_HW_NS)
                .set_QME_SCSR(l_mmioData)
                .set_CORE_TARGET(i_target),
                "ERROR: PMSR_SHIFT_INACTIVE Timeout");

    FAPI_DBG("Drop L2_PURGE_REQ/ABORT via PCR_SCSR[5, 6]");
    FAPI_TRY( HCD_PUTMMIO_C( l_target, QME_SCSR_WO_CLEAR, MMIO_LOAD32H( BITS32(5, 2) ) ) );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_l2_purge");

    return fapi2::current_err;

}
