/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_reader.H $              */
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
/// @file spd_reader.H
/// @brief SPD generic API to read SPD byte fields
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_READER_H_
#define _MSS_SPD_READER_H_

#include <fapi2.H>
#include <cstdint>
#include <generic/memory/lib/spd/spd_field.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/spd/spd_traits_ddr4.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace spd
{

///
/// @brief Helper function to find bit length of an integral type
/// @tparam T integral type
/// @return bit length for given integral type
///
template < typename T >
constexpr size_t get_bit_length()
{
    return sizeof(T) * BITS_PER_BYTE;
}

///
/// @brief Helper function to find bit length of an input param
/// @tparam T input type
/// @param[in] i_input argument we want to get bit length of
/// @return bit length for given input
///
template < typename T >
constexpr size_t get_bit_length(const T& i_input)
{
    return sizeof(T) * BITS_PER_BYTE;
}

///
/// @brief Variadic helper function to find bit length of integral types
/// @tparam T input type
/// @tparam Types input type for a list in input params
/// @param[in] i_first first argument we want to get bit length of
/// @param[in] i_args list of arguments we want to get the total bit length of
/// @return total bit length for given input
//
template < typename T, typename... Types >
constexpr size_t get_bit_length (const T& i_first, const Types& ... i_args)
{
    // Recursive-ish pattern to add up bit length of passed in params
    return get_bit_length(i_first) + get_bit_length(i_args...);
}

///
/// @tparam T input type
/// @tparam T
/// @param[in] i_data data to insert
/// @param[in,out] io_out buffer we wish to insert values to
///
template <size_t INPUT_BIT_LEN, typename T, typename OT>
static void set_buffer_helper(const T i_data, fapi2::buffer<OT>& io_out)
{
    constexpr size_t l_output_bit_length = get_bit_length<OT>();

    constexpr size_t l_start_bit = l_output_bit_length - INPUT_BIT_LEN;
    constexpr size_t l_len = get_bit_length<T>();

    FAPI_DBG("Total input bit length %d, output bit length %d, insert start bit %d, insert length %d, data %d",
             INPUT_BIT_LEN, l_output_bit_length, l_start_bit, l_len, i_data);

    io_out.template insertFromRight<l_start_bit, l_len >(i_data);
}

///
/// @brief Helper function to insert entire values of any integral value into a buffer
/// @tparam T input type
/// @tparam OT output type of fapi2::buffer
/// @param[in,out] io_out buffer we wish to insert values to
/// @param[in] i_input argument we want to get bit length of
///
template <typename T, typename OT>
void rightAlignedInsert(fapi2::buffer<OT>& io_out, const T& i_input)
{
    constexpr size_t l_input_total_args_bit_length = get_bit_length(i_input);
    set_buffer_helper<l_input_total_args_bit_length>(i_input, io_out);
}

///
/// @tparam T input type
/// @tparam Types input type for a list in input params
/// @param[in,out] io_out buffer we wish to insert values to
/// @param[in] i_first first argument we want to get bit length of
/// @param[in] i_args list of arguments we want to get the total bit length of
///
template <typename T, typename OT, typename... Types>
void rightAlignedInsert(fapi2::buffer<OT>& io_out, const T& first, const Types& ... args)
{
    constexpr size_t l_input_total_args_bit_length = get_bit_length(first, args...);
    set_buffer_helper<l_input_total_args_bit_length>(first, io_out);

    rightAlignedInsert(io_out, args...);
}

///
/// @brief Helper function to extract byte information
/// @tparam F the SPD field to extract
/// @param[in] i_target the dimm target
/// @param[in] i_spd_data the SPD data
/// @param[out] o_value raw value for this SPD field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t& F >
fapi2::ReturnCode extract_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const std::vector<uint8_t>& i_spd_data,
                                uint8_t& o_value)
{
    FAPI_ASSERT( F.get_byte() < i_spd_data.size(),
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(F.get_byte())
                 .set_LIST_SIZE(i_spd_data.size())
                 .set_FUNCTION(EXTRACT_SPD_FLD)
                 .set_TARGET(i_target),
                 "Out of bounds indexing (with %d) on a list of size %d for %s",
                 F.get_byte(),
                 i_spd_data.size(),
                 spd::c_str(i_target));

    {
        // Extracting desired bits
        const fapi2::buffer<uint8_t> l_buffer(i_spd_data[F.get_byte()]);
        l_buffer.extractToRight<F.get_start(), F.get_length()>(o_value);

        FAPI_INF("%s SPD data at Byte %d: 0x%02x.",
                 spd::c_str(i_target),
                 F.get_byte(),
                 o_value);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief SPD reader
/// @tparam F the SPD field to read
/// @tparam R the SPD revision
/// @tparam T data input type
/// @tparam OT data output type
/// @tparam TT traits associated with reader, defaulted to readerTraits<F, T>
/// @param[in] i_target the dimm target
/// @param[in] i_spd_data the SPD data
/// @param[out] o_value raw value for this SPD field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t& F, rev R, typename T, typename OT, typename TT = readerTraits<F, R> >
fapi2::ReturnCode reader( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::vector<T>& i_spd_data,
                          OT& o_value)
{
    T l_temp = 0;
    FAPI_TRY( extract_field<F>(i_target, i_spd_data, l_temp),
              "Failed extract_field() for %s", spd::c_str(i_target) );

    FAPI_DBG("extracted %s value: 0x%02x for %s",
             TT::FIELD_STR, l_temp, spd::c_str(i_target));

    // Test if retrieved data seems valid
    FAPI_TRY( check::fail_for_invalid_value(i_target,
                                            conditional( l_temp,
                                                    TT::COMPARISON_VAL,
                                                    typename TT::template COMPARISON_OP<T>() ),
                                            F.get_byte(),
                                            l_temp),
              "Failed fail_for_invalid_value() for %s", spd::c_str(i_target) );

    // Output should only change if data check passes
    o_value = static_cast<OT>(l_temp);

    FAPI_ASSERT( o_value == l_temp,
                 fapi2::MSS_CONVERSION_ERROR()
                 .set_ORIGINAL_VAL(l_temp)
                 .set_CONVERTED_VAL(o_value)
                 .set_TARGET(i_target)
                 .set_FUNCTION(SPD_READER),
                 "Conversion error between original %d to converted %d value for %s",
                 l_temp, o_value, spd::c_str(i_target) );

    FAPI_INF("%s: 0x%02x for %s",
             TT::FIELD_STR,
             o_value,
             spd::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

}// spd
}// mss

#endif // _MSS_SPD_READER_H_
