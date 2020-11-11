/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_scominit.H $ */
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
/// @file  p10_pcie_scominit.H
/// @brief Perform PCIE SCOM initialization (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

///
/// *HWP HW Maintainer: Ricardo Mata Jr. (ricmata@us.ibm.com)
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

#ifndef _P10_PCIE_SCOMINIT_H_
#define _P10_PCIE_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>


//----------------------------------------------------------------------------
// Structure definitions
//----------------------------------------------------------------------------
// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pcie_scominit_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief p10_pcie_scominit procedure
///
/// Initializes PCIE unit SCOM registers of the target processor
///
/// @param[in] i_target Reference to processor chip target
/// @return FAPI2_RC_SUCCESS if success, else error code.
///

    fapi2::ReturnCode p10_pcie_scominit(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief p10_load_iop_override procedure
///
/// Initializes CReg Overrides through the CR Parallel Interface
/// Function needs to be called when phy is out of reset in proc_load_iop_xram
///
/// @param[in] i_target Reference to processor chip target
/// @return FAPI2_RC_SUCCESS if success, else error code.
///

    fapi2::ReturnCode p10_load_iop_override(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


///
/// @brief p10_load_rtrim_override procedure
///
/// Initializes CReg Overrides through the CR Parallel Interface
/// Function needs to be called when phy is out of reset in proc_load_iop_xram
///
/// @param[in] i_target Reference to processor chip target
/// @return FAPI2_RC_SUCCESS if success, else error code.
///

    fapi2::ReturnCode p10_load_rtrim_override(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


///
/// @brief p10_verify_iop_fw procedure
///
/// Reads FW version via CR Parallel Interface and compares with HW image
/// version information
/// Function needs to be called when phy is out of reset in proc_load_iop_xram
///
/// @param[in] i_target Reference to processor chip target
/// @return FAPI2_RC_SUCCESS if success, else error code.
///

    fapi2::ReturnCode p10_verify_iop_fw(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


} // extern "C"

#endif  // _P10_PCIE_SCOMINIT_H_
