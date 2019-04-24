/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_core_stopgrid.C $ */
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
/// @file  p10_hcd_core_stopgrid.C
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

#include "p10_hcd_core_stopgrid.H"
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

enum P10_HCD_CORE_STOPGRID_CONSTANTS
{
    HCD_L2_PURGE_DONE_POLL_TIMEOUT_HW_NS    = 100000, // 10^5ns = 100us timeout
    HCD_L2_PURGE_DONE_POLL_DELAY_HW_NS      = 1000,   // 1us poll loop delay
    HCD_L2_PURGE_DONE_POLL_DELAY_SIM_CYCLE  = 32000,  // 32k sim cycle delay
};

//------------------------------------------------------------------------------
// Procedure: p10_hcd_core_stopgrid
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_hcd_core_stopgrid(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::buffer<buffer_t> l_mmioData = 0;

    FAPI_INF(">>p10_hcd_core_stopgrid");

    FAPI_DBG("Switch glsmux to refclk to save clock grid power via CPMS_CGCSR[11]");
    FAPI_TRY( HCD_PUTMMIO_C( i_target, CPMS_CGCSR_WO_CLEAR, MMIO_1BIT(11) ) );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_core_stopgrid");

    return fapi2::current_err;

}
