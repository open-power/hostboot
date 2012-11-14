/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/mss_thermal_init/mss_thermal_init.C $ */
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
// $Id: mss_thermal_init.C,v 1.6 2012/11/28 15:22:20 joabhend Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_thermal_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_thermal_init
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Joab Henderson    Email: joabhend@us.ibm.com
// *! BACKUP NAME : Michael Pardeik   Email: pardeik@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// DESCRIPTION:
// The purpose of this procedure is to configure and start the OCC cache and Centaur thermal cache
//
// TODO:
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.6   | joabhend |28-NOV-12| Corrected procedure_name from char* to const char*
//   1.5   | joabhend |16-NOV-12| Updated code to reflect review output
//   1.4   | joabhend |02-NOV-12| Corrected scom call from SCAC_FIRMASK to SCAC_ADDRMAP
//   1.3   | joabhend |10-OCT-12| Added section for emergency throttle disable, removed FIR bit 33 handling
//   1.2   | gollub   |05-SEP-12| Calling mss_unmask_fetch_errors after mss_thermal_init_cloned
//   1.1   | joabhend |30-APR-12| First Draft



//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <mss_thermal_init.H>
#include <fapi.H>
#include <mss_unmask_errors.H>

extern "C" {

   using namespace fapi;


   // Procedures in this file
   fapi::ReturnCode mss_thermal_init(const fapi::Target & i_target);
   fapi::ReturnCode mss_thermal_init_cloned(const fapi::Target & i_target);
   
   
//******************************************************************************
//
//******************************************************************************
   
fapi::ReturnCode mss_thermal_init(const fapi::Target & i_target)
{
    // Target is centaur.mba
    
    fapi::ReturnCode l_rc;
    
    l_rc = mss_thermal_init_cloned(i_target);
    
	// If mss_unmask_fetch_errors gets it's own bad rc,
	// it will commit the passed in rc (if non-zero), and return it's own bad rc.
	// Else if mss_unmask_fetch_errors runs clean, 
	// it will just return the passed in rc.
	l_rc = mss_unmask_fetch_errors(i_target, l_rc);

	return l_rc;
}
   

//******************************************************************************
//
//******************************************************************************

   fapi::ReturnCode mss_thermal_init_cloned(const fapi::Target & i_target)
   {

      fapi::ReturnCode l_rc;
      uint32_t l_ecmd_rc = 0;

      const char *procedure_name = "mss_thermal_init";
      FAPI_INF("*** Running %s ***", procedure_name);

      // Constant declaration
      const uint8_t l_NUM_MBAS = 2;                                     // Number of MBAs per Centaur
      const uint8_t l_NUM_PORTS = 2;					// Number of ports per MBA
      const uint8_t l_NUM_DIMMS = 2;					// Number of dimms per MBA port

      const uint64_t SCAC_FIRMASK = 0x020115c3;
      const uint64_t SCAC_ADDRMAP = 0x020115cd;
      const uint64_t SCAC_CONFIG = 0x020115ce;
      const uint64_t SCAC_ENABLE = 0x020115cc;
      const uint64_t SCAC_I2CMCTRL = 0x020115d1;
      //const uint64_t SCAC_LFIR = 0x020115c0;
      const uint64_t SCAC_PIBTARGET = 0x020115d2;

      const uint64_t MBS_EMER_THROT = 0x0201142d;
      const uint64_t MBS_FIR_REG = 0x02011400;

      const uint32_t PRIMARY_I2C_BASE_ADDR = 0x000A0000;
      const uint32_t SPARE_I2C_BASE_ADDR = 0x000A0020;
      const uint32_t I2C_SETUP_UPPER_HALF = 0x92314009;
      const uint32_t I2C_SETUP_LOWER_HALF = 0x00000000;
      const uint32_t CONFIG_INTERVAL_TIMER = 0;
      const uint32_t CONFIG_STALE_TIMER = 0;

      // Variable declaration
      uint8_t l_dimm_ranks_array[l_NUM_MBAS][l_NUM_PORTS][l_NUM_DIMMS];	// Number of ranks for each configured DIMM in each MBA
      uint8_t l_dimm_type_array[l_NUM_MBAS];				// Type of DIMMs in each MBA
      uint8_t l_mba_pos = 0;						// Current MBA for populating rank array
      ecmdDataBufferBase l_data(64);

      // Get input attributes from MBAs
      std::vector<fapi::Target> l_target_mba_array;
      l_rc = fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_MBA_CHIPLET, l_target_mba_array);
      if (l_rc) return l_rc;

      for (uint8_t mba_index = 0; mba_index < l_target_mba_array.size(); mba_index++){
         l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_target_mba_array[mba_index], l_mba_pos);
	 if (l_rc) return l_rc;
	 FAPI_INF("MBA_POS: %d", l_mba_pos);

	 l_rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &l_target_mba_array[mba_index], l_dimm_ranks_array[l_mba_pos]);
	 if (l_rc) return l_rc;
	 FAPI_INF("EFF_NUM_RANKS: %d:%d:%d:%d", l_dimm_ranks_array[l_mba_pos][0][0], l_dimm_ranks_array[l_mba_pos][0][1], l_dimm_ranks_array[l_mba_pos][1][0], l_dimm_ranks_array[l_mba_pos][1][1]);

	 l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_TYPE, &l_target_mba_array[mba_index], l_dimm_type_array[l_mba_pos]);
	 if (l_rc) return l_rc;
	 FAPI_INF("ATTR_EFF_DIMM_TYPE: %d", l_dimm_type_array[l_mba_pos]);
      }

      // Configure Centaur Thermal Cache

      // ---------------------------------
      // Clear the master enable bit
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_CONFIG, l_data);
      if (l_rc) return l_rc;

      l_ecmd_rc |= l_data.clearBit(0); //Master enable is bit 0
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
         return l_rc;
      }

      l_rc = fapiPutScom(i_target, SCAC_CONFIG, l_data);
      if (l_rc) return l_rc;

      // ---------------------------------
      // Mask FIR bit 33 
      // Sets if any sensor cache addresses are written while the master enable is set
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_FIRMASK, l_data);
      if (l_rc) return l_rc;

      l_ecmd_rc |= l_data.setBit(33);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
         return l_rc;
      }

      l_rc = fapiPutScom(i_target, SCAC_FIRMASK, l_data);
      if (l_rc) return l_rc;

      // ---------------------------------
      // Program SensorAddressMap Register
      // ---------------------------------

      uint32_t l_addr_map_data_int;

      l_rc = fapiGetScom(i_target, SCAC_ADDRMAP, l_data);
      if (l_rc) return l_rc;

      if (l_dimm_type_array[0] == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM && l_dimm_type_array[1] == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM){
	 l_addr_map_data_int = 0x012389ab;
      }
      else{
	 l_addr_map_data_int = 0x01234567;
      }

      ecmdDataBufferBase l_addr_map_data(32);
      l_ecmd_rc |= l_addr_map_data.flushTo0();
      l_ecmd_rc |= l_addr_map_data.insert(l_addr_map_data_int, 0, 32, 0);
      l_ecmd_rc |= l_data.insert(l_addr_map_data, 0, 32, 0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }
      l_rc = fapiPutScom(i_target, SCAC_ADDRMAP, l_data);
      if (l_rc) return l_rc;

      // ---------------------------------
      // Program PibTarget Register
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_PIBTARGET, l_data);
      if (l_rc) return l_rc;

      ecmdDataBufferBase l_primary_i2cm_addr(32);
      ecmdDataBufferBase l_spare_i2cm_addr(32);

      l_ecmd_rc |= l_primary_i2cm_addr.flushTo0();
      l_ecmd_rc |= l_primary_i2cm_addr.insert(PRIMARY_I2C_BASE_ADDR, 0, 32, 0);

      l_ecmd_rc |= l_spare_i2cm_addr.flushTo0();
      l_ecmd_rc |= l_spare_i2cm_addr.insert(SPARE_I2C_BASE_ADDR, 0, 32, 0);

      l_ecmd_rc |= l_data.insert(l_primary_i2cm_addr, 0, 32, 0);
      l_ecmd_rc |= l_data.insert(l_spare_i2cm_addr, 32, 32, 0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }
      l_rc = fapiPutScom(i_target, SCAC_PIBTARGET, l_data);
      if (l_rc) return l_rc;

      // ---------------------------------
      // Program I2CMCtrl Register
      // TODO: Check if this can be setup at scan time, since it should be constant
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_I2CMCTRL, l_data);
      if (l_rc) return l_rc;

      ecmdDataBufferBase l_i2c_ctrl_upper_half(32);
      ecmdDataBufferBase l_i2c_ctrl_lower_half(32);

      l_ecmd_rc |= l_i2c_ctrl_upper_half.flushTo0();
      l_ecmd_rc |= l_i2c_ctrl_upper_half.insert(I2C_SETUP_UPPER_HALF, 0, 32, 0);

      l_ecmd_rc |= l_i2c_ctrl_lower_half.flushTo0();
      l_ecmd_rc |= l_i2c_ctrl_lower_half.insert(I2C_SETUP_LOWER_HALF, 0, 32, 0);

      l_ecmd_rc |= l_data.insert(l_i2c_ctrl_upper_half, 0, 32, 0);
      l_ecmd_rc |= l_data.insert(l_i2c_ctrl_lower_half, 32, 0, 0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }
      l_rc = fapiPutScom(i_target, SCAC_I2CMCTRL, l_data);
      if (l_rc) return l_rc;

      // ---------------------------------
      // Program SensorCacheConfiguration Register
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_CONFIG, l_data);
      if (l_rc) return l_rc;

      ecmdDataBufferBase l_interval_timer(32);
      ecmdDataBufferBase l_stale_timer(32);

      l_ecmd_rc |= l_interval_timer.flushTo0();
      l_ecmd_rc |= l_interval_timer.insert(CONFIG_INTERVAL_TIMER, 0, 32, 0);

      l_ecmd_rc |= l_stale_timer.flushTo0();
      l_ecmd_rc |= l_stale_timer.insert(CONFIG_STALE_TIMER, 0, 32, 0);

      l_ecmd_rc |= l_data.setBit(1);   //Sync to OCC_Read signal
      l_ecmd_rc |= l_data.insert(l_interval_timer, 11, 5, 32-5);
      l_ecmd_rc |= l_data.insert(l_stale_timer, 16, 8, 32-8);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }
      l_rc = fapiPutScom(i_target, SCAC_CONFIG, l_data);
      if (l_rc) return l_rc;

      // ---------------------------------
      // Program SensorCacheEnable Register
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_ENABLE, l_data);
      if (l_rc) return l_rc;

      if (l_dimm_type_array[0] == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM && l_dimm_type_array[1] == fapi::ENUM_ATTR_EFF_DIMM_TYPE_CDIMM){
         l_ecmd_rc |= l_data.setBit(0);
	 l_ecmd_rc |= l_data.setBit(4);
      }
      else{
         // Iterate through the num_ranks array to determine what DIMMs are plugged
	 // Enable sensor monitoring for each plugged DIMM
         uint32_t l_iterator = 0;
         for (uint32_t i = 0; i < 2; i++){
	    if (l_dimm_ranks_array[i][0][0] != 0){
	       l_ecmd_rc |= l_data.setBit(l_iterator);
	    }
	    l_iterator++;
	    if (l_dimm_ranks_array[i][0][1] != 0){
	       l_ecmd_rc |= l_data.setBit(l_iterator);
	    }
	    l_iterator++;
	    if (l_dimm_ranks_array[i][1][0] != 0){
	       l_ecmd_rc |= l_data.setBit(l_iterator);
	    }
	    l_iterator++;
	    if (l_dimm_ranks_array[i][1][1] != 0){
	       l_ecmd_rc |= l_data.setBit(l_iterator);
	    }
	    l_iterator++;
	 }
      }

      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }

      l_rc = fapiPutScom(i_target, SCAC_ENABLE, l_data);
      if (l_rc) return l_rc;


      // ---------------------------------
      // Set the master enable bit
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_CONFIG, l_data);
      if (l_rc) return l_rc;

      l_ecmd_rc |= l_data.setBit(0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }

      l_rc = fapiPutScom(i_target, SCAC_CONFIG, l_data);
      if (l_rc) return l_rc;

      // Configure Centaur Thermal Cache COMPLETED



      // Disable Emergency Throttles

      // ---------------------------------
      // Clear the emergency throttle FIR bit (MBS FIR 21)
      // ---------------------------------

      l_rc = fapiGetScom(i_target, MBS_FIR_REG, l_data);
      if (l_rc) return l_rc;

      l_ecmd_rc |= l_data.clearBit(21);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }

      l_rc = fapiPutScom(i_target, MBS_FIR_REG, l_data);
      if (l_rc) return l_rc;


      // ---------------------------------
      // Reset emergency throttle in progress bit (EMER THROT 0)
      // ---------------------------------

      l_rc = fapiGetScom(i_target, MBS_EMER_THROT, l_data);
      if (l_rc) return l_rc;

      l_ecmd_rc |= l_data.clearBit(0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }

      l_rc = fapiPutScom(i_target, MBS_EMER_THROT, l_data);
      if (l_rc) return l_rc;

      // Disable Emergency Throttles COMPLETED

      FAPI_INF("*** %s COMPLETE ***", procedure_name);
      return l_rc;

   } //end mss_thermal_init

} //end extern C

