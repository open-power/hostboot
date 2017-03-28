/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_mcbist.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file mss_mcbist.H
/// @brief MCBIST execution procedures header
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef MSS_MCBIST_H
#define MSS_MCBIST_H
#include <fapi2.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_mss_access_delay_reg.H>
#include <dimmConsts.H>

extern "C"
{

    //############### Global variables ################
    ///
    /// @brief mcbist test enums
    ///
    enum mcbist_test_mem
    {
        USER_MODE,
        CENSHMOO,
        SUREFAIL,
        MEMWRITE,
        MEMREAD,
        CBR_REFRESH,
        MCBIST_SHORT,
        SHORT_SEQ,
        DELTA_I,
        DELTA_I_LOOP,
        SHORT_RAND,
        LONG1,
        BUS_TAT,
        SIMPLE_FIX,
        SIMPLE_RAND,
        SIMPLE_RAND_2W,
        SIMPLE_RAND_FIXD,
        SIMPLE_RA_RD_WR,
        SIMPLE_RA_RD_R,
        SIMPLE_RA_FD_R,
        SIMPLE_RA_FD_R_INF,
        SIMPLE_SA_FD_R,
        SIMPLE_RA_FD_W,
        INFINITE,
        WR_ONLY,
        W_ONLY,
        R_ONLY,
        W_ONLY_RAND,
        R_ONLY_RAND,
        R_ONLY_MULTI,
        SHORT,
        SIMPLE_RAND_BARI,
        W_R_INFINITE,
        W_R_RAND_INFINITE,
        R_INFINITE1,
        R_INFINITE_RF,
        MARCH,
        SIMPLE_FIX_RF,
        SHMOO_STRESS,
        SIMPLE_RAND_RA,
        SIMPLE_FIX_RA,
        SIMPLE_FIX_RF_RA,
        TEST_RR,
        TEST_RF,
        W_ONLY_INFINITE_RAND,
        MCB_2D_CUP_SEQ,
        MCB_2D_CUP_RAND,
        SHMOO_STRESS_INFINITE,
        HYNIX_1_COL,
        RMWFIX,
        RMWFIX_I,
        W_INFINITE,
        R_INFINITE
    };
    ///
    /// @brief mcbist data enums
    ///
    enum mcbist_data_gen
    {
        ABLE_FIVE,
        USR_MODE,
        ONEHOT,
        DQ0_00011111_RESTALLONE,
        DQ0_11100000_RESTALLZERO,
        ALLZERO,
        ALLONE,
        BYTE_BURST_SIGNATURE,
        BYTE_BURST_SIGNATURE_V1,
        BYTE_BURST_SIGNATURE_V2,
        BYTE_BURST_SIGNATURE_V3,
        DATA_GEN_DELTA_I,
        MCBIST_2D_CUP_PAT0,
        MPR,
        MPR03,
        MPR25,
        MPR47,
        DELTA_I1,
        MCBIST_2D_CUP_PAT1,
        MHC_55,
        MHC_DQ_SIM,
        MCBIST_2D_CUP_PAT2,
        MCBIST_2D_CUP_PAT3,
        MCBIST_2D_CUP_PAT4,
        MCBIST_2D_CUP_PAT5,
        MCBIST_2D_CUP_PAT6,
        MCBIST_2D_CUP_PAT7,
        MCBIST_2D_CUP_PAT8,
        MCBIST_2D_CUP_PAT9,
        CWLPATTERN,
        GREY1,
        DC_ONECHANGE,
        DC_ONECHANGEDIAG,
        GREY2,
        FIRST_XFER,
        MCBIST_222_XFER,
        MCBIST_333_XFER,
        MCBIST_444_XFER,
        MCBIST_555_XFER,
        MCBIST_666_XFER,
        MCBIST_777_XFER,
        MCBIST_888_XFER,
        FIRST_XFER_X4MODE,
        MCBIST_LONG,
        PSEUDORANDOM,
        CASTLE
    };

    ///
    /// @brief mcbist operation enums
    ///
    enum mcbist_oper_type
    {
        W,
        R,
        RW,
        WR,
        RWR,
        RWW,
        OPER_RAND,
        GOTO
    };

    ///
    /// @brief mcbist data mode enums
    ///
    enum mcbist_data_mode
    {
        FIX,
        DATA_RF,
        DATA_RR,
        RECCF,
        RECCB,
        DEA,
        DRL,
        DRR

    };

    ///
    /// @brief mcbist address mode enums
    ///
    enum mcbist_addr_mode
    {
        SF,
        SR,
        RF,
        RR
    };

    ///
    /// @brief mcbist select mode enums
    ///
    enum mcbist_add_select_mode
    {
        FIX_ADDR,
        PORTA0_RANDOM,
        PORTA1_RANDOM,
        PORTA0_SEQ
    };

    ///
    /// @brief mcbist data select enums
    ///
    enum mcbist_data_select_mode
    {
        DEFAULT,
        BURST0,
        BURST1,
        BURST2
    };

    ///
    /// @brief byte mask enums
    ///
    enum mcbist_byte_mask
    {
        BYTE0,
        BYTE1,
        BYTE2,
        BYTE3,
        BYTE4,
        BYTE5,
        BYTE6,
        BYTE7,
        BYTE8,
        BYTE9,
        UNMASK_ALL,
        NONE
    };

    ///
    /// @brief shmoo mode enums
    ///
    enum shmoo_mode
    {
        FAST = 0,
        ONE_SLOW = 1,
        QUARTER_SLOW = 2,
        HALF_SLOW = 3,
        FULL_SLOW = 4,
        ONE_CHAR = 5,
        QUARTER_CHAR = 6,
        HALF_CHAR = 7,
        FULL_CHAR = 8
    };

    ///
    /// @brief shmoo address mode enums
    ///
    enum shmoo_addr_mode
    {
        FEW_ADDR = 0,
        QUARTER_ADDR = 1,
        HALF_ADDR = 2,
        FULL_ADDR = 3
    };

    ///
    /// @brief subtest enums
    ///
    struct subtest_info
    {
        uint8_t l_operation_type;
        uint8_t l_data_mode;
        uint8_t l_addr_mode;
        uint8_t l_random_data_enable;
        uint8_t l_fixed_data_enable;
        uint8_t l_random_addr_enable;
        uint8_t l_fixed_addr_enable;
    };

    ///
    /// @brief check the MCBIST Configuration Register for mcb fail, in progress, done
    /// @param[in] i_target_mba Centaur.mba
    /// @param[out] o_mcb_status MCB status
    /// @param[in] i_sub_info  MCB subtest information array
    /// @param[in] i_flag  verbose flag
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode poll_mcb(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                               uint8_t* o_mcb_status,
                               struct subtest_info l_sub_info[30],
                               const uint8_t i_flag);

    ///
    /// @brief Reads the nibblewise Error map registers into o_error_map
    /// @param[in] i_target_mba Centaur input mba
    /// @param[out] o_error_map[][8][10][2]   Contains the error map
    /// @param[in] i_CDarray0[80]
    /// @param[in] i_CDarray1[80]
    /// @param[in] count_bad_dq[2]
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_error_map(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                    uint8_t  o_error_map[MAX_PORTS_PER_MBA][MAX_RANKS_PER_PORT][MAX_BYTES_PER_RANK][MAX_NIBBLES_PER_BYTE],
                                    uint8_t i_CDarray0[DIMM_DQ_SPD_DATA_SIZE],
                                    uint8_t i_CDarray1[DIMM_DQ_SPD_DATA_SIZE],
                                    uint8_t count_bad_dq[2]);

    ///
    /// @brief Based on parameters passed we write data into Register being passed
    /// @param[in]   i_target_mba               Centaur input mba
    /// @param[in]   i_reg_addr                 Register address
    /// @param[in]   i_operation_type           Operation Type
    /// @param[in]   i_cfg_test_123_cmd         Integer value
    /// @param[in]   i_addr_mode                Sequential or Random address modes
    /// @param[in]   i_data_mode                Data Mode
    /// @param[in]   i_done                     Done Bit
    /// @param[in]   i_data_select_mode         Different BURST modes or DEFAULT
    /// @param[in]   i_addr_select_mode         Address Select mode
    /// @param[in]   i_testnumber               Subtest number
    /// @param[in]   i_testnumber1              Subtest number
    /// @param[in]   i_total_subtest_no
    /// @param[in]   i_sub_info                 Subtest info array
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_write_test_mem(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const uint64_t i_reg_addr,
                                         const mcbist_oper_type i_operation_type,
                                         const uint8_t i_cfg_test_123_cmd,
                                         const mcbist_addr_mode i_addr_mode,
                                         const mcbist_data_mode i_data_mode,
                                         const uint8_t i_done,
                                         const mcbist_data_select_mode i_data_select_mode,
                                         const mcbist_add_select_mode i_addr_select_mode,
                                         const uint8_t i_testnumber,
                                         const uint8_t i_testnumber1,
                                         const uint8_t i_total_no,
                                         struct subtest_info l_sub_info[30]);

    ///
    /// @brief This function executes different MCBIST subtests
    /// @param[in]    i_target_mba      Centaur.mba
    /// @param[in]    i_test_type       Subtest Type
    /// @param[in]    i_sub_info
    /// @retun FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode cfg_mcb_test_mem(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                       const mcbist_test_mem i_test_type,
                                       struct subtest_info l_sub_info[30]);

    ///
    /// @brief Clears all the trap registers in MCBIST engine
    /// @param[in] i_target_mba Centaur input mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_reset_trap(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief This function writes data patterns based on i_datamode passed
    /// @param[in] i_target_mba     Centaur input mba
    /// @param[in] i_datamode       MCBIST Data mode
    /// @param[in] i_mcbrotate      Provides the number of bit to shift per burst
    /// @param[in] i_mcbrotdata     Provides the data seed to shift per burst
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode cfg_mcb_dgen(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                   const mcbist_data_gen i_datamode,
                                   const uint8_t i_mcbrotate,
                                   const uint64_t i_mcbrotdata);

    ///
    /// @brief It is used to mask bad bits read from SPD
    /// @param[in]  i_target_mba Centaur.mba
    /// @return FAPI2_RC_SUCCESS  iff successful
    ///
    fapi2::ReturnCode cfg_byte_mask(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief Checks for dimms drop in the particular port & starts MCBIST
    /// @param[in] i_target_mna Centaur.mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode start_mcb(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief Will setup the required MCBIST configuration register
    /// @param[in]  i_target_mba        Centaur input mba
    /// @param[in]  i_mcbbytemask       It is used to mask bad bits read from SPD
    /// @param[in]  i_mcbrotate         Provides the number of bit to shift per burst
    /// @param[in]  i_mcbrotdata        Provides the rotate data to shift per burst
    /// @param[in]  i_sub_info
    /// @param[in]  i_str_cust_addr
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode setup_mcbist(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                   const mcbist_byte_mask i_mcbbytemask,
                                   const uint8_t i_mcbrotate,
                                   const uint64_t i_mcbrotdata,
                                   struct subtest_info l_sub_info[30],
                                   const char* l_str_cust_addr);

    ///
    /// @brief print the mcbist error map
    /// @param[in] i_target_mba Centaur input MBA
    /// @param[in] i_mcb_fail_160
    /// @param[in] i_port Centaur input port
    /// @param[in] i_array  error array
    /// @param[in] i_number  Highest index in array w error
    /// @param[in] i_data_buf_port MCB data mask
    /// @param[in] i_data_buf_spare MCB data mask
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mcb_error_map_print(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                          const fapi2::variable_buffer& l_mcb_fail_160,
                                          const uint8_t i_port,
                                          const uint8_t l_array[DIMM_DQ_SPD_DATA_SIZE],
                                          const uint8_t l_number,
                                          const fapi2::buffer<uint64_t> l_data_buf_port,
                                          const fapi2::buffer<uint64_t> l_data_buf_spare);
    ///
    /// @brief Convert Testype num to mcbist_test_mem type
    /// @param[in] i_target_mba  Centaur input mba
    /// @param[in] i_pattern     MCBIST testtype
    /// @param[out] o_mcbtest     MCBIST testtype
    ///
    void mss_conversion_testtype(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const uint8_t l_pattern,
                                 mcbist_test_mem& o_mcbtest);

    ///
    /// @brief convert number pattern to mcbist_data_gen type
    /// @param[in] i_target_mba Centaur input mba
    /// @param[in] i_pattern    input pattern
    /// @param[out] o_mcbpatt   mcbist_data_gen type pattern
    ///
    void mss_conversion_data(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                             const uint8_t l_pattern,
                             mcbist_data_gen& o_mcbpatt);
}
#endif
