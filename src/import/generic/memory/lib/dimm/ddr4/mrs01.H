/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs01.H $             */
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
/// @file mrs01.H
/// @brief Run and manage the DDR4 MRS01 loading
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR4_MRS01_H_
#define _GENERIC_DDR4_MRS01_H_

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
/// @brief Helper function to decode ODIC to the MRS value
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_odic_value the value to be decoded for ODIC
/// @param[out] o_odic_decode the MRS decoded value for ODIC
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC >
fapi2::ReturnCode odic_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const uint8_t i_odic_value,
                              fapi2::buffer<uint8_t>& o_odic_decode);


///
/// @brief Configure the ARR0 of the CCS instruction for mrs01, data object as input
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @tparam MRS traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs01_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>, typename MRS = mrsTraits<MC> >
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs01_data<MC>& i_data,
                        ccs::instruction_t<MC>& io_inst,
                        const uint64_t i_port_rank)
{
    constexpr uint64_t ODIC_LENGTH = 2;
    constexpr uint64_t ODIC_START_BIT = 7;
    constexpr uint64_t ADDITIVE_LATENCE_LENGTH = 2;
    constexpr uint64_t ADDITIVE_LATENCE_START_BIT = 7;
    constexpr uint64_t RTT_NOM_LENGTH = 3;
    constexpr uint64_t RTT_NOM_START_BIT = 7;


    fapi2::buffer<uint8_t> l_additive_latency;
    fapi2::buffer<uint8_t> l_odic_buffer;
    fapi2::buffer<uint8_t> l_rtt_nom_buffer;

    // check here to make sure the rank indexes correctly into the attribute array
    // It's equivalent to mss::index(i_port_rank) < l_rtt_nom.size() if C arrays had a .size() method
    const auto l_dimm_rank = mss::index(i_port_rank);
    FAPI_ASSERT(l_dimm_rank < MAX_RANK_PER_DIMM,
                fapi2::MSS_INVALID_RANK()
                .set_PORT_TARGET(mss::find_target<MRS::PORT_TARGET_TYPE>(i_target))
                .set_RANK(i_port_rank)
                .set_FUNCTION(generic_ffdc_codes::MRS01_GEN),
                "%s MRS01 rank out of bounds rank%u", mss::c_str(i_target), i_port_rank);

    // ODIC decode
    FAPI_TRY(odic_helper<MC>(i_target, i_data.iv_odic[l_dimm_rank], l_odic_buffer));

    // Map from RTT_NOM array to the value in the map
    l_rtt_nom_buffer = i_data.iv_rtt_nom[l_dimm_rank];

    // Print this here as opposed to the MRS01 ctor as we want to see the specific rtt now information
    FAPI_INF("%s MR1 rank %d attributes: DLL_ENABLE: 0x%x, ODIC: 0x%x(0x%x), AL: 0x%x, WLE: 0x%x, "
             "RTT_NOM:0x%x, TDQS: 0x%x, QOFF: 0x%x",
             mss::c_str(i_target), i_port_rank, i_data.iv_dll_enable,
             i_data.iv_odic[l_dimm_rank], uint8_t(l_odic_buffer),
             uint8_t(l_additive_latency), i_data.iv_wl_enable,
             uint8_t(l_rtt_nom_buffer), i_data.iv_tdqs, i_data.iv_qoff);

    io_inst.arr0.template writeBit<TT::A0>(i_data.iv_dll_enable);
    mss::swizzle<TT::A1, ODIC_LENGTH, ODIC_START_BIT>(l_odic_buffer, io_inst.arr0);
    mss::swizzle<TT::A3, ADDITIVE_LATENCE_LENGTH, ADDITIVE_LATENCE_START_BIT>(fapi2::buffer<uint8_t>
            (i_data.iv_additive_latency), io_inst.arr0);
    io_inst.arr0.template writeBit<TT::A7>(i_data.iv_wl_enable);
    mss::swizzle<TT::A8, RTT_NOM_LENGTH, RTT_NOM_START_BIT>(l_rtt_nom_buffer, io_inst.arr0);
    io_inst.arr0.template writeBit<TT::A11>(i_data.iv_tdqs);
    io_inst.arr0.template writeBit<TT::A12>(i_data.iv_qoff);

    FAPI_INF("%s MR1: 0x%016llx", mss::c_str(i_target), uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs01
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<MC>& io_inst,
                        const uint64_t i_port_rank)
{
    // Check to make sure our ctor worked ok
    mrs01_data<MC> l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS01 data from attributes", mss::c_str(i_target) );
    FAPI_TRY( mrs01(i_target, l_data, io_inst, i_port_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs01_decode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank ths rank in question
/// @param[out] o_dll_enable the dll enable bit
/// @param[out] o_wrl_enable the write leveling enable bit
/// @param[out] o_tdqs the tdqs enable bit
/// @param[out] o_qoff the qoff bit
/// @param[out] o_odic the output driver impedance control setting
/// @param[out] o_additive_latency the additive latency setting
/// @param[out] o_rtt_nom the rtt_nom setting
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs01_decode_helper(const ccs::instruction_t<MC>& i_inst,
                                      const uint64_t i_port_rank,
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

    o_dll_enable = i_inst.arr0.template getBit<TT::A0>();
    o_wrl_enable = i_inst.arr0.template getBit<TT::A7>();
    o_tdqs = i_inst.arr0.template getBit<TT::A11>();
    o_qoff = i_inst.arr0.template getBit<TT::A12>();

    mss::swizzle<6, 2, TT::A2>(i_inst.arr0, o_odic);
    mss::swizzle<6, 2, TT::A4>(i_inst.arr0, o_additive_latency);
    mss::swizzle<5, 3, TT::A10>(i_inst.arr0, o_rtt_nom);

    FAPI_INF("MR1 rank %d decode: DLL_ENABLE: 0x%x, ODIC: 0x%x, AL: 0x%x, WLE: 0x%x, "
             "RTT_NOM: 0x%x, TDQS: 0x%x, QOFF: 0x%x",
             i_port_rank, o_dll_enable, uint8_t(o_odic), uint8_t(o_additive_latency),
             o_wrl_enable, uint8_t(o_rtt_nom), o_tdqs, o_qoff);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS1,
/// decode and trace the contents
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
inline fapi2::ReturnCode mrs01_decode(const ccs::instruction_t<MC>& i_inst,
                                      const uint64_t i_port_rank)
{
    uint8_t l_dll_enable = 0;
    uint8_t l_wrl_enable = 0;
    uint8_t l_tdqs = 0;
    uint8_t l_qoff = 0;
    fapi2::buffer<uint8_t> l_odic;
    fapi2::buffer<uint8_t> l_additive_latency;
    fapi2::buffer<uint8_t> l_rtt_nom;

    return mrs01_decode_helper(i_inst, i_port_rank, l_dll_enable, l_wrl_enable, l_tdqs, l_qoff, l_odic,
                               l_additive_latency, l_rtt_nom);
}


} // ns ddr4

} // ns mss
#endif
