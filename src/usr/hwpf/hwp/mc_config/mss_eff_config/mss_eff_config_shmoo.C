/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_shmoo.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: mss_eff_config_shmoo.C,v 1.2 2013/03/27 15:15:07 lapietra Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_shmoo.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_shmoo
// *! DESCRIPTION : Additional attributes for MCBIST 
// *! OWNER NAME  : Saurabh Chadha    Email: sauchadh@in.ibm.com
// *! BACKUP NAME :                   Email: 
// *! ADDITIONAL COMMENTS :
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | sauchadh |26-Feb-13| Added MCBIST related attributes
//   1.2   | sauchadh |13-Mar-13| Added Schmoo related attributes from mss_eff_config.C 


//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>


extern "C" {



//******************************************************************************
//* name=mss_eff_config_shmoo, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_shmoo(const fapi::Target i_target_mba) {
   fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
   const char * const PROCEDURE_NAME = "mss_eff_config_shmoo";
   FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());

   uint32_t datapattern=8;
   uint32_t testtype=1;
   uint8_t  addr_modes=0;
   uint8_t  rank=0;
   uint64_t start_addr=0;
   uint64_t end_addr=0;
   uint8_t error_capture=0;
   uint64_t max_timeout=0;
   uint8_t print_port=0;
   uint8_t stop_on_error=0;
   uint32_t data_seed=0;
   uint8_t addr_inter=0;
   uint8_t addr_num_rows=0;
   uint8_t addr_num_cols=0;
   uint8_t addr_rank=0;
   uint8_t addr_bank=0;
   uint8_t addr_slave_rank_on=0;
   uint64_t adr_str_map=0;
   uint8_t addr_rand=0;
   uint8_t shmoo_mode=0;
   uint8_t shmoo_addr_mode=3;
   uint8_t shmoo_param_valid=0;
   uint8_t shmoo_test_valid=0;
   uint8_t wr_eye_min_margin=0x46;
   uint8_t rd_eye_min_margin=0x46;
   uint8_t dqs_clk_min_margin=0x8c;
   uint8_t rd_gate_min_margin=0x64;
   uint8_t adr_cmd_min_margin=0x8c;
   uint32_t cen_rd_vref_shmoo[2];
   cen_rd_vref_shmoo[0]=0x00000000;
   cen_rd_vref_shmoo[1]=0x00000000;
   uint32_t dram_wr_vref_schmoo[2];
   dram_wr_vref_schmoo[0]=0x00000000;
   dram_wr_vref_schmoo[1]=0x00000000;
   uint32_t cen_rcv_imp_dq_dqs_schmoo[2];
   cen_rcv_imp_dq_dqs_schmoo[0]=0x00000000;
   cen_rcv_imp_dq_dqs_schmoo[1]=0x00000000;
   uint32_t cen_drv_imp_dq_dqs_schmoo[2];
   cen_drv_imp_dq_dqs_schmoo[0]=0x00000000;
   cen_drv_imp_dq_dqs_schmoo[1]=0x00000000;
   uint8_t cen_drv_imp_cntl_schmoo[2];
   cen_drv_imp_cntl_schmoo[0]=0x00;
   cen_drv_imp_cntl_schmoo[1]=0x00;
   uint8_t cen_drv_imp_clk_schmoo[2];
   cen_drv_imp_clk_schmoo[0]=0x00;
   cen_drv_imp_clk_schmoo[1]=0x00;
   uint8_t cen_drv_imp_spcke_schmoo[2];
   cen_drv_imp_spcke_schmoo[0]=0x00;
   cen_drv_imp_spcke_schmoo[1]=0x00;
   uint8_t cen_slew_rate_dq_dqs_schmoo[2];
   cen_slew_rate_dq_dqs_schmoo[0]=0x00;
   cen_slew_rate_dq_dqs_schmoo[1]=0x00;
   uint8_t cen_slew_rate_cntl_schmoo[2];
   cen_slew_rate_cntl_schmoo[0]=0x00;
   cen_slew_rate_cntl_schmoo[1]=0x00;
   uint8_t cen_slew_rate_addr_schmoo[2];
   cen_slew_rate_addr_schmoo[0]=0x00;
   cen_slew_rate_addr_schmoo[1]=0x00;
   uint8_t cen_slew_rate_clk_schmoo[2];
   cen_slew_rate_clk_schmoo[0]=0x00;
   cen_slew_rate_clk_schmoo[1]=0x00;
   uint8_t cen_slew_rate_spcke_schmoo[2];
   cen_slew_rate_spcke_schmoo[0]=0x00;
   cen_slew_rate_spcke_schmoo[1]=0x00;
   
   rc = FAPI_ATTR_SET(ATTR_MCBIST_PATTERN, &i_target_mba, datapattern); if(rc) return rc; 
   rc = FAPI_ATTR_SET(ATTR_MCBIST_TEST_TYPE, &i_target_mba, testtype); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_MODES, &i_target_mba, addr_modes); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_RANK, &i_target_mba, rank); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_START_ADDR, &i_target_mba, start_addr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_END_ADDR, &i_target_mba, end_addr); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ERROR_CAPTURE, &i_target_mba, error_capture); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_MAX_TIMEOUT, &i_target_mba, max_timeout); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_PRINT_PORT, &i_target_mba, print_port); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_STOP_ON_ERROR, &i_target_mba, stop_on_error); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_DATA_SEED, &i_target_mba, data_seed); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_INTER, &i_target_mba, addr_inter); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_NUM_ROWS, &i_target_mba, addr_num_rows); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_NUM_COLS, &i_target_mba, addr_num_cols); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_RANK, &i_target_mba, addr_rank); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, addr_bank); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_SLAVE_RANK_ON, &i_target_mba, addr_slave_rank_on); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_STR_MAP, &i_target_mba, adr_str_map); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_RAND, &i_target_mba, addr_rand); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_MODE, &i_target_mba, shmoo_mode); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_ADDR_MODE, &i_target_mba, shmoo_addr_mode); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_PARAM_VALID, &i_target_mba, shmoo_param_valid); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target_mba, shmoo_test_valid); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_WR_EYE_MIN_MARGIN, &i_target_mba, wr_eye_min_margin); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_RD_EYE_MIN_MARGIN, &i_target_mba, rd_eye_min_margin); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_DQS_CLK_MIN_MARGIN, &i_target_mba, dqs_clk_min_margin); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_RD_GATE_MIN_MARGIN, &i_target_mba, rd_gate_min_margin); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SCHMOO_ADDR_CMD_MIN_MARGIN, &i_target_mba, adr_cmd_min_margin); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RD_VREF_SCHMOO, &i_target_mba, cen_rd_vref_shmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WR_VREF_SCHMOO, &i_target_mba, dram_wr_vref_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, &i_target_mba, cen_rcv_imp_dq_dqs_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, &i_target_mba, cen_drv_imp_dq_dqs_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CNTL_SCHMOO, &i_target_mba, cen_drv_imp_cntl_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_CLK_SCHMOO, &i_target_mba, cen_drv_imp_clk_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_SPCKE_SCHMOO, &i_target_mba, cen_drv_imp_spcke_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_DQ_DQS_SCHMOO, &i_target_mba, cen_slew_rate_dq_dqs_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CNTL_SCHMOO, &i_target_mba, cen_slew_rate_cntl_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_ADDR_SCHMOO, &i_target_mba, cen_slew_rate_addr_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_CLK_SCHMOO, &i_target_mba, cen_slew_rate_clk_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_SLEW_RATE_SPCKE_SCHMOO, &i_target_mba, cen_slew_rate_spcke_schmoo); if(rc) return rc;
       
   FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
   return rc;
}



} // extern "C"
