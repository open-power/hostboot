/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_l3err_extract.H $ */
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
/// @file p10_l3err_extract.H
///
/// @brief Parse and extract error information from L3 trace array (FAPI2)
///
/// *HWP HW Maintainer: Benjamin Gass <bgass@ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB, PRDF
///----------------------------------------------------------------------------
#ifndef _P10_L3ERR_EXTRACT_H_
#define _P10_L3ERR_EXTRACT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// enum used to denote what type of error occured or which we want to find
enum p10_l3err_extract_err_type
{
    L3ERR_CE,
    L3ERR_UE,
    L3ERR_CE_UE
};

// structure to document control/data registers for each supported trace array
struct p10_l3err_extract_err_data
{
    p10_l3err_extract_err_type ce_ue;
    uint8_t member;
    uint8_t dw;
    uint8_t bank;
    uint8_t syndrome_col;
    uint16_t real_address_46_57;
};

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_l3err_extract_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
 const fapi2::variable_buffer&,
 p10_l3err_extract_err_type,
 p10_l3err_extract_err_data&,
 bool&);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
///
/// @brief  FAPI2 p10_l3err_extract HWP entry point
///         Parse and extract L3 error information from provided
///         L3_T0 trace array that has been stopped on an L3 CE or UE.
///
/// @param[in]  i_target      => core chiplet target
/// @param[in]  i_ta_data     => Input trace data buffer
/// @param[in]  i_err_type    => Type of error that is to be extracted (CE,UE,both)
/// @param[out] o_err_data    => Failing location information for CE or UE
/// @param[out] o_error_found => Error is found
///
    fapi2::ReturnCode p10_l3err_extract(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const fapi2::variable_buffer& i_ta_data,
        p10_l3err_extract_err_type i_err_type,
        p10_l3err_extract_err_data& o_err_data,
        bool& o_error_found);

} // extern "C"

#endif // _P10_L3ERR_EXTRACT_H_
