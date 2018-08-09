/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_generic_check.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file mss_generic_check.H
/// @brief Checker functions for generic API
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_GENERIC_CHECK_H_
#define _MSS_GENERIC_CHECK_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{
namespace check
{

///
/// @brief Checks conditional passes and implements traces & exits if it fails
/// @tparam T fapi2 target type
/// @tparam IT input data type
/// @tparam FFDC error callout code type
/// @param[in] i_target fapi2 target
/// @param[in] i_conditional conditional that we are testing against
/// @param[in] i_byte_index byte index
/// @param[in] i_data debug data
/// @param[in] i_ffdc_codes FFDC code
/// @param[in] i_err_str error string - defaulted to ""
/// @return FAPI2_RC_SUCCESS iff okay
///
template< fapi2::TargetType T, typename IT , typename FFDC >
inline fapi2::ReturnCode invalid_value(const fapi2::Target<T>& i_target,
                                       const bool i_conditional,
                                       const size_t i_byte_index,
                                       const IT i_data,
                                       const FFDC i_ffdc_codes,
                                       const char* i_err_str = "")
{
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_FAILED_DATA_INTEGRITY_CHECK().
                set_VALUE(i_data).
                set_BYTE(i_byte_index).
                set_TARGET(i_target).
                set_FFDC_CODE(i_ffdc_codes),
                "%s %s Byte %d, Data returned: %d.",
                spd::c_str(i_target),
                i_err_str,
                i_byte_index,
                i_data);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

} // fail_for_invalid_value

} // check
}// mss

#endif
