/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/customize/p10_qme_customize.H $ */
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
enum CUST_RING_OP
{
    CUST_QME0_INSTANCE_RING = 0x00,
    CUST_QME1_INSTANCE_RING = 0x01,
    CUST_QME2_INSTANCE_RING = 0x02,
    CUST_QME3_INSTANCE_RING = 0x03,
    CUST_QME4_INSTANCE_RING = 0x04,
    CUST_QME5_INSTANCE_RING = 0x05,
    CUST_QME6_INSTANCE_RING = 0x06,
    CUST_QME7_INSTANCE_RING = 0x07,
    CUST_QME_COMMON_RING = 0x08,
    NUM_QME_CUST_OPS
};

typedef fapi2::ReturnCode (*p10_qme_customize_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
    uint8_t*      i_qmeRings,
    CUST_RING_OP  i_custOp,
    uint8_t*      io_bufCustRings,
    uint32_t&     io_bufCustRingsSize,
    uint32_t      i_dbgl);

extern "C"
{

/// @brief          customizes QME ring section based on input.
/// @param[in]      i_procTarget reference to processor chip target.
/// @param[in/out]  i_qmeRings  Pointer to the input QME ring section
/// @param[in]      i_custOp  Type of customization requested.
/// @param[in/out]  io_bufCustRings  Pointer to a buffer containing the customized QME rings.
/// @param[in/out]  io_bufCustRingsSize  Size of customized QME ring section
///                     Input - max buffer size, must be >= to the size in the TOR header of
///                             the input QME ring section in i_qmeRings
///                     Output- the actual size of the customized QME ring section
/// @param[in]      i_dbgl  Debug level, default value is 0
/// @return         FAPI_RC_SUCCESS if the customization was successful, otherwise error code

    fapi2::ReturnCode p10_qme_customize(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget,
        uint8_t*      i_bufQmeRings,
        CUST_RING_OP  i_custOp,
        uint8_t*      io_bufCustRings,
        uint32_t&     io_bufCustRingsSize,
        uint32_t      i_dbgl = 0);

} //extern "C"

#endif // _P10_QME_CUSTOMIZE_H_
