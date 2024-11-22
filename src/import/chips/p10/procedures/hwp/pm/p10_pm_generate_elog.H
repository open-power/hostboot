/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_generate_elog.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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
/// @file p10_pm_generate_elog.H
/// @brief This hardware procedure facilitates extraction and commitment of elog in HB context:
///
/// *HWP HW Owner    : Prem S Jha (premjha2@in.ibm.com)
/// *HWP FW Owner    : Greg Still(stillgs@us.ibm.com)
/// *HWP Team        : PM
/// *HWP Consumed by : HB
/// *HWP Level       : 3
///
//  EKB-Mirror-To: hostboot

#ifndef _P10_PM_GEN_ELOG_
#define _P10_PM_GEN_ELOG_

#include <p10_pm_elog.H>

extern "C" {

/// @brief extracts PM elog from PM complex and copies it to a buffer.
/// @param[in]  i_procChip      fapi2 target for P10 chip
/// @param[in]  i_coreId        relative unit position of failing core
/// @param[out] o_logData       data struct capturing elog details
/// @param[out] o_pBuf          raw buffer to which hcode elog gets copied
/// @param[io]  io_bufLength    [in] full length of buffer, [out] actual length used
/// @return     FAPI2_RC_SUCCESS if function succeeds, error code otherwise.
    fapi2::ReturnCode p10_pm_generate_elog( fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_procChip,
                                            uint32_t i_coreId, ElogDissectionSum& o_logData, uint8_t* o_pBuf, uint32_t& io_bufLength );

} //extern "C"
#endif  //_P10_PM_GEN_ELOG_
