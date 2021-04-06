/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/ffdc/exp_collect_explorer_saved_A_log.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file  exp_collect_explorer_saved_A_log.C
///
/// @brief Collects and adds Explorer SAVED log from image A side to rc
//------------------------------------------------------------------------------
// *HWP HW Owner        : Matt Derksen
// *HWP HW Backup Owner :  <>
// *HWP FW Owner        :  <>
// *HWP Level           : 2
// *HWP Consumed by     : SE:HB
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <exp_collect_explorer_log.H>
#include <exp_collect_explorer_saved_A_log.H>

/// See header
fapi2::ReturnCode exp_collect_explorer_saved_A_log(
    const fapi2::ffdc_t& i_ocmb_chip,
    const fapi2::ffdc_t& i_size,
    fapi2::ReturnCode& o_rc )
{
    return exp_collect_explorer_logs(i_ocmb_chip, i_size, SAVED_LOG_A, o_rc);
}
