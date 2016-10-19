/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs04.C $ */
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
/// @file mrs04.C
/// @brief Run and manage the DDR4 MRS04 loading
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
/// @brief mrs04_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
mrs04_data::mrs04_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc ):
    iv_max_pd_mode(fapi2::ENUM_ATTR_EFF_MAX_POWERDOWN_MODE_DISABLE),
    iv_temp_refresh_range(fapi2::ENUM_ATTR_MSS_MRW_TEMP_REFRESH_RANGE_NORMAL),
    iv_temp_ref_mode(fapi2::ENUM_ATTR_EFF_TEMP_REFRESH_MODE_DISABLE),
    iv_vref_mon(fapi2::ENUM_ATTR_EFF_INTERNAL_VREF_MONITOR_DISABLE),
    iv_cs_cmd_latency(fapi2::ENUM_ATTR_EFF_CS_CMD_LATENCY_DISABLE),
    iv_ref_abort(fapi2::ENUM_ATTR_EFF_SELF_REF_ABORT_DISABLE),
    iv_rd_pre_train_mode(fapi2::ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE),
    iv_rd_preamble(fapi2::ENUM_ATTR_EFF_RD_PREAMBLE_TRAIN_DISABLE),
    iv_wr_preamble(fapi2::ENUM_ATTR_EFF_RD_PREAMBLE_1NCLK),
    iv_ppr(fapi2::ENUM_ATTR_EFF_DRAM_PPR_NOT_SUPPORTED)
{
    FAPI_TRY( mss::eff_max_powerdown_mode(i_target, iv_max_pd_mode) );
    FAPI_TRY( mss::mrw_temp_refresh_range(iv_temp_refresh_range) );
    FAPI_TRY( mss::eff_temp_refresh_mode(i_target, iv_temp_ref_mode) );
    FAPI_TRY( mss::eff_internal_vref_monitor(i_target, iv_vref_mon) );
    FAPI_TRY( mss::eff_cs_cmd_latency(i_target, iv_cs_cmd_latency) );
    FAPI_TRY( mss::eff_self_ref_abort(i_target, iv_ref_abort) );
    FAPI_TRY( mss::eff_rd_preamble_train(i_target, iv_rd_pre_train_mode) );
    FAPI_TRY( mss::eff_rd_preamble(i_target, iv_rd_preamble) );
    FAPI_TRY( mss::eff_wr_preamble(i_target, iv_wr_preamble) );
    FAPI_TRY( mss::eff_dram_ppr(i_target, iv_ppr) );

    FAPI_INF("MR4 attributes: MAX_PD: 0x%x, TEMP_REFRESH_RANGE: 0x%x, TEMP_REF_MODE: 0x%x "
             "VREF_MON: 0x%x, CSL: 0x%x, REF_ABORT: 0x%x, RD_PTM: 0x%x, RD_PRE: 0x%x, "
             "WR_PRE: 0x%x, PPR: 0x%x",
             iv_max_pd_mode, iv_temp_refresh_range, iv_temp_ref_mode, iv_vref_mon,
             iv_cs_cmd_latency, iv_ref_abort,
             iv_rd_pre_train_mode, iv_rd_preamble, iv_wr_preamble, iv_ppr);

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("unable to get attributes for mrs0");
    return;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs04
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank thes rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
    // Check to make sure our ctor worked ok
    mrs04_data l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "Unable to construct MRS04 data from attributes");
    FAPI_TRY( mrs04(i_target, l_data, io_inst, i_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs04, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs04_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs04_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
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

    io_inst.arr0.writeBit<A1>(i_data.iv_max_pd_mode);
    io_inst.arr0.writeBit<A2>(i_data.iv_temp_refresh_range);
    io_inst.arr0.writeBit<A3>(i_data.iv_temp_ref_mode);
    io_inst.arr0.writeBit<A4>(i_data.iv_vref_mon);

    mss::swizzle<A6, 3, 7>(l_cs_cmd_latency_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A9>(i_data.iv_ref_abort);
    io_inst.arr0.writeBit<A10>(i_data.iv_rd_pre_train_mode);
    io_inst.arr0.writeBit<A11>(i_data.iv_rd_preamble);
    io_inst.arr0.writeBit<A12>(i_data.iv_wr_preamble);
    io_inst.arr0.writeBit<A13>(i_data.iv_ppr);

    FAPI_INF("MR4: 0x%016llx", uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs04_decode
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
fapi2::ReturnCode mrs04_decode_helper(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
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
                                      fapi2::buffer<uint8_t>& o_cs_cmd_latency_buffer)
{
    o_max_pd_mode = i_inst.arr0.getBit<A1>();
    o_temp_refresh_range = i_inst.arr0.getBit<A2>();
    o_temp_ref_mode = i_inst.arr0.getBit<A3>();
    o_vref_mon = i_inst.arr0.getBit<A4>();

    o_cs_cmd_latency_buffer = 0;
    mss::swizzle<5, 3, A8>(i_inst.arr0, o_cs_cmd_latency_buffer);

    o_ref_abort = i_inst.arr0.getBit<A9>();
    o_rd_pre_train_mode = i_inst.arr0.getBit<A10>();
    o_rd_preamble = i_inst.arr0.getBit<A11>();
    o_wr_preamble = i_inst.arr0.getBit<A12>();
    o_ppr = i_inst.arr0.getBit<A13>();

    FAPI_INF("MR4 rank %d decode: MAX_PD: 0x%x, TEMP_REFRESH_RANGE: 0x%x, TEMP_REF_MODE: 0x%x "
             "VREF_MON: 0x%x, CSL: 0x%x, REF_ABORT: 0x%x, RD_PTM: 0x%x, RD_PRE: 0x%x, "
             "WR_PRE: 0x%x, PPR: 0x%x", i_rank,
             o_max_pd_mode, o_temp_refresh_range, o_temp_ref_mode, o_vref_mon,
             uint8_t(o_cs_cmd_latency_buffer), o_ref_abort,
             o_rd_pre_train_mode, o_rd_preamble, o_wr_preamble, o_ppr);

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS4,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs04_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
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

    fapi2::buffer<uint8_t> l_cs_cmd_latency_buffer;

    return mrs04_decode_helper(i_inst, i_rank, l_max_pd_mode, l_temp_refresh_range, l_temp_ref_mode,
                               l_vref_mon, l_ref_abort, l_rd_pre_train_mode, l_rd_preamble,
                               l_wr_preamble, l_ppr, l_cs_cmd_latency_buffer);
}

fapi2::ReturnCode (*mrs04_data::make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs04_data& i_data,
        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
        const uint64_t i_rank) = &mrs04;

fapi2::ReturnCode (*mrs04_data::decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                        const uint64_t i_rank) = &mrs04_decode;

} // ns ddr4
} // ns mss
