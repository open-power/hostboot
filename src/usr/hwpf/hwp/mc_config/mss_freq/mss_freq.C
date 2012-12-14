/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_freq/mss_freq.C $              */
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
// $Id: mss_freq.C,v 1.18 2012/09/07 22:22:08 jdsloat Exp $
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
//  1.15   | jdsloat  | 06/04/12 | Added a Configuration check
//  1.16   | jdsloat  | 06/08/12 | Updates per Firware request
//  1.17   | bellows  | 07/16/12 | added in Id tag
//  1.18   | jdsloat  | 09/07/12 | Added FTB offset to TAA and TCK
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

//----------------------------------------------------------------------
// ENUMs   
//----------------------------------------------------------------------
enum {
   MSS_FREQ_EMPTY = 0,
   MSS_FREQ_SINGLE_DROP = 1,
   MSS_FREQ_DUAL_DROP = 2,
   MSS_FREQ_VALID = 255,
};


using namespace fapi;

fapi::ReturnCode mss_freq(const fapi::Target &i_target_memb)
{

     // Define attribute array size
    const uint8_t PORT_SIZE = 2;
    const uint8_t DIMM_SIZE = 2;

  fapi::ReturnCode l_rc;
  std::vector<fapi::Target> l_mbaChiplets;
  std::vector<fapi::Target> l_dimm_targets;
  uint8_t l_spd_mtb_dividend=0;
  uint8_t l_spd_mtb_divisor=0;
  uint8_t l_spd_ftb_dividend=0;
  uint8_t l_spd_ftb_divisor=0;
  uint32_t l_dimm_freq_calc=0;
  uint32_t l_dimm_freq_min=9999;
  uint8_t l_spd_min_tck_MTB=0;
  uint8_t l_spd_tck_offset_FTB=0;
  uint8_t l_spd_tck_offset=0;
  uint32_t l_spd_min_tck=0;
  uint32_t l_spd_min_tck_max=0;
  uint8_t  l_spd_min_taa_MTB=0;
  uint8_t  l_spd_taa_offset_FTB=0;
  uint8_t  l_spd_taa_offset=0;
  uint32_t l_spd_min_taa=0;
  uint32_t l_spd_min_taa_max=0;
  uint32_t l_selected_dimm_freq=0;
  uint32_t l_spd_cas_lat_supported = 0xFFFFFFFF;
  uint32_t l_spd_cas_lat_supported_all = 0xFFFFFFFF;
  uint8_t l_cas_latency = 0;
  uint32_t l_cl_mult_tck = 0;
  uint8_t cur_mba_port = 0;
  uint8_t cur_mba_dimm = 0;
  uint8_t cur_dimm_spd_valid_u8array[PORT_SIZE][DIMM_SIZE] = {{0}};
  uint8_t plug_config = 0;
  uint8_t module_type = 0;
  uint8_t module_type_all = 0;
  uint8_t num_ranks = 0;
  uint8_t num_ranks_total = 0;

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

	  l_rc = FAPI_ATTR_GET(ATTR_MBA_PORT,  &l_dimm_targets[j], cur_mba_port); if(l_rc) return l_rc;
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read the Port Info in order to determine configuration.");
	      break;
	    }
	  l_rc = FAPI_ATTR_GET(ATTR_MBA_DIMM,  &l_dimm_targets[j], cur_mba_dimm); if(l_rc) return l_rc;
	  if (l_rc)
	    {
	      FAPI_ERR("Unable to read the DIMM Info in order to determine configuration.");
	      break;
	    }
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE,  &l_dimm_targets[j], module_type); if(l_rc) return l_rc;
	  if (l_rc)
	  {
	      FAPI_ERR("Unable to read the SPD module type.");
	      break;
	  }
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_NUM_RANKS,  &l_dimm_targets[j], num_ranks); if(l_rc) return l_rc;
	  if (l_rc)
	  {
	      FAPI_ERR("Unable to read the SPD number of ranks");
	      break;
	  }
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TAAMIN,  &l_dimm_targets[j], l_spd_taa_offset_FTB); if(l_rc) return l_rc;
	  if (l_rc)
	  {
	      FAPI_ERR("Unable to read the SPD TAA offset (FTB)");
	      break;
	  }
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TCKMIN,  &l_dimm_targets[j], l_spd_tck_offset_FTB); if(l_rc) return l_rc;
	  if (l_rc)
	  {
	      FAPI_ERR("Unable to read the SPD TCK offset (FTB)");
	      break;
	  }
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVIDEND,  &l_dimm_targets[j], l_spd_ftb_dividend); if(l_rc) return l_rc;
	  if (l_rc)
	  {
	      FAPI_ERR("Unable to read the SPD FTB dividend");
	      break;
	  }
	  l_rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVISOR,  &l_dimm_targets[j], l_spd_ftb_divisor); if(l_rc) return l_rc;
	  if (l_rc)
	  {
	      FAPI_ERR("Unable to read the SPD FTB divisor");
	      break;
	  }

	  cur_dimm_spd_valid_u8array[cur_mba_port][cur_mba_dimm] = MSS_FREQ_VALID;

	  if ((l_spd_min_tck_MTB == 0)||(l_spd_mtb_dividend == 0)||(l_spd_mtb_divisor == 0)||(l_spd_min_taa_MTB == 0)||(l_spd_ftb_dividend == 0)||(l_spd_ftb_divisor == 0))
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

	  // Adjusting by tck offset -- tck offset represented in 2's compliment as it could be positive or negative adjustment
	  // No multiplication of 1000 as it is already in picoseconds.
	  if (l_spd_tck_offset_FTB & 0x80)
	  {
	      l_spd_tck_offset_FTB = ~( l_spd_tck_offset_FTB ) + 1;
	      l_spd_tck_offset = (l_spd_tck_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
	      l_spd_min_tck =  l_spd_min_tck - l_spd_tck_offset;
	  }
	  else
	  {
	      l_spd_tck_offset = (l_spd_tck_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
	      l_spd_min_tck =  l_spd_min_tck + l_spd_tck_offset;
	  }

	  // Adjusting by taa offset -- taa offset represented in 2's compliment as it could be positive or negative adjustment
	  if (l_spd_taa_offset_FTB & 0x80)
	  {
	      l_spd_taa_offset_FTB = ~( l_spd_taa_offset_FTB) + 1;
	      l_spd_taa_offset = (l_spd_taa_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
	      l_spd_min_taa =  l_spd_min_taa - l_spd_taa_offset;
	  }
	  else
	  {
	      l_spd_taa_offset = (l_spd_taa_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
	      l_spd_min_taa =  l_spd_min_taa + l_spd_taa_offset;
	  }

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
	  num_ranks_total = num_ranks_total + num_ranks;
	  if (module_type_all == 0)
	  {
	      module_type_all = module_type;
	  }
	  else if (module_type_all != module_type)
	  {
	      FAPI_ERR("Mixing of DIMM Module Types (%d, %d)", module_type_all, module_type);
	      FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MODULE_TYPE_MIX);
	  }

      }
      if (l_rc)
      {
	  break;
      }
  }

  //Determining the cnfg for imposing any cnfg speed limitations
  if ((cur_dimm_spd_valid_u8array[0][0] == MSS_FREQ_VALID) && (cur_dimm_spd_valid_u8array[0][1] == MSS_FREQ_VALID))
  {
      plug_config = MSS_FREQ_DUAL_DROP;
  }
  else if ((cur_dimm_spd_valid_u8array[0][0] == MSS_FREQ_VALID) && (cur_dimm_spd_valid_u8array[0][1] == MSS_FREQ_EMPTY))
  {
      plug_config = MSS_FREQ_SINGLE_DROP;
  }
  else
  {
      plug_config = MSS_FREQ_EMPTY;
  }

  // Impose configuration limitations
  // Single Drop RDIMMs Cnfgs cannot run faster than 1333 unless it only has 1 rank
  if ((module_type_all == ENUM_ATTR_SPD_MODULE_TYPE_RDIMM)&&(plug_config == MSS_FREQ_SINGLE_DROP)&&(num_ranks_total > 1)&&(l_dimm_freq_min > 1333))
  {
      l_dimm_freq_min = 1333;
      l_spd_min_tck_max = 1500;
  }
  // Double Drop RDIMMs Cnfgs cannot run faster than 1333 with 4 ranks total
  else if ((module_type_all == ENUM_ATTR_SPD_MODULE_TYPE_RDIMM)&&(plug_config == MSS_FREQ_DUAL_DROP)&&(num_ranks_total == 4)&&(l_dimm_freq_min > 1333))
  {
      l_dimm_freq_min = 1333;
      l_spd_min_tck_max = 1500;
  }
  // Double Drop RDIMMs Cnfgs cannot run faster than 1066 with 8 ranks total
  else if ((module_type_all == ENUM_ATTR_SPD_MODULE_TYPE_RDIMM)&&(plug_config == MSS_FREQ_DUAL_DROP)&&(num_ranks_total == 8)&&(l_dimm_freq_min > 1066))
  {
      l_dimm_freq_min = 1066;
      l_spd_min_tck_max = 1875;
  }
  // Single Drop LRDIMMs Cnfgs cannot run faster than 1333 with greater than 2 ranks
  else if ((module_type_all == ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM)&&(plug_config == MSS_FREQ_SINGLE_DROP)&&(num_ranks_total > 2)&&(l_dimm_freq_min > 1333))
  {
      l_dimm_freq_min = 1333;
      l_spd_min_tck_max = 1500;
  }
  // Dual Drop LRDIMMs Cnfgs cannot run faster than 1333
  else if ((module_type_all == ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM)&&(plug_config == MSS_FREQ_DUAL_DROP)&&(l_dimm_freq_min > 1333))
  {
      l_dimm_freq_min = 1333;
      l_spd_min_tck_max = 1500;
  }

  FAPI_INF( "PLUG CONFIG: %d Type O' Dimm: 0x%02X Num Ranks: %d",  plug_config, module_type, num_ranks);

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
