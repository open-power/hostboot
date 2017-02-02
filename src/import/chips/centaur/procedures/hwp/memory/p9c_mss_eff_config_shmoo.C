/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_config_shmoo.C $ */
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

/// @file p9c_mss_eff_config_shmoo.C
/// @brief  setup shmoo attrs
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>

extern "C" {
    ///
    /// @brief mss_eff_config_shmoo : Sets up shmoo attrs
    /// @param[in] i_target_mba
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target_mba)
    {
        uint32_t l_datapattern = 0; // mdb - type 8 is not valid per Saravanan's Sametime
        uint32_t l_testtype = 37; // SIMPLE_FIX_RF
        uint8_t l_addr_modes = 1;
        uint8_t l_rank = 0;
        uint64_t l_start_addr = 0;
        uint64_t l_end_addr = 0;
        uint8_t l_error_capture = 0;
        uint64_t l_max_timeout = 0;
        uint8_t l_print_port = 0;
        uint8_t l_stop_on_error = 0;
        uint32_t l_data_seed = 0;
        uint8_t l_addr_inter = 0;
        uint8_t l_addr_num_rows = 0;
        uint8_t l_addr_num_cols = 0;
        uint8_t l_addr_rank = 0;
        uint8_t l_addr_bank = 0;
        uint8_t l_addr_slave_rank_on = 0;
        uint64_t l_adr_str_map = 0;
        uint8_t l_addr_rand = 0;
        uint8_t l_shmoo_mode = 0;
        uint8_t l_shmoo_addr_mode = 3;
        uint8_t l_shmoo_param_valid = 0;
        uint8_t l_shmoo_test_valid = 0;
        uint8_t l_wr_eye_min_margin = 0x46;
        uint8_t l_rd_eye_min_margin = 0x46;
        uint8_t l_dqs_clk_min_margin = 0x8c;
        uint8_t l_rd_gate_min_margin = 0x64;
        uint8_t l_adr_cmd_min_margin = 0x8c;
        uint32_t l_cen_rd_vref_shmoo[MAX_PORTS_PER_MBA] = { 0x00000000, 0x00000000 };
        uint32_t l_dram_wr_vref_schmoo[MAX_PORTS_PER_MBA] = { 0x00000000 , 0x00000000 };
        uint32_t l_cen_rcv_imp_dq_dqs_schmoo[MAX_PORTS_PER_MBA] = { 0x00000000, 0x00000000 };
        uint32_t l_cen_drv_imp_dq_dqs_schmoo[MAX_PORTS_PER_MBA] = { 0x00000000, 0x00000000 };
        uint8_t l_cen_drv_imp_cntl_schmoo[MAX_PORTS_PER_MBA] = { 0x00, 0x00 };
        uint8_t l_cen_drv_imp_clk_schmoo[MAX_PORTS_PER_MBA] =  { 0x00, 0x00 };
        uint8_t l_cen_drv_imp_spcke_schmoo[MAX_PORTS_PER_MBA] = { 0x00, 0x00 };
        uint8_t l_cen_slew_rate_dq_dqs_schmoo[MAX_PORTS_PER_MBA] = { 0x00, 0x00 };
        uint8_t l_cen_slew_rate_cntl_schmoo[MAX_PORTS_PER_MBA] = { 0x00, 0x00 };
        uint8_t l_cen_slew_rate_addr_schmoo[MAX_PORTS_PER_MBA] = { 0x00, 0x00 };
        uint8_t l_cen_slew_rate_clk_schmoo[MAX_PORTS_PER_MBA] = { 0x00, 0x00 };
        uint8_t l_cen_slew_rate_spcke_schmoo[MAX_PORTS_PER_MBA] = { 0x00, 0x00 };
        uint8_t l_mcb_print_disable = 0;
        uint8_t l_mcb_data_en = 0;
        uint8_t l_mcb_user_rank = 0;
        uint8_t l_mcb_user_bank = 0;
        uint8_t l_shmoo_mul_setup_call = 0;
        uint32_t l_rand_seed_val = 0;
        uint8_t l_rand_seed_type = 0x01;
        uint32_t l_attr_eff_cen_rd_vref[MAX_PORTS_PER_MBA] = {0};
        uint32_t l_attr_eff_dram_wr_vref[MAX_PORTS_PER_MBA] = {0};
        uint8_t l_attr_eff_cen_rcv_imp_dq_dqs[MAX_PORTS_PER_MBA] = {0};
        uint8_t l_attr_eff_cen_drv_imp_dq_dqs[MAX_PORTS_PER_MBA] = {0};
        uint8_t l_attr_eff_cen_slew_rate_dq_dqs[MAX_PORTS_PER_MBA] = {0};


        // get these attributes from the VPD but allow the code to override later
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_RD_VREF, i_target_mba, l_attr_eff_cen_rd_vref));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_WR_VREF, i_target_mba, l_attr_eff_dram_wr_vref));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_RCV_IMP_DQ_DQS, i_target_mba, l_attr_eff_cen_rcv_imp_dq_dqs));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_DQ_DQS, i_target_mba, l_attr_eff_cen_drv_imp_dq_dqs));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_SLEW_RATE_DQ_DQS, i_target_mba, l_attr_eff_cen_slew_rate_dq_dqs));

        // attriubtes that are needing to be copied from VPD into scratch pads
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_RD_VREF, i_target_mba, l_attr_eff_cen_rd_vref));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WR_VREF, i_target_mba, l_attr_eff_dram_wr_vref));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS, i_target_mba, l_attr_eff_cen_rcv_imp_dq_dqs));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS, i_target_mba, l_attr_eff_cen_drv_imp_dq_dqs));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS, i_target_mba, l_attr_eff_cen_slew_rate_dq_dqs));


        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_PRINTING_DISABLE, i_target_mba, l_mcb_print_disable));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_DATA_ENABLE, i_target_mba, l_mcb_data_en));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_USER_RANK, i_target_mba, l_mcb_user_rank));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_USER_BANK, i_target_mba, l_mcb_user_bank));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL, i_target_mba, l_shmoo_mul_setup_call));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_PATTERN, i_target_mba, l_datapattern));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_TEST_TYPE, i_target_mba, l_testtype));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_MODES, i_target_mba, l_addr_modes));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_RANK, i_target_mba, l_rank));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_START_ADDR, i_target_mba, l_start_addr));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_END_ADDR, i_target_mba, l_end_addr));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ERROR_CAPTURE, i_target_mba, l_error_capture));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_MAX_TIMEOUT, i_target_mba, l_max_timeout));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_PRINT_PORT, i_target_mba, l_print_port));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_STOP_ON_ERROR, i_target_mba, l_stop_on_error));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_DATA_SEED, i_target_mba, l_data_seed));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_INTER, i_target_mba, l_addr_inter));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_NUM_ROWS, i_target_mba, l_addr_num_rows));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_NUM_COLS, i_target_mba, l_addr_num_cols));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_RANK, i_target_mba, l_addr_rank));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba, l_addr_bank));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_SLAVE_RANK_ON, i_target_mba, l_addr_slave_rank_on));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_STR_MAP, i_target_mba, l_adr_str_map));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_RAND, i_target_mba, l_addr_rand));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_MODE, i_target_mba, l_shmoo_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE, i_target_mba, l_shmoo_addr_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_PARAM_VALID, i_target_mba, l_shmoo_param_valid));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_shmoo_test_valid));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_WR_EYE_MIN_MARGIN, i_target_mba, l_wr_eye_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_RD_EYE_MIN_MARGIN, i_target_mba, l_rd_eye_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_DQS_CLK_MIN_MARGIN, i_target_mba, l_dqs_clk_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_RD_GATE_MIN_MARGIN, i_target_mba, l_rd_gate_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN, i_target_mba, l_adr_cmd_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_RD_VREF_SCHMOO, i_target_mba, l_cen_rd_vref_shmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WR_VREF_SCHMOO, i_target_mba, l_dram_wr_vref_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, i_target_mba, l_cen_rcv_imp_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, i_target_mba, l_cen_drv_imp_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_CNTL_SCHMOO, i_target_mba, l_cen_drv_imp_cntl_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_CLK_SCHMOO, i_target_mba, l_cen_drv_imp_clk_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_SPCKE_SCHMOO, i_target_mba, l_cen_drv_imp_spcke_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO, i_target_mba, l_cen_slew_rate_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_CNTL_SCHMOO, i_target_mba, l_cen_slew_rate_cntl_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_ADDR_SCHMOO, i_target_mba, l_cen_slew_rate_addr_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_CLK_SCHMOO, i_target_mba, l_cen_slew_rate_clk_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_SPCKE_SCHMOO, i_target_mba, l_cen_slew_rate_spcke_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_RANDOM_SEED_VALUE, i_target_mba, l_rand_seed_val));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_RANDOM_SEED_TYPE, i_target_mba, l_rand_seed_type));

    fapi_try_exit:
        return fapi2::current_err;
    }
} // extern "C"
