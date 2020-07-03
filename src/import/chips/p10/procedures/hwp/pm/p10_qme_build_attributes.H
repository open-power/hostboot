/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_qme_build_attributes.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file  p10_p10_qme_build_attributes.H
/// @brief Hcode Image Build to extract attribute value and put in qme image
///
/// *HW Owner    : Yue Du <daviddu@us.ibm.com>
/// *FW Owner    : Greg Still <stillgs@us.ibm.com>
/// *Team        : PM
/// *Consumed by : QME
/// *Level       : 3
///

#ifndef __p10_p10_qme_build_attributes_H__
#define __p10_p10_qme_build_attributes_H__

#include <fapi2.H>
#include <p10_qme_meta_data.H>

/// @typedef p10_p10_qme_build_attributes_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_qme_build_attributes_FP_t) (
    const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP >&,
    void*, QmeAttrMeta_t*);

extern "C"
{
/// @brief Read and Decode the MARK information in SPRG0 on a CME
/// @param [in]  i_target TARGET_TYPE_PROC_EX
/// @param [out] o_mark   Value of the MARK field
/// @param [out] o_str    Text decode of the MARK field

/// @return FAPI2_RC_SUCCESS
    fapi2::ReturnCode
    p10_qme_build_attributes(
        const fapi2::Target< fapi2::TARGET_TYPE_PROC_CHIP >& i_core_tgt,
        void* i_pQmeAttrTank, QmeAttrMeta_t* i_pQmeAttrMeta);

} // extern "C"

#endif  // __p10_p10_qme_build_attributes_H__
