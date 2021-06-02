/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_lpc_test.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file  p10_lpc_test.C
///
/// @brief procedure to test whether the LPC logic is hung (HW570899)
//------------------------------------------------------------------------------
// *HWP HW Maintainer : Joachim Fenkes (fenkes@de.ibm.com)
// *HWP FW Maintainer : Raja Das    (rajadas2@in.ibm.com)
// *HWP Consumed by   : Hostboot
//------------------------------------------------------------------------------
// EKB-Mirror-To: hostboot
#include "p10_sbe_lpc_init.H"
#include "p10_lpc_test.H"
#include "p10_scom_proc.H"
#include "p10_lpc_utils.H"

fapi2::ReturnCode p10_lpc_test(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    fapi2::buffer<uint32_t> l_data32;
    return lpc_read(i_target_chip, LPCM_OPB_MASTER_STATUS_REG, l_data32, false);
}
