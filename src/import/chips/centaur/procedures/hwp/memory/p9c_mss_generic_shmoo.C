/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_generic_shmoo.C $ */
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
/// @file p9c_mss_generic_shmoo.C
/// @brief MSS Generic Shmoo Implementation
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#include <fapi2.H>
#include <p9c_mss_generic_shmoo.H>
#include <p9c_mss_mcbist.H>
#include <p9c_mss_draminit_training.H>
#include <p9c_dimmBadDqBitmapFuncs.H>
#include <p9c_mss_access_delay_reg.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>

extern "C"
{
    ///
    /// @brief Constructor used to initialize variables and do the initial settings
    /// @param[in] addr Port number
    /// @param[in] shmoo_type_t shmoo_mask set what shmoos caller wants to run
    /// @param[in] shmoo_algorithm SEQ_LIN, PARALLEL etc.
    ///
    generic_shmoo::generic_shmoo(uint8_t addr, shmoo_type_t shmoo_mask, shmoo_algorithm_t shmoo_algorithm)
    {
        this->shmoo_mask = shmoo_mask; //! Sets what Shmoos the caller wants to run
        this->algorithm = shmoo_algorithm ;
        this->iv_shmoo_type = shmoo_mask;
        this->iv_addr = addr;
        iv_MAX_BYTES = 10;
        iv_DQS_ON = 0;
        iv_pattern = 0;
        iv_test_type = 0;
        iv_dmm_type = 0;
        iv_shmoo_param = 0;
        iv_binary_diff = 2;
        iv_vref_mul = 0;
        iv_SHMOO_ON = 0;

        for(uint8_t p = 0; p < MAX_PORT; p++)
        {
            for(uint8_t i = 0; i < MAX_RANK; i++)
            {
                valid_rank1[p][i] = 0;
                valid_rank[i] = 0;
            }
        }

        iv_MAX_RANKS[0] = 4;
        iv_MAX_RANKS[1] = 4;

        if (shmoo_mask & TEST_NONE)
        {
            FAPI_INF("mss_generic_shmoo : NONE selected %d", shmoo_mask);
        }

        if (shmoo_mask & MCBIST)
        {
            FAPI_INF("mss_generic_shmoo : MCBIST selected %d", shmoo_mask);
            iv_shmoo_type = 1;
        }

        if (shmoo_mask & WR_EYE)
        {
            FAPI_INF("mss_generic_shmoo : WR_EYE selected %d", shmoo_mask);
            iv_shmoo_type = 2;
        }

        if (shmoo_mask & RD_EYE)
        {
            FAPI_INF("mss_generic_shmoo : RD_EYE selected %d", shmoo_mask);
            iv_shmoo_type = 8;
        }

        if (shmoo_mask & WRT_DQS)
        {
            FAPI_INF("mss_generic_shmoo : WRT_DQS selected %d", shmoo_mask);
            iv_shmoo_type = 4;
            iv_DQS_ON = 1;
        }

        if(iv_DQS_ON == 1)
        {
            for (uint8_t k = 0; k < MAX_SHMOO; k++)
            {
                for (uint8_t i = 0; i < MAX_PORT; i++)
                {
                    for (uint8_t j = 0; j < iv_MAX_RANKS[i]; j++)
                    {
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.nom_val, 250);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.lb_regval, 0);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.rb_regval, 512);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.last_pass, 0);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.last_fail, 0);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.curr_val, 0);
                    }
                }
            }
        }
    }

    ///
    /// @brief Delegator function that runs shmoo using other  functions
    /// @param[in] i_target Centaur input mba
    /// @param[out] o_right_min_margin Minimum hold time
    /// @param[out] o_left_min_margin Minimum setup time
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::run(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                         uint32_t* o_right_min_margin,
                                         uint32_t* o_left_min_margin,
                                         uint32_t i_vref_mul)
    {
        uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_schmoo_test_type_u8 = 0;
        uint8_t l_attr_schmoo_multiple_setup_call_u8 = 0;
        uint8_t l_mcbist_prnt_off = 0;
        uint64_t i_content_array[10];
        uint8_t l_rankpgrp0[2] = { 0 };
        uint8_t l_rankpgrp1[2] = { 0 };
        uint8_t l_rankpgrp2[2] = { 0 };
        uint8_t l_rankpgrp3[2] = { 0 };
        uint8_t l_totrg_0 = 0;
        uint8_t l_totrg_1 = 0;
        uint8_t l_pp = 0;
        uint8_t l_shmoo_param = 0;
        uint8_t rank_table_port0[8] = {0};
        uint8_t rank_table_port1[8] = {0};
        uint8_t l_dram_gen = 0;
        uint8_t i_rp = 0;
        uint8_t l_dram_width = 0;
        uint8_t eff_stack_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_MODE, i_target, l_shmoo_param));
        iv_shmoo_param = l_shmoo_param;
        FAPI_INF(" +++++ The iv_shmoo_param = %d ++++ ", iv_shmoo_param);
        iv_vref_mul = i_vref_mul;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, l_dram_width));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_PRINTING_DISABLE, i_target, l_mcbist_prnt_off));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, num_ranks_per_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target, l_attr_eff_dimm_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target, l_attr_schmoo_test_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SCHMOO_MULTIPLE_SETUP_CALL, i_target, l_attr_schmoo_multiple_setup_call_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target, l_rankpgrp0));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target, l_rankpgrp1));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target, l_rankpgrp2));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target, l_rankpgrp3));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, eff_stack_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target, l_dram_gen));
        iv_MAX_RANKS[0] = num_ranks_per_dimm[0][0] + num_ranks_per_dimm[0][1];
        iv_MAX_RANKS[1] = num_ranks_per_dimm[1][0] + num_ranks_per_dimm[1][1];
        iv_pattern = 0;
        iv_test_type = 0;

        if ( l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES )
        {
            iv_MAX_BYTES = 10;
        }
        else
        {
            iv_dmm_type = 1;
            iv_MAX_BYTES = 9;
        }

        for(uint8_t l_rnk = 0; l_rnk < iv_MAX_RANKS[0]; l_rnk++)
        {
            // Byte loop
            FAPI_TRY(mss_getrankpair(i_target, 0, 0, &i_rp, rank_table_port0));
        }

        for(uint8_t l_rnk = 0; l_rnk < iv_MAX_RANKS[0]; l_rnk++)
        {
            // Byte loop
            FAPI_TRY(mss_getrankpair(i_target, 1, 0, &i_rp, rank_table_port1));
        }

        for(uint8_t l_p = 0; l_p < MAX_PORTS_PER_MBA; l_p++)
        {
            for(uint8_t l_rnk = 0; l_rnk < MAX_RANKS_PER_PORT; l_rnk++)
            {
                // Byte loop
                if(l_p == 0)
                {
                    valid_rank1[l_p][l_rnk] = rank_table_port0[l_rnk];
                }
                else
                {
                    valid_rank1[l_p][l_rnk] = rank_table_port1[l_rnk];
                }

                if((l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                   && (eff_stack_type[l_p][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
                   && (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
                {
                    //3ds 256 GB Dimm
                    //FAPI_INF("3DS - 2H 256GB");
                    rank_table_port0[0] = 0;
                    rank_table_port0[1] = 4;
                    rank_table_port0[2] = 255;
                    rank_table_port0[3] = 255;
                    rank_table_port1[0] = 0;
                    rank_table_port1[1] = 4;
                    rank_table_port1[2] = 255;
                    rank_table_port1[3] = 255;
                }
            }
        }

        FAPI_DBG("mss_generic_shmoo : run() for shmoo type %d", shmoo_mask);
        FAPI_DBG("mss_generic_shmoo : run() l_attr_schmoo_test_type_u8 %d", l_attr_schmoo_test_type_u8);
        // Check if all bytes/bits are in a pass condition initially .Otherwise quit

        //Value of l_attr_schmoo_test_type_u8 are  0x01,     0x02,   0x04,      0x08,   0x10 ===
        //                                       "MCBIST","WR_EYE","RD_EYE","WRT_DQS","RD_DQS" resp.

        if (l_attr_schmoo_test_type_u8 == 0)
        {
            FAPI_INF("%s:This procedure wont change any delay settings",
                     mss::c_str(i_target));
        }

        if (l_attr_schmoo_test_type_u8 == 1)
        {

            FAPI_TRY(sanity_check(i_target),
                     "generic_shmoo::run MSS Generic Shmoo failed initial Sanity Check. Memory not in an all pass Condition");

        }

        else if (l_attr_schmoo_test_type_u8 == 8)
        {
            if (l_rankpgrp0[0] != 255)
            {
                l_totrg_0++;
            }

            if (l_rankpgrp1[0] != 255)
            {
                l_totrg_0++;
            }

            if (l_rankpgrp2[0] != 255)
            {
                l_totrg_0++;
            }

            if (l_rankpgrp3[0] != 255)
            {
                l_totrg_0++;
            }

            if (l_rankpgrp0[1] != 255)
            {
                l_totrg_1++;
            }

            if (l_rankpgrp1[1] != 255)
            {
                l_totrg_1++;
            }

            if (l_rankpgrp2[1] != 255)
            {
                l_totrg_1++;
            }

            if (l_rankpgrp3[1] != 255)
            {
                l_totrg_1++;
            }

            if ((l_totrg_0 == 1) || (l_totrg_1 == 1))
            {
                FAPI_TRY(shmoo_save_rest(i_target, i_content_array, 0));
                l_pp = 1;
            }

            if (l_pp == 1)
            {
                FAPI_INF("%s:Ping pong is disabled", mss::c_str(i_target));
            }
            else
            {
                FAPI_INF("%s:Ping pong is enabled", mss::c_str(i_target));
            }

            if ((l_pp = 1) && ((l_totrg_0 == 1) || (l_totrg_1 == 1)))
            {
                FAPI_INF("%s:Rank group is not good with ping pong. Hope you have set W2W gap to 10",
                         mss::c_str(i_target));
            }

            iv_shmoo_type = 4; //for Gate Delays
            FAPI_TRY(get_all_noms_dqs(i_target));

            iv_shmoo_type = 2; // For Access delays
            FAPI_TRY(get_all_noms(i_target));

            FAPI_TRY(schmoo_setup_mcb(i_target));
            //Find RIGHT BOUND OR SETUP BOUND
            FAPI_TRY(find_bound(i_target, RIGHT));

            //Find LEFT BOUND OR HOLD BOUND
            FAPI_TRY(find_bound(i_target, LEFT));
            iv_shmoo_type = 4;

            if (l_dram_width == 4)
            {
                FAPI_TRY(get_margin_dqs_by4(i_target));
            }
            else
            {
                FAPI_TRY(get_margin_dqs_by8(i_target));
            }

            FAPI_TRY(print_report_dqs(i_target));

            FAPI_TRY(get_min_margin_dqs(i_target, o_right_min_margin, o_left_min_margin));

            if ((l_totrg_0 == 1) || (l_totrg_1 == 1))
            {
                FAPI_TRY(shmoo_save_rest(i_target, i_content_array, 1));
            }

            FAPI_INF("%s: Least tDQSSmin(ps)=%d ps and Least tDQSSmax=%d ps", mss::c_str(i_target), *o_left_min_margin,
                     *o_right_min_margin);
        }
        else
        {
            FAPI_INF("************ ++++++++++++++++++ ***************** +++++++++++++ *****************");
            FAPI_TRY(get_all_noms(i_target));

            if(l_attr_schmoo_multiple_setup_call_u8 == 0)
            {
                FAPI_TRY(schmoo_setup_mcb(i_target));
            }

            FAPI_TRY(set_all_binary(i_target, RIGHT));
            //Find RIGHT BOUND OR SETUP BOUND
            FAPI_TRY(find_bound(i_target, RIGHT));
            FAPI_TRY(set_all_binary(i_target, LEFT));
            //Find LEFT BOUND OR HOLD BOUND
            FAPI_TRY(find_bound(i_target, LEFT));

            //Find the margins in Ps i.e setup margin ,hold margin,Eye width
            FAPI_TRY(get_margin2(i_target));

            //It is used to find the lowest of setup and hold margin
            if(iv_shmoo_param == 6)
            {
                get_min_margin2(i_target, o_right_min_margin, o_left_min_margin);
                FAPI_TRY(print_report2(i_target));
                FAPI_INF("%s:Minimum hold margin=%d ps and setup margin=%d ps", mss::c_str(i_target), *o_left_min_margin,
                         *o_right_min_margin);
            }
            else
            {
                get_min_margin2(i_target, o_right_min_margin, o_left_min_margin);
                FAPI_TRY(print_report2(i_target));
                FAPI_INF("%s:Minimum hold margin=%d ps and setup margin=%d ps", mss::c_str(i_target), *o_left_min_margin,
                         *o_right_min_margin);
            }
        }

        l_mcbist_prnt_off = 0;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_PRINTING_DISABLE, i_target, l_mcbist_prnt_off));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief save and restore registers before and after shmoo
    /// @param[in] i_target Centaur input MBA
    /// @param[in] i_content_array register contents to save/restore
    /// @param[in] i_mode 0 = save; 1 = restore
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::shmoo_save_rest(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint64_t i_content_array[],
            const uint8_t i_mode)
    {
        uint8_t l_index = 0;
        uint64_t l_value = 0;
        uint64_t l_val_u64 = 0;
        fapi2::buffer<uint64_t> l_shmoo1ab;
        uint64_t l_Databitdir[10] = { 0x800000030301143full,
                                      0x800004030301143full,
                                      0x800008030301143full,
                                      0x80000c030301143full,
                                      0x800010030301143full,
                                      0x800100030301143full,
                                      0x800104030301143full,
                                      0x800108030301143full,
                                      0x80010c030301143full,
                                      0x800110030301143full
                                    };

        if (i_mode == 0)
        {
            FAPI_INF("%s: Saving DP18 data bit direction register contents",
                     mss::c_str(i_target));

            for (l_index = 0; l_index < MAX_BYTE; l_index++)
            {
                l_value = l_Databitdir[l_index];
                FAPI_TRY(fapi2::getScom(i_target, l_value, l_shmoo1ab));
                l_shmoo1ab.setBit<57>();
                FAPI_TRY(fapi2::putScom(i_target, l_value, l_shmoo1ab));
                l_shmoo1ab.extract<0, 64>(i_content_array[l_index]);
            }
        }
        else if (i_mode == 1)
        {
            FAPI_INF("%s: Restoring DP18 data bit direction register contents",
                     mss::c_str(i_target));

            for (l_index = 0; l_index < MAX_BYTE; l_index++)
            {
                l_val_u64 = i_content_array[l_index];
                l_value = l_Databitdir[l_index];
                l_shmoo1ab.insert<0, 64>(l_val_u64);
                FAPI_TRY(fapi2::putScom(i_target, l_value, l_shmoo1ab));
            }
        }
        else
        {
            FAPI_INF("%s:Invalid value of MODE", mss::c_str(i_target));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief do intial mcbist check in nominal and report spd if any bad bit found
    /// @param[in] i_target Centaur input mba
    /// @return FAPI2_RC_SUCCESS iff succesful
    ///
    fapi2::ReturnCode generic_shmoo::sanity_check(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        mcbist_mode = QUARTER_SLOW;
        uint8_t l_mcb_status = 0;
        uint8_t l_CDarray0[DIMM_TO_C4_DQ_ENTRIES] = { 0 };
        uint8_t l_CDarray1[DIMM_TO_C4_DQ_ENTRIES] = { 0 };
        uint8_t l_byte, l_rnk = 0;
        uint8_t l_nibble = 0;
        uint8_t l_p = 0;
        uint8_t rank = 0;
        uint8_t l_faulted_rank = 255;
        uint8_t l_faulted_port = 255;
        uint8_t l_faulted_dimm = 255;
        uint8_t l_memory_health = 0;
        uint8_t l_max_byte = 10;

        struct subtest_info l_sub_info[30];

        FAPI_TRY(schmoo_setup_mcb(i_target));
        FAPI_DBG("%s:  starting  mcbist now", mss::c_str(i_target));
        FAPI_TRY(start_mcb(i_target));
        FAPI_DBG("%s:  polling   mcbist now", mss::c_str(i_target));
        FAPI_TRY(poll_mcb(i_target, &l_mcb_status, l_sub_info, 1), "generic_shmoo::do_mcbist_test: POLL MCBIST failed !!");
        FAPI_DBG("%s:  checking error map ", mss::c_str(i_target));
        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1,
                               count_bad_dq));

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                // Byte loop
                rank = valid_rank1[l_p][l_rnk];

                for (l_byte = 0; l_byte < l_max_byte; l_byte++)
                {
                    //Nibble loop
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        if (mcbist_error_map[l_p][rank][l_byte][l_nibble] == 1)
                        {
                            l_memory_health = 1;
                            l_faulted_rank = rank;
                            l_faulted_port = l_p;

                            if(rank > 3)
                            {
                                l_faulted_dimm = 1;
                            }
                            else
                            {
                                l_faulted_dimm = 0;
                            }

                            break;
                        }
                    }
                }
            }
        }

        //////////////// changed the check condition ... The error call out need to gard the dimm=l_faulted_dimm(0 or 1) //// port=l_faulted_port(0 or 1) target=i_target ...
        FAPI_ASSERT(!l_memory_health,
                    fapi2::CEN_MSS_GENERIC_SHMOO_MCBIST_FAILED().
                    set_MBA_TARGET(i_target).
                    set_MBA_PORT_NUMBER(l_faulted_port).
                    set_MBA_DIMM_NUMBER(l_faulted_dimm),
                    "generic_shmoo:sanity_check failed !! MCBIST failed on %s initial run , memory is not in good state needs investigation port=%d rank=%d dimm=%d",
                    mss::c_str(i_target),
                    l_faulted_port,
                    l_faulted_rank,
                    l_faulted_dimm);

    fapi_try_exit:
        return fapi2::current_err;
    }
    ///
    /// @brief do mcbist reset
    /// @param[in] i_target Centaur input mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::do_mcbist_reset(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        const auto i_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        fapi2::buffer<uint64_t> l_data_buffer_64;
        l_data_buffer_64.flush<0>();
        //PORT - A
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBEMA1Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBEMA2Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBEMA3Q, l_data_buffer_64));

        //PORT - B
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBEMB1Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBEMB2Q, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, CEN_MCBISTS01_MCBEMB3Q, l_data_buffer_64));

        // MBS 23
        FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201176a, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201176b, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201176c, l_data_buffer_64));

        //PORT - B
        FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201176d, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201176e, l_data_buffer_64));
        FAPI_TRY(fapi2::putScom(i_target_centaur, 0x0201176f, l_data_buffer_64));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief do mcbist check for error on particular nibble
    /// @param[in] i_target: centaur input mba
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::do_mcbist_test(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_mcb_status = 0;
        struct subtest_info l_sub_info[30];

        FAPI_TRY(start_mcb(i_target), "generic_shmoo::do_mcbist_test: Start MCBIST failed !!");
        FAPI_TRY(poll_mcb(i_target, &l_mcb_status, l_sub_info, 1), "generic_shmoo::do_mcbist_test: POLL MCBIST failed !!");
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief used by do_mcbist_test  to check the error map for particular nibble
    /// @param[in] i_target Centaur input MBA
    /// @param[in] l_p Centaur input port
    /// @param[out] pass 1 = error found in mcb_error_map
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::check_error_map(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint8_t l_p,
            uint8_t& pass)
    {
        uint8_t l_byte, l_rnk = 0;
        uint8_t l_nibble = 0;
        uint8_t l_byte_is = 0;
        uint8_t l_nibble_is = 0;
        uint8_t l_n = 0;
        pass = 1;
        input_type l_input_type_e =  ISDIMM_DQ;
        uint8_t i_input_index_u8 = 0;
        uint8_t l_val = 0;
        uint8_t rank = 0;
        uint8_t l_max_byte = 10;
        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};

        if(iv_dmm_type == 1)
        {
            l_max_byte = 9;
        }

        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                 "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

        for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
        {
            // Byte loop
            rank = valid_rank1[l_p][l_rnk];
            l_n = 0;

            for(l_byte = 0; l_byte < l_max_byte; l_byte++)
            {
                //Nibble loop
                for(l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                {
                    if(iv_dmm_type == 1)
                    {
                        i_input_index_u8 = 8 * l_byte + 4 * l_nibble;

                        FAPI_TRY(rosetta_map(i_target, l_p, l_input_type_e, i_input_index_u8, 0, l_val));

                        l_byte_is = l_val / 8;
                        l_nibble_is = l_val % 8;

                        if(l_nibble_is > 3)
                        {
                            l_nibble_is = 1;
                        }
                        else
                        {
                            l_nibble_is = 0;
                        }

                        if( mcbist_error_map [l_p][rank][l_byte_is][l_nibble_is] == 1)
                        {
                            schmoo_error_map[l_p][rank][l_n] = 1;
                            pass = 1;
                        }
                        else
                        {

                            schmoo_error_map[l_p][rank][l_n] = 0;
                            pass = 0;
                        }
                    }
                    else
                    {
                        if( mcbist_error_map [l_p][rank][l_byte][l_nibble] == 1)
                        {

                            schmoo_error_map[l_p][rank][l_n] = 1;
                            pass = 1;
                        }
                        else
                        {
                            schmoo_error_map[l_p][rank][l_n] = 0;
                            pass = 0;
                        }
                    }

                    l_n++;
                }//end of nibble loop
            }//end byte loop
        }//end rank loop

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief used by do_mcbist_test  to check the error map for particular nibble
    /// @param[in] i_target Centaur input MBA
    /// @param[in] l_p Centaur input port
    /// @param[out] pass 1 = error found in mcb_error_map
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::check_error_map2(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint8_t port,
            uint8_t& pass)
    {
        uint8_t l_byte, l_rnk = 0;
        uint8_t l_nibble = 0;
        uint8_t l_byte_is = 0;
        uint8_t l_nibble_is = 0;
        uint8_t l_n = 0;
        pass = 1;
        uint8_t l_p = 0;
        input_type l_input_type_e =  ISDIMM_DQ;
        uint8_t i_input_index_u8 = 0;
        uint8_t l_val = 0;
        uint8_t rank = 0;
        uint8_t l_max_byte = 10;
        uint8_t l_max_nibble = 20;
        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};

        if(iv_dmm_type == 1)
        {
            l_max_byte = 9;
            l_max_nibble = 18;
        }

        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                 "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                rank = valid_rank1[l_p][l_rnk];
                l_n = 0;

                // Byte loop
                for(l_byte = 0; l_byte < l_max_byte; l_byte++)
                {
                    //Nibble loop
                    for(l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        if(iv_dmm_type == 1)
                        {
                            i_input_index_u8 = BITS_PER_BYTE * l_byte + BITS_PER_NIBBLE * l_nibble;

                            FAPI_TRY(rosetta_map(i_target, l_p, l_input_type_e, i_input_index_u8, 0, l_val));

                            l_byte_is = l_val / BITS_PER_BYTE;
                            l_nibble_is = l_val % BITS_PER_BYTE;

                            if(l_nibble_is > 3)
                            {
                                l_nibble_is = 1;
                            }
                            else
                            {
                                l_nibble_is = 0;
                            }

                            if( mcbist_error_map [l_p][rank][l_byte_is][l_nibble_is] == 1)
                            {
                                //pass=0;
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }
                            else
                            {
                                schmoo_error_map[l_p][rank][l_n] = 0;
                            }

                        }
                        else
                        {
                            if( mcbist_error_map [l_p][rank][l_byte][l_nibble] == 1)
                            {
                                //pass=0;
                                schmoo_error_map[l_p][rank][l_n] = 1;
                                //FAPI_INF("We are in error and nibble is %d and rank is %d and port is %d \n",l_n,rank,l_p);
                            }
                            else
                            {
                                schmoo_error_map[l_p][rank][l_n] = 0;
                            }
                        }

                        l_n++;
                    } // for nibble
                } // for byte
            } // for rank
        } // for port

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                // Byte loop
                rank = valid_rank1[l_p][l_rnk];

                for (l_n = 0; l_n < l_max_nibble; l_n++)
                {
                    if(schmoo_error_map[l_p][rank][l_n] == 0)
                    {
                        pass = 0;
                    }

                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;

    }



    ///
    /// @brief This function does the initialization of various schmoo parameters
    /// @param[out] array address
    /// @param[in] init_val initial value to initialize to
    ///
    void generic_shmoo::init_multi_array(uint16_t(&array)[MAX_DQ],
                                         const uint16_t init_val)
    {
        uint8_t l_byte, l_nibble, l_bit = 0;
        uint8_t l_dq = 0;

        // Byte loop
        for (l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
        {
            //Nibble loop
            for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
            {
                //Bit loop
                for (l_bit = 0; l_bit < MAX_BITS; l_bit++)
                {
                    l_dq = 8 * l_byte + 4 * l_nibble + l_bit;
                    array[l_dq] = init_val;
                }
            }
        }
    }

    ///
    /// @brief  set all bits
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::set_all_binary(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound)
    {
        uint8_t l_rnk, l_byte, l_nibble, l_bit = 0;
        uint8_t l_dq = 0;
        uint8_t l_p = 0;
        uint32_t l_max = 512;
        uint32_t l_max_offset = 64;
        uint8_t rank = 0;

        //if RD_EYE
        if(iv_shmoo_type == 8)
        {
            l_max = 127;
        }

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                rank = valid_rank1[l_p][l_rnk];

                for(l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
                {
                    for(l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        for(l_bit = 0; l_bit < MAX_BITS; l_bit++)
                        {
                            l_dq = (BITS_PER_BYTE * l_byte) + (BITS_PER_NIBBLE * l_nibble) + l_bit;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq];
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq];

                            if(bound == RIGHT)
                            {
                                if((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] + l_max_offset) > l_max)
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] = l_max;
                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                            l_max_offset;
                                }
                            }

                            else
                            {
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] > 64)
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                            l_max_offset;
                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] = 0;
                                }
                            }
                        } // bit loop
                    } // nibble loop
                } // byte loop
            } // rank loop
        } // port loop

        return fapi2::FAPI2_RC_SUCCESS;
    }


    ///
    /// @brief This function gets the nominal values for each DQ
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::get_all_noms(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk, l_byte, l_nibble, l_bit = 0;
        uint8_t i_rnk = 0;
        uint16_t val = 0;
        uint8_t l_dq = 0;
        uint8_t l_p = 0;
        input_type_t l_input_type_e = WR_DQ;
        access_type_t l_access_type_e = READ;
        FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
        }
        else if(iv_shmoo_type == 16)
        {
            l_input_type_e = RD_DQS;
        }

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                // Byte loop
                i_rnk = valid_rank1[l_p][l_rnk];

                for(l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
                {
                    //Nibble loop
                    for(l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        //Bit loop
                        for(l_bit = 0; l_bit < MAX_BITS; l_bit++)
                        {
                            l_dq = 8 * l_byte + 4 * l_nibble + l_bit;
                            FAPI_INF("Before access call");
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, i_rnk, l_input_type_e, l_dq, 1, val));
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq] = val;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rnk].K.rb_regval[l_dq] = val;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rnk].K.lb_regval[l_dq] = val;

                        }
                    }
                }
            }
        }

        FAPI_INF("get all noms done");

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Read in all nominal values
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::get_all_noms_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk = 0;
        uint32_t val = 0;
        uint8_t l_p = 0;
        uint8_t l_max_nibble = 20;
        uint8_t rank = 0;
        uint8_t l_n = 0;
        FAPI_INF("%s:mss_generic_shmoo : get_all_noms_dqs : Reading in all nominal values and schmoo type=%d \n",
                 mss::c_str(i_target), 1);

        if(iv_dmm_type == 1)
        {
            l_max_nibble = 18;
        }

        input_type_t l_input_type_e = WR_DQS;
        access_type_t l_access_type_e = READ ;
        FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                rank = valid_rank1[l_p][l_rnk];

                for (l_n = 0; l_n < l_max_nibble; l_n++)
                {
                    FAPI_TRY(mss_access_delay_reg(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_n, 0, val));
                    SHMOO[1].MBA.P[l_p].S[rank].K.nom_val[l_n] = val;
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This is a key function is used to find right and left bound using new algorithm -- there is an option u can chose not to use it by setting a flag
    /// @param[in] i_target Centaur input MBA Parameters: Target:MBA,bound:RIGHT/LEFT,scenario:type of schmoo,iv_port:0/1,rank:0-7,byte:0-7,nibble:0/1,bit:0-3,pass,
    /// @param[in] bound RIGHT/LEFT
    /// @param[in] scenario type of shmoo
    /// @param[in] bit 0-3
    /// @param[in] pass
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::knob_update(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound,
            const uint8_t scenario,
            const uint8_t bit,
            uint8_t pass)
    {
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::buffer<uint64_t> data_buffer_64_1;
        input_type_t l_input_type_e = WR_DQ;
        uint8_t l_dq = 0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n = 0;
        uint8_t l_i = 0;
        uint8_t l_p = 0;
        uint16_t l_delay = 0;
        uint16_t l_max_limit = 500;
        uint8_t rank = 0;
        uint8_t l_rank = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_CDarray0[CDIMM_MAX_DQ_80] = {0};
        uint8_t l_CDarray1[CDIMM_MAX_DQ_80] = {0};

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        //l_SCHMOO_NIBBLES = 2; //temp preet del this
        FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");

        FAPI_INF("Linear in Progress FW --> %d", scenario);

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
            l_max_limit = 127;
        }
        else if(iv_shmoo_type == 4)
        {
            l_input_type_e = WR_DQS;
        }

        for (l_p = 0; l_p < 2; l_p++)
        {
            for(uint8_t i = 0; i < iv_MAX_RANKS[l_p]; i++)
            {

                rank = valid_rank1[l_p][i];

                for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                {
                    schmoo_error_map[l_p][rank][l_n] = 0;
                }
            }
        }

        if(bound == RIGHT)
        {
            for (l_delay = 1; ((pass == 0)); l_delay = l_delay + 1)
            {

                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {


                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {

                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 1,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));

                            }

                            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq));


                            if(l_p == 0)
                            {

                                for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                {

                                    if(l_CDarray0[l_i] == l_dq)
                                    {

                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }
                            else
                            {
                                for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                {

                                    if(l_CDarray1[l_i] == l_dq)
                                    {

                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }

                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] > l_max_limit)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }


                            l_dq = l_dq + 4;

                        } //end of nibble
                    } //end of rank
                } //end of port loop

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 35)
                {
                    break;
                }
            } //end of Delay loop;


            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq = bit;

                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 1,
                                                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                        l_dq = l_dq + 4;
                    }
                }
            }


        }

        if(bound == LEFT)
        {
            for (l_delay = 1; (pass == 0); l_delay += 1)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = bit;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {



                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                            }

                            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq));

                            if(l_p == 0)
                            {
                                for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                {
                                    if(l_CDarray0[l_i] == l_dq)
                                    {
                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }
                            else
                            {
                                for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                {
                                    if(l_CDarray1[l_i] == l_dq)
                                    {
                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }

                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] == 0)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }

                            l_dq = l_dq + 4;

                        }
                    }

                }

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 35)
                {
                    break;
                }
            }


            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq = bit;

                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                        l_dq = l_dq + 4;
                    }
                }
            }



        }

    fapi_try_exit:
        return fapi2::current_err;
    }



    ///
    /// @brief used to find right and left bound
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @param[in] scenario type of shmoo
    /// @param[in] bit 0-3
    /// @param[in] pass
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::knob_update_bin(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound,
            const uint8_t scenario,
            const uint8_t bit,
            uint8_t pass)
    {
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::buffer<uint64_t> data_buffer_64_1;
        input_type_t l_input_type_e = WR_DQ;
        uint8_t l_dq = 0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n = 0;
        uint8_t l_i = 0;
        uint8_t l_flag_p0 = 0;
        uint8_t l_flag_p1 = 0;
        FAPI_INF("Inside - Binary Schmoo FW - %d", scenario);
        uint8_t l_p = 0;
        uint8_t rank = 0;
        uint8_t l_rank = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_status = 1;
        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};
        int count_cycle = 0;

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
        }
        else if(iv_shmoo_type == 4)
        {
            l_input_type_e = WR_DQS;
        }
        else if(iv_shmoo_type == 16)
        {
            l_input_type_e = RD_DQS;
        }


        FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");


        //Reset schmoo_error_map

        for(l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for(uint8_t i = 0; i < iv_MAX_RANKS[l_p]; i++)
            {

                rank = valid_rank1[l_p][i];

                for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                {
                    schmoo_error_map[l_p][rank][l_n] = 0;
                    binary_done_map[l_p][rank][l_n] = 0;
                }
            }
        }

        if(bound == RIGHT)
        {
            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                do
                {
                    l_status = 0;
                    FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq));


                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            if(binary_done_map[l_p][rank][l_n] == 0)
                            {
                                l_status = 1;
                            }

                            l_flag_p0 = 0;
                            l_flag_p1 = 0;

                            if(l_p == 0)
                            {
                                for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                {
                                    if(l_CDarray0[l_i] == l_dq)
                                    {
                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                        l_flag_p0 = 1;
                                    }
                                }
                            }
                            else
                            {
                                for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                {

                                    if(l_CDarray1[l_i] == l_dq)
                                    {
                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                        l_flag_p1 = 1;

                                    }
                                }
                            }

                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq] = (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] +
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) / 2;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]));

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] > SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] <= 1)
                                {
                                    binary_done_map[l_p][rank][l_n] = 1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                }
                            }
                            else
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq] = (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] +
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) / 2;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]));

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] > SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }

                                if(l_p == 0)
                                {
                                    if(l_flag_p0 == 1)
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = 1;
                                    }
                                }
                                else
                                {
                                    if(l_flag_p1 == 1)
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = 1;
                                    }
                                }

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] <= 1)
                                {
                                    binary_done_map[l_p][rank][l_n] = 1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];

                                }
                            }

                            l_dq = l_dq + 4;
                        }
                    }


                    FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");
                    FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
                    FAPI_TRY(check_error_map(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");
                    count_cycle++;
                }
                while(l_status == 1);
            }

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq = bit;
                    //////
                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                        l_dq = l_dq + 4;
                    }
                }
            }




        }

        count_cycle = 0;

        if(bound == LEFT)
        {
            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                l_status = 1;

                while(l_status == 1)
                {
                    l_status = 0;

                    FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq));

                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = bit;
                        //////
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {

                            if(binary_done_map[l_p][rank][l_n] == 0)
                            {
                                l_status = 1;
                            }

                            l_flag_p0 = 0;
                            l_flag_p1 = 0;

                            if(l_p == 0)
                            {
                                for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                {
                                    if(l_CDarray0[l_i] == l_dq)
                                    {
                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                        l_flag_p0 = 1;

                                    }
                                }
                            }
                            else
                            {
                                for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                {

                                    if(l_CDarray1[l_i] == l_dq)
                                    {
                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                        l_flag_p1 = 1;

                                    }
                                }
                            }

                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq] = (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] +
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) / 2;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]));

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] > SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] <= 1)
                                {
                                    binary_done_map[l_p][rank][l_n] = 1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];

                                }
                            }
                            else
                            {

                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq] = (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] +
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) / 2;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]));

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] > SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }


                                if(l_p == 0)
                                {
                                    if(l_flag_p0 == 1)
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = 1;
                                    }
                                }
                                else
                                {
                                    if(l_flag_p1 == 1)
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] = 1;
                                    }
                                }

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq] <= 1)
                                {
                                    binary_done_map[l_p][rank][l_n] = 1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];

                                }
                            }

                            l_dq = l_dq + 4;
                        }
                    }

                    FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");
                    FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
                    FAPI_TRY(check_error_map(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");
                    count_cycle++;
                }
            }

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq = bit;
                    //////
                    rank = valid_rank1[l_p][l_rank];
                    //printf("Valid rank of %d %d %d %d %d %d %d %d",valid_rank1[0],valid_rank1[1],valid_rank1[2],valid_rank1[3],valid_rank1[4],valid_rank1[5],valid_rank1[6],valid_rank1[7]);

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                        l_dq = l_dq + 4;
                    }
                }
            }

        } // End of LEFT

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief used to find right and left bound
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @param[in] scenario type of shmoo
    /// @param[in] bit 0-3
    /// @param[in] pass
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::knob_update_dqs_by4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound,
            const uint8_t scenario,
            const uint8_t bit,
            uint8_t pass)
    {
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::buffer<uint64_t> data_buffer_64_1;

        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq = 0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n = 0;
        uint8_t l_dqs = 1;
        uint8_t l_p = 0;
        uint8_t l_i = 0;
        uint16_t l_delay = 0;
        uint16_t l_max_limit = 500;
        uint8_t rank = 0;
        uint8_t l_rank = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;

        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};
        FAPI_INF("\nWRT_DQS --- > CDIMM  X4 - Scenario = %d", scenario);

        FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                 "generic_shmoo::do_mcbist_test: ecb_error_map failed!!");

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }


        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for(uint8_t i = 0; i < iv_MAX_RANKS[l_p]; i++)
            {

                rank = valid_rank1[l_p][i];

                for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                {
                    schmoo_error_map[l_p][rank][l_n] = 0;
                }
            }
        }

        if(bound == RIGHT)
        {

            for (l_delay = 1; ((pass == 0)); l_delay++)
            {

                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;

                            if(l_p == 0)
                            {

                                for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                {

                                    if(l_CDarray0[l_i] == l_dq)
                                    {

                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }
                            else
                            {
                                for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                {

                                    if(l_CDarray1[l_i] == l_dq)
                                    {

                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }

                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {

                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n] = SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n] + l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                                     SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n]));
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                            }

                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dq] > l_max_limit)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }
                        } // for nibble
                    } // for rank
                } // for port

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }
            } //end of delay


            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {


                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {

                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));

                    }
                }
            }

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        }
                    }
                }
            }

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

        } // end bound == right

        if(bound == LEFT)
        {


            for (l_delay = 1; (pass == 0); l_delay++)
            {

                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;

                            if(l_p == 0)
                            {

                                for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                {

                                    if(l_CDarray0[l_i] == l_dq)
                                    {

                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }
                            else
                            {
                                for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                {

                                    if(l_CDarray1[l_i] == l_dq)
                                    {

                                        schmoo_error_map[l_p][rank][l_n] = 1;
                                    }
                                }
                            }

                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {
                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n] = SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n] - l_delay;
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                                     SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n]));
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                            }

                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n] == 0)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }
                        }
                    }
                }

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }
            }

            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));
                    }
                }
            }

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        }
                    }
                }
            }

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief used to find right and left bound
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @param[in] scenario type of shmoo
    /// @param[in] bit 0-3
    /// @param[in] pass
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::knob_update_dqs_by4_isdimm(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound,
            const uint8_t scenario,
            const uint8_t bit,
            uint8_t pass)
    {
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::buffer<uint64_t> data_buffer_64_1;
        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq = 0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n = 0;
        uint8_t l_dqs = 1;
        uint8_t l_my_dqs = 0;
        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};
        uint8_t l_p = 0;
        uint16_t l_delay = 0;
        uint16_t l_max_limit = 500;
        uint8_t rank = 0;
        uint8_t l_rank = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_dqs_arr[18] = {0, 9, 1, 10, 2, 11, 3, 12, 4, 13, 5, 14, 6, 15, 7, 16, 8, 17};

        FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                 "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for(uint8_t i = 0; i < iv_MAX_RANKS[l_p]; i++)
            {
                rank = valid_rank1[l_p][i];

                for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                {
                    schmoo_error_map[l_p][rank][l_n] = 0;
                }
            }
        }

        if(bound == RIGHT)
        {
            for (l_delay = 1; ((pass == 0)); l_delay++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;
                        l_my_dqs = 0;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;
                            l_my_dqs = l_dqs_arr[l_n];

                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {

                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs] = SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs] + l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_my_dqs, 0,
                                                                     SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs]));
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                            }

                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dq] > l_max_limit)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }
                        } //end of nibble loop
                    } //end of rank
                } //end of port

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }
            } //end of delay loop

            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));
                    }
                }
            }

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        }
                    } //end of rank
                } //end of port
            } //end of bit

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
        }

        if(bound == LEFT)
        {
            for (l_delay = 1; (pass == 0); l_delay++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;
                        l_my_dqs = 0;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;
                            l_my_dqs = l_dqs_arr[l_n];

                            if(schmoo_error_map[l_p][rank][l_n] == 0)
                            {
                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs] = SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs] - l_delay;
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_my_dqs, 0,
                                                                     SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs]));
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                            }

                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dq] == 0)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }
                        }
                    }
                }

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }
            } //end of delay loop

            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));
                    }
                }
            }

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        } //end of nibble
                    } //end of rank
                } //port loop
            } //bit loop

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
        } //end of Left

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief used to find right and left bound
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @param[in] scenario type of shmoo
    /// @param[in] bit 0-3
    /// @param[in] pass
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::knob_update_dqs_by8(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound,
            const uint8_t scenario,
            const uint8_t bit,
            uint8_t pass)
    {
        fapi2::buffer<uint64_t> data_buffer_64(64);
        fapi2::buffer<uint64_t> data_buffer_64_1(64);
        //uint8_t  l_rp=0;
        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq = 0;
        uint8_t l_dqs = 0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n = 0;
        uint8_t l_scen_dqs = 1;
        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};
        uint8_t l_p = 0;
        uint16_t l_delay = 0;
        uint16_t l_max_limit = 500;
        uint8_t rank = 0;
        uint8_t l_rank = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;

        FAPI_INF("\nWRT_DQS --- > CDIMM  X8 - Scenario = %d", scenario);
        FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                 "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for(uint8_t i = 0; i < iv_MAX_RANKS[l_p]; i++)
            {

                rank = valid_rank1[l_p][i];

                for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                {
                    schmoo_error_map[l_p][rank][l_n] = 0;
                } //end of nib
            } //end of rank
        } //end of port loop

        if(bound == RIGHT)
        {
            for (l_delay = 1; ((pass == 0)); l_delay++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;
                        l_dqs = 0;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;

                            if((schmoo_error_map[l_p][rank][l_n] == 0) && (schmoo_error_map[l_p][rank][l_n + 1] == 0))
                            {
                                //Increase delay of DQS
                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n] = SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n] + l_delay;
                                //Write it to register DQS delay
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                                     SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n]));

                                //Increase Delay of DQ
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));

                                l_dq = l_dq + 1;

                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));

                            }

                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] > l_max_limit)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n] == 1) || (schmoo_error_map[l_p][rank][l_n + 1] == 1))
                            {

                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            l_n = l_n + 1;
                            l_dqs = l_dqs + 1;

                        } //end of nibble loop
                    } //end of rank loop
                } //end of port loop


                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }
            } //end of delay loop


            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {

                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));

                    } //end of nib
                } //end of rank
            } //end of port loop

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        } //end of nib
                    } //end of rank
                } //end of port loop
            } //end of bit loop

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
        }

        if(bound == LEFT)
        {
            for (l_delay = 1; (pass == 0); l_delay++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;
                        l_dqs = 0;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;



                            if((schmoo_error_map[l_p][rank][l_n] == 0) && (schmoo_error_map[l_p][rank][l_n + 1] == 0))
                            {
                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n] = SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n] - l_delay;
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                                     SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n]));
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                            }

                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] == 0)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n] == 1) || (schmoo_error_map[l_p][rank][l_n + 1] == 1))
                            {

                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            l_n = l_n + 1;
                            l_dqs = l_dq + 1;

                        }  //nibble loop
                    } //rank loop
                } //port loop

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }

            } //end of l delay loop


            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));

                    }
                }
            }

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        }
                    }
                }
            }

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
        } //end of bound Left

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief used to find right and left bound
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @param[in] scenario type of shmoo
    /// @param[in] bit 0-3
    /// @param[in] pass
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::knob_update_dqs_by8_isdimm(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound,
            const uint8_t scenario,
            const uint8_t bit,
            uint8_t pass)
    {
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::buffer<uint64_t> data_buffer_64_1;
        //uint8_t  l_rp=0;
        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq = 0;
        uint8_t l_dqs = 0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n = 0;
        uint8_t l_scen_dqs = 1;
        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};
        uint8_t l_p = 0;
        uint16_t l_delay = 0;
        uint16_t l_max_limit = 500;
        uint8_t rank = 0;
        uint8_t l_rank = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        //uint8_t i_rp=0;

        FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                 "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

        if(iv_dmm_type == 1)
        {

            l_SCHMOO_NIBBLES = 18;
        }


        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for(uint8_t i = 0; i < iv_MAX_RANKS[l_p]; i++)
            {

                rank = valid_rank1[l_p][i];

                for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                {
                    schmoo_error_map[l_p][rank][l_n] = 0;
                }
            }
        }

        if(bound == RIGHT)
        {

            for (l_delay = 1; ((pass == 0)); l_delay++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;
                        l_dqs = 0;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;
                            l_dqs = l_n / 2;

                            if((schmoo_error_map[l_p][rank][l_n] == 0) && (schmoo_error_map[l_p][rank][l_n + 1] == 0))
                            {

                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs] = SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_dqs, 0,
                                                                     SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs]));
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] +
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]));

                            }

                            if(SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs] > l_max_limit)
                            {

                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n] == 1) || (schmoo_error_map[l_p][rank][l_n + 1] == 1))
                            {

                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            l_n = l_n + 1;

                        }


                    }

                }

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }
            }


            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {
                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));
                    }
                }
            }

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        }
                    }
                }
            }

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
        }

        if(bound == LEFT)
        {

            for (l_delay = 1; (pass == 0); l_delay++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = 0;
                        l_dqs = 0;
                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            l_dq = 4 * l_n;

                            l_dqs = l_n / 2;

                            if((schmoo_error_map[l_p][rank][l_n] == 0) && (schmoo_error_map[l_p][rank][l_n + 1] == 0))
                            {
                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs] = SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs] -
                                        l_delay;
                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_dqs, 0,
                                                                     SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs]));
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                                l_dq = l_dq + 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] -
                                        l_delay;

                                FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                     SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]));
                            }

                            if(SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs] == 0)
                            {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n] == 1) || (schmoo_error_map[l_p][rank][l_n + 1] == 1))
                            {

                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n + 1] = 1;
                            }

                            l_n = l_n + 1;

                        } //nibble loop
                    } //rank loop
                } //port loop

                FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

                FAPI_TRY(check_error_map2(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");

                if (l_delay > 70)
                {
                    break;
                }

            }


            for (l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank[l_rank];

                    for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                    {

                        FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e_dqs, l_n, 0,
                                                             SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]));

                    }
                }
            }

            for(uint8_t l_bit = 0; l_bit < 4; l_bit++)
            {
                for (l_p = 0; l_p < MAX_PORT; l_p++)
                {
                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq = l_bit;

                        rank = valid_rank1[l_p][l_rank];

                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]));
                            l_dq = l_dq + 4;
                        }
                    } //rank loop
                } //port loop
            } //bit loop

            FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");

            FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq),
                     "generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

        } //end of LEFT

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function calls the knob_update for each DQ which is used to find bound  that is left/right according to schmoo type
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::find_bound(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const bound_t bound)
    {
        uint8_t l_bit = 0;
        uint8_t l_comp = 0;
        uint8_t pass = 0;
        uint8_t l_dram_width = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, l_dram_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_MODE, i_target, l_comp));

        FAPI_INF("%s:\n SCHMOO IS IN PROGRESS ...... \n", mss::c_str(i_target));

        //WRT_DQS Portion
        if(iv_DQS_ON == 1)
        {
            FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");
            pass = 0;

            if(l_dram_width == 4)
            {
                if(iv_dmm_type == 1)
                {
                    FAPI_TRY(knob_update_dqs_by4_isdimm(i_target, bound, iv_shmoo_type, l_bit, pass));
                }
                else
                {
                    FAPI_TRY(knob_update_dqs_by4(i_target, bound, iv_shmoo_type, l_bit, pass));
                }
            } //end of if dram_width 4
            else
            {
                if(iv_dmm_type == 1)
                {
                    FAPI_TRY(knob_update_dqs_by8_isdimm(i_target, bound, iv_shmoo_type, l_bit, pass));
                }
                else
                {
                    FAPI_TRY(knob_update_dqs_by8(i_target, bound, iv_shmoo_type, l_bit, pass));
                }
            }
        } //end of if iv_DQS_ON 1 or WRT_DQS

        else if(l_comp == 6)
        {
            pass = 0;
            FAPI_TRY(knob_update_bin_composite(i_target, bound, iv_shmoo_type, l_bit, pass));
        }
        else
        {
            //Bit loop
            for (l_bit = 0; l_bit < MAX_BITS; l_bit++)
            {
                // preetham function here
                pass = 0;

                ////////////////////////////////////////////////////////////////////////////////////
                if (l_comp  == 4)
                {
                    FAPI_INF("Calling Binary - %d", iv_shmoo_type);
                    FAPI_TRY(knob_update_bin(i_target, bound, iv_shmoo_type, l_bit, pass));
                }
                else
                {
                    FAPI_TRY(knob_update(i_target, bound, iv_shmoo_type, l_bit, pass));
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to print the information needed such as freq,voltage etc, and also the right,left and total margin
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::print_report(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk, l_byte, l_nibble, l_bit = 0;
        uint8_t l_dq = 0;
        uint8_t l_p = 0;
        uint8_t i_rank = 0;
        uint8_t l_mbapos = 0;
        uint32_t l_attr_mss_freq_u32 = 0;
        uint32_t l_attr_mss_volt_u32 = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;

        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_target_centaur, l_attr_mss_volt_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target, l_attr_eff_dimm_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, i_target, l_attr_eff_num_drops_per_port_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, l_attr_eff_dram_width_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbapos));

        FAPI_INF("%s:freq = %d on %s.", mss::c_str(i_target), l_attr_mss_freq_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s: volt = %d on %s.", mss::c_str(i_target), l_attr_mss_volt_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s: dimm_type = %d on %s.", mss::c_str(i_target), l_attr_eff_dimm_type_u8, mss::c_str(i_target));

        if ( l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES )
        {
            FAPI_INF("%s: It is a CDIMM", mss::c_str(i_target));
        }
        else
        {
            FAPI_INF("%s: It is an ISDIMM", mss::c_str(i_target));
        }

        FAPI_INF("%s: \n Number of ranks on port = 0 is %d ", mss::c_str(i_target), iv_MAX_RANKS[0]);
        FAPI_INF("%s: \n Number of ranks on port = 1 is %d \n \n", mss::c_str(i_target), iv_MAX_RANKS[1]);
        FAPI_INF("%s:+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", mss::c_str(i_target));

        //// Based on schmoo param the print will change eventually
        if(iv_shmoo_type == 2)
        {
            FAPI_INF("%s:Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ",
                     mss::c_str(i_target));
        }
        else
        {
            FAPI_INF("%s:Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tRdD_Setup(ps)\tRdD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ",
                     mss::c_str(i_target));
        }

        for (l_p = 0; l_p < 2; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank = valid_rank1[l_p][l_rnk];

                for(l_byte = 0; l_byte < 10; l_byte++)
                {
                    //Nibble loop
                    for(l_nibble = 0; l_nibble < 2; l_nibble++)
                    {
                        for(l_bit = 0; l_bit < 4; l_bit++)
                        {
                            l_dq = 8 * l_byte + 4 * l_nibble + l_bit;

                            if(iv_shmoo_type == 2)
                            {
                                FAPI_INF("%s:WR_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ", mss::c_str(i_target),
                                         l_mbapos, l_p, i_rank, l_byte, l_nibble, l_bit, SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq], SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_dq], l_attr_mss_freq_u32, iv_vref_mul);
                            }

                            if(iv_shmoo_type == 8)
                            {
                                FAPI_INF("%s:RD_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ", mss::c_str(i_target),
                                         l_mbapos, l_p, i_rank, l_byte, l_nibble, l_bit, SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq], SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_dq], l_attr_mss_freq_u32, iv_vref_mul);
                            }
                        }
                    }
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to print the information needed such as freq,voltage etc, and also the right,left and total margin
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::print_report_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk, l_nibble = 0;
        uint8_t l_p = 0;
        uint8_t i_rank = 0;
        uint8_t l_mbapos = 0;
        uint16_t l_total_margin = 0;
        uint32_t l_attr_mss_freq_u32 = 0;
        uint32_t l_attr_mss_volt_u32 = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_by8_dqs = 0;
        char* l_pMike = new char[128];
        char* l_str = new char[128];

        uint8_t l_i = 0;
        uint8_t l_dq = 0;
        uint8_t l_flag = 0;
        uint8_t l_CDarray0[80] = { 0 };
        uint8_t l_CDarray1[80] = { 0 };
        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1,
                               count_bad_dq), "generic_shmoo::print report: mcb_error_map failed!!");

        if (iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_target_centaur, l_attr_mss_volt_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target, l_attr_eff_dimm_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, i_target, l_attr_eff_num_drops_per_port_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, l_attr_eff_dram_width_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbapos));

        if (l_attr_eff_dram_width_u8 == 8)
        {
            l_SCHMOO_NIBBLES = 10;

            if (iv_dmm_type == 1)
            {
                l_SCHMOO_NIBBLES = 9;
            }
        }

        FAPI_INF("%s:      freq = %d on %s.", mss::c_str(i_target),
                 l_attr_mss_freq_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s:volt = %d on %s.", mss::c_str(i_target),
                 l_attr_mss_volt_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s:dimm_type = %d on %s.", mss::c_str(i_target),
                 l_attr_eff_dimm_type_u8, mss::c_str(i_target));
        FAPI_INF("%s:\n Number of ranks on port=0 is %d ", mss::c_str(i_target),
                 iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d ", mss::c_str(i_target),
                 iv_MAX_RANKS[1]);

        if (l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            FAPI_INF("%s:It is a CDIMM", mss::c_str(i_target));
        }
        else
        {
            FAPI_INF("%s:It is an ISDIMM", mss::c_str(i_target));
        }

        FAPI_INF("%s:\n Number of ranks on port=0 is %d ", mss::c_str(i_target),
                 iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d \n \n",
                 mss::c_str(i_target), iv_MAX_RANKS[1]);

        FAPI_INF(
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        sprintf(l_pMike,
                "Schmoo  POS\tPort\tRank\tDQS\tNominal\t\ttDQSSmin_PR_limit\ttDQSSmax_PR_limit\ttDQSSmin(ps)\ttDQSSmax(ps)\ttDQSS_Window(ps)\tBitRate  ");
        FAPI_INF("%s", l_pMike);
        delete[] l_pMike;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                ////

                i_rank = valid_rank1[l_p][l_rnk];
                //

                for (l_nibble = 0; l_nibble < l_SCHMOO_NIBBLES; l_nibble++)
                {
                    l_by8_dqs = l_nibble;

                    if (iv_dmm_type == 0)
                    {
                        if (l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_nibble * 2;
                        }
                    }

                    l_dq = 4 * l_nibble;
                    l_flag = 0;

                    if (l_p == 0)
                    {
                        for (l_i = 0; l_i < count_bad_dq[0]; l_i++)
                        {
                            if (l_CDarray0[l_i] == l_dq)
                            {
                                l_flag = 1;

                            }
                        }
                    }
                    else
                    {
                        for (l_i = 0; l_i < count_bad_dq[1]; l_i++)
                        {
                            if (l_CDarray1[l_i] == l_dq)
                            {
                                l_flag = 1;

                            }
                        }
                    }

                    if(l_flag == 1)
                    {
                        continue;
                    }

                    l_total_margin
                        = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble]
                          + SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble];
                    sprintf(l_str, "%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
                            l_mbapos, l_p, i_rank, l_nibble,
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.curr_val[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble],
                            l_total_margin, l_attr_mss_freq_u32);

                    FAPI_INF("WR_DQS %s", l_str);

                    if (iv_dmm_type == 0)
                    {
                        if (l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_by8_dqs;
                        }
                    }
                }
            }
        }

        delete[] l_str;
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to print the information needed such as freq,voltage etc, and also the right,left and total margin
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::print_report_dqs2(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk, l_nibble = 0;
        uint8_t l_p = 0;
        uint8_t i_rank = 0;
        uint8_t l_mbapos = 0;
        uint32_t l_attr_mss_freq_u32 = 0;
        uint32_t l_attr_mss_volt_u32 = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_by8_dqs = 0;

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_target_centaur, l_attr_mss_volt_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target, l_attr_eff_dimm_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, i_target, l_attr_eff_num_drops_per_port_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, l_attr_eff_dram_width_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbapos));

        if(l_attr_eff_dram_width_u8 == 8)
        {
            l_SCHMOO_NIBBLES = 10;

            if(iv_dmm_type == 1)
            {
                l_SCHMOO_NIBBLES = 9;
            }
        }

        FAPI_INF("%s:freq = %d on %s.", mss::c_str(i_target), l_attr_mss_freq_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s:volt = %d on %s.", mss::c_str(i_target), l_attr_mss_volt_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s:dimm_type = %d on %s.", mss::c_str(i_target), l_attr_eff_dimm_type_u8, mss::c_str(i_target));
        FAPI_INF("%s:\n Number of ranks on port=0 is %d ", mss::c_str(i_target), iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d ", mss::c_str(i_target), iv_MAX_RANKS[1]);

        if ( l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES )
        {
            FAPI_INF("%s:It is a CDIMM", mss::c_str(i_target));
        }
        else
        {
            FAPI_INF("%s:It is an ISDIMM", mss::c_str(i_target));
        }

        FAPI_INF("%s:\n Number of ranks on port=0 is %d ", mss::c_str(i_target), iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d \n \n", mss::c_str(i_target), iv_MAX_RANKS[1]);

        FAPI_INF("%s:+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", mss::c_str(i_target));
        FAPI_INF("%s:Schmoo  POS\tPort\tRank\tDQS\tNominal\t\ttDQSSmin_PR_limit\ttDQSSmax_PR_limit\ttDQSSmin(ps)\ttDQSSmax(ps)\ttDQSS_Window(ps)\tBitRate  ",
                 mss::c_str(i_target));

        iv_shmoo_type = 4;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank = valid_rank1[l_p][l_rnk];

                for(l_nibble = 0; l_nibble < l_SCHMOO_NIBBLES; l_nibble++)
                {
                    l_by8_dqs = l_nibble;

                    if(iv_dmm_type == 0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_nibble * 2;
                        }
                    }

                    FAPI_INF("%s:WR_DQS %d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ", mss::c_str(i_target), l_mbapos, l_p,
                             i_rank, l_nibble, SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble],
                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble],
                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble],
                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble],
                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble],
                             SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble], l_attr_mss_freq_u32);

                    if(iv_dmm_type == 0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_by8_dqs;
                        }
                    }


                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to get margin for setup,hold and total eye width in Ps by using frequency
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::get_margin(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk, l_byte, l_nibble, l_bit;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq = 0;
        uint64_t l_cyc = 1000000000000000ULL;
        uint8_t l_dq = 0;
        uint8_t l_p = 0;
        uint8_t i_rank = 0;
        uint64_t l_factor = 0;
        uint64_t l_factor_ps = 1000000000;
        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur,
                               l_attr_mss_freq_margin_u32));
        l_freq = l_attr_mss_freq_margin_u32 / 2;
        l_cyc = l_cyc / l_freq;// converting to zepto to get more accurate data
        l_factor = l_cyc / 128;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                ////

                i_rank = valid_rank1[l_p][l_rnk];

                //
                for (l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
                {
                    //Nibble loop
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        for (l_bit = 0; l_bit < MAX_BITS; l_bit++)
                        {
                            l_dq = 8 * l_byte + 4 * l_nibble + l_bit;

                            if (iv_shmoo_type == 1)
                            {
                                if (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] == 0)
                                {

                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] = 0;


                                }
                            }

                            if (iv_shmoo_param == 4)
                            {
                                if (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                    > SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                        = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] - 1;
                                }

                                if (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]
                                    < SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]
                                        = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] + 1;
                                }
                            }
                            else
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] - 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] + 1;
                            }

                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq]
                                = ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                    - SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                   * l_factor) / l_factor_ps;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq]
                                = ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq]
                                    - SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq])
                                   * l_factor) / l_factor_ps;
                        }
                    }
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to get margin for setup,hold and total eye width in Ps by using frequency
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::get_margin2(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk, l_byte, l_nibble, l_bit = 0;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq = 0;
        uint64_t l_cyc = 1000000000000000ULL;
        uint8_t l_dq = 0;
        uint8_t  l_p = 0;
        uint8_t i_rank = 0;
        uint64_t l_factor = 0;
        uint64_t l_factor_ps = 1000000000;
        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_margin_u32));
        l_freq = l_attr_mss_freq_margin_u32 / 2;
        l_cyc = l_cyc / l_freq; // converting to zepto to get more accurate data
        l_factor = l_cyc / 128;

        //FAPI_INF("Get Margin2 - Preet");

        for (l_p = 0; l_p < MAX_PORTS_PER_MBA; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank = valid_rank1[l_p][l_rnk];

                for(l_byte = 0; l_byte < 10; l_byte++)
                {
                    for(l_nibble = 0; l_nibble < 2; l_nibble++)
                    {
                        for(l_bit = 0; l_bit < 4; l_bit++)
                        {
                            l_dq = 8 * l_byte + 4 * l_nibble + l_bit;

                            if((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]) <= 0 && (iv_shmoo_type == 8))
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] = 0;
                            }

                            if((iv_shmoo_param == 4) || (iv_shmoo_param == 6))
                            {
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] > SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] -
                                            1;
                                }

                                if((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] < SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                   && (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] != 0))
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] +
                                            1;
                                }
                            }
                            else
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] -
                                        1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] +
                                        1;
                            }

                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq] = ((
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] - SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq]) *
                                    l_factor) / l_factor_ps;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq] = ((
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq] - SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]) *
                                    l_factor) / l_factor_ps; //((1/uint32_t_freq*1000000)/128);
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_dq] =
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq] +
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq];
                        } // for bit
                    } // for nibble
                } //for byte
            } //for rank
        } // for port

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to print the information needed such as freq,voltage etc, and also the right,left and total margin
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::print_report2(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk, l_byte, l_nibble, l_bit = 0;
        uint8_t l_p = 0;
        uint8_t i_rank = 0;
        uint8_t l_mbapos = 0;
        uint32_t l_attr_mss_freq_u32 = 0;
        uint32_t l_attr_mss_volt_u32 = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;
        uint16_t l_total_margin = 0;
        uint8_t l_dq = 0;
        uint8_t vrefdq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        char* l_pMike = new char[160];
        char* l_str = new char[128];
        uint8_t l_dram_gen = 1;
        uint8_t l_param_valid = 0;
        uint32_t base_percent = 60000;
        uint32_t index_mul_print = 650;
        uint32_t vref_val_print = 0;
        uint8_t vrefdq_train_range[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint32_t l_attr_rd_vred_vpd_value[2] = {0};
        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target, vrefdq_train_range));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target, l_dram_gen));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target, vrefdq_train_value));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_SCHMOO_PARAM_VALID, i_target, l_param_valid));

        if(vrefdq_train_range[0][0][0] == 1)
        {
            base_percent = 45000;
        }

        if (iv_shmoo_type == 2)
        {
            vref_val_print = base_percent + (vrefdq_train_value[0][0][0] * index_mul_print);
        }

        else if((iv_shmoo_type == 8) && (l_param_valid != fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_PARAM_VALID_RD_VREF))
        {
            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_VPD_RD_VREF, i_target, l_attr_rd_vred_vpd_value));
            //FAPI_INF("Rd_From VPD = %d",l_attr_rd_vred_vpd_value[0]);
            vref_val_print = l_attr_rd_vred_vpd_value[0];
        }
        else if((iv_shmoo_type == 8) && (l_param_valid == fapi2::ENUM_ATTR_CEN_EFF_SCHMOO_PARAM_VALID_RD_VREF))
        {
            FAPI_INF("Rd_From iv_vref_mul = %d", iv_vref_mul);
            vref_val_print = iv_vref_mul;
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_target_centaur, l_attr_mss_volt_u32));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target, l_attr_eff_dimm_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, i_target,
                               l_attr_eff_num_drops_per_port_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target,
                               l_attr_eff_dram_width_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbapos));

        FAPI_INF("%s: freq = %d on %s.", mss::c_str(i_target),
                 l_attr_mss_freq_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s: volt = %d on %s.", mss::c_str(i_target),
                 l_attr_mss_volt_u32, mss::c_str(l_target_centaur));
        FAPI_INF("%s: dimm_type = %d on %s.", mss::c_str(i_target),
                 l_attr_eff_dimm_type_u8, mss::c_str(i_target));
        //FAPI_INF("%s: +++ Preet1 %d +++ ", mss::c_str(i_target),vref_val_print);

        if (l_attr_eff_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            FAPI_INF("%s: It is a CDIMM", mss::c_str(i_target));
        }
        else
        {
            FAPI_INF("%s: It is an ISDIMM", mss::c_str(i_target));
        }

        FAPI_INF("%s: \n Number of ranks on port = 0 is %d ",
                 mss::c_str(i_target), iv_MAX_RANKS[0]);
        FAPI_INF("%s: \n Number of ranks on port = 1 is %d \n \n",
                 mss::c_str(i_target), iv_MAX_RANKS[1]);

        FAPI_INF("dram_width = %d  \n\n", l_attr_eff_dram_width_u8);
        FAPI_INF("%s:+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
                 mss::c_str(i_target));
        //// Based on schmoo param the print will change eventually

        if (iv_shmoo_type == 0)
        {
            sprintf(l_pMike,
                    "Schmoo  POS\tPort\tRank\tByte\tnibble\t\tNominal\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ");
        }
        else
        {
            sprintf(l_pMike,
                    "Schmoo  POS\tPort\tRank\tByte\tnibble\t\tNominal\tSetup_Limit\tHold_Limit\tRdD_Setup(ps)\tRdD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ");
        }

        //FAPI_INF("Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit \n");
        FAPI_INF("%s", l_pMike);
        delete[] l_pMike;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank = valid_rank1[l_p][l_rnk];

                for (l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
                {
                    //Nibble loop
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        for (l_bit = 0; l_bit < MAX_BITS; l_bit++)
                        {
                            l_dq = (BITS_PER_BYTE * l_byte) + (BITS_PER_NIBBLE * l_nibble) + l_bit;
                            l_total_margin
                                = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq]
                                  + SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq];

                            if(l_dram_gen == 2)
                            {
                                sprintf(l_str, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
                                        l_mbapos, l_p, i_rank, l_byte, l_nibble, l_bit,
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],
                                        l_total_margin, l_attr_mss_freq_u32, vref_val_print);
                            }
                            else
                            {
                                sprintf(l_str, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
                                        l_mbapos, l_p, i_rank, l_byte, l_nibble, l_bit,
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],
                                        l_total_margin, l_attr_mss_freq_u32, iv_vref_mul);
                            }

                            if (iv_shmoo_type == 2)
                            {
                                FAPI_IMP("WR_EYE %s ", l_str);

                            }

                            if (iv_shmoo_type == 8)
                            {
                                FAPI_IMP("RD_EYE %s ", l_str);

                            }
                        } // end for bit
                    } // end for nibble
                } // end for byte
            } // end for rank
        } // end for port

        delete[] l_str;
    fapi_try_exit:
        return fapi2::current_err;
    }

    fapi2::ReturnCode generic_shmoo::get_margin_dqs_by4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk = 0;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq = 0;
        uint64_t l_cyc = 1000000000000000ULL;
        uint8_t l_nibble = 0;
        uint8_t  l_p = 0;
        uint8_t i_rank = 0;
        uint64_t l_factor = 0;
        uint64_t l_factor_ps = 1000000000;
        uint8_t l_SCHMOO_NIBBLES = 20;

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_margin_u32));
        l_freq = l_attr_mss_freq_margin_u32 / 2;
        l_cyc = l_cyc / l_freq; // converting to zepto to get more accurate data
        l_factor = l_cyc / 128;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {

            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank = valid_rank1[l_p][l_rnk];
                //Nibble loop

                for(l_nibble = 0; l_nibble < l_SCHMOO_NIBBLES; l_nibble++)
                {
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble] =
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble] - 1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble] =
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble] + 1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble] = ((
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble] -
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble]) * l_factor) / l_factor_ps;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble] = ((
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble] -
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble]) * l_factor) /
                            l_factor_ps; //((1/uint32_t_freq*1000000)/128);
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble] =
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble] +
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble];

                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to get margin for setup,hold and total eye width in Ps by using frequency
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::get_margin_dqs_by8(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t l_rnk = 0;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq = 0;
        uint64_t l_cyc = 1000000000000000ULL;
        uint8_t l_nibble = 0;
        uint8_t  l_p = 0;
        uint8_t i_rank = 0;
        uint64_t l_factor = 0;
        uint64_t l_factor_ps = 1000000000;
        uint8_t l_SCHMOO_NIBBLES = 20;

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 9;
        }

        const auto l_target_centaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_attr_mss_freq_margin_u32));
        l_freq = l_attr_mss_freq_margin_u32 / 2;
        l_cyc = l_cyc / l_freq; // converting to zepto to get more accurate data
        l_factor = l_cyc / 128;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank = valid_rank1[l_p][l_rnk];

                for(l_nibble = 0; l_nibble < l_SCHMOO_NIBBLES; l_nibble++)
                {
                    if(iv_dmm_type == 0)
                    {
                        if((l_nibble % 2))
                        {
                            continue ;
                        }
                    }

                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble] =
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble] - 1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble] =
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble] + 1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble] = ((
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble] -
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble]) * l_factor) / l_factor_ps;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble] = ((
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble] -
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble]) * l_factor) /
                            l_factor_ps; //((1/uint32_t_freq*1000000)/128);
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble] =
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble] +
                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble];
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief used to find right and left bound
    /// @param[in] i_target Centaur input MBA
    /// @param[in] bound RIGHT/LEFT
    /// @param[in] scenario type of shmoo
    /// @param[in] bit 0-3
    /// @param[in] pass
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::knob_update_bin_composite(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            bound_t bound, uint8_t scenario, uint8_t bit, uint8_t pass)
    {
        fapi2::buffer<uint64_t> data_buffer_64(64);
        fapi2::buffer<uint64_t> data_buffer_64_1(64);
        input_type_t l_input_type_e = WR_DQ;
        uint8_t l_n = 0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_dq = 0;
        uint8_t l_i = 0;
        uint8_t l_flag_p0 = 0;
        uint8_t l_flag_p1 = 0;
        FAPI_INF("SHMOOING VIA COMPOSITE EYE  FW !!!!");
        uint8_t l_p = 0;
        uint8_t rank = 0;
        uint8_t l_rank = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_status = 1;
        uint8_t l_CDarray0[80] = {0};
        uint8_t l_CDarray1[80] = {0};
        int count_cycle = 0;

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
        }
        else if(iv_shmoo_type == 4)
        {
            l_input_type_e = WR_DQS;
        }
        else if(iv_shmoo_type == 16)
        {
            l_input_type_e = RD_DQS;
        }

        FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");

        //Reset schmoo_error_map
        for(l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for(uint8_t i = 0; i < iv_MAX_RANKS[l_p]; i++)
            {

                rank = valid_rank1[l_p][i];

                for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                {
                    schmoo_error_map[l_p][rank][l_n] = 0;
                    binary_done_map[l_p][rank][l_n] = 0;
                }
            }
        }

        if(bound == RIGHT)
        {
            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                do
                {
                    l_status = 0;
                    FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq));

                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        rank = valid_rank1[l_p][l_rank];

                        for(l_dq = 0; l_dq < 4; l_dq++)
                        {
                            for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                            {
                                if(binary_done_map[l_p][rank][l_n] == 0)
                                {
                                    l_status = 1;
                                }

                                l_flag_p0 = 0;
                                l_flag_p1 = 0;

                                if(l_p == 0)
                                {
                                    for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                    {
                                        if(l_CDarray0[l_i] == l_dq + l_n * 4)
                                        {
                                            schmoo_error_map[l_p][rank][l_n] = 1;
                                            l_flag_p0 = 1;

                                        }
                                    }
                                }
                                else
                                {
                                    for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                    {

                                        if(l_CDarray1[l_i] == l_dq + l_n * 4)
                                        {
                                            schmoo_error_map[l_p][rank][l_n] = 1;
                                            l_flag_p1 = 1;

                                        }
                                    }
                                }

                                if(schmoo_error_map[l_p][rank][l_n] == 0)
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] =
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4] =
                                        (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] +
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4]) / 2;

                                    FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq + l_n * 4, 0,
                                                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4]));

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] >
                                       SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4])
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];
                                    }
                                    else
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4];
                                    }

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] <= 1)
                                    {
                                        binary_done_map[l_p][rank][l_n] = 1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];
                                        // printf("\n the right bound for port=%d rank=%d dq=%d is %d \n",l_p,rank,l_dq+l_n*4,FAPI_INF.MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
                                    }
                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4] =
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4] =
                                        (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] +
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4]) / 2;

                                    FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq + l_n * 4, 0,
                                                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4]));

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] >
                                       SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4])
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];
                                    }
                                    else
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4];
                                    }

                                    if(l_p == 0)
                                    {
                                        if(l_flag_p0 == 1)
                                        {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] = 1;
                                        }
                                    }
                                    else
                                    {
                                        if(l_flag_p1 == 1)
                                        {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] = 1;
                                        }
                                    }

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] <= 1)
                                    {
                                        binary_done_map[l_p][rank][l_n] = 1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];

                                    }
                                } // end else (schmoo_error_map[l_p][rank][l_n] != 0)
                            } // end for nibble
                        } // end for dq
                    } // end for rank


                    FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");
                    FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
                    FAPI_TRY(check_error_map(i_target, l_p, pass));
                    //FAPI_INF("\n the status =%d \n",l_status);
                    count_cycle++;
                } // end do

                while(l_status == 1);
            } // end for port

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for(l_dq = 0; l_dq < 4; l_dq++)
                    {
                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq + l_n * 4, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq + l_n * 4]));
                        }
                    }
                }
            }
        }

        count_cycle = 0;

        if(bound == LEFT)
        {
            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                l_status = 1;

                while(l_status == 1)
                {
                    l_status = 0;

                    FAPI_TRY(mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1, count_bad_dq));

                    for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        rank = valid_rank1[l_p][l_rank];

                        for(l_dq = 0; l_dq < 4; l_dq++)
                        {
                            for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                            {
                                if(binary_done_map[l_p][rank][l_n] == 0)
                                {
                                    l_status = 1;
                                }

                                l_flag_p0 = 0;
                                l_flag_p1 = 0;

                                if(l_p == 0)
                                {
                                    for(l_i = 0; l_i < count_bad_dq[0]; l_i++)
                                    {
                                        if(l_CDarray0[l_i] == l_dq + l_n * 4)
                                        {
                                            schmoo_error_map[l_p][rank][l_n] = 1;
                                            l_flag_p0 = 1;

                                        }
                                    }
                                }
                                else
                                {
                                    for(l_i = 0; l_i < count_bad_dq[1]; l_i++)
                                    {

                                        if(l_CDarray1[l_i] == l_dq + l_n * 4)
                                        {
                                            schmoo_error_map[l_p][rank][l_n] = 1;
                                            l_flag_p1 = 1;

                                        }
                                    }
                                }

                                if(schmoo_error_map[l_p][rank][l_n] == 0)
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] =
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4] =
                                        (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] +
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4]) / 2;

                                    FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq + l_n * 4, 0,
                                                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4]));

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] >
                                       SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4])
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];
                                    }
                                    else
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4];
                                    }

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] <= 1)
                                    {
                                        binary_done_map[l_p][rank][l_n] = 1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];

                                    }
                                }
                                else
                                {

                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4] =
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4] =
                                        (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] +
                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4]) / 2;

                                    FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq + l_n * 4, 0,
                                                                         SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq + l_n * 4]));

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] >
                                       SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4])
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];
                                    }
                                    else
                                    {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4] -
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq + l_n * 4];
                                    }


                                    if(l_p == 0)
                                    {
                                        if(l_flag_p0 == 1)
                                        {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] = 1;
                                        }
                                    }
                                    else
                                    {
                                        if(l_flag_p1 == 1)
                                        {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] = 1;
                                        }
                                    }

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq + l_n * 4] <= 1)
                                    {
                                        binary_done_map[l_p][rank][l_n] = 1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq + l_n * 4] =
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq + l_n * 4];

                                    }
                                }
                            }
                        }
                    }

                    FAPI_TRY(do_mcbist_reset(i_target), "generic_shmoo::find_bound do_mcbist_reset failed");
                    FAPI_TRY(do_mcbist_test(i_target), "generic_shmoo::find_bound do_mcbist_test failed");
                    FAPI_TRY(check_error_map(i_target, l_p, pass), "generic_shmoo::find_bound do_mcbist_test failed");
                    count_cycle++;
                }
            }

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank = 0; l_rank < iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank = valid_rank1[l_p][l_rank];

                    for(l_dq = 0; l_dq < 4; l_dq++)
                    {
                        for (l_n = 0; l_n < l_SCHMOO_NIBBLES; l_n++)
                        {
                            FAPI_TRY(mss_access_delay_reg_schmoo(i_target, l_access_type_e, l_p, rank, l_input_type_e, l_dq + l_n * 4, 0,
                                                                 SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq + l_n * 4]));
                        }
                    }
                }
            }
        } // End of LEFT

    fapi_try_exit:
        return fapi2::current_err;

    }

    ///
    /// @brief Sets the PDA nibble table  with shmoo values
    /// @param[in] i_target Centaur input MBA
    /// @param[in] pda_nibble_table Per nibble vref + margins
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::get_nibble_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint32_t pda_nibble_table[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM][16][2])
    {
        uint8_t l_dimm = 0;
        uint8_t num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, num_ranks_per_dimm));

        for(uint8_t l_p = 0; l_p < MAX_PORTS_PER_MBA; l_p++)
        {
            for (l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
            {
                for(uint8_t l_rnk = 0; l_rnk < num_ranks_per_dimm[l_p][l_dimm]; l_rnk++)
                {
                    for(uint8_t l_dq = 0; l_dq < 4; l_dq++)
                    {
                        for(uint8_t l_n = 0; l_n < 16; l_n++)
                        {
                            pda_nibble_table[l_p][l_dimm][l_rnk][l_n][0] = iv_vref_mul;

                            if(l_dimm == 0)
                            {
                                pda_nibble_table[l_p][l_dimm][l_rnk][l_n][1] = SHMOO[iv_DQS_ON].MBA.P[l_p].S[l_rnk].K.total_margin[l_dq + l_n * 4];
                            }
                            else
                            {
                                pda_nibble_table[l_p][l_dimm][l_rnk][l_n][1] = SHMOO[iv_DQS_ON].MBA.P[l_p].S[l_rnk + 4].K.total_margin[l_dq + l_n * 4];
                            }
                        }
                    }
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function is used to get the minimum margin of all the schmoo margins
    /// @param[in] i_target Centaur input MBA
    /// @param[out] o_right_min_margin Minimum hold margin
    /// @param[out] o_left_min_margin Minimum setup margin
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    void generic_shmoo::get_min_margin2(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint32_t* o_right_min_margin,
                                        uint32_t* o_left_min_margin)
    {
        uint8_t l_rnk, l_byte, l_nibble, l_bit, i_rank = 0;
        uint16_t l_temp_right = 4800;
        uint16_t l_temp_left = 4800;
        uint8_t l_dq = 0;
        uint8_t l_p = 0;
        FAPI_INF("In GET_MIN_MARGIN - iv_shmoo_type = %d", iv_shmoo_type);

        for (l_p = 0; l_p < 2; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {

                i_rank = valid_rank1[l_p][l_rnk];

                ////
                for (l_byte = 0; l_byte < 10; l_byte++)
                {
                    //Nibble loop
                    for (l_nibble = 0; l_nibble < 2; l_nibble++)
                    {
                        for (l_bit = 0; l_bit < 4; l_bit++)
                        {
                            l_dq = 8 * l_byte + 4 * l_nibble + l_bit;

                            if ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq]
                                 < l_temp_right) && (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq] != 0 ))
                            {
                                l_temp_right
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq];
                            }

                            if ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq]
                                 < l_temp_left) && (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq] != 0))
                            {
                                l_temp_left
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq];
                            }
                        }
                    }
                }
            }
        }

        if(iv_shmoo_type == 8)
        {
            *o_right_min_margin = l_temp_left;
            *o_left_min_margin = l_temp_right;
        }
        else
        {
            *o_right_min_margin = l_temp_right;
            *o_left_min_margin = l_temp_left;
        }
    }

    ///
    /// @brief This function is used to get the minimum margin of all the schmoo margins
    /// @param[in] i_target Centaur input MBA
    /// @param[out] o_right_min_margin Minimum hold margin
    /// @param[out] o_left_min_margin Minimum setup margin
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::get_min_margin_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint32_t* o_right_min_margin, uint32_t* o_left_min_margin)
    {
        uint8_t l_rnk, l_nibble, i_rank = 0;
        uint16_t l_temp_right = 4800;
        uint16_t l_temp_left = 4800;
        uint8_t l_p = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_by8_dqs = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, l_attr_eff_dram_width_u8));

        if(iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        if(l_attr_eff_dram_width_u8 == 8)
        {
            l_SCHMOO_NIBBLES = 10;

            if(iv_dmm_type == 1)
            {
                l_SCHMOO_NIBBLES = 9;
            }
        }

        iv_shmoo_type = 4;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank = valid_rank1[l_p][l_rnk];

                for(l_nibble = 0; l_nibble < l_SCHMOO_NIBBLES; l_nibble++)
                {
                    l_by8_dqs = l_nibble;

                    if(iv_dmm_type == 0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_nibble * 2;
                        }
                    }

                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble] < l_temp_right)
                    {
                        l_temp_right = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble];
                    }

                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble] < l_temp_left)
                    {
                        l_temp_left = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble];
                    }

                    if(iv_dmm_type == 0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_by8_dqs;
                        }
                    }
                } // for nibble
            } // for rank
        } // for port


        // hacked for now till schmoo is running
        if(iv_shmoo_type == 8)
        {
            *o_right_min_margin = l_temp_left;
            *o_left_min_margin = l_temp_right;
        }
        else
        {
            *o_right_min_margin = l_temp_right;
            *o_left_min_margin = l_temp_left;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief call setup_mcbist
    /// @param[in] i_target Centaur input MBA
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode generic_shmoo::schmoo_setup_mcb(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {

        struct subtest_info l_sub_info[30] = {0};
        uint32_t l_pattern = 0;
        uint32_t l_testtype = 0;
        mcbist_byte_mask i_mcbbytemask1;
        char l_str_cust_addr[] =
            "ba0,ba1,mr3,mr2,mr1,mr0,ba2,ba3,cl2,cl3,cl4,cl5,cl6,cl7,cl8,cl9,cl11,cl13,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,sl2,sl1,sl0";

        i_mcbbytemask1 = UNMASK_ALL;
        l_pattern = iv_pattern;
        l_testtype = iv_test_type;

        if (iv_shmoo_type == 16)
        {
            FAPI_INF("%s:\n Read DQS is running \n", mss::c_str(i_target));

            if (iv_SHMOO_ON == 1)
            {
                l_testtype = 3;
            }

            if (iv_SHMOO_ON == 2)
            {
                l_testtype = 4;
            }
        }

        //send shmoo mode to vary the address range
        if (iv_shmoo_type == 16)
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_PATTERN, i_target, l_pattern));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MCBIST_TEST_TYPE, i_target, l_testtype));
        }

        FAPI_TRY(setup_mcbist(i_target, i_mcbbytemask1, 0, 0x0ull , l_sub_info, l_str_cust_addr));
    fapi_try_exit:
        return fapi2::current_err;
    }

}//Extern C
