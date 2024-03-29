/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_ocb_indir_setup_circular.H $ */
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
/// @file  p10_pm_ocb_indir_setup_circular.H
/// @brief  Configure OCB Channels for Circular Push or Pull Mode

// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : HS

#ifndef _PM_OCB_INDIR_SETUP_CIRCULAR_H_
#define _PM_OCB_INDIR_SETUP_CIRCULAR_H_

#include <fapi2.H>
#include <p10_pm_ocb_init.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_ocb_indir_setup_circular_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const ocb::PM_OCB_CHAN_NUM,
 const ocb::PM_OCB_CHAN_TYPE,
 const uint32_t,
 const uint8_t,
 const ocb::PM_OCB_CHAN_OUFLOW,
 const ocb::PM_OCB_ITPTYPE);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// @brief Configure OCB Channels for Circular Push or Pull Mode
/// @param[in] i_target    Chip Target
/// @param[in] i_ocb_chan  Select channel 0-3 to set up
/// @param[in] i_ocb_type  Select the type of Channel: Push, Pull
/// @param[in] i_ocb_bar   Base Address of the queue in OCC SRAM
/// @param[in] i_ocb_q_len Length (in doublewords) of the queue
/// @param[in] i_ocb_flow  Over/underflow control
///    OCB_Q_OUFLOW_NULL         Do nothing
///    OCB_Q_OUFLOW_EN           Overflow/Underflow Enable
///    OCB_Q_OUFLOW_DIS          Overflow/Underflow Disable
/// @param[in] i_ocb_itp   Interrupt type
///    OCB_Q_ITPTYPE_NULL        Overflow/Underflow Disable
///    OCB_Q_ITPTYPE_FULL        Interrupt on Full
///    OCB_Q_ITPTYPE_NOTFULL     Interrupt on Not Full
///    OCB_Q_ITPTYPE_EMPTY       Interrupt on Empty
///    OCB_Q_ITPTYPE_NOTEMPTY    Interrupt on Not Empty
/// @return FAPI2_RC_SUCCESS on success, error otherwise

    fapi2::ReturnCode p10_pm_ocb_indir_setup_circular(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const ocb::PM_OCB_CHAN_NUM      i_ocb_chan,
        const ocb::PM_OCB_CHAN_TYPE     i_ocb_type,
        const uint32_t                  i_ocb_bar,
        const uint8_t                   i_ocb_q_len,
        const ocb::PM_OCB_CHAN_OUFLOW   i_ocb_flow,
        const ocb::PM_OCB_ITPTYPE       i_ocb_itp);

} // extern "C"

#endif
