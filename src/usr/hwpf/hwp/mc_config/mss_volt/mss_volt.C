/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt.C $              */
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
// $Id: mss_volt.C,v 1.12 2012/10/18 14:46:36 jdsloat Exp $
/* File mss_volt.C created by JEFF SABROWSKI on Fri 21 Oct 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_volt.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME :   Jeff Sabrowski (jsabrow@us.ibm.com)
// *! BACKUP NAME :
// #! ADDITIONAL COMMENTS :
//
// General purpose funcs

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.0    | jsabrow  | 09/30/11 | Initial draft.
//  1.1    | jsabrow  | 12/13/11 | This version compiles. Attributes dont work yet.
//  1.3    | bellows  | 12/21/11 | fapiGetAssociatedDimms funciton does not work, added quick exit
//  1.4    | jsabrow  | 02/13/12 | Updates for code review
//  1.5    | jsabrow  | 03/26/12 | Updates for code review
//  1.8    | jdsloat  | 04/26/12 | fixed 1.5V issue
//  1.9    | jdsloat  | 05/08/12 | Removed debug message
//  1.10   | jdsloat  | 05/09/12 | Fixed typo
//  1.11   | bellows  | 07/16/12 | added in Id tag
//  1.11   | jdsloat  | 10/18/12 | Added check for violation of tolerant voltages of non-functional dimms.

// This procedure takes a vector of Centaurs behind a voltage domain,
// reads in supported DIMM voltages from SPD and determines optimal
//  voltage bin for the DIMM voltage domain.
// supported voltage bins:  DDR3: 1.35   DDR4: 1.25V (expected)


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_volt.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
const uint32_t MAX_TOLERATED_VOLT = 1500;
const uint32_t MAX_TOLERATED_DDR3_VOLT = 1500;
const uint32_t MAX_TOLERATED_DDR4_VOLT = 1200;

fapi::ReturnCode mss_volt(std::vector<fapi::Target> & i_targets_memb)
{

  fapi::ReturnCode l_rc;
  uint8_t l_dimm_functionality=0;
  uint8_t l_spd_dramtype=0;
  uint8_t l_spd_volts=0;
  uint8_t l_spd_volts_all_dimms=0x06;  //start assuming all voltages supported
  uint8_t l_dram_ddr3_found_flag=0;
  uint8_t l_dram_ddr4_found_flag=0;

  uint32_t l_selected_dram_voltage=0;  //this gets written into all centaurs when done.
  uint32_t l_tolerated_dram_voltage = MAX_TOLERATED_VOLT; //initially set to the max tolerated voltage

  // Iterate through the list of centaurs
  for (uint32_t i=0; i < i_targets_memb.size(); i++)
    {
      std::vector<fapi::Target> l_mbaChiplets;
      // Get associated MBA's on this centaur
      l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
      if (l_rc) return l_rc;
      // Loop through the 2 MBA's
      for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
	{
      std::vector<fapi::Target> l_dimm_targets;
	  // Get a vector of DIMM targets
	  l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
	  if (l_rc) return l_rc;
	  for (uint32_t k=0; k < l_dimm_targets.size(); k++)
	    {
	      l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &l_dimm_targets[k], l_spd_dramtype);
	      if (l_rc) return l_rc;
	      l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE, &l_dimm_targets[k], l_spd_volts);
	      if (l_rc) return l_rc;
	      l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_dimm_targets[k], l_dimm_functionality);
	      if (l_rc) return l_rc;

	      // spd_volts:  bit0= NOT 1.5V bit1=1.35V bit2=1.25V, assume a 1.20V in future for DDR4
	      // check for supported voltage/dram type combo  DDR3=12, DDR4=13
	      if (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3)
		{
		  l_dram_ddr3_found_flag=1;
		}
	      else if (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4)
		{
		  l_dram_ddr4_found_flag=1;
		}
	      else 
		{
		  uint8_t &DEVICE_TYPE = l_spd_dramtype;
		  FAPI_ERR("Unknown DRAM Device Type 0x%x", l_spd_dramtype);
		  FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_UNRECOGNIZED_DRAM_DEVICE_TYPE);
		  return l_rc;
		}

	      if(l_dimm_functionality == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
	      {
	          //AND dimm voltage capabilities together to find aggregate voltage support on all dimms
		  l_spd_volts_all_dimms = l_spd_volts_all_dimms & l_spd_volts;
	      }

	    }
	}
    }      

  // now we figure out if we have a supported ddr type and voltage
  // note: only support DDR3=1.35V and DDR4=1.2xV

  if (l_dram_ddr3_found_flag && l_dram_ddr4_found_flag)
  {
      FAPI_ERR("mss_volt: DDR3 and DDR4 mixing not allowed");
      FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_DDR_TYPE_MIXING_UNSUPPORTED);
      return l_rc;
  }
  if (l_dram_ddr3_found_flag && ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35) == fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35))
  {
      l_selected_dram_voltage=1350;
  }
  else if (l_dram_ddr4_found_flag && ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2X) == fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2X))
  {
      l_selected_dram_voltage=1200;
  }
  else if ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) != fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5)
  {
      l_selected_dram_voltage=1500;
  }
  else
  {
      FAPI_ERR("One or more DIMMs do not support required voltage for DIMM type");
      FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE);
      return l_rc;
  }

/*  if( l_selected_dram_voltage > l_supported_dram_voltage)
  {
      FAPI_INF( "Selected Voltage larger than highest supported voltage.  Selected Voltage: %d Supported Voltage: %d ", l_selected_dram_voltage, l_supported_dram_voltage);
      FAPI_INF( "Using supported Voltage.");
      l_selected_dram_voltage = l_supported_dram_voltage;
  }
*/

  // Must check to see if we violate Tolerent voltages of Non-functional Dimms
  // If so we must error/deconfigure on the centaur level.
  // Iterate through the list of centaurs
  for (uint32_t i=0; i < i_targets_memb.size(); i++)
  {
      l_tolerated_dram_voltage = MAX_TOLERATED_VOLT; // using 1.5 as this is the largest supported voltage
      std::vector<fapi::Target> l_mbaChiplets;
      // Get associated MBA's on this centaur
      l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
      if (l_rc) return l_rc;
      for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
      {
	  std::vector<fapi::Target> l_dimm_targets;
          // Get a vector of DIMM targets
	  l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
	  if (l_rc) return l_rc;
	  for (uint32_t k=0; k < l_dimm_targets.size(); k++)
	  {
	      l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_dimm_targets[k], l_dimm_functionality);
	      if (l_rc) return l_rc;

	      if(l_dimm_functionality == fapi::ENUM_ATTR_FUNCTIONAL_NON_FUNCTIONAL)
	      {
		  if ( (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3) && (l_tolerated_dram_voltage > MAX_TOLERATED_DDR3_VOLT) )
		  {
		      l_tolerated_dram_voltage =  MAX_TOLERATED_DDR3_VOLT;
		  }
		  if ( (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4) && (l_tolerated_dram_voltage > MAX_TOLERATED_DDR4_VOLT) )
		  {
		      l_tolerated_dram_voltage =  MAX_TOLERATED_DDR4_VOLT;
		  }
	      }
	  }
      }

      if ( l_tolerated_dram_voltage < l_selected_dram_voltage )
      {
	  FAPI_ERR("One or more DIMMs classified non-functional has a tolerated voltage below selected voltage.");
	  FAPI_ERR("Deconfiguring the associated Centaur.");
	  const fapi::Target & MASTER_CHIP = i_targets_memb[i];
	  FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_TOLERATED_VOLTAGE_VIOLATION);
	  return l_rc;
      }
  }


  // Iterate through the list of centaurs again, to update ATTR
  for (uint32_t i=0; i < i_targets_memb.size(); i++)
  {
      l_rc = FAPI_ATTR_SET(ATTR_MSS_VOLT, &i_targets_memb[i], l_selected_dram_voltage);
      FAPI_INF( "mss_volt calculation complete.  MSS_VOLT: %d", l_selected_dram_voltage);
      if (l_rc) return l_rc;
  }

  return l_rc;
}




