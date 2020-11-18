/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_reader.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file spd_reader.H
/// @brief SPD generic API to read SPD byte fields
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_READER_H_
#define _MSS_SPD_READER_H_

#include <fapi2.H>
#include <cstdint>
#include <generic/memory/lib/spd/spd_traits_ddr4.H>

namespace mss
{
namespace spd
{

///
/// @brief SPD reader
/// @tparam F the SPD field to read
/// @tparam R the SPD revision
/// @tparam IT data input type
/// @tparam OT data output type
/// @tparam TT traits associated with reader, defaulted to readerTraits<F, T>
/// @param[in] i_target the dimm target
/// @param[in] i_spd_data the SPD data
/// @param[out] o_value raw value for this SPD field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t<endian::LITTLE>& F,
          rev R,
          typename IT,
          typename OT,
          typename TT = readerTraits<F, R> >
inline fapi2::ReturnCode reader( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const std::vector<IT>& i_spd_data,
                                 OT& o_value)
{

    FAPI_TRY( (mss::get_field<endian::LITTLE, F, TT>(i_target, i_spd_data, mss::READ_SPD_FIELD, o_value)),
              "Failed read_field() for %s", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

}// spd
}// mss

#endif // _MSS_SPD_READER_H_
