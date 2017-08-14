/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/ddr_phy.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file ddr_phy.H
/// @brief Subroutines to manipulate the phy, or used during phy procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_DDR_PHY_H_
#define _MSS_DDR_PHY_H_

#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/ccs/ccs.H>

namespace mss
{

///
/// @brief Perform initializations for the PHY
/// @param[in] i_target the MCBIST which has the PHYs to initialize
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode phy_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target);

///
/// @brief change resetn to the given state
/// @param[in] i_target the mcbist
/// @param[in] i_state the desired state
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_resetn( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, states i_state );

///
/// @brief perform the zctl enable process
/// @param[in] i_target the mcbist for the reset recover
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode enable_zctl( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

/// @brief Change mclk low
/// @param[in] i_target mcbist target
/// @param[in] i_state mss::HIGH or mss::LOW - desired state.
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode change_force_mclk_low (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const mss::states i_state);

///
/// @brief Change the continuous update mode of the PR CNTL registers
/// @note Will take the SYSCLK control out of reset, too
/// @param[in] i_target the mcbist target
/// @param[in] i_state, mss::ON if you want to be in continuous mode, mss::OFF to turn it off
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode setup_phase_rotator_control_registers( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const states i_state );

///
/// @brief Deassetr the sys clk reset
/// @param[in] i_target the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode deassert_sysclk_reset( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Reset the training delay configureation
/// @param[in] i_target the mcbist target
/// @return FAPI2_RC_SUCCES iff ok
///
fapi2::ReturnCode reset_delay_values( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Check if the bang bang lock has succeeded
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode check_bang_bang_lock( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Write the READ_VREF register to enable and or to skip the read centering cal
/// @param[in] i_target the MCA target associated with this cal setup
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint8_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode setup_read_vref_config1( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::buffer<uint32_t>& i_cal_steps_enabled);

///
/// @brief Configure the DP16 sysclk
/// @param[in] i_target a MCBIST target
/// @return FAPI2_RC_SUCCESs iff ok
///
fapi2::ReturnCode setup_dp16_sysclk( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief check and process initial cal errors
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode process_initial_cal_errors( const fapi2::Target<T>& i_target );

///
/// @brief Clears all training related errors
/// @tparam T the type of the target in question
/// @param[in] i_target the port in question
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff no error
///
template< fapi2::TargetType T >
fapi2::ReturnCode clear_initial_cal_errors( const fapi2::Target<T>& i_target );

///
/// @brief Setup all the cal config register
/// @tparam T, the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rank_pairs the vector of currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer<uint32_t> representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode setup_cal_config( const fapi2::Target<T>& i_target,
                                    const std::vector<uint64_t>& i_rank_pairs,
                                    const fapi2::buffer<uint32_t>& i_cal_steps_enabled);

///
/// @brief Setup all the cal config register
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rank one currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer representing the cal steps to enable
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode setup_cal_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                    const uint64_t i_rank,
                                    const fapi2::buffer<uint32_t>& i_cal_steps_enabled);

///
/// @brief Execute a set of PHY cal steps
/// @tparam T the target type associated with this cal
/// @param[in] i_target the target associated with this cal
/// @param[in] i_rp one of the currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer representing the cal steps to enable
/// @param[in] i_abort_on_error CAL_ABORT_ON_ERROR override
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @note This is a helper function. Library users are required to call setup_and_execute_cal
///
template< fapi2::TargetType T >
fapi2::ReturnCode execute_cal_steps_helper( const fapi2::Target<T>& i_target,
        const uint64_t i_rp,
        const fapi2::buffer<uint32_t>& i_cal_steps_enabled,
        const uint8_t i_abort_on_error);

///
/// @brief Perform necessary termination setup and execute a set of PHY cal steps
/// @tparam T, the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal
/// @param[in] i_rp one of the currently configured rank pairs
/// @param[in] i_cal_steps_enabled fapi2::buffer representing the cal steps to enable
/// @param[in] i_abort_on_error CAL_ABORT_ON_ERROR override
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode setup_and_execute_cal( const fapi2::Target<T>& i_target,
        const uint64_t i_rp,
        const fapi2::buffer<uint32_t>& i_cal_steps_enabled,
        const uint8_t i_abort_on_error);

// TODO RTC:167929 Can ODT VPD processing be shared between RD and WR?
// TODO RTC:157753 tparams P and R can be pulled from an MCA trait once we have it
///
/// @brief Setup odt_rd_config
/// @tparam T the target type of the MCA/MBA
/// @tparam P the maximum DIMM per T
/// @tparam R the maximum rank per DIMM on T
/// @param[in] i_target the target
/// @param[in] i_dimm_count the number of DIMM presently on the target
/// @param[in] i_odt_rd the RD ODT values from VPD
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T, uint64_t P, uint64_t R >
fapi2::ReturnCode reset_odt_rd_config_helper( const fapi2::Target<T>& i_target,
        const uint64_t i_dimm_count,
        const uint8_t i_odt_rd[P][R] );

// TODO RTC:167929 Can ODT VPD processing be shared between RD and WR?
// TODO RTC:157753 tparams P and R can be pulled from an MCA trait once we have it
///
/// @brief Setup odt_wr_config
/// @tparam T the target type of the MCA/MBA
/// @tparam P the maximum DIMM per T
/// @tparam R the maximum rank per DIMM on T
/// @param[in] i_target the target
/// @param[in] i_dimm_count the number of DIMM presently on the target
/// @param[in] i_odt_wr the WR ODT values from VPD
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T, uint64_t P, uint64_t R >
fapi2::ReturnCode reset_odt_wr_config_helper( const fapi2::Target<T>& i_target,
        const uint64_t i_dimm_count,
        const uint8_t i_odt_wr[P][R] );

///
/// @brief Setup odt_rd_config
/// @param[in] i_target the MCA target
/// @param[in] i_dimm_count the number of DIMM presently on the target
/// @param[in] i_odt_rd the RD ODT values from VPD
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_odt_rd_config_helper<fapi2::TARGET_TYPE_MCA, MAX_DIMM_PER_PORT, MAX_RANK_PER_DIMM>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const uint64_t i_dimm_count,
    const uint8_t i_odt_rd[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM]);

///
/// @brief Setup odt_wr_config
/// @param[in] i_target the MCA target
/// @param[in] i_dimm_count the number of DIMM presently on the target
/// @param[in] i_odt_wr the WR ODT values from VPD
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_odt_wr_config_helper<fapi2::TARGET_TYPE_MCA, MAX_DIMM_PER_PORT, MAX_RANK_PER_DIMM>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
    const uint64_t i_dimm_count,
    const uint8_t i_odt_wr[MAX_DIMM_PER_PORT][MAX_RANK_PER_DIMM]);

///
/// @brief Setup odt_rd_config, reads attributes
/// @tparam T the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_odt_rd_config( const fapi2::Target<T>& i_target );

///
/// @brief Setup odt_rd_config, reads attributes
/// @param[in] i_target the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_odt_rd_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Setup odt_wr_config, reads attributes
/// @tparam T the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_odt_wr_config( const fapi2::Target<T>& i_target );

///
/// @brief Setup odt_wr_config, reads attributes
/// @param[in] i_target the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_odt_wr_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Override odt_wr_config to enabled for a given rank
/// @tparam T the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rank the rank to override
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode override_odt_wr_config( const fapi2::Target<T>& i_target,
        const uint64_t& i_rank);

///
/// @brief Override odt_wr_config to enabled for a given rank
/// @param[in] i_target the MCA target associated with this cal setup
/// @param[in] i_rank the rank to override
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode override_odt_wr_config( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t& i_rank);

///
/// @brief Setup terminations for WR_LEVEL cal for a given RP
/// @tparam T the target type of the MCA/MBA
/// @tparam CT TargetType of the CCS instruction
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rp selected rank pair
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T, fapi2::TargetType CT >
fapi2::ReturnCode setup_wr_level_terminations( const fapi2::Target<T>& i_target,
        const uint64_t i_rp,
        std::vector< ccs::instruction_t<CT> >& io_inst);

///
/// @brief Setup terminations for WR_LEVEL cal for a given RP
/// @param[in] i_target the MCA target associated with this cal setup
/// @param[in] i_rp selected rank pair
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode setup_wr_level_terminations( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief Restore terminations after WR_LEVEL cal for a given RP
/// @tparam T the target type of the MCA/MBA
/// @tparam CT TargetType of the CCS instruction
/// @param[in] i_target the target associated with this cal setup
/// @param[in] i_rp selected rank pair
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T, fapi2::TargetType CT >
fapi2::ReturnCode restore_mainline_terminations( const fapi2::Target<T>& i_target,
        const uint64_t i_rp,
        std::vector< ccs::instruction_t<CT> >& io_inst);

///
/// @brief Restore terminations after WR_LEVEL cal for a given RP
/// @param[in] i_target the MCA target associated with this cal setup
/// @param[in] i_rp selected rank pair
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode restore_mainline_terminations( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rp,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief Perform the DLL calibration
/// @tparam T the target type of the MCBIST
/// @param[in] i_target the target associated with this DLL cal
/// @param[out] o_run_workaround whether we need to run workarounds
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode dll_calibration( const fapi2::Target<T>& i_target, bool& o_run_workaround );

///
/// @brief Perform the DLL calibration
/// @param[in] i_target the target associated with this DLL cal
/// @param[out] o_run_workaround whether we need to run workarounds
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode dll_calibration( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target, bool& o_run_workaround );

///
/// @brief Flush the output drivers
/// @tparam T the target type of the MCBIST
/// @param[in] i_target the target associated with the phy reset sequence
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode flush_output_drivers( const fapi2::Target<T>& i_target );

///
/// @brief Flush the output drivers
/// @param[in] i_target the target associated with the phy reset sequence
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode flush_output_drivers( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

///
/// @brief Setup seq_rd_wr_data
/// @tparam T the target type of the MCA/MBA
/// @param[in] i_target the target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode reset_seq_rd_wr_data( const fapi2::Target<T>& i_target );

///
/// @brief Setup seq_rd_wr_data
/// @param[in] i_target the MCA target associated with this cal setup
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<>
fapi2::ReturnCode reset_seq_rd_wr_data( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Return the DIMM target for the primary rank in the specificed rank pair
/// @tparam T fapi2::TargetType of the port target
/// @param[in] i_target the target
/// @param[in] i_rp the rank pair
/// @param[out] fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @return FAPI2_RC_SUCCESS iff ok
///
template<fapi2::TargetType T>
fapi2::ReturnCode rank_pair_primary_to_dimm(const fapi2::Target<T>& i_target, const uint64_t i_rp,
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_dimm);
///
/// @brief Set the custom pattern
/// @param[in] i_target the port target
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template<fapi2::TargetType T>
fapi2::ReturnCode configure_custom_pattern( const fapi2::Target<T>& i_target );

///
/// @brief Handle draminit_training cal fails
/// @param[in] i_fails vector holding the return codes for calibration failures
/// @note We handle errors differently depending on if we're HB or cronus
/// If we're cronus, we want to error out.
/// If we're hostboot, we want to log the error as hidden and let PRD choose to deconfigure
///
fapi2::ReturnCode draminit_training_error_handler ( const std::vector<fapi2::ReturnCode>& i_fails);

///
/// @brief Finds the calibration errors from draminit training
/// @tparam T fapi2::TargetType of the port target
/// @param[in] i_target the port target
/// @param[in] i_rp the rank pair we are calibrating
/// @param[in] i_cal_abort_on_error denoting if we aborted on first fail
/// @param[out] o_cal_fail a flag that gets set to true if there was a cal fail
/// @param[in,out] io_fails a vector storing all of our cal fails
/// @return FAPI2_RC_SUCCESS iff all of the scoms and functionality were good
///
template<fapi2::TargetType T>
fapi2::ReturnCode find_and_log_cal_errors(const fapi2::Target<T>& i_target,
        const uint64_t i_rp,
        const uint64_t i_cal_abort_on_error,
        bool& o_cal_fail,
        std::vector<fapi2::ReturnCode>& io_fails);

///
/// @brief Sets up the IO impedances (ADR DRV's and DP DRV's/RCV's)
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA/MCBIST or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode reset_io_impedances(const fapi2::Target<T>& i_target);

}
#endif
