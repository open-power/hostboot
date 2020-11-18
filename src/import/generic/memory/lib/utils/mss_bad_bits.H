/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_bad_bits.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file mss_bad_bits.C
/// @brief Contains the generic bad bits logic
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_BAD_BITS_H_
#define _MSS_BAD_BITS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>

namespace mss
{

///
/// @brief A generic bad bits getter
/// @tparam MC type memory controller type
/// @param[in] i_target the fapi2 target oon which training was conducted
/// @param[out] o_array the bad bits array
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template <mss::mc_type MC>
fapi2::ReturnCode get_bad_dq_bitmap(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    uint8_t (&o_array)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]);

///
/// @brief A generic bad bits setter
/// @tparam MC type memory controller type
/// @param[in] i_target the fapi2 target oon which training was conducted
/// @param[in] i_array the bad bits to set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
///
template <mss::mc_type MC>
fapi2::ReturnCode set_bad_dq_bitmap(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    uint8_t (&i_array)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT]);

///
/// @brief combine the two bad bits arrays into the io_bad_bits array
/// @param[in] i_new_bad_bits bad bits to append
/// @param[in,out] io_bad_bits will contain the bitwise or of the original io_bad_bits and i_new_bad_bits
///
inline void combine_bad_bits(const uint8_t (&i_new_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT],
                             uint8_t (&io_bad_bits)[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT])
{
    for (uint8_t l_rank = 0; l_rank < BAD_BITS_RANKS; ++ l_rank)
    {
        for (uint8_t l_bad_dq_byte = 0; l_bad_dq_byte < BAD_DQ_BYTE_COUNT; ++l_bad_dq_byte)
        {
            io_bad_bits[l_rank][l_bad_dq_byte] |= i_new_bad_bits[l_rank][l_bad_dq_byte];
        }
    }
}

///
/// @brief Records bad bits into the bad bits attribute
/// @tparam MC MC type on which training was run
/// @tparam T fapi2::TargetType on which training was conducted
/// @tparam I Interface class used to abstract converting bad bits into the attribute
/// @param[in] i_target the fapi2 target oon which training was conducted
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if bad bits can be repaired
/// @note calling GENERIC bad_fir_bits to cover this case in HB -- GENERIC firChecklist not specified (see bad_fir_bits for more details)
///
template <mss::mc_type MC, fapi2::TargetType T, class I >
inline fapi2::ReturnCode record_bad_bits( const fapi2::Target<T>& i_target, const I& i_helper )
{
    // If we have a FIR set that could have caused our training fail, then skip checking bad bits in FW
    // PRD will handle the FIR and retrigger the procedure
#ifdef __HOSTBOOT_MODULE
    bool l_fir_error = false;

    // Note: using success here will cause an RC to not be logged
    // We can still see if we do have a FIR error though
    // NOTE: calling GENERIC bad_fir_bits to cover this case in HB -- GENERIC firChecklist not specified (see bad_fir_bits for more details)
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
    FAPI_TRY((mss::check::bad_fir_bits<MC, mss::check::firChecklist::GENERIC, T>(i_target, l_rc, l_fir_error)),
             "%s took an error while checking FIR's",
             mss::c_str(i_target));

    // Exit if we took a FIR error - PRD will handle bad bits
    if(l_fir_error)
    {
        FAPI_INF("%s has FIR's set, exiting to let PRD handle it", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

#endif

    for( const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        uint8_t l_data[BAD_BITS_RANKS][BAD_DQ_BYTE_COUNT] = {};

        FAPI_TRY( i_helper.record_bad_bits_interface(d, l_data) );

        // Write
        FAPI_TRY(set_bad_dq_bitmap<MC>(d, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
#endif
