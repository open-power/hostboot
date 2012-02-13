//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/mc_init/mss_freq/mss_freq.C $
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
// *! TITLE : mss_freq.C
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
// Version:|  Author: |   Date:  | Comment:
//---------|----------|----------|----------------------------------------------
//  1.1    | jsabrow  | 09/30/11 | Initial draft.
//  1.2    | bellows  | 12/21/11 | fixed function call to mss_freq
//  1.4    | jsabrow  | 
// This procedure takes CENTAUR as argument.  for each DIMM (under each MBA)
// DIMM SPD attributes are read to determine optimal DRAM frequency
// frequency bins:  800*, 1066*, 1333, 1600, 1866, 2133, 2400*, 2666*
//    (*=not supported in product as of feb'12)

//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_freq.H>

using namespace fapi;

fapi::ReturnCode mss_freq(fapi::Target &i_target_memb)
{
  fapi::ReturnCode l_rc;
  std::vector<fapi::Target> l_mbaChiplets;
  std::vector<fapi::Target> l_dimm_targets;
  uint8_t l_spd_byte10=0;
  uint8_t l_spd_byte11=0;
  uint8_t l_spd_byte12=0;
  uint32_t l_spd_byte1415=0xFFFF;
  uint8_t l_spd_byte16=0;
  uint32_t l_dimm_freq_calc=0;
  uint32_t l_dimm_freq_max=9999;
  uint32_t l_selected_dimm_freq=0;
  uint32_t l_dimm_all_cas=0;

  // Get associated MBA's on this centaur                                                                                      
  l_rc=fapiGetChildChiplets(i_target_memb, fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
  // Loop through the 2 MBA's                                                                                                  
  for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    {
      // Get a vector of DIMM targets                                                                                          
      l_rc = fapiGetAssociatedDimms(l_mbaChiplets[i], l_dimm_targets);
      for (uint32_t j=0; j < l_dimm_targets.size(); j++)
	{
	  
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVIDEND, &l_dimm_targets[j], l_spd_byte10);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD byte 10.");
	      break;
	    }

	  l_rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVISOR, &l_dimm_targets[j], l_spd_byte11);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD byte 11.");
	      break;
	    }

	  l_rc = FAPI_ATTR_GET(ATTR_SPD_TCKMIN, &l_dimm_targets[j], l_spd_byte12);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD byte 12.");
	      break;
	    }                                                            

	  //TODO: need to check that bytes 10, 11 nor 12 are zero
	  //JEDEC doesn't allow zeroes in these bytes, but we should check.
	  //integer-safe equation for dram clock * 2
	  l_dimm_freq_calc = 2000000 / ( ( 1000 * l_spd_byte12 * l_spd_byte10 ) / l_spd_byte11);

	  //is this the slowest dimm?
	  if (l_dimm_freq_calc < l_dimm_freq_max)
	    {
	      l_dimm_freq_max = l_dimm_freq_calc;
	    }

	  l_rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED, &l_dimm_targets[j], l_spd_byte1415);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD byte 14-15.");
	      break;
	    }                                                            

	  //'AND' all dimm CAS support 
	  l_dimm_all_cas = l_dimm_all_cas & l_spd_byte1415;

	  l_rc = FAPI_ATTR_GET(ATTR_SPD_TAAMIN, &l_dimm_targets[j], l_spd_byte16);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD byte 16.");
	      break;
	    }                                                            

	  
	}
    }
  
  //bucketize dimm freq.
  if (!l_rc) 
    {
      if (l_dimm_freq_max < 1013)
	{
	  // 800 isn't supported
	  l_selected_dimm_freq=800;
	}
      else if (l_dimm_freq_max < 1266)
	{
	  // 1066 
	  l_selected_dimm_freq=1066;
	}
      else if (l_dimm_freq_max < 1520)
	{
	  // 1333
	  l_selected_dimm_freq=1333;
	}
      else if (l_dimm_freq_max < 1773)
	{
	  // 1600
	  l_selected_dimm_freq=1600;
	}
      else if (l_dimm_freq_max < 2026)
	{
	  // 1866
	  l_selected_dimm_freq=1866;
	}
      else if (l_dimm_freq_max < 2280)
	{
	  // 2133
	  l_selected_dimm_freq=2133;
	}
      else
	{
	  //FAPI_ERR("Error dimm freq calculated > 2133 MHz");
	}
    }

  //TODO:  frequency consideration for CAS
  
  // set frequency in centaur attribute ATTR_MSS_FREQ
  if (!l_rc) 
    {
      l_rc = FAPI_ATTR_SET(ATTR_MSS_FREQ, &i_target_memb, l_selected_dimm_freq);
    }

  //all done.
  return l_rc;
}
