/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
/// @file data_engine_utils.H
/// @brief Data engine to set memory driven data
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI

#ifndef _MSS_DATA_ENGINE_UTILS_H_
#define _MSS_DATA_ENGINE_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#ifndef __PPE__
    #include <generic/memory/lib/spd/spd_fields_ddr4.H>
#endif
#include <generic/memory/lib/spd/spd_fields_ddr5.H>
#include <generic/memory/lib/utils/mss_pair.H>
#include <fapi2_spd_access.H>

namespace mss
{

// Controller agnostic functions

namespace gen
{

///
/// @class get
/// @brief get struct base class
/// @tparam T TargetType with which to use
/// @tparam DT the data type
///
template <fapi2::TargetType T, typename DT>
struct get;

///
/// @brief Helper function to update the structure that holds attr data
/// @tparam DT data type
/// @tparam T Input/output data type
/// @tparam FFDC the FFDC type
/// @tparam X size of 1st array index
/// @param[in] i_data the SPD data
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data attribute data structure to set
/// @warn DT requires an adaptor that supports get_target()
/// @return FAPI2_RC_SUCCESS iff okay
///
template < typename DT,
           typename T,
           typename FFDC,
           size_t X >
fapi2::ReturnCode update_data( const DT& i_data,
                               const T i_setting,
                               const FFDC i_ffdc_code,
                               T (&o_data)[X])
{
    const auto l_dimm = i_data.get_target();
    const size_t l_dimm_index = mss::index(l_dimm);

    FAPI_TRY( check::index_within_bounds(l_dimm, l_dimm_index, X, i_ffdc_code) );

    FAPI_DBG("Updating data[%d] with %d for %s", l_dimm_index, i_setting, spd::c_str(l_dimm));
    o_data[l_dimm_index] = i_setting;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to update the structure that holds attr data
/// @tparam DT the data type
/// @tparam IT Input data type
/// @tparam FFDC type
/// @tparam OT Output data type
/// @param[in] i_data the data (e.g. EFD, SPD)
/// @param[in] i_setting array to set
/// @param[in] i_ffdc_code FFDC function code
/// @param[out] o_data output to set
/// @return FAPI2_RC_SUCCESS iff okay
///
template <typename DT,
          typename IT,
          typename FFDC,
          typename OT>
inline fapi2::ReturnCode update_data(const DT& i_data,
                                     const IT& i_setting,
                                     const FFDC i_ffdc_code,
                                     OT& o_data)
{
    o_data = i_setting;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Sets attr data fields
/// @tparam TT data engine class traits (e.g. preDataInitTraits, etc.)
/// @tparam DT the data type
/// @tparam IT Input data type
/// @param[in] i_target the FAPI target
/// @param[in] i_setting value we want to set attr with
/// @return FAPI2_RC_SUCCESS iff okay
///
template< typename TT,
          typename DT,
          typename IT >
inline fapi2::ReturnCode set_field(const DT& i_data,
                                   const IT& i_setting)
{
    // Grab the target associated w/the data (e.g. SPD or EFD)
    const auto l_attr_target = get<TT::TARGET_TYPE, DT>::target(i_data);

    // Get the attribute data in its entirety
    typename TT::attr_type l_attr_list = {};
    FAPI_TRY( TT::get_attr(l_attr_target, l_attr_list),
              "Failed get_attr()");

    // Update the portion of interest (can vary per dimm and/or rank)
    FAPI_TRY( update_data(i_data, i_setting, TT::FFDC_CODE, l_attr_list),
              "Failed update_data()");

    FAPI_DBG("Updating data with %d for %s", i_setting, spd::c_str(l_attr_target));

    // Set the contents back to the attribute
    FAPI_TRY( TT::set_attr(l_attr_target, l_attr_list),
              "Failed set_attr()");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a DIMM's position from a fapi2 target
/// @tparam TT Traits associated with DIMM position (e.g. dimmPosTraits)
/// @tparam OT the output type
/// @param[in] i_target a target representing the target in question
/// @param[out] o_value The position relative to the chip
///
template< typename TT, typename OT>
fapi2::ReturnCode dimm_pos(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, OT& o_value)
{
    const auto l_proc_pos = mss::pos( TT::get_proc(i_target) );

    typename TT::pos_type l_pos = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_target, l_pos));

    // To get the FAPI_POS to the equivilent of ATTR_POS, we need to normalize the fapi_pos value
    // to the processor (stride across which ever processor we're on) and then add in the delta
    // per processor as ATTR_POS isn't processor relative (delta is the total dimm on a processor)
    o_value = ((l_pos - (l_proc_pos * TT::DIMM_STRIDE_PER_PROC)) % TT::TOTAL_DIMM) + (TT::TOTAL_DIMM * l_proc_pos);

fapi_try_exit:
    return fapi2::current_err;
}

#ifndef __PPE__
///
/// @brief Align the READ_PREAMBLE and WRITE_PREAMBLE to the si attribute bitmap
///
/// @param[in] i_read_pramble read preamble value
/// @param[in] i_write_preamble write preamble value
/// @return uint8_t attribute-friendly bitmap
///
static inline uint8_t align_preamble_to_attr(const uint8_t i_read_pramble, const uint8_t i_write_preamble)
{
    fapi2::buffer<uint8_t> l_si_preamble;

    // Sets bits if the fields are true ( == 1 )
    l_si_preamble.writeBit<fapi2::ENUM_ATTR_MEM_SI_DRAM_PREAMBLE_WRITE_PREAMBLE_BIT>(i_write_preamble);
    l_si_preamble.writeBit<fapi2::ENUM_ATTR_MEM_SI_DRAM_PREAMBLE_READ_PREAMBLE_BIT>(i_read_pramble);

    return l_si_preamble;
}
#endif

///
/// @brief Shift the bits of the SPD field to match the attribute format
/// @param[in] i_value ODT field value from SPD
/// @return ATTR formatted uint8_t
///
static inline uint8_t align_odt_field_to_attr(const uint8_t i_value)
{
    static constexpr uint8_t ODT2_OLD = 2;
    static constexpr uint8_t ODT3_OLD = 3;
    static constexpr uint8_t ODT2 = 4;
    static constexpr uint8_t ODT3 = 5;

    fapi2::buffer<uint8_t> l_value(i_value);
    // Map to attribute bitmap
    reverse(l_value);

    // l_value currently looks like:
    // XXYY0000
    // ODT
    // 0123----
    //
    // We need it to look like:
    // XX00YY00
    // 01--23--
    l_value.writeBit<ODT2>(l_value.getBit<ODT2_OLD>());
    l_value.writeBit<ODT3>(l_value.getBit<ODT3_OLD>());

    l_value.clearBit<ODT2_OLD>();
    l_value.clearBit<ODT3_OLD>();

    return l_value;
}

#ifndef __PPE__
namespace ddr4
{

///
/// @brief Get the max valid cas latency
///
/// @param[in] i_rev SPD revision
/// @param[in] i_dimm_type DIMM type
/// @return uint32_t max valid CL val
///
static inline uint32_t get_max_valid_cl_val(const uint8_t i_rev, const uint8_t i_dimm_type)
{
    return (i_rev == mss::spd::rev::V1_0 && (i_dimm_type != fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM))
           ? 0x0003FFFF : 0xBFFFFFFF;
}

///
/// @brief Get the supported cas latencies as calculated from SPD fields and dimm type (DDR4 version)
///
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd spd binary
/// @param[in] i_rev spd revision
/// @param[out] o_field supported CL field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_supported_cas_latencies(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    const mss::spd::rev i_rev,
    uint32_t& o_field);

} // namespace ddr4
#endif

namespace ddr5
{

///
/// @brief Get the supported cas latencies as calculated from SPD fields and dimm type (DDR5 version)
///
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd spd binary
/// @param[in] i_rev spd revision
/// @param[out] o_field supported CL field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_supported_cas_latencies(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    const mss::spd::rev i_rev,
    uint64_t& o_field);

/// @brief Get the supported cas latencies as calculated from SPD fields and dimm type (DDR5 version)
///
/// tparam N size of spd binary array
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd spd binary
/// @param[in] i_rev spd revision
/// @param[out] o_field supported CL field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
/// Note : PPE compatible version of function
template <size_t N>
fapi2::ReturnCode get_supported_cas_latencies(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const uint8_t (&i_spd)[N],
    const mss::spd::rev i_rev,
    uint64_t& o_field)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR5, mss::spd::module_params::BASE_CNFG>;

    o_field = 0;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);
    uint8_t l_first_raw_byte = 0;
    uint8_t l_sec_raw_byte = 0;
    uint8_t l_third_raw_byte = 0;
    uint8_t l_fourth_raw_byte = 0;
    uint8_t l_fifth_raw_byte = 0;
    uint8_t l_dimm_type = 0;

    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_FIRST_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_first_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_SECOND_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_sec_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_THIRD_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_third_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_FOURTH_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_fourth_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_FIFTH_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_fifth_raw_byte));

    FAPI_TRY(mss::attr::get_dimm_type(i_dimm, l_dimm_type));

    {
        // Buffers used for bit manipulation
        // Combine Bytes to create bitmap - right aligned
        fapi2::buffer<uint64_t> l_buffer;
        right_aligned_insert(l_buffer,
                             l_fifth_raw_byte,
                             l_fourth_raw_byte,
                             l_third_raw_byte,
                             l_sec_raw_byte,
                             l_first_raw_byte);

        // For DDR5 all bits are valid in the CAS latencies supported bytes
        // so no range checking is needed
        o_field = uint64_t(l_buffer);

        FAPI_INF(GENTARGTIDFORMAT " CAS latencies supported (bitmap): 0x%010X",
                 GENTARGTID(i_dimm),
                 o_field);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Performs vref calculations per dram
/// @param[in] i_port MEM PORT target
/// @param[in] i_dimm_rank DIMM rank
/// @param[in] i_byte_index byte index of base vref value
/// @param[in] i_dram DRAM to set calculated vref to
/// @param[in] i_vref_byte Value for VREF pulled from SPD
/// @param[in] i_vref_add_sub Bit that denotes wether we are adding or sub with offset
/// @param[in] i_vref_multiplier Determines how many times to apply offset
/// @param[in] i_vref_offset Offset value to apply to VREF
/// @param[inout] io_vref Value of VREF to be written into attribute
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode calc_vref_offset(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
                                   const uint8_t& i_dimm_rank,
                                   const uint8_t& i_byte_index,
                                   const uint8_t& i_dram,
                                   const uint8_t (&i_vref_byte)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR],
                                   const uint8_t (&i_vref_add_sub)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM],
                                   const uint8_t& i_vref_multiplier,
                                   const uint8_t (&i_vref_offset)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM],
                                   uint8_t (&io_vref)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM]);

///
/// @brief Applies Bytes 322 and 324-403 to VREF CA/CS
/// @param[in] i_port MEM PORT target
/// @param[in] i_dimm_rank Dimm rank
/// @param[in] i_ffdc_code FFDC code for error traces
/// @param[in] i_vref_byte Value for VREF pulled from SPD
/// @param[in] i_vref_add_sub Bit that denotes wether we are adding or sub with offset
/// @param[in] i_vref_multiplier Determines how many times to apply offset
/// @param[in] i_vref_offset Offset value to apply to VREF
/// @param[in,out] io_vref Value of VREF to be written into attribute
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode apply_vref_offset_mult(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
        const uint8_t& i_dimm_rank,
        const uint16_t& i_ffdc_code,
        const uint8_t (&i_vref_byte)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR],
        const uint8_t (&i_vref_add_sub)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM],
        const uint8_t& i_vref_multiplier,
        const uint8_t (&i_vref_offset)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM],
        uint8_t (&io_vref)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM]);

} // namespace ddr5

} // namespace gen

namespace spd
{

///
/// @brief Retrieve SPD data from DIMM
/// @param[in] i_target the DIMM target
/// @param[out] o_spd reference to std::vector
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_raw_data_dimm(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    std::vector<uint8_t>& o_spd);

///
/// @brief Retrieve SPD data from DIMM
/// @param[in] i_target the OCMB CHIP target
/// @param[out] o_spd reference to spd array
/// @return FAPI2_RC_SUCCESS iff okay
///
/// Note : PPE compatible version of function
fapi2::ReturnCode get_raw_data_dimm(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint8_t (&o_spd)[mss::spd::DDR5_SPD_SIZE]);

///
/// @brief Retrieve module specific portion of SPD data from planar config
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_spd reference to std::vector
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_raw_data_planar(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& o_spd);

///
/// @brief Combine module specific and ISDIMM SPD data for planar config
/// @param[in] i_planar_spd module-specific SPD from planar
/// @param[in] i_isdimm_spd SPD from ISDIMM
/// @param[out] o_spd reference to std::vector of combined SPD, like we would get from a DDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
void combine_planar_spd(
    const std::vector<uint8_t>& i_planar_spd,
    const std::vector<uint8_t>& i_isdimm_spd,
    std::vector<uint8_t>& o_spd);

///
/// @brief Retrieve SPD data
/// @param[in] i_target the DIMM target
/// @param[in] i_is_planar the value of ATTR_MEM_MRW_IS_PLANAR
/// @param[out] o_spd reference to std::vector
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_raw_data(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint8_t i_is_planar,
    std::vector<uint8_t>& o_spd);

///
/// @brief Retrieve SPD data
/// @param[in] i_target the OCMB CHIP target
/// @param[out] o_spd reference to spd array
/// @return FAPI2_RC_SUCCESS iff okay
///
/// Note : PPE compatible version of function
fapi2::ReturnCode get_raw_data(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint8_t (&o_spd)[mss::spd::DDR5_SPD_SIZE]);

///
/// @brief Helper function for setting the bytes per DRAM
/// @param[in] i_target the DIMM target
/// @param[in] i_field field parameter including byte, start, len
/// @param[in] i_binary binary (SPD/EFD)
/// @param[in] i_ffdc_code FFDC code for error traces
/// @param[in] Current rank
/// @param[in] Current pos/phy/port
/// @param[out] o_bytes reference to std::vector of the arranged bytes
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode set_bytes_per_dram_helper_func(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        const mss::field_t<mss::endian::LITTLE>& i_field,
        const std::vector<uint8_t>& i_binary,
        const uint16_t i_ffdc_code,
        const uint8_t i_rank,
        const uint8_t i_pos,
        uint8_t (&o_bytes)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM]);

///
/// @brief Helper function for setting the bytes per DRAM
/// @param[in] i_target the DIMM target
/// @param[in] i_field field parameter including byte, start, len
/// @param[in] i_binary binary (SPD/EFD)
/// @param[in] i_ffdc_code FFDC code for error traces
/// @param[in] Current rank
/// @param[in] Current pos/phy/port
/// @param[out] o_bytes reference to std::vector of the arranged bytes
/// @return FAPI2_RC_SUCCESS iff okay
///
/// Note : PPE compatible version of function
template <size_t N>
fapi2::ReturnCode set_bytes_per_dram_helper_func(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::field_t<mss::endian::LITTLE>& i_field,
        const uint8_t (&i_binary)[N],
        const uint16_t i_ffdc_code,
        const uint8_t i_rank,
        const uint8_t i_pos,
        uint8_t (&o_bytes)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM])
{
    // Get the ocmb target
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Get the byte number
    size_t l_start_byte_num = i_field.get_byte(i_binary);

    // Manipulate the starting byte number based on rank and port
    //  [POS][RANK][DRAM]  Byte Num Start Byte
    //    0     0  [0-9]   0-9          0
    //    0     0  [10-19] 20-29
    //    0     1  [0-9]   10-19       10
    //    0     1  [10-19] 30-39
    //    1     0  [0-9]   40-49       40
    //    1     0  [10-19] 60-69
    //    1     1  [0-9]   50-59       50
    //    1     1  [10-19] 70-79
    // If we are in pos 0 and rank 0 the start byte is 0
    // If we are in pos 0 and rank 1, add 10 to start byte
    if(i_pos == 0 && i_rank == 1)
    {
        // Set the start byte as byte 10
        l_start_byte_num = i_field.get_byte(i_binary) + 10;
    }
    // If we are in pos 1 and rank0, add 40 to start byte
    else if(i_pos == 1 && i_rank == 0)
    {
        // Set the start byte as byte 40
        l_start_byte_num = i_field.get_byte(i_binary) + 40;
    }
    // If we are in pos 1 and rank1, add 50 to start byte
    else if(i_pos == 1 && i_rank == 1)
    {
        // Set the start byte as byte 50
        l_start_byte_num = i_field.get_byte(i_binary) + 50;
    }

    // Create a new array of field_t for the port we are working on using the above start_byte_num
    // Note: start byte and the length will not change for the particular field
    const mss::field_t<mss::endian::LITTLE>PER_DRAM_FIELDS[mss::ddr5::mr::ATTR_DRAM] =
    {
        // DRAM[0]- DRAM[9]
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num,   i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 1, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 2, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 3, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 4, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 5, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 6, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 7, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 8, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 9, i_field.get_start(), i_field.get_length()),
        // DRAM[10] - DRAM[19]
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 20, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 21, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 22, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 23, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 24, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 25, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 26, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 27, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 28, i_field.get_start(), i_field.get_length()),
        mss::field_t<mss::endian::LITTLE>(l_start_byte_num + 29, i_field.get_start(), i_field.get_length()),
    };

    // Update the o_bytes with the fields
    for(uint8_t l_dram = 0; l_dram < mss::ddr5::mr::ATTR_DRAM; l_dram++)
    {
        FAPI_TRY(mss::spd::get_field_spd(l_ocmb, PER_DRAM_FIELDS[l_dram], i_binary, i_ffdc_code, o_bytes[i_rank][l_dram]));
    }

fapi_try_exit:
    return fapi2::current_err;
}

}
namespace pmic
{

///
/// @brief Convert PMIC rail voltage offset from SPD to signed offset for attributes
///
/// @param[in] i_offset - unsigned offset value
/// @param[in] i_direction - direction (0 = positive, 1 = negative)
/// @return int8_t signed equivalent
/// @note Should be used with SPD data where the offset is 7 bits such that overflow could not be possible
///
int8_t convert_to_signed_offset(const uint8_t i_offset, const uint8_t i_direction);

}
} // namespace mss

#endif
