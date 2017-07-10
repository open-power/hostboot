/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_mcbist.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
/// @file mss_mcbist.C
/// @brief MCBIST execution procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#include <generic/memory/lib/utils/c_str.H>
#include <p9c_mss_mcbist.H>
#include <fapi2.H>
extern "C"
{
    constexpr uint8_t MAX_BYTE = 10;
    ///
    /// @brief This function executes different MCBIST subtests
    /// @param[in]    i_target_mba      Centaur.mba
    /// @param[in]    i_test_type       Subtest Type
    /// @param[in]    i_sub_info
    /// @retun FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode cfg_mcb_test_mem(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                       const mcbist_test_mem i_test_type,
                                       struct subtest_info l_sub_info[30])
    {
        uint8_t l_print = 0;
        uint32_t l_mcbtest = 0;
        uint8_t l_index, l_data_flag, l_random_flag, l_count, l_data_attr;
        l_index = 0;
        l_data_flag = 0;
        l_random_flag = 0;
        l_data_attr = 0;
        uint8_t l_done_bit = 0;
        uint8_t test_array_count[44] = { 0, 2, 2, 1, 1, 1, 6, 6, 30, 30,
                                         2, 7, 4, 2, 1, 5, 4, 2, 1, 1,
                                         3, 1, 1, 4, 2, 1, 1, 1, 1, 10,
                                         0, 5, 3, 3, 3, 3, 9, 4, 30, 1,
                                         2, 2, 3, 3
                                       };
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_PRINTING_DISABLE, i_target_mba,  l_print));

        if (l_print == 0)
        {
            FAPI_DBG("Function Name: cfg_mcb_test_mem");
            FAPI_DBG("Start Time");
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_TEST_TYPE, i_target_mba,  l_mcbtest));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));

        if (i_test_type == CENSHMOO)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : CENSHMOO ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, SF, FIX, 0, DEFAULT, FIX_ADDR, 0, 0, 1, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 1, 1, 1, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

        }
        else if (i_test_type == MEMWRITE)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : MEMWRITE ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 0, 0, 0, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

        }
        else if (i_test_type == MEMREAD)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : MEMREAD ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 0, 0, 0, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");
        }
        else if (i_test_type == SIMPLE_FIX)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : SIMPLE_FIX ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, SF, FIX, 0, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            l_done_bit = 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR1Q,
                                        RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");
        }
        else if (i_test_type == SIMPLE_RAND)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : SIMPLE_RAND ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        WR, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            l_done_bit = 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 1, SF, DATA_RF, 0, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, RF, DATA_RF, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR1Q,
                                        RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

        }
        else if (i_test_type == WR_ONLY)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : WR_ONLY ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, SF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            l_done_bit = 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, RF, FIX, 0, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR1Q,
                                        RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

        }
        else if (i_test_type == W_ONLY)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : W_ONLY ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            l_done_bit = 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, RF, FIX, 0, DEFAULT, FIX_ADDR, 2, 2, 4,
                                        l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR1Q,
                                        RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

        }
        else if (i_test_type == R_ONLY)
        {
            if (l_print == 0)
            {
                FAPI_DBG("Current MCBIST TESTTYPE : R_ONLY ");
            }

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            l_done_bit = 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        GOTO, 0, SF, FIX, 0, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, RF, FIX, 0, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");


            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR1Q,
                                        RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

        }
        else if (i_test_type == SIMPLE_FIX_RF)
        {
            FAPI_DBG("%s:Current MCBIST TESTTYPE : SIMPLE_FIX_RF ",
                     mss::c_str(i_target_mba));
            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        W, 0, SF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            FAPI_TRY(mcb_write_test_mem(i_target_mba, CEN_MBA_MCBMR0Q,
                                        R, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info), "cfg_mcb_test_mem failed mcb_write_test_mem");

            l_done_bit = 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_ADDR_BANK, i_target_mba,  l_done_bit));

        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_CFG_MCB_TEST_MEM_INVALID_INPUT().
                        set_TEST_TYPE_PARAM(i_test_type),
                        "Invalid MCBIST test type (%d)! cfg_mcb_test_mem Function",
                        i_test_type);
        }

        if (l_print == 0)
        {
            FAPI_DBG("Function Name: cfg_mcb_test_mem");
            FAPI_DBG("Stop Time");
        }

        l_count = test_array_count[l_mcbtest];

        for (l_index = 0; l_index < l_count; l_index++)
        {
            if (l_sub_info[l_index].l_fixed_data_enable == 1)
            {
                l_data_flag = 1;
            }

            if (l_sub_info[l_index].l_random_data_enable == 1)
            {
                l_random_flag = 1;
            }
        }

        if ((l_data_flag == 0) && (l_random_flag == 1))
        {
            l_data_attr = 1;
        }
        else if ((l_data_flag == 1) && (l_random_flag == 0))
        {
            l_data_attr = 2;
        }
        else if ((l_data_flag == 1) && (l_random_flag == 1))
        {
            l_data_attr = 3;
        }
        else
        {
            l_data_attr = 3;
        }

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_DATA_ENABLE, i_target_mba,  l_data_attr));

    fapi_try_exit:
        return fapi2::current_err;

    }

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
                                   const uint64_t i_mcbrotdata)
    {
        uint8_t l_print = 0;
        uint8_t l_data_attr, l_random_flag, l_data_flag = 0;
        l_data_flag = 1;
        l_random_flag = 1;
        l_data_attr = 3;
        uint8_t l_seed_choice = 0;
        uint32_t i_seed = 0;
        i_seed = 0x20;
        l_seed_choice = 1;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::buffer<uint64_t> l_var_data_buffer_64;
        fapi2::buffer<uint64_t> l_var1_data_buffer_64;
        fapi2::buffer<uint64_t> l_spare_data_buffer_64;
        fapi2::buffer<uint32_t> l_data_buffer_32;
        fapi2::buffer<uint16_t> l_data_buffer_16;
        fapi2::variable_buffer l_data_buffer_4(4);
        fapi2::variable_buffer l_data_buffer1_4(4);
        uint64_t l_var = 0x0000000000000000ull;
        uint64_t l_var1 = 0x0000000000000000ull;
        uint64_t l_spare = 0x0000000000000000ull;
        uint8_t l_rotnum = 0;
        uint64_t l_data_buffer_64_value = 0;
        uint32_t l_mba01_mcb_pseudo_random[MAX_BYTE] =
        {
            CEN_MBA_MCBFD0Q, CEN_MBA_MCBFD1Q,
            CEN_MBA_MCBFD2Q, CEN_MBA_MCBFD3Q,
            CEN_MBA_MCBFD4Q, CEN_MBA_MCBFD5Q,
            CEN_MBA_MCBFD6Q, CEN_MBA_MCBFD7Q,
            CEN_MBA_MCBFDQ, CEN_MBA_MCBFDSPQ
        };
        constexpr uint32_t l_mba01_mcb_random[MAX_BYTE] = { CEN_MBA_MCBRDS0Q,
                                                            CEN_MBA_MCBRDS1Q,
                                                            CEN_MBA_MCBRDS2Q,
                                                            CEN_MBA_MCBRDS3Q,
                                                            CEN_MBA_MCBRDS4Q,
                                                            CEN_MBA_MCBRDS5Q,
                                                            CEN_MBA_MCBRDS6Q,
                                                            CEN_MBA_MCBRDS7Q,
                                                            CEN_MBA_MCBRDS8Q,
                                                            CEN_MBA_MCBRDSSPQ
                                                          };
        constexpr uint32_t l_mbs01_mcb_random[MAX_BYTE] = { CEN_MCBISTS01_MBS_MCBRDS0Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS1Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS2Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS3Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS4Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS5Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS6Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS7Q,
                                                            CEN_MCBISTS01_MBS_MCBRDS8Q,
                                                            CEN_MCBISTS01_MBS_MCBRDSSPQ
                                                          };
        constexpr uint32_t l_mbs23_mcb_random[MAX_BYTE] = { CEN_MCBISTS23_MBS_MCBRDS0Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS1Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS2Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS3Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS4Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS5Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS6Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS7Q,
                                                            CEN_MCBISTS23_MBS_MCBRDS8Q,
                                                            CEN_MCBISTS23_MBS_MCBRDSSPQ
                                                          };

        uint8_t l_index, l_index1 = 0;
        uint32_t l_rand_32 = 0;
        uint32_t l_rand_8 = 0;
        uint8_t l_mbaPosition = 0;


        if (l_print == 0)
        {
            FAPI_DBG("Function Name: cfg_mcb_dgen");
            FAPI_DBG(" Data mode is %d ", i_datamode);
        }

        const auto i_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        //Read MBA position attribute 0 - MBA01 1 - MBA23
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba,  l_mbaPosition));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_PRINTING_DISABLE, i_target_mba,  l_print));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_DATA_ENABLE, i_target_mba,  l_data_attr));

        if (l_data_attr == 1)
        {
            l_data_flag = 0;
            l_random_flag = 1;
        }
        else if (l_data_attr == 2)
        {
            l_data_flag = 1;
            l_random_flag = 0;
        }
        else if (l_data_attr == 3)
        {
            l_data_flag = 1;
            l_random_flag = 1;
        }
        else
        {
            l_data_flag = 1;
            l_random_flag = 1;
        }

        if (l_data_flag == 1)
        {
            if (i_datamode == MCBIST_2D_CUP_PAT5)
            {
                l_var = 0xFFFF0000FFFF0000ull;
                l_var1 = 0x0000FFFF0000FFFFull;
                l_spare = 0xFF00FF00FF00FF00ull;

                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;
                l_spare_data_buffer_64 = l_spare;

                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD0Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD1Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD2Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD3Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD4Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD5Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD6Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD7Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDQ, l_spare_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDSPQ, l_spare_data_buffer_64));
            }
            else if (i_datamode == MCBIST_2D_CUP_PAT8)
            {
                l_var = 0xFFFFFFFFFFFFFFFFull;
                l_var1 = 0x0000000000000000ull;
                l_spare = 0xFFFF0000FFFF0000ull;
                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;
                l_spare_data_buffer_64 = l_spare;
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD0Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD1Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD2Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD3Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD4Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD5Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD6Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD7Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDQ, l_spare_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDSPQ, l_spare_data_buffer_64));
            }
            else if (i_datamode == ABLE_FIVE)
            {
                l_var = 0xA5A5A5A5A5A5A5A5ull;
                l_var1 = 0x5A5A5A5A5A5A5A5Aull;
                l_spare = 0xA55AA55AA55AA55Aull;

                l_spare_data_buffer_64 = l_spare;
                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;

                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD0Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD1Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD2Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD3Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD4Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD5Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD6Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD7Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDQ, l_spare_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDSPQ, l_spare_data_buffer_64));
            }
            else if(i_datamode == MPR)
            {
                l_var = 0x0000000000000000ull;
                l_var1 = 0xFFFFFFFFFFFFFFFFull;
                l_spare = 0x00FF00FF00FF00FFull;

                l_spare_data_buffer_64 = l_spare;
                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD0Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD1Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD2Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD3Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD4Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD5Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD6Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD7Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDQ , l_spare_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDSPQ , l_spare_data_buffer_64));
            }
            else if ((i_datamode == DATA_GEN_DELTA_I) ||
                     (i_datamode == MCBIST_2D_CUP_PAT0))
            {
                l_var = 0xFFFFFFFFFFFFFFFFull;
                l_var1 = 0x0000000000000000ull;
                l_spare = 0xFF00FF00FF00FF00ull;
                l_spare_data_buffer_64 = l_spare;
                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;

                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD0Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD1Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD2Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD3Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD4Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD5Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD6Q, l_var_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFD7Q, l_var1_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDQ, l_spare_data_buffer_64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBFDSPQ, l_spare_data_buffer_64));
            }
            else if (i_datamode == PSEUDORANDOM)
            {
                l_rand_32 = 0xFFFFFFFF;//Hard Coded Temporary Fix till random function is fixed

                // srand(2);
                if (l_seed_choice == 1)
                {
                    if (i_seed == 0)
                    {
                        i_seed = 0xFFFFFFFF;
                    }

                    l_rand_32 = i_seed;
                }

                for (l_index = 0; l_index < (MAX_BYTE); l_index++)
                {
                    FAPI_TRY(l_data_buffer_32.insertFromRight(l_rand_32, 0, 32));
                    FAPI_TRY(l_data_buffer_64.insert(uint32_t(l_data_buffer_32), 0, 32, 0));
                    FAPI_TRY(l_data_buffer_32.insertFromRight(l_rand_32, 0, 32));
                    FAPI_TRY(l_data_buffer_64.insert(uint32_t(l_data_buffer_32), 32, 32, 0));
                    FAPI_TRY(fapi2::putScom(i_target_mba, l_mba01_mcb_pseudo_random[l_index],
                                            l_data_buffer_64));
                }
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_CFG_MCB_DGEN_INVALID_INPUT().
                            set_DATA_MODE_PARAM(i_datamode),
                            "cfg_mcb_dgen: Invalid data mode (%d)",
                            i_datamode);
            }

            if (i_datamode == MCBIST_2D_CUP_PAT5)
            {
                l_var = 0xFFFF0000FFFF0000ull;
                l_var1 = 0x0000FFFF0000FFFFull;
                l_spare = 0xFF00FF00FF00FF00ull;

                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;
                l_spare_data_buffer_64 = l_spare;

                if (l_mbaPosition == 0)
                {
                    //Writing MBS 01 pattern registers for comparison mode
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD1Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD2Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD5Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD6Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDQ, l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
                else if (l_mbaPosition == 1)
                {
                    //Writing MBS 23 pattern registers for comparison mode
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD1Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD2Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD5Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD6Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDQ, l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
            }
            else if (i_datamode == MCBIST_2D_CUP_PAT8)
            {
                l_var = 0xFFFFFFFFFFFFFFFFull;
                l_var1 = 0x0000000000000000ull;
                l_spare = 0xFFFF0000FFFF0000ull;

                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;
                l_spare_data_buffer_64 = l_spare;

                if (l_mbaPosition == 0)
                {
                    //Writing MBS 01 pattern registers for comparison mod
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD1Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD2Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD5Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD6Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDQ, l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
                else if (l_mbaPosition == 1)
                {
                    //Writing MBS 23 pattern registers for comparison mod
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD1Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD2Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD5Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD6Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDQ, l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
            }
            else if (i_datamode == ABLE_FIVE)
            {
                l_var = 0xA5A5A5A5A5A5A5A5ull;
                l_var1 = 0x5A5A5A5A5A5A5A5Aull;
                l_spare = 0xA55AA55AA55AA55Aull;

                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;
                l_spare_data_buffer_64 = l_spare;

                if (l_mbaPosition == 0)
                {
                    //Writing MBS 01 pattern registers for comparison mod
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD1Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD2Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD5Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD6Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDQ,  l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
                else if (l_mbaPosition == 1)
                {
                    //Writing MBS 23 pattern registers for comparison mod
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD1Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD2Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD5Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD6Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDQ, l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
            }
            else if ((i_datamode == DATA_GEN_DELTA_I) || (i_datamode
                     == MCBIST_2D_CUP_PAT0))
            {
                l_var = 0xFFFFFFFFFFFFFFFFull;
                l_var1 = 0x0000000000000000ull;
                l_spare = 0xFF00FF00FF00FF00ull;

                l_var_data_buffer_64 = l_var;
                l_var1_data_buffer_64 = l_var1;
                l_spare_data_buffer_64 = l_spare;

                if (l_mbaPosition == 0)
                {
                    //Writing MBS 01 pattern registers for comparison mod
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD1Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD2Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD5Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD6Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDQ, l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
                else if (l_mbaPosition == 1)
                {
                    //Writing MBS 23 pattern registers for comparison mod
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD0Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD1Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD2Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD3Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD4Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD5Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD6Q, l_var_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFD7Q, l_var1_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDQ, l_spare_data_buffer_64));
                    FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS23_MBS_MCBFDSPQ, l_spare_data_buffer_64));
                }
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_CFG_MCB_DGEN_INVALID_INPUT().
                            set_DATA_MODE_PARAM(i_datamode),
                            "cfg_mcb_dgen: Invalid data mode (%d)",
                            i_datamode);
            }
        }

        if (l_random_flag == 1)
        {
            for (l_index = 0; l_index < MAX_BYTE; l_index++)
            {
                for (l_index1 = 0; l_index1 < 8; l_index1++)
                {
                    l_rand_8 = 0xFF;
                    FAPI_TRY(l_data_buffer_64.insert(l_rand_8, 8 * l_index1, 8, 24));
                }

                FAPI_TRY(fapi2::putScom(i_target_mba, l_mba01_mcb_random[l_index], l_data_buffer_64));

                if (l_mbaPosition == 0)
                {
                    FAPI_TRY(fapi2::putScom(i_target_centaur, l_mbs01_mcb_random[l_index], l_data_buffer_64));
                }
                else
                {
                    FAPI_TRY(fapi2::putScom(i_target_centaur, l_mbs23_mcb_random[l_index], l_data_buffer_64));
                }
            }
        }


        // get the rotate value loaded into reg, if rotate value 0 / not defined the default to rotate =13
        if(i_mcbrotate == 0)
        {
            FAPI_DBG("%s:i_mcbrotate == 0 , the l_rotnum is set to 13", mss::c_str(i_target_mba));
            l_rotnum = 13;   // for random data generation - basic setup
        }
        else
        {
            l_rotnum = i_mcbrotate;
        }

        l_data_buffer_64.flush<0>();

        // get the rotate data seed loaded into reg, if rotate data value = 0 / not defined the default rotate pttern is randomlly generated.
        if(i_mcbrotdata == 0)
        {
            // generate the random number
            l_data_buffer_64 = 0x863A822CDF2924C4ull;
        }
        else
        {
            l_data_buffer_64 = i_mcbrotdata;
        }

        // load the mcbist and mba with rotnum and rotdata.
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBDRSRQ , l_data_buffer_64)); //added

        if(l_mbaPosition == 0)
        {
            FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201167F , l_data_buffer_64));
            l_data_buffer_64_value = l_data_buffer_64;
            FAPI_INF("%s:Value of Rotate data seed %016llX for reg %08X", mss::c_str(i_target_mba), l_data_buffer_64_value,
                     0x0201167F );

            FAPI_TRY(l_data_buffer_16.insert(l_data_buffer_64, 0, 16));
            FAPI_TRY(fapi2::getScom(i_target_centaur, 0x02011680 , l_data_buffer_64));
            FAPI_TRY(l_data_buffer_64.insert(l_rotnum, 0, 4, 4));
            FAPI_TRY(l_data_buffer_64.insert(l_data_buffer_16, 4, 16));
            FAPI_TRY(fapi2::putScom(i_target_centaur, 0x02011680 , l_data_buffer_64));
        }
        else
        {
            FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201177F , l_data_buffer_64)); //added
            l_data_buffer_64_value = l_data_buffer_64;
            FAPI_INF("%s:Value of Rotate data seed %016llX for reg %08X", mss::c_str(i_target_mba), l_data_buffer_64_value,
                     0x0201177F );

            FAPI_TRY(l_data_buffer_16.insert(l_data_buffer_64, 0, 16));
            FAPI_TRY(fapi2::getScom(i_target_centaur, 0x02011780 , l_data_buffer_64));
            FAPI_TRY(l_data_buffer_64.insert(l_rotnum, 0, 4, 4));
            FAPI_TRY(l_data_buffer_64.insert(l_data_buffer_16, 4, 16));
            FAPI_TRY(fapi2::putScom(i_target_centaur, 0x02011780 , l_data_buffer_64));
        }

        FAPI_DBG("%s: Preet Clearing bit 20 of CEN_MBA_MCBDRCRQ to avoid inversion of data to the write data flow",
                 mss::c_str(i_target_mba));
        l_data_buffer_64.clearBit<20, 2>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBDRCRQ, l_data_buffer_64));

    fapi_try_exit:
        return fapi2::current_err;
    }

}
