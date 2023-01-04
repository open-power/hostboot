/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/index.H $                 */
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
/// @file index.H
/// @brief Tools to return attribute array index from a fapi2 target
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP:SBE
// EKB-Mirror-To: hw/ppe

#ifndef _MSS_INDEX_H_
#define _MSS_INDEX_H_

#include <fapi2.H>

#ifdef __PPE__
    #include "plat_target.H"
    #include "plat_utils.H"
    #include <mss_generic_consts.H>
#else
    #include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#endif

namespace mss
{

///
/// @brief Return an attribute array index from a fapi2 target
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target a fapi2 target
/// @return size_t the attribute array index.
///
template< fapi2::TargetType T >
inline size_t index(const fapi2::Target<T>& i_target)
{
    uint8_t l_pos = 0;

#ifdef __PPE__
    STATIC_CHECK(T == fapi2::TARGET_TYPE_GENERICI2CSLAVE,
                 "index() called for Invalid target type");
    l_pos = i_target.get().getTargetInstance();
#else
    // Unrolled c_str to avoid a circular include
    char l_c_str_storage[fapi2::MAX_ECMD_STRING_LEN] = {};
    fapi2::toString( i_target, l_c_str_storage, fapi2::MAX_ECMD_STRING_LEN );

    // Don't use FAPI_TRY as you'll mess up fapi2::current_err which
    // lmits where this can be used.
    if (FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_target, l_pos) != fapi2::FAPI2_RC_SUCCESS)
    {
        goto fapi_try_exit;
    }

#endif // __PPE

    return l_pos;

fapi_try_exit:

#ifndef __PPE__
    // If we can't get our relative position, we're in other trouble
    FAPI_ERR("can't get ATTR_REL_POS for %s", l_c_str_storage);
#endif

    fapi2::Assert(false);
    return 0;
}

///
/// @brief Return a dimm rank / attribute array index from a port rank number
/// @param[in] i_rank uint64_t a rank number DIMM0 {0, 1, 2, 3} DIMM1 {0, 1, 2, 3}
/// @return size_t the attribute array index.
///
inline size_t index(const uint64_t i_rank)
{
    constexpr size_t RANK_MID_POINT = 4;
    return i_rank % RANK_MID_POINT;
}

}
#endif
