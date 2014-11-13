/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: mss_eff_config.C,v 1.48 2014/10/13 22:51:53 asaetow Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/
//          centaur/working/procedures/ipl/fapi/mss_eff_config.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is to setup attributes used in other mss
// procedures.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.49  | asaetow  |15-OCT-14| Added RDIMM SPD/VPD support for ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15 to take in SPD bits69:76 thru new VPD attribute ATTR_VPD_DIMM_RCD_CNTL_WORD_0_15.
//         |          |         | Added ATTR_VPD_DIMM_RCD_IBT and ATTR_VPD_DIMM_RCD_OUTPUT_TIMING merge, per meeting with Ken and Dan P.
//         |          |         | NOTE: DO NOT pickup w/o getMBvpdTermData.C vX.XX or newer. TBD from Dan.C
//         |          |         | NOTE: DO NOT pickup w/o dimm_spd_attributes.xml v1.40 or newer.
//         |          |         | NOTE: DO NOT pickup w/o memory_mss_eff_config.xml v1.3 or newer.
//         |          |         | Added hardcode for RC0-DA4=0b0 and RC9-DBA1-DBA0-DA4-DA3=0b00X0, per meeting with Ken and Dan P.
//         |          |         | Changed l_mss_volt to p_l_mss_eff_config_data->mss_volt.
//   1.48  | asaetow  |13-OCT-14| Removed call to mss_eff_config_termination() for Palmetto and Habanero using ifdef "FAPI_MSSLABONLY", moving to liveVPD.
//         |          |         | Note: Stradale, Glacier, KG3, and DDR4 will still need ifdef "FAPI_MSSLABONLY".
//   1.47  | asaetow  |15-SEP-14| Changed ATTR_MSS_POWER_CONTROL_REQUESTED to ATTR_MRW_POWER_CONTROL_REQUESTED.
//         |          |         | NOTE: Do NOT pickup without memory_attributes.xml v1.135
//   1.46  | asaetow  |06-AUG-14| Added ATTR_MSS_POWER_CONTROL_REQUESTED to determine ATTR_EFF_DRAM_DLL_PPD. 
//   1.45  | sglancy  |05-AUG-14| Updated comments.
//   1.44  | sglancy  |17-JUL-14| Fixed DDR4 ifdef flag - TARGET_MBA error definition
//   1.43  | jdsloat  |04-APR-14| Fixed DDR4 ifdef flag
//   1.42  | asaetow  |31-MAR-14| Added ifdef for three #include from Thi and Jake FW Code review.
//         |          |         | Added back in bus_width_extension check from SPD byte8[4:3]. 
//         |          |         | NOTE: Only 64bit with ECC extension is allowed.
//         |          |         | Added FFDC error callout from Andrea's FW RAS review.
//         |          |         | NOTE: Do NOT pickup without memory_mss_eff_config.xml v1.2
//         |          |         | Added comments for commended out code.
//   1.41  | jdsloat  |20-MAR-14| FASTEXIT settings in mba_def.initfile are causing fails.  Workaround to use SLOWEXIT. SW249561
//   1.40  | kcook    |14-MAR-14| Added call to DDR4 function support
//   1.39  | dcadiga  |04-MAR-14| Added isdimm support pass 1
//   1.38  | asaetow  |17-JAN-14| Removed mss_eff_config_cke_map, now empty, data from vpd.
//         |          |         | Removed mss_eff_config_termination from normal/FW code flow.
//         |          |         | Added mss_eff_config_termination to lab only code flow.
//         |          |         | Removed CDIMM as a valid EFF_DIMM_TYPE, use EFF_CUSTOM_DIMM instead.
//         |          |         | Added ATTR_MSS_CAL_STEP_ENABLE attribute set to "always run all cal steps".
//         |          |         | NOTE: Needs mss_eff_config_termination.C v1.42 and mss_eff_config_termination.H v1.2
//   1.37  | bellows  |17-JAN-14| Fixed VPD version when only single drop
//   1.36  | bellows  |13-JAN-14| Make VPD version available at mba level
//   1.35  | asaetow  |13-JAN-14| Fixed ATTR_EFF_DRAM_DLL_PPD from SLOWEXIT to FASTEXIT.
//         |          |         | Added comments and converted some attr to use enums.
//   1.34  | bellows  |02-JAN-14| VPD attribute removal
//   1.33  | bellows  |16-SEP-13| Hostboot compile update
//   1.32  | kcook    |13-SEP-13| Added using namespace fapi.
//   1.31  | kcook    |13-SEP-13| Updated define FAPI_LRDIMM token.
//   1.30  | kcook    |27-AUG-13| Removed LRDIMM support to mss_lrdimm_funcs.C.
//   1.29  | kcook    |16-AUG-13| Added LRDIMM support.
//   1.28  | asaetow  |06-AUG-13| Added call to mss_eff_pre_config().
//         |          |         | Removed call to mss_eff_config_thermal().
//         |          |         | NOTE: Do NOT pickup without mss_eff_pre_config.C v1.1 or newer.
//   1.27  | asaetow  |05-AUG-13| Restored EFF_STACK_TYPE_DDP_QDP support v1.25.
//         |          |         | NOTE: Do NOT pickup without mss_eff_config_termination.C v1.28 or newer, contains workaround for incorrect byte33 SPD data in early lab OLD 16G/32G CDIMMs.
//   1.26  | bellows  |21-JUN-13| Removed last update because caused lab problems
//   1.25  | asaetow  |20-JUN-13| Added EFF_STACK_TYPE_DDP_QDP support.
//   1.24  | asaetow  |19-APR-13| Fixed X4 CDIMM spare for RCB to use LOW_NIBBLE only.
//   1.23  | asaetow  |17-APR-13| Added 10% margin to TRFI per defect HW248225
//   1.22  | asaetow  |11-APR-13| Changed eff_dram_tdqs from 0 back to 1 for X8 ISDIMMs. 
//   1.21  | asaetow  |22-MAR-13| Changed ATTR_EFF_ZQCAL_INTERVAL and ATTR_EFF_MEMCAL_INTERVAL back to enable.
//         |          |         | NOTE: Need mba_def.initfile v1.27 or newer
//   1.20  | asaetow  |28-FEB-13| Changed temporary ATTR_EFF_ZQCAL_INTERVAL and ATTR_EFF_MEMCAL_INTERVAL to disable.
//         |          |         | NOTE: Temporary until we get timeout error fixed.
//   1.19  | sauchadh |26-FEB-13| Added MCBIST related attributes
//   1.18  | asaetow  |12-FEB-13| Changed eff_dram_tdqs from 1 to 0.
//   1.17  | asaetow  |30-JAN-13| Changed "ATTR_SPD_MODULE_TYPE_CDIMM is obsolete..." message from error to warning.
//   1.16  | bellows  |24-JAN-13| Added in CUSTOM bit of SPD and CUSTOM Attr
//         |          |         | settings.  
//   1.15  | asaetow  |15-NOV-12| Added call to mss_eff_config_cke_map().
//         |          |         | NOTE: DO NOT pick-up without
//         |          |         | mss_eff_config_cke_map.C v1.3 or newer.
//         |          |         | Added ATTR_MSS_ALLOW_SINGLE_PORT check. 
//         |          |         | Added ATTR_EFF_DIMM_SPARE.
//         |          |         | Fixed NUM_RANKS_PER_DIMM for single drop. 
//         |          |         | Fixed calc_timing_in_clk() for negative. 
//         |          |         | Fixed IBM_TYPE and STACK_TYPE. 
//   1.14  | asaetow  |08-NOV-12| Changed to match new memory_attributes.xml
//         |          |         | v1.45 or newer.
//         |          |         | NOTE: DO NOT pick-up without
//         |          |         | memory_attributes.xml v1.45 or newer.
//   1.13  | asaetow  |11-OCT-12| Added ATTR_EFF_SCHMOO_ADDR_MODE, 
//         |          |         | ATTR_EFF_SCHMOO_WR_EYE_MIN_MARGIN,
//         |          |         | ATTR_EFF_SCHMOO_RD_EYE_MIN_MARGIN,
//         |          |         | ATTR_EFF_SCHMOO_DQS_CLK_MIN_MARGIN,
//         |          |         | ATTR_EFF_SCHMOO_RD_GATE_MIN_MARGIN,
//         |          |         | ATTR_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN,
//         |          |         | ATTR_EFF_DRAM_WR_VREF_SCHMOO,
//         |          |         | ATTR_EFF_CEN_RD_VREF_SCHMOO,
//         |          |         | ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO,
//         |          |         | ATTR_EFF_CEN_DRV_IMP_CMD_SCHMOO,
//         |          |         | ATTR_EFF_CEN_DRV_IMP_CNTL_SCHMOO,
//         |          |         | ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO,
//         |          |         | ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO,
//         |          |         | ATTR_EFF_CEN_SLEW_RATE_CMD_SCHMOO,
//         |          |         | and ATTR_EFF_CEN_SLEW_RATE_CNTL_SCHMOO.
//   1.12  | asaetow  |26-SEP-12| Added initial equation for
//         |          |         | ATTR_EFF_ZQCAL_INTERVAL and
//         |          |         | ATTR_EFF_MEMCAL_INTERVAL from Ken.
//   1.11  | kjpower  |26-SEP-12| Restructured code, added modularity
//   1.10  | bellows  |02-AUG-12| Added in DIMM functional vector for Daniel
//   1.9   | asaetow  |29-MAY-12| Added divide by 0 check for mss_freq.
//         |          |         | Added 9 new attributes from
//         |          |         | memory_attributes.xml v1.23
//         |          |         | Changed plug_config to
//         |          |         | my_attr_eff_num_drops_per_port.
//         |          |         | NOTE: DO NOT pick-up without
//         |          |         | memory_attributes.xml v1.23 or newer.
//         |          |         | NOTE: Some hard code still in place awaiting
//         |          |         | SPD attributes bytes[76:68,33,8].
//   1.8   | asaetow  |04-MAY-12| Fixed my_attr_eff_dimm_size calcualtion and
//         |          |         | use new ATTR_EFF_DRAM_WIDTH enum from
//         |          |         | memory_attributes.xml v1.22
//         |          |         | NOTE: DO NOT pick-up without
//         |          |         | memory_attributes.xml v1.22 or newer.
//   1.7   | asaetow  |04-MAY-12| Removed calc_u8_timing_in_clk().
//         |          |         | Changed calc_u32_timing_in_clk() to
//         |          |         | calc_timing_in_clk() and changed params.
//         |          |         | Removed currently unused vars.
//   1.6   | asaetow  |03-MAY-12| Removed FAPI_ATTR_SET(ATTR_EFF_DRAM_CL), moved
//         |          |         | to mss_freq.C.
//         |          |         | Fixed "suggest parentheses around && within
//         |          |         | ||", per Mike Jones.
//         |          |         | Changed tCK_in_ps calc to reduce num of
//         |          |         | operations.
//   1.5   | asaetow  |02-MAY-12| Removed #include <*.C>, per FW.
//         |          |         | Added #include <mss_eff_config_thermal.H>
//         |          |         | Added call to sub-procedure
//         |          |         | mss_eff_config_thermal().
//   1.4   | asaetow  |30-APR-12| Changed procedure to use SPD attributes.
//         |          |         | Added calls to sub-procedures
//         |          |         | mss_eff_config_rank_group() and
//         |          |         | mss_eff_config_termination().
//   1.3   | asaetow  |18-APR-12| Changed procedure to print use
//         |          |         | mss_eff_config_sim.C until 30APR2012.
//   1.2   | asaetow  |03-NOV-11| Fixed to comply with mss_eff_config.H.
//         |          |         | Added calls to mss_eff_config_rank_group()
//         |          |         | and mss_eff_config_thermal().
//   1.1   | asaetow  |01-NOV-11| First Draft.
//------------------------------------------------------------------------------

#include <fapi.H>

//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------
#include <mss_eff_config.H>
#include <mss_eff_pre_config.H>
#include <mss_eff_config_rank_group.H>
#include <mss_eff_config_shmoo.H>

#ifdef FAPI_MSSLABONLY
#include <mss_eff_config_termination.H>
#endif

#ifdef FAPI_LRDIMM
#include <mss_lrdimm_funcs.H>
#endif

#ifdef FAPI_DDR4
#include <mss_eff_config_ddr4.H>
#endif


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
const uint32_t MSS_EFF_EMPTY = 0;
const uint32_t MSS_EFF_VALID = 255;
const uint32_t TWO_MHZ = 2000000;
const uint8_t PORT_SIZE = 2;
const uint8_t DIMM_SIZE = 2;
const uint8_t RANK_SIZE = 4;

using namespace fapi;

#ifndef FAPI_LRDIMM
fapi::ReturnCode mss_lrdimm_eff_config( const Target& i_target_mba,
                                  uint8_t cur_dimm_spd_valid_u8array[PORT_SIZE][DIMM_SIZE],
                                  uint32_t mss_freq, 
                                  uint8_t eff_num_ranks_per_dimm[PORT_SIZE][DIMM_SIZE])
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of LRDIMM function on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_LRDIMM_INVALID_EXEC);
   return rc;

}
#endif

#ifndef FAPI_MSSLABONLY
fapi::ReturnCode mss_eff_config_termination( const Target& i_target_mba)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of MSSLABONLY function on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INVALID_TERM_EXEC);
   return rc;

}
#endif

#ifndef FAPI_DDR4
fapi::ReturnCode mss_eff_config_ddr4( const Target& i_target_mba)
{
   ReturnCode rc;

   FAPI_ERR("Invalid exec of DDR4 function on %s!", i_target_mba.toEcmdString());
   FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_DDR4_INVALID_EXEC);
   return rc;

}
#endif


//------------------------------------------------------------------------------
// Structure
// @brief struct mss_eff_config_data
// @brief holds the the variables used in many function calls
//        in mss_eff_config.C
//------------------------------------------------------------------------------
struct mss_eff_config_data
{
    uint8_t cur_dimm_spd_valid_u8array[PORT_SIZE][DIMM_SIZE];
    uint8_t dimm_functional;
    uint8_t allow_single_port;
    uint8_t cur_dram_density;
    uint32_t mss_freq;
    uint32_t mss_volt;
    uint32_t mtb_in_ps_u32array[PORT_SIZE][DIMM_SIZE];
    uint32_t ftb_in_fs_u32array[PORT_SIZE][DIMM_SIZE];
    //uint8_t dram_taa;
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
};

//------------------------------------------------------------------------------
// Structure
// @brief struct mss_eff_config_spd_data
// @brief holds the DIMM SPD data for an MBA
//------------------------------------------------------------------------------
struct mss_eff_config_spd_data
{
    uint8_t dram_device_type[PORT_SIZE][DIMM_SIZE];
    uint8_t sdram_device_type[PORT_SIZE][DIMM_SIZE];
    uint8_t module_type[PORT_SIZE][DIMM_SIZE];
    uint8_t custom[PORT_SIZE][DIMM_SIZE];
    uint8_t sdram_banks[PORT_SIZE][DIMM_SIZE];
    uint8_t sdram_density[PORT_SIZE][DIMM_SIZE];
    uint8_t sdram_rows[PORT_SIZE][DIMM_SIZE];
    uint8_t sdram_columns[PORT_SIZE][DIMM_SIZE];
    //uint8_t module_nominal_voltage[PORT_SIZE][DIMM_SIZE];
    uint8_t num_ranks[PORT_SIZE][DIMM_SIZE];
    uint8_t dram_width[PORT_SIZE][DIMM_SIZE];
    uint8_t module_memory_bus_width[PORT_SIZE][DIMM_SIZE];
    uint8_t ftb_dividend[PORT_SIZE][DIMM_SIZE];
    uint8_t ftb_divisor[PORT_SIZE][DIMM_SIZE];
    uint8_t mtb_dividend[PORT_SIZE][DIMM_SIZE];
    uint8_t mtb_divisor[PORT_SIZE][DIMM_SIZE];
    //uint8_t tckmin[PORT_SIZE][DIMM_SIZE];
    //uint32_t cas_latencies_supported[PORT_SIZE][DIMM_SIZE];
    //uint8_t taamin[PORT_SIZE][DIMM_SIZE];
    uint8_t twrmin[PORT_SIZE][DIMM_SIZE];
    uint8_t trcdmin[PORT_SIZE][DIMM_SIZE];
    uint8_t trrdmin[PORT_SIZE][DIMM_SIZE];
    uint8_t trpmin[PORT_SIZE][DIMM_SIZE];
    uint32_t trasmin[PORT_SIZE][DIMM_SIZE];
    uint32_t trcmin[PORT_SIZE][DIMM_SIZE];
    uint32_t trfcmin[PORT_SIZE][DIMM_SIZE];
    uint8_t twtrmin[PORT_SIZE][DIMM_SIZE];
    uint8_t trtpmin[PORT_SIZE][DIMM_SIZE];
    uint32_t tfawmin[PORT_SIZE][DIMM_SIZE];

    // Not needed for GA1 CDIMM, will need to enable check for ISDIMM.
    //uint8_t sdram_optional_features[PORT_SIZE][DIMM_SIZE];
    //uint8_t sdram_thermal_and_refresh_options[PORT_SIZE][DIMM_SIZE];
    //uint8_t module_thermal_sensor[PORT_SIZE][DIMM_SIZE];

    uint8_t fine_offset_tckmin[PORT_SIZE][DIMM_SIZE];
    uint8_t fine_offset_taamin[PORT_SIZE][DIMM_SIZE];
    uint8_t fine_offset_trcdmin[PORT_SIZE][DIMM_SIZE];
    uint8_t fine_offset_trpmin[PORT_SIZE][DIMM_SIZE];
    uint8_t fine_offset_trcmin[PORT_SIZE][DIMM_SIZE];

    // ATTR_SPD_MODULE_SPECIFIC_SECTION, Located in DDR3 SPD bytes 60d - 116d
    //uint8_t module_specific_section[PORT_SIZE][DIMM_SIZE][57];         
    uint64_t rdimm_rcd_cntl_word_0_15[PORT_SIZE][DIMM_SIZE];         

    // Moved from DIMM to MBA[port][dimm] attr per DanC. see dimm_spd_attributes.xml v1.40
    //uint32_t rdimm_rcd_ibt[PORT_SIZE][DIMM_SIZE];         
    //uint8_t rdimm_rcd_output_timing[PORT_SIZE][DIMM_SIZE];         

    // See "svpdMFGtool --inventory"
    //uint32_t module_id_module_manufacturers_jedec_id_code[PORT_SIZE][DIMM_SIZE];
    //uint8_t module_id_module_manufacturing_location[PORT_SIZE][DIMM_SIZE];
    //uint32_t module_id_module_manufacturing_date[PORT_SIZE][DIMM_SIZE];
    //uint32_t module_id_module_serial_number[PORT_SIZE][DIMM_SIZE];
    //uint32_t cyclical_redundancy_code[PORT_SIZE][DIMM_SIZE];
    //uint8_t module_part_number[PORT_SIZE][DIMM_SIZE][SPD_ATTR_SIZE_18];
    //uint32_t module_revision_code[PORT_SIZE][DIMM_SIZE];
    //uint32_t dram_manufacturer_jedec_id_code[PORT_SIZE][DIMM_SIZE];

    // See VPD parser #A keyword
    //uint8_t bad_dq_data[PORT_SIZE][DIMM_SIZE][SPD_ATTR_SIZE_80];

    uint32_t vpd_version[PORT_SIZE][DIMM_SIZE];
};

//------------------------------------------------------------------------------
// Structure
// @brief struct mss_eff_config_atts
// @brief holds the effective configuration attributes
//------------------------------------------------------------------------------
struct mss_eff_config_atts
{
    uint8_t eff_dimm_ranks_configed[PORT_SIZE][DIMM_SIZE];
    // Using SPD byte68,69:76, enabled in GA2 for full RDIMM support
    uint64_t eff_dimm_rcd_cntl_word_0_15[PORT_SIZE][DIMM_SIZE];
    uint8_t eff_dimm_size[PORT_SIZE][DIMM_SIZE];
    uint8_t eff_dimm_type;
    uint8_t eff_custom_dimm;
    uint8_t eff_dram_al; // Always use AL = CL - 1.
    uint8_t eff_dram_asr;
    uint8_t eff_dram_bl;
    uint8_t eff_dram_banks;

    // See mss_freq.C
    //uint8_t eff_dram_cl;

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
    uint8_t eff_ibm_type[PORT_SIZE][DIMM_SIZE];
    uint32_t eff_memcal_interval;
    uint8_t eff_mpr_loc;
    uint8_t eff_mpr_mode;

    // AST HERE: Needs SPD byte33[6:4], currently hard coded to 0, removed for GA1
    //uint8_t eff_num_dies_per_package[PORT_SIZE][DIMM_SIZE];

    uint8_t eff_num_drops_per_port;
    uint8_t eff_num_master_ranks_per_dimm[PORT_SIZE][DIMM_SIZE];

    // AST HERE: Needs source data, currently hard coded to 0, removed for GA1
    //uint8_t eff_num_packages_per_rank[PORT_SIZE][DIMM_SIZE];

    uint8_t eff_num_ranks_per_dimm[PORT_SIZE][DIMM_SIZE];
    uint8_t eff_schmoo_mode;

    uint8_t eff_schmoo_addr_mode;
    uint8_t eff_schmoo_wr_eye_min_margin;
    uint8_t eff_schmoo_rd_eye_min_margin;
    uint8_t eff_schmoo_dqs_clk_min_margin;
    uint8_t eff_schmoo_rd_gate_min_margin;
    uint8_t eff_schmoo_addr_cmd_min_margin;
    uint32_t eff_cen_rd_vref_schmoo[PORT_SIZE];
    uint32_t eff_dram_wr_vref_schmoo[PORT_SIZE];
    uint32_t eff_cen_rcv_imp_dq_dqs_schmoo[PORT_SIZE];
    uint32_t eff_cen_drv_imp_dq_dqs_schmoo[PORT_SIZE];
    uint8_t eff_cen_drv_imp_cntl_schmoo[PORT_SIZE];
    uint8_t eff_cen_drv_imp_clk_schmoo[PORT_SIZE];
    uint8_t eff_cen_drv_imp_spcke_schmoo[PORT_SIZE];
    uint8_t eff_cen_slew_rate_dq_dqs_schmoo[PORT_SIZE];
    uint8_t eff_cen_slew_rate_cntl_schmoo[PORT_SIZE];
    uint8_t eff_cen_slew_rate_addr_schmoo[PORT_SIZE];
    uint8_t eff_cen_slew_rate_clk_schmoo[PORT_SIZE];
    uint8_t eff_cen_slew_rate_spcke_schmoo[PORT_SIZE];

    uint8_t eff_schmoo_param_valid;
    uint8_t eff_schmoo_test_valid;
    uint8_t eff_stack_type[PORT_SIZE][DIMM_SIZE];
    uint32_t eff_zqcal_interval;
    uint8_t dimm_functional_vector;
    uint8_t mss_cal_step_enable; // Always run all cal steps
    uint32_t eff_vpd_version;

};

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
/*
fapi::ReturnCode mss_eff_config_get_spd_data(const fapi::Target &i_target_mba,
                                mss_eff_config_data *p_i_mss_eff_config_data,
                                mss_eff_config_spd_data *p_o_spd_data,
                                mss_eff_config_atts *p_i_atts);


fapi::ReturnCode mss_eff_config_read_spd_data(fapi::Target i_target_dimm,
                                mss_eff_config_spd_data *p_o_spd_data,
                                uint8_t i_port, uint8_t i_dimm);

fapi::ReturnCode mss_eff_config_verify_plug_rules(
                                const fapi::Target  &i_target_mba,
                                mss_eff_config_data *p_i_mss_eff_config_data,
                                mss_eff_config_atts *p_i_atts);

fapi::ReturnCode mss_eff_config_verify_spd_data(
                                const fapi::Target &i_target_mba,
                                mss_eff_config_atts *p_i_atts,
                                mss_eff_config_spd_data *p_i_data);

fapi::ReturnCode mss_eff_config_setup_eff_atts(const fapi::Target &i_target_mba,
                                mss_eff_config_data *p_i_mss_eff_config_data,
                                mss_eff_config_spd_data *p_i_data,
                                mss_eff_config_atts *p_o_atts);


fapi::ReturnCode mss_eff_config_write_eff_atts(const fapi::Target &i_target_mba,
                                mss_eff_config_atts *p_i_atts);
*/
//------------------------------------------------------------------------------
// extern encapsulation
//------------------------------------------------------------------------------
extern "C"
{

//------------------------------------------------------------------------------
// @brief calc_timing_in_clk(): This function calculates clock timing
//
// @param unit32_t i_mtb_in_ps:
// @param unit32_t i_ftb_in_fs:
// @param unit32_t i_unit:
// @param unit32_t i_offset:
// @param uint32_t i_mss_freq:
//
// @return unit32_t l_timing_in_clk
//------------------------------------------------------------------------------
uint32_t calc_timing_in_clk(uint32_t i_mtb_in_ps, uint32_t i_ftb_in_fs,
        uint32_t i_unit, uint8_t i_offset, uint32_t i_mss_freq)
{
    uint64_t l_timing;
    uint32_t l_timing_in_clk;
    uint32_t l_tCK_in_ps;
    // perform calculations
    l_tCK_in_ps = TWO_MHZ/i_mss_freq;
    if ( i_offset >= 128 ) {
       i_offset = 256 - i_offset;
       l_timing = (i_unit * i_mtb_in_ps) - (i_offset * i_ftb_in_fs);
    } else {
       l_timing = (i_unit * i_mtb_in_ps) + (i_offset * i_ftb_in_fs);
    }
    // ceiling()
    l_timing_in_clk = l_timing / l_tCK_in_ps;
    // check l_timing
    if ( (l_timing_in_clk * l_tCK_in_ps) < l_timing )
    {
        l_timing_in_clk += 1;
    }
    // DEBUG HERE:
    //FAPI_INF("calc_timing_in_clk: l_timing_in_clk = %d, l_tCK_in_ps = %d, i_mtb_in_ps = %d, i_ftb_in_fs = %d, i_unit = %d, i_offset = %d", l_timing_in_clk, l_tCK_in_ps, i_mtb_in_ps, i_ftb_in_fs, i_unit, i_offset);

    return l_timing_in_clk;
} // end calc_timing_in_clk()

//------------------------------------------------------------------------------
// @brief mss_eff_config_read_spd_data(): This function reads DIMM SPD data
//
// @param      fapi::Target i_target_dimm: target dimm
// @param      mss_eff_config_spd_data *p_o_spd_data: Pointer to
//              mss_eff configuration spd data structure
// @param      uint8_t i_port: current mba port
// @param      uint8_t i_dimm: current mba dimm
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config_read_spd_data(fapi::Target i_target_dimm,
                                        mss_eff_config_spd_data *p_o_spd_data,
                                        uint8_t i_port, uint8_t i_dimm)
{
    fapi::ReturnCode rc;
    // Grab DIMM/SPD data.
    do
    {
        rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &i_target_dimm,
                p_o_spd_data->dram_device_type[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_DEVICE_TYPE, &i_target_dimm,
                p_o_spd_data->sdram_device_type[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE, &i_target_dimm,
            p_o_spd_data->module_type[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM, &i_target_dimm,
            p_o_spd_data->custom[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_BANKS, &i_target_dimm,
            p_o_spd_data->sdram_banks[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_DENSITY, &i_target_dimm,
            p_o_spd_data->sdram_density[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_ROWS, &i_target_dimm,
            p_o_spd_data->sdram_rows[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_COLUMNS, &i_target_dimm,
            p_o_spd_data->sdram_columns[i_port][i_dimm]);
        if(rc) break;

        // See mss_volt.C
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE, &i_target_dimm,
            //p_o_spd_data->module_nominal_voltage[i_port][i_dimm]);
        //if(rc) break;

        rc = FAPI_ATTR_GET(ATTR_SPD_NUM_RANKS, &i_target_dimm,
            p_o_spd_data->num_ranks[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_WIDTH, &i_target_dimm,
            p_o_spd_data->dram_width[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_MEMORY_BUS_WIDTH, &i_target_dimm,
            p_o_spd_data->module_memory_bus_width[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVIDEND, &i_target_dimm,
            p_o_spd_data->ftb_dividend[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVISOR, &i_target_dimm,
            p_o_spd_data->ftb_divisor[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVIDEND, &i_target_dimm,
            p_o_spd_data->mtb_dividend[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVISOR, &i_target_dimm,
            p_o_spd_data->mtb_divisor[i_port][i_dimm]);
        if(rc) break;

        // See mss_freq.C
        //rc = FAPI_ATTR_GET(ATTR_SPD_TCKMIN, &i_target_dimm,
            //p_o_spd_data->tckmin[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED, &i_target_dimm,
            //p_o_spd_data->cas_latencies_supported[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_TAAMIN, &i_target_dimm,
            //p_o_spd_data->taamin[i_port][i_dimm]);
        //if(rc) break;

        rc = FAPI_ATTR_GET(ATTR_SPD_TWRMIN, &i_target_dimm,
            p_o_spd_data->twrmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TRCDMIN, &i_target_dimm,
            p_o_spd_data->trcdmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TRRDMIN, &i_target_dimm,
            p_o_spd_data->trrdmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TRPMIN, &i_target_dimm,
            p_o_spd_data->trpmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TRASMIN, &i_target_dimm,
            p_o_spd_data->trasmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TRCMIN, &i_target_dimm,
            p_o_spd_data->trcmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TRFCMIN, &i_target_dimm,
            p_o_spd_data->trfcmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TWTRMIN, &i_target_dimm,
            p_o_spd_data->twtrmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TRTPMIN, &i_target_dimm,
            p_o_spd_data->trtpmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_TFAWMIN, &i_target_dimm,
            p_o_spd_data->tfawmin[i_port][i_dimm]);
        if(rc) break;

        // Not needed for GA1 CDIMM, will need to enable check for ISDIMM.
        //rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_OPTIONAL_FEATURES, &i_target_dimm,
            //p_o_spd_data->sdram_optional_features[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS,
            //&i_target_dimm,
            //p_o_spd_data->sdram_thermal_and_refresh_options[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_THERMAL_SENSOR, &i_target_dimm,
            //p_o_spd_data->module_thermal_sensor[i_port][i_dimm]);
        //if(rc) break;

        rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TCKMIN, &i_target_dimm,
            p_o_spd_data->fine_offset_tckmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TAAMIN, &i_target_dimm,
            p_o_spd_data->fine_offset_taamin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TRCDMIN, &i_target_dimm,
            p_o_spd_data->fine_offset_trcdmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TRPMIN, &i_target_dimm,
            p_o_spd_data->fine_offset_trpmin[i_port][i_dimm]);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TRCMIN, &i_target_dimm,
            p_o_spd_data->fine_offset_trcmin[i_port][i_dimm]);
        if(rc) break;


        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_SPECIFIC_SECTION,                    // LRDIMM needed.
            //&i_target_dimm,
            //p_o_spd_data->module_specific_section[i_port][i_dimm]);
        //if(rc) break;


        rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_RCD_CNTL_WORD_0_15,                    // Needed for RDIMM.
            &i_target_dimm,
            p_o_spd_data->rdimm_rcd_cntl_word_0_15[i_port][i_dimm]);
        if(rc) break;

        // Moved from DIMM to MBA[port][dimm] attr per DanC. see dimm_spd_attributes.xml v1.40
        //rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_RCD_IBT,                               // Needed for RDIMM.
        //    &i_target_dimm,
        //    p_o_spd_data->rdimm_rcd_ibt[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_RCD_OUTPUT_TIMING,                     // Needed for RDIMM.
        //    &i_target_dimm,
        //    p_o_spd_data->rdimm_rcd_output_timing[i_port][i_dimm]);
        //if(rc) break;


        // See "svpdMFGtool --inventory"
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_MANUFACTURERS_
            //JEDEC_ID_CODE,
            //&i_target_dimm,
            //p_o_spd_data->
        //module_id_module_manufacturers_jedec_id_code[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION,
            //&i_target_dimm,
            //p_o_spd_data->module_id_module_manufacturing_location
            //[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE,
            //&i_target_dimm,
            //p_o_spd_data->module_id_module_manufacturing_date
            //[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_ID_MODULE_SERIAL_NUMBER,
            //&i_target_dimm,
            //p_o_spd_data->module_id_module_serial_number[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_CYCLICAL_REDUNDANCY_CODE,
            //&i_target_dimm,
            //p_o_spd_data->cyclical_redundancy_code[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_PART_NUMBER,
            //&i_target_dimm,
            //p_o_spd_data->module_part_number[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_REVISION_CODE,
            //&i_target_dimm,
            //p_o_spd_data->module_revision_code[i_port][i_dimm]);
        //if(rc) break;
        //rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE,
            //&i_target_dimm,
            //p_o_spd_data->dram_manufacturer_jedec_id_code[i_port][i_dimm]);
        //if(rc) break;

        // See VPD parser #A keyword
        //rc = FAPI_ATTR_GET(ATTR_SPD_BAD_DQ_DATA, &i_target_dimm,
            //p_o_spd_data->bad_dq_data[i_port][i_dimm]);
        //if(rc) break;

        rc = FAPI_ATTR_GET(ATTR_VPD_VERSION, &i_target_dimm,
                           p_o_spd_data->vpd_version[i_port][i_dimm]);
        if(rc) break;

    } while(0);

    return rc;
} // end of mss_eff_config_read_spd_data()

//------------------------------------------------------------------------------
// @brief mss_eff_config_get_spd_data(): This function sets gathers the
//              DIMM info then uses mss_eff_config_read_spd_data() as a
//              helper function to read the spd data
//
// @param const fapi::Target &i_target_mba: the fapi target
// @param       mss_eff_config_data *p_i_mss_eff_config_data: Pointer to
//              mss_eff_config_data variable structure
// @param const mss_eff_config_spd_data *p_o_spd_data: Pointer to mss_eff
//              configuration spd data structure
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config_get_spd_data(
                                const fapi::Target &i_target_mba,
                                mss_eff_config_data *p_i_mss_eff_config_data,
                                mss_eff_config_spd_data *p_o_spd_data,
                                mss_eff_config_atts *p_i_atts)
{
    fapi::ReturnCode rc;
    std::vector<fapi::Target> l_target_dimm_array;
    uint8_t l_cur_mba_port = 0;
    uint8_t l_cur_mba_dimm = 0;
    // Grab all DIMM/SPD data.
    do
    {
 //------------------------------------------------------------------------------
// initialize vpd_version
      for(l_cur_mba_port=0; l_cur_mba_port < PORT_SIZE ; l_cur_mba_port++)
        for(l_cur_mba_dimm=0; l_cur_mba_dimm < DIMM_SIZE ; l_cur_mba_dimm++)
          p_o_spd_data->vpd_version[l_cur_mba_port][l_cur_mba_dimm]=0xFFFFFFFF;
//------------------------------------------------------------------------------

       rc = fapiGetAssociatedDimms(i_target_mba, l_target_dimm_array);
        if(rc)
        {
            FAPI_ERR("Error retrieving assodiated dimms");
            break;
        }
//------------------------------------------------------------------------------
        // call mss_eff_config_read_spd_data()
        for (uint8_t l_dimm_index = 0; l_dimm_index <
                l_target_dimm_array.size(); l_dimm_index += 1)
        {
            rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &l_target_dimm_array[l_dimm_index],
                    l_cur_mba_port);
            if(rc)
            {
                FAPI_ERR("Error retrieving ATTR_MBA_PORT");
                break;
            }
//------------------------------------------------------------------------------
            rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &l_target_dimm_array[l_dimm_index
                    ], l_cur_mba_dimm);
            if(rc)
            {
                FAPI_ERR("Error retrieving ATTR_MBA_DIMM");
                break;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->cur_dimm_spd_valid_u8array
                [l_cur_mba_port][l_cur_mba_dimm] = MSS_EFF_VALID;
            rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL,
                    &l_target_dimm_array[l_dimm_index],
                    p_i_mss_eff_config_data->dimm_functional);
            if(rc)
            {
                FAPI_ERR("Error retrieving functional fapi attribute");
                break;
            }
//------------------------------------------------------------------------------
            (p_i_mss_eff_config_data->dimm_functional ==
             fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
                ? p_i_mss_eff_config_data->dimm_functional=1
                : p_i_mss_eff_config_data->dimm_functional=0;
            p_i_atts->dimm_functional_vector |=
                p_i_mss_eff_config_data->dimm_functional
                << ((4*(1-(l_cur_mba_port)))+(4-(l_cur_mba_dimm))-1);

            rc = mss_eff_config_read_spd_data(l_target_dimm_array[l_dimm_index],
                    p_o_spd_data, l_cur_mba_port, l_cur_mba_dimm);
            if(rc)
            {
                FAPI_ERR("Error reading spd data from caller");
                break;
            }
        }
    } while(0);

    return rc;
} // end of mss_eff_config_get_spd_data()

//------------------------------------------------------------------------------
// @brief mss_eff_config_verify_plug_rules(): This function verifies DIMM
//              plug rules based on which dimms are present
//
// @param       mss_eff_config_data *p_i_mss_eff_config_data: Pointer to
//              mss_eff_config_data variable structure
// @param const fapi::Target &i_target_mba: the fapi target
// @param       mss_eff_config_data *p_i_mss_eff_config_data: Pointer to
//              mss_eff_config_data variable structure
// @param       mss_eff_config_atts *p_i_atts: Pointer to mss_eff
//              configuration attributes structure
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config_verify_plug_rules(
                                const fapi::Target &i_target_mba,
                                mss_eff_config_data *p_i_mss_eff_config_data,
                                mss_eff_config_atts *p_i_atts)
{
    fapi::ReturnCode rc;
    const fapi::Target& TARGET_MBA = i_target_mba;
    uint8_t& CUR_DIMM_SPD_VALID_U8ARRAY_0_0 = 
             p_i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][0];
    uint8_t& CUR_DIMM_SPD_VALID_U8ARRAY_0_1 = 
             p_i_mss_eff_config_data->cur_dimm_spd_valid_u8array[0][1];
    uint8_t& CUR_DIMM_SPD_VALID_U8ARRAY_1_0 = 
             p_i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][0];
    uint8_t& CUR_DIMM_SPD_VALID_U8ARRAY_1_1 = 
             p_i_mss_eff_config_data->cur_dimm_spd_valid_u8array[1][1];

    // Identify/Verify DIMM plug rule
    if (
            (p_i_mss_eff_config_data->
             cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_EMPTY)
            &&
            (
                (p_i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID)
                ||
                (p_i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][0] == MSS_EFF_VALID)
                ||
                (p_i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][1] == MSS_EFF_VALID)
            )
       )
    {
        FAPI_ERR("Plug rule violation on %s!", i_target_mba.toEcmdString());
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_MISMATCH_EMPTY);
        return rc;
    }
    if ( (
            ((p_i_mss_eff_config_data->
              cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID)
             && (p_i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][0] == MSS_EFF_EMPTY))
            ||
            ((p_i_mss_eff_config_data->
              cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID)
             && (p_i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][1] == MSS_EFF_EMPTY))
       ) && (p_i_mss_eff_config_data->allow_single_port == fapi::ENUM_ATTR_MSS_ALLOW_SINGLE_PORT_FALSE) )
    {
        FAPI_ERR("Plug rule violation on %s!", i_target_mba.toEcmdString());
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_MISMATCH_SIDE);
        return rc;
    }
    if ( (
            (p_i_mss_eff_config_data->
              cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID)
             || (p_i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][0] == MSS_EFF_VALID)
             || (p_i_mss_eff_config_data->
                 cur_dimm_spd_valid_u8array[1][1] == MSS_EFF_VALID)
       ) && (p_i_mss_eff_config_data->allow_single_port == fapi::ENUM_ATTR_MSS_ALLOW_SINGLE_PORT_TRUE) )
    {
        FAPI_ERR("Plug rule violation on %s!", i_target_mba.toEcmdString());
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_MISMATCH_TOP);
        return rc;
    }
    if ((p_i_mss_eff_config_data->
                cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID)
            && (p_i_mss_eff_config_data->
                cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_VALID))
    {
        p_i_atts->eff_num_drops_per_port
            = fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL;
    }
    else if ((p_i_mss_eff_config_data->
                cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID)
            && (p_i_mss_eff_config_data->
                cur_dimm_spd_valid_u8array[0][1] == MSS_EFF_EMPTY))
    {
        p_i_atts->eff_num_drops_per_port
            = fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE;
    }
    else
    {
        p_i_atts->eff_num_drops_per_port
            = fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_EMPTY;
    }
    // end Indetify/Verify DIMM plug rule

    return rc;
} // end of mss_eff_config_verify_plug_rules()

//------------------------------------------------------------------------------
// @brief mss_eff_config_verify_spd_data(): This function verifies DIMM
//              SPD data
//
// @param const fapi::Target &i_target_mba: the fapi target
// @param       mss_eff_config_atts *p_i_atts: Pointer to mss_eff
//              configuration attributes structure
// @param       mss_eff_config_spd_data *p_i_data: Pointer to mss_eff
//              configuration spd data structure
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config_verify_spd_data(
                                    const fapi::Target &i_target_mba,
                                    mss_eff_config_atts *p_i_atts,
                                    mss_eff_config_spd_data *p_i_data)
{
    fapi::ReturnCode rc;
    const fapi::Target& TARGET_MBA = i_target_mba;

    // Start Identify/Verify/Assigning values to attributes
    // Identify/Verify DIMM compatability
//------------------------------------------------------------------------------
    if (
            (p_i_data->dram_device_type[0][0]
             != p_i_data->dram_device_type[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                        (p_i_data->dram_device_type[0][1]
                         != p_i_data->dram_device_type[1][1])
                        ||
                        (p_i_data->dram_device_type[0][0]
                         != p_i_data->dram_device_type[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DRAM generation on %s!",
                i_target_mba.toEcmdString());
        uint8_t& DRAM_DEVICE_TYPE_0_0 = p_i_data->dram_device_type[0][0];
        uint8_t& DRAM_DEVICE_TYPE_0_1 = p_i_data->dram_device_type[0][1];
        uint8_t& DRAM_DEVICE_TYPE_1_0 = p_i_data->dram_device_type[1][0];
        uint8_t& DRAM_DEVICE_TYPE_1_1 = p_i_data->dram_device_type[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_GEN);
        return rc;
    }
//------------------------------------------------------------------------------
    if (
            (p_i_data->module_type[0][0]
             != p_i_data->module_type[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (p_i_data->module_type[0][1]
                     != p_i_data->module_type[1][1])
                    ||
                    (p_i_data->module_type[0][0]
                     != p_i_data->module_type[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DIMM type on %s!", i_target_mba.toEcmdString());
        uint8_t& MODULE_TYPE_0_0 = p_i_data->module_type[0][0];
        uint8_t& MODULE_TYPE_0_1 = p_i_data->module_type[0][1];
        uint8_t& MODULE_TYPE_1_0 = p_i_data->module_type[1][0];
        uint8_t& MODULE_TYPE_1_1 = p_i_data->module_type[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_TYPE);
        return rc;
    }
//------------------------------------------------------------------------------
    if (
            (p_i_data->num_ranks[0][0]
             != p_i_data->num_ranks[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (p_i_data->num_ranks[0][1]
                     != p_i_data->num_ranks[1][1])
                    ||
                    (p_i_data->num_ranks[0][0]
                     != p_i_data->num_ranks[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DIMM ranks on %s!", i_target_mba.toEcmdString());
        uint8_t& NUM_RANKS_0_0 = p_i_data->num_ranks[0][0];
        uint8_t& NUM_RANKS_0_1 = p_i_data->num_ranks[0][1];
        uint8_t& NUM_RANKS_1_0 = p_i_data->num_ranks[1][0];
        uint8_t& NUM_RANKS_1_1 = p_i_data->num_ranks[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_RANKS);
        return rc;
    }
//------------------------------------------------------------------------------
    if (
            (p_i_data->sdram_banks[0][0]
             != p_i_data->sdram_banks[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (p_i_data->sdram_banks[0][1]
                     != p_i_data->sdram_banks[1][1])
                    ||
                    (p_i_data->sdram_banks[0][0]
                     != p_i_data->sdram_banks[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DIMM banks on %s!", i_target_mba.toEcmdString());
                uint8_t& SDRAM_BANKS_0_0 = p_i_data->sdram_banks[0][0];
                uint8_t& SDRAM_BANKS_0_1 = p_i_data->sdram_banks[0][1];
                uint8_t& SDRAM_BANKS_1_0 = p_i_data->sdram_banks[1][0];
                uint8_t& SDRAM_BANKS_1_1 = p_i_data->sdram_banks[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_BANKS);
        return rc;
    }
//------------------------------------------------------------------------------
    if (
            (p_i_data->sdram_rows[0][0]
             != p_i_data->sdram_rows[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (p_i_data->sdram_rows[0][1]
                     != p_i_data->sdram_rows[1][1])
                    ||
                    (p_i_data->sdram_rows[0][0]
                     != p_i_data->sdram_rows[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DIMM rows on %s!", i_target_mba.toEcmdString());
                uint8_t& SDRAM_ROWS_0_0 = p_i_data->sdram_rows[0][0];
                uint8_t& SDRAM_ROWS_0_1 = p_i_data->sdram_rows[0][1];
                uint8_t& SDRAM_ROWS_1_0 = p_i_data->sdram_rows[1][0];
                uint8_t& SDRAM_ROWS_1_1 = p_i_data->sdram_rows[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_ROWS);
        return rc;
    }
//------------------------------------------------------------------------------
    if (
            (p_i_data->sdram_columns[0][0]
             != p_i_data->sdram_columns[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (p_i_data->sdram_columns[0][1]
                     != p_i_data->sdram_columns[1][1])
                    ||
                    (p_i_data->sdram_columns[0][0]
                     != p_i_data->sdram_columns[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DIMM cols on %s!", i_target_mba.toEcmdString());
                uint8_t& SDRAM_COLS_0_0 = p_i_data->sdram_columns[0][0];
                uint8_t& SDRAM_COLS_0_1 = p_i_data->sdram_columns[0][1];
                uint8_t& SDRAM_COLS_1_0 = p_i_data->sdram_columns[1][0];
                uint8_t& SDRAM_COLS_1_1 = p_i_data->sdram_columns[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DIMM_COLUMNS);
        return rc;
    }
//------------------------------------------------------------------------------
    if (
            (p_i_data->module_memory_bus_width[0][0]
             != p_i_data->module_memory_bus_width[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (p_i_data->module_memory_bus_width[0][1]
                     != p_i_data->module_memory_bus_width[1][1])
                    ||
                    (p_i_data->module_memory_bus_width[0][0]
                     != p_i_data->module_memory_bus_width[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DRAM primary bus width on %s!",
                i_target_mba.toEcmdString());
                uint8_t& BUS_WIDTH_0_0 = p_i_data->module_memory_bus_width[0][0];
                uint8_t& BUS_WIDTH_0_1 = p_i_data->module_memory_bus_width[0][1];
                uint8_t& BUS_WIDTH_1_0 = p_i_data->module_memory_bus_width[1][0];
                uint8_t& BUS_WIDTH_1_1 = p_i_data->module_memory_bus_width[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_BUS_WIDTH);
        return rc;
    }
//------------------------------------------------------------------------------
    // ATTR_SPD_MODULE_MEMORY_BUS_WIDTH, SPD byte8[4:3], only 64bit with ECC extension is allowed
    if ( p_i_data->module_memory_bus_width[0][0] != 
         fapi::ENUM_ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_WE64 )
    {
        FAPI_ERR("Unsupported DRAM bus width on %s!",
            i_target_mba.toEcmdString());
            uint8_t& MODULE_MEMORY_BUS_WIDTH = p_i_data->module_memory_bus_width[0][0];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_UNSUPPORTED_MODULE_MEMORY_BUS_WIDTH);
        return rc;
    }
//------------------------------------------------------------------------------
    if (
            (p_i_data->dram_width[0][0]
             != p_i_data->dram_width[1][0])
            ||
            (
                (p_i_atts->eff_num_drops_per_port
                 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL)
                &&
                (
                    (p_i_data->dram_width[0][1]
                     != p_i_data->dram_width[1][1])
                    ||
                    (p_i_data->dram_width[0][0]
                     != p_i_data->dram_width[0][1])
                )
            )
        )
    {
        FAPI_ERR("Incompatable DRAM width on %s!", i_target_mba.toEcmdString());
                uint8_t& DRAM_WIDTH_0_0 = p_i_data->dram_width[0][0];
                uint8_t& DRAM_WIDTH_0_1 = p_i_data->dram_width[0][1];
                uint8_t& DRAM_WIDTH_1_0 = p_i_data->dram_width[1][0];
                uint8_t& DRAM_WIDTH_1_1 = p_i_data->dram_width[1][1];
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INCOMPATABLE_DRAM_WIDTH);
        return rc;
    }
//------------------------------------------------------------------------------
    return rc;
} // end of mss_eff_config_verify_spd_data()

//------------------------------------------------------------------------------
// @brief mss_eff_config_setup_eff_atts(): This function sets up the
//             effective configuration attributes and does some extra
//             verification of SPD data
//
// @param const fapi::Target &i_target_mba: the fapi target
// @param       mss_eff_config_data *p_i_mss_eff_config_data: Pointer to
//              mss_eff_config_data variable structure
// @param       mss_eff_config_spd_data *p_i_data: Pointer to mss_eff
//              configuration spd data structure
// @param       mss_eff_config_atts *p_o_atts: Pointer to mss_eff
//              configuration attributes structure
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config_setup_eff_atts(
                                const fapi::Target &i_target_mba,
                                mss_eff_config_data *p_i_mss_eff_config_data,
                                mss_eff_config_spd_data *p_i_data,
                                mss_eff_config_atts *p_o_atts)
{
    fapi::ReturnCode rc;
    const fapi::Target& TARGET_MBA = i_target_mba;

    // set select atts members to non-zero
    p_o_atts->eff_dram_al = fapi::ENUM_ATTR_EFF_DRAM_AL_CL_MINUS_1; // Always use AL = CL - 1.

    // Transfer powerdown request from system attr to DRAM attr
    uint8_t mss_power_control_requested;
    rc = FAPI_ATTR_GET(ATTR_MRW_POWER_CONTROL_REQUESTED, NULL, mss_power_control_requested); 
    if(rc) return rc;
    if ( mss_power_control_requested == fapi::ENUM_ATTR_MRW_POWER_CONTROL_REQUESTED_FASTEXIT) {
       p_o_atts->eff_dram_dll_ppd = fapi::ENUM_ATTR_EFF_DRAM_DLL_PPD_FASTEXIT;
    } else {
       p_o_atts->eff_dram_dll_ppd = fapi::ENUM_ATTR_EFF_DRAM_DLL_PPD_SLOWEXIT; // if "OFF" default to SLOWEXIT, FASTEXIT settings in mba_def.initfile are causing fails.  Workaround to use SLOWEXIT.
    }

    p_o_atts->eff_dram_dll_reset = fapi::ENUM_ATTR_EFF_DRAM_DLL_RESET_YES; // Always reset DLL at start of IPL.
    p_o_atts->eff_dram_srt = fapi::ENUM_ATTR_EFF_DRAM_SRT_EXTEND; // Always use extended operating temp range.
    p_o_atts->mss_cal_step_enable = 0xFF; // Always run all cal steps
    // array init
    for(int i = 0; i < PORT_SIZE; i++)
    {
        for(int j = 0; j < DIMM_SIZE; j++)
        {
            // i <-> PORT_SIZE, j <-> DIMM_SIZE
            p_o_atts->eff_stack_type[i][j] = 0;
            p_o_atts->eff_ibm_type[i][j] = 0;
        }
    }

    // Assigning values to attributes
//------------------------------------------------------------------------------
    p_o_atts->eff_schmoo_wr_eye_min_margin = 70;
    p_o_atts->eff_schmoo_rd_eye_min_margin = 70;
    p_o_atts->eff_schmoo_dqs_clk_min_margin = 140;
    p_o_atts->eff_schmoo_rd_gate_min_margin = 100;
    p_o_atts->eff_schmoo_addr_cmd_min_margin = 140;
//------------------------------------------------------------------------------
    switch(p_i_data->dram_device_type[0][0])
    {
        case fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3:
            p_o_atts->eff_dram_gen = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3;
            break;
        case fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4:
            p_o_atts->eff_dram_gen = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4;
            break;
        default:
                        uint8_t& DRAM_DEVICE_TYPE=p_i_data->dram_device_type[0][0];
            FAPI_ERR("Unknown DRAM type on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_DRAM_DEVICE_ERROR);
            return rc;
    }
//------------------------------------------------------------------------------
    switch(p_i_data->module_type[0][0])
    {
        // Removed CDIMM as a valid EFF_DIMM_TYPE.
        //case fapi::ENUM_ATTR_SPD_MODULE_TYPE_CDIMM:
        //    p_o_atts->eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM;
        //    FAPI_INF("WARNING: ATTR_SPD_MODULE_TYPE_CDIMM is obsolete.  Check your VPD for correct definition on %s!", i_target_mba.toEcmdString());
        //    break;
        case fapi::ENUM_ATTR_SPD_MODULE_TYPE_RDIMM:
            p_o_atts->eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM;
            break;
        case fapi::ENUM_ATTR_SPD_MODULE_TYPE_UDIMM:
            // Removed CDIMM as a valid EFF_DIMM_TYPE.
            //if(p_i_data->custom[0][0]) {
            //  p_o_atts->eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM;
            //}
            //else {
              p_o_atts->eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM;
            //}
            break;
        case fapi::ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM:
            p_o_atts->eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM;
            break;
        default:
            FAPI_ERR("Unknown DIMM type on %s!", i_target_mba.toEcmdString());
            uint8_t& MOD_TYPE = p_i_data->module_type[0][0];
            FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_MOD_TYPE_ERROR);
            return rc;
    }
//------------------------------------------------------------------------------
    // Moved from DIMM to MBA[port][dimm] attr per DanC. see dimm_spd_attributes.xml v1.40
    uint32_t l_rdimm_rcd_ibt[PORT_SIZE][DIMM_SIZE];
    uint8_t l_rdimm_rcd_output_timing[PORT_SIZE][DIMM_SIZE];
    if ( p_o_atts->eff_dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM ) {
       rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_RCD_IBT, &i_target_mba, l_rdimm_rcd_ibt);
       if (rc) return rc;
       rc = FAPI_ATTR_GET(ATTR_VPD_DIMM_RCD_OUTPUT_TIMING, &i_target_mba, l_rdimm_rcd_output_timing);
       if (rc) return rc;
    }
//------------------------------------------------------------------------------
    if(p_i_data->custom[0][0] == fapi::ENUM_ATTR_SPD_CUSTOM_YES) {
      p_o_atts->eff_custom_dimm = fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES;
    }
    else {
      p_o_atts->eff_custom_dimm = fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_NO;
    }
//------------------------------------------------------------------------------
    switch(p_i_data->sdram_banks[0][0])
    {
        case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B8:
            p_o_atts->eff_dram_banks = 8;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B16:
            p_o_atts->eff_dram_banks = 16;
            break;
        case  fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B32:
            p_o_atts->eff_dram_banks = 32;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_BANKS_B64:
            p_o_atts->eff_dram_banks = 64;
            break;
        default:
            FAPI_ERR("Unknown DRAM banks on %s!", i_target_mba.toEcmdString());
                        uint8_t& SDRAM_BANKS= p_i_data->sdram_banks[0][0];
            FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_SDRAM_BANK_ERROR);
            return rc;
    }
//------------------------------------------------------------------------------
    switch (p_i_data->sdram_rows[0][0])
    {
        case fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R12:
            p_o_atts->eff_dram_rows = 12;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R13:
            p_o_atts->eff_dram_rows = 13;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R14:
            p_o_atts->eff_dram_rows = 14;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R15:
            p_o_atts->eff_dram_rows = 15;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_ROWS_R16:
            p_o_atts->eff_dram_rows = 16;
            break;
        default:
            FAPI_ERR("Unknown DRAM rows on %s!", i_target_mba.toEcmdString());
                        uint8_t& SDRAM_ROWS= p_i_data->sdram_rows[0][0];
            FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_SDRAM_ROWS_ERROR);
            return rc;
    }
//------------------------------------------------------------------------------
    switch (p_i_data->sdram_columns[0][0])
    {
        case fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C9:
            p_o_atts->eff_dram_cols = 9;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C10:
            p_o_atts->eff_dram_cols = 10;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C11:
            p_o_atts->eff_dram_cols = 11;
            break;
        case fapi::ENUM_ATTR_SPD_SDRAM_COLUMNS_C12:
            p_o_atts->eff_dram_cols = 12;
            break;
        default:
            FAPI_ERR("Unknown DRAM cols on %s!", i_target_mba.toEcmdString());
                        uint8_t& SDRAM_COLS= p_i_data->sdram_columns[0][0];
            FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_SDRAM_COLS_ERROR);
            return rc;
    }
//------------------------------------------------------------------------------
         uint8_t& DRAM_WIDTH= p_i_data->dram_width[0][0];
    if (p_i_data->dram_width[0][0]
            == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W4)
    {
        p_o_atts->eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4;
        p_o_atts->eff_dram_tdqs = fapi::ENUM_ATTR_EFF_DRAM_TDQS_DISABLE;
    }
    else if (p_i_data->dram_width[0][0]
            == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W8)
    {
        p_o_atts->eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X8;
        // NOTE: TDQS enable MR1(A11) is only avaliable for X8 in DDR3
        // TDQS disabled for X8 DDR3 CDIMM, enable for ISDIMM
        if ( p_o_atts->eff_custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_NO ) {
           p_o_atts->eff_dram_tdqs = fapi::ENUM_ATTR_EFF_DRAM_TDQS_ENABLE;
        } else {
           p_o_atts->eff_dram_tdqs = fapi::ENUM_ATTR_EFF_DRAM_TDQS_DISABLE;
        }
    }
    else if (p_i_data->dram_width[0][0]
            == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W16)
    {
        p_o_atts->eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X16;
        FAPI_ERR("Unsupported DRAM width x16 on %s!",
                i_target_mba.toEcmdString());
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_DRAM_WIDTH_16_ERROR);
        return rc;
    }
    else if (p_i_data->dram_width[0][0]
            == fapi::ENUM_ATTR_SPD_DRAM_WIDTH_W32)
    {
        p_o_atts->eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X32;
        FAPI_ERR("Unsupported DRAM width x32 on %s!",
                i_target_mba.toEcmdString());
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_DRAM_WIDTH_32_ERROR);
        return rc;

    }
    else
    {
         FAPI_ERR("Unknown DRAM width on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_DRAM_WIDTH_ERROR);
         return rc;
    }
//------------------------------------------------------------------------------
    p_o_atts->eff_dram_density = 16;

    uint8_t allow_port_size = 1;
    if (p_i_mss_eff_config_data->allow_single_port == fapi::ENUM_ATTR_MSS_ALLOW_SINGLE_PORT_FALSE) {
       allow_port_size = PORT_SIZE;
    }
    for (int l_cur_mba_port = 0; l_cur_mba_port < allow_port_size; l_cur_mba_port += 1)
    {
        for (int l_cur_mba_dimm = 0; l_cur_mba_dimm <
                p_o_atts->eff_num_drops_per_port; l_cur_mba_dimm += 1)
        {
            if (p_i_data->sdram_density[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D16GB)
            {
               p_i_mss_eff_config_data->cur_dram_density = 16;
            }
            else if (p_i_data->sdram_density[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D8GB)
            {
               p_i_mss_eff_config_data->cur_dram_density = 8;
            }
            else if (p_i_data->sdram_density[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D4GB)
            {
               p_i_mss_eff_config_data->cur_dram_density = 4;
            }
            else if (p_i_data->sdram_density[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D2GB)
            {
               p_i_mss_eff_config_data->cur_dram_density = 2;
            }
            else if (p_i_data->sdram_density[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_SDRAM_DENSITY_D1GB)
            {
               p_i_mss_eff_config_data->cur_dram_density = 1;
            }
            else
            {
                           uint8_t& SDRAM_DENSITY = p_i_data->sdram_density[l_cur_mba_port][l_cur_mba_dimm];
               p_i_mss_eff_config_data->cur_dram_density = 1;
               if (p_i_mss_eff_config_data->allow_single_port == fapi::ENUM_ATTR_MSS_ALLOW_SINGLE_PORT_FALSE) {
                  FAPI_ERR("Unsupported DRAM density on %s!",
                          i_target_mba.toEcmdString());
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_DRAM_DENSITY_ERR);
                  return rc;
               }
            }
//------------------------------------------------------------------------------
            if (p_o_atts->eff_dram_density >
                    p_i_mss_eff_config_data->cur_dram_density)
            {
               p_o_atts->eff_dram_density =
                   p_i_mss_eff_config_data->cur_dram_density;
            }
//------------------------------------------------------------------------------
            // Identify/Verify DIMM voltage compatability
            // See mss_volt.C
//------------------------------------------------------------------------------
            // Identify/Assign minimum timing
            p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                [l_cur_mba_dimm] =
                (p_i_data->mtb_dividend[l_cur_mba_port]
                 [l_cur_mba_dimm] * 1000)
                /
                p_i_data->mtb_divisor[l_cur_mba_port]
                [l_cur_mba_dimm];
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                [l_cur_mba_dimm] =
                (p_i_data->ftb_dividend[l_cur_mba_port]
                 [l_cur_mba_dimm] * 1000)
                /
                p_i_data->ftb_divisor[l_cur_mba_port]
                [l_cur_mba_dimm];
//------------------------------------------------------------------------------
            // Calculate CL
            // See mss_freq.C
            // call calc_timing_in_clk()
            p_i_mss_eff_config_data->dram_wr = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->twrmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    0,
                    p_i_mss_eff_config_data->mss_freq

                                            );
            if (p_i_mss_eff_config_data->dram_wr > p_o_atts->eff_dram_wr)
            {
                p_o_atts->eff_dram_wr = p_i_mss_eff_config_data->dram_wr;
            }
//------------------------------------------------------------------------------
            // call calc_timing_in_clk()
            p_i_mss_eff_config_data->dram_trcd = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->trcdmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->fine_offset_trcdmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_trcd >
                    p_o_atts->eff_dram_trcd)
            {
                p_o_atts->eff_dram_trcd =
                    p_i_mss_eff_config_data->dram_trcd;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_trrd = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->trrdmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    0,
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_trrd >
                    p_o_atts->eff_dram_trrd)
            {
                p_o_atts->eff_dram_trrd =
                    p_i_mss_eff_config_data->dram_trrd;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_trp = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->trpmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->fine_offset_trpmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_trp > p_o_atts->eff_dram_trp)
            {
                p_o_atts->eff_dram_trp = p_i_mss_eff_config_data->dram_trp;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_twtr = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->twtrmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    0,
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_twtr >
                    p_o_atts->eff_dram_twtr)
            {
                p_o_atts->eff_dram_twtr =
                    p_i_mss_eff_config_data->dram_twtr;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_trtp = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->trtpmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    0,
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_trtp >
                    p_o_atts->eff_dram_trtp)
            {
                p_o_atts->eff_dram_trtp =
                    p_i_mss_eff_config_data->dram_trtp;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_tras = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->trasmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    0,
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_tras >
                    p_o_atts->eff_dram_tras_u32)
            {
                p_o_atts->eff_dram_tras_u32 =
                    p_i_mss_eff_config_data->dram_tras;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_trc = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->trcmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->fine_offset_trcmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_trc >
                    p_o_atts->eff_dram_trc_u32)
            {
                p_o_atts->eff_dram_trc_u32 =
                    p_i_mss_eff_config_data->dram_trc;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_trfc = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->trfcmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    0,
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_trfc >
                    p_o_atts->eff_dram_trfc)
            {
                p_o_atts->eff_dram_trfc =
                    p_i_mss_eff_config_data->dram_trfc;
            }
//------------------------------------------------------------------------------
            p_i_mss_eff_config_data->dram_tfaw = calc_timing_in_clk
                (
                    p_i_mss_eff_config_data->mtb_in_ps_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_mss_eff_config_data->ftb_in_fs_u32array[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    p_i_data->tfawmin[l_cur_mba_port]
                    [l_cur_mba_dimm],
                    0,
                    p_i_mss_eff_config_data->mss_freq
                );
            if (p_i_mss_eff_config_data->dram_tfaw >
                    p_o_atts->eff_dram_tfaw_u32)
            {
                p_o_atts->eff_dram_tfaw_u32 =
                    p_i_mss_eff_config_data->dram_tfaw;
            }
//------------------------------------------------------------------------------
        } // inner for loop
    } // outter for loop

    // Calculate CWL
    if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 2500)
    {
        p_o_atts->eff_dram_cwl = 5;
    }
    else if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 1875)
    {
        p_o_atts->eff_dram_cwl = 6;
    }
    else if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 1500)
    {
        p_o_atts->eff_dram_cwl = 7;
    }
    else if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 1250)
    {
        p_o_atts->eff_dram_cwl = 8;
    }
    else if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 1070)
    {
        p_o_atts->eff_dram_cwl = 9;
    }
    else if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 935)
    {
        p_o_atts->eff_dram_cwl = 10;
    }
    else if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 833)
    {
        p_o_atts->eff_dram_cwl = 11;
    }
    else if ((TWO_MHZ/p_i_mss_eff_config_data->mss_freq) >= 750)
    {
        p_o_atts->eff_dram_cwl = 12;
    }
    else
    {
                const uint16_t& CWL_VAL = (TWO_MHZ/p_i_mss_eff_config_data->mss_freq);
        FAPI_ERR("Error calculating CWL");
        FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_CWL_CALC_ERR);
        return rc;
    }
//------------------------------------------------------------------------------
    // Calculate ZQCAL Interval based on the following equation from Ken:
    //            0.5
    //  ------------------------------ = 13.333ms 
    //  (1.5 * 10) + (0.15 * 150)

    //p_o_atts->eff_zqcal_interval = 0;
    p_o_atts->eff_zqcal_interval = ( 13333 *
            p_i_mss_eff_config_data->mss_freq) / 2;
//------------------------------------------------------------------------------
    // Calculate MEMCAL Interval based on 1sec interval across all bits per DP18

    //p_o_atts->eff_memcal_interval = 0;
    p_o_atts->eff_memcal_interval = (62500 *
            p_i_mss_eff_config_data->mss_freq) / 2;
//------------------------------------------------------------------------------
    // Calculate tRFI
    p_o_atts->eff_dram_trfi = (3900 *
            p_i_mss_eff_config_data->mss_freq) / 2000;
    // Added 10% margin to TRFI per defect HW248225
    p_o_atts->eff_dram_trfi = (p_o_atts->eff_dram_trfi * 9) / 10;

    p_o_atts->eff_vpd_version = 0xFFFFFF; // set VPD version to a large number, searching for smallest
    // the VPD version is 2 ASCI characters, so this is always later than that

    // Assigning dependent values to attributes
    for (int l_cur_mba_port = 0; l_cur_mba_port <
            PORT_SIZE; l_cur_mba_port += 1)
    {
        for (int l_cur_mba_dimm = 0; l_cur_mba_dimm <
                DIMM_SIZE; l_cur_mba_dimm += 1)
        {
          if (p_i_mss_eff_config_data->
              cur_dimm_spd_valid_u8array[l_cur_mba_port][l_cur_mba_dimm] == MSS_EFF_VALID)
          {
             if (p_i_data->num_ranks[l_cur_mba_port]
                    [l_cur_mba_dimm] == 0x04)                 // for 8R LRDIMM  since no ENUM defined yet for SPD of 8R
//                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_NUM_RANKS_R8)
            {
                p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] = 8;
                p_o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0x80;                            // DD0/1: 1 master rank
            }
            else if (p_i_data->num_ranks[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_NUM_RANKS_R4)
            {
                p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] = 4;
                p_o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0xF0;
            }
            else if (p_i_data->num_ranks[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_NUM_RANKS_R2)
            {
                p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] = 2;
                p_o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0xC0;
            }
            else if (p_i_data->num_ranks[l_cur_mba_port]
                    [l_cur_mba_dimm] == fapi::ENUM_ATTR_SPD_NUM_RANKS_R1)
            {
                p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] = 1;
                p_o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0x80;
            } else
            {
                p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0;
                p_o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0x00;
            }

            if ( p_i_data->sdram_device_type[l_cur_mba_port][l_cur_mba_dimm] == 
                 fapi::ENUM_ATTR_SPD_SDRAM_DEVICE_TYPE_NON_STANDARD) {
               p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_DDP_QDP;
            } else {
               p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_NONE;
            }

                        uint8_t& UNSUPPORTED_VAL = p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm];
            // AST HERE: Needed SPD byte33[7,1:0], for expanded IBM_TYPE
            if ( p_o_atts->eff_dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM ) {
               if (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 1) {
                  p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1A;
               } else if (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2) {
                  p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1B;
               } else if (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 4) {
                  p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1D;
               } else {
                  p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_UNDEFINED;
                  FAPI_ERR("Currently unsupported IBM_TYPE on %s!", i_target_mba.toEcmdString());
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_RDIMM_UNSUPPORTED_TYPE); return rc;
               }
            } else if (( p_o_atts->eff_dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM ) && ( p_o_atts->eff_custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES )) {
               if (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 1) {
                  p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1A;
               } else if (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 2) {
                  p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1B;
               } else {
                  p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_UNDEFINED;
                  FAPI_ERR("Currently unsupported IBM_TYPE on %s!", i_target_mba.toEcmdString());
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_UDIMM_UNSUPPORTED_TYPE); return rc;
               }
            } else if ( p_o_atts->eff_dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM ) {
               FAPI_INF("Will set LR atts after orig eff_config functions");

            } else {
               p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_UNDEFINED;
               FAPI_ERR("Currently unsupported DIMM_TYPE on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_DIMM_UNSUPPORTED_TYPE); return rc;
            }
          } else {
             p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                 [l_cur_mba_dimm] = 0;
             p_o_atts->eff_dimm_ranks_configed[l_cur_mba_port]
                 [l_cur_mba_dimm] = 0x00;
            p_o_atts->eff_stack_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_STACK_TYPE_NONE;
            p_o_atts->eff_ibm_type[l_cur_mba_port][l_cur_mba_dimm] = fapi::ENUM_ATTR_EFF_IBM_TYPE_UNDEFINED;
          }
//------------------------------------------------------------------------------
          
//------------------------------------------------------------------------------
            if (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] != 0)
            {
                // structured equations as such due to long names
                // example: answer = ((num1)*(num2)*(const)) / ((const) * (num3));
                // becomes:
                //          answer =
                //              (
                //                  (num1)
                //                  *
                //                  (num2)
                //                  *
                //                  (const)
                //              )
                //              /
                //              (
                //                  (const)
                //                  *
                //                  (num3)
                //              );
                //
                // dimm_size = dram_density / 8 * primary_bus_width
                //             / dram_width * num_ranks_per_dimm
                p_o_atts->eff_dimm_size[l_cur_mba_port][l_cur_mba_dimm] =
                    (
                        (p_o_atts->eff_dram_density)
                        *
                        (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                         [l_cur_mba_dimm])
                        *
                        64
                    )
                    /
                    (
                        8
                        *
                        (p_o_atts->eff_dram_width)
                    );
            }
            else
            {
                p_o_atts->eff_dimm_size[l_cur_mba_port]
                    [l_cur_mba_dimm] = 0;
            }


            if ( (p_o_atts->eff_dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) &&
                    (p_i_data->dram_device_type[l_cur_mba_port][l_cur_mba_dimm] ==
                                              fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3) &&
                       (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] == 8) )
            {
                p_o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port]
                        [l_cur_mba_dimm] = 1;
            } 
            else 
            {
                // AST HERE: Needs SPD byte33[7,1:0],
                //  currently hard coded to no stacking
                p_o_atts->eff_num_master_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm] =
                    p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port]
                    [l_cur_mba_dimm];
            }

            // Populate RCD_CNTL_WORD for RDIMM, add hardcode to RC0-DA4=0b0 RC9-DBA1-DBA0-DA4-DA3=0b00X0, merge in ATTR_VPD_DIMM_RCD_IBT ATTR_VPD_DIMM_RCD_OUTPUT_TIMING, and adjust in RC10 and RC11 for freq/voltage
            if (( p_o_atts->eff_dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM ) && (p_o_atts->eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm] != 0)) {

               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_i_data->rdimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm];

               uint64_t l_rcd_hardcode_mask      = 0xDFFFFFFFF2FFFFFFLL;
               uint64_t l_mss_freq_mask          = 0xFFFFFFFFFF8FFFFFLL;
               uint64_t l_mss_volt_mask          = 0xFFFFFFFFFFFCFFFFLL;
               uint64_t l_rcd_ibt_mask           = 0xFFBFFFFF8FFFFFFFLL;
               uint64_t l_rcd_output_timing_mask = 0xFFDFFFFFFFFFFFFFLL;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] & l_rcd_hardcode_mask;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] & l_mss_freq_mask;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] & l_mss_volt_mask;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] & l_rcd_ibt_mask;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] & l_rcd_output_timing_mask;

               if ( p_i_mss_eff_config_data->mss_freq <= 933 ) {         // 800Mbps
                  l_mss_freq_mask = 0x0000000000000000LL;
               } else if ( p_i_mss_eff_config_data->mss_freq <= 1200 ) { // 1066Mbps
                  l_mss_freq_mask = 0x0000000000100000LL;
               } else if ( p_i_mss_eff_config_data->mss_freq <= 1466 ) { // 1333Mbps
                  l_mss_freq_mask = 0x0000000000200000LL;
               } else if ( p_i_mss_eff_config_data->mss_freq <= 1733 ) { // 1600Mbps
                  l_mss_freq_mask = 0x0000000000300000LL;
               } else {                           // 1866Mbps
                  FAPI_ERR("Invalid RDIMM ATTR_MSS_FREQ = %d on %s!", p_i_mss_eff_config_data->mss_freq, i_target_mba.toEcmdString());
                  uint32_t& INVALID_RDIMM_FREQ = p_i_mss_eff_config_data->mss_freq;
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INVALID_RDIMM_FREQ); return rc;
               }

               if ( p_i_mss_eff_config_data->mss_volt >= 1420 ) {        // 1.5V
                  l_mss_volt_mask = 0x0000000000000000LL;
               } else if ( p_i_mss_eff_config_data->mss_volt >= 1270 ) { // 1.35V
                  l_mss_volt_mask = 0x0000000000010000LL;
               } else {                           // 1.2V 
                  FAPI_ERR("Invalid RDIMM ATTR_MSS_VOLT = %d on %s!", p_i_mss_eff_config_data->mss_volt, i_target_mba.toEcmdString());
                  uint32_t& INVALID_RDIMM_VOLT = p_i_mss_eff_config_data->mss_volt;
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INVALID_RDIMM_VOLT); return rc;
               }

               if ( l_rdimm_rcd_ibt[l_cur_mba_port][l_cur_mba_dimm] == fapi::ENUM_ATTR_VPD_DIMM_RCD_IBT_IBT_OFF ) {
                  l_rcd_ibt_mask = 0x0000000070000000LL;
               } else if ( l_rdimm_rcd_ibt[l_cur_mba_port][l_cur_mba_dimm] == fapi::ENUM_ATTR_VPD_DIMM_RCD_IBT_IBT_100 ) {
                  l_rcd_ibt_mask = 0x0000000000000000LL;
               } else if ( l_rdimm_rcd_ibt[l_cur_mba_port][l_cur_mba_dimm] == fapi::ENUM_ATTR_VPD_DIMM_RCD_IBT_IBT_150 ) {
                  l_rcd_ibt_mask = 0x0040000000000000LL;
               } else if ( l_rdimm_rcd_ibt[l_cur_mba_port][l_cur_mba_dimm] == fapi::ENUM_ATTR_VPD_DIMM_RCD_IBT_IBT_200 ) {
                  l_rcd_ibt_mask = 0x0000000020000000LL;
               } else if ( l_rdimm_rcd_ibt[l_cur_mba_port][l_cur_mba_dimm] == fapi::ENUM_ATTR_VPD_DIMM_RCD_IBT_IBT_300 ) {
                  l_rcd_ibt_mask = 0x0000000040000000LL;
               } else {
                  FAPI_ERR("Invalid RDIMM_RCD_IBT = %d port %d dimm %d on %s!", l_rdimm_rcd_ibt[l_cur_mba_port][l_cur_mba_dimm], l_cur_mba_port, l_cur_mba_dimm, i_target_mba.toEcmdString());
                  uint32_t& INVALID_RDIMM_RCD_IBT_U32ARRAY_0_0 = l_rdimm_rcd_ibt[0][0];
                  uint32_t& INVALID_RDIMM_RCD_IBT_U32ARRAY_0_1 = l_rdimm_rcd_ibt[0][1];
                  uint32_t& INVALID_RDIMM_RCD_IBT_U32ARRAY_1_0 = l_rdimm_rcd_ibt[1][0];
                  uint32_t& INVALID_RDIMM_RCD_IBT_U32ARRAY_1_1 = l_rdimm_rcd_ibt[1][1];
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INVALID_RDIMM_RCD_IBT); return rc;
               }

               if ( l_rdimm_rcd_output_timing[l_cur_mba_port][l_cur_mba_dimm] == fapi::ENUM_ATTR_VPD_DIMM_RCD_OUTPUT_TIMING_1T ) {
                  l_rcd_output_timing_mask = 0x0000000000000000LL;
               } else if ( l_rdimm_rcd_output_timing[l_cur_mba_port][l_cur_mba_dimm] == fapi::ENUM_ATTR_VPD_DIMM_RCD_OUTPUT_TIMING_3T ) {
                  l_rcd_output_timing_mask = 0x0020000000000000LL;
               } else {
                  FAPI_ERR("Invalid RDIMM_RCD_OUTPUT_TIMING = %d port %d dimm %d on %s!", l_rdimm_rcd_output_timing[l_cur_mba_port][l_cur_mba_dimm], l_cur_mba_port, l_cur_mba_dimm, i_target_mba.toEcmdString());
                  uint8_t& INVALID_RDIMM_RCD_OUTPUT_TIMING_U8ARRAY_0_0 = l_rdimm_rcd_output_timing[0][0];
                  uint8_t& INVALID_RDIMM_RCD_OUTPUT_TIMING_U8ARRAY_0_1 = l_rdimm_rcd_output_timing[0][1];
                  uint8_t& INVALID_RDIMM_RCD_OUTPUT_TIMING_U8ARRAY_1_0 = l_rdimm_rcd_output_timing[1][0];
                  uint8_t& INVALID_RDIMM_RCD_OUTPUT_TIMING_U8ARRAY_1_1 = l_rdimm_rcd_output_timing[1][1];
                  FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_INVALID_RDIMM_RCD_OUTPUT_TIMING); return rc;
               }

               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] | l_mss_freq_mask;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] | l_mss_volt_mask;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] | l_rcd_ibt_mask;
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] | l_rcd_output_timing_mask;
            } else {
               p_o_atts->eff_dimm_rcd_cntl_word_0_15[l_cur_mba_port][l_cur_mba_dimm] = 0x0000000000000000LL;
            }

            // DEBUG HERE:
            //FAPI_INF("size=%d density=%d ranks=%d width=%d on %s",
            // p_o_atts->eff_dimm_size[l_cur_mba_port][l_cur_mba_dimm],
            // p_o_atts->eff_dram_density, p_o_atts->
            // attr_eff_num_ranks_per_dimm[l_cur_mba_port][l_cur_mba_dimm],
            // p_o_atts->eff_dram_width, i_target_mba.toEcmdString());
//------------------------------------------------------------------------------
            if(p_o_atts->eff_vpd_version == 0xFFFFFF ||
               p_i_data->vpd_version[l_cur_mba_port][l_cur_mba_dimm] < p_o_atts->eff_vpd_version ) { // find the smallest VPD
                p_o_atts->eff_vpd_version = p_i_data->vpd_version[l_cur_mba_port][l_cur_mba_dimm];
            }
//------------------------------------------------------------------------------

        } // inner for loop
    } // outer for loop
    return rc;
} // end mss_eff_config_setup_eff_atts()

//------------------------------------------------------------------------------
// @brief mss_eff_config_write_eff_atts(): This function writes the
//              effective configuration attributes
//
// @param const fapi::Target &i_target_mba: the fapi target
// @param       mss_eff_config_data *p_i_mss_eff_config_data: Pointer to
//              mss_eff_config_data variable structure
// @param const mss_eff_config_atts *p_i_atts: Pointer to mss_eff
//              configuration attributes structure
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config_write_eff_atts(
                                            const fapi::Target &i_target_mba,
                                            mss_eff_config_atts *p_i_atts)
{
    fapi::ReturnCode rc;

    p_i_atts->eff_dram_tras = uint8_t (p_i_atts->eff_dram_tras_u32);
    p_i_atts->eff_dram_trc = uint8_t (p_i_atts->eff_dram_trc_u32);
    p_i_atts->eff_dram_tfaw = uint8_t (p_i_atts->eff_dram_tfaw_u32);

    do
    {
        // Set attributes
        rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RANKS_CONFIGED, &i_target_mba,
                p_i_atts->eff_dimm_ranks_configed);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba,
                p_i_atts->eff_dimm_rcd_cntl_word_0_15);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_SIZE, &i_target_mba,
                p_i_atts->eff_dimm_size);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_TYPE, &i_target_mba,
                p_i_atts->eff_dimm_type);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba,
                p_i_atts->eff_custom_dimm);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_AL, &i_target_mba,
                p_i_atts->eff_dram_al);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_ASR, &i_target_mba,
                p_i_atts->eff_dram_asr);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_BANKS, &i_target_mba,
                p_i_atts->eff_dram_banks);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_BL, &i_target_mba,
                p_i_atts->eff_dram_bl);
        if(rc) break;

        // See mss_freq.C
        //rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_CL, &i_target_mba,
            //p_i_atts->eff_dram_cl);
        //if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_COLS, &i_target_mba,
                p_i_atts->eff_dram_cols);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_CWL, &i_target_mba,
                p_i_atts->eff_dram_cwl);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DENSITY, &i_target_mba,
                p_i_atts->eff_dram_density);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DLL_ENABLE, &i_target_mba,
                p_i_atts->eff_dram_dll_enable);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DLL_PPD, &i_target_mba,
                p_i_atts->eff_dram_dll_ppd);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_DLL_RESET, &i_target_mba,
                p_i_atts->eff_dram_dll_reset);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_GEN, &i_target_mba,
                p_i_atts->eff_dram_gen);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_OUTPUT_BUFFER, &i_target_mba,
                p_i_atts->eff_dram_output_buffer);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_PASR, &i_target_mba,
                p_i_atts->eff_dram_pasr);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RBT, &i_target_mba,
                p_i_atts->eff_dram_rbt);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_ROWS, &i_target_mba,
                p_i_atts->eff_dram_rows);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_SRT, &i_target_mba,
                p_i_atts->eff_dram_srt);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TDQS, &i_target_mba,
                p_i_atts->eff_dram_tdqs);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TFAW, &i_target_mba,
                p_i_atts->eff_dram_tfaw);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TM, &i_target_mba,
                p_i_atts->eff_dram_tm);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRAS, &i_target_mba,
                p_i_atts->eff_dram_tras);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRC, &i_target_mba,
                p_i_atts->eff_dram_trc);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRCD, &i_target_mba,
                p_i_atts->eff_dram_trcd);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRFC, &i_target_mba,
                p_i_atts->eff_dram_trfc);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRFI, &i_target_mba,
                p_i_atts->eff_dram_trfi);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRP, &i_target_mba,
                p_i_atts->eff_dram_trp);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRRD, &i_target_mba,
                p_i_atts->eff_dram_trrd);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TRTP, &i_target_mba,
                p_i_atts->eff_dram_trtp);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TWTR, &i_target_mba,
                p_i_atts->eff_dram_twtr);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WIDTH, &i_target_mba,
                p_i_atts->eff_dram_width);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR, &i_target_mba,
                p_i_atts->eff_dram_wr);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_LVL_ENABLE, &i_target_mba,
                p_i_atts->eff_dram_wr_lvl_enable);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_IBM_TYPE, &i_target_mba,
                p_i_atts->eff_ibm_type);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_MEMCAL_INTERVAL, &i_target_mba,
                p_i_atts->eff_memcal_interval);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_MPR_LOC, &i_target_mba,
                p_i_atts->eff_mpr_loc);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_MPR_MODE, &i_target_mba,
                p_i_atts->eff_mpr_mode);
        if(rc) break;

        // AST HERE: Needs SPD byte33[6:4], currently hard coded to 0, removed for GA1
        //rc = FAPI_ATTR_SET(ATTR_EFF_NUM_DIES_PER_PACKAGE, &i_target_mba,
        //        p_i_atts->eff_num_dies_per_package);
        //if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba,
                p_i_atts->eff_num_drops_per_port);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target_mba,
                p_i_atts->eff_num_master_ranks_per_dimm);
        if(rc) break;

        // AST HERE: Needs source data, currently hard coded to 0, removed for GA1
        //rc = FAPI_ATTR_SET(ATTR_EFF_NUM_PACKAGES_PER_RANK, &i_target_mba,
        //        p_i_atts->eff_num_packages_per_rank);
        //if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba,
                p_i_atts->eff_num_ranks_per_dimm);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_MODE, &i_target_mba,
                p_i_atts->eff_schmoo_mode);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba,
                p_i_atts->eff_schmoo_addr_mode);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_PARAM_VALID, &i_target_mba,
                p_i_atts->eff_schmoo_param_valid);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba,
                p_i_atts->eff_schmoo_test_valid);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_WR_EYE_MIN_MARGIN, &i_target_mba,
                p_i_atts->eff_schmoo_wr_eye_min_margin);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_RD_EYE_MIN_MARGIN, &i_target_mba,
                p_i_atts->eff_schmoo_rd_eye_min_margin);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_DQS_CLK_MIN_MARGIN, &i_target_mba,
                p_i_atts->eff_schmoo_dqs_clk_min_margin);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_RD_GATE_MIN_MARGIN, &i_target_mba,
                p_i_atts->eff_schmoo_rd_gate_min_margin);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN, &i_target_mba,
                p_i_atts->eff_schmoo_addr_cmd_min_margin);
        if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_rd_vref_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF_SCHMOO, &i_target_mba,
                p_i_atts->eff_dram_wr_vref_schmoo);
        if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_rcv_imp_dq_dqs_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_drv_imp_dq_dqs_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CNTL_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_drv_imp_cntl_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CLK_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_drv_imp_clk_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_SPCKE_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_drv_imp_spcke_schmoo);
        if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_slew_rate_dq_dqs_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CNTL_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_slew_rate_cntl_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_ADDR_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_slew_rate_addr_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CLK_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_slew_rate_clk_schmoo);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_SPCKE_SCHMOO, &i_target_mba,
                p_i_atts->eff_cen_slew_rate_spcke_schmoo);
        if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_STACK_TYPE, &i_target_mba,
                p_i_atts->eff_stack_type);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_EFF_ZQCAL_INTERVAL, &i_target_mba,
                p_i_atts->eff_zqcal_interval);
        if(rc) break;
        rc = FAPI_ATTR_SET(ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, &i_target_mba,
                p_i_atts->dimm_functional_vector);
        if(rc) break;

        rc = FAPI_ATTR_SET(ATTR_MSS_CAL_STEP_ENABLE, &i_target_mba,
                p_i_atts->mss_cal_step_enable);
        if(rc) break;

        // Make the final VPD version be a number and not ascii
        p_i_atts->eff_vpd_version=((p_i_atts->eff_vpd_version & 0x0f00)>> 4)|
          ((p_i_atts->eff_vpd_version & 0x000f)>> 0);
        rc = FAPI_ATTR_SET(ATTR_MSS_EFF_VPD_VERSION, &i_target_mba,
                p_i_atts->eff_vpd_version);
        if(rc) break;

    } while(0);

    return rc;
}

//------------------------------------------------------------------------------
// @brief mss_eff_config(): This function is the main function which calls
//                          helper functions that read and verify spd data as
//                          well as configure effective attributes.
//
// @param const fapi::Target i_target_mba: the fapi target
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
fapi::ReturnCode mss_eff_config(const fapi::Target i_target_mba)
{
#ifdef FAPI_DDR4
	fapi::ReturnCode rc;
	rc = mss_eff_config_ddr4(i_target_mba);
	if(rc)
    {
        FAPI_ERR("Error from mss_eff_config_ddr4()");
        return rc;
    }
#endif
#ifndef FAPI_DDR4
    /* Initialize Variables */
    const fapi::Target& TARGET_MBA = i_target_mba;
    const char * const PROCEDURE_NAME = "mss_eff_config";
    fapi::ReturnCode rc;
    fapi::Target l_target_centaur;
    // Changed l_mss_volt to p_l_mss_eff_config_data->mss_volt.
    //uint32_t l_mss_volt;
    // mss_eff_config_data_variable struct
    mss_eff_config_data *p_l_mss_eff_config_data = new mss_eff_config_data();
    // mss_eff_config_spd_data struct
    mss_eff_config_spd_data *p_l_spd_data = new mss_eff_config_spd_data();
    // mss_eff_config_atts struct
    mss_eff_config_atts *p_l_atts = new mss_eff_config_atts();
    /* End Variable Initialization */

    /* zero out struct elements */
    memset( p_l_mss_eff_config_data, 0, sizeof(mss_eff_config_data) );
    memset( p_l_spd_data, 0, sizeof(mss_eff_config_spd_data) );
    memset( p_l_atts, 0, sizeof(mss_eff_config_atts) );

    FAPI_INF("STARTING %s on %s \n", PROCEDURE_NAME,
            i_target_mba.toEcmdString());

    do
    {
      FAPI_INF("Setup and VPD attributes if needbe\n");

#ifdef FAPI_MSSLABONLY
      FAPI_INF("Lab only: Setup and VPD attributes if needbe\n");

      rc = mss_eff_config_termination_vpd(i_target_mba); if(rc) break;
      if(rc)
      {
        FAPI_ERR("Error from mss_eff_config_termination_vpd()");
        break;
      }
#endif

    // Added call to mss_eff_pre_config() for Mike Pardeik (power/thermal).
    rc = mss_eff_pre_config(i_target_mba); if(rc) return rc;

     
//------------------------------------------------------------------------------
        // Grab allow single port data
        rc = FAPI_ATTR_GET(ATTR_MSS_ALLOW_SINGLE_PORT, &i_target_mba, p_l_mss_eff_config_data->allow_single_port);
        if(rc) break;
        if ( p_l_mss_eff_config_data->allow_single_port == fapi::ENUM_ATTR_MSS_ALLOW_SINGLE_PORT_TRUE ) {
           FAPI_INF("WARNING: allow_single_port = %d on %s.", p_l_mss_eff_config_data->allow_single_port, i_target_mba.toEcmdString());
        }
//------------------------------------------------------------------------------
        // Grab freq/volt data
        rc = fapiGetParentChip(i_target_mba, l_target_centaur);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur,
                p_l_mss_eff_config_data->mss_freq);
        if(rc) break;
        rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, p_l_mss_eff_config_data->mss_volt);
        if(rc) break;
        if (p_l_mss_eff_config_data->mss_freq == 0)
        {
            FAPI_ERR("Invalid ATTR_MSS_FREQ = %d on %s!",
                    p_l_mss_eff_config_data->mss_freq,
                    i_target_mba.toEcmdString());
                        uint32_t& FREQ_VAL = p_l_mss_eff_config_data->mss_freq;
            FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_CONFIG_MSS_FREQ);
            break;
        }
        FAPI_INF("mss_freq = %d, tCK_in_ps= %d on %s.",
                p_l_mss_eff_config_data->mss_freq,
                TWO_MHZ/p_l_mss_eff_config_data->mss_freq,
                l_target_centaur.toEcmdString());
        FAPI_INF("mss_volt = %d on %s.", p_l_mss_eff_config_data->mss_volt,
                l_target_centaur.toEcmdString());

//------------------------------------------------------------------------------
        /* Function calls */
        // get SPD data
        rc = mss_eff_config_get_spd_data( i_target_mba,
                p_l_mss_eff_config_data, p_l_spd_data, p_l_atts );
        if(rc)
        {
            FAPI_ERR("Error from mss_eff_config_get_spd_data()");
            break;
        }

        // verify dimm plug rules
        rc = mss_eff_config_verify_plug_rules( i_target_mba,
                p_l_mss_eff_config_data, p_l_atts );
        if(rc)
        {
            FAPI_ERR("Error from mss_eff_config_verify_plug_rules()");
            break;
        }

        // verify SPD data
        if(( p_l_atts->eff_num_drops_per_port
                != fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_EMPTY )
          && ( p_l_mss_eff_config_data->allow_single_port == fapi::ENUM_ATTR_MSS_ALLOW_SINGLE_PORT_FALSE ))
        {
            rc = mss_eff_config_verify_spd_data( i_target_mba,
                    p_l_atts, p_l_spd_data );
            if(rc)
            {
                FAPI_ERR("Error from mss_eff_config_verify_spd_data()");
                break;
            }
        }

        // setup effective configuration attributes
        rc = mss_eff_config_setup_eff_atts( i_target_mba,
                p_l_mss_eff_config_data, p_l_spd_data, p_l_atts );
        if(rc)
        {
            FAPI_ERR("Error from mss_eff_config_setup_eff_atts()");
            break;
        }

        // write effective configuration attributes
        rc = mss_eff_config_write_eff_atts( i_target_mba,
                p_l_atts );
        if(rc)
        {
            FAPI_ERR("Error from mss_eff_config_write_eff_atts()");
            break;
        }



        // Calls to sub-procedures

        // LRDIMM attributes
        if ( p_l_atts->eff_dimm_type == fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM )
        {
           rc = mss_lrdimm_eff_config(i_target_mba, p_l_mss_eff_config_data->cur_dimm_spd_valid_u8array,
                                      p_l_mss_eff_config_data->mss_freq, p_l_atts->eff_num_ranks_per_dimm);
           if(rc)
           {
               FAPI_ERR("Error from mss_lrdimm_eff_config()");
               break;
           }
        }
 
        rc = mss_eff_config_rank_group(i_target_mba); if(rc) break;

        // Removed call to mss_eff_config_cke_map(), 
        //rc = mss_eff_config_cke_map(i_target_mba); if(rc) break;


// Removed call to mss_eff_config_termination() for Palmetto and Habanero using ifdef "FAPI_MSSLABONLY", moving to liveVPD.
// Note: Stradale, KG3, and DDR4 will still need ifdef "FAPI_MSSLABONLY"
#ifdef FAPI_MSSLABONLY
        // If MSS Lab/Development override, for now everything except DDR3 CDIMMs
        if ((p_l_atts->eff_custom_dimm == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_NO) || (p_l_atts->eff_dram_gen == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4)) {
           rc = mss_eff_config_termination(i_target_mba); if(rc) break;
           if(rc)
           {
               FAPI_ERR("Error from mss_eff_config_termination()");
               break;
           }
        }
#endif


        // Removed call to mss_eff_config_thermal(), it is now called externally.
        //rc = mss_eff_config_thermal(i_target_mba); if(rc) break;

        rc = mss_eff_config_shmoo(i_target_mba); if(rc) break;



        FAPI_INF("%s on %s COMPLETE\n", PROCEDURE_NAME,
                i_target_mba.toEcmdString());

    } while(0);
    /* free memory */
    delete p_l_mss_eff_config_data;
    delete p_l_spd_data;
    delete p_l_atts;
#endif
    return rc;
} // end mss_eff_config()
} // extern "C"

