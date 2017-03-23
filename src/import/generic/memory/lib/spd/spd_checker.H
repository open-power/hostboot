/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_checker.H $             */
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

#ifndef _SPD_CHECKER_H_
#define _SPD_CHECKER_H_

#include <fapi2.H>

namespace mss
{
namespace check
{
namespace spd
{

///
/// @brief      Checks conditional passes and implements traces & exits if it fails
/// @tparam     T input data of any size
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_conditional conditional that we are testing against
/// @param[in]  i_spd_byte_index current SPD byte
/// @param[in]  i_spd_data debug data
/// @param[in]  i_err_str error string to print out when conditional fails
/// @return     ReturnCode
///
template< typename T >
inline fapi2::ReturnCode fail_for_invalid_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bool i_conditional,
        const size_t i_spd_byte_index,
        const T i_spd_data,
        const char* i_err_str)
{
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_BAD_SPD().
                set_VALUE(i_spd_data).
                set_BYTE(i_spd_byte_index).
                set_DIMM_TARGET(i_target),
                "%s %s Byte %d, Data returned: %d.",
                c_str(i_target),
                i_err_str,
                i_spd_byte_index,
                i_spd_data);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;

} // fail_for_invalid_value()

///
/// @brief      Checks conditional passes and implements traces if it fails. No FFDC collected.
/// @tparam     T input data of any size
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_conditional that we are testing against
/// @param[in]  i_spd_byte_index
/// @param[in]  i_spd_data debug data
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     void
///
template< typename T >
inline void warn_for_invalid_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const bool i_conditional,
                                   const size_t i_spd_byte_index,
                                   const T i_spd_data,
                                   const char* i_err_str)
{
    // Don't print warning conditional if true
    if(!i_conditional)
    {
        FAPI_IMP("%s. %s. Byte %d, Data returned: %d.",
                 c_str(i_target),
                 i_err_str,
                 i_spd_byte_index,
                 i_spd_data );
    }
}// warn_for_invalid_value

///
/// @brief      Checks if valid factory parameters are given
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_dimm_type DIMM type enumeration
/// @param[in]  i_encoding_rev SPD encoding level rev number
/// @param[in]  i_additions_rev SPD additions level rev number
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     fapi2::ReturnCode
///
inline fapi2::ReturnCode invalid_factory_sel(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_dimm_type,
        const uint8_t i_encoding_rev,
        const uint8_t i_additions_rev,
        const char* i_err_str)
{
    FAPI_ASSERT(false,
                fapi2::MSS_INVALID_DIMM_REV_COMBO().
                set_DIMM_TYPE(i_dimm_type).
                set_ENCODING_REV(i_encoding_rev).
                set_ADDITIONS_REV(i_additions_rev).
                set_DIMM_TARGET(i_target),
                "%s. %s. Invalid combination for dimm type: %d, rev: %d.%d",
                c_str(i_target),
                i_err_str,
                i_dimm_type,
                i_encoding_rev,
                i_additions_rev);
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}// invalid_factory_sel

}// spd
}// check
}// mss

#endif
