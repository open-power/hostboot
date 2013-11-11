/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/mss_thermal_init/mss_thermal_init.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: mss_thermal_init.C,v 1.9 2013/10/11 15:51:56 pardeik Exp $
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
//   1.9   | pardeik  |11-OCT-13| gerrit review updates to remove uneeded items
//   1.8   | pardeik  |04-OCT-13| changes done from gerrit review
//   1.7   | pardeik  |01-AUG-13| Functional corrections to procedure
//                              | Updates for defect HW257484
//                              | Use custom DIMM instead of dimm type attribute
//                              | Added commented out throttle section at end to enable later
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
#include <cen_scom_addresses.H>

extern "C" {

   using namespace fapi;


   // Procedures in this file
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

      const uint64_t HANG_PULSE_0_REG = 0x00000000020f0020ULL;
      const uint64_t THERM_MODE_REG = 0x000000000205000fULL;
      const uint64_t CONTROL_REG = 0x0000000002050012ULL;

      const uint64_t SCAC_FIRMASK = 0x00000000020115c3ULL;
      const uint64_t SCAC_ACTMASK = 0x00000000020115d3ULL;
      const uint64_t SCAC_ADDRMAP = 0x00000000020115cdULL;
      const uint64_t SCAC_CONFIG = 0x00000000020115ceULL;
      const uint64_t SCAC_ENABLE = 0x00000000020115ccULL;
      const uint64_t SCAC_I2CMCTRL = 0x00000000020115d1ULL;
      const uint64_t SCAC_PIBTARGET = 0x00000000020115d2ULL;
      const uint64_t I2CM_RESET = 0x00000000000A0001ULL;

      const uint64_t MBS_EMER_THROT = 0x000000000201142dULL;
      const uint64_t MBS_FIR_REG = 0x0000000002011400ULL;

      const uint32_t PRIMARY_I2C_BASE_ADDR = 0x000A0000;
      const uint32_t SPARE_I2C_BASE_ADDR = 0x000A0000;
      const uint32_t I2C_SETUP_UPPER_HALF = 0xD2314049;
      const uint32_t I2C_SETUP_LOWER_HALF = 0x05000000;
      const uint32_t ACT_MASK_UPPER_HALF = 0x00018000;
      const uint32_t ACT_MASK_LOWER_HALF = 0x00000000;
      const uint32_t SENSOR_ADDR_MAP_ISDIMM = 0x012389ab;
      const uint32_t SENSOR_ADDR_MAP_CDIMM = 0x01234567;
// OCC polls cacheline every 2 ms.
// For I2C bus at 50kHz (9.6 ms max to read 8 sensors), use interval of 5 to prevent stall error
      const uint32_t CONFIG_INTERVAL_TIMER = 5;
      const uint32_t CONFIG_STALL_TIMER = 128;

      // Variable declaration
      uint8_t l_dimm_ranks_array[l_NUM_MBAS][l_NUM_PORTS][l_NUM_DIMMS];	// Number of ranks for each configured DIMM in each MBA
      uint8_t l_custom_dimm[l_NUM_MBAS];				// Custom DIMM
      uint8_t l_mba_pos = 0;						// Current MBA for populating rank array
      ecmdDataBufferBase l_data(64);

//********************************************
// Centaur internal temperature polling setup 
//********************************************
// setup hang pulse
      l_rc = fapiGetScom(i_target, HANG_PULSE_0_REG, l_data);
      if (l_rc) return l_rc;
      l_ecmd_rc |= l_data.setBit(1);
      l_ecmd_rc |= l_data.setBit(2);
      if(l_ecmd_rc) {
	  l_rc.setEcmdError(l_ecmd_rc);
	  return l_rc;
      }
      l_rc = fapiPutScom(i_target, HANG_PULSE_0_REG, l_data);
      if (l_rc) return l_rc;
// setup DTS enables
      l_rc = fapiGetScom(i_target, THERM_MODE_REG, l_data);
      if (l_rc) return l_rc;
      l_ecmd_rc |= l_data.setBit(20);
      l_ecmd_rc |= l_data.setBit(21);
      if(l_ecmd_rc) {
	  l_rc.setEcmdError(l_ecmd_rc);
	  return l_rc;
      }
      l_rc = fapiPutScom(i_target, THERM_MODE_REG, l_data);
      if (l_rc) return l_rc;
// setup pulse count and enable DTS sampling
      l_rc = fapiGetScom(i_target, THERM_MODE_REG, l_data);
      if (l_rc) return l_rc;
      l_ecmd_rc |= l_data.setBit(5);
      l_ecmd_rc |= l_data.setBit(6);
      l_ecmd_rc |= l_data.setBit(7);
      l_ecmd_rc |= l_data.setBit(8);
      l_ecmd_rc |= l_data.setBit(9);
      if(l_ecmd_rc) {
	  l_rc.setEcmdError(l_ecmd_rc);
	  return l_rc;
      }
      l_rc = fapiPutScom(i_target, THERM_MODE_REG, l_data);
      if (l_rc) return l_rc;
// issue a reset
      l_ecmd_rc |= l_data.flushTo0();
      l_ecmd_rc |= l_data.setBit(0);
      l_ecmd_rc |= l_data.setBit(1);
      l_ecmd_rc |= l_data.setBit(2);
      l_ecmd_rc |= l_data.setBit(3);
      l_ecmd_rc |= l_data.setBit(4);
      if(l_ecmd_rc) {
	  l_rc.setEcmdError(l_ecmd_rc);
	  return l_rc;
      }
      l_rc = fapiPutScom(i_target, CONTROL_REG, l_data);
      if (l_rc) return l_rc;
// Centaur internal temperature polling setup complete


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

	 l_rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &l_target_mba_array[mba_index], l_custom_dimm[l_mba_pos]);
	 if (l_rc) return l_rc;
	 FAPI_INF("ATTR_EFF_CUSTOM_DIMM: %d", l_custom_dimm[l_mba_pos]);
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

      if ((l_custom_dimm[0] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) && (l_custom_dimm[1] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)){
	 l_addr_map_data_int = SENSOR_ADDR_MAP_ISDIMM;
      }
      else{
	 l_addr_map_data_int = SENSOR_ADDR_MAP_CDIMM;
      }

      l_ecmd_rc |= l_data.insert(l_addr_map_data_int, 0, 32, 0);
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

      l_ecmd_rc |= l_data.insert(PRIMARY_I2C_BASE_ADDR, 0, 32, 0);
      l_ecmd_rc |= l_data.insert(SPARE_I2C_BASE_ADDR, 32, 32, 0);
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

      l_ecmd_rc |= l_data.insert(I2C_SETUP_UPPER_HALF, 0, 32, 0);
      l_ecmd_rc |= l_data.insert(I2C_SETUP_LOWER_HALF, 32, 32, 0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }
      l_rc = fapiPutScom(i_target, SCAC_I2CMCTRL, l_data);
      if (l_rc) return l_rc;


      // ---------------------------------
      // Program Action Mask Register
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_ACTMASK, l_data);
      if (l_rc) return l_rc;

      l_ecmd_rc |= l_data.insert(ACT_MASK_UPPER_HALF, 0, 32, 0);
      l_ecmd_rc |= l_data.insert(ACT_MASK_LOWER_HALF, 32, 32, 0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
         return l_rc;
      }
      l_rc = fapiPutScom(i_target, SCAC_ACTMASK, l_data);
      if (l_rc) return l_rc;


      // ---------------------------------
      // Program SensorCacheConfiguration Register
      // ---------------------------------

      l_rc = fapiGetScom(i_target, SCAC_CONFIG, l_data);
      if (l_rc) return l_rc;

      l_ecmd_rc |= l_data.setBit(1);   //Sync to OCC_Read signal
      l_ecmd_rc |= l_data.insert(CONFIG_INTERVAL_TIMER, 11, 5, 32-5);
      l_ecmd_rc |= l_data.insert(CONFIG_STALL_TIMER, 16, 8, 32-8);
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

      if ((l_custom_dimm[0] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) && (l_custom_dimm[1] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)){

	  
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

      //---------------------------------
      // Reset the I2CM
      //---------------------------------

      ecmdDataBufferBase l_reset(64);
      l_ecmd_rc |= l_reset.setBit(0);
      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
         return l_rc;
      }

      l_rc = fapiPutScom(i_target, I2CM_RESET, l_reset);
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


// Write the IPL Safe Mode Throttles
// TODO:  Enable once OCC writes the runtime memory throttles (SW227937)
/*
      uint32_t l_safemode_throttle_n_per_mba;
      uint32_t l_safemode_throttle_n_per_chip;
      uint32_t l_safemode_throttle_d;

      l_rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA, NULL, l_safemode_throttle_n_per_mba);
      if (l_rc) return l_rc;
      l_rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP, NULL, l_safemode_throttle_n_per_chip);
      if (l_rc) return l_rc;
      l_rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_DENOMINATOR, NULL, l_safemode_throttle_d);
      if (l_rc) return l_rc;
// write the N/M throttle control register
      for (uint8_t mba_index = 0; mba_index < l_target_mba_array.size(); mba_index++){
	  l_rc = fapiGetScom(l_target_mba_array[mba_index], MBA01_MBA_FARB3Q_0x03010416, l_data);
	  if (l_rc) return l_rc;
	  l_ecmd_rc |= l_data.insertFromRight(l_safemode_throttle_n_per_mba, 0, 15);
	  l_ecmd_rc |= l_data.insertFromRight(l_safemode_throttle_n_per_chip, 15, 16);
	  l_ecmd_rc |= l_data.insertFromRight(l_safemode_throttle_d, 31, 14);
	  if(l_ecmd_rc) {
	      l_rc.setEcmdError(l_ecmd_rc);
	      return l_rc;
	  }
	  l_rc = fapiPutScom(l_target_mba_array[mba_index], MBA01_MBA_FARB3Q_0x03010416, l_data);
	  if (l_rc) return l_rc;
      }
*/

// Update the runtime throttle attributes if needed for non custom DIMMs since those run power tests
// TODO:  Enable once dimm_power_test is running and updating attributes (SW227941)
/*
      uint32_t l_runtime_throttle_n_per_mba;
      uint32_t l_runtime_throttle_n_per_chip;
      uint32_t l_runtime_throttle_d;
      uint32_t l_dimm_power_test_throttle_n_per_mba;
      uint32_t l_dimm_power_test_throttle_n_per_chip;
      uint32_t l_dimm_power_test_throttle_d;

      for (uint8_t mba_index = 0; mba_index < l_target_mba_array.size(); mba_index++){
	  if (l_custom_dimm[mba_index] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_NO){

	      l_rc = FAPI_ATTR_GET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA, &l_target_mba_array[mba_index], l_runtime_throttle_n_per_mba);
	      if (l_rc) return l_rc;
	      l_rc = FAPI_ATTR_GET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP, &l_target_mba_array[mba_index], l_runtime_throttle_n_per_chip);
	      if (l_rc) return l_rc;
	      l_rc = FAPI_ATTR_GET(ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR, &l_target_mba_array[mba_index], l_runtime_throttle_d);
	      if (l_rc) return l_rc;
	      l_rc = FAPI_ATTR_GET(ATTR_MSS_DIMM_POWER_TEST_MEM_THROTTLE_NUMERATOR_PER_MBA, &l_target_mba_array[mba_index], l_dimm_power_test_throttle_n_per_mba);
	      if (l_rc) return l_rc;
	      l_rc = FAPI_ATTR_GET(ATTR_MSS_DIMM_POWER_TEST_MEM_THROTTLE_NUMERATOR_PER_CHIP, &l_target_mba_array[mba_index], l_dimm_power_test_throttle_n_per_chip);
	      if (l_rc) return l_rc;
	      l_rc = FAPI_ATTR_GET(ATTR_MSS_DIMM_POWER_TEST_MEM_THROTTLE_DENOMINATOR, &l_target_mba_array[mba_index], l_dimm_power_test_throttle_d);
	      if (l_rc) return l_rc;
// update the runtime throttle attributes with the dimm power test attributes if they are different
	      if (
		  (l_runtime_throttle_n_per_mba != l_dimm_power_test_throttle_n_per_mba)
		  ||
		  (l_runtime_throttle_n_per_chip != l_dimm_power_test_throttle_n_per_chip)
		  ||
		  (l_runtime_throttle_d != l_dimm_power_test_throttle_d)
		  )
	      {
		  l_rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
				       &l_target_mba_array[mba_index], l_dimm_power_test_throttle_n_per_mba);
		  if (l_rc) return l_rc;
		  l_rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
				       &l_target_mba_array[mba_index], l_dimm_power_test_throttle_n_per_chip);
		  if (l_rc) return l_rc;
		  l_rc = FAPI_ATTR_SET(ATTR_MSS_RUNTIME_MEM_THROTTLE_DENOMINATOR,
				       &l_target_mba_array[mba_index], l_dimm_power_test_throttle_d);
		  if (l_rc) return l_rc;

	      }
	  }
      }
*/

      FAPI_INF("*** %s COMPLETE ***", procedure_name);
      return l_rc;

   } //end mss_thermal_init

} //end extern C

