/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_core_topo.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
//------------------------------------------------------------------------------------
//
/// @file p10_fbc_core_topo.H
/// @brief Create SCOM restore HOMER entries for the EQ fabric topology tables
///
// *HWP HW Maintainer : Greg Still (stillgs@us.ibm.com)
// *HWP FW Maintainer : TBD
// *HWP Consumed by   : HB

// EKB-Mirror-To: hostboot
// EKB-Mirror-To: hw/ppe

#ifndef _P10_FBC_CORE_TOPO_H_
#define _P10_FBC_CORE_TOPO_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------

#include <fapi2.H>
#include <p10_stop_api.H>

namespace rt_topo
{
enum rt_mode_t
{
    RT_TOPO_MODE_HW,
    RT_TOPO_MODE_HOMER
};

} // end of rt_topo namespace

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------
typedef fapi2::ReturnCode
(*p10_fbc_core_topo_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > &,
    const std::vector<uint64_t>&,
    void*,
    const stopImageSection::ScomSection_t,
    const rt_topo::rt_mode_t);

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Put EQ topology id tables into either Hardware or HOMER for restoration
/// @param[in] i_target         Core Target or Multicast
/// @param[in] i_topo_scoms     Vector of topology entries
/// @param[in] i_pImage         Pointer to HOMER image to update (if non-SBE)
/// @param[in] i_section        (if non-SBE) HOMER SCOM section (CL2/L3)to place values
/// @param[in] i_section        (if SBE) SCOM hardware region to write values (eg CL2/L3e)
/// @param[in] i_mode           Either write to hardware or place values in HOMER
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS on success, error otherwise
///

    fapi2::ReturnCode
    p10_fbc_core_topo(
        const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const std::vector<uint64_t>& i_topo_scoms,
        void* i_pImage,  // This needs to be point to the appropriate chip HOMER for mode HOMER
        const stopImageSection::ScomSection_t i_section,
        const rt_topo::rt_mode_t i_mode);

} //extern "C"

#endif //_P10_FBC_CORE_TOPO_H_
