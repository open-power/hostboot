/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/ffdc/exp_collect_explorer_saved_B_log.H $ */
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
/// @file  exp_collect_explorer_saved_B_log.H
///
/// @brief Collects and adds Explorer SAVED side B log to rc
// ----------------------------------------
// *HWP HWP Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB
// ----------------------------------------
#ifndef _COLLECT_EXPLORER_SAVED_B_LOG_H_
#define _COLLECT_EXPLORER_SAVED_B_LOG_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <return_code.H>
#include <error_info_defs.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*exp_collect_explorer_saved_B_log_FP_t)(
    const fapi2::ffdc_t&,
    const fapi2::ffdc_t&,
    fapi2::ReturnCode& );

extern "C"
{
///
/// @brief  Procedure to grab saved (SPI flash) log traces from Explorer chip
///         image B and add those traces to the HWP error
///  @param[in]  i_ocmb_chip - OCMB chip target
///  @param[in]  i_size - allowable total size (add entries upto this size)
///  @param[out] o_rc - return code to add FFDC data to.
///
/// @return FAPI2_RC_SUCCESS iff ok
///
/// NOTE: All input parameters must be of type fapi2::ffdc_t and converted
///       to the correct type inside the function.
///
    fapi2::ReturnCode exp_collect_explorer_saved_B_log(
        const fapi2::ffdc_t& i_ocmb_chip,
        const fapi2::ffdc_t& i_size,
        fapi2::ReturnCode& o_rc );

} // extern "C"

#endif
