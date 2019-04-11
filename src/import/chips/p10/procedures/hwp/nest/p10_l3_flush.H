/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_l3_flush.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
///-----------------------------------------------------------------------------
///
/// @file p10_l3_flush.H
/// @brief Initiates an L3 purge request
///
/// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by: FSP, SBE
/// ----------------------------------------------------------------------------

#ifndef P10_L3_FLUSH_
#define P10_L3_FLUSH_

//-------------------------------------------------------
// Includes
//-------------------------------------------------------
#include <fapi2.H>
#include <p10_scom_c.H>
//--------------------------------------------------------------------------
// Constant definitions
//--------------------------------------------------------------------------
// L3 Purge ttype dials
enum l3_purge_type
{
    L3_FULL_PURGE = 0,
    L3_SINGLE_PURGE = 1,
    L3_SINGLE_DELETE = 2,
    L3_FULL_BLIND_PURGE = 4,
    L3_DYNAMIC_PURGE = 5
};

//--------------------------------------------------------
// Function prototypes
//--------------------------------------------------------
//Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_l3_flush_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
 const uint32_t,
 const uint32_t);

extern "C"
{

/// @brief Initiates an L3 purge request and spins until completion
///
/// @param[in] i_target       => CORE chiplet target
/// @param[in] i_purge_type   => type of purge to execute
/// @param[in] i_purge_addr   => directory address to begin the purge
///
/// @return FAPI_RC_SUCCESS if the purge operation completes successfully
///
    fapi2::ReturnCode p10_l3_flush(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const uint32_t i_purge_type,
        const uint32_t i_purge_addr);

}//extern "C"

#endif //P10_L3_FLUSH_
