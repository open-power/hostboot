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
// $Id: mss_eff_config_termination.C,v 1.2 2012/09/05 23:01:02 asaetow Exp $
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
//   1.3   |          |         |
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
// ENUMs
//----------------------------------------------------------------------



extern "C" {



//******************************************************************************
//* name=mss_eff_config_termination, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_termination(const fapi::Target i_target_mba) {
   fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
   const char * const PROCEDURE_NAME = "mss_eff_config_termination";
   FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());

   // Define attribute array size
   const uint8_t PORT_SIZE = 2;
   const uint8_t DIMM_SIZE = 2;
   const uint8_t RANK_SIZE = 4;

   // Define local attribute variables
   uint8_t my_attr_mss_cal_step_enable = 0xFF;
   uint8_t my_attr_eff_cen_drv_imp_cmd = 15;
   uint8_t my_attr_eff_cen_drv_imp_cntl = 15;
   uint8_t my_attr_eff_cen_drv_imp_dq_dqs = 24;
   uint8_t my_attr_eff_cen_rcv_imp_dq_dqs = 15;
   uint32_t my_attr_eff_cen_rd_vref = 50000;
   uint8_t my_attr_eff_cen_slew_rate_cmd = 0x0;
   uint8_t my_attr_eff_cen_slew_rate_cntl = 0x0;
   uint8_t my_attr_eff_cen_slew_rate_dq_dqs = 0x0;
   uint8_t my_attr_eff_dram_ron[PORT_SIZE][DIMM_SIZE];
      my_attr_eff_dram_ron[0][0] = 34;
      my_attr_eff_dram_ron[0][1] = 34;
      my_attr_eff_dram_ron[1][0] = 34; 
      my_attr_eff_dram_ron[1][1] = 34;
   uint8_t my_attr_eff_dram_rtt_nom[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      my_attr_eff_dram_rtt_nom[0][0][0] = 20;
      my_attr_eff_dram_rtt_nom[0][0][1] = 0;
      my_attr_eff_dram_rtt_nom[0][0][2] = 0;
      my_attr_eff_dram_rtt_nom[0][0][3] = 0;
      my_attr_eff_dram_rtt_nom[0][1][0] = 20;
      my_attr_eff_dram_rtt_nom[0][1][1] = 0;
      my_attr_eff_dram_rtt_nom[0][1][2] = 0;
      my_attr_eff_dram_rtt_nom[0][1][3] = 0;
      my_attr_eff_dram_rtt_nom[1][0][0] = 20;
      my_attr_eff_dram_rtt_nom[1][0][1] = 0;
      my_attr_eff_dram_rtt_nom[1][0][2] = 0;
      my_attr_eff_dram_rtt_nom[1][0][3] = 0;
      my_attr_eff_dram_rtt_nom[1][1][0] = 20;
      my_attr_eff_dram_rtt_nom[1][1][1] = 0;
      my_attr_eff_dram_rtt_nom[1][1][2] = 0;
      my_attr_eff_dram_rtt_nom[1][1][3] = 0;
   uint8_t my_attr_eff_dram_rtt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      my_attr_eff_dram_rtt_wr[0][0][0] = 60;
      my_attr_eff_dram_rtt_wr[0][0][1] = 60;
      my_attr_eff_dram_rtt_wr[0][0][2] = 0;
      my_attr_eff_dram_rtt_wr[0][0][3] = 0;
      my_attr_eff_dram_rtt_wr[0][1][0] = 60;
      my_attr_eff_dram_rtt_wr[0][1][1] = 60;
      my_attr_eff_dram_rtt_wr[0][1][2] = 0;
      my_attr_eff_dram_rtt_wr[0][1][3] = 0;
      my_attr_eff_dram_rtt_wr[1][0][0] = 60;
      my_attr_eff_dram_rtt_wr[1][0][1] = 60;
      my_attr_eff_dram_rtt_wr[1][0][2] = 0;
      my_attr_eff_dram_rtt_wr[1][0][3] = 0;
      my_attr_eff_dram_rtt_wr[1][1][0] = 60;
      my_attr_eff_dram_rtt_wr[1][1][1] = 60;
      my_attr_eff_dram_rtt_wr[1][1][2] = 0;
      my_attr_eff_dram_rtt_wr[1][1][3] = 0;
   uint32_t my_attr_eff_dram_wr_vref = 500;
   uint8_t my_attr_eff_odt_rd[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      my_attr_eff_odt_rd[0][0][0] = 0x0;
      my_attr_eff_odt_rd[0][0][1] = 0x0;
      my_attr_eff_odt_rd[0][0][2] = 0x0;
      my_attr_eff_odt_rd[0][0][3] = 0x0;
      my_attr_eff_odt_rd[0][1][0] = 0x0;
      my_attr_eff_odt_rd[0][1][1] = 0x0;
      my_attr_eff_odt_rd[0][1][2] = 0x0;
      my_attr_eff_odt_rd[0][1][3] = 0x0;
      my_attr_eff_odt_rd[1][0][0] = 0x0;
      my_attr_eff_odt_rd[1][0][1] = 0x0;
      my_attr_eff_odt_rd[1][0][2] = 0x0;
      my_attr_eff_odt_rd[1][0][3] = 0x0;
      my_attr_eff_odt_rd[1][1][0] = 0x0;
      my_attr_eff_odt_rd[1][1][1] = 0x0;
      my_attr_eff_odt_rd[1][1][2] = 0x0;
      my_attr_eff_odt_rd[1][1][3] = 0x0;
   uint8_t my_attr_eff_odt_wr[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
      my_attr_eff_odt_wr[0][0][0] = 0x0;
      my_attr_eff_odt_wr[0][0][1] = 0x0;
      my_attr_eff_odt_wr[0][0][2] = 0x0;
      my_attr_eff_odt_wr[0][0][3] = 0x0;
      my_attr_eff_odt_wr[0][1][0] = 0x0;
      my_attr_eff_odt_wr[0][1][1] = 0x0;
      my_attr_eff_odt_wr[0][1][2] = 0x0;
      my_attr_eff_odt_wr[0][1][3] = 0x0;
      my_attr_eff_odt_wr[1][0][0] = 0x0;
      my_attr_eff_odt_wr[1][0][1] = 0x0;
      my_attr_eff_odt_wr[1][0][2] = 0x0;
      my_attr_eff_odt_wr[1][0][3] = 0x0;
      my_attr_eff_odt_wr[1][1][0] = 0x0;
      my_attr_eff_odt_wr[1][1][1] = 0x0;
      my_attr_eff_odt_wr[1][1][2] = 0x0;
      my_attr_eff_odt_wr[1][1][3] = 0x0;

   // Set attributes
   rc = FAPI_ATTR_SET(ATTR_MSS_CAL_STEP_ENABLE, &i_target_mba, my_attr_mss_cal_step_enable); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CMD, &i_target_mba, my_attr_eff_cen_drv_imp_cmd); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CNTL, &i_target_mba, my_attr_eff_cen_drv_imp_cntl); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS, &i_target_mba, my_attr_eff_cen_drv_imp_dq_dqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS, &i_target_mba, my_attr_eff_cen_rcv_imp_dq_dqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF, &i_target_mba, my_attr_eff_cen_rd_vref); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CMD, &i_target_mba, my_attr_eff_cen_slew_rate_cmd); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CNTL, &i_target_mba, my_attr_eff_cen_slew_rate_cntl); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, &i_target_mba, my_attr_eff_cen_slew_rate_dq_dqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RON, &i_target_mba, my_attr_eff_dram_ron); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RTT_NOM, &i_target_mba, my_attr_eff_dram_rtt_nom); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_RTT_WR, &i_target_mba, my_attr_eff_dram_rtt_wr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF, &i_target_mba, my_attr_eff_dram_wr_vref); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_ODT_RD, &i_target_mba, my_attr_eff_odt_rd); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_ODT_WR, &i_target_mba, my_attr_eff_odt_wr); if(rc) return rc;

   FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
   return rc;
}



} // extern "C"
