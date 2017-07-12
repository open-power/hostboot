/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/dp16_workarounds.H $ */
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
/// @file workarounds/dp16.H
/// @brief Workarounds for the DP16 logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_DP16_H_
#define _MSS_WORKAROUNDS_DP16_H_

#include <fapi2.H>
#include <map>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <mss_attribute_accessors.H>
#include <lib/phy/dp16.H>

namespace mss
{

namespace workarounds
{

namespace dp16
{

///
/// @brief DQS polarity workaround
/// For Monza DDR port 2, one pair of DQS P/N is swapped polarity.  Not in DDR port 6
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called during the phy scom init procedure, after the initfile is
/// processed. It is specific to the Monza module, but can be called for all modules as it
/// will enforce its requirements internally
///
fapi2::ReturnCode dqs_polarity( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 Read Diagnostic Configuration 5 work around
/// Not in the Model 67 spydef, so we scom them. Should be removed when they are
/// added to the spydef.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode rd_dia_config5( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 DQSCLK Offset work around
/// Not in the Model 67 spydef, so we scom them. Should be removed when they are
/// added to the spydef.
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode dqsclk_offset( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 VREF DAC override
/// In DD1.0 Nimbus VREF DAC work arounds are needed
/// @param[in] i_target the port target for this override
/// @param[in] i_original_value a value to which we add the workaround bits
/// @return uint64_t the original value with the bits added
///
inline uint64_t vref_dac( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_original_value )
{
    fapi2::buffer<uint64_t> l_value(i_original_value);

    // Check for whether we apply this workaround or not
    if (! mss::chip_ec_feature_mss_vref_dac(i_target) )
    {
        return i_original_value;
    }

    // We have an attribute for VREF DAC nibble, if it's 0 then we'll not do anything
    uint8_t l_vref_dac_nibble = 0;
    FAPI_TRY( mss::vref_dac_nibble(i_target, l_vref_dac_nibble) );

    // We want to set the EN_FORCE on no matter what.
    l_value.setBit<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0_EN_FORCE>()
    .setBit<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1_EN_FORCE>();

    // But we only give a new value if they asked for one in the attribute
    if (l_vref_dac_nibble != 0)
    {
        l_value.insertFromRight<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0,
                                MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB0_LEN>(l_vref_dac_nibble)
                                .insertFromRight<MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1,
                                MCA_DDRPHY_DP16_RD_VREF_BYTE0_DAC_P0_0_01_NIB1_LEN>(l_vref_dac_nibble);
    }

    FAPI_INF("vref_dac 0x%016lx, 0x%016lx", i_original_value, uint64_t(l_value));
    return l_value;

fapi_try_exit:
    // Probably bigger problems ...
    FAPI_ERR("Unable to get vref_dac_nibble attribute");
    fapi2::Assert(false);

    // Not reached
    return 0;
}

///
/// @brief DP16 workarounds to be run after PHY reset
/// In DD1.0 Nimbus various work arounds are needed
/// @param[in] i_target the fapi2 target of the controller
/// @return fapi2::ReturnValue FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode after_phy_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Updates gate delay and blue waterfall (aka RDCLK phase select) values based upon blue waterfall values
/// @param[in,out] io_blue_waterfall - the blue waterfall value
/// @param[in,out] io_gate_delay     - the gate delay value
///
inline void update_blue_waterfall_gate_delay(uint64_t& io_blue_waterfall, uint64_t& io_gate_delay)
{
    // The PHY should never have a blue waterfall value of a 0 - if so, change it to a 3, and decrease one off the gate delay
    // The blue waterfall is a quarter clock cycle delay - the current thinking is that a value of a 0 is a value of a 4
    // In this case the delay was large enough, so that a value of a 3 rolled over to another clock cycle.
    // The value of a 0 is considered to be incorrect but can be passable, as the gate delay calibrates in an extra cycle of delay
    // So, if there is a 0 value in the blue waterfall, change it to the max, a 3, and subtract one off the gate delay to have correct timing
    constexpr uint64_t BW_INCORRECT = 0;
    constexpr uint64_t BW_MAX = 3;

    // Check if a correction is needed
    if(io_blue_waterfall == BW_INCORRECT)
    {
        io_blue_waterfall = BW_MAX;
        // Does a check to make sure the value doesn't underflow
        io_gate_delay     = ((io_gate_delay == 0) ? 0 : (io_gate_delay - 1));
    }
}

///
/// @brief Gets the blue waterfall and gate delay values for a given DP quad
/// @tparam uint64_t QUAD - which quad to access
/// @param[in,out] io_waterfall_reg   - waterfall register data
/// @param[in,out] io_gate_reg        - gate delay register information
///
template< uint64_t QUAD>
void update_blue_waterfall_gate_delay_for_quad(fapi2::buffer<uint64_t>& io_waterfall_reg,
        fapi2::buffer<uint64_t>& io_gate_reg)
{
    constexpr uint64_t NUM_QUAD = 4;
    // Valid quad values are from 0-3, exit if the requested value is greater
    static_assert(QUAD < NUM_QUAD, "Inserted quad value is greater than or equal to 4");

    // Gets the data for this Quad
    auto l_blue_waterfall = mss::dp16::get_blue_waterfall<QUAD>(io_waterfall_reg);
    auto l_gate_delay     = mss::dp16::get_gate_delay<QUAD>(io_gate_reg);

    // Updates the waterfall and gate delay
    update_blue_waterfall_gate_delay(l_blue_waterfall, l_gate_delay);

    // Sets the data back into the register
    mss::dp16::set_blue_waterfall<QUAD>(io_waterfall_reg, l_blue_waterfall);
    mss::dp16::set_gate_delay<QUAD>(io_gate_reg, l_gate_delay);
}

///
/// @brief Fixes blue waterfall values in a port
/// @param[in] i_target - the target to operate on
/// @param[in] i_always_run - ignores the attribute and always run - default = false - this is used in lab code to force the workaround to be run
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode fix_blue_waterfall_gate( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const bool i_always_run = false );

///
/// @brief Modifies HW calibration results based upon workarounds
/// @param[in]  i_target - the target to operate on
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode modify_calibration_results( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Cleans up the VREF sense values after training
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called after training - it will only be run after coarse wr/rd
///
fapi2::ReturnCode rd_vref_vref_sense_cleanup( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Sets up the VREF sense values before training
/// @param[in] i_target the fapi2 target of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called before training
///
fapi2::ReturnCode rd_vref_vref_sense_setup( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );


///
/// @brief Workarounds for after training
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_cal_steps_enabled the enabled cal steps
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note This function is called after training - it will only be run after coarse wr/rd
///
fapi2::ReturnCode post_training_workarounds( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::buffer<uint32_t>& i_cal_steps_enabled );

namespace dqs_align
{

///
/// @brief Runs the DQS workaround
/// @param[in] i_target
/// @param[in] i_rp
/// @param[in] i_abort_on_error CAL_ABORT_ON_ERROR override
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode dqs_align_workaround(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_rp,
                                       const uint8_t i_abort_on_error = fapi2::ENUM_ATTR_MSS_CAL_ABORT_ON_ERROR_NO);

///
/// @brief Checks if the DQS align workaround needs to be run
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp rank pair to check
/// @param[out] o_skip_workaround - YES if cal should be skipped
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note the workaround needs to be run IFF we failed DQS align
///
fapi2::ReturnCode check_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rp,
                                    mss::states& o_skip_workaround );

///
/// @brief Resets bad DQ/DQS bits
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to operate on
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode reset_disables( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_rp );

///
/// @brief Records the passing values into a map
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to operate on
/// @param[in,out] io_passing_values - the passing values, a map from the DQS number to the value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode record_passing_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_rp,
        std::map<uint64_t, uint64_t>& io_passing_values);

///
/// @brief Sets the passing values from the map into the registers
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to operate on
/// @param[in] i_passing_values - the passing values, a map from the DQS number to the value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode set_passing_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_rp,
                                      std::map<uint64_t, uint64_t>& i_passing_values);

///
/// @brief Records the passing values for a DP/quad
/// @tparam uint64_t QUAD - the quad to operate on
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rp - the rank pair to operate on
/// @param[in] i_dp - the DP
/// @param[in] i_quad - the quad
/// @param[in] i_disable_bits - pair of disable bit 0/1's
/// @param[in] i_rd_clk_reg - pair of RD clk registers
/// @param[in,out] io_passing_values - the passing values, a map from the DQS number to the value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template <uint64_t QUAD>
fapi2::ReturnCode record_passing_values_per_dqs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        const uint64_t i_dp,
        const std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>& i_disable_bits,
        const std::pair<fapi2::buffer<uint64_t>, fapi2::buffer<uint64_t>>& i_rd_clk_reg,
        std::map<uint64_t, uint64_t>& io_passing_values)
{
    // Declares constexprs
    constexpr uint64_t MAX_QUAD_PER_DP = NIBBLES_PER_DP;
    constexpr uint64_t MAX_DP = 4;
    constexpr uint64_t NUM_QUADS_PER_DP4 = 2;
    constexpr uint64_t PHY_REG_START = 48;
    constexpr uint64_t DISABLE0_BITS_PER_QUAD = 4;
    constexpr uint64_t DISABLE1_BITS_PER_QUAD = 2;
    constexpr uint64_t DISABLE0_START = PHY_REG_START + (QUAD * DISABLE0_BITS_PER_QUAD);
    constexpr uint64_t DISABLE1_START = PHY_REG_START + (QUAD * DISABLE1_BITS_PER_QUAD);

    static_assert(QUAD < MAX_QUAD_PER_DP, "QUAD value is not less than the maximum value");

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // TK make this a real error
    if(i_dp > MAX_DP)
    {
        FAPI_ERR("%s i_rp %s DP %lu is out of bounds", mss::c_str(i_target), i_rp, i_dp);
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // Skips DP4 non-existant quads
    if((QUAD >= NUM_QUADS_PER_DP4) && (i_dp == MAX_DP))
    {
        FAPI_INF("%s i_rp %lu skipping non existant DP%lu QUAD%lu", mss::c_str(i_target), i_rp, i_dp, QUAD)
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Gets the bits to check
    const auto l_disable0 = i_disable_bits.first.getBit<DISABLE0_START, DISABLE0_BITS_PER_QUAD>();
    const auto l_disable1 = i_disable_bits.second.getBit<DISABLE1_START, DISABLE1_BITS_PER_QUAD>();
    const auto l_disable = l_disable0 || l_disable1;

    FAPI_DBG("%s i_rp %lu disable0 0x%016lx, disable1 0x%016lx %lu %lu", mss::c_str(i_target), i_rp,
             uint64_t(i_disable_bits.first), uint64_t(i_disable_bits.second), DISABLE0_START, DISABLE1_START);

    // Gets the register to operate on
    const auto l_data = QUAD < 2 ? i_rd_clk_reg.first : i_rd_clk_reg.second;
    constexpr uint64_t START = QUAD % 2 == 0 ? MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0_01_ROT_CLK_N0 :
                               MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0_01_ROT_CLK_N1;
    constexpr uint64_t LEN = MCA_DDRPHY_DP16_DQSCLK_PR0_RANK_PAIR0_P0_0_01_ROT_CLK_N0_LEN;

    FAPI_INF("%s i_rp %lu DP%lu QUAD%lu %s", mss::c_str(i_target), i_rp, i_dp, QUAD,
             l_disable ? "failed - skipping assignment" : "passed - assigning value");
    FAPI_DBG("%s i_rp %lu DP%lu QUAD%lu value 0x%016lx bit pos %lu", mss::c_str(i_target), i_rp, i_dp, QUAD,
             uint64_t(l_data), START);

    // Only extract the values for the ones that passed
    if(!l_disable)
    {
        const auto l_nibble = i_dp * MAX_QUAD_PER_DP + QUAD;
        uint64_t l_value = 0;
        l_data.extractToRight<START, LEN>(l_value);
        io_passing_values[l_nibble] = l_value;
        FAPI_INF("%s i_rp %lu DP%lu QUAD%lu value: %lu", mss::c_str(i_target), i_rp, i_dp, QUAD, l_value);
    }

    return fapi2::current_err;
}

///
/// @brief Checks if the workaround has finished
/// @param[in] i_passing_values - the passing values, a map from the DQS number to the value
/// @param[in] i_expected - the number of DRAM/DQS expected
/// @return bool - true if the the map of passing values is full
///
inline bool check_completed( const std::map<uint64_t, uint64_t>& i_passing_values, const uint64_t i_expected)
{
    return i_passing_values.size() == i_expected;
}

} // close namespace dqs_align

namespace rd_dq
{

///
/// @brief Declares a struct to simplify the rd_dq workaround
///
struct delay_data
{
    // Deletes base constructor
    delay_data() = delete;

    ///
    /// @brief Constructor
    /// @param[in] i_register - register info
    /// @param[in] i_bit - bit position info
    /// @param[in] i_data - data stored in the register
    ///
    delay_data(const uint64_t i_register, const uint64_t i_bit, const uint64_t& i_data) :
        iv_register(i_register),
        iv_bit(i_bit),
        iv_data(i_data)
    {}

    ///
    /// @brief Default destructor
    ///
    ~delay_data() = default;

    ///
    /// @brief Comparison operator
    /// @param[in] i_rhs - delay_info to compare against
    /// @return bool - true if the right hand side is greater
    bool operator<(const delay_data& i_rhs) const
    {
        // For this class, we only care about the delay value
        return iv_data < i_rhs.iv_data;
    }

    static constexpr uint64_t LEN = MCA_DDRPHY_DP16_READ_DELAY0_RANK_PAIR0_P0_0_01_RD_LEN;
    uint64_t iv_register;
    uint64_t iv_bit;
    uint64_t iv_data;
};

///
/// @brief Reads out the read dq registers and stores the values in a vector
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rank_pair the rank pair to operate on
/// @param[out] o_reg_data register conglomerate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_delay_data(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                 const uint64_t i_rank_pair,
                                 std::vector<delay_data>& o_reg_data);

///
/// @brief Finds the median and sorts the vector
/// @param[in,out] io_reg_data register data
/// @param[out] o_median the median value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode find_median_and_sort(std::vector<delay_data>& io_reg_data, uint64_t& o_median);

///
/// @brief Overrides any bad (out of range) read delay values with the median value
/// @param[in] i_target the fapi2 target of the port
/// @param[in] i_rank_pair the rank pair to operate on
/// @param[in] i_percent the percentage below the median outside of which to override values to be the median - OPTIONAL - defaults to 75
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode fix_delay_values(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rank_pair,
                                   const uint64_t i_percent = 75);

} // close namespace rd_dq

namespace wr_vref
{

///
/// @brief DP16 WR VREF error latching workaround
/// In DD1 Nimbus in the WR VREF algorithm, DRAM's 2/3 latch over error information from DRAM's 0/1.
/// The workaround is to set the error mask for DRAM's 2/3 to be 0xFFFF (informational but not errors)
/// @param[in] i_target the fapi2 target type MCA of the port
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode error_dram23( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief DP16 big step/small step check and modify workaround
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure that the big step is divisible by the small step
/// This function converts the small step value over to the closest allowable value as to what was entered
/// @tparam T fapi2 Target Type - just here to ensure that this won't be called on a non-Nimbus system
/// @param[in] i_big_step - WR VREF big step value
/// @param[in,out] io_small_step - WR VREF small step value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode modify_small_step_for_big_step(const uint8_t i_big_step, uint8_t& io_small_step);

///
/// @brief DP16 writes config 0 overriding bad small step/big step values
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure that the big step is divisible by the small step
/// This function converts the small step value over to the closest allowable value as to what was entered
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[out] o_big_step - WR VREF big step value
/// @param[out] o_small_step - WR VREF small step value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode write_config0( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint8_t& o_big_step,
                                 uint8_t& o_small_step);

///
/// @brief DP16 converts the VREF training values to start calibration
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure the WR VREF is an integer number of big steps away from the 0 value and one big step from the top of the range
/// This function converts values over to the required rules
/// @tparam T fapi2 Target Type - just here to ensure that this won't be called on a non-Nimbus system
/// @param[in] i_big_step - WR VREF big step value
/// @param[in,out] io_train_range - VREF train range converted value
/// @param[in,out] io_train_value - VREF train value converted value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode convert_train_values( const uint8_t i_big_step,
                                        uint8_t& io_train_range,
                                        uint8_t& io_train_value);

///
/// @brief DP16 gets the VREF training values to start calibration
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure the WR VREF is an integer number of big steps away from the 0 value and one big step from the top of the range
/// This function gets and converts the train values over to good values
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_big_step - WR VREF big step value
/// @param[out] o_train_range - JEDEC MR6 WR VREF training range
/// @param[out] o_train_value - JEDEC MR6 WR VREF training value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode get_train_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rp,
                                    const uint8_t i_big_step,
                                    uint8_t& o_train_range,
                                    uint8_t& o_train_value);

///
/// @brief DP16 sets up the VREF train range and value. also sets up the VREF value registers
/// In DD1 Nimbus in the WR VREF algorithm, the out of bounds checks are broken.
/// One aspect of fixing this bug is to ensure the WR VREF is an integer number of big steps away from the 0 value and one big step from the top of the range
/// This function converts the WR VREF values over to be good values and writes the good values out to the chip
/// @param[in] i_target the fapi2 target type MCA of the port
/// @param[in] i_rp - rank pair to check and modify
/// @param[out] o_train_range - JEDEC MR6 WR VREF training range
/// @param[out] o_train_value - JEDEC MR6 WR VREF training value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode setup_values( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                const uint64_t i_rp,
                                uint8_t& o_train_range,
                                uint8_t& o_train_value);

} // close namespace wr_vref
} // close namespace dp16
} // close namespace workarounds
} // close namespace mss

#endif
