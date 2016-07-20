/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs06.C $ */
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
/// @file mrs06.C
/// @brief Run and manage the DDR4 MRS06 loading
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
/// @brief mrs06_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
mrs06_data::mrs06_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc ):
    iv_tccd_l(0)
{
    FAPI_TRY( mss::eff_vref_dq_train_value(i_target, &(iv_vrefdq_train_value[0])) );
    FAPI_TRY( mss::eff_vref_dq_train_range(i_target, &(iv_vrefdq_train_range[0])) );
    FAPI_TRY( mss::eff_vref_dq_train_enable(i_target, &(iv_vrefdq_train_enable[0])) );
    FAPI_TRY( mss::eff_dram_tccd_l(i_target, iv_tccd_l) );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("unable to get attributes for mrs0");
    return;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs06
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
    // Check to make sure our ctor worked ok
    mrs06_data l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "Unable to construct MRS06 data from attributes");
    FAPI_TRY( mrs06(i_target, l_data, io_inst, i_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs06, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs06_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs06_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank)
{
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
                "Bad value for TCCD: %d (%s)", i_data.iv_tccd_l, mss::c_str(i_target));

    l_tccd_l_buffer = tccd_l_map[i_data.iv_tccd_l - LOWEST_TCCD];
    l_vrefdq_train_value_buffer = i_data.iv_vrefdq_train_value[mss::index(i_rank)];

    FAPI_INF("MR6 rank %d attributes: TRAIN_V: 0x%x(0x%x), TRAIN_R: 0x%x, TRAIN_E: 0x%x, TCCD_L: 0x%x(0x%x)", i_rank,
             i_data.iv_vrefdq_train_value[mss::index(i_rank)], uint8_t(l_vrefdq_train_value_buffer),
             i_data.iv_vrefdq_train_range[mss::index(i_rank)],
             i_data.iv_vrefdq_train_enable[mss::index(i_rank)], i_data.iv_tccd_l, uint8_t(l_tccd_l_buffer));

    mss::swizzle<A0, 6, 7>(l_vrefdq_train_value_buffer, io_inst.arr0);
    io_inst.arr0.writeBit<A6>(i_data.iv_vrefdq_train_range[mss::index(i_rank)]);
    io_inst.arr0.writeBit<A7>(i_data.iv_vrefdq_train_enable[mss::index(i_rank)]);
    mss::swizzle<A10, 3, 7>(l_tccd_l_buffer, io_inst.arr0);

    FAPI_INF("MR6: 0x%016llx", uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS6,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank ths rank in question
/// @return void
///
fapi2::ReturnCode mrs06_decode(const ccs::instruction_t<TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank)
{
    fapi2::buffer<uint8_t> l_tccd_l_buffer;
    fapi2::buffer<uint8_t> l_vrefdq_train_value_buffer;

    mss::swizzle<2, 6, A5>(i_inst.arr0, l_vrefdq_train_value_buffer);
    uint8_t l_vrefdq_train_range = i_inst.arr0.getBit<A6>();
    uint8_t l_vrefdq_train_enable = i_inst.arr0.getBit<A7>();
    mss::swizzle<5, 3, A12>(i_inst.arr0, l_tccd_l_buffer);

    FAPI_INF("MR6 rank %d decode: TRAIN_V: 0x%x, TRAIN_R: 0x%x, TRAIN_E: 0x%x, TCCD_L: 0x%x", i_rank,
             uint8_t(l_vrefdq_train_value_buffer), l_vrefdq_train_range,
             l_vrefdq_train_enable, uint8_t(l_tccd_l_buffer));

    return FAPI2_RC_SUCCESS;
}

} // ns ddr4
} // ns mss
