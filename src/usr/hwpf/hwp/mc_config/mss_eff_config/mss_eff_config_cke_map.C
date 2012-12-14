/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_config_cke_map.C $ */
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
// $Id: mss_eff_config_cke_map.C,v 1.3 2012/11/16 14:39:15 asaetow Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_config_cke_map.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_config_cke_map
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Anuwat Saetow     Email: asaetow@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// This procedure takes in attributes and determines proper cke map.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.4   |          |         |
//   1.3   | asaetow  |14-NOV-12| Added ATTR_EFF_SPCKE_MAP. 
//   1.2   | asaetow  |13-NOV-12| Added FAPI_ERR for else "Undefined IBM_TYPE". 
//         |          |         | Removed outter NUM_DROPS_PER_PORT check.
//   1.1   | asaetow  |07-NOV-12| First Draft.



//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi.H>



extern "C" {



//----------------------------------------------------------------------
// ENUMs and CONSTs
//----------------------------------------------------------------------

// Define attribute array size
const uint8_t PORT_SIZE = 2;
const uint8_t DIMM_SIZE = 2;
const uint8_t RANK_SIZE = 4;
const uint8_t IBM_TYPE_SIZE = 27;

const uint8_t l_cke_map_u8array[IBM_TYPE_SIZE][DIMM_SIZE][RANK_SIZE] = {
   // UNDEFINED = 0, TYPE_1A = 1, TYPE_1B = 2, TYPE_1C = 3, TYPE_1D = 4, TYPE_2A = 5, TYPE_2B = 6, TYPE_2C = 7, TYPE_3A = 8, TYPE_3B = 9, TYPE_3C = 10, TYPE_4A = 11, TYPE_4B = 12, TYPE_4C = 13, TYPE_5A = 14, TYPE_5B = 15, TYPE_5C = 16, TYPE_5D = 17, TYPE_6A = 18, TYPE_6B = 19, TYPE_6C = 20, TYPE_7A = 21, TYPE_7B = 22, TYPE_7C = 23, TYPE_8A = 24, TYPE_8B = 25, TYPE_8C = 26
   //        DIMM0          ,          DIMM1
   //   0     1     2     3 ,     0     1     2     3
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // UNDEFINED 
   {{0x80, 0x00, 0x00, 0x00}, {0x08, 0x00, 0x00, 0x00}},  // TYPE_1A
   {{0x80, 0x40, 0x00, 0x00}, {0x08, 0x04, 0x00, 0x00}},  // TYPE_1B
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_1C <-- UNDEFINED
   {{0x80, 0x40, 0x80, 0x40}, {0x08, 0x04, 0x08, 0x04}},  // TYPE_1D
   {{0x80, 0x00, 0x00, 0x00}, {0x08, 0x00, 0x00, 0x00}},  // TYPE_2A
   {{0x80, 0x00, 0x00, 0x00}, {0x08, 0x00, 0x00, 0x00}},  // TYPE_2B
   {{0x80, 0x00, 0x00, 0x00}, {0x08, 0x00, 0x00, 0x00}},  // TYPE_2C
   {{0x80, 0x40, 0x00, 0x00}, {0x08, 0x04, 0x00, 0x00}},  // TYPE_3A
   {{0x80, 0x40, 0x00, 0x00}, {0x08, 0x04, 0x00, 0x00}},  // TYPE_3B
   {{0x80, 0x40, 0x00, 0x00}, {0x08, 0x04, 0x00, 0x00}},  // TYPE_3C
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_4A <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_4B <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_4C <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_5A <-- UNDEFINED
   {{0x80, 0x40, 0x00, 0x00}, {0x08, 0x04, 0x00, 0x00}},  // TYPE_5B
   {{0x80, 0x40, 0x80, 0x40}, {0x08, 0x04, 0x08, 0x04}},  // TYPE_5C
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_5D <-- NOT YET SUPPORTED for LRDIMM DDR3
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_6A <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_6B <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_6C <-- UNDEFINED
   {{0x80, 0x40, 0x00, 0x00}, {0x08, 0x04, 0x00, 0x00}},  // TYPE_7A
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_7B <-- NOT YET SUPPORTED for LRDIMM DDR3
   {{0x80, 0x40, 0x00, 0x00}, {0x08, 0x04, 0x00, 0x00}},  // TYPE_7C
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_8A <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_8B <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}}}; // TYPE_8C <-- UNDEFINED

const uint8_t l_spcke_map_u8array[IBM_TYPE_SIZE][DIMM_SIZE][RANK_SIZE] = {
   //        DIMM0          ,          DIMM1
   //   0     1     2     3 ,     0     1     2     3
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // UNDEFINED 
   {{0x20, 0x00, 0x00, 0x00}, {0x02, 0x00, 0x00, 0x00}},  // TYPE_1A
   {{0x20, 0x10, 0x00, 0x00}, {0x02, 0x01, 0x00, 0x00}},  // TYPE_1B
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_1C <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_1D <-- NOT SUPPORTED for CDIMM
   {{0x20, 0x00, 0x00, 0x00}, {0x02, 0x00, 0x00, 0x00}},  // TYPE_2A
   {{0x20, 0x00, 0x00, 0x00}, {0x02, 0x00, 0x00, 0x00}},  // TYPE_2B
   {{0x20, 0x00, 0x00, 0x00}, {0x02, 0x00, 0x00, 0x00}},  // TYPE_2C
   {{0x20, 0x10, 0x00, 0x00}, {0x02, 0x01, 0x00, 0x00}},  // TYPE_3A
   {{0x20, 0x10, 0x00, 0x00}, {0x02, 0x01, 0x00, 0x00}},  // TYPE_3B
   {{0x20, 0x10, 0x00, 0x00}, {0x02, 0x01, 0x00, 0x00}},  // TYPE_3C
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_4A <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_4B <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_4C <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_5A <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_5B <-- NOT SUPPORTED for CDIMM
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_5C <-- NOT SUPPORTED for CDIMM
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_5D <-- NOT SUPPORTED for CDIMM, NOT YET SUPPORTED for LRDIMM DDR3
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_6A <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_6B <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_6C <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_7A <-- NOT SUPPORTED for CDIMM
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_7B <-- NOT SUPPORTED for CDIMM, NOT YET SUPPORTED for LRDIMM DDR3
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_7C <-- NOT SUPPORTED for CDIMM
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_8A <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}},  // TYPE_8B <-- UNDEFINED
   {{0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00}}}; // TYPE_8C <-- UNDEFINED



//******************************************************************************
//* name=mss_eff_config_cke_map, param=i_target_mba, return=ReturnCode
//******************************************************************************
fapi::ReturnCode mss_eff_config_cke_map(const fapi::Target i_target_mba) {
   fapi::ReturnCode rc = fapi::FAPI_RC_SUCCESS;
   const char * const PROCEDURE_NAME = "mss_eff_config_cke_map";
   FAPI_INF("*** Running %s on %s ... ***", PROCEDURE_NAME, i_target_mba.toEcmdString());


   // Define attribute array size


   // Fetch dependent attributes
   uint8_t l_num_ranks_per_dimm_u8array[PORT_SIZE][DIMM_SIZE];
   // ATTR_EFF_DRAM_GEN: EMPTY = 0, DDR3 = 1, DDR4 = 2, 
   uint8_t l_dram_gen_u8;
   // ATTR_EFF_DIMM_TYPE: CDIMM = 0, RDIMM = 1, UDIMM = 2, LRDIMM = 3,
   uint8_t l_dimm_type_u8;
   uint8_t l_num_drops_per_port_u8;
   uint8_t l_ibm_type_u8array[PORT_SIZE][DIMM_SIZE];
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm_u8array); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target_mba, l_dram_gen_u8); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &i_target_mba, l_dimm_type_u8); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target_mba, l_num_drops_per_port_u8); if(rc) return rc;
   rc = FAPI_ATTR_GET(ATTR_EFF_IBM_TYPE, &i_target_mba, l_ibm_type_u8array); if(rc) return rc;


   // Define local attribute variables
   uint8_t l_attr_eff_cke_map[PORT_SIZE][DIMM_SIZE][RANK_SIZE];
   uint8_t l_attr_eff_spcke_map[PORT_SIZE][DIMM_SIZE][RANK_SIZE];


   for (uint8_t l_cur_port = 0; l_cur_port < PORT_SIZE; l_cur_port += 1) {
      for (uint8_t l_cur_dimm = 0; l_cur_dimm < DIMM_SIZE; l_cur_dimm += 1) {
         uint8_t l_ibm_type_index = 0;
         // UNDEFINED = 0, TYPE_1A = 1, TYPE_1B = 2, TYPE_1C = 3, TYPE_1D = 4, TYPE_2A = 5, TYPE_2B = 6, TYPE_2C = 7, TYPE_3A = 8, TYPE_3B = 9, TYPE_3C = 10, TYPE_4A = 11, TYPE_4B = 12, TYPE_4C = 13, TYPE_5A = 14, TYPE_5B = 15, TYPE_5C = 16, TYPE_5D = 17, TYPE_6A = 18, TYPE_6B = 19, TYPE_6C = 20, TYPE_7A = 21, TYPE_7B = 22, TYPE_7C = 23, TYPE_8A = 24, TYPE_8B = 25, TYPE_8C = 26
         if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_UNDEFINED ) {
            l_ibm_type_index = 0;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1A ) {
            l_ibm_type_index = 1;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1B ) {
            l_ibm_type_index = 2;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1C ) {
            l_ibm_type_index = 3;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_1D ) {
            l_ibm_type_index = 4;
            if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
               FAPI_ERR("Invalid IBM_TYPE for CDIMM on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_2A ) {
            l_ibm_type_index = 5;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_2B ) {
            l_ibm_type_index = 6;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_2C ) {
            l_ibm_type_index = 7;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_3A ) {
            l_ibm_type_index = 8;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_3B ) {
            l_ibm_type_index = 9;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_3C ) {
            l_ibm_type_index = 10;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_4A ) {
            l_ibm_type_index = 11;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_4B ) {
            l_ibm_type_index = 12;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_4C ) {
            l_ibm_type_index = 13;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5A ) {
            l_ibm_type_index = 14;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5B ) {
            l_ibm_type_index = 15;
            if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
               FAPI_ERR("Invalid IBM_TYPE for CDIMM on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5C ) {
            l_ibm_type_index = 16;
            if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
               FAPI_ERR("Invalid IBM_TYPE for CDIMM on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_5D ) {
            l_ibm_type_index = 17;
            if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
               FAPI_ERR("Invalid IBM_TYPE for CDIMM on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
            FAPI_ERR("Currently unsupported IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_6A ) {
            l_ibm_type_index = 18;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_6B ) {
            l_ibm_type_index = 19;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_6C ) {
            l_ibm_type_index = 20;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_7A ) {
            l_ibm_type_index = 21;
            if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
               FAPI_ERR("Invalid IBM_TYPE for CDIMM on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_7B ) {
            l_ibm_type_index = 22;
            if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
               FAPI_ERR("Invalid IBM_TYPE for CDIMM on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
            FAPI_ERR("Currently unsupported IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_7C ) {
            l_ibm_type_index = 23;
            if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
               FAPI_ERR("Invalid IBM_TYPE for CDIMM on %s!", i_target_mba.toEcmdString());
               FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
            }
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_8A ) {
            l_ibm_type_index = 24;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_8B ) {
            l_ibm_type_index = 25;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else if ( l_ibm_type_u8array[l_cur_port][l_cur_dimm] == fapi::ENUM_ATTR_EFF_IBM_TYPE_TYPE_8C ) {
            l_ibm_type_index = 26;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         } else {
            l_ibm_type_index = 0;
            FAPI_ERR("Undefined IBM_TYPE on %s!", i_target_mba.toEcmdString());
            FAPI_SET_HWP_ERROR(rc, RC_MSS_PLACE_HOLDER_ERROR); return rc;
         }

         for (uint8_t l_cur_rank = 0; l_cur_rank < RANK_SIZE; l_cur_rank += 1) {
            if ( l_num_drops_per_port_u8 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_SINGLE ) {
               if ( l_cur_dimm == 0 ) {
                  l_attr_eff_cke_map[l_cur_port][l_cur_dimm][l_cur_rank] = l_cke_map_u8array[l_ibm_type_index][l_cur_dimm][l_cur_rank];
                  if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
                     l_attr_eff_spcke_map[l_cur_port][l_cur_dimm][l_cur_rank] = l_spcke_map_u8array[l_ibm_type_index][l_cur_dimm][l_cur_rank];
                     FAPI_INF("WARNING: NUM_DROPS_PER_PORT = SINGLE for a CDIMM on %s!", i_target_mba.toEcmdString());
                  } else {
                     l_attr_eff_spcke_map[l_cur_port][l_cur_dimm][l_cur_rank] = 0;
                  }
               } else {
                  l_attr_eff_cke_map[l_cur_port][l_cur_dimm][l_cur_rank] = 0;
                  l_attr_eff_spcke_map[l_cur_port][l_cur_dimm][l_cur_rank] = 0;
               }
            } else if ( l_num_drops_per_port_u8 == fapi::ENUM_ATTR_EFF_NUM_DROPS_PER_PORT_DUAL ) {
               l_attr_eff_cke_map[l_cur_port][l_cur_dimm][l_cur_rank] = l_cke_map_u8array[l_ibm_type_index][l_cur_dimm][l_cur_rank];
               if ( l_dimm_type_u8 == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM ) {
                  l_attr_eff_spcke_map[l_cur_port][l_cur_dimm][l_cur_rank] = l_spcke_map_u8array[l_ibm_type_index][l_cur_dimm][l_cur_rank];
               } else {
                  l_attr_eff_spcke_map[l_cur_port][l_cur_dimm][l_cur_rank] = 0;
               }
            } else {
               l_attr_eff_cke_map[l_cur_port][l_cur_dimm][l_cur_rank] = 0;
               l_attr_eff_spcke_map[l_cur_port][l_cur_dimm][l_cur_rank] = 0;
            }
         }
      }
   }


   // Set attributes
   rc = FAPI_ATTR_SET(ATTR_EFF_CKE_MAP, &i_target_mba, l_attr_eff_cke_map); if(rc) return rc;
   rc = FAPI_ATTR_SET(ATTR_EFF_SPCKE_MAP, &i_target_mba, l_attr_eff_spcke_map); if(rc) return rc;

   FAPI_INF("%s on %s COMPLETE", PROCEDURE_NAME, i_target_mba.toEcmdString());
   return rc;
}



} // extern "C"
