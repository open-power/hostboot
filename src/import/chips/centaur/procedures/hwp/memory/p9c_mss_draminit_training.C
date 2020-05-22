/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_training.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

/// @file p9c_mss_draminit_training.C
/// @brief HWP for training DRAM delay values
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB


//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi2.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fld.H>
#include <p9c_mss_funcs.H>
#include <p9c_mss_ddr4_funcs.H>
#include <p9c_dimmBadDqBitmapFuncs.H>
#include <p9c_mss_unmask_errors.H>
#include "p9c_mss_access_delay_reg.H"
#include <p9c_mss_mrs6_DDR4.H>
#include <p9c_mss_row_repair.H>
#include <p9c_mss_draminit_training.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/utils/cumulus_find.H>
#include <dimmConsts.H>
#include <delayRegs.H>

const uint64_t INIT_CAL_STATUS[MAX_PORTS_PER_MBA]  = {CEN_MBA_DDRPHY_PC_INIT_CAL_STATUS_P0_ROX, CEN_MBA_DDRPHY_PC_INIT_CAL_STATUS_P1_ROX};
const uint64_t INIT_CAL_ERROR[MAX_PORTS_PER_MBA]   = {CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ROX,  CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P1_ROX};
const uint64_t INIT_CAL_CONFIG0[MAX_PORTS_PER_MBA] = {CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0,    CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P1};
const uint64_t INIT_CAL_CONFIG0_REVERSED[MAX_PORTS_PER_MBA] = {CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P1,    CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0};

enum size
{
    MAX_CAL_STEPS = 7, ///< read course and write course will occur at the same time
    MAX_DQS_RETRY = 10, ///< Used for the DQS Alignment workaround.  Determines the number of DQS alignment retries.
    DELAY_500MS = 500000000, ///< Delay used in dqs align workaround
    DELAY_LOOP = 6, ///< Delay used in dqs align workaround
    NUM_POLL = 10000 ///< Num to poll for ccs execute complete
};

extern "C" {

    ///
    /// @brief Training procedure.   Find dram delay values
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_draminit_training(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        constexpr size_t CLEANUP_QOFF_WRLVL_OFF = 0x00;  // Flag to signal configure_non_calibrating_ranks function post wrlvl
        constexpr size_t CONFIGURE_QOFF_WRLVL_ON = 0xFF; // Flag to signal configure_non_calibrating_ranks function pre wrlvl

        //Issue ZQ Cal first per rank
        uint32_t l_instruction_number = 0;
        uint8_t l_port = 0;
        uint8_t l_group = 0;
        uint8_t l_primary_ranks_array[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {0}; //primary_ranks_array[group][port]
        uint8_t l_cal_steps = 0;
        uint8_t l_dqs_try = 0;        //part of DQS alignment workaround
        uint8_t l_cur_cal_step = 0;
        fapi2::buffer<uint8_t> l_cal_steps_8;

        uint8_t l_dram_rtt_nom_original = 0;
        uint8_t l_training_success = 0;
        uint8_t l_dimm_type = 0;
        uint8_t l_dram_gen = 0;
        uint8_t l_mbaPosition = 0;

        fapi2::variable_buffer l_address_buffer_16(16);
        fapi2::variable_buffer l_bank_buffer_8(8);
        fapi2::variable_buffer l_activate_buffer_1(1);
        fapi2::variable_buffer l_rasn_buffer_1(1);
        fapi2::variable_buffer l_casn_buffer_1(1);
        fapi2::variable_buffer l_wen_buffer_1(1);
        fapi2::variable_buffer l_cke_buffer_8(8);
        fapi2::variable_buffer l_odt_buffer_8(8);
        fapi2::variable_buffer l_csn_buffer_8(8);
        fapi2::variable_buffer l_test_buffer_4(4);
        l_address_buffer_16.flush<0>();
        l_bank_buffer_8.flush<0>();
        l_activate_buffer_1.flush<0>();
        l_cke_buffer_8.flush<1>();
        l_csn_buffer_8.flush<1>();
        l_odt_buffer_8.flush<0>();

        fapi2::variable_buffer l_num_idles_buffer_16(16);
        fapi2::variable_buffer l_num_repeat_buffer_16(16);
        fapi2::variable_buffer l_data_buffer_20(20);
        fapi2::variable_buffer l_read_compare_buffer_1(1);
        fapi2::variable_buffer l_rank_cal_buffer_4(4);
        fapi2::variable_buffer l_ddr_cal_enable_buffer_1(1);
        fapi2::variable_buffer l_ccs_end_buffer_1(1);
        l_num_idles_buffer_16.flush<1>();
        l_num_repeat_buffer_16.flush<0>();
        l_data_buffer_20.flush<0>();
        l_read_compare_buffer_1.flush<0>();
        l_rank_cal_buffer_4.flush<0>();
        l_ccs_end_buffer_1.flush<1>();

        fapi2::buffer<uint8_t> l_stop_on_err_buffer_1;
        fapi2::buffer<uint16_t> l_cal_timeout_cnt_buffer_16;
        fapi2::buffer<uint8_t> l_resetn_buffer_1;
        fapi2::buffer<uint8_t> l_cal_timeout_cnt_mult_buffer_2;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        l_stop_on_err_buffer_1.flush<0>();
        l_cal_timeout_cnt_buffer_16.flush<1>();
        l_cal_timeout_cnt_mult_buffer_2.flush<1>();
        l_resetn_buffer_1.setBit<0>();

        enum mss_draminit_training_result l_cur_complete_status = MSS_INIT_CAL_COMPLETE;
        enum mss_draminit_training_result l_cur_error_status = MSS_INIT_CAL_PASS;
        enum mss_draminit_training_result l_complete_status = MSS_INIT_CAL_COMPLETE;
        enum mss_draminit_training_result l_error_status = MSS_INIT_CAL_PASS;

        uint8_t l_reset_disable = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DRAMINIT_RESET_DISABLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_reset_disable), "Failed to get ATTR_CEN_MSS_DRAMINIT_RESET_DISABLE\n");

        if (l_reset_disable != fapi2::ENUM_ATTR_CEN_MSS_DRAMINIT_RESET_DISABLE_DISABLE)
        {
            FAPI_TRY(mss_reset_delay_values(i_target), "Failed mss_reset_delay_values on %s", mss::c_str(i_target));
        }



        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target, l_dram_gen));

        //populate primary_ranks_arrays_array
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target, l_primary_ranks_array[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target, l_primary_ranks_array[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target, l_primary_ranks_array[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target, l_primary_ranks_array[3]));

        // Get MBA position: 0 = mba01, 1 = mba23
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbaPosition));
        //Get which training steps we are to run
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_CAL_STEP_ENABLE, i_target, l_cal_steps));

        l_cal_steps_8.insertFromRight<0, 8>(l_cal_steps);

        //Set up CCS Mode Reg for Init cal
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer_64));

        l_data_buffer_64.writeBit<CEN_MBA_CCS_MODEQ_STOP_ON_ERR>(l_stop_on_err_buffer_1);
        l_data_buffer_64.insert<CEN_MBA_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT, CEN_MBA_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_LEN>
        (l_cal_timeout_cnt_buffer_16);
        l_data_buffer_64.writeBit<CEN_MBA_CCS_MODEQ_MCBIST_DDR_RESETN>(l_resetn_buffer_1);
        l_data_buffer_64.insert<CEN_MBA_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_MULT, CEN_MBA_CCS_MODEQ_DDR_CAL_TIMEOUT_CNT_MULT_LEN>
        (l_cal_timeout_cnt_mult_buffer_2);

        //if in DDR4 mode, count the parity bit and set it
        if((l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) && (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM
                || l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM) )
        {
            l_data_buffer_64.insertFromRight<CEN_MBA_CCS_MODEQ_DDR_PARITY_ENABLE, 1>( (uint8_t)0xff);
        }

        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer_64), "Failed putscom on %s", mss::c_str(i_target));
        FAPI_TRY(mss_set_bbm_regs (i_target), "Failed mss_set_bbm_regs on %s", mss::c_str(i_target));

        if ( ( l_cal_steps_8.getBit<fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_EXT_ZQCAL>() ) || !(l_cal_steps_8.getBit<0, 8>()) )
        {
            FAPI_INF( "Performing External ZQ Calibration on %s.", mss::c_str(i_target));

            //Execute ZQ_CAL
            for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port ++)
            {
                FAPI_TRY(mss_execute_zq_cal(i_target, l_port), "Failed mss_execute_zq_cal on %s", mss::c_str(i_target));
            }

            //executes the following to ensure that DRAMS have a good intial WR VREF DQ
            //1) enter training mode w/ old value (nominal VREF DQ)
            //2) set value in training mode (nominal VREF DQ)
            //3) exit training mode (nominal VREF DQ)
            if(l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
            {
                FAPI_INF("For DDR4, setting VREFDQ to have an initial value!!!!");
                uint8_t l_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][NUM_RANK_GROUPS] = {0};
                uint8_t l_train_enable_override_on[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][NUM_RANK_GROUPS] = {{{fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE}, {fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE}}, {{fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE}, {fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE}}};

                FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target, l_train_enable));
                FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target, l_train_enable_override_on));

                //runs new values w/ train enable forces on
                FAPI_INF("RUN MRS6 1ST");
                FAPI_TRY(p9c_mss_mrs6_DDR4(  i_target), "Failed 1st p9c_mss_mrs6_DDR4 on %s", mss::c_str(i_target));

                FAPI_INF("RUN MRS6 2ND");
                FAPI_TRY(p9c_mss_mrs6_DDR4( i_target), "Failed 2nd p9c_mss_mrs6_DDR4 on %s", mss::c_str(i_target));
                //set old train enable value
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target, l_train_enable));

                FAPI_INF("RUN MRS6 3RD");
                FAPI_TRY(p9c_mss_mrs6_DDR4( i_target), "Failed 3rd p9c_mss_mrs6_DDR4 on %s", mss::c_str(i_target));

                //sets up the DQS offset to be 16 instead of 8
                FAPI_TRY(mss_setup_dqs_offset(i_target), "Failed mss_setup_dqs_offset on %s", mss::c_str(i_target));
            }
        }

        for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port ++)
        {
            for(l_group = 0; l_group < NUM_RANK_GROUPS; l_group ++)
            {
                //Check if rank group exists
                if(l_primary_ranks_array[l_group][l_port] != INVALID_RANK)
                {
                    //Set up for Init Cal - Done per port pair
                    FAPI_TRY(l_test_buffer_4.setBit(0, 2)); //Init Cal test = 11XX
                    l_wen_buffer_1.flush<1>(); //Init Cal ras/cas/we = 1/1/1
                    l_casn_buffer_1.flush<1>();
                    l_rasn_buffer_1.flush<1>();
                    l_ddr_cal_enable_buffer_1.flush<1>(); //Init cal
                    l_dqs_try = 0;

                    FAPI_INF( "+++ Setting up Init Cal on %s Port: %d rank group: %d cal_steps: 0x%02X +++", mss::c_str(i_target), l_port,
                              l_group, l_cal_steps);

                    for(l_cur_cal_step = 1; l_cur_cal_step < MAX_CAL_STEPS; l_cur_cal_step ++) //Cycle through all possible cal steps
                    {
                        FAPI_TRY(clear_status_and_error_regs(i_target, l_port), "Failed to clear status and error regs on %s",
                                 mss::c_str(i_target));

                        FAPI_TRY(configure_cal_registers(i_target, l_port, l_group, l_cur_cal_step, l_cal_steps_8),
                                 "Failed to confiugre cal registers on %s", mss::c_str(i_target));

                        FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_CONFIG0[l_port], l_data_buffer_64),
                                 "Failed to getscom INIT_CAL_CONFIG0 on %s", mss::c_str(i_target));

                        if ( ( l_data_buffer_64.getBit<48, 8>() ) ) // Only execute if we are doing a Cal Step
                        {
                            // Before WR_LVL --- Change the RTT_NOM to RTT_WR pre-WR_LVL
                            if ( (l_cur_cal_step == fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_LVL)
                                 && (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
                            {
                                l_dram_rtt_nom_original = 0xFF;
                                FAPI_TRY(mss_rtt_nom_rtt_wr_swap(i_target,
                                                                 l_port,
                                                                 l_primary_ranks_array[l_group][l_port],
                                                                 l_group,
                                                                 l_instruction_number,
                                                                 l_dram_rtt_nom_original), "mss_rtt_nom_rtt_wr_swap failed!");
                                // Set non-calibrating ranks wr lvl == enable and qoff
                                FAPI_TRY(configure_non_calibrating_ranks(i_target, l_port, l_group, CONFIGURE_QOFF_WRLVL_ON, l_instruction_number),
                                         "Failed to configure non calibrating ranks with wr lvl settings on %s", mss::c_str(i_target));
                            }

                            //DDR4 RDIMM, do the swap of the RTT_WR to RTT_NOM
                            if ( (l_cur_cal_step == fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_LVL)
                                 && (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
                            {
                                l_dram_rtt_nom_original = 0xFF;
                                FAPI_TRY(mss_ddr4_rtt_nom_rtt_wr_swap(i_target,
                                                                      l_mbaPosition,
                                                                      l_port,
                                                                      l_primary_ranks_array[l_group][l_port],
                                                                      l_group,
                                                                      l_instruction_number,
                                                                      l_dram_rtt_nom_original), "mss_ddr4_rtt_nom_rtt_wr_swap failed!");
                                // Set non-calibrating ranks wr lvl == enable and qoff
                                FAPI_TRY(configure_non_calibrating_ranks(i_target, l_port, l_group, CONFIGURE_QOFF_WRLVL_ON, l_instruction_number),
                                         "Failed to configure non calibrating ranks with wr lvl settings on %s", mss::c_str(i_target));
                            }

                            FAPI_TRY(mss_ccs_inst_arry_0(i_target,
                                                         l_instruction_number,
                                                         l_address_buffer_16,
                                                         l_bank_buffer_8,
                                                         l_activate_buffer_1,
                                                         l_rasn_buffer_1,
                                                         l_casn_buffer_1,
                                                         l_wen_buffer_1,
                                                         l_cke_buffer_8,
                                                         l_csn_buffer_8,
                                                         l_odt_buffer_8,
                                                         l_test_buffer_4,
                                                         l_port));

                            //Error handling for mss_ccs_inst built into mss_funcs

                            FAPI_INF( "primary_ranks_array[%d][0]: %d [%d][1]: %d", l_group, l_primary_ranks_array[l_group][0], l_group,
                                      l_primary_ranks_array[l_group][1]);

                            FAPI_TRY(l_rank_cal_buffer_4.insert(l_primary_ranks_array[l_group][l_port], 0, 4,
                                                                4)); // 8 bit storage, need last 4 bits
                            FAPI_TRY(mss_ccs_inst_arry_1(i_target,
                                                         l_instruction_number,
                                                         l_num_idles_buffer_16,
                                                         l_num_repeat_buffer_16,
                                                         l_data_buffer_20,
                                                         l_read_compare_buffer_1,
                                                         l_rank_cal_buffer_4,
                                                         l_ddr_cal_enable_buffer_1,
                                                         l_ccs_end_buffer_1));

                            //Error handling for mss_ccs_inst built into mss_funcs
                            FAPI_TRY(mss_execute_ccs_inst_array( i_target, NUM_POLL, 60));

                            //Check to see if the training completes
                            FAPI_TRY(mss_check_cal_status(i_target, l_port, l_group, l_cur_complete_status));

                            if (l_cur_complete_status == MSS_INIT_CAL_STALL)
                            {
                                l_complete_status = l_cur_complete_status;
                            }

                            //Check to see if the training errored out
                            FAPI_TRY(mss_check_error_status(i_target, l_port, l_group, l_cur_cal_step, l_cur_error_status, l_dqs_try));

                            if (l_cur_error_status == MSS_INIT_CAL_FAIL)
                            {
                                l_error_status = l_cur_error_status;
                            }

                            // Following WR_LVL -- Restore RTT_NOM to orignal value post-wr_lvl
                            if ((l_cur_cal_step == fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_LVL)
                                && (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3))
                            {
                                FAPI_TRY(mss_rtt_nom_rtt_wr_swap(i_target,
                                                                 l_port,
                                                                 l_primary_ranks_array[l_group][l_port],
                                                                 l_group,
                                                                 l_instruction_number,
                                                                 l_dram_rtt_nom_original));
                                //cleanup non calibrating ranks wr_lvl enable and qoff
                                FAPI_TRY(configure_non_calibrating_ranks(i_target, l_port, l_group, CLEANUP_QOFF_WRLVL_OFF, l_instruction_number),
                                         "Failed to cleanup non calibrating ranks with wr lvl settings on %s", mss::c_str(i_target));
                            }

                            // Following WR_LVL -- Restore RTT_NOM to orignal value post-wr_lvl
                            if ((l_cur_cal_step == fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_LVL)
                                && (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
                            {
                                FAPI_TRY(mss_ddr4_rtt_nom_rtt_wr_swap(i_target,
                                                                      l_mbaPosition,
                                                                      l_port,
                                                                      l_primary_ranks_array[l_group][l_port],
                                                                      l_group,
                                                                      l_instruction_number,
                                                                      l_dram_rtt_nom_original));
                                //cleanup non calibrating ranks wr_lvl enable and qoff
                                FAPI_TRY(configure_non_calibrating_ranks(i_target, l_port, l_group, CLEANUP_QOFF_WRLVL_OFF, l_instruction_number),
                                         "Failed to cleanup non calibrating ranks with wr lvl settings on %s", mss::c_str(i_target));
                            }

                        } //end if l_data_buffer_64.getBit<48, 8>
                    }//end of step loop
                } //end if RG exists
            }//end of group loop
        }//end of port loop

        if ((l_error_status != MSS_INIT_CAL_FAIL) && (l_error_status != MSS_INIT_CAL_STALL))
        {
            l_training_success = 0xFF;
        }

        FAPI_TRY(mss_get_bbm_regs(i_target, l_training_success),
                 "Error Moving bad bit information from the Phy regs on %s. Exiting.", mss::c_str(i_target));

        //Executes if we do "all at once" or on the last cal steps
        //Must be a successful run.
        if (l_error_status == MSS_INIT_CAL_PASS &&
            (l_cal_steps_8.getBit<6, 2>() || !(l_cal_steps_8.getBit<0, 8>()) ) )
        {
            FAPI_INF( "WR LVL DISABLE WORKAROUND: Running wr_lvl workaround on %s", mss::c_str(i_target));
            FAPI_TRY(mss_wr_lvl_disable_workaround(i_target), "mss_wr_lvl_disable_workaround failed on %s", mss::c_str(i_target));
        }

        // If we hit either of these States, the error callout originates from Mike Jones Bad Bit code.
        if (l_complete_status == MSS_INIT_CAL_STALL)
        {
            FAPI_ERR( "+++ Partial/Full calibration stall. Check Debug trace. +++");
        }
        else if (l_error_status == MSS_INIT_CAL_FAIL)
        {
            FAPI_ERR( "+++ Partial/Full calibration fail. Check Debug trace. +++");
        }
        else
        {
            FAPI_INF( "+++ Full calibration successful. +++");
        }

        // If mss_unmask_draminit_training_errors gets it's own bad rc,
        // it will commit the passed in rc (if non-zero), and return it's own bad rc.
        // Else if mss_unmask_draminit_training_errors runs clean,
        // it will just return the passed in rc.
        FAPI_TRY(mss_unmask_draminit_training_errors(i_target), "Failed to unmask errors on %s", mss::c_str(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Clear cal-related status and error regs
    /// @param[in] i_port Port to clear
    /// @return fapi2::FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode clear_status_and_error_regs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_port)
    {
        fapi2::buffer<uint64_t> l_data_buffer_64;

        FAPI_ASSERT(i_port < MAX_PORTS_PER_MBA,
                    fapi2::CEN_INVALID_PORT().
                    set_PORT_POSITION(i_port).
                    set_TARGET_MBA_ERROR(i_target),
                    "clear_status_and_error_regs got invalid input on %s port: %d",
                    mss::c_str(i_target), i_port);

        //clear status reg
        FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_STATUS[i_port], l_data_buffer_64), "Failed to getscom INIT_CAL_STATUS on %s",
                 mss::c_str(i_target));
        l_data_buffer_64.clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_STATUS_P0_COMPLETE, CEN_MBA_DDRPHY_PC_INIT_CAL_STATUS_P0_COMPLETE_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, INIT_CAL_STATUS[i_port], l_data_buffer_64), "Failed to putscom INIT_CAL_STATUS on %s",
                 mss::c_str(i_target));
        //clear error reg
        FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_ERROR[i_port], l_data_buffer_64), "Failed to getscom INIT_CAL_ERROR on %s",
                 mss::c_str(i_target));
        l_data_buffer_64.clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_WR_LEVEL>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_INITIAL_PAT_WRITE>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_DQS_ALIGN>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_RDCLK_ALIGN>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_READ_CTR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_WRITE_CTR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_INITIAL_COARSE_WR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_COARSE_RD>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_CUSTOM_RD>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_CUSTOM_WR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_DIGITAL_EYE>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_RANK_PAIR, CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_RANK_PAIR_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, INIT_CAL_ERROR[i_port], l_data_buffer_64), "Failed to putscom INIT_CAL_ERROR on %s",
                 mss::c_str(i_target));

        //Clearing any status or errors bits that may have occured in previous training subtest.
        //clear other port
        FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_CONFIG0_REVERSED[i_port], l_data_buffer_64),
                 "Failed to getscom INIT_CAL_CONFIG0_REVERSED on %s", mss::c_str(i_target));
        l_data_buffer_64.clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WR_LEVEL>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_DQS_ALIGN>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RDCLK_ALIGN>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_READ_CTR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WRITE_CTR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_COARSE_WR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_COARSE_RD>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ABORT_ON_ERROR>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR, CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, INIT_CAL_CONFIG0_REVERSED[i_port], l_data_buffer_64),
                 "Failed to putscom INIT_CAL_CONFIG0_REVERSED on %s", mss::c_str(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Configure calibration register in phy
    /// @param[in] i_target MBA Target to configure
    /// @param[in] i_port Port to calibrate
    /// @param[in] i_group Rank Group to calibrate
    /// @param[in] i_cur_step Current calibration step
    /// @param[in] i_cal_step_arr Cal steps to run
    /// @return fapi2::FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode configure_cal_registers(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_port,
            const uint8_t i_group,
            const uint8_t i_cur_cal_step,
            const fapi2::buffer<uint8_t>& i_cal_steps)
    {
        //Setup the Config Reg bit for the only cal step we want
        fapi2::buffer<uint64_t> l_data_buffer_64;
        //Setup the Config Reg bit for the only cal step we want
        FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_CONFIG0[i_port], l_data_buffer_64),
                 "Failed to getscom INIT_CAL_CONFIG0 on %s", mss::c_str(i_target));

        //Clear training cnfg
        l_data_buffer_64.clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WR_LEVEL>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_DQS_ALIGN, 6>().
        clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR, CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR_LEN>();
        //Set stop on error
        l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ABORT_ON_ERROR>();
        //cnfg rank groups
        FAPI_TRY(l_data_buffer_64.setBit(CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR + i_group),
                 "Failed to configure rank group for calibration on %s",
                 mss::c_str(i_target));

        switch (i_cur_cal_step)
        {
            case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_LVL:
                if ( !(i_cal_steps.getBit<0, 8>()) )
                {
                    FAPI_INF( "+++ Executing ALL Cal Steps at the same time on %s Port: %d rank group: %d +++",
                              mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WR_LEVEL>().
                    setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_DQS_ALIGN, 6>();
                }
                else if ( i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_LVL))
                {
                    FAPI_INF( "+++ Write Leveling (WR_LVL) on %s Port %d rank group: %d +++", mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WR_LEVEL>();
                }

                break;

            case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_DQS_ALIGN:
                if (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_DQS_ALIGN))
                {
                    FAPI_INF( "+++ DQS Align (DQS_ALIGN) on %s Port: %d rank group: %d +++", mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_DQS_ALIGN>();
                }

                break;

            case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_RDCLK_ALIGN:
                if (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_RDCLK_ALIGN))
                {
                    FAPI_INF( "+++ RD CLK Align (RDCLK_ALIGN) on %s Port: %d rank group: %d +++", mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RDCLK_ALIGN>();
                }

                break;

            case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_RD_CTR:
                if (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_RD_CTR))
                {
                    FAPI_INF( "+++ Read Centering (READ_CTR) on %s Port: %d rank group: %d +++", mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_READ_CTR>();
                }

                break;

            case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_CTR:
                if (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_CTR))
                {
                    FAPI_INF( "+++ Write Centering (WRITE_CTR) on %s Port: %d rank group: %d +++", mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WRITE_CTR>();
                }

                break;

            case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_WR:
                if ( (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_WR))
                     && !(i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_RD)) )
                {
                    FAPI_INF( "+++ Initial Course Write (COURSE_WR) on %s Port: %d rank group: %d +++", mss::c_str(i_target), i_port,
                              i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_COARSE_WR>();
                }
                else if ( !(i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_WR))
                          && (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_RD)) )
                {
                    FAPI_INF( "+++ Course Read (COURSE_RD) on %s Port: %d rank group: %d +++", mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_COARSE_RD>();
                }
                else if ( (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_WR))
                          && (i_cal_steps.getBit(fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_RD)) )
                {
                    FAPI_INF( "+++ Initial Course Write (COURSE_WR) and Course Read (COURSE_RD) simultaneously on %s Port: %d rank group: %d +++",
                              mss::c_str(i_target), i_port, i_group);
                    l_data_buffer_64.setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_COARSE_WR, 2>();
                }

                break;

            default:
                break;
        }

        //Set the config register
        FAPI_TRY(fapi2::putScom(i_target, INIT_CAL_CONFIG0[i_port], l_data_buffer_64),
                 "Failed to putscom INIT_CAL_CONFIG0 on %s", mss::c_str(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Check status of init cal.  Poll until stalled or complete
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port   Memory port
    /// @param[in] i_group  Rank group
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_check_cal_status( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                            const uint8_t i_port,
                                            const uint8_t i_group,
                                            mss_draminit_training_result& io_status
                                          )
    {
        fapi2::buffer<uint64_t> l_cal_status_buffer_64;
        uint8_t l_poll_count = 1;
        const uint8_t l_cal_status_reg_offset = CEN_MBA_DDRPHY_PC_INIT_CAL_STATUS_P0_COMPLETE + i_group;

        FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_STATUS[i_port], l_cal_status_buffer_64));

        while((!l_cal_status_buffer_64.getBit(l_cal_status_reg_offset)) &&
              (l_poll_count <= 20))
        {
            FAPI_INF( "+++ Calibration on %s port: %d rank group: %d in progress. Poll count: %d +++", mss::c_str(i_target), i_port,
                      i_group, l_poll_count);

            ++l_poll_count;

            FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_STATUS[i_port], l_cal_status_buffer_64));
        }

        if(l_cal_status_buffer_64.getBit(CEN_MBA_DDRPHY_PC_INIT_CAL_STATUS_P0_COMPLETE + i_group))
        {
            FAPI_INF( "+++ Calibration on %s port: %d rank group: %d finished. +++", mss::c_str(i_target), i_port, i_group);
            io_status = MSS_INIT_CAL_COMPLETE;
        }
        else
        {
            FAPI_ERR( "+++ Calibration on %s port: %d rank group: %d has stalled! +++", mss::c_str(i_target), i_port, i_group);
            io_status = MSS_INIT_CAL_STALL;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }


    ///
    /// @brief Interprets initcal error register
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_group Memory Rank Group
    /// @param[in, out] io_cur_cal_step   Step of init cal
    /// @param[in, out] io_status Cal Status
    /// @param[in, out] io_dqs_try  Num dqs_align retries
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_check_error_status(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_port,
            const uint8_t i_group,
            uint8_t& io_cur_cal_step,
            mss_draminit_training_result& io_status,
            uint8_t& io_dqs_try
                                            )
    {
        // Used to determine if the error should be logged as recovered or not
        bool l_training_error = false;
        fapi2::buffer<uint64_t> l_cal_error_buffer_64;
        fapi2::buffer<uint64_t> l_disable_bit_data_for_dp18_buffer_64;
        uint8_t l_mbaPosition = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbaPosition));

        FAPI_ASSERT(i_port < MAX_PORTS_PER_MBA && i_group < NUM_RANK_GROUPS,
                    fapi2::CEN_INVALID_INPUT_DATA().
                    set_PORT_POSITION(i_port).
                    set_RANKGROUP_POSITION(i_group).
                    set_MBA_POSITION(l_mbaPosition).
                    set_TARGET_MBA_ERROR(i_target),
                    "mss_check_error_status got invalid input on %s port: %d  rankgroup: %d",
                    mss::c_str(i_target), i_port, i_group);

        FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_ERROR[i_port], l_cal_error_buffer_64));

        if(l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_RANK_PAIR, CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_RANK_PAIR_LEN>())
        {
            io_status = MSS_INIT_CAL_FAIL;
            l_training_error = true;
            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_WR_LEVEL>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_WR_LVL_ERROR().
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group).
                        set_TARGET_MBA_ERROR(i_target),
                        "+++ Write leveling error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);

            if(l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_DQS_ALIGN>())
            {
                // DQS Alignment Work Around:
                if (io_dqs_try < MAX_DQS_RETRY)
                {
                    l_training_error = false;
                    ++io_dqs_try;
                    --io_cur_cal_step;
                    FAPI_INF( "+++ DQS Alignment recovery attempt %d on %s port: %d rank group: %d! +++", io_dqs_try, mss::c_str(i_target),
                              i_port,
                              i_group);

                    l_disable_bit_data_for_dp18_buffer_64.flush<0>();

                    //Clear all disable regs before next attempt
                    for (const auto& l_dp_reg : l_disable_reg[i_port][i_group])
                    {
                        FAPI_TRY(fapi2::putScom(i_target, l_dp_reg, l_disable_bit_data_for_dp18_buffer_64));
                    }

                    //Delay before next attempt
                    FAPI_INF("Delaying before next DQS_ALIGN Attempt on %s.", mss::c_str(i_target));

                    for(uint8_t l_delay = 0; l_delay < DELAY_LOOP; l_delay++)
                    {
                        FAPI_TRY(fapi2::delay(DELAY_500MS, DELAY_500SIMCYCLES));
                    }
                } // if dqs_try < max
                else
                {
                    l_training_error = true;
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_DRAMINIT_TRAINING_DQS_ALIGNMENT_ERROR().
                                set_TARGET_MBA_ERROR(i_target).
                                set_MBA_POSITION(l_mbaPosition).
                                set_PORT_POSITION(i_port).
                                set_RANKGROUP_POSITION(i_group),
                                "+++ DQS Alignment error occured on %s port: %d rank group: %d! Max attempts of %d tried and failed.  +++",
                                mss::c_str(i_target), i_port, i_group, io_dqs_try);
                }
            } // if getBit<50>

            l_training_error = true;
            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_RDCLK_ALIGN>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_RD_CLK_SYS_CLK_ALIGNMENT_ERROR().
                        set_TARGET_MBA_ERROR(i_target).
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group),
                        "+++ RDCLK to SysClk alignment error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);

            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_READ_CTR>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_RD_CENTERING_ERROR().
                        set_TARGET_MBA_ERROR(i_target).
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group),
                        "+++ Read centering error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);



            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_WRITE_CTR>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_WR_CENTERING_ERROR().
                        set_TARGET_MBA_ERROR(i_target).
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group),
                        "+++ Write centering error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);

            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_COARSE_RD>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_COURSE_RD_CENTERING_ERROR().
                        set_TARGET_MBA_ERROR(i_target).
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group),
                        "+++ +++ Coarse read centering error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);

            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_CUSTOM_RD>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_CUSTOM_PATTERN_RD_CENTERING_ERROR().
                        set_TARGET_MBA_ERROR(i_target).
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group),
                        "+++ Custom pattern read centering error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);

            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_CUSTOM_WR>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_CUSTOM_PATTERN_WR_CENTERING_ERROR().
                        set_TARGET_MBA_ERROR(i_target).
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group),
                        "+++ Custom pattern write centering error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);

            FAPI_ASSERT(!l_cal_error_buffer_64.getBit<CEN_MBA_DDRPHY_PC_INIT_CAL_ERROR_P0_ERROR_DIGITAL_EYE>(),
                        fapi2::CEN_MSS_DRAMINIT_TRAINING_DIGITAL_EYE_ERROR().
                        set_TARGET_MBA_ERROR(i_target).
                        set_MBA_POSITION(l_mbaPosition).
                        set_PORT_POSITION(i_port).
                        set_RANKGROUP_POSITION(i_group),
                        "+++ Digital eye error occured on %s port: %d rank group: %d! +++",
                        mss::c_str(i_target), i_port, i_group);
        } // endif getBit<60,4>
        else
        {
            switch (io_cur_cal_step)
            {
                case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_LVL:
                    FAPI_INF( "+++ Write_leveling on %s port: %d rank group: %d was successful. +++", mss::c_str(i_target), i_port,
                              i_group);
                    break;

                case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_DQS_ALIGN:
                    FAPI_INF( "+++ DQS Alignment on %s port: %d rank group: %d was successful. +++", mss::c_str(i_target), i_port, i_group);
                    break;

                case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_RDCLK_ALIGN:
                    FAPI_INF( "+++ RDCLK to SysClk alignment on %s port: %d rank group: %d was successful. +++", mss::c_str(i_target),
                              i_port, i_group);
                    break;

                case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_RD_CTR:
                    FAPI_INF( "+++ Read Centering on %s port: %d rank group: %d was successful. +++", mss::c_str(i_target), i_port,
                              i_group);
                    break;

                case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_WR_CTR:
                    FAPI_INF( "+++ Write Centering on %s port: %d rank group: %d was successful. +++", mss::c_str(i_target), i_port,
                              i_group);
                    break;

                case fapi2::ENUM_ATTR_CEN_MSS_CAL_STEP_ENABLE_COARSE_WR:
                    FAPI_INF( "+++ Course Read and/or Course Write on %s port: %d rank group: %d was successful. +++", mss::c_str(i_target),
                              i_port, i_group);
                    break;

                default:
                    break;
            }

            io_status = MSS_INIT_CAL_PASS;
        }

        return fapi2::FAPI2_RC_SUCCESS;
    fapi_try_exit:
#ifdef __HOSTBOOT_MODULE

        // If we took a training fail, log it as recovered - memdiags will sort it out
        if(l_training_error)
        {
            auto l_temp_rc = fapi2::current_err;
            fapi2::logError(l_temp_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

#else

        if(l_training_error)
        {
            FAPI_ERR("%s error was caused by a training error", mss::c_str(i_target));
        }

#endif
        return fapi2::current_err;
    }

    ///
    /// @brief  DQS_CLK for each nibble of a byte is being adjusted to the lowest value for the given byte
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_wr_lvl_disable_workaround(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target
    )
    {
        constexpr uint64_t DISABLE_BITS_LEN = 4;
        constexpr uint64_t DISABLE_BITS_NIBBLE0 = CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_01_DISABLE_15;
        constexpr uint64_t DISABLE_BITS_NIBBLE1 = CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_01_DISABLE_15 + 4;
        constexpr uint64_t DISABLE_BITS_NIBBLE2 = CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_01_DISABLE_15 + 8;
        constexpr uint64_t DISABLE_BITS_NIBBLE3 = CEN_MBA_DDRPHY_DP18_DATA_BIT_DISABLE0_RP0_P0_0_01_DISABLE_15 + 12;

        //DQS_CLK for each nibble of a byte is being adjusted to the lowest value for the given byte
        //Across all byte lanes
        uint8_t l_primary_ranks_array[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {0}; //primary_ranks_array[group][port]
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint8_t l_port = 0;
        uint8_t l_rank_group = 0;
        uint8_t l_block = 0;
        uint32_t l_byte = 0;
        uint32_t l_nibble = 0;
        uint8_t l_dqsclk_phase_value_u8[NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK][MAX_BYTES_PER_BLOCK][MAX_NIBBLES_PER_BYTE] = {0}; // l_lowest_value_u8[group][block][byte_of_reg][nibble_of_byte]
        uint8_t l_disable_value_u8[NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK][MAX_BYTES_PER_BLOCK][MAX_NIBBLES_PER_BYTE] = {0};
        uint8_t l_disable_old_value_u8[NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK][MAX_BYTES_PER_BLOCK][MAX_NIBBLES_PER_BYTE] = {0};
        uint8_t l_gate_delay_value_u8[NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK][MAX_BYTES_PER_BLOCK][MAX_NIBBLES_PER_BYTE] = {0};
        uint8_t l_rdclk_phase_value_u8[NUM_RANK_GROUPS][MAX_BLOCKS_PER_RANK][MAX_BYTES_PER_BLOCK][MAX_NIBBLES_PER_BYTE] = {0};
        uint8_t l_ranks_array[NUM_RANK_GROUPS][MAX_RANKS_PER_DIMM][MAX_PORTS_PER_MBA] = {0}; //[group][rank_group position][port]
        uint8_t l_flag = 0;
        uint8_t l_verbose = 0;
        uint8_t l_rank_u8 = 0;
        uint32_t l_old_delay_value_u32 = 0;
        uint32_t l_old_DQS_delay_value_u32 = 0;
        uint32_t l_delay_value_u32 = 0;
        uint32_t l_DQS_delay_value_u32 = 0;
        uint8_t l_index_u8 = 0;
        uint8_t l_mask = 0;
        uint8_t l_nibble_dq = 0;
        uint8_t l_rg = 0;
        uint8_t l_rank_2 = 0;
        uint8_t l_width = 0;
        uint8_t l_dqs_index = 0;
        uint32_t l_instruction_number = 0;
        fapi2::variable_buffer l_address_buffer_16(16);
        fapi2::variable_buffer l_activate_buffer_1(1);
        fapi2::variable_buffer l_rasn_buffer_1(1);
        fapi2::variable_buffer l_casn_buffer_1(1);
        fapi2::variable_buffer l_wen_buffer_1(1);
        fapi2::variable_buffer l_cke_buffer_8(8);
        fapi2::variable_buffer l_csn_buffer_8(8);
        fapi2::variable_buffer l_odt_buffer_8(8);
        fapi2::variable_buffer l_bank_buffer_8(8);
        fapi2::variable_buffer l_test_buffer_4(4);
        fapi2::variable_buffer l_num_idles_buffer_16(16);
        fapi2::variable_buffer l_num_repeat_buffer_16(16);
        fapi2::variable_buffer l_data_buffer_20(20);
        fapi2::variable_buffer l_read_compare_buffer_1(1);
        fapi2::variable_buffer l_rank_cal_buffer_4(4);
        fapi2::variable_buffer l_ddr_cal_enable_buffer_1(1);
        fapi2::variable_buffer l_ccs_end_buffer_1(1);
        uint8_t l_group = 255;
        uint8_t l_cur_cal_step = 2;
        uint8_t l_mbaPosition = 0;
        uint8_t l_curr_bit = 0;
        uint8_t max_retries = MAX_DQS_RETRY;

        //populate primary_ranks_arrays_array
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target, l_primary_ranks_array[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target, l_primary_ranks_array[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target, l_primary_ranks_array[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target, l_primary_ranks_array[3]));

        FAPI_DBG("WR LVL DISABLE WORKAROUND: Entered WR_LVL workaround");

        for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port ++)
        {
            //Gather all the byte information
            for(l_rank_group = 0; l_rank_group < NUM_RANK_GROUPS; l_rank_group ++)
            {
                //Initialize values
                for(l_block = 0; l_block < MAX_BLOCKS_PER_RANK; l_block ++)
                {
                    for (l_byte = 0; l_byte < MAX_BYTES_PER_BLOCK; l_byte ++)
                    {
                        for (l_nibble = 0; l_nibble < MAX_NIBBLES_PER_BYTE; l_nibble ++)
                        {
                            l_dqsclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble] = 255;
                            l_gate_delay_value_u8[l_rank_group][l_block][l_byte][l_nibble] = 255;
                            l_rdclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble] = 255;
                            l_disable_value_u8[l_rank_group][l_block][l_byte][l_nibble] = 0;
                            l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble] = 0;

                        }
                    }
                }

                //Check if rank group exists
                if(l_primary_ranks_array[l_rank_group][l_port] != 255)
                {
                    FAPI_DBG("WR LVL DISABLE WORKAROUND: DISABLE Workaround being applied on  %s  PORT: %d RP: %d", mss::c_str(i_target),
                             l_port, l_rank_group);

                    for(uint8_t l_block = 0; l_block < MAX_BLOCKS_PER_RANK; l_block++)
                    {
                        FAPI_TRY(fapi2::getScom(i_target, l_disable_reg[l_port][l_rank_group][l_block], l_data_buffer_64), "getScom Failed!");
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE0, DISABLE_BITS_LEN>
                        (l_disable_value_u8[l_rank_group][l_block][0][0]);
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE1, DISABLE_BITS_LEN>
                        (l_disable_value_u8[l_rank_group][l_block][0][1]);
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE2, DISABLE_BITS_LEN>
                        (l_disable_value_u8[l_rank_group][l_block][1][0]);
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE3, DISABLE_BITS_LEN>
                        (l_disable_value_u8[l_rank_group][l_block][1][1]);
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE0, DISABLE_BITS_LEN>
                        (l_disable_old_value_u8[l_rank_group][l_block][0][0]);
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE1, DISABLE_BITS_LEN>
                        (l_disable_old_value_u8[l_rank_group][l_block][0][1]);
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE2, DISABLE_BITS_LEN>
                        (l_disable_old_value_u8[l_rank_group][l_block][1][0]);
                        l_data_buffer_64.extractToRight<DISABLE_BITS_NIBBLE3, DISABLE_BITS_LEN>
                        (l_disable_old_value_u8[l_rank_group][l_block][1][1]);

                        FAPI_TRY(fapi2::getScom(i_target, l_dqs_rd_phase_select[l_port][l_rank_group][l_block], l_data_buffer_64),
                                 "getScom Failed!");
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT0,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT0_LEN>
                                                        (l_dqsclk_phase_value_u8[l_rank_group][l_block][0][0]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT1,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT1_LEN>
                                                        (l_dqsclk_phase_value_u8[l_rank_group][l_block][0][1]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT2,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT2_LEN>
                                                        (l_dqsclk_phase_value_u8[l_rank_group][l_block][1][0]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT3,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_DQSCLK_SELECT3_LEN>
                                                        (l_dqsclk_phase_value_u8[l_rank_group][l_block][1][1]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT0,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT0_LEN>
                                                        (l_rdclk_phase_value_u8[l_rank_group][l_block][0][0]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT1,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT1_LEN>
                                                        (l_rdclk_phase_value_u8[l_rank_group][l_block][0][1]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT2,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT2_LEN>
                                                        (l_rdclk_phase_value_u8[l_rank_group][l_block][1][0]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT3,
                                                        CEN_MBA_DDRPHY_DP18_DQS_RD_PHASE_SELECT_RANK_PAIR0_P0_0_01_RDCLK_SELECT3_LEN>
                                                        (l_rdclk_phase_value_u8[l_rank_group][l_block][1][1]);

                        FAPI_TRY(fapi2::getScom(i_target, l_dqs_gate_delay[l_port][l_rank_group][l_block], l_data_buffer_64),
                                 "getScom Failed!");
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N0,
                                                        CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N0_LEN>
                                                        (l_gate_delay_value_u8[l_rank_group][l_block][0][0]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N1,
                                                        CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N1_LEN>
                                                        (l_gate_delay_value_u8[l_rank_group][l_block][0][1]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N2,
                                                        CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N2_LEN>
                                                        (l_gate_delay_value_u8[l_rank_group][l_block][1][0]);
                        l_data_buffer_64.extractToRight<CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N3,
                                                        CEN_MBA_DDRPHY_DP18_DQS_GATE_DELAY_RP0_P0_0_01_N3_LEN>
                                                        (l_gate_delay_value_u8[l_rank_group][l_block][1][1]);
                    } //for block
                } //if rank group exists
            } // for rank group

            // Determine rank and rank group matching
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target, l_ranks_array[0][0]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target, l_ranks_array[1][0]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target, l_ranks_array[2][0]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target, l_ranks_array[3][0]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP0, i_target, l_ranks_array[0][1]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP1, i_target, l_ranks_array[1][1]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP2, i_target, l_ranks_array[2][1]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP3, i_target, l_ranks_array[3][1]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP0, i_target, l_ranks_array[0][2]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP1, i_target, l_ranks_array[1][2]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP2, i_target, l_ranks_array[2][2]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP3, i_target, l_ranks_array[3][2]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0, i_target, l_ranks_array[0][3]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1, i_target, l_ranks_array[1][3]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2, i_target, l_ranks_array[2][3]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3, i_target, l_ranks_array[3][3]));


            access_type_t l_access_type_e = READ;
            input_type_t l_input_type_e = WR_DQS;

            enum mss_draminit_training_result l_cur_error_status = MSS_INIT_CAL_PASS;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, l_width));
            l_address_buffer_16.flush<0>();
            l_bank_buffer_8.flush<0>();
            l_activate_buffer_1.flush<0>();
            l_cke_buffer_8.flush<1>();
            l_csn_buffer_8.flush<1>();
            l_odt_buffer_8.flush<0>();
            l_test_buffer_4.setBit(0, 4);
            l_num_idles_buffer_16.flush<1>();
            l_num_repeat_buffer_16.flush<0>();
            l_data_buffer_20.flush<0>();
            l_read_compare_buffer_1.flush<0>();
            l_rank_cal_buffer_4.flush<0>();
            l_ddr_cal_enable_buffer_1.flush<1>();
            l_ccs_end_buffer_1.flush<1>();

            // Get MBA position: 0 = mba01, 1 = mba23
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbaPosition));


            //Resetting Disable mask.  Avoid spares.
            for(l_block = 0; l_block < MAX_BLOCKS_PER_RANK; l_block ++)
            {
                for (l_byte = 0; l_byte < MAX_BYTES_PER_BLOCK; l_byte ++)
                {
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES_PER_BYTE; l_nibble ++)
                    {
                        for(l_rank_group = 0; l_rank_group < NUM_RANK_GROUPS; l_rank_group ++)
                        {
                            //Check if rank group exists
                            if(l_primary_ranks_array[l_rank_group][l_port] != 255)
                            {
                                // l_lane is not const because it's an i/o in mss_c4_phy below
                                uint8_t l_lane = l_byte * BITS_PER_BYTE + l_nibble * BITS_PER_NIBBLE;
                                l_input_type_e = WR_DQ;
                                l_flag = 1;
                                // C4 DQ to lane/block (l_flag = 0) in PHY or lane/block to C4 DQ (l_flag = 1)
                                // In this case moving from  lane/block to C4 DQ to determine spare
                                FAPI_TRY(mss_c4_phy(i_target, l_port, l_rank_group, l_input_type_e, l_index_u8, l_verbose, l_lane, l_block, l_flag));


                                l_dqs_index = l_index_u8 / 8;


                                if ( ((l_dqs_index % 9 == 0) && (l_dqs_index / 9 > 0))
                                     && (l_disable_value_u8[l_rank_group][l_block][l_byte][l_nibble] != 0x0))
                                {
                                    //This is a spare.  Unmark it in the old map for the rest of the workaround to not operate on a spare
                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: Denoting Spare that is disabled for block: %d byte: %d nibble: %d Previous Value: 0x%02X",
                                             l_block, l_byte, l_nibble, l_disable_value_u8[l_rank_group][l_block][l_byte][l_nibble]);
                                    l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble] = 0x00;

                                }
                                else if (l_disable_value_u8[l_rank_group][l_block][l_byte][l_nibble] != 0x00)
                                {
                                    //This is not a spare.  Unmark into what will be scommed back in; to be able to reset the disable mask.
                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: Unmasking disable for block: %d byte: %d nibble: %d Previous Value: 0x%02X",
                                             l_block,
                                             l_byte, l_nibble, l_disable_value_u8[l_rank_group][l_block][l_byte][l_nibble]);
                                    l_disable_value_u8[l_rank_group][l_block][l_byte][l_nibble] = 0x00;
                                }

                                for(uint8_t l_block_num = 0; l_block_num < MAX_BLOCKS_PER_RANK; l_block_num++)
                                {
                                    FAPI_TRY(fapi2::getScom(i_target, l_disable_reg[l_port][l_rank_group][l_block_num], l_data_buffer_64),
                                             "getScom failed!");
                                    l_data_buffer_64.insertFromRight<48, 4>(l_disable_value_u8[l_rank_group][l_block_num][0][0]);
                                    l_data_buffer_64.insertFromRight<52, 4>(l_disable_value_u8[l_rank_group][l_block_num][0][1]);
                                    l_data_buffer_64.insertFromRight<56, 4>(l_disable_value_u8[l_rank_group][l_block_num][1][0]);
                                    l_data_buffer_64.insertFromRight<60, 4>(l_disable_value_u8[l_rank_group][l_block_num][1][1]);
                                    FAPI_TRY(fapi2::putScom(i_target, l_disable_reg[l_port][l_rank_group][l_block_num], l_data_buffer_64));
                                }
                            } // end if rank group exists
                        } // end for rank group
                    } // end for nibble
                }  // end for byte
            } // end for block


            //Re-run DQS ALIGN for only rank_group/ports that had a disable.
            for(l_rank_group = 0; l_rank_group < NUM_RANK_GROUPS; l_rank_group ++)
            {
                l_group = 255;

                for(l_block = 0; l_block < MAX_BLOCKS_PER_RANK; l_block ++)
                {
                    for (l_byte = 0; l_byte < MAX_BYTES_PER_BLOCK; l_byte ++)
                    {
                        for (l_nibble = 0; l_nibble < MAX_NIBBLES_PER_BYTE; l_nibble ++)
                        {
                            //Check if rank group exists
                            if(l_primary_ranks_array[l_rank_group][l_port] != 255)
                            {
                                if (l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble] != 0x0)
                                {
                                    l_group = l_rank_group;
                                }
                            }
                        }
                    }
                } // end for block

                FAPI_DBG("WR LVL DISABLE WORKAROUND: DQS ALIGN LOOP on group: %d rank_group: %d port: %d", l_group, l_rank_group,
                         l_port);

                if (l_group != 255)
                {
                    FAPI_DBG("WR LVL DISABLE WORKAROUND: Re-Running DQS ALIGN on rank_group: %d port: %d", l_group, l_port);

                    FAPI_TRY(clear_status_and_error_regs(i_target, l_port), "Failed to clear cal error and status regs on %s",
                             mss::c_str(i_target));

                    //Setup the Config Reg bit for the only cal step we want
                    FAPI_TRY(fapi2::getScom(i_target, INIT_CAL_CONFIG0[l_port], l_data_buffer_64),
                             "Failed to getscom INIT_CAL_CONFIG0 on %s", mss::c_str(i_target));

                    //Clear training cnfg
                    l_data_buffer_64.clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WR_LEVEL>().
                    clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_PAT_WR>().
                    setBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_DQS_ALIGN>(). //Rerun DQS_ALIGN
                    clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RDCLK_ALIGN>().
                    clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_READ_CTR>().
                    clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_WRITE_CTR>().
                    clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_INITIAL_COARSE_WR>().
                    clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_COARSE_RD>().
                    clearBit<CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR, CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR_LEN>();  // rerun dqs align

                    FAPI_TRY(l_data_buffer_64.setBit(CEN_MBA_DDRPHY_PC_INIT_CAL_CONFIG0_P0_ENA_RANK_PAIR + l_group));

                    //Set the config register
                    FAPI_TRY(fapi2::putScom(i_target, INIT_CAL_CONFIG0[l_port], l_data_buffer_64),
                             "Failed to putscom INIT_CAL_CONFIG0 on %s", mss::c_str(i_target));

                    FAPI_TRY(mss_ccs_inst_arry_0(i_target,
                                                 l_instruction_number,
                                                 l_address_buffer_16,
                                                 l_bank_buffer_8,
                                                 l_activate_buffer_1,
                                                 l_rasn_buffer_1,
                                                 l_casn_buffer_1,
                                                 l_wen_buffer_1,
                                                 l_cke_buffer_8,
                                                 l_csn_buffer_8,
                                                 l_odt_buffer_8,
                                                 l_test_buffer_4,
                                                 l_port));


                    FAPI_TRY(l_rank_cal_buffer_4.insert(l_primary_ranks_array[l_rank_group][l_port], 0, 4,
                                                        4)); // 8 bit storage, need last 4 bits

                    FAPI_TRY(mss_ccs_inst_arry_1(i_target,
                                                 l_instruction_number,
                                                 l_num_idles_buffer_16,
                                                 l_num_repeat_buffer_16,
                                                 l_data_buffer_20,
                                                 l_read_compare_buffer_1,
                                                 l_rank_cal_buffer_4,
                                                 l_ddr_cal_enable_buffer_1,
                                                 l_ccs_end_buffer_1));
                    //Error handling for mss_ccs_inst built into mss_funcs

                    FAPI_TRY(mss_execute_ccs_inst_array( i_target, NUM_POLL, 60));
                    //Error handling for mss_ccs_inst built into mss_funcs

                    //Check to see if the training errored out, no dqs align workaround.
                    FAPI_TRY(mss_check_error_status(i_target, l_port, l_group, l_cur_cal_step, l_cur_error_status, max_retries));

                    if (l_cur_error_status == MSS_INIT_CAL_FAIL)
                    {
                        //RC/Log is generated in mss_check_error_status
                        FAPI_ERR("Error returned on workaround Re-run of DQS_ALIGN on %s  PORT: %d RP: %d", mss::c_str(i_target), l_port,
                                 l_group);
                    }

                } // end if rank group exists (!=255)
            } // end for each rank group

            //Finding the lowest Values on disabled bytes, then resetting mask.
            for(l_block = 0; l_block < MAX_BLOCKS_PER_RANK; l_block ++)
            {
                for (l_byte = 0; l_byte < MAX_BYTES_PER_BLOCK; l_byte ++)
                {
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES_PER_BYTE; l_nibble ++)
                    {
                        for(l_rank_group = 0; l_rank_group < NUM_RANK_GROUPS; l_rank_group ++)
                        {
                            for (l_nibble_dq = 0; l_nibble_dq < 4; l_nibble_dq ++)
                            {
                                if (l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble] != 0x00)
                                {
                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: DISABLED block: %d byte: %d nibble: %d disable value: 0x%02X", l_block, l_byte,
                                             l_nibble,
                                             l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble]);
                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: DQSCLK replacement: block: %d byte: %d nibble: %d current value: %d", l_block,
                                             l_byte,
                                             l_nibble, l_dqsclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble]);

                                    //SWAPPING DQSCLK PHASE SELECT
                                    for (l_rg = 0; l_rg < NUM_RANK_GROUPS; l_rg ++)
                                    {
                                        FAPI_DBG("WR LVL DISABLE WORKAROUND: DQSCLK possible replacement value: %d",
                                                 l_dqsclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble]);

                                        if ( (l_disable_old_value_u8[l_rg][l_block][l_byte][l_nibble] == 0)
                                             && (l_dqsclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble] <
                                                 l_dqsclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble]) )
                                        {
                                            FAPI_DBG("WR LVL DISABLE WORKAROUND: DQSCLK replacement: block: %d byte: %d nibble: %d", l_block, l_byte, l_nibble);
                                            FAPI_DBG("WR LVL DISABLE WORKAROUND: DQSCLK replacement value: %d",
                                                     l_dqsclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble]);
                                            l_dqsclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble] =
                                                l_dqsclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble];
                                        }
                                    }

                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: RDCLK replacement: block: %d byte: %d nibble: %d current value: %d", l_block,
                                             l_byte,
                                             l_nibble, l_dqsclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble]);

                                    //SWAPPING RDCLK PHASE SELECT
                                    for (l_rg = 0; l_rg < NUM_RANK_GROUPS; l_rg ++)
                                    {
                                        FAPI_DBG("WR LVL DISABLE WORKAROUND: RDCLK possible replacement value: %d",
                                                 l_rdclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble]);

                                        if ( (l_disable_old_value_u8[l_rg][l_block][l_byte][l_nibble] == 0)
                                             && (l_rdclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble] <
                                                 l_rdclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble]) )
                                        {
                                            FAPI_DBG("WR LVL DISABLE WORKAROUND: RDCLK replacement: block: %d byte: %d nibble: %d", l_block, l_byte, l_nibble);
                                            FAPI_DBG("WR LVL DISABLE WORKAROUND: RDCLK replacement value: %d",
                                                     l_rdclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble]);
                                            l_rdclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble] =
                                                l_rdclk_phase_value_u8[l_rg][l_block][l_byte][l_nibble];
                                        }
                                    }

                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: GATE DELAY replacement: block: %d byte: %d nibble: %d current value: %d", l_block,
                                             l_byte, l_nibble, l_dqsclk_phase_value_u8[l_rank_group][l_block][l_byte][l_nibble]);

                                    //SWAPPING RDCLK PHASE SELECT
                                    for (l_rg = 0; l_rg < NUM_RANK_GROUPS; l_rg ++)
                                    {
                                        FAPI_DBG("WR LVL DISABLE WORKAROUND: GATE DELAY possible replacement value: %d",
                                                 l_gate_delay_value_u8[l_rg][l_block][l_byte][l_nibble]);

                                        if ( (l_disable_old_value_u8[l_rg][l_block][l_byte][l_nibble] == 0)
                                             && (l_gate_delay_value_u8[l_rg][l_block][l_byte][l_nibble] <
                                                 l_gate_delay_value_u8[l_rank_group][l_block][l_byte][l_nibble]) )
                                        {
                                            FAPI_DBG("WR LVL DISABLE WORKAROUND: GATE DELAY replacement: block: %d byte: %d nibble: %d", l_block, l_byte, l_nibble);
                                            FAPI_DBG("WR LVL DISABLE WORKAROUND: GATE DELAY replacement value: %d",
                                                     l_gate_delay_value_u8[l_rg][l_block][l_byte][l_nibble]);
                                            l_gate_delay_value_u8[l_rank_group][l_block][l_byte][l_nibble] = l_gate_delay_value_u8[l_rg][l_block][l_byte][l_nibble];
                                        }
                                    }

                                    //SWAPPING DQ AND DQS
                                    l_mask = 0x8 >> l_nibble_dq;
                                    l_curr_bit = l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble] & l_mask;
                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: DQ/DQS SWAP MASK: 0x%02X DISABLE BIT: 0x%02X CURR BIT: 0x%02X", l_mask,
                                             l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble] & l_mask, l_curr_bit);

                                    if (l_curr_bit)
                                    {

                                        FAPI_DBG("%s WR LVL DISABLE WORKAROUND: DQ/DQS SWAP RANK_GROUP: %d BLOCK: %d BYTE: %d NIBBLE: %d DISABLE VALUE: 0x%02X",
                                                 mss::c_str(i_target), l_rank_group, l_block, l_byte, l_nibble,
                                                 l_disable_old_value_u8[l_rank_group][l_block][l_byte][l_nibble]);

                                        //Figure out which lane to investigate
                                        l_index_u8 = l_nibble_dq + 4 * l_nibble + 8 * l_byte;
                                        // l_lane isn't const because it's an i/o in mss_c4_phy below
                                        uint8_t l_lane = l_index_u8;

                                        l_input_type_e = WR_DQ;
                                        l_flag = 1;
                                        // C4 DQ to lane/block (flag = 0) in PHY or lane/block to C4 DQ (flag = 1)
                                        // In this case moving from lane/block to C4 DQ to use access_delay_reg
                                        FAPI_TRY(mss_c4_phy(i_target, l_port, l_rank_group, l_input_type_e, l_index_u8, l_verbose, l_lane, l_block, l_flag));

                                        l_access_type_e = READ;
                                        l_rank_u8 = l_ranks_array[l_rank_group][0][0];

                                        if (l_rank_u8 == 255)
                                        {
                                            continue;
                                        }

                                        // Getting old DQ Value
                                        l_input_type_e = WR_DQ;
                                        FAPI_TRY(mss_access_delay_reg(i_target, l_access_type_e, l_port, l_ranks_array[l_rank_group][0][0], l_input_type_e,
                                                                      l_index_u8, l_verbose, l_old_delay_value_u32));

                                        if (l_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8)
                                        {
                                            l_dqs_index = l_index_u8 / 8;
                                        }
                                        else
                                        {
                                            l_dqs_index = l_index_u8 / 4;
                                        }

                                        // Getting old DQS Value
                                        l_input_type_e = WR_DQS;
                                        FAPI_TRY(mss_access_delay_reg(i_target, l_access_type_e, l_port, l_ranks_array[l_rank_group][0][0], l_input_type_e,
                                                                      l_dqs_index,
                                                                      l_verbose, l_old_DQS_delay_value_u32));

                                        FAPI_DBG("WR LVL DISABLE WORKAROUND: Value being replaced C4: %d C4 DQS: %d Rank:%d DQ DELAY VALUE: 0x%03X DQS DELAY VALUE: 0x%03X ",
                                                 l_index_u8, l_dqs_index, l_ranks_array[l_rank_group][0][0], l_old_delay_value_u32, l_old_DQS_delay_value_u32);

                                        for (l_rg = 0; l_rg < NUM_RANK_GROUPS; l_rg ++)
                                        {
                                            l_access_type_e = READ;
                                            l_rank_2 = l_ranks_array[l_rg][0][0];
                                            FAPI_DBG("WR LVL DISABLE WORKAROUND: RANK: %d DISABLE VALUE: 0x%02X MASKED: 0x%02X", l_rank_2,
                                                     l_disable_old_value_u8[l_rg][l_block][l_byte][l_nibble],
                                                     l_disable_old_value_u8[l_rg][l_block][l_byte][l_nibble] & l_mask);

                                            if ( (l_rank_2 != 255) && (l_disable_old_value_u8[l_rg][l_block][l_byte][l_nibble] == 0 ) )
                                            {
                                                // Getting New DQ Value
                                                l_input_type_e = WR_DQ;
                                                FAPI_TRY(mss_access_delay_reg(i_target, l_access_type_e, l_port, l_rank_2, l_input_type_e, l_index_u8, l_verbose,
                                                                              l_delay_value_u32));

                                                // Getting New DQS Value
                                                l_input_type_e = WR_DQS;
                                                FAPI_TRY(mss_access_delay_reg(i_target, l_access_type_e, l_port, l_rank_2, l_input_type_e, l_dqs_index, l_verbose,
                                                                              l_DQS_delay_value_u32));

                                                FAPI_DBG("WR LVL DISABLE WORKAROUND: Possible Replacement Value C4: %d C4 DQS: %d Rank:%d DQ DELAY VALUE: 0x%03X DQS DELAY VALUE: 0x%03X",
                                                         l_index_u8, l_dqs_index, l_rank_2, l_delay_value_u32, l_DQS_delay_value_u32);

                                                if ( l_delay_value_u32 < l_old_delay_value_u32)
                                                {
                                                    l_old_delay_value_u32 = l_delay_value_u32;
                                                    // Writing DQ Value
                                                    l_access_type_e = WRITE;
                                                    l_rank_u8 = l_ranks_array[l_rank_group][0][0];
                                                    l_input_type_e = WR_DQ;
                                                    FAPI_TRY(mss_access_delay_reg(i_target, l_access_type_e, l_port, l_ranks_array[l_rank_group][0][0], l_input_type_e,
                                                                                  l_index_u8, l_verbose, l_delay_value_u32));

                                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: Replacing DQ: Value C4: %d C4 DQS: %d Rank:%d DELAY VALUE: 0x%03X", l_index_u8,
                                                             l_dqs_index, l_ranks_array[l_rank_group][0][0], l_delay_value_u32);
                                                }

                                                if ( l_DQS_delay_value_u32 < l_old_DQS_delay_value_u32)
                                                {
                                                    l_old_DQS_delay_value_u32 = l_DQS_delay_value_u32;
                                                    // Writing DQS Value
                                                    l_access_type_e = WRITE;
                                                    l_rank_u8 = l_ranks_array[l_rank_group][0][0];
                                                    l_input_type_e = WR_DQS;
                                                    FAPI_TRY(mss_access_delay_reg(i_target, l_access_type_e, l_port, l_ranks_array[l_rank_group][0][0], l_input_type_e,
                                                                                  l_dqs_index,
                                                                                  l_verbose, l_DQS_delay_value_u32));

                                                    FAPI_DBG("WR LVL DISABLE WORKAROUND: Replacing DQS: Value C4: %d C4 DQS: %d Rank:%d DQS DELAY VALUE: 0x%03X",
                                                             l_index_u8, l_dqs_index, l_ranks_array[l_rank_group][0][0], l_DQS_delay_value_u32);
                                                }
                                            } // if rank is valid
                                        } // for each rank
                                    } // if curr_bit
                                } // if nibble disabled
                            } // for each nibble dq
                        } // for each rank group
                    } // for each nibble
                } // for each byte
            } // for each block

            //Scoming in the New Values
            for(l_rank_group = 0; l_rank_group < NUM_RANK_GROUPS; l_rank_group ++)
            {
                //Check if rank group exists
                if(l_primary_ranks_array[l_rank_group][l_port] != 255)
                {
                    for(uint8_t l_block = 0; l_block < MAX_BLOCKS_PER_RANK; l_block++)
                    {
                        FAPI_TRY(fapi2::getScom(i_target, l_dqs_rd_phase_select[l_port][l_rank_group][l_block], l_data_buffer_64));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_dqsclk_phase_value_u8[l_rank_group][l_block][0][0], 48, 2));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_dqsclk_phase_value_u8[l_rank_group][l_block][0][1], 52, 2));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_dqsclk_phase_value_u8[l_rank_group][l_block][1][0], 56, 2));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_dqsclk_phase_value_u8[l_rank_group][l_block][1][1], 60, 2));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_rdclk_phase_value_u8[l_rank_group][l_block][0][0], 50, 2));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_rdclk_phase_value_u8[l_rank_group][l_block][0][1], 54, 2));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_rdclk_phase_value_u8[l_rank_group][l_block][1][0], 58, 2));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_rdclk_phase_value_u8[l_rank_group][l_block][1][1], 62, 2));
                        FAPI_TRY(fapi2::putScom(i_target, l_dqs_rd_phase_select[l_port][l_rank_group][l_block], l_data_buffer_64));


                        FAPI_TRY(fapi2::getScom(i_target, l_dqs_gate_delay[l_port][l_rank_group][l_block], l_data_buffer_64));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_gate_delay_value_u8[l_rank_group][l_block][0][0], 49, 3));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_gate_delay_value_u8[l_rank_group][l_block][0][1], 53, 3));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_gate_delay_value_u8[l_rank_group][l_block][1][0], 57, 3));
                        FAPI_TRY(l_data_buffer_64.insertFromRight(l_gate_delay_value_u8[l_rank_group][l_block][1][1], 61, 3));
                        FAPI_TRY(fapi2::putScom(i_target, l_dqs_gate_delay[l_port][l_rank_group][l_block], l_data_buffer_64));
                    }
                } // if rank group exists
            } // for each rank group
        } // for each port

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Reset Wr_level delays and Gate Delays
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_reset_delay_values(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        //Across all configed rank pairs, in order
        uint8_t l_primary_ranks_array[4][2]; //primary_ranks_array[group][port]
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint8_t l_port = 0;
        uint8_t l_rank_group = 0;


        //populate primary_ranks_arrays_array
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target, l_primary_ranks_array[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target, l_primary_ranks_array[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target, l_primary_ranks_array[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target, l_primary_ranks_array[3]));

        //Hit the reset button for wr_lvl values
        //These won't reset until the next run of wr_lvl
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG2_P0, l_data_buffer_64));
        l_data_buffer_64.insertFromRight<CEN_MBA_DDRPHY_WC_CONFIG2_P0_EN_RESET_WR_DELAY_WL, 1>((uint8_t) 0xFF);
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG2_P0, l_data_buffer_64));

        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG2_P1, l_data_buffer_64));
        l_data_buffer_64.insertFromRight<CEN_MBA_DDRPHY_WC_CONFIG2_P0_EN_RESET_WR_DELAY_WL, 1>((uint8_t) 0xFF);
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG2_P1, l_data_buffer_64));

        //Scoming in zeros into the Gate delay l_registers.
        for(l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port ++)
        {
            for(l_rank_group = 0; l_rank_group < NUM_RANK_GROUPS; l_rank_group ++)
            {
                //Check if rank group exists
                if(l_primary_ranks_array[l_rank_group][l_port] != 255)
                {
                    l_data_buffer_64.flush<0>();

                    for(uint8_t l_block = 0; l_block < MAX_BLOCKS_PER_RANK; l_block++)
                    {
                        FAPI_TRY(fapi2::putScom(i_target, l_dqs_gate_delay[l_port][l_rank_group][l_block], l_data_buffer_64));
                    }
                } // if rank group exists
            } // rank group
        } // port

    fapi_try_exit:
        return fapi2::current_err;
    }


    ///
    /// @brief Places RTT_WR into RTT_NOM within MR1 before wr_lvl
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port_number Memory port
    /// @param[in] i_rank Memory Rank
    /// @param[in] i_rank_pair_group Rank group
    /// @param[in,out] io_ccs_inst_cnt  CCS instance number
    /// @param[in,out] io_dram_rtt_nom_original RTT_NOM val which will be overwritten
    /// @return fapi2::ReturnCode
    ///
    /// @note If the function argument dram_rtt_nom_original has a value of 0xFF it will put the original rtt_nom there
    /// @note and write rtt_wr to the rtt_nom value
    /// @note If the function argument dram_rtt_nom_original has any value besides 0xFF it will try to write that value to rtt_nom.
    fapi2::ReturnCode mss_rtt_nom_rtt_wr_swap(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint32_t i_port_number,
        const uint8_t i_rank,
        const uint32_t i_rank_pair_group,
        uint32_t& io_ccs_inst_cnt,
        uint8_t& io_dram_rtt_nom_original)
    {
        fapi2::variable_buffer l_address_16(16);
        fapi2::variable_buffer l_bank_3(3);
        fapi2::variable_buffer l_activate_1(1);
        fapi2::variable_buffer l_rasn_1(1);
        fapi2::variable_buffer l_casn_1(1);
        fapi2::variable_buffer l_wen_1(1);
        fapi2::variable_buffer l_cke_4(4);
        fapi2::variable_buffer l_csn_8(8);
        fapi2::variable_buffer l_odt_4(4);
        fapi2::variable_buffer l_ddr_cal_type_4(4);
        fapi2::variable_buffer l_num_idles_16(16);
        fapi2::variable_buffer l_num_repeat_16(16);
        fapi2::variable_buffer l_data_20(20);
        fapi2::variable_buffer l_read_compare_1(1);
        fapi2::variable_buffer l_rank_cal_4(4);
        fapi2::variable_buffer l_ddr_cal_enable_1(1);
        fapi2::variable_buffer l_ccs_end_1(1);
        fapi2::variable_buffer l_mrs1_16(16);
        fapi2::variable_buffer l_mrs2_16(16);
        fapi2::buffer<uint64_t> l_data_buffer_64;

        uint16_t l_MRS1 = 0;
        uint16_t l_MRS2 = 0;
        uint8_t l_dimm = 0;
        uint8_t l_dimm_rank = 0;
        uint8_t l_dimm_type = 0;
        uint8_t l_is_sim = 0;
        uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
        uint8_t l_dll_enable = 0x00; //DLL Enable
        uint8_t l_out_drv_imp_cntl = 0x00;
        uint8_t l_dram_rtt_nom = 0x00;
        uint8_t l_dram_al = 0x00;
        uint8_t l_tdqs_enable = 0x00; //TDQS Enable
        uint8_t l_wr_lvl = 0x00; //write leveling enable
        uint8_t l_q_off = 0x00; //Qoff - Output buffer Enable
        uint8_t l_dram_rtt_wr = 0x00;
        constexpr uint64_t const MR1_ADDRESS[MAX_PORTS_PER_MBA][NUM_RANK_GROUPS] =
        {
            {CEN_MBA_DDRPHY_PC_MR1_PRI_RP0_P0, CEN_MBA_DDRPHY_PC_MR1_PRI_RP1_P0, CEN_MBA_DDRPHY_PC_MR1_PRI_RP2_P0, CEN_MBA_DDRPHY_PC_MR1_PRI_RP3_P0},
            {CEN_MBA_DDRPHY_PC_MR1_PRI_RP0_P1, CEN_MBA_DDRPHY_PC_MR1_PRI_RP1_P1, CEN_MBA_DDRPHY_PC_MR1_PRI_RP2_P1, CEN_MBA_DDRPHY_PC_MR1_PRI_RP3_P1}
        };
        constexpr uint64_t const MR2_ADDRESS[MAX_PORTS_PER_MBA][NUM_RANK_GROUPS] =
        {
            {CEN_MBA_DDRPHY_PC_MR2_PRI_RP0_P0, CEN_MBA_DDRPHY_PC_MR2_PRI_RP1_P0, CEN_MBA_DDRPHY_PC_MR2_PRI_RP2_P0, CEN_MBA_DDRPHY_PC_MR2_PRI_RP3_P0},
            {CEN_MBA_DDRPHY_PC_MR2_PRI_RP0_P1, CEN_MBA_DDRPHY_PC_MR2_PRI_RP1_P1, CEN_MBA_DDRPHY_PC_MR2_PRI_RP2_P1, CEN_MBA_DDRPHY_PC_MR2_PRI_RP3_P1}
        };

        FAPI_TRY(l_rasn_1.clearBit(0));
        FAPI_TRY(l_casn_1.clearBit(0));
        FAPI_TRY(l_wen_1.clearBit(0));
        FAPI_TRY(l_cke_4.setBit(0, 4));
        FAPI_TRY(l_csn_8.setBit(0, 8));
        FAPI_TRY(l_odt_4.setBit(0, 4));
        // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
        l_dimm = (i_rank) / 4;
        l_dimm_rank = i_rank - 4 * l_dimm;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));

        // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
        FAPI_TRY(l_csn_8.setBit(0, 8));
        FAPI_TRY(l_address_16.clearBit(0, 16));
        FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16));
        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                      io_ccs_inst_cnt,
                                      l_address_16,
                                      l_bank_3,
                                      l_activate_1,
                                      l_rasn_1,
                                      l_casn_1,
                                      l_wen_1,
                                      l_cke_4,
                                      l_csn_8,
                                      l_odt_4,
                                      l_ddr_cal_type_4,
                                      i_port_number));

        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                      io_ccs_inst_cnt,
                                      l_num_idles_16,
                                      l_num_repeat_16,
                                      l_data_20,
                                      l_read_compare_1,
                                      l_rank_cal_4,
                                      l_ddr_cal_enable_1,
                                      l_ccs_end_1));

        io_ccs_inst_cnt ++;

        FAPI_TRY(l_csn_8.setBit(0, 8));
        FAPI_TRY(l_csn_8.clearBit(i_rank));

        // MRS CMD to CMD spacing = 12 cycles
        FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 12, 0, 16));
        FAPI_INF( "Editing RTT_NOM during wr_lvl for %s PORT: %d RP: %d", mss::c_str(i_target), i_port_number,
                  i_rank_pair_group);

        //MRS1
        // Get contents of MRS 1 Shadow Reg
        FAPI_TRY(fapi2::getScom(i_target, MR1_ADDRESS[i_port_number][i_rank_pair_group], l_data_buffer_64));

        l_data_buffer_64.reverse();
        FAPI_TRY(l_mrs1_16.insert(uint64_t(l_data_buffer_64), 0, 16, 0));
        FAPI_TRY(l_mrs1_16.extract(l_MRS1, 0, 16));
        FAPI_INF( "CURRENT MRS 1: 0x%04X", l_MRS1);

        if (l_mrs1_16.isBitSet(0))
        {
            // DLL disabled
            l_dll_enable = 0xFF;
        }
        else if (l_mrs1_16.isBitClear(0))
        {
            // DLL enabled
            l_dll_enable = 0x00;
        }

        if ( (l_mrs1_16.isBitClear(1)) && (l_mrs1_16.isBitClear(5)) )
        {
            // out_drv_imp_ctrl set to 40 (Rzq/6)
            l_out_drv_imp_cntl = 0x00;
        }
        else if ( (l_mrs1_16.isBitSet(1)) && (l_mrs1_16.isBitClear(5)) )
        {
            // out_drv_imp_ctrl set to 34 (Rzq/7)
            l_out_drv_imp_cntl = 0x80;
        }

        if ( (l_mrs1_16.isBitClear(2)) && (l_mrs1_16.isBitClear(6)) && (l_mrs1_16.isBitClear(9)) )
        {
            // RTT_NOM set to disabled
            FAPI_INF( "DRAM_RTT_NOM orignally set to Disabled.");
            l_dram_rtt_nom = 0x00;

        }
        else if ( (l_mrs1_16.isBitClear(2)) && (l_mrs1_16.isBitClear(6)) && (l_mrs1_16.isBitSet(9)) )
        {
            // RTT_NOM set to 20
            FAPI_INF( "DRAM_RTT_NOM orignally set to 20 Ohm.");
            l_dram_rtt_nom = 0x20;
        }
        else if ( (l_mrs1_16.isBitSet(2)) && (l_mrs1_16.isBitClear(6)) && (l_mrs1_16.isBitSet(9)) )
        {
            // RTT_NOM set to 30
            FAPI_INF( "DRAM_RTT_NOM orignally set to 30 Ohm.");
            l_dram_rtt_nom = 0xA0;
        }
        else if ( (l_mrs1_16.isBitSet(2)) && (l_mrs1_16.isBitSet(6)) && (l_mrs1_16.isBitClear(9)) )
        {
            // RTT_NOM set to 40
            FAPI_INF( "DRAM_RTT_NOM orignally set to 40 Ohm.");
            l_dram_rtt_nom = 0xC0;
        }
        else if ( (l_mrs1_16.isBitSet(2)) && (l_mrs1_16.isBitSet(6)) && (l_mrs1_16.isBitClear(9)) )
        {
            // RTT_NOM set to 60
            FAPI_INF( "DRAM_RTT_NOM orignally set to 60 Ohm.");
            l_dram_rtt_nom = 0x80;
        }
        else if ( (l_mrs1_16.isBitClear(2)) && (l_mrs1_16.isBitSet(6)) && (l_mrs1_16.isBitClear(9)) )
        {
            // RTT_NOM set to 120
            FAPI_INF( "DRAM_RTT_NOM orignally set to 120 Ohm.");
            l_dram_rtt_nom = 0x40;
        }

        if ( (l_mrs1_16.isBitClear(3)) && (l_mrs1_16.isBitClear(4)) )
        {
            //AL DISABLED
            l_dram_al = 0x00;
        }
        else if ( (l_mrs1_16.isBitSet(3)) && (l_mrs1_16.isBitClear(4)) )
        {
            // AL = CL -1
            l_dram_al = 0x80;
        }
        else if ( (l_mrs1_16.isBitClear(3)) && (l_mrs1_16.isBitSet(4)) )
        {
            // AL = CL -2
            l_dram_al = 0x40;
        }

        if (l_mrs1_16.isBitClear(7))
        {
            // WR_LVL DISABLED
            l_wr_lvl = 0x00;
        }
        else if (l_mrs1_16.isBitSet(7))
        {
            // WR_LVL ENABLED
            l_wr_lvl = 0xFF;
        }

        if (l_mrs1_16.isBitClear(11))
        {
            //TDQS DISABLED
            l_tdqs_enable = 0x00;
        }
        else if (l_mrs1_16.isBitSet(11))
        {
            //TDQS ENABLED
            l_tdqs_enable = 0xFF;
        }

        if (l_mrs1_16.isBitSet(12))
        {
            //Output Buffer Disabled
            l_q_off = 0xFF;
        }
        else if (l_mrs1_16.isBitClear(12))
        {
            //Output Buffer Enabled
            l_q_off = 0x00;
        }

        // Get contents of MRS 2 Shadow Reg
        FAPI_TRY(fapi2::getScom(i_target, MR2_ADDRESS[i_port_number][i_rank_pair_group], l_data_buffer_64));

        l_data_buffer_64.reverse();
        FAPI_TRY(l_mrs2_16.insert(uint64_t(l_data_buffer_64), 0, 16, 0));
        FAPI_TRY(l_mrs2_16.extract(l_MRS2, 0, 16));
        FAPI_INF( "MRS 2: 0x%04X", l_MRS2);

        if ( (l_mrs2_16.isBitClear(9)) && (l_mrs2_16.isBitClear(10)) )
        {
            //RTT WR DISABLE
            FAPI_INF( "DRAM_RTT_WR currently set to Disable.");
            l_dram_rtt_wr = 0x00;

            //RTT NOM CODE FOR THIS VALUE IS
            // dram_rtt_nom = 0x00
        }
        else if ( (l_mrs2_16.isBitSet(9)) && (l_mrs2_16.isBitClear(10)) )
        {
            //RTT WR 60 OHM
            FAPI_INF( "DRAM_RTT_WR currently set to 60 Ohm.");
            l_dram_rtt_wr = 0x80;

            //RTT NOM CODE FOR THIS VALUE IS
            // dram_rtt_nom = 0x80
        }
        else if ( (l_mrs2_16.isBitClear(9)) && (l_mrs2_16.isBitSet(10)) )
        {
            //RTT WR 120 OHM
            FAPI_INF( "DRAM_RTT_WR currently set to 120 Ohm.");
            l_dram_rtt_wr = 0x40;

            //RTT NOM CODE FOR THIS VALUE IS
            // dram_rtt_nom = 0x40
        }

        // If you have a 0 value in dram_rtt_nom_orignal
        // you will use dram_rtt_nom_original to save the original value
        if (io_dram_rtt_nom_original  == 0xFF)
        {
            io_dram_rtt_nom_original = l_dram_rtt_nom;
            l_dram_rtt_nom = l_dram_rtt_wr;

            if (l_dram_rtt_wr == 0x00)
            {
                FAPI_INF( "DRAM_RTT_NOM to be set to DRAM_RTT_WR which is Disable.");
            }
            else if (l_dram_rtt_wr == 0x80)
            {
                FAPI_INF( "DRAM_RTT_NOM to be set to DRAM_RTT_WR which is 60 Ohm.");
            }
            else if (l_dram_rtt_wr == 0x40)
            {
                FAPI_INF( "DRAM_RTT_NOM to be set to DRAM_RTT_WR which is 120 Ohm.");
            }
        }
        else if (io_dram_rtt_nom_original != 0xFF)
        {
            l_dram_rtt_nom = io_dram_rtt_nom_original;

            if ( l_dram_rtt_nom == 0x00 )
            {
                // RTT_NOM set to disabled
                FAPI_INF( "DRAM_RTT_NOM being set back to Disabled.");
            }
            else if ( l_dram_rtt_nom == 0x20 )
            {
                // RTT_NOM set to 20
                FAPI_INF( "DRAM_RTT_NOM being set back to 20 Ohm.");
            }
            else if ( l_dram_rtt_nom == 0xA0 )
            {
                // RTT_NOM set to 30
                FAPI_INF( "DRAM_RTT_NOM being set back to 30 Ohm.");
            }
            else if ( l_dram_rtt_nom == 0xC0 )
            {
                // RTT_NOM set to 40
                FAPI_INF( "DRAM_RTT_NOM being set back to 40 Ohm.");
            }
            else if ( l_dram_rtt_nom == 0x80 )
            {
                // RTT_NOM set to 60
                FAPI_INF( "DRAM_RTT_NOM being set back to 60 Ohm.");
            }
            else if ( l_dram_rtt_nom == 0x40 )
            {
                // RTT_NOM set to 120
                FAPI_INF( "DRAM_RTT_NOM being set back to 120 Ohm.");
            }
            else
            {
                FAPI_INF( "Proposed DRAM_RTT_NOM value is a non-supported.  Using Disabled.");
                l_dram_rtt_nom = 0x00;
            }
        }

        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_dll_enable, 0, 1, 0));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_out_drv_imp_cntl, 1, 1, 0));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_dram_rtt_nom, 2, 1, 0));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_dram_al, 3, 2, 0));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_out_drv_imp_cntl, 5, 1, 1));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_dram_rtt_nom, 6, 1, 1));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_wr_lvl, 7, 1, 0));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) 0x00, 8, 1));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_dram_rtt_nom, 9, 1, 2));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) 0x00, 10, 1));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_tdqs_enable, 11, 1, 0));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) l_q_off, 12, 1, 0));
        FAPI_TRY(l_mrs1_16.insert((uint8_t) 0x00, 13, 3));

        FAPI_TRY(l_mrs1_16.extract(l_MRS1, 0, 16));
        FAPI_INF( "NEW MRS 1: 0x%04X", l_MRS1);

        // Copying the current MRS into address buffer matching the MRS_array order
        // Setting the bank address

        FAPI_TRY(l_address_16.insert(l_mrs1_16, 0, 16, 0));
        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7));
        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6));
        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5));

        if ( ( l_address_mirror_map[i_port_number][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
        {
            //dimm and rank are only for print trace only, functionally not needed
            FAPI_TRY(mss_address_mirror_swizzle(i_target, l_address_16, l_bank_3), "mss_address_mirror_swizzle failed on %s",
                     mss::c_str(i_target));
        }

        FAPI_TRY(l_ccs_end_1.setBit(0));

        // Send out to the CCS array
        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                      io_ccs_inst_cnt,
                                      l_address_16,
                                      l_bank_3,
                                      l_activate_1,
                                      l_rasn_1,
                                      l_casn_1,
                                      l_wen_1,
                                      l_cke_4,
                                      l_csn_8,
                                      l_odt_4,
                                      l_ddr_cal_type_4,
                                      i_port_number));

        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                      io_ccs_inst_cnt,
                                      l_num_idles_16,
                                      l_num_repeat_16,
                                      l_data_20,
                                      l_read_compare_1,
                                      l_rank_cal_4,
                                      l_ddr_cal_enable_1,
                                      l_ccs_end_1));

        FAPI_TRY(mss_execute_ccs_inst_array( i_target, NUM_POLL, 60));
        //Error handling for mss_ccs_inst built into mss_funcs
        io_ccs_inst_cnt = 0;
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Set bad bit mask
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_set_bbm_regs (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba_target)
    {
        const uint16_t l_wrclk_disable_mask[] =       // by quads
        {
            0x8800, 0x4400, 0x2280, 0x1140
        };

        // 0x8000007d0301143f    from disable0 register
        const uint64_t l_disable1_addr_offset = 0x0000000100000000ull;
        // 0x800000050301143f    from disable1 register
        const uint64_t l_wrclk_en_addr_mask   = 0xFFFFFF07FFFFFFFFull;

        uint64_t l_addr = 0;
        uint16_t l_data = 0;
        uint16_t l_data_rank0 = 0;
        uint16_t l_data_rank1 = 0;
        uint16_t l_data_rank2 = 0;
        uint16_t l_data_rank3 = 0;
        uint16_t l_data_rank4 = 0;
        uint16_t l_data_rank5 = 0;
        uint16_t l_data_rank6 = 0;
        uint16_t l_data_rank7 = 0;
        uint8_t l_dimm = 0;
        uint8_t l_rank = 0;
        uint16_t l_mask = 0xF000;
        uint8_t l_all_F_mask = 0;
        uint16_t l_nmask = 0;
        uint16_t l_wrclk_nmask = 0;

        const uint8_t l_rg_invalid[] =
        {
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0_INVALID,
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1_INVALID,
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2_INVALID,
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3_INVALID,
        };

        uint8_t l_dram_width = 0;
        fapi2::buffer<uint64_t> l_data_buffer;
        fapi2::variable_buffer l_db_reg(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank0(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank1(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank2(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank3(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank4(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank5(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank6(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_rank7(LANES_PER_PORT);
        fapi2::buffer<uint64_t> l_put_mask;
        uint8_t l_prg[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {0};      // primary rank group values
        uint8_t l_is_clean = 1;
        uint8_t l_rank0_invalid = 1; //0 = valid, 1 = invalid
        uint8_t l_rank1_invalid = 1;
        uint8_t l_rank2_invalid = 1;
        uint8_t l_rank3_invalid = 1;
        uint8_t l_rank4_invalid = 1;
        uint8_t l_rank5_invalid = 1;
        uint8_t l_rank6_invalid = 1;
        uint8_t l_rank7_invalid = 1;
        uint8_t l_port = 0;
        FAPI_INF("%s Running flash->registers(set)", mss::c_str(i_mba_target));
        uint8_t l_prank = 0;
        uint8_t l_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_ranks_per_port[MAX_PORTS_PER_MBA] = {0};
        // This vector contains a row repair entry for each DIMM rank
        std::vector<fapi2::buffer<uint32_t>> l_repairs_per_dimm;
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_mba_dimms;
        l_mba_dimms = i_mba_target.getChildren<fapi2::TARGET_TYPE_DIMM>();

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_mba_target, l_prg[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_mba_target, l_prg[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_mba_target, l_prg[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_mba_target, l_prg[3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_mba_target, l_dram_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_mba_target, l_ranks_per_dimm));

        //DECONFIG and FFDC INFO
        FAPI_ASSERT(l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4
                    || l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8,
                    fapi2::CEN_MSS_DRAMINIT_TRAINING_DRAM_WIDTH_INPUT_ERROR_SETBBM().
                    set_TARGET_MBA_ERROR(i_mba_target).
                    set_WIDTH(l_dram_width),
                    "ATTR_EFF_DRAM_WIDTH is invalid %u",
                    l_dram_width);

        l_data_buffer.flush<0>();

        // Calculate the number of ranks on each port
        count_ranks_per_port(l_ranks_per_dimm, l_ranks_per_port);

        for (l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port ++ )  // [0:1]
        {
            l_db_reg_rank0.flush<0>();
            l_db_reg_rank1.flush<0>();
            l_db_reg_rank2.flush<0>();
            l_db_reg_rank3.flush<0>();
            l_db_reg_rank4.flush<0>();
            l_db_reg_rank5.flush<0>();
            l_db_reg_rank6.flush<0>();
            l_db_reg_rank7.flush<0>();

            // Gather all ranks first
            // loop through primary ranks [0:3]
            for (l_prank = 0; l_prank < NUM_RANK_GROUPS; l_prank ++ )
            {
                l_is_clean = 1;

                if (l_prg[l_prank][l_port] == l_rg_invalid[l_prank])  // invalid rank
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    continue;
                }

                if ( l_prg[l_prank][l_port] == 0)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 0, 0, l_db_reg_rank0, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 0, 0);
                    l_rank0_invalid = 0;
                }

                if ( l_prg[l_prank][l_port] == 1)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 0, 1, l_db_reg_rank1, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 0, 1);
                    l_rank1_invalid = 0;
                }

                if ( l_prg[l_prank][l_port] == 2)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 0, 2, l_db_reg_rank2, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 0, 2);
                    l_rank2_invalid = 0;
                }

                if ( l_prg[l_prank][l_port] == 3)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 0, 3, l_db_reg_rank3, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 0, 3);
                    l_rank3_invalid = 0;
                }

                if ( l_prg[l_prank][l_port] == 4)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 1, 0, l_db_reg_rank4, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 1, 0);
                    l_rank4_invalid = 0;
                }

                if ( l_prg[l_prank][l_port] == 5)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 1, 1, l_db_reg_rank5, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 1, 1);;
                    l_rank5_invalid = 0;
                }

                if ( l_prg[l_prank][l_port] == 6)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 1, 2, l_db_reg_rank6, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 1, 2);;
                    l_rank6_invalid = 0;
                }

                if ( l_prg[l_prank][l_port] == 7)
                {
                    FAPI_DBG("%s BYTE DISABLE WORKAROUND  Primary rank group (prank) %i port %d rank value: %d Not INVALID, Marking and continuing...",
                             mss::c_str(i_mba_target), l_prank, l_port, l_prg[l_prank][l_port]);
                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, 1, 3, l_db_reg_rank7, l_is_clean),
                             "Error from getting register bitmap port=%i: "
                             "dimm=%i, rank=%i", l_port, 1, 3);;
                    l_rank7_invalid = 0;
                }
            }

            // loop through primary ranks [0:3]
            for (l_prank = 0; l_prank < NUM_RANK_GROUPS; l_prank ++ )
            {
                l_dimm = l_prg[l_prank][l_port] >> 2;
                l_rank = l_prg[l_prank][l_port] & 0x03;
                l_is_clean = 1;

                if (l_prg[l_prank][l_port] == l_rg_invalid[l_prank])  // invalid rank
                {
                    FAPI_DBG("%s Primary rank group %i: INVALID, continuing...",
                             mss::c_str(i_mba_target), l_prank);
                    continue;
                }

                FAPI_TRY(getC4dq2reg(i_mba_target, l_port, l_dimm, l_rank, l_db_reg, l_is_clean),
                         "Error from getting register bitmap port=%i: "
                         "dimm=%i, rank=%i", l_port, l_dimm, l_rank);

                // quick test to move on to next rank if no bits need to be set
                if (l_is_clean == 1)          // Note ignores spares that match attribute
                {
                    FAPI_INF("Primary rank group %i: No bad bits found for "
                             "p%i:d%i:r%i:cs%i", l_prank, l_port, l_dimm, l_rank,
                             l_prg[l_prank][l_port]);
                    continue;
                }

                // 1-rank workaround: Read row repair attribute and build table
                if (l_ranks_per_port[l_port] == 1)
                {
                    uint8_t l_row_repair_data[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK] = {0};

                    // Get DIMM target from port/index
                    fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm_target;
                    FAPI_TRY(find_dimm_from_index(i_mba_target, l_port, l_dimm, l_dimm_target));

                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROW_REPAIR_DATA, l_dimm_target, l_row_repair_data));

                    FAPI_TRY(build_row_repair_table(l_dimm_target, l_dram_width, l_row_repair_data, l_repairs_per_dimm));
                }

                for ( uint8_t i = 0; i < DP18_INSTANCES; ++i ) // dp18 [0:4]
                {
                    uint8_t l_disable1_data = 0;
                    uint16_t l_wrclk_mask = 0;

                    // check or not to check(always set register)?
                    FAPI_TRY(l_db_reg.extract(l_data, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank0.extract(l_data_rank0, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank1.extract(l_data_rank1, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank2.extract(l_data_rank2, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank3.extract(l_data_rank3, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank4.extract(l_data_rank4, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank5.extract(l_data_rank5, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank6.extract(l_data_rank6, i * 16, 16));
                    FAPI_TRY(l_db_reg_rank7.extract(l_data_rank7, i * 16, 16));
                    FAPI_INF("%s port%u rank0 DP%u l_data_rank0:0x%04x data:0x%04x", mss::c_str(i_mba_target), l_port, i, l_data_rank0,
                             l_data);

                    if (l_data == 0)
                    {
                        FAPI_DBG("\tDP18_%i has no bad bits set, continuing...", i);
                        continue;
                    }

                    // clear bits 48:63
                    l_data_buffer.flush<0>();

                    for (uint8_t n = 0; n < MAX_NIBBLES_PER_BLOCK; n++) // check each nibble
                    {
                        l_nmask = l_mask >> (4 * n);

                        if ((l_nmask & l_data) == l_nmask)
                        {
                            FAPI_DBG("BYTE DISABLE WORKAROUND  Found a 0XF on nibble=%i Port%i, dimm=%i, prg%i rank=%i data=0x%04X", n, l_port,
                                     l_dimm,
                                     l_prank, l_rank, l_data);

                            // Check if nibble is marked bad on all valid ranks
                            if ( ( ((l_nmask & l_data_rank0) == l_nmask) || (l_rank0_invalid) ) &&
                                 ( ((l_nmask & l_data_rank1) == l_nmask) || (l_rank1_invalid) ) &&
                                 ( ((l_nmask & l_data_rank2) == l_nmask) || (l_rank2_invalid) ) &&
                                 ( ((l_nmask & l_data_rank3) == l_nmask) || (l_rank3_invalid) ) &&
                                 ( ((l_nmask & l_data_rank4) == l_nmask) || (l_rank4_invalid) ) &&
                                 ( ((l_nmask & l_data_rank5) == l_nmask) || (l_rank5_invalid) ) &&
                                 ( ((l_nmask & l_data_rank6) == l_nmask) || (l_rank6_invalid) ) &&
                                 ( ((l_nmask & l_data_rank7) == l_nmask) || (l_rank7_invalid) )   )
                            {
                                // 1-rank workaround: if there's a row repair requested on this DRAM, don't disable it so we can try training it
                                bool l_workaround_needed = false;

                                if (l_ranks_per_port[l_port] == 1)
                                {
                                    FAPI_TRY(row_repair_workaround_check(i_mba_target, l_port, l_rank, i, n * BITS_PER_NIBBLE,
                                                                         l_dram_width, l_repairs_per_dimm, l_workaround_needed));

                                    if (l_workaround_needed)
                                    {
                                        FAPI_INF("%s Port %d Rank %d DP%d Nibble %d is marked bad, but has a row repair request. Will not disable this nibble",
                                                 mss::c_str(i_mba_target), l_port, l_rank, i, n * BITS_PER_NIBBLE);
                                        l_data = l_data & ~(l_nmask);
                                    }
                                }

                                if (!l_workaround_needed)
                                {
                                    //Leave it an F.
                                    FAPI_DBG("BYTE DISABLE WORKAROUND  All ranks are a F so writing an 0xF to disable regs.");
                                    FAPI_DBG("BYTE DISABLE WORKAROUND  data rank 0 =0x%04X rank 1 =0x%04X rank 2 =0x%04X rank 3 =0x%04X rank 4 =0x%04X rank 5 =0x%04X rank 6 =0x%04X rank 7 =0x%04X",
                                             l_data_rank0, l_data_rank1, l_data_rank2, l_data_rank3, l_data_rank4, l_data_rank5, l_data_rank6, l_data_rank7 );
                                    l_all_F_mask = 1;
                                }
                            }
                            else
                            {
                                //Replacing F nibble with E nibble
                                FAPI_DBG("BYTE DISABLE WORKAROUND  Single rank is a 0xF so writing an 0x0 to disable regs. PRE DATA: 0x%04X", l_data);
                                l_data = l_data & ~(l_nmask);
                                FAPI_DBG("BYTE DISABLE WORKAROUND  POST DATA: 0x%04X", l_data);
                            }
                        }

                        l_wrclk_nmask = 0xF000 >> (4 * n);

                        if (l_dram_width != fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4) // x8 only disable the wrclk
                        {

                            if (((l_wrclk_nmask & l_data) >> (4 * (3 - n))) == 0x0F)
                            {
                                l_wrclk_mask |= l_wrclk_disable_mask[n];
                            }
                        }

                    }//nibble

                    if (l_all_F_mask == 1)
                    {
                        FAPI_INF("Entering into all F across all ranks case. Need to Disable WRCLK Enable as well.");

                        for (uint8_t n = 0; n < 4; n++) // check each nibble
                        {
                            uint16_t l_nmask = 0xF000 >> (4 * n);

                            if (l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
                            {
                                if ((l_nmask & l_data) == l_nmask)      // bad bit(s) in nibble
                                {
                                    // For Marc Gollub, since repair for x4 DRAM is in nibble
                                    // granularity.  Also due to higher chance of hitting dq0 of
                                    // Micron causing write leveling to fail for entire x4 DRAM.
                                    // Will also save a re-training loop.  Complement in get_bbm_regs.


                                    FAPI_TRY(mss_get_dqs_lane(i_mba_target, l_port, i, n,
                                                              l_disable1_data));

                                    l_wrclk_mask |= l_wrclk_disable_mask[n];
                                    FAPI_INF("%s port%d Disabling entire nibble %i - mask 0x%04x", mss::c_str(i_mba_target), l_port,  n, l_wrclk_mask);
                                }
                            }  // end x4
                            else    // width == 8+?
                            {
                                if ((n % 2) == 0)
                                {
                                    l_nmask = 0xFF00 >> (4 * n);

                                    if ((l_nmask & l_data) == l_nmask)  // entire byte bad
                                    {
                                        l_disable1_data |= (0xF0 >> (n * 2));
                                    }
                                }

                                if (((l_nmask & l_data) >> (4 * (3 - n))) == 0x0F)
                                {
                                    l_wrclk_mask |= l_wrclk_disable_mask[n];
                                }
                            }
                        }
                    }

                    FAPI_INF("%s port%u DP%u disable1_data=0x%04X", mss::c_str(i_mba_target), l_port, i, l_disable1_data);

                    // set disable0(dq) reg
                    FAPI_TRY(l_data_buffer.insert(l_data, 3 * 16, 16, 0));
                    l_addr = l_disable_reg[l_port][l_prank][i];

                    FAPI_INF("+++ Setting Disable0 Bad Bit Mask p%i: DIMM%i PRG%i "
                             "Rank%i dp18_%i addr=0x%llx, data=0x%04X", l_port,
                             l_dimm, l_prank, l_prg[l_prank][l_port], i, l_addr , l_data);

                    FAPI_TRY(fapi2::putScomUnderMask(i_mba_target, l_addr, l_data_buffer,
                                                     l_data_buffer));

                    if (l_all_F_mask == 1)
                    {
                        FAPI_INF("Entering into all F across ranks case. Need to Disable DQS as well.");
                        // set address for disable1(dqs) register
                        l_addr += l_disable1_addr_offset;

                        if (l_disable1_data != 0)
                        {
                            l_data_buffer.flush<0>();  // clear buffer

                            FAPI_TRY(l_data_buffer.insert(l_disable1_data, 6 * 8, 8, 0));
                            // write disable1(dqs) register
                            FAPI_TRY(fapi2::putScomUnderMask(i_mba_target, l_addr,
                                                             l_data_buffer, l_data_buffer));
                        } // end disable1_data != 0


                        // set address for wrclk_en register
                        l_addr &= l_wrclk_en_addr_mask;

                        if (l_wrclk_mask != 0)
                        {
                            l_data_buffer.flush<0>(); // clear buffer
                            FAPI_TRY(l_put_mask.insert(l_wrclk_mask, 3 * 16, 16, 0));

                            // does disabling read clocks for unused bytes cause problems?
                            // SW25701 Workaround - x4s will not mask out RDCLKs on Bad Bits to avoid translation issues
                        } // end wrclk_mask != 0
                    }//if mask
                } // end DP18 instance loop
            } // end primary rank loop
        } // end port loop

    fapi_try_exit:
        return fapi2::current_err;
    } // end mss_set_bbm_regs

    ///
    /// @brief Get DQS lane from port-block-quad
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_block
    /// @param[in] i_quad
    /// @param[out] o_lane OR'd in lane of the dqs for the specified input
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_get_dqs_lane (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                        const uint8_t i_port, const uint8_t i_block, const uint8_t i_quad,
                                        uint8_t& o_lane)
    {
        uint8_t l_dq = 0;
        uint8_t l_dqs = 0;
        uint8_t l_phy_lane = i_quad * 4;
        uint8_t l_block = i_block;
        // returns dq
        FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq, 1, l_phy_lane, l_block, 1));

        FAPI_INF("DQ returning mss_c4_phy inputs port: %d input index: %d phy_lane: %d block: %d", i_port, l_dq, l_phy_lane,
                 l_block);

        l_dqs = l_dq / 4;
        // returns phy_lane
        FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, WR_DQS, l_dqs, 1, l_phy_lane, l_block, 0));

        FAPI_INF("phy_lane returning mss_c4_phy inputs port: %d input index: %d phy_lane: %d block: %d", i_port, l_dqs,
                 l_phy_lane,
                 l_block);

        if (l_block != i_block)
        {
            FAPI_ERR("\t !!!  blocks don't match from c4 to phy i_block=%i,"
                     " o_block=%i", i_block, l_block);
        }

        switch (l_phy_lane)
        {
            case 16:
            case 17:
                o_lane |= 0xC0;
                break;

            case 18:
            case 19:
                o_lane |= 0x30;
                break;

            case 20:
            case 21:
                o_lane |= 0x0C;
                break;

            case 22:
            case 23:
                o_lane |= 0x03;
                break;

            default:
                //DECONFIG and FFDC INFO
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_DRAMINIT_TRAINING_C4_PHY_TRANSLATION_ERROR().
                            set_TARGET_MBA_ERROR(i_mba).
                            set_PORT(i_port).
                            set_BLOCK(i_block).
                            set_QUAD(i_quad).
                            set_PHYLANE(l_phy_lane),
                            "\t!!!  (Port%i, dp18_%i, q=%i)  phy_lane(%i)"
                            "returned from mss_c4_phy is invalid",
                            i_port, i_block, i_quad, l_phy_lane);
        }

    fapi_try_exit:
        return fapi2::current_err;
    } //end mss_get_dqs_lane

    ///
    /// @brief Get bad bit mask
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_training_success  Training passed flag
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_get_bbm_regs (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba_target,
                                        const uint8_t i_training_success)
    {
        const uint8_t l_rg_invalid[] =
        {
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0_INVALID,
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1_INVALID,
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2_INVALID,
            fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3_INVALID,
        };

        fapi2::buffer<uint64_t> l_data_buffer;
        fapi2::variable_buffer l_db_reg(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_vpd(LANES_PER_PORT);
        uint8_t l_prg[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {0};      // primary rank group values
        uint8_t l_dram_width = 0;
        uint8_t l_dimm = 0;
        uint8_t l_rank = 0;
        uint8_t l_rank0_invalid = 1; //0 = valid, 1 = invalid
        uint8_t l_rank1_invalid = 1;
        uint8_t l_rank2_invalid = 1;
        uint8_t l_rank3_invalid = 1;
        uint8_t l_rank4_invalid = 1;
        uint8_t l_rank5_invalid = 1;
        uint8_t l_rank6_invalid = 1;
        uint8_t l_rank7_invalid = 1;
        uint16_t l_data = 0;
        uint16_t l_data_rank0 = 0;
        uint16_t l_data_rank1 = 0;
        uint16_t l_data_rank2 = 0;
        uint16_t l_data_rank3 = 0;
        uint16_t l_data_rank4 = 0;
        uint16_t l_data_rank5 = 0;
        uint16_t l_data_rank6 = 0;
        uint16_t l_data_rank7 = 0;
        uint16_t l_data_curr_vpd = 0;
        uint16_t l_mask = 0xF000;
        uint16_t l_nmask = 0;
        uint8_t l_is_clean = 1;
        uint8_t l_port = 0;
        uint8_t l_prank = 0;
        uint8_t l_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_ranks_per_port[MAX_PORTS_PER_MBA] = {0};
        //Storing all the errors across rank/eff dimm
        fapi2::variable_buffer l_db_reg_dimm0_rank0(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_dimm0_rank1(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_dimm0_rank2(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_dimm0_rank3(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_dimm1_rank0(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_dimm1_rank1(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_dimm1_rank2(LANES_PER_PORT);
        fapi2::variable_buffer l_db_reg_dimm1_rank3(LANES_PER_PORT);
        // This vector contains a row repair entry for each DIMM rank
        std::vector<fapi2::buffer<uint32_t>> l_repairs_per_dimm;

        FAPI_INF("%s Running (get)registers->flash", mss::c_str(i_mba_target));

        const auto l_mba_dimms = i_mba_target.getChildren<fapi2::TARGET_TYPE_DIMM>();

        // 4 dimms per MBA, 2 per port
        // ATTR_EFF_PRIMARY_RANK_GROUP0[port], GROUP1[port],
        //                       GROUP2[port], GROUP3[port]
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_mba_target, l_prg[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_mba_target, l_prg[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_mba_target, l_prg[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_mba_target, l_prg[3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_mba_target, l_dram_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_mba_target, l_ranks_per_dimm));

        FAPI_ASSERT(l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4
                    || l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8,
                    fapi2::CEN_MSS_DRAMINIT_TRAINING_DRAM_WIDTH_INPUT_ERROR_GETBBM().
                    set_TARGET_MBA_ERROR(i_mba_target).
                    set_WIDTH(l_dram_width),
                    "ATTR_EFF_DRAM_WIDTH is invalid %u", l_dram_width);

        l_data_buffer.flush<0>();

        // Calculate the number of ranks on each port
        count_ranks_per_port(l_ranks_per_dimm, l_ranks_per_port);

        for (l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port ++ )  // [0:1]
        {
            // Initialize all the stored errors to 0.
            l_db_reg_dimm0_rank0.flush<0>();
            l_db_reg_dimm0_rank1.flush<0>();
            l_db_reg_dimm0_rank2.flush<0>();
            l_db_reg_dimm0_rank3.flush<0>();
            l_db_reg_dimm1_rank0.flush<0>();
            l_db_reg_dimm1_rank1.flush<0>();
            l_db_reg_dimm1_rank2.flush<0>();
            l_db_reg_dimm1_rank3.flush<0>();
            l_rank0_invalid = 1; //0 = valid, 1 = invalid
            l_rank1_invalid = 1;
            l_rank2_invalid = 1;
            l_rank3_invalid = 1;
            l_rank4_invalid = 1;
            l_rank5_invalid = 1;
            l_rank6_invalid = 1;
            l_rank7_invalid = 1;


            // loop through primary ranks [0:3]
            for (l_prank = 0; l_prank < NUM_RANK_GROUPS; l_prank ++ )
            {
                l_dimm = l_prg[l_prank][l_port] >> 2;
                l_rank = l_prg[l_prank][l_port] & 0x03;

                if (l_prg[l_prank][l_port] == l_rg_invalid[l_prank])  // invalid rank
                {
                    FAPI_DBG("%s Primary rank group %i is INVALID, continuing...", mss::c_str(i_mba_target),
                             l_prank);

                    if ( l_prg[l_prank][l_port] == 0)
                    {
                        l_db_reg_dimm0_rank0.flush<1>();
                    }

                    if ( l_prg[l_prank][l_port] == 1)
                    {
                        l_db_reg_dimm0_rank1.flush<1>();
                    }

                    if ( l_prg[l_prank][l_port] == 2)
                    {
                        l_db_reg_dimm0_rank2.flush<1>();
                    }

                    if ( l_prg[l_prank][l_port] == 3)
                    {
                        l_db_reg_dimm0_rank3.flush<1>();
                    }

                    if ( l_prg[l_prank][l_port] == 4)
                    {
                        l_db_reg_dimm1_rank0.flush<1>();
                    }

                    if ( l_prg[l_prank][l_port] == 5)
                    {
                        l_db_reg_dimm1_rank1.flush<1>();
                    }

                    if ( l_prg[l_prank][l_port] == 6)
                    {
                        l_db_reg_dimm1_rank2.flush<1>();
                    }

                    if ( l_prg[l_prank][l_port] == 7)
                    {
                        l_db_reg_dimm1_rank3.flush<1>();
                    }

                    continue;
                }

                // create the db_reg (all the failed bits of the port)
                l_db_reg.flush<0>();

                FAPI_DBG("%s Port%i, dimm=%i, prg%i rank=%i", mss::c_str(i_mba_target), l_port, l_dimm, l_prank, l_rank);

                for ( uint8_t i = 0; i < DP18_INSTANCES; ++i ) // dp18 [0:4]
                {
                    // clear bits 48:63
                    FAPI_TRY(l_data_buffer.clearBit(48, LANES_PER_BLOCK));

                    FAPI_TRY(fapi2::getScom(i_mba_target, l_disable_reg[l_port][l_prank][i],
                                            l_data_buffer));

                    FAPI_TRY(l_data_buffer.extract(l_data, 3 * 16, 16));
                    FAPI_DBG("%s dp18_%i  0x%llx = 0x%x", mss::c_str(i_mba_target), i,
                             l_disable_reg[l_port][l_prank][i], l_data);

                    if (l_data != 0)
                    {
                        FAPI_TRY(l_db_reg.insert(l_data, i * 16, 16, 0));
                        FAPI_INF("+++ %s Setting Bad Bit Mask p%i: DIMM%i PRG%i "
                                 "Rank%i \tdp18_%i addr=0x%llx, data=0x%04X", mss::c_str(i_mba_target), l_port,
                                 l_dimm, l_prank, l_prg[l_prank][l_port], i,
                                 l_disable_reg[l_port][l_prank][i], l_data);
                    }
                } // end DP18 instance loop

                if (l_prg[l_prank][l_port] == l_rg_invalid[l_prank])  // invalid rank
                {
                    FAPI_DBG("%s Primary rank group %i: INVALID, continuing...", mss::c_str(i_mba_target),
                             l_prank);
                    continue;
                }

                if (l_dimm == 0)
                {
                    if (l_rank == 0)
                    {
                        l_db_reg_dimm0_rank0 = l_db_reg;
                        l_rank0_invalid = 0; //0 = valid, 1 = invalid
                    }
                    else if (l_rank == 1)
                    {
                        l_db_reg_dimm0_rank1 = l_db_reg;
                        l_rank1_invalid = 0; //0 = valid, 1 = invalid
                    }
                    else if (l_rank == 2)
                    {
                        l_db_reg_dimm0_rank2 = l_db_reg;
                        l_rank2_invalid = 0; //0 = valid, 1 = invalid
                    }
                    else if (l_rank == 3)
                    {
                        l_db_reg_dimm0_rank3 = l_db_reg;
                        l_rank3_invalid = 0; //0 = valid, 1 = invalid
                    }
                }
                else if (l_dimm == 1)
                {
                    if (l_rank == 0)
                    {
                        l_db_reg_dimm1_rank0 = l_db_reg;
                        l_rank4_invalid = 0; //0 = valid, 1 = invalid
                    }
                    else if (l_rank == 1)
                    {
                        l_db_reg_dimm1_rank1 = l_db_reg;
                        l_rank5_invalid = 0; //0 = valid, 1 = invalid
                    }
                    else if (l_rank == 2)
                    {
                        l_db_reg_dimm1_rank2 = l_db_reg;
                        l_rank6_invalid = 0; //0 = valid, 1 = invalid
                    }
                    else if (l_rank == 3)
                    {
                        l_db_reg_dimm1_rank3 = l_db_reg;
                        l_rank7_invalid = 0; //0 = valid, 1 = invalid
                    }
                }
            } // end primary rank loop

            // loop through primary ranks [0:3]
            for (uint8_t l_prank = 0; l_prank < NUM_RANK_GROUPS; l_prank ++ )
            {
                l_dimm = l_prg[l_prank][l_port] >> 2;
                l_rank = l_prg[l_prank][l_port] & 0x03;

                if (l_prg[l_prank][l_port] == l_rg_invalid[l_prank])  // invalid rank
                {
                    FAPI_DBG("%s Primary rank group %i is INVALID, continuing...", mss::c_str(i_mba_target),
                             l_prank);
                    continue;
                }

                FAPI_DBG("%s Port%i, dimm=%i, prg%i rank=%i", mss::c_str(i_mba_target), l_port, l_dimm, l_prank, l_rank);

                uint8_t l_row_repair_data[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK] = {0};
                // Get DIMM target from port/index
                fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm_target;
                FAPI_TRY(find_dimm_from_index(i_mba_target, l_port, l_dimm, l_dimm_target));

                // 1-rank workaround: Read row repair requests for this DIMM
                if (l_ranks_per_port[l_port] == 1)
                {
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROW_REPAIR_DATA, l_dimm_target, l_row_repair_data));

                    FAPI_TRY(build_row_repair_table(l_dimm_target, l_dram_width, l_row_repair_data, l_repairs_per_dimm));
                }

                for ( uint8_t i = 0; i < DP18_INSTANCES; ++i ) // dp18 [0:4]
                {
                    FAPI_TRY(l_db_reg_dimm0_rank0.extract(l_data_rank0, i * 16, 16));
                    FAPI_TRY(l_db_reg_dimm0_rank1.extract(l_data_rank1, i * 16, 16));
                    FAPI_TRY(l_db_reg_dimm0_rank2.extract(l_data_rank2, i * 16, 16));
                    FAPI_TRY(l_db_reg_dimm0_rank3.extract(l_data_rank3, i * 16, 16));
                    FAPI_TRY(l_db_reg_dimm1_rank0.extract(l_data_rank4, i * 16, 16));
                    FAPI_TRY(l_db_reg_dimm1_rank1.extract(l_data_rank5, i * 16, 16));
                    FAPI_TRY(l_db_reg_dimm1_rank2.extract(l_data_rank6, i * 16, 16));
                    FAPI_TRY(l_db_reg_dimm1_rank3.extract(l_data_rank7, i * 16, 16));

                    if (l_dimm == 0)
                    {
                        if (l_rank == 0)
                        {
                            l_data = l_data_rank0;
                        }
                        else if (l_rank == 1)
                        {
                            l_data = l_data_rank1;
                        }
                        else if (l_rank == 2)
                        {
                            l_data = l_data_rank2;
                        }
                        else if (l_rank == 3)
                        {
                            l_data = l_data_rank3;
                        }
                    }
                    else if (l_dimm == 1)
                    {
                        if (l_rank == 0)
                        {
                            l_data = l_data_rank4;
                        }
                        else if (l_rank == 1)
                        {
                            l_data = l_data_rank5;
                        }
                        else if (l_rank == 2)
                        {
                            l_data = l_data_rank6;
                        }
                        else if (l_rank == 3)
                        {
                            l_data = l_data_rank7;
                        }
                    }

                    FAPI_TRY(getC4dq2reg(i_mba_target, l_port, l_dimm, l_rank, l_db_reg_vpd, l_is_clean));
                    FAPI_TRY(l_db_reg_vpd.extract(l_data_curr_vpd, i * 16, 16));

                    for (uint8_t n = 0; n < MAX_NIBBLES_PER_BLOCK; n++) // check each nibble
                    {
                        l_nmask = l_mask >> (4 * n);

                        // Nibble marked bad in bad bits
                        if ((l_nmask & l_data_curr_vpd) == l_nmask)
                        {
                            FAPI_DBG("BYTE DISABLE WORKAROUND: %s Found a 0XF on nibble=%i Port%i, dimm=%i, prg%i rank=%i data= 0x%04X",
                                     mss::c_str(i_mba_target), n, l_port,
                                     l_dimm,
                                     l_prank, l_rank, l_data);
                            FAPI_DBG("BYTE DISABLE WORKAROUND: %s data rank 0 =0x%04X rank 1 =0x%04X rank 2 =0x%04X rank 3 =0x%04X rank 4 =0x%04X rank 5 =0x%04X rank 6 =0x%04X rank 7 =0x%04X",
                                     mss::c_str(i_mba_target), l_data_rank0, l_data_rank1, l_data_rank2, l_data_rank3, l_data_rank4, l_data_rank5,
                                     l_data_rank6, l_data_rank7 );

                            if (i_training_success)
                            {
                                //Leave it an F.
                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s Training was successful so writing an 0xF to VPD. PRE data: 0x%04X",
                                         mss::c_str(i_mba_target), l_data);
                                l_data = l_data | l_nmask;
                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s POST DATA: 0x%04X", mss::c_str(i_mba_target), l_data);
                            }
                            else
                            {
                                // Nibble marked bad in bad bits in all valid ranks
                                if ( ( ((l_nmask & l_data_rank0) == l_nmask) || (l_rank0_invalid) ) &&
                                     ( ((l_nmask & l_data_rank1) == l_nmask) || (l_rank1_invalid) ) &&
                                     ( ((l_nmask & l_data_rank2) == l_nmask) || (l_rank2_invalid) ) &&
                                     ( ((l_nmask & l_data_rank3) == l_nmask) || (l_rank3_invalid) ) &&
                                     ( ((l_nmask & l_data_rank4) == l_nmask) || (l_rank4_invalid) ) &&
                                     ( ((l_nmask & l_data_rank5) == l_nmask) || (l_rank5_invalid) ) &&
                                     ( ((l_nmask & l_data_rank6) == l_nmask) || (l_rank6_invalid) ) &&
                                     ( ((l_nmask & l_data_rank7) == l_nmask) || (l_rank7_invalid) )   )
                                {
                                    // 1-rank workaround: if training failed on DRAM with row repair request, then clear the request
                                    // and trigger a reconfig loop to re-run training
                                    bool l_workaround_needed = false;

                                    if (l_ranks_per_port[l_port] == 1)
                                    {
                                        FAPI_TRY(row_repair_workaround_check(i_mba_target, l_port, l_rank, i, n * BITS_PER_NIBBLE,
                                                                             l_dram_width, l_repairs_per_dimm, l_workaround_needed));

                                        if (l_workaround_needed)
                                        {
                                            FAPI_INF("%s Port %d Rank %d DP%d Nibble %d failed training, but has a row repair request. Clearing row repair request",
                                                     mss::c_str(i_mba_target), l_port, l_rank, i, n * BITS_PER_NIBBLE);
                                            FAPI_TRY(clear_row_repair_entry(l_rank, l_row_repair_data));
                                            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ROW_REPAIR_DATA, l_dimm_target, l_row_repair_data));

                                            FAPI_INF("%s Triggering a reconfig loop due to 1-rank row repair workaround...",
                                                     mss::c_str(i_mba_target));
                                            fapi2::ATTR_RECONFIGURE_LOOP_Type l_reconfigAttr = 0;
                                            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RECONFIGURE_LOOP,
                                                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_reconfigAttr));

                                            // This value makes it look like new bad bits were found during training.
                                            // It is how the PRD code triggers a reconfig when it sets new bad bits in the VPD.
                                            // 'OR' values in case of multiple reasons for reconfigure
                                            l_reconfigAttr |= fapi2::ENUM_ATTR_RECONFIGURE_LOOP_BAD_DQ_BIT_SET;
                                            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_RECONFIGURE_LOOP,
                                                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_reconfigAttr));
                                        }
                                    }

                                    if (!l_workaround_needed)
                                    {
                                        FAPI_DBG("BYTE DISABLE WORKAROUND: %s All ranks were F's and training was not successful.  Uncool.",
                                                 mss::c_str(i_mba_target));
                                    }

                                    continue;
                                }
                                else
                                {
                                    //Replacing E nibble with F nibble
                                    FAPI_DBG("BYTE DISABLE WORKAROUND: %s Training failed so writing an 0xF to VPD for all ranks.",
                                             mss::c_str(i_mba_target));
                                    l_data = l_data  | l_nmask;
                                    l_data_rank0 = l_data_rank0  | l_nmask;
                                    l_data_rank1 = l_data_rank1  | l_nmask;
                                    l_data_rank2 = l_data_rank2  | l_nmask;
                                    l_data_rank3 = l_data_rank3  | l_nmask;
                                    l_data_rank4 = l_data_rank4  | l_nmask;
                                    l_data_rank5 = l_data_rank5  | l_nmask;
                                    l_data_rank6 = l_data_rank6  | l_nmask;
                                    l_data_rank7 = l_data_rank7  | l_nmask;
                                }
                            }
                        }
                        else if ( ((l_nmask & l_data_curr_vpd) != l_nmask) && ((l_nmask & l_data_curr_vpd) > 0))
                        {
                            FAPI_DBG("BYTE DISABLE WORKAROUND: %s Found a non-zero, non-F nibble. Applying to all ranks.",
                                     mss::c_str(i_mba_target));

                            if (l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
                            {
                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s Its a x4 so turning it to a 0xF. PRE DATA: 0x%04X", mss::c_str(i_mba_target),
                                         l_data);
                                l_data = l_data  | l_nmask;
                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s POST DATA: 0x%04X", mss::c_str(i_mba_target), l_data);

                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s PRE data rank 0 =0x%04X rank 1 =0x%04X rank 2 =0x%04X rank 3 =0x%04X rank 4 =0x%04X rank 5 =0x%04X rank 6 =0x%04X rank 7 =0x%04X",
                                         mss::c_str(i_mba_target), l_data_rank0, l_data_rank1, l_data_rank2, l_data_rank3, l_data_rank4, l_data_rank5,
                                         l_data_rank6, l_data_rank7 );
                                l_data_rank0 = l_data_rank0  | l_nmask;
                                l_data_rank1 = l_data_rank1  | l_nmask;
                                l_data_rank2 = l_data_rank2  | l_nmask;
                                l_data_rank3 = l_data_rank3  | l_nmask;
                                l_data_rank4 = l_data_rank4  | l_nmask;
                                l_data_rank5 = l_data_rank5  | l_nmask;
                                l_data_rank6 = l_data_rank6  | l_nmask;
                                l_data_rank7 = l_data_rank7  | l_nmask;
                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s POST data rank 0 =0x%04X rank 1 =0x%04X rank 2 =0x%04X rank 3 =0x%04X rank 4 =0x%04X rank 5 =0x%04X rank 6 =0x%04X rank 7 =0x%04X",
                                         mss::c_str(i_mba_target), l_data_rank0, l_data_rank1, l_data_rank2, l_data_rank3, l_data_rank4, l_data_rank5,
                                         l_data_rank6, l_data_rank7 );

                            }
                            else if (l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8)
                            {
                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s Its a x8 so leaving it the same.", mss::c_str(i_mba_target));

                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s PRE data rank 0 =0x%04X rank 1 =0x%04X rank 2 =0x%04X rank 3 =0x%04X rank 4 =0x%04X rank 5 =0x%04X rank 6 =0x%04X rank 7 =0x%04X",
                                         mss::c_str(i_mba_target), l_data_rank0, l_data_rank1, l_data_rank2, l_data_rank3, l_data_rank4, l_data_rank5,
                                         l_data_rank6, l_data_rank7 );
                                l_data_rank0 = (l_data_rank0) | ( l_data & l_nmask);
                                l_data_rank1 = (l_data_rank1) | ( l_data & l_nmask);
                                l_data_rank2 = (l_data_rank2) | ( l_data & l_nmask);
                                l_data_rank3 = (l_data_rank3) | ( l_data & l_nmask);
                                l_data_rank4 = (l_data_rank4) | ( l_data & l_nmask);
                                l_data_rank5 = (l_data_rank5) | ( l_data & l_nmask);
                                l_data_rank6 = (l_data_rank6) | ( l_data & l_nmask);
                                l_data_rank7 = (l_data_rank7) | ( l_data & l_nmask);

                                FAPI_DBG("BYTE DISABLE WORKAROUND: %s POST data rank 0 =0x%04X rank 1 =0x%04X rank 2 =0x%04X rank 3 =0x%04X rank 4 =0x%04X rank 5 =0x%04X rank 6 =0x%04X rank 7 =0x%04X",
                                         mss::c_str(i_mba_target), l_data_rank0, l_data_rank1, l_data_rank2, l_data_rank3, l_data_rank4, l_data_rank5,
                                         l_data_rank6, l_data_rank7 );
                            }
                        }

                    }//nibble

                    if (l_dimm == 0)
                    {
                        if (l_rank == 0)
                        {
                            l_data_rank0 = l_data;
                        }
                        else if (l_rank == 1)
                        {
                            l_data_rank1 = l_data;
                        }
                        else if (l_rank == 2)
                        {
                            l_data_rank2 = l_data;
                        }
                        else if (l_rank == 3)
                        {
                            l_data_rank3 = l_data;
                        }
                    }
                    else if (l_dimm == 1)
                    {
                        if (l_rank == 0)
                        {
                            l_data_rank4 = l_data;
                        }
                        else if (l_rank == 1)
                        {
                            l_data_rank5 = l_data;
                        }
                        else if (l_rank == 2)
                        {
                            l_data_rank6 = l_data;
                        }
                        else if (l_rank == 3)
                        {
                            l_data_rank7 = l_data;
                        }
                    }

                    FAPI_TRY(l_db_reg_dimm0_rank0.insert(l_data_rank0, i * 16, 16, 0));
                    FAPI_TRY(l_db_reg_dimm0_rank1.insert(l_data_rank1, i * 16, 16, 0));
                    FAPI_TRY(l_db_reg_dimm0_rank2.insert(l_data_rank2, i * 16, 16, 0));
                    FAPI_TRY(l_db_reg_dimm0_rank3.insert(l_data_rank3, i * 16, 16, 0));
                    FAPI_TRY(l_db_reg_dimm1_rank0.insert(l_data_rank4, i * 16, 16, 0));
                    FAPI_TRY(l_db_reg_dimm1_rank1.insert(l_data_rank5, i * 16, 16, 0));
                    FAPI_TRY(l_db_reg_dimm1_rank2.insert(l_data_rank6, i * 16, 16, 0));
                    FAPI_TRY(l_db_reg_dimm1_rank3.insert(l_data_rank7, i * 16, 16, 0));
                }//dp18
            }// end of primary rank loop

            // loop through primary ranks [0:3]
            for (uint8_t l_prank = 0; l_prank < NUM_RANK_GROUPS; l_prank ++ )
            {
                l_dimm = l_prg[l_prank][l_port] >> 2;
                uint8_t l_rank = l_prg[l_prank][l_port] & 0x03;
                FAPI_DBG("%s BYTE DISABLE WORKAROUND: Looping through dimm: %d rank: %d ", mss::c_str(i_mba_target), l_dimm, l_rank);

                if (l_prg[l_prank][l_port] == l_rg_invalid[l_prank])  // invalid rank
                {
                    FAPI_DBG("%s Primary rank group %i is INVALID, continuing...",
                             mss::c_str(i_mba_target), l_prank);
                    continue;
                }

                if (l_dimm == 0)
                {
                    if (l_rank == 0)
                    {
                        FAPI_TRY(l_db_reg_dimm0_rank0.insert(l_db_reg));
                    }
                    else if (l_rank == 1)
                    {
                        FAPI_TRY(l_db_reg_dimm0_rank1.insert(l_db_reg));
                    }
                    else if (l_rank == 2)
                    {
                        FAPI_TRY(l_db_reg_dimm0_rank2.insert(l_db_reg));
                    }
                    else if (l_rank == 3)
                    {

                        FAPI_TRY(l_db_reg_dimm0_rank3.insert(l_db_reg));
                    }
                }
                else if (l_dimm == 1)
                {
                    if (l_rank == 0)
                    {
                        FAPI_TRY(l_db_reg_dimm1_rank0.insert(l_db_reg));
                    }
                    else if (l_rank == 1)
                    {
                        FAPI_TRY(l_db_reg_dimm1_rank1.insert(l_db_reg));
                    }
                    else if (l_rank == 2)
                    {
                        FAPI_TRY(l_db_reg_dimm1_rank2.insert(l_db_reg));
                    }
                    else if (l_rank == 3)
                    {
                        FAPI_TRY(l_db_reg_dimm1_rank3.insert(l_db_reg));
                    }
                }

                FAPI_INF("%s Setting BBM across dimm: %d rank: %d", mss::c_str(i_mba_target), l_dimm, l_rank);
                FAPI_TRY(setC4dq2reg(i_mba_target, l_port, l_dimm, l_rank, l_db_reg));

            }// end of primary rank loop
        } // end port loop

    fapi_try_exit:
        return fapi2::current_err;
    } // end mss_get_bbm_regs

    ///
    /// @brief  calls dimmGetBadDqBitmap and converts the data to phy order in a databuffer
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_dimm Memory Dimm
    /// @param[in] i_rank Memory Rank
    /// @param[out] o_reg
    /// @param[out] o_is_clean
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode getC4dq2reg(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba, const uint8_t i_port,
                                  const uint8_t i_dimm, const uint8_t i_rank, fapi2::variable_buffer& o_reg, uint8_t& o_is_clean)
    {
        // used by set_bbm(flash to registers)
        // output reg = in phy based order(lanes)
        uint8_t l_bbm[DIMM_DQ_RANK_BITMAP_SIZE] = {0};   // bad bitmap from dimmGetBadDqBitmap
        uint8_t l_dq = 0;
        uint8_t l_phy_lane, l_phy_block;
        uint8_t l_spare_bitmap = 0;
        uint8_t l_dimm_spare[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t l_bs = 0;
        uint8_t l_be = 8;
        uint8_t l_loc = 0;

        o_reg.flush<0>();       // clear output databuffer

        // get Centaur dq bitmap (C4 signal) order=[0:79], array of bytes
        FAPI_TRY(dimmGetBadDqBitmap(i_mba, i_port, i_dimm, i_rank, l_bbm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, i_mba, l_dimm_spare));

        // Setting to clean to start - if we find any bad bits, we'll note em as not clean below
        o_is_clean = 1;

        for (uint8_t byte = 0; byte < DIMM_DQ_RANK_BITMAP_SIZE; byte ++)
        {
            if (l_bbm[byte] != 0)
            {
                if (byte == (DIMM_DQ_RANK_BITMAP_SIZE - 1))      // spare byte
                {
                    switch (l_dimm_spare[i_port][i_dimm][i_rank])
                    {
                        case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_NO_SPARE:  // 0xFF
                            continue;                           // ignore bbm data for nonexistent spare
                            break;

                        case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_LOW_NIBBLE:
                            l_spare_bitmap = 0x0F;
                            break;

                        case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_HIGH_NIBBLE:
                            l_spare_bitmap = 0xF0;
                            break;

                        case fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_FULL_BYTE:
                            l_spare_bitmap = 0x00;
                            break;

                        default:
                            FAPI_ASSERT(false,
                                        fapi2::CEN_MSS_DRAMINIT_TRAINING_DIMM_SPARE_INPUT_ERROR().
                                        set_TARGET_MBA_ERROR(i_mba).
                                        set_SPARE(l_dimm_spare[i_port][i_dimm][i_rank]).
                                        set_PORT(i_port).
                                        set_DIMM(i_dimm).
                                        set_RANK(i_rank),
                                        "ATTR_VPD_DIMM_SPARE is invalid %u",
                                        l_dimm_spare[i_port][i_dimm][i_rank]);
                    }

                    if (l_bbm[byte] == l_spare_bitmap)    // spare already set via initfile
                    {
                        continue;
                    }
                }

                o_is_clean = 0;

                if ((l_bbm[byte] & 0xF0) == 0xF0)   // 0xF?
                {
                    l_dq = (byte * BITS_PER_BYTE);        // for first lane
                    // input=cen_c4_dq, output=phy block, lane
                    FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq,
                                        0, l_phy_lane, l_phy_block, 0));

                    if (l_bbm[byte] == 0xFF)
                    {
                        // block lanes + 1st lane{0,8}
                        l_loc = (l_phy_block * LANES_PER_BLOCK) + (l_phy_lane / BITS_PER_BYTE) * BITS_PER_BYTE;
                        o_reg.setBit(l_loc, 8);   // set dq byte
                        FAPI_DBG("%s 0xFF  byte=%i, lbbm=0x%02x  dp%i_%i dq=%i o=%i",
                                 mss::c_str(i_mba), byte, l_bbm[byte], l_phy_block, l_phy_lane, l_dq, l_loc);
                        continue;
                    }

                    // block lanes + 1st lane{0,4,8,12}
                    l_loc = (l_phy_block * LANES_PER_BLOCK) + (l_phy_lane / BITS_PER_NIBBLE) * BITS_PER_NIBBLE;
                    o_reg.setBit(l_loc, 4);       // set dq nibble0
                    FAPI_DBG("%s 0xF0  byte=%i, lbbm=0x%02x  dp%i_%i dq=%i o=%i",
                             mss::c_str(i_mba), byte, l_bbm[byte], l_phy_block, l_phy_lane, l_dq, l_loc);

                    if (l_bbm[byte] == 0xF0)            // done with byte
                    {
                        continue;
                    }

                    l_bs = 4;     // processed the first 4 bits already
                }
                else if ((l_bbm[byte] & 0x0F) == 0x0F)  // 0x?F
                {
                    l_dq = (byte * BITS_PER_BYTE) + 4;        // for first lane of dq
                    FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq,
                                        0, l_phy_lane, l_phy_block, 0));

                    // block lanes + 1st lane{0,4,8,12}
                    l_loc = (l_phy_block * LANES_PER_BLOCK) + (l_phy_lane / BITS_PER_NIBBLE) * BITS_PER_NIBBLE;
                    FAPI_DBG("%s 0x0F  byte=%i, lbbm=0x%02x  dp%i_%i dq=%i o=%i",
                             mss::c_str(i_mba), byte, l_bbm[byte], l_phy_block, l_phy_lane, l_dq, l_loc);
                    o_reg.setBit(l_loc, 4);               // set dq nibble1

                    if (l_bbm[byte] == 0x0F)            // done with byte
                    {
                        continue;
                    }

                    l_be = 4;     // processed the last 4 bits already
                }
                else if ((l_bbm[byte] >> 4) == 0)   // 0x0?
                {
                    l_bs = 4;
                }
                else if ((l_bbm[byte] & 0x0F) == 0) // 0x?0
                {
                    l_be = 4;
                }

                for (uint8_t b = l_bs; b < l_be; b++)   // test each bit
                {
                    if ((l_bbm[byte] & (0x80 >> b)) > 0)        // bit is set,
                    {
                        l_dq = (byte * BITS_PER_BYTE) + b;
                        FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq,
                                            0, l_phy_lane, l_phy_block, 0));

                        l_loc = (l_phy_block * LANES_PER_BLOCK) + l_phy_lane;
                        o_reg.setBit(l_loc);
                        FAPI_DBG("%s b=%i  byte=%i, lbbm=0x%02x  dp%i_%i dq=%i "
                                 "loc=%i bs=%i be=%i", mss::c_str(i_mba), b, byte, l_bbm[byte],
                                 l_phy_block, l_phy_lane, l_dq, l_loc, l_bs, l_be);
                    }
                }
            } // end if not clean
        } // end byte

    fapi_try_exit:
        return fapi2::current_err;
    } // end getC4dq2reg

    ///
    /// @brief  Converts the data from phy order (i_reg) to cen_c4_dq array for dimmSetBadDqBitmap to write flash with
    /// @param[in] i_target const reference to centaur.mba target
    /// @param[in] i_port Memory Port
    /// @param[in] i_dimm Memory Dimm
    /// @param[in] i_rank Memory Rank
    /// @param[in] i_reg
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode setC4dq2reg(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba, const uint8_t i_port,
                                  const uint8_t i_dimm, const uint8_t i_rank, const fapi2::variable_buffer& i_reg)
    {
// used by get_bbm(registers to flash)
        uint8_t l_bbm [DIMM_DQ_RANK_BITMAP_SIZE] = {0};
        uint8_t l_dq = 0;
        uint8_t l_phy_lane = 0;
        uint8_t l_phy_block = 0;
        uint8_t l_data = 0;
        uint8_t l_bs = 0;
        uint8_t l_be = 8;

        // get Centaur dq bitmap (C4 signal) order=[0:79], array of bytes
        FAPI_TRY(dimmGetBadDqBitmap(i_mba, i_port, i_dimm, i_rank, l_bbm));

        for (uint8_t byte = 0; byte < DIMM_DQ_RANK_BITMAP_SIZE; byte++)
        {
            FAPI_TRY(i_reg.extract(l_data, byte * BITS_PER_BYTE, 8));

            if (l_data != 0)              // need to check bits
            {

                l_phy_block = (byte / MAX_BYTES_PER_BLOCK);     // byte=[0..9], block=[0..4]
                FAPI_DBG("\n\t\t\t\t\t\tbyte=%i, data=0x%02x  phy_block=%i  ",
                         byte, l_data, l_phy_block);

                if ((l_data & 0xF0) == 0xF0)  // 0xF?
                {
                    l_phy_lane = BITS_PER_BYTE * (byte % 2);  // lane=[0,8]
                    // input=block, lane  output=cen_dq
                    FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq,
                                        0, l_phy_lane, l_phy_block, 1));


                    if (l_data == 0xFF)
                    {
                        // set 8 consecutive bits of the cen_c4_dq
                        l_bbm[(l_dq / BITS_PER_BYTE)] = 0xFF;
                        FAPI_DBG("0xFF dp%i_%i dq=%i, lbbm=0x%02x",
                                 l_phy_block, l_phy_lane, l_dq, l_bbm[l_dq / BITS_PER_BYTE]);
                        continue;
                    }

                    l_bbm[(l_dq / BITS_PER_BYTE)] |= ((l_dq % BITS_PER_BYTE) < 4) ? 0xF0 : 0x0F;
                    FAPI_DBG("0xF0 dp%i_%i dq=%i, lbbm=0x%02x",
                             l_phy_block, l_phy_lane, l_dq, l_bbm[l_dq / BITS_PER_BYTE]);

                    if (l_data == 0xF0)           // done with byte
                    {
                        continue;
                    }

                    l_bs = 4;         // need to work on other bits
                }
                else if ((l_data & 0x0F) == 0x0F) // 0x?F
                {
                    l_phy_lane = (BITS_PER_BYTE * (byte % 2)) + 4;    // lane=[4,12]
                    FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq,
                                        0, l_phy_lane, l_phy_block, 1));


                    l_bbm[(l_dq / BITS_PER_BYTE)] |= ((l_dq % BITS_PER_BYTE) < 4) ? 0xF0 : 0x0F;
                    FAPI_DBG("0x0F dp%i_%i dq=%i, lbbm=0x%02x",
                             l_phy_block, l_phy_lane, l_dq, l_bbm[l_dq / BITS_PER_BYTE]);

                    if (l_data == 0x0F)           // done with byte
                    {
                        continue;
                    }

                    l_be = 4;         // need to work on other bits
                }
                else if ((l_data >> 4) == 0)  // 0x0?
                {
                    l_bs = 4;
                }
                else if ((l_data & 0x0F) == 0)    // 0x?0
                {
                    l_be = 4;
                }

                for (uint8_t b = l_bs; b < l_be; b++)   // test each bit
                {
                    if ((l_data & (0x80 >> b)) > 0)       // bit is set,
                    {
                        l_phy_lane = (BITS_PER_BYTE * (byte % 2)) + b;
                        FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq,
                                            0, l_phy_lane, l_phy_block, 1));

                        l_bbm[(l_dq / BITS_PER_BYTE)] |= (0x80 >> (l_dq % BITS_PER_BYTE));

                    }
                    else        // bit is not set,
                    {
                        l_phy_lane = (BITS_PER_BYTE * (byte % 2)) + b;
                        FAPI_TRY(mss_c4_phy(i_mba, i_port, 0, RD_DQ, l_dq,
                                            0, l_phy_lane, l_phy_block, 1));

                        l_bbm[(l_dq / BITS_PER_BYTE)] &= (~(0x80 >> (l_dq % BITS_PER_BYTE)));

                    }
                }
            } //end if not clean
        } //end byte

        // set Centaur dq bitmap (C4 signal) order=[0:79], array of bytes
        FAPI_TRY(dimmSetBadDqBitmap(i_mba, i_port, i_dimm, i_rank, l_bbm), "Error from dimmSetBadDqBitmap on port %i: "
                 "dimm=%i, rank=%i ", i_port, i_dimm, i_rank);
    fapi_try_exit:
        return fapi2::current_err;
    } //end setC4dq2reg


    ///
    /// @brief DDR4: Sets the DQS offset to be 16 instead of 8
    /// @param[in] i_target const reference to centaur.mba target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_setup_dqs_offset(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        fapi2::buffer<uint64_t> l_buffer;
        constexpr uint8_t const NUM_DQSCLK_REGS = MAX_PORTS_PER_MBA * DP18_INSTANCES; //2 * 5 = 10
        uint64_t l_scom_addr_array[NUM_DQSCLK_REGS] = {CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P0_0 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P0_1 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P0_2 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P0_3 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P0_4 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P1_0 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P1_1 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P1_2 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P1_3 ,
                                                       CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P1_4
                                                      };

        FAPI_INF("DDR4: setting up DQS offset to be 16");

        for(uint8_t scom_addr = 0; scom_addr < NUM_DQSCLK_REGS; ++scom_addr)
        {
            FAPI_TRY(fapi2::getScom(i_target, l_scom_addr_array[scom_addr], l_buffer));
            //Setting up CCS mode
            l_buffer.insertFromRight<CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P0_0_01_DQS, CEN_MBA_DDRPHY_DP18_DQSCLK_OFFSET_P0_0_01_DQS_LEN>((
                        uint32_t)16);
            FAPI_TRY(fapi2::putScom(i_target, l_scom_addr_array[scom_addr], l_buffer));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Setup CCS instructions for setting non calibrating ranks to wr lvl mode on and qoff disabled during wr lvling
/// @param[in] i_target mba target being calibrated
/// @param[in] i_port port being calibrated
/// @param[in] i_rank_pair_group rank pair group being calibrated
/// @param[in] i_state 1 turn on (confiugre) or 0 turn off (cleanup)
/// @param[in,out] CCS instruction Number
/// @return FAPI2_RC_SUCCESS iff successful
///
    fapi2::ReturnCode configure_non_calibrating_ranks(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_port,
            const uint32_t i_rank_pair_group,
            const uint8_t i_state,
            uint32_t& io_ccs_inst_cnt)
    {
        uint8_t l_dram_gen = 0;
        uint8_t l_ranks_array[MAX_RANKS_PER_RANK_GROUP][NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {0};
        uint8_t l_rank_to_cal = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target, l_ranks_array[0][0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target, l_ranks_array[0][1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target, l_ranks_array[0][2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target, l_ranks_array[0][3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP0, i_target, l_ranks_array[1][0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP1, i_target, l_ranks_array[1][1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP2, i_target, l_ranks_array[1][2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP3, i_target, l_ranks_array[1][3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP0, i_target, l_ranks_array[2][0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP1, i_target, l_ranks_array[2][1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP2, i_target, l_ranks_array[2][2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP3, i_target, l_ranks_array[2][3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0, i_target, l_ranks_array[3][0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1, i_target, l_ranks_array[3][1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2, i_target, l_ranks_array[3][2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3, i_target, l_ranks_array[3][3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target, l_dram_gen));
        l_rank_to_cal = l_ranks_array[0][i_rank_pair_group][i_port];

        FAPI_DBG("Rank Group Under Cal:  %d   Rank: %d   on %s", i_rank_pair_group, l_rank_to_cal, mss::c_str(i_target));

        for(uint8_t l_rankgroup = 0; l_rankgroup < NUM_RANK_GROUPS; l_rankgroup++)
        {
            FAPI_DBG("Checking rankgroup %d on %s port %d: rank: %d ", l_rankgroup, mss::c_str(i_target), i_port,
                     l_ranks_array[0][l_rankgroup][i_port]);

            // If rankgroup is valid and is not the rankgroup being calibrated, send MRS
            if((l_ranks_array[0][l_rankgroup][i_port] != fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0_INVALID)
               && (l_rankgroup != i_rank_pair_group))
            {
                // Send MRS
                FAPI_INF("Sending WRLVL MRS to rank group %d rank %d on target %s", l_rankgroup,
                         l_ranks_array[0][l_rankgroup][i_port], mss::c_str(i_target));
                FAPI_TRY(send_wr_lvl_mrs(i_target, i_port, l_ranks_array[0][l_rankgroup][i_port], i_state, io_ccs_inst_cnt),
                         "Failed to send wr lvl mrs to non calibrating ranks on %s port %d rank %d", mss::c_str(i_target), i_port,
                         l_ranks_array[0][l_rankgroup][i_port]);
            }

            // Disable any other valid ranks
            for(uint8_t l_rank = 1; l_rank < MAX_RANKS_PER_RANK_GROUP; l_rank++)
            {
                if(l_ranks_array[l_rank][l_rankgroup][i_port] != fapi2::ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0_INVALID)
                {
                    // Send MRS
                    FAPI_INF("Sending WRLVL MRS to rank group %d rank %d on target %s", l_rankgroup,
                             l_ranks_array[l_rank][l_rankgroup][i_port], mss::c_str(i_target));
                    FAPI_TRY(send_wr_lvl_mrs(i_target, i_port, l_ranks_array[l_rank][l_rankgroup][i_port], i_state, io_ccs_inst_cnt),
                             "Failed to send wr lvl mrs to non calibrating ranks on %s port %d rank %d", mss::c_str(i_target), i_port,
                             l_ranks_array[l_rank][l_rankgroup][i_port]);
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Check row repair requests for a bad nibble and decide whether it affects training
/// @param[in] i_target mba target
/// @param[in] i_port port index
/// @param[in] i_rank rank index
/// @param[in] i_dp DP18 index of nibble in question
/// @param[in] i_lane DP18 lane of nibble in question
/// @param[in] i_dram_width DRAM width
/// @param[in] i_repairs_per_dimm table of row repair requests, from build_row_repair_table
/// @param[out] o_workaround_needed true if the workaround applies (we should train the nibble or clear the row repair request), false if not
/// @return FAPI2_RC_SUCCESS iff successful
///
    bool row_repair_workaround_check(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_port,
                                     const uint8_t i_rank,
                                     const uint8_t i_dp,
                                     const uint8_t i_lane,
                                     const uint8_t i_dram_width,
                                     const std::vector<fapi2::buffer<uint32_t>> i_repairs_per_dimm,
                                     bool& o_workaround_needed)
    {
        uint8_t l_dram = 0;
        uint8_t l_srank = 0;
        uint8_t l_bg = 0;
        uint8_t l_bank = 0;
        uint32_t l_row = 0;

        o_workaround_needed = false;

        if (valid_row_repair_entry(i_repairs_per_dimm[i_rank], l_dram, l_srank, l_bg, l_bank, l_row))
        {
            uint8_t l_phy_lane = 0;
            uint8_t l_phy_block = 0;
            const auto l_row_repair_nibble = (i_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ?
                                             l_dram * 2 :
                                             l_dram;
            // This guy can't be const because it's not in the mss_c4_phy API
            uint8_t l_row_repair_index = l_row_repair_nibble * BITS_PER_NIBBLE;

            // Training works on a phy-perspective, and the row repair attribute is on a Centaur perspective
            // so we need to convert the row repair's DRAM into PHY block/lane
            FAPI_TRY(mss_c4_phy(i_target, i_port, 0, RD_DQ, l_row_repair_index, 0, l_phy_lane, l_phy_block, 0));

            // Then normalize the lane to get the 0th bit on the nibble
            l_phy_lane = (l_phy_lane / BITS_PER_NIBBLE) * BITS_PER_NIBBLE;

            if ((l_phy_block == i_dp) && (l_phy_lane == i_lane))
            {
                o_workaround_needed = true;
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Find a DIMM target on an MBA target, from a port and DIMM index
/// @param[in] i_target mba target
/// @param[in] i_port_index port index
/// @param[in] i_dimm_index DIMM index
/// @param[out] o_dimm DIMM target
/// @return FAPI2_RC_SUCCESS iff successful
///
    fapi2::ReturnCode find_dimm_from_index(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                           const uint8_t i_port_index,
                                           const uint8_t i_dimm_index,
                                           fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_dimm)
    {
        bool l_found_dimm = false;

        // Find DIMM target with this port and dimm index
        for (const auto l_dimm_target : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
        {
            uint8_t l_this_port = 0;
            uint8_t l_this_dimm = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_dimm_target, l_this_port));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm_target, l_this_dimm));

            if ((l_this_port == i_port_index) && (l_this_dimm == i_dimm_index))
            {
                l_found_dimm = true;
                o_dimm = l_dimm_target;
                break; // Break out of for loop since we found the DIMM target for this i_port and i_dimm
            }
        }

        FAPI_ASSERT(l_found_dimm,
                    fapi2::CEN_DIMM_NOT_FOUND_FROM_INDEX().
                    set_MBA(i_target).
                    set_PORT_INDEX(i_port_index).
                    set_DIMM_INDEX(i_dimm_index),
                    "Did not find DIMM for %s, port index:%d dimm index:%d",
                    mss::c_str(i_target), i_port_index, i_dimm_index);

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Set non calibrating ranks to wr lvl mode on and qoff disabled during wr lvling
/// @param[in] i_target mba target being calibrated
/// @param[in] i_port port being calibrated
/// @param[in] i_rank_pair_group rank pair group being calibrated
/// @param[in] i_state 1 turn on (configure) or 0 turn off (cleanup)
/// @param[in,out] CCS instruction Number
/// @return FAPI2_RC_SUCCESS iff successful
///
    fapi2::ReturnCode send_wr_lvl_mrs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const uint8_t i_port,
                                      const uint8_t i_rank,
                                      const uint8_t i_state,
                                      uint32_t& io_ccs_inst_cnt)
    {
        uint8_t l_dram_gen = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target, l_dram_gen));

        if (l_dram_gen == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4)
        {
            FAPI_TRY(setup_wr_lvl_mrs_ddr4(i_target, i_port, i_rank, i_state, io_ccs_inst_cnt));
        }
        else
        {
            FAPI_TRY(setup_wr_lvl_mrs(i_target, i_port, i_rank, i_state, io_ccs_inst_cnt));
        }

        FAPI_TRY(mss_execute_ccs_inst_array(i_target, 10, 10), " EXECUTE_CCS_INST_ARRAY FAILED FAPI_TRY");

    fapi_try_exit:
        return fapi2::current_err;
    }

} //end extern C
