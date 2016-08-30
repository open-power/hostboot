/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_pib2pcb_mux_seq.H $ */
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
//------------------------------------------------------------------------------
/// @file  p9_pib2pcb_mux_seq.H
///
/// @brief Pib2pcb mux sequence
//------------------------------------------------------------------------------
// *HWP HW Owner        : Anusha Reddy Rangareddygari <anusrang@in.ibm.com>
// *HWP HW Backup Owner :  <>
// *HWP FW Owner        :  <>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SE:HB
//------------------------------------------------------------------------------


#ifndef _P9_PIB2PCB_MUX_SEQ_H_
#define _P9_PIB2PCB_MUX_SEQ_H_

#include <return_code.H>
#include <error_info_defs.H>

typedef fapi2::ReturnCode (*p9_pib2pcb_mux_seq_FP_t)(const fapi2::ffdc_t&, fapi2::ReturnCode&);

/// @brief switching tp pib2pcb mux
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode p9_pib2pcb_mux_seq(const fapi2::ffdc_t& i_chip,
                                         fapi2::ReturnCode&);
}

#endif
