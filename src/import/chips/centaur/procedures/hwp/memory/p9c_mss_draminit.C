/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_draminit.C $ */
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
/// @file p9c_mss_draminit.C
/// @brief HWP for initializing DRAM in accordance w JEDEC Spec
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB CI
//
//----------------------------------------------------------------------
//  FAPI function Includes
//----------------------------------------------------------------------

#include <fapi2.H>

//----------------------------------------------------------------------
//  Centaur function Includes
//----------------------------------------------------------------------
#include <dimmConsts.H>
#include <p9c_mss_funcs.H>
#include "cen_gen_scom_addresses.H"
#include <p9c_mss_unmask_errors.H>
#include <p9c_mss_ddr4_funcs.H>
#include <p9c_mss_funcs.H>
#include <p9c_mss_draminit.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C" {

    /// @brief Draminit procedure. Loading RCD and MRS into the drams.
    /// @param[in]  i_target  Reference to centaur.mba target
    /// @return ReturnCode
    fapi2::ReturnCode p9c_mss_draminit(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint32_t l_port_number = 0;
        uint32_t l_ccs_inst_cnt = 0;
        uint8_t l_dram_gen = 0;
        uint8_t l_dimm_type = 0;
        uint8_t l_rank_pair_group = 0;
        uint8_t l_bit_position = 0;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::variable_buffer mrs0(16);
        fapi2::variable_buffer mrs1(16);
        fapi2::variable_buffer mrs2(16);
        fapi2::variable_buffer mrs3(16);
        fapi2::variable_buffer mrs4(16);
        fapi2::variable_buffer mrs5(16);
        fapi2::variable_buffer mrs6(16);
        uint8_t l_num_drops_per_port = 0;
        uint8_t l_primary_ranks_array[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {}; //primary_ranks_array[group][port]
        uint8_t l_secondary_ranks_array[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {}; //secondary_ranks_array[group][port]
        uint8_t l_tertiary_ranks_array[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {}; //tertiary_ranks_array[group][port]
        uint8_t l_quaternary_ranks_array[NUM_RANK_GROUPS][MAX_PORTS_PER_MBA] = {}; //quaternary_ranks_array[group][port]
        uint8_t l_is_sim = 0;
        uint8_t l_pri_dimm = 0;
        uint8_t l_pri_dimm_rank = 0;
        uint8_t l_sec_dimm = 0;
        uint8_t l_sec_dimm_rank = 0;
        uint8_t l_ter_dimm = 0;
        uint8_t l_ter_dimm_rank = 0;
        uint8_t l_qua_dimm = 0;
        uint8_t l_qua_dimm_rank = 0;
        uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //address_mirror_map[port][dimm]

        //populate primary_ranks_arrays_array
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target,  l_primary_ranks_array[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target,  l_primary_ranks_array[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target,  l_primary_ranks_array[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target,  l_primary_ranks_array[3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP0, i_target,  l_secondary_ranks_array[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP1, i_target,  l_secondary_ranks_array[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP2, i_target,  l_secondary_ranks_array[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP3, i_target,  l_secondary_ranks_array[3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP0, i_target,  l_tertiary_ranks_array[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP1, i_target,  l_tertiary_ranks_array[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP2, i_target,  l_tertiary_ranks_array[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP3, i_target,  l_tertiary_ranks_array[3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0, i_target,  l_quaternary_ranks_array[0]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1, i_target,  l_quaternary_ranks_array[1]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2, i_target,  l_quaternary_ranks_array[2]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3, i_target,  l_quaternary_ranks_array[3]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, i_target,  l_num_drops_per_port));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target,  l_dram_gen));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target,  l_dimm_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target,  l_address_mirror_map));



        // Check to see if any dimm needs address mirror mode.  Set the approriate flag.
        if ( ( l_address_mirror_map[0][0] ||
               l_address_mirror_map[0][1] ||
               l_address_mirror_map[1][0] ||
               l_address_mirror_map[1][1] )
             && (l_is_sim == 0)   )
        {

            FAPI_INF( "Setting Address Mirroring in the PHY on %s ", mss::c_str(i_target));

            //Set the Address and BA bits affected by mirroring
            if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3)
            {
                FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));
                l_data_buffer_64.setBit<58, 3>();
                l_data_buffer_64.setBit<62>();
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));

                FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));
                l_data_buffer_64.setBit<58, 3>();
                l_data_buffer_64.setBit<62>();
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));
            }

            if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
            {
                FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));
                l_data_buffer_64.setBit<58, 6>();
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));

                FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));
                l_data_buffer_64.setBit<58, 6>();
                FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));
            }

            for ( l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
            {
                for ( l_rank_pair_group = 0; l_rank_pair_group < MAX_RANKS_PER_DIMM; l_rank_pair_group++)
                {
                    // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
                    l_pri_dimm = (l_primary_ranks_array[l_rank_pair_group][l_port_number]) / 4;
                    l_pri_dimm_rank = l_primary_ranks_array[l_rank_pair_group][l_port_number] - 4 * l_pri_dimm;
                    l_sec_dimm = (l_secondary_ranks_array[l_rank_pair_group][l_port_number]) / 4;
                    l_sec_dimm_rank = l_secondary_ranks_array[l_rank_pair_group][l_port_number] - 4 * l_sec_dimm;
                    l_ter_dimm = (l_tertiary_ranks_array[l_rank_pair_group][l_port_number]) / 4;
                    l_ter_dimm_rank = l_tertiary_ranks_array[l_rank_pair_group][l_port_number] - 4 * l_ter_dimm;
                    l_qua_dimm = (l_quaternary_ranks_array[l_rank_pair_group][l_port_number]) / 4;
                    l_qua_dimm_rank = l_quaternary_ranks_array[l_rank_pair_group][l_port_number] - 4 * l_qua_dimm;

                    // Set the rank pairs that will be affected.
                    if ( l_port_number == 0 )
                    {
                        if ( ( ( l_address_mirror_map[l_port_number][l_pri_dimm] & (0x08 >> l_pri_dimm_rank) ) )
                             && (l_primary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", mss::c_str(i_target), l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 48;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));

                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));

                        }

                        if ( ( ( l_address_mirror_map[l_port_number][l_sec_dimm] & (0x08 >> l_sec_dimm_rank) ) )
                             && (l_secondary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", mss::c_str(i_target), l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 49;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));

                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P0, l_data_buffer_64));

                        }

                        if ( ( ( l_address_mirror_map[l_port_number][l_ter_dimm] & (0x08 >> l_ter_dimm_rank) ) )
                             && (l_tertiary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", mss::c_str(i_target), l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 48;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P0, l_data_buffer_64));

                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P0, l_data_buffer_64));

                        }

                        if ( ( ( l_address_mirror_map[l_port_number][l_qua_dimm] & (0x08 >> l_qua_dimm_rank) ) )
                             && (l_quaternary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", mss::c_str(i_target), l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 49;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P0, l_data_buffer_64));

                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P0, l_data_buffer_64));

                        }
                    }

                    if ( l_port_number == 1 )
                    {
                        if ( ( ( l_address_mirror_map[l_port_number][l_pri_dimm] & (0x08 >> l_pri_dimm_rank) ) )
                             && (l_primary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", mss::c_str(i_target), l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 48;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));
                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));
                        }

                        if ( ( ( l_address_mirror_map[l_port_number][l_sec_dimm] & (0x08 >> l_sec_dimm_rank) ) )
                             && (l_secondary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", mss::c_str(i_target), l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 49;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));

                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_P1, l_data_buffer_64));

                        }

                        if ( ( ( l_address_mirror_map[l_port_number][l_ter_dimm] & (0x08 >> l_ter_dimm_rank) ) )
                             && (l_tertiary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on %s PORT%d RANKPAIR%d RANK%d", mss::c_str(i_target), l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 48;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P1, l_data_buffer_64));

                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P1, l_data_buffer_64));

                        }

                        if ( ( ( l_address_mirror_map[l_port_number][l_qua_dimm] & (0x08 >> l_qua_dimm_rank) ) )
                             && (l_quaternary_ranks_array[l_rank_pair_group][l_port_number] != 0xff ) )
                        {
                            FAPI_INF( "Address Mirroring on PORT%d RANKPAIR%d RANK%d", l_port_number, l_rank_pair_group,
                                      l_primary_ranks_array[l_rank_pair_group][l_port_number]);
                            l_bit_position = 2 * l_rank_pair_group + 49;
                            FAPI_INF( "Setting bit %d", l_bit_position);
                            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P1, l_data_buffer_64));

                            FAPI_TRY(l_data_buffer_64.setBit(l_bit_position));
                            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_PC_RANK_GROUP_EXT_P1, l_data_buffer_64));

                        }
                    }

                }
            }
        }

        // Step one: Deassert Force_mclk_low signal
        // this action needs to be done in ddr_phy_reset so that the plls can actually lock

        // Step two: Assert Resetn signal, Begin driving mem clks
        FAPI_TRY(mss_assert_resetn_drive_mem_clks(i_target), " assert_resetn_drive_mem_clks Failed");
        FAPI_TRY(mss_assert_resetn(i_target, 0 ), " assert_resetn Failed"); // assert a reset
        FAPI_TRY(fapi2::delay(DELAY_100US, DELAY_2000SIMCYCLES)); // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
        FAPI_TRY(mss_assert_resetn(i_target, 1 ), " assert_resetn Failed "); // de-assert a reset

        // Cycle through Ports...
        // Ports 0-1
        for ( l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            if (!((l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_UDIMM)
                  || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_CDIMM)))
            {
                // Step three: Load RCD Control Words
                if(l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
                {
                    FAPI_TRY(mss_rcd_load_ddr4(i_target, l_port_number, l_ccs_inst_cnt), " rcd_load Failed");
                }
                else if(l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3)
                {
                    FAPI_TRY(mss_rcd_load(i_target, l_port_number, l_ccs_inst_cnt));
                }
                else
                {
                    FAPI_ERR("%s: DRAM GEN NOT RECOGNIZED", mss::c_str(i_target));
                }
            }
        }

        FAPI_TRY(fapi2::delay(DELAY_500US,
                              DELAY_10000000SIMCYCLES)); // wait 10000 simcycles (in sim mode) OR 500 uS (in hw mode)


        // Cycle through Ports...
        // Ports 0-1
        for ( l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            if (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3)
            {
                FAPI_TRY(mss_mrs_load(i_target, l_port_number, l_ccs_inst_cnt), " mrs_load Failed");
            }
            else if(l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
            {
                // Step four: Load MRS Setting
                FAPI_TRY(mss_mrs_load_ddr4(i_target, l_port_number, l_ccs_inst_cnt), "mrs_load_ddr4 Failed");
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_DRAM_GEN_NOT_RECOGNIZED().
                            set_TARGET_MBA_ERROR(i_target).
                            set_DRAM_GEN(l_dram_gen).
                            set_PORT(l_port_number).
                            set_TARGET(i_target),
                            "%s bad DRAM gen\n", mss::c_str(i_target));
            }
        }

        // Execute the contents of CCS array
        if (l_ccs_inst_cnt  > 0)
        {
            // Set the End bit on the last CCS Instruction
            FAPI_TRY(mss_ccs_set_end_bit( i_target, l_ccs_inst_cnt - 1), "CCS_SET_END_BIT FAILED");
            FAPI_TRY(mss_execute_ccs_inst_array(i_target, DELAY_200000SIMCYCLES, 20), " EXECUTE_CCS_INST_ARRAY FAILED");

            l_ccs_inst_cnt = 0;
        }
        else
        {
            FAPI_INF("No Memory configured.");
        }

        // Cycle through Ports...
        // Ports 0-1
        for ( l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            for ( l_rank_pair_group = 0; l_rank_pair_group < MAX_RANKS_PER_DIMM; l_rank_pair_group++)
            {
                //Check if rank group exists
                if((l_primary_ranks_array[l_rank_pair_group][0] != INVALID) || (l_primary_ranks_array[l_rank_pair_group][1] != INVALID))
                {
                    print_shadow_reg(i_target, l_port_number, l_rank_pair_group);
                }
            }
        }

        if ( (l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) && (l_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM
                || l_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) )
        {
            FAPI_INF("Performing B-side address inversion MPR write pattern");
            FAPI_TRY(mss_ddr4_invert_mpr_write(i_target));
        }

        // If mss_unmask_draminit_errors gets it's own bad rc,
        // it will commit the passed in rc (if non-zero), and return it's own bad rc.
        // Else if mss_unmask_draminit_errors runs clean,
        // it will just return the passed in rc.
        FAPI_TRY(mss_unmask_draminit_errors(i_target));
        FAPI_INF("mss_draminit complete");

    fapi_try_exit:
        return fapi2::current_err;
    }


} //end extern C

