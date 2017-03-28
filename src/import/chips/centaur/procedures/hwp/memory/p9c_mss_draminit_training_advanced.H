/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_training_advanced.H $ */
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
/// @file mss_draminit_training_advanced.H
/// @brief Tools for centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef _MSS_DRAMINIT_TRAINING_ADVANCED_H
#define _MSS_DRAMINIT_TRAINING_ADVANCED_H

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>
#include <p9c_mss_shmoo_common.H>
typedef fapi2::ReturnCode (*p9c_mss_draminit_training_advanced_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&);

///
/// @brief Shmoo Param enums
///
enum shmoo_param
{
    PARAM_NONE = 0x00,
    DELAY_REG = 0x01,
    DRV_IMP = 0x02,
    SLEW_RATE = 0x04,
    WR_VREF = 0x08,
    RD_VREF = 0x10,
    RCV_IMP = 0x20
};

extern "C"
{
    ///
    /// @brief Draminit training advanced procedure shmoo's drv_impedance, slew, vref and receiver impedance and get the optimum value
    /// @param[in] i_target Reference to MBA target
    /// @return ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_draminit_training_advanced(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief This function varies the driver impedance in the nominal mode
    /// @param[in] i_target_mba : Centaur input MBA
    /// @param[in] i_port : Centuar input port
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode drv_imped_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const uint8_t i_port); //done

    ///
    /// @brief varies the slew rate of the data & adr signals (fast/slow)
    /// @param[in] i_target_mba Centaur input mba
    /// @param[in] i_port Centaur input port
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode slew_rate_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port);

    ///
    /// @brief perform wr vref shmoo on DDR4 dimms
    /// @param[in] i_target_mba Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode wr_vref_shmoo_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief perform binary wr vref shmoo on DDR4 dimms
    /// @param[in] i_target_mba Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode wr_vref_shmoo_ddr4_bin(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    ///@brief Read VREF shmoo (ddr4 dimms)
    ///@param[in] i_target_mba Centaur input mba
    ///@return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode rd_vref_shmoo_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief Receiver impedance shmoo function varies 9 values
    /// @param[in] i_target_mba Centaur input mba
    /// @param[in] i_port Centaur input port
    /// @param[in] i_shmoo_type_valid  MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode rcv_imp_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, uint8_t i_port);

    ///
    /// @brief Calls Delay shmoo function varies delay values of each dq and returns timing margin
    /// @param[in] i_target_mba Centaur input mba
    /// @param[in] i_port Centaur input port
    /// @param[in] i_shmoo_type_valid Shmoo type MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
    /// @param[out] o_left_margin  returns left margin delay (setup) in ps
    /// @param[out] o_right_margin returns right margin delay (hold) in ps
    /// @param[in] i_shmoo_param Shmoo
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode delay_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port,
                                  const shmoo_type_t i_shmoo_type_valid,
                                  uint32_t* o_left_margin, uint32_t* o_right_margin,
                                  uint32_t i_shmoo_param);

    ///
    /// @brief Calls Delay shmoo function varies delay values of each dq and returns timing margin
    /// @param[in] i_target_mba Centaur input mba
    /// @param[in] i_port Centaur input port
    /// @param[in] i_shmoo_type_valid Shmoo type MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
    /// @param[out] o_left_margin  returns left margin delay (setup) in ps
    /// @param[out] o_right_margin returns right margin delay (hold) in ps
    /// @param[in] i_shmoo_param Shmoo
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode delay_shmoo_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port,
                                       const shmoo_type_t i_shmoo_type_valid,
                                       uint32_t* o_left_margin, uint32_t* o_right_margin,
                                       const uint32_t i_shmoo_param);

    ///
    /// @brief Calls Delay shmoo function varies delay values of each dq and returns timing margin
    /// @param[in] i_target_mba Centaur input mba
    /// @param[in] i_port Centaur input port
    /// @param[in] i_shmoo_type_valid Shmoo type MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
    /// @param[out] o_left_margin  returns left margin delay (setup) in ps
    /// @param[out] o_right_margin returns right margin delay (hold) in ps
    /// @param[in] i_shmoo_param Shmoo
    /// @param[in] i_pda_nibble_table
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode delay_shmoo_ddr4_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port,
                                           const shmoo_type_t i_shmoo_type_valid,
                                           uint32_t* o_left_margin, uint32_t* o_right_margin,
                                           const uint32_t i_shmoo_param, uint32_t i_pda_nibble_table[2][2][4][16][2]);
    ///
    /// @brief Finds better timing margin and returns the index
    /// @param[in] i_shmoo_param_valid PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
    /// @param[in] i_left[] timing margin array
    /// @param[in] i_right[] timing margin array
    /// @param[in] i_max  Max enum value of schmoo param
    /// @param[in] i_param_nom selected shmoo parameter (DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP)
    /// @param[in] o_index returns index
    ///
    void find_best_margin(const shmoo_param i_shmoo_param_valid,
                          const uint32_t i_left[],
                          const uint32_t i_right[],
                          const uint8_t l_max,
                          const uint32_t i_param_nom,
                          uint8_t& o_index);

    ///
    /// @brief Sets the attribute ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL used by all functions
    /// @param[in] i_target_mba Centaur input mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode set_attribute(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief resets the attribute ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL used by all functions
    /// @param[in] i_target_mba Centaur input mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode reset_attribute(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);


} // extern C

#endif// _MSS_DRAMINIT_TRAINING_ADVANCED_H
