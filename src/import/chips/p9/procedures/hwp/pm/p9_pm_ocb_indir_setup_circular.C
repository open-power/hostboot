/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_ocb_indir_setup_circular.C $ */
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
/// @file  p9_pm_ocb_indir_setup_circular.C
/// @brief  Configure OCB Channels for Circular Push or Pull Mode
///
// *HWP HWP Owner       : Amit Kumar <akumar@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS

/// High-level procedure flow:
/// @verbatim
///  Setup specified channel to push or pull circular mode by calling
///  p9_pm_ocb_init
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
    const p9ocb::PM_OCB_CHAN_NUM i_ocb_chan,
    const p9ocb::PM_OCB_CHAN_TYPE i_ocb_type,
    const uint32_t i_ocb_bar,
    const uint8_t i_ocb_q_len,
    const p9ocb::PM_OCB_CHAN_OUFLOW i_ocb_flow,
    const p9ocb::PM_OCB_ITPTYPE i_ocb_itp)
{
    FAPI_IMP("p9_pm_ocb_indir_setup_circular Enter");
    FAPI_DBG("Channel: %d; Mode: %d; OCB BAR: 0x%08X; Queue length: %d;",
             i_ocb_chan, i_ocb_type, i_ocb_bar, i_ocb_q_len);
    FAPI_DBG("Flow Notification Mode: %d; Interrupt Behaviour: %d", i_ocb_flow,
             i_ocb_itp);

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    FAPI_EXEC_HWP(l_rc,
                  p9_pm_ocb_init,
                  i_target,
                  p9pm::PM_SETUP_ALL,
                  i_ocb_chan,
                  i_ocb_type,
                  i_ocb_bar,
                  i_ocb_q_len,
                  i_ocb_flow,
                  i_ocb_itp);

    if (l_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        FAPI_INF("Circular setup of channel %d successful.", i_ocb_chan);
    }
    else
    {
        FAPI_ERR("ERROR: Failed to setup channel %d to circular mode.",
                 i_ocb_chan);
    }

    FAPI_IMP("p9_pm_ocb_indir_setup_circular Exit");
    return l_rc;
}
