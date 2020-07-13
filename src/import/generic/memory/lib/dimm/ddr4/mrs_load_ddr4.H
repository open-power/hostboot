/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H $     */
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
/// @file mrs_load_ddr4.H
/// @brief Code to support mrs_load_ddr4
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _GENERIC_MRS_LOAD_DDR4_H_
#define _GENERIC_MRS_LOAD_DDR4_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/dimm/mrs_traits.H>
#include <generic/memory/lib/dimm/mrs_load.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>

namespace mss
{

// RTT_WR settings in MR2 from JEDEC DDR4 spec
enum rtt_wr_settings
{
    RTT_WR_DYNAMIC_ODT_OFF = 0b000,
    RTT_WR_RZQ_OVER_2 = 0b001,
    RTT_WR_RZQ_OVER_1 = 0b010,
    RTT_WR_HIZ = 0b011,
    RTT_WR_RZQ_OVER_3 = 0b100,
};

// RTT_NOM settings in MR1 from JEDEC DDR4 spec
enum rtt_nom_settings
{
    RTT_NOM_DISABLE = 0b000,
    RTT_NOM_RZQ_OVER_4 = 0b001,
    RTT_NOM_RZQ_OVER_2 = 0b010,
    RTT_NOM_RZQ_OVER_6 = 0b011,
    RTT_NOM_RZQ_OVER_1 = 0b100,
    RTT_NOM_RZQ_OVER_5 = 0b101,
    RTT_NOM_RZQ_OVER_3 = 0b110,
    RTT_NOM_RZQ_OVER_7 = 0b111,
};

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction - implementation
/// @tparam mc_type MC - defaults to DEFAULT_MC_TYPE
/// @tparam ccsTraits - defaults to use DEFAULT_MC_TYPE
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note written this way so this is easier to test
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>>
inline void address_mirror_impl(ccs::instruction_t& io_inst)
{
    // Nothing fancy here, just mirror the bits we're told to mirror in Table 14 Address Mirroring and Inversion
    mss::template swap<TT::A3, TT::A4>(io_inst.arr0);
    mss::template swap<TT::A5, TT::A6>(io_inst.arr0);
    mss::template swap<TT::A7, TT::A8>(io_inst.arr0);
    mss::template swap<TT::A11, TT::A13>(io_inst.arr0);
    mss::template swap<TT::BA0, TT::BA1>(io_inst.arr0);
    mss::template swap<TT::BG0, TT::BG1>(io_inst.arr0);
}

///
/// @brief Mirror (front to back) the ADR bits of a CCS instruction
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target target to use to get mirroring attribute
/// @param[in] i_rank the rank in question
/// @param[in, out] io_inst reference to a CCS instruction to be mirrored
/// @return FAPI2_RC_SUCESS iff ok
/// @note assumes the input is from an even number rank
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode address_mirror(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank,
                                 ccs::instruction_t& io_inst)
{
    // We only mirror if the mirroring attribute is set.
    uint8_t l_mirror = 0;
    FAPI_TRY( TT::mirror_mode(i_target, i_rank, l_mirror),
              "Failed to invoke rcd_mirror_mode accesor on %s", mss::c_str(i_target) );

    // We only mirror odd ranks.
    if ((l_mirror == TT::attr_mirror_mode_on()) && (i_rank & 0x1))
    {
        address_mirror_impl(io_inst);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Invert (side to side) the ADR bits of a CCS instruction
/// @tparam mc_type MC - defaults to DEFAULT_MC_TYPE
/// @tparam ccsTraits - defaults to use DEFAULT_MC_TYPE
/// @param[in] i_target the DIMM target of the ccs command
/// @param[in] i_inst const reference to a CCS instruction.
/// @param[in] l_is_a17 Boolean for whether A17 bit is enabled or not
/// @return ccs instruction with the ADR bits inverted (side-to-side)
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>>
inline ccs::instruction_t address_invert(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const ccs::instruction_t& i_inst,
        const bool i_is_a17 = false)
{
    // Copy the input as the output doesn't all change.
    ccs::instruction_t i_out(i_inst);

    // Nothing fancy here, just negate the bits we're told to negate in Table 14 Address Mirroring and Inversion
    mss::template negate<TT::A3>(i_out.arr0);
    mss::template negate<TT::A4>(i_out.arr0);
    mss::template negate<TT::A5>(i_out.arr0);
    mss::template negate<TT::A6>(i_out.arr0);
    mss::template negate<TT::A7>(i_out.arr0);
    mss::template negate<TT::A8>(i_out.arr0);
    mss::template negate<TT::A9>(i_out.arr0);

    mss::template negate<TT::A11>(i_out.arr0);
    mss::template negate<TT::A13>(i_out.arr0);

    if (i_is_a17)
    {
        FAPI_INF("%s A17 is turned on, negating CCS bit A17", mss::c_str(i_target) );
        mss::template negate<TT::A17>(i_out.arr0);
    }

    mss::template negate<TT::BA0>(i_out.arr0);
    mss::template negate<TT::BA1>(i_out.arr0);
    mss::template negate<TT::BG0>(i_out.arr0);
    mss::template negate<TT::BG1>(i_out.arr0);

    return i_out;
}

///
/// @brief Helper function to make a CCS instruction for an MRS
/// @tparam D the mrs data structure to send out
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< typename D >
inline fapi2::ReturnCode make_ccs_helper( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const D& i_data,
        const uint64_t i_rank,
        ccs::instruction_t& io_inst )
{
    FAPI_TRY( D::make_ccs_instruction(i_target, i_data, io_inst, i_rank),
              "Failed making a CCS instruction for templated MRS data. MR%d rank %d on %s",
              i_data.iv_mrs, i_rank, mss::c_str(i_target) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to decode MRS and trace CCS instructions
/// @tparam D the mrs data structure to send out
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in] i_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< typename D >
inline fapi2::ReturnCode decode_helper(const D& i_data,
                                       const uint64_t i_rank,
                                       const ccs::instruction_t& i_inst )
{
    // Dump out the 'decoded' MRS and trace the CCS instructions.
    FAPI_TRY( D::decode(i_inst, i_rank),
              "Failed dumping information for MR%d rank%d",
              i_data.iv_mrs, i_rank );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to determine whether the A17 is needed
/// @tparam mc_type MC
/// @tparam T fapi2::TargetType DIMM or port type
/// @param[in] i_target the target to check
/// @param[out] o_is_needed boolean whether A17 should be turned on or off
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Based off of Table 2.8 Proposed DDR4 Full spec update(79-4B) page 28
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode is_a17_needed(const fapi2::Target<T>& i_target,
                                bool& o_is_needed);

///
/// @brief Sets up MRS CCS instructions
/// @tparam D the mrs data structure to send out
/// @tparam mc_type MC - defaults to DEFAULT_MC_TYPE
/// @tparam ccsTraits - defaults to use DEFAULT_MC_TYPE
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in] i_delay_in_cycles the delay, in cycles
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< typename D, mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs_engine( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const D& i_data,
                              const uint64_t i_rank,
                              const uint64_t i_delay_in_cycles,
                              std::vector< ccs::instruction_t >& io_inst )
{
    ccs::instruction_t l_inst_a_side = ccs::mrs_command(i_rank, i_data.iv_mrs);
    ccs::instruction_t l_inst_b_side;
    bool l_is_a17 = false;
    bool l_has_rcd = false;

    // Thou shalt send 2 MRS, one for the a-side and the other inverted for the b-side.
    // If we're on an odd-rank then we need to mirror
    // So configure the A-side, mirror if necessary and invert for the B-side
    FAPI_TRY( make_ccs_helper(i_target, i_data, i_rank, l_inst_a_side),
              "Failed to make CCS instruction for MR%d on %s",
              i_data.iv_mrs, mss::c_str(i_target) );

    // Call traits mirroring to determine if necessary
    FAPI_TRY( mss::address_mirror(i_target, i_rank, l_inst_a_side),
              "Failed mirroring MR%d rank %d on %s",
              i_data.iv_mrs, i_rank, mss::c_str(i_target) );

    // So we need to see if the A17 bit is enabled. If it is we need to invert it for the CCS parity
    FAPI_TRY( is_a17_needed<MC>( i_target, l_is_a17) );
    l_inst_b_side = mss::address_invert(i_target, l_inst_a_side, l_is_a17);

    // Not sure if we can get tricky here and only delay after the b-side MR. The question is whether the delay
    // is needed/assumed by the register or is purely a DRAM mandated delay. We know we can't go wrong having
    // both delays but if we can ever confirm that we only need one we can fix this. BRS
    l_inst_a_side.arr1.template insertFromRight<TT::ARR1_IDLES,
                                TT::ARR1_IDLES_LEN>(i_delay_in_cycles);
    l_inst_b_side.arr1.template insertFromRight<TT::ARR1_IDLES,
                                TT::ARR1_IDLES_LEN>(i_delay_in_cycles);

    // Dump out the 'decoded' MRS and trace the CCS instructions.
    FAPI_TRY(decode_helper(i_data, i_rank, l_inst_a_side),
             "Failed to decode information for MR%d on %s",
             i_data.iv_mrs, mss::c_str(i_target) );

    FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d a-side", uint8_t(i_data.iv_mrs), i_delay_in_cycles,
             l_inst_a_side.arr0, l_inst_a_side.arr1, mss::c_str(i_target), i_rank);
    io_inst.push_back(l_inst_a_side);


    // Only issue b-side if we have an RCD
    FAPI_TRY(mss::dimm::has_rcd<MC>( i_target, l_has_rcd ));

    if(l_has_rcd)
    {
        FAPI_INF("MRS%02d (%d) 0x%016llx:0x%016llx %s:rank %d b-side", uint8_t(i_data.iv_mrs), i_delay_in_cycles,
                 l_inst_b_side.arr0, l_inst_b_side.arr1, mss::c_str(i_target), i_rank);
        io_inst.push_back(l_inst_b_side);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets up MRS CCS instructions
/// @tparam D the mrs data structure to send out
/// @param[in] i_target a fapi2::Target DIMM
/// @param[in] i_data the completed MRS data to send
/// @param[in] i_rank the rank to send to
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< typename D >
fapi2::ReturnCode mrs_engine( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const D& i_data,
                              const uint64_t i_rank,
                              std::vector< ccs::instruction_t >& io_inst );

namespace ddr4
{

// Forward declarations
template< mss::mc_type MC >
struct mrs00_data;

template< mss::mc_type MC >
struct mrs01_data;

template< mss::mc_type MC >
struct mrs02_data;

template< mss::mc_type MC >
struct mrs03_data;

template< mss::mc_type MC >
struct mrs04_data;

template< mss::mc_type MC >
struct mrs05_data;

template< mss::mc_type MC >
struct mrs06_data;

///
/// @defgroup mrs-structs
/// @addtogroup mrs-structs
// Each MRS has it's attributes encapsulated in it's little struct.
// Comparisions for the MRS will be done in the order they'd be built in (according to the JEDEC spec) with the MSB going first
/// @{

///
/// @brief Data structure for MRS0 data
/// @tparam MC mss::mc_type memory controller type
///
template< mss::mc_type MC >
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
            ccs::instruction_t& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs00_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs00_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    ///
    /// @brief Default constructor
    /// @note Default constructor is defined to allow for the use of STL data structures
    ///
    mrs00_data() = default;

    ///
    /// @brief Less than operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is less than i_rhs
    ///
    bool operator<(const mss::ddr4::mrs00_data<MC>& i_rhs) const
    {
        // MSB to LSB - 2015 JEDEC spec
        // write recover/RTP
        // CAS latency
        // DLL reset
        // TM
        // Read burst type
        // Burst length

        if(iv_write_recovery != i_rhs.iv_write_recovery)
        {
            return iv_write_recovery < i_rhs.iv_write_recovery;
        }

        if(iv_cas_latency != i_rhs.iv_cas_latency)
        {
            return iv_cas_latency < i_rhs.iv_cas_latency;
        }

        if(iv_dll_reset != i_rhs.iv_dll_reset)
        {
            return iv_dll_reset < i_rhs.iv_dll_reset;
        }

        if(iv_test_mode != i_rhs.iv_test_mode)
        {
            return iv_test_mode < i_rhs.iv_test_mode;
        }

        if(iv_read_burst_type != i_rhs.iv_read_burst_type)
        {
            return iv_read_burst_type < i_rhs.iv_read_burst_type;
        }

        return iv_burst_length < i_rhs.iv_burst_length;
    }

    ///
    /// @brief Equal to operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is equal to i_rhs
    ///
    bool operator==(const mss::ddr4::mrs00_data<MC>& i_rhs) const
    {
        return !((*this < i_rhs) || (i_rhs < *this));
    }

    uint8_t iv_burst_length;
    uint8_t iv_read_burst_type;
    uint8_t iv_dll_reset;
    uint8_t iv_test_mode;
    uint8_t iv_write_recovery;
    uint8_t iv_cas_latency;
};

///
/// @brief Data structure for MRS1 data
/// @tparam MC mss::mc_type memory controller type
///
template< mss::mc_type MC >
struct mrs01_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 1;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs01_data& i_data,
            ccs::instruction_t& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs01_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs01_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    ///
    /// @brief Default constructor
    /// @note Default constructor is defined to allow for the use of STL data structures
    ///
    mrs01_data() = default;

    ///
    /// @brief Less than operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is less than i_rhs
    ///
    bool operator<(const mss::ddr4::mrs01_data<MC>& i_rhs) const
    {
        // MSB to LSB - 2015 JEDEC spec
        // Qoff
        // TDQS enable
        // RTT_NOM
        // Write leveling enable
        // Additive latency
        // Ouptut driver impedance control
        // DLL enable

        if(iv_qoff != i_rhs.iv_qoff)
        {
            return iv_qoff < i_rhs.iv_qoff;
        }

        if(iv_tdqs != i_rhs.iv_tdqs)
        {
            return iv_tdqs < i_rhs.iv_tdqs;
        }

        const auto l_rtt_nom = memcmp(iv_rtt_nom, i_rhs.iv_rtt_nom, sizeof(i_rhs.iv_rtt_nom));

        if(l_rtt_nom != MEMCMP_EQUAL)
        {
            return l_rtt_nom < MEMCMP_EQUAL;
        }

        if(iv_wl_enable != i_rhs.iv_wl_enable)
        {
            return iv_wl_enable < i_rhs.iv_wl_enable;
        }

        if(iv_additive_latency != i_rhs.iv_additive_latency)
        {
            return iv_additive_latency < i_rhs.iv_additive_latency;
        }

        const auto l_odic = memcmp(iv_odic, i_rhs.iv_odic, sizeof(i_rhs.iv_odic));

        if(l_odic != MEMCMP_EQUAL)
        {
            return l_odic < MEMCMP_EQUAL;
        }

        return iv_dll_enable < i_rhs.iv_dll_enable;
    }

    ///
    /// @brief Equal to operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is equal to i_rhs
    ///
    bool operator==(const mss::ddr4::mrs01_data<MC>& i_rhs) const
    {
        return !((*this < i_rhs) || (i_rhs < *this));
    }

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
/// @tparam MC mss::mc_type memory controller type
///
template< mss::mc_type MC >
struct mrs02_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 2;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs02_data& i_data,
            ccs::instruction_t& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs02_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs02_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    ///
    /// @brief Default constructor
    /// @note Default constructor is defined to allow for the use of STL data structures
    ///
    mrs02_data() = default;

    ///
    /// @brief Less than operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is less than i_rhs
    ///
    bool operator<(const mss::ddr4::mrs02_data<MC>& i_rhs) const
    {
        // MSB to LSB - 2015 JEDEC spec
        // write crc
        // rtt wr
        // LPASR
        // cwl

        if(iv_write_crc != i_rhs.iv_write_crc)
        {
            return iv_write_crc < i_rhs.iv_write_crc;
        }

        const auto l_rtt_wr = memcmp(iv_dram_rtt_wr, i_rhs.iv_dram_rtt_wr, sizeof(i_rhs.iv_dram_rtt_wr));

        if(l_rtt_wr != MEMCMP_EQUAL)
        {
            return l_rtt_wr < MEMCMP_EQUAL;
        }

        if(iv_lpasr != i_rhs.iv_lpasr)
        {
            return iv_lpasr < i_rhs.iv_lpasr;
        }

        return iv_cwl < i_rhs.iv_cwl;
    }

    ///
    /// @brief Equal to operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is equal to i_rhs
    ///
    bool operator==(const mss::ddr4::mrs02_data<MC>& i_rhs) const
    {
        return !((*this < i_rhs) || (i_rhs < *this));
    }

    uint8_t iv_lpasr;
    uint8_t iv_cwl;
    uint8_t iv_write_crc;
    uint8_t iv_dram_rtt_wr[MAX_RANK_PER_DIMM];
};


///
/// @brief Data structure for MRS3 data
/// @tparam MC mss::mc_type memory controller type
///
template< mss::mc_type MC >
struct mrs03_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 3;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs03_data& i_data,
            ccs::instruction_t& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs03_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs03_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    ///
    /// @brief Default constructor
    /// @note Default constructor is defined to allow for the use of STL data structures
    ///
    mrs03_data() = default;

    ///
    /// @brief Less than operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is less than i_rhs
    ///
    bool operator<(const mss::ddr4::mrs03_data<MC>& i_rhs) const
    {
        // MSB to LSB - 2015 JEDEC spec
        // MPR read format
        // crc wr latency
        // fine refresh
        // temp sensor
        // PDA (per-DRAM addressability)
        // geardown mode
        // MPR mode
        // MPR page

        if(iv_read_format != i_rhs.iv_read_format)
        {
            return iv_read_format < i_rhs.iv_read_format;
        }

        if(iv_crc_wr_latency != i_rhs.iv_crc_wr_latency)
        {
            return iv_crc_wr_latency < i_rhs.iv_crc_wr_latency;
        }

        if(iv_fine_refresh != i_rhs.iv_fine_refresh)
        {
            return iv_fine_refresh < i_rhs.iv_fine_refresh;
        }

        if(iv_temp_readout != i_rhs.iv_temp_readout)
        {
            return iv_temp_readout < i_rhs.iv_temp_readout;
        }

        if(iv_pda != i_rhs.iv_pda)
        {
            return iv_pda < i_rhs.iv_pda;
        }

        if(iv_geardown != i_rhs.iv_geardown)
        {
            return iv_geardown < i_rhs.iv_geardown;
        }

        if(iv_mpr_mode != i_rhs.iv_mpr_mode)
        {
            return iv_mpr_mode < i_rhs.iv_mpr_mode;
        }

        return iv_mpr_page < i_rhs.iv_mpr_page;
    }

    ///
    /// @brief Equal to operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is equal to i_rhs
    ///
    bool operator==(const mss::ddr4::mrs03_data<MC>& i_rhs) const
    {
        return !((*this < i_rhs) || (i_rhs < *this));
    }

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
/// @tparam MC mss::mc_type memory controller type
///
template< mss::mc_type MC >
struct mrs04_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 4;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs04_data& i_data,
            ccs::instruction_t& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs04_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs04_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    ///
    /// @brief Default constructor
    /// @note Default constructor is defined to allow for the use of STL data structures
    ///
    mrs04_data() = default;

    ///
    /// @brief Less than operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is less than i_rhs
    ///
    bool operator<(const mss::ddr4::mrs04_data<MC>& i_rhs) const
    {
        // MSB to LSB - 2015 JEDEC spec
        // PPR
        // Write preamble
        // Read preamble
        // Read preamble training mode
        // Refresh abort
        // CS to command address latency
        // Soft PPR
        // VREF monitor
        // Temperature controlled refresh mode
        // Temperature controlled refresh range
        // Maximum power down mode

        if(iv_ppr != i_rhs.iv_ppr)
        {
            return iv_ppr < i_rhs.iv_ppr;
        }

        if(iv_wr_preamble != i_rhs.iv_wr_preamble)
        {
            return iv_wr_preamble < i_rhs.iv_wr_preamble;
        }

        if(iv_rd_preamble != i_rhs.iv_rd_preamble)
        {
            return iv_rd_preamble < i_rhs.iv_rd_preamble;
        }

        if(iv_rd_pre_train_mode != i_rhs.iv_rd_pre_train_mode)
        {
            return iv_rd_pre_train_mode < i_rhs.iv_rd_pre_train_mode;
        }

        if(iv_ref_abort != i_rhs.iv_ref_abort)
        {
            return iv_ref_abort < i_rhs.iv_ref_abort;
        }

        if(iv_cs_cmd_latency != i_rhs.iv_cs_cmd_latency)
        {
            return iv_cs_cmd_latency < i_rhs.iv_cs_cmd_latency;
        }

        if(iv_soft_ppr != i_rhs.iv_soft_ppr)
        {
            return iv_soft_ppr < i_rhs.iv_soft_ppr;
        }

        if(iv_vref_mon != i_rhs.iv_vref_mon)
        {
            return iv_vref_mon < i_rhs.iv_vref_mon;
        }

        if(iv_temp_ref_mode != i_rhs.iv_temp_ref_mode)
        {
            return iv_temp_ref_mode < i_rhs.iv_temp_ref_mode;
        }

        if(iv_temp_refresh_range != i_rhs.iv_temp_refresh_range)
        {
            return iv_temp_refresh_range < i_rhs.iv_temp_refresh_range;
        }

        return iv_max_pd_mode < i_rhs.iv_max_pd_mode;
    }

    ///
    /// @brief Equal to operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is equal to i_rhs
    ///
    bool operator==(const mss::ddr4::mrs04_data<MC>& i_rhs) const
    {
        return !((*this < i_rhs) || (i_rhs < *this));
    }

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
/// @tparam MC mss::mc_type memory controller type
///
template< mss::mc_type MC >
struct mrs05_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 5;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs05_data& i_data,
            ccs::instruction_t& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs05_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs05_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    ///
    /// @brief Default constructor
    /// @note Default constructor is defined to allow for the use of STL data structures
    ///
    mrs05_data() = default;

    ///
    /// @brief Less than operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is less than i_rhs
    ///
    bool operator<(const mss::ddr4::mrs05_data<MC>& i_rhs) const
    {
        // MSB to LSB - 2015 JEDEC spec
        // Read DBI
        // Write DBI
        // Data mask
        // CA parity - persistent error
        // RTT_PARK
        // ODT input buffer
        // CA parity error status
        // CRC error clear
        // CA parity latency mode

        if(iv_read_dbi != i_rhs.iv_read_dbi)
        {
            return iv_read_dbi < i_rhs.iv_read_dbi;
        }

        if(iv_write_dbi != i_rhs.iv_write_dbi)
        {
            return iv_write_dbi < i_rhs.iv_write_dbi;
        }

        if(iv_data_mask != i_rhs.iv_data_mask)
        {
            return iv_data_mask < i_rhs.iv_data_mask;
        }

        if(iv_ca_parity != i_rhs.iv_ca_parity)
        {
            return iv_ca_parity < i_rhs.iv_ca_parity;
        }

        const auto l_rtt_park = memcmp(iv_rtt_park, i_rhs.iv_rtt_park, sizeof(i_rhs.iv_rtt_park));

        if(l_rtt_park != MEMCMP_EQUAL)
        {
            return l_rtt_park < MEMCMP_EQUAL;
        }

        if(iv_odt_input_buffer != i_rhs.iv_odt_input_buffer)
        {
            return iv_odt_input_buffer < i_rhs.iv_odt_input_buffer;
        }

        if(iv_ca_parity_error_status != i_rhs.iv_ca_parity_error_status)
        {
            return iv_ca_parity_error_status < i_rhs.iv_ca_parity_error_status;
        }

        if(iv_crc_error_clear != i_rhs.iv_crc_error_clear)
        {
            return iv_crc_error_clear < i_rhs.iv_crc_error_clear;
        }

        return iv_ca_parity_latency < i_rhs.iv_ca_parity_latency;
    }

    ///
    /// @brief Equal to operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is equal to i_rhs
    ///
    bool operator==(const mss::ddr4::mrs05_data<MC>& i_rhs) const
    {
        return !((*this < i_rhs) || (i_rhs < *this));
    }

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
/// @tparam MC mss::mc_type memory controller type
///
template< mss::mc_type MC >
struct mrs06_data
{
    // Needed as we need to know what MR for the CCS instruction created by the lab tooling
    static constexpr uint64_t iv_mrs = 6;

    // Helper function needed by the lab tooling to find our instruction maker and our dumper
    static fapi2::ReturnCode (*make_ccs_instruction)(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const mrs06_data& i_data,
            ccs::instruction_t& io_inst,
            const uint64_t i_rank);

    static fapi2::ReturnCode (*decode)(const ccs::instruction_t& i_inst,
                                       const uint64_t i_rank);

    ///
    /// @brief mrs06_data ctor
    /// @param[in] a fapi2::TARGET_TYPE_DIMM target
    /// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
    ///
    mrs06_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc );

    ///
    /// @brief Default constructor
    /// @note Default constructor is defined to allow for the use of STL data structures
    ///
    mrs06_data() = default;

    ///
    /// @brief Less than operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is less than i_rhs
    ///
    bool operator<(const mss::ddr4::mrs06_data<MC>& i_rhs) const
    {
        // MSB to LSB - 2015 JEDEC spec
        // TCCD_L
        // Train enable
        // Train range
        // Train value

        if(iv_tccd_l != i_rhs.iv_tccd_l)
        {
            return iv_tccd_l < i_rhs.iv_tccd_l;
        }

        const auto l_enable = memcmp(iv_vrefdq_train_enable, i_rhs.iv_vrefdq_train_enable,
                                     sizeof(i_rhs.iv_vrefdq_train_enable));

        if(l_enable != MEMCMP_EQUAL)
        {
            return l_enable < MEMCMP_EQUAL;
        }

        const auto l_range = memcmp(iv_vrefdq_train_range, i_rhs.iv_vrefdq_train_range, sizeof(i_rhs.iv_vrefdq_train_range));

        if(l_range != MEMCMP_EQUAL)
        {
            return l_range < MEMCMP_EQUAL;
        }

        return memcmp(iv_vrefdq_train_value, i_rhs.iv_vrefdq_train_value, sizeof(i_rhs.iv_vrefdq_train_value)) < MEMCMP_EQUAL;
    }

    ///
    /// @brief Equal to operator
    /// @param[in] i_rhs right hand comparison operator
    /// @bool true if this object is equal to i_rhs
    ///
    bool operator==(const mss::ddr4::mrs06_data<MC>& i_rhs) const
    {
        return !((*this < i_rhs) || (i_rhs < *this));
    }

    uint8_t iv_vrefdq_train_value[MAX_RANK_PER_DIMM];
    uint8_t iv_vrefdq_train_range[MAX_RANK_PER_DIMM];
    uint8_t iv_vrefdq_train_enable[MAX_RANK_PER_DIMM];
    uint8_t iv_tccd_l;
};

/// @}

///
/// @brief Sets WR LVL mode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for WR LVL mode
/// @param[in,out] io_data data we are modifying MPR mode to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode set_wr_lvl_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const mss::states i_mode,
                                  mrs01_data<MC>& io_data)
{
    constexpr uint64_t MAX_WR_LVL_MODE = 0b1;

    FAPI_ASSERT( i_mode <= MAX_WR_LVL_MODE,
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(MRS_LOAD)
                 .set_PARAMETER(WR_LVL)
                 .set_PARAMETER_VALUE(i_mode)
                 .set_DIMM_IN_ERROR(i_target),
                 "%s Invalid WR LVL Mode recieved: %d. Max encoding allowed: %d.",
                 mss::c_str(i_target),
                 i_mode,
                 MAX_WR_LVL_MODE);

    // Update field if input check passes
    io_data.iv_wl_enable = i_mode == mss::states::ON;

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set MPR Mode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for MPR mode
/// @param[in,out] io_data data we are modifying MPR mode to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode set_dram_mpr_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint8_t i_mode,
                                    mrs03_data<MC>& io_data)
{
    constexpr uint64_t MAX_MPR_MODE = 0b1;

    FAPI_ASSERT( i_mode <= MAX_MPR_MODE,
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(MRS_LOAD)
                 .set_PARAMETER(MPR_MODE)
                 .set_PARAMETER_VALUE(i_mode)
                 .set_DIMM_IN_ERROR(i_target),
                 "%s Invalid MPR Mode recieved: %d. Max encoding allowed: %d.",
                 mss::c_str(i_target),
                 i_mode,
                 MAX_MPR_MODE);

    // Update field if input check passes
    io_data.iv_mpr_mode = i_mode;

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set RTT_NOM values in an mrs01_data object
/// @param[in] i_target a DIMM target
/// @param[in] i_value settings for RTT_NOM
/// @param[in,out] io_data data we are modifying RTT_NOM to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode set_dram_rtt_nom(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t i_value[MAX_RANK_PER_DIMM],
                                   mrs01_data<MC>& io_data)
{
    constexpr uint64_t MAX_RTT_NOM = RTT_NOM_RZQ_OVER_7;

    for (size_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
    {
        FAPI_ASSERT( i_value[l_rank] <= MAX_RTT_NOM,
                     fapi2::MSS_BAD_MR_PARAMETER()
                     .set_MR_NUMBER(MRS_LOAD)
                     .set_PARAMETER(RTT_NOM)
                     .set_PARAMETER_VALUE(i_value[l_rank])
                     .set_DIMM_IN_ERROR(i_target),
                     "%s Invalid RTT_NOM value recieved: %d. Max encoding allowed: %d.",
                     mss::c_str(i_target),
                     i_value[l_rank],
                     MAX_RTT_NOM);

        // Update field if input check passes
        io_data.iv_rtt_nom[l_rank] = i_value[l_rank];
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set RTT_WR values in an mrs02_data object
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_value settings for RTT_WR
/// @param[in,out] io_data data we are modifying RTT_WR to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode set_dram_rtt_wr(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint8_t i_value[MAX_RANK_PER_DIMM],
                                  mrs02_data<MC>& io_data)
{
    constexpr uint64_t MAX_RTT_WR = RTT_WR_RZQ_OVER_3;

    for (size_t l_rank = 0; l_rank < MAX_RANK_PER_DIMM; ++l_rank)
    {
        FAPI_ASSERT( i_value[l_rank] <= MAX_RTT_WR,
                     fapi2::MSS_BAD_MR_PARAMETER()
                     .set_MR_NUMBER(MRS_LOAD)
                     .set_PARAMETER(RTT_WR)
                     .set_PARAMETER_VALUE(i_value[l_rank])
                     .set_DIMM_IN_ERROR(i_target),
                     "%s Invalid RTT_WR value recieved: %d. Max encoding allowed: %d.",
                     mss::c_str(i_target),
                     i_value[l_rank],
                     MAX_RTT_WR);

        // Update field if input check passes
        io_data.iv_dram_rtt_wr[l_rank] = i_value[l_rank];
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set MPR Read
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_format setting for MPR read format
/// @param[in,out] io_data data we are modifying MPR mode to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode set_dram_mpr_rd_format(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_format,
        mrs03_data<MC>& io_data)
{
    constexpr uint64_t MAX_READ_FORMAT = 0b10;

    FAPI_ASSERT( i_format <= MAX_READ_FORMAT,
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(MRS_LOAD)
                 .set_PARAMETER(MPR_READ_FORMAT)
                 .set_PARAMETER_VALUE(i_format)
                 .set_DIMM_IN_ERROR(i_target),
                 "%s Invalid MPR Read Format recieved: %d. Max encoding allowed: %d.",
                 mss::c_str(i_target),
                 i_format,
                 MAX_READ_FORMAT);

    // Update field if input check passes
    io_data.iv_read_format = i_format;

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set MPR page
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to mrsTraits<MC>
/// @param[in] i_target a DIMM target
/// @param[in] i_page setting for MPR read format
/// @param[in,out] io_data data we are modifying MPR mode to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode set_dram_mpr_page(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint8_t i_page,
                                    mrs03_data<MC>& io_data)
{
    constexpr uint64_t MAX_PAGE = 0b11;

    FAPI_ASSERT( i_page <= MAX_PAGE,
                 fapi2::MSS_BAD_MR_PARAMETER()
                 .set_MR_NUMBER(MRS_LOAD)
                 .set_PARAMETER(MPR_PAGE)
                 .set_PARAMETER_VALUE(i_page)
                 .set_DIMM_IN_ERROR(i_target),
                 "%s Invalid MPR Page received: %d. Max encoding allowed: %d.",
                 mss::c_str(i_target),
                 i_page,
                 MAX_PAGE);

    // Update field if input check passes
    io_data.iv_mpr_page = i_page;

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction to set WR LVL Mode
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for WR LVL mode
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode wr_lvl(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                         const mss::states i_mode,
                         const uint64_t i_rank,
                         std::vector< ccs::instruction_t >& io_inst )
{
    // Spec states we need to use tmod for our delay, so we do
    const uint64_t l_delay = TT::mrs_tmod(i_target);

    mrs01_data<MC> l_data(i_target, fapi2::current_err);
    FAPI_TRY(fapi2::current_err, "%s. Failed to initialize mrs01_data for set_wr_lvl_mode", mss::c_str(i_target) );

    FAPI_TRY( set_wr_lvl_mode(i_target, i_mode, l_data),
              "%s. Failed set_wr_lvl_mode() with a setting of %d",
              mss::c_str(i_target), i_mode);

    // Make MRS CCS inst
    FAPI_TRY( mrs_engine(i_target, l_data, i_rank, l_delay, io_inst),
              "Failed to send MRS01 on %s, rank: %d, delay (in cycles): %d",
              mss::c_str(i_target), i_rank, l_delay);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction to set MPR Mode
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for MPR mode
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode mpr_load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const uint8_t i_mode,
                           const uint64_t i_rank,
                           std::vector< ccs::instruction_t >& io_inst )
{
    // From DDR4 spec section 4.10.3 MPR Reads:
    // tMRD and tMOD must be satisfied after enabling/disabling MPR mode
    const uint64_t l_delay = std::max( TT::mrs_tmod(i_target), TT::TMRD );

    mrs03_data<MC> l_data(i_target, fapi2::current_err);
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
/// @param[in] i_target a DIMM target
/// @param[in] i_mode setting for MPR mode
/// @param[in] i_rd_format MPR read format
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode mpr_load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const uint8_t i_mode,
                           const uint8_t i_rd_format,
                           const uint64_t i_rank,
                           std::vector< ccs::instruction_t >& io_inst )
{
    // From DDR4 spec section 4.10.3 MPR Reads:
    // tMRD and tMOD must be satisfied after enabling/disabling MPR mode
    const uint64_t l_delay = std::max( TT::mrs_tmod(i_target), TT::TMRD );

    mrs03_data<MC> l_data(i_target, fapi2::current_err);
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
/// @brief Makes CCS instruction to set RTT_NOM value
/// @param[in] i_target a DIMM target
/// @param[in] i_value values to set to RTT_NOM
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode rtt_nom_load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                               const uint8_t i_value[MAX_RANK_PER_DIMM],
                               const uint64_t i_rank,
                               std::vector< ccs::instruction_t >& io_inst )
{
    // tMRD (clock cycles) must be satisfied after an MRS command
    constexpr uint64_t l_delay = TT::TMRD;

    mrs01_data<MC> l_data(i_target, fapi2::current_err);
    FAPI_TRY(fapi2::current_err, "%s. Failed to initialize mrs01_data for rtt_nom_load", mss::c_str(i_target) );

    FAPI_TRY( set_dram_rtt_nom(i_target, i_value, l_data),
              "%s. Failed set_dram_rtt_nom()",
              mss::c_str(i_target));

    // Make MRS CCS inst
    FAPI_TRY( mrs_engine(i_target, l_data, i_rank, l_delay, io_inst),
              "Failed to send MRS01 on %s, rank: %d",
              mss::c_str(i_target), i_rank);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction to set RTT_WR value
/// @param[in] i_target a DIMM target
/// @param[in] i_value values to set to RTT_WR
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = mrsTraits<MC> >
fapi2::ReturnCode rtt_wr_load(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                              const uint8_t i_value[MAX_RANK_PER_DIMM],
                              const uint64_t i_rank,
                              std::vector< ccs::instruction_t >& io_inst )
{
    // tMRD (clock cycles) must be satisfied after an MRS command
    constexpr uint64_t l_delay = TT::TMRD;

    mrs02_data<MC> l_data(i_target, fapi2::current_err);
    FAPI_TRY(fapi2::current_err, "%s. Failed to initialize mrs02_data for rtt_wr_load", mss::c_str(i_target) );

    FAPI_TRY( set_dram_rtt_wr(i_target, i_value, l_data),
              "%s. Failed set_dram_rtt_wr()",
              mss::c_str(i_target));

    // Make MRS CCS inst
    FAPI_TRY( mrs_engine(i_target, l_data, i_rank, l_delay, io_inst),
              "Failed to send MRS02 on %s, rank: %d",
              mss::c_str(i_target), i_rank);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction for an MPR read
/// @param[in] i_target a DIMM target
/// @param[in] i_mode MPR location
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode mpr_read( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint64_t i_mpr_loc,
                                   const uint64_t i_rank,
                                   std::vector< ccs::instruction_t >& io_inst )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;
    using MRS = mrsTraits<DEFAULT_MC_TYPE>;

    // Right now we only have support for RD and RDA
    // Unclear if we want the API select the type of read command right now
    // Note the auto precharge is ignored with MPR mode on so we just do a read cmd
    ccs::instruction_t l_inst = ccs::rd_command (i_rank, i_mpr_loc);

    // In MPR Mode:
    // Reads (back-to-back) from Page 0 may use tCCD_S or tCCD_L timing between read commands
    // Reads (back-to-back) from Pages 1, 2, or 3 may not use tCCD_S timing between read commands
    // tCCD_L must be used for timing between read commands
    uint8_t l_delay = 0;

    if( i_mpr_loc == 0)
    {
        // note we are truncating a uint64 to a uint8 but since
        // the value of tccd_s is always 4....we should be okay
        l_delay = MRS::TCCD_S;
    }
    else
    {
        FAPI_TRY(MRS::dram_tccd_l(i_target, l_delay), "Failed to invoke accessor for tCCD_L");
    }

    // Input type needs to be greater than IDLES_LEN, hence the cast
    l_inst.arr1.template insertFromRight<TT::ARR1_IDLES,
                         TT::ARR1_IDLES_LEN>(static_cast<uint64_t>(l_delay));

    FAPI_INF("MPR Read CCS inst 0x%016llx:0x%016llx %s:rank %d, MPR location:%d, delay (in cycles) %d",
             uint64_t(l_inst.arr0), uint64_t(l_inst.arr1), mss::c_str(i_target), i_rank, i_mpr_loc, l_delay);

    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Makes CCS instruction to set precharge all command
/// @param[in] i_target a DIMM target
/// @param[in] i_rank DIMM rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode precharge_all( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint64_t i_rank,
                                        std::vector< ccs::instruction_t >& io_inst )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;
    using MRS = mrsTraits<DEFAULT_MC_TYPE>;

    ccs::instruction_t l_inst = ccs::precharge_all_command (i_rank);

    // From the DDR4 Spec tRP is the precharge command period
    uint8_t l_delay = 0;
    FAPI_TRY( MRS::dram_trp(i_target, l_delay) );

    // Input type needs to be greater than IDLES_LEN, hence the cast
    l_inst.arr1.template insertFromRight<TT::ARR1_IDLES,
                         TT::ARR1_IDLES_LEN>( static_cast<uint64_t>(l_delay));

    FAPI_INF("precharge_all CCS inst 0x%016llx:0x%016llx %s:rank %d, delay (in cycles) %d",
             uint64_t(l_inst.arr0), uint64_t(l_inst.arr1), mss::c_str(i_target), i_rank, l_delay);

    // Add to CCS program
    io_inst.push_back(l_inst);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Maps RTT_WR setting to equivalent RTT_NOM setting
/// @tparam T TargetType of the DIMM
/// @param[in] i_target a DIMM target
/// @param[in] i_rtt_wr an RTT_WR setting
/// @param[out] o_rtt_nom equivalent RTT_NOM setting
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode rtt_wr_to_rtt_nom_helper(const fapi2::Target<T>& i_target,
        const uint8_t i_rtt_wr,
        uint8_t& o_rtt_nom)
{
    switch(i_rtt_wr)
    {
        case RTT_WR_DYNAMIC_ODT_OFF:
        case RTT_WR_HIZ:
            o_rtt_nom = RTT_NOM_DISABLE;
            break;

        case RTT_WR_RZQ_OVER_3:
            o_rtt_nom = RTT_NOM_RZQ_OVER_3;
            break;

        case RTT_WR_RZQ_OVER_2:
            o_rtt_nom = RTT_NOM_RZQ_OVER_2;
            break;

        case RTT_WR_RZQ_OVER_1:
            o_rtt_nom = RTT_NOM_RZQ_OVER_1;
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RTT_WR_ENCODING().
                         set_RTT_WR(i_rtt_wr).
                         set_TARGET(i_target),
                         "Received invalid RTT_WR value: 0x%02x for %s.",
                         i_rtt_wr, mss::c_str(i_target) );
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if the RTT_NOM override should be run
/// @tparam mc_type MC
/// @param[in] i_target the target on which to operate
/// @param[out] o_run_override true if the override should be run
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC >
fapi2::ReturnCode is_rtt_nom_override_needed(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_run_override);

///
/// @brief Attribute getter helper for RTT_NOM
/// @tparam mc_type MC
/// @param[in] i_target the target on which to operate
/// @param[out] o_array the array with the attr values
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC >
fapi2::ReturnCode rtt_nom_attr_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      uint8_t (&o_array)[MAX_RANK_PER_DIMM]);

///
/// @brief Attribute getter helper for RTT_WR
/// @tparam mc_type MC
/// @param[in] i_target the target on which to operate
/// @param[out] o_array the array with the attr values
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC >
fapi2::ReturnCode rtt_wr_attr_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     uint8_t (&o_array)[MAX_RANK_PER_DIMM]);

///
/// @brief Executes CCS instructions to set RTT_WR value into RTT_NOM
/// @tparam mc_type MC - defaults to DEFAULT_MC_TYPE
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode rtt_nom_override(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint64_t i_rank,
                                   std::vector< ccs::instruction_t >& io_inst)
{
    bool l_run_override = false;
    uint8_t l_rtt_wr_value[MAX_RANK_PER_DIMM] = {0};
    uint8_t l_rtt_nom_value[MAX_RANK_PER_DIMM] = {0};

    // eff_dram* attributes use a per-DIMM rank index, so get that
    const auto l_rank_idx = mss::index(i_rank);

    FAPI_TRY( is_rtt_nom_override_needed<MC>(i_target, l_run_override) );

    // Skip the override if it's not needed
    if ( !l_run_override )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Map RTT_WR settings to RTT_NOM
    FAPI_TRY( rtt_wr_attr_helper<MC>(i_target, l_rtt_wr_value));
    FAPI_TRY( rtt_wr_to_rtt_nom_helper(i_target, l_rtt_wr_value[l_rank_idx], l_rtt_nom_value[l_rank_idx]) );

    // Write the override values to RTT_NOM
    FAPI_DBG("Overriding RTT_NOM value to 0x%01x to match original RTT_WR value 0x%01x on rank %d",
             l_rtt_nom_value[l_rank_idx], l_rtt_wr_value[l_rank_idx], i_rank);
    FAPI_TRY( rtt_nom_load<MC>(i_target, l_rtt_nom_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes CCS instructions to disable RTT_WR
/// @tparam mc_type MC - defaults to DEFAULT_MC_TYPE
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode rtt_wr_disable(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank,
                                 std::vector< ccs::instruction_t >& io_inst)
{
    uint8_t l_rtt_wr_value[MAX_RANK_PER_DIMM] = {0};

    // eff_dram* attributes use a per-DIMM rank index, so get that
    const auto l_rank_idx = mss::index(i_rank);

    // Write RTT_WR setting for the given rank to RTT_WR_DYNAMIC_ODT_OFF
    FAPI_TRY( rtt_wr_attr_helper<MC>(i_target, l_rtt_wr_value));
    l_rtt_wr_value[l_rank_idx] = RTT_WR_DYNAMIC_ODT_OFF;

    FAPI_TRY( rtt_wr_load<MC>(i_target, l_rtt_wr_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes CCS instructions to restore original value to RTT_NOM
/// @tparam mc_type MC - defaults to DEFAULT_MC_TYPE
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode rtt_nom_restore(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const uint64_t i_rank,
                                  std::vector< ccs::instruction_t >& io_inst)
{
    bool l_run_override = false;
    uint8_t l_rtt_nom_value[MAX_RANK_PER_DIMM] = {0};

    FAPI_TRY( is_rtt_nom_override_needed<MC>(i_target, l_run_override) );

    // Skip the override if it's not needed
    if ( !l_run_override )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get original RTT_NOM value
    FAPI_TRY( rtt_nom_attr_helper<MC>(i_target, l_rtt_nom_value));

    // Write the value to RTT_NOM
    FAPI_TRY( rtt_nom_load<MC>(i_target, l_rtt_nom_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Executes CCS instructions to restore original value to RTT_WR
/// @tparam mc_type MC - defaults to DEFAULT_MC_TYPE
/// @param[in] i_target a DIMM target
/// @param[in] i_rank selected rank
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode rtt_wr_restore(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const uint64_t i_rank,
                                 std::vector< ccs::instruction_t >& io_inst)
{
    // Get original RTT_WR value
    uint8_t l_rtt_wr_value[MAX_RANK_PER_DIMM] = {0};
    FAPI_TRY( rtt_wr_attr_helper<MC>(i_target, l_rtt_wr_value));

    // Write the value to RTT_WR
    FAPI_TRY( rtt_wr_load<MC>(i_target, l_rtt_wr_value, i_rank, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

} // ddr4
} // mss
#endif
