/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_field.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_FIELD_H_
#define _MSS_FIELD_H_

#ifdef __PPE__
    #include <mss_generic_check.H>
#else
    #include <generic/memory/lib/utils/shared/mss_generic_consts.H>
    #include <generic/memory/lib/utils/mss_generic_check.H>
#endif

// reused TARGTID & TARGTIDFORMAT macro defined in generic/memory/lib/utils/mss_generic_check.H

namespace mss
{

///
/// @brief endian fields for use as a template selecor
///
enum class endian
{
    BIG,
    LITTLE,
};

///
/// @class field_t
/// @brief data structure for byte fields
/// @tparam E endian type for this field
/// @note holds byte index, start bit, and bit length of a decoded field
///
template< endian E >
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
        const size_t get_byte(const std::vector<uint8_t>& i_data) const;

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
/// @brief Byte index getter - big endian specialization
/// @return the byte index for this field
///
template<>
inline const size_t field_t<mss::endian::BIG>::get_byte(const std::vector<uint8_t>& i_data) const
{
    return ( i_data.size() - 1 ) - iv_byte;
}

///
/// @brief Byte index getter - big endian specialization
/// @return the byte index for this field
///
template<>
inline const size_t field_t<mss::endian::LITTLE>::get_byte(const std::vector<uint8_t>& i_data) const
{
    return iv_byte;
}

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
inline bool conditional(const T i_field,
                        const size_t i_comparison_val,
                        const F i_op)
{
    return i_op(i_field, i_comparison_val);
}

///
/// @brief Helper function to extract byte information
/// @tparam E endian type
/// @tparam F the field to extract
/// @tparam T the fapi2 target type
/// @tparam OT output type
/// @tparam FFDC ffdc code type
/// @param[in] i_target the fapi2 target
/// @param[in] i_data the data
/// @param[in] i_ffdc_codes FFDC code
/// @param[out] o_value raw value for this field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< mss::endian E,
          const mss::field_t<E>& F,
          fapi2::TargetType T,
          typename OT,
          typename FFDC >
inline fapi2::ReturnCode get_field(const fapi2::Target<T>& i_target,
                                   const std::vector<uint8_t>& i_data,
                                   const FFDC i_ffdc_codes,
                                   OT& o_value)
{
    const size_t BYTE = F.get_byte(i_data);
    FAPI_TRY(check::index_within_bounds(i_target, BYTE, i_data.size(), i_ffdc_codes));

    {
        // clear out stale state
        o_value = 0;

        // Extracting desired bits
        // API enforces uint8_t vector data, so no conversion check needed to uint8_t buffer
        fapi2::buffer<uint8_t>(i_data[BYTE]).extractToRight<F.get_start(), F.get_length()>(o_value);

#ifndef __PPE__
        FAPI_DBG(TARGTIDFORMAT " data[%d] = 0x%02x. Field with start bit %d, bit len %d, has data 0x%02x.",
                 TARGTID,
                 BYTE,
                 i_data[BYTE],
                 F.get_start(),
                 F.get_length(),
                 o_value);
#endif
    }

fapi_try_exit:
    return fapi2::current_err;
}
#ifndef __PPE__

///
/// @brief Helper function to set byte field information
/// @tparam E endian type
/// @tparam F the field to extract
/// @tparam T the fapi2 target type
/// @tparam IT input type
/// @tparam FFDC ffdc code type
/// @param[in] i_target the fapi2 target
/// @param[in] i_setting the setting to set
/// @param[in] i_ffdc_codes FFDC code
/// @param[in,out] io_data the data to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< mss::endian E,
          const mss::field_t<E>& F,
          fapi2::TargetType T,
          typename IT,
          typename FFDC >
inline fapi2::ReturnCode set_field(const fapi2::Target<T>& i_target,
                                   const IT i_setting,
                                   const FFDC i_ffdc_codes,
                                   std::vector<uint8_t>& io_data)
{
    const size_t BYTE = F.get_byte(io_data);

    FAPI_TRY(check::index_within_bounds(i_target, BYTE, io_data.size(), i_ffdc_codes));
    FAPI_TRY(check::invalid_type_conversion<uint8_t>(i_target, i_setting, i_ffdc_codes));

    {
        // Insert desired setting
        fapi2::buffer<uint8_t> l_buffer(io_data[BYTE]);
        l_buffer.template insertFromRight<F.get_start(), F.get_length()>(i_setting);

        // Safe to set since no implicit conversion errors will occur here
        io_data[BYTE] = l_buffer;
    }

    FAPI_DBG("%s data[%d] = 0x%02x. Field with start bit %d, bit len %d, has data 0x%02x.",
             spd::c_str(i_target),
             BYTE,
             io_data[BYTE],
             F.get_start(),
             F.get_length(),
             i_setting);

fapi_try_exit:
    return fapi2::current_err;
}
#endif // PPE
///
/// @brief byte field reader
/// @tparam E endian type
/// @tparam F the byte field to read
/// @tparam TT traits associated with F - required
/// @tparam T the fapi2 target type
/// @param[in] i_target the dimm target
/// @param[in] i_data the data
/// @param[in] i_ffdc_codes FFDC code
/// @param[out] o_value raw value for this field
/// @return FAPI2_RC_SUCCESS iff okay
///
template< mss::endian E,
          const mss::field_t<E>& F,
          typename TT,
          fapi2::TargetType T,
          typename OT,
          typename FFDC >
inline fapi2::ReturnCode get_field( const fapi2::Target<T>& i_target,
                                    const std::vector<uint8_t>& i_data,
                                    const FFDC i_ffdc_codes,
                                    OT& o_value )
{
    uint8_t l_temp = 0;
    FAPI_TRY( (get_field<E, F>(i_target, i_data, i_ffdc_codes, l_temp)),
              "Failed get_field() for " TARGTIDFORMAT, TARGTID );

    // Test if retrieved data seems valid
    FAPI_TRY( check::invalid_value(i_target,
                                   conditional( l_temp,
                                           TT::COMPARISON_VAL,
                                           typename TT::template COMPARISON_OP<uint8_t>() ),
                                   F.get_byte(i_data),
                                   l_temp,
                                   i_ffdc_codes,
                                   TT::FIELD_STR),
              "%s failed check::invalid_value() for %s",
              TT::FIELD_STR, spd::c_str(i_target) );

    // Implicit (possible) promotion during conversion is safe
    o_value = static_cast<OT>(l_temp);

#ifndef __PPE__
    FAPI_DBG("%s: 0x%02x for %s",
             TT::FIELD_STR,
             o_value,
             spd::c_str(i_target));
#endif


fapi_try_exit:
    return fapi2::current_err;
}
#ifndef __PPE__
///
/// @brief byte field writer
/// @tparam E endian type
/// @tparam F the byte field to read
/// @tparam TT traits associated with writer
/// @tparam T the fapi2 target type
/// @tparam IT input type
/// @tparam FFDC ffdc code type
/// @param[in] i_target the dimm target
/// @param[in] i_setting value to set for field
/// @param[in] i_ffdc_codes FFDC code
/// @param[in,out] io_data the data to modify
/// @return FAPI2_RC_SUCCESS iff okay
///
template< mss::endian E,
          const mss::field_t<E>& F,
          typename TT,
          fapi2::TargetType T,
          typename IT,
          typename FFDC >
inline fapi2::ReturnCode set_field( const fapi2::Target<T>& i_target,
                                    const IT i_setting,
                                    const FFDC i_ffdc_codes,
                                    std::vector<uint8_t>& io_data )
{
    const size_t BYTE = F.get_byte(io_data);

    // Test if the data we want to set is valid for this field
    FAPI_TRY( check::invalid_value(i_target,
                                   conditional( i_setting,
                                           TT::COMPARISON_VAL,
                                           typename TT::template COMPARISON_OP<IT>() ),
                                   BYTE,
                                   i_setting,
                                   i_ffdc_codes),
              "Failed fail_for_invalid_value() for %s", spd::c_str(i_target) );

    FAPI_TRY( (set_field<E, F>(i_target, i_setting, i_ffdc_codes, io_data)),
              "Failed set_field() for %s", spd::c_str(i_target) );

    FAPI_DBG("%s: Set value of 0x%02x. Data for buffer at byte %d, is now 0x%02x for %s",
             TT::FIELD_STR,
             i_setting,
             BYTE,
             io_data[BYTE],
             spd::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

#endif // PPE

}// mss

#endif // include guard
