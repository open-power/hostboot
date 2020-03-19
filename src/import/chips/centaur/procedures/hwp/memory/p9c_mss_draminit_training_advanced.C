/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit_training_advanced.C $ */
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

///
/// @file p9c_mss_draminit_training_advanced.C
/// @brief Tools for centaur procedures
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

// This procedure Shmoo's DRV_IMP, SLEW, VREF (DDR, CEN), RCV_IMP based on attribute from effective config procedure
// DQ & DQS Driver impedance, Slew rate, WR_Vref shmoo would call only write_eye shmoo for margin calculation
// DQ & DQS VREF (rd_vref), RCV_IMP shmoo would call rd_eye for margin calculation
// Internal Vref controlled by this function & external vref

// Not supported
// DDR4, DIMM Types
//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------

#include <map>
#include <array>
#include <fapi2.H>
#include <p9c_mss_termination_control.H>
#include <p9c_mss_mcbist.H>
#include <dimmConsts.H>
#include <p9c_mss_draminit_training_advanced.H>
#include <p9c_mss_unmask_errors.H>
#include <p9c_mss_mrs6_DDR4.H>
#include <p9c_mss_ddr4_pda.H>
#include <p9c_mss_generic_shmoo.H>
#include <generic/memory/lib/utils/c_str.H>

const uint32_t MASK = 1;
constexpr uint64_t SAVE_RESTORE_LENGTH = 8;
enum save_restore_mode : uint8_t
{
    SAVE = 0,
    RESTORE = 1,
};

constexpr uint64_t REFRESH_BIT = CEN_MBA_MBAREF0Q_CFG_REFRESH_ENABLE;

extern "C"
{

    ///
    /// @brief  Save and restore registers before and after shmoo
    /// @param[in] i_target_mba Centaur input MBA
    /// @param[in,out] io_content_array Storage array to save to and restore from
    /// @param[in] i_mode  0 = save 1 = restore
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_SaveAndRestore(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         uint64_t io_content_array[],
                                         const uint8_t i_mode)
    {
        uint8_t l_index = 0;
        uint8_t l_index1 = 0;
        uint64_t l_value = 0;
        uint64_t l_val_u64 = 0;
        fapi2::buffer<uint64_t> l_mcbem1ab;
        uint64_t l_register_array[6] = {CEN_MBA_MCBCFGQ, CEN_MBA_MBA_WRQ0Q, CEN_MBA_MBA_RRQ0Q, CEN_MBA_MBA_WRD_MODE, CEN_MBA_MBA_FARB3Q, CEN_MBA_MBARPC0Q};
        uint64_t l_mbs_reg[2] = {CEN_ECC01_MBSECCQ, CEN_ECC23_MBSECCQ};

        const auto l_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        if(i_mode == save_restore_mode::SAVE) // MODE == SAVE
        {
            FAPI_INF("%s: Saving Register contents", mss::c_str(i_target_mba));

            for(l_index = 0; l_index < 6; l_index++)
            {
                l_value = l_register_array[l_index];
                FAPI_TRY(fapi2::getScom(i_target_mba, l_value, l_mcbem1ab));

                FAPI_TRY(l_mcbem1ab.extract(io_content_array[l_index], 0, 64));
            }

            for(l_index = 6; l_index < 8; l_index++)
            {

                l_value = l_mbs_reg[l_index1];
                FAPI_TRY(fapi2::getScom(l_target_centaur, l_value, l_mcbem1ab));
                FAPI_TRY(l_mcbem1ab.extract(io_content_array[l_index], 0, 64));
                l_index1++;
            }
        }

        else if(i_mode == save_restore_mode::RESTORE) // MODE == RESTORE
        {
            FAPI_INF("%s:  Restoring Register contents", mss::c_str(i_target_mba));

            for(l_index = 0; l_index < 6; l_index++)
            {
                l_val_u64 = io_content_array[l_index];
                l_value = l_register_array[l_index];
                FAPI_TRY(l_mcbem1ab.insert(l_val_u64, 0, 64), "Error in function  mcb_SaveAndRestore");
                FAPI_TRY(fapi2::putScom(i_target_mba, l_value, l_mcbem1ab));
            }

            l_index1 = 0;

            for(l_index = 6; l_index < 8; l_index++)
            {
                l_val_u64 = io_content_array[l_index];
                l_value = l_mbs_reg[l_index1];
                FAPI_TRY(l_mcbem1ab.insert(l_val_u64, 0, 64), "Error in function mcb_SaveAndRestore");
                FAPI_TRY(fapi2::putScom(l_target_centaur, l_value, l_mcbem1ab));
                l_index1++;
            }
        }
        else
        {
            FAPI_INF("%s: Invalid value of MODE", mss::c_str(i_target_mba));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}
//end of extern C

///
/// @brief: varies drv&rcv imp, slew, wr&rd vref based on attribute definition and runs either mcbist/delay shmoo based on attribute
/// @param[in] i_target_mba :  Centaur MBA
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode p9c_mss_draminit_training_advanced(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{

    // Define attribute variables
    uint32_t l_attr_mss_freq_u32 = 0;
    uint32_t l_attr_mss_volt_u32 = 0;
    uint8_t l_num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {{0}};
    uint8_t l_port = 0;
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_shmoo_param = 0;
    uint8_t l_dram_type = 0;
    uint8_t l_bin_pda = 0;
    uint8_t vref_cal_control = 0;
    uint8_t temp_cal_control = 0;
    uint32_t l_cal_control[2] = {0};
    uint64_t l_mcbist_address_config = 0;
    fapi2::buffer<uint64_t> l_data_buffer_64;

    // Define local variables
    uint8_t l_shmoo_type_valid_t = 0;
    uint8_t l_shmoo_param_valid_t = 0;
    const auto& l_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

    FAPI_INF("%s +++++++ Executing mss_draminit_training_advanced +++++++", mss::c_str(i_target_mba));

    //Save registers pre-shmoo
    uint64_t i_content_array[SAVE_RESTORE_LENGTH] = {0};
    FAPI_TRY(mcb_SaveAndRestore(i_target_mba, i_content_array, save_restore_mode::SAVE));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_u32));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_target_centaur, l_attr_mss_volt_u32));
    //Preet Add MSS_CAL control here
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VREF_CAL_CNTL, l_target_centaur, vref_cal_control));
    FAPI_INF("%s +++++++++++ - DDR4 - CAL Control - %d ++++++++++++++++++++", mss::c_str(i_target_mba), vref_cal_control);

    // Skips training advanced completely if VREF cal control is disable
    if(vref_cal_control == fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_DISABLE)
    {
        FAPI_INF("%s has training advanced disabled. Only running unmask errors.", mss::c_str(i_target_mba));
        FAPI_TRY(mss_unmask_draminit_training_advanced_errors(i_target_mba), "Unmask Function Failed");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //const fapi::Target is centaur.mba
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, l_num_ranks_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba, l_dram_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_USER_BANK, i_target_mba, l_bin_pda));

    // Note: the raw 3 below is the result of porting over from the prior product generation - leaving as is as we are unable to track down it's purpose
    if ((vref_cal_control == fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_DISABLE)
        && (l_dram_type == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) && (l_bin_pda != 3))
    {
        FAPI_INF("%s +++++++++++++++++++++++++++++ - DDR4 - Skipping - V-Ref CAL Control +++++++++++++++++++++++++++++++++++++++++++++",
                 mss::c_str(i_target_mba));
        l_cal_control[0] = mcbist_test_mem::WRITE_READ_SF_RF;
        l_shmoo_param_valid_t = 1;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE, i_target_mba, l_shmoo_param_valid_t));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_TEST_TYPE, i_target_mba, l_cal_control[0]));
        FAPI_TRY(wr_vref_shmoo_ddr4_bin(i_target_mba), "Write Vref Shmoo Function Failed");

        // Disable Refresh DDR4 Requirement
        if (l_dram_type == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
        {
            FAPI_INF("%s ************* Disabling Refresh - DDR4 **************", mss::c_str(i_target_mba));
            FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
            l_data_buffer_64.clearBit<REFRESH_BIT>();
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        }
    }

    // Note: the raw 3 below is the result of porting over from the prior product generation - leaving as is as we are unable to track down it's purpose
    else if ((vref_cal_control != fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_DISABLE)
             && (l_dram_type == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) && (l_bin_pda != 3))
    {
        FAPI_INF("%s +++++++++++++++++++++++++++++ - DDR4 - CAL Control +++++++++++ Training ++++++++++++ in Progress ++++++++++++++++",
                 mss::c_str(i_target_mba));

        // Note: cannot be constant'ed due to FAPI_SET_ATTR's macro
        uint32_t MCBIST_TESTTYPE = mcbist_test_mem::WRITE_READ_SF_RF;
        constexpr uint64_t MCBIST_START_ADDRESS = 0;
        constexpr uint64_t SHMOO_MCBIST_END_ADDRESS = 0x0000001fc0000000ull;
        constexpr uint32_t SHMOO_ALL_VREF = 0xFFFFFFFF;

        // Sets up all of the needed attributes for the shmoo
        temp_cal_control = fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_PARAM_VALID_WR_VREF;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_PARAM_VALID, i_target_mba, temp_cal_control));
        temp_cal_control = fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_MODE_QUARTER_CHAR;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_MODE, i_target_mba, temp_cal_control));
        // Looks like this means we only hit one rank - leaving as this is ported code
        temp_cal_control = 1;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_USER_BANK, i_target_mba, temp_cal_control));
        temp_cal_control = fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_TEST_VALID_WR_EYE;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, temp_cal_control));
        // Looks like this means we only hit one rank - leaving as this is ported code
        l_shmoo_param_valid_t = 1;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_RANK, i_target_mba, l_shmoo_param_valid_t));
        l_shmoo_param_valid_t = fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_ADDR_MODE_QUARTER_ADDR;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE, i_target_mba, l_shmoo_param_valid_t));
        l_cal_control[0] = SHMOO_ALL_VREF;
        l_cal_control[1] = SHMOO_ALL_VREF;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WR_VREF_SCHMOO, i_target_mba, l_cal_control));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_TEST_TYPE, i_target_mba, MCBIST_TESTTYPE));
        l_mcbist_address_config = MCBIST_START_ADDRESS;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_START_ADDR, i_target_mba, l_mcbist_address_config));
        l_mcbist_address_config = SHMOO_MCBIST_END_ADDRESS;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_END_ADDR, i_target_mba, l_mcbist_address_config));
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_USER_BANK, i_target_mba, l_bin_pda));

    FAPI_INF("%s +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", mss::c_str(i_target_mba));
    FAPI_INF("%s freq = %d", mss::c_str(i_target_mba), l_attr_mss_freq_u32);
    FAPI_INF("%s volt = %d", mss::c_str(i_target_mba), l_attr_mss_volt_u32);
    FAPI_INF("%s num_ranks_per_dimm = [%02d][%02d][%02d][%02d]",
             mss::c_str(i_target_mba),
             l_num_ranks_per_dimm[0][0],
             l_num_ranks_per_dimm[0][1],
             l_num_ranks_per_dimm[1][0],
             l_num_ranks_per_dimm[1][1]);

    FAPI_INF("%s +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", mss::c_str(i_target_mba));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_shmoo_type_valid_t));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_PARAM_VALID, i_target_mba, l_shmoo_param_valid_t));

    FAPI_INF("%s +++++++++++++++++++++++++ Read Shmoo Attributes ++++++++++++++++++++++++++", mss::c_str(i_target_mba));
    FAPI_INF("%s Shmoo param valid = 0x%x", mss::c_str(i_target_mba), l_shmoo_param_valid_t);
    FAPI_INF("%s Shmoo test valid = 0x%x" , mss::c_str(i_target_mba), l_shmoo_type_valid_t);
    FAPI_INF("%s +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", mss::c_str(i_target_mba));
    //Check for Shmoo Parameter, if anyof them is enabled then go into the loop else the procedure exit

    // Checks to see if we have any ranks - if we do then get to shmooing
    if ((l_num_ranks_per_dimm[0][0] > 0) ||
        (l_num_ranks_per_dimm[0][1] > 0) ||
        (l_num_ranks_per_dimm[1][0] > 0) ||
        (l_num_ranks_per_dimm[1][1] > 0))
    {
        if ((l_shmoo_param_valid_t != PARAM_NONE) ||
            (l_shmoo_type_valid_t != TEST_NONE))
        {
            if ((l_shmoo_param_valid_t& DRV_IMP) != 0)
            {
                FAPI_TRY(drv_imped_shmoo(i_target_mba, l_port), "Driver Impedance Shmoo function is Failed");
            }

            if ((l_shmoo_param_valid_t& SLEW_RATE) != 0)
            {
                FAPI_TRY(slew_rate_shmoo(i_target_mba, l_port), "Slew Rate Shmoo Function is Failed");
            }

            if ((l_shmoo_param_valid_t& WR_VREF) != 0)
            {
                if(l_bin_pda == 1)
                {
                    FAPI_INF("%s ************* Bin - PDA - Vref_Shmoo **************", mss::c_str(i_target_mba));

                    FAPI_TRY(wr_vref_shmoo_ddr4_bin(i_target_mba), "Write Vref Shmoo Function is Failed");
                }
                else
                {
                    FAPI_TRY(wr_vref_shmoo_ddr4(i_target_mba), "Write Vref Shmoo Function is Failed");
                }

            }

            if ((l_shmoo_param_valid_t& RD_VREF) != 0)
            {
                FAPI_TRY(rd_vref_shmoo_ddr4(i_target_mba), "Read Vref Shmoo Function Failed");
            }

            if ((l_shmoo_param_valid_t& RCV_IMP) != 0)
            {
                FAPI_TRY(rcv_imp_shmoo(i_target_mba, l_port), "Receiver Impedance Shmoo Function is Failed");
            }

            if (((l_shmoo_param_valid_t == PARAM_NONE)))
            {
                FAPI_TRY(delay_shmoo(i_target_mba, l_port, static_cast<shmoo_type_t>(l_shmoo_type_valid_t),
                                     &l_left_margin, &l_right_margin,
                                     l_shmoo_param), "Delay Shmoo Function is Failed");
            }
        }
    }

    // Disable Refresh DDR4 Requirement
    if (l_dram_type == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
    {
        FAPI_INF("%s ************* Disabling Refresh - DDR4 **************", mss::c_str(i_target_mba));
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        l_data_buffer_64.clearBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
    }

    // If mss_unmask_draminit_training_advanced_errors gets it's own bad rc,
    // it will commit the passed in rc (if non-zero), and return it's own bad rc.
    // Else if mss_unmask_draminit_training_advanced_errors runs clean,
    // it will just return the passed in rc.
    FAPI_TRY(mss_unmask_draminit_training_advanced_errors(i_target_mba), "Unmask Function is Failed");
    FAPI_TRY(mcb_SaveAndRestore(i_target_mba, i_content_array, save_restore_mode::RESTORE));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief This function varies the driver impedance in the nominal mode
/// @param[in] i_target_mba : Centaur input MBA
/// @param[in] i_port : Centaur input port
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode drv_imped_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                  const uint8_t i_port)
{
    // for both dq/dqs & adr/cmd signals - DQ_DQS<24,30,34,40>,CMD_CNTL<15,20,30,40>
    // if there is any mcbist failure, that will be reported to put_bad_bits function
    uint8_t l_drv_imp_dq_dqs[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_drv_imp_dq_dqs_nom[MAX_PORTS_PER_MBA] = {0};
    uint8_t index = 0;
    uint8_t l_slew_rate_dq_dqs[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_slew_rate_dq_dqs_shmoo[MAX_PORTS_PER_MBA] = {0};
    uint32_t l_drv_imp_dq_dqs_shmoo[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_drv_imp_dq_dqs_nom_fc = 0;
    uint8_t l_drv_imp_dq_dqs_in = 0;
    //Temporary
    const shmoo_type_t l_shmoo_type_valid = WR_EYE;  //Hard coded, since no other shmoo is applicable for this parameter
    uint32_t l_left_margin_drv_imp_array[MAX_DRV_IMP] = {0};
    uint32_t l_right_margin_drv_imp_array[MAX_DRV_IMP] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t count = 0;
    uint8_t shmoo_param_count = 0;
    uint8_t l_slew_type = 0; // Hard coded since this procedure will touch only DQ_DQS and not address

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS, i_target_mba, l_slew_rate_dq_dqs));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS, i_target_mba, l_drv_imp_dq_dqs_nom));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, i_target_mba, l_drv_imp_dq_dqs_shmoo));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO, i_target_mba, l_slew_rate_dq_dqs_shmoo));

    FAPI_INF("+++++++++++++++++Read DRIVER IMP Attributes values++++++++++++++++");
    FAPI_INF("CEN_DRV_IMP_DQ_DQS[%d]  = [%02d] Ohms, on %s",
             i_port,
             l_drv_imp_dq_dqs_nom[i_port],
             mss::c_str(i_target_mba));
    FAPI_INF("CEN_DRV_IMP_DQ_DQS_SHMOO[0]  = [0x%x], CEN_DRV_IMP_DQ_DQS_SHMOO[1]  = [0x%x] on %s",
             l_drv_imp_dq_dqs_shmoo[0],
             l_drv_imp_dq_dqs_shmoo[1],
             mss::c_str(i_target_mba));
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS[0] = [%02d]V/ns , CEN_SLEW_RATE_DQ_DQS[1] = [%02d]V/ns on %s",
             l_slew_rate_dq_dqs[0],
             l_slew_rate_dq_dqs[1],
             mss::c_str(i_target_mba));
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS_SHMOO[0] = [0x%x], CEN_SLEW_RATE_DQ_DQS_SHMOO[1] = [0x%x] on %s",
             l_slew_rate_dq_dqs_shmoo[0],
             l_slew_rate_dq_dqs_shmoo[1],
             mss::c_str(i_target_mba));
    FAPI_INF("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    if(l_drv_imp_dq_dqs_shmoo[i_port] == 0) //Check for any of the bits enabled in the shmoo
    {
        FAPI_INF("DRIVER IMP Shmoo set to FAST Mode and won't do anything");
    }
    else
    {
        for (index = 0; index < MAX_DRV_IMP; index += 1)
        {
            if (l_drv_imp_dq_dqs_shmoo[i_port] & MASK)
            {
                l_drv_imp_dq_dqs[i_port] = drv_imp_array[index];
                FAPI_INF("Current Driver Impedance Value = %d Ohms",
                         drv_imp_array[index]);
                FAPI_INF("Configuring Driver Impedance Registers:");
                FAPI_TRY(config_drv_imp(i_target_mba, i_port,
                                        l_drv_imp_dq_dqs[i_port]));
                l_drv_imp_dq_dqs_in = l_drv_imp_dq_dqs[i_port];
                FAPI_INF("Configuring Slew Rate Registers:");
                FAPI_TRY(config_slew_rate(i_target_mba, i_port, l_slew_type,
                                          l_drv_imp_dq_dqs[i_port],
                                          l_slew_rate_dq_dqs[i_port]));
                FAPI_INF("Calling Shmoo for finding Timing Margin:");

                if (shmoo_param_count)
                {
                    FAPI_TRY(set_attribute(i_target_mba));
                }

                FAPI_TRY(delay_shmoo(i_target_mba, i_port, l_shmoo_type_valid,
                                     &l_left_margin, &l_right_margin,
                                     l_drv_imp_dq_dqs_in));
                l_left_margin_drv_imp_array[index] = l_left_margin;
                l_right_margin_drv_imp_array[index] = l_right_margin;
                shmoo_param_count++;
            }
            else
            {
                l_left_margin_drv_imp_array[index] = 0;
                l_right_margin_drv_imp_array[index] = 0;
            }

            l_drv_imp_dq_dqs_shmoo[i_port] = (l_drv_imp_dq_dqs_shmoo[i_port] >> 1);
        }

        l_drv_imp_dq_dqs_nom_fc = l_drv_imp_dq_dqs_nom[i_port];
        find_best_margin(DRV_IMP, l_left_margin_drv_imp_array,
                         l_right_margin_drv_imp_array, MAX_DRV_IMP,
                         l_drv_imp_dq_dqs_nom_fc, count);

        FAPI_ASSERT(count < MAX_DRV_IMP,
                    fapi2::CEN_DRV_IMPED_SHMOO_INVALID_MARGIN_DATA().
                    set_COUNT_DATA(count),
                    "Driver Imp new input %d out of bounds, >= %d",
                    count,
                    MAX_DRV_IMP);

        FAPI_INF("Restoring the nominal values!");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS, i_target_mba, l_drv_imp_dq_dqs_nom));
        FAPI_TRY(config_drv_imp(i_target_mba, i_port, l_drv_imp_dq_dqs_nom[i_port]));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS, i_target_mba, l_slew_rate_dq_dqs));
        FAPI_TRY(config_slew_rate(i_target_mba, i_port, l_slew_type,
                                  l_drv_imp_dq_dqs_nom[i_port],
                                  l_slew_rate_dq_dqs[i_port]));

        FAPI_INF("Restoring mcbist setup attribute...");
        FAPI_TRY(reset_attribute(i_target_mba));
        FAPI_INF("++++ Driver impedance shmoo function executed successfully ++++");
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief varies the slew rate of the data & adr signals (fast/slow)
/// @param[in] i_target_mba Centaur input mba
/// @param[in] i_port Centaur input port
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode slew_rate_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                  const uint8_t i_port)
{
    uint8_t l_slew_rate_dq_dqs[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_slew_rate_dq_dqs_nom[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_slew_rate_dq_dqs_nom_fc = 0;
    uint8_t l_slew_rate_dq_dqs_in = 0;
    uint32_t l_slew_rate_dq_dqs_shmoo[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_drv_imp_dq_dqs_nom[MAX_PORTS_PER_MBA] = {0};
    const shmoo_type_t l_shmoo_type_valid = WR_EYE; // Hard coded - Other shmoo type is not valid - Temporary
    uint8_t count = 0;
    uint8_t shmoo_param_count = 0;
    uint32_t l_left_margin_slew_array[MAX_NUM_SLEW_RATES] = {0};
    uint32_t l_right_margin_slew_array[MAX_NUM_SLEW_RATES] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t l_slew_type = 0; // Hard coded since this procedure will touch only DQ_DQS and not address

    //Read Attributes - DRV IMP, SLEW, SLEW RATES values to be Shmoo'ed
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS, i_target_mba, l_slew_rate_dq_dqs_nom));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, i_target_mba, l_slew_rate_dq_dqs_shmoo));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS, i_target_mba, l_drv_imp_dq_dqs_nom));

    FAPI_INF("+++++++++++++++++Read Slew Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_DRV_IMP_DQ_DQS[0]  = [%02d] Ohms, CEN_DRV_IMP_DQ_DQS[1]  = [%02d] Ohms on %s",
             l_drv_imp_dq_dqs_nom[0],
             l_drv_imp_dq_dqs_nom[1],
             mss::c_str(i_target_mba));
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS[0] = [%02d]V/ns , CEN_SLEW_RATE_DQ_DQS[1] = [%02d]V/ns on %s",
             l_slew_rate_dq_dqs_nom[0],
             l_slew_rate_dq_dqs_nom[1],
             mss::c_str(i_target_mba));
    FAPI_INF("CEN_SLEW_RATE_DQ_DQS_SHMOO[0] = [0x%x], CEN_SLEW_RATE_DQ_DQS_SHMOO[1] = [0x%x] on %s",
             l_slew_rate_dq_dqs_shmoo[0],
             l_slew_rate_dq_dqs_shmoo[1],
             mss::c_str(i_target_mba));
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    if(l_slew_rate_dq_dqs_shmoo == 0) //Check for any of the bits enabled in the shmoo
    {
        FAPI_INF("Slew Rate Shmoo set to FAST Mode and won't do anything");
    }
    else
    {
        for (uint8_t index = 0; index < MAX_NUM_SLEW_RATES; index += 1)
        {
            if (l_slew_rate_dq_dqs_shmoo[i_port] & MASK)
            {
                l_slew_rate_dq_dqs[i_port] = slew_rate_array[index];
                FAPI_INF("Current Slew rate value is %d V/ns",
                         slew_rate_array[index]);
                FAPI_INF("Configuring Slew registers:");
                FAPI_TRY(config_slew_rate(i_target_mba, i_port, l_slew_type,
                                          l_drv_imp_dq_dqs_nom[i_port],
                                          l_slew_rate_dq_dqs[i_port]));
                l_slew_rate_dq_dqs_in = l_slew_rate_dq_dqs[i_port];
                FAPI_INF("Calling Shmoo for finding Timing Margin:");

                if (shmoo_param_count)
                {
                    FAPI_TRY(set_attribute(i_target_mba));
                }

                FAPI_TRY(delay_shmoo(i_target_mba, i_port, l_shmoo_type_valid,
                                     &l_left_margin, &l_right_margin,
                                     l_slew_rate_dq_dqs_in));

                l_left_margin_slew_array[index] = l_left_margin;
                l_right_margin_slew_array[index] = l_right_margin;
                shmoo_param_count++;
            }
            else
            {
                l_left_margin_slew_array[index] = 0;
                l_right_margin_slew_array[index] = 0;
            }

            l_slew_rate_dq_dqs_shmoo[i_port]
                = (l_slew_rate_dq_dqs_shmoo[i_port] >> 1);
        } // end for index

        l_slew_rate_dq_dqs_nom_fc = l_slew_rate_dq_dqs_nom[i_port];
        find_best_margin(SLEW_RATE, l_left_margin_slew_array,
                         l_right_margin_slew_array, MAX_NUM_SLEW_RATES,
                         l_slew_rate_dq_dqs_nom_fc, count);

        FAPI_ASSERT(count < MAX_NUM_SLEW_RATES,
                    fapi2::CEN_CONFIG_SLEW_RATE_INVALID_INPUT(),
                    "Driver Imp new input(%d) out of bounds, (>= %d)",
                    count,
                    MAX_NUM_SLEW_RATES);

        FAPI_INF("Restoring the nominal values!");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS, i_target_mba, l_drv_imp_dq_dqs_nom));
        FAPI_TRY(config_drv_imp(i_target_mba, i_port, l_drv_imp_dq_dqs_nom[i_port]));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS, i_target_mba, l_slew_rate_dq_dqs_nom));
        FAPI_TRY(config_slew_rate(i_target_mba, i_port, l_slew_type,
                                  l_drv_imp_dq_dqs_nom[i_port],
                                  l_slew_rate_dq_dqs_nom[i_port]));

        FAPI_INF("Restoring mcbist setup attribute...");
        FAPI_TRY(reset_attribute(i_target_mba));
        FAPI_INF("++++ Slew Rate shmoo function executed successfully ++++");
    } // end else

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief perform wr vref shmoo on DDR4 dimms
/// @param[in] i_target_mba Centaur input MBA
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode wr_vref_shmoo_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    uint8_t max_ddr4_vrefs1 = 51;
    shmoo_type_t l_shmoo_type_valid = MCBIST; // Hard coded - Temporary
    fapi2::buffer<uint64_t> l_data_buffer_64;
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_MAX_RANKS[MAX_DIMM_PER_PORT] = {0};
    uint8_t l_SHMOO_NIBBLES = 20;
    uint32_t base_percent = 60000;
    uint32_t index_mul_print = 650;
    uint8_t l_attr_shmoo_test_type_u8 = 1;
    uint32_t vref_val_print = 0;
    uint8_t vrefdq_train_range[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t vrefdq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t vrefdq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint32_t vref_val = 0;
    uint8_t l_vref_num = 0;
    uint8_t i_port = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_attr_eff_dimm_type_u8));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, num_ranks_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target_mba, vrefdq_train_range));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));

    if(vrefdq_train_range[0][0][0] == 1)
    {
        base_percent = 45000;
    }

    l_MAX_RANKS[0] = num_ranks_per_dimm[0][0] + num_ranks_per_dimm[0][1];
    l_MAX_RANKS[1] = num_ranks_per_dimm[1][0] + num_ranks_per_dimm[1][1];

    if ( l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES )
    {
        l_SHMOO_NIBBLES = 20;
    }
    else
    {
        l_SHMOO_NIBBLES = 18;
    }

    FAPI_DBG(" +++  l_SHMOO_NIBBLES = %d +++ ", l_SHMOO_NIBBLES);
    ///// ddr4 vref //////
    FAPI_DBG("+++++++++++++++++++++++++++++++++++++++++++++ Patch - WR_VREF - Check Sanity only at 500 ddr4 +++++++++++++++++++++++++++");
    FAPI_TRY(delay_shmoo_ddr4(i_target_mba, i_port, l_shmoo_type_valid,
                              &l_left_margin, &l_right_margin,
                              vref_val));

    FAPI_DBG(" Setup and Sanity - Check disabled from now on..... Continuing .....");
    FAPI_TRY(set_attribute(i_target_mba));

    l_shmoo_type_valid = WR_EYE;
    l_attr_shmoo_test_type_u8 = 2;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));
    //Initialize all to zero

    for(l_vref_num = 0; l_vref_num < max_ddr4_vrefs1; l_vref_num++)
    {
        vref_val = l_vref_num;
        vref_val_print = base_percent + (l_vref_num * index_mul_print);

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        l_data_buffer_64.clearBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        FAPI_INF("\n After Clearing Refresh");

        for(uint8_t l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
        {
            for(uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
            {
                for(uint8_t l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; l_rank++)
                {
                    vrefdq_train_enable[l_port][l_dimm][l_rank] = 0x00; // disable vref train enable attr
                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target_mba, vrefdq_train_range));
        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba, vrefdq_train_enable));
        FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba));

        for(uint8_t l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
        {
            for(uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
            {
                for(uint8_t l_rank = 0; l_rank < l_MAX_RANKS[l_port]; l_rank++)
                {
                    vrefdq_train_value[l_port][l_dimm][l_rank] = vref_val;
                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba, vrefdq_train_value));

        FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba));

        FAPI_INF("The Vref value is %d .... The percent voltage bump = %d ", vref_val, vref_val_print);

        for(uint8_t l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
        {
            for(uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
            {
                for(uint8_t l_rank = 0; l_rank < l_MAX_RANKS[l_port]; l_rank++)
                {
                    vrefdq_train_enable[l_port][l_dimm][l_rank] = 0x01;
                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba, vrefdq_train_enable));
        FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba));

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        l_data_buffer_64.setBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

        FAPI_TRY(delay_shmoo_ddr4(i_target_mba, i_port, l_shmoo_type_valid,
                                  &l_left_margin, &l_right_margin,
                                  vref_val));

        FAPI_INF("Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d",
                 vref_val_print,
                 l_left_margin,
                 l_right_margin);
    }

    FAPI_INF("Restoring mcbist setup attribute...");
    FAPI_TRY(reset_attribute(i_target_mba));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Call mrs6 function until MR latch
/// @param[in] i_target_mba Centaur input mba
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode latch_mrs6_val(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{

    fapi2::buffer<uint64_t> l_data_buffer_64;
    uint8_t vrefdq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t latch_values[3] = {fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE, fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE};
    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
    l_data_buffer_64.clearBit<REFRESH_BIT>();
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

    for(uint8_t latch_val = 0; latch_val < 3; latch_val++)
    {
        for(uint8_t port = 0; port < MAX_PORTS_PER_MBA; port++)
        {
            for(uint8_t dimm = 0; dimm < MAX_DIMM_PER_PORT; dimm++)
            {
                for(uint8_t rank = 0; rank < 4; rank++)
                {
                    vrefdq_train_enable[port][dimm][rank] = latch_values[latch_val];
                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba, vrefdq_train_enable));
        FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba), " mrs_load Failed");
    }

    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
    l_data_buffer_64.setBit<REFRESH_BIT>();
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief set and latch new wr vref values
/// @param[in] i_target_mba Centaur input MBA
/// @param[in] i_vref_values the value to set for each rank
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode latch_wr_vref(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                const uint8_t (&i_vref_values)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM])
{
    constexpr uint8_t ENABLE_TRAINING = 0x01;
    constexpr uint8_t DISABLE_TRAINING = 0x00;

    fapi2::buffer<uint64_t> l_data_buffer_64;
    uint8_t l_vrefdq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t l_vrefdq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};

    // Turn off refresh
    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
    l_data_buffer_64.clearBit<REFRESH_BIT>();
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

    // Setup training attributes
    std::fill(&l_vrefdq_train_enable[0][0][0],
              &l_vrefdq_train_enable[0][0][0] + (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM),
              ENABLE_TRAINING);
    memcpy(&l_vrefdq_train_value[0][0][0], &i_vref_values[0][0][0],
           (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM));

    FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba, l_vrefdq_train_enable));
    FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba, l_vrefdq_train_value));

    // Setup and latch MRS6 to run training
    FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba), "%s mrs_load failed", mss::c_str(i_target_mba));
    FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba), "%s mrs_load failed", mss::c_str(i_target_mba));

    // Clear training enables
    std::fill(&l_vrefdq_train_enable[0][0][0],
              &l_vrefdq_train_enable[0][0][0] + (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM),
              DISABLE_TRAINING);

    FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba, l_vrefdq_train_enable));

    // ...and send them out
    FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba), "%s mrs_load failed", mss::c_str(i_target_mba));

    // Turn refresh back on
    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
    l_data_buffer_64.setBit<REFRESH_BIT>();
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief set average wr vref value on all ranks
/// @param[in] i_target_mba Centaur input MBA
/// @param[in] i_pda_nibble_table table of vref values from training
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_wr_vref_by_rank(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const uint32_t (
                                              &i_pda_nibble_table)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2])
{
    uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint32_t l_avg_best_vref = 0;
    uint8_t l_dimm_type = 0;
    uint32_t l_max_nibbles = 0;
    uint8_t l_vref_values[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, num_ranks_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimm_type));

    l_max_nibbles = (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? MAX_DRAMS_PER_RANK_X4 :
                    MAX_DRAMS_PER_RANK_X4_ISDIMM;

    // Calculate and set the Average V-Ref Value for each rank
    for(uint8_t l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
    {
        for(uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
        {
            for(uint8_t l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm]; l_rank_index++)
            {
                for(uint8_t l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                {
                    l_avg_best_vref += i_pda_nibble_table[l_port_index][l_dimm][l_rank_index][l_nibble_index][0];
                }

                l_avg_best_vref = l_avg_best_vref / l_max_nibbles;
                l_vref_values[l_port_index][l_dimm][l_rank_index] = l_avg_best_vref;
                FAPI_INF("%s Port %d Dimm %d Rank:%d Best Avg V-Ref = %d", mss::c_str(i_target_mba),
                         l_port_index, l_dimm, l_rank_index, l_avg_best_vref);
            }
        }
    }

    FAPI_TRY(latch_wr_vref(i_target_mba, l_vref_values));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set new wr vref values on a DRAM basis (PDA)
/// @param[in] i_target_mba Centaur input MBA
/// @param[in] i_odt_wr nominal write ODT settings
/// @param[in] i_pda_nibble_table table of vref values from training
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_wr_vref_by_dram(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const uint8_t (&i_odt_wr)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM],
                                      const uint32_t (
                                              &i_pda_nibble_table)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2])
{
    uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t dram_width = 0;
    std::vector<PDA_MRS_Storage> pda_enable;
    std::vector<PDA_MRS_Storage> pda_disable;
    uint32_t max_vref;
    uint8_t dram_num;
    fapi2::buffer<uint64_t> l_data_buffer_64;
    uint8_t l_dimm_type = 0;
    uint32_t l_max_nibbles = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, num_ranks_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, dram_width));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimm_type));

    l_max_nibbles = (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? MAX_DRAMS_PER_RANK_X4 :
                    MAX_DRAMS_PER_RANK_X4_ISDIMM;

    // Issue PDA commands with train enable 1 (enabled) for all DRAMs with good VREF values
    for(uint8_t l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
    {
        for(uint8_t l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
        {
            for(uint8_t l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
            {
                for(uint8_t l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                {
                    dram_num = l_nibble_index;
                    max_vref = i_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0];

                    // If we're x8 width, average the Vref for both nibbles together and update the DRAM index
                    if(dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8)
                    {
                        l_nibble_index++;
                        dram_num = dram_num / MAX_NIBBLES_PER_BYTE;
                        max_vref += i_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0];
                        max_vref = max_vref / MAX_NIBBLES_PER_BYTE;
                    }

                    FAPI_INF("%s Port %d Dimm %d Rank:%d Pda_Nibble: %d DRAM_num %d  V-ref:%d  Margin:%d", mss::c_str(i_target_mba),
                             l_port_index, l_dimm_index, l_rank_index, l_nibble_index, dram_num,
                             i_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0],
                             i_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1]);

                    // Push the PDA enable MRS commands onto the enable list
                    pda_enable.push_back(PDA_MRS_Storage(0x01, fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, dram_num, l_dimm_index,
                                                         l_rank_index, l_port_index, i_odt_wr));
                    FAPI_INF("%s PDA STRING (training enable): %d %s", mss::c_str(i_target_mba), pda_enable.size() - 1,
                             pda_enable[pda_enable.size() - 1].c_str());
                    pda_enable.push_back(PDA_MRS_Storage(max_vref, fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, dram_num, l_dimm_index,
                                                         l_rank_index, l_port_index, i_odt_wr));
                    FAPI_INF("%s PDA STRING (vref value): %d %s", mss::c_str(i_target_mba), pda_enable.size() - 1,
                             pda_enable[pda_enable.size() - 1].c_str());

                    // And the disable commands onto the disable list
                    pda_disable.push_back(PDA_MRS_Storage(0x00, fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, dram_num, l_dimm_index,
                                                          l_rank_index, l_port_index, i_odt_wr));
                    FAPI_INF("%s PDA STRING (training disable): %d %s", mss::c_str(i_target_mba), pda_disable.size() - 1,
                             pda_disable[pda_disable.size() - 1].c_str());
                    pda_disable.push_back(PDA_MRS_Storage(max_vref, fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, dram_num, l_dimm_index,
                                                          l_rank_index, l_port_index, i_odt_wr));
                    FAPI_INF("%s PDA STRING (vref value): %d %s", mss::c_str(i_target_mba), pda_disable.size() - 1,
                             pda_disable[pda_disable.size() - 1].c_str());
                }
            } //End of Rank Loop
        } //end of dimm loop
    } //End of Port Loop

    // Turn off refresh
    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
    l_data_buffer_64.clearBit<REFRESH_BIT>();
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

    FAPI_INF("%s RUNNING PDA FOR 1ST TIME", mss::c_str(i_target_mba));
    FAPI_TRY(mss_ddr4_run_pda((fapi2::Target<fapi2::TARGET_TYPE_MBA>&)i_target_mba, pda_enable));
    FAPI_INF("%s FINISHED RUNNING PDA FOR 1ST TIME", mss::c_str(i_target_mba));

    // Issue call to run PDA again (latching good value in train mode)
    FAPI_INF("%s RUNNING PDA FOR 2ND TIME", mss::c_str(i_target_mba));
    FAPI_TRY(mss_ddr4_run_pda((fapi2::Target<fapi2::TARGET_TYPE_MBA>&)i_target_mba, pda_enable));
    FAPI_INF("%s FINISHED RUNNING PDA FOR 2ND TIME", mss::c_str(i_target_mba));

    // Next issue PDA commands with train enable 0 (disabled) for all DRAMs
    FAPI_INF("%s RUNNING PDA FOR 3RD TIME", mss::c_str(i_target_mba));
    FAPI_TRY(mss_ddr4_run_pda((fapi2::Target<fapi2::TARGET_TYPE_MBA>&)i_target_mba, pda_disable));
    FAPI_INF("%s FINISHED RUNNING PDA FOR 3RD TIME", mss::c_str(i_target_mba));

    // Turn refresh back on
    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
    l_data_buffer_64.setBit<REFRESH_BIT>();
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set new wr vref values and return margins
/// @param[in] i_target_mba Centaur input MBA
/// @param[in] i_odt_wr nominal write ODT settings
/// @param[in] i_vref_values Vref values to test
/// @param[in,out] io_pda_nibble_table table of vref values from training
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode wr_vref_test_helper(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const uint8_t (&i_odt_wr)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM],
                                      const uint8_t (&i_vref_values)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4],
                                      uint32_t (&io_pda_nibble_table)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2])
{
    uint8_t l_dimm_type = 0;
    uint32_t l_max_nibbles = 0;
    uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    shmoo_type_t l_shmoo_type_valid = WR_EYE;
    uint32_t l_left_total_margin = 0;
    uint32_t l_right_total_margin = 0;

    // Set up the test point Vrefs and run a shmoo to get the margins
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, num_ranks_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimm_type));

    l_max_nibbles = (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? MAX_DRAMS_PER_RANK_X4 :
                    MAX_DRAMS_PER_RANK_X4_ISDIMM;

    for(uint8_t l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
    {
        for(uint8_t l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
        {
            for(uint8_t l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
            {
                for(uint8_t l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                {
                    io_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0] =
                        i_vref_values[l_port_index][l_dimm_index][l_rank_index][l_nibble_index];
                }
            }
        }
    }

    FAPI_TRY(set_wr_vref_by_dram(i_target_mba, i_odt_wr, io_pda_nibble_table));

    FAPI_TRY(delay_shmoo_ddr4_pda(i_target_mba, 0, l_shmoo_type_valid,
                                  &l_left_total_margin, &l_right_total_margin, 0, io_pda_nibble_table));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief search for best wr vref values by DRAM using ternary search algorithm
/// @param[in] i_target_mba Centaur input MBA
/// @param[in] i_odt_wr nominal write ODT settings
/// @param[in] io_pda_nibble_table table of best vref values
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode wr_vref_ternary_search(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        const uint8_t (&i_odt_wr)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM],
        uint32_t (&io_pda_nibble_table)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2])
{
    constexpr uint8_t MAX_VREF = 50;

    // Set the MCBIST end addresses to limit the duration of each delay_shmoo, and yield a low run-to-run variation
    uint64_t l_mcbist_address_config = 0x0000001ffc000000ull;

    uint8_t l_vpd_wr_vref_value[2] = {0};
    uint8_t l_nominal_vref = 0;
    uint8_t l_max_delta = 0;
    uint8_t l_min_vref = 0;
    uint8_t l_max_vref = 0;
    uint8_t l_starting_ticks_from_nominal = 0;
    uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_dimm_type = 0;
    uint32_t l_max_nibbles = 0;
    uint8_t l_attr_shmoo_test_type_u8 = fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_TEST_VALID_WR_EYE;
    bool l_search_complete = true;

    // Search boundaries
    uint8_t l_low_bound[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4] = {0};
    uint8_t l_high_bound[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4] = {0};

    // Test point
    uint8_t l_test_vref[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4] = {0};

    // Test results (margins)
    uint32_t l_pda_table[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2] = {0};

    // Test result storage (key is dram_key (port, dimm, rank, nibble), data is a map of vrefs to the margins found so far)
    std::map<dram_key, std::map<uint8_t, uint32_t>> l_results;

    for(uint8_t l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
    {
        for(uint8_t l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
        {
            for(uint8_t l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
            {
                for(uint8_t l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                {
                    // Insert an empty map into l_results for each DRAM
                    const dram_key l_dram = {l_port_index, l_dimm_index, l_rank_index, l_nibble_index};
                    l_results.insert(std::make_pair(l_dram, std::map<uint8_t, uint32_t>()));
                }
            }
        }
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, num_ranks_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_WRDDR4_VREF, i_target_mba, l_vpd_wr_vref_value));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VREF_CAL_DELTA_FROM_NOMINAL, i_target_mba, l_starting_ticks_from_nominal));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimm_type));

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_END_ADDR, i_target_mba, l_mcbist_address_config));

    // Make sure we do the MCBIST setup the fist time through so we get our custom MCBIST end address
    FAPI_TRY(reset_attribute(i_target_mba));

    l_max_nibbles = (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? MAX_DRAMS_PER_RANK_X4 :
                    MAX_DRAMS_PER_RANK_X4_ISDIMM;

    // Make sure our initial settings are ok
    l_nominal_vref = l_vpd_wr_vref_value[0];
    l_max_delta = std::min<uint8_t>((MAX_VREF - l_nominal_vref), l_nominal_vref);
    FAPI_ASSERT((l_starting_ticks_from_nominal > 0) &&
                (l_nominal_vref - l_starting_ticks_from_nominal >= 0) &&
                (l_nominal_vref + l_starting_ticks_from_nominal <= MAX_VREF),
                fapi2::CEN_MSS_WR_VREF_CAL_DELTA_INVALID_VALUE().
                set_MBA_TARGET(i_target_mba).
                set_DELTA_VALUE(l_starting_ticks_from_nominal).
                set_NOMINAL_VREF(l_nominal_vref).
                set_DELTA_MAX(l_max_delta),
                "%s Invalid value supplied for ATTR_CEN_MSS_VREF_CAL_DELTA_FROM_NOMINAL (%d). Nominal Vref is %d, so max delta is %d",
                mss::c_str(i_target_mba),
                l_starting_ticks_from_nominal,
                l_nominal_vref,
                l_max_delta);

    // Initial settings: start at the given delta from nominal
    l_min_vref = l_nominal_vref - l_starting_ticks_from_nominal;
    l_max_vref = l_nominal_vref + l_starting_ticks_from_nominal;

    std::fill(&l_low_bound[0][0][0][0],
              &l_low_bound[0][0][0][0] + (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM * l_max_nibbles),
              l_min_vref);
    std::fill(&l_high_bound[0][0][0][0],
              &l_high_bound[0][0][0][0] + (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM * l_max_nibbles),
              l_max_vref);

    // Continue until we've converged the search range to the minumum boundary size
    do
    {
        // Start with search complete true so &= operator switches us to false if any DRAM is not complete
        l_search_complete = true;

        for(uint8_t l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
        {
            for(uint8_t l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
            {
                for(uint8_t l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
                {
                    for(uint8_t l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                    {
                        // The helper function will do the following:
                        // 1) Step min or max boundary inward (if both high and low results are available)
                        // 2) Give us the next Vref to test
                        // 3) Tell us if a given DRAM's search is complete
                        // Note: searches on all DRAMs may not complete at the same time due to skipping tests we've already done
                        bool l_dram_complete = false;

                        const dram_key l_dram = {l_port_index, l_dimm_index, l_rank_index, l_nibble_index};
                        FAPI_TRY(ternary_search_helper(l_results[l_dram],
                                                       l_low_bound[l_port_index][l_dimm_index][l_rank_index][l_nibble_index],
                                                       l_high_bound[l_port_index][l_dimm_index][l_rank_index][l_nibble_index],
                                                       l_test_vref[l_port_index][l_dimm_index][l_rank_index][l_nibble_index],
                                                       l_dram_complete));
                        l_search_complete &= l_dram_complete;
                    }
                }
            }
        }

        // Check margins at next test point
        FAPI_TRY(wr_vref_test_helper(i_target_mba, i_odt_wr, l_test_vref, l_pda_table));

        // Print them and store them in our results map
        for(uint8_t l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
        {
            for(uint8_t l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
            {
                for(uint8_t l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
                {
                    for(uint8_t l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                    {
                        FAPI_INF("%s Port %d Dimm %d Rank:%d Nibble:%d Vref:%d margin=%d",
                                 mss::c_str(i_target_mba), l_port_index, l_dimm_index, l_rank_index, l_nibble_index,
                                 l_test_vref[l_port_index][l_dimm_index][l_rank_index][l_nibble_index],
                                 l_pda_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1]);

                        const dram_key l_dram = {l_port_index, l_dimm_index, l_rank_index, l_nibble_index};
                        auto l_result = std::make_pair(l_test_vref[l_port_index][l_dimm_index][l_rank_index][l_nibble_index],
                                                       l_pda_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1]);
                        l_results[l_dram].insert(l_result);
                    }
                }
            }
        }

        // Turn the attribute back on so we don't do the MCBIST setup after the fist time through
        FAPI_TRY(set_attribute(i_target_mba));
    }
    while (!l_search_complete);

    // Now that we've converged to the minimal search range, set the best vref for each nibble
    for(uint8_t l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
    {
        for(uint8_t l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
        {
            for(uint8_t l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
            {
                for(uint8_t l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                {
                    // The best vref is set in the next test point, so copy that into the table
                    io_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0] =
                        l_test_vref[l_port_index][l_dimm_index][l_rank_index][l_nibble_index];

                    // Rather than running another shmoo, copy the margins in from the last shmoo
                    // which was tested at either the best vref or one tick away from it
                    io_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1] =
                        l_pda_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1];
                }
            }
        }
    }

    FAPI_TRY(set_wr_vref_by_dram(i_target_mba, i_odt_wr, io_pda_nibble_table));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief perform binary wr vref shmoo on DDR4 dimms
/// @param[in] i_target_mba Centaur input MBA
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode wr_vref_shmoo_ddr4_bin(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    shmoo_type_t l_shmoo_type_valid = MCBIST;
    fapi2::buffer<uint64_t> l_data_buffer_64;
    fapi2::buffer<uint64_t> refresh_reg;
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t vrefdq_train_range[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t odt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint32_t total_val = 0;
    uint32_t last_total = 0;
    uint32_t base_percent = 60000;
    // Port,Dimm,Rank,Nibble,Data[0] = vref data[1] = total margin
    uint32_t pda_nibble_table[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2] = {0};
    uint32_t best_pda_nibble_table[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2] = {0};
    uint8_t cal_control = 0;
    ///// ddr4 vref //////
    uint8_t vrefdq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint8_t vrefdq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
    uint32_t vref_val = 0;
    uint8_t l_port = 0;
    uint8_t l_port_index = 0;
    uint8_t l_dimm_index = 0;
    uint8_t l_rank_index = 0;
    uint8_t l_nibble_index = 0;
    uint8_t l_vref_mid = 0;
    uint8_t imax =      39;
    uint8_t imin = 13;
    uint8_t last_known_vref = 0;
    uint8_t l_loop_count = 0;
    uint8_t dram_width = 0;
    uint32_t index_mul_print = 650;
    uint8_t l_attr_shmoo_test_type_u8 = 1;
    uint32_t vref_val_print = 0;
    uint8_t vpd_wr_vref_value[2] = {0};
    const auto l_target_centaur1 = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
    uint32_t l_max_nibbles = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, dram_width));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_attr_eff_dimm_type_u8));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, num_ranks_per_dimm));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target_mba, vrefdq_train_range));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_WRDDR4_VREF, i_target_mba, vpd_wr_vref_value));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VREF_CAL_CNTL, l_target_centaur1, cal_control));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_WR, i_target_mba, odt_wr));
    //FAPI_INF("++++++++++++++ATTR_CEN_MSS_VREF_CAL_CNTL = %d +++++++++++++++++++++++++++",cal_control);

    if(vrefdq_train_range[0][0][0] == 1)
    {
        base_percent = 45;
    }

    l_max_nibbles = (l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                    ? MAX_DRAMS_PER_RANK_X4
                    : MAX_DRAMS_PER_RANK_X4_ISDIMM;

    FAPI_INF("%s Setting MCBIST DONE bit MASK as FW reports FIR bits!...", mss::c_str(i_target_mba));
    //Workaround MCBIST MASK Bit as FW reports FIR bits --- > SET
    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBSPAMSKQ, l_data_buffer_64));
    FAPI_TRY(l_data_buffer_64.setBit(10), "Buffer error in function wr_vref_shmoo_ddr4_bin Workaround MCBIST MASK Bit");


    FAPI_INF("%s +++++++++++++++++++++++++++++++++++++++++++++ WR_VREF - Check Sanity only MCBIST +++++++++++++++++++++++++++",
             mss::c_str(i_target_mba));
    FAPI_TRY(delay_shmoo_ddr4_pda(i_target_mba, l_port, l_shmoo_type_valid,
                                  &l_left_margin, &l_right_margin,
                                  vref_val, pda_nibble_table));

    FAPI_INF("%s Setup and Sanity - Check disabled from now on..... Continuing .....", mss::c_str(i_target_mba));
    FAPI_TRY(set_attribute(i_target_mba));

    if(cal_control == fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_BOX)
    {
        constexpr uint8_t WR_VREF_RANGE_MAX = 0x32;
        constexpr uint8_t WR_VREF_RANGE_MIN = 0x00;

        l_shmoo_type_valid = BOX;
        FAPI_INF("%s Running box shmoo!!!", mss::c_str(i_target_mba));
        l_attr_shmoo_test_type_u8 = fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_TEST_VALID_BOX;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba, vrefdq_train_value));
        uint8_t vrefdq_train_value_plus[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t vrefdq_train_value_minus[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t vref_train_step_size = 0;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_MRW_WR_VREF_CHECK_VREF_STEP_SIZE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                vref_train_step_size));

        //sets up values
        for(l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++) //Port
        {
            for(l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++) //Max dimms
            {
                for(l_rank_index = 0; l_rank_index < MAX_RANKS_PER_DIMM; l_rank_index++) //Ranks
                {
                    //sets up +5%
                    vrefdq_train_value_plus[l_port_index][l_dimm_index][l_rank_index] =
                        vrefdq_train_value[l_port_index][l_dimm_index][l_rank_index] + vref_train_step_size;

                    //if over the max, then set to max val
                    if(vrefdq_train_value_plus[l_port_index][l_dimm_index][l_rank_index] > WR_VREF_RANGE_MAX)
                    {
                        vrefdq_train_value_plus[l_port_index][l_dimm_index][l_rank_index] = WR_VREF_RANGE_MAX;
                    }

                    //sets up -5%
                    if(vrefdq_train_value[l_port_index][l_dimm_index][l_rank_index] < vref_train_step_size)
                    {
                        vrefdq_train_value_minus[l_port_index][l_dimm_index][l_rank_index] = WR_VREF_RANGE_MIN;
                    }
                    else
                    {
                        vrefdq_train_value_minus[l_port_index][l_dimm_index][l_rank_index] =
                            vrefdq_train_value[l_port_index][l_dimm_index][l_rank_index] - vref_train_step_size;
                    }
                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba, vrefdq_train_value_minus));
        FAPI_TRY(latch_mrs6_val(i_target_mba));

        //should run MCBIST -% VREF +/-X ticks write delay
        FAPI_TRY(delay_shmoo(i_target_mba, l_port, l_shmoo_type_valid,
                             &l_left_margin, &l_right_margin,
                             (uint32_t)vref_train_step_size));
        FAPI_INF("%s found a left margin %lu and a right margin %lu at +VREF %u", mss::c_str(i_target_mba), l_left_margin,
                 l_right_margin, vref_train_step_size);

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba, vrefdq_train_value_plus));
        FAPI_TRY(latch_mrs6_val(i_target_mba));

        //should run MCBIST +% VREF +/-X ticks write delay
        FAPI_TRY(delay_shmoo(i_target_mba, l_port, l_shmoo_type_valid,
                             &l_left_margin, &l_right_margin,
                             (uint32_t)(0xff - vref_train_step_size)));
        FAPI_INF("%s found a left margin %lu and a right margin %lu at -VREF", mss::c_str(i_target_mba), l_left_margin,
                 l_right_margin);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba, vrefdq_train_value));
        FAPI_TRY(latch_mrs6_val(i_target_mba));
        FAPI_INF("%s finished with the box shmoo", mss::c_str(i_target_mba));

    }

    else if (cal_control == fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_TERNARY)
    {
        // Perform the shmoo search algorithm
        FAPI_TRY(wr_vref_ternary_search(i_target_mba, odt_wr, pda_nibble_table));

        // Report final Vrefs
        for(l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
        {
            for(l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
            {
                for(l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
                {
                    for(l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                    {
                        vref_val_print = base_percent +
                                         (pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0] * index_mul_print);
                        FAPI_INF("%s: *** Final results from ternary shmoo: port%d, dimm%d, rank%d, nibble%d: Best V-Ref - %d - %d; Total Window = %d",
                                 mss::c_str(i_target_mba), l_port_index, l_dimm_index, l_rank_index, l_nibble_index,
                                 pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0], vref_val_print,
                                 pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1]);
                    }
                }
            }
        }
    } // end of VREF_CAL_CNTL_BINARY (P9)

    // P8 algorithms
    else if ((cal_control == fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_P8_DRAM) ||
             (cal_control == fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_P8_RANK))
    {
        l_shmoo_type_valid = WR_EYE;
        l_attr_shmoo_test_type_u8 = fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_TEST_VALID_WR_EYE;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));

        //Initialise All to Zero [MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]
        for(l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++) // port
        {
            for(l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++) //Dimm
            {
                for(l_rank_index = 0; l_rank_index < MAX_RANKS_PER_DIMM; l_rank_index++) //Rank
                {
                    for(l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++) //Nibble
                    {
                        pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0] = 0;  //  Index 0 Are V-refs
                        pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1] = 0;   // Index 1 are Total Margin Values
                        best_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0] = 0;   //  Index 0 Are V-refs
                        best_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1] =
                            0;    // Index 1 are Total Margin Values
                    }
                }
            }
        }

        while(imax >= imin)
        {
            uint8_t l_vref_values[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};

            if(l_loop_count == 0)
            {
                l_vref_mid = imin;
            }
            else
            {
                l_vref_mid = (imax + imin) / 2;
            }

            vref_val = l_vref_mid;
            vref_val_print = base_percent + (l_vref_mid * index_mul_print);
            FAPI_INF("%sThe Vref value is = %d; The percent voltage bump = %d ", mss::c_str(i_target_mba), vref_val,
                     vref_val_print);

            std::fill(&l_vref_values[0][0][0],
                      &l_vref_values[0][0][0] + (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM),
                      vref_val);

            FAPI_TRY(latch_wr_vref(i_target_mba, l_vref_values));

            FAPI_TRY(delay_shmoo_ddr4_pda(i_target_mba, l_port, l_shmoo_type_valid, &l_left_margin, &l_right_margin, vref_val,
                                          pda_nibble_table));

            total_val = l_right_margin + l_left_margin;
            FAPI_INF("%s: Preet2 - %d ; Wr Vref = %d ; Min Setup time = %d; Min Hold time = %d and Total = %d",
                     mss::c_str(i_target_mba), vref_val, vref_val_print, l_left_margin, l_right_margin, total_val);

            if(total_val > last_total)
            {
                last_known_vref = vref_val;
                last_total = total_val;

                if(l_loop_count != 0)
                {
                    imin = l_vref_mid + 1;
                }
            }
            else
            {
                imax = l_vref_mid - 1;
            }

            l_loop_count ++;

            for(l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
            {
                for(l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
                {
                    for(l_rank_index = 0; l_rank_index < num_ranks_per_dimm[l_port_index][l_dimm_index]; l_rank_index++)
                    {
                        for(l_nibble_index = 0; l_nibble_index < l_max_nibbles; l_nibble_index++)
                        {
                            if (best_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1] <
                                pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1])
                            {
                                best_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1] =
                                    pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][1];
                                best_pda_nibble_table[l_port_index][l_dimm_index][l_rank_index][l_nibble_index][0] = vref_val;
                            }
                        }
                    } //Rank Loop
                } //dimm loop
            } //Port loop
        } //end of While


        vref_val_print = base_percent + (last_known_vref * index_mul_print);
        FAPI_INF("%s: Best V-Ref - %d - %d  ; Total Window = %d", mss::c_str(i_target_mba), last_known_vref, vref_val_print,
                 last_total);
        // What do we do Once we know best V-Ref

        FAPI_TRY(fapi2::getScom( i_target_mba,  CEN_MBA_MBAREF0Q,  refresh_reg));
        refresh_reg.clearBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom( i_target_mba,  CEN_MBA_MBAREF0Q,  refresh_reg));

        if(cal_control == fapi2::ENUM_ATTR_CEN_MSS_VREF_CAL_CNTL_P8_RANK)
        {
            FAPI_INF("%s CAL_CONTROL in RANK_Wise Mode!! ", mss::c_str(i_target_mba));
            FAPI_TRY(set_wr_vref_by_rank(i_target_mba, best_pda_nibble_table));
        }
        else
        {
            FAPI_TRY(set_wr_vref_by_dram(i_target_mba, odt_wr, best_pda_nibble_table));
        }

        //turn on refresh then exit
        FAPI_TRY(fapi2::getScom( i_target_mba, CEN_MBA_MBAREF0Q, refresh_reg));
        refresh_reg.setBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom( i_target_mba, CEN_MBA_MBAREF0Q, refresh_reg));

    } // end of P8 algorithms

    else     //Skipping Shmoos ... Writing VPD data directly

    {
        vref_val_print = base_percent + (vpd_wr_vref_value[0] * index_mul_print);
        FAPI_INF("%s The Vref value is from VPD = %d; The  Voltage bump = %d ", mss::c_str(i_target_mba), vpd_wr_vref_value[0],
                 vref_val_print);

        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        l_data_buffer_64.clearBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        //FAPI_INF("\n After Clearing Refresh");

        for(l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
        {
            for(l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
            {
                for(l_rank_index = 0; l_rank_index < MAX_RANKS_PER_DIMM; l_rank_index++)
                {

                    vrefdq_train_enable[l_port_index][l_dimm_index][l_rank_index] = 0x01;

                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target_mba, vrefdq_train_range));
        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba, vrefdq_train_enable));
        FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba), "mrs_load failed");

        for(l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++) //Port
        {
            for(l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++) //Max dimms
            {
                for(l_rank_index = 0; l_rank_index < MAX_RANKS_PER_DIMM; l_rank_index++) //Ranks
                {

                    vrefdq_train_value[l_port_index][l_dimm_index][l_rank_index] = vpd_wr_vref_value[0];

                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba, vrefdq_train_value));
        FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba), "mrs_load failed");

        for(l_port_index = 0; l_port_index < MAX_PORTS_PER_MBA; l_port_index++)
        {
            for(l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; l_dimm_index++)
            {
                for(l_rank_index = 0; l_rank_index < MAX_RANKS_PER_DIMM; l_rank_index++)
                {

                    vrefdq_train_enable[l_port_index][l_dimm_index][l_rank_index] = 0x00;

                }
            }
        }

        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba, vrefdq_train_enable));
        FAPI_TRY(p9c_mss_mrs6_DDR4(i_target_mba), "mrs_load failed");
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));
        l_data_buffer_64.setBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_data_buffer_64));

    }

    //Workaround MCBIST MASK Bit as FW reports FIR bits --- > CLEAR
    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBSPAMSKQ, l_data_buffer_64));
    l_data_buffer_64.clearBit<10>();

    FAPI_INF("Restoring mcbist setup attribute...");
    FAPI_TRY(reset_attribute(i_target_mba));
//Read the write vref attributes
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Receiver impedance shmoo function varies 9 values
/// @param[in] i_target_mba Centaur input mba
/// @param[in] i_port Centaur input port
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode rcv_imp_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                const uint8_t i_port)
{
    uint8_t l_rcv_imp_dq_dqs[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_rcv_imp_dq_dqs_nom[MAX_PORTS_PER_MBA] = {0};
    uint8_t l_rcv_imp_dq_dqs_nom_fc = 0;
    uint8_t l_rcv_imp_dq_dqs_in = 0;
    uint32_t l_rcv_imp_dq_dqs_shmoo[MAX_PORTS_PER_MBA] = {0};
    uint8_t index = 0;
    uint8_t count  = 0;
    uint8_t shmoo_param_count = 0;
    const shmoo_type_t l_shmoo_type_valid = RD_EYE;   //Hard coded since no other shmoo is applicable - Temporary

    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_left_margin_rcv_imp_array[MAX_RCV_IMP] = {0};
    uint32_t l_right_margin_rcv_imp_array[MAX_RCV_IMP] = {0};

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS, i_target_mba, l_rcv_imp_dq_dqs_nom));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, i_target_mba, l_rcv_imp_dq_dqs_shmoo));

    FAPI_INF("+++++++++++++++++RECIVER IMP Read Shmoo Attributes values+++++++++++++++");
    FAPI_INF("CEN_RCV_IMP_DQ_DQS[0]  = %d , CEN_RCV_IMP_DQ_DQS[1]  = %d on %s",
             l_rcv_imp_dq_dqs_nom[0],
             l_rcv_imp_dq_dqs_nom[1],
             mss::c_str(i_target_mba));
    FAPI_INF("CEN_RCV_IMP_DQ_DQS_SHMOO[0] = [%d], CEN_RCV_IMP_DQ_DQS_SHMOO[1] = [%d], on %s",
             l_rcv_imp_dq_dqs_shmoo[0],
             l_rcv_imp_dq_dqs_shmoo[1],
             mss::c_str(i_target_mba));
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    if (l_rcv_imp_dq_dqs_shmoo[i_port] == 0)
    {
        FAPI_INF("FAST Shmoo Mode: This function will not change any Write DRAM VREF settings");
    }
    else
    {
        for (index = 0; index < MAX_RCV_IMP; index += 1)
        {
            if ((l_rcv_imp_dq_dqs_shmoo[i_port] & MASK) == 1)
            {
                l_rcv_imp_dq_dqs[i_port] = rcv_imp_array[index];
                FAPI_INF("Current Receiver Impedance: %d Ohms ",
                         rcv_imp_array[index]);
                FAPI_INF("Configuring Receiver impedance registers:");
                FAPI_TRY(config_rcv_imp(i_target_mba, i_port,
                                        l_rcv_imp_dq_dqs[i_port]));
                l_rcv_imp_dq_dqs_in = l_rcv_imp_dq_dqs[i_port];

                if (shmoo_param_count)
                {
                    FAPI_TRY(set_attribute(i_target_mba));
                }

                FAPI_TRY(delay_shmoo(i_target_mba, i_port, l_shmoo_type_valid,
                                     &l_left_margin, &l_right_margin,
                                     l_rcv_imp_dq_dqs_in));
                l_left_margin_rcv_imp_array[index] = l_left_margin;
                l_right_margin_rcv_imp_array[index] = l_right_margin;
                shmoo_param_count++;
            }
            else
            {
                l_left_margin_rcv_imp_array[index] = 0;
                l_right_margin_rcv_imp_array[index] = 0;
            }

            l_rcv_imp_dq_dqs_shmoo[i_port] = (l_rcv_imp_dq_dqs_shmoo[i_port] >> 1);
        }

        l_rcv_imp_dq_dqs_nom_fc = l_rcv_imp_dq_dqs_nom[i_port];
        find_best_margin(RCV_IMP, l_left_margin_rcv_imp_array,
                         l_right_margin_rcv_imp_array, MAX_RCV_IMP,
                         l_rcv_imp_dq_dqs_nom_fc, count);

        if(count >= MAX_RCV_IMP)
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_RCV_IMP_SHMOO_INVALID_MARGIN_DATA(),
                        "Receiver Imp new input(%d) out of bounds, (>= %d)",
                        count, MAX_RCV_IMP);
        }
        else
        {
            FAPI_INF("Restoring the nominal values!");
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS, i_target_mba,
                                   l_rcv_imp_dq_dqs_nom));
            FAPI_TRY(config_rcv_imp(i_target_mba, i_port,
                                    l_rcv_imp_dq_dqs_nom[i_port]));
        }

        FAPI_TRY(reset_attribute(i_target_mba));
        FAPI_INF("++++ Receiver Impdeance Shmoo function executed successfully ++++");
    }

fapi_try_exit:
    return fapi2::current_err;

}

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
fapi2::ReturnCode delay_shmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                              const uint8_t i_port,
                              const shmoo_type_t i_shmoo_type_valid,
                              uint32_t* o_left_margin,
                              uint32_t* o_right_margin,
                              const uint32_t i_shmoo_param)
{
    //need to use fapi allocator to avoid memory fragmentation issues in Hostboot
    //  then use an in-place new to put the object in the pre-allocated memory
    void* l_mallocptr = malloc(sizeof(generic_shmoo));
    generic_shmoo* l_pShmoo = new (l_mallocptr) generic_shmoo(i_port, i_shmoo_type_valid, SEQ_LIN);
    FAPI_TRY(l_pShmoo->run(i_target_mba, o_left_margin, o_right_margin, i_shmoo_param), "Delay Shmoo Function is Failed");
    free(l_mallocptr);
    FAPI_TRY(mcb_reset_error_flags(i_target_mba));

fapi_try_exit:
    return fapi2::current_err;
}

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
fapi2::ReturnCode delay_shmoo_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                   const uint8_t i_port,
                                   const shmoo_type_t i_shmoo_type_valid,
                                   uint32_t* o_left_margin,
                                   uint32_t* o_right_margin,
                                   const uint32_t i_shmoo_param)
{

    //need to use fapi allocator to avoid memory fragmentation issues in Hostboot
    //  then use an in-place new to put the object in the pre-allocated memory
    void* l_mallocptr = malloc(sizeof(generic_shmoo));
    generic_shmoo* l_pShmoo = new (l_mallocptr) generic_shmoo(i_port, i_shmoo_type_valid, SEQ_LIN);

    FAPI_TRY(l_pShmoo->run(i_target_mba, o_left_margin, o_right_margin, i_shmoo_param));

    free(l_mallocptr);
    FAPI_TRY(mcb_reset_error_flags(i_target_mba));
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Calls Delay shmoo function varies delay values of each dq and returns timing margin
/// @param[in] i_target_mba Centaur input mba
/// @param[in] i_port Centaur input port
/// @param[in] i_shmoo_type_valid Shmoo type MCBIST, WR_EYE, RD_EYE, WR_DQS, RD_DQS
/// @param[out] o_left_margin  returns left margin delay (setup) in ps
/// @param[out] o_right_margin returns right margin delay (hold) in ps
/// @param[in] i_shmoo_param Shmoo
/// @param[in] i_pda_nibble_table table of Vref values and measured margins (hence the last [2] array parameter)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode delay_shmoo_ddr4_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, uint8_t i_port,
                                       shmoo_type_t i_shmoo_type_valid,
                                       uint32_t* o_left_margin,
                                       uint32_t* o_right_margin,
                                       uint32_t i_shmoo_param,
                                       uint32_t (&i_pda_nibble_table)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][MAX_DRAMS_PER_RANK_X4][2])
{

    //need to use fapi allocator to avoid memory fragmentation issues in Hostboot
    //  then use an in-place new to put the object in the pre-allocated memory
    void* l_mallocptr = malloc(sizeof(generic_shmoo));
    generic_shmoo* l_pShmoo = new (l_mallocptr) generic_shmoo(i_port, i_shmoo_type_valid, SEQ_LIN);

    FAPI_TRY(l_pShmoo->run(i_target_mba, o_left_margin, o_right_margin, i_shmoo_param));

    FAPI_TRY(l_pShmoo->get_nibble_pda(i_target_mba, i_pda_nibble_table));

    free(l_mallocptr);
    FAPI_TRY(mcb_reset_error_flags(i_target_mba));
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Sets the attribute ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL used  by all functions
/// @param[in] i_target_mba Centaur input mba
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode set_attribute(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    uint8_t l_mcbist_setup_multiple_set = 1;  //Hard coded it wont change
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL, i_target_mba, l_mcbist_setup_multiple_set));
fapi_try_exit:
    return fapi2::current_err;
}

///
///@brief Read VREF shmoo (ddr4 dimms)
///@param[in] i_target_mba Centaur input mba
///@return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode rd_vref_shmoo_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    shmoo_type_t l_shmoo_type_valid = MCBIST; // Hard coded - Temporary
    fapi2::buffer<uint64_t> l_data_buffer_64;
    fapi2::buffer<uint64_t> data_buffer;
    uint32_t l_rd_cen_vref_shmoo[MAX_PORTS_PER_MBA] = {0};
    uint32_t l_left_margin = 0;
    uint32_t l_right_margin = 0;
    uint32_t l_rd_cen_vref_in = 0;
    uint8_t l_attr_shmoo_test_type_u8 = 1;
    uint8_t i_port = 0;
    uint32_t diff_value = 1375;
    uint32_t base = 70000;
    uint32_t vref_value_print = 0;
    uint32_t l_left_margin_rd_vref_array[16] = {0};
    uint32_t l_right_margin_rd_vref_array[16] = {0};
    uint8_t l_vref_num = 0;
    uint8_t l_vref_num_tmp = 0;

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - Preet - RD_VREF - Check Sanity only - DDR4 +++++++++++++++++++++++++++");
    FAPI_TRY(delay_shmoo(i_target_mba, i_port, l_shmoo_type_valid,
                         &l_left_margin, &l_right_margin,
                         l_rd_cen_vref_in));
    FAPI_INF(" Setup and Sanity - Check disabled from now on..... Continuing .....");
    FAPI_TRY(set_attribute(i_target_mba));

    l_shmoo_type_valid = RD_EYE;
    l_attr_shmoo_test_type_u8 = 4;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba, l_attr_shmoo_test_type_u8));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_RD_VREF_SCHMOO, i_target_mba, l_rd_cen_vref_shmoo));


    FAPI_INF("CEN_RD_VREF_SHMOO[0] = [%x], CEN_RD_VREF_SHMOO[1] = [%x] on %s",
             l_rd_cen_vref_shmoo[0],
             l_rd_cen_vref_shmoo[1],
             mss::c_str(i_target_mba));
    FAPI_INF("+++++++++++++++++++++++++++++++++++++++++++++ Patch - Preet - RD_VREF DDR4 +++++++++++++++++++++++++++");

    //For DDR3 - DDR4 Range
    if (l_rd_cen_vref_shmoo[i_port] == 1)
    {
        FAPI_INF("\n Testing Range - DDR3 to DDR4 - Vrefs");
        base = 50000;
    }
    else
    {
        FAPI_INF("\n Testing Range - DDR4 Range Only - Vrefs");

        for(l_vref_num_tmp = 8; l_vref_num_tmp > 0 ; l_vref_num_tmp--)
        {
            l_vref_num = l_vref_num_tmp - 1;
            l_rd_cen_vref_in = l_vref_num;
            vref_value_print = base - (l_vref_num * diff_value);
            FAPI_INF("Current Vref value is %d", vref_value_print);
            FAPI_INF("Configuring Read Vref Registers:");
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_0,
                                    data_buffer));
            FAPI_TRY(data_buffer.insertFromRight(l_rd_cen_vref_in, 56, 4), "config_rd_vref: Error in setting up buffer");
            data_buffer.setBit<60>();
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_3,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_4,
                                    data_buffer));
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_0,
                                    data_buffer));
            FAPI_TRY(data_buffer.insertFromRight(l_rd_cen_vref_in, 56, 4), "config_rd_vref: Error in setting up buffer ");
            data_buffer.setBit<60>();
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_3,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_4,
                                    data_buffer));

            FAPI_TRY(delay_shmoo(i_target_mba, i_port, l_shmoo_type_valid, &l_left_margin, &l_right_margin, vref_value_print));
            l_left_margin_rd_vref_array[l_vref_num] = l_left_margin;
            l_right_margin_rd_vref_array[l_vref_num] = l_right_margin;

            FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d", vref_value_print,
                     l_left_margin_rd_vref_array[l_vref_num], l_right_margin_rd_vref_array[l_vref_num]);
        }

        // For base + values

        for(l_vref_num = 8; l_vref_num < 16; l_vref_num++)
        {

            l_rd_cen_vref_in = l_vref_num;
            vref_value_print = base + ((l_vref_num - 7) * diff_value);
            FAPI_INF("Current Vref value is %d", vref_value_print);
            FAPI_INF("Configuring Read Vref Registers:");
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_0,
                                    data_buffer));
            FAPI_TRY(data_buffer.insertFromRight(l_rd_cen_vref_in, 56, 4), "config_rd_vref: Error in setting up buffer ");
            data_buffer.setBit<60>();
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_3,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_4,
                                    data_buffer));
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_0,
                                    data_buffer));
            FAPI_TRY(data_buffer.insertFromRight(l_rd_cen_vref_in, 56, 4), "config_rd_vref: Error in setting up buffer ");
            data_buffer.setBit<60>();
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_3,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_4,
                                    data_buffer));

            FAPI_TRY(delay_shmoo(i_target_mba, i_port, l_shmoo_type_valid, &l_left_margin, &l_right_margin, vref_value_print));
            l_left_margin_rd_vref_array[l_vref_num] = l_left_margin;
            l_right_margin_rd_vref_array[l_vref_num] = l_right_margin;

            FAPI_INF("Read Vref = %d ; Min Setup time = %d; Min Hold time = %d", vref_value_print,
                     l_left_margin_rd_vref_array[l_vref_num], l_right_margin_rd_vref_array[l_vref_num]);
        }


    }

    FAPI_INF("++++ Centaur Read Vref Shmoo function DDR4 done ! ++++");
    FAPI_INF("Restoring mcbist setup attribute...");
    FAPI_TRY(reset_attribute(i_target_mba));
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Sets the attribute ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL used by all functions
/// @param[in] i_target_mba Centaur input mba
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode reset_attribute(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    uint8_t l_mcbist_setup_multiple_reset = 0; //Hard coded it wont change
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL, i_target_mba, l_mcbist_setup_multiple_reset));
fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Finds better timing margin and returns the index
/// @param[in] i_shmoo_param_valid PARAM_NONE, DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP
/// @param[in] i_left[] timing margin array
/// @param[in] i_right[] timing margin array
/// @param[in] i_max  Max enum value of shmoo param
/// @param[in] i_param_nom selected shmoo parameter (DRV_IMP, SLEW_RATE, WR_VREF, RD_VREF, RCV_IMP)
/// @param[in] o_index returns index
///
void find_best_margin(const shmoo_param i_shmoo_param_valid,
                      const uint32_t i_left[],
                      const uint32_t i_right[],
                      const uint8_t i_max,
                      const uint32_t i_param_nom,
                      uint8_t& o_index)
{
    uint32_t left_margin = 0;
    uint32_t right_margin = 0;
    uint32_t left_margin_nom = 0;
    uint32_t right_margin_nom = 0;
    uint32_t diff_margin_nom = 0;
    uint32_t diff_margin = 0;
    uint8_t index = 0;
    uint8_t index2 = 0;

    for (index = 0; index < i_max; index += 1) //send max from top function
    {
        if (i_shmoo_param_valid & DRV_IMP)
        {
            if (drv_imp_array[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & SLEW_RATE)
        {
            if (slew_rate_array[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & WR_VREF)
        {
            if (wr_vref_array_fitness[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & RD_VREF)
        {
            if (rd_cen_vref_array_fitness[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                break;
            }
        }
        else if (i_shmoo_param_valid & RCV_IMP)
        {
            if (rcv_imp_array[index] == i_param_nom)
            {
                left_margin_nom = i_left[index];
                right_margin_nom = i_right[index];
                diff_margin_nom = (i_left[index] >= i_right[index]) ?
                                  (i_left[index] - i_right[index]) :
                                  (i_right[index] - i_left[index]);
                break;
            }
        }
    }

    for (index2 = 0; index2 < i_max; index2 += 1)
    {
        left_margin = i_left[index2];
        right_margin = i_right[index2];
        diff_margin = (i_left[index2] >= i_right[index2]) ? (i_left[index2]
                      - i_right[index2]) : (i_right[index2] - i_left[index2]);

        if ((left_margin > 0 && right_margin > 0))
        {
            if ((left_margin >= left_margin_nom) && (right_margin
                    >= right_margin_nom) && (diff_margin <= diff_margin_nom))
            {
                o_index = index2;
            }
        }
    }
}


