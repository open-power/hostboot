/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs05.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file mrs05.H
/// @brief Run and manage the DDR4 MRS05 loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR4_MRS05_H_
#define _GENERIC_DDR4_MRS05_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/dimm/mrs_traits.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/dimm/mrs_load.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/ccs/ccs.H>

namespace mss
{

namespace ddr4
{

///
/// @brief Configure the ARR0 of the CCS instruction for mrs05, data object as input
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @tparam MRS traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs05_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>, typename MRS = mrsTraits<MC> >
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs05_data<MC>& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_port_rank)
{
    constexpr uint64_t CA_PARITY_LATENCY_LENGTH = 3;
    constexpr uint64_t CA_PARITY_LATENCY_START = 7;
    constexpr uint64_t RTT_PARK_LENGTH = 3;
    constexpr uint64_t RTT_PARK_START = 7;

    constexpr uint64_t CA_PARITY_COUNT = 9;
    //                                                             0                4      5      6         8
    constexpr uint8_t ca_parity_latency_map[CA_PARITY_COUNT] = { 0b000, 0, 0, 0, 0b001, 0b010, 0b011, 0, 0b100 };

    fapi2::buffer<uint8_t> l_ca_parity_latency_buffer;

    fapi2::buffer<uint8_t> l_rtt_park_buffer = i_data.iv_rtt_park[mss::index(i_port_rank)];

    //check here to make sure the rank indexes correctly into the attribute array
    FAPI_ASSERT( (mss::index(i_port_rank) < MAX_RANK_PER_DIMM),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(5)
                 .set_PARAMETER(RANK)
                 .set_PARAMETER_VALUE(i_port_rank)
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for RTT park: %d (%s)", i_port_rank, mss::c_str(i_target));

    FAPI_ASSERT( (i_data.iv_ca_parity_latency < CA_PARITY_COUNT),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(5)
                 .set_PARAMETER(CA_PARITY_LATENCY)
                 .set_PARAMETER_VALUE(i_data.iv_ca_parity_latency)
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for CA parity latency: %d (%s)", i_data.iv_ca_parity_latency, mss::c_str(i_target));

    l_ca_parity_latency_buffer = ca_parity_latency_map[i_data.iv_ca_parity_latency];

    FAPI_INF("%s MR5 rank %d attributes: CAPL: 0x%x(0x%x), CRC_EC: 0x%x, CA_PES: 0x%x, ODT_IB: 0x%x "
             "RTT_PARK: 0x%x, CAP: 0x%x, DM: 0x%x, WDBI: 0x%x, RDBI: 0x%x",
             mss::c_str(i_target), i_port_rank, i_data.iv_ca_parity_latency, uint8_t(l_ca_parity_latency_buffer),
             i_data.iv_crc_error_clear, i_data.iv_ca_parity_error_status, i_data.iv_odt_input_buffer,
             uint8_t(l_rtt_park_buffer), i_data.iv_ca_parity,
             i_data.iv_data_mask, i_data.iv_write_dbi, i_data.iv_read_dbi);

    mss::swizzle<TT::A0, CA_PARITY_LATENCY_LENGTH, CA_PARITY_LATENCY_START>(l_ca_parity_latency_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<TT::A3>(i_data.iv_crc_error_clear);
    io_inst.arr0.writeBit<TT::A4>(i_data.iv_ca_parity_error_status);
    io_inst.arr0.writeBit<TT::A5>(i_data.iv_odt_input_buffer);
    mss::swizzle<TT::A6, RTT_PARK_LENGTH, RTT_PARK_START>(l_rtt_park_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<TT::A9>(i_data.iv_ca_parity);
    io_inst.arr0.writeBit<TT::A10>(i_data.iv_data_mask);
    io_inst.arr0.writeBit<TT::A11>(i_data.iv_write_dbi);
    io_inst.arr0.writeBit<TT::A12>(i_data.iv_read_dbi);

    FAPI_INF("%s MR5: 0x%016llx", mss::c_str(i_target), uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs05
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_port_rank)
{
    // Check to make sure our ctor worked ok
    mrs05_data<MC> l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS05 data from attributes", mss::c_str(i_target) );
    FAPI_TRY( mrs05(i_target, l_data, io_inst, i_port_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs05_decode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank the rank in question
/// @param[out] o_crc_error_clear the crc error clear setting
/// @param[out] o_ca_parity_error_status the c/a parity error status
/// @param[out] o_odt_input_buffer the odt input buffer during power down mode setting
/// @param[out] o_ca_parity the c/a parity persistent error setting
/// @param[out] o_data_mask the data mask setting
/// @param[out] o_write_dbi the write dbi setting
/// @param[out] o_read_dbi the read dbi setting
/// @param[out] o_ca_parity_latency_buffer the c/a parity latency mode setting
/// @param[out] o_rtt_park_buffer the rtt_park setting
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs05_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_port_rank,
                                      uint8_t& o_crc_error_clear,
                                      uint8_t& o_ca_parity_error_status,
                                      uint8_t& o_odt_input_buffer,
                                      uint8_t& o_ca_parity,
                                      uint8_t& o_data_mask,
                                      uint8_t& o_write_dbi,
                                      uint8_t& o_read_dbi,
                                      fapi2::buffer<uint8_t>& o_ca_parity_latency_buffer,
                                      fapi2::buffer<uint8_t>& o_rtt_park_buffer)
{
    o_ca_parity_latency_buffer = 0;
    o_rtt_park_buffer = 0;

    mss::swizzle<5, 3, TT::A2>(i_inst.arr0, o_ca_parity_latency_buffer);
    mss::swizzle<5, 3, TT::A8>(i_inst.arr0, o_rtt_park_buffer);

    o_crc_error_clear = i_inst.arr0.getBit<TT::A3>();
    o_ca_parity_error_status = i_inst.arr0.getBit<TT::A4>();
    o_odt_input_buffer = i_inst.arr0.getBit<TT::A5>();

    o_ca_parity = i_inst.arr0.getBit<TT::A9>();
    o_data_mask = i_inst.arr0.getBit<TT::A10>();
    o_write_dbi = i_inst.arr0.getBit<TT::A11>();
    o_read_dbi = i_inst.arr0.getBit<TT::A12>();

    FAPI_INF("MR5 rank %d decode: CAPL: 0x%x, CRC_EC: 0x%x, CA_PES: 0x%x, ODT_IB: 0x%x "
             "RTT_PARK: 0x%x, CAP: 0x%x, DM: 0x%x, WDBI: 0x%x, RDBI: 0x%x",
             i_port_rank, uint8_t(o_ca_parity_latency_buffer), o_crc_error_clear, o_ca_parity_error_status,
             o_odt_input_buffer, uint8_t(o_rtt_park_buffer), o_ca_parity, o_data_mask,
             o_write_dbi, o_read_dbi);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS5,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode mrs05_decode(const ccs::instruction_t& i_inst,
                                      const uint64_t i_port_rank)
{
    fapi2::buffer<uint8_t> l_ca_parity_latency_buffer;
    fapi2::buffer<uint8_t> l_rtt_park_buffer;

    uint8_t l_crc_error_clear = 0;
    uint8_t l_ca_parity_error_status = 0;
    uint8_t l_odt_input_buffer = 0;
    uint8_t l_ca_parity = 0;
    uint8_t l_data_mask = 0;
    uint8_t l_write_dbi = 0;
    uint8_t l_read_dbi = 0;

    return mrs05_decode_helper(i_inst, i_port_rank, l_crc_error_clear, l_ca_parity_error_status,
                               l_odt_input_buffer, l_ca_parity, l_data_mask, l_write_dbi,
                               l_read_dbi, l_ca_parity_latency_buffer, l_rtt_park_buffer);
}


} // ns ddr4
} // ns mss
#endif
