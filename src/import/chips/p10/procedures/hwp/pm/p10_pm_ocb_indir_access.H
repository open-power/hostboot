/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_ocb_indir_access.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
/// @file  p10_pm_ocb_indir_access.H
/// @brief Access procedure to the OCC OCB indirect channels
///

// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : SBE:HS

#ifndef _PM_OCB_INDIR_ACCESS_H_
#define _PM_OCB_INDIR_ACCESS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p10_pm.H>
#include <p10_pm_ocb_init.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
namespace ocb
{
enum PM_OCB_ACCESS_OP
{
    OCB_GET     = 0,
    OCB_PUT     = 1,
    OCB_MAX_OPS = 2
};
}

#define PM_OCB_ACCESS_OP_STR { \
        "GET",     \
        "PUT",     \
    }


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_ocb_indir_access_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const ocb::PM_OCB_CHAN_NUM,
 const ocb::PM_OCB_ACCESS_OP,
 const uint32_t,
 const bool,
 const uint32_t,
 uint32_t&,
 uint64_t*);

typedef fapi2::ReturnCode (*p10_pm_ocb_indir_access_bytes_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const ocb::PM_OCB_CHAN_NUM,
 const ocb::PM_OCB_ACCESS_OP,
 const uint32_t,
 const bool,
 const uint32_t,
 uint32_t&,
 uint8_t*);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

extern "C"
{

/// @brief Provides for the abstract access to an OCB indirect channel that has
/// been configured previously via p10_pm_ocb_indir_setup_[linear/circular]
/// procedures
///
/// @param[in]     &i_target           Chip target
/// @param[in]     i_ocb_chan          OCB channel number (0, 1, 2, 3)
/// @param[in]     i_ocb_op            Operation (Get, Put)
/// @param[in]     i_ocb_req_length    Requested length in the number of 8B
///                                    elements to be accessed (unit origin)
///                                    Number of bytes = (i_ocb_req_length) *
///                                    8B
/// @param[in]     i_oci_address_valid Indicator that oci_address is to be used
/// @param[in]     i_oci_address       OCI Address to be used for the operation
/// @param[out]    &o_ocb_act_length   Address containing the actual length
///                                    in the number of 8B elements to be
///                                    accessed (zero origin)
///                                    Number of bytes = (o_ocb_act_length+1) *
///                                    8B
/// @param[in/out] io_ocb_buffer       Pointer to a container of type uint64_t
///                                    to store the data to be written into or
///                                    obtained from OCC SRAM
///
/// @return FAPI2_RC_SUCCESS on success, else error.

    fapi2::ReturnCode p10_pm_ocb_indir_access(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
        const ocb::PM_OCB_ACCESS_OP   i_ocb_op,
        const uint32_t                i_ocb_req_length,
        const bool                    i_oci_address_valid,
        const uint32_t                i_oci_address,
        uint32_t&                     o_ocb_act_length,
        uint64_t*                     io_ocb_buffer);


/// @brief Same as above but use byte unit for data
///
/// @param[in]     &i_target           Chip target
/// @param[in]     i_ocb_chan          OCB channel number (0, 1, 2, 3)
/// @param[in]     i_ocb_op            Operation (Get, Put)
/// @param[in]     i_ocb_req_length    Requested length in the number bytes.
///                                    elements to be accessed (unit origin)
/// @param[in]     i_oci_address_valid Indicator that oci_address is to be used
/// @param[in]     i_oci_address       OCI Address to be used for the operation
/// @param[out]    &o_ocb_act_length   Address containing the actual length
///                                    in the number byte elements to be
///                                    accessed (zero origin)
/// @param[in/out] io_ocb_buffer       Pointer to a container of type uint8_t
///                                    to store the data to be written into or
///                                    obtained from OCC SRAM
///
/// @return FAPI2_RC_SUCCESS on success, else error.

    fapi2::ReturnCode p10_pm_ocb_indir_access_bytes(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const ocb::PM_OCB_CHAN_NUM    i_ocb_chan,
        const ocb::PM_OCB_ACCESS_OP   i_ocb_op,
        const uint32_t                i_ocb_req_length,
        const bool                    i_oci_address_valid,
        const uint32_t                i_oci_address,
        uint32_t&                     o_ocb_act_length,
        uint8_t*                      io_ocb_buffer);


} // extern "C"

#endif // _PM_OCB_INDIR_ACCESS_H_
