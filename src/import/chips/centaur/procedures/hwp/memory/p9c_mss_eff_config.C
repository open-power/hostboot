/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_config.C $ */
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
/// @file p9c_mss_eff_config.C
/// @brief  Takes in spd and configures effective attrs
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Anuwat Saetow <asaetow@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------
#include <p9c_mss_eff_config.H>
#include <p9c_mss_eff_pre_config.H>
#include <p9c_mss_eff_config_rank_group.H>
#include <p9c_mss_eff_config_shmoo.H>
#include <generic/memory/lib/utils/c_str.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
constexpr uint32_t MSS_EFF_EMPTY = 0;
constexpr uint32_t MSS_EFF_VALID = 255;
constexpr uint32_t TWO_MHZ = 2000000;

extern "C"
{
    ///
    /// @brief calc_timing_in_clk(): This function calculates tXX in clocks
    /// @param[in] i_mtb_in_ps:  Medium timebase in picoseconds
    /// @param[in] i_ftb_in_fs:  Fundamental timebase in femtoseconds
    /// @param[in] i_unit: tXX value we are trying to calculate
    /// @param[in] i_offset: Fine timebase offset
    /// @param[in] i_mss_freq: Memory Frequency
    /// @return l_timing_in_clk
    ///
    uint32_t calc_timing_in_clk(const uint32_t i_mtb_in_ps, const uint32_t i_ftb_in_fs,
                                const uint32_t i_unit, uint8_t i_offset, const uint32_t i_mss_freq)
    {
        uint64_t l_timing;
        uint32_t l_timing_in_clk;
        uint32_t l_tCK_in_ps;
        // perform calculations
        l_tCK_in_ps = TWO_MHZ / i_mss_freq;

        if ( i_offset >= 128 )
        {
            i_offset = 256 - i_offset;
            l_timing = (i_unit * i_mtb_in_ps) - (i_offset * i_ftb_in_fs);
        }
        else
        {
            l_timing = (i_unit * i_mtb_in_ps) + (i_offset * i_ftb_in_fs);
        }

        // ceiling()
        l_timing_in_clk = l_timing / l_tCK_in_ps;

        // check l_timing
        if ( (l_timing_in_clk * l_tCK_in_ps) < l_timing )
        {
            l_timing_in_clk += 1;
        }

        return l_timing_in_clk;
    } // end calc_timing_in_clk()

    ///
    /// @brief mss_eff_config_read_spd_data(): This function reads DIMM SPD data
    /// @param[in]      fapi2::Target<fapi2::TARGET_TYPE_DIMM> i_target_dimm: target dimm
    /// @param[out]     mss_eff_config_spd_data *o_spd_data: Pointer to mss_eff configuration spd data structure
    /// @param[in]      uint8_t i_port: current mba port
    /// @param[in]      uint8_t i_dimm: current mba dimm
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_read_spd_data(const fapi2::Target<fapi2::TARGET_TYPE_DIMM> i_target_dimm,
            mss_eff_config_spd_data* o_spd_data,
            const uint8_t i_port, const uint8_t i_dimm)
    {

        uint8_t l_spd_tb_mtb_ddr4, l_spd_tb_ftb_ddr4 = 0;
        // Grab DIMM/SPD data.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, i_target_dimm,
                               o_spd_data->dram_device_type[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE, i_target_dimm,
                               o_spd_data->sdram_device_type[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING, i_target_dimm,
                               o_spd_data->sdram_device_type_signal_loading[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_DIE_COUNT, i_target_dimm,
                               o_spd_data->sdram_die_count[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_TYPE, i_target_dimm,
                               o_spd_data->module_type[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_CUSTOM, i_target_dimm,
                               o_spd_data->custom[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_BANKS, i_target_dimm,
                               o_spd_data->sdram_banks[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_DENSITY, i_target_dimm,
                               o_spd_data->sdram_density[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_ROWS, i_target_dimm,
                               o_spd_data->sdram_rows[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_COLUMNS, i_target_dimm,
                               o_spd_data->sdram_columns[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_NUM_RANKS, i_target_dimm,
                               o_spd_data->num_ranks[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_DRAM_WIDTH, i_target_dimm,
                               o_spd_data->dram_width[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH, i_target_dimm,
                               o_spd_data->module_memory_bus_width[i_port][i_dimm]));

        if (o_spd_data->dram_device_type[i_port][i_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            // DDR3 only
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FTB_DIVIDEND, i_target_dimm,
                                   o_spd_data->ftb_dividend[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FTB_DIVISOR, i_target_dimm,
                                   o_spd_data->ftb_divisor[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MTB_DIVIDEND, i_target_dimm,
                                   o_spd_data->mtb_dividend[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MTB_DIVISOR, i_target_dimm,
                                   o_spd_data->mtb_divisor[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRRDMIN, i_target_dimm,
                                   o_spd_data->trrdmin[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRFCMIN, i_target_dimm,
                                   o_spd_data->trfcmin[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TWTRMIN, i_target_dimm,
                                   o_spd_data->twtrmin[i_port][i_dimm]));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TWRMIN, i_target_dimm,
                                   o_spd_data->twrmin[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRTPMIN, i_target_dimm,
                                   o_spd_data->trtpmin[i_port][i_dimm]));

        }
        else if (o_spd_data->dram_device_type[i_port][i_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
        {
            // DDR4 only
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TIMEBASE_MTB_DDR4, i_target_dimm,  l_spd_tb_mtb_ddr4));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TIMEBASE_FTB_DDR4, i_target_dimm,  l_spd_tb_ftb_ddr4));

            // AST HERE: !If DDR4 spec changes to include other values, this section needs to be updated!
            FAPI_ASSERT((l_spd_tb_mtb_ddr4 == 0) && (l_spd_tb_ftb_ddr4 == 0),
                        fapi2::CEN_MSS_EFF_CONFIG_INVALID_DDR4_SPD_TB().
                        set_TARGET_DIMM(i_target_dimm),
                        "Invalid DDR4 MTB/FTB Timebase received from SPD attribute on %s!", mss::c_str(i_target_dimm));

            // for 1000fs = 1ps = 1000 * 1 / 1
            o_spd_data->ftb_dividend[i_port][i_dimm] = 1;
            o_spd_data->ftb_divisor[i_port][i_dimm] = 1;
            // for 125ps = 1000 * 1 / 8
            o_spd_data->mtb_dividend[i_port][i_dimm] = 1;
            o_spd_data->mtb_divisor[i_port][i_dimm] = 8;

            // not available in ddr4 spd, these are replacements.  need to double check
            // 15 ns for all speeds
            o_spd_data->twrmin[i_port][i_dimm] = 15000 / (
                    (o_spd_data->mtb_dividend[i_port][i_dimm] * 1000) /
                    o_spd_data->mtb_divisor[i_port][i_dimm]);

            // 7.5ns = 7500ps; work backwards to figure out value.  no FTB
            o_spd_data->trtpmin[i_port][i_dimm] = 7500 / (
                    (o_spd_data->mtb_dividend[i_port][i_dimm] * 1000) /
                    o_spd_data->mtb_divisor[i_port][i_dimm]);

            // DDR4 RDIMM/LRDIMM Support
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_ADDR_MAP_REG_TO_DRAM, i_target_dimm,
                                   o_spd_data->addr_map_reg_to_dram[i_port][i_dimm]));

            // 3 trfc values, 1x, 2x, 4x
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRFC1MIN_DDR4, i_target_dimm,  o_spd_data->trfc1min[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRFC2MIN_DDR4, i_target_dimm,  o_spd_data->trfc2min[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRFC4MIN_DDR4, i_target_dimm,  o_spd_data->trfc4min[i_port][i_dimm]));

            // ddr4 has 's' (short; different bank group) and
            // 'l' (long; same bank group) values
            // tRRD needs to be used by Yuen's mba initfile...
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRRDSMIN_DDR4, i_target_dimm,
                                   o_spd_data->trrdsmin[i_port][i_dimm]));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRRDLMIN_DDR4, i_target_dimm,
                                   o_spd_data->trrdlmin[i_port][i_dimm]));

            // tccdl
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TCCDLMIN_DDR4, i_target_dimm,
                                   o_spd_data->tccdlmin[i_port][i_dimm]));

            // should be constant based on MTB and FTB after calculations
            o_spd_data->twtrsmin[i_port][i_dimm] = 2500 / (       // 2.5 ns
                    (o_spd_data->mtb_dividend[i_port][i_dimm] * 1000) /
                    o_spd_data->mtb_divisor[i_port][i_dimm]);
            o_spd_data->twtrlmin[i_port][i_dimm] = 7500 / (       // 7.5 ns
                    (o_spd_data->mtb_dividend[i_port][i_dimm] * 1000) /
                    o_spd_data->mtb_divisor[i_port][i_dimm]);
        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_SPD_DRAM_GEN().
                        set_TARGET_DIMM(i_target_dimm),
                        "Incompatable SPD DRAM generation on %s!", mss::c_str(i_target_dimm));
        }

        // Common for DDR3 and DDR4
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRCDMIN, i_target_dimm,
                               o_spd_data->trcdmin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRPMIN, i_target_dimm,
                               o_spd_data->trpmin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRASMIN, i_target_dimm,
                               o_spd_data->trasmin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TRCMIN, i_target_dimm,
                               o_spd_data->trcmin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_TFAWMIN, i_target_dimm,
                               o_spd_data->tfawmin[i_port][i_dimm]));


        // Allows feature checking
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_OPTIONAL_FEATURES, i_target_dimm,
                               o_spd_data->sdram_optional_features[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS, i_target_dimm,
                               o_spd_data->sdram_thermal_and_refresh_options[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_MODULE_THERMAL_SENSOR, i_target_dimm,
                               o_spd_data->module_thermal_sensor[i_port][i_dimm]));


        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TCKMIN, i_target_dimm,
                               o_spd_data->fine_offset_tckmin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TAAMIN, i_target_dimm,
                               o_spd_data->fine_offset_taamin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCDMIN, i_target_dimm,
                               o_spd_data->fine_offset_trcdmin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRPMIN, i_target_dimm,
                               o_spd_data->fine_offset_trpmin[i_port][i_dimm]));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_FINE_OFFSET_TRCMIN, i_target_dimm,
                               o_spd_data->fine_offset_trcmin[i_port][i_dimm]));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_VERSION, i_target_dimm,
                               o_spd_data->vpd_version[i_port][i_dimm]));

    fapi_try_exit:
        return fapi2::current_err;
    } // end of mss_eff_config_read_spd_data()

    ///
    /// @brief mss_eff_config_get_spd_data(): This function sets gathers the DIMM info then uses mss_eff_config_read_spd_data()
    /// @param[in] i_target_mba: the fapi2 target
    /// @param[in,out]  i_mss_eff_config_data: Pointer to mss_eff_config_data variable structure
    /// @param[out] o_spd_data: Pointer to mss_eff configuration spd data structure
    /// @param[in] i_atts: Pointer to mss_eff config attribute structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_get_spd_data(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        mss_eff_config_data* i_mss_eff_config_data,
        mss_eff_config_spd_data* o_spd_data,
        mss_eff_config_atts* i_atts)
    {
        uint8_t l_cur_mba_port = 0;
        uint8_t l_cur_mba_dimm = 0;

        // Grab all DIMM/SPD data.
        // initialize vpd_version
        for(l_cur_mba_port = 0; l_cur_mba_port < MAX_PORTS_PER_MBA ; l_cur_mba_port++)
            for(l_cur_mba_dimm = 0; l_cur_mba_dimm < MAX_DIMM_PER_PORT ; l_cur_mba_dimm++)
            {
                o_spd_data->vpd_version[l_cur_mba_port][l_cur_mba_dimm] = 0xFFFFFFFF;
            }

        const auto l_target_dimm_array = i_target_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();

        // call mss_eff_config_read_spd_data()
        for (const auto l_dimm : l_target_dimm_array)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_dimm, l_cur_mba_port), "Error retrieving ATTR_MBA_PORT");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm, l_cur_mba_dimm), "Error retrieving ATTR_MBA_DIMM");
            i_mss_eff_config_data->cur_dimm_spd_valid_u8array
            [l_cur_mba_port][l_cur_mba_dimm] = MSS_EFF_VALID;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL,
                                   l_dimm,
                                   i_mss_eff_config_data->dimm_functional), "Error retrieving functional fapi2 attribute");

            (i_mss_eff_config_data->dimm_functional ==
             fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
            ? i_mss_eff_config_data->dimm_functional = 1
                    : i_mss_eff_config_data->dimm_functional = 0;
            i_atts->dimm_functional_vector |=
                i_mss_eff_config_data->dimm_functional
                << ((4 * (1 - (l_cur_mba_port))) + (4 - (l_cur_mba_dimm)) - 1);

            FAPI_TRY(mss_eff_config_read_spd_data(l_dimm,
                                                  o_spd_data, l_cur_mba_port, l_cur_mba_dimm), "Error reading spd data from caller");
        }

    fapi_try_exit:
        return fapi2::current_err;
    } // end of mss_eff_config_get_spd_data()

    ///
    /// @brief mss_eff_config_verify_plug_rules(): This function verifies DIMM plug rules based on which dimms are present
    /// @param[in] const fapi2::Target<fapi2::TARGET_TYPE_MBA> &i_target_mba: the fapi2 target
    /// @param[in] mss_eff_config_data *i_mss_eff_config_data: Pointer to mss_eff_config_data variable structure
    /// @param[in] mss_eff_config_atts *i_atts: Pointer to mss_eff configuration attributes structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_verify_plug_rules(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        mss_eff_config_data* i_mss_eff_config_data,
        mss_eff_config_atts* i_atts)
    {
        // Identify/Verify DIMM plug rule
        if (
            (i_mss_eff_config_data->
             cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_EMPTY)
            &&
            (
                (i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID)
                ||
                (i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][0] == MSS_EFF_VALID)
                ||
                (i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][1] == MSS_EFF_VALID)
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_MISMATCH_EMPTY().
                        set_TARGET_MBA(i_target_mba).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_0_0(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][0]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_0_1(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][1]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_1_0(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][0]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_1_1(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][1]),
                        "Plug rule violation on %s! Port 0 Dimm 0 not valid.\n \
                         [0][0]: %d\n [0][1]: %d\n [1][0]: %d\n [1][1]: %d\n",
                        mss::c_str(i_target_mba),
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][0],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][1],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][0],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][1]);
        }

        if ( (
                 ((i_mss_eff_config_data->
                   cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID)
                  && (i_mss_eff_config_data->
                      cur_dimm_spd_valid_u8array[1][0] == MSS_EFF_EMPTY))
                 ||
                 ((i_mss_eff_config_data->
                   cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID)
                  && (i_mss_eff_config_data->
                      cur_dimm_spd_valid_u8array[1][1] == MSS_EFF_EMPTY))
             ) && (i_mss_eff_config_data->allow_single_port == fapi2::ENUM_ATTR_CEN_MSS_ALLOW_SINGLE_PORT_FALSE) )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_MISMATCH_SIDE().
                        set_TARGET_MBA(i_target_mba).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_0_0(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][0]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_0_1(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][1]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_1_0(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][0]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_1_1(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][1]),
                        "Plug rule violation on %s! Single port not allowed..\n \
                        [0][0]: %d\n [0][1]: %d\n [1][0]: %d\n [1][1]: %d\n",
                        mss::c_str(i_target_mba),
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][0],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][1],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][0],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][1]);


        }

        if ( (
                 (i_mss_eff_config_data->
                  cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID)
                 || (i_mss_eff_config_data->
                     cur_dimm_spd_valid_u8array[1][0] == MSS_EFF_VALID)
                 || (i_mss_eff_config_data->
                     cur_dimm_spd_valid_u8array[1][1] == MSS_EFF_VALID)
             ) && (i_mss_eff_config_data->allow_single_port == fapi2::ENUM_ATTR_CEN_MSS_ALLOW_SINGLE_PORT_TRUE) )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_MISMATCH_TOP().
                        set_TARGET_MBA(i_target_mba).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_0_0(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][0]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_0_1(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][1]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_1_0(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][0]).
                        set_CUR_DIMM_SPD_VALID_U8ARRAY_1_1(i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][1]),
                        "Plug rule violation on %s! Port 0 Dimm 0 not valid.\n \
                        [0][0]: %d\n [0][1]: %d\n [1][0]: %d\n [1][1]: %d\n",
                        mss::c_str(i_target_mba),
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][0],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][1],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][0],
                        i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][1]);
        }

        if ((i_mss_eff_config_data->
             cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID)
            && (i_mss_eff_config_data->
                cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID))
        {
            i_atts->eff_num_drops_per_port
                = fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL;
        }
        else if ((i_mss_eff_config_data->
                  cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID)
                 && (i_mss_eff_config_data->
                     cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_EMPTY))
        {
            i_atts->eff_num_drops_per_port
                = fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_SINGLE;
        }
        else
        {
            i_atts->eff_num_drops_per_port
                = fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_EMPTY;
        }

        // end Indetify/Verify DIMM plug rule
    fapi_try_exit:
        return fapi2::current_err;
    } // end of mss_eff_config_verify_plug_rules()

    ///
    /// @brief mss_eff_config_verify_spd_data(): This function verifies DIMM SPD data
    /// @param[in] const fapi2::Target<fapi2::TARGET_TYPE_MBA> &i_target_mba: the fapi2 target
    /// @param[in]       mss_eff_config_atts *i_atts: Pointer to mss_eff configuration attributes structure
    /// @param[in]       mss_eff_config_spd_data *i_data: Pointer to mss_eff configuration spd data structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_verify_spd_data(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        mss_eff_config_atts* i_atts,
        mss_eff_config_spd_data* i_data)
    {
        // Start Identify/Verify/Assigning values to attributes
        // Identify/Verify DIMM compatability
        if (
            (i_data->dram_device_type[0][0]
             != i_data->dram_device_type[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->dram_device_type[0][1]
                     != i_data->dram_device_type[1][1])
                    ||
                    (i_data->dram_device_type[0][0]
                     != i_data->dram_device_type[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                        set_TARGET_MBA(i_target_mba).
                        set_DRAM_DEVICE_TYPE_0_0( i_data->dram_device_type[0][0]).
                        set_DRAM_DEVICE_TYPE_0_1( i_data->dram_device_type[0][1]).
                        set_DRAM_DEVICE_TYPE_1_0( i_data->dram_device_type[1][0]).
                        set_DRAM_DEVICE_TYPE_1_1( i_data->dram_device_type[1][1]),
                        "Incompatable DRAM generation on %s!",
                        mss::c_str(i_target_mba));
        }

        if (
            (i_data->module_type[0][0]
             != i_data->module_type[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->module_type[0][1]
                     != i_data->module_type[1][1])
                    ||
                    (i_data->module_type[0][0]
                     != i_data->module_type[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_TYPE().
                        set_TARGET_MBA(i_target_mba).
                        set_MODULE_TYPE_0_0(i_data->module_type[0][0]).
                        set_MODULE_TYPE_0_1(i_data->module_type[0][1]).
                        set_MODULE_TYPE_1_0(i_data->module_type[1][0]).
                        set_MODULE_TYPE_1_1(i_data->module_type[1][1]),
                        "Incompatable DIMM type on %s!", mss::c_str(i_target_mba));
        }

        if (
            (i_data->num_ranks[0][0]
             != i_data->num_ranks[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->num_ranks[0][1]
                     != i_data->num_ranks[1][1])
                    ||
                    (i_data->num_ranks[0][0]
                     != i_data->num_ranks[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_RANKS().
                        set_TARGET_MBA(i_target_mba).
                        set_NUM_RANKS_0_0(i_data->num_ranks[0][0]).
                        set_NUM_RANKS_0_1(i_data->num_ranks[0][1]).
                        set_NUM_RANKS_1_0(i_data->num_ranks[1][0]).
                        set_NUM_RANKS_1_1(i_data->num_ranks[1][1]),
                        "Incompatable DIMM ranks on %s!", mss::c_str(i_target_mba));
        }

        if (
            (i_data->sdram_banks[0][0]
             != i_data->sdram_banks[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->sdram_banks[0][1]
                     != i_data->sdram_banks[1][1])
                    ||
                    (i_data->sdram_banks[0][0]
                     != i_data->sdram_banks[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_BANKS().
                        set_TARGET_MBA(i_target_mba).
                        set_SDRAM_BANKS_0_0(i_data->sdram_banks[0][0]).
                        set_SDRAM_BANKS_0_1(i_data->sdram_banks[0][1]).
                        set_SDRAM_BANKS_1_0(i_data->sdram_banks[1][0]).
                        set_SDRAM_BANKS_1_1(i_data->sdram_banks[1][1]),
                        "Incompatable DIMM banks on %s!", mss::c_str(i_target_mba));
        }

        if (
            (i_data->sdram_rows[0][0]
             != i_data->sdram_rows[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->sdram_rows[0][1]
                     != i_data->sdram_rows[1][1])
                    ||
                    (i_data->sdram_rows[0][0]
                     != i_data->sdram_rows[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_ROWS().
                        set_TARGET_MBA(i_target_mba).
                        set_SDRAM_ROWS_0_0( i_data->sdram_rows[0][0]).
                        set_SDRAM_ROWS_0_1(i_data->sdram_rows[0][1]).
                        set_SDRAM_ROWS_1_0(i_data->sdram_rows[1][0]).
                        set_SDRAM_ROWS_1_1(i_data->sdram_rows[1][1]),
                        "Incompatable DIMM rows on %s!", mss::c_str(i_target_mba));
        }

        if (
            (i_data->sdram_columns[0][0]
             != i_data->sdram_columns[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->sdram_columns[0][1]
                     != i_data->sdram_columns[1][1])
                    ||
                    (i_data->sdram_columns[0][0]
                     != i_data->sdram_columns[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_COLUMNS().
                        set_TARGET_MBA(i_target_mba).
                        set_SDRAM_COLS_0_0(i_data->sdram_columns[0][0]).
                        set_SDRAM_COLS_0_1(i_data->sdram_columns[0][1]).
                        set_SDRAM_COLS_1_0(i_data->sdram_columns[1][0]).
                        set_SDRAM_COLS_1_1(i_data->sdram_columns[1][1]),
                        "Incompatable DIMM cols on %s!", mss::c_str(i_target_mba));
        }

        if (
            (i_data->module_memory_bus_width[0][0]
             != i_data->module_memory_bus_width[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->module_memory_bus_width[0][1]
                     != i_data->module_memory_bus_width[1][1])
                    ||
                    (i_data->module_memory_bus_width[0][0]
                     != i_data->module_memory_bus_width[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_BUS_WIDTH().
                        set_TARGET_MBA(i_target_mba).
                        set_BUS_WIDTH_0_0( i_data->module_memory_bus_width[0][0]).
                        set_BUS_WIDTH_0_1( i_data->module_memory_bus_width[0][1]).
                        set_BUS_WIDTH_1_0( i_data->module_memory_bus_width[1][0]).
                        set_BUS_WIDTH_1_1( i_data->module_memory_bus_width[1][1]),
                        "Incompatable DRAM primary bus width on %s!",
                        mss::c_str(i_target_mba));
        }

        // ATTR_SPD_MODULE_MEMORY_BUS_WIDTH, SPD byte8[4:3], only 64bit with ECC extension is allowed
        if ( i_data->module_memory_bus_width[0][0] !=
             fapi2::ENUM_ATTR_CEN_SPD_MODULE_MEMORY_BUS_WIDTH_WE64 )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_UNSUPPORTED_MODULE_MEMORY_BUS_WIDTH().
                        set_TARGET_MBA(i_target_mba).
                        set_MODULE_MEMORY_BUS_WIDTH( i_data->module_memory_bus_width[0][0]),
                        "Unsupported DRAM bus width on %s!",
                        mss::c_str(i_target_mba));
        }

        if (
            (i_data->dram_width[0][0]
             != i_data->dram_width[1][0])
            ||
            (
                (i_atts->eff_num_drops_per_port
                 == fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (i_data->dram_width[0][1]
                     != i_data->dram_width[1][1])
                    ||
                    (i_data->dram_width[0][0]
                     != i_data->dram_width[0][1])
                )
            )
        )
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_WIDTH().
                        set_TARGET_MBA(i_target_mba).
                        set_DRAM_WIDTH_0_0(i_data->dram_width[0][0]).
                        set_DRAM_WIDTH_0_1(i_data->dram_width[0][1]).
                        set_DRAM_WIDTH_1_0(i_data->dram_width[1][0]).
                        set_DRAM_WIDTH_1_1(i_data->dram_width[1][1]),
                        "Incompatable DRAM width on %s!", mss::c_str(i_target_mba));
        }

    fapi_try_exit:
        return fapi2::current_err;
    } // end of mss_eff_config_verify_spd_data()

    ///
    /// @brief mss_eff_config_setup_eff_atts(): This function sets up the effective configuration attributes
    /// @param[in] const fapi2::Target<fapi2::TARGET_TYPE_MBA> &i_target_mba: the fapi2 target
    /// @param[in]       mss_eff_config_data *i_mss_eff_config_data: Pointer to mss_eff_config_data variable structure
    /// @param[in]       mss_eff_config_spd_data *i_data: Pointer to mss_eff configuration spd data structure
    /// @param[in,out]       mss_eff_config_atts *o_atts: Pointer to mss_eff configuration attributes structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_setup_eff_atts(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        mss_eff_config_data* i_mss_eff_config_data,
        mss_eff_config_spd_data* i_data,
        mss_eff_config_atts* o_atts)
    {
        uint8_t l_vpd_dram_address_mirroring[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_mss_dram_2n_mode_enable = 0;
        uint8_t l_attr_vpd_dram_wrddr4_vref[MAX_PORTS_PER_MBA] = {0};
        uint8_t l_mss_power_control_requested = 0;
        uint32_t l_rdimm_rcd_ibt[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_rdimm_rcd_output_timing[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_refresh_rate = 0;
        uint8_t l_die_count = 1;
        uint8_t l_ranks_3d_tsv = 0;
        uint8_t l_allow_port_size = 1;
        const uint8_t l_min_delay_clocks = 4;
        uint32_t l_max_delay = 0;             // in ps
        uint8_t l_speed_idx = 0;
        uint8_t l_width_idx = 0;
        constexpr double TEN_PERCENT_FASTER = 0.90;
        constexpr double ONE_PERCENT_FASTER = 0.99;
        constexpr uint64_t TRFI_BASE = 7800;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_ADDRESS_MIRRORING, i_target_mba,  l_vpd_dram_address_mirroring));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED, i_target_mba,  l_mss_dram_2n_mode_enable));
        // DDR4 Vref
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_WRDDR4_VREF, i_target_mba,  l_attr_vpd_dram_wrddr4_vref));
        // Transfer powerdown request from system attr to DRAM attr
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_mss_power_control_requested));

        if ( l_mss_power_control_requested == fapi2::ENUM_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED_FASTEXIT)
        {
            o_atts->eff_dram_dll_ppd = fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_FASTEXIT;
        }
        else
        {
            o_atts->eff_dram_dll_ppd =
                fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_SLOWEXIT; // if "OFF" default to SLOWEXIT, FASTEXIT settings in mba_def.initfile are causing fails.  Workaround to use SLOWEXIT.
        }

        o_atts->eff_dram_dll_reset = fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_RESET_YES; // Always reset DLL at start of IPL.
        o_atts->eff_dram_srt = fapi2::ENUM_ATTR_CEN_EFF_DRAM_SRT_EXTEND; // Always use extended operating temp range.
        o_atts->mss_cal_step_enable = 0xFF; // Always run all cal steps

        // array init
        for(uint8_t i = 0; i < MAX_PORTS_PER_MBA; i++)
        {
            for(uint8_t j = 0; j < MAX_DIMM_PER_PORT; j++)
            {
                // i <-> MAX_PORTS_PER_MBA, j <-> MAX_DIMM_PER_PORT
                o_atts->eff_stack_type[i][j] = 0;
                o_atts->eff_ibm_type[i][j] = 0;
            }
        }

        // Assigning values to attributes
//------------------------------------------------------------------------------
        o_atts->eff_schmoo_wr_eye_min_margin = 70;
        o_atts->eff_schmoo_rd_eye_min_margin = 70;
        o_atts->eff_schmoo_dqs_clk_min_margin = 140;
        o_atts->eff_schmoo_rd_gate_min_margin = 100;
        o_atts->eff_schmoo_addr_cmd_min_margin = 140;

//------------------------------------------------------------------------------
        switch(i_data->dram_device_type[0][0])
        {
            case fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3:
                o_atts->eff_dram_gen = fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4:
                o_atts->eff_dram_gen = fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_DRAM_DEVICE_ERROR().
                            set_TARGET_MBA(i_target_mba).
                            set_DRAM_DEVICE_TYPE(i_data->dram_device_type[0][0]),
                            "Unknown DRAM type on %s!", mss::c_str(i_target_mba));
        }

//------------------------------------------------------------------------------
        switch(i_data->module_type[0][0])
        {
            // Removed CDIMM as a valid EFF_DIMM_TYPE.
            //case fapi2::ENUM_ATTR_CEN_SPD_MODULE_TYPE_CDIMM:
            //    o_atts->eff_dimm_type = fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_CDIMM;
            //    FAPI_INF("WARNING: ATTR_SPD_MODULE_TYPE_CDIMM is obsolete.  Check your VPD for correct definition on %s!", mss::c_str(i_target_mba));
            //    break;
            case fapi2::ENUM_ATTR_CEN_SPD_MODULE_TYPE_RDIMM:
                o_atts->eff_dimm_type = fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_MODULE_TYPE_UDIMM:
                o_atts->eff_dimm_type = fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_UDIMM;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_MODULE_TYPE_LRDIMM:
                o_atts->eff_dimm_type = fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_MOD_TYPE_ERROR().
                            set_TARGET_MBA(i_target_mba).
                            set_MOD_TYPE(i_data->module_type[0][0]),
                            "Unknown DIMM type on %s!", mss::c_str(i_target_mba));
        }

//------------------------------------------------------------------------------
        if ( o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM )
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT, i_target_mba,  l_rdimm_rcd_ibt));

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, i_target_mba,  l_rdimm_rcd_output_timing));

        }

//------------------------------------------------------------------------------
        if(i_data->custom[0][0] == fapi2::ENUM_ATTR_CEN_SPD_CUSTOM_YES)
        {
            o_atts->eff_custom_dimm = fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES;
        }
        else
        {
            o_atts->eff_custom_dimm = fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_NO;
        }

//------------------------------------------------------------------------------
        switch(i_data->sdram_banks[0][0])
        {
            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_BANKS_B4:
                o_atts->eff_dram_banks = 4;                       // DDR4 only
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_BANKS_B8:
                o_atts->eff_dram_banks = 8;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_BANKS_B16:
                o_atts->eff_dram_banks = 16;
                break;

            case  fapi2::ENUM_ATTR_CEN_SPD_SDRAM_BANKS_B32:
                o_atts->eff_dram_banks = 32;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_BANKS_B64:
                o_atts->eff_dram_banks = 64;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_SDRAM_BANK_ERROR().
                            set_TARGET_MBA(i_target_mba).
                            set_SDRAM_BANKS(i_data->sdram_banks[0][0]),
                            "Unknown DRAM banks on %s!", mss::c_str(i_target_mba));
        }

//------------------------------------------------------------------------------
        switch (i_data->sdram_rows[0][0])
        {
            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_ROWS_R12:
                o_atts->eff_dram_rows = 12;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_ROWS_R13:
                o_atts->eff_dram_rows = 13;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_ROWS_R14:
                o_atts->eff_dram_rows = 14;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_ROWS_R15:
                o_atts->eff_dram_rows = 15;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_ROWS_R16:
                o_atts->eff_dram_rows = 16;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_ROWS_R17:
                o_atts->eff_dram_rows = 17;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_ROWS_R18:
                o_atts->eff_dram_rows = 18;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_SDRAM_ROWS_ERROR().
                            set_TARGET_MBA(i_target_mba).
                            set_SDRAM_ROWS(i_data->sdram_rows[0][0]),
                            "Unknown DRAM rows on %s!", mss::c_str(i_target_mba));
        }

//------------------------------------------------------------------------------
        switch (i_data->sdram_columns[0][0])
        {
            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_COLUMNS_C9:
                o_atts->eff_dram_cols = 9;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_COLUMNS_C10:
                o_atts->eff_dram_cols = 10;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_COLUMNS_C11:
                o_atts->eff_dram_cols = 11;
                break;

            case fapi2::ENUM_ATTR_CEN_SPD_SDRAM_COLUMNS_C12:
                o_atts->eff_dram_cols = 12;
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_SDRAM_COLS_ERROR().
                            set_TARGET_MBA(i_target_mba).
                            set_SDRAM_COLS(i_data->sdram_columns[0][0]),
                            "Unknown DRAM cols on %s!", mss::c_str(i_target_mba));
        }

//------------------------------------------------------------------------------
        if (i_data->dram_width[0][0]
            == fapi2::ENUM_ATTR_CEN_SPD_DRAM_WIDTH_W4)
        {
            o_atts->eff_dram_width = fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4;
            o_atts->eff_dram_tdqs = fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE;
        }
        else if (i_data->dram_width[0][0]
                 == fapi2::ENUM_ATTR_CEN_SPD_DRAM_WIDTH_W8)
        {
            o_atts->eff_dram_width = fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8;

            // NOTE: TDQS enable MR1(A11) is only avaliable for X8 in DDR3
            // TDQS disabled for X8 DDR3 CDIMM, enable for ISDIMM
            if ( o_atts->eff_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_NO )
            {
                o_atts->eff_dram_tdqs = fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_ENABLE;
            }
            else
            {
                o_atts->eff_dram_tdqs = fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE;
            }
        }
        else if (i_data->dram_width[0][0]
                 == fapi2::ENUM_ATTR_CEN_SPD_DRAM_WIDTH_W16)
        {
            o_atts->eff_dram_width = fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X16;
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_DRAM_WIDTH_16_ERROR().
                        set_DRAM_WIDTH(i_data->dram_width[0][0]).
                        set_TARGET_MBA(i_target_mba),
                        "Unsupported DRAM width x16 on %s!",
                        mss::c_str(i_target_mba));
        }
        else if (i_data->dram_width[0][0]
                 == fapi2::ENUM_ATTR_CEN_SPD_DRAM_WIDTH_W32)
        {
            o_atts->eff_dram_width = fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X32;
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_DRAM_WIDTH_32_ERROR().
                        set_DRAM_WIDTH(i_data->dram_width[0][0]).
                        set_TARGET_MBA(i_target_mba),
                        "Unsupported DRAM width x32 on %s!",
                        mss::c_str(i_target_mba));
        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_DRAM_WIDTH_ERROR().
                        set_DRAM_WIDTH(i_data->dram_width[0][0]).
                        set_TARGET_MBA(i_target_mba),
                        "Unknown DRAM width on %s!", mss::c_str(i_target_mba));
        }

//------------------------------------------------------------------------------
        o_atts->eff_dram_density = 16;

        if (i_mss_eff_config_data->allow_single_port == fapi2::ENUM_ATTR_CEN_MSS_ALLOW_SINGLE_PORT_FALSE)
        {
            l_allow_port_size = MAX_PORTS_PER_MBA;
        }

        for (uint8_t l_cur_mba_port = 0; l_cur_mba_port < l_allow_port_size; l_cur_mba_port += 1)
        {
            for (uint8_t l_cur_mba_dimm = 0; l_cur_mba_dimm <
                 o_atts->eff_num_drops_per_port; l_cur_mba_dimm += 1)
            {
                if (i_data->sdram_density[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DENSITY_D16GB)
                {
                    i_mss_eff_config_data->cur_dram_density = 16;
                }
                else if (i_data->sdram_density[l_cur_mba_port]
                         [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DENSITY_D8GB)
                {
                    i_mss_eff_config_data->cur_dram_density = 8;
                }
                else if (i_data->sdram_density[l_cur_mba_port]
                         [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DENSITY_D4GB)
                {
                    i_mss_eff_config_data->cur_dram_density = 4;
                }
                else if (i_data->sdram_density[l_cur_mba_port]
                         [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DENSITY_D2GB)
                {
                    i_mss_eff_config_data->cur_dram_density = 2;
                }
                else if (i_data->sdram_density[l_cur_mba_port]
                         [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DENSITY_D1GB)
                {
                    i_mss_eff_config_data->cur_dram_density = 1;
                }
                else
                {
                    i_mss_eff_config_data->cur_dram_density = 1;
                    FAPI_ASSERT(i_mss_eff_config_data->allow_single_port != fapi2::ENUM_ATTR_CEN_MSS_ALLOW_SINGLE_PORT_FALSE,
                                fapi2::CEN_MSS_EFF_CONFIG_DRAM_DENSITY_ERR().
                                set_TARGET_MBA(i_target_mba).
                                set_SDRAM_DENSITY(i_data->sdram_density[l_cur_mba_port][l_cur_mba_dimm]),
                                "Unsupported DRAM density on %s!",
                                mss::c_str(i_target_mba));
                }

//------------------------------------------------------------------------------
                if (o_atts->eff_dram_density >
                    i_mss_eff_config_data->cur_dram_density)
                {
                    o_atts->eff_dram_density =
                        i_mss_eff_config_data->cur_dram_density;
                }

//------------------------------------------------------------------------------
                // Identify/Verify DIMM voltage compatability
                // See mss_volt.C
//------------------------------------------------------------------------------
                // Identify/Assign minimum timing
                i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                [l_cur_mba_dimm] =
                    (i_data->mtb_dividend[l_cur_mba_port]
                     [l_cur_mba_dimm] * 1000)
                    /
                    i_data->mtb_divisor[l_cur_mba_port]
                    [l_cur_mba_dimm];
//------------------------------------------------------------------------------
                i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                [l_cur_mba_dimm] =
                    (i_data->ftb_dividend[l_cur_mba_port]
                     [l_cur_mba_dimm] * 1000)
                    /
                    i_data->ftb_divisor[l_cur_mba_port]
                    [l_cur_mba_dimm];
//------------------------------------------------------------------------------
                // Calculate CL
                // See mss_freq.C
                // call calc_timing_in_clk()
                i_mss_eff_config_data->dram_wr = calc_timing_in_clk
                                                 (
                                                     i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                     [l_cur_mba_dimm],
                                                     i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                     [l_cur_mba_dimm],
                                                     i_data->twrmin[l_cur_mba_port]
                                                     [l_cur_mba_dimm],
                                                     0,
                                                     i_mss_eff_config_data->mss_freq

                                                 );

                if (i_mss_eff_config_data->dram_wr > o_atts->eff_dram_wr)
                {
                    o_atts->eff_dram_wr = i_mss_eff_config_data->dram_wr;
                }

//------------------------------------------------------------------------------
                // call calc_timing_in_clk()
                i_mss_eff_config_data->dram_trcd = calc_timing_in_clk
                                                   (
                                                       i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_data->trcdmin[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_data->fine_offset_trcdmin[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_mss_eff_config_data->mss_freq
                                                   );

                if (i_mss_eff_config_data->dram_trcd >
                    o_atts->eff_dram_trcd)
                {
                    o_atts->eff_dram_trcd =
                        i_mss_eff_config_data->dram_trcd;
                }

//------------------------------------------------------------------------------
                if (i_data->dram_device_type[0][0] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
                {
                    // DDR3
                    i_mss_eff_config_data->dram_trrd = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_data->trrdmin[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           0,
                                                           i_mss_eff_config_data->mss_freq
                                                       );

                    if (i_mss_eff_config_data->dram_trrd >
                        o_atts->eff_dram_trrd)
                    {
                        o_atts->eff_dram_trrd =
                            i_mss_eff_config_data->dram_trrd;
                    }
                }
                else if (i_data->dram_device_type[0][0] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                {
                    // DDR4
                    FAPI_INF("DDR4 Check: spd tRRDs=0x%x, tRRDl=0x%x, mtb=%i, ftb=%i, width=%i",
                             i_data->trrdsmin[l_cur_mba_port][l_cur_mba_dimm],
                             i_data->trrdlmin[l_cur_mba_port][l_cur_mba_dimm],
                             i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port][l_cur_mba_dimm],
                             i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port][l_cur_mba_dimm],
                             o_atts->eff_dram_width);
                    // bool is_2K_page = 0;

                    // get the spd min trrd in clocks
                    i_mss_eff_config_data->dram_trrd = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port][l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port][l_cur_mba_dimm],
                                                           i_data->trrdsmin[l_cur_mba_port][l_cur_mba_dimm],
                                                           0,  // need to put in the trrdsmin_ftb here...
                                                           i_mss_eff_config_data->mss_freq
                                                       );

                    // trrdsmin from SPD is absolute min of DIMM.
                    // need to know page size, then use 6ns for (2k page) otherwise 5ns

                    FAPI_INF("DDR4 Check:  i_tRRD_s(nCK) = %i",  i_mss_eff_config_data->dram_trrd);
                    FAPI_INF("Attribute o_eff_dram_trrd = %i",  o_atts->eff_dram_trrd);
                    // need a table here for other speeds/page sizes

                    // trrd_s = 2K page @ 1600, max(4nCK,6ns)       since min nCK=1.25ns, const 6ns
                    // 1/2 or 1K   page @ 1600, max(4nCK, 5ns)

                    // 1600 1866 2133 2400 (data rate)
                    // 6,   5.3, 5.3, 5.3 ns        for 2k page size (x16)
                    // 5,   4.2, 3.7, 3.3 ns        for 0.5k or 1k page size (x8)
                    // !! NOTE !!  NOT supporting 2k page size (with check for width above should cause error out).

                    if (i_mss_eff_config_data->mss_freq < 1733)           // 1600
                    {
                        l_max_delay = 5000;       // in ps
                    }
                    else if (i_mss_eff_config_data->mss_freq < 2000)      // 1866
                    {
                        l_max_delay = 4200;       // in ps
                    }
                    else if (i_mss_eff_config_data->mss_freq < 2267)      // 2133
                    {
                        l_max_delay = 3700;       // in ps
                    }
                    else // if (i_mss_eff_config_data->mss_freq < 2533)   // 2400
                    {
                        l_max_delay = 3300;       // in ps
                    }

                    uint8_t l_max_delay_clocks = calc_timing_in_clk
                                                 (1, 0, l_max_delay, 0, i_mss_eff_config_data->mss_freq);

                    // find max between l_min_delay_clocks, l_max_delay_clocks and dev_min

                    if (l_min_delay_clocks > l_max_delay_clocks)
                    {
                        l_max_delay_clocks = l_min_delay_clocks;
                    }

                    if (i_mss_eff_config_data->dram_trrd > l_max_delay_clocks)
                    {
                        l_max_delay_clocks = i_mss_eff_config_data->dram_trrd;
                    }

                    if (l_max_delay_clocks > o_atts->eff_dram_trrd)
                    {
                        o_atts->eff_dram_trrd = l_max_delay_clocks;
                    }

//---------------------------------------------------------------------------------------
// trrd_l = max(4nCK,7.5ns)
                    // 1600 1866 2133 2400 (data rate)
                    // 7.5  6.4, 6.4, 6.4 ns        for 2k page size (x16)
                    // 6,   5.3, 5.3, 4.9 ns        for 0.5k or 1k page size (x8)
                    // !! NOTE !!  NOT supporting 2k page size (with check for width above should cause error out).
                    i_mss_eff_config_data->dram_trrdl = calc_timing_in_clk
                                                        (
                                                            i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port][l_cur_mba_dimm],
                                                            i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port][l_cur_mba_dimm],
                                                            i_data->trrdlmin[l_cur_mba_port][l_cur_mba_dimm],
                                                            0, // need to put in the trrdlmin_ftb here...
                                                            i_mss_eff_config_data->mss_freq
                                                        );

                    // condense this later with the if/else above...
                    if (i_mss_eff_config_data->mss_freq < 1733)           // 1600
                    {
                        l_max_delay = 6000;       // in ps
                    }
                    else if (i_mss_eff_config_data->mss_freq < 2000)      // 1866
                    {
                        l_max_delay = 5300;       // in ps
                    }
                    else if (i_mss_eff_config_data->mss_freq < 2267)      // 2133
                    {
                        l_max_delay = 5300;       // in ps
                    }
                    else // if (i_mss_eff_config_data->mss_freq < 2533)   // 2400
                    {
                        l_max_delay = 4900;       // in ps
                    }

                    l_max_delay_clocks = calc_timing_in_clk
                                         (1, 0, l_max_delay, 0, i_mss_eff_config_data->mss_freq);

                    if (l_max_delay_clocks > o_atts->eff_dram_trrdl)
                    {
                        o_atts->eff_dram_trrdl = l_max_delay_clocks;
                    }
                    else if (i_mss_eff_config_data->dram_trrdl > o_atts->eff_dram_trrdl)
                    {
                        o_atts->eff_dram_trrdl = i_mss_eff_config_data->dram_trrdl;
                    }

                    FAPI_INF("DDR4 tRRDs = %i, tRRDl = %i", o_atts->eff_dram_trrd, o_atts->eff_dram_trrdl);

                    // DDR4 Vref DQ Train
                    for (uint8_t l_cur_mba_rank = 0; l_cur_mba_rank < MAX_RANKS_PER_DIMM; l_cur_mba_rank += 1)
                    {
                        o_atts->eff_vref_dq_train_enable[l_cur_mba_port][l_cur_mba_dimm][l_cur_mba_rank] =
                            fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE;

                        //VREF DQ range is set to 1 -> range 2
                        if (l_attr_vpd_dram_wrddr4_vref[l_cur_mba_port] & 0x40)
                        {
                            o_atts->eff_vref_dq_train_range[l_cur_mba_port][l_cur_mba_dimm][l_cur_mba_rank] =
                                fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE2;
                        }
                        else
                        {
                            o_atts->eff_vref_dq_train_range[l_cur_mba_port][l_cur_mba_dimm][l_cur_mba_rank] =
                                fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE1;
                        }

                        o_atts->eff_vref_dq_train_value[l_cur_mba_port][l_cur_mba_dimm][l_cur_mba_rank] =
                            l_attr_vpd_dram_wrddr4_vref[l_cur_mba_port] & 0x3f;
                    }

                    // DDR4 controls/features
                    o_atts->eff_cs_cmd_latency = fapi2::ENUM_ATTR_CEN_EFF_CS_CMD_LATENCY_DISABLE;
                    o_atts->eff_mpr_page = 0;
                    o_atts->eff_mpr_page = 0;
                    o_atts->eff_dram_lpasr = fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_NORMAL;
                    o_atts->eff_geardown_mode = fapi2::ENUM_ATTR_CEN_EFF_GEARDOWN_MODE_HALF;
                    o_atts->eff_per_dram_access = fapi2::ENUM_ATTR_CEN_EFF_PER_DRAM_ACCESS_DISABLE;
                    o_atts->eff_temp_readout = fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_DISABLE;

                    //Preet   --- ISDIMM based System = 4X Refresh and CDIMMs - Normal as per warren
                    if((o_atts->eff_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                       && (o_atts->eff_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4))
                    {
                        o_atts->eff_fine_refresh_mode = fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_NORMAL;
                    }
                    else
                    {
                        o_atts->eff_fine_refresh_mode = fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_NORMAL;
                    }

                    o_atts->eff_mpr_rd_format = fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_SERIAL;
                    o_atts->eff_max_powerdown_mode = fapi2::ENUM_ATTR_CEN_EFF_MAX_POWERDOWN_MODE_DISABLE;
                    o_atts->eff_temp_ref_range = fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_RANGE_NORMAL;
                    o_atts->eff_temp_ref_mode = fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_MODE_DISABLE;
                    o_atts->eff_int_vref_mon = fapi2::ENUM_ATTR_CEN_EFF_INT_VREF_MON_DISABLE;
                    o_atts->eff_self_ref_abort = fapi2::ENUM_ATTR_CEN_EFF_SELF_REF_ABORT_DISABLE;
                    o_atts->eff_rd_preamble_train = fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_TRAIN_DISABLE;
                    o_atts->eff_rd_preamble = fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_1NCLK;
                    o_atts->eff_wr_preamble = fapi2::ENUM_ATTR_CEN_EFF_WR_PREAMBLE_1NCLK;
                    o_atts->eff_odt_input_buff = fapi2::ENUM_ATTR_CEN_EFF_ODT_INPUT_BUFF_ACTIVATED;
                    o_atts->eff_data_mask = fapi2::ENUM_ATTR_CEN_EFF_DATA_MASK_DISABLE;
                    o_atts->eff_write_dbi = fapi2::ENUM_ATTR_CEN_EFF_WRITE_DBI_DISABLE;
                    o_atts->eff_read_dbi = fapi2::ENUM_ATTR_CEN_EFF_READ_DBI_DISABLE;
                    o_atts->eff_ca_parity = fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_DISABLE;
                    o_atts->eff_ca_parity_latency = fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_LATENCY_DISABLE;
                    o_atts->eff_ca_parity_error_status = fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS_CLEAR;
                    o_atts->eff_write_crc = (fapi2::ENUM_ATTR_CEN_EFF_WRITE_CRC_DISABLE);
                    o_atts->eff_crc_wr_latency = fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_4NCK;
                    o_atts->eff_crc_error_clear = fapi2::ENUM_ATTR_CEN_EFF_CRC_ERROR_CLEAR_CLEAR;
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                                set_TARGET_MBA(i_target_mba).
                                set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                                set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                                set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                                set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                                "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
                }

//------------------------------------------------------------------------------
                if (i_data->dram_device_type[0][0] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                {

                    //Fixed DDR4 tCCD_L = 5ck @1600Mbps and ignore SPD completely per Warren Maule.
                    //Note: This is to always be in sync with mba_def.initfile since it's not using attributes for tCCD.
                    //Note: Currently mba_def.initfile v1.83 has DDR4 tCCD_S = 4ck and tCCD_L = 5ck @1600Mbps&1866Mbps, 6ck @2133Mbps&2400Mbps. If that ever changes mss_eff_config.C will also need to change to match.
                    if ((i_mss_eff_config_data->mss_freq == 1600) || (i_mss_eff_config_data->mss_freq == 1866))
                    {
                        o_atts->eff_dram_tccdl = 5;
                    }
                    else if ((i_mss_eff_config_data->mss_freq == 2133) || (i_mss_eff_config_data->mss_freq == 2400))
                    {
                        o_atts->eff_dram_tccdl = 6;
                    }
                    else
                    {
                        FAPI_ASSERT(false,
                                    fapi2::CEN_MSS_EFF_CONFIG_MSS_FREQ().
                                    set_TARGET_MBA(i_target_mba).
                                    set_FREQ_VAL(i_mss_eff_config_data->mss_freq),
                                    "Invalid ATTR_MSS_FREQ = %d on %s!", i_mss_eff_config_data->mss_freq, mss::c_str(i_target_mba));
                    }

                }

                i_mss_eff_config_data->dram_trp = calc_timing_in_clk
                                                  (
                                                      i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                      [l_cur_mba_dimm],
                                                      i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                      [l_cur_mba_dimm],
                                                      i_data->trpmin[l_cur_mba_port]
                                                      [l_cur_mba_dimm],
                                                      i_data->fine_offset_trpmin[l_cur_mba_port]
                                                      [l_cur_mba_dimm],
                                                      i_mss_eff_config_data->mss_freq
                                                  );

                if (i_mss_eff_config_data->dram_trp > o_atts->eff_dram_trp)
                {
                    o_atts->eff_dram_trp = i_mss_eff_config_data->dram_trp;
                }

                if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
                {
                    i_mss_eff_config_data->dram_twtr = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_data->twtrmin[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           0,
                                                           i_mss_eff_config_data->mss_freq
                                                       );

                    if (i_mss_eff_config_data->dram_twtr > o_atts->eff_dram_twtr)
                    {
                        o_atts->eff_dram_twtr = i_mss_eff_config_data->dram_twtr;
                    }
                }
                else if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                {
                    i_mss_eff_config_data->dram_twtr = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_data->twtrsmin[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           0,
                                                           i_mss_eff_config_data->mss_freq
                                                       );
                    o_atts->eff_dram_twtr = i_mss_eff_config_data->dram_twtr;

                    i_mss_eff_config_data->dram_twtrl = calc_timing_in_clk
                                                        (
                                                            i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                            [l_cur_mba_dimm],
                                                            i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                            [l_cur_mba_dimm],
                                                            i_data->twtrlmin[l_cur_mba_port]
                                                            [l_cur_mba_dimm],
                                                            0,
                                                            i_mss_eff_config_data->mss_freq
                                                        );

                    if (i_mss_eff_config_data->dram_twtrl < 4)
                    {
                        o_atts->eff_dram_twtrl = 4;
                    }
                    else
                    {
                        o_atts->eff_dram_twtrl = i_mss_eff_config_data->dram_twtrl;
                    }

                    FAPI_INF("DDR4 twtrs = %i, twtrl = %i", o_atts->eff_dram_twtr, o_atts->eff_dram_twtrl);
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                                set_TARGET_MBA(i_target_mba).
                                set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                                set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                                set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                                set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                                "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
                }

                i_mss_eff_config_data->dram_trtp = calc_timing_in_clk
                                                   (
                                                       i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_data->trtpmin[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       0,
                                                       i_mss_eff_config_data->mss_freq
                                                   );

                if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
                {
                    if (i_mss_eff_config_data->dram_trtp > o_atts->eff_dram_trtp)
                    {
                        o_atts->eff_dram_trtp = i_mss_eff_config_data->dram_trtp;
                    }
                }
                else if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                {
                    if (i_mss_eff_config_data->dram_trtp < 4)
                    {
                        o_atts->eff_dram_trtp = 4;
                    }
                    else
                    {
                        o_atts->eff_dram_trtp = i_mss_eff_config_data->dram_trtp;
                    }
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                                set_TARGET_MBA(i_target_mba).
                                set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                                set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                                set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                                set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                                "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
                }

                i_mss_eff_config_data->dram_tras = calc_timing_in_clk
                                                   (
                                                       i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_data->trasmin[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       0,
                                                       i_mss_eff_config_data->mss_freq
                                                   );

                if (i_mss_eff_config_data->dram_tras >
                    o_atts->eff_dram_tras_u32)
                {
                    o_atts->eff_dram_tras_u32 =
                        i_mss_eff_config_data->dram_tras;
                }

                i_mss_eff_config_data->dram_trc = (calc_timing_in_clk
                                                   (
                                                       i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_data->trcmin[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_data->fine_offset_trcmin[l_cur_mba_port]
                                                       [l_cur_mba_dimm],
                                                       i_mss_eff_config_data->mss_freq
                                                   ));

                if (i_mss_eff_config_data->dram_trc >
                    o_atts->eff_dram_trc_u32)
                {
                    o_atts->eff_dram_trc_u32 =
                        i_mss_eff_config_data->dram_trc;
                }

                if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
                {
                    i_mss_eff_config_data->dram_trfc = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_data->trfcmin[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           0,
                                                           i_mss_eff_config_data->mss_freq
                                                       );

                    if (i_mss_eff_config_data->dram_trfc >
                        o_atts->eff_dram_trfc)
                    {
                        o_atts->eff_dram_trfc =
                            i_mss_eff_config_data->dram_trfc;
                    }
                }
                else if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                {
                    i_mss_eff_config_data->dram_trfc = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_data->trfc1min[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           0,
                                                           i_mss_eff_config_data->mss_freq
                                                       );
                    FAPI_INF("DDR4 Check: spd trfc = 0x%x (%i clks), o_attr=0x%x",
                             i_data->trfc1min[l_cur_mba_port][l_cur_mba_dimm],
                             i_mss_eff_config_data->dram_trfc,
                             o_atts->eff_dram_trfc
                            );

                    if (i_mss_eff_config_data->dram_trfc >
                        o_atts->eff_dram_trfc)
                    {
                        o_atts->eff_dram_trfc =
                            i_mss_eff_config_data->dram_trfc;
                    }

                    // AST HERE: Need DDR4 attributes for other refresh rates, 2x, 4x if we want to support those modes
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                                set_TARGET_MBA(i_target_mba).
                                set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                                set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                                set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                                set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                                "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
                }

                if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
                {
                    i_mss_eff_config_data->dram_tfaw = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           i_data->tfawmin[l_cur_mba_port]
                                                           [l_cur_mba_dimm],
                                                           0,
                                                           i_mss_eff_config_data->mss_freq
                                                       );

                    if (i_mss_eff_config_data->dram_tfaw >
                        o_atts->eff_dram_tfaw_u32)
                    {
                        o_atts->eff_dram_tfaw_u32 =
                            i_mss_eff_config_data->dram_tfaw;
                    }
                }
                else if (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                {
                    i_mss_eff_config_data->dram_tfaw = calc_timing_in_clk
                                                       (
                                                           i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port][l_cur_mba_dimm],
                                                           i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port][l_cur_mba_dimm],
                                                           i_data->tfawmin[l_cur_mba_port][l_cur_mba_dimm],
                                                           0,
                                                           i_mss_eff_config_data->mss_freq
                                                       );
                    FAPI_DBG("DDR4 Check:  SPD=0x%x, i_tFAWmin (nCK) = %i",
                             i_data->tfawmin[l_cur_mba_port][l_cur_mba_dimm], i_mss_eff_config_data->dram_tfaw);

                    // example x8, 1600, min= 25ns => 25/1.25 = 20 clocks
                    const uint8_t min_clks [][6] =          // width, data rate
                    {
                        // NOTE: 2666 and 3200 are TBD, using guess values
                        // 1600 1866 2133 2400 2666 3200
                        { 16,  16,  16,  16,  16,  16},               // x4 (page size = 1/2K)
                        { 20,  22,  23,  26,  29,  32}                // x8 (page size = 1K)
                        //{ xx,  xx,  xx,  xx,  TBD, TBD},              // x16(page size = 2K)
                    };


                    if (i_data->dram_width[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_WIDTH_W4)
                    {
                        l_width_idx = 0;
                    }
                    else //(i_data->dram_width[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_WIDTH_W8)
                    {
                        l_width_idx = 1;
                    }

                    //else (i_data->dram_width == fapi2::ENUM_ATTR_CEN_SPD_DRAM_WIDTH_W16)


                    if (i_mss_eff_config_data->mss_freq < 1733)           // 1600
                    {
                        l_speed_idx  = 0;                 // 1.25ns
                    }
                    else if (i_mss_eff_config_data->mss_freq < 2000)      // 1866
                    {
                        l_speed_idx  = 1;                 // 1.0718ns
                    }
                    else if (i_mss_eff_config_data->mss_freq < 2267)      // 2133
                    {
                        l_speed_idx  = 2;                 // 0.9376ns
                    }
                    else // if (i_mss_eff_config_data->mss_freq < 2533)   // 2400
                    {
                        l_speed_idx  = 3;                 // 0.8333ns
                    }

                    if (o_atts->eff_dram_tfaw_u32 < min_clks[l_width_idx][l_speed_idx])
                    {
                        o_atts->eff_dram_tfaw_u32 =  min_clks[l_width_idx][l_speed_idx];
                    }

                    if (o_atts->eff_dram_tfaw_u32 == 16)  // due to logic bug above
                    {
                        o_atts->eff_dram_tfaw_u32 = 15;
                        FAPI_INF("setting tFAW to 15 due to bug");
                    }

                    FAPI_DBG("Attribute o_eff_dram_tfaw = %i",  o_atts->eff_dram_tfaw_u32);
                }
                else
                {
                    FAPI_ASSERT(false,
                                fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                                set_TARGET_MBA(i_target_mba).
                                set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                                set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                                set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                                set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                                "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
                }
            } // inner for loop
        } // outter for loop

        // Calculate CWL
        if (i_data->dram_device_type[0][0] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 2500)
            {
                o_atts->eff_dram_cwl = 5;
            }
            else if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 1875)
            {
                o_atts->eff_dram_cwl = 6;
            }
            else if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 1500)
            {
                o_atts->eff_dram_cwl = 7;
            }
            else if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 1250)
            {
                o_atts->eff_dram_cwl = 8;
            }
            else if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 1070)
            {
                o_atts->eff_dram_cwl = 9;
            }
            else if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 935)
            {
                o_atts->eff_dram_cwl = 10;
            }
            else if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 833)
            {
                o_atts->eff_dram_cwl = 11;
            }
            else if ((TWO_MHZ / i_mss_eff_config_data->mss_freq) >= 750)
            {
                o_atts->eff_dram_cwl = 12;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_CWL_CALC_ERR().
                            set_TARGET_MBA(i_target_mba).
                            set_CWL_VAL((TWO_MHZ / i_mss_eff_config_data->mss_freq)),
                            "Error calculating CWL");
            }
        }
        else if (i_data->dram_device_type[0][0] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
        {
            // 1st set only
            // need to look at this again...
            if (i_mss_eff_config_data->mss_freq <= (1600 * 1.05)) // 1600
            {
                o_atts->eff_dram_cwl = 9;
            }
            else if (i_mss_eff_config_data->mss_freq <= (1866 * 1.05))    // 1866
            {
                o_atts->eff_dram_cwl = 10;
            }
            else if (i_mss_eff_config_data->mss_freq <= (2133 * 1.05))    // 2133
            {
                o_atts->eff_dram_cwl = 11;
            }
            else if (i_mss_eff_config_data->mss_freq <= (2400 * 1.05))    // 2400
            {
                o_atts->eff_dram_cwl = 12;
            }
            else if (i_mss_eff_config_data->mss_freq <= (2666 * 1.05))    // 2666
            {
                o_atts->eff_dram_cwl = 14;
            }
            else if (i_mss_eff_config_data->mss_freq <= (3200 * 1.05))    // 2666
            {
                o_atts->eff_dram_cwl = 16;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_EFF_CONFIG_CWL_CALC_ERR().
                            set_TARGET_MBA(i_target_mba).
                            set_CWL_VAL(TWO_MHZ / i_mss_eff_config_data->mss_freq),
                            "Error calculating CWL");
            }
        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                        set_TARGET_MBA(i_target_mba).
                        set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                        set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                        set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                        set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                        "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
        }

        // Calculate ZQCAL Interval based on the following equation from Ken:
        //            0.5
        //  ------------------------------ = 13.333ms
        //  (1.5 * 10) + (0.15 * 150)

        o_atts->eff_zqcal_interval = ( 13333 *
                                       i_mss_eff_config_data->mss_freq) / 2;
        // Calculate MEMCAL Interval based on 1sec interval across all bits per DP18

        o_atts->eff_memcal_interval = (62500 *
                                       i_mss_eff_config_data->mss_freq) / 2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_REFRESH_RATE_REQUEST, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_refresh_rate));

        //  Calculate tRFI
        switch(l_refresh_rate)
        {
            case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE:
                o_atts->eff_dram_trfi = ((TRFI_BASE / 2) *
                                         i_mss_eff_config_data->mss_freq) / 2000;
                // Added 1% margin to TRFI
                o_atts->eff_dram_trfi = o_atts->eff_dram_trfi * ONE_PERCENT_FASTER;
                break;

            case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_DOUBLE_10_PERCENT_FASTER:
                o_atts->eff_dram_trfi = ((TRFI_BASE / 2) *
                                         i_mss_eff_config_data->mss_freq) / 2000;
                // Added 10% margin to TRFI
                o_atts->eff_dram_trfi = o_atts->eff_dram_trfi * TEN_PERCENT_FASTER;
                break;

            case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE:
                o_atts->eff_dram_trfi = (TRFI_BASE *
                                         i_mss_eff_config_data->mss_freq) / 2000;
                // Added 1% margin to TRFI
                o_atts->eff_dram_trfi = o_atts->eff_dram_trfi * ONE_PERCENT_FASTER;
                break;

            case fapi2::ENUM_ATTR_MSS_MRW_REFRESH_RATE_REQUEST_SINGLE_10_PERCENT_FASTER:
                o_atts->eff_dram_trfi = (TRFI_BASE *
                                         i_mss_eff_config_data->mss_freq) / 2000;
                // Added 10% margin to TRFI
                o_atts->eff_dram_trfi = o_atts->eff_dram_trfi * TEN_PERCENT_FASTER;
                break;

            default:
                FAPI_ERR("Unknown value in MRW attribute ATTR_MSS_MRW_REFRESH_RATE_REQUEST, setting TRFI to double plus 10 percent on %s",
                         mss::c_str(i_target_mba));
                o_atts->eff_dram_trfi = ((TRFI_BASE / 2) *
                                         i_mss_eff_config_data->mss_freq) / 2000;
                // Added 10% margin to TRFI
                o_atts->eff_dram_trfi = o_atts->eff_dram_trfi * TEN_PERCENT_FASTER;
                break;
        }

        FAPI_INF("Set eff_dram_trfi = %d", o_atts->eff_dram_trfi);

        o_atts->eff_vpd_version = 0xFFFFFF; // set VPD version to a large number, searching for smallest

        // the VPD version is 2 ASCI characters, so this is always later than that
        // Assigning dependent values to attributes
        for (uint8_t l_cur_mba_port = 0; l_cur_mba_port <
             MAX_PORTS_PER_MBA; l_cur_mba_port += 1)
        {
            for (uint8_t l_cur_mba_dimm = 0; l_cur_mba_dimm <
                 MAX_DIMM_PER_PORT; l_cur_mba_dimm += 1)
            {
                if (i_mss_eff_config_data->
                    cur_dimm_spd_valid_u8array[l_cur_mba_port][l_cur_mba_dimm] == MSS_EFF_VALID)
                {
                    if ( i_data->sdram_device_type[l_cur_mba_port][l_cur_mba_dimm] ==
                         fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_NON_STANDARD)
                    {
                        //Preet - Added 3TSV Type here
                        if (i_data->sdram_device_type_signal_loading[l_cur_mba_port][l_cur_mba_dimm] ==
                            fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING_SINGLE_LOAD_STACK )
                        {
                            o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS;
                        }
                        else
                        {
                            o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_DDP_QDP;
                        }
                    }
                    else
                    {
                        o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_NONE;
                    }

                    if (o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
                    {
                        if (i_data->sdram_die_count[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DIE_COUNT_DIE2)
                        {
                            l_die_count = 2;
                        }
                        else if(i_data->sdram_die_count[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DIE_COUNT_DIE3)
                        {
                            l_die_count = 3;
                        }
                        else if(i_data->sdram_die_count[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DIE_COUNT_DIE4)
                        {
                            l_die_count = 4;
                        }
                        else if(i_data->sdram_die_count[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DIE_COUNT_DIE5)
                        {
                            l_die_count = 5;
                        }
                        else if(i_data->sdram_die_count[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DIE_COUNT_DIE6)
                        {
                            l_die_count = 6;
                        }
                        else if(i_data->sdram_die_count[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DIE_COUNT_DIE7)
                        {
                            l_die_count = 7;
                        }
                        else if(i_data->sdram_die_count[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DIE_COUNT_DIE8)
                        {
                            l_die_count = 8;
                        }

                        if (i_data->num_ranks[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R1)
                        {
                            l_ranks_3d_tsv = 1 * l_die_count;
                        }
                        else if (i_data->num_ranks[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R2)
                        {
                            l_ranks_3d_tsv = 2 * l_die_count;
                        }
                        else if (i_data->num_ranks[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R4)
                        {
                            l_ranks_3d_tsv = 4 * l_die_count;
                        }

                        o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] = l_ranks_3d_tsv;

                    }  //end of 3d TSV
                    else      //if Non-3D TSV
                    {
                        if (i_data->num_ranks[l_cur_mba_port]
                            [l_cur_mba_dimm] == 0x04)                 // for 8R LRDIMM  since no ENUM defined yet for SPD of 8R
                        {
                            o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                            [l_cur_mba_dimm] = 8;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                            [l_cur_mba_dimm] = 0x80;                            // DD0/1: 1 master rank
                        }
                        else if (i_data->num_ranks[l_cur_mba_port]
                                 [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R4)
                        {
                            o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                            [l_cur_mba_dimm] = 4;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                            [l_cur_mba_dimm] = 0xF0;
                        }
                        else if (i_data->num_ranks[l_cur_mba_port]
                                 [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R2)
                        {
                            o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                            [l_cur_mba_dimm] = 2;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                            [l_cur_mba_dimm] = 0xC0;
                        }
                        else if (i_data->num_ranks[l_cur_mba_port]
                                 [l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R1)
                        {
                            o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                            [l_cur_mba_dimm] = 1;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                            [l_cur_mba_dimm] = 0x80;
                        }
                        else
                        {
                            o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                            [l_cur_mba_dimm] = 0;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                            [l_cur_mba_dimm] = 0x00;
                        }
                    }

                    //Adding timer overrides for 1600 DDR4 TSV DIMMs
                    //TSV tRCD Override when requiring 1600 freq override (i.e. using 2666 parts)
                    if ((i_mss_eff_config_data->mss_freq == 1600)
                        && (o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS))
                    {
                        o_atts->eff_dram_trcd = 0x0C;
                        o_atts->eff_dram_trp = 0x0B;
                        o_atts->eff_dram_tras_u32 = 0x0000001C;
                        o_atts->eff_dram_trc_u32 = 0x00000027;
                    }

                    // AST HERE: Needed SPD byte33[7,1:0], for expanded IBM_TYPE
                    if ( o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM )
                    {
                        if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 1)
                        {
                            o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_1A;
                        }
                        else if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2)
                        {
                            o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_1B;
                        }
                        else if ((o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4)
                                 && (o_atts->eff_stack_type[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS))
                        {
                            o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_3A;
                        }
                        else if ((o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 8)
                                 && (o_atts->eff_stack_type[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS))
                        {
                            o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_3B;
                        }
                        else
                        {
                            o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_UNDEFINED;
                            FAPI_ASSERT(false,
                                        fapi2::CEN_MSS_EFF_CONFIG_RDIMM_UNSUPPORTED_TYPE().
                                        set_TARGET_MBA(i_target_mba).
                                        set_UNSUPPORTED_VAL(o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm]),
                                        "Currently unsupported IBM_TYPE on %s!", mss::c_str(i_target_mba));
                        }
                    }
                    else if (( o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_UDIMM )
                             && ( o_atts->eff_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES ))
                    {
                        if (o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
                        {
                            if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2)
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_2A;
                            }
                            else if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4)
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_2B;
                            }
                            else
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_UNDEFINED;
                                FAPI_ASSERT(false,
                                            fapi2::CEN_MSS_EFF_CONFIG_UDIMM_UNSUPPORTED_TYPE().
                                            set_TARGET_MBA(i_target_mba).
                                            set_UNSUPPORTED_VAL(o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm]),
                                            "Currently unsupported IBM_TYPE on %s!", mss::c_str(i_target_mba));
                            }
                        }
                        else
                        {
                            if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 1)
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_1A;
                            }
                            else if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2)
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_1B;
                            }
                            else if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4)
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_1D;
                            }
                            else
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_UNDEFINED;
                                FAPI_ASSERT(false,
                                            fapi2::CEN_MSS_EFF_CONFIG_UDIMM_UNSUPPORTED_TYPE().
                                            set_TARGET_MBA(i_target_mba).
                                            set_UNSUPPORTED_VAL(o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm]),
                                            "Currently unsupported IBM_TYPE on %s!", mss::c_str(i_target_mba));
                            }
                        }
                    }
                    else if ( o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM )
                    {
                        if (o_atts->eff_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3)
                        {
                            FAPI_INF("Will set LR atts after orig eff_config functions");
                        }
                        else if (o_atts->eff_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)       // need to update this later...
                        {
                            if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4)
                            {
                                o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_TYPE_5C;
                            }
                            else
                            {
                                FAPI_INF("Will set LR atts after orig eff_config functions");
                            }
                        }
                        else
                        {
                            FAPI_ASSERT(false,
                                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                                        set_TARGET_MBA(i_target_mba).
                                        set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                                        set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                                        set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                                        set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                                        "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
                        }
                    }
                    else
                    {
                        o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_UNDEFINED;
                        FAPI_ASSERT(false,
                                    fapi2::CEN_MSS_EFF_CONFIG_DIMM_UNSUPPORTED_TYPE().
                                    set_TARGET_MBA(i_target_mba).
                                    set_UNSUPPORTED_VAL(o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm]),
                                    "Currently unsupported DIMM_TYPE on %s!", mss::c_str(i_target_mba));
                    }

                    if ( (o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) &&
                         (i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] ==
                          fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3) &&
                         (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 8) )
                    {
                        o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port]
                        [l_cur_mba_dimm] = 1;
                    }
                    else if ((i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
                             && (i_data->sdram_device_type_signal_loading[l_cur_mba_port][l_cur_mba_dimm] ==
                                 fapi2::ENUM_ATTR_CEN_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING_SINGLE_LOAD_STACK))
                    {
                        if(i_data->num_ranks[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R1)
                        {
                            o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] = 1;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port][l_cur_mba_dimm] = 0x80;
                        }
                        else if(i_data->num_ranks[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R2)
                        {
                            o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] = 2;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port][l_cur_mba_dimm] = 0xC0;
                        }
                        else if(i_data->num_ranks[l_cur_mba_port][l_cur_mba_dimm] == fapi2::ENUM_ATTR_CEN_SPD_NUM_RANKS_R4)
                        {
                            o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] = 4;
                            o_atts->eff_dimm_ranks_configed[l_cur_mba_port][l_cur_mba_dimm] = 0xF0;
                        }
                    }
                    else
                    {
                        // AST HERE: Needs SPD byte33[7,1:0],
                        //  currently hard coded to no stacking
                        o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] =
                            o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm];
                    }

                    // Support for new attribute ATTR_EFF_DRAM_ADDRESS_MIRRORING
                    // Bit wise map bit4=RANK0_MIRRORED, bit5=RANK1_MIRRORED, bit6=RANK2_MIRRORED, bit7=RANK3_MIRRORED
                    if ( o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM )
                    {
                        if (o_atts->eff_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
                        {
                            // Assuming Byte136[7:0] right align based on dimm_spd_attributes.xml
                            // Mask for bit0 of Byte136 = 0x00000001
                            if ((i_data->addr_map_reg_to_dram[l_cur_mba_port][l_cur_mba_dimm] & 0x01) != 0)
                            {

                                if (o_atts->eff_stack_type[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
                                {
                                    if (o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 1)
                                    {
                                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                                    }
                                    else if (o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2)
                                    {
                                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x04;
                                    }
                                    else if (o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4)
                                    {
                                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x05;
                                    }
                                    else
                                    {
                                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                                    }
                                }
                                else
                                {
                                    if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4)
                                    {
                                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x05;
                                    }
                                    else if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2)
                                    {
                                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x04;
                                    }
                                    else
                                    {
                                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                                    }
                                }
                            }
                            else
                            {
                                o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                            }
                        }
                    }
                    else if (( o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_UDIMM )
                             && ( o_atts->eff_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES ))
                    {
                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] =
                            l_vpd_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm];
                    }
                    else if ( o_atts->eff_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM )
                    {
                        if (o_atts->eff_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)
                        {
                            // Assuming Byte136[7:0]:Byte137[7:0] right align based on dimm_spd_attributes.xml
                            // Mask for bit0 of Byte136 = 0x00000100
                            if ((i_data->addr_map_reg_to_dram[l_cur_mba_port][l_cur_mba_dimm] & 0x00000001) != 0)
                            {
                                if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4)
                                {
                                    o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x05;
                                }
                                else if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2)
                                {
                                    o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x04;
                                }
                                else
                                {
                                    o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                                }
                            }
                            else
                            {
                                o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                            }
                        }
                        else
                        {
                            // DDR3 LRDIMM not supported
                            o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                        }
                    }
                    else
                    {
                        o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                        FAPI_ASSERT(false,
                                    fapi2::CEN_MSS_EFF_CONFIG_DIMM_UNSUPPORTED_TYPE().
                                    set_TARGET_MBA(i_target_mba),
                                    "Currently unsupported DIMM_TYPE on %s!", mss::c_str(i_target_mba));
                    }
                }
                else
                {
                    o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0;
                    o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0x00;
                    o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_NONE;
                    o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi2::ENUM_ATTR_CEN_EFF_IBM_TYPE_UNDEFINED;
                    o_atts->eff_dram_address_mirroring[l_cur_mba_port][l_cur_mba_dimm] = 0x00;
                }

                if (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] != 0)
                {
                    o_atts->eff_dimm_size[l_cur_mba_port][l_cur_mba_dimm] =
                        (
                            (o_atts->eff_dram_density)
                            *
                            (o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                             [l_cur_mba_dimm])
                            *
                            64
                        )
                        /
                        (
                            8
                            *
                            (o_atts->eff_dram_width)
                        );
                }
                else
                {
                    o_atts->eff_dimm_size[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0;
                }

                o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = 0x0000000000000000LL;

                if(o_atts->eff_vpd_version == 0xFFFFFF ||
                   i_data->vpd_version[l_cur_mba_port][l_cur_mba_dimm] < o_atts->eff_vpd_version )   // find the smallest VPD
                {
                    o_atts->eff_vpd_version = i_data->vpd_version[l_cur_mba_port][l_cur_mba_dimm];
                }
            } // inner for loop
        } // outer for loop


        // Select EFF_DRAM_AL
        if (i_data->dram_device_type[0][0] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR3)
        {
            if ( l_mss_dram_2n_mode_enable == fapi2::ENUM_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_TRUE )
            {
                o_atts->eff_dram_al = fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2; // Always use AL = CL - 2 for 2N/2T mode
            }
            else
            {
                o_atts->eff_dram_al = fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_1; // Always use AL = CL - 1 for 1N/1T mode
            }
        }
        else if (i_data->dram_device_type[0][0] == fapi2::ENUM_ATTR_CEN_SPD_DRAM_DEVICE_TYPE_DDR4)
        {
            if ( o_atts->eff_stack_type[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS )
            {
                if ( l_mss_dram_2n_mode_enable == fapi2::ENUM_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_TRUE )
                {
                    o_atts->eff_dram_al = fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_3; // Always use AL = CL - 3 for 2N/2T mode
                }
                else
                {
                    o_atts->eff_dram_al = fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2; // Always use AL = CL - 2 for 1N/1T mode
                }
            }
            else
            {
                if ( l_mss_dram_2n_mode_enable == fapi2::ENUM_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_TRUE )
                {
                    o_atts->eff_dram_al = fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2; // Always use AL = CL - 2 for 2N/2T mode
                }
                else
                {
                    o_atts->eff_dram_al = fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_1; // Always use AL = CL - 1 for 1N/1T mode
                }
            }
        }
        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN().
                        set_TARGET_MBA(i_target_mba).
                        set_DRAM_DEVICE_TYPE_0_0(i_data->dram_device_type[0][0]).
                        set_DRAM_DEVICE_TYPE_0_1(i_data->dram_device_type[0][1]).
                        set_DRAM_DEVICE_TYPE_1_0(i_data->dram_device_type[1][0]).
                        set_DRAM_DEVICE_TYPE_1_1(i_data->dram_device_type[1][1]),
                        "Incompatable DRAM generation on %s!", mss::c_str(i_target_mba));
        }

    fapi_try_exit:
        return fapi2::current_err;
    } // end mss_eff_config_setup_eff_atts()

    ///
    /// @brief mss_eff_config_write_eff_atts(): This function writes the effective configuration attributes
    /// @param[in] const fapi2::Target<fapi2::TARGET_TYPE_MBA> &i_target_mba: the fapi2 target
    /// @param[in] const mss_eff_config_atts *i_atts: Pointer to mss_eff configuration attributes structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_write_eff_atts(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        mss_eff_config_atts* i_atts)
    {
        i_atts->eff_dram_tras = uint8_t (i_atts->eff_dram_tras_u32);
        i_atts->eff_dram_trc = (uint8_t (i_atts->eff_dram_trc_u32));
        i_atts->eff_dram_tfaw = uint8_t (i_atts->eff_dram_tfaw_u32);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target_mba,
                               i_atts->eff_dram_address_mirroring));

        // Set attributes
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_RANKS_CONFIGED, i_target_mba,
                               i_atts->eff_dimm_ranks_configed));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_RCD_CNTL_WORD_0_15, i_target_mba,
                               i_atts->eff_dimm_rcd_cntl_word_0_15));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_SIZE, i_target_mba,
                               i_atts->eff_dimm_size));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target_mba,
                               i_atts->eff_dimm_type));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba,
                               i_atts->eff_custom_dimm));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target_mba,
                               i_atts->eff_dram_al));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_ASR, i_target_mba,
                               i_atts->eff_dram_asr));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_BANKS, i_target_mba,
                               i_atts->eff_dram_banks));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_BL, i_target_mba,
                               i_atts->eff_dram_bl));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_COLS, i_target_mba,
                               i_atts->eff_dram_cols));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_CWL, i_target_mba,
                               i_atts->eff_dram_cwl));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_DENSITY, i_target_mba,
                               i_atts->eff_dram_density));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_DLL_ENABLE, i_target_mba,
                               i_atts->eff_dram_dll_enable));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD, i_target_mba,
                               i_atts->eff_dram_dll_ppd));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_DLL_RESET, i_target_mba,
                               i_atts->eff_dram_dll_reset));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba,
                               i_atts->eff_dram_gen));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER, i_target_mba,
                               i_atts->eff_dram_output_buffer));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_PASR, i_target_mba,
                               i_atts->eff_dram_pasr));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_RBT, i_target_mba,
                               i_atts->eff_dram_rbt));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_ROWS, i_target_mba,
                               i_atts->eff_dram_rows));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_SRT, i_target_mba,
                               i_atts->eff_dram_srt));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TDQS, i_target_mba,
                               i_atts->eff_dram_tdqs));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TFAW, i_target_mba,
                               i_atts->eff_dram_tfaw));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TM, i_target_mba,
                               i_atts->eff_dram_tm));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRAS, i_target_mba,
                               i_atts->eff_dram_tras));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRC, i_target_mba,
                               i_atts->eff_dram_trc));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRCD, i_target_mba,
                               i_atts->eff_dram_trcd));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRFC, i_target_mba,
                               i_atts->eff_dram_trfc));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRFI, i_target_mba,
                               i_atts->eff_dram_trfi));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRP, i_target_mba,
                               i_atts->eff_dram_trp));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRRD, i_target_mba,
                               i_atts->eff_dram_trrd));
        // DDR4 only
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRRD_L, i_target_mba,
                               i_atts->eff_dram_trrdl));
        // DDR4 only
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_TCCD_L, i_target_mba,
                               i_atts->eff_dram_tccdl));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TCCD_L, i_target_mba,
                               i_atts->eff_dram_tccdl));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TRTP, i_target_mba,
                               i_atts->eff_dram_trtp));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TWTR, i_target_mba,
                               i_atts->eff_dram_twtr));
        // DDR4 only
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_TWTR_L, i_target_mba,
                               i_atts->eff_dram_twtrl));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba,
                               i_atts->eff_dram_width));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WR, i_target_mba,
                               i_atts->eff_dram_wr));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE, i_target_mba,
                               i_atts->eff_dram_wr_lvl_enable));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_IBM_TYPE, i_target_mba,
                               i_atts->eff_ibm_type));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_MEMCAL_INTERVAL, i_target_mba,
                               i_atts->eff_memcal_interval));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_MPR_LOC, i_target_mba,
                               i_atts->eff_mpr_loc));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_MPR_MODE, i_target_mba,
                               i_atts->eff_mpr_mode));

        // AST HERE: Needs SPD byte33[6:4], currently hard coded to 0, removed for GA1
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_DIES_PER_PACKAGE, i_target_mba,
                               i_atts->eff_num_dies_per_package));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, i_target_mba,
                               i_atts->eff_num_drops_per_port));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba,
                               i_atts->eff_num_master_ranks_per_dimm));

        // AST HERE: Needs source data, currently hard coded to 0, removed for GA1
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_PACKAGES_PER_RANK, i_target_mba,
                               i_atts->eff_num_packages_per_rank));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba,
                               i_atts->eff_num_ranks_per_dimm));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_MODE, i_target_mba,
                               i_atts->eff_schmoo_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE, i_target_mba,
                               i_atts->eff_schmoo_addr_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_PARAM_VALID, i_target_mba,
                               i_atts->eff_schmoo_param_valid));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, i_target_mba,
                               i_atts->eff_schmoo_test_valid));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_WR_EYE_MIN_MARGIN, i_target_mba,
                               i_atts->eff_schmoo_wr_eye_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_RD_EYE_MIN_MARGIN, i_target_mba,
                               i_atts->eff_schmoo_rd_eye_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_DQS_CLK_MIN_MARGIN, i_target_mba,
                               i_atts->eff_schmoo_dqs_clk_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_RD_GATE_MIN_MARGIN, i_target_mba,
                               i_atts->eff_schmoo_rd_gate_min_margin));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN, i_target_mba,
                               i_atts->eff_schmoo_addr_cmd_min_margin));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_RD_VREF_SCHMOO, i_target_mba,
                               i_atts->eff_cen_rd_vref_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_WR_VREF_SCHMOO, i_target_mba,
                               i_atts->eff_dram_wr_vref_schmoo));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, i_target_mba,
                               i_atts->eff_cen_rcv_imp_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, i_target_mba,
                               i_atts->eff_cen_drv_imp_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_CNTL_SCHMOO, i_target_mba,
                               i_atts->eff_cen_drv_imp_cntl_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_CLK_SCHMOO, i_target_mba,
                               i_atts->eff_cen_drv_imp_clk_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_SPCKE_SCHMOO, i_target_mba,
                               i_atts->eff_cen_drv_imp_spcke_schmoo));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO, i_target_mba,
                               i_atts->eff_cen_slew_rate_dq_dqs_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_CNTL_SCHMOO, i_target_mba,
                               i_atts->eff_cen_slew_rate_cntl_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_ADDR_SCHMOO, i_target_mba,
                               i_atts->eff_cen_slew_rate_addr_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_CLK_SCHMOO, i_target_mba,
                               i_atts->eff_cen_slew_rate_clk_schmoo));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_SPCKE_SCHMOO, i_target_mba,
                               i_atts->eff_cen_slew_rate_spcke_schmoo));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,
                               i_atts->eff_stack_type));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_ZQCAL_INTERVAL, i_target_mba,
                               i_atts->eff_zqcal_interval));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, i_target_mba,
                               i_atts->dimm_functional_vector));

        // DDR4 Only
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target_mba,  i_atts->eff_vref_dq_train_value));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target_mba,  i_atts->eff_vref_dq_train_range));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target_mba,  i_atts->eff_vref_dq_train_enable));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_MPR_PAGE, i_target_mba,  i_atts->eff_mpr_page));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DRAM_LPASR, i_target_mba,  i_atts->eff_dram_lpasr));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_GEARDOWN_MODE, i_target_mba,  i_atts->eff_geardown_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_PER_DRAM_ACCESS, i_target_mba,  i_atts->eff_per_dram_access));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_TEMP_READOUT, i_target_mba,  i_atts->eff_temp_readout));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_FINE_REFRESH_MODE, i_target_mba,  i_atts->eff_fine_refresh_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CRC_WR_LATENCY, i_target_mba,  i_atts->eff_crc_wr_latency));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_MPR_RD_FORMAT, i_target_mba,  i_atts->eff_mpr_rd_format));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_MAX_POWERDOWN_MODE, i_target_mba,  i_atts->eff_max_powerdown_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_TEMP_REF_RANGE, i_target_mba,  i_atts->eff_temp_ref_range));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_TEMP_REF_MODE, i_target_mba,  i_atts->eff_temp_ref_mode));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_INT_VREF_MON, i_target_mba,  i_atts->eff_int_vref_mon));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_SELF_REF_ABORT, i_target_mba,  i_atts->eff_self_ref_abort));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_RD_PREAMBLE_TRAIN, i_target_mba,  i_atts->eff_rd_preamble_train));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_RD_PREAMBLE, i_target_mba,  i_atts->eff_rd_preamble));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_WR_PREAMBLE, i_target_mba,  i_atts->eff_wr_preamble));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_ODT_INPUT_BUFF, i_target_mba,  i_atts->eff_odt_input_buff));
        //FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_RTT_PARK, i_target_mba,  i_atts->eff_rtt_park));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DATA_MASK, i_target_mba,  i_atts->eff_data_mask));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_WRITE_DBI, i_target_mba,  i_atts->eff_write_dbi));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_READ_DBI, i_target_mba,  i_atts->eff_read_dbi));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CA_PARITY, i_target_mba,  i_atts->eff_ca_parity));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CA_PARITY_LATENCY, i_target_mba,  i_atts->eff_ca_parity_latency));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS, i_target_mba,
                               i_atts->eff_ca_parity_error_status));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_WRITE_CRC, i_target_mba,  i_atts->eff_write_crc));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CS_CMD_LATENCY, i_target_mba,  i_atts->eff_cs_cmd_latency));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_CRC_ERROR_CLEAR, i_target_mba,  i_atts->eff_crc_error_clear));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC00, i_target_mba,  i_atts->eff_dimm_ddr4_rc00));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC01, i_target_mba,  i_atts->eff_dimm_ddr4_rc01));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC02, i_target_mba,  i_atts->eff_dimm_ddr4_rc02));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC03, i_target_mba,  i_atts->eff_dimm_ddr4_rc03));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC04, i_target_mba,  i_atts->eff_dimm_ddr4_rc04));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC05, i_target_mba,  i_atts->eff_dimm_ddr4_rc05));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC06_07, i_target_mba,  i_atts->eff_dimm_ddr4_rc06_07));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC08, i_target_mba,  i_atts->eff_dimm_ddr4_rc08));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC09, i_target_mba,  i_atts->eff_dimm_ddr4_rc09));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC10, i_target_mba,  i_atts->eff_dimm_ddr4_rc10));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC11, i_target_mba,  i_atts->eff_dimm_ddr4_rc11));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC12, i_target_mba,  i_atts->eff_dimm_ddr4_rc12));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC13, i_target_mba,  i_atts->eff_dimm_ddr4_rc13));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC14, i_target_mba,  i_atts->eff_dimm_ddr4_rc14));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC15, i_target_mba,  i_atts->eff_dimm_ddr4_rc15));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_1x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_1x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_2x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_2x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_3x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_3x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_4x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_4x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_5x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_5x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_6x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_6x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_7x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_7x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_8x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_8x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_9x, i_target_mba,  i_atts->eff_dimm_ddr4_rc_9x));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_Ax, i_target_mba,  i_atts->eff_dimm_ddr4_rc_ax));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_Bx, i_target_mba,  i_atts->eff_dimm_ddr4_rc_bx));

        // Calibration switches
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_CAL_STEP_ENABLE, i_target_mba,
                               i_atts->mss_cal_step_enable));

        // Make the final VPD version be a number and not ascii
        i_atts->eff_vpd_version = ((i_atts->eff_vpd_version & 0x0f00) >> 4) |
                                  ((i_atts->eff_vpd_version & 0x000f) >> 0);
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_EFF_VPD_VERSION, i_target_mba,
                               i_atts->eff_vpd_version));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief mss_eff_config(): read and verify spd data as well as configure effective attributes.
    /// @param[in] const fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target_mba: the fapi2 target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_eff_config(const fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target_mba)
    {
        const auto l_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
        // mss_eff_config_data_variable struct
        mss_eff_config_data* l_mss_eff_config_data = new mss_eff_config_data();
        // mss_eff_config_spd_data struct
        mss_eff_config_spd_data* l_spd_data = new mss_eff_config_spd_data();
        // mss_eff_config_atts struct
        mss_eff_config_atts* l_atts = new mss_eff_config_atts();
        /* End Variable Initialization */

        FAPI_INF("STARTING mss_eff_config on %s \n",
                 mss::c_str(i_target_mba));

        // Added call to mss_eff_pre_config() for Mike Pardeik (power/thermal).
        FAPI_TRY(mss_eff_pre_config(i_target_mba));
        // Grab allow single port data
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_ALLOW_SINGLE_PORT, i_target_mba,
                               l_mss_eff_config_data->allow_single_port));

        if ( l_mss_eff_config_data->allow_single_port == fapi2::ENUM_ATTR_CEN_MSS_ALLOW_SINGLE_PORT_TRUE )
        {
            FAPI_INF("WARNING: allow_single_port = %d on %s.", l_mss_eff_config_data->allow_single_port,
                     mss::c_str(i_target_mba));
        }

        // Grab freq/volt data
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur,  l_mss_eff_config_data->mss_freq));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_target_centaur,  l_mss_eff_config_data->mss_volt));

        FAPI_ASSERT(l_mss_eff_config_data->mss_freq != 0,
                    fapi2::CEN_MSS_EFF_CONFIG_MSS_FREQ().
                    set_TARGET_MBA(i_target_mba).
                    set_FREQ_VAL(l_mss_eff_config_data->mss_freq),
                    "Invalid ATTR_MSS_FREQ = %d on %s!",
                    l_mss_eff_config_data->mss_freq,
                    mss::c_str(i_target_mba));

        FAPI_INF("mss_freq = %d, tCK_in_ps= %d on %s.",
                 l_mss_eff_config_data->mss_freq,
                 TWO_MHZ / l_mss_eff_config_data->mss_freq,
                 mss::c_str(l_target_centaur));

        FAPI_INF("mss_volt = %d on %s.", l_mss_eff_config_data->mss_volt, mss::c_str(l_target_centaur));
        /* Function calls */
        // get SPD data
        FAPI_TRY(mss_eff_config_get_spd_data( i_target_mba, l_mss_eff_config_data, l_spd_data, l_atts ));

        // verify dimm plug rules
        FAPI_TRY(mss_eff_config_verify_plug_rules( i_target_mba, l_mss_eff_config_data, l_atts ));

        // verify SPD data
        if(( l_atts->eff_num_drops_per_port
             != fapi2::ENUM_ATTR_CEN_EFF_NUM_DROPS_PER_PORT_EMPTY )
           && ( l_mss_eff_config_data->allow_single_port == fapi2::ENUM_ATTR_CEN_MSS_ALLOW_SINGLE_PORT_FALSE ))
        {
            FAPI_TRY(mss_eff_config_verify_spd_data( i_target_mba, l_atts, l_spd_data ));
        }

        // setup effective configuration attributes
        FAPI_TRY(mss_eff_config_setup_eff_atts( i_target_mba, l_mss_eff_config_data, l_spd_data, l_atts ));

        // write effective configuration attributes
        FAPI_TRY(mss_eff_config_write_eff_atts( i_target_mba, l_atts ));

        // Calls to sub-procedures
        FAPI_TRY(mss_eff_config_rank_group(i_target_mba));

        FAPI_TRY(mss_eff_config_shmoo(i_target_mba));

        FAPI_INF("mss_eff_config on %s COMPLETE\n", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    } // end mss_eff_config()
} // extern "C"

