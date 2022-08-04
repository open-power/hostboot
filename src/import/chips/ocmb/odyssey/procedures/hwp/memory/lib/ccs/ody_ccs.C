/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_ccs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_ccs.C
/// @brief Odyssey CCS specializations
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/ecc/ecc_traits_odyssey.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/utils/conversions.H>
#include <lib/ccs/ody_ccs.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <ody_scom_ody_odc.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>

// Generates linkage
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::ODYSSEY>::CS_N[];
constexpr std::pair<uint64_t, uint64_t> ccsTraits<mss::mc_type::ODYSSEY>::CS_ND[];

namespace mss
{
namespace ccs
{

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command - Odyssey specialization
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
///
template<>
instruction_t<mss::mc_type::ODYSSEY> des_command<mss::mc_type::ODYSSEY>(const uint16_t i_idle)
{
    // Odyssey uses DDR4 commands
    return mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(i_idle);
}

///
/// @brief Sets any signals associated with the chip selects for this instruction - Odyssey specialization
/// @param[in] i_csn01 chip selects 0 and 1
/// @param[in] i_csn23 chip selects 2 and 3
/// @param[in] i_cid the chip ID values to set
/// @param[in] i_update_cid if true, the CID is updated, if not it is ignored
/// @note Odyssey specialization CS01 is for command 0, while CS23 is for command 1
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::set_chipselects_helper(const uint8_t i_csn01, const uint8_t i_csn23,
        const uint8_t i_cid, const bool i_update_cid)
{
    using TT = ccsTraits<mss::mc_type::ODYSSEY>;

    arr0.insertFromRight<TT::ARR0_CMD0_CSN_0_1,
                         TT::ARR0_CMD0_CSN_0_1_LEN>(i_csn01);
    arr0.insertFromRight<TT::ARR0_CMD1_CSN_0_1,
                         TT::ARR0_CMD1_CSN_0_1_LEN>(i_csn23);

    // CID and update CID are unused (no quad encoded chip select in DDR5)
}

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Odyssey specialization
/// @param[out] o_cke the CKE for this instruction
/// @note nothing to do for Odyssey
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_cke_helper(uint8_t& o_cke) const
{
}

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Odyssey specialization
/// @param[in] i_cke the CKE for this instruction
/// @note nothing to do for Odyssey
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::set_cke_helper(const uint8_t i_cke)
{
}

///
/// @brief Gets the register value for the idles/repeats multiplier
/// @param[in] i_idles the requested number of idles
/// @param[in] i_repeats the requested number of repeats
/// @return the register value for the idles/repeats multiplier
///
uint8_t get_inst_idle_reg_multiplier(const uint16_t i_idles, const uint16_t i_repeats)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    // First up, gets the multiplier
    const uint16_t MAX = std::max(i_idles, i_repeats);

    // The multiplier is just computed based upon the max
    // If the max is less than X padding amount, that's the amount to use
    if(MAX < TT::delay_padding::PADDING_NO_END)
    {
        return TT::delay_padding::REG_MULTIPLIER_0;
    }

    if(MAX < TT::delay_padding::PADDING_2_END)
    {
        return TT::delay_padding::REG_MULTIPLIER_2;
    }

    if(MAX < TT::delay_padding::PADDING_4_END)
    {
        return TT::delay_padding::REG_MULTIPLIER_4;
    }

    // Otherwise, use the max (8 padding bits)
    return TT::delay_padding::REG_MULTIPLIER_8;
}

///
/// @brief Gets the numeric value for the idles/repeats multiplier
/// @param[in] i_reg_multiplier the register value (0b00 to 0b11)
/// @return the register numeric for the idles/repeats multiplier
///
uint16_t get_inst_idle_numeric_multiplier(const uint8_t i_reg_multiplier)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    uint16_t l_mult = TT::delay_padding::NUM_MULTIPLIER_0;

    switch(i_reg_multiplier)
    {
        case TT::delay_padding::REG_MULTIPLIER_0:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_0;
            break;

        case TT::delay_padding::REG_MULTIPLIER_2:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_2;
            break;

        case TT::delay_padding::REG_MULTIPLIER_4:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_4;
            break;

        case TT::delay_padding::REG_MULTIPLIER_8:
        default:
            l_mult = TT::delay_padding::NUM_MULTIPLIER_8;
            break;
    }

    return l_mult;
}

///
/// @brief Updates the idles and repeats based upon the memory controller - Odyssey specialization
/// @param[in] i_target the port target for this instruction - for error logging
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::ODYSSEY>::configure_idles_and_repeats(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target )
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    // First grab the multipler
    const auto l_reg_multiplier = get_inst_idle_reg_multiplier(iv_idles, iv_repeats);
    const auto l_num_multiplier = get_inst_idle_numeric_multiplier(l_reg_multiplier);

    // Now, recompute idle and repeat values
    // We always want to round up for our number of idles and repeats
    // If there is a remainder, add in the multiplier to the register value to round up
    // More delay is always better than not enough
    const uint8_t l_idles_reg = (iv_idles / l_num_multiplier) + ((iv_idles % l_num_multiplier) == 0 ? 0 : 1);
    const uint8_t l_repeats_reg = (iv_repeats / l_num_multiplier) + ((iv_repeats % l_num_multiplier) == 0 ? 0 : 1);

    arr1.template insertFromRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_idles_reg)
    .template insertFromRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(l_repeats_reg)
    .template insertFromRight<TT::ARR1_PADDING, TT::ARR1_PADDING_LEN>(l_reg_multiplier);

    // At the end, get the idles and the repeats
    // This forces the updates to be in sync with what is in the instructions
    get_idles();
    get_repeats();

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Grabs the idles from the CCS array - Odyssey specialization
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_idles()
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    uint8_t l_reg_idles = 0;
    uint8_t l_reg_padding = 0;
    arr1.template extractToRight<TT::ARR1_IDLES, TT::ARR1_IDLES_LEN>(l_reg_idles)
    .template extractToRight<TT::ARR1_PADDING, TT::ARR1_PADDING_LEN>(l_reg_padding);

    const auto l_num_multiplier = get_inst_idle_numeric_multiplier(l_reg_padding);
    iv_idles = l_reg_idles * l_num_multiplier;
}

///
/// @brief Grabs the repeats from the CCS array - Odyssey specialization
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_repeats()
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    uint8_t l_reg_repeats = 0;
    uint8_t l_reg_padding = 0;
    arr1.template extractToRight<TT::ARR1_REPEAT_CMD_CNT, TT::ARR1_REPEAT_CMD_CNT_LEN>(l_reg_repeats)
    .template extractToRight<TT::ARR1_PADDING, TT::ARR1_PADDING_LEN>(l_reg_padding);

    const auto l_num_multiplier = get_inst_idle_numeric_multiplier(l_reg_padding);
    iv_repeats = l_reg_repeats * l_num_multiplier;
}

///
/// @brief Grabs the repeats from the CCS array - Odyssey specialization
/// @param[in] i_target the port target for this instruction
/// @param[in] i_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::ODYSSEY>::compute_parity(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target, const rank_configuration i_rank_config)
{
    // Odyssey does not need to manually compute parity at this time
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Configures the chip to properly execute CCS instructions - ODYSSEY specialization
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode setup_to_execute<mss::mc_type::ODYSSEY>(
    const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    // Loops through all ports
    for(const auto& l_port : i_ports)
    {
        const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

        // Disables low power mode
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(l_ocmb, scomt::ody::ODC_SRQ_MBARPC0Q, l_data));

        l_data.setBit<scomt::ody::ODC_SRQ_MBARPC0Q_CFG_CONC_LP_DATA_DISABLE>();

        FAPI_TRY(fapi2::putScom(l_ocmb, scomt::ody::ODC_SRQ_MBARPC0Q, l_data));

        // Only one of these register per chip, so no need to continue looping
        break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Cleans up from a CCS execution - multiple ports - ODYSSEY specialization
/// @param[in] i_program the vector of instructions
/// @param[in] i_ports the vector of ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template<>
fapi2::ReturnCode cleanup_from_execute<mss::mc_type::ODYSSEY>
(const ccs::program<mss::mc_type::ODYSSEY>& i_program,
 const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_ports)
{
    // Loops through all ports
    for(const auto& l_port : i_ports)
    {
        const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

        // Re-enable low power mode
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(l_ocmb, scomt::ody::ODC_SRQ_MBARPC0Q, l_data));

        l_data.clearBit<scomt::ody::ODC_SRQ_MBARPC0Q_CFG_CONC_LP_DATA_DISABLE>();

        FAPI_TRY(fapi2::putScom(l_ocmb, scomt::ody::ODC_SRQ_MBARPC0Q, l_data));

        // Only one of these register per chip, so no need to continue looping
        break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determine the CCS failure type - ODYSSEY specialization
/// @param[in] i_target OCMB target
/// @param[in] i_type the failure type
/// @param[in] i_port The port the CCS instruction is training
/// @return ReturnCode associated with the fail.
/// @note FFDC is handled here, caller doesn't need to do it
///
template<>
fapi2::ReturnCode fail_type<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_type,
        const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port )
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;

    // Including the PORT_TARGET here and below at CAL_TIMEOUT since these problems likely lie at the MEM_PORT/PHY level
    // So we disable the PORT and hopefully that's it
    // If the problem lies with the OCMB_CHIP (Odyssey memory controller), it'll just have to loop
    FAPI_ASSERT(TT::STAT_READ_MISCOMPARE != i_type,
                fapi2::MSS_ODY_CCS_READ_MISCOMPARE()
                .set_MC_TARGET(i_target)
                .set_FAIL_TYPE(i_type)
                .set_PORT_TARGET(i_port),
                "%s CCS FAIL Read Miscompare", mss::c_str(i_port));

    // This error is likely due to a bad CCS engine/ Odyssey chip
    FAPI_ASSERT(TT::STAT_UE_SUE != i_type,
                fapi2::MSS_ODY_CCS_UE_SUE()
                .set_FAIL_TYPE(i_type)
                .set_MC_TARGET(i_target),
                "%s CCS FAIL UE or SUE Error", mss::c_str(i_target));

    // Problem with the CCS engine
    FAPI_ASSERT(TT::STAT_HUNG != i_type,
                fapi2::MSS_ODY_CCS_HUNG().set_MC_TARGET(i_target),
                "%s CCS appears hung", mss::c_str(i_target));
fapi_try_exit:
    // Due to the PRD update, we need to check for FIR's
    // If any FIR's have lit up, this CCS fail could have been caused by the FIR
    // So, let PRD retrigger this step to see if we can resolve the issue
    return mss::check::fir_or_pll_fail<mss::mc_type::ODYSSEY, mss::check::firChecklist::CCS>(i_target, fapi2::current_err);
}

///
/// @brief EXP specialization for modeq_copy_cke_to_spare_cke
/// @param[in] fapi2::Target<TARGET_TYPE_OCMB_CHIP>& the target to effect
/// @param[in,out] the buffer representing the mode register
/// @param[in] mss::states - mss::ON iff Copy CKE signals to CKE Spare on both ports
/// @note no-op for Odyssey
///
template<>
void copy_cke_to_spare_cke<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        fapi2::buffer<uint64_t>&, states )
{
    return;
}

///
/// @brief Select the port(s) to be used by the CCS - ODYSSEY specialization
/// @param[in] i_target the target to effect
/// @param[in] i_ports the buffer representing the ports
/// @note Only supports a single MEM_PORT at a time right now with both channels being selected
///
template<>
fapi2::ReturnCode select_ports<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint64_t i_ports)
{
    typedef ccsTraits<mss::mc_type::ODYSSEY> TT;
    constexpr uint64_t PORT0 = 0b1100;
    constexpr uint64_t PORT1 = 0b0011;
    const auto l_port_value = i_ports == 0 ? PORT0 : PORT1;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY( mss::getScom(i_target, TT::MODEQ_REG, l_data) );
    l_data.insertFromRight<TT::PORT_SEL, TT::PORT_SEL_LEN>(l_port_value);
    FAPI_TRY( mss::putScom(i_target, TT::MODEQ_REG, l_data) );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines our rank configuration type - Odyssey specialization
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode get_rank_config<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        rank_configuration& o_rank_config)
{
    // Odyssey only supports dual direct
    o_rank_config = rank_configuration::DUAL_DIRECT;
    return fapi2::FAPI2_RC_SUCCESS;
}

} // namespace ccs
} // namespace mss
