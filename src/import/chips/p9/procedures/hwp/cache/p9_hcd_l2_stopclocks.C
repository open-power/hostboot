/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_hcd_l2_stopclocks.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file  p9_hcd_l2_stopclocks.C
/// @brief Quad Clock Stop
///
/// Procedure Summary:

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : HB:PREV
// *HWP Level              : 2

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_misc_scom_addresses.H>
#include <p9_quad_scom_addresses.H>
#include <p9_hcd_common.H>
#include "p9_hcd_l2_stopclocks.H"

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Procedure: Quad Clock Stop
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_hcd_l2_stopclocks(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target)
{
    FAPI_INF(">>p9_hcd_l2_stopclocks");

    FAPI_INF("<<p9_hcd_l2_stopclocks");
    return fapi2::FAPI2_RC_SUCCESS;
}

