/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs02.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
/// @file mrs02.H
/// @brief Run and manage the DDR4 MRS02 loading
///
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR4_MRS02_H_
#define _GENERIC_DDR4_MRS02_H_

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
/// @brief Configure the ARR0 of the CCS instruction for mrs02, data object as input
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @tparam MRS traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs02_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC, typename TT = ccsTraits<MC>, typename MRS = mrsTraits<MC> >
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs02_data<MC>& i_data,
                        ccs::instruction_t<MC>& io_inst,
                        const uint64_t i_port_rank)
{
    constexpr uint64_t CWL_LENGTH = 3;
    constexpr uint64_t CWL_START = 7;
    constexpr uint64_t LPASR_LENGTH = 2;
    constexpr uint64_t LPASR_START = 7;
    constexpr uint64_t RTT_WR_LENGTH = 3;
    constexpr uint64_t RTT_WR_START = 7;

    // Index this by subtracting 9 from the CWL attribute value. The table maps CWL attribute value
    // (in clks) to the bit setting in MR2. See the table in the JEDEC spec for the mapping.
    constexpr uint64_t LOWEST_CWL = 9;
    constexpr uint64_t CWL_COUNT = 12;
    //                                          9     10     11     12        14         16       18        20
    constexpr uint8_t cwl_map[CWL_COUNT] = { 0b000, 0b001, 0b010, 0b011, 0, 0b100, 0, 0b101, 0, 0b110, 0, 0b111 };

    fapi2::buffer<uint8_t> l_cwl_buffer;

    // Ensures our rank is inbounds for the attribute array
    const auto l_dimm_rank = mss::index(i_port_rank);
    FAPI_ASSERT(l_dimm_rank < MAX_RANK_PER_DIMM,
                fapi2::MSS_INVALID_RANK()
                .set_PORT_TARGET(mss::find_target<MRS::PORT_TARGET_TYPE>(i_target))
                .set_RANK(i_port_rank)
                .set_FUNCTION(generic_ffdc_codes::MRS01_GEN),
                "%s MRS01 rank out of bounds rank%u", mss::c_str(i_target), i_port_rank);

    {
        fapi2::buffer<uint8_t> l_rtt_wr_buffer = i_data.iv_dram_rtt_wr[l_dimm_rank];

        FAPI_ASSERT((i_data.iv_cwl >= LOWEST_CWL) && (i_data.iv_cwl < (LOWEST_CWL + CWL_COUNT)),
                    fapi2::MSS_BAD_MR_PARAMETER()
                    .set_MR_NUMBER(2)
                    .set_PARAMETER(CAS_WRITE_LATENCY)
                    .set_PARAMETER_VALUE(i_data.iv_cwl)
                    .set_DIMM_IN_ERROR(i_target),
                    "Bad value for CWL: %d (%s)", i_data.iv_cwl, mss::c_str(i_target));

        l_cwl_buffer = cwl_map[i_data.iv_cwl - LOWEST_CWL];


        // Printed here as opposed to the ctor as it uses the rank information
        FAPI_INF_NO_SBE("%s MR2 rank %d attributes: LPASR: 0x%x, CWL: 0x%x, RTT_WR: 0x%x(0x%x), WRITE_CRC: 0x%x",
                        mss::c_str(i_target), i_port_rank, uint8_t(i_data.iv_lpasr), i_data.iv_cwl,
                        uint8_t(l_cwl_buffer), uint8_t(l_rtt_wr_buffer), i_data.iv_write_crc);

        mss::swizzle<TT::A3, CWL_LENGTH, CWL_START>(l_cwl_buffer, io_inst.arr0);

        mss::swizzle<TT::A6, LPASR_LENGTH, LPASR_START>(fapi2::buffer<uint8_t>(i_data.iv_lpasr), io_inst.arr0);

        mss::swizzle<TT::A9, RTT_WR_LENGTH, RTT_WR_START>(l_rtt_wr_buffer, io_inst.arr0);

        io_inst.arr0.template writeBit<TT::A12>(i_data.iv_write_crc);

        FAPI_INF_NO_SBE("MR2: 0x%016llx", uint64_t(io_inst.arr0));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs02
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC >
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<MC>& io_inst,
                        const uint64_t i_port_rank)
{
    // Check to make sure our ctor worked ok
    mrs02_data<MC> l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err,
              "%s Unable to construct MRS02 data from attributes",
              mss::c_str(i_target) );
    FAPI_TRY( mrs02(i_target, l_data, io_inst, i_port_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs02_decode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank the rank in question
/// @param[out] o_write_crc the write crc bit
/// @param[out] o_lpasr the low power array self refresh setting
/// @param[out] o_cwl the cas write latency setting
/// @param[out] o_rtt_wr the rtt_wr setting
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs02_decode_helper(const ccs::instruction_t<MC>& i_inst,
                                      const uint64_t i_port_rank,
                                      uint8_t& o_write_crc,
                                      fapi2::buffer<uint8_t>& o_lpasr,
                                      fapi2::buffer<uint8_t>& o_cwl,
                                      fapi2::buffer<uint8_t>& o_rtt_wr)
{
    o_lpasr = 0;
    o_cwl = 0;
    o_rtt_wr = 0;

    o_write_crc = i_inst.arr0.template getBit<TT::A12>();
    mss::swizzle<5, 3, TT::A5>(i_inst.arr0, o_cwl);
    mss::swizzle<6, 2, TT::A7>(i_inst.arr0, o_lpasr);
    mss::swizzle<5, 3, TT::A11>(i_inst.arr0, o_rtt_wr);

    FAPI_INF_NO_SBE("MR2 rank %d deocode: LPASR: 0x%x, CWL: 0x%x, RTT_WR: 0x%x, WRITE_CRC: 0x%x",
                    i_port_rank, uint8_t(o_lpasr), uint8_t(o_cwl), uint8_t(o_rtt_wr), o_write_crc);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS2,
/// decode and trace the contents
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC >
inline fapi2::ReturnCode mrs02_decode(const ccs::instruction_t<MC>& i_inst,
                                      const uint64_t i_port_rank)
{
    uint8_t l_write_crc = 0;
    fapi2::buffer<uint8_t> l_lpasr;
    fapi2::buffer<uint8_t> l_cwl;
    fapi2::buffer<uint8_t> l_rtt_wr;

    return mrs02_decode_helper(i_inst, i_port_rank, l_write_crc, l_lpasr, l_cwl, l_rtt_wr);
}

} // ns ddr4

} // ns mss
#endif
