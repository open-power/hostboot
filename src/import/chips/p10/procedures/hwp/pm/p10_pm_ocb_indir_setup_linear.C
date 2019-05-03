/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_ocb_indir_setup_linear.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p10_ocb_indir_setup_linear.C
/// @brief  Configure OCB Channel for Linear Streaming or Non-streaming mode

// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Consumed by     : HS

/// High-level procedure flow:
/// @verbatim
///  Setup specified channel to linear streaming or non-streaming mode by
///  calling p10_pm_ocb_init
///
///  Procedure Prereq:
///     - System clocks are running
/// @endverbatim
///
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p10_pm.H>
#include <p10_pm_ocb_indir_setup_linear.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
fapi2::ReturnCode p10_pm_ocb_indir_setup_linear(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const ocb::PM_OCB_CHAN_NUM  i_ocb_chan,
    const ocb::PM_OCB_CHAN_TYPE i_ocb_type,
    const uint32_t      i_ocb_bar)
{
    FAPI_IMP("> p10_pm_ocb_indir_setup_linear");
    FAPI_DBG("For channel %d as type %d, OCB Bar 0x%x",
             i_ocb_chan, i_ocb_type, i_ocb_bar);

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    FAPI_EXEC_HWP(l_rc,
                  p10_pm_ocb_init,
                  i_target,
                  pm::PM_SETUP_PIB,
                  i_ocb_chan,
                  i_ocb_type,
                  i_ocb_bar,
                  0, // ocb_q_len
                  ocb::OCB_Q_OUFLOW_NULL,
                  ocb::OCB_Q_ITPTYPE_NULL);

    if (l_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_INF("Linear setup of channel %d successful.", i_ocb_chan);
    }
    else
    {
        FAPI_ERR("ERROR: Failed to setup channel %d to linear mode.",
                 i_ocb_chan);
    }

    FAPI_IMP("< p10_pm_ocb_indir_setup_linear");
    return l_rc;
}
