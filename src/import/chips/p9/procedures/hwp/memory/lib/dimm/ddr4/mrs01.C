/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs01.C $ */
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
/// @file mrs01.C
/// @brief Run and manage the DDR4 MRS01 loading
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
/// @brief mrs01_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
mrs01_data::mrs01_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc ):
    iv_dll_enable(fapi2::ENUM_ATTR_EFF_DRAM_DLL_ENABLE_YES),
    iv_additive_latency(0),
    iv_wl_enable(0),
    iv_tdqs(0),
    iv_qoff(0)
{
    FAPI_TRY( mss::eff_dram_dll_enable(i_target, iv_dll_enable) );
    FAPI_TRY( mss::vpd_mt_dram_drv_imp_dq_dqs(i_target, &(iv_odic[0])) );
    FAPI_TRY( mss::eff_dram_al(i_target, iv_additive_latency) );
    FAPI_TRY( mss::eff_dram_wr_lvl_enable(i_target, iv_wl_enable) );
    FAPI_TRY( mss::vpd_mt_dram_rtt_nom(i_target, &(iv_rtt_nom[0])) );
    FAPI_TRY( mss::eff_dram_tdqs(i_target, iv_tdqs) );
    FAPI_TRY( mss::eff_dram_output_buffer(i_target, iv_qoff) );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("unable to get attributes for mrs0");
    return;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs01
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
    // Check to make sure our ctor worked ok
    mrs01_data l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "Unable to construct MRS01 data from attributes");
    FAPI_TRY( mrs01(i_target, l_data, io_inst, i_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs01, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs01_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs01_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
    // Little table to map Output Driver Imepdance Control. 34Ohm is index 0,
    // 48Ohm is index 1
    // Left bit is A2, right bit is A1
    constexpr uint8_t odic_map[2] = { 0b00, 0b01 };

    // Indexed by denominator. So, if RQZ is 240, and you have OHM240, then you're looking
    // for index 1. So this doesn't correspond directly with the table in the JEDEC spec,
    // as that's not in "denominator order."
    //                                   0  RQZ/1  RQZ/2  RQZ/3  RQZ/4  RQZ/5  RQZ/6  RQZ/7
    constexpr uint8_t rtt_nom_map[8] = { 0, 0b100, 0b010, 0b110, 0b001, 0b101, 0b011, 0b111 };

    size_t l_rtt_nom_index = 0;

    fapi2::buffer<uint8_t> l_additive_latency;
    fapi2::buffer<uint8_t> l_odic_buffer;
    fapi2::buffer<uint8_t> l_rtt_nom_buffer;

    FAPI_ASSERT( ((i_data.iv_odic[mss::index(i_rank)] == fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM34) ||
                  (i_data.iv_odic[mss::index(i_rank)] == fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM48)),
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(1)
                 .set_PARAMETER(OUTPUT_IMPEDANCE)
                 .set_PARAMETER_VALUE(i_data.iv_odic[mss::index(i_rank)])
                 .set_DIMM_IN_ERROR(i_target),
                 "Bad value for output driver impedance: %d (%s)", i_data.iv_odic[mss::index(i_rank)], mss::c_str(i_target));

    // Map from impedance to bits in MRS1
    l_odic_buffer = (i_data.iv_odic[mss::index(i_rank)] == fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS_OHM34) ?
                    odic_map[0] : odic_map[1];

    // We have to be careful about 0
    l_rtt_nom_index = (i_data.iv_rtt_nom[mss::index(i_rank)] == 0) ?
                      0 : fapi2::ENUM_ATTR_MSS_VPD_MT_DRAM_RTT_NOM_OHM240 / i_data.iv_rtt_nom[mss::index(i_rank)];

    // Map from RTT_NOM array to the value in the map
    l_rtt_nom_buffer = rtt_nom_map[l_rtt_nom_index];

    // Print this here as opposed to the MRS01 ctor as we want to see the specific rtt now information
    FAPI_INF("MR1 rank %d attributes: DLL_ENABLE: 0x%x, ODIC: 0x%x(0x%x), AL: 0x%x, WLE: 0x%x, "
             "RTT_NOM: 0x%x(0x%x), TDQS: 0x%x, QOFF: 0x%x", i_rank,
             i_data.iv_dll_enable, i_data.iv_odic[mss::index(i_rank)], uint8_t(l_odic_buffer), uint8_t(l_additive_latency),
             i_data.iv_wl_enable,
             i_data.iv_rtt_nom[mss::index(i_rank)], uint8_t(l_rtt_nom_buffer), i_data.iv_tdqs, i_data.iv_qoff);

    io_inst.arr0.writeBit<A0>(i_data.iv_dll_enable);
    mss::swizzle<A1, 2, 7>(l_odic_buffer, io_inst.arr0);
    mss::swizzle<A3, 2, 7>(fapi2::buffer<uint8_t>(i_data.iv_additive_latency), io_inst.arr0);
    io_inst.arr0.writeBit<A7>(i_data.iv_wl_enable);
    mss::swizzle<A8, 3, 7>(l_rtt_nom_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A11>(i_data.iv_tdqs);
    io_inst.arr0.writeBit<A12>(i_data.iv_qoff);

    FAPI_INF("MR1: 0x%016llx", uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs01_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @param[out] o_dll_enable the dll enable bit
/// @param[out] o_wrl_enable the write leveling enable bit
/// @param[out] o_tdqs the tdqs enable bit
/// @param[out] o_qoff the qoff bit
/// @param[out] o_odic the output driver impedance control setting
/// @param[out] o_additive_latency the additive latency setting
/// @param[out] o_rtt_nom the rtt_nom setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs01_decode_helper(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_dll_enable,
                                      uint8_t& o_wrl_enable,
                                      uint8_t& o_tdqs,
                                      uint8_t& o_qoff,
                                      fapi2::buffer<uint8_t>& o_odic,
                                      fapi2::buffer<uint8_t>& o_additive_latency,
                                      fapi2::buffer<uint8_t>& o_rtt_nom)
{
    o_odic = 0;
    o_additive_latency = 0;
    o_rtt_nom = 0;

    o_dll_enable = i_inst.arr0.getBit<A0>();
    o_wrl_enable = i_inst.arr0.getBit<A7>();
    o_tdqs = i_inst.arr0.getBit<A11>();
    o_qoff = i_inst.arr0.getBit<A12>();

    mss::swizzle<6, 2, A2>(i_inst.arr0, o_odic);
    mss::swizzle<6, 2, A4>(i_inst.arr0, o_additive_latency);
    mss::swizzle<5, 3, A10>(i_inst.arr0, o_rtt_nom);

    FAPI_INF("MR1 rank %d decode: DLL_ENABLE: 0x%x, ODIC: 0x%x, AL: 0x%x, WLE: 0x%x, "
             "RTT_NOM: 0x%x, TDQS: 0x%x, QOFF: 0x%x", i_rank,
             o_dll_enable, uint8_t(o_odic), uint8_t(o_additive_latency), o_wrl_enable, uint8_t(o_rtt_nom),
             o_tdqs, o_qoff);

    return FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS1,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs01_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank)
{
    uint8_t l_dll_enable = 0;
    uint8_t l_wrl_enable = 0;
    uint8_t l_tdqs = 0;
    uint8_t l_qoff = 0;
    fapi2::buffer<uint8_t> l_odic;
    fapi2::buffer<uint8_t> l_additive_latency;
    fapi2::buffer<uint8_t> l_rtt_nom;

    return mrs01_decode_helper(i_inst, i_rank, l_dll_enable, l_wrl_enable, l_tdqs, l_qoff, l_odic,
                               l_additive_latency, l_rtt_nom);
}

fapi2::ReturnCode (*mrs01_data::make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs01_data& i_data,
        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
        const uint64_t i_rank) = &mrs01;

fapi2::ReturnCode (*mrs01_data::decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                        const uint64_t i_rank) = &mrs01_decode;

} // ns ddr4

} // ns mss
