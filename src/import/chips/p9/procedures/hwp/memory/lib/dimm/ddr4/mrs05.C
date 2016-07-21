/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs05.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file mrs05.C
/// @brief Run and manage the DDR4 MRS05 loading
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <mss.H>
#include <lib/dimm/ddr4/mrs_load_ddr4.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace ddr4
{

///
/// @brief mrs05_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
mrs05_data::mrs05_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc ):
    iv_ca_parity_latency(0),
    iv_crc_error_clear(0),
    iv_ca_parity_error_status(0),
    iv_odt_input_buffer(0),
    iv_ca_parity(0),
    iv_data_mask(0),
    iv_write_dbi(0),
    iv_read_dbi(0)
{
    FAPI_TRY( mss::eff_ca_parity_latency(i_target, iv_ca_parity_latency) );
    FAPI_TRY( mss::eff_crc_error_clear(i_target, iv_crc_error_clear) );
    FAPI_TRY( mss::eff_ca_parity_error_status(i_target, iv_ca_parity_error_status) );
    FAPI_TRY( mss::eff_odt_input_buff(i_target, iv_odt_input_buffer) );
    FAPI_TRY( mss::eff_rtt_park(i_target, &(iv_rtt_park[0])) );
    FAPI_TRY( mss::eff_ca_parity(i_target, iv_ca_parity) );
    FAPI_TRY( mss::eff_data_mask(i_target, iv_data_mask) );
    FAPI_TRY( mss::eff_write_dbi(i_target, iv_write_dbi) );
    FAPI_TRY( mss::eff_read_dbi(i_target, iv_read_dbi) );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("unable to get attributes for mrs0");
    return;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs05
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
    // Check to make sure our ctor worked ok
    mrs05_data l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "Unable to construct MRS05 data from attributes");
    FAPI_TRY( mrs05(i_target, l_data, io_inst, i_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs05, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs05_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs05_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
    constexpr uint64_t CA_PARITY_COUNT = 9;
    //                                                             0                4      5      6         8
    constexpr uint8_t ca_parity_latency_map[CA_PARITY_COUNT] = { 0b000, 0, 0, 0, 0b001, 0b010, 0b011, 0, 0b100 };

    // Indexed by denominator. So, if RQZ is 240, and you have OHM240, then you're looking
    // for index 1. So this doesn't correspond directly with the table in the JEDEC spec,
    // as that's not in "denominator order."
    constexpr uint64_t RTT_PARK_COUNT = 8;
    //                                                 0  RQZ/1  RQZ/2  RQZ/3  RQZ/4  RQZ/5  RQZ/6  RQZ/7
    constexpr uint8_t rtt_park_map[RTT_PARK_COUNT] = { 0, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };

    uint8_t l_rtt_park_index = 0;

    fapi2::buffer<uint8_t> l_ca_parity_latency_buffer;
    fapi2::buffer<uint8_t> l_rtt_park_buffer;

    FAPI_ASSERT( (i_data.iv_ca_parity_latency < CA_PARITY_COUNT),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(5)
                 .set_PARAMETER(CA_PARITY_LATENCY)
                 .set_PARAMETER_VALUE(i_data.iv_ca_parity_latency)
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for CA parity latency: %d (%s)", i_data.iv_ca_parity_latency, mss::c_str(i_target));

    FAPI_ASSERT( (i_rank < RTT_PARK_COUNT),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(5)
                 .set_PARAMETER(RTT_PARK)
                 .set_PARAMETER_VALUE(i_rank)
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for RTT park: %d (%s)", i_rank, mss::c_str(i_target));

    l_ca_parity_latency_buffer = ca_parity_latency_map[i_data.iv_ca_parity_latency];

    // We have to be careful about 0
    l_rtt_park_index = (i_data.iv_rtt_park[mss::index(i_rank)] == 0) ?
                       0 : fapi2::ENUM_ATTR_EFF_RTT_PARK_240OHM / i_data.iv_rtt_park[mss::index(i_rank)];

    // Map from RTT_NOM array to the value in the map
    l_rtt_park_buffer = rtt_park_map[l_rtt_park_index];

    FAPI_INF("MR5 rank %d attributes: CAPL: 0x%x(0x%x), CRC_EC: 0x%x, CA_PES: 0x%x, ODT_IB: 0x%x "
             "RTT_PARK: 0x%x(0x%x), CAP: 0x%x, DM: 0x%x, WDBI: 0x%x, RDBI: 0x%x", i_rank,
             i_data.iv_ca_parity_latency, uint8_t(l_ca_parity_latency_buffer), i_data.iv_crc_error_clear,
             i_data.iv_ca_parity_error_status, i_data.iv_odt_input_buffer,
             i_data.iv_rtt_park[mss::index(i_rank)], uint8_t(l_rtt_park_buffer), i_data.iv_ca_parity,
             i_data.iv_data_mask, i_data.iv_write_dbi, i_data.iv_read_dbi);

    mss::swizzle<A0, 3, 7>(l_ca_parity_latency_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A3>(i_data.iv_crc_error_clear);
    io_inst.arr0.writeBit<A4>(i_data.iv_ca_parity_error_status);
    io_inst.arr0.writeBit<A5>(i_data.iv_odt_input_buffer);
    mss::swizzle<A6, 3, 7>(l_rtt_park_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A9>(i_data.iv_ca_parity);
    io_inst.arr0.writeBit<A10>(i_data.iv_data_mask);
    io_inst.arr0.writeBit<A11>(i_data.iv_write_dbi);
    io_inst.arr0.writeBit<A12>(i_data.iv_read_dbi);

    FAPI_INF("MR5: 0x%016llx", uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS5,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs05_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_ca_parity_latency_buffer;
    fapi2::buffer<uint8_t> l_rtt_park_buffer;

    mss::swizzle<5, 3, A2>(i_inst.arr0, l_ca_parity_latency_buffer);
    mss::swizzle<5, 3, A8>(i_inst.arr0, l_rtt_park_buffer);

    uint8_t l_crc_error_clear = i_inst.arr0.getBit<A3>();
    uint8_t l_ca_parity_error_status = i_inst.arr0.getBit<A4>();
    uint8_t l_odt_input_buffer = i_inst.arr0.getBit<A5>();

    uint8_t l_ca_parity = i_inst.arr0.getBit<A9>();
    uint8_t l_data_mask = i_inst.arr0.getBit<A10>();
    uint8_t l_write_dbi = i_inst.arr0.getBit<A11>();
    uint8_t l_read_dbi = i_inst.arr0.getBit<A12>();

    FAPI_INF("MR5 rank %d decode: CAPL: 0x%x, CRC_EC: 0x%x, CA_PES: 0x%x, ODT_IB: 0x%x "
             "RTT_PARK: 0x%x, CAP: 0x%x, DM: 0x%x, WDBI: 0x%x, RDBI: 0x%x", i_rank,
             uint8_t(l_ca_parity_latency_buffer), l_crc_error_clear, l_ca_parity_error_status,
             l_odt_input_buffer, uint8_t(l_rtt_park_buffer), l_ca_parity, l_data_mask,
             l_write_dbi, l_read_dbi);

    return FAPI2_RC_SUCCESS;
}

fapi2::ReturnCode (*mrs05_data::make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs05_data& i_data,
        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
        const uint64_t i_rank) = &mrs05;

fapi2::ReturnCode (*mrs05_data::decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                        const uint64_t i_rank) = &mrs05_decode;

} // ns ddr4
} // ns mss
