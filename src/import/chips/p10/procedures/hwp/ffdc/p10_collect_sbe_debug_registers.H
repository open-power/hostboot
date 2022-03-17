/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/ffdc/p10_collect_sbe_debug_registers.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file  p10_extract_sbe_rc.H
///
/// @brief Check for errors on the SBE, OTPROM, PIBMEM & SEEPROM
//------------------------------------------------------------------------------
// *HWP HW Owner        : Sandeep Korrapati <sakorrap@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : Raja Das <rajadas2@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 3
// *HWP Consumed by     : FSP:HB
//------------------------------------------------------------------------------
// EKB-Mirror-To: hostboot
// EKB-Mirror-To: hwsv

#ifndef _P10_COLLECT_SBE_DEB_REG_H_
#define _P10_COLLECT_SBE_DEB_REG_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p10_collect_sbe_debug_registers_FP_t)(
    const fapi2::ffdc_t&, const fapi2::ffdc_t&, fapi2::ReturnCode&);

extern "C"
{
    fapi2::ReturnCode p10_collect_sbe_debug_registers(
        const fapi2::ffdc_t& i_target,
        const fapi2::ffdc_t& i_is_cfam_supported,
        fapi2::ReturnCode& o_rc);
}

#endif
