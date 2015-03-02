/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/mss_thermal_init/mss_thermal_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: mss_thermal_init.C,v 1.19 2015/02/12 23:23:56 pardeik Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_thermal_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_thermal_init
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Michael Pardeik   Email: pardeik@us.ibm.com
// *! BACKUP NAME : Jacob Sloat       Email: jdsloat@us.ibm.com
// *! ADDITIONAL COMMENTS :
//
// applicable CQ component memory_screen
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
//   1.18  | pardeik  |12-FEB-15| change ATTR_MRW_MEM_SENSOR_CACHE_ADDR_MAP to
//                              | a centaur target (was system)
//   1.17  | pardeik  |19-NOV-14| Use MRW attribute for SC address map for ISDIMMs
//   1.16  | pardeik  |06-FEB-14| removed string in trace statement
//   1.15  | pardeik  |24-FEB-14| added support for ATTR_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE
//   1.14  | pardeik  |12-FEB-14| changed CONFIG_INTERVAL_TIMER from 5 to 15 to 
//   1.13  | pardeik  |30-JAN-14| workaround for SW243504 (enable sensors on master
//                              |   i2c bus if ATTR_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE=ON)
//   1.12  | pardeik  |06-JAN-14| enable writing of safemode IPL throttles
//   1.11  | pardeik  |20-DEC-13| Only get sensor map attributes if a custom dimm
//   1.10  | pardeik  |21-NOV-13| added support for dimm temperature sensor attributes
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
    // Target is centaur
    
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

      FAPI_INF("*** Running mss_thermal_init ***");

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
// OCC polls cacheline every 2 ms (could vary from this, as seen on scope)
// For I2C bus at 50kHz (9.6 ms max to read 8 sensors), use interval of 15 for margin and to prevent stall errors when 8 sensors are enabled to be read
      const uint32_t CONFIG_INTERVAL_TIMER = 15;
      const uint32_t CONFIG_STALL_TIMER = 128;
      const uint8_t I2C_BUS_ENCODE_PRIMARY = 0;
      const uint8_t I2C_BUS_ENCODE_SECONDARY = 8;
      const uint8_t MAX_NUM_DIMM_SENSORS = 8;

      // Variable declaration
      uint8_t l_dimm_ranks_array[l_NUM_MBAS][l_NUM_PORTS][l_NUM_DIMMS];	// Number of ranks for each configured DIMM in each MBA
      uint8_t l_custom_dimm[l_NUM_MBAS];				// Custom DIMM
      uint8_t l_mba_pos = 0;						// Current MBA for populating rank array
      ecmdDataBufferBase l_data(64);
      ecmdDataBufferBase l_data_scac_enable(64);
      ecmdDataBufferBase l_data_scac_addrmap(64);
      uint8_t l_cdimm_sensor_map;
      uint8_t l_cdimm_sensor_map_primary;
      uint8_t l_cdimm_sensor_map_secondary;
      uint8_t l_cdimm_number_dimm_temp_sensors;
      uint8_t l_i2c_address_map;
      uint8_t l_data_scac_addrmap_offset;
      uint8_t l_i2c_bus_encode;
      uint8_t l_sensor_map_mask;
      uint8_t l_master_i2c_temp_sensor_enable;
      uint8_t l_spare_i2c_temp_sensor_enable;
      uint32_t l_dimm_sensor_cache_addr_map = 0;

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

      // need to clear out the array since it could be sparsely filled
      //  in the ISDIMM case
      for( size_t i = 0;
           i < (sizeof(l_custom_dimm)/sizeof(l_custom_dimm[0]));
           i++ )
      {
          l_custom_dimm[i] = fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_NO;
      }

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

      // Get attributes for dimm temperature sensor mapping for only a custom dimm so we don't get an error
      // Get attritute for custom dimms for enablement on the master i2c bus
      if ((l_custom_dimm[0] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) || (l_custom_dimm[1] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES))
      {
	  l_rc = FAPI_ATTR_GET(ATTR_VPD_CDIMM_SENSOR_MAP_PRIMARY, &i_target, l_cdimm_sensor_map_primary);
	  if (l_rc) return l_rc;
	  l_rc = FAPI_ATTR_GET(ATTR_VPD_CDIMM_SENSOR_MAP_SECONDARY, &i_target, l_cdimm_sensor_map_secondary);
	  if (l_rc) return l_rc;
	  l_rc = FAPI_ATTR_GET(ATTR_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE, NULL, l_master_i2c_temp_sensor_enable);
	  if (l_rc) return l_rc;
	  l_rc = FAPI_ATTR_GET(ATTR_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE, NULL, l_spare_i2c_temp_sensor_enable);
	  if (l_rc) return l_rc;
      }
      else
      {
	  // sensor cache address map for non custom dimm temperature sensors (which i2c bus and i2c address they are)
	  l_rc = FAPI_ATTR_GET(ATTR_MRW_MEM_SENSOR_CACHE_ADDR_MAP, &i_target, l_dimm_sensor_cache_addr_map);
	  if (l_rc) return l_rc;
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

      // --------------------------------------------------------
      // Program SensorCacheEnable and SensorAddressMap Registers
      // --------------------------------------------------------

      l_rc = fapiGetScom(i_target, SCAC_ENABLE, l_data_scac_enable);
      if (l_rc) return l_rc;

      l_rc = fapiGetScom(i_target, SCAC_ADDRMAP, l_data_scac_addrmap);
      if (l_rc) return l_rc;

      if ((l_custom_dimm[0] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) || (l_custom_dimm[1] == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)){

	  l_cdimm_number_dimm_temp_sensors = 0;
	  // cycle through both primary and secondary i2c busses, determine i2c address and enable bits
	  for (uint8_t k = 0; k < 2; k++)
	  {
	      for (uint8_t i = 0; i < 8; i++)
	      {
		  if (k == 0)
		  {
		      l_i2c_bus_encode = I2C_BUS_ENCODE_PRIMARY;
		      l_cdimm_sensor_map = l_cdimm_sensor_map_primary;
		  }
		  else
		  {
		      l_i2c_bus_encode = I2C_BUS_ENCODE_SECONDARY;
		      l_cdimm_sensor_map = l_cdimm_sensor_map_secondary;
		  }
		  switch (i)
		  {
		      case 0:
			  l_sensor_map_mask = 0x01;
			  break;
		      case 1:
			  l_sensor_map_mask = 0x02;
			  break;
		      case 2:
			  l_sensor_map_mask = 0x04;
			  break;
		      case 3:
			  l_sensor_map_mask = 0x08;
			  break;
		      case 4:
			  l_sensor_map_mask = 0x10;
			  break;
		      case 5:
			  l_sensor_map_mask = 0x20;
			  break;
		      case 6:
			  l_sensor_map_mask = 0x40;
			  break;
		      case 7:
			  l_sensor_map_mask = 0x80;
			  break;
		      default:
			  l_sensor_map_mask = 0x00;		
		  }
		  if ((l_cdimm_sensor_map & l_sensor_map_mask) != 0)
		  {
		      // Only enable the sensor for custom dimms based on the attributes
		      if (
			  (
			   (k==0)
			   &&
			   (l_master_i2c_temp_sensor_enable ==
			    ENUM_ATTR_MRW_CDIMM_MASTER_I2C_TEMP_SENSOR_ENABLE_OFF)
			   )
			  ||
			  (
			   (k==1)
			   &&
			   (l_spare_i2c_temp_sensor_enable ==
			    ENUM_ATTR_MRW_CDIMM_SPARE_I2C_TEMP_SENSOR_ENABLE_OFF)
			   )
			  )
		      {
			  // do nothing here - do not enable the sensor
		      }
		      else	
		      {	
			  l_ecmd_rc |= l_data_scac_enable.setBit(l_cdimm_number_dimm_temp_sensors);
		      }
		      l_i2c_address_map = i + l_i2c_bus_encode;
		      l_data_scac_addrmap_offset = l_cdimm_number_dimm_temp_sensors * 4;
		      l_ecmd_rc |= l_data_scac_addrmap.insert(l_i2c_address_map, l_data_scac_addrmap_offset , 4, 4);
		      l_cdimm_number_dimm_temp_sensors++;
		      if(l_ecmd_rc) {
			  l_rc.setEcmdError(l_ecmd_rc);
			  return l_rc;
		      }
		      if (l_cdimm_number_dimm_temp_sensors > MAX_NUM_DIMM_SENSORS)
		      {
			  FAPI_ERR("Invalid number of dimm temperature sensors specified in the CDIMM VPD MW keyword");
			  const fapi::Target & MEM_CHIP = i_target;
			  uint8_t FFDC_DATA_1 = l_cdimm_sensor_map_primary;
			  uint8_t FFDC_DATA_2 = l_cdimm_sensor_map_secondary;
			  FAPI_SET_HWP_ERROR(l_rc, RC_MSS_CDIMM_INVALID_NUMBER_SENSORS);
			  return l_rc;
		      }
		  }
	      }
	  }
      }
      else{
         // Iterate through the num_ranks array to determine what DIMMs are plugged
	 // Enable sensor monitoring for each plugged DIMM
         uint32_t l_iterator = 0;
         for (uint32_t i = 0; i < 2; i++){
	    if (l_dimm_ranks_array[i][0][0] != 0){
	       l_ecmd_rc |= l_data_scac_enable.setBit(l_iterator);
	    }
	    l_iterator++;
	    if (l_dimm_ranks_array[i][0][1] != 0){
	       l_ecmd_rc |= l_data_scac_enable.setBit(l_iterator);
	    }
	    l_iterator++;
	    if (l_dimm_ranks_array[i][1][0] != 0){
	       l_ecmd_rc |= l_data_scac_enable.setBit(l_iterator);
	    }
	    l_iterator++;
	    if (l_dimm_ranks_array[i][1][1] != 0){
	       l_ecmd_rc |= l_data_scac_enable.setBit(l_iterator);
	    }
	    l_iterator++;
	 }
	 l_ecmd_rc |= l_data_scac_addrmap.insert(l_dimm_sensor_cache_addr_map, 0, 32, 0);
	 if(l_ecmd_rc) {
	     l_rc.setEcmdError(l_ecmd_rc);
	     return l_rc;
	 }

      }


      if(l_ecmd_rc) {
         l_rc.setEcmdError(l_ecmd_rc);
	 return l_rc;
      }

      l_rc = fapiPutScom(i_target, SCAC_ENABLE, l_data_scac_enable);
      if (l_rc) return l_rc;

      l_rc = fapiPutScom(i_target, SCAC_ADDRMAP, l_data_scac_addrmap);
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
// For centaur DD2 and above since OCC only writes runtime throttles for this

      uint8_t l_enable_safemode_throttle = 0;
      l_rc = FAPI_ATTR_GET(ATTR_CENTAUR_EC_ENABLE_SAFEMODE_THROTTLE, &i_target, l_enable_safemode_throttle);
      if (l_rc) return l_rc;

      if (l_enable_safemode_throttle)
      {
	  uint32_t l_safemode_throttle_n_per_mba;
	  uint32_t l_safemode_throttle_n_per_chip;
	  uint32_t l_throttle_d;

	  l_rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA, NULL, l_safemode_throttle_n_per_mba);
	  if (l_rc) return l_rc;
	  l_rc = FAPI_ATTR_GET(ATTR_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP, NULL, l_safemode_throttle_n_per_chip);
	  if (l_rc) return l_rc;
	  l_rc = FAPI_ATTR_GET(ATTR_MRW_MEM_THROTTLE_DENOMINATOR, NULL, l_throttle_d);
	  if (l_rc) return l_rc;
// write the N/M throttle control register
	  for (uint8_t mba_index = 0; mba_index < l_target_mba_array.size(); mba_index++){
	      l_rc = fapiGetScom(l_target_mba_array[mba_index], MBA01_MBA_FARB3Q_0x03010416, l_data);
	      if (l_rc) return l_rc;
	      l_ecmd_rc |= l_data.insertFromRight(l_safemode_throttle_n_per_mba, 0, 15);
	      l_ecmd_rc |= l_data.insertFromRight(l_safemode_throttle_n_per_chip, 15, 16);
	      l_ecmd_rc |= l_data.insertFromRight(l_throttle_d, 31, 14);
	      if(l_ecmd_rc) {
		  l_rc.setEcmdError(l_ecmd_rc);
		  return l_rc;
	      }
	      l_rc = fapiPutScom(l_target_mba_array[mba_index], MBA01_MBA_FARB3Q_0x03010416, l_data);
	      if (l_rc) return l_rc;
	  }
      }

      FAPI_INF("*** mss_thermal_init COMPLETE ***");
      return l_rc;

   } //end mss_thermal_init

} //end extern C

