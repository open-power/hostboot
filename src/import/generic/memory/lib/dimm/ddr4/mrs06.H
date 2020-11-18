/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs06.H $             */
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
/// @file mrs06.H
/// @brief Run and manage the DDR4 MRS06 loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR4_MRS06_H_
#define _GENERIC_DDR4_MRS06_H_

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
/// @brief Configure the ARR0 of the CCS instruction for mrs06, data object as input
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @tparam MRS traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs06_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>, typename MRS = mrsTraits<MC> >
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs06_data<MC>& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank)
{
    constexpr uint64_t VREFDQ_TRAIN_LENGTH = 6;
    constexpr uint64_t VREFDQ_TRAIN_START = 7;
    constexpr uint64_t TCCD_L_LENGTH = 3;
    constexpr uint64_t TCCD_L_START = 7;

    constexpr uint64_t LOWEST_TCCD = 4;
    constexpr uint64_t TCCD_COUNT = 5;
    //                                             4      5     6      7       8
    constexpr uint8_t tccd_l_map[TCCD_COUNT] = { 0b000, 0b001, 0b010, 0b011, 0b100 };

    fapi2::buffer<uint8_t> l_tccd_l_buffer;
    fapi2::buffer<uint8_t> l_vrefdq_train_value_buffer;

    FAPI_ASSERT((i_data.iv_tccd_l >= LOWEST_TCCD) && (i_data.iv_tccd_l < (LOWEST_TCCD + TCCD_COUNT)),
                fapi2::MSS_BAD_MR_PARAMETER()
                .set_MR_NUMBER(6)
                .set_PARAMETER(TCCD)
                .set_PARAMETER_VALUE(i_data.iv_tccd_l)
                .set_DIMM_IN_ERROR(i_target),
                "Bad value for TCCD: %d (%s)",
                i_data.iv_tccd_l,
                mss::c_str(i_target));

    l_tccd_l_buffer = tccd_l_map[i_data.iv_tccd_l - LOWEST_TCCD];
    l_vrefdq_train_value_buffer = i_data.iv_vrefdq_train_value[mss::index(i_rank)];

    FAPI_INF("%s MR6 rank %d attributes: TRAIN_V: 0x%x(0x%x), TRAIN_R: 0x%x, TRAIN_E: 0x%x, TCCD_L: 0x%x(0x%x)",
             mss::c_str(i_target), i_rank, i_data.iv_vrefdq_train_value[mss::index(i_rank)],
             uint8_t(l_vrefdq_train_value_buffer), i_data.iv_vrefdq_train_range[mss::index(i_rank)],
             i_data.iv_vrefdq_train_enable[mss::index(i_rank)], i_data.iv_tccd_l, uint8_t(l_tccd_l_buffer));

    mss::swizzle<TT::A0, VREFDQ_TRAIN_LENGTH, VREFDQ_TRAIN_START>(l_vrefdq_train_value_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<TT::A6>(i_data.iv_vrefdq_train_range[mss::index(i_rank)]);
    io_inst.arr0.writeBit<TT::A7>(i_data.iv_vrefdq_train_enable[mss::index(i_rank)]);
    mss::swizzle<TT::A10, TCCD_L_LENGTH, TCCD_L_START>(l_tccd_l_buffer, io_inst.arr0);

    FAPI_INF("%s MR6: 0x%016llx", mss::c_str(i_target), uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs06
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank)
{
    // Check to make sure our ctor worked ok
    mrs06_data<MC> l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS06 data from attributes", mss::c_str(i_target) );
    FAPI_TRY( mrs06(i_target, l_data, io_inst, i_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs06_decode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_vrefdq_train_range the vrefdq training range setting
/// @param[out] o_vrefdq_train_enable the vrefdq training enable setting
/// @param[out] o_tccd_l_buffer the tccd_l setting
/// @param[out] o_vrefdq_train_value_buffer the vrefdq training value
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs06_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_vrefdq_train_range,
                                      uint8_t& o_vrefdq_train_enable,
                                      fapi2::buffer<uint8_t>& o_tccd_l_buffer,
                                      fapi2::buffer<uint8_t>& o_vrefdq_train_value_buffer)
{
    o_tccd_l_buffer = 0;
    o_vrefdq_train_value_buffer = 0;

    mss::swizzle<2, 6, TT::A5>(i_inst.arr0, o_vrefdq_train_value_buffer);
    o_vrefdq_train_range = i_inst.arr0.getBit<TT::A6>();
    o_vrefdq_train_enable = i_inst.arr0.getBit<TT::A7>();
    mss::swizzle<5, 3, TT::A12>(i_inst.arr0, o_tccd_l_buffer);

    FAPI_INF("MR6 rank %d decode: TRAIN_V: 0x%x, TRAIN_R: 0x%x, TRAIN_E: 0x%x, TCCD_L: 0x%x",
             i_rank, uint8_t(o_vrefdq_train_value_buffer), o_vrefdq_train_range,
             o_vrefdq_train_enable, uint8_t(o_tccd_l_buffer));

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS6,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode mrs06_decode(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_tccd_l_buffer;
    fapi2::buffer<uint8_t> l_vrefdq_train_value_buffer;
    uint8_t l_vrefdq_train_range = 0;
    uint8_t l_vrefdq_train_enable = 0;

    return mrs06_decode_helper(i_inst, i_rank, l_vrefdq_train_range, l_vrefdq_train_enable,
                               l_tccd_l_buffer, l_vrefdq_train_value_buffer);
}


} // ns ddr4
} // ns mss
#endif
