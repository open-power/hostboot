/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/mss_training.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
/// @file workarounds/mss_training_workarounds.H
/// @brief High level workarounds for training
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_WORKAROUNDS_TRAINING_H
#define MSS_WORKAROUNDS_TRAINING_H

#include <fapi2.H>
#include <lib/eff_config/timing.H>
#include <lib/dimm/ddr4/latch_wr_vref_nimbus.H>

namespace mss
{

namespace training
{

///
/// @brief Training step class - contains all information to run a calibration step
/// @note step is an abstract class
///
class step
{
    public:
        // Delete base constructor
        step() = delete;

        ///
        /// @brief Default virtual destructor
        ///
        virtual ~step() = default;

        ///
        /// @brief Constructor for step class
        /// @param[in] i_name - calibration step name
        ///
        step( const char* i_name) :
            iv_name(i_name)
        {}

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        virtual fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                const uint64_t i_rp,
                const uint8_t i_abort_on_error ) const
        {
            FAPI_INF("%s RP%d cal step '%s' has no pre-cal step workaround.", mss::c_str(i_target), i_rp, iv_name);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        virtual fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_rp,
                                       const uint8_t i_abort_on_error ) const = 0;

        ///
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        virtual fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                const uint64_t i_rp,
                const uint8_t i_abort_on_error ) const
        {
            FAPI_INF("%s RP%d cal step '%s' has no post-cal step workaround.", mss::c_str(i_target), i_rp, iv_name);
            return fapi2::FAPI2_RC_SUCCESS;
        }

        ///
        /// @brief Executes a cal step with workarounds
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        virtual fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        virtual uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const = 0;

        ///
        /// @brief Gets the name of this calibration step
        /// @return name of this calibration step
        ///
        const char* get_name() const
        {
            return iv_name;
        }

    private:
        // Contains the human readable name for this calibration step
        const char* iv_name;
};

///
/// @brief Latches the WR VREF data into the hardware
///
class wr_vref_latch : public step
{
    public:
        // Delete base constructor
        wr_vref_latch() = delete;

        ///
        /// @brief Default destructor
        ///
        ~wr_vref_latch() override = default;

        ///
        /// @brief Constructor for step class
        /// @param[in] i_wr_vref - true if WR VREF will be run during the calibration
        ///
        wr_vref_latch( const bool i_wr_vref ) :
            step("WR_VREF_LATCH"),
            iv_wr_vref(i_wr_vref),
            iv_vrefdq_train_range_override(mss::ddr4::USE_DEFAULT_WR_VREF_SETTINGS),
            iv_vrefdq_train_value_override(mss::ddr4::USE_DEFAULT_WR_VREF_SETTINGS)
        {}

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          const uint64_t i_rp,
                                          const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;

        ///
        /// @brief Getter for WR VREF
        /// @return bool iv_wr_vref
        ///
        bool get_wr_vref() const
        {
            return iv_wr_vref;
        }

        ///
        /// @brief Getter for WR VREF
        /// @return uint64_t iv_vrefdq_train_range_override
        ///
        uint64_t get_vrefdq_range() const
        {
            return iv_vrefdq_train_range_override;
        }

        ///
        /// @brief Getter for WR VREF
        /// @return uint64_t iv_vrefdq_train_value_override
        ///
        uint64_t get_vrefdq_value() const
        {
            return iv_vrefdq_train_value_override;
        }

    private:
        // Notes whether the WR VREF calibration workaround needs to be run or not
        bool iv_wr_vref;

        // WR VREF values to latch
        // Note: these are mutable as they might need to be modified for a workaround related to Nimbus DD1 WR VREF HW calibration
        mutable uint8_t iv_vrefdq_train_range_override;
        mutable uint8_t iv_vrefdq_train_value_override;
};

///
/// @brief A PHY hardware accelerated calibration step
/// @note phy_step is an abstract class
///
class phy_step : public step
{
    public:
        // Delete base constructor
        phy_step() = delete;

        ///
        /// @brief Default destructor
        ///
        virtual ~phy_step() = default;

        ///
        /// @brief Constructor for step class
        /// @param[in] i_init_cal_config - calibration step name
        /// @param[in] i_name - calibration step name
        ///
        phy_step( const fapi2::buffer<uint64_t> i_init_cal_config, const char* i_name) :
            step(i_name),
            iv_init_cal_config(i_init_cal_config)
        {}

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        virtual fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       const uint64_t i_rp,
                                       const uint8_t i_abort_on_error ) const;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        virtual uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const = 0;

        ///
        /// @brief Gets the init cal config register's starting
        /// @return fapi2::buffer<uint64_t> iv_init_cal_config - init cal config's starting value
        ///
        const fapi2::buffer<uint64_t> get_init_cal_config() const
        {
            return iv_init_cal_config;
        }

    private:
        // Contains all of the base information for the init cal configuration register
        fapi2::buffer<uint64_t> iv_init_cal_config;
};

///
/// @brief Write leveling calibration step class
///
class wr_lvl : public phy_step
{
    public:
        ///
        /// @brief Base constructor
        /// @param[in] i_sim - true if in simulation mode
        ///
        wr_lvl(const bool i_sim) :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WR_LEVEL>(), "WR_LVL"),
            iv_sim(i_sim)
        {}

        // Delete the default constructor
        wr_lvl() = delete;

        ///
        /// @brief Default destructor
        ///
        ~wr_lvl() override = default;

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          const uint64_t i_rp,
                                          const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const;

    private:
        bool iv_sim;
};

///
/// @brief Initial pattern write
///
class initial_pattern_write : public phy_step
{
    public:
        ///
        /// @brief Base constructor
        ///
        initial_pattern_write() :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_PAT_WR>(),
                      "INITIAL_PATTERN_WRITE")
        {}

        ///
        /// @brief Default destructor
        ///
        ~initial_pattern_write() override = default;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;
};

///
/// @brief DQS align
///
class dqs_align : public phy_step
{
    public:
        ///
        /// @brief Base constructor
        ///
        dqs_align() :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_DQS_ALIGN>(),
                      "DQS_ALIGN")
        {}

        ///
        /// @brief Default destructor
        ///
        ~dqs_align() override = default;

        ///
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;
};

///
/// @brief Read clock align
///
class rdclk_align : public phy_step
{
    public:
        ///
        /// @brief Base constructor
        ///
        rdclk_align() :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RDCLK_ALIGN>(),
                      "RDCLK_ALIGN")
        {}

        ///
        /// @brief Default destructor
        ///
        ~rdclk_align() override = default;

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          const uint64_t i_rp,
                                          const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;
};

///
/// @brief Read centering (and potentially RD VREF)
///
class read_ctr : public phy_step
{
    public:
        // No default constructor
        read_ctr() = delete;

        ///
        /// @brief Base constructor
        /// @param[in] i_rd_vref - true IFF RD VREF is enabled
        /// @param[in] i_rd_ctr - true IFF RD CTR is enabled
        ///
        read_ctr(const bool i_rd_vref, const bool i_rd_ctr) :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_READ_CTR>(),
                      "READ_CTR"),
            iv_rd_vref(i_rd_vref),
            iv_rd_ctr(i_rd_ctr)
        {}

        ///
        /// @brief Default destructor
        ///
        ~read_ctr() override = default;

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          const uint64_t i_rp,
                                          const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;

        ///
        /// @brief Getter for RD VREF
        /// @return bool iv_rd_vref
        ///
        bool get_rd_vref() const
        {
            return iv_rd_vref;
        }

        ///
        /// @brief Getter for RD centering
        /// @return bool iv_rd_ctr
        ///
        bool get_rd_ctr() const
        {
            return iv_rd_ctr;
        }

    private:
        bool iv_rd_vref;
        bool iv_rd_ctr;
};

///
/// @brief Write centering (and potentially WR VREF)
///
class write_ctr : public phy_step
{
    public:
        // No default constructor
        write_ctr() = delete;

        ///
        /// @brief Base constructor
        /// @param[in] i_wr_vref - true IFF WR VREF is enabled
        ///
        write_ctr(const bool i_wr_vref) :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WRITE_CTR>(),
                      "WRITE_CTR"),
            iv_wr_vref(i_wr_vref)
        {}

        ///
        /// @brief Default destructor
        ///
        ~write_ctr() override = default;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          const uint64_t i_rp,
                                          const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;

        ///
        /// @brief Getter for WR VREF
        /// @return bool iv_wr_vref
        ///
        bool get_wr_vref() const
        {
            return iv_wr_vref;
        }

    private:
        bool iv_wr_vref;
        // Contains all information related to any DRAMs that were disabled due to the WR VREF algorithm
        // The pair contains the following information:
        // first  -> the DRAM's number to test
        // second -> the DRAM's starting write delay value
        mutable std::vector<std::pair<uint64_t, uint64_t>> iv_dram_to_check;

        ///
        /// @brief Sets up and runs the calibration step according to an external 1D vs 2D input
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @param[in] i_wr_vref - true IFF write VREF calibration needs to be run
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error,
                               const bool i_wr_vref ) const;
};

///
/// @brief Coarse WR/RD calibration
///
class coarse_wr_rd : public phy_step
{
    public:
        ///
        /// @brief Base constructor
        ///
        static constexpr uint64_t COARSE_WR_RD_LEN = 2;
        coarse_wr_rd() :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_COARSE_WR, COARSE_WR_RD_LEN>(),
                      "COARSE_WR/RD")
        {}

        ///
        /// @brief Default destructor
        ///
        ~coarse_wr_rd() override = default;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;
};

///
/// @brief Custom read centering - can include initial pattern write
///
class custom_read_ctr : public phy_step
{
    public:
        // Type def to beautify
        using attr_func = fapi2::ReturnCode (*)(const fapi2::Target<fapi2::TARGET_TYPE_MCA>&,
                                                uint32_t&);

        ///
        /// @brief Base constructor
        ///
        custom_read_ctr() :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_CUSTOM_RD>(),
                      "CUSTOM_READ_CTR"),
            iv_current_pattern(0),
            iv_training_failed(false)
        {}

        ///
        /// @brief Default destructor
        ///
        ~custom_read_ctr() override = default;

        ///
        /// @brief Executes a cal step with workarounds
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode execute( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                   const uint64_t i_rp,
                                   const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Executes the pre-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode pre_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                          const uint64_t i_rp,
                                          const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Executes the post-cal step workaround
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode post_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                           const uint64_t i_rp,
                                           const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;

        ///
        /// @brief Resets the current pattern
        /// @note Marked as constant as the current pattern is mutable
        ///
        void reset_data_pattern() const
        {
            iv_current_pattern = 0;
        }

        ///
        /// @brief Returns true if we exhausted all of our training patterns
        /// @return true if the current pattern is greater than our maximum number of patterns
        ///
        bool is_out_of_patterns() const
        {
            return iv_current_pattern >= NUM_PATTERNS;
        }

        ///
        /// @brief Returns true if training failed
        /// @return result of init cal training - true if a fail was detected
        ///
        inline bool training_failed() const
        {
            return iv_training_failed;
        }

    private:

        // Declares the accessors for which RD CTR patterns to run in what order
        constexpr static const uint32_t NUM_PATTERNS = 3;
        constexpr static attr_func DATA_PATTERNS[NUM_PATTERNS] =
        {
            custom_training_adv_patterns,
            custom_training_adv_backup_patterns,
            custom_training_adv_backup_patterns2,
        };
        mutable uint64_t iv_current_pattern;
        mutable bool iv_training_failed;
};

///
/// @brief Custom read centering - can include initial pattern write
///
class custom_write_ctr : public phy_step
{
    public:
        ///
        /// @brief Base constructor
        ///
        custom_write_ctr() :
            phy_step( fapi2::buffer<uint64_t>().setBit<MCA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_CUSTOM_WR>(),
                      "CUSTOM_WRITE_CTR"),
            iv_training_failed(false)
        {}

        ///
        /// @brief Default destructor
        ///
        ~custom_write_ctr() override = default;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override;

        ///
        /// @brief Returns true if training failed
        /// @return result of init cal training - true if a fail was detected
        ///
        inline bool training_failed() const
        {
            return iv_training_failed;
        }

    private:
        mutable bool iv_training_failed;
};


///
/// @class custom_training_facade
/// @brief Overall custom training algorithm
/// @note Due to interactions between write and read calibrations, using a facade class to setup the combined custom training algorithm
///
class custom_training_facade : public step
{
    public:
        ///
        /// @brief Base constructor
        ///
        custom_training_facade() :
            step( "CUSTOM_WRRD_CTR"),
            iv_rd_ctr(std::make_shared<custom_read_ctr>()),
            iv_wr_ctr(std::make_shared<custom_write_ctr>())
        {}

        ///
        /// @brief Custom destructor
        ///
        ~custom_training_facade() override = default;

        ///
        /// @brief Sets up and runs the calibration step
        /// @param[in] i_target - the MCA target on which to operate
        /// @param[in] i_rp - the rank pair
        /// @param[in] i_abort_on_error - whether or not we are aborting on cal error
        /// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ok
        ///
        fapi2::ReturnCode run( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                               const uint64_t i_rp,
                               const uint8_t i_abort_on_error ) const override;

        ///
        /// @brief Calculates the number of cycles a given calibration step will take
        /// @param[in] i_target - the MCA target on which to operate
        /// @return l_cycles - the number of cycles a given calibration step wil take
        ///
        uint64_t calculate_cycles( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target ) const override
        {
            // This class doesn't run training itself
            // iv_rd_ctr and iv_wr_ctr run it for us
            // As such, a dummy value of 0 is ok here (it's needed by the API, but not useful in this case)
            return 0;
        }

    private:
        std::shared_ptr<custom_read_ctr> iv_rd_ctr;
        std::shared_ptr<custom_write_ctr> iv_wr_ctr;
};

///
/// @brief Creates the vector of training steps to loop over
/// @param[in] i_cal_steps - the bit mask of calibration steps
/// @param[in] i_sim - simulation mode or not
/// @return a vector of the calibration steps to run
///
std::vector<std::shared_ptr<step>> steps_factory(const fapi2::buffer<uint32_t>& i_cal_steps, const bool i_sim);

///
/// @brief Creates the vector of training steps to loop over with an LRDIMM switch included
/// @param[in] i_dimm_type - the DIMM type - used to select LRDIMM vs not
/// @param[in] i_cal_steps - the bit mask of calibration steps
/// @param[in] i_sim - simulation mode or not
/// @return a vector of the calibration steps to run
///
std::vector<std::shared_ptr<step>> steps_factory(const uint8_t i_dimm_type, const fapi2::buffer<uint32_t>& i_cal_steps,
                                const bool i_sim);
namespace sim
{
///
/// @brief Deconfigures steps based upon simulation mode
/// @param[in] i_sim - simulation mode or not
/// @param[in,out] io_cal_steps calibration steps to deconfigure
///
void deconfigure_steps(const bool i_sim, fapi2::buffer<uint32_t>& io_cal_steps);
} // ns sim

} // ns training

} // ns mss

#endif
