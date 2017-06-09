/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_eq_clear_atomic_lock.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file  p9_eq_clear_atomic_lock.H
/// @brief FFDC procedure to pick up the atomic lock on cache chiplet
//
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : SBE, HB

#ifndef __P9_EQ_CLEAR_ATOMIC_LOCK_H__
#define __P9_EQ_CLEAR_ATOMIC_LOCK_H__

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <error_info_defs.H>

#ifndef __PPE__
/// @typedef p9_eq_clear_atomic_lock_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_eq_clear_atomic_lock_FP_t) (
    const fapi2::ffdc_t&,
    fapi2::ReturnCode&
);
#endif

/// typedef p9_clear_atomic_lock_FP_t
/// function pointer typdef definition for HWP call support
typedef fapi2::ReturnCode (*p9_clear_atomic_lock_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& );

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
#ifndef __PPE__
/// @brief HWP to pick up the atomic lock on a cache chiplet to allow the
///        collection of CME FFDC register content (SCOM or RAM)
/// @param  [in]    i_eq_target    TARGET_TYPE_EQ
/// @param  [inout] io_rc          Return code - unused
/// @return FAPI2_RC_SUCCESS       Always succeeds
    fapi2::ReturnCode
    p9_eq_clear_atomic_lock ( const fapi2::ffdc_t& i_eq_target,
                              fapi2::ReturnCode& io_rc );
#endif

/// @brief HWP to pick up the atomic lock on a cache chiplet to allow the
///        collection of CME FFDC register content (SCOM or RAM)
/// @param [in] i_eq EQ target on which the atomic lock should be released
/// @return FAPI2_RC_SUCCESS on success, else error code
/// @note Unlike the collectFfdc triggered callback, this is a direct HWP call
///       to support the SBE platform limitations
    fapi2::ReturnCode
    p9_clear_atomic_lock ( const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_eq );
} // extern C

#endif  // __P9_EQ_CLEAR_ATOMIC_LOCK_H__
