//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/mc_init/mss_volt/mss_volt.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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

//  ???    | mww    | remove internal target vector

// This procedure takes a vector of Centaurs behind a voltage domain,
// reads in supported DIMM voltages from SPD and determines optimal
//  voltage bin for the DIMM voltage domain.
// supported voltage bins:  DDR3: 1.35   DDR4: 1.25V (expected)


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_volt.H>

fapi::ReturnCode mss_volt(std::vector<fapi::Target> & l_targets_memb)
{

  fapi::ReturnCode l_rc;
  // $$ std::vector<fapi::Target> l_targets_memb;
  std::vector<fapi::Target> l_mbaChiplets;
  std::vector<fapi::Target> l_dimm_targets;
  uint8_t l_spd_dramtype=0;
  uint8_t l_spd_volts=0;
  uint8_t l_spd_volts_all_dimms=0x07;  //start assuming all voltages supported
  uint8_t l_dram_ddr3_found_flag=0;
  uint8_t l_dram_ddr4_found_flag=0;

  uint32_t l_selected_dram_voltage=0;  //this gets written into all centaurs when done.

  // Iterate through the list of centaurs
  for (uint32_t i=0; i < l_targets_memb.size(); i++)
    {
      // Get associated MBA's on this centaur
      l_rc=fapiGetChildChiplets(l_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
      // Loop through the 2 MBA's
      for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
	{
	  // Get a vector of DIMM targets
	  l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets);
	  for (uint32_t k=0; k < l_dimm_targets.size(); k++)
	    {

	      l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &l_dimm_targets[k], l_spd_dramtype);
	      // TODO: need to verify l_rc is 'good'
	      // can I do: 	  if (l_rc) { FAPI_ERR("..."); break; }
	      l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE, &l_dimm_targets[k], l_spd_volts);
	      // TODO: need to verify l_rc is 'good'
	      // spd_volts:  bit0=1.5V bit1=1.35V bit2=1.25V, assume a 1.20V in future.
	      // check for supported voltage/dram type combo  DDR3=12, DDR4=13
	      if (l_spd_dramtype == 0x0b)
		{
		  l_dram_ddr3_found_flag=1;
		}
	      else if (l_spd_dramtype == 0x0c)
		{
		  l_dram_ddr4_found_flag=1;
		}
	      else
		{
		  //FAPI_ERR("Dimm not DDR3 or DDR4");
		}

	      //AND of voltages support by all dimms in this domain (bit 0 is negative logic)
	      l_spd_volts = l_spd_volts ^ 0x01;
	      l_spd_volts_all_dimms = l_spd_volts_all_dimms & l_spd_volts;

	    }
	}
    }

  // now we figure out if we have a supported ddr type and voltage
  if (l_dram_ddr3_found_flag && l_dram_ddr4_found_flag)
    {
      //FAPI_ERR("DDR3 and DDR4 mixing not allowed");
    }


  if (l_dram_ddr3_found_flag && (l_spd_volts_all_dimms & 0x01) == 0x01)
    {
      l_selected_dram_voltage=1350;
    }
  else if (l_dram_ddr4_found_flag && (l_spd_volts_all_dimms & 0x02) == 0x02)
    {
      l_selected_dram_voltage=1200;
    }
  else
    {
      //FAPI_ERR("Dimms do not all support 1.35 or 1.2x");
    }

  // Iterate through the list of centaurs again, to update ATTR
  for (uint32_t i=0; i < l_targets_memb.size(); i++)
    {
      l_rc = FAPI_ATTR_SET(ATTR_MSS_VOLT, &l_targets_memb[i], l_selected_dram_voltage);
      if (l_rc)
	{
	  //FAPI_ERR("Dimms do not all support 1.35 or 1.2x");
	  break;
	}
    }

  return l_rc;
}




