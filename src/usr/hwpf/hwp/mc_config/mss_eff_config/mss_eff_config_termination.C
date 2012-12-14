/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_termination.C $ */
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
// $Id: mss_eff_config_termination.C,v 1.8 2012/12/06 13:45:57 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_termination.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_termination
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// This procedure is a place holder for attributes set by the machine parsable workbook.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.9   |          |         |
//   1.8   | bellows  |06-DEC-12| Added sim leg for rotator values
//   1.7   | asaetow  |18-NOV-12| Changed ATTR_MSS_CAL_STEP_ENABLE from 0x7F back to 0xFF. 
//   1.6   | asaetow  |17-NOV-12| Fixed ATTR_EFF_ODT_WR for 4R RDIMMs.
//   1.5   | asaetow  |17-NOV-12| Added PR settings.
//         |          |         | Fixed RCD settings for RDIMM.
//   1.4   | asaetow  |17-NOV-12| Changed ATTR_MSS_CAL_STEP_ENABLE from 0xFF to 0x7F. 
//   1.3   | asaetow  |05-NOV-12| Added Paul's SI value for pre-machine parsable workbook.
//         |          |         | NOTE: DO NOT pick-up without memory_attributes.xml v1.45 or newer.
//   1.2   | asaetow  |05-SEP-12| Added ATTR_MSS_CAL_STEP_ENABLE.
//   1.1   | asaetow  |30-APR-12| First Draft.



//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>



//----------------------------------------------------------------------
// ENUMs and CONSTs
//----------------------------------------------------------------------

// Define attribute array size
const uint8_t PORT_SIZE = 2;
const uint8_t PR_TYPE_SIZE = 48;
const uint8_t TOPO_SIZE = 25;

const uint8_t PR_VALUE_U8ARRAY[PORT_SIZE][PR_TYPE_SIZE][TOPO_SIZE] = {
   {{0,95,100,63,67,66,63,63,63,90,95,69,71,73,77,69,71,69,73,76,77,81,73,78,74},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,103,109,0,0,0,0,0,0,98,104,0,0,0,0,0,0,0,69,71,72,77,69,71,68},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,6,9,2,1,2,2,2,2,11,14,12,15,12,15,12,14,10,18,21,17,21,16,20,15},
   {0,7,9,3,2,3,2,3,3,11,14,11,13,11,13,10,13,9,17,20,16,19,14,18,14},
   {0,7,9,2,2,2,2,2,2,10,13,12,15,12,15,12,15,10,18,22,18,21,16,20,15},
   {0,3,3,5,4,5,4,5,4,5,6,11,14,11,14,11,14,9,17,20,17,20,15,19,14},
   {0,0,0,0,0,0,0,0,1,4,5,8,10,8,10,8,10,7,14,17,14,16,12,15,12},
   {0,0,0,1,1,1,1,1,1,5,6,12,15,12,15,11,14,10,18,21,17,21,16,20,15},
   {0,3,3,4,3,4,3,4,4,6,8,13,16,13,16,13,16,11,19,23,18,22,17,21,16},
   {0,2,2,3,2,3,2,3,3,6,8,13,17,13,17,13,17,11,19,23,19,23,17,22,16},
   {0,4,4,6,5,6,5,6,5,9,11,16,21,16,21,16,21,14,22,27,22,27,21,26,19},
   {0,6,8,2,2,2,2,2,2,10,13,12,15,12,15,12,15,10,18,22,18,22,16,21,15},
   {0,11,14,8,6,8,6,8,7,8,11,9,11,9,11,9,11,7,15,18,15,17,12,16,12},
   {0,8,10,3,3,3,3,3,3,11,14,12,15,12,15,12,15,10,18,22,18,21,16,21,15},
   {0,8,10,4,3,4,3,4,4,10,12,11,13,11,13,10,13,9,17,20,16,19,14,18,14},
   {0,7,10,3,3,3,3,3,3,13,16,14,18,14,18,14,17,12,20,24,19,23,18,23,17},
   {0,7,9,3,2,3,2,3,3,11,14,12,15,12,15,12,15,10,18,21,17,21,16,20,15},
   {0,11,14,8,7,8,6,8,7,8,10,7,9,7,9,7,9,6,13,15,13,15,10,14,11},
   {0,6,7,8,7,8,7,8,7,3,3,9,11,9,11,9,11,7,15,18,14,17,12,16,12},
   {0,6,6,8,7,8,7,8,7,4,5,10,13,10,13,10,13,8,16,20,16,19,14,18,14},
   {0,11,14,8,6,8,6,8,7,7,9,7,8,7,8,7,8,5,13,15,12,14,10,13,10},
   {0,12,15,9,8,9,8,9,8,7,9,8,10,8,10,8,10,7,14,17,14,16,12,15,12},
   {0,11,14,8,6,8,6,8,7,11,13,11,14,11,14,11,14,9,17,20,17,20,15,19,14},
   {0,12,15,9,7,9,7,9,8,7,9,6,7,6,7,6,7,5,12,14,11,13,9,12,9},
   {0,0,0,8,7,8,7,8,7,0,0,9,11,9,11,9,11,7,15,18,14,17,12,16,12},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,31,37,3,2,3,2,3,3,38,44,8,10,8,9,8,10,7,11,14,12,13,12,16,12},
   {0,0,0,12,10,12,10,12,11,0,0,1,2,1,1,1,1,1,5,6,5,5,6,8,7},
   {0,24,29,0,0,0,0,0,0,34,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,12,14,0,0,0,0,0,1,21,25,10,13,10,13,10,13,9,14,17,14,16,15,20,15},
   {0,0,0,12,10,12,10,12,11,0,0,1,2,1,2,1,2,1,5,6,5,5,6,8,7},
   {0,0,0,2,2,2,2,2,3,0,0,10,12,10,12,10,12,8,13,17,14,15,14,19,14},
   {0,0,0,12,10,12,10,12,11,0,0,4,5,4,5,4,5,3,7,10,8,8,8,12,9},
   {0,14,16,3,2,3,2,3,3,14,16,3,4,3,4,3,4,3,7,9,7,7,8,11,9},
   {0,0,0,11,9,11,9,11,10,0,0,1,2,1,1,1,1,1,5,6,5,5,6,8,7},
   {0,31,37,0,0,0,0,0,0,41,47,0,0,0,0,0,0,0,11,13,11,13,11,14,9},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,1},
   {0,34,40,0,0,0,0,0,0,34,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,19,23,0,0,0,0,0,0,13,15,0,0,0,0,0,0,0,3,4,3,4,3,4,3},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,2},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,6,4},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3},
   {0,15,17,0,0,0,0,0,0,21,24,0,0,0,0,0,0,0,8,10,8,10,8,10,7},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,2,2,2,3,2}},
   
   {{0,90,95,70,71,75,68,70,71,91,96,69,71,73,77,69,71,69,73,76,77,81,73,78,74},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,99,105,0,0,0,0,0,0,99,104,0,0,0,0,0,0,0,69,71,72,77,69,71,68},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,11,13,8,7,8,7,8,7,7,9,10,12,10,12,10,12,8,16,19,16,19,14,17,13},
   {0,9,11,6,5,6,5,6,5,8,10,10,13,10,13,10,13,8,16,20,16,19,14,18,14},
   {0,12,14,9,7,9,7,9,7,10,12,13,16,13,16,13,16,11,19,23,19,23,17,22,16},
   {0,2,3,4,3,4,3,4,3,2,2,10,13,11,13,10,13,8,16,20,16,19,14,18,14},
   {0,0,0,2,2,2,2,2,2,2,3,11,13,11,13,10,13,9,17,20,16,19,14,18,14},
   {0,0,0,0,0,0,0,0,0,4,4,13,16,13,16,13,16,10,19,23,18,22,17,21,16},
   {0,1,2,3,2,3,2,3,2,4,5,13,16,13,16,13,16,11,19,23,19,23,17,22,16},
   {0,0,0,2,1,2,1,2,1,3,4,12,15,12,15,12,15,10,18,22,18,21,16,20,15},
   {0,7,8,10,8,10,8,10,8,5,5,13,16,13,16,13,16,11,19,23,19,23,17,22,16},
   {0,5,7,1,1,1,1,1,1,10,12,13,17,13,17,13,16,11,19,23,19,23,17,22,16},
   {0,12,15,9,8,9,8,9,8,5,7,9,11,9,11,8,10,7,15,17,14,17,12,15,12},
   {0,6,8,3,2,3,2,3,2,10,12,13,16,13,16,13,16,11,19,23,18,22,17,21,16},
   {0,10,13,7,6,7,6,7,6,7,8,10,12,10,13,10,12,8,16,19,16,19,14,17,13},
   {0,9,11,6,5,6,5,6,5,9,11,12,15,12,15,12,15,10,18,22,18,21,16,20,15},
   {0,7,9,3,3,3,3,3,3,10,12,13,17,13,17,13,17,11,19,23,19,23,17,22,16},
   {0,10,13,6,5,6,5,6,5,7,9,10,12,10,12,10,12,8,16,19,16,19,13,17,13},
   {0,4,5,6,5,6,5,6,5,1,1,10,12,10,12,9,12,8,16,19,15,18,13,17,13},
   {0,4,4,5,4,5,4,5,4,2,2,10,13,10,13,10,12,8,16,19,16,19,14,17,13},
   {0,11,14,7,6,8,6,8,6,6,8,9,11,9,11,9,11,7,15,18,15,18,13,16,12},
   {0,12,15,9,7,9,7,9,7,7,9,10,12,10,12,10,12,8,16,19,16,19,14,17,13},
   {0,15,18,11,9,11,9,11,9,5,7,8,9,8,9,8,9,6,14,16,13,16,11,14,11},
   {0,13,16,10,9,11,9,11,9,5,7,8,10,8,10,8,9,6,14,16,13,16,11,14,11},
   {0,0,0,4,3,4,3,4,3,0,0,12,15,12,15,12,15,10,18,22,18,22,16,21,15},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,32,38,3,1,3,2,3,2,31,37,4,4,4,4,4,4,3,7,9,8,7,8,11,9},
   {0,0,0,5,3,5,4,5,4,0,0,11,14,11,14,11,14,10,15,19,15,17,16,21,15},
   {0,27,32,0,0,0,0,0,0,36,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,14,16,4,3,4,4,5,4,14,15,4,4,4,4,4,4,3,7,9,8,8,8,11,9},
   {0,0,0,10,7,10,8,10,8,0,0,12,15,12,15,12,15,10,15,20,16,18,17,22,16},
   {0,0,0,3,2,3,3,3,3,0,0,4,4,4,4,4,4,3,7,9,8,8,8,11,9},
   {0,0,0,12,9,12,10,12,10,0,0,11,13,11,13,11,13,9,14,18,15,16,15,20,15},
   {0,14,16,3,1,3,2,3,3,13,15,3,4,3,3,3,4,2,6,8,7,7,7,10,8},
   {0,0,0,12,10,12,10,13,11,0,0,9,12,9,11,9,12,8,13,16,13,15,14,18,14},
   {0,33,39,0,0,0,0,0,0,31,36,0,0,0,0,0,0,0,4,4,4,4,4,4,3},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,15,12,15,12,15,10},
   {0,33,40,0,0,0,0,0,0,32,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,15,18,0,0,0,0,0,0,19,21,0,0,0,0,0,0,0,9,11,9,11,9,11,8},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,17,14,17,14,17,12},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,10,9,10,9,11,7},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,13,11,13,11,13,9},
   {0,12,14,0,0,0,0,0,0,13,15,0,0,0,0,0,0,0,4,5,4,5,4,5,3},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,13,11,13,10,13,9}}};



extern "C" {



//******************************************************************************
//* name=mss_eff_config_termination, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_termination(const fapi::Target i_target_mba) {
   fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
   const char * const PROCEDURE_NAME = "mss_eff_config_termination";
   FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());


   // Define attribute array size
   const uint8_t DIMM_SIZE = 2;
   const uint8_t RANK_SIZE = 4;


   // Fetch dependent attributes
   uint8_t l_target_mba_pos = 0;
   uint32_t l_mss_freq = 0;
   uint32_t l_mss_volt = 0;
   uint8_t l_num_ranks_per_dimm_u8array[PORT_SIZE][DIMM_SIZE];
   // ATTR_EFF_DRAM_GEN: EMPTY = 0, DDR3 = 1, DDR4 = 2, 
   uint8_t l_dram_gen_u8;
   // ATTR_EFF_DIMM_TYPE: CDIMM = 0, RDIMM = 1, UDIMM = 2, LRDIMM = 3,
   uint8_t l_dimm_type_u8;
   uint8_t l_num_drops_per_port;
   rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_target_mba_pos);
   fapi::Target l_target_centaur;
   rc = fapiGetParentChip(i_target_mba, l_target_centaur); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_mss_freq); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_mss_volt); if(rc) return rc;
   if (l_mss_freq <= 0) {
      FAPI_ERR("Invalid ATTR_MSS_FREQ = %d on %s!", l_mss_freq, i_target_mba.toEcmdString());
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
   }
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target_mba, l_dram_gen_u8); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target_mba, l_dimm_type_u8); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, l_num_drops_per_port); if(rc) return rc;


   // Fetch impacted attributes
   uint64_t l_attr_eff_dimm_rcd_cntl_word_0_15[PORT_SIZE][DIMM_SIZE];
   rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;

   // find out if we are in simulation mode
   uint8_t l_attr_is_simulation;
   rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, l_attr_is_simulation);


   // Define local attribute variables
   uint8_t l_attr_mss_cal_step_enable = 0xFF;

   uint32_t l_attr_eff_dimm_rcd_ibt[PORT_SIZE][DIMM_SIZE];
      l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF;
      l_attr_eff_dimm_rcd_ibt[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF;
      l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF;
      l_attr_eff_dimm_rcd_ibt[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF;
   uint8_t l_attr_eff_dimm_rcd_mirror_mode[PORT_SIZE][DIMM_SIZE];
      l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;
      l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;
      l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;
      l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;

   uint32_t l_attr_eff_cen_rd_vref[PORT_SIZE];
      l_attr_eff_cen_rd_vref[0] = fapi::ENUM_ATTR_EFF_CEN_RD_VREF_VDD50000;
      l_attr_eff_cen_rd_vref[1] = fapi::ENUM_ATTR_EFF_CEN_RD_VREF_VDD50000;
   uint32_t l_attr_eff_dram_wr_vref[PORT_SIZE];
      l_attr_eff_dram_wr_vref[0] = fapi::ENUM_ATTR_EFF_DRAM_WR_VREF_VDD500;
      l_attr_eff_dram_wr_vref[1] = fapi::ENUM_ATTR_EFF_DRAM_WR_VREF_VDD500;

   uint8_t l_attr_eff_cen_rcv_imp_dq_dqs[PORT_SIZE];
      l_attr_eff_cen_rcv_imp_dq_dqs[0] = fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM60;
      l_attr_eff_cen_rcv_imp_dq_dqs[1] = fapi::ENUM_ATTR_EFF_CEN_RCV_IMP_DQ_DQS_OHM60;
   uint8_t l_attr_eff_cen_drv_imp_dq_dqs[PORT_SIZE];
      l_attr_eff_cen_drv_imp_dq_dqs[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0;
      l_attr_eff_cen_drv_imp_dq_dqs[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0;
   uint8_t l_attr_eff_cen_drv_imp_cntl[PORT_SIZE];
      l_attr_eff_cen_drv_imp_cntl[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CNTL_OHM30;
      l_attr_eff_cen_drv_imp_cntl[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CNTL_OHM30;
   uint8_t l_attr_eff_cen_drv_imp_addr[PORT_SIZE];
      l_attr_eff_cen_drv_imp_addr[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_ADDR_OHM30;
      l_attr_eff_cen_drv_imp_addr[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_ADDR_OHM30;
   uint8_t l_attr_eff_cen_drv_imp_clk[PORT_SIZE];
      l_attr_eff_cen_drv_imp_clk[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CLK_OHM30;
      l_attr_eff_cen_drv_imp_clk[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CLK_OHM30;
   uint8_t l_attr_eff_cen_drv_imp_spcke[PORT_SIZE];
      l_attr_eff_cen_drv_imp_spcke[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_SPCKE_OHM40;
      l_attr_eff_cen_drv_imp_spcke[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_SPCKE_OHM40;

   uint8_t l_attr_eff_cen_slew_rate_dq_dqs[PORT_SIZE];
      l_attr_eff_cen_slew_rate_dq_dqs[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_dq_dqs[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SLEW_4V_NS;
   uint8_t l_attr_eff_cen_slew_rate_cntl[PORT_SIZE];
      l_attr_eff_cen_slew_rate_cntl[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CNTL_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_cntl[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CNTL_SLEW_4V_NS;
   uint8_t l_attr_eff_cen_slew_rate_addr[PORT_SIZE];
      l_attr_eff_cen_slew_rate_addr[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_ADDR_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_addr[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_ADDR_SLEW_4V_NS;
   uint8_t l_attr_eff_cen_slew_rate_clk[PORT_SIZE];
      l_attr_eff_cen_slew_rate_clk[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CLK_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_clk[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CLK_SLEW_4V_NS;
   uint8_t l_attr_eff_cen_slew_rate_spcke[PORT_SIZE];
      l_attr_eff_cen_slew_rate_spcke[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS;
      l_attr_eff_cen_slew_rate_spcke[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_SPCKE_SLEW_3V_NS;

   uint8_t l_attr_eff_dram_ron[PORT_SIZE][DIMM_SIZE];
      l_attr_eff_dram_ron[0][0] = fapi::ENUM_ATTR_EFF_DRAM_RON_OHM34;
      l_attr_eff_dram_ron[0][1] = fapi::ENUM_ATTR_EFF_DRAM_RON_OHM34;
      l_attr_eff_dram_ron[1][0] = fapi::ENUM_ATTR_EFF_DRAM_RON_OHM34;
      l_attr_eff_dram_ron[1][1] = fapi::ENUM_ATTR_EFF_DRAM_RON_OHM34;
   uint8_t l_attr_eff_dram_rtt_nom[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      l_attr_eff_dram_rtt_nom[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE; 
      l_attr_eff_dram_rtt_nom[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[0][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[0][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[0][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[0][1][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
      l_attr_eff_dram_rtt_nom[1][1][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_DISABLE;
   uint8_t l_attr_eff_dram_rtt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[0][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[0][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[0][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[0][1][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      l_attr_eff_dram_rtt_wr[1][1][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_DISABLE;
      
   uint8_t l_attr_eff_odt_rd[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      l_attr_eff_odt_rd[0][0][0] = 0x0;
      l_attr_eff_odt_rd[0][0][1] = 0x0;
      l_attr_eff_odt_rd[0][0][2] = 0x0;
      l_attr_eff_odt_rd[0][0][3] = 0x0;
      l_attr_eff_odt_rd[0][1][0] = 0x0;
      l_attr_eff_odt_rd[0][1][1] = 0x0;
      l_attr_eff_odt_rd[0][1][2] = 0x0;
      l_attr_eff_odt_rd[0][1][3] = 0x0;
      l_attr_eff_odt_rd[1][0][0] = 0x0;
      l_attr_eff_odt_rd[1][0][1] = 0x0;
      l_attr_eff_odt_rd[1][0][2] = 0x0;
      l_attr_eff_odt_rd[1][0][3] = 0x0;
      l_attr_eff_odt_rd[1][1][0] = 0x0;
      l_attr_eff_odt_rd[1][1][1] = 0x0;
      l_attr_eff_odt_rd[1][1][2] = 0x0;
      l_attr_eff_odt_rd[1][1][3] = 0x0;
   uint8_t l_attr_eff_odt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      l_attr_eff_odt_wr[0][0][0] = 0x0;
      l_attr_eff_odt_wr[0][0][1] = 0x0;
      l_attr_eff_odt_wr[0][0][2] = 0x0;
      l_attr_eff_odt_wr[0][0][3] = 0x0;
      l_attr_eff_odt_wr[0][1][0] = 0x0;
      l_attr_eff_odt_wr[0][1][1] = 0x0;
      l_attr_eff_odt_wr[0][1][2] = 0x0;
      l_attr_eff_odt_wr[0][1][3] = 0x0;
      l_attr_eff_odt_wr[1][0][0] = 0x0;
      l_attr_eff_odt_wr[1][0][1] = 0x0;
      l_attr_eff_odt_wr[1][0][2] = 0x0;
      l_attr_eff_odt_wr[1][0][3] = 0x0;
      l_attr_eff_odt_wr[1][1][0] = 0x0;
      l_attr_eff_odt_wr[1][1][1] = 0x0;
      l_attr_eff_odt_wr[1][1][2] = 0x0;
      l_attr_eff_odt_wr[1][1][3] = 0x0;


   if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
      // IMP
      l_attr_eff_cen_drv_imp_dq_dqs[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0;
      l_attr_eff_cen_drv_imp_dq_dqs[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0;
      l_attr_eff_cen_drv_imp_cntl[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CNTL_OHM30;
      l_attr_eff_cen_drv_imp_cntl[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CNTL_OHM30;
      l_attr_eff_cen_drv_imp_addr[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_ADDR_OHM30;
      l_attr_eff_cen_drv_imp_addr[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_ADDR_OHM30;
      l_attr_eff_cen_drv_imp_clk[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CLK_OHM30;
      l_attr_eff_cen_drv_imp_clk[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CLK_OHM30;
      // SLEW
      l_attr_eff_cen_slew_rate_cntl[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CNTL_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_cntl[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CNTL_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_addr[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_ADDR_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_addr[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_ADDR_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_clk[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CLK_SLEW_4V_NS;
      l_attr_eff_cen_slew_rate_clk[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CLK_SLEW_4V_NS;
      // RTT and ODT
      l_attr_eff_dram_rtt_nom[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
      l_attr_eff_dram_rtt_nom[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
      l_attr_eff_dram_rtt_nom[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
      l_attr_eff_dram_rtt_nom[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
      l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
      l_attr_eff_dram_rtt_wr[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
      l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
      l_attr_eff_dram_rtt_wr[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
      l_attr_eff_odt_wr[0][0][0] = 0x80;
      l_attr_eff_odt_wr[1][0][0] = 0x80;
   } else if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM ) {
      // IMP
      l_attr_eff_cen_drv_imp_dq_dqs[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0;
      l_attr_eff_cen_drv_imp_dq_dqs[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0;
      l_attr_eff_cen_drv_imp_cntl[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CNTL_OHM40;
      l_attr_eff_cen_drv_imp_cntl[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CNTL_OHM40;
      l_attr_eff_cen_drv_imp_addr[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_ADDR_OHM40;
      l_attr_eff_cen_drv_imp_addr[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_ADDR_OHM40;
      l_attr_eff_cen_drv_imp_clk[0] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CLK_OHM40;
      l_attr_eff_cen_drv_imp_clk[1] = fapi::ENUM_ATTR_EFF_CEN_DRV_IMP_CLK_OHM40;
      // SLEW
      l_attr_eff_cen_slew_rate_cntl[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CNTL_SLEW_3V_NS;
      l_attr_eff_cen_slew_rate_cntl[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CNTL_SLEW_3V_NS;
      l_attr_eff_cen_slew_rate_addr[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_ADDR_SLEW_3V_NS;
      l_attr_eff_cen_slew_rate_addr[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_ADDR_SLEW_3V_NS;
      l_attr_eff_cen_slew_rate_clk[0] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CLK_SLEW_3V_NS;
      l_attr_eff_cen_slew_rate_clk[1] = fapi::ENUM_ATTR_EFF_CEN_SLEW_RATE_CLK_SLEW_3V_NS;
      // Check DPHY01 or DHPY23
      if ( l_target_mba_pos == 0 ) {
         if ( l_num_ranks_per_dimm_u8array[0][0] == 4 ) {
            // RCD TERM
            l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
            l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
            l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            // RTT and ODT
            l_attr_eff_dram_rtt_nom[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
            l_attr_eff_dram_rtt_nom[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
            l_attr_eff_dram_rtt_nom[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
            l_attr_eff_dram_rtt_nom[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
            l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_dram_rtt_wr[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_dram_rtt_wr[0][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_dram_rtt_wr[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_dram_rtt_wr[1][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
            l_attr_eff_odt_rd[0][0][0] = 0x40;
            l_attr_eff_odt_rd[0][0][1] = 0x40;
            l_attr_eff_odt_rd[0][0][2] = 0x80;
            l_attr_eff_odt_rd[0][0][3] = 0x80;
            l_attr_eff_odt_rd[1][0][0] = 0x40;
            l_attr_eff_odt_rd[1][0][1] = 0x40;
            l_attr_eff_odt_rd[1][0][2] = 0x80;
            l_attr_eff_odt_rd[1][0][3] = 0x80;
            l_attr_eff_odt_wr[0][0][0] = 0xC0;
            l_attr_eff_odt_wr[0][0][1] = 0x40;
            l_attr_eff_odt_wr[0][0][2] = 0xC0;
            l_attr_eff_odt_wr[0][0][3] = 0x40;
            l_attr_eff_odt_wr[1][0][0] = 0xC0;
            l_attr_eff_odt_wr[1][0][1] = 0x40;
            l_attr_eff_odt_wr[1][0][2] = 0xC0;
            l_attr_eff_odt_wr[1][0][3] = 0x40;
         } else if ( l_num_ranks_per_dimm_u8array[0][0] == 2 ) {
            // RCD TERM
            l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
            l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
            l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            // RTT and ODT
            l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
            l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
            l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
            l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
            l_attr_eff_odt_wr[0][0][0] = 0x80;
            l_attr_eff_odt_wr[0][0][1] = 0x40;
            l_attr_eff_odt_wr[1][0][0] = 0x80;
            l_attr_eff_odt_wr[1][0][1] = 0x40;
         } else if ( l_num_ranks_per_dimm_u8array[0][0] == 1 ) {
            // RCD TERM
            l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
            l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
            l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
            // RTT and ODT
            l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
            l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
            l_attr_eff_odt_wr[0][0][0] = 0x80;
            l_attr_eff_odt_wr[1][0][0] = 0x80;
         }
      } else if ( l_target_mba_pos == 1 ) {
         // Check SINGLE or DUAL Drop
         if ( l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE ) {
            if ( l_num_ranks_per_dimm_u8array[0][0] == 4 ) {
               // RCD TERM
               l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
               l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
               l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               // RTT and ODT
               l_attr_eff_dram_rtt_nom[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_nom[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_nom[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_nom[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_odt_rd[0][0][0] = 0x40;
               l_attr_eff_odt_rd[0][0][1] = 0x40;
               l_attr_eff_odt_rd[0][0][2] = 0x80;
               l_attr_eff_odt_rd[0][0][3] = 0x80;
               l_attr_eff_odt_rd[1][0][0] = 0x40;
               l_attr_eff_odt_rd[1][0][1] = 0x40;
               l_attr_eff_odt_rd[1][0][2] = 0x80;
               l_attr_eff_odt_rd[1][0][3] = 0x80;
               l_attr_eff_odt_wr[0][0][0] = 0xC0;
               l_attr_eff_odt_wr[0][0][1] = 0x40;
               l_attr_eff_odt_wr[0][0][2] = 0xC0;
               l_attr_eff_odt_wr[0][0][3] = 0x40;
               l_attr_eff_odt_wr[1][0][0] = 0xC0;
               l_attr_eff_odt_wr[1][0][1] = 0x40;
               l_attr_eff_odt_wr[1][0][2] = 0xC0;
               l_attr_eff_odt_wr[1][0][3] = 0x40;
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 2 ) {
               // RCD TERM
               l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
               l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
               l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               // RTT and ODT
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_odt_wr[0][0][0] = 0x40;
               l_attr_eff_odt_wr[0][0][1] = 0x80;
               l_attr_eff_odt_wr[1][0][0] = 0x40;
               l_attr_eff_odt_wr[1][0][1] = 0x80;
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 1 ) {
               // RCD TERM
               l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
               l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100;
               l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               // RTT and ODT
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM60;
               l_attr_eff_odt_wr[0][0][0] = 0x80;
               l_attr_eff_odt_wr[1][0][0] = 0x80;
            }
         } else if ( l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL ) {
            if ( l_num_ranks_per_dimm_u8array[0][0] == 4 ) {
               // RCD TERM
               l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;
               l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;
               l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;
               l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF;
               // RTT and ODT
               l_attr_eff_dram_rtt_nom[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_nom[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_nom[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_nom[0][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_nom[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_nom[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_nom[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_nom[1][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM20;
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][1][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][1][2] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][1][3] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_odt_rd[0][0][0] = 0x20;
               l_attr_eff_odt_rd[0][0][1] = 0x20;
               l_attr_eff_odt_rd[0][0][2] = 0x20;
               l_attr_eff_odt_rd[0][0][3] = 0x20;
               l_attr_eff_odt_rd[0][1][0] = 0x80;
               l_attr_eff_odt_rd[0][1][1] = 0x80;
               l_attr_eff_odt_rd[0][1][2] = 0x80;
               l_attr_eff_odt_rd[0][1][3] = 0x80;
               l_attr_eff_odt_rd[1][0][0] = 0x20;
               l_attr_eff_odt_rd[1][0][1] = 0x20;
               l_attr_eff_odt_rd[1][0][2] = 0x20;
               l_attr_eff_odt_rd[1][0][3] = 0x20;
               l_attr_eff_odt_rd[1][1][0] = 0x80;
               l_attr_eff_odt_rd[1][1][1] = 0x80;
               l_attr_eff_odt_rd[1][1][2] = 0x80;
               l_attr_eff_odt_rd[1][1][3] = 0x80;
               l_attr_eff_odt_wr[0][0][0] = 0xA0;
               l_attr_eff_odt_wr[0][0][1] = 0x20;
               l_attr_eff_odt_wr[0][0][2] = 0x60;
               l_attr_eff_odt_wr[0][0][3] = 0x20;
               l_attr_eff_odt_wr[0][1][0] = 0xA0;
               l_attr_eff_odt_wr[0][1][1] = 0x80;
               l_attr_eff_odt_wr[0][1][2] = 0x90;
               l_attr_eff_odt_wr[0][1][3] = 0x80;
               l_attr_eff_odt_wr[1][0][0] = 0xA0;
               l_attr_eff_odt_wr[1][0][1] = 0x20;
               l_attr_eff_odt_wr[1][0][2] = 0x60;
               l_attr_eff_odt_wr[1][0][3] = 0x20;
               l_attr_eff_odt_wr[1][1][0] = 0xA0;
               l_attr_eff_odt_wr[1][1][1] = 0x80;
               l_attr_eff_odt_wr[1][1][2] = 0x90;
               l_attr_eff_odt_wr[1][1][3] = 0x80;
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 2 ) {
               // RCD TERM
               l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               // RTT and ODT
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[0][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[1][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM40;
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][1][1] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_odt_rd[0][0][0] = 0x20;
               l_attr_eff_odt_rd[0][0][1] = 0x20;
               l_attr_eff_odt_rd[0][1][0] = 0x80;
               l_attr_eff_odt_rd[0][1][1] = 0x80;
               l_attr_eff_odt_rd[1][0][0] = 0x20;
               l_attr_eff_odt_rd[1][0][1] = 0x20;
               l_attr_eff_odt_rd[1][1][0] = 0x80;
               l_attr_eff_odt_rd[1][1][1] = 0x80;
               l_attr_eff_odt_wr[0][0][0] = 0xA0;
               l_attr_eff_odt_wr[0][0][1] = 0x60;
               l_attr_eff_odt_wr[0][1][0] = 0xA0;
               l_attr_eff_odt_wr[0][1][1] = 0x60;
               l_attr_eff_odt_wr[1][0][0] = 0xA0;
               l_attr_eff_odt_wr[1][0][1] = 0x60;
               l_attr_eff_odt_wr[1][1][0] = 0xA0;
               l_attr_eff_odt_wr[1][1][1] = 0x60;
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 1 ) {
               // RCD TERM
               l_attr_eff_dimm_rcd_ibt[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_ibt[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200;
               l_attr_eff_dimm_rcd_mirror_mode[0][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[0][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][0] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               l_attr_eff_dimm_rcd_mirror_mode[1][1] = fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON;
               // RTT and ODT
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_wr[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_wr[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_NOM_OHM30;
               l_attr_eff_dram_rtt_wr[0][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[0][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][0][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_dram_rtt_wr[1][1][0] = fapi::ENUM_ATTR_EFF_DRAM_RTT_WR_OHM120;
               l_attr_eff_odt_rd[0][0][0] = 0x20;
               l_attr_eff_odt_rd[0][1][0] = 0x80;
               l_attr_eff_odt_rd[1][0][0] = 0x20;
               l_attr_eff_odt_rd[1][1][0] = 0x80;
               l_attr_eff_odt_wr[0][0][0] = 0xA0;
               l_attr_eff_odt_wr[0][1][0] = 0xA0;
               l_attr_eff_odt_wr[1][0][0] = 0xA0;
               l_attr_eff_odt_wr[1][1][0] = 0xA0;
            }
         }
      } else {
         FAPI_ERR("Invalid MBA on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
   } else {
      FAPI_ERR("Currently unsupported DIMM_TYPE on %s!", i_target_mba.toEcmdString());
      FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
   }


   // Modify impacted attributes
   if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM ) {
      for( int l_port = 0; l_port < PORT_SIZE; l_port += 1 ) {
         for( int l_dimm = 0; l_dimm < DIMM_SIZE; l_dimm += 1 ) {
            uint64_t l_mss_freq_mask        = 0xFFFFFFFFFFCFFFFFLL;
            uint64_t l_mss_volt_mask        = 0xFFFFFFFFFFFEFFFFLL;
            uint64_t l_rcd_ibt_mask         = 0xFFBFFFFF8FFFFFFFLL;
            uint64_t l_rcd_mirror_mode_mask = 0xFFFFFFFF7FFFFFFFLL;
            if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4 ) {
               l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0005050080210000LL;
            } else if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 2 ) {
               l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0005550000210000LL;
            } else if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 1 ) {
               l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0C00000001210000LL;
            } else {
               l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = 0x0000000000000000LL;
            }
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_mss_freq_mask; 
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_mss_volt_mask; 
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_rcd_ibt_mask; 
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] & l_rcd_mirror_mode_mask; 
            if ( l_mss_freq <= 933 ) {         // 800Mbps
               l_mss_freq_mask = 0x0000000000000000LL;
            } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
               l_mss_freq_mask = 0x0000000000100000LL;
            } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
               l_mss_freq_mask = 0x0000000000200000LL;
            } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
               l_mss_freq_mask = 0x0000000000300000LL;
            } else {                           // 1866Mbps
               FAPI_ERR("Invalid RDIMM ATTR_MSS_FREQ = %d on %s!", l_mss_freq, i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
            if ( l_mss_volt >= 1420 ) {        // 1.5V
               l_mss_volt_mask = 0x0000000000000000LL;
            } else if ( l_mss_volt >= 1270 ) { // 1.35V
               l_mss_volt_mask = 0x0000000000010000LL;
            } else {                           // 1.2V 
               FAPI_ERR("Invalid RDIMM ATTR_MSS_VOLT = %d on %s!", l_mss_volt, i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            } 
            if ( l_attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_OFF ) {
               l_rcd_ibt_mask = 0x0000000070000000LL;
            } else if ( l_attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_100 ) {
               l_rcd_ibt_mask = 0x0000000000000000LL;
            } else if ( l_attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_150 ) {
               l_rcd_ibt_mask = 0x0040000000000000LL;
            } else if ( l_attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_200 ) {
               l_rcd_ibt_mask = 0x0000000020000000LL;
            } else if ( l_attr_eff_dimm_rcd_ibt[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_IBT_IBT_300 ) {
               l_rcd_ibt_mask = 0x0000000040000000LL;
            } else {
               FAPI_ERR("Invalid DIMM_RCD_IBT on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
            if ( l_attr_eff_dimm_rcd_mirror_mode[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_OFF ) {
               l_rcd_mirror_mode_mask = 0x0000000000000000LL;
            } else if ( l_attr_eff_dimm_rcd_mirror_mode[l_port][l_dimm] == fapi::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_IBT_BACK_ON ) {
               l_rcd_mirror_mode_mask = 0x0000000080000000LL;
            } else {
               FAPI_ERR("Invalid DIMM_RCD_MIRROR_MODE on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_mss_freq_mask; 
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_mss_volt_mask; 
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_rcd_ibt_mask; 
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] = l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] | l_rcd_mirror_mode_mask; 
         }
      }
   }


   // PR_VALUE_U8ARRAY[PORT_SIZE][PR_TYPE_SIZE][TOPO_SIZE]
   uint8_t l_attr_eff_cen_phase_rot[PR_TYPE_SIZE][PORT_SIZE];
   uint8_t l_topo_index = 0;
   if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
      if ( l_target_mba_pos == 0 ) {
         if ( l_mss_freq <= 933 ) {         // 800Mbps
            l_topo_index = 0;
         } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
            l_topo_index = 1;
         } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
            l_topo_index = 1;
         } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
            l_topo_index = 2;
         } else {                           // 1866Mbps
            l_topo_index = 2;
         }
      } else if ( l_target_mba_pos == 1 ) {
         if ( l_mss_freq <= 933 ) {         // 800Mbps
            l_topo_index = 0;
         } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
            l_topo_index = 9;
         } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
            l_topo_index = 9;
         } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
            l_topo_index = 10;
         } else {                           // 1866Mbps
            l_topo_index = 10;
         }
      } else {
         FAPI_ERR("Invalid MBA on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
   } else {
      if ( l_target_mba_pos == 0 ) {
         if ( l_num_ranks_per_dimm_u8array[0][0] == 4 ) {
            l_topo_index = 8;
         } else if ( l_num_ranks_per_dimm_u8array[0][0] == 2 ) {
            if ( l_mss_freq <= 933 ) {         // 800Mbps
               l_topo_index = 0;
            } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
               l_topo_index = 4;
            } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
               l_topo_index = 4;
            } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
               l_topo_index = 5;
            } else {                           // 1866Mbps
               l_topo_index = 5;
            }
         } else if ( l_num_ranks_per_dimm_u8array[0][0] == 1 ) {
            l_topo_index = 3;
         } else {
            l_topo_index = 0;
         }
      } else if ( l_target_mba_pos == 1 ) {
         if ( l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE ) {
            if ( l_num_ranks_per_dimm_u8array[0][0] == 4 ) {
               l_topo_index = 17;
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 2 ) {
               if ( l_mss_freq <= 933 ) {         // 800Mbps
                  l_topo_index = 0;
               } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
                  l_topo_index = 13;
               } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
                  l_topo_index = 13;
               } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
                  l_topo_index = 14;
               } else {                           // 1866Mbps
                  l_topo_index = 14;
               }
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 1 ) {
               if ( l_mss_freq <= 933 ) {         // 800Mbps
                  l_topo_index = 0;
               } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
                  l_topo_index = 11;
               } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
                  l_topo_index = 11;
               } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
                  l_topo_index = 12;
               } else {                           // 1866Mbps
                  l_topo_index = 12;
               }
            } else {
               l_topo_index = 0;
            }
         } else if ( l_num_drops_per_port == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL ) {
            if ( l_num_ranks_per_dimm_u8array[0][0] == 4 ) {
               l_topo_index = 24;
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 2 ) {
               if ( l_mss_freq <= 933 ) {         // 800Mbps
                  l_topo_index = 0;
               } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
                  l_topo_index = 20;
               } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
                  l_topo_index = 20;
               } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
                  l_topo_index = 21;
               } else {                           // 1866Mbps
                  l_topo_index = 21;
               }
            } else if ( l_num_ranks_per_dimm_u8array[0][0] == 1 ) {
               if ( l_mss_freq <= 933 ) {         // 800Mbps
                  l_topo_index = 0;
               } else if ( l_mss_freq <= 1200 ) { // 1066Mbps
                  l_topo_index = 18;
               } else if ( l_mss_freq <= 1466 ) { // 1333Mbps
                  l_topo_index = 18;
               } else if ( l_mss_freq <= 1733 ) { // 1600Mbps
                  l_topo_index = 19;
               } else {                           // 1866Mbps
                  l_topo_index = 19;
               }
            } else {
               l_topo_index = 0;
            }
         } else {
            l_topo_index = 0;
         }
      } else {
         FAPI_ERR("Invalid MBA on %s!", i_target_mba.toEcmdString());
         FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
      }
   }
   for( int l_port = 0; l_port < PORT_SIZE; l_port += 1 ) {
      for( int l_pr_type_index = 0; l_pr_type_index < PR_TYPE_SIZE; l_pr_type_index += 1 ) {
         l_attr_eff_cen_phase_rot[l_pr_type_index][l_port] = PR_VALUE_U8ARRAY[l_port][l_pr_type_index][l_topo_index];
      }
   }


   // Set attributes
   rc = FAPI_ATTR_SET(ATTR_MSS_CAL_STEP_ENABLE, &i_target_mba, l_attr_mss_cal_step_enable); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_CNTL_WORD_0_15, &i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_IBT, &i_target_mba, l_attr_eff_dimm_rcd_ibt); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RCD_MIRROR_MODE, &i_target_mba, l_attr_eff_dimm_rcd_mirror_mode); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, l_attr_eff_cen_rd_vref); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, l_attr_eff_dram_wr_vref); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, l_attr_eff_cen_rcv_imp_dq_dqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, l_attr_eff_cen_drv_imp_dq_dqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CNTL, &i_target_mba, l_attr_eff_cen_drv_imp_cntl); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_ADDR, &i_target_mba, l_attr_eff_cen_drv_imp_addr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CLK, &i_target_mba, l_attr_eff_cen_drv_imp_clk); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_SPCKE, &i_target_mba, l_attr_eff_cen_drv_imp_spcke); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, l_attr_eff_cen_slew_rate_dq_dqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CNTL, &i_target_mba, l_attr_eff_cen_slew_rate_cntl); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_ADDR, &i_target_mba, l_attr_eff_cen_slew_rate_addr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CLK, &i_target_mba, l_attr_eff_cen_slew_rate_clk); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_SPCKE, &i_target_mba, l_attr_eff_cen_slew_rate_spcke); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RON, &i_target_mba, l_attr_eff_dram_ron); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RTT_NOM, &i_target_mba, l_attr_eff_dram_rtt_nom); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RTT_WR, &i_target_mba, l_attr_eff_dram_rtt_wr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_ODT_RD, &i_target_mba, l_attr_eff_odt_rd); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_ODT_WR, &i_target_mba, l_attr_eff_odt_wr); if(rc) return rc;

   if(l_attr_is_simulation || 1) {
     FAPI_INF("In Sim Detected %s on %s value is %d", PROCEDURE_NAME, i_target_mba.toEcmdString(), l_attr_is_simulation);

     for(int i=0;i<2;i++) {
       l_attr_eff_cen_phase_rot[0][i]=0;
       l_attr_eff_cen_phase_rot[1][i]=0;
       l_attr_eff_cen_phase_rot[2][i]=0;
       l_attr_eff_cen_phase_rot[3][i]=0;
       l_attr_eff_cen_phase_rot[4][i]=0;
       l_attr_eff_cen_phase_rot[5][i]=0;
       l_attr_eff_cen_phase_rot[6][i]=0;
       l_attr_eff_cen_phase_rot[7][i]=0;
       l_attr_eff_cen_phase_rot[8][i]=0;
       l_attr_eff_cen_phase_rot[9][i]=0;
       l_attr_eff_cen_phase_rot[10][i]=0;
       l_attr_eff_cen_phase_rot[11][i]=0;
       l_attr_eff_cen_phase_rot[12][i]=0;
       l_attr_eff_cen_phase_rot[13][i]=0;
       l_attr_eff_cen_phase_rot[14][i]=0;
       l_attr_eff_cen_phase_rot[15][i]=0;
       l_attr_eff_cen_phase_rot[16][i]=0;
       l_attr_eff_cen_phase_rot[17][i]=0;
       l_attr_eff_cen_phase_rot[18][i]=0;
       l_attr_eff_cen_phase_rot[19][i]=0;
       l_attr_eff_cen_phase_rot[20][i]=0;
       l_attr_eff_cen_phase_rot[21][i]=0;
       l_attr_eff_cen_phase_rot[22][i]=0;
       l_attr_eff_cen_phase_rot[23][i]=0;
       l_attr_eff_cen_phase_rot[24][i]=0;
       l_attr_eff_cen_phase_rot[25][i]=0;
       l_attr_eff_cen_phase_rot[26][i]=0;
       l_attr_eff_cen_phase_rot[27][i]=0;
       l_attr_eff_cen_phase_rot[28][i]=0;
       l_attr_eff_cen_phase_rot[29][i]=0;
       l_attr_eff_cen_phase_rot[30][i]=0;
       l_attr_eff_cen_phase_rot[31][i]=0;
       l_attr_eff_cen_phase_rot[32][i]=0;
       l_attr_eff_cen_phase_rot[33][i]=0;
       l_attr_eff_cen_phase_rot[34][i]=0;
       l_attr_eff_cen_phase_rot[35][i]=0;
       l_attr_eff_cen_phase_rot[36][i]=0;
       l_attr_eff_cen_phase_rot[37][i]=0;
       l_attr_eff_cen_phase_rot[38][i]=0;
       l_attr_eff_cen_phase_rot[39][i]=0;
       l_attr_eff_cen_phase_rot[40][i]=0;
       l_attr_eff_cen_phase_rot[41][i]=0;
       l_attr_eff_cen_phase_rot[42][i]=0;
       l_attr_eff_cen_phase_rot[43][i]=0;
       l_attr_eff_cen_phase_rot[44][i]=0;
       l_attr_eff_cen_phase_rot[45][i]=0;
       l_attr_eff_cen_phase_rot[46][i]=0;
       l_attr_eff_cen_phase_rot[47][i]=0;
     }
   }


   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0, &i_target_mba, l_attr_eff_cen_phase_rot[0]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1, &i_target_mba, l_attr_eff_cen_phase_rot[1]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0, &i_target_mba, l_attr_eff_cen_phase_rot[2]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1, &i_target_mba, l_attr_eff_cen_phase_rot[3]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0, &i_target_mba, l_attr_eff_cen_phase_rot[4]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1, &i_target_mba, l_attr_eff_cen_phase_rot[5]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2, &i_target_mba, l_attr_eff_cen_phase_rot[6]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3, &i_target_mba, l_attr_eff_cen_phase_rot[7]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4, &i_target_mba, l_attr_eff_cen_phase_rot[8]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5, &i_target_mba, l_attr_eff_cen_phase_rot[9]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6, &i_target_mba, l_attr_eff_cen_phase_rot[10]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7, &i_target_mba, l_attr_eff_cen_phase_rot[11]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8, &i_target_mba, l_attr_eff_cen_phase_rot[12]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9, &i_target_mba, l_attr_eff_cen_phase_rot[13]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10, &i_target_mba, l_attr_eff_cen_phase_rot[14]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11, &i_target_mba, l_attr_eff_cen_phase_rot[15]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12, &i_target_mba, l_attr_eff_cen_phase_rot[16]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13, &i_target_mba, l_attr_eff_cen_phase_rot[17]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14, &i_target_mba, l_attr_eff_cen_phase_rot[18]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15, &i_target_mba, l_attr_eff_cen_phase_rot[19]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0, &i_target_mba, l_attr_eff_cen_phase_rot[20]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1, &i_target_mba, l_attr_eff_cen_phase_rot[21]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2, &i_target_mba, l_attr_eff_cen_phase_rot[22]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN, &i_target_mba, l_attr_eff_cen_phase_rot[23]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN, &i_target_mba, l_attr_eff_cen_phase_rot[24]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN, &i_target_mba, l_attr_eff_cen_phase_rot[25]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_PAR, &i_target_mba, l_attr_eff_cen_phase_rot[26]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M_ACTN, &i_target_mba, l_attr_eff_cen_phase_rot[27]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0, &i_target_mba, l_attr_eff_cen_phase_rot[28]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1, &i_target_mba, l_attr_eff_cen_phase_rot[29]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2, &i_target_mba, l_attr_eff_cen_phase_rot[30]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3, &i_target_mba, l_attr_eff_cen_phase_rot[31]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0, &i_target_mba, l_attr_eff_cen_phase_rot[32]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1, &i_target_mba, l_attr_eff_cen_phase_rot[33]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2, &i_target_mba, l_attr_eff_cen_phase_rot[34]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3, &i_target_mba, l_attr_eff_cen_phase_rot[35]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0, &i_target_mba, l_attr_eff_cen_phase_rot[36]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1, &i_target_mba, l_attr_eff_cen_phase_rot[37]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0, &i_target_mba, l_attr_eff_cen_phase_rot[38]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1, &i_target_mba, l_attr_eff_cen_phase_rot[39]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2, &i_target_mba, l_attr_eff_cen_phase_rot[40]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3, &i_target_mba, l_attr_eff_cen_phase_rot[41]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0, &i_target_mba, l_attr_eff_cen_phase_rot[42]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1, &i_target_mba, l_attr_eff_cen_phase_rot[43]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2, &i_target_mba, l_attr_eff_cen_phase_rot[44]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3, &i_target_mba, l_attr_eff_cen_phase_rot[45]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0, &i_target_mba, l_attr_eff_cen_phase_rot[46]); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1, &i_target_mba, l_attr_eff_cen_phase_rot[47]); if(rc) return rc;

   FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
   return rc;
}



} // extern "C"
