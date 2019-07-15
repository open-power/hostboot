/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_qme_customize.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

//  @file p10_qme_customize.C
//
//  @brief Customizes QME ring section  for consumption by p10_hcode_image_build
//
//  *HWP Owner:         Mike Olsen <cmolsen@us.ibm.com>
//  *HWP Backup Owner:  Prem S Jha <premjha2@in.ibm.com>
//  *HWP Team:          Infrastructure
//  *HWP Level:         2
//  *HWP Consumed by:   HOSTBOOT, CRONUS
#ifndef _P10_QME_CUSTOMIZE_H_
#define _P10_QME_CUSTOMIZE_H_

#include <fapi2.H>

/**
 * @brief   various ring customization operation supported by HWP
 */
enum CUSTOM_RING_OP
{
    CUSTOMIZE_QME0_SPECIFIC_RING = 0x00,
    CUSTOMIZE_QME1_SPECIFIC_RING = 0x01,
    CUSTOMIZE_QME2_SPECIFIC_RING = 0x02,
    CUSTOMIZE_QME3_SPECIFIC_RING = 0x03,
    CUSTOMIZE_QME4_SPECIFIC_RING = 0x04,
    CUSTOMIZE_QME5_SPECIFIC_RING = 0x05,
    CUSTOMIZE_QME6_SPECIFIC_RING = 0x06,
    CUSTOMIZE_QME7_SPECIFIC_RING = 0x07,
    CUSTOMIZE_QME_COMMON_RING = 0x08,
    NUM_CUSTOMIZE_QME_ENTRIES
};

typedef fapi2::ReturnCode (*p10_qme_customize_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    uint8_t* i_bufQmeRings,
    CUSTOM_RING_OP i_custOp,
    uint8_t* io_bufCustRings,
    uint32_t& io_bufCustRingsSize,
    uint32_t i_dbgl);

extern "C"
{

/// @brief          customizes QME ring section based on input.
/// @param[in]      i_procTarget reference to processor chip target.
/// @param[in/out]  i_bufQmeRings pointer to a buffer containing all
///                     scan rings associated with QME image.
/// @param[in]      i_custOp type of customization requested.
/// @param[in/out]  io_bufCustRings pointer to a buffer containing
///                     customized QME rings.
/// @param[in/out]  io_bufCustRingsSize reference.
///                     Input - max buffer size, must be greater than or
///                         equal to the size in the TOR header of QME
///                         ring section in the i_bufQmeRing buffer.
///                     output- the actual buffer size of customized QME
///                         rings.
/// @param[in]      i_dbgl  debug level, default value is 0.
/// @return         FAPI_RC_SUCCESS if the customization was successful,
///                     error code otherwise.

    fapi2::ReturnCode p10_qme_customize(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
        uint8_t* i_bufQmeRings,
        CUSTOM_RING_OP i_custOp,
        uint8_t* io_bufCustRings,
        uint32_t& io_bufCustRingsSize,
        uint32_t i_dbgl = 0);

} //extern "C"

#endif // _P10_QME_CUSTOMIZE_H_
