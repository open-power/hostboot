/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source:  $                                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
/**
 *  @file collect_reg_ffdc.H
 *
 *  @brief Defines the collectRegFfdc function that collects chip or
 *         chiplet register FFDC data. This is called automatically by
 *         FAPI_SET_HWP_ERROR (when a HWP creates an error) and
 *         FAPI_ADD_INFO_TO_HWP_ERROR (when an FFDC HWP adds error information
 *         to an existing error) if the error XML contains a
 *         <collectRegisterFfdc> element. This function should not be called
 *         directly by any user code. The function implementation is
 *         automatically generated from FAPI Error XML files.
 */

#ifndef FAPI2_COLLECT_REG_FFDC_H_
#define FAPI2_COLLECT_REG_FFDC_H_

#include <target.H>
#include <return_code.H>
#include <ffdc.H>
#include <hwp_error_info.H>

namespace fapi2
{

    ///
    /// @brief Collects Register FFDC from a chip or chiplet
    ///
    /// @warning This should only be called by FAPI during FAPI_SET_HWP_ERROR or
    /// FAPI_ADD_INFO_TO_HWP_ERROR
    ///
    /// @param[in]  i_target      Pointer to Target to collect FFDC from
    /// @param[in]  i_ffdcId      FFDC Identifier
    /// @param[out] o_rc          Reference to ReturnCode that FFDC is added to
    /// @param[in]  i_child       Specifies type of i_target's chiplet to collect
    ///                           FFDC from.  If this parameter is TARGET_TYPE_NONE
    ///                           (default value), then register FFDC is collected
    ///                           from i_target, else, register FFDC is collected
    ///                           from all functional child chiplets i_target of
    ///                           the specified type
    /// @param[in]  i_presChild   When specified, register FFDC will be collected
    ///                           from i_target's registers based on present chiplets
    ///                           of this type.
    /// @param[in]  i_childOffsetMult  Specifies the chiplet position offset multiplier.
    ///                           This is used in calculating the scom register
    ///                           addresses when collecting register FFDC based on
    ///                           present child chiplets.
    ///
    void collectRegFfdc(const fapi2::Target<TARGET_TYPE_ALL>* i_target,
                        const fapi2::HwpFfdcId i_ffdcId,
                        fapi2::ReturnCode & o_rc,
                        const TargetType i_child = TARGET_TYPE_NONE,
                        const TargetType i_presChild = TARGET_TYPE_NONE,
                        uint32_t i_childOffsetMult = 0);
}

#endif
