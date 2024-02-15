/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_ppe_common.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// @file io_ppe_common.H
///
/// @brief Class that supports command execution and polling functions
///        for IO hwps
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

#include <fapi2.H>
#include <io_ppe_lib.H>
#include <io_scom_lib.H>

#define IO_PPE_COMMON_PRINT(_fail_, _fmt_, _args_...) if (!(_fail_)) { FAPI_INF(_fmt_, ##_args_);} else { FAPI_ERR(_fmt_, ##_args_);}

enum IO_PPE_CONSTS
{
    IO_PPE_MAX_THREADS = 9,
    IO_PPE_DCCAL_DONE_POLL_TRYS = 100,
    IO_PPE_DCCAL_DONE_POLL_DELAY_NS = 10000,
    IO_PPE_DCCAL_DONE_POLL_DELAY_SIM_CYCLES = 100000000,
    IO_PPE_EL_DONE_POLL_TRYS = 100,
    IO_PPE_EL_DONE_POLL_DELAY_NS = 10000,
    IO_PPE_EL_DONE_POLL_DELAY_SIM_CYCLES = 100000000,

    IO_TX_MODE2_PL = 0x0848, // unload_sel bit 60, 2 wide
    IO_TX_MODE4_PL = 0x0A78, // tx_fifo_l2u_dly bit 48, 4 wide

    IO_PPE_RX_DAC_CNTL3_PL = 0x0030,
    IO_PPE_RX_DAC_CNTL4_PL = 0x0040,
    IO_TX_FIFO_L2U_DLY = 48,
    IO_TX_FIFO_L2U_DLY_LEN = 4,
    IO_TX_UNLOAD_SEL = 60,
    IO_TX_UNLOAD_SEL_LEN = 2,

    IO_PPE_RX_DAC_CNTL6_PL = 0x0060,
    IO_PPE_RX_DAC_CNTL13_PL = 0x00D0,
    IO_PPE_RX_LTE_GAIN = 48,
    IO_PPE_RX_LTE_GAIN_LEN = 3,
    IO_PPE_RX_LTE_ZERO = 51,
    IO_PPE_RX_LTE_ZERO_LEN = 3,
    IO_PPE_RX_CTLE_PEAK1 = 56,
    IO_PPE_RX_CTLE_PEAK1_LEN = 4,
    IO_PPE_RX_CTLE_PEAK2 = 60,
    IO_PPE_RX_CTLE_PEAK2_LEN = 4,
    IO_PPE_HARD_RESET_DELAY_NS = 5000,
    IO_PPE_HARD_RESET_DELAY_SIM_CYCLES = 10000000,
    IO_PPE_RESUME_DELAY_NS = 5000,
    IO_PPE_RESUME_DELAY_SIM_CYCLES = 10000000,

    IO_PPE_DELAY_1MS = 1000000,
    IO_PPE_DELAY_SIM_CYCLES = 100000000,
};

//WARNING!!  Since these are hard coded and not generated
// from the image register definitions, any changes or
// inconsistances between image commands would cause
// problems.
enum IO_PPE_EXT_CMD_REQ_BITS
{
    //                              1111111111222222222233
    //                    01234567890123456789012345678901
    CLEAR             = 0b00000000000000000000000000000000,
    HW_REG_INIT_PG    = 0b10000000000000000000000000000000,
    IORESET_PL        = 0b01000000000000000000000000000000,
    NOP_RX_DETECT_PL  = 0b00100000000000000000000000000000,
    DCCAL_PL          = 0b00010000000000000000000000000000,
    TX_ZCAL_PL        = 0b00001000000000000000000000000000,
    TX_FFE_PL         = 0b00000100000000000000000000000000,
    POWER_OFF_PL      = 0b00000010000000000000000000000000,
    POWER_ON_PL       = 0b00000001000000000000000000000000,
    TX_FIFO_INIT_PL   = 0b00000000100000000000000000000000,
    NOP_RX_BIST_TESTS = 0b00000000010000000000000000000000,
    TX_BIST_TESTS_PL  = 0b00000000001000000000000000000000,
    TRAIN_PL          = 0b00000000000100000000000000000000,
    RECAL_PL          = 0b00000000000010000000000000000000,
    BIST_FINAL        = 0b00000000000001000000000000000000,
    RESERVED_14       = 0b00000000000000100000000000000000,
    RESERVED_15       = 0b00000000000000010000000000000000,
    BIST_START_CMD    = HW_REG_INIT_PG | DCCAL_PL | POWER_ON_PL | TX_BIST_TESTS_PL | TRAIN_PL | RECAL_PL | BIST_FINAL,
};

///
/// @brief Common PPE procedures bewteen POZ
///
template<fapi2::TargetType K, fapi2::MulticastType M = fapi2::MULTICAST_OR, typename V = fapi2::plat_target_handle_t>
class io_ppe_common
{
    public:
        io_ppe_regs<K, M, V>* iv_regs;

        io_ppe_common(io_ppe_regs<K, M, V>* i_regs) :
            iv_regs(i_regs)
        {
            FAPI_DBG("io_ppe_common constructor");
        }

        ///
        /// @brief Calculate the PPE data rate number from the data rate value
        ///
        /// @param[in] i_data_rate  Input data rate as GBps
        ///
        /// @return uint32_t value of 0..6 based on datarate
        uint32_t calc_ppe_data_rate(const uint32_t i_data_rate);
        ///
        /// @brief Calculate the PCIE data rate number from the data rate value
        ///
        /// @param[in] i_data_rate  Input data rate as GBps
        ///
        /// @return uint32_t value of 0..4 based on datarate
        uint32_t calc_pcie_data_rate(const uint32_t i_data_rate);

        ///
        /// @brief Sets the LTE Gain & LTE Zero
        ///
        /// @param[in] i_target     Chip target to start
        /// @param[in] i_thread     The thread LTE is being set on
        /// @param[in] i_lane       The lane LTE is being set on
        /// @param[in] i_rx_lte_g   LTE Gain value to be set
        /// @param[in] i_rx_lte_z   LTE Zero value to be set
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode set_lte_gain_zero(const fapi2::Target<K, M, V>& i_target,
                                            const uint8_t i_thread,
                                            const uint8_t i_lane,
                                            const uint32_t i_rx_lte_g,
                                            const uint32_t i_rx_lte_z);

        ///
        ///
        /// @brief Sets the CTLE Peak 1/2 values
        ///
        /// @param[in] i_target     Chip target to start
        /// @param[in] i_thread     The thread LTE is being set on
        /// @param[in] i_lane       The lane LTE is being set on
        /// @param[in] i_rx_peak1   Rx Peak1 value
        /// @param[in] i_rx_peak2   Rx Peak2 value
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code. error code.
        fapi2::ReturnCode set_ctle_peaking(const fapi2::Target<K, M, V>& i_target,
                                           const uint8_t i_thread,
                                           const uint8_t i_lane,
                                           const int32_t i_rx_peak1,
                                           const int32_t i_rx_peak2);

        ///
        /// @brief Starts the PPE and checks that it's in a healthy state
        ///
        /// @param[in] i_target    Chip target to start
        /// @param[out] o_fail     If in PPE start failed
        /// @param[out] o_iar      IAR value for debug print outs
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode ppe_start(const fapi2::Target<K, M, V>& i_target, bool& o_fail, uint32_t& o_iar);

        ///
        /// @brief Configures the PPEs threads and VIO voltage
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_num_threads    Number of threads to initialize
        /// @param[in] i_vio_volts      VIO voltage to be set in mV
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode config_ppe(const fapi2::Target<K, M, V>& i_target,
                                     const uint8_t i_num_threads,
                                     const uint32_t i_vio_volts);

        ///
        /// @brief Configures the threads of the PPE with the number of lanes
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        /// @param[in] i_gcr_id         GCR ID to run on
        /// @param[in] i_num_rx_lanes   Number of Rx lanes to initialize
        /// @param[in] i_num_tx_lanes   Number of Tx lanes to initialize
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode config_thread(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint8_t i_gcr_id,
                                        const uint8_t i_num_rx_lanes,
                                        const uint8_t i_num_tx_lanes);

        fapi2::ReturnCode stop_thread(const fapi2::Target<K, M, V>& i_target,
                                      const uint8_t i_max_threads,
                                      bool i_stop_thread);

        ///
        /// @brief BIST Initialization per thread
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        /// @param[in] i_rx_mask        Rx lane mask
        /// @param[in] i_freq           Frequency lanes are being run at
        /// @param[in] i_bist_timer_sel BIST Timer value to set
        /// @param[in] i_pcie_mode      If link being set is PCIE link
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode bist_init_thread(const fapi2::Target<K, M, V>& i_target,
                                           const uint8_t i_thread,
                                           const uint32_t i_rx_mask,
                                           const uint32_t i_freq,
                                           const uint8_t i_bist_timer_sel,
                                           const uint8_t i_pcie_mode);

        ///
        /// @brief BIST Initialization per PPE
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_group          Group to run on
        /// @param[in] i_dacTest        DAC Test avlue to set
        /// @param[in] i_esdTest        ESD Test value to set
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode bist_init(const fapi2::Target<K, M, V>& i_target,
                                    const uint8_t i_group,
                                    const uint8_t i_dacTest,
                                    const uint8_t i_esdTest);


        ///
        /// @brief BIST PPE cleanup to prepare for DCCAL
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        /// @param[in] i_rx_lanes_0_31  Rx lane mask
        /// @param[in] i_tx_lanes_0_31  Tx lane mask
        /// @param[out] o_done          Done value for cleanup external command
        /// @param[out] o_fail          Fail value for cleanup external command
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode bist_cleanup(const fapi2::Target<K, M, V>& i_target,
                                       const uint8_t i_thread,
                                       const uint32_t i_rx_lanes_0_31,
                                       const uint32_t i_tx_lanes_0_31,
                                       uint8_t& o_done,
                                       uint32_t& o_fail);

        ///
        /// @brief PPE initialization for DCCAL
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        /// @param[in] i_date_rate          Date rate PPE is running at
        /// @param[in] i_channel_length     Channel length of the PPE's lanes
        /// @param[in] i_spread_en          Spread spectrum enable
        /// @param[in] i_pcie_mode          If the PPE is PCIE
        /// @param[in] i_auto_recal_mask    Auto Recal mask
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode hss_init(const fapi2::Target<K, M, V>& i_target,
                                   const uint8_t i_thread,
                                   const uint32_t i_data_rate,
                                   const uint32_t i_channel_length,
                                   const uint8_t i_spread_en,
                                   const uint8_t i_pcie_mode,
                                   const uint32_t i_auto_recal_mask);

        ///
        /// @brief Tx initialization for DCCAL
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        /// @param[in] i_lane_mask          Tx lane mask
        /// @param[in] i_tx_pre1            Tx Pre1 value
        /// @param[in] i_tx_pre2            Tx Pre2 value
        /// @param[in] i_tx_post            Tx Post value
        /// @param[in] i_tx_fifo_l2u_dly    FIFO L2U Delay
        /// @param[in] i_tx_unload_sel      Unload select value
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode hss_init_tx(const fapi2::Target<K, M, V>& i_target,
                                      const uint8_t i_thread,
                                      const uint32_t i_lane_mask,
                                      const uint8_t i_tx_pre1,
                                      const uint8_t i_tx_pre2,
                                      const uint8_t i_tx_post,
                                      const uint32_t i_tx_fifo_l2u_dly,
                                      const uint32_t i_tx_unload_sel);

        ///
        /// @brief Rx initialization for DCCAL
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        /// @param[in] i_lane_mask          Rx lane mask
        /// @param[in] i_rx_lte_g           Rx LTE Gain value
        /// @param[in] i_rx_lte_z           Rx LTE Zero value
        /// @param[in] i_rx_peak1           Rx Peak 1 value
        /// @param[in] i_rx_peak2           Rx Peak 2 value
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode hss_init_rx(const fapi2::Target<K, M, V>& i_target,
                                      const uint8_t i_thread,
                                      const uint32_t i_lane_mask,
                                      const int32_t i_rx_lte_g,
                                      const int32_t i_rx_lte_z,
                                      const int32_t i_rx_peak1,
                                      const int32_t i_rx_peak2);

        ///
        /// @brief Set the functional margins for HSS Init
        ///
        /// @param[in] i_target                 Chip target to start
        /// @param[in] i_thread                 Thread to run on
        /// @param[in] i_lane_mask              Rx lane mask
        /// @param[in] i_rx_vert_offset         Rx vertical offset
        /// @param[in] i_rx_horiz_data_offset   Rx hoirzontal data offset
        /// @param[in] i_rx_horiz_edge_offset   Rx hoirzontal edge offset
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode setup_func_margin(const fapi2::Target<K, M, V>& i_target,
                                            const uint8_t i_thread,
                                            const uint8_t i_rx_vert_offset,
                                            const uint8_t i_rx_horiz_data_offset,
                                            const uint8_t i_rx_horiz_edge_offset);

        ///
        /// @brief Set the ext_cmd_req bits and start the PPE running those functions
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        /// @param[in] i_rx_lanes_0_31  Rx lane mask
        /// @param[in] i_tx_lanes_0_31  Tx lane mask
        /// @param[in] i_ext_cmd_req    External command to set/run
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode ext_cmd_start(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint32_t i_rx_lanes_0_31,
                                        const uint32_t i_tx_lanes_0_31,
                                        const uint32_t i_ext_cmd_req);

        ///
        /// @brief Check the status ext_cmd_done and ext_cmd_fail bits
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        /// @param[in] i_ext_cmd_req    External command to check
        /// @param[out] o_done          Done value for cleanup external command
        /// @param[out] o_fail          Fail value for cleanup external command
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode ext_cmd_check(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint32_t i_ext_cmd_req,
                                        uint8_t& o_done,
                                        uint32_t& o_fail);

        ///
        /// @brief Poll the status ext_cmd_done and ext_cmd_fail bits 1000 times
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        /// @param[in] i_ext_cmd_req    External command to check
        /// @param[out] o_done          Done value for cleanup external command
        /// @param[out] o_fail          Fail value for cleanup external command
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode ext_cmd_poll(const fapi2::Target<K, M, V>& i_target,
                                       const uint8_t i_thread,
                                       const uint32_t i_ext_cmd_req,
                                       uint8_t& o_done,
                                       uint32_t& o_fail);

        ///
        /// @brief Set the external command clear mode to 1
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode set_ext_cmd_clear_mode(const fapi2::Target<K, M, V>& i_target,
                const uint8_t i_thread);

        ///
        /// @brief Print debug info, primarily BIST and PPE statuses
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         Thread to run on
        /// @param[in] i_rx_lanes_0_31  Rx lane mask
        /// @param[in] i_tx_lanes_0_31  Tx lane mask
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode debug_display(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread,
                                        const uint32_t i_rx_lanes_0_31,
                                        const uint32_t i_tx_lanes_0_31);

        ///
        /// @brief Enable lanes procedure POWER_ON_PL | TX_FIFO_INIT_PL
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_num_threads    Threads to run on
        /// @param[in] i_rx_lanes_0_31  Rx lane mask
        /// @param[in] i_tx_lanes_0_31  Tx lane mask
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode enable_lanes(const fapi2::Target<K, M, V>& i_target,
                                       const fapi2::buffer<uint64_t> i_num_threads,
                                       const uint32_t i_rx_lanes_0_31,
                                       const uint32_t i_tx_lanes_0_31);

        ///
        /// @brief Check if enable lanes is completed
        ///
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_num_threads    Threads to run on
        /// @param[out] o_done          Done value for cleanup external command
        /// @param[out] o_fail          Fail value for cleanup external command
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode check_enable_lanes_done(const fapi2::Target<K, M, V>& i_target,
                const fapi2::buffer<uint64_t> i_num_threads,
                fapi2::buffer<uint64_t>& o_done,
                fapi2::buffer<uint64_t>& o_fail);

        ///
        /// @brief Start the IOBIST external commands
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        /// @param[in] i_rx_lanes_0_31      Rx lane mask
        /// @param[in] i_tx_lanes_0_31      Tx lane mask
        /// @param[in] i_ext_cmd_override   External command to run instead of BIST_START
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode bist_start(const fapi2::Target<K, M, V>& i_target,
                                     const uint8_t i_thread,
                                     const uint32_t i_rx_lanes_0_31,
                                     const uint32_t i_tx_lanes_0_31,
                                     const uint32_t i_ext_cmd_override);

        ///
        /// @brief Poll for done on the IOBIST external commands
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        /// @param[out] o_done              Done value for cleanup external command
        /// @param[out] o_fail              Fail value for cleanup external command
        /// @param[in] i_ext_cmd_override   External command to run instead of BIST_START
        /// @param[in] i_poll_count         Number of times to poll for
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode bist_poll(const fapi2::Target<K, M, V>& i_target,
                                    const uint8_t i_num_threads,
                                    uint8_t& o_done,
                                    uint32_t& o_fail,
                                    bool& o_bist_overall_fail,
                                    const uint32_t i_ext_cmd_override,
                                    const uint32_t i_poll_count);

        ///
        /// @brief Sim speed up options
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode fast_mode(const fapi2::Target<K, M, V>& i_target,
                                    const uint8_t i_thread);

        ///
        /// @brief Gets the number of lanes from the mask
        ///
        /// @param[in] i_lane_mask  Lane mask to check
        ///
        /// @return uint8_t     The number of lanes
        uint8_t get_num_lanes(uint32_t);

        ///
        /// @brief Clears the DL IFC Ignore bit
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode clear_dl_ignore(const fapi2::Target<K, M, V>& i_target,
                                          const uint8_t i_thread);

        ///
        /// @brief Sets the DL IFC Ignore bit
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode set_dl_ignore(const fapi2::Target<K, M, V>& i_target,
                                        const uint8_t i_thread);

        ///
        /// @brief Sets the PCIE presets for all gens and lanes
        ///
        /// @param[in] i_target             Chip target to start
        /// @param[in] i_thread             Thread to run on
        ///
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode set_pcie_presets(const fapi2::Target<K, M, V>& i_target,
                                           const uint8_t i_thread);

        /// @brief      Setting auto recal for xbus syncmode operations
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         The thread LTE is being set on
        /// @param[in] i_auto_recal     Wheter or not auto_recal will run
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode auto_recal_sync(const fapi2::Target<K, M, V>& i_target,
                                          const uint32_t i_auto_recal_mask,
                                          const uint8_t i_thread,
                                          const uint8_t i_auto_recal);

        /// @brief      Turning on auto recal after posttrain for A/XBUS
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         The thread LTE is being set on
        /// @param[in] i_data           The value to set the field to
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode set_auto_recal(const fapi2::Target<K, M, V>& i_target,
                                         const uint8_t i_thread,
                                         const uint32_t i_data);

        /// @brief      Enabling recal not run checking
        /// @param[in] i_target         Chip target to start
        /// @param[in] i_thread         The thread LTE is being set on
        /// @param[in] i_data           The value to set the field to
        /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code.
        fapi2::ReturnCode set_recal_not_run_disable(const fapi2::Target<K, M, V>& i_target,
                const uint8_t i_thread,
                const uint32_t i_data);
};

// ===============================================================
// phy_config
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
uint32_t io_ppe_common<K, M, V>::calc_ppe_data_rate(const uint32_t i_data_rate)
{
    uint32_t l_ppe_data_rate = 0;

    if (i_data_rate <= 2500)
    {
        l_ppe_data_rate = 0;
    }
    else if (i_data_rate <= 5000)
    {
        l_ppe_data_rate = 1;
    }
    else if (i_data_rate <= 8000)
    {
        l_ppe_data_rate = 2;
    }
    else if (i_data_rate <= 16000)
    {
        l_ppe_data_rate = 3;
    }
    else if (i_data_rate <= 21333)
    {
        l_ppe_data_rate = 4;
    }
    else if (i_data_rate <= 25600)
    {
        l_ppe_data_rate = 5;
    }
    else if (i_data_rate <= 32000)
    {
        l_ppe_data_rate = 6;
    }
    else
    {
        l_ppe_data_rate = 7;
    }

    return l_ppe_data_rate;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
uint32_t io_ppe_common<K, M, V>::calc_pcie_data_rate(const uint32_t i_data_rate)
{
    uint32_t l_pcie_data_rate = 0;

    if (i_data_rate <= 2500)
    {
        l_pcie_data_rate = 0;
    }
    else if (i_data_rate <= 5000)
    {
        l_pcie_data_rate = 1;
    }
    else if (i_data_rate <= 8000)
    {
        l_pcie_data_rate = 2;
    }
    else if (i_data_rate <= 16000)
    {
        l_pcie_data_rate = 3;
    }
    else if (i_data_rate <= 32000)
    {
        l_pcie_data_rate = 4;
    }
    else
    {
        l_pcie_data_rate = 5;
    }

    return l_pcie_data_rate;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::set_lte_gain_zero(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint8_t i_lane,
        const uint32_t i_rx_lte_g,
        const uint32_t i_rx_lte_z)
{
    FAPI_DBG("Starting io_ppe_common::set_lte_gain_zero");
    uint64_t l_addr = 0;
    fapi2::buffer<uint64_t> l_buffer = 0;

    FAPI_TRY(MEM_REG_PPE_LTE_GAIN_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
    FAPI_TRY(MEM_REG_PPE_LTE_ZERO_DISABLE_PUT(iv_regs, i_target, i_thread, 1));
    l_buffer.insertFromRight<IO_PPE_RX_LTE_GAIN, IO_PPE_RX_LTE_GAIN_LEN, uint32_t>(i_rx_lte_g);
    l_buffer.insertFromRight<IO_PPE_RX_LTE_ZERO, IO_PPE_RX_LTE_ZERO_LEN, uint32_t>(i_rx_lte_z);

    // LTE Gain and Zero
    l_addr = buildAddr(iv_regs->base_addr, i_thread, i_lane, IO_PPE_RX_DAC_CNTL3_PL); // A Bank LTE G/Z
    FAPI_TRY(putScom(i_target, l_addr, l_buffer));
    l_addr = buildAddr(iv_regs->base_addr, i_thread, i_lane, IO_PPE_RX_DAC_CNTL4_PL); // B Bank LTE G/Z
    FAPI_TRY(putScom(i_target, l_addr, l_buffer));

    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::set_lte_gain_zero");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::set_ctle_peaking(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint8_t i_lane,
        const int32_t i_rx_peak1,
        const int32_t i_rx_peak2)
{
    FAPI_DBG("Starting io_ppe_common::set_ctle_peaking");
    uint64_t l_addr = 0;
    fapi2::buffer<uint64_t> l_buffer = 0;

    l_buffer.insertFromRight<IO_PPE_RX_CTLE_PEAK1, IO_PPE_RX_CTLE_PEAK1_LEN, uint32_t>(i_rx_peak1);
    l_buffer.insertFromRight<IO_PPE_RX_CTLE_PEAK2, IO_PPE_RX_CTLE_PEAK2_LEN, uint32_t>(i_rx_peak2);

    l_addr = buildAddr(iv_regs->base_addr, i_thread, i_lane, IO_PPE_RX_DAC_CNTL6_PL); // A Bank CTLE PEAK1/2
    FAPI_TRY(putScom(i_target, l_addr, l_buffer));
    l_addr = buildAddr(iv_regs->base_addr, i_thread, i_lane, IO_PPE_RX_DAC_CNTL13_PL); // B Bank CTLE PEAK1/2
    FAPI_TRY(putScom(i_target, l_addr, l_buffer));

    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::set_ctle_peaking");
    return fapi2::current_err;
}



template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::config_ppe(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_num_threads,
        const uint32_t i_vio_mv)
{
    FAPI_DBG("Start");
    uint8_t l_vio_volts = 0;

    if (i_vio_mv > 900)
    {
        l_vio_volts = 0;
    }
    else if (i_vio_mv > 850)
    {
        l_vio_volts = 1;
    }
    else if (i_vio_mv > 800)
    {
        l_vio_volts = 2;
    }
    else
    {
        l_vio_volts = 3;
    }

    FAPI_TRY(IMG_REG_PPE_NUM_THREADS_PUT(iv_regs, i_target, i_num_threads));

    //"ppe_vio_volts": 2, >850mv && <=900mv
    FAPI_TRY(IMG_REG_PPE_VIO_VOLTS_PUT(iv_regs, i_target, l_vio_volts));

    //Turn off unused threads.
    for (uint32_t l_thread = i_num_threads + 1; l_thread < IO_PPE_MAX_THREADS; l_thread++)
    {
        FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, l_thread, 1));
    }

    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::config_thread(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint8_t i_gcr_id,
        const uint8_t i_num_rx_lanes,
        const uint8_t i_num_tx_lanes)
{
    FAPI_DBG("Start");
    FAPI_TRY(FW_REG_FW_GCR_BUS_ID_PUT(iv_regs, i_target, i_thread, i_gcr_id));
    FAPI_TRY(FW_REG_FW_NUM_LANES_RX_PUT(iv_regs, i_target, i_thread, i_num_rx_lanes));
    FAPI_TRY(FW_REG_FW_NUM_LANES_TX_PUT(iv_regs, i_target, i_thread, i_num_tx_lanes));
    FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::stop_thread(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_max_threads,
        bool i_stop_thread)
{
    FAPI_DBG("Start");

    constexpr uint8_t c_max_tries = 20;

    fapi2::buffer<uint64_t> l_done = 0;
    uint8_t l_tries = 0;

    for (uint8_t l_thread = 0; l_thread < i_max_threads; l_thread++)
    {
        l_done = 0;
        l_tries = 0;

        FAPI_TRY(FW_REG_FW_STOP_THREAD_PUT(iv_regs, i_target, l_thread, i_stop_thread));

        FAPI_TRY(iv_regs->flushCache(i_target));

        if (i_stop_thread)
        {
            FAPI_TRY(FW_REG_FW_THREAD_STOPPED_GET(iv_regs, i_target, l_thread, l_done));

            while (l_done && (l_tries < c_max_tries))
            {
                FAPI_TRY(iv_regs->flushCache(i_target));
                FAPI_TRY(FW_REG_FW_THREAD_STOPPED_GET(iv_regs, i_target, l_thread, l_done));
                l_tries++;
                fapi2::delay(2000000, 2000000);
            }

            if (l_done == 0)
            {
                FAPI_INF("Thread Never Stopped...");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// ===============================================================
// PPE START
// ===============================================================

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ppe_start(const fapi2::Target<K, M, V>& i_target, bool& o_fail,
        uint32_t& o_iar)
{
    const uint64_t c_lfir_wclear = (iv_regs->base_addr + 0x0);
    const uint64_t c_cscr        = (iv_regs->base_addr + 0xC);
    const uint64_t c_xixcr       = (iv_regs->base_addr + 0x10);
    const uint64_t c_xidbgpro    = (iv_regs->base_addr + 0x15);

    const uint64_t c_ppe_start_reset_iar = 0xfffe0040 >> 2;
    const uint64_t c_ppe_program_exception_iar = 0xfffe00e0 >> 2;
    const uint8_t c_sram_scrub_enable_bit = 1;
    const uint8_t c_xidbgpro_bit = 32;
    const uint8_t c_xidbgpro_len = 30;

    const uint8_t c_ppe_halted_bit = 17;
    const uint8_t c_ppe_status_bit = 0;

    fapi2::buffer<uint64_t> l_buffer = 0;

    // SRAM Scrub, set via Write-OR to CSCR
    FAPI_INF("SRAM Scrub");
    l_buffer.setBit<c_sram_scrub_enable_bit>();
    FAPI_TRY(fapi2::putScom(i_target, c_cscr, l_buffer));
    l_buffer.flush<0>();

    // Hard reset PPE
    FAPI_INF("IO hard reset.");
    l_buffer = 0x6000000000000000ULL;
    FAPI_TRY(fapi2::putScom(i_target, c_xixcr, l_buffer));
    fapi2::delay(IO_PPE_HARD_RESET_DELAY_NS, IO_PPE_HARD_RESET_DELAY_SIM_CYCLES);

    // Verify IAR @ reset vector loc
    FAPI_INF("Verify IAR reset.");
    FAPI_TRY(fapi2::getScom(i_target, c_xidbgpro, l_buffer));
    l_buffer.extractToRight<c_xidbgpro_bit, c_xidbgpro_len, uint32_t>(o_iar);

    if ((o_iar != c_ppe_start_reset_iar) || (o_iar == c_ppe_program_exception_iar))
    {
        o_fail = true;
        FAPI_DBG("IAR (0x%8x) did not reset correctly.", o_iar << 2);
        return fapi2::current_err;
    }

    l_buffer.flush<0>();

    // Resume PPE
    FAPI_INF("IO resume");
    l_buffer = 0x2000000000000000ULL;
    FAPI_TRY(fapi2::putScom(i_target, c_xixcr, l_buffer));
    fapi2::delay(IO_PPE_RESUME_DELAY_NS, IO_PPE_RESUME_DELAY_SIM_CYCLES);

    FAPI_INF("Verify IAR cleared.");
    FAPI_TRY(fapi2::getScom(i_target, c_xidbgpro, l_buffer));
    l_buffer.extractToRight<c_xidbgpro_bit, c_xidbgpro_len, uint32_t>(o_iar);

    if (o_iar == c_ppe_start_reset_iar)
    {
        o_fail = true;
        FAPI_DBG("IAR (0x%8x) did not resume.", o_iar << 2);
        return fapi2::current_err;
    }

    // Clear Halted FIR Bit
    // Reg is RW_CLEAR
    FAPI_INF("Clear halted FIR.");
    l_buffer.flush<0>();
    l_buffer.setBit<c_ppe_halted_bit>();
    FAPI_TRY(fapi2::putScom(i_target, c_lfir_wclear, l_buffer),
             "Error putscom to MAC0_LFIR_REG (clear halt).");

    FAPI_INF("Check PPE halted state");
    FAPI_TRY(fapi2::getScom(i_target, c_xidbgpro, l_buffer),
             "Error putscom to XIDBGPRO (clear halt).");

    if (l_buffer.getBit<c_ppe_status_bit>())
    {
        o_fail = true;
        FAPI_INF("PPE is halted.");
        return fapi2::current_err;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// ===============================================================
// BIST INIT
// ===============================================================

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_init_thread(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_mask,
        const uint32_t i_freq,
        const uint8_t i_bist_timer_sel,
        const uint8_t i_pcie_mode)
{
    FAPI_DBG("Start");

    uint8_t l_ppe_data_rate = calc_ppe_data_rate(i_freq);
    uint8_t l_pcie_data_rate = calc_pcie_data_rate(i_freq);

    // Set PCIe Data rate
    FAPI_TRY(FW_REG_FW_BIST_PCIE_RATE_PUT(iv_regs, i_target, i_thread, l_pcie_data_rate));

    // Set PPE Data rate
    FAPI_TRY(MEM_REG_PPE_DATA_RATE_PUT(iv_regs, i_target, i_thread, l_ppe_data_rate));

    // Cleanup of previous run
    FAPI_TRY(MEM_REG_BIST_OVERALL_PASS_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_RX_LINKLAYER_DONE_PUT(iv_regs, i_target, i_thread, 0));

    // write the timer
    FAPI_DBG("Setting BIST timer sel: %d", i_bist_timer_sel);
    FAPI_TRY(MEM_REG_RX_BER_TIMER_SEL_BIST_PUT(iv_regs, i_target, i_thread, i_bist_timer_sel));

    // Write fw_bist_en = 1
    FAPI_DBG("Setting FW BIST EN enabled");
    FAPI_TRY(FW_REG_FW_BIST_EN_PUT(iv_regs, i_target, i_thread, 1));

    //"ppe_channel_loss": 2,
    FAPI_TRY(MEM_REG_PPE_CHANNEL_LOSS_PUT(iv_regs, i_target, i_thread, 2));

    // Set FW PCIE Mode
    FAPI_TRY(FW_REG_FW_PCIE_MODE_PUT(iv_regs, i_target, i_thread, i_pcie_mode));

    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_init(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_group,
        const uint8_t i_dacTest,
        const uint8_t i_esdTest)
{
    const uint16_t c_reg_rx_datasm_cnt22 = 0x1460;
    const uint16_t c_reg_rx_ctl_cntl5 = 0x1240;

    const uint8_t c_bit_rx_esd_test = 6;        // rx_datasm_cnt22
    const uint8_t c_bit_rx_dac_test = 15;       // rx_datasm_cnt22
    const uint8_t c_bit_rx_perv_capt =   0;   //48;      // rx_ctl_cntl5
    const uint8_t c_bit_tc_bist_shared = 1;   //49;       // rx_ctl_cntl5
    const uint8_t c_bit_tc_bist_code =   3;   //51;      // rx_ctl_cntl5
    const uint8_t c_len_rx = 1;

    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_addr = 0;

    l_addr = buildAddr(iv_regs->base_addr, i_group, 0, c_reg_rx_datasm_cnt22);
    FAPI_DBG("RX_DATASM_CNTL22 Address 0x%08X%08X", (l_addr >> 32) & 0xFFFFFFFF, l_addr & 0xFFFFFFFF);

    // Write rx_dac_test_check_en = 0
    FAPI_DBG("Setting RX DAC test Check enabled");
    l_buffer.insertFromRight(i_dacTest, c_bit_rx_dac_test + 48, c_len_rx);

    // Write rx_dac_test_check_en = 0
    FAPI_DBG("Setting RX ESD test Check enabled");
    l_buffer.insertFromRight(i_esdTest, c_bit_rx_esd_test + 48, c_len_rx);

    FAPI_TRY(putScom(i_target, l_addr, l_buffer),
             "Error putscom to address 0x%08X.", l_addr);

    l_buffer.flush<0>();

    l_addr = buildAddr(iv_regs->base_addr, i_group, 0, c_reg_rx_ctl_cntl5);
    FAPI_DBG("RX_CTL_CNTL5 Address 0x%08X%08X", (l_addr >> 32) & 0xFFFFFFFF, l_addr & 0xFFFFFFFF);

    // Write rx_pervasive_capt = 1
    FAPI_DBG("Setting RX Pervasive Capt enabled");
    l_buffer.insertFromRight(1, c_bit_rx_perv_capt + 48, c_len_rx);

    // Write tc_bist_shared_ovrd = 1
    FAPI_DBG("Setting TC BIST shared overload enabled");
    l_buffer.insertFromRight(1, c_bit_tc_bist_shared + 48, c_len_rx);

    // Write tc_bist_code_go = 1
    FAPI_DBG("Setting TC BIST code go enabled");
    l_buffer.insertFromRight(1, c_bit_tc_bist_code + 48, c_len_rx);

    FAPI_TRY(putScom(i_target, l_addr, l_buffer),
             "Error putscom to address 0x%08X.", l_addr);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// ===============================================================
// BIST CLEANUP
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_cleanup(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        uint8_t& o_done,
        uint32_t& o_fail)
{
    const uint16_t c_reg_rx_ctl_cntl5 = 0x1240;
    const uint16_t c_reg_rx_bit_mode4 = 0x0670;
    const uint16_t c_reg_rx_bit_mode5 = 0x0680;
    const uint16_t c_reg_tx_ctl_mode1 = 0x1818;
    const fapi2::buffer<uint64_t> l_ext_cmd = IORESET_PL | POWER_OFF_PL;

    uint64_t l_addr = 0;
    uint8_t l_lane = 0;

    FAPI_DBG("Starting BIST cleanup");

    FAPI_DBG("Clearing error registers and BIST settings");
    FAPI_TRY(FW_REG_FW_BIST_EN_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_RX_DISABLE_BANK_PDWN_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_RX_HIST_MIN_EYE_HEIGHT_VALID_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_RX_HIST_MIN_EYE_WIDTH_VALID_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_RX_MIN_RECAL_CNT_PUT(iv_regs, i_target, i_thread, 3));


    // Set rx_ctl_cntl5_pg to 0
    //l_buffer = 0;
    l_addr = buildAddr(iv_regs->base_addr, i_thread, 0, c_reg_rx_ctl_cntl5);
    FAPI_TRY(putScom(i_target, l_addr, 0),
             "Error putscom to address 0x%08X.", l_addr);

    for (l_lane = 0; l_lane < 32; l_lane++)
    {
        if (i_rx_lanes_0_31 & (0x80000000 >> l_lane))
        {
            // Set rx_pr_fw_inertia_amt to 4
            l_addr = buildAddr(iv_regs->base_addr, i_thread, l_lane, c_reg_rx_bit_mode4);
            FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, 4, 48 + 0, 4),
                     "Error rmwIoHardwareReg to address 0x%08X.", l_addr);

            // Set rx_pr_fw_inertia_amt_coarse to 7
            l_addr = buildAddr(iv_regs->base_addr, i_thread, l_lane, c_reg_rx_bit_mode5);
            FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, 7, 48 + 0, 4),
                     "Error rmwIoHardwareReg to address 0x%08X.", l_addr);
        }
    }

    // Set tx_bist_en_alias to 0
    l_addr = buildAddr(iv_regs->base_addr, i_thread, 0, c_reg_tx_ctl_mode1);
    FAPI_TRY(rmwIoHardwareReg(i_target, l_addr, 0, 48 + 6, 3),
             "Error rmwIoHardwareReg to address 0x%08X.", l_addr);

    // Possibly TODO: clear rx_pr_unlocked_a_sticky / rx_pr_unlocked_b_sticky

    FAPI_TRY(MEM_REG_PPE_ERROR_STATE_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_ERROR_LANE_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_ERROR_THREAD_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_ERROR_VALID_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_RX_LANE_FAIL_0_31_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_TX_BIST_FAIL_0_15_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_TX_BIST_FAIL_16_23_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_PPE_SERVO_STATUS0_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(MEM_REG_PPE_SERVO_STATUS1_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_DBG("Clearing per-image registers");
    FAPI_TRY(IMG_REG_PPE_DEBUG_LOG_NUM_PUT(iv_regs, i_target, 0));

    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_DBG("Starting BIST cleanup ext_cmd");
    FAPI_TRY(ext_cmd_start(i_target, i_thread, i_rx_lanes_0_31, i_tx_lanes_0_31, l_ext_cmd));

    FAPI_DBG("Polling for BIST cleanup ext_cmd done");
    FAPI_TRY(ext_cmd_poll(i_target, i_thread, l_ext_cmd, o_done, o_fail));


fapi_try_exit:
    FAPI_DBG("End BIST cleanup");
    return fapi2::current_err;
}

// ===============================================================
// PPE_INIT
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::hss_init(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_data_rate,
        const uint32_t i_channel_length,
        const uint8_t i_spread_en,
        const uint8_t i_pcie_mode,
        const uint32_t i_auto_recal_mask)
{
    FAPI_DBG("Starting io_ppe_common::hss_init");
    const uint32_t c_high_loss_channel = 8000; // 8000 mils or 8.000 inches
    uint32_t l_channel_loss_parm = 2; // 0: high loss, 1: mid loss, 2: low loss
    uint8_t l_ppe_data_rate = calc_ppe_data_rate(i_data_rate);

    MEM_REG_PPE_DATA_RATE_PUT(iv_regs, i_target, i_thread, l_ppe_data_rate);

    if (i_channel_length > c_high_loss_channel)
    {
        l_channel_loss_parm = 0;
    }

    MEM_REG_PPE_CHANNEL_LOSS_PUT(iv_regs, i_target, i_thread, l_channel_loss_parm);

    FAPI_TRY(FW_REG_FW_SERDES_16_TO_1_MODE_PUT(iv_regs, i_target, i_thread, 1));
    FAPI_TRY(FW_REG_FW_SPREAD_EN_PUT(iv_regs, i_target, i_thread, i_spread_en));
    FAPI_TRY(FW_REG_FW_PCIE_MODE_PUT(iv_regs, i_target, i_thread, i_pcie_mode));

    MEM_REG_RX_ENABLE_AUTO_RECAL_0_31_PUT(iv_regs, i_target, i_thread, i_auto_recal_mask);
    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::hss_init");
    return fapi2::current_err;
}
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::hss_init_tx(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_lane_mask,
        const uint8_t i_tx_pre1,
        const uint8_t i_tx_pre2,
        const uint8_t i_tx_post,
        const uint32_t i_tx_fifo_l2u_dly,
        const uint32_t i_tx_unload_sel)
{
    FAPI_DBG("Starting io_ppe_common::hss_init_tx");
    uint64_t l_addr = 0;
    fapi2::buffer<uint64_t> l_buffer = 0;
    uint8_t l_lane = 0;
    MEM_REG_TX_FFE_PRE1_COEF_PUT(iv_regs, i_target, i_thread, i_tx_pre1);
    MEM_REG_TX_FFE_PRE2_COEF_PUT(iv_regs, i_target, i_thread, i_tx_pre2);
    MEM_REG_TX_FFE_POST_COEF_PUT(iv_regs, i_target, i_thread, i_tx_post);
    FAPI_TRY(iv_regs->flushCache(i_target));

    for (l_lane = 0; l_lane < 32; l_lane++)
    {
        if (i_lane_mask & (0x80000000 >> l_lane))
        {
            // tx_fifo_l2u_dly
            l_addr = buildAddr(iv_regs->base_addr, i_thread, l_lane, IO_TX_MODE4_PL);
            FAPI_TRY(getScom(i_target, l_addr, l_buffer));
            l_buffer.insertFromRight<IO_TX_FIFO_L2U_DLY, IO_TX_FIFO_L2U_DLY_LEN, uint8_t>(i_tx_fifo_l2u_dly);
            FAPI_TRY(putScom(i_target, l_addr, l_buffer));

            // tx_unload_sel
            l_addr = buildAddr(iv_regs->base_addr, i_thread, l_lane, IO_TX_MODE2_PL);
            FAPI_TRY(getScom(i_target, l_addr, l_buffer));
            l_buffer.insertFromRight<IO_TX_UNLOAD_SEL, IO_TX_UNLOAD_SEL_LEN, uint8_t>(i_tx_unload_sel);
            FAPI_TRY(putScom(i_target, l_addr, l_buffer));

            FAPI_TRY(iv_regs->flushCache(i_target));
        }
    }

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::hss_init_tx");
    return fapi2::current_err;
}
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::hss_init_rx(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_lane_mask,
        const int32_t i_rx_lte_g,
        const int32_t i_rx_lte_z,
        const int32_t i_rx_peak1,
        const int32_t i_rx_peak2)
{
    FAPI_DBG("Starting io_ppe_common::hss_init_rx");
    uint8_t l_lane = 0;

    for (l_lane = 0; l_lane < 32; l_lane++)
    {
        if (i_lane_mask & (0x80000000 >> l_lane))
        {
            // LTE Gain and Zero
            FAPI_TRY(set_lte_gain_zero(i_target, i_thread, l_lane, i_rx_lte_g, i_rx_lte_z));

            // CTLE Peak1 and Peak2
            FAPI_TRY(set_ctle_peaking(i_target, i_thread, l_lane, i_rx_peak1, i_rx_peak2));
        }
    }

    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::hss_init_rx");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::setup_func_margin(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint8_t i_rx_vert_offset,
        const uint8_t i_rx_horiz_data_offset,
        const uint8_t i_rx_horiz_edge_offset)
{
    FAPI_DBG("Starting io_ppe_common::setup_func_margin");
    FAPI_TRY(MEM_REG_PPE_OFFSET_MARGIN_MODE_PUT(iv_regs, i_target, i_thread, 3));

    FAPI_TRY(MEM_REG_PPE_LOFF_OFFSET_D_OVERRIDE_PUT(iv_regs, i_target, i_thread, i_rx_vert_offset));
    FAPI_TRY(MEM_REG_PPE_LOFF_OFFSET_PAUSE_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(MEM_REG_PPE_PR_OFFSET_D_OVERRIDE_PUT(iv_regs, i_target, i_thread, i_rx_horiz_data_offset));
    FAPI_TRY(MEM_REG_PPE_PR_OFFSET_E_OVERRIDE_PUT(iv_regs, i_target, i_thread, i_rx_horiz_edge_offset));
    FAPI_TRY(MEM_REG_PPE_PR_OFFSET_PAUSE_PUT(iv_regs, i_target, i_thread, 0));

    FAPI_TRY(iv_regs->flushCache(i_target));
fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::setup_func_margin");
    return fapi2::current_err;
}


// ===============================================================
// EXT_CMD FUNCTIONS
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_start(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        const uint32_t i_ext_cmd_req)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_start_thread");

    fapi2::buffer<uint64_t> l_clear_mode = 0;

    FAPI_TRY(FW_REG_EXT_CMD_STATUS_CLEAR_MODE_GET(iv_regs, i_target, i_thread, l_clear_mode));

    if (l_clear_mode)
    {
        FAPI_TRY(FW_REG_EXT_CMD_REQ_00_31_PUT(iv_regs, i_target, i_thread, 0));
        FAPI_TRY(iv_regs->flushCache(i_target));
        FAPI_TRY(FW_REG_EXT_CMD_DONE_00_31_PUT(iv_regs, i_target, i_thread, 0));
        FAPI_TRY(iv_regs->flushCache(i_target));
    }

    // RX / TX
    FAPI_TRY(FW_REG_EXT_CMD_LANES_RX_00_31_PUT(iv_regs, i_target, i_thread, i_rx_lanes_0_31));
    FAPI_TRY(FW_REG_EXT_CMD_LANES_TX_00_31_PUT(iv_regs, i_target, i_thread, i_tx_lanes_0_31));

    // MUST flush lanes before start
    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_TRY(FW_REG_EXT_CMD_REQ_00_31_PUT(iv_regs, i_target, i_thread, i_ext_cmd_req));

    // Flush lanes before start
    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_start_thread");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_check(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_ext_cmd_req,
        uint8_t& o_done,
        uint32_t& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_check");

    fapi2::buffer<uint64_t> l_data = 0;

    // Need to flush to clear the cache before checking so
    // The HW is read again
    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_TRY(FW_REG_EXT_CMD_DONE_00_31_GET(iv_regs, i_target, i_thread, l_data));
    o_done = (l_data ^ i_ext_cmd_req) == 0x00000000;

    FAPI_TRY(FW_REG_EXT_CMD_FAIL_00_31_GET(iv_regs, i_target, i_thread, l_data));
    o_fail = l_data;

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_check (done %d, fail 0x%08x)", o_done, o_fail);
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::ext_cmd_poll(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_ext_cmd_req,
        uint8_t& o_done,
        uint32_t& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::ext_cmd_poll");

    o_done = 0;
    o_fail = 0;
    int l_timeout = 1000;
    int l_loop_count = 0;

    while (!o_done && (l_loop_count < l_timeout))
    {
        FAPI_DBG("ext_cmd_poll: thread: %d", i_thread);
        FAPI_TRY(iv_regs->flushCache(i_target));
        FAPI_TRY(ext_cmd_check(i_target, i_thread, i_ext_cmd_req, o_done, o_fail));

        if (!o_done)
        {
            fapi2::delay(2000000, 2000000); //ns, sim cycles. 1ms
        }

        l_loop_count++;
    }

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::ext_cmd_req_poll");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::set_ext_cmd_clear_mode(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread)
{
    FAPI_DBG("Starting io_ppe_common::set_ext_cmd_clear_mode");

    FAPI_TRY(FW_REG_EXT_CMD_STATUS_CLEAR_MODE_PUT(iv_regs, i_target, i_thread, 1));
    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::set_ext_cmd_clear_mode");
    return fapi2::current_err;
}


// ===============================================================
// Debug dump
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::debug_display(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31)
{
    FAPI_INF("Start");

    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_lane = 0;

    FAPI_INF("BASE ADDRESS: 0x%X%X, thread: %d", (iv_regs->base_addr >> 32), iv_regs->base_addr, i_thread);

    FAPI_TRY(iv_regs->flushCache(i_target));

    FAPI_TRY(MEM_REG_PPE_ERROR_STATE_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_INF("PPE_ERROR_STATE: 0x%X, thread: %d", l_data, i_thread);

    FAPI_TRY(MEM_REG_TX_BIST_FAIL_0_15_GET(iv_regs, i_target, i_thread, l_data));
    FAPI_INF("MEM_REG_TX_BIST_FAIL_0_15: 0x%X, thread: %d", l_data, i_thread);

    FAPI_TRY(MEM_REG_PPE_ERROR_VALID_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d PPE_ERROR_VALID: %d", i_thread, l_data)

    if (l_data) // ppe_error_valid is set
    {
        FAPI_TRY(MEM_REG_PPE_ERROR_THREAD_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_ERROR_THREAD: %d", i_thread, l_data);
        FAPI_TRY(MEM_REG_PPE_ERROR_LANE_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_ERROR_LANE: %d", i_thread, l_data);
        FAPI_TRY(MEM_REG_PPE_ERROR_STATE_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_ERROR_STATE: 0x%04x", i_thread, l_data);
    }


    FAPI_TRY(MEM_REG_RX_LANE_FAIL_0_31_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d RX_LANE_FAIL_0_31:  0x%08x", i_thread, l_data)

    FAPI_TRY(MEM_REG_TX_BIST_FAIL_0_15_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d TX_BIST_FAIL_0_15:  0x%04x", i_thread, l_data)

    FAPI_TRY(MEM_REG_TX_BIST_FAIL_16_23_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d TX_BIST_FAIL_16_23: 0x%04x", i_thread, l_data)


    for (uint32_t l_lanes = i_rx_lanes_0_31; l_lanes & 0x80000000; l_lanes <<= 1)
    {
        FAPI_TRY(MEM_REG_RX_STEP_FAIL_ALIAS_PL_GET(iv_regs, i_target, i_thread, l_lane, l_data));
        IO_PPE_COMMON_PRINT(l_data != 0, "Thread %d, Lane %d RX_STEP_FAIL_ALIAS:  0x%04x", i_thread, l_lane, l_data)
        l_lane++;
    }


    FAPI_TRY(MEM_REG_PPE_SERVO_STATUS1_GET(iv_regs, i_target, i_thread, l_data));

    if (l_data & (0x0F80)) // Check for any errors or min/max results
    {
        FAPI_TRY(MEM_REG_PPE_SERVO_STATUS0_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_SERVO_STATUS0:  0x%04x", i_thread, l_data);
        FAPI_TRY(MEM_REG_PPE_SERVO_STATUS1_GET(iv_regs, i_target, i_thread, l_data));
        FAPI_ERR("Thread %d PPE_SERVO_STATUS1:  0x%04x", i_thread, l_data);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// ===============================================================
// BIST START
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_start(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31,
        const uint32_t i_ext_cmd_override)
{
    FAPI_DBG("Starting io_ppe_common::bist_start");

    fapi2::buffer<uint64_t> l_cmd;
    l_cmd = (i_ext_cmd_override == 0x00000000) ? BIST_START_CMD : i_ext_cmd_override;
    FAPI_INF("BIST EXT CMD 0x%08X", l_cmd);

    FAPI_TRY(ext_cmd_start(i_target, i_thread, i_rx_lanes_0_31, i_tx_lanes_0_31, l_cmd));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::bist_start");
    return fapi2::current_err;
}

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::bist_poll(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        uint8_t& o_done,
        uint32_t& o_fail,
        bool& o_bist_overall_fail,
        const uint32_t i_ext_cmd_override,
        const uint32_t i_poll_count)
{
    FAPI_DBG("Starting io_ppe_common::bist_poll");

    fapi2::buffer<uint64_t> l_cmd;
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_loop_count = 0;

    o_done = 0;
    o_fail = 0;

    l_cmd = (i_ext_cmd_override == 0x00000000) ? BIST_START_CMD : i_ext_cmd_override;
    FAPI_INF("BIST EXT CMD 0x%08X", l_cmd);

    FAPI_DBG("io_ppe_common::BIST Poll: thread: %d", i_thread);

    while (!o_done && (l_loop_count < i_poll_count))
    {
        FAPI_TRY(iv_regs->flushCache(i_target));
        FAPI_TRY(ext_cmd_check(i_target, i_thread, l_cmd, o_done, o_fail));


        if (!o_done)
        {
            fapi2::delay(20000000, 20000000); // ns, 20000000 sim cycles. 20ms
        }

        l_loop_count++;
    }

    FAPI_DBG("Final loop count %d", l_loop_count);

    FAPI_INF("BIST POLL took %d loops", l_loop_count);

    FAPI_TRY(MEM_REG_BIST_OVERALL_PASS_GET(iv_regs, i_target, i_thread, l_data));
    IO_PPE_COMMON_PRINT(l_data == 0, "Thread %d BIST_OVERALL_PASS: 0x%04x", i_thread, l_data)

    o_bist_overall_fail = l_data != 1;

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::bist_poll");
    return fapi2::current_err;
}


// ===============================================================
// ENABLE_LANES
// ===============================================================
static fapi2::buffer<uint64_t> ENABLE_LANES_CMD = POWER_ON_PL | TX_FIFO_INIT_PL;

template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::enable_lanes(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        const uint32_t i_rx_lanes_0_31,
        const uint32_t i_tx_lanes_0_31)
{
    FAPI_DBG("Starting io_ppe_common::enable_lanes");

    FAPI_TRY(ext_cmd_start(i_target, i_num_threads, i_rx_lanes_0_31, i_tx_lanes_0_31, ENABLE_LANES_CMD));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::enable_lanes");
    return fapi2::current_err;
}


template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::check_enable_lanes_done(const fapi2::Target<K, M, V>& i_target,
        const fapi2::buffer<uint64_t> i_num_threads,
        fapi2::buffer<uint64_t>& o_done,
        fapi2::buffer<uint64_t>& o_fail)
{
    FAPI_DBG("Starting io_ppe_common::check_enable_lanes_done");

    FAPI_TRY(ext_cmd_poll(i_target, i_num_threads, ENABLE_LANES_CMD, o_done, o_fail));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::check_enable_lanes_done");
    return fapi2::current_err;
}


// ===============================================================
// FAST MODE (SIM ONLY)
// ===============================================================
template<fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::fast_mode(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread)
{
    FAPI_DBG("Starting io_ppe_common::fast_mode");

    fapi2::buffer<uint64_t> l_data = 1;
    FAPI_TRY(MEM_REG_LOFF_SETTING_OVR_ENB_PUT(iv_regs, i_target, i_thread, l_data));
    FAPI_TRY(MEM_REG_AMP_SETTING_OVR_ENB_PUT(iv_regs, i_target, i_thread, l_data));
    l_data = 0;
    FAPI_TRY(MEM_REG_RX_EO_CONVERGED_END_COUNT_PUT(iv_regs, i_target, i_thread, l_data));
    FAPI_TRY(MEM_REG_RX_MIN_RECAL_CNT_PUT(iv_regs, i_target, i_thread, l_data));
    l_data = 4;
    FAPI_TRY(MEM_REG_TX_DCC_MAIN_MIN_SAMPLES_PUT(iv_regs, i_target, i_thread, l_data));

fapi_try_exit:
    FAPI_DBG("Ending io_ppe_common::fast_mode");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::clear_dl_ignore(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread)
{
    FAPI_DBG("Clearing DL Ignore bit");
    FAPI_TRY(MEM_REG_PPE_DL_IFC_IGNORE_PUT(iv_regs, i_target, i_thread, 0));
    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::set_dl_ignore(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread)
{
    FAPI_DBG("Setting DL Ignore bit");
    FAPI_TRY(MEM_REG_PPE_DL_IFC_IGNORE_PUT(iv_regs, i_target, i_thread, 1));
    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::set_pcie_presets(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread)
{
    FAPI_DBG("Setting PCIE Presets")

    // Tx Detect Rx
    // [00:03] Idle Timer = 7
    // [08:15]Samp Timer = 2
    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_IDLE_SAMP_TIMER_LANE_0_PUT(iv_regs, i_target, i_thread, 0xE002));
    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_IDLE_SAMP_TIMER_LANE_1_PUT(iv_regs, i_target, i_thread, 0xE002));
    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_IDLE_SAMP_TIMER_LANE_2_PUT(iv_regs, i_target, i_thread, 0xE002));
    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_IDLE_SAMP_TIMER_LANE_3_PUT(iv_regs, i_target, i_thread, 0xE002));

    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_DAC_CNTL_LANE_0_PUT(iv_regs, i_target, i_thread, 192));
    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_DAC_CNTL_LANE_1_PUT(iv_regs, i_target, i_thread, 192));
    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_DAC_CNTL_LANE_2_PUT(iv_regs, i_target, i_thread, 192));
    FAPI_TRY(MEM_REG_PCIE_PPE_TXDETRX_DAC_CNTL_LANE_3_PUT(iv_regs, i_target, i_thread, 192));

    // Gen1 :: 2.5Gbps :: Peak1 Preset, Peak2 Preset
    // [00:03] peak1 = 2
    // [04:07] peak2 = 2
    // [09:11] lte gain = 1
    // [13:15] let zero = 5
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE0_GEN1_PUT(iv_regs, i_target, i_thread, 0x2215));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE1_GEN1_PUT(iv_regs, i_target, i_thread, 0x2215));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE2_GEN1_PUT(iv_regs, i_target, i_thread, 0x2215));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE3_GEN1_PUT(iv_regs, i_target, i_thread, 0x2215));

    // Gen 2 :: 5Gbps :: Peak1 Preset, Peak2 Preset
    // [00:03] peak1 = 2
    // [04:07] peak2 = 2
    // [09:11] lte gain = 1
    // [13:15] let zero = 5
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE0_GEN2_PUT(iv_regs, i_target, i_thread, 0x2215));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE1_GEN2_PUT(iv_regs, i_target, i_thread, 0x2215));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE2_GEN2_PUT(iv_regs, i_target, i_thread, 0x2215));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE3_GEN2_PUT(iv_regs, i_target, i_thread, 0x2215));

    // Gen3 :: 8Gbps :: Peak1 Preset, Peak2 Preset
    // [00:03] peak1 = 4
    // [04:07] peak2 = 7
    // [09:11] lte gain = 1
    // [13:15] let zero = 5
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE0_GEN3_PUT(iv_regs, i_target, i_thread, 0x4715));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE1_GEN3_PUT(iv_regs, i_target, i_thread, 0x4715));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE2_GEN3_PUT(iv_regs, i_target, i_thread, 0x4715));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE3_GEN3_PUT(iv_regs, i_target, i_thread, 0x4715));

    // Gen 4 :: 16Gbps :: Peak1 Preset, Peak2 Cal En
    // [00:03] peak1 = 4
    // [04:07] peak2 = 0
    // [09:11] lte gain = 1
    // [13:15] let zero = 5
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE0_GEN4_PUT(iv_regs, i_target, i_thread, 0x4015));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE1_GEN4_PUT(iv_regs, i_target, i_thread, 0x4015));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE2_GEN4_PUT(iv_regs, i_target, i_thread, 0x4015));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE3_GEN4_PUT(iv_regs, i_target, i_thread, 0x4015));

    // Gen 5 :: 32Gbps :: Peak1 Cal En, Peak2 Preset
    // [00:03] peak1 = 0
    // [04:07] peak2 = 7
    // [09:11] lte gain = 1
    // [13:15] let zero = 5
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE0_GEN5_PUT(iv_regs, i_target, i_thread, 0x0715));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE1_GEN5_PUT(iv_regs, i_target, i_thread, 0x0715));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE2_GEN5_PUT(iv_regs, i_target, i_thread, 0x0715));
    FAPI_TRY(MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE3_GEN5_PUT(iv_regs, i_target, i_thread, 0x0715));

    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::auto_recal_sync(const fapi2::Target<K, M, V>& i_target,
        const uint32_t i_auto_recal_mask,
        const uint8_t i_thread,
        const uint8_t i_auto_recal)
{
    FAPI_INF("Starting auto_recal_sync");

    constexpr uint16_t PPE_STATE_RECAL_NOT_RUN = 0xF009;
    constexpr uint16_t c_max_tries = 20;

    const uint32_t c_recal_abort_mask = i_auto_recal ? 0 : i_auto_recal_mask;
    const uint32_t c_recal_lane_mask = i_auto_recal ? i_auto_recal_mask : 0;

    enum RECAL_BITS
    {
        RECAL_ABORT_BIT = 22,
        RECAL_NOT_RUN_BIT = 26,
        ASYNC_MODE_SWITCH_BIT = 32,
        LANE_BUSY_BIT = 0
    };

    fapi2::buffer<uint64_t> l_data;

    // Mask Recal Abort (Bit 22), Recal Not Run (Bit 26)
    FAPI_INF("Setting RECAL_NOT_RUN & RECAL_ABORT FIR Mask")
    l_data.setBit<RECAL_ABORT_BIT>();
    l_data.setBit<RECAL_NOT_RUN_BIT>();
    FAPI_TRY(fapi2::putScom(i_target, iv_regs->base_addr + 3, l_data)); // PPE_FIR_MASK WO_OR
    l_data.flush<0>();

    // Set the auto recal enable
    FAPI_INF("Setting RX_AUTO_RECAL")
    FAPI_TRY(MEM_REG_RX_RECAL_ABORT_0_31_PUT(iv_regs, i_target, i_thread, c_recal_abort_mask));
    FAPI_TRY(set_auto_recal(i_target, i_thread, c_recal_lane_mask));
    FAPI_TRY(iv_regs->flushCache(i_target));

    if (i_auto_recal)
    {
        // Check if there's an error state related to recal
        //  Clear if so
        FAPI_TRY(MEM_REG_PPE_ERROR_STATE_GET(iv_regs, i_target, i_thread, l_data));

        if (l_data == PPE_STATE_RECAL_NOT_RUN)
        {
            FAPI_INF("PPE Error state related to RECAL_NOT_RUN")
            FAPI_TRY(MEM_REG_PPE_ERROR_STATE_PUT(iv_regs, i_target, i_thread, 0));
            FAPI_TRY(MEM_REG_PPE_ERROR_THREAD_PUT(iv_regs, i_target, i_thread, 0));
            FAPI_TRY(MEM_REG_PPE_ERROR_LANE_PUT(iv_regs, i_target, i_thread, 0));
            FAPI_TRY(MEM_REG_PPE_ERROR_VALID_PUT(iv_regs, i_target, i_thread, 0));
            FAPI_TRY(iv_regs->flushCache(i_target));
        }

        FAPI_INF("Clearing RECAL_NOT_RUN & RECAL_ABORT FIR (& Mask)")
        l_data.setBit<RECAL_ABORT_BIT>();
        l_data.setBit<RECAL_NOT_RUN_BIT>();
        l_data.setBit<ASYNC_MODE_SWITCH_BIT>();
        // Clear Recal Not Run FIR (Bit 26), Recal Abort (Bit 22), & ASYNC_MODE_SWITCH (Bit 32)
        FAPI_TRY(fapi2::putScom(i_target, iv_regs->base_addr, l_data)); // PPE_FIR WCLEAR
        // Unmask Recal Not Run (Bit 26), Recal Abort (Bit 22), & ASYNC_MODE_SWITCH (Bit 32)
        FAPI_TRY(fapi2::putScom(i_target, iv_regs->base_addr + 2, l_data)); // PPE_FIR_MASK WCLEAR
        l_data.flush<0>();

    }
    else
    {
        // Poll rx_lane_busy == 0
        FAPI_INF("Polling for RX_LANE_BUSY == 0")

        for(uint32_t l_lane = 0; l_lane < 32; l_lane++)
        {
            uint8_t l_tries = 0;

            if (!((0x80000000 >> l_lane) & i_auto_recal_mask))
            {
                continue;
            }

            do
            {

                FAPI_TRY(MEM_REG_RX_LANE_BUSY_PL_GET(iv_regs, i_target, i_thread, l_lane, l_data));
                FAPI_TRY(iv_regs->flushCache(i_target));
                l_tries++;
                fapi2::delay(IO_PPE_DELAY_1MS, IO_PPE_DELAY_SIM_CYCLES);
            }
            while (l_data && (l_tries < c_max_tries));

            if (l_tries >= c_max_tries)
            {
                FAPI_ERR("RX Lane Busy, failed to set to 0");
            }
        }
    }


fapi_try_exit:
    FAPI_INF("End - auto_recal_sync");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::set_auto_recal(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_data)
{
    FAPI_INF("Setting set_auto_recal to 0x%08X", i_data);

    FAPI_TRY(MEM_REG_RX_ENABLE_AUTO_RECAL_0_31_PUT(iv_regs, i_target, i_thread, i_data));
    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_INF("End - set_auto_recal");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_common<K, M, V>::set_recal_not_run_disable(const fapi2::Target<K, M, V>& i_target,
        const uint8_t i_thread,
        const uint32_t i_data)
{
    FAPI_INF("Setting set_recal_not_run_disable to %d", i_data);

    FAPI_TRY(MEM_REG_PPE_RECAL_NOT_RUN_DISABLE_PUT(iv_regs, i_target, i_thread, i_data));
    FAPI_TRY(iv_regs->flushCache(i_target));

fapi_try_exit:
    FAPI_INF("End - set_recal_not_run_disable");
    return fapi2::current_err;
}
