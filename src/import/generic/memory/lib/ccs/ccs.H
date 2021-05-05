/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ccs/ccs.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file ccs.H
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CCS_H_
#define _MSS_CCS_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/ccs/ccs_traits.H>

namespace mss
{

static constexpr uint64_t CKE_HIGH = 0b1111;
static constexpr uint64_t CKE_LOW  = 0b0000;

// CKE setup for rank 0-7 to support
// Currently only support 0, 1, 4, 5
// Not supported ranks will always get 0
// For self_refresh_entry_command()
static constexpr uint64_t CKE_ARY_SRE[]  =
{
    //   0,      1, 2, 3,
    0b0111, 0b1011, 0, 0,
    //   4,      5, 6, 7
    0b0111, 0b1011, 0, 0
};

// For self_refresh_exit_command()
static constexpr uint64_t CKE_ARY_SRX[]  =
{
    //   0,      1, 2, 3,
    0b1000, 0b0100, 0, 0,
    //   4,      5, 6, 7
    0b1000, 0b0100, 0, 0
};

namespace ccs
{

enum rank_configuration
{
    DUAL_DIRECT = 0,
    QUAD_ENCODED = 1,
    // Note: we don't include QUAD_DIRECT in here
    // That's because it uses 4 CS and is board wiring dependent
    // Not sure if it would use CS23 or CID01 for CS2/3
};

///
/// @class instruction_t
/// @brief Class for ccs instructions
/// @tparam T fapi2::TargetType representing the target of the CCS instructions
/// @note A ccs instruction is data (array 0) and some control information (array 1)cc
///
class instruction_t
{
    private:
        using TT = ccsTraits<DEFAULT_MC_TYPE>;

    public:
        fapi2::buffer<uint64_t> arr0;
        fapi2::buffer<uint64_t> arr1;
        // The port indexed rank on which to operate. If this is invalid, all ranks will be disabled
        uint64_t iv_port_rank;
        // We want to have a switch to update rank or not. A user might want to setup CS in some weird way
        // In that case, they don't want us "fixing" their CS values
        // We'll default the rank to be updated - we want to send out CS properly
        bool iv_update_rank;

        ///
        /// @brief intstruction_t ctor
        /// @param[in] i_port_rank the port rank this instruction is headed for
        /// @param[in] i_arr0 the initial value for arr0, defaults to 0
        /// @param[in] i_arr1 the initial value for arr1, defaults to 0
        /// @param[in] i_update_rank true if the rank should be updated before being sent, defaults to true
        ///
        instruction_t( const uint64_t i_port_rank = NO_CHIP_SELECT_ACTIVE,
                       const fapi2::buffer<uint64_t> i_arr0 = 0,
                       const fapi2::buffer<uint64_t> i_arr1 = 0,
                       const bool i_update_rank = true):
            arr0(i_arr0),
            arr1(i_arr1),
            iv_port_rank(i_port_rank),
            iv_update_rank(i_update_rank)
        {
            // Skip setting up the rank if the user doesn't want us to
            if(iv_update_rank)
            {
                // Set the chip selects to be 1's (not active)
                // We'll fix these up before executing the instructions
                arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1,
                                     TT::ARR0_DDR_CSN_0_1_LEN>(0b11);
                arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3,
                                     TT::ARR0_DDR_CSN_2_3_LEN>(0b11);
            }
        }

        ///
        /// @brief Updates the rank based upon the passed in rank configuration encoding
        /// @param[in] i_target the port target for this instruction - for error logging
        /// @param[in] i_rank_config the rank configuration
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
        ///
        fapi2::ReturnCode configure_rank(
            const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
            const rank_configuration i_rank_config )
        {
            // If this instrunction is set to not update the rank, then don't update the rank
            if(!iv_update_rank)
            {
                return fapi2::FAPI2_RC_SUCCESS;
            }

            // Regardless of rank configurations, if we have NO_CHIP_SELECT_ACTIVE, deactivate all CS
            if(iv_port_rank == NO_CHIP_SELECT_ACTIVE)
            {
                arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1, TT::ARR0_DDR_CSN_0_1_LEN>(0b11);
                arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3, TT::ARR0_DDR_CSN_2_3_LEN>(0b11);
                return fapi2::FAPI2_RC_SUCCESS;
            }

            // First, check rank - we need to make sure that we have a valid rank
            FAPI_ASSERT(iv_port_rank < TT::CCS_MAX_MRANK_PER_PORT,
                        fapi2::MSS_INVALID_RANK()
                        .set_PORT_TARGET(i_target)
                        .set_RANK(iv_port_rank)
                        .set_FUNCTION(generic_ffdc_codes::CCS_INST_CONFIGURE_RANK),
                        "%s rank out of bounds rank%u", mss::c_str(i_target), iv_port_rank);

            // Now the fun happens and we can deal with the actual encoding

            // If we're quad mode, setup the encoding accordingly
            if(i_rank_config == rank_configuration::QUAD_ENCODED)
            {
                // CS 0/1 are first, while CID0/1 are second
                // In quad enabled mode, CID acts as a "package select"
                // It selects R0/2 vs R1/3
                // CS0 vs CS1 selects the low vs high rank in the package
                // CS0 will select rank 0/1
                // CS1 will select rank 2/3

                const auto l_dimm_rank = mss::index(iv_port_rank);
                const bool l_is_dimm0 = iv_port_rank < TT::CCS_MAX_RANK_PER_DIMM;
                constexpr uint64_t NON_DIMM_CS = 0b11;

                // Assigns the CS based upon which DIMM we're at
                const uint64_t CS01 = l_is_dimm0 ? TT::CS_N[l_dimm_rank].first : NON_DIMM_CS;
                uint64_t CS23 = l_is_dimm0 ? NON_DIMM_CS : TT::CS_N[l_dimm_rank].first;

                // Set CS23 <-- CS01 if CS needs to be tied
                FAPI_TRY(TT::cs_tied(i_target, CS01, CS23));

                // Setup that rank
                arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1,
                                     TT::ARR0_DDR_CSN_0_1_LEN>(CS01);
                arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3,
                                     TT::ARR0_DDR_CSN_2_3_LEN>(CS23);
                arr0.insertFromRight<TT::ARR0_DDR_CID_0_1,
                                     TT::ARR0_DDR_CID_0_1_LEN>(TT::CS_N[l_dimm_rank].second);
            }

            // Otherwise, setup for dual-direct mode (our only other supported mode at the moment)
            else
            {
                const auto l_dimm_rank = mss::index(iv_port_rank);
                const bool l_is_dimm0 = iv_port_rank < TT::CCS_MAX_RANK_PER_DIMM;

                // Assigns the CS based upon which DIMM we're at
                const uint64_t CS01 = l_is_dimm0 ? TT::CS_ND[l_dimm_rank].first : TT::CS_ND[l_dimm_rank].second;
                uint64_t CS23 = l_is_dimm0 ? TT::CS_ND[l_dimm_rank].second : TT::CS_ND[l_dimm_rank].first;

                // Set CS23 <-- CS01 if CS needs to be tied
                FAPI_TRY(TT::cs_tied(i_target, CS01, CS23));

                // Setup that rank
                arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1,
                                     TT::ARR0_DDR_CSN_0_1_LEN>(CS01);
                arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3,
                                     TT::ARR0_DDR_CSN_2_3_LEN>(CS23);

                // Check that we don't have a rank out of bounds case here
                // We can only have that if
                // 1) we are DIMM1
                // 2) our DIMM rank is greater than the maximum allowed number of ranks on DIMM1
                // So, we pass always if we're DIMM0, or if our DIMM rank is less than the maximum number of DIMM's on rank 1
                FAPI_ASSERT((l_dimm_rank < TT::CCS_MAX_RANKS_DIMM1) || l_is_dimm0,
                            fapi2::MSS_INVALID_RANK()
                            .set_PORT_TARGET(i_target)
                            .set_RANK(iv_port_rank)
                            .set_FUNCTION(generic_ffdc_codes::CCS_INST_CONFIGURE_RANK),
                            "%s rank out of bounds rank%u", mss::c_str(i_target), iv_port_rank);
            }

            return fapi2::FAPI2_RC_SUCCESS;
        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Equals comparison operator
        /// @param[in] i_rhs - the instruction to compare to
        /// @return True if both instructions are equal
        ///
        inline bool operator==( const instruction_t& i_rhs ) const
        {
            return arr0 == i_rhs.arr0 &&
                   arr1 == i_rhs.arr1 &&
                   iv_port_rank == i_rhs.iv_port_rank &&
                   iv_update_rank == i_rhs.iv_update_rank;
        }
};

///
/// @brief Determines our rank configuration type
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
inline fapi2::ReturnCode get_rank_config(const fapi2::Target<DEFAULT_MEM_PORT_TARGET>& i_target,
        rank_configuration& o_rank_config)
{
    typedef ccsTraits<DEFAULT_MC_TYPE> TT;
    constexpr uint8_t QUAD_RANK_ENABLE = 4;
    o_rank_config = rank_configuration::DUAL_DIRECT;

    uint8_t l_num_master_ranks[TT::CCS_MAX_DIMM_PER_PORT] = {};
    bool l_has_rcd = false;
    FAPI_TRY(TT::get_rank_config_attr(i_target, l_num_master_ranks));
    FAPI_TRY(TT::get_has_rcd(i_target, l_has_rcd));

    // We only need to check DIMM0
    // Our number of ranks should be the same between DIMM's 0/1
    // Check if we have the right number for encoded mode
    // And that we have an RCD
    o_rank_config = ((l_num_master_ranks[0] == QUAD_RANK_ENABLE) && (l_has_rcd)) ?
                    rank_configuration::QUAD_ENCODED :
                    rank_configuration::DUAL_DIRECT;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines our rank configuration type across all ports
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
inline fapi2::ReturnCode get_rank_config(const fapi2::Target<DEFAULT_MC_TARGET>& i_target,
        std::vector<rank_configuration>& o_rank_config)
{
    typedef ccsTraits<DEFAULT_MC_TYPE> TT;

    o_rank_config.clear();
    // Create one per port, we then use relative indexing to get us the number we need
    o_rank_config = std::vector<rank_configuration>(TT::PORTS_PER_MC_TARGET);

    for(const auto& l_port : mss::find_targets<DEFAULT_MEM_PORT_TARGET>(i_target))
    {
        rank_configuration l_config;
        FAPI_TRY(get_rank_config(l_port, l_config));
        o_rank_config[mss::relative_pos<DEFAULT_MC_TARGET>(l_port)] = l_config;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief A class representing a series of CCS instructions, and the
/// CCS engine parameters associated with running the instructions
/// @tparam T fapi2::TargetType  representing the fapi2 target which
/// @tparam P fapi2::TargetType representing the port
/// contains the CCS engine
class program
{
    private:
        using TT = ccsTraits<DEFAULT_MC_TYPE>;

    public:
        // Setup our poll parameters so the CCS executer can see
        // whether to use the delays in the instruction stream or not
        program(): iv_poll(0, 0)
        {}

        // Vector of instructions
        std::vector< instruction_t > iv_instructions;
        poll_parameters                 iv_poll;

        // Vector of polling probes
        std::vector< poll_probe<TT::PORT_TARGET_TYPE> >    iv_probes;
};

///
/// @brief Common setup for all MRS/RCD instructions
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in,out] i_arr0 fapi2::buffer<uint64_t> representing the ARR0 of the instruction
///
static void mrs_rcd_helper( fapi2::buffer<uint64_t>& i_arr0 )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    i_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    i_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS, CAS, WE low
    i_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();
}

///
/// @brief Setup activate command instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_port_rank the rank on this dimm
///
inline instruction_t act_command( const uint64_t i_port_rank )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Set all CKE to high
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ACTN>();

    // RAS low, CAS low, WE low
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // Just leaving the row addresses to all 0 for now
    // row, bg, ba set to 0
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_17>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_0_13, TT::ARR0_DDR_ADDRESS_0_13_LEN>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_0>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_0_1, TT::ARR0_DDR_BANK_0_1_LEN>();
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_2>();

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Create, initialize an RCD (RCW - JEDEC) CCS command
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_turn_on_cke flag that states whether we want CKE on for this RCW (defaulted to true)
/// @return the RCD CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t rcd_command( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                  const bool i_sim,
                                  const bool i_turn_on_cke = true)
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    mrs_rcd_helper(rcd_boilerplate_arr0);

    // Not adding i_turn_on_cke in the mrs_rcd helper because we only need this
    // for RCWs and there is no need to complicate/change the MRS cmd API with
    // uneeded functionality. Little duplication, but this isolates the change.
    if( !i_sim )
    {
        const uint64_t l_cke = i_turn_on_cke ? CKE_HIGH : CKE_LOW;
        rcd_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(l_cke);
    }

    //
    // RCD setup
    //
    // DDR4: Set BG1 to 0 during an MRS.
    // BG0, BA1:BA0 to 0b111 selects RCW (aka MR7).
    rcd_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>()
    .template insertFromRight<TT::ARR0_DDR_BANK_0_1, TT::ARR0_DDR_BANK_0_1_LEN>(0b11)
    .template setBit<TT::ARR0_DDR_BANK_GROUP_0>();

    // RCD always goes to the 0th rank on the DIMM; either 0 or 4.
    return instruction_t((mss::index(i_target) == 0) ? 0 : 4, rcd_boilerplate_arr0, rcd_boilerplate_arr1);
}

///
/// @brief Create, initialize an MRS CCS command
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_port_rank the port rank
/// @param[in] i_mrs the specific MRS
/// @return the MRS CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t mrs_command ( const uint64_t i_port_rank,
                                   const uint64_t i_mrs )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;
    fapi2::buffer<uint8_t> mrs(i_mrs);

    //
    // Generic DDR4 MRS setup (RCD is an MRS)
    //
    mrs_rcd_helper(rcd_boilerplate_arr0);

    //
    // MRS setup
    //
    // DDR4: Set BG1 to 0. BG0, BA1:BA0 to i_mrs
    rcd_boilerplate_arr0.clearBit<TT::ARR0_DDR_BANK_GROUP_1>();
    mss::swizzle<TT::ARR0_DDR_BANK_0_1, 3, 7>(mrs, rcd_boilerplate_arr0);
    FAPI_DBG("mrs rcd boiler 0x%016lx 0x%llx", uint8_t(mrs), uint64_t(rcd_boilerplate_arr0));
    return instruction_t(i_port_rank, rcd_boilerplate_arr0, rcd_boilerplate_arr1);
}

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t des_command(const uint16_t i_idle = 0)
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    // ACT is high. It's a no-care in the spec but it seems to raise questions when
    // people look at the trace, so lets set it high.
    rcd_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    rcd_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // Insert idle
    rcd_boilerplate_arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>( i_idle );

    // ACT is high no-care
    // RAS, CAS, WE no-care

    // Device Deslect wants CS_n always high (select nothing using rank NO_CHIP_SELECT_ACTIVE)
    return instruction_t( NO_CHIP_SELECT_ACTIVE,
                          rcd_boilerplate_arr0,
                          rcd_boilerplate_arr1);
}

///
/// @brief Converts an ODT attribute to CCS array input
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_attr_value ODT attribute value
/// @param[in] i_target PORT target type
/// @param[out] CCS value for the ODT's
/// @return FAPI2_RC_SUCCESS iff success, else error code
///
template< typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline fapi2::ReturnCode convert_odt_attr_to_ccs(
    const fapi2::buffer<uint8_t>& i_attr_value,
    const fapi2::Target<TT::PORT_TARGET_TYPE>& i_target,
    uint8_t& o_ccs_value)
{
    // ODT value buffer
    fapi2::buffer<uint8_t> l_ccs_value;
    l_ccs_value.template writeBit<TT::CCS_ODT_DIMM0_R0>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM0_R0>())
    .template writeBit<TT::CCS_ODT_DIMM0_R1>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM0_R1>())
    .template writeBit<TT::CCS_ODT_DIMM0_R0>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM0_R0>())
    .template writeBit<TT::CCS_ODT_DIMM1_R0>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM1_R0>())
    .template writeBit<TT::CCS_ODT_DIMM1_R1>(i_attr_value.template getBit<TT::ATTR_ODT_DIMM1_R1>());

    // Set ODT_DIMM1_R0 & R1 <-- ODT_DIMM0_R0 & R1 if CS/ODt needs to be tied
    FAPI_TRY(TT::odt_tied(i_target, l_ccs_value));

    o_ccs_value = uint8_t(l_ccs_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create, initialize an ODT CCS command
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_odt_values CCS defined ODT values
/// @param[in] i_cycles the number of cycles to hold the ODT for - defaults to DEFAULT_ODT_CYCLE_LEN
/// @return the Device Deselect CCS instruction
/// @note This technically is not a JEDEC command, but is needed for CCS to hold the ODT cycles
/// CCS by design does not repeat or latch ODT's appropriately
/// As such, it's up to the programmers to hold the ODT's appropriately
/// This "command" will greatly help us do that
///
template< typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline instruction_t odt_command(const uint8_t i_odt_values, const uint64_t i_cycles = TT::DEFAULT_ODT_CYCLE_LEN)
{
    auto l_odt_cmd = des_command();
    l_odt_cmd.arr0.template insertFromRight<TT::ARR0_DDR_ODT, TT::ARR0_DDR_ODT_LEN>(i_odt_values);
    l_odt_cmd.arr1.template insertFromRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(i_cycles);

    return l_odt_cmd;
}


///
/// @brief Create, initialize a NTTM read CCS command
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @return the Device Deselect CCS instruction
/// @note need to setup 4 cycles delay
///
inline instruction_t nttm_read_command()
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    // get the des_command
    auto l_command = des_command();
    // set to CCS_INST_ARR1 register
    l_command.arr1.template setBit<TT::NTTM_MODE_FORCE_READ>();
    l_command.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(TT::NTTM_READ_DELAY);

    return l_command;
}

///
/// @brief Create, initialize a JEDEC Device Power Down Entry CCS command
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @return the Device Deselect CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t pde_command()
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> rcd_boilerplate_arr0;
    fapi2::buffer<uint64_t> rcd_boilerplate_arr1;

    // Power Down Entry just like a DES, but we set CKE low
    instruction_t l_inst = des_command();

    // CKE is low. Note: P8 set all 4 of these low - not sure if that's correct.
    l_inst.arr0.template insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_LOW);

    l_inst.arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>( TT::TIMING_TCPDED );

    return l_inst;
}

///
/// @brief Setup ZQ Long instruction
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the MRS CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t zqcl_command( const uint64_t i_port_rank,
                                   const uint16_t i_idle = 0 )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. BRS
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS/CAS high, WE low
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // ADDR10/AP is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    // Insert idle
    l_boilerplate_arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>( i_idle );

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup read command helper function
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
static fapi2::buffer<uint64_t> read_cmd_boilerplate( const uint64_t i_port_rank,
        const fapi2::buffer<uint64_t>& i_bank_addr = 0,
        const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
        const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    // TODO - RTC 166175 Encapsulate command truth table in a subclass for ccs.H
    fapi2::buffer<uint64_t> l_boilerplate_arr0;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. AAM
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE,
                                       TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS high, CAS low, WE high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template setBit<TT::ARR0_DDR_ADDRESS_14>();

    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_BANK_0_1,
                                       TT::ARR0_DDR_BANK_0_1_LEN>(i_bank_addr);

    // Bank Group takes a little effort - the bits aren't contiguous
    constexpr uint64_t BG0_BIT = 62;
    constexpr uint64_t BG1_BIT = 63;

    l_boilerplate_arr0.writeBit<TT::ARR0_DDR_BANK_GROUP_0>(i_bank_group_addr.getBit<BG0_BIT>())
    .template writeBit<TT::ARR0_DDR_BANK_GROUP_1>(i_bank_group_addr.getBit<BG1_BIT>());

    // CA is A[0:9]
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_ADDRESS_0_9,
                                       TT::ARR0_DDR_ADDRESS_0_9_LEN>(i_column_addr);

    return l_boilerplate_arr0;
}

///
/// @brief Setup write command (Fixed BL8 or BC4) instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the write command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t wr_command( const uint64_t i_port_rank,
                                 const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                 const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                 const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    // WR's and RD's are very similar, so we just use the RD command boiler plate and modify the command to a WR
    fapi2::buffer<uint64_t> l_boilerplate_arr0 = read_cmd_boilerplate(i_port_rank,
            i_bank_addr,
            i_bank_group_addr,
            i_column_addr);
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // RAS high, CAS low, WE low
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup read command (Fixed BL8 or BC4) instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t rd_command( const uint64_t i_port_rank,
                                 const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                 const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                 const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0 = read_cmd_boilerplate(i_port_rank,
                         i_bank_addr,
                         i_bank_group_addr,
                         i_column_addr);

    // Setup ADDR10/AP based on read type
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup read w/auto precharge command (Fixed BL8 or BC4) instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_port_rank the port rank
/// @param[in] i_bank_addr bank address bits [BG0:BG1] = [62:63] (right aligned)
/// @param[in] i_bank_group_addr bank group address bits [BA0:BA1] = [62:63] (right aligned)
/// @param[in] i_column_addr column address bits [A0:A9] = [54:63] (right aligned)
/// @return the read command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t rda_command( const uint64_t i_port_rank,
                                  const fapi2::buffer<uint64_t>& i_bank_addr = 0,
                                  const fapi2::buffer<uint64_t>& i_bank_group_addr = 0,
                                  const fapi2::buffer<uint64_t>& i_column_addr = 0)
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    l_boilerplate_arr0 = read_cmd_boilerplate(i_port_rank,
                         i_bank_addr,
                         i_bank_group_addr,
                         i_column_addr);

    // Setup ADDR10/AP based on read type
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup precharge all banks command instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the precharge all banks command CCS instruction
/// @note THIS IS DDR4 ONLY RIGHT NOW. We can (and possibly should) specialize this
/// for the controller (Nimbus v Centaur) and then correct for DRAM generation (not included
/// in this template definition)
///
inline instruction_t precharge_all_command( const uint64_t i_port_rank,
        const uint16_t i_idle = 0 )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // CKE is high Note: P8 set all 4 of these high - not sure if that's correct. AAM
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS low, CAS high, WE low
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_14>();

    // Setup ADDR10/AP high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_10>();

    // Insert idle
    l_boilerplate_arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>( i_idle );

    // From DDR4 Spec table 17:
    // All other bits from the command truth table or 'V', for valid (1 or 0)

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup self-refresh entry command instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh entry command CCS instruction
/// @note THIS IS FOR DDR4 NON-LRDIMM ONLY RIGHT NOW
///
inline instruction_t self_refresh_entry_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Set all CKE to high except the rank passed in
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_ARY_SRE[i_port_rank]);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS low, CAS low, WE high
    l_boilerplate_arr0.clearBit<TT::ARR0_DDR_ADDRESS_16>()
    .template clearBit<TT::ARR0_DDR_ADDRESS_15>()
    .template setBit<TT::ARR0_DDR_ADDRESS_14>();

    // Insert idle
    l_boilerplate_arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>( i_idle );

    // From DDR4 Spec table 17:
    // All other bits from the command truth table are 'V', for valid (1 or 0)

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup self-refresh exit using NOP command instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh exit command CCS instruction
/// @note Using NOP in case SDRAM is in gear down mode and max power saving mode exit
/// @note THIS IS FOR DDR4 NON-LRDIMM ONLY RIGHT NOW
///
inline instruction_t self_refresh_exit_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    fapi2::buffer<uint64_t> l_boilerplate_arr0;
    fapi2::buffer<uint64_t> l_boilerplate_arr1;

    // Set all CKE to low except the rank passed in
    l_boilerplate_arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_ARY_SRX[i_port_rank]);

    // ACT is high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ACTN>();

    // RAS high, CAS high, WE high
    l_boilerplate_arr0.setBit<TT::ARR0_DDR_ADDRESS_16>()
    .template setBit<TT::ARR0_DDR_ADDRESS_15>()
    .template setBit<TT::ARR0_DDR_ADDRESS_14>();

    // Insert idle
    l_boilerplate_arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>( i_idle );

    // From DDR4 Spec table 17:
    // All other bits from the command truth table are 'V', for valid (1 or 0)

    return instruction_t(i_port_rank, l_boilerplate_arr0, l_boilerplate_arr1);
}

///
/// @brief Setup refresh command instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the DIMM this instruction is headed for
/// @param[in] i_port_rank the port rank
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the self-refresh entry command CCS instruction
/// @note THIS IS FOR DDR4 NON-LRDIMM ONLY RIGHT NOW
///
inline instruction_t refresh_command( const uint64_t i_port_rank, const uint16_t i_idle = 0 )
{
    using TT = ccsTraits<DEFAULT_MC_TYPE>;

    // Refresh is self-refresh entry with CKE high
    auto l_refresh_template = self_refresh_entry_command(i_port_rank, i_idle);

    // CKE is high
    l_refresh_template.arr0.template insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(CKE_HIGH);

    return l_refresh_template;
}

//
// These functions are a little sugar to keep callers from doing the traits-dance to get the
// appropriate bit field
//

///
/// @brief Select the port(s) to be used by the CCS
/// @tparam MC the memory controller type which executes the CCS instruction
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = ccsTraits<MC> >
fapi2::ReturnCode select_ports( const fapi2::Target<T>& i_target, uint64_t i_ports);

///
/// @brief User sets to a '1'b to tell the Hdw to stop CCS whenever failure occurs. When a
///        '0'b, Hdw will continue CCS even if a failure occurs.
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in]  the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value true iff stop whenever failure occurs.
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline void stop_on_err( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::STOP_ON_ERR>(i_value);
}

///
/// @brief Disable ECC checking on the CCS arrays
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline void disable_ecc( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer)
{
    io_buffer.setBit<TT::DISABLE_ECC_ARRAY_CHK>()
    .template setBit<TT::DISABLE_ECC_ARRAY_CORRECTION>();
}

///
/// @brief User sets to a '1'b to force the Hdw to ignore any array ue or sue errors
///        during CCS command fetching.
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value true iff ignore any array ue or sue errors.
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline void ue_disable( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::UE_DISABLE>(i_value);
}

///
/// @brief User sets to a '1'b to force the Hdw to delay parity a cycle
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value mss::ON iff delay parity a cycle
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline void parity_after_cmd( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value)
{
    io_buffer.writeBit<TT::CFG_PARITY_AFTER_CMD>(i_value);
}

///
/// @brief DDr calibration counter
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_count the count to wait for DDR cal to complete.
/// @param[in] i_mult the DDR calibration time multiplaction factor
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline void cal_count( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer,
                       const uint64_t i_count, const uint64_t i_mult)
{
    io_buffer.insertFromRight<TT::DDR_CAL_TIMEOUT_CNT, TT::DDR_CAL_TIMEOUT_CNT_LEN>(i_count);
    io_buffer.insertFromRight<TT::DDR_CAL_TIMEOUT_CNT_MULT, TT::DDR_CAL_TIMEOUT_CNT_MULT_LEN>(i_mult);
}

///
/// @brief Copy CKE signals to CKE Spare on both ports NOTE: DOESN'T APPLY FOR NIMBUS. NO
///        SPARE CHIPS TO COPY TO. 0 - Spare CKEs not copied with values from CKE(0:1) and
///         CKE(4:5) 1 - Port A CKE(0:1) copied to Port A CKE(2:3), Port A CKE(4:5) copied
///         to Port A CKE(6:7), Port B CKE(0:1) copied to Port B CKE(2:3) and Port B CKE(4:5)
///         copied to Port B CKE(6:7)
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the ccsTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @param[in] i_value mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for p9n
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
void copy_cke_to_spare_cke( const fapi2::Target<T>&, fapi2::buffer<uint64_t>& io_buffer, const states i_value);

///
/// @brief Read the modeq register appropriate for this target
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in,out] io_buffer the buffer representing the mode register
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline fapi2::ReturnCode read_mode( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& io_buffer)
{
    return mss::getScom(i_target, TT::MODEQ_REG, io_buffer);
}

///
/// @brief Write the modeq register appropriate for this target
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_buffer the buffer representing the mode register
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline fapi2::ReturnCode write_mode( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_buffer)
{
    return mss::putScom(i_target, TT::MODEQ_REG, i_buffer);
}

///
/// @brief config the NTTM
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_mcbist the target to operate
/// @param[in] i_nttm_mode NTTM we need to turn on or off (i.e. ON, OFF)
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
inline fapi2::ReturnCode configure_nttm( const fapi2::Target<T>& i_target,
        const mss::states i_nttm_mode)
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(read_mode(i_target, l_data));

    l_data.writeBit<TT::NTTM_MODE>(i_nttm_mode);

    FAPI_TRY(write_mode(i_target, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the chip to properly execute CCS instructions
/// @tparam MC the MC type on which to operate
/// @tparam P  the port type for this CCS engine - derived from i_ports
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Code location for pre CCS execute workarounds
///
template< mss::mc_type MC, fapi2::TargetType P>
fapi2::ReturnCode setup_to_execute(const std::vector< fapi2::Target<P> >& i_ports);

///
/// @brief Cleans up the chip from executing CCS instructions
/// @tparam MC the MC type on which to operate
/// @tparam P  the port type for this CCS engine - derived from i_ports
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Code location for post CCS execute workarounds
///
template< mss::mc_type MC, fapi2::TargetType P>
fapi2::ReturnCode cleanup_from_execute(const ccs::program& i_program,
                                       const std::vector< fapi2::Target<P> >& i_ports);

///
/// @brief Start or stop the CCS engine
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[in] i_start_stop bool MSS_CCS_START for starting MSS_CCS_STOP otherwise
/// @return FAPI2_RC_SUCCESS iff success
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
fapi2::ReturnCode start_stop( const fapi2::Target<T>& i_target, const bool i_start_stop )
{
    fapi2::buffer<uint64_t> l_buf;

    // Do we need to read this? We are setting the only bit defined in the scomdef? BRS
    FAPI_TRY(mss::getScom(i_target, TT::CNTLQ_REG, l_buf));

    FAPI_TRY( mss::putScom(i_target, TT::CNTLQ_REG,
                           i_start_stop ? l_buf.setBit<TT::CCS_START>() : l_buf.setBit<TT::CCS_STOP>()) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine the CCS failure type
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target MC target
/// @param[in] i_type the failure type
/// @param[in] i_port The port the CCS instruction is training
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template< fapi2::TargetType T = DEFAULT_MC_TARGET, fapi2::TargetType P = DEFAULT_MEM_PORT_TARGET, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
fapi2::ReturnCode fail_type( const fapi2::Target<T>& i_target,
                             const uint64_t i_type,
                             const fapi2::Target<P>& i_port );

///
/// @brief Execute a CCS array already loaded in to the engine
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_program the MCBIST ccs program - to get the polling parameters
/// @param[in] i_port the port associated with the MCBIST array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
fapi2::ReturnCode execute_inst_array(const fapi2::Target<T>& i_target,
                                     ccs::program& i_program,
                                     const fapi2::Target<P>& i_port)
{
    fapi2::buffer<uint64_t> status;

    FAPI_TRY(start_stop(i_target, mss::START), "%s Error in execute_inst_array", mss::c_str(i_port) );

    mss::poll(i_target, TT::STATQ_REG, i_program.iv_poll,
              [&status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("ccs statq 0x%016lx, remaining: %d", stat_reg, poll_remaining);
        status = stat_reg;
        return status.getBit<TT::CCS_IN_PROGRESS>() != 1;
    },
    i_program.iv_probes);

    // Check for done and success. DONE being the only bit set.
    if (status == TT::STAT_QUERY_SUCCESS)
    {
        FAPI_INF("%s CCS Executed Successfully.", mss::c_str(i_port) );
        goto fapi_try_exit;
    }

    // So we failed or we're still in progress. Mask off the fail bits
    // and run this through the FFDC generator.
    FAPI_TRY(fail_type(i_target, status & TT::STAT_ERR_MASK, i_port), "Error in execute_inst_array" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute CCS loaded in to the CCS engine via the MCBIST engine
/// @tparam MC the memory controller type running CCS
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T>
fapi2::ReturnCode execute_inst_via_mcbist(const fapi2::Target<T>& i_target)
{
    mss::mcbist::program<MC> l_program;

    // Will need these to configure address range, if needed
    constexpr uint64_t START = 0;
    constexpr uint64_t END = 1;

    // Push back a ccsexec subtest (0x1111)
    l_program.iv_subtests.push_back( mss::mcbist::ccsexec_subtest<MC, T>() );

    // NOTE: Unsure if needed, if required, need to discover how to set the range up
    FAPI_TRY( mcbist::config_address_range0(i_target, START, END) );

    // Setup the polling based on lab experiments
    // Looks like tests run with 5 clock cycles or 6ns for polling, rounding to 10ns
    // Unsure if this will hold for all of CCS, but its a starting point
    l_program.iv_poll.iv_initial_delay = 10 * mss::DELAY_1NS;
    l_program.iv_poll.iv_delay = 10 * mss::DELAY_1NS;
    l_program.iv_poll.iv_poll_count = 10;

    // Kick it off, wait for a result
    FAPI_TRY( mss::mcbist::execute<MC>(i_target, l_program) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the initial delays based upon the total delays passed in
/// @tparam fapi2::TargetType T the type of the target running CCS
/// @tparam MC the memory controller type running CCS
/// @param[in] i_target the target type on which to operate
/// @param[in] i_delay the calculated delays from CCS
/// @param[in,out] io_program the program for which to update the delays
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode update_initial_delays( const fapi2::Target<T>& i_target,
        const uint64_t i_delay,
        ccs::program& io_program);

///
/// @brief Execute first part of preperation for a set of CCS instructions - multiple ports
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam MC the memory controller type running CCS
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
static inline fapi2::ReturnCode prelude_to_execution( const fapi2::Target<T>& i_target,
        ccs::program& io_program,
        const std::vector< fapi2::Target<P> >& i_ports)
{
    FAPI_INF("loading ccs instructions (%d) for %s", io_program.iv_instructions.size(), mss::c_str(i_target));

    // Pre CCS execution configuration
    FAPI_TRY(setup_to_execute<MC>(i_ports));

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( start_stop(i_target, mss::states::STOP), "Error stopping CCS engine before ccs::execution on %s",
              mss::c_str(i_target) );

    FAPI_ASSERT( mss::poll(i_target, TT::STATQ_REG, poll_parameters(),
                           [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) 0x%llx, remaining: %d", stat_reg, poll_remaining);
        return stat_reg.getBit<TT::CCS_IN_PROGRESS>() != 1;
    }),
    TT::setup_trying_to_stop_err(i_target), "CCS in progress bit timed out on %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup all the CCS registers for CCS instructions passed in
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam MC the memory controller type running CCS
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_inst_iter the iterator for the ccs instructions
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_port the port target to effect
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
static inline fapi2::ReturnCode setup_ccs_instructions( const fapi2::Target<T>& i_target,
        std::vector<mss::ccs::instruction_t>::iterator io_inst_iter,
        ccs::program& io_program,
        const fapi2::Target<P>& i_port )
{
    // Subtract one for the idle we insert at the end
    constexpr size_t CCS_INSTRUCTION_DEPTH = TT::CCS_ARRAY_LEN - 1;
    constexpr uint64_t CCS_ARR0_ZERO = TT::CCS_ARR0_START;
    constexpr uint64_t CCS_ARR1_ZERO = TT::CCS_ARR1_START;

    size_t l_inst_count = 0;
    uint64_t l_total_delay = 0;
    uint64_t l_delay = 0;
    uint64_t l_repeat = 0;
    uint8_t l_current_cke = 0;

    // Grab port index and first inst
    const auto l_port_index = mss::relative_pos<T>(i_port);
    ccs::instruction_t l_des = ccs::des_command();

    std::vector<rank_configuration> l_rank_configs;
    FAPI_TRY(get_rank_config(i_target, l_rank_configs));

    // Shove the instructions into the CCS engine, in 32 instruction chunks, and execute them
    // NOTE: For concurrent CCS the CCS_INSTRUCTION_DEPTH of 32 will never be hit
    for (; io_inst_iter != io_program.iv_instructions.end()
         && l_inst_count < CCS_INSTRUCTION_DEPTH; ++l_inst_count, ++io_inst_iter)
    {
        // First, update the current instruction's chip selects for the current port
        FAPI_TRY(io_inst_iter->configure_rank(i_port, l_rank_configs[l_port_index]),
                 "Error configuring rank in ccs::execute on port %s", mss::c_str(i_port));

        io_inst_iter->arr0.extractToRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(l_current_cke);

        // Make sure this instruction leads to the next. Notice this limits this mechanism to pretty
        // simple (straight line) CCS programs. Anything with a loop or such will need another mechanism.
        io_inst_iter->arr1.insertFromRight<TT::ARR1_GOTO_CMD, TT::ARR1_GOTO_CMD_LEN>(l_inst_count + 1);
        FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, io_inst_iter->arr0) );
        FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, io_inst_iter->arr1) );

        // arr1 contains a specification of the delay and repeat after this instruction, as well
        // as a repeat. Total up the delays as we go so we know how long to wait before polling
        // the CCS engine for completion
        io_inst_iter->arr1.extractToRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_delay);
        io_inst_iter->arr1.extractToRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(l_repeat);

        l_total_delay += l_delay * (l_repeat + 1);

        FAPI_INF("css inst %d: 0x%016lX 0x%016lX (0x%lx, 0x%lx) delay: 0x%x (0x%x) %s",
                 l_inst_count, io_inst_iter->arr0, io_inst_iter->arr1,
                 CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count,
                 l_delay, l_total_delay, mss::c_str(i_target));
    }

    // Updates the initial delays
    FAPI_TRY(update_initial_delays(i_target, l_total_delay, io_program),
             "Failed in update_initial_delays for ccs::execute_via_mcbist on %s", mss::c_str(i_target));

    FAPI_INF("executing ccs instructions via MCBIST (%d:%d, %d) for %s",
             io_program.iv_instructions.size(), l_inst_count, io_program.iv_poll.iv_initial_delay, mss::c_str(i_target));

    // Deselect
    l_des.arr0.insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(l_current_cke);

    // Insert a DES as our last instruction. DES is idle state anyway and having this
    // here as an instruction forces the CCS engine to wait the delay specified in
    // the last instruction in this array (which it otherwise doesn't do.)
    l_des.arr1.setBit<TT::ARR1_END>();
    FAPI_TRY( mss::putScom(i_target, CCS_ARR0_ZERO + l_inst_count, l_des.arr0) );
    FAPI_TRY( mss::putScom(i_target, CCS_ARR1_ZERO + l_inst_count, l_des.arr1) );

    FAPI_INF("css inst %d fixup: 0x%016lX 0x%016lX (0x%lx, 0x%lx) %s",
             l_inst_count, l_des.arr0, l_des.arr1,
             CCS_ARR0_ZERO + l_inst_count, CCS_ARR1_ZERO + l_inst_count, mss::c_str(i_target));

fapi_try_exit:
    io_program.iv_instructions.clear();
    return fapi2::current_err;
}


///
/// @brief Execute a set of CCS instructions - multiple ports
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
static inline fapi2::ReturnCode execute( const fapi2::Target<T>& i_target,
        ccs::program& io_program,
        const std::vector< fapi2::Target<P> >& i_ports)
{
    FAPI_INF("Execution standalone CCS commands (%d) for %s", io_program.iv_instructions.size(), mss::c_str(i_target));

    auto l_inst_iter = io_program.iv_instructions.begin();

    // Run prelude to execution
    FAPI_TRY( prelude_to_execution(i_target, io_program, i_ports),
              "Error setting up ccs engine before execution on %s", mss::c_str(i_target) );

    // Execute via standalone CCS
    while (l_inst_iter != io_program.iv_instructions.end())
    {
        // Kick off the CCS engine - per port. No broadcast mode for CCS (per Shelton 9/23/15)
        for (const auto& p : i_ports)
        {
            const auto l_port_index = mss::relative_pos<T>(p);

            // Run ccs instruction setup
            FAPI_TRY( setup_ccs_instructions(i_target, l_inst_iter, io_program, p),
                      "Error setting up ccs instructions in registers on %s", mss::c_str(i_target) );

            FAPI_INF("executing CCS array for port %d (%s)", l_port_index, mss::c_str(p));
            FAPI_TRY( select_ports<DEFAULT_MC_TYPE>( i_target, l_port_index),
                      "Error in port select for %s", mss::c_str(i_target) );
            FAPI_TRY( execute_inst_array(i_target, io_program, p),
                      "Error in executing ccs array for %s", mss::c_str(i_target) );
        }
    }

    // Cleans up after executing the CCS program (runs workarounds if needed)
    FAPI_TRY((cleanup_from_execute<DEFAULT_MC_TYPE>(io_program, i_ports)));

fapi_try_exit:
    io_program.iv_instructions.clear();
    return fapi2::current_err;
}

///
/// @brief Execute a set of CCS instructions via the MCBIST engine
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P  the port type for this CCS engine
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
static inline fapi2::ReturnCode execute_via_mcbist( const fapi2::Target<T>& i_target,
        ccs::program& io_program,
        const std::vector< fapi2::Target<P> >& i_ports)
{
    // Subtract one for the idle we insert at the end
    constexpr size_t CCS_INSTRUCTION_DEPTH = TT::CCS_ARRAY_LEN - 1;

    FAPI_INF("Execution CCS commands (%d) via MCBIST for %s", io_program.iv_instructions.size(), mss::c_str(i_target));

    // Get instruction count and rank info
    const uint64_t l_inst_count = io_program.iv_instructions.size();
    auto l_inst_iter = io_program.iv_instructions.begin();

    // Check that we have less than the maximum CCS instructions
    FAPI_ASSERT(l_inst_count <= CCS_INSTRUCTION_DEPTH,
                fapi2::MSS_CONCURRENT_CCS_EXCEEDS_INSTRUCTION_LIMIT()
                .set_MC_TARGET(i_target)
                .set_REQUESTED_INSTRUCTIONS(io_program.iv_instructions.size())
                .set_MAX_INSTRUCTIONS(CCS_INSTRUCTION_DEPTH),
                "%s over CCS concurrent instructions limit, requested %d instructions",
                mss::c_str(i_target), l_inst_count);


    // Run prelude to execution
    FAPI_TRY( prelude_to_execution(i_target, io_program, i_ports), "Error setting up ccs engine before execution on %s",
              mss::c_str(i_target));

    // Stop any ongoing MCBIST command
    FAPI_TRY( mss::memdiags::stop(i_target), "MCBIST engine failed to stop current command in progress on %s",
              mss::c_str(i_target) );

    // Setup CCS per port
    for (const auto& p : i_ports)
    {
        const auto l_port_index = mss::relative_pos<T>(p);

        // Run ccs instruction setup
        FAPI_TRY( setup_ccs_instructions(i_target, l_inst_iter, io_program, p),
                  "Error setting up ccs instructions in registers on %s", mss::c_str(i_target) );

        FAPI_INF("executing CCS via MCBIST for port %d (%s)", l_port_index, mss::c_str(p));
        FAPI_TRY( select_ports<DEFAULT_MC_TYPE>( i_target, l_port_index),
                  "Error in port select for ccs::execute_via_mcbist on %s", mss::c_str(i_target) );
        FAPI_TRY( execute_inst_via_mcbist(i_target), "Error in ccs::execute_inst_via_mcbist on %s", mss::c_str(i_target) );
    }

    // Cleans up after executing the CCS program (runs workarounds if needed)
    FAPI_TRY((cleanup_from_execute<DEFAULT_MC_TYPE>(io_program, i_ports)));

fapi_try_exit:
    io_program.iv_instructions.clear();
    return fapi2::current_err;
}

///
/// @brief Execute a set of CCS instructions - single port
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in] i_program the vector of instructions
/// @param[in] i_port The target that's being programmed by the array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
static inline fapi2::ReturnCode execute( const fapi2::Target<T>& i_target,
        ccs::program& i_program,
        const fapi2::Target<P>& i_port)
{
    // Mmm. Might want to find a better way to do this - seems expensive. BRS
    std::vector< fapi2::Target<P> > l_ports{ i_port };
    return execute(i_target, i_program, l_ports);
}

///
/// @brief Execute a set of CCS instructions via the MCBIST engine - single port
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam P the target of the CCS instruction (the port)
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target the target to effect
/// @param[in, out] io_program the vector of instructions
/// @param[in] i_port The target that's being programmed by the array
/// @return FAPI2_RC_SUCCSS iff ok
///
template< fapi2::TargetType T, fapi2::TargetType P, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
static inline fapi2::ReturnCode execute_via_mcbist( const fapi2::Target<T>& i_target,
        ccs::program& io_program,
        const fapi2::Target<P>& i_port)
{
    // Mmm. Might want to find a better way to do this - seems expensive. BRS
    std::vector< fapi2::Target<P> > l_ports{ i_port };
    return execute_via_mcbist(i_target, io_program, l_ports);
}

///
/// @brief Query the status of the CCS engine
/// @tparam T the target type of the chiplet which executes the CCS instruction
/// @tparam TT the CCS traits of the chiplet which executes the CCS instruction
/// @param[in] i_target The MCBIST containing the CCS engine
/// @param[out] io_status The query result first being the result, second the type
/// @return FAPI2_RC_SUCCESS iff success
///
template< fapi2::TargetType T, typename TT = ccsTraits<DEFAULT_MC_TYPE> >
fapi2::ReturnCode status_query( const fapi2::Target<T>& i_target, std::pair<uint64_t, uint64_t>& io_status );

} // ends namespace ccs
} // ends namespace mss

#endif
