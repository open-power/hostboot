/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_ncu_purge.C $ */
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
/// @file  p10_hcd_ncu_purge.C
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

#include "p10_hcd_ncu_purge.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_ppe_c.H"
    using namespace scomt::ppe_c;
#else
    #include "p10_scom_c.H"
    using namespace scomt::c;
#endif

#ifdef __PPE_QME

    extern void qme_ncu_purge_abort_detect();

#endif

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

enum P10_HCD_NCU_PURGE_CONSTANTS
{
    HCD_NCU_PURGE_DONE_POLL_TIMEOUT_HW_NS    = 100000000, // 10^5ns = 100us timeout
    HCD_NCU_PURGE_DONE_POLL_DELAY_HW_NS      = 1000,   // 1us poll loop delay
    HCD_NCU_PURGE_DONE_POLL_DELAY_SIM_CYCLE  = 32000,  // 32k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_ncu_purge
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_ncu_purge(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::buffer<buffer_t> l_mmioData = 0;
    uint32_t                l_timeout  = 0;

    FAPI_INF(">>p10_hcd_ncu_purge");

    FAPI_DBG("Assert NCU_PURGE_REQ via PCR_SCSR[9]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_SCSR_WO_OR, MMIO_1BIT(9) ) );

    FAPI_DBG("Wait for NCU_PURGE_DONE via PCR_SCSR[41]");
    l_timeout = HCD_NCU_PURGE_DONE_POLL_TIMEOUT_HW_NS /
                HCD_NCU_PURGE_DONE_POLL_DELAY_HW_NS;

    do
    {

#ifdef __PPE_QME

        qme_ncu_purge_abort_detect();

#endif

        FAPI_TRY( HCD_GETMMIO_C( i_target, MMIO_LOWADDR(QME_SCSR), l_mmioData ) );

        // use multicastAND to check 1
        if( MMIO_GET( MMIO_LOWBIT(41) ) == 1 )
        {
            break;
        }

        fapi2::delay(HCD_NCU_PURGE_DONE_POLL_DELAY_HW_NS,
                     HCD_NCU_PURGE_DONE_POLL_DELAY_SIM_CYCLE);
    }
    while( (--l_timeout) != 0 );

    HCD_ASSERT((l_timeout != 0),
               NCU_PURGE_DONE_TIMEOUT,
               set_NCU_PURGE_DONE_POLL_TIMEOUT_HW_NS, HCD_NCU_PURGE_DONE_POLL_TIMEOUT_HW_NS,
               set_QME_SCSR, l_mmioData,
               set_CORE_TARGET, i_target,
               "ERROR: NCU Purge Done Timeout");

    FAPI_DBG("Drop NCU_PURGE_REQ/ABORT via PCR_SCSR[9,10]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_SCSR_WO_CLEAR, MMIO_LOAD32H( BITS32(9, 2) ) ) );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_ncu_purge");

    return fapi2::current_err;

}
