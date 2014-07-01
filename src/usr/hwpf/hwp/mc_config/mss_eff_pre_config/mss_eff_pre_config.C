/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_pre_config/mss_eff_pre_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: mss_eff_pre_config.C,v 1.1 2013/08/06 23:30:21 asaetow Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_pre_config.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_pre_config
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Michael Pardeik   Email: pardeik@us.ibm.com
// *! BACKUP NAME : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// This procedure puts in required attributes for mss_eff_config_thermal which are based on "worst case" config in case these attributes were not able to be setup by mss_eff_config.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.2   |          |         |
//   1.1   | asaetow  |02-AUG-13| First Draft.



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
//* name=mss_eff_pre_config, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_pre_config(const fapi::Target i_target_mba) {
   fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
   const char * const PROCEDURE_NAME = "mss_eff_pre_config";
   FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());

   
   const uint32_t MSS_EFF_EMPTY = 0;
   const uint32_t MSS_EFF_VALID = 255;
   const uint8_t PORT_SIZE = 2;
   const uint8_t DIMM_SIZE = 2;

   // Grab DIMM/SPD data.
   uint8_t cur_dimm_spd_valid_u8array[PORT_SIZE][DIMM_SIZE]; 
   uint8_t spd_custom[PORT_SIZE][DIMM_SIZE];
   for (uint8_t cur_port = 0; cur_port < PORT_SIZE; cur_port += 1) {
      for (uint8_t cur_dimm = 0; cur_dimm < DIMM_SIZE; cur_dimm += 1) {
         cur_dimm_spd_valid_u8array[cur_port][cur_dimm] = MSS_EFF_EMPTY;
         spd_custom[cur_port][cur_dimm] = 0;
      }
   }
   uint8_t cur_mba_port = 0;
   uint8_t cur_mba_dimm = 0;
   std::vector<fapi::Target> l_target_dimm_array;
   rc = fapiGetAssociatedDimms(i_target_mba, l_target_dimm_array); if(rc) return rc;
   for (uint8_t dimm_index = 0; dimm_index < l_target_dimm_array.size(); dimm_index += 1) {
      rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &l_target_dimm_array[dimm_index], cur_mba_port); if(rc) return rc;
      rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &l_target_dimm_array[dimm_index], cur_mba_dimm); if(rc) return rc;
      cur_dimm_spd_valid_u8array[cur_mba_port][cur_mba_dimm] = MSS_EFF_VALID;
      rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM, &l_target_dimm_array[dimm_index], spd_custom[cur_mba_port][cur_mba_dimm]); if(rc) return rc;
   }

   uint32_t eff_cen_rcv_imp_dq_dqs_schmoo[PORT_SIZE];
   uint32_t eff_cen_drv_imp_dq_dqs_schmoo[PORT_SIZE];
   uint8_t eff_dram_gen = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3;
   uint8_t eff_dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM;
   uint8_t eff_custom_dimm = fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES;
   uint8_t eff_dram_width = fapi::ENUM_ATTR_EFF_DRAM_WIDTH_X4;
   uint8_t eff_dram_tdqs = fapi::ENUM_ATTR_EFF_DRAM_TDQS_DISABLE;
   uint8_t eff_num_ranks_per_dimm[PORT_SIZE][DIMM_SIZE];
   uint8_t eff_num_master_ranks_per_dimm[PORT_SIZE][DIMM_SIZE];
   uint8_t eff_dimm_ranks_configed[PORT_SIZE][DIMM_SIZE]; 
   uint8_t eff_num_drops_per_port = fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE;

   if (cur_dimm_spd_valid_u8array[0][0] == MSS_EFF_VALID) {
      if (spd_custom[0][0] == fapi::ENUM_ATTR_SPD_CUSTOM_YES) {
         eff_custom_dimm = fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES;
      } else {
         eff_custom_dimm = fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_NO;
      }
   } else {
      FAPI_INF("WARNING: Plug rule violation at %s!", i_target_mba.toEcmdString());
      FAPI_INF("WARNING: Do NOT trust ATTR_EFF_CUSTOM_DIMM for %s!", i_target_mba.toEcmdString());
   }

   for (uint8_t cur_port = 0; cur_port < PORT_SIZE; cur_port += 1) {
      eff_cen_rcv_imp_dq_dqs_schmoo[cur_port] = 0;
      eff_cen_drv_imp_dq_dqs_schmoo[cur_port] = 0;
      for (uint8_t cur_dimm = 0; cur_dimm < DIMM_SIZE; cur_dimm += 1) {
         eff_num_ranks_per_dimm[cur_port][cur_dimm] = 8;
         eff_num_master_ranks_per_dimm[cur_port][cur_dimm] = 8;
         eff_dimm_ranks_configed[cur_port][cur_dimm] = 0xFF;
      }
   }

   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_RCV_IMP_DQ_DQS_SCHMOO, &i_target_mba, eff_cen_rcv_imp_dq_dqs_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CEN_DRV_IMP_DQ_DQS_SCHMOO, &i_target_mba, eff_cen_drv_imp_dq_dqs_schmoo); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_GEN, &i_target_mba, eff_dram_gen); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_TYPE, &i_target_mba, eff_dimm_type); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, eff_custom_dimm); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_WIDTH, &i_target_mba, eff_dram_width); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_TDQS, &i_target_mba, eff_dram_tdqs); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, eff_num_ranks_per_dimm); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target_mba, eff_num_master_ranks_per_dimm); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_RANKS_CONFIGED, &i_target_mba, eff_dimm_ranks_configed); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, eff_num_drops_per_port); if(rc) return rc;

   return rc;
}



} // extern "C"
