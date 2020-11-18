/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs04.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file mrs04.H
/// @brief Run and manage the DDR4 MRS04 loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR4_MRS04_H_
#define _GENERIC_DDR4_MRS04_H_

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
/// @brief Configure the ARR0 of the CCS instruction for mrs04, data object as input
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @tparam MRS traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs04_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>, typename MRS = mrsTraits<MC> >
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs04_data<MC>& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank)
{
    constexpr uint64_t CS_CMD_LATENCY_LENGTH = 3;
    constexpr uint64_t CS_CMD_LATENCY_START = 7;

    constexpr uint64_t CS_CMD_COUNT = 9;
    //                                                       0            3      4      5      6         8
    constexpr uint8_t cs_cmd_latency_map[CS_CMD_COUNT] = { 0b000, 0, 0, 0b001, 0b010, 0b011, 0b100, 0, 0b101 };

    fapi2::buffer<uint8_t> l_cs_cmd_latency_buffer;

    FAPI_ASSERT( (i_data.iv_cs_cmd_latency < CS_CMD_COUNT),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(4)
                 .set_PARAMETER(CS_CMD_LATENCY)
                 .set_PARAMETER_VALUE(i_data.iv_cs_cmd_latency)
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for CS to CMD/ADDR Latency: %d (%s)", i_data.iv_cs_cmd_latency, mss::c_str(i_target));

    l_cs_cmd_latency_buffer = cs_cmd_latency_map[i_data.iv_cs_cmd_latency];

    io_inst.arr0.writeBit<TT::A1>(i_data.iv_max_pd_mode);
    io_inst.arr0.writeBit<TT::A2>(i_data.iv_temp_refresh_range);
    io_inst.arr0.writeBit<TT::A3>(i_data.iv_temp_ref_mode);
    io_inst.arr0.writeBit<TT::A4>(i_data.iv_vref_mon);
    io_inst.arr0.writeBit<TT::A5>(i_data.iv_soft_ppr);

    mss::swizzle<TT::A6, CS_CMD_LATENCY_LENGTH, CS_CMD_LATENCY_START>(l_cs_cmd_latency_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<TT::A9>(i_data.iv_ref_abort);
    io_inst.arr0.writeBit<TT::A10>(i_data.iv_rd_pre_train_mode);
    io_inst.arr0.writeBit<TT::A11>(i_data.iv_rd_preamble);
    io_inst.arr0.writeBit<TT::A12>(i_data.iv_wr_preamble);
    io_inst.arr0.writeBit<TT::A13>(i_data.iv_ppr);

    FAPI_INF("%s MR4: 0x%016llx", mss::c_str(i_target), uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs04
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank thes rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank)
{
    // Check to make sure our ctor worked ok
    mrs04_data<MC> l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS04 data from attributes", mss::c_str(i_target) );
    FAPI_TRY( mrs04(i_target, l_data, io_inst, i_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs04_decode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_max_pd_mode the maximum power down mode setting
/// @param[out] o_temp_refresh_range the temperature controlled refresh range setting
/// @param[out] o_temp_ref_mode the temperature controlled refresh mode setting
/// @param[out] o_vref_mon the internal vref monitor setting
/// @param[out] o_ref_abort the self refresh abort setting
/// @param[out] o_rd_pre_train_mode the read preamble training mode setting
/// @param[out] o_rd_preamble the read preamble setting
/// @param[out] o_wr_preamble the write preamble setting
/// @param[out] o_ppr the ppr setting
/// @param[out] o_cs_cmd_latency_buffer the cs to cmd/addr latency mode setting
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs04_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_max_pd_mode,
                                      uint8_t& o_temp_refresh_range,
                                      uint8_t& o_temp_ref_mode,
                                      uint8_t& o_vref_mon,
                                      uint8_t& o_ref_abort,
                                      uint8_t& o_rd_pre_train_mode,
                                      uint8_t& o_rd_preamble,
                                      uint8_t& o_wr_preamble,
                                      uint8_t& o_ppr,
                                      uint8_t& o_soft_ppr,
                                      fapi2::buffer<uint8_t>& o_cs_cmd_latency_buffer)
{
    o_max_pd_mode = i_inst.arr0.getBit<TT::A1>();
    o_temp_refresh_range = i_inst.arr0.getBit<TT::A2>();
    o_temp_ref_mode = i_inst.arr0.getBit<TT::A3>();
    o_vref_mon = i_inst.arr0.getBit<TT::A4>();
    o_soft_ppr = i_inst.arr0.getBit<TT::A5>();

    o_cs_cmd_latency_buffer = 0;
    mss::swizzle<5, 3, TT::A8>(i_inst.arr0, o_cs_cmd_latency_buffer);

    o_ref_abort = i_inst.arr0.getBit<TT::A9>();
    o_rd_pre_train_mode = i_inst.arr0.getBit<TT::A10>();
    o_rd_preamble = i_inst.arr0.getBit<TT::A11>();
    o_wr_preamble = i_inst.arr0.getBit<TT::A12>();
    o_ppr = i_inst.arr0.getBit<TT::A13>();

    FAPI_INF("MR4 rank %d decode: MAX_PD: 0x%x, TEMP_REFRESH_RANGE: 0x%x, TEMP_REF_MODE: 0x%x "
             "VREF_MON: 0x%x, CSL: 0x%x, REF_ABORT: 0x%x, RD_PTM: 0x%x, RD_PRE: 0x%x, "
             "WR_PRE: 0x%x, PPR: 0x%x",
             i_rank, o_max_pd_mode, o_temp_refresh_range, o_temp_ref_mode,
             o_vref_mon, uint8_t(o_cs_cmd_latency_buffer), o_ref_abort,
             o_rd_pre_train_mode, o_rd_preamble, o_wr_preamble, o_ppr);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS4,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode mrs04_decode(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank)
{
    uint8_t l_max_pd_mode = 0;
    uint8_t l_temp_refresh_range = 0;
    uint8_t l_temp_ref_mode = 0;
    uint8_t l_vref_mon = 0;
    uint8_t l_ref_abort = 0;
    uint8_t l_rd_pre_train_mode = 0;
    uint8_t l_rd_preamble = 0;
    uint8_t l_wr_preamble = 0;
    uint8_t l_ppr = 0;
    uint8_t l_soft_ppr = 0;

    fapi2::buffer<uint8_t> l_cs_cmd_latency_buffer;

    return mrs04_decode_helper(i_inst, i_rank, l_max_pd_mode, l_temp_refresh_range, l_temp_ref_mode,
                               l_vref_mon, l_ref_abort, l_rd_pre_train_mode, l_rd_preamble,
                               l_wr_preamble, l_ppr, l_soft_ppr, l_cs_cmd_latency_buffer);
}


} // ns ddr4
} // ns mss
#endif
