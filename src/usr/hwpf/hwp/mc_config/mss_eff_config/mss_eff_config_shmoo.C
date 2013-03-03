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
// $Id: mss_eff_config_shmoo.C,v 1.1 2013/02/26 12:38:20 lapietra Exp $
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
   
   FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
   return rc;
}



} // extern "C"
