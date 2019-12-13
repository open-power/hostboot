/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_mma_stopclocks.C $ */
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
/// @file  p10_hcd_mma_stopclocks.C
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

#include "p10_hcd_mma_stopclocks.H"
#include "p10_hcd_corecache_clock_control.H"
#include "p10_hcd_common.H"

#ifdef __PPE_QME
    #include "p10_scom_eq.H"
    #include "p10_ppe_c.H"
    using namespace scomt::eq;
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

enum P10_HCD_MMA_STOPCLOCKS_CONSTANTS
{
    HCD_MMA_CLK_SYNC_DROP_POLL_TIMEOUT_HW_NS        = 10000,   // 10^4ns = 10us timeout
    HCD_MMA_CLK_SYNC_DROP_POLL_DELAY_HW_NS          = 100,     // 100ns poll loop delay
    HCD_MMA_CLK_SYNC_DROP_POLL_DELAY_SIM_CYCLE      = 3200,    // 3.2k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_mma_stopclocks
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_mma_stopclocks(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_OR > & i_target)
{
    return fapi2::current_err;
}
