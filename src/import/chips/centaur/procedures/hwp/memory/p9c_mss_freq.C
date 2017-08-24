/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_freq.C $ */
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

/// @file p9c_mss_freq.C
/// @brief DIMM SPD attributes are read to determine optimal DRAM frequency
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamaring@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
///

//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi2.H>
#include <p9c_mss_freq.H>
#include <dimmConsts.H>
#include <generic/memory/lib/utils/c_str.H>
//----------------------------------------------------------------------
// ENUMs
//----------------------------------------------------------------------
enum
{
    MSS_FREQ_EMPTY = 0,
    MSS_FREQ_SINGLE_DROP = 1,
    MSS_FREQ_DUAL_DROP = 2,
    MSS_FREQ_VALID = 255,
};

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
constexpr uint8_t DDR4_MTB_DIVIDEND = 1;
constexpr uint8_t DDR4_MTB_DIVISOR = 8;
constexpr uint8_t DDR4_FTB_DIVIDEND = 1;
constexpr uint8_t DDR4_FTB_DIVISOR = 1;
constexpr uint8_t NUM_CL_SUPPORTED = 21;


///
/// @brief DIMM SPD attributes are read to determine optimal DRAM frequency
/// @param[in] i_target_memb Centaur target
/// @return FAPI2_RC_SUCCESS iff frequency + CL found successfully
///
fapi2::ReturnCode p9c_mss_freq(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target_memb)
{
    uint8_t l_spd_mtb_dividend = 0;
    uint8_t l_spd_mtb_divisor = 0;
    uint8_t l_spd_ftb_dividend = 0;
    uint8_t l_spd_ftb_divisor = 0;
    uint32_t l_dimm_freq_calc = 0;
    uint32_t l_dimm_freq_min = 9999;
    uint8_t l_spd_min_tck_MTB = 0;
    uint8_t l_spd_tck_offset_FTB = 0;
    uint8_t l_spd_tck_offset = 0;
    uint32_t l_spd_min_tck = 0;
    uint32_t l_spd_min_tck_max = 0;
    uint8_t  l_spd_min_taa_MTB = 0;
    uint8_t  l_spd_taa_offset_FTB = 0;
    uint8_t  l_spd_taa_offset = 0;
    uint32_t l_spd_min_taa = 0;
    uint32_t l_spd_min_taa_max = 0;
    uint32_t l_selected_dimm_freq = 0;
    uint32_t l_spd_cas_lat_supported = 0xFFFFFFFF;
    uint32_t l_spd_cas_lat_supported_all = 0xFFFFFFFF;
    uint8_t l_cas_latency = 0;
    uint32_t l_cl_mult_tck = 0;
    uint8_t l_cur_mba_port = 0;
    uint8_t l_cur_mba_dimm = 0;
    uint8_t l_cur_mba = 0;
    uint8_t l_cur_dimm_spd_valid_u8array[MAX_MBA_PER_CEN][MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {{{0}}};
    uint8_t l_plug_config = 0;
    uint8_t l_module_type = 0;
    uint8_t l_module_type_deconfig = 0;
    uint8_t l_module_type_group_1 = 0;
    uint8_t l_module_type_group_2 = 0;
    uint8_t l_module_type_group_1_total = 0;
    uint8_t l_module_type_group_2_total = 0;
    uint8_t l_num_ranks[MAX_MBA_PER_CEN][MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {{{0}}};
    uint8_t l_num_ranks_total = 0;
    uint32_t  l_freq_override = 0;
    uint8_t l_override_path = 0;
    uint8_t l_nest_capable_frequencies = 0;
    uint8_t l_spd_dram_dev_type;
    uint8_t l_spd_tb_mtb_ddr4 = 0;
    uint8_t l_spd_tb_ftb_ddr4 = 0;
    uint8_t l_spd_tckmax_ddr4 = 0;
    uint8_t l_cl_count_array[NUM_CL_SUPPORTED];
    uint8_t l_highest_common_cl = 0;
    uint8_t l_highest_cl_count = 0;
    uint8_t l_lowest_common_cl = 0;
    uint32_t l_lowest_cl_count = 0xFFFFFFFF;

    for(uint8_t i = 0; i < NUM_CL_SUPPORTED; i++)
    {
        l_cl_count_array[i] = 0; // Initializing each element separately
    }

    // Get associated MBA's on this centaur
    const auto l_mbaChiplets = i_target_memb.getChildren<fapi2::TARGET_TYPE_MBA>();

    // Loop through the 2 MBA's
    for (const auto& l_mba : l_mbaChiplets)
    {
        // Get a vector of DIMM targets
        const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

        for (const auto& l_dimm : l_dimm_targets)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, l_dimm,  l_spd_dram_dev_type));

            if (l_spd_dram_dev_type == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
            {
                // DDR4 ONLY
                FAPI_DBG("DDR4 detected");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TIMEBASE_MTB_DDR4, l_dimm,  l_spd_tb_mtb_ddr4));
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TIMEBASE_FTB_DDR4, l_dimm,  l_spd_tb_ftb_ddr4));
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TCKMAX_DDR4, l_dimm,  l_spd_tckmax_ddr4));

                if ( (l_spd_tb_mtb_ddr4 == 0) && (l_spd_tb_ftb_ddr4 == 0))
                {
                    // These are now considered constant within DDR4
                    // If DDR4 spec changes to include other values, these const's need to be updated
                    l_spd_mtb_dividend = DDR4_MTB_DIVIDEND;
                    l_spd_mtb_divisor = DDR4_MTB_DIVISOR;
                    l_spd_ftb_dividend = DDR4_FTB_DIVIDEND;
                    l_spd_ftb_divisor = DDR4_FTB_DIVISOR;
                }
                else
                {
                    //Invalid due to the fact that JEDEC dictates that these should be zero.
                    // Log error and continue to next DIMM
                    FAPI_ASSERT_NOEXIT(false,
                                       fapi2::CEN_MSS_UNSUPPORTED_SPD_DATA_DDR4().
                                       set_MTB_DDR4(l_spd_tb_mtb_ddr4).
                                       set_FTB_DDR4(l_spd_tb_ftb_ddr4).
                                       set_DIMM_TARGET( l_dimm),
                                       "Invalid data received from SPD DDR4 MTB/FTB Timebase");
                    continue;
                }
            }
            else
            {
                // DDR3 ONLY
                FAPI_DBG("DDR3 detected");

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MTB_DIVIDEND, l_dimm, l_spd_mtb_dividend),
                         "Unable to read SPD Medium Timebase Dividend.");
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MTB_DIVISOR, l_dimm, l_spd_mtb_divisor),
                         "Unable to read SPD Medium Timebase Divisor.");
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FTB_DIVIDEND,  l_dimm, l_spd_ftb_dividend),
                         "Unable to read the SPD FTB dividend");
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FTB_DIVISOR,  l_dimm, l_spd_ftb_divisor),
                         "Unable to read the SPD FTB divisor");
                FAPI_ASSERT((l_spd_mtb_dividend != 0) && (l_spd_mtb_divisor != 0) && (l_spd_ftb_dividend != 0)
                            && (l_spd_ftb_divisor != 0),
                            fapi2::CEN_MSS_UNSUPPORTED_SPD_DATA_DDR3().
                            set_MTB_DIVIDEND(l_spd_mtb_dividend).
                            set_MTB_DIVISOR(l_spd_mtb_divisor).
                            set_FTB_DIVIDEND(l_spd_ftb_dividend).
                            set_FTB_DIVISOR(l_spd_ftb_divisor).
                            set_DIMM_TARGET(l_dimm),
                            "Invalid data received from SPD within MTB/FTB Dividend, MTB/FTB Divisor");

            }

            // common to both DDR3 & DDR4
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TCKMIN, l_dimm,  l_spd_min_tck_MTB));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TAAMIN, l_dimm,  l_spd_min_taa_MTB));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED, l_dimm,  l_spd_cas_lat_supported));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_dimm,  l_cur_mba_port));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm,  l_cur_mba_dimm));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mba,  l_cur_mba));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_TYPE, l_dimm,  l_module_type));

            // from dimm_spd_attributes.xml, R1 = 0x00, R2 = 0x01, R3 = 0x02, R4 = 0x03
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_NUM_RANKS, l_dimm,
                                   l_num_ranks[l_cur_mba][l_cur_mba_port][l_cur_mba_dimm]));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TAAMIN, l_dimm,  l_spd_taa_offset_FTB));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TCKMIN, l_dimm,  l_spd_tck_offset_FTB));

            l_cur_dimm_spd_valid_u8array[l_cur_mba][l_cur_mba_port][l_cur_mba_dimm] = MSS_FREQ_VALID;

            if ((l_spd_min_tck_MTB == 0) || (l_spd_min_taa_MTB == 0))
            {
                //Invalid due to the fact that JEDEC dictates that these should be non-zero.
                // Log error and continue to next DIMM
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::CEN_MSS_UNSUPPORTED_SPD_DATA_COMMON().
                                   set_MIN_TCK(l_spd_min_tck_MTB).
                                   set_MIN_TAA(l_spd_min_taa_MTB).
                                   set_DIMM_TARGET(l_dimm).

                                   set_TARGET(i_target_memb),
                                   "Invalid data received from SPD within TCK Min, or TAA Min");
                continue;
            }

            // Calc done on PS units (the multiplication of 1000) to avoid rounding errors.
            // Frequency listed with multiplication of 2 as clocking data on both +- edges
            l_spd_min_tck =  ( 1000 * l_spd_min_tck_MTB * l_spd_mtb_dividend ) / l_spd_mtb_divisor;
            l_spd_min_taa =  ( 1000 * l_spd_min_taa_MTB * l_spd_mtb_dividend ) / l_spd_mtb_divisor;

            FAPI_INF("min tck = %i, taa = %i", l_spd_min_tck, l_spd_min_taa);
            FAPI_INF("FTB tck 0x%x, taa 0x%x", l_spd_tck_offset_FTB, l_spd_taa_offset_FTB);

            // Adjusting by tck offset -- tck offset represented in 2's compliment as it could be positive or negative adjustment
            // No multiplication of 1000 as it is already in picoseconds.
            if (l_spd_tck_offset_FTB & 0x80)
            {
                l_spd_tck_offset_FTB = ~( l_spd_tck_offset_FTB ) + 1;
                l_spd_tck_offset = (l_spd_tck_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
                l_spd_min_tck =  l_spd_min_tck - l_spd_tck_offset;
                FAPI_INF("FTB minus offset %i, min tck %i", l_spd_tck_offset, l_spd_min_tck);
            }
            else
            {
                l_spd_tck_offset = (l_spd_tck_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
                l_spd_min_tck =  l_spd_min_tck + l_spd_tck_offset;
                FAPI_INF("FTB plus offset %i, min tck %i", l_spd_tck_offset, l_spd_min_tck);
            }

            // Adjusting by taa offset -- taa offset represented in 2's compliment as it could be positive or negative adjustment
            if (l_spd_taa_offset_FTB & 0x80)
            {
                l_spd_taa_offset_FTB = ~( l_spd_taa_offset_FTB) + 1;
                l_spd_taa_offset = (l_spd_taa_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
                l_spd_min_taa =  l_spd_min_taa - l_spd_taa_offset;
            }
            else
            {
                l_spd_taa_offset = (l_spd_taa_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
                l_spd_min_taa =  l_spd_min_taa + l_spd_taa_offset;
            }

            if ((l_spd_min_tck == 0) || (l_spd_min_taa == 0))
            {
                //Invalid due to the fact that JEDEC dictates that these should be non-zero.
                // Log error and continue to next DIMM
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::CEN_MSS_UNSUPPORTED_SPD_DATA_COMMON().
                                   set_MIN_TCK(l_spd_min_tck_MTB).
                                   set_MIN_TAA(l_spd_min_taa_MTB).
                                   set_DIMM_TARGET(l_dimm).
                                   set_TARGET(i_target_memb),
                                   "Invalid data received from SPD causing TCK Min or TAA Min to be 0");
                continue;
            }

            l_dimm_freq_calc = 2000000 / l_spd_min_tck;

            FAPI_INF( "TAA(ps): %d TCK(ps): %d Calc'ed Freq for this dimm: %d", l_spd_min_taa, l_spd_min_tck, l_dimm_freq_calc);

            //is this the slowest dimm?
            if (l_dimm_freq_calc < l_dimm_freq_min)
            {
                l_dimm_freq_min = l_dimm_freq_calc;
            }

            if (l_spd_min_tck > l_spd_min_tck_max)
            {
                l_spd_min_tck_max = l_spd_min_tck;
            }

            if (l_spd_min_taa > l_spd_min_taa_max)
            {
                l_spd_min_taa_max = l_spd_min_taa;
            }

            if ( l_spd_cas_lat_supported & 0x00000001 )
            {
                l_cl_count_array[0]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000002 )
            {
                l_cl_count_array[1]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000004 )
            {
                l_cl_count_array[2]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000008 )
            {
                l_cl_count_array[3]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000010 )
            {
                l_cl_count_array[4]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000020 )
            {
                l_cl_count_array[5]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000040 )
            {
                l_cl_count_array[6]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000080 )
            {
                l_cl_count_array[7]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000100 )
            {
                l_cl_count_array[8]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000200 )
            {
                l_cl_count_array[9]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000400)
            {
                l_cl_count_array[10]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00000800 )
            {
                l_cl_count_array[11]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00001000 )
            {
                l_cl_count_array[12]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00002000 )
            {
                l_cl_count_array[13]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00004000)
            {
                l_cl_count_array[14]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00008000 )
            {
                l_cl_count_array[15]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00010000 )
            {
                l_cl_count_array[16]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00020000 )
            {
                l_cl_count_array[17]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00040000)
            {
                l_cl_count_array[18]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00080000 )
            {
                l_cl_count_array[19]++;
            }
            else if ( l_spd_cas_lat_supported & 0x00100000 )
            {
                l_cl_count_array[20]++;
            }

            l_spd_cas_lat_supported_all = l_spd_cas_lat_supported_all & l_spd_cas_lat_supported;

            if ( (l_module_type_group_1 == l_module_type) || (l_module_type_group_1 == 0) )
            {
                l_module_type_group_1 = l_module_type;
                l_module_type_group_1_total++;
            }
            else if ( (l_module_type_group_2 == l_module_type) || (l_module_type_group_2 == 0) )
            {
                l_module_type_group_2 = l_module_type;
                l_module_type_group_2_total++;
            }

        } // DIMM
    } // MBA

    // Check for DIMM Module Type Mixing
    if (l_module_type_group_2 != 0)
    {
        if (l_module_type_group_1_total > l_module_type_group_2_total)
        {
            l_module_type_deconfig = l_module_type_group_1;
        }
        else
        {
            l_module_type_deconfig = l_module_type_group_2;
        }

        // Loop through the 2 MBA's
        for (const auto& l_mba : l_mbaChiplets)
        {
            // Get a vector of DIMM targets
            const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

            for (const auto& l_dimm : l_dimm_targets)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_TYPE, l_dimm,  l_module_type));

                FAPI_ASSERT_NOEXIT(l_module_type != l_module_type_deconfig,
                                   fapi2::CEN_MSS_MODULE_TYPE_MIX().
                                   set_DIMM_TARGET(l_dimm).
                                   set_MODULE_TYPE(l_module_type),
                                   "Mixing of DIMM Module Types (%d, %d) deconfiguring minority type: %d", l_module_type_group_1, l_module_type_group_2,
                                   l_module_type_deconfig);
            } // DIMM
        } // MBA
    } // if

    FAPI_INF( "Highest Supported Frequency amongst DIMMs: %d", l_dimm_freq_min);
    FAPI_INF( "Minimum TAA(ps) amongst DIMMs: %d Minimum TCK(ps) amongst DIMMs: %d", l_spd_min_taa_max, l_spd_min_tck_max);

    //Determining the cnfg for imposing any cnfg speed limitations
    if (((l_cur_dimm_spd_valid_u8array[0][0][0] == MSS_FREQ_VALID)
         && (l_cur_dimm_spd_valid_u8array[0][0][1] == MSS_FREQ_EMPTY))
        || ((l_cur_dimm_spd_valid_u8array[0][0][1] == MSS_FREQ_VALID)
            && (l_cur_dimm_spd_valid_u8array[0][0][0] == MSS_FREQ_EMPTY)))
    {
        l_plug_config = MSS_FREQ_SINGLE_DROP;
        l_num_ranks_total = l_num_ranks[0][0][0] + 1;
    }
    else if (((l_cur_dimm_spd_valid_u8array[1][0][0] == MSS_FREQ_VALID)
              && (l_cur_dimm_spd_valid_u8array[1][0][1] == MSS_FREQ_EMPTY))
             || ((l_cur_dimm_spd_valid_u8array[1][0][1] == MSS_FREQ_VALID)
                 && (l_cur_dimm_spd_valid_u8array[1][0][0] == MSS_FREQ_EMPTY)))
    {
        l_plug_config = MSS_FREQ_SINGLE_DROP;
        l_num_ranks_total = l_num_ranks[1][0][0] + 1;
    }
    else if ((l_cur_dimm_spd_valid_u8array[0][0][0] == MSS_FREQ_VALID)
             && (l_cur_dimm_spd_valid_u8array[0][0][1] == MSS_FREQ_VALID))
    {
        l_plug_config = MSS_FREQ_DUAL_DROP;
        l_num_ranks_total = (l_num_ranks[0][0][0] + 1) + (l_num_ranks[0][0][1] + 1);
    }
    else if ((l_cur_dimm_spd_valid_u8array[1][0][0] == MSS_FREQ_VALID)
             && (l_cur_dimm_spd_valid_u8array[1][0][1] == MSS_FREQ_VALID))
    {
        l_plug_config = MSS_FREQ_DUAL_DROP;
        l_num_ranks_total = (l_num_ranks[1][0][0] + 1) + (l_num_ranks[1][0][1] + 1);
    }
    else
    {
        l_plug_config = MSS_FREQ_EMPTY;
    }

    FAPI_INF( "PLUG CONFIG(from SPD): %d, Type of Dimm(from SPD): 0x%02X, Num Ranks(from SPD): %d",  l_plug_config,
              l_module_type, l_num_ranks_total);

    // Impose configuration limitations
    // Single Drop RDIMMs Cnfgs cannot run faster than 1333
    // DDR4 min speed 1600 and Cen no longer supports 1866.
    if (l_spd_dram_dev_type == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
    {
        l_dimm_freq_min = 1600;
        l_spd_min_tck_max = 1250;
        FAPI_INF( "DDR4/Centaur limitation. Centaur no longer handles 1866 and 1600 is min speed of DDR4.  New Freq: %d",
                  l_dimm_freq_min);
    }
    else if ((l_module_type_group_1 == fapi2::ENUM_ATTR_CEN_SPD_MODULE_TYPE_RDIMM)
             && (l_plug_config == MSS_FREQ_SINGLE_DROP)
             && (l_dimm_freq_min > 1333))
    {
        l_dimm_freq_min = 1333;
        l_spd_min_tck_max = 1500;
        FAPI_INF( "Single Drop RDIMM with more than 1 Rank Cnfg limitation.  New Freq: %d", l_dimm_freq_min);
    }
    // Double Drop RDIMMs Cnfgs cannot run faster than 1333 with less than 8 ranks total per port
    else if ((l_module_type_group_1 == fapi2::ENUM_ATTR_CEN_SPD_MODULE_TYPE_RDIMM) && (l_plug_config == MSS_FREQ_DUAL_DROP)
             && (l_num_ranks_total < 8) && (l_dimm_freq_min > 1333))
    {
        l_dimm_freq_min = 1333;
        l_spd_min_tck_max = 1500;
        FAPI_INF( "Dual Drop RDIMM with more than 4 Rank Cnfg limitation.  New Freq: %d", l_dimm_freq_min);
    }
    // Double Drop RDIMMs Cnfgs cannot run faster than 1066 with 8 ranks total per port
    else if ((l_module_type_group_1 == fapi2::ENUM_ATTR_CEN_SPD_MODULE_TYPE_RDIMM) && (l_plug_config == MSS_FREQ_DUAL_DROP)
             && (l_num_ranks_total == 8) && (l_dimm_freq_min > 1066))
    {
        l_dimm_freq_min = 1066;
        l_spd_min_tck_max = 1875;
        FAPI_INF( "Dual Drop RDIMM with more than 8 Rank Cnfg limitation.  New Freq: %d", l_dimm_freq_min);
    }

    if ( l_spd_min_tck_max == 0)
    {
        // Loop through the 2 MBA's
        for (const auto& l_mba : l_mbaChiplets)
        {
            // Get a vector of DIMM targets
            const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

            for (const auto& l_dimm : l_dimm_targets)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TCKMIN, l_dimm,  l_spd_min_tck_MTB));

                FAPI_ASSERT_NOEXIT(l_spd_min_tck_MTB != 0,
                                   fapi2::CEN_MSS_UNSUPPORTED_SPD_DATA_COMMON().
                                   set_MIN_TCK(l_spd_min_tck_max).
                                   set_MIN_TAA(l_spd_min_taa_max).
                                   set_DIMM_TARGET( l_dimm).
                                   set_TARGET(i_target_memb),
                                   "l_spd_min_tck_max = 0 unable to calculate freq or cl.  Possibly no centaurs configured. ");
            } // DIMM
        } // MBA
    } // if

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ_OVERRIDE, i_target_memb,  l_freq_override));

    if ( l_freq_override != 0)
    {
        // The relationship is as such
        // l_dimm_freq_min = 2000000 / l_spd_min_tck_max

        if (l_freq_override == 1866)
        {
            l_dimm_freq_min = 1866;
            l_spd_min_tck_max = 1072;
        }

        if (l_freq_override == 1600)
        {
            l_dimm_freq_min = 1600;
            l_spd_min_tck_max = 1250;
        }

        if (l_freq_override == 1333)
        {
            l_dimm_freq_min = 1333;
            l_spd_min_tck_max = 1500;
        }

        if (l_freq_override == 1066)
        {
            l_dimm_freq_min = 1066;
            l_spd_min_tck_max = 1875;
        }

        FAPI_INF( "Override Frequency Detected: %d", l_dimm_freq_min);
    }

    //If no common supported CL get rid of the minority DIMMs
    FAPI_INF("l_spd_cas_lat_supported_all: %x", l_spd_cas_lat_supported_all);

    if ((l_spd_cas_lat_supported_all == 0))
    {
        FAPI_INF("l_spd_cas_lat_supported_all: %x", l_spd_cas_lat_supported_all);

        for(uint8_t i = 0; i < 20; i++)
        {
            if (l_cl_count_array[i] > l_highest_cl_count)
            {
                l_highest_common_cl = i;
            }
        }

        // Loop through the 2 MBA's
        for (const auto& l_mba : l_mbaChiplets)
        {
            // Get a vector of DIMM targets
            const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

            for (const auto& l_dimm : l_dimm_targets)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED, l_dimm,  l_spd_cas_lat_supported));

                FAPI_ASSERT_NOEXIT(l_spd_cas_lat_supported & 0x0000001 << l_highest_common_cl,
                                   fapi2::CEN_MSS_NO_COMMON_SUPPORTED_CL().
                                   set_DIMM_TARGET(l_dimm).
                                   set_CL_SUPPORTED(l_spd_cas_lat_supported),
                                   "No common supported CAS latencies between DIMMS.");
            } // DIMM
        } // MBA
    }//if

    //Determine a proposed CAS latency
    l_cas_latency = l_spd_min_taa_max / l_spd_min_tck_max;

    FAPI_INF( "CL = TAA / TCK ... TAA(ps): %d TCK(ps): %d", l_spd_min_taa_max, l_spd_min_tck_max);
    FAPI_INF( "Calculated CL: %d", l_cas_latency);

    if ( l_spd_min_taa_max % l_spd_min_tck_max)
    {
        l_cas_latency++;
        FAPI_INF( "After rounding up ... CL: %d", l_cas_latency);
    }

    //Setting Max CL = 13 for 1600 DDR4 TSV
    if (l_freq_override == 1600 && l_cas_latency > 13)
    {
        FAPI_INF( "Setting CL to 13 from %d", l_cas_latency);
        l_cas_latency = 13;
    }

    l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;

    // If the CL proposed is not supported or the TAA exceeds TAA max
    // Spec defines tAAmax as 20 ns for all DDR3 speed grades.
    // Break loop if we have an override condition without a solution.
    while (    ( (!( l_spd_cas_lat_supported_all & (0x00000001 << (l_cas_latency - 4)))) || (l_cl_mult_tck > 20000) )
               && ( l_override_path == 0 ) )
    {
        FAPI_INF( "Warning calculated CL is not supported in VPD.  Searching for a new CL.");

        // If not supported, increment the CL up to 18 (highest supported CL) looking for Supported CL
        while ((!( l_spd_cas_lat_supported_all & (0x00000001 << (l_cas_latency - 4)))) && (l_cas_latency < 18))
        {
            l_cas_latency++;
        }

        // If still not supported CL or TAA is > 20 ns ... pick a slower TCK and start again
        l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;

        // Do not move freq if using an override freq.  Just continue.  Hence the overide in this if statement
        if ( ( (!( l_spd_cas_lat_supported_all & (0x00000001 << (l_cas_latency - 4)))) || (l_cl_mult_tck > 20000) )
             && ( l_freq_override == 0) )
        {
            FAPI_INF( "No Supported CL works for calculating frequency.  Lowering frequency and trying CL Algorithm again.");

            if (l_spd_min_tck_max < 1500)
            {
                //1600 to 1333
                l_spd_min_tck_max = 1500;
            }
            else if (l_spd_min_tck_max < 1875)
            {
                //1333 to 1066
                l_spd_min_tck_max = 1875;
            }
            else if (l_spd_min_tck_max < 2500)
            {
                //1066 to 800
                l_spd_min_tck_max = 2500;
            }
            else
            {
                //This is minimum frequency and cannot be lowered
                //Therefore we will deconfig the minority dimms.
                for(uint8_t i = 0; i < 20; i++)
                {
                    if (l_cl_count_array[i] > l_lowest_cl_count)
                    {
                        l_lowest_common_cl = i;
                    }
                }

                // Loop through the 2 MBA's
                for (const auto& l_mba : l_mbaChiplets)
                {
                    // Get a vector of DIMM targets
                    const auto l_dimm_targets = l_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

                    for (const auto& l_dimm : l_dimm_targets)
                    {
                        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CAS_LATENCIES_SUPPORTED, l_dimm,  l_spd_cas_lat_supported));

                        if (l_spd_cas_lat_supported & 0x0000001 << l_lowest_common_cl)
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                               fapi2::CEN_MSS_EXCEED_TAA_MAX_NO_CL().
                                               set_DIMM_TARGET(l_dimm).
                                               set_CL_SUPPORTED(l_spd_cas_lat_supported),
                                               "Lowered Frequency to TCLK MIN finding no supported CL without exceeding TAA MAX.");
                        }
                    } // DIMM
                } // MBA
            } // else

            // Re-calculate with new tck
            l_cas_latency = l_spd_min_taa_max / l_spd_min_tck_max;

            if ( l_spd_min_taa_max % l_spd_min_tck_max)
            {
                l_cas_latency++;
            }

            l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;
            l_dimm_freq_min = 2000000 / l_spd_min_tck_max;

        } // if

        // Need to break the loop in case we reach this condition because no longer modify freq and CL
        // With an overrride
        if ( ( (!( l_spd_cas_lat_supported_all & (0x00000001 << (l_cas_latency - 4)))) || (l_cl_mult_tck > 20000) )
             && ( l_freq_override != 0) )
        {
            FAPI_INF( "No Supported CL works for override frequency.  Using override frequency with an unsupported CL.");
            l_override_path = 1;
        }
    } // while

    //bucketize dimm freq.
    if (l_dimm_freq_min < 1013)
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_UNSUPPORTED_FREQ_CALCULATED().
                    set_DIMM_MIN_FREQ(l_dimm_freq_min),
                    "Unsupported frequency:  DIMM Freq calculated < 1013 MHz");

    }
    else if (l_dimm_freq_min < 1266)
    {
        // 1066
        l_selected_dimm_freq = 1066;
    }
    else if (l_dimm_freq_min < 1520)
    {
        // 1333
        l_selected_dimm_freq = 1333;
    }
    else if (l_dimm_freq_min < 1773)
    {
        // 1600
        l_selected_dimm_freq = 1600;
    }
    else if (l_dimm_freq_min < 2026)
    {
        // 1866
        l_selected_dimm_freq = 1866;
    }
    else if (l_dimm_freq_min < 2280)
    {
        // 2133
        l_selected_dimm_freq = 2133;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_UNSUPPORTED_FREQ_CALCULATED().
                    set_DIMM_MIN_FREQ(l_dimm_freq_min),
                    "Unsupported frequency:  DIMM Freq calculated > 2133 MHz: %d", l_dimm_freq_min);

    }

    // 0x03 = capable of both 8.0G/9.6G, 0x01 = capable of 8.0G, 0x02 = capable 9.6G
    if ( l_selected_dimm_freq == 1066)
    {
        l_nest_capable_frequencies = 0x01;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_NEST_CAPABLE_FREQUENCIES, i_target_memb,  l_nest_capable_frequencies));
    }
    else
    {
        l_nest_capable_frequencies = 0x03;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_NEST_CAPABLE_FREQUENCIES, i_target_memb,  l_nest_capable_frequencies));
    }

    // set frequency in centaur attribute ATTR_MSS_FREQ
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_FREQ, i_target_memb,  l_selected_dimm_freq));
    FAPI_INF( "Final Chosen Frequency: %d ",  l_selected_dimm_freq);
    FAPI_INF( "Final Chosen CL: %d ",  l_cas_latency);

    for (uint32_t k = 0; k < l_mbaChiplets.size(); k++)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_CL, l_mbaChiplets[k],  l_cas_latency));
    }

fapi_try_exit:
    return fapi2::current_err;
}

