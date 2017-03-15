/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_training.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
/// @file p9c_mss_draminit_training.H
/// @brief HWP for training DRAMs delay values
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: Memtools

#ifndef mss_draminit_training_H_
#define mss_draminit_training_H_
#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_draminit_training_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& target );

enum mss_draminit_training_result
{
    MSS_INIT_CAL_COMPLETE = 1,
    MSS_INIT_CAL_PASS = 2,
    MSS_INIT_CAL_STALL = 3,
    MSS_INIT_CAL_FAIL = 4
};

extern "C"
{
    /// @brief DRAM training procedure.  Calibrate delay values
    /// @param[in] i_target reference to centaur.mba target
    /// @return FAPI2_RC_SUCCESS iff training completes
    fapi2::ReturnCode p9c_mss_draminit_training(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    /// @brief DDR4: Sets the DQS offset to be 16 instead of 8
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_setup_dqs_offset(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    /// @brief Training procedure.   Find dram delay values
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_draminit_training_cloned(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    /// @brief Check status of init cal.  Poll until stalled or complete
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port   Memory port
    /// @param[in] i_group  Rank group
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_check_cal_status(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                           const uint8_t i_port, const uint8_t i_group,  mss_draminit_training_result& io_status);

    /// @brief Interprets initcal error register
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_group Memory Rank Group
    /// @param[in] i_cur_cal_step   Step of init cal
    /// @param[in,out] io_status Cal Status
    /// @param[in] i_max_cal_retry Max retry
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_check_error_status(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_port, const uint8_t i_group,  const uint8_t i_cur_cal_step, mss_draminit_training_result& io_status,
            const uint8_t i_max_cal_retry);

    /// @brief Places RTT_WR into RTT_NOM within MR1 before wr_lvl
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port_number Memory port
    /// @param[in] i_rank Memory Rank
    /// @param[in] i_rank_pair_group Rank group
    /// @param[in,out] io_ccs_inst_cnt  CCS instance number
    /// @param[in,out] io_dram_rtt_nom_original RTT_NOM val which will be overwritten
    /// @return fapi2::ReturnCode
    /// @note If the function argument dram_rtt_nom_original has a value of 0xFF it will put the original rtt_nom there
    /// @note and write rtt_wr to the rtt_nom value
    /// @note If the function argument dram_rtt_nom_original has any value besides 0xFF it will try to write that value to rtt_nom.
    fapi2::ReturnCode mss_rtt_nom_rtt_wr_swap( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint32_t i_port_number, const uint8_t i_rank, const uint32_t i_rank_pair_group, uint32_t& io_ccs_inst_cnt,
            uint8_t& io_dram_rtt_nom_original);

    /// @brief  DQS_CLK for each nibble of a byte is being adjusted to the lowest value for the given byte
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_wr_lvl_disable_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    /// @brief Reset Wr_level delays and Gate Delays
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_reset_delay_values(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    /// @brief  calls dimmGetBadDqBitmap and converts the data to phy order in a databuffer
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_dimm Memory Dimm
    /// @param[out] o_reg
    /// @param[out] is_clean
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode getC4dq2reg(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba, const uint8_t i_port,
                                  const uint8_t i_dimm, const uint8_t i_rank, fapi2::variable_buffer& o_reg, uint8_t& is_clean);

    /// @brief  Converts the data from phy order (i_reg) to cen_c4_dq array for dimmSetBadDqBitmap to write flash with
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_dimm Memory Dimm
    /// @param[in] i_reg
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode setC4dq2reg(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba, const uint8_t i_port,
                                  const uint8_t i_dimm, const uint8_t i_rank, const fapi2::variable_buffer& i_reg);
    /// @brief Set bad bit mask
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_set_bbm_regs (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& mba_target);

    /// @brief Get bad bit mask
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_training_success  Training passed flag
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_get_bbm_regs (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& mba_target,
                                        const uint8_t i_training_success);

    /// @brief Get DQS lane from port-block-quad
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_block
    /// @param[in] i_quad
    /// @param[out] o_lane DQS lane
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode mss_get_dqs_lane (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba, const uint8_t i_port,
                                        const uint8_t i_block, const uint8_t i_quad, uint8_t& lane);



} // extern "C"

#endif // mss_draminit_training_H_
