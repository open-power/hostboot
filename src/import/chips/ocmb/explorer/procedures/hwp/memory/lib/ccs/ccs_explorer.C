/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/ccs_explorer.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file ccs_explorer.C
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/utils/conversions.H>
#include <lib/ccs/ccs_explorer.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>
#include <generic/memory/lib/ccs/ccs_ddr4_commands.H>
#include <generic/memory/lib/utils/bit_count.H>

// Generates linkage
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::EXPLORER>::CS_N[];
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::EXPLORER>::CS_ND[];

namespace mss
{
namespace ccs
{

///
/// @brief Configures the CCS engine
/// @param[in] i_target the target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode configure_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_ccs_config;

    FAPI_TRY( mss::ccs::read_mode<mss::mc_type::EXPLORER>(i_target, l_ccs_config),
              "%s Failed ccs read_mode",
              mss::c_str(i_target) );

    // We want to generate the parity after the command
    // Note: this is not needed for most explorer configurations (as most do not run with parity enabled)
    // However, the ones that do run with parity enabled need this logic
    mss::ccs::parity_after_cmd<mss::mc_type::EXPLORER>(i_target, l_ccs_config, mss::HIGH);

    FAPI_TRY( mss::ccs::write_mode<mss::mc_type::EXPLORER>(i_target, l_ccs_config),
              "%s Failed ccs write_mode",
              mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command - Explorer specialization
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
///
template<>
instruction_t<mss::mc_type::EXPLORER> des_command<mss::mc_type::EXPLORER>(const uint16_t i_idle)
{
    // Explorer uses DDR4 commands
    return mss::ccs::ddr4::des_command<mss::mc_type::EXPLORER>(i_idle);
}

///
/// @brief Sets any signals associated with the chip selects for this instruction - Explorer specialization
/// @param[in] i_csn01 chip selects 0 and 1
/// @param[in] i_csn23 chip selects 2 and 3
/// @param[in] i_cid the chip ID values to set
/// @param[in] i_update_cid if true, the CID is updated, if not it is ignored
/// @note This helper is created to allow different memory controllers to handle the ranks differently
/// Largely, this is to allow for different DRAM generations between memory controllers
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::set_chipselects_helper(const uint8_t i_csn01, const uint8_t i_csn23,
        const uint8_t i_cid, const bool i_update_cid)
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;

    arr0.insertFromRight<TT::ARR0_DDR_CSN_0_1,
                         TT::ARR0_DDR_CSN_0_1_LEN>(i_csn01);
    arr0.insertFromRight<TT::ARR0_DDR_CSN_2_3,
                         TT::ARR0_DDR_CSN_2_3_LEN>(i_csn23);

    // Update the chip ID's only if requested
    // Why? in DDR4 the chip ID's can be used in addressing the ranks during quad encoded chip select mode
    // However, they are not truly considered to be chip selects
    // As such, they should not always be updated when setting the chip selects
    if(i_update_cid)
    {
        arr0.insertFromRight<TT::ARR0_DDR_CID_0_1,
                             TT::ARR0_DDR_CID_0_1_LEN>(i_cid);
    }
}

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Explorer specialization
/// @param[out] o_cke the CKE for this instruction
/// @note This helper is created to allow different memory controllers to handle the CKE differently
/// Largely, this is to allow for different DRAM generations between memory controllers
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::get_cke_helper(uint8_t& o_cke) const
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;

    arr0.template extractToRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(o_cke);
}

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Explorer specialization
/// @param[in] i_cke the CKE for this instruction
/// @note This helper is created to allow different memory controllers to handle the CKE differently
/// Largely, this is to allow for different DRAM generations between memory controllers
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::set_cke_helper(const uint8_t i_cke)
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;

    arr0.template insertFromRight<TT::ARR0_DDR_CKE, TT::ARR0_DDR_CKE_LEN>(i_cke);
}

///
/// @brief Updates the idles and repeats based upon the memory controller - Explorer specialization
/// @param[in] i_target the port target for this instruction - for error logging
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::EXPLORER>::configure_idles_and_repeats(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;
    arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(iv_idles);
    arr1.template insertFromRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(iv_repeats);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Grabs the idles from the CCS array - Explorer specialization
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::get_idles()
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;
    arr1.template extractToRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(iv_idles);
}

///
/// @brief Grabs the repeats from the CCS array - Explorer specialization
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::get_repeats()
{
    using TT = ccsTraits<mss::mc_type::EXPLORER>;
    arr1.template extractToRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(iv_repeats);
}

///
/// @brief Computes and sets the parity bit - Explorer specialization
/// @param[in] i_target the port target for this instruction
/// @param[in] i_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::EXPLORER>::compute_parity(const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const rank_configuration i_rank_config)
{
    uint8_t l_is_planar = 0;
    FAPI_TRY(mss::attr::get_mem_mrw_is_planar(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target), l_is_planar));
    FAPI_TRY(compute_parity_helper(i_target, i_rank_config, l_is_planar, *this));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Computes and sets the parity bit - Explorer specialization
/// @param[in] i_target the port target for this instruction
/// @param[in] i_rank_config the rank configuration
/// @param[in] i_is_planar the value of the is planar attribute
/// @param[in,out] io_inst the instruction on which to operate
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode compute_parity_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        const rank_configuration i_rank_config,
                                        const uint8_t i_is_planar,
                                        instruction_t<mss::mc_type::EXPLORER>& io_inst)
{

    using TT = ccsTraits<mss::mc_type::EXPLORER>;

    // Parity computation is only needed if the ran configuration is in quad encoded CS mode
    // Automatic parity computation works in dual direct mode and therefore the parity will not be manually computed
    if(i_rank_config == rank_configuration::DUAL_DIRECT)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If this is not a planar system, parity is unused, so skip the manual calculations
    if(i_is_planar == fapi2::ENUM_ATTR_MEM_MRW_IS_PLANAR_FALSE)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Now the fun begins...
    // Control signals are not used in the parity calculations
    // The parity calculations use even parity
    // This means that the total number of valid signals + parity must be even
    // To compute this, count the number of 1's, then if it's odd, set the parity signal
    uint8_t l_num_signals = 0;
    uint8_t l_num_rows[mss::exp::MAX_DIMM_PER_PORT] = {};
    FAPI_TRY(mss::attr::get_dram_row_bits(i_target, l_num_rows));

    // CA17 may not be used - it depends upon the number of rows
    // Using DIMM0's number of rows. They should be the same
    if(l_num_rows[0] == fapi2::ENUM_ATTR_MEM_EFF_DRAM_ROW_BITS_NUM18)
    {
        l_num_signals += mss::bit_count<TT::ARR0_DDR_ADDRESS_17>(io_inst.arr0);
    }

    // Now for the rest of the signals
    // Just using the values individually so that it's very explicit what is being used
    l_num_signals += mss::bit_count<TT::ARR0_DDR_ADDRESS_0_13, TT::ARR0_DDR_ADDRESS_0_13_LEN>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_BANK_GROUP_1>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_BANK_0_1, TT::ARR0_DDR_BANK_0_1_LEN>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_BANK_GROUP_0>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_ACTN>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_ADDRESS_16>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_ADDRESS_15>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_ADDRESS_14>(io_inst.arr0);
    l_num_signals += mss::bit_count<TT::ARR0_DDR_CID_2>(io_inst.arr0);

    // Set the parity bit
    io_inst.arr0. template writeBit<TT::ARR0_DDR_PARITY>(mss::is_odd(l_num_signals));

    FAPI_DBG("%s manually computed CCS parity as %u", mss::c_str(i_target), mss::is_odd(l_num_signals));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configures the chip to properly execute CCS instructions - EXPLORER specialization
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode setup_to_execute<mss::mc_type::EXPLORER>(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    // Loops through all ports
    for(const auto& l_port : i_ports)
    {
        // Disables low power mode
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));

        l_data.setBit<EXPLR_SRQ_MBARPC0Q_CFG_CONC_LP_DATA_DISABLE>();

        FAPI_TRY(fapi2::putScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Cleans up from a CCS execution - multiple ports - EXPLORER specialization
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode cleanup_from_execute<mss::mc_type::EXPLORER>
(const ccs::program<mss::mc_type::EXPLORER>& i_program,
 const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    // Loops through all ports
    for(const auto& l_port : i_ports)
    {
        // Re-enable low power mode
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));

        l_data.clearBit<EXPLR_SRQ_MBARPC0Q_CFG_CONC_LP_DATA_DISABLE>();

        FAPI_TRY(fapi2::putScom(l_port, EXPLR_SRQ_MBARPC0Q, l_data));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine the CCS failure type - EXPLORER specialization
/// @param[in] i_target OCMB target
/// @param[in] i_type the failure type
/// @param[in] i_port The port the CCS instruction is training
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template<>
fapi2::ReturnCode fail_type<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_type,
        const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port )
{
    typedef ccsTraits<mss::mc_type::EXPLORER> TT;

    // Including the PORT_TARGET here and below at CAL_TIMEOUT since these problems likely lie at the MCA level
    // So we disable the PORT and hopefully that's it
    // If the problem lies with the MCBIST, it'll just have to loop
    FAPI_ASSERT(TT::STAT_READ_MISCOMPARE != i_type,
                fapi2::MSS_EXP_CCS_READ_MISCOMPARE()
                .set_MC_TARGET(i_target)
                .set_FAIL_TYPE(i_type)
                .set_PORT_TARGET(i_port),
                "%s CCS FAIL Read Miscompare", mss::c_str(i_port));

    // This error is likely due to a bad CCS engine/ MCBIST
    FAPI_ASSERT(TT::STAT_UE_SUE != i_type,
                fapi2::MSS_EXP_CCS_UE_SUE()
                .set_FAIL_TYPE(i_type)
                .set_MC_TARGET(i_target),
                "%s CCS FAIL UE or SUE Error", mss::c_str(i_target));

    // Problem with RCD parity
    FAPI_ASSERT(TT::STAT_RCD_FAIL_RCD != i_type,
                fapi2::MSS_EXP_CCS_RCD_FAIL()
                .set_FAIL_TYPE(i_type)
                .set_MC_TARGET(i_target),
                "%s CCS FAIL RCD PARITY Error", mss::c_str(i_target));

    // Problem with the CCS engine
    FAPI_ASSERT(TT::STAT_HUNG != i_type,
                fapi2::MSS_EXP_CCS_HUNG().set_MC_TARGET(i_target),
                "%s CCS appears hung", mss::c_str(i_target));

fapi_try_exit:
    // Due to the PRD update, we need to check for FIR's
    // If any FIR's have lit up, this CCS fail could have been caused by the FIR
    // So, let PRD retrigger this step to see if we can resolve the issue
    return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER, mss::check::firChecklist::CCS>(i_target, fapi2::current_err);
}

///
/// @brief EXP specialization for modeq_copy_cke_to_spare_cke
/// @param[in] fapi2::Target<TARGET_TYPE_OCMB_CHIP>& the target to effect
/// @param[in,out] the buffer representing the mode register
/// @param[in] mss::states - mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for p9n
///
template<>
void copy_cke_to_spare_cke<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        fapi2::buffer<uint64_t>&, states )
{
    return;
}

///
/// @brief Select the port(s) to be used by the CCS - EXPLORER specialization
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
///
template<>
fapi2::ReturnCode select_ports<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint64_t i_ports)
{
    // No broadcast mode, only one port, so no port selection
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Determines our rank configuration type - Explorer specialization
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode get_rank_config<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        rank_configuration& o_rank_config)
{
    typedef ccsTraits<mss::mc_type::EXPLORER> TT;
    constexpr uint8_t QUAD_RANK_ENABLE = 4;
    o_rank_config = rank_configuration::DUAL_DIRECT;

    uint8_t l_num_master_ranks[TT::CCS_MAX_DIMM_PER_PORT] = {};
    bool l_has_rcd = false;
    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_num_master_ranks));
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

} // namespace ccs
} // namespace mss
