/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config.C $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_eff_config.C,v 1.10 2012/08/02 18:31:50 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is to setup attributes used in other mss procedures.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.10  | bellows  |02-AUG-12| Added in DIMM functional vector for Daniel
//   1.9   | asaetow  |29-MAY-12| Added divide by 0 check for mss_freq. 
//         |          |         | Added 9 new attributes from memory_attributes.xml v1.23 
//         |          |         | Changed plug_config to my_attr_eff_num_drops_per_port.
//         |          |         | NOTE: DO NOT pick-up without memory_attributes.xml v1.23 or newer.
//         |          |         | NOTE: Some hard code still in place awaiting SPD attributes bytes[76:68,33,8].
//   1.8   | asaetow  |04-MAY-12| Fixed my_attr_eff_dimm_size calcualtion and use new ATTR_EFF_DRAM_WIDTH enum from memory_attributes.xml v1.22 
//         |          |         | NOTE: DO NOT pick-up without memory_attributes.xml v1.22 or newer.
//   1.7   | asaetow  |04-MAY-12| Removed calc_u8_timing_in_clk(). 
//         |          |         | Changed calc_u32_timing_in_clk() to calc_timing_in_clk() and changed params.
//         |          |         | Removed currently unused vars.
//   1.6   | asaetow  |03-MAY-12| Removed FAPI_ATTR_SET(ATTR_EFF_DRAM_CL), moved to mss_freq.C.
//         |          |         | Fixed "suggest parentheses around && within ||", per Mike Jones.
//         |          |         | Changed tCK_in_ps calc to reduce num of operations.
//   1.5   | asaetow  |02-MAY-12| Removed #include <*.C>, per FW.
//         |          |         | Added #include <mss_eff_config_thermal.H>
//         |          |         | Added call to sub-procedure mss_eff_config_thermal().
//   1.4   | asaetow  |30-APR-12| Changed procedure to use SPD attributes.
//         |          |         | Added calls to sub-procedures mss_eff_config_rank_group() and mss_eff_config_termination().
//   1.3   | asaetow  |18-APR-12| Changed procedure to print use mss_eff_config_sim.C until 30APR2012.
//   1.2   | asaetow  |03-NOV-11| Fixed to comply with mss_eff_config.H.
//         |          |         | Added calls to mss_eff_config_rank_group() and mss_eff_config_thermal().
//   1.1   | asaetow  |01-NOV-11| First Draft.



//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------
#include <mss_eff_config.H>
#include <mss_eff_config_rank_group.H>
#include <mss_eff_config_termination.H>
#include <mss_eff_config_thermal.H>



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>



//----------------------------------------------------------------------
// ENUMs   
//----------------------------------------------------------------------
enum {
   EMPTY = 0,
   VALID = 255,
};



extern "C" {



//******************************************************************************
//* name=calc_timing_in_clk, param=my_tCK_in_ps,my_mtb_in_ps,my_ftb_in_fs,my_unit,my_offset, return=my_timing_in_clk
//******************************************************************************
uint32_t calc_timing_in_clk(uint32_t my_tCK_in_ps, uint32_t my_mtb_in_ps, uint32_t my_ftb_in_fs, uint32_t my_unit, uint8_t my_offset) {

   uint64_t my_timing = (my_unit * my_mtb_in_ps) + (my_offset * my_ftb_in_fs);
   // ceiling()
   uint32_t my_timing_in_clk = my_timing / my_tCK_in_ps;
   if ((my_timing_in_clk * my_tCK_in_ps) < my_timing) {
      my_timing_in_clk += 1;
   }
   // DEBUG HERE:
   //FAPI_INF("calc_timing_in_clk: my_timing_in_clk = %d, my_tCK_in_ps = %d, my_mtb_in_ps = %d, my_ftb_in_fs = %d, my_unit = %d, my_offset = %d", my_timing_in_clk, my_tCK_in_ps, my_mtb_in_ps, my_ftb_in_fs, my_unit, my_offset );
   
   return my_timing_in_clk;
}



//******************************************************************************
//* name=mss_eff_config, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config(const fapi::Target i_target_mba) {
   fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
   const char * const PROCEDURE_NAME = "mss_eff_config";
   FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());

   // Define attribute array size
   const uint8_t PORT_SIZE = 2;
   const uint8_t DIMM_SIZE = 2;

   // Define spd attribute array size
   // HERE const uint8_t SPD_ATTR_SIZE_18 = 18;
   // HERE const uint8_t SPD_ATTR_SIZE_57 = 57;
   // HERE const uint8_t SPD_ATTR_SIZE_80 = 80;

   // Define local variables
   uint8_t cur_dimm_spd_valid_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t cur_mba_port = 0;
   uint8_t cur_mba_dimm = 0;
   uint8_t dimm_functional_vector = 0x00;
   uint8_t dimm_functional=0; 
   uint8_t cur_dram_density = 0;
   uint32_t mss_freq = 0;
   uint32_t mss_volt = 0;
   uint32_t tCK_in_ps= 0;
   uint32_t mtb_in_ps_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint32_t ftb_in_fs_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t my_dram_taa = 0;
   uint32_t my_dram_tfaw = 0;
   uint32_t my_dram_tras = 0;
   uint32_t my_dram_trc = 0;
   uint8_t my_dram_trcd = 0;
   uint32_t my_dram_trfc = 0;
   uint8_t my_dram_trp = 0;
   uint8_t my_dram_trrd = 0;
   uint8_t my_dram_trtp = 0;
   uint8_t my_dram_twtr = 0;
   uint8_t my_dram_wr = 0;

   // Define local attribute variables
   uint8_t my_attr_eff_dimm_ranks_configed[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint64_t my_attr_eff_dimm_rcd_cntl_word_0_15[PORT_SIZE][DIMM_SIZE] = {{0}}; // AST HERE: Needs SPD byte68:76
   uint8_t my_attr_eff_dimm_size[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t my_attr_eff_dimm_type = 0;
   uint8_t my_attr_eff_dram_al = 1;
   uint8_t my_attr_eff_dram_asr = 0;
   uint8_t my_attr_eff_dram_bl = 0;
   uint8_t my_attr_eff_dram_banks = 0;
   // See mss_freq.C
   //uint8_t my_attr_eff_dram_cl = 0;
   uint8_t my_attr_eff_dram_cols = 0;
   uint8_t my_attr_eff_dram_cwl = 0;
   uint8_t my_attr_eff_dram_density = 0;
   uint8_t my_attr_eff_dram_dll_enable = 0;
   uint8_t my_attr_eff_dram_dll_ppd = 0;
   uint8_t my_attr_eff_dram_dll_reset = 1;
   uint8_t my_attr_eff_dram_gen = 0;
   uint8_t my_attr_eff_dram_output_buffer = 0;
   uint8_t my_attr_eff_dram_pasr = 0;
   uint8_t my_attr_eff_dram_rbt = 0;
   uint8_t my_attr_eff_dram_rows = 0;
   uint8_t my_attr_eff_dram_srt = 1;
   uint8_t my_attr_eff_dram_tdqs = 0;
   uint8_t my_attr_eff_dram_tfaw = 0;
   uint32_t my_attr_eff_dram_tfaw_u32 = 0;
   uint8_t my_attr_eff_dram_tm = 0;
   uint8_t my_attr_eff_dram_tras = 0;
   uint32_t my_attr_eff_dram_tras_u32 = 0;
   uint8_t my_attr_eff_dram_trc = 0;
   uint32_t my_attr_eff_dram_trc_u32 = 0;
   uint8_t my_attr_eff_dram_trcd = 0;
   uint32_t my_attr_eff_dram_trfc = 0;
   uint32_t my_attr_eff_dram_trfi = 0;
   uint8_t my_attr_eff_dram_trp = 0;
   uint8_t my_attr_eff_dram_trrd = 0;
   uint8_t my_attr_eff_dram_trtp = 0;
   uint8_t my_attr_eff_dram_twtr = 0;
   uint8_t my_attr_eff_dram_width = 0;
   uint8_t my_attr_eff_dram_wr = 0;
   uint8_t my_attr_eff_dram_wr_lvl_enable = 0;

   // AST HERE: Needs SPD byte33[7,1:0], currently hard coded to TYPE_1B
   uint8_t my_attr_eff_ibm_type[PORT_SIZE][DIMM_SIZE] = {{2,2},{2,2}};

   uint32_t my_attr_eff_memcal_interval = 0;
   uint8_t my_attr_eff_mpr_loc = 0x0;
   uint8_t my_attr_eff_mpr_mode = 0;

   // AST HERE: Needs SPD byte33[6:4], currently hard coded to 0
   uint8_t my_attr_eff_num_dies_per_package[PORT_SIZE][DIMM_SIZE] = {{0}};

   uint8_t my_attr_eff_num_drops_per_port = 0;
   uint8_t my_attr_eff_num_master_ranks_per_dimm[PORT_SIZE][DIMM_SIZE] = {{0}};
   
   // AST HERE: Needs source data, currently hard coded to 0
   uint8_t my_attr_eff_num_packages_per_rank[PORT_SIZE][DIMM_SIZE] = {{0}};

   uint8_t my_attr_eff_num_ranks_per_dimm[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t my_attr_eff_schmoo_mode = 0;
   uint8_t my_attr_eff_schmoo_param_valid = 0x0;
   uint8_t my_attr_eff_schmoo_test_valid = 0x0;

   // AST HERE: Needs SPD byte33[7,1:0], currently hard coded to 1
   uint8_t my_attr_eff_stack_type[PORT_SIZE][DIMM_SIZE] = {{1,1},{1,1}};

   uint32_t my_attr_eff_zqcal_interval = 0;

   // Define local spd attribute variables
   uint8_t spd_dram_device_type_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_module_type_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_sdram_banks_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_sdram_density_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_sdram_rows_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_sdram_columns_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t spd_module_nominal_voltage_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_num_ranks_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_dram_width_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_module_memory_bus_width_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_ftb_dividend_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_ftb_divisor_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_mtb_dividend_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_mtb_divisor_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t spd_tckmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint32_t spd_cas_latencies_supported_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t spd_taamin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_twrmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_trcdmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_trrdmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_trpmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint32_t spd_trasmin_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint32_t spd_trcmin_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint32_t spd_trfcmin_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_twtrmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_trtpmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint32_t spd_tfawmin_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t spd_sdram_optional_features_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t spd_sdram_thermal_and_refresh_options_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t spd_module_thermal_sensor_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_fine_offset_tckmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_fine_offset_taamin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_fine_offset_trcdmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_fine_offset_trpmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   uint8_t spd_fine_offset_trcmin_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   // HERE uint8_t spd_module_specific_section_u8array[PORT_SIZE][DIMM_SIZE][SPD_ATTR_SIZE_57] = {{{0}}};
   //uint32_t spd_module_id_module_manufacturers_jedec_id_code_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint8_t spd_module_id_module_manufacturing_location_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint32_t spd_module_id_module_manufacturing_date_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint32_t spd_module_id_module_serial_number_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint32_t spd_cyclical_redundancy_code_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   // HERE uint8_t spd_module_part_number_u8array[PORT_SIZE][DIMM_SIZE][SPD_ATTR_SIZE_18] = {{{0}}};
   //uint32_t spd_module_revision_code_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   //uint32_t spd_dram_manufacturer_jedec_id_code_u32array[PORT_SIZE][DIMM_SIZE] = {{0}};
   // HERE uint8_t spd_bad_dq_data_u8array[PORT_SIZE][DIMM_SIZE][SPD_ATTR_SIZE_80] = {{{0}}};


   // Grab freq/volt data.
   fapi::Target l_target_centaur;
   rc = fapiGetParentChip(i_target_mba, l_target_centaur); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, mss_freq); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, mss_volt); if(rc) return rc;
   if (mss_freq <= 0) {
      FAPI_ERR("Invalid ATTR_MSS_FREQ = %d on %s!", mss_freq, i_target_mba.toEcmdString());
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
   }
   tCK_in_ps = 2000000/mss_freq;
   FAPI_INF("mss_freq = %d, tCK_in_ps= %d on %s.", mss_freq, tCK_in_ps, l_target_centaur.toEcmdString());
   FAPI_INF("mss_volt = %d on %s.", mss_volt, l_target_centaur.toEcmdString());


   // Grab all DIMM/SPD data.
   std::vector<fapi::Target> l_target_dimm_array;
   rc = fapiGetAssociatedDimms(i_target_mba, l_target_dimm_array); if(rc) return rc;
   for (uint8_t dimm_index = 0; dimm_index < l_target_dimm_array.size(); dimm_index += 1) {

      rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &l_target_dimm_array[dimm_index], cur_mba_port); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &l_target_dimm_array[dimm_index], cur_mba_dimm); if(rc) return rc;
      cur_dimm_spd_valid_u8array[cur_mba_port][cur_mba_dimm] = VALID;

      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_target_dimm_array[dimm_index], dimm_functional); if(rc) return rc;
      if(dimm_functional == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL) 
        dimm_functional=1;
      else
        dimm_functional=0;
      dimm_functional_vector |=  dimm_functional << ((4*(1-cur_mba_port))+(4-cur_mba_dimm)-1);

      rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &l_target_dimm_array[dimm_index], spd_dram_device_type_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE, &l_target_dimm_array[dimm_index], spd_module_type_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_BANKS, &l_target_dimm_array[dimm_index], spd_sdram_banks_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_DENSITY, &l_target_dimm_array[dimm_index], spd_sdram_density_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_ROWS, &l_target_dimm_array[dimm_index], spd_sdram_rows_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_COLUMNS, &l_target_dimm_array[dimm_index], spd_sdram_columns_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE, &l_target_dimm_array[dimm_index], spd_module_nominal_voltage_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_NUM_RANKS, &l_target_dimm_array[dimm_index], spd_num_ranks_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_WIDTH, &l_target_dimm_array[dimm_index], spd_dram_width_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_MEMORY_BUS_WIDTH, &l_target_dimm_array[dimm_index], spd_module_memory_bus_width_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVIDEND, &l_target_dimm_array[dimm_index], spd_ftb_dividend_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVISOR, &l_target_dimm_array[dimm_index], spd_ftb_divisor_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVIDEND, &l_target_dimm_array[dimm_index], spd_mtb_dividend_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVISOR, &l_target_dimm_array[dimm_index], spd_mtb_divisor_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_TCKMIN, &l_target_dimm_array[dimm_index], spd_tckmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED, &l_target_dimm_array[dimm_index], spd_cas_latencies_supported_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_TAAMIN, &l_target_dimm_array[dimm_index], spd_taamin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TWRMIN, &l_target_dimm_array[dimm_index], spd_twrmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TRCDMIN, &l_target_dimm_array[dimm_index], spd_trcdmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TRRDMIN, &l_target_dimm_array[dimm_index], spd_trrdmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TRPMIN, &l_target_dimm_array[dimm_index], spd_trpmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TRASMIN, &l_target_dimm_array[dimm_index], spd_trasmin_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TRCMIN, &l_target_dimm_array[dimm_index], spd_trcmin_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TRFCMIN, &l_target_dimm_array[dimm_index], spd_trfcmin_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TWTRMIN, &l_target_dimm_array[dimm_index], spd_twtrmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TRTPMIN, &l_target_dimm_array[dimm_index], spd_trtpmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_TFAWMIN, &l_target_dimm_array[dimm_index], spd_tfawmin_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_OPTIONAL_FEATURES, &l_target_dimm_array[dimm_index], spd_sdram_optional_features_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS, &l_target_dimm_array[dimm_index], spd_sdram_thermal_and_refresh_options_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_THERMAL_SENSOR, &l_target_dimm_array[dimm_index], spd_module_thermal_sensor_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TCKMIN, &l_target_dimm_array[dimm_index], spd_fine_offset_tckmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TAAMIN, &l_target_dimm_array[dimm_index], spd_fine_offset_taamin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TRCDMIN, &l_target_dimm_array[dimm_index], spd_fine_offset_trcdmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TRPMIN, &l_target_dimm_array[dimm_index], spd_fine_offset_trpmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TRCMIN, &l_target_dimm_array[dimm_index], spd_fine_offset_trcmin_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      // HERE rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_SPECIFIC_SECTION, &l_target_dimm_array[dimm_index], spd_module_specific_section_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE, &l_target_dimm_array[dimm_index], spd_module_id_module_manufacturers_jedec_id_code_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION, &l_target_dimm_array[dimm_index], spd_module_id_module_manufacturing_location_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE, &l_target_dimm_array[dimm_index], spd_module_id_module_manufacturing_date_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_SERIAL_NUMBER, &l_target_dimm_array[dimm_index], spd_module_id_module_serial_number_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_CYCLICAL_REDUNDANCY_CODE, &l_target_dimm_array[dimm_index], spd_cyclical_redundancy_code_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      // HERE rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_PART_NUMBER, &l_target_dimm_array[dimm_index], spd_module_part_number_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_REVISION_CODE, &l_target_dimm_array[dimm_index], spd_module_revision_code_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      //rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE, &l_target_dimm_array[dimm_index], spd_dram_manufacturer_jedec_id_code_u32array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
      // HERE rc = FAPI_ATTR_GET(ATTR_SPD_BAD_DQ_DATA, &l_target_dimm_array[dimm_index], spd_bad_dq_data_u8array[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
   }


   // Identify/Verify DIMM plug rule
   if ((cur_dimm_spd_valid_u8array[0][0] == EMPTY) && ((cur_dimm_spd_valid_u8array[0][1] == VALID) || (cur_dimm_spd_valid_u8array[1][0] == VALID) || (cur_dimm_spd_valid_u8array[1][1] == VALID))) {
      FAPI_ERR("Plug rule violation on %s!", i_target_mba.toEcmdString());
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
   }
   if (((cur_dimm_spd_valid_u8array[0][0] == VALID) && (cur_dimm_spd_valid_u8array[1][0] == EMPTY)) || ((cur_dimm_spd_valid_u8array[0][1] == VALID) && (cur_dimm_spd_valid_u8array[1][1] == EMPTY))) {
      FAPI_ERR("Plug rule violation on %s!", i_target_mba.toEcmdString());
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
   }
   if ((cur_dimm_spd_valid_u8array[0][0] == VALID) && (cur_dimm_spd_valid_u8array[0][1] == VALID)) {
      my_attr_eff_num_drops_per_port = fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL;
   } else if ((cur_dimm_spd_valid_u8array[0][0] == VALID) && (cur_dimm_spd_valid_u8array[0][1] == EMPTY)) {
      my_attr_eff_num_drops_per_port = fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE;
   } else {
      my_attr_eff_num_drops_per_port = fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_EMPTY;
   }


   // Start Identify/Verify/Assigning values to attributes
   if (my_attr_eff_num_drops_per_port != fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_EMPTY) {

      // Identify/Verify DIMM compatability
      if ((spd_dram_device_type_u8array[0][0] != spd_dram_device_type_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_dram_device_type_u8array[0][1] != spd_dram_device_type_u8array[1][1]) || (spd_dram_device_type_u8array[0][0] != spd_dram_device_type_u8array[0][1])))) {
         FAPI_ERR("Incompatable DRAM generation on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if ((spd_module_type_u8array[0][0] != spd_module_type_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_module_type_u8array[0][1] != spd_module_type_u8array[1][1]) || (spd_module_type_u8array[0][0] != spd_module_type_u8array[0][1])))) {
         FAPI_ERR("Incompatable DIMM type on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if ((spd_num_ranks_u8array[0][0] != spd_num_ranks_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_num_ranks_u8array[0][1] != spd_num_ranks_u8array[1][1]) || (spd_num_ranks_u8array[0][0] != spd_num_ranks_u8array[0][1])))) {
         FAPI_ERR("Incompatable DIMM ranks on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if ((spd_sdram_banks_u8array[0][0] != spd_sdram_banks_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_sdram_banks_u8array[0][1] != spd_sdram_banks_u8array[1][1]) || (spd_sdram_banks_u8array[0][0] != spd_sdram_banks_u8array[0][1])))) {
         FAPI_ERR("Incompatable DIMM banks on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if ((spd_sdram_rows_u8array[0][0] != spd_sdram_rows_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_sdram_rows_u8array[0][1] != spd_sdram_rows_u8array[1][1]) || (spd_sdram_rows_u8array[0][0] != spd_sdram_rows_u8array[0][1])))) {
         FAPI_ERR("Incompatable DIMM rows on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if ((spd_sdram_columns_u8array[0][0] != spd_sdram_columns_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_sdram_columns_u8array[0][1] != spd_sdram_columns_u8array[1][1]) || (spd_sdram_columns_u8array[0][0] != spd_sdram_columns_u8array[0][1])))) {
         FAPI_ERR("Incompatable DIMM cols on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if ((spd_module_memory_bus_width_u8array[0][0] != spd_module_memory_bus_width_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_module_memory_bus_width_u8array[0][1] != spd_module_memory_bus_width_u8array[1][1]) || (spd_module_memory_bus_width_u8array[0][0] != spd_module_memory_bus_width_u8array[0][1])))) {
         FAPI_ERR("Incompatable DRAM primary bus width on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      /* AST HERE: Needs SPD byte8[4:3]
      if ((spd_module_memory_bus_width_extension_u8array[0][0] != spd_module_memory_bus_width_extension_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_module_memory_bus_width_extension_u8array[0][1] != spd_module_memory_bus_width_extension_u8array[1][1])) || ((spd_module_memory_bus_width_extension_u8array[0][0] != spd_module_memory_bus_width_extension_u8array[0][1])))) {
         FAPI_ERR("Incompatable DRAM bus width extension on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if ((spd_module_memory_bus_width_u8array[0][0] != fapi::ENUM_ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_W64) || (spd_module_memory_bus_width_extension_u8array[0][0] != fapi::ENUM_ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_EXTENSION_W8)) {
         FAPI_ERR("Unsupported DRAM bus width on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      */
      if ((spd_dram_width_u8array[0][0] != spd_dram_width_u8array[1][0]) || ((my_attr_eff_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL) && ((spd_dram_width_u8array[0][1] != spd_dram_width_u8array[1][1]) || (spd_dram_width_u8array[0][0] != spd_dram_width_u8array[0][1])))) {
         FAPI_ERR("Incompatable DRAM width on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }

      // Assigning values to attributes
      if (spd_dram_device_type_u8array[0][0] == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3) {
         my_attr_eff_dram_gen = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3;
      } else if (spd_dram_device_type_u8array[0][0] == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4) {
         my_attr_eff_dram_gen = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4;
      } else {
         FAPI_ERR("Unknown DRAM type on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if (spd_module_type_u8array[0][0] == fapi::ENUM_ATTR_SPD_MODULE_TYPE_CDIMM) {
         my_attr_eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM;
      } else if (spd_module_type_u8array[0][0] == fapi::ENUM_ATTR_SPD_MODULE_TYPE_RDIMM) {
         my_attr_eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM;
      } else if (spd_module_type_u8array[0][0] == fapi::ENUM_ATTR_SPD_MODULE_TYPE_UDIMM) {
         my_attr_eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM;
      } else if (spd_module_type_u8array[0][0] == fapi::ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM) {
         my_attr_eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM;
      } else {
         FAPI_ERR("Unknown DIMM type on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if (spd_sdram_banks_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B8) {
         my_attr_eff_dram_banks = 8;
      } else if (spd_sdram_banks_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B16) {
         my_attr_eff_dram_banks = 16;
      } else if (spd_sdram_banks_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B32) {
         my_attr_eff_dram_banks = 32;
      } else if (spd_sdram_banks_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B64) {
         my_attr_eff_dram_banks = 64;
      } else {
         FAPI_ERR("Unknown DRAM banks on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if (spd_sdram_rows_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R12) {
         my_attr_eff_dram_rows = 12;
      } else if (spd_sdram_rows_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R13) {
         my_attr_eff_dram_rows = 13;
      } else if (spd_sdram_rows_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R14) {
         my_attr_eff_dram_rows = 14;
      } else if (spd_sdram_rows_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R15) {
         my_attr_eff_dram_rows = 15;
      } else if (spd_sdram_rows_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R16) {
         my_attr_eff_dram_rows = 16;
      } else {
         FAPI_ERR("Unknown DRAM rows on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if (spd_sdram_columns_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C9) {
         my_attr_eff_dram_cols = 9;
      } else if (spd_sdram_columns_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C10) {
         my_attr_eff_dram_cols = 10;
      } else if (spd_sdram_columns_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C11) {
         my_attr_eff_dram_cols = 11;
      } else if (spd_sdram_columns_u8array[0][0] == fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C12) {
         my_attr_eff_dram_cols = 12;
      } else {
         FAPI_ERR("Unknown DRAM cols on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      if (spd_dram_width_u8array[0][0] == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W4) {
         my_attr_eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4;
      } else if (spd_dram_width_u8array[0][0] == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W8) {
         my_attr_eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8;
         // NOTE: TDQS enable MR1(A11) is only avaliable for X8 in DDR3
         my_attr_eff_dram_tdqs = 1;
      } else if (spd_dram_width_u8array[0][0] == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W16) {
         my_attr_eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X16;
         FAPI_ERR("Unsupported DRAM width x16 on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      } else if (spd_dram_width_u8array[0][0] == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W32) {
         my_attr_eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X32;
         FAPI_ERR("Unsupported DRAM width x32 on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      } else {
         FAPI_ERR("Unknown DRAM width on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
      my_attr_eff_dram_density = 16;
      for (cur_mba_port = 0; cur_mba_port < PORT_SIZE; cur_mba_port += 1) {
         for (cur_mba_dimm = 0; cur_mba_dimm < my_attr_eff_num_drops_per_port; cur_mba_dimm += 1) {
            if (spd_sdram_density_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D16GB) {
               cur_dram_density = 16;
            } else if (spd_sdram_density_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D8GB) {
               cur_dram_density = 8;
            } else if (spd_sdram_density_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D4GB) {
               cur_dram_density = 4;
            } else if (spd_sdram_density_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D2GB) {
               cur_dram_density = 2;
            } else if (spd_sdram_density_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D1GB) {
               cur_dram_density = 1;
            } else {
               FAPI_ERR("Unsupported DRAM density on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
            if (my_attr_eff_dram_density > cur_dram_density) {
               my_attr_eff_dram_density = cur_dram_density;
            }

            // Identify/Verify DIMM voltage compatability
            // See mss_volt.C

            // Identify/Assign minimum timing
            mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm] = (spd_mtb_dividend_u8array[cur_mba_port][cur_mba_dimm] * 1000) / spd_mtb_divisor_u8array[cur_mba_port][cur_mba_dimm];
            ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm] = (spd_ftb_dividend_u8array[cur_mba_port][cur_mba_dimm] * 1000) / spd_ftb_divisor_u8array[cur_mba_port][cur_mba_dimm];

            // Calculate CL
            // See mss_freq.C

            my_dram_wr = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_twrmin_u8array[cur_mba_port][cur_mba_dimm], 0);
            if (my_dram_wr > my_attr_eff_dram_wr) {
               my_attr_eff_dram_wr = my_dram_wr;
            }
            my_dram_trcd = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_trcdmin_u8array[cur_mba_port][cur_mba_dimm], spd_fine_offset_trcdmin_u8array[cur_mba_port][cur_mba_dimm]);
            if (my_dram_trcd > my_attr_eff_dram_trcd) {
               my_attr_eff_dram_trcd = my_dram_trcd;
            }
            my_dram_trrd = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_trrdmin_u8array[cur_mba_port][cur_mba_dimm], 0);
            if (my_dram_trrd > my_attr_eff_dram_trrd) {
               my_attr_eff_dram_trrd = my_dram_trrd;
            }
            my_dram_trp = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_trpmin_u8array[cur_mba_port][cur_mba_dimm], spd_fine_offset_trpmin_u8array[cur_mba_port][cur_mba_dimm]);
            if (my_dram_trp > my_attr_eff_dram_trp) {
               my_attr_eff_dram_trp = my_dram_trp;
            }
            my_dram_twtr = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_twtrmin_u8array[cur_mba_port][cur_mba_dimm], 0);
            if (my_dram_twtr > my_attr_eff_dram_twtr) {
               my_attr_eff_dram_twtr = my_dram_twtr;
            }
            my_dram_trtp = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_trtpmin_u8array[cur_mba_port][cur_mba_dimm], 0);
            if (my_dram_trtp > my_attr_eff_dram_trtp) {
               my_attr_eff_dram_trtp = my_dram_trtp;
            }
            my_dram_tras = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_trasmin_u32array[cur_mba_port][cur_mba_dimm], 0);
            if (my_dram_tras > my_attr_eff_dram_tras_u32) {
               my_attr_eff_dram_tras_u32 = my_dram_tras;
            }
            my_dram_trc = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_trcmin_u32array[cur_mba_port][cur_mba_dimm], spd_fine_offset_trcmin_u8array[cur_mba_port][cur_mba_dimm]);
            if (my_dram_trc > my_attr_eff_dram_trc_u32) {
               my_attr_eff_dram_trc_u32 = my_dram_trc;
            }
            my_dram_trfc = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_trfcmin_u32array[cur_mba_port][cur_mba_dimm], 0); if(rc) return rc;
            if (my_dram_trfc > my_attr_eff_dram_trfc) {
               my_attr_eff_dram_trfc = my_dram_trfc;
            }
            my_dram_tfaw = calc_timing_in_clk(tCK_in_ps, mtb_in_ps_u32array[cur_mba_port][cur_mba_dimm], ftb_in_fs_u32array[cur_mba_port][cur_mba_dimm], spd_tfawmin_u32array[cur_mba_port][cur_mba_dimm], 0); if(rc) return rc;
            if (my_dram_tfaw > my_attr_eff_dram_tfaw_u32) {
               my_attr_eff_dram_tfaw_u32 = my_dram_tfaw;
            }
         }
      }

      // Calculate CWL
      if ((2000000/mss_freq) >= 2500) {
         my_attr_eff_dram_cwl = 5;
      } else if ((2000000/mss_freq) >= 1875) {
         my_attr_eff_dram_cwl = 6;
      } else if ((2000000/mss_freq) >= 1500) {
         my_attr_eff_dram_cwl = 7;
      } else if ((2000000/mss_freq) >= 1250) {
         my_attr_eff_dram_cwl = 8;
      } else if ((2000000/mss_freq) >= 1070) {
         my_attr_eff_dram_cwl = 9;
      } else if ((2000000/mss_freq) >= 935) {
         my_attr_eff_dram_cwl = 10;
      } else if ((2000000/mss_freq) >= 833) {
         my_attr_eff_dram_cwl = 11;
      } else if ((2000000/mss_freq) >= 750) {
         my_attr_eff_dram_cwl = 12;
      }

      // Calculate tRFI
      my_attr_eff_dram_trfi = (3900 * mss_freq) / 2000;

      // Assigning dependent values to attributes
      for (cur_mba_port = 0; cur_mba_port < PORT_SIZE; cur_mba_port += 1) {
         for (cur_mba_dimm = 0; cur_mba_dimm < DIMM_SIZE; cur_mba_dimm += 1) {
            if (spd_num_ranks_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_NUM_RANKS_R4) { 
               my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm] = 4;
               my_attr_eff_dimm_ranks_configed[cur_mba_port][cur_mba_dimm] = 0xF0;
            } else if (spd_num_ranks_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_NUM_RANKS_R2) { 
               my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm] = 2;
               my_attr_eff_dimm_ranks_configed[cur_mba_port][cur_mba_dimm] = 0xC0;
            } else if (spd_num_ranks_u8array[cur_mba_port][cur_mba_dimm] == fapi::ENUM_ATTR_SPD_NUM_RANKS_R1) { 
               my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm] = 1;
               my_attr_eff_dimm_ranks_configed[cur_mba_port][cur_mba_dimm] = 0x80;
            } else {
               my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm] = 0;
               my_attr_eff_dimm_ranks_configed[cur_mba_port][cur_mba_dimm] = 0x00;
            }
            if (my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm] != 0) {
               // dimm_size = dram_density / 8 * primary_bus_width / dram_width * num_ranks_per_dimm
               my_attr_eff_dimm_size[cur_mba_port][cur_mba_dimm] = (my_attr_eff_dram_density * my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm] * 64) / (8 * my_attr_eff_dram_width);
            } else {
               my_attr_eff_dimm_size[cur_mba_port][cur_mba_dimm] = 0;
            }

            // AST HERE: Needs SPD byte33[7,1:0], currently hard coded to no stacking
            my_attr_eff_num_master_ranks_per_dimm[cur_mba_port][cur_mba_dimm] = my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm];

            // DEBUG HERE:
            //FAPI_INF("size=%d density=%d ranks=%d width=%d on %s", my_attr_eff_dimm_size[cur_mba_port][cur_mba_dimm], my_attr_eff_dram_density, my_attr_eff_num_ranks_per_dimm[cur_mba_port][cur_mba_dimm], my_attr_eff_dram_width, i_target_mba.toEcmdString());
         }
      }
   }


   my_attr_eff_dram_tras = uint8_t (my_attr_eff_dram_tras_u32);
   my_attr_eff_dram_trc = uint8_t (my_attr_eff_dram_trc_u32);
   my_attr_eff_dram_tfaw = uint8_t (my_attr_eff_dram_tfaw_u32);


   // Set attributes
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RANKS_CONFIGED, &i_target_mba, my_attr_eff_dimm_ranks_configed); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, my_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_SIZE, &i_target_mba, my_attr_eff_dimm_size); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_TYPE, &i_target_mba, my_attr_eff_dimm_type); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_AL, &i_target_mba, my_attr_eff_dram_al); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_ASR, &i_target_mba, my_attr_eff_dram_asr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_BANKS, &i_target_mba, my_attr_eff_dram_banks); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_BL, &i_target_mba, my_attr_eff_dram_bl); if(rc) return rc;
   // See mss_freq.C
   //rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_CL, &i_target_mba, my_attr_eff_dram_cl); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_COLS, &i_target_mba, my_attr_eff_dram_cols); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_CWL, &i_target_mba, my_attr_eff_dram_cwl); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DENSITY, &i_target_mba, my_attr_eff_dram_density); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DLL_ENABLE, &i_target_mba, my_attr_eff_dram_dll_enable); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DLL_PPD, &i_target_mba, my_attr_eff_dram_dll_ppd); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DLL_RESET, &i_target_mba, my_attr_eff_dram_dll_reset); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_GEN, &i_target_mba, my_attr_eff_dram_gen); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_OUTPUT_BUFFER, &i_target_mba, my_attr_eff_dram_output_buffer); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_PASR, &i_target_mba, my_attr_eff_dram_pasr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RBT, &i_target_mba, my_attr_eff_dram_rbt); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_ROWS, &i_target_mba, my_attr_eff_dram_rows); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_SRT, &i_target_mba, my_attr_eff_dram_srt); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TDQS, &i_target_mba, my_attr_eff_dram_tdqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TFAW, &i_target_mba, my_attr_eff_dram_tfaw); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TM, &i_target_mba, my_attr_eff_dram_tm); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRAS, &i_target_mba, my_attr_eff_dram_tras); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRC, &i_target_mba, my_attr_eff_dram_trc); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRCD, &i_target_mba, my_attr_eff_dram_trcd); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRFC, &i_target_mba, my_attr_eff_dram_trfc); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRFI, &i_target_mba, my_attr_eff_dram_trfi); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRP, &i_target_mba, my_attr_eff_dram_trp); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRRD, &i_target_mba, my_attr_eff_dram_trrd); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRTP, &i_target_mba, my_attr_eff_dram_trtp); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TWTR, &i_target_mba, my_attr_eff_dram_twtr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, my_attr_eff_dram_width); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR, &i_target_mba, my_attr_eff_dram_wr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_LVL_ENABLE, &i_target_mba, my_attr_eff_dram_wr_lvl_enable); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_IBM_TYPE, &i_target_mba, my_attr_eff_ibm_type); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_MEMCAL_INTERVAL, &i_target_mba, my_attr_eff_memcal_interval); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_MPR_LOC, &i_target_mba, my_attr_eff_mpr_loc); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_MPR_MODE, &i_target_mba, my_attr_eff_mpr_mode); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_DIES_PER_PACKAGE, &i_target_mba, my_attr_eff_num_dies_per_package); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, my_attr_eff_num_drops_per_port); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target_mba, my_attr_eff_num_master_ranks_per_dimm); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_PACKAGES_PER_RANK, &i_target_mba, my_attr_eff_num_packages_per_rank); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, my_attr_eff_num_ranks_per_dimm); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_MODE, &i_target_mba, my_attr_eff_schmoo_mode); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_PARAM_VALID, &i_target_mba, my_attr_eff_schmoo_param_valid); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, my_attr_eff_schmoo_test_valid); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_STACK_TYPE, &i_target_mba, my_attr_eff_stack_type); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_ZQCAL_INTERVAL, &i_target_mba, my_attr_eff_zqcal_interval); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, &i_target_mba, dimm_functional_vector); if(rc) return rc;

   // Calls to sub-procedures
   rc = mss_eff_config_rank_group(i_target_mba); if(rc) return rc;
   rc = mss_eff_config_termination(i_target_mba); if(rc) return rc;
   rc = mss_eff_config_thermal(i_target_mba); if(rc) return rc;


   FAPI_INF("%s on %s COMPLETE\n", PROCEDURE_NAME, i_target_mba.toEcmdString());
   return rc;
}



} // extern "C"
