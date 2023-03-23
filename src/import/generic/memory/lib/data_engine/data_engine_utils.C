/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/data_engine/data_engine_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file data_engine_utils.C
/// @brief Data engine to set memory driven data
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP FW Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: CI
// EKB-Mirror-To: hostboot

#include <vpd_access.H>
#include <generic/memory/lib/data_engine/data_engine_utils.H>
#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{

namespace gen
{

namespace ddr4
{

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
    uint32_t& o_field)
{
    using F = mss::spd::fields<mss::spd::device_type::DDR4, mss::spd::module_params::BASE_CNFG>;

    o_field = 0;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_dimm);
    uint8_t l_first_raw_byte = 0;
    uint8_t l_sec_raw_byte = 0;
    uint8_t l_third_raw_byte = 0;
    uint8_t l_fourth_raw_byte = 0;
    uint8_t l_dimm_type = 0;
    uint32_t l_field = 0;

    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_FIRST_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_first_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_SECOND_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_sec_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_THIRD_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_third_raw_byte));
    FAPI_TRY(mss::spd::get_field_spd(l_ocmb, F::CL_FOURTH_BYTE, i_spd, SET_SPD_CL_SUPPORTED, l_fourth_raw_byte));

    FAPI_TRY(mss::attr::get_dimm_type(i_dimm, l_dimm_type));

    {
        // Buffers used for bit manipulation
        // Combine Bytes to create bitmap - right aligned
        fapi2::buffer<uint64_t> l_buffer;
        right_aligned_insert(l_buffer, l_fourth_raw_byte, l_third_raw_byte, l_sec_raw_byte, l_first_raw_byte);

        // According to the JEDEC spec:
        // Byte 22 (Bits 7~0) and Byte 23 are reserved in the base revision SPD general section
        // Only bit 6 (right-aligned) for Byte 23 is reserved for subsequent SPD revisions
        // Check for a valid value, and that reserved bit is not set
        // We return Byte 23 arbitrarily as the failed byte, but any byte (20 - 23) would work
        // This rev 1.0 does not apply to DDIMM 1.0 - so make sure we are not a ddimm
        const size_t MAX_VALID_VAL = mss::gen::ddr4::get_max_valid_cl_val(i_rev, l_dimm_type);

        constexpr uint64_t DATA_START_OFFSET  = 32;
        constexpr uint64_t RESERVED_BIT = DATA_START_OFFSET + 1;
        // Bit 6 of byte 23 must be 0 (reserved for future use)
        const bool RESERVED_BIT_VALUE = l_buffer.getBit<RESERVED_BIT>();

        FAPI_TRY( mss::check::invalid_value(i_dimm,
                                            l_buffer <= MAX_VALID_VAL && !RESERVED_BIT_VALUE,
                                            23,
                                            l_buffer,
                                            mss::BAD_SPD_DATA,
                                            "Failed check on CAS latencies supported") );

        // Update output value only if range check passes
        l_field = uint32_t(l_buffer);

        FAPI_INF("%s. CAS latencies supported (bitmap): 0x%llX",
                 spd::c_str(i_dimm),
                 l_field);
        o_field = l_field;
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns ddr4

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

        FAPI_INF("%s. CAS latencies supported (bitmap): 0x%010X",
                 spd::c_str(i_dimm),
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
                                   uint8_t (&io_vref)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM])
{
    // Checks vref_sub_add for operation
    // Checks for over/underflow
    // Applies Offset (EFD Bytes 324-403) * multiplier (EFD Byte 322) to Base Vref (EFD Byte 306-313)
    // Stores in io_vref array to be written to attr
    uint16_t l_calc_vref_step = i_vref_offset[i_dimm_rank][i_dram] * i_vref_multiplier;

    if(i_vref_add_sub[i_dimm_rank][i_dram] == mss::ddr5::mr::VREF_ADD)
    {
        if((l_calc_vref_step + i_vref_byte[i_byte_index]) <=  mss::ddr5::mr::VREF_MAX )
        {
            io_vref[i_dimm_rank][i_dram] = i_vref_byte[i_byte_index] + l_calc_vref_step;
        }
        else
        {
            FAPI_INF("Port %s VREF Overflow detected on DRAM %u Rank %u (Offset w/ multiplier value %d)",
                     spd::c_str(i_port),
                     i_dram,
                     i_dimm_rank,
                     l_calc_vref_step);
            FAPI_INF("Base Vref on that DRAM and RANK was %d, value set to 155",
                     i_vref_byte[i_byte_index])

            // Set to VREF_MAX if overflow detected
            io_vref[i_dimm_rank][i_dram] = mss::ddr5::mr::VREF_MAX;
        }
    }
    else
    {
        if(l_calc_vref_step <= i_vref_byte[i_byte_index])
        {
            io_vref[i_dimm_rank][i_dram] = i_vref_byte[i_byte_index] - l_calc_vref_step;
        }
        else
        {
            FAPI_INF("Port %s VREF Underflow detected on DRAM %u Rank %u (Offset w/ multiplier value %d)",
                     spd::c_str(i_port),
                     i_dram,
                     i_dimm_rank,
                     l_calc_vref_step);

            FAPI_INF("Base Vref on that DRAM and RANK was %d, value set to 0",
                     i_vref_byte[i_byte_index])

            // Set to VREF_MIN if underflow detected
            io_vref[i_dimm_rank][i_dram] = mss::ddr5::mr::VREF_MIN;
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Applies Bytes 322 and 324-403 to VREF CA/CS
/// @param[in] i_port MEM PORT target
/// @param[in] i_dimm_rank DIMM rank
/// @param[in] i_ffdc_code FFDC code for error traces
/// @param[in] i_vref_byte Value for VREF pulled from SPD
/// @param[in] i_vref_add_sub Bit that denotes wether we are adding or sub with offset
/// @param[in] i_vref_multiplier Determines how many times to apply offset
/// @param[in] i_vref_offset Offset value to apply to VREF
/// @param[inout] io_vref Value of VREF to be written into attribute
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode apply_vref_offset_mult(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
        const uint8_t& i_dimm_rank,
        const uint16_t& i_ffdc_code,
        const uint8_t (&i_vref_byte)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR],
        const uint8_t (&i_vref_add_sub)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM],
        const uint8_t& i_vref_multiplier,
        const uint8_t (&i_vref_offset)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM],
        uint8_t (&io_vref)[mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR][mss::ddr5::mr::ATTR_DRAM])
{
    uint8_t l_byte_index = 0;
    FAPI_ASSERT(i_dimm_rank < mss::generic_sizes::MAX_RANK_PER_DIMM_ATTR,
                fapi2::MSS_INVALID_RANK().
                set_FUNCTION(i_ffdc_code).
                set_RANK(i_dimm_rank).
                set_PORT_TARGET(i_port),
                "%s rank out of bounds rank %u", spd::c_str(i_port), i_dimm_rank);

    // Multiplies offset by l_vref_mult then adds or subtracts from vrefca
    //    Port  Rank  Dram   Byte
    //    0       0    0-9   Byte 306 +/- bytes 324-333 * byte 322 A0
    //    0       1    0-9   Byte 307 +/- bytes 334-343 * byte 322 A0
    //    1       0    0-9   Byte 310 +/- bytes 364-373 * byte 322 A1
    //    1       1    0-9   Byte 311 +/- bytes 374-383 * byte 322 A1
    //    0       0   10-19  Byte 308 +/- bytes 344-353 * byte 322 B0
    //    0       1   10-19  Byte 309 +/- bytes 354-363 * byte 322 B0
    //    1       0   10-19  Byte 312 +/- bytes 384-393 * byte 322 B1
    //    1       1   10-19  Byte 313 +/- bytes 394-403 * byte 322 B1

    for(uint8_t l_dram = mss::ddr5::mr::ATTR_DRAM_CHA_SELECT; l_dram < mss::ddr5::mr::ATTR_DRAM; l_dram++)
    {
        // Channel A DRAM 0-9
        if(l_dram < mss::ddr5::mr::ATTR_DRAM_CHB_SELECT)
        {
            l_byte_index = i_dimm_rank % 2;
        }
        // Channel B DRAM 10-19
        else
        {
            l_byte_index = (i_dimm_rank % 2) + 2;
        }

        FAPI_TRY(calc_vref_offset(i_port,
                                  i_dimm_rank,
                                  l_byte_index,
                                  l_dram,
                                  i_vref_byte,
                                  i_vref_add_sub,
                                  i_vref_multiplier,
                                  i_vref_offset,
                                  io_vref));
    }

fapi_try_exit:
    return fapi2::current_err;
}
} // ns ddr5

} // ns gen

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
    std::vector<uint8_t>& o_spd)
{
    // Get SPD blob size
    size_t l_size = 0;
    FAPI_TRY( fapi2::getSPD(i_target, nullptr, l_size),
              "%s. Failed to retrieve SPD blob size", spd::c_str(i_target) );

    FAPI_DBG( "SPD size %d for %s", l_size, spd::c_str(i_target) );

    // Reassign container size with the retrieved size
    // Arbitrarily set the data to zero since it will be overwritten
    o_spd.assign(l_size, 0);

    // Retrieve SPD data content
    FAPI_TRY( fapi2::getSPD(i_target, o_spd.data(), l_size),
              "%s. Failed to retrieve SPD data", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieve module specific portion of SPD data from planar config
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_spd reference to std::vector
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode get_raw_data_planar(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<uint8_t>& o_spd)
{
    // Get SPD size
    fapi2::MemVpdData_t l_vpd_type(fapi2::MemVpdData::BUFFER);
    fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP> l_vpd_info(l_vpd_type);

    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, nullptr),
              "%s failed getting VPD size from getVPD", spd::c_str(i_target) );

    // If we have a negative SPD size, assert out
    FAPI_ASSERT(l_vpd_info.iv_size < 0x80000,
                fapi2::MSS_NEGATIVE_VPD_SIZE()
                .set_OCMB_TARGET(i_target)
                .set_SIZE(l_vpd_info.iv_size),
                "%s has a negative VPD size of %i", spd::c_str(i_target), l_vpd_info.iv_size);

    // Reassign container size with the retrieved size
    // Arbitrarily set the data to zero since it will be overwritten
    o_spd.assign(l_vpd_info.iv_size, 0);

    // Get SPD data
    FAPI_TRY( fapi2::getVPD(i_target, l_vpd_info, o_spd.data()),
              "%s. Failed to retrieve SPD data", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

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
    std::vector<uint8_t>& o_spd)
{
    // Note: These constants are only valid for DDR4
    constexpr uint64_t BASE_CONFIG_NUM_BYTES = 128;
    constexpr uint64_t MODULE_CONFIG_NUM_BYTES = 64;
    constexpr uint64_t BASE_PLUS_MODULE_NUM_BYTES = BASE_CONFIG_NUM_BYTES + MODULE_CONFIG_NUM_BYTES;
    constexpr uint64_t MODULE_SUPPLIER_DATA_START = 320;
    constexpr uint64_t MODULE_SUPPLIER_DATA_LEN = 64;
    constexpr uint64_t MODULE_SUPPLIER_DATA_END = MODULE_SUPPLIER_DATA_START + MODULE_SUPPLIER_DATA_LEN;

    o_spd.clear();
    o_spd.resize(i_planar_spd.size());

    // Copy base config content
    std::copy(i_isdimm_spd.begin(),
              i_isdimm_spd.begin() + BASE_CONFIG_NUM_BYTES,
              o_spd.begin());

    // Copy ISDIMM module specific content
    std::copy(i_isdimm_spd.begin() + BASE_CONFIG_NUM_BYTES,
              i_isdimm_spd.begin() + BASE_PLUS_MODULE_NUM_BYTES,
              o_spd.begin() + BASE_CONFIG_NUM_BYTES);

    // Copy planar (DDIMM) module specific content
    std::copy(i_planar_spd.begin() + BASE_PLUS_MODULE_NUM_BYTES,
              i_planar_spd.end(),
              o_spd.begin() + BASE_PLUS_MODULE_NUM_BYTES);

    // Copy ISDIMM module supplier data
    std::copy(i_isdimm_spd.begin() + MODULE_SUPPLIER_DATA_START,
              i_isdimm_spd.begin() + MODULE_SUPPLIER_DATA_END,
              o_spd.begin() + MODULE_SUPPLIER_DATA_START);
}

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
    std::vector<uint8_t>& o_spd)
{
    if (i_is_planar == fapi2::ENUM_ATTR_MEM_MRW_IS_PLANAR_FALSE)
    {
        FAPI_TRY(mss::spd::get_raw_data_dimm(i_target, o_spd));
    }
    else
    {
        // For planar config, we need to read the SPD from both the DIMM and planar then combine
        const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
        std::vector<uint8_t> l_isdimm_spd;
        std::vector<uint8_t> l_planar_vpd;

        // First read the ISDIMM SPD
        FAPI_TRY(mss::spd::get_raw_data_dimm(i_target, l_isdimm_spd));

        // Next read the planar VPD
        FAPI_TRY(mss::spd::get_raw_data_planar(l_ocmb, l_planar_vpd));

        // Then combine them into a single blob like we get from a DDIMM
        mss::spd::combine_planar_spd(l_planar_vpd, l_isdimm_spd, o_spd);
    }

fapi_try_exit:
    return fapi2::current_err;
}

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
fapi2::ReturnCode set_bytes_per_dram_helper_func(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::field_t<mss::endian::LITTLE>& i_field,
        const std::vector<uint8_t>& i_binary,
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

} // ns spd

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
int8_t convert_to_signed_offset(const uint8_t i_offset, const uint8_t i_direction)
{
    // Offset voltage from spd (+/-)
    static constexpr uint8_t OFFSET_MINUS = 1;

    // Since offset value must be 7 bits (from SPD), we can directly cast it to an int8_t
    int8_t l_signed_offset = static_cast<int8_t>(i_offset);

    if (i_direction == OFFSET_MINUS)
    {
        // Can't overflow since signed_offset was only 7 bits
        l_signed_offset = 0 - l_signed_offset;
    }

    return l_signed_offset;
}

} // ns pmic
} // ns mss
