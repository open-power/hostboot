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
//  1.6    | jdsloat  | 05/03/12 | Fixed per Firmware request, added CL calc
//  1.7    | jdsloat  | 05/03/12 | Uncommented Set Attributes
//  1.8    | jdsloat  | 05/07/12 | fixed per Firmware request
//  1.9    | jdsloat  | 05/07/12 | Unused Variables removed
//  1.11   | jdsloat  | 05/07/12 | Uncommented Set Attributes
//  1.12   | jdsloat  | 05/08/12 | Fixed per Firmware request, fixed CL attribute set, fixed MTB usage.
//  1.13   | jdsloat  | 05/09/12 | Fixed per Firmware request
//  1.14   | jdsloat  | 05/10/12 | Fixed per Firmware Request, RC checks, 0 checks
//
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

fapi::ReturnCode mss_freq(const fapi::Target &i_target_memb)
{
  fapi::ReturnCode l_rc;
  std::vector<fapi::Target> l_mbaChiplets;
  std::vector<fapi::Target> l_dimm_targets;
  uint8_t l_spd_mtb_dividend=0;
  uint8_t l_spd_mtb_divisor=0;
  uint32_t l_dimm_freq_calc=0;
  uint32_t l_dimm_freq_min=9999;
  uint8_t l_spd_min_tck_MTB=0;
  uint32_t l_spd_min_tck=0;
  uint32_t l_spd_min_tck_max=0;
  uint8_t  l_spd_min_taa_MTB=0;
  uint32_t l_spd_min_taa=0;
  uint32_t l_spd_min_taa_max=0;
  uint32_t l_selected_dimm_freq=0;
  uint32_t l_spd_cas_lat_supported = 0xFFFFFFFF;
  uint32_t l_spd_cas_lat_supported_all = 0xFFFFFFFF;
  uint8_t l_cas_latency = 0;
  uint32_t l_cl_mult_tck = 0;

  // Get associated MBA's on this centaur                                                                                      
  l_rc=fapiGetChildChiplets(i_target_memb, fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
  if (l_rc)
  {
      FAPI_ERR("Error Getting MBA targets.");
      return l_rc;
  }
  // Loop through the 2 MBA's                                                                                                  
  for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    {
      // Get a vector of DIMM targets                                                                                          
      l_rc = fapiGetAssociatedDimms(l_mbaChiplets[i], l_dimm_targets);
      if (l_rc)
      {
	  FAPI_ERR("Error Getting DIMM targets.");
	  return l_rc;
      }
      for (uint32_t j=0; j < l_dimm_targets.size(); j++)
	{
	  
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVIDEND, &l_dimm_targets[j], l_spd_mtb_dividend);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD Medium Timebase Dividend.");
	      break;
	    }

	  l_rc = FAPI_ATTR_GET(ATTR_SPD_MTB_DIVISOR, &l_dimm_targets[j], l_spd_mtb_divisor);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD Medium Timebase Divisor.");
	      break;
	    }

	  l_rc = FAPI_ATTR_GET(ATTR_SPD_TCKMIN, &l_dimm_targets[j], l_spd_min_tck_MTB);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD Minimum TCK (Min Clock Cycle).");
	      break;
	    }

	  l_rc = FAPI_ATTR_GET(ATTR_SPD_TAAMIN, &l_dimm_targets[j], l_spd_min_taa_MTB);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD Minimum TAA (Min CAS Latency Time).");
	      break;
	    }
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED, &l_dimm_targets[j], l_spd_cas_lat_supported);
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read SPD Supported CAS Latencies.");
	      break;
	    }

	  if ((l_spd_min_tck_MTB == 0)||(l_spd_mtb_dividend == 0)||(l_spd_mtb_divisor == 0)||(l_spd_min_taa_MTB == 0))
	  {
	      //Invalid due to the fact that JEDEC dictates that these should be non-zero.
	      FAPI_ERR("Invalid data recieved from SPD within MTB Dividend, MTB Divisor, TCK Min, or TAA Min");
	      FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_SPD_DATA);
	      break;
	  }

	  // Calc done on PS units (the multiplication of 1000) to avoid rounding errors.
	  // Frequency listed with multiplication of 2 as clocking data on both +- edges
	  l_spd_min_tck =  ( 1000 * l_spd_min_tck_MTB * l_spd_mtb_dividend ) / l_spd_mtb_divisor;
	  l_spd_min_taa =  ( 1000 * l_spd_min_taa_MTB * l_spd_mtb_dividend ) / l_spd_mtb_divisor;
	  if ((l_spd_min_tck == 0)||(l_spd_min_taa == 0))
	  {
	      //Invalid due to the fact that JEDEC dictates that these should be non-zero.
	      FAPI_ERR("Invalid data recieved from SPD causing TCK Min or TAA Min to be 0");
	      FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_SPD_DATA);
	      break;
	  }
	  l_dimm_freq_calc = 2000000 / l_spd_min_tck;
	  
	  //is this the slowest dimm?
	  if (l_dimm_freq_calc < l_dimm_freq_min)
	    {
	      l_dimm_freq_min = l_dimm_freq_calc;
	    }

	  if (l_spd_min_tck > l_spd_min_tck_max)
	    {
	      l_spd_min_tck_max = l_spd_min_tck;
	    }

	  if (l_spd_min_taa > l_spd_min_taa_max)
	    {
	      l_spd_min_taa_max = l_spd_min_taa;
	    }

	  l_spd_cas_lat_supported_all = l_spd_cas_lat_supported_all & l_spd_cas_lat_supported;

      }
      if (l_rc)
      {
	  break;
      }
  }

  if ((l_spd_cas_lat_supported_all == 0) && (!l_rc))
  {
      FAPI_ERR("No common supported CAS latencies between DIMMS.");
      FAPI_SET_HWP_ERROR(l_rc, RC_MSS_NO_COMMON_SUPPORTED_CL);
  }

  if (!l_rc) 
  {

      //Determine a proposed CAS latency
      l_cas_latency = l_spd_min_taa_max / l_spd_min_tck_max;
      if ( l_spd_min_taa_max % l_spd_min_tck_max)
      {
	  l_cas_latency++;
      } 
      l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;

      // If the CL proposed is not supported or the TAA exceeds TAA max
      // Spec defines tAAmax as 20 ns for all DDR3 speed grades.
      while ((!( l_spd_cas_lat_supported_all & (0x00000001<<(l_cas_latency-4)))) || (l_cl_mult_tck > 20000))
      {
          // If not supported, increment the CL up to 18 (highest supported CL) looking for Supported CL 
	  while ((!( l_spd_cas_lat_supported_all & (0x00000001<<(l_cas_latency-4))))&&(l_cas_latency < 18))
	  {
	      l_cas_latency++;
	  }

          // If still not supported CL or TAA is > 20 ns ... pick a slower TCK and start again
	  l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;

	  if ((!( l_spd_cas_lat_supported_all & (0x00000001<<(l_cas_latency-4)))) || (l_cl_mult_tck > 20000))
	  {
	      if (l_spd_min_tck_max < 1500)
	      {
	          //1600 to 1333
		  l_spd_min_tck_max = 1500;

	      }
	      else if (l_spd_min_tck_max < 1875)
	      {
	          //1333 to 1066 
		  l_spd_min_tck_max = 1875;
	      }
	      else if (l_spd_min_tck_max < 2500)
	      {
	          //1066 to 800
		  l_spd_min_tck_max = 2500;
	      }
	      else
	      {
	          //This is minimum frequency and cannot be lowered
		  FAPI_ERR("Lowered Frequency to TCLK MIN finding no supported CL without exceeding TAA MAX.");
		  FAPI_SET_HWP_ERROR(l_rc, RC_MSS_EXCEED_TAA_MAX_NO_CL );
		  break;
	      }

	      // Re-calculate with new tck
	      l_cas_latency = l_spd_min_taa_max / l_spd_min_tck_max;
	      if ( l_spd_min_taa_max % l_spd_min_tck_max)
	      {
		  l_cas_latency++;
	      } 
	      l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;
	      l_dimm_freq_min = 2000000 / l_spd_min_tck_max;

	  }
      }
  }

  FAPI_INF( "Calculated Frequency: %d ",  l_dimm_freq_min);

  //bucketize dimm freq.
  if (!l_rc) 
  {
      if (l_dimm_freq_min < 1013)
	{
          FAPI_ERR("Unsupported frequency:  DIMM Freq calculated < 1013 MHz");
	  FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_FREQ_CALCULATED);
	}
      else if (l_dimm_freq_min < 1266)
	{
	  // 1066 
	  l_selected_dimm_freq=1066;
	}
      else if (l_dimm_freq_min < 1520)
	{
	  // 1333
	  l_selected_dimm_freq=1333;
	}
      else if (l_dimm_freq_min < 1773)
	{
	  // 1600
	  l_selected_dimm_freq=1600;
	}
      else if (l_dimm_freq_min < 2026)
	{
	  // 1866
	  l_selected_dimm_freq=1866;
	}
      else if (l_dimm_freq_min < 2280)
	{
	  // 2133
	  l_selected_dimm_freq=2133;
	}
      else
	{
	  FAPI_ERR("Unsupported frequency:  DIMM Freq calculated > 2133 MHz: %d", l_dimm_freq_min);
	  FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_FREQ_CALCULATED);
	}
  }

  // set frequency in centaur attribute ATTR_MSS_FREQ
  if (!l_rc) 
  {
      l_rc = FAPI_ATTR_SET(ATTR_MSS_FREQ, &i_target_memb, l_selected_dimm_freq);
      if (l_rc) 
      {
	  return l_rc;
      }
      FAPI_INF( "Successfully Calculated Frequency: %d ",  l_selected_dimm_freq);
      FAPI_INF( "Successfully Calculated CL: %d ",  l_cas_latency);
      for (uint32_t k=0; k < l_mbaChiplets.size(); k++)
      {
	  l_rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_CL, &l_mbaChiplets[k], l_cas_latency);
	  if (l_rc) 
	  {
	      return l_rc;
	  }
      }
  }

  //all done.
  return l_rc;
}
