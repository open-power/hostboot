/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_config.H $ */
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
/// @file p9c_mss_eff_config.H
/// @brief  Takes in spd and configures effective attrs
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Anuwat Saetow <asaetow@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef MSS_EFF_CONFIG_H_
#define MSS_EFF_CONFIG_H_

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <dimmConsts.H>

typedef fapi2::ReturnCode (*p9c_mss_eff_config_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target_mba);

///
/// @brief struct mss_eff_config_data
/// @brief holds the the variables used in many function calls
///        in mss_eff_config.C
struct mss_eff_config_data
{
    uint8_t cur_dimm_spd_valid_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t dimm_functional;
    uint8_t allow_single_port;
    uint8_t cur_dram_density;
    uint32_t mss_freq;
    uint32_t mss_volt;
    uint32_t mtb_in_ps_u32array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t ftb_in_fs_u32array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t dram_tfaw;
    uint32_t dram_tras;
    uint32_t dram_trc;
    uint8_t dram_trcd;
    uint32_t dram_trfc;
    uint8_t dram_trp;
    uint8_t dram_trrd;
    uint8_t dram_trtp;
    uint8_t dram_twtr;
    uint8_t dram_wr;
    uint8_t dram_trrdl;
    uint8_t dram_tccdl;
    uint8_t dram_twtrl;

};

///
/// @brief struct mss_eff_config_spd_data
/// @brief holds the DIMM SPD data for an MBA
struct mss_eff_config_spd_data
{
    uint8_t dram_device_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_device_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_device_type_signal_loading[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_die_count[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t module_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t custom[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_banks[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_density[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_rows[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_columns[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t num_ranks[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t dram_width[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t module_memory_bus_width[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t ftb_dividend[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t ftb_divisor[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t mtb_dividend[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t mtb_divisor[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t twrmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t trcdmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t trrdmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; // DDR3 only
    uint8_t trpmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t trasmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t trcmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t trfcmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; // DDR3 only
    uint8_t twtrmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; // DDR3 only
    uint8_t trtpmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t tfawmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];


    // DDR4 only
    uint8_t sdram_bankgroups_ddr4[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t trrdsmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t trrdlmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t tccdlmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t trfc1min[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t trfc2min[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t trfc4min[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t twtrsmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t twtrlmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t addr_map_reg_to_dram[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; // Assuming right align based on dimm_spd_attributes.xml

    // Not needed for GA1 CDIMM, will need to enable check for ISDIMM.
    uint8_t sdram_optional_features[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t sdram_thermal_and_refresh_options[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t module_thermal_sensor[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];

    uint8_t fine_offset_tckmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t fine_offset_taamin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t fine_offset_trcdmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t fine_offset_trpmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t fine_offset_trcmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    // DDR4 only
    uint8_t fine_offset_tccdlmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t fine_offset_trrdlmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t fine_offset_trrdsmin[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t fine_offset_tckmax[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    // ATTR_SPD_MODULE_SPECIFIC_SECTION, Located in DDR3 SPD bytes 60d - 116d
    uint32_t vpd_version[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
};

///
/// @brief struct mss_eff_config_atts
/// @brief holds the effective configuration attributes
struct mss_eff_config_atts
{
    uint8_t eff_dimm_ranks_configed[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dram_address_mirroring[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    // Using SPD byte68,69:76, enabled in GA2 for full RDIMM support
    uint64_t eff_dimm_rcd_cntl_word_0_15[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_size[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_type;
    uint8_t eff_custom_dimm;
    uint8_t eff_dram_al; // Based on 2N/2T or 1N/1T enable
    uint8_t eff_dram_asr;
    uint8_t eff_dram_bl;
    uint8_t eff_dram_banks;
    uint8_t eff_cs_cmd_latency;
    uint8_t eff_dimm_ddr4_rc00[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc01[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc02[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc03[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc04[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc05[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc06_07[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc08[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc09[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc10[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc11[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc12[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc13[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc14[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc15[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_1x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_2x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_3x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_4x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_5x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_6x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_7x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_8x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_9x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_ax[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dimm_ddr4_rc_bx[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_dram_cols;
    uint8_t eff_dram_cwl;
    uint8_t eff_dram_density;
    uint8_t eff_dram_dll_enable;
    uint8_t eff_dram_dll_ppd; // Check MRW, ATTR_MRW_POWER_CONTROL_REQUESTED attr
    uint8_t eff_dram_dll_reset; // Always reset DLL at start of IPL.
    uint8_t eff_dram_gen;
    uint8_t eff_dram_output_buffer;
    uint8_t eff_dram_pasr;
    uint8_t eff_dram_rbt;
    uint8_t eff_dram_rows;
    uint8_t eff_dram_srt; // Always use extended operating temp range.
    uint8_t eff_dram_tdqs;
    uint8_t eff_dram_tfaw;
    uint32_t eff_dram_tfaw_u32;
    uint8_t eff_dram_tm;
    uint8_t eff_dram_tras;
    uint32_t eff_dram_tras_u32;
    uint8_t eff_dram_trc;
    uint32_t eff_dram_trc_u32;
    uint8_t eff_dram_trcd;
    uint32_t eff_dram_trfc;
    uint32_t eff_dram_trfi;
    uint8_t eff_dram_trp;
    uint8_t eff_dram_trrd;
    uint8_t eff_dram_trtp;
    uint8_t eff_dram_twtr;
    uint8_t eff_dram_width;
    uint8_t eff_dram_wr;
    uint8_t eff_dram_wr_lvl_enable;
    uint8_t eff_ibm_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t eff_memcal_interval;
    uint8_t eff_mpr_loc;
    uint8_t eff_mpr_mode;

    // AST HERE: Needs SPD DDR3 byte33[6:4], DDR4 byte6[6:4] currently hard coded to 0
    uint8_t eff_num_dies_per_package[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];

    uint8_t eff_num_drops_per_port;
    uint8_t eff_num_master_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];

    // AST HERE: Needs source data, currently hard coded to 0
    uint8_t eff_num_packages_per_rank[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];

    uint8_t eff_num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t eff_schmoo_mode;
    uint8_t eff_schmoo_addr_mode;
    uint8_t eff_schmoo_wr_eye_min_margin;
    uint8_t eff_schmoo_rd_eye_min_margin;
    uint8_t eff_schmoo_dqs_clk_min_margin;
    uint8_t eff_schmoo_rd_gate_min_margin;
    uint8_t eff_schmoo_addr_cmd_min_margin;
    uint32_t eff_cen_rd_vref_schmoo[MAX_PORTS_PER_MBA];
    uint32_t eff_dram_wr_vref_schmoo[MAX_PORTS_PER_MBA];
    uint32_t eff_cen_rcv_imp_dq_dqs_schmoo[MAX_PORTS_PER_MBA];
    uint32_t eff_cen_drv_imp_dq_dqs_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_drv_imp_cntl_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_drv_imp_clk_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_drv_imp_spcke_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_slew_rate_dq_dqs_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_slew_rate_cntl_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_slew_rate_addr_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_slew_rate_clk_schmoo[MAX_PORTS_PER_MBA];
    uint8_t eff_cen_slew_rate_spcke_schmoo[MAX_PORTS_PER_MBA];

    uint8_t eff_schmoo_param_valid;
    uint8_t eff_schmoo_test_valid;
    uint8_t eff_stack_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t eff_zqcal_interval;
    uint8_t dimm_functional_vector;
    uint8_t mss_cal_step_enable; // Always run all cal steps
    uint32_t eff_vpd_version;

    // DDR4 attributes
    uint8_t eff_dram_trrdl;
    uint8_t eff_dram_tccdl;
    //uint8_t eff_dram_tccds;
    uint8_t eff_dram_twtrl;
    uint8_t eff_vref_dq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t eff_vref_dq_train_range[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t eff_vref_dq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t eff_mpr_page;
    uint8_t eff_dram_lpasr;
    uint8_t eff_geardown_mode;
    uint8_t eff_per_dram_access;
    uint8_t eff_temp_readout;
    uint8_t eff_fine_refresh_mode;
    uint8_t eff_mpr_rd_format;
    uint8_t eff_max_powerdown_mode;
    uint8_t eff_temp_ref_range;
    uint8_t eff_temp_ref_mode;
    uint8_t eff_int_vref_mon;
    uint8_t eff_self_ref_abort;
    uint8_t eff_rd_preamble_train;
    uint8_t eff_rd_preamble;
    uint8_t eff_wr_preamble;
    uint8_t eff_odt_input_buff;
    uint8_t eff_data_mask;
    uint8_t eff_write_dbi;
    uint8_t eff_read_dbi;
    uint8_t eff_ca_parity;
    uint8_t eff_ca_parity_latency;
    uint8_t eff_ca_parity_error_status;
    // DDR4 CRC attributes
    uint8_t eff_write_crc;
    uint8_t eff_crc_wr_latency;
    uint8_t eff_crc_error_clear;
};


extern "C" {

    ///
    /// @brief mss_eff_config(): read and verify spd data as well as configure effective attributes.
    /// @param[in] i_target_mba: the fapi2 mba target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_eff_config(const fapi2::Target<fapi2::TARGET_TYPE_MBA> i_target_mba);

    ///
    /// @brief mss_eff_config_get_spd_data(): This function sets gathers the DIMM info then uses mss_eff_config_read_spd_data()
    /// @param[in]  i_target_mba: the fapi2 target
    /// @param[in]  i_mss_eff_config_data: Pointer to mss_eff_config_data variable structure
    /// @param[out] o_spd_data: Pointer to mss_eff configuration spd data structure
    /// @param[in]  i_atts: Pointer to the attribute data structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_get_spd_data(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            mss_eff_config_data* i_mss_eff_config_data,
            mss_eff_config_spd_data* o_spd_data,
            mss_eff_config_atts* i_atts);

    ///
    /// @brief mss_eff_config_read_spd_data(): This function reads DIMM SPD data
    /// @param[in]      i_target_dimm: target dimm
    /// @param[in,out]  o_spd_data: Pointer to mss_eff configuration spd data structure
    /// @param[in]      i_port: current mba port
    /// @param[in]      i_dimm: current mba dimm
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_read_spd_data(const fapi2::Target<fapi2::TARGET_TYPE_DIMM> i_target_dimm,
            mss_eff_config_spd_data* o_spd_data,
            const uint8_t i_port, const uint8_t i_dimm);

    ///
    /// @brief mss_eff_config_verify_plug_rules(): This function verifies DIMM plug rules based on which dimms are present
    /// @param[in] i_target_mba: the fapi2 target
    /// @param[in] i_mss_eff_config_data: Pointer to mss_eff_config_data variable structure
    /// @param[in] i_atts: Pointer to mss_eff configuration attributes structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_verify_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&  i_target_mba,
            mss_eff_config_data* i_mss_eff_config_data,
            mss_eff_config_atts* i_atts);

    ///
    /// @brief mss_eff_config_verify_spd_data(): This function verifies DIMM SPD data
    /// @param[in] i_target_mba: the fapi2 target
    /// @param[in] i_atts: Pointer to mss_eff configuration attributes structure
    /// @param[in] i_data: Pointer to mss_eff configuration spd data structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_verify_spd_data(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            mss_eff_config_atts* i_atts,
            mss_eff_config_spd_data* i_data);

    ///
    /// @brief mss_eff_config_setup_eff_atts(): This function sets up the effective configuration attributes
    /// @param[in] i_target_mba: the fapi2 target
    /// @param[in] i_mss_eff_config_data: Pointer to mss_eff_config_data variable structure
    /// @param[in] i_data: Pointer to mss_eff configuration spd data structure
    /// @param[out] o_atts: Pointer to mss_eff configuration attributes structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_setup_eff_atts(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            mss_eff_config_data* i_mss_eff_config_data,
            mss_eff_config_spd_data* i_data,
            mss_eff_config_atts* o_atts);


    ///
    /// @brief mss_eff_config_write_eff_atts(): This function writes the effective configuration attributes
    /// @param[in] i_target_mba: the fapi2 target
    /// @param[in] i_atts: Pointer to mss_eff configuration attributes structure
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode mss_eff_config_write_eff_atts(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            mss_eff_config_atts* i_atts);

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
                                const uint32_t i_unit, uint8_t i_offset, const uint32_t i_mss_freq);



} // extern "C"

#endif // MSS_EFF_CONFIG_H

