/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs00.H $             */
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
/// @file mrs00.H
/// @brief Run and manage the DDR4 MRS00 loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR4_MRS00_H_
#define _GENERIC_DDR4_MRS00_H_

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
/// @brief Configure the ARR0 of the CCS instruction for mrs00, data object as input
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @tparam MRS traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>, typename MRS = mrsTraits<MC> >
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs00_data<MC>& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_port_rank)
{
    // Map from Write Recovery attribute value to bits in the MRS.
    // Bit 4 is A13, bits 5:7 are A11:A9
    constexpr uint64_t LOWEST_WR = 10;
    constexpr uint64_t WR_COUNT = 17;
    constexpr uint8_t wr_map[WR_COUNT] =
    {
        // 10        12         14         16         18         20         22         24         26
        0b0000, 0, 0b0001, 0, 0b0010, 0, 0b0011, 0, 0b0100, 0, 0b0101, 0, 0b0111, 0, 0b0110, 0, 0b1000
    };

    // Map from the CAS Latency attribute to the bits in the MRS
    constexpr uint64_t LOWEST_CL = 9;
    constexpr uint64_t CL_COUNT = 25;
    constexpr uint8_t cl_map[CL_COUNT] =
    {
        // 9        10       11       12       13       14       15       16
        0b00000, 0b00001, 0b00010, 0b00011, 0b00100, 0b00101, 0b00110, 0b00111,
        // 17,      18       19       20       21       22       23       24
        0b01101, 0b01000, 0b01110, 0b01001, 0b01111, 0b01010, 0b01100, 0b01011,
        // 25       26       27       28       29       30       31       32       33
        0b10000, 0b10001, 0b10010, 0b10011, 0b10100, 0b10101, 0b10110, 0b10111, 0b11000
    };
    constexpr uint64_t BURST_LENGTH_LEN = 2;
    constexpr uint64_t BURST_LENGTH     = 7;

    fapi2::buffer<uint8_t> l_cl;
    fapi2::buffer<uint8_t> l_wr;
    fapi2::buffer<uint8_t> l_burst_length(i_data.iv_burst_length);

    FAPI_ASSERT((i_data.iv_write_recovery >= LOWEST_WR) && (i_data.iv_write_recovery < (LOWEST_WR + WR_COUNT)),
                fapi2::MSS_BAD_MR_PARAMETER()
                .set_MR_NUMBER(0)
                .set_PARAMETER(WRITE_RECOVERY)
                .set_PARAMETER_VALUE(i_data.iv_write_recovery)
                .set_DIMM_IN_ERROR(i_target),
                "Bad value for Write Recovery: %d (%s)",
                i_data.iv_write_recovery,
                mss::c_str(i_target));

    FAPI_ASSERT((i_data.iv_cas_latency >= LOWEST_CL) && (i_data.iv_cas_latency < (LOWEST_CL + CL_COUNT)),
                fapi2::MSS_BAD_MR_PARAMETER()
                .set_MR_NUMBER(0)
                .set_PARAMETER(CAS_LATENCY)
                .set_PARAMETER_VALUE(i_data.iv_cas_latency)
                .set_DIMM_IN_ERROR(i_target),
                "Bad value for CAS Latency: %d (%s)",
                i_data.iv_cas_latency,
                mss::c_str(i_target));

    mss::swizzle<TT::A0, BURST_LENGTH_LEN, BURST_LENGTH>(l_burst_length, io_inst.arr0);

    io_inst.arr0.writeBit<TT::A3>(i_data.iv_read_burst_type);
    io_inst.arr0.writeBit<TT::A7>(i_data.iv_test_mode);
    io_inst.arr0.writeBit<TT::A8>(i_data.iv_dll_reset);

    // CAS Latency takes a little effort - the bits aren't contiguous
    l_cl = cl_map[i_data.iv_cas_latency - LOWEST_CL];
    io_inst.arr0.writeBit<TT::A12>(l_cl.getBit<3>());
    io_inst.arr0.writeBit<TT::A6>(l_cl.getBit<4>());
    io_inst.arr0.writeBit<TT::A5>(l_cl.getBit<5>());
    io_inst.arr0.writeBit<TT::A4>(l_cl.getBit<6>());
    io_inst.arr0.writeBit<TT::A2>(l_cl.getBit<7>());

    // Write Recovery/Read to Precharge is not contiguous either.
    l_wr = wr_map[i_data.iv_write_recovery - LOWEST_WR];
    io_inst.arr0.writeBit<TT::A13>(l_wr.getBit<4>());
    io_inst.arr0.writeBit<TT::A11>(l_wr.getBit<5>());
    io_inst.arr0.writeBit<TT::A10>(l_wr.getBit<6>());
    io_inst.arr0.writeBit<TT::A9>(l_wr.getBit<7>());

    FAPI_INF("%s MR0: 0x%016llx", mss::c_str(i_target), uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs00
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_port_rank)
{
    // Check to make sure our ctor worked ok
    mrs00_data<MC> l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS00 data from attributes", mss::c_str(i_target) );
    FAPI_TRY( mrs00(i_target, l_data, io_inst, i_port_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs00_decode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank ths rank in question
/// @param[out] o_burst_length the burst length
/// @param[out] o_read_burst_type the burst type
/// @param[out] o_dll_reset the dll reset bit
/// @param[out] o_test_mode the test mode bit
/// @param[out] o_wr_index the write index
/// @param[out] o_cas_latency the cas latency
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs00_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_port_rank,
                                      uint8_t& o_burst_length,
                                      uint8_t& o_read_burst_type,
                                      uint8_t& o_dll_reset,
                                      uint8_t& o_test_mode,
                                      fapi2::buffer<uint8_t>& o_wr_index,
                                      fapi2::buffer<uint8_t>& o_cas_latency)
{
    static const uint8_t wr_map[9] = { 10, 12, 14, 16, 18, 20, 24, 22, 26 };

    o_wr_index = 0;
    o_cas_latency = 0;

    i_inst.arr0.extractToRight<TT::A0, 2>(o_burst_length);
    o_read_burst_type = i_inst.arr0.getBit<TT::A3>();
    o_test_mode = i_inst.arr0.getBit<TT::A7>();
    o_dll_reset = i_inst.arr0.getBit<TT::A8>();

    // CAS Latency takes a little effort - the bits aren't contiguous
    o_cas_latency.writeBit<3>(i_inst.arr0.getBit<TT::A12>());
    o_cas_latency.writeBit<4>(i_inst.arr0.getBit<TT::A6>());
    o_cas_latency.writeBit<5>(i_inst.arr0.getBit<TT::A5>());
    o_cas_latency.writeBit<6>(i_inst.arr0.getBit<TT::A4>());
    o_cas_latency.writeBit<7>(i_inst.arr0.getBit<TT::A2>());

    // Write Recovery/Read to Precharge is not contiguous either.
    o_wr_index.writeBit<4>(i_inst.arr0.getBit<TT::A13>());
    o_wr_index.writeBit<5>(i_inst.arr0.getBit<TT::A11>());
    o_wr_index.writeBit<6>(i_inst.arr0.getBit<TT::A10>());
    o_wr_index.writeBit<7>(i_inst.arr0.getBit<TT::A9>());

    FAPI_INF("MR0 Decode BL: 0x%x, RBT: 0x%x, CL: 0x%x, TM: 0x%x, DLL_RESET: 0x%x, WR: (0x%x)0x%x",
             o_burst_length, o_read_burst_type, uint8_t(o_cas_latency), o_test_mode, o_dll_reset,
             wr_map[uint8_t(o_wr_index)], uint8_t(o_wr_index));

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS0,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode mrs00_decode(const ccs::instruction_t& i_inst,
                                      const uint64_t i_port_rank)
{
    uint8_t l_burst_length = 0;
    uint8_t l_read_burst_type = 0;
    uint8_t l_dll_reset = 0;
    uint8_t l_test_mode = 0;
    fapi2::buffer<uint8_t> l_wr_index;
    fapi2::buffer<uint8_t> l_cas_latency;

    return mrs00_decode_helper(i_inst, i_port_rank, l_burst_length, l_read_burst_type, l_dll_reset, l_test_mode,
                               l_wr_index, l_cas_latency);
}

} // ns ddr4

} // ns mss
#endif
