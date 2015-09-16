/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_ocb_indir_setup_circular.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file  p9_pm_ocb_indir_setup_circular.C
/// @brief  Configure OCB Channels for Circular Push or Pull Mode
///
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP Backup HWP Owner:
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS


/// High-level procedure flow:
/// @verbatim
///  Setup specified channel to push or pull circular mode by calling
///  proc proc_ocb_init
///
///  Procedure Prereq:
///     - System clocks are running
/// @endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_pm_ocb_indir_setup_circular.H>

fapi2::ReturnCode p9_pm_ocb_indir_setup_circular(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    p9ocb::PM_OCB_CHAN_NUM i_ocb_chan,
    p9ocb::PM_OCB_CHAN_TYPE i_ocb_type)
{
    FAPI_IMP("Entering...");
    FAPI_DBG("For channel %x as type %x", i_ocb_chan, i_ocb_type);

    return fapi2::FAPI2_RC_SUCCESS;
}
