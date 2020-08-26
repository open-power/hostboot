/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_l2_tlbie_quiesce.C $ */
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
/// @file  p10_hcd_l2_tlbie_quiesce.C
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

#include "p10_hcd_l2_tlbie_quiesce.H"
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

enum P10_HCD_L2_TLBIE_QUIESCE_CONSTANTS
{
    HCD_L2_TLBIE_QUIESCE_DELAY_HW_NS      = 5,   // 5ns quiesce delay
    HCD_L2_TLBIE_QUIESCE_DELAY_SIM_CYCLE  = 32,  // 32 sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_l2_tlbie_quiesce
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_l2_tlbie_quiesce(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::buffer<buffer_t> l_mmioData = 0;

    FAPI_INF(">>p10_hcd_l2_tlbie_quiesce");

    FAPI_DBG("Assert L2RCMD_INTF_QUIESCE/NCU_TLBIE_QUIESCE via PCR_SCSR[7,8]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, QME_SCSR_WO_OR, MMIO_LOAD32H( BITS32(7, 2) ) ) );

    FAPI_DBG("Wait ~10 Cache clocks");
    fapi2::delay(HCD_L2_TLBIE_QUIESCE_DELAY_HW_NS,
                 HCD_L2_TLBIE_QUIESCE_DELAY_SIM_CYCLE);

fapi_try_exit:

    FAPI_INF("<<p10_hcd_l2_tlbie_quiesce");

    return fapi2::current_err;

}
