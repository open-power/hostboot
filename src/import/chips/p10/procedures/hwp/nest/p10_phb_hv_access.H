/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_phb_hv_access.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
//------------------------------------------------------------------------------

///
/// @file p10_phb_hv_access.H
/// @brief Code to support PHB HV Indirect access procedures (FAPI)
///
/// @author ricmata@us.ibm.com
///

// *HWP HWP Owner: Ricardo Mata Jr. ricmata@us.ibm.com
// *HWP FW Owner:
// *HWP Team: Nest
// *HWP Level:
// *HWP Consumed by: HB

// EKB-Mirror-To: hostboot

#ifndef _P10_PHB_HV_ACCESS_H_
#define _P10_PHB_HV_ACCESS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_phb_hv_access_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PHB>&,
    const uint32_t,
    bool const,
    bool const,
    uint64_t&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C" {

/// @brief perform read/write to PHB HV register space
/// @param[in] i_target PHB target
/// @param[in] i_address PHB HV register offset between 0x0000 - 0x1FFF
/// @param[in] i_rnw 1 for read, 0 for write
/// @param[in] i_size 1 for 8B op to access PHB HV. 0 for 4B op for config ops
/// @param[inout] io_data Input data for writes / output data for reads
///
/// @return FAPI_RC_SUCCESS if the read/write completes successfully.
    fapi2::ReturnCode p10_phb_hv_access(
        const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
        const uint32_t i_address,
        bool const i_rnw,
        bool const i_size,
        uint64_t& io_data);

} // extern "C"

#endif //_P10_PHB_HV_ACCESS_H_
