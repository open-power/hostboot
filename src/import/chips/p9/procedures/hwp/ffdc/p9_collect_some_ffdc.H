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
#include <return_code.H>
#include <error_info_defs.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_collect_some_ffdc_FP_t)(fapi2::ffdc_t& i_param1, fapi2::ReturnCode&);

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
///                           vector
///  @param[in] a - parameter passed in from calling context
///  @param[out] o_rc - return code to add FFDC data to.
///
/// @return FAPI2_RC_SUCCESS iff ok
///
/// NOTE: All input parameters must be of type fapi2::ffdc_t and converted
///       to the correct type inside the function.
///
    fapi2::ReturnCode p9_collect_some_ffdc(fapi2::ffdc_t&,
                                           fapi2::ReturnCode& );

} // extern "C"

#endif // _PROC_EXAMPLE_H_
