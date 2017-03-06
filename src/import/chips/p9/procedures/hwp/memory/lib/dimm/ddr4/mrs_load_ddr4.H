/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs_load_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file mrs_load_ddr4.H
/// @brief Code to support mrs_load_ddr4
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MRS_LOAD_DDR4_H_
#define _MSS_MRS_LOAD_DDR4_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/dimm/mrs_load.H>
#include <lib/eff_config/timing.H>

namespace mss
{

// Map bits in the ARR0 register(s) to MRS address bits. Should be traits related to ARR0. BRS
enum address_bits
{
    A0 = 0,
    A1 = 1,
    A2 = 2,
    A3 = 3,
    A4 = 4,
    A5 = 5,
    A6 = 6,
    A7 = 7,
    A8 = 8,
    A9 = 9,
    A10 = 10,
    A11 = 11,
    A12 = 12,
    A13 = 13,
    A14 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_14,
    A15 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_15,
    A16 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_16,
    A17 = MCBIST_CCS_INST_ARR0_00_DDR_ADDRESS_17,

    // Only kind of address bits ... <shrug>
    BA0 = 17,
    BA1 = 18,
    BG0 = 19,
    BG1 = 15,
};

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction - implementation
/// @tparam T typename of the ccs::instruction_t
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note written this way so this is easier to test
///
template<fapi2::TargetType T>
void address_mirror_impl(ccs::instruction_t<T>& io_inst)
{
    // Nothing fancy here, just mirror the bits we're told to mirror in Table 14 — Address Mirroring and Inversion
    mss::template swap<A3, A4>(io_inst.arr0);
    mss::template swap<A5, A6>(io_inst.arr0);
    mss::template swap<A7, A8>(io_inst.arr0);
    mss::template swap<A11, A13>(io_inst.arr0);
    mss::template swap<BA0, BA1>(io_inst.arr0);
    mss::template swap<BG0, BG1>(io_inst.arr0);
}

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction
/// @tparam T typename of the ccs::instruction_t
/// @param[in] i_target target to use to get mirroring attribute
/// @param[in] i_rank the rank in question
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note assumes the input is from an even number rank
///
template<fapi2::TargetType T>
fapi2::ReturnCode address_mirror(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank,
                                 ccs::instruction_t<T>& io_inst)
{
    // We only mirror if the mirroring attribute is set.
    uint8_t l_mirror = 0;
    FAPI_TRY( eff_dimm_rcd_mirror_mode(i_target, l_mirror),
              "Failed to invoke rcd_mirror_mode accesor on %s", mss::c_str(i_target) );

    // We only mirror odd ranks.
    if ((l_mirror == fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_ON) && (i_rank & 0x1))
    {
        address_mirror_impl(io_inst);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Invert (side to side) the ADR bits of a CCS instruction
/// @param[in] i_inst const reference to a CCS instruction.
/// @return[out] ccs instruction with the ADR bits inverted (side-to-side)
///
template<fapi2::TargetType T>
ccs::instruction_t<T> address_invert(const ccs::instruction_t<T>& i_inst)
{
    // Copy the input as the output doesn't all change.
    ccs::instruction_t<T> i_out(i_inst);

    // Nothing fancy here, just negate the bits we're told to negate in Table 14 — Address Mirroring and Inversion
    mss::template negate<A3>(i_out.arr0);
    mss::template negate<A4>(i_out.arr0);
    mss::template negate<A5>(i_out.arr0);
    mss::template negate<A6>(i_out.arr0);
    mss::template negate<A7>(i_out.arr0);
    mss::template negate<A8>(i_out.arr0);
    mss::template negate<A9>(i_out.arr0);

    mss::template negate<A11>(i_out.arr0);
    mss::template negate<A13>(i_out.arr0);
    mss::template negate<A17>(i_out.arr0);

    mss::template negate<BA0>(i_out.arr0);
    mss::template negate<BA1>(i_out.arr0);
    mss::template negate<BG0>(i_out.arr0);
    mss::template negate<BG1>(i_out.arr0);

    return i_out;
}

///
/// @brief Helper function to make a CCS instruction for an MRS
/// @tparam T TargetType of the CCS instruction
/// @tparam D the mrs data structure to send out
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename D >
static inline fapi2::ReturnCode make_ccs_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const D& i_data,
        const uint64_t i_rank,
        ccs::instruction_t<T>& io_inst )
{
    FAPI_TRY( D::make_ccs_instruction(i_target, i_data, io_inst, i_rank),
              "Failed making a CCS instruction for templated MRS data. MR%d rank %d on %s",
              i_data.iv_mrs, i_rank, mss::c_str(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to make a CCS instruction for an MRS
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< >
fapi2::ReturnCode make_ccs_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const mrs_data<fapi2::TARGET_TYPE_MCBIST>& i_data,
                                   const uint64_t i_rank,
                                   ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst )
{
    FAPI_TRY( i_data.iv_func(i_target, io_inst, i_rank),
              "Failed making a CCS instruction for mrs_data<TARGET_TYPE_MCBIST> specialization. MR%d rank %d on %s",
              i_data.iv_mrs, i_rank, mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to decode MRS and trace CCS instructions
/// @tparam T TargetType of the CCS instruction
/// @tparam D the mrs data structure to send out
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in] i_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename D >
static inline fapi2::ReturnCode decode_helper(const D& i_data,
        const uint64_t i_rank,
        const ccs::instruction_t<T>& i_inst )
{
    // Dump out the 'decoded' MRS and trace the CCS instructions.
    FAPI_TRY( D::decode(i_inst, i_rank),
              "Failed dumping information for MR%d rank%d",
              i_data.iv_mrs, i_rank );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to decode MRS and trace CCS instructions
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in] i_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< >
inline fapi2::ReturnCode decode_helper(const mrs_data<fapi2::TARGET_TYPE_MCBIST>& i_data,
                                       const uint64_t i_rank,
                                       const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst )
{
    // Dump out the 'decoded' MRS and trace the CCS instructions.
    FAPI_TRY( i_data.iv_dumper(i_inst, i_rank),
              "Failed dumping information for MR%d rank%d",
              i_data.iv_mrs, i_rank );


fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up MRS CCS instructions
/// @tparam T TargetType of the CCS instruction
/// @tparam D the mrs data structure to send out
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in] i_delay_in_cycles the delay, in cycles
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename D >
fapi2::ReturnCode mrs_engine( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const D& i_data,
                              const uint64_t i_rank,
                              const uint64_t i_delay_in_cycles,
                              std::vector< ccs::instruction_t<T> >& io_inst )
{
    ccs::instruction_t<T> l_inst_a_side = ccs::mrs_command<T>(i_target, i_rank, i_data.iv_mrs);
    ccs::instruction_t<T> l_inst_b_side;

    // Thou shalt send 2 MRS, one for the a-side and the other inverted for the b-side.
    // If we're on an odd-rank then we need to mirror
    // So configure the A-side, mirror if necessary and invert for the B-side
    FAPI_TRY( make_ccs_helper(i_target, i_data, i_rank, l_inst_a_side),
              "Failed to make CCS instruction for MR%d on %s",
              i_data.iv_mrs, mss::c_str(i_target) );

    FAPI_TRY( mss::address_mirror(i_target, i_rank, l_inst_a_side),
              "Failed mirroring MR%d rank %d on %s",
              i_data.iv_mrs, i_rank, mss::c_str(i_target) );

    l_inst_b_side = mss::address_invert(l_inst_a_side);

    // Not sure if we can get tricky here and only delay after the b-side MR. The question is whether the delay
    // is needed/assumed by the register or is purely a DRAM mandated delay. We know we can't go wrong having
    // both delays but if we can ever confirm that we only need one we can fix this. BRS
    l_inst_a_side.arr1.template insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                                MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(i_delay_in_cycles);
    l_inst_b_side.arr1.template insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                                MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(i_delay_in_cycles);

    // Dump out the 'decoded' MRS and trace the CCS instructions.
    FAPI_TRY(decode_helper(i_data, i_rank, l_inst_a_side),
             "Failed to decode information for MR%d on %s",
             i_data.iv_mrs, mss::c_str(i_target) );

    FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d a-side", uint8_t(i_data.iv_mrs), i_delay_in_cycles,
             l_inst_a_side.arr0, l_inst_a_side.arr1, mss::c_str(i_target), i_rank);
    FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d b-side", uint8_t(i_data.iv_mrs), i_delay_in_cycles,
             l_inst_b_side.arr0, l_inst_b_side.arr1, mss::c_str(i_target), i_rank);

    // Add both to the CCS program
    io_inst.push_back(l_inst_a_side);
    io_inst.push_back(l_inst_b_side);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up MRS CCS instructions
/// @tparam T TargetType of the CCS instruction
/// @tparam D the mrs data structure to send out
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T, typename D >
fapi2::ReturnCode mrs_engine( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const D& i_data,
                              const uint64_t i_rank,
                              std::vector< ccs::instruction_t<T> >& io_inst );

namespace ddr4
{

// Forward declarations
class mrs00_data;
class mrs01_data;
class mrs02_data;
class mrs03_data;
class mrs04_data;
class mrs05_data;
class mrs06_data;

///
/// @defgroup setup-ccs
/// @addtogroyp setup-ccs
/// API which setup CCS instructions.
/// @{

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs00
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs01
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs02
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs03
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs04
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs05
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs06
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

/// }@

///
/// @defgroup setup-ccs-overloads
/// @addtogroyp setup-ccs-overloads
/// API which setup CCS instructions, but take an MRS data object as input
/// @{

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs00, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs00_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs01, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs01_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs01_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs02, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs02_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs02_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs03, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs03_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs04, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs04_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs04_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs05, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs05_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs05_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs06, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs06_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs06_data& i_data,
                        ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
                        const uint64_t i_rank);

/// }@

///
/// @defgroup ccs-decode
/// @addtogroyccs-decode
/// API which decode CCS instructions.
/// @{

///
/// @brief Helper function for mrs00_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_burst_length the burst length
/// @param[out] o_read_burst_type the burst type
/// @param[out] o_dll_reset the dll reset bit
/// @param[out] o_test_mode the test mode bit
/// @param[out] o_wr_index the write index
/// @param[out] o_cas_latency the cas latency
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs00_decode_helper(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_burst_length,
                                      uint8_t& o_read_burst_type,
                                      uint8_t& o_dll_reset,
                                      uint8_t& o_test_mode,
                                      fapi2::buffer<uint8_t>& o_wr_index,
                                      fapi2::buffer<uint8_t>& o_cas_latency);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS00,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs00_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs01_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_dll_enable the dll enable bit
/// @param[out] o_wrl_enable the write leveling enable bit
/// @param[out] o_tdqs the tdqs enable bit
/// @param[out] o_qoff the qoff bit
/// @param[out] o_odic the output driver impedance control setting
/// @param[out] o_additive_latency the additive latency setting
/// @param[out] o_rtt_nom the rtt_nom setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs01_decode_helper(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_dll_enable,
                                      uint8_t& o_wrl_enable,
                                      uint8_t& o_tdqs,
                                      uint8_t& o_qoff,
                                      fapi2::buffer<uint8_t>& o_odic,
                                      fapi2::buffer<uint8_t>& o_additive_latency,
                                      fapi2::buffer<uint8_t>& o_rtt_nom);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS01,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs01_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs02_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_write_crc the write crc bit
/// @param[out] o_lpasr the low power array self refresh setting
/// @param[out] o_cwl the cas write latency setting
/// @param[out] o_rtt_wr the rtt_wr setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs02_decode_helper(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_write_crc,
                                      fapi2::buffer<uint8_t>& o_lpasr,
                                      fapi2::buffer<uint8_t>& o_cwl,
                                      fapi2::buffer<uint8_t>& o_rtt_wr);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS02,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs02_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs03_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_mpr_mode the mpr operation setting
/// @param[out] o_geardown the geardown mode setting
/// @param[out] o_pda the per dram addressability setting
/// @param[out] o_temp_readout the temperature sensor readout setting
/// @param[out] o_mpr_page the mpr page selection
/// @param[out] o_fine_refresh the fine granularity refresh mode setting
/// @param[out] o_crc_wr_latency_buffer the write cmd latency when crc and dm are enabled
/// @param[out] o_read_fromat the mpr read format setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs03_decode_helper(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_mpr_mode,
                                      uint8_t& o_geardown,
                                      uint8_t& o_pda,
                                      uint8_t& o_temp_readout,
                                      fapi2::buffer<uint8_t>& o_mpr_page,
                                      fapi2::buffer<uint8_t>& o_fine_refresh,
                                      fapi2::buffer<uint8_t>& o_crc_wr_latency_buffer,
                                      fapi2::buffer<uint8_t>& o_read_format);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS03,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs03_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

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
fapi2::ReturnCode mrs04_decode_helper(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
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
                                      fapi2::buffer<uint8_t>& o_cs_cmd_latency_buffer);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS04,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs04_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs05_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
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
fapi2::ReturnCode mrs05_decode_helper(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_crc_error_clear,
                                      uint8_t& o_ca_parity_error_status,
                                      uint8_t& o_odt_input_buffer,
                                      uint8_t& o_ca_parity,
                                      uint8_t& o_data_mask,
                                      uint8_t& o_write_dbi,
                                      uint8_t& o_read_dbi,
                                      fapi2::buffer<uint8_t>& o_ca_parity_latency_buffer,
                                      fapi2::buffer<uint8_t>& o_rtt_park_buffer);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS05,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs05_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs06_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_vrefdq_train_range the vrefdq training range setting
/// @param[out] o_vrefdq_train_enable the vrefdq training enable setting
/// @param[out] o_tccd_l_buffer the tccd_l setting
/// @param[out] o_vrefdq_train_value_buffer the vrefdq training value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs06_decode_helper(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_vrefdq_train_range,
                                      uint8_t& o_vrefdq_train_enable,
                                      fapi2::buffer<uint8_t>& o_tccd_l_buffer,
                                      fapi2::buffer<uint8_t>& o_vrefdq_train_value_buffer);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS06,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs06_decode(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                               const uint64_t i_rank);

///
/// @defgroup mrs-structs
/// @addtogroup mrs-structs
// Each MRS has it's attributes encapsulated in it's little struct.
/// @{

///
/// @brief Data structure for MRS0 data
///
struct mrs00_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 0;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    // Kind of inverted; normally you'd implement this as a method of this class. But that
    // would mean pointers <sigh> as we'd have to make the IPL MRS machine's table leverage
    // dynaimc polymorphism and I avoid that where possible.
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs00_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs00_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs00_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_burst_length;
    uint8_t iv_read_burst_type;
    uint8_t iv_dll_reset;
    uint8_t iv_test_mode;
    uint8_t iv_write_recovery;
    uint8_t iv_cas_latency;
};

///
/// @brief Data structure for MRS1 data
///
struct mrs01_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 1;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs01_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs01_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs01_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_dll_enable;
    uint8_t iv_odic[MAX_RANK_PER_DIMM];
    uint8_t iv_additive_latency;
    uint8_t iv_wl_enable;
    uint8_t iv_tdqs;
    uint8_t iv_qoff;
    uint8_t iv_rtt_nom[MAX_RANK_PER_DIMM];
};

///
/// @brief Data structure for MRS2 data
///
struct mrs02_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 2;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs02_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs02_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs02_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_lpasr;
    uint8_t iv_cwl;
    uint8_t iv_write_crc;
    uint8_t iv_dram_rtt_wr[MAX_RANK_PER_DIMM];
};


///
/// @brief Data structure for MRS3 data
///
struct mrs03_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 3;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs03_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs03_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs03_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_mpr_mode;
    uint8_t iv_mpr_page;
    uint8_t iv_geardown;
    uint8_t iv_pda;
    uint8_t iv_crc_wr_latency;
    uint8_t iv_temp_readout;
    uint8_t iv_fine_refresh;
    uint8_t iv_read_format;
};

///
/// @brief Data structure for MRS4 data
///
struct mrs04_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 4;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs04_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs04_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs04_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_max_pd_mode;
    uint8_t iv_temp_refresh_range;
    uint8_t iv_temp_ref_mode;
    uint8_t iv_vref_mon;
    uint8_t iv_cs_cmd_latency;
    uint8_t iv_ref_abort;
    uint8_t iv_rd_pre_train_mode;
    uint8_t iv_rd_preamble;
    uint8_t iv_wr_preamble;
    uint8_t iv_ppr;
    uint8_t iv_soft_ppr;
};

///
/// @brief Data structure for MRS5 data
///
struct mrs05_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 5;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs05_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs05_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs05_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_ca_parity_latency;
    uint8_t iv_crc_error_clear;
    uint8_t iv_ca_parity_error_status;
    uint8_t iv_odt_input_buffer;
    uint8_t iv_ca_parity;
    uint8_t iv_data_mask;
    uint8_t iv_write_dbi;
    uint8_t iv_read_dbi;
    uint8_t iv_rtt_park[MAX_RANK_PER_DIMM];
};

///
/// @brief Data structure for MRS6 data
///
struct mrs06_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 6;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs06_data& i_data,
            ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST>& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs06_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs06_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    uint8_t iv_vrefdq_train_value[MAX_RANK_PER_DIMM];
    uint8_t iv_vrefdq_train_range[MAX_RANK_PER_DIMM];
    uint8_t iv_vrefdq_train_enable[MAX_RANK_PER_DIMM];
    uint8_t iv_tccd_l;
};

/// @}

///
/// @brief Perform the mrs_load DDR4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief  Set MPR Mode
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for MPR mode
/// @param[in,out] io_data data we are modifying MPR mode to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode set_dram_mpr_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_mode,
        mrs03_data& io_data)
{
    constexpr uint64_t MAX_MPR_MODE = 0b1;

    if(i_mode > MAX_MPR_MODE)
    {
        FAPI_ERR("Invalid MPR Mode recieved: %d. Max encoding allowed: %d.", i_mode, MAX_MPR_MODE);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Update field if input check passes
    io_data.iv_mpr_mode = i_mode;

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Set MPR Read
/// @param[in] i_target a DIMM target
/// @param[in] i_format setting for MPR read format
/// @param[in,out] io_data data we are modifying MPR mode to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode set_dram_mpr_rd_format(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_format,
        mrs03_data& io_data)
{
    constexpr uint64_t MAX_READ_FORMAT = 0b10;

    if(i_format > MAX_READ_FORMAT)
    {
        FAPI_ERR("Invalid MPR Read Format recieved: %d. Max encoding allowed: %d.", i_format, MAX_READ_FORMAT);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Update field if input check passes
    io_data.iv_read_format = i_format;

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Set MPR page
/// @param[in] i_target a DIMM target
/// @param[in] i_page setting for MPR read format
/// @param[in,out] io_data data we are modifying MPR mode to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode set_dram_mpr_page(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_page,
        mrs03_data& io_data)
{
    constexpr uint64_t MAX_PAGE = 0b11;

    if(i_page > MAX_PAGE)
    {
        FAPI_ERR("Invalid MPR Page recieved: %d. Max encoding allowed: %d.", i_page, MAX_PAGE);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Update field if input check passes
    io_data.iv_mpr_page = i_page;

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Makes CCS instruction to set MPR Mode
/// @tparam T TargetType of the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for MPR mode
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode mpr_load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const uint8_t i_mode,
                           const uint64_t i_rank,
                           std::vector< ccs::instruction_t<T> >& io_inst )
{
    // From DDR4 spec section 4.10.3 MPR Reads:
    // tMRD and tMOD must be satisfied after enabling/disabling MPR mode
    const uint64_t l_delay = std::max( mss::tmod(i_target), mss::tmrd() );

    mrs03_data l_data(i_target, fapi2::current_err);
    FAPI_TRY(fapi2::current_err, "%s. Failed to initialize mrs03_data for mpr_load", mss::c_str(i_target) );

    FAPI_TRY( set_dram_mpr_mode(i_target, i_mode, l_data),
              "%s. Failed set_dram_mpr_mode() with a setting of %d",
              mss::c_str(i_target), i_mode);

    // Make MRS CCS inst
    FAPI_TRY( mrs_engine(i_target, l_data, i_rank, l_delay, io_inst),
              "Failed to send MRS03 on %s, rank: %d, delay (in cycles): %d",
              mss::c_str(i_target), i_rank, l_delay);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction to set MPR Mode
/// @tparam T TargetType of the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for MPR mode
/// @param[in] i_rd_format MPR read format
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode mpr_load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const uint8_t i_mode,
                           const uint8_t i_rd_format,
                           const uint64_t i_rank,
                           std::vector< ccs::instruction_t<T> >& io_inst )
{
    // From DDR4 spec section 4.10.3 MPR Reads:
    // tMRD and tMOD must be satisfied after enabling/disabling MPR mode
    const uint64_t l_delay = std::max( mss::tmod(i_target), mss::tmrd() );

    mrs03_data l_data(i_target, fapi2::current_err);
    FAPI_TRY(fapi2::current_err, "%s. Failed to initialize mrs03_data for mpr_load", mss::c_str(i_target) );

    FAPI_TRY( set_dram_mpr_mode(i_target, i_mode, l_data),
              "%s. Failed set_dram_mpr_mode() with a setting of %d",
              mss::c_str(i_target), i_mode);

    FAPI_TRY( set_dram_mpr_rd_format(i_target, i_rd_format, l_data),
              "%s. Failed set_dram_mpr_rd_format() with a setting of %d",
              mss::c_str(i_target), i_rd_format);

    // Make MRS CCS inst
    FAPI_TRY( mrs_engine(i_target, l_data, i_rank, l_delay, io_inst),
              "Failed to send MRS03 on %s, rank: %d, delay (in cycles): %d",
              mss::c_str(i_target), i_rank, l_delay);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction for an MPR read
/// @tparam T TargetType of the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_mode MPR location
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode mpr_read( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            const uint64_t i_mpr_loc,
                            const uint64_t i_rank,
                            std::vector< ccs::instruction_t<T> >& io_inst )
{
    // Right now we only have support for RD and RDA
    // Unclear if we want the API select the type of read command right now
    // Note the auto precharge is ignored with MPR mode on so we just do a read cmd
    ccs::instruction_t<T> l_inst = ccs::rd_command<T> (i_target, i_rank, i_mpr_loc);

    // In MPR Mode:
    // Reads (back-to-back) from Page 0 may use tCCD_S or tCCD_L timing between read commands
    // Reads (back-to-back) from Pages 1, 2, or 3 may not use tCCD_S timing between read commands
    // tCCD_L must be used for timing between read commands
    uint8_t l_delay = 0;

    if( i_mpr_loc == 0)
    {
        // note we are truncating a uint64 to a uint8 but since
        // the value of tccd_s is always 4....we should be okay
        l_delay = mss::tccd_s();
    }
    else
    {
        FAPI_TRY(eff_dram_tccd_l(i_target, l_delay), "Failed to invoke accessor for tCCD_L");
    }

    // Input type needs to be greater than IDLES_LEN, hence the cast
    l_inst.arr1.template insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                         MCBIST_CCS_INST_ARR1_00_IDLES_LEN>(static_cast<uint64_t>(l_delay));

    FAPI_INF("MPR Read CCS inst 0x%016llx:0x%016llx %s:rank %d, MPR location:%d, delay (in cycles) %d",
             uint64_t(l_inst.arr0), uint64_t(l_inst.arr1), mss::c_str(i_target), i_rank, i_mpr_loc, l_delay);

    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction to set precharge all command
/// @tparam T TargetType of the CCS instruction
/// @param[in] i_target a DIMM target
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode precharge_all( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank,
                                 std::vector< ccs::instruction_t<T> >& io_inst )
{
    ccs::instruction_t<T> l_inst = ccs::precharge_all_command<T> (i_target, i_rank);

    // From the DDR4 Spec tRP is the precharge command period
    uint8_t l_delay = 0;
    FAPI_TRY( eff_dram_trp(i_target, l_delay) );

    // Input type needs to be greater than IDLES_LEN, hence the cast
    l_inst.arr1.template insertFromRight<MCBIST_CCS_INST_ARR1_00_IDLES,
                         MCBIST_CCS_INST_ARR1_00_IDLES_LEN>( static_cast<uint64_t>(l_delay));

    FAPI_INF("precharge_all CCS inst 0x%016llx:0x%016llx %s:rank %d, delay (in cycles) %d",
             uint64_t(l_inst.arr0), uint64_t(l_inst.arr1), mss::c_str(i_target), i_rank, l_delay);

    // Add to CCS program
    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

} // ddr4
} // mss
#endif
