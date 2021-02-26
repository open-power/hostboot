/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_hcd_mma_poweroff.C $ */
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
/// @file  p10_hcd_mma_poweroff.C
/// @brief Power off MMA VDD+VCS PFET headers
///

// *HWP HWP Owner          : David Du               <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still             <stillgs@us.ibm.com>
// *HWP FW Owner           : Prasad Brahmasamurdra  <prasadbgr@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : SBE:QME
// *HWP Level              : 2


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "p10_hcd_mma_poweroff.H"
#include "p10_hcd_corecache_power_control.H"
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


//------------------------------------------------------------------------------
// Procedure: p10_hcd_mma_poweroff
//------------------------------------------------------------------------------


fapi2::ReturnCode
p10_hcd_mma_poweroff(
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST, fapi2::MULTICAST_AND > & i_target)
{
    fapi2::buffer<buffer_t> l_mmioData = 0;

    FAPI_INF(">>p10_hcd_mma_poweroff");

    // MMA PFET Power On/Off sequence requires CL2 PFET[ON] + CL2 RegulationFinger[ON]
    // Here always assert RF before operate on MMA power.

    // After MMA is off,
    // Due to Stop3 requires RegulationFinger to be ON while OFF for stop11,
    // Here handle drop RF outside of this procedure

    // Stop3: Set RF -> MMA PFET[OFF] -> CL2 PFET[Vmin]
    // Exit3:                            CL2 PFET[ON] -> MMA PFET[ON] (keep RF on)

    // Stop11: Set RF -> MMA PFET[OFF] -> Drop RF -> CL2 PFET[OFF]
    // Exit11:                                       CL2 PFET[ON] -> Set RF -> MMA PFET[ON] (keep RF on)
    FAPI_DBG("Assert VDD_PFET_REGULATION_FINGER_EN via CPMS_CL2_PFETCNTL[8]");
    FAPI_TRY( HCD_PUTMMIO_S( i_target, CPMS_CL2_PFETCNTL_WO_OR, BIT64(8) ) );

    // Also note MMA only has VDD
    FAPI_TRY( p10_hcd_corecache_power_control( i_target, HCD_POWER_MMA_OFF ) );

fapi_try_exit:

    FAPI_INF("<<p10_hcd_mma_poweroff");

    return fapi2::current_err;

}
