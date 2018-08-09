/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_field.H $             */
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
/// @file mss_field.H
/// @brief API for data fields and operations
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_FIELD_H_
#define _MSS_FIELD_H_

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

namespace mss
{

///
/// @class field_t
/// @brief data structure for byte fields
/// @note holds byte index, start bit, and bit length of a decoded field
///
class field_t
{
    private:

        const size_t iv_byte;
        const size_t iv_start;
        const size_t iv_length;

    public:

        // default ctor deleted
        field_t() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_byte_index
        /// @param[in] i_start_bit
        /// @param[in] i_bit_length
        ///
        constexpr field_t(const size_t i_byte_index,
                          const size_t i_start_bit,
                          const size_t i_bit_length)
            : iv_byte(i_byte_index),
              iv_start(i_start_bit),
              iv_length(i_bit_length)
        {}

        ///
        /// @brief default dtor
        ///
        ~field_t() = default;

        ///
        /// @brief Byte index getter
        /// @return the byte index for this field
        ///
        constexpr size_t get_byte() const
        {
            return iv_byte;
        }

        ///
        /// @brief Starting bit getter
        /// @return the starting bit position for this field
        ///
        constexpr size_t get_start() const
        {
            return iv_start;
        }

        ///
        /// @brief bit length getter
        /// @return the bit length of this field
        ///
        constexpr size_t get_length() const
        {
            return iv_length;
        }

};// field_t

///
/// @brief Checks input field against a custom conditional
/// @tparam T field input type
/// @tparam F Callable object type
/// @param[in] i_field Extracted field
/// @param[in] i_comparison_val value we are comparing against
/// @param[in] i_op comparison operator function object
/// @return boolean true or false
///
template < typename T, typename F >
bool conditional(const T i_field,
                 const size_t i_comparison_val,
                 const F i_op)
{
    return i_op(i_field, i_comparison_val);
}

///
/// @brief Helper function to extract byte information
/// @tparam F the field to extract
/// @tparam T the fapi2 target type
/// @tparam IT data input type
/// @tparam OT data output type
/// @tparam FFDC ffdc code type
/// @param[in] i_target the fapi2 target
/// @param[in] i_data the data
/// @param[in] i_ffdc_codes FFDC code
/// @param[out] o_value raw value for this field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t& F,
          fapi2::TargetType T,
          typename IT,
          typename OT,
          typename FFDC >
fapi2::ReturnCode get_field(const fapi2::Target<T>& i_target,
                            const std::vector<IT>& i_data,
                            const FFDC i_ffdc_codes,
                            OT& o_value)
{
    constexpr size_t BYTE = F.get_byte();

    FAPI_ASSERT( BYTE < i_data.size(),
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(BYTE)
                 .set_LIST_SIZE(i_data.size())
                 .set_FUNCTION(i_ffdc_codes)
                 .set_TARGET(i_target),
                 "Out of bounds indexing (with %d) on a list of size %d for %s",
                 BYTE,
                 i_data.size(),
                 spd::c_str(i_target));

    {
        // Extracting desired bits
        const fapi2::buffer<OT> l_buffer(i_data[BYTE]);
        l_buffer.template extractToRight<F.get_start(), F.get_length()>(o_value);

        FAPI_DBG("%s data[%d] = 0x%02x. Field with start bit %d, bit len %d, has data 0x%02x.",
                 spd::c_str(i_target),
                 BYTE,
                 i_data[BYTE],
                 F.get_start(),
                 F.get_length(),
                 o_value);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to set byte field information
/// @tparam F the field to extract
/// @tparam T the fapi2 target type
/// @tparam IT data input type
/// @tparam OT data output type
/// @tparam FFDC ffdc code type
/// @param[in] i_target the fapi2 target
/// @param[in] i_setting the setting to set
/// @param[in] i_ffdc_codes FFDC code
/// @param[in,out] io_data the data to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t& F,
          fapi2::TargetType T,
          typename IT,
          typename OT,
          typename FFDC >
fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                            const IT i_setting,
                            const FFDC i_ffdc_codes,
                            std::vector<OT>& io_data)
{
    constexpr size_t BYTE = F.get_byte();

    FAPI_ASSERT( BYTE < io_data.size(),
                 fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                 .set_INDEX(BYTE)
                 .set_LIST_SIZE(io_data.size())
                 .set_FUNCTION(i_ffdc_codes)
                 .set_TARGET(i_target),
                 "Out of bounds indexing (with %d) on a list of size %d for %s",
                 BYTE,
                 io_data.size(),
                 spd::c_str(i_target));

    {
        // Insert desired setting
        fapi2::buffer<OT> l_buffer(io_data[BYTE]);
        l_buffer.template insertFromRight<F.get_start(), F.get_length()>(i_setting);

        io_data[BYTE] = static_cast<OT>(l_buffer);

        FAPI_DBG("%s data[%d] = 0x%02x. Field with start bit %d, bit len %d, has data 0x%02x.",
                 spd::c_str(i_target),
                 BYTE,
                 io_data[BYTE],
                 F.get_start(),
                 F.get_length(),
                 i_setting);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief byte field reader
/// @tparam F the byte field to read
/// @tparam TT traits associated with F - required
/// @tparam T the fapi2 target type
/// @tparam IT data input type
/// @tparam OT data output type
/// @param[in] i_target the dimm target
/// @param[in] i_data the data
/// @param[in] i_ffdc_codes FFDC code
/// @param[out] o_value raw value for this field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t& F,
          typename TT,
          fapi2::TargetType T,
          typename IT,
          typename OT,
          typename FFDC >
inline fapi2::ReturnCode get_field( const fapi2::Target<T>& i_target,
                                    const std::vector<IT>& i_data,
                                    const FFDC i_ffdc_codes,
                                    OT& o_value )
{
    IT l_temp = 0;
    FAPI_TRY( get_field<F>(i_target, i_data, i_ffdc_codes, l_temp),
              "Failed get_field() for %s", spd::c_str(i_target) );

    // Test if retrieved data seems valid
    FAPI_TRY( check::invalid_value(i_target,
                                   conditional( l_temp,
                                           TT::COMPARISON_VAL,
                                           typename TT::template COMPARISON_OP<IT>() ),
                                   F.get_byte(),
                                   l_temp,
                                   i_ffdc_codes),
              "Failed fail_for_invalid_value() for %s", spd::c_str(i_target) );

    // Output should only change if data check passes
    o_value = static_cast<OT>(l_temp);

    FAPI_ASSERT( o_value == l_temp,
                 fapi2::MSS_CONVERSION_ERROR()
                 .set_ORIGINAL_VAL(l_temp)
                 .set_CONVERTED_VAL(o_value)
                 .set_TARGET(i_target)
                 .set_FUNCTION(i_ffdc_codes),
                 "Conversion error between original %d to converted %d value for %s",
                 l_temp, o_value, spd::c_str(i_target) );

    FAPI_INF("%s: 0x%02x for %s",
             TT::FIELD_STR,
             o_value,
             spd::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief byte field writer
/// @tparam F the byte field to read
/// @tparam TT traits associated with writer
/// @tparam T the fapi2 target type
/// @tparam IT data input type
/// @tparam OT data output type
/// @tparam FFDC ffdc code type
/// @param[in] i_target the dimm target
/// @param[in] i_setting value to set for field
/// @param[in] i_ffdc_codes FFDC code
/// @param[in,out] io_data the data to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< const field_t& F,
          typename TT,
          fapi2::TargetType T,
          typename IT,
          typename OT,
          typename FFDC >
fapi2::ReturnCode set_field( const fapi2::Target<T>& i_target,
                             const IT i_setting,
                             const FFDC i_ffdc_codes,
                             std::vector<OT>& io_data )
{
    constexpr size_t BYTE = F.get_byte();

    // Test if the data we want to set is valid for this field
    FAPI_TRY( check::invalid_value(i_target,
                                   conditional( i_setting,
                                           TT::COMPARISON_VAL,
                                           typename TT::template COMPARISON_OP<IT>() ),
                                   BYTE,
                                   i_setting,
                                   i_ffdc_codes),
              "Failed fail_for_invalid_value() for %s", spd::c_str(i_target) );

    FAPI_TRY( set_field<F>(i_target, i_setting, i_ffdc_codes, io_data),
              "Failed set_field() for %s", spd::c_str(i_target) );

    FAPI_INF("%s: Set value of 0x%02x. Data for buffer at byte %d, is now 0x%02x for %s",
             TT::FIELD_STR,
             i_setting,
             BYTE,
             io_data[BYTE],
             spd::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

}// mss

#endif
