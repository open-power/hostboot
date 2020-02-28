/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_l3err_linedelete.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
///----------------------------------------------------------------------------
///
/// @file p10_l3err_linedelete.H
///
/// @brief Delete the L3 error cache line according to the error extraction
///        information.
///
/// *HWP HW Maintainer: Benjamin Gass <bgass@ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB, PRDF
///----------------------------------------------------------------------------
#ifndef _P10_L3ERR_LINEDELETE_H_
#define _P10_L3ERR_LINEDELETE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_l3err_extract.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode(*p10_l3err_linedelete_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
 const p10_l3err_extract_err_data&,
 const uint64_t p10_l3err_linedelete_TryBusyCounts);

extern "C"
{


//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
///
/// @brief  Perform L3 Line Delete on an EX target using input L3
///         error data information.
///
/// @param[in]  i_target       => EX chiplet target
/// @param[in]  i_err_data     => L2 error data
/// @param[in]  i_busyCount    => Max busy count waiting for PURGE to complete.
///
    fapi2::ReturnCode p10_l3err_linedelete(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const p10_l3err_extract_err_data& i_err_data,
        const uint64_t i_busyCount);

} // extern "C"

#endif // _P10_L3ERR_LINEDELETE_H_
