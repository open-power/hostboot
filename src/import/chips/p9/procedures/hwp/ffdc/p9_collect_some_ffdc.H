/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_collect_some_ffdc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef _COLLECT_SOME_FFDC_H_
#define _COLLECT_SOME_FFDC_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_collect_some_ffdc_FP_t)(std::vector<std::shared_ptr<fapi2::ErrorInfoFfdc>>& o_ffdc_data,
        uint32_t a, uint8_t b);

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{
///
/// @brief Sample procedure used to demonstrate FFDC collection using
///        collectFfdc tag in xml files
/// @param[in] o_ffdc_data - default parameter ffdc data returned in this
///                           vector
///  @param[in] a - parameter passed from the SBE through the ffdc data buffer
///  @param[in] b - parameter passed from the SBE through the ffdc data buffer
///
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_collect_some_ffdc(std::vector<std::shared_ptr<fapi2::ErrorInfoFfdc>>& o_ffdc_data, uint32_t a,
                                           uint8_t b);

} // extern "C"

#endif // _PROC_EXAMPLE_H_
