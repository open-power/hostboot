/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_ocb_indir_setup_linear.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_pm_ocb_indir_setup_linear.C
/// @brief  Configure OCB Channel for Linear Streaming or Non-streaming mode

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS

#ifndef _P9_PM_OCB_INDIR_SETUP_LINEAR_H_
#define _P9_PM_OCB_INDIR_SETUP_LINEAR_H_

#include <fapi2.H>
#include <p9_pm_ocb_init.H>

typedef fapi2::ReturnCode (*p9_pm_ocb_indir_setup_linear_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const p9ocb::PM_OCB_CHAN_NUM,
 const p9ocb::PM_OCB_CHAN_TYPE,
 const uint32_t);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// @brief  Configure OCB Channel for Linear Streaming or Non-streaming mode
/// @param[in]  i_target   Chip Target
/// @param[in]  i_ocb_chan select channel 0-3 to set up      (see p8_ocb_init.H)
/// @param[in]  i_ocb_type linear streaming or non-streaming (see p8_ocb_init.H)
/// @param[in]  i_ocb_bar  32-bit channel base address (29 bits + "000")
/// @return FAPI2_RC_SUCCESS on success, else error.

    fapi2::ReturnCode p9_pm_ocb_indir_setup_linear(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9ocb::PM_OCB_CHAN_NUM  i_ocb_chan,
        const p9ocb::PM_OCB_CHAN_TYPE i_ocb_type,
        const uint32_t      i_ocb_bar);

} // extern "C"

#endif
