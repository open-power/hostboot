/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_config_rank_group.C $ */
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

/// @file p9c_mss_eff_config_rank_group.C
/// @brief  Takes in attributes and determines proper rank groupings that will be applied to the system
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Anuwat Saetow <asaetow@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
///


// This procedure takes in attributes and determines proper rank groupings that will be apply to the system and used during draminit_training and draminit_training_adv. Each valid rank in the system will be assigned to one of twelve attributes below. Only the primary rank group will be calibrated and have values stored in the delay registers.
//    EFF_PRIMARY_RANK_GROUP0,    EFF_PRIMARY_RANK_GROUP1,    EFF_PRIMARY_RANK_GROUP2,    EFF_PRIMARY_RANK_GROUP3
//    EFF_SECONDARY_RANK_GROUP0,  EFF_SECONDARY_RANK_GROUP1,  EFF_SECONDARY_RANK_GROUP2,  EFF_SECONDARY_RANK_GROUP3
//    EFF_TERTIARY_RANK_GROUP0,   EFF_TERTIARY_RANK_GROUP1,   EFF_TERTIARY_RANK_GROUP2,   EFF_TERTIARY_RANK_GROUP3
//    EFF_QUATERNARY_RANK_GROUP0, EFF_QUATERNARY_RANK_GROUP1, EFF_QUATERNARY_RANK_GROUP2, EFF_QUATERNARY_RANK_GROUP3

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>

extern "C" {

    ///
    /// @brief mss_eff_config_rank_group determines proper rank groupings
    /// @param[in] i_target_mba
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_rank_group(const fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target_mba)
    {
        const char* const PROCEDURE_NAME = "mss_eff_config_rank_group";
        FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, mss::c_str(i_target_mba));

        uint8_t num_ranks_per_dimm_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_num_master_ranks[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t dram_gen_u8 = 0;
        uint8_t dimm_type_u8 = 0;
        uint8_t l_stack_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t primary_rank_group0_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t primary_rank_group1_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t primary_rank_group2_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t primary_rank_group3_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t secondary_rank_group0_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t secondary_rank_group1_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t secondary_rank_group2_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t secondary_rank_group3_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t tertiary_rank_group0_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t tertiary_rank_group1_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t tertiary_rank_group2_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t tertiary_rank_group3_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t quanternary_rank_group0_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t quanternary_rank_group1_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t quanternary_rank_group2_u8array[MAX_PORTS_PER_MBA] = {0};
        uint8_t quanternary_rank_group3_u8array[MAX_PORTS_PER_MBA] = {0};

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba,  num_ranks_per_dimm_u8array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba,  dram_gen_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target_mba,  dimm_type_u8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba,  l_num_master_ranks));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  l_stack_type));

        for (uint8_t cur_port = 0; cur_port < MAX_PORTS_PER_MBA; cur_port += 1)
        {
            if ((num_ranks_per_dimm_u8array[cur_port][0] > 0) && (num_ranks_per_dimm_u8array[cur_port][1] == 0))    //Single Drop
            {
                primary_rank_group0_u8array[cur_port] = 0;

                if (num_ranks_per_dimm_u8array[cur_port][0] > 1)
                {
                    primary_rank_group1_u8array[cur_port] = 1;
                }
                else
                {
                    primary_rank_group1_u8array[cur_port] = INVALID;
                }

                if (num_ranks_per_dimm_u8array[cur_port][0] > 2)
                {
                    primary_rank_group2_u8array[cur_port] = 2;
                    primary_rank_group3_u8array[cur_port] = 3;
                }
                else
                {
                    primary_rank_group2_u8array[cur_port] = INVALID;
                    primary_rank_group3_u8array[cur_port] = INVALID;
                }

                secondary_rank_group0_u8array[cur_port] = INVALID;
                secondary_rank_group1_u8array[cur_port] = INVALID;
                secondary_rank_group2_u8array[cur_port] = INVALID;
                secondary_rank_group3_u8array[cur_port] = INVALID;

                //Preet Add 3TSV /2H  Type - Single Drop Case
                //ATTR_EFF_STACK_TYPE <enum>NONE = 0, DDP_QDP = 1, STACK_3DS = 2</enum>

                if((l_num_master_ranks[cur_port][0] != 0) && (dram_gen_u8 == 2) && (l_stack_type[cur_port][0] == 2))
                {
                    if(num_ranks_per_dimm_u8array[cur_port][0] == 2)
                    {
                        primary_rank_group0_u8array[cur_port] = 0;
                        primary_rank_group1_u8array[cur_port] = INVALID;
                        primary_rank_group2_u8array[cur_port] = INVALID;
                        primary_rank_group3_u8array[cur_port] = INVALID;
                        secondary_rank_group0_u8array[cur_port] = 1;
                        secondary_rank_group1_u8array[cur_port] = INVALID;
                        secondary_rank_group2_u8array[cur_port] = INVALID;
                        secondary_rank_group3_u8array[cur_port] = INVALID;
                    }

                    //if 4H
                    else if(num_ranks_per_dimm_u8array[cur_port][0] == 4)
                    {
                        primary_rank_group0_u8array[cur_port] = 0;
                        primary_rank_group1_u8array[cur_port] = INVALID;
                        primary_rank_group2_u8array[cur_port] = INVALID;
                        primary_rank_group3_u8array[cur_port] = INVALID;
                        secondary_rank_group0_u8array[cur_port] = 1;
                        secondary_rank_group1_u8array[cur_port] = INVALID;
                        secondary_rank_group2_u8array[cur_port] = INVALID;
                        secondary_rank_group3_u8array[cur_port] = INVALID;
                        tertiary_rank_group0_u8array[cur_port] = 2;
                        tertiary_rank_group1_u8array[cur_port] = INVALID;
                        tertiary_rank_group2_u8array[cur_port] = INVALID;
                        tertiary_rank_group3_u8array[cur_port] = INVALID;
                        quanternary_rank_group0_u8array[cur_port] = 3;
                        quanternary_rank_group1_u8array[cur_port] = INVALID;
                        quanternary_rank_group2_u8array[cur_port] = INVALID;
                        quanternary_rank_group3_u8array[cur_port] = INVALID;
                    }

                    //if 8H   <Add Later if Required>
                } //end of if 3DS Stack
            }
            else if ((num_ranks_per_dimm_u8array[cur_port][0] > 0) && (num_ranks_per_dimm_u8array[cur_port][1] > 0)) //Dual Drop
            {
                if (num_ranks_per_dimm_u8array[cur_port][0] != num_ranks_per_dimm_u8array[cur_port][1])
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_EFF_CONFIG_RANK_GROUP_NON_MATCH_RANKS().
                                set_TARGET_MBA(i_target_mba),
                                "Plug rule violation, num_ranks_per_dimm=%d[0],%d[1] on %s PORT%d!", num_ranks_per_dimm_u8array[cur_port][0],
                                num_ranks_per_dimm_u8array[cur_port][1], mss::c_str(i_target_mba), cur_port);
                }

                primary_rank_group0_u8array[cur_port] = 0;
                primary_rank_group1_u8array[cur_port] = 4;
                primary_rank_group2_u8array[cur_port] = INVALID;
                primary_rank_group3_u8array[cur_port] = INVALID;
                secondary_rank_group0_u8array[cur_port] = INVALID;
                secondary_rank_group1_u8array[cur_port] = INVALID;
                secondary_rank_group2_u8array[cur_port] = INVALID;
                secondary_rank_group3_u8array[cur_port] = INVALID;

                if (num_ranks_per_dimm_u8array[cur_port][0] == 2)
                {
                    primary_rank_group2_u8array[cur_port] = 1;
                    primary_rank_group3_u8array[cur_port] = 5;
                }
                else if (num_ranks_per_dimm_u8array[cur_port][0] == 4)
                {
                    primary_rank_group2_u8array[cur_port] = 2;
                    primary_rank_group3_u8array[cur_port] = 6;
                    secondary_rank_group0_u8array[cur_port] = 1;
                    secondary_rank_group1_u8array[cur_port] = 5;
                    secondary_rank_group2_u8array[cur_port] = 3;
                    secondary_rank_group3_u8array[cur_port] = 7;
                }
                else if (num_ranks_per_dimm_u8array[cur_port][0] != 1)
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_EFF_CONFIG_RANK_GROUP_NUM_RANKS_NEQ1().
                                set_TARGET_MBA(i_target_mba),
                                "Plug rule violation, num_ranks_per_dimm=%d[0],%d[1] on %s PORT%d!", num_ranks_per_dimm_u8array[cur_port][0],
                                num_ranks_per_dimm_u8array[cur_port][1], mss::c_str(i_target_mba), cur_port);

                }

                //Preet Add 3TSV
                if((l_num_master_ranks[cur_port][0] != 0) && (dram_gen_u8 == 2) && (l_stack_type[cur_port][0] == 2))
                {
                    //2H Type - Dual Drop Case
                    if(num_ranks_per_dimm_u8array[cur_port][0] == 2)
                    {
                        primary_rank_group0_u8array[cur_port] = 0;
                        primary_rank_group1_u8array[cur_port] = 4;
                        primary_rank_group2_u8array[cur_port] = INVALID;
                        primary_rank_group3_u8array[cur_port] = INVALID;
                        secondary_rank_group0_u8array[cur_port] = INVALID;
                        secondary_rank_group1_u8array[cur_port] = INVALID;
                        secondary_rank_group2_u8array[cur_port] = INVALID;
                        secondary_rank_group3_u8array[cur_port] = INVALID;
                    }
                    //if 4H
                    else if(num_ranks_per_dimm_u8array[cur_port][0] == 4)
                    {
                        primary_rank_group0_u8array[cur_port] = 0;
                        primary_rank_group1_u8array[cur_port] = 4;
                        primary_rank_group2_u8array[cur_port] = INVALID;
                        primary_rank_group3_u8array[cur_port] = INVALID;
                        secondary_rank_group0_u8array[cur_port] = INVALID;
                        secondary_rank_group1_u8array[cur_port] = INVALID;
                        secondary_rank_group2_u8array[cur_port] = INVALID;
                        secondary_rank_group3_u8array[cur_port] = INVALID;
                        tertiary_rank_group0_u8array[cur_port] = INVALID;
                        tertiary_rank_group1_u8array[cur_port] = INVALID;
                        tertiary_rank_group2_u8array[cur_port] = INVALID;
                        tertiary_rank_group3_u8array[cur_port] = INVALID;
                        quanternary_rank_group0_u8array[cur_port] = INVALID;
                        quanternary_rank_group1_u8array[cur_port] = INVALID;
                        quanternary_rank_group2_u8array[cur_port] = INVALID;
                        quanternary_rank_group3_u8array[cur_port] = INVALID;
                    }

                    //if 8H   <Add Later if Required>
                } //end of if 3DS Stack
            }
            else if ((num_ranks_per_dimm_u8array[cur_port][0] == 0) && (num_ranks_per_dimm_u8array[cur_port][1] == 0))
            {
                primary_rank_group0_u8array[cur_port] = INVALID;
                primary_rank_group1_u8array[cur_port] = INVALID;
                primary_rank_group2_u8array[cur_port] = INVALID;
                primary_rank_group3_u8array[cur_port] = INVALID;
                secondary_rank_group0_u8array[cur_port] = INVALID;
                secondary_rank_group1_u8array[cur_port] = INVALID;
                secondary_rank_group2_u8array[cur_port] = INVALID;
                secondary_rank_group3_u8array[cur_port] = INVALID;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_RANK_GROUP_NO_MATCH().
                            set_TARGET_MBA(i_target_mba),
                            "Plug rule violation, num_ranks_per_dimm=%d[0],%d[1] on %s PORT%d!", num_ranks_per_dimm_u8array[cur_port][0],
                            num_ranks_per_dimm_u8array[cur_port][1], mss::c_str(i_target_mba), cur_port);

            }

            tertiary_rank_group0_u8array[cur_port] = INVALID;
            tertiary_rank_group1_u8array[cur_port] = INVALID;
            tertiary_rank_group2_u8array[cur_port] = INVALID;
            tertiary_rank_group3_u8array[cur_port] = INVALID;
            quanternary_rank_group0_u8array[cur_port] = INVALID;
            quanternary_rank_group1_u8array[cur_port] = INVALID;
            quanternary_rank_group2_u8array[cur_port] = INVALID;
            quanternary_rank_group3_u8array[cur_port] = INVALID;

            FAPI_INF("P[%02d][%02d][%02d][%02d],S[%02d][%02d][%02d][%02d],T[%02d][%02d][%02d][%02d],Q[%02d][%02d][%02d][%02d] on %s PORT%d.",
                     primary_rank_group0_u8array[cur_port], primary_rank_group1_u8array[cur_port], primary_rank_group2_u8array[cur_port],
                     primary_rank_group3_u8array[cur_port], secondary_rank_group0_u8array[cur_port], secondary_rank_group1_u8array[cur_port],
                     secondary_rank_group2_u8array[cur_port], secondary_rank_group3_u8array[cur_port],
                     tertiary_rank_group0_u8array[cur_port], tertiary_rank_group1_u8array[cur_port], tertiary_rank_group2_u8array[cur_port],
                     tertiary_rank_group3_u8array[cur_port], quanternary_rank_group0_u8array[cur_port],
                     quanternary_rank_group1_u8array[cur_port], quanternary_rank_group2_u8array[cur_port],
                     quanternary_rank_group3_u8array[cur_port], mss::c_str(i_target_mba), cur_port);
        } // For port

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target_mba, primary_rank_group0_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target_mba, primary_rank_group1_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target_mba, primary_rank_group2_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target_mba, primary_rank_group3_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP0, i_target_mba, secondary_rank_group0_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP1, i_target_mba, secondary_rank_group1_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP2, i_target_mba, secondary_rank_group2_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP3, i_target_mba, secondary_rank_group3_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP0, i_target_mba, tertiary_rank_group0_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP1, i_target_mba, tertiary_rank_group1_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP2, i_target_mba, tertiary_rank_group2_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP3, i_target_mba, tertiary_rank_group3_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0, i_target_mba, quanternary_rank_group0_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1, i_target_mba, quanternary_rank_group1_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2, i_target_mba, quanternary_rank_group2_u8array));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3, i_target_mba, quanternary_rank_group3_u8array));

        FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, mss::c_str(i_target_mba));
    fapi_try_exit:
        return fapi2::current_err;
    } //rank group
} // extern "C"
