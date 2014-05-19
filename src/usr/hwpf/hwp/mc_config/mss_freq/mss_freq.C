/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_freq/mss_freq.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_freq.C,v 1.28 2014/04/30 19:32:56 jdsloat Exp $
/* File mss_freq.C created by JEFF SABROWSKI on Fri 21 Oct 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_freq.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME :   Jacob Sloat (jdsloat@us.ibm.com)
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
//  1.19   | jdsloat  | 01/30/13 | Added Check for l_spd_min_tck_max
//  1.20   | jdsloat  | 02/12/13 | Added path for freq_override
//  1.21   | jdsloat  | 02/12/13 | Added Debug messages
//  1.22   | jdsloat  | 06/27/13 | Fixed overridng RC error that results in coredump on no centaur SPD info.
//  1.23   | jdsloat  | 02/05/14 | Added support for DMI capable frequecies via ATTR_MSS_NEST_CAPABLE_FREQUENCIES
//  1.24   | jdsloat  | 02/18/14 | Added support for DDR4
//  1.25   | jdsloat  | 03/05/14 | RAS review Edits -- Error HW callouts
//  1.26   | jdsloat  | 03/12/14 | Fixed an assignment within a boolean expression.
//  1.27   | jdsloat  | 03/12/14 | Fixed inf loop bug associated with edit 1.26
//  1.28   | jdsloat  | 04/30/14 | Fixed a divide by 0 error opened up by RAS review Edits -- Error HW callouts v1.25
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

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
const uint8_t DDR4_MTB_DIVIDEND = 1;
const uint8_t DDR4_MTB_DIVISOR = 8;
const uint8_t DDR4_FTB_DIVIDEND = 1;
const uint8_t DDR4_FTB_DIVISOR = 1;



using namespace fapi;

fapi::ReturnCode mss_freq(const fapi::Target &i_target_memb)
{

    // Define attribute array size
    const uint8_t PORT_SIZE = 2;
    const uint8_t DIMM_SIZE = 2;

    fapi::ReturnCode l_rc;
    std::vector<fapi::Target> l_mbaChiplets;
    std::vector<fapi::Target> l_dimm_targets;
    std::vector<fapi::Target> l_dimm_targets_deconfig;
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
    uint8_t module_type_deconfig = 0;
    uint8_t module_type_group_1 = 0;
    uint8_t module_type_group_2 = 0;
    uint8_t module_type_group_1_total = 0;
    uint8_t module_type_group_2_total = 0;
    uint8_t num_ranks = 0;
    uint8_t num_ranks_total = 0;
    uint32_t  l_freq_override = 0;
    uint8_t l_override_path = 0;
    uint8_t l_nest_capable_frequencies = 0; 
    uint8_t l_spd_dram_dev_type;
    uint8_t l_spd_tb_mtb_ddr4=0;
    uint8_t l_spd_tb_ftb_ddr4=0;
    uint8_t l_spd_tckmax_ddr4=0;
    uint8_t cl_count_array[20];
    uint8_t highest_common_cl = 0;
    uint8_t highest_cl_count = 0;
    uint8_t lowest_common_cl = 0;
    uint32_t lowest_cl_count = 0xFFFFFFFF;

    for(uint8_t i=0;i<20;i++) 
    { 
        cl_count_array[i] = 0; // Initializing each element separately 
    } 
    do
    {
        // Get associated MBA's on this centaur                                                                                      
        l_rc=fapiGetChildChiplets(i_target_memb, fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
        if (l_rc)
        {
            FAPI_ERR("Error Getting MBA targets.");
            break;
        }
        // Loop through the 2 MBA's                                                                                                  
        for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
        {
            // Get a vector of DIMM targets                                                                                          
            l_rc = fapiGetAssociatedDimms(l_mbaChiplets[i], l_dimm_targets);
            if (l_rc)
            {
                FAPI_ERR("Error Getting DIMM targets.");
                break;
            }
            for (uint32_t j=0; j < l_dimm_targets.size(); j++)
            {

                l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &l_dimm_targets[j], l_spd_dram_dev_type);
                if (l_rc)
                {
                    FAPI_ERR("Unable to read SPD Dram Device Type.");
                    break;
                }
                if (l_spd_dram_dev_type == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4)
                {		
                    // DDR4 ONLY
                    FAPI_DBG("DDR4 detected");

                    l_rc = FAPI_ATTR_GET(ATTR_SPD_TIMEBASE_MTB_DDR4, &l_dimm_targets[j], l_spd_tb_mtb_ddr4);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read SPD DDR4 Medium Timebase");
                        break;
                    }

                    l_rc = FAPI_ATTR_GET(ATTR_SPD_TIMEBASE_FTB_DDR4, &l_dimm_targets[j], l_spd_tb_ftb_ddr4);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read SPD DDR4 Fine Timebase");
                        break;
                    }

                    l_rc = FAPI_ATTR_GET(ATTR_SPD_TCKMAX_DDR4, &l_dimm_targets[j], l_spd_tckmax_ddr4);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read SPD DDR4 TCK Max");
                        break;
                    }

                    if ( (l_spd_tb_mtb_ddr4 == 0)&&(l_spd_tb_ftb_ddr4 == 0))
                    {
                        // These are now considered constant within DDR4 
                        // If DDR4 spec changes to include other values, these const's need to be updated
                        l_spd_mtb_dividend = DDR4_MTB_DIVIDEND;
                        l_spd_mtb_divisor = DDR4_MTB_DIVISOR;	
                        l_spd_ftb_dividend = DDR4_FTB_DIVIDEND;
                        l_spd_ftb_divisor = DDR4_FTB_DIVISOR;
                    }
                    else
                    {

                        //Invalid due to the fact that JEDEC dictates that these should be zero.
                        // Log error and continue to next DIMM
                        FAPI_ERR("Invalid data received from SPD DDR4 MTB/FTB Timebase");
                        const uint8_t &MTB_DDR4 = l_spd_tb_mtb_ddr4;
                        const uint8_t &FTB_DDR4 = l_spd_tb_ftb_ddr4;
                        const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
                        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_SPD_DATA_DDR4);
                        fapiLogError(l_rc);
                        continue;
                    }

                }
                else
                {		
                    // DDR3 ONLY
                    FAPI_DBG("DDR3 detected");

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

                    l_rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVIDEND,  &l_dimm_targets[j], l_spd_ftb_dividend);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read the SPD FTB dividend");
                        break;
                    }
                    l_rc = FAPI_ATTR_GET(ATTR_SPD_FTB_DIVISOR,  &l_dimm_targets[j], l_spd_ftb_divisor);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read the SPD FTB divisor");
                        break;
                    }
                    if ( (l_spd_mtb_dividend == 0)||(l_spd_mtb_divisor == 0)||(l_spd_ftb_dividend == 0)||(l_spd_ftb_divisor == 0))
                    {
                        //Invalid due to the fact that JEDEC dictates that these should be non-zero.
                        // Log error and continue to next DIMM
                        FAPI_ERR("Invalid data received from SPD within MTB/FTB Dividend, MTB/FTB Divisor");
                        const uint8_t &MTB_DIVIDEND = l_spd_mtb_dividend;
                        const uint8_t &MTB_DIVISOR = l_spd_mtb_divisor;
                        const uint8_t &FTB_DIVIDEND = l_spd_ftb_dividend;
                        const uint8_t &FTB_DIVISOR = l_spd_ftb_divisor;
                        const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
                        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_SPD_DATA_DDR3);
                        fapiLogError(l_rc);
                        continue;
                    }
                }
                // common to both DDR3 & DDR4
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

                l_rc = FAPI_ATTR_GET(ATTR_MBA_PORT,  &l_dimm_targets[j], cur_mba_port);
                if (l_rc)
                {
                    FAPI_ERR("Unable to read the Port Info in order to determine configuration.");
                    break;
                }
                l_rc = FAPI_ATTR_GET(ATTR_MBA_DIMM,  &l_dimm_targets[j], cur_mba_dimm);
                if (l_rc)
                {
                    FAPI_ERR("Unable to read the DIMM Info in order to determine configuration.");
                    break;
                }
                l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE,  &l_dimm_targets[j], module_type);
                if (l_rc)
                {
                    FAPI_ERR("Unable to read the SPD module type.");
                    break;
                }
                // from dimm_spd_attributes.xml, R1 = 0x00, R2 = 0x01, R3 = 0x02, R4 = 0x03
                l_rc = FAPI_ATTR_GET(ATTR_SPD_NUM_RANKS,  &l_dimm_targets[j], num_ranks);
                if (l_rc)
                {
                    FAPI_ERR("Unable to read the SPD number of ranks");
                    break;
                }
                l_rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TAAMIN,  &l_dimm_targets[j], l_spd_taa_offset_FTB); 
                if (l_rc)
                {
                    FAPI_ERR("Unable to read the SPD TAA offset (FTB)");
                    break;
                }
                l_rc = FAPI_ATTR_GET(ATTR_SPD_FINE_OFFSET_TCKMIN,  &l_dimm_targets[j], l_spd_tck_offset_FTB);
                if (l_rc)
                {
                    FAPI_ERR("Unable to read the SPD TCK offset (FTB)");
                    break;
                }

                cur_dimm_spd_valid_u8array[cur_mba_port][cur_mba_dimm] = MSS_FREQ_VALID;

                if ((l_spd_min_tck_MTB == 0)||(l_spd_min_taa_MTB == 0))
                {
                    //Invalid due to the fact that JEDEC dictates that these should be non-zero.
                    // Log error and continue to next DIMM
                    FAPI_ERR("Invalid data received from SPD within TCK Min, or TAA Min");
                    const uint8_t &MIN_TCK = l_spd_min_tck_MTB;
                    const uint8_t &MIN_TAA = l_spd_min_taa_MTB;
                    const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
		            const fapi::Target &TARGET = i_target_memb;
                    FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_SPD_DATA_COMMON);
                    fapiLogError(l_rc);
                    continue;
                }

                // Calc done on PS units (the multiplication of 1000) to avoid rounding errors.
                // Frequency listed with multiplication of 2 as clocking data on both +- edges
                l_spd_min_tck =  ( 1000 * l_spd_min_tck_MTB * l_spd_mtb_dividend ) / l_spd_mtb_divisor;
                l_spd_min_taa =  ( 1000 * l_spd_min_taa_MTB * l_spd_mtb_dividend ) / l_spd_mtb_divisor;

                FAPI_INF("min tck = %i, taa = %i", l_spd_min_tck, l_spd_min_taa);
                FAPI_INF("FTB tck 0x%x, taa 0x%x",l_spd_tck_offset_FTB,l_spd_taa_offset_FTB);
                // Adjusting by tck offset -- tck offset represented in 2's compliment as it could be positive or negative adjustment
                // No multiplication of 1000 as it is already in picoseconds.
                if (l_spd_tck_offset_FTB & 0x80)
                {
                    l_spd_tck_offset_FTB = ~( l_spd_tck_offset_FTB ) + 1;
                    l_spd_tck_offset = (l_spd_tck_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
                    l_spd_min_tck =  l_spd_min_tck - l_spd_tck_offset;
                    FAPI_INF("FTB minus offset %i, min tck %i",l_spd_tck_offset,l_spd_min_tck);
                }
                else
                {
                    l_spd_tck_offset = (l_spd_tck_offset_FTB  * l_spd_ftb_dividend )  / l_spd_ftb_divisor;
                    l_spd_min_tck =  l_spd_min_tck + l_spd_tck_offset;
                    FAPI_INF("FTB plus offset %i, min tck %i",l_spd_tck_offset,l_spd_min_tck);
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
                    // Log error and continue to next DIMM
                    FAPI_ERR("Invalid data received from SPD causing TCK Min or TAA Min to be 0");
                    const uint8_t &MIN_TCK = l_spd_min_tck_MTB;
                    const uint8_t &MIN_TAA = l_spd_min_taa_MTB;
                    const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
		            const fapi::Target &TARGET = i_target_memb;
                    FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_SPD_DATA_COMMON);
                    fapiLogError(l_rc);
                    continue;
                }
                l_dimm_freq_calc = 2000000 / l_spd_min_tck;

                FAPI_INF( "TAA(ps): %d TCK(ps): %d Calc'ed Freq for this dimm: %d", l_spd_min_taa, l_spd_min_tck, l_dimm_freq_calc);

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

                if ( l_spd_cas_lat_supported & 0x00000001 )
                {
                    cl_count_array[0]++;
                }
                else if ( l_spd_cas_lat_supported & 0x00000002 )
                {
                    cl_count_array[1]++;
                }
                else if ( l_spd_cas_lat_supported & 0x00000004 )
                {
                    cl_count_array[2]++;
                }
                else if ( l_spd_cas_lat_supported & 0x00000008 )
                {
                    cl_count_array[3]++;	
                }
                else if ( l_spd_cas_lat_supported & 0x00000010 )
                {
                    cl_count_array[4]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00000020 )
                {
                    cl_count_array[5]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00000040 )
                {
                    cl_count_array[6]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00000080 )
                {
                    cl_count_array[7]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00000100 )
                {
                    cl_count_array[8]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00000200 )
                {
                    cl_count_array[9]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00000400)
                {
                    cl_count_array[10]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00000800 )
                {
                    cl_count_array[11]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00001000 )
                {
                    cl_count_array[12]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00002000 )
                {
                    cl_count_array[13]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00004000)
                {
                    cl_count_array[14]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00008000 )
                {
                    cl_count_array[15]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00010000 )
                {
                    cl_count_array[16]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00020000 )
                {
                    cl_count_array[17]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00040000)
                {
                    cl_count_array[18]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00080000 )
                {
                    cl_count_array[19]++;		
                }
                else if ( l_spd_cas_lat_supported & 0x00100000 )
                {
                    cl_count_array[20]++;		
                }


                l_spd_cas_lat_supported_all = l_spd_cas_lat_supported_all & l_spd_cas_lat_supported;


                num_ranks_total = num_ranks_total + num_ranks + 1;

                if ( (module_type_group_1 == module_type) || (module_type_group_1 == 0) ) 
                {
                    module_type_group_1 = module_type;
                    module_type_group_1_total++;
                }
                else if ( (module_type_group_2 == module_type) || (module_type_group_2 == 0) ) 
                {
                    module_type_group_2 = module_type;
                    module_type_group_2_total++;
                }

            } // DIMM
            if (l_rc)
            {
                break;
            }
        } // MBA
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }
        // Check for DIMM Module Type Mixing
        if (module_type_group_2 != 0)
        {
            if (module_type_group_1_total > module_type_group_2_total)
            {
                module_type_deconfig = module_type_group_1;
            }
            else
            {
                module_type_deconfig = module_type_group_2;
            }

            // Loop through the 2 MBA's                                                                                                  
            for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
            {
                // Get a vector of DIMM targets                                                                                          
                l_rc = fapiGetAssociatedDimms(l_mbaChiplets[i], l_dimm_targets);
                if (l_rc)
                {
                    FAPI_ERR("Error Getting DIMM targets.");
                    break;
                }
                for (uint32_t j=0; j < l_dimm_targets.size(); j++)
                {
                    l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE,  &l_dimm_targets[j], module_type);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read the SPD module type.");
                        break;
                    }
                    if (module_type == module_type_deconfig)
                    {
                        const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
                        const uint8_t &MODULE_TYPE = module_type;
                        FAPI_ERR("Mixing of DIMM Module Types (%d, %d) deconfiguring minority type: %d", module_type_group_1, module_type_group_2, module_type_deconfig);
                        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MODULE_TYPE_MIX);
                        fapiLogError(l_rc);
                    }
                } // DIMM
                if (l_rc)
                {
                    break;
                }
            } // MBA
        } // if
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }
        FAPI_INF( "Highest Supported Frequency amongst DIMMs: %d", l_dimm_freq_min);
        FAPI_INF( "Minimum TAA(ps) amongst DIMMs: %d Minimum TCK(ps) amongst DIMMs: %d", l_spd_min_taa_max, l_spd_min_tck_max);

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


        FAPI_INF( "PLUG CONFIG(from SPD): %d, Type of Dimm(from SPD): 0x%02X, Num Ranks(from SPD): %d",  plug_config, module_type, num_ranks);

        // Impose configuration limitations
        // Single Drop RDIMMs Cnfgs cannot run faster than 1333 unless it only has 1 rank
        if ((module_type_group_1 == ENUM_ATTR_SPD_MODULE_TYPE_RDIMM)&&(plug_config == MSS_FREQ_SINGLE_DROP)&&(num_ranks_total > 1)&&(l_dimm_freq_min > 1333))
        {
            l_dimm_freq_min = 1333;
            l_spd_min_tck_max = 1500;
            FAPI_INF( "Single Drop RDIMM with more than 1 Rank Cnfg limitation.  New Freq: %d", l_dimm_freq_min); 
        }
        // Double Drop RDIMMs Cnfgs cannot run faster than 1333 with 4 ranks total
        else if ((module_type_group_1 == ENUM_ATTR_SPD_MODULE_TYPE_RDIMM)&&(plug_config == MSS_FREQ_DUAL_DROP)&&(num_ranks_total == 4)&&(l_dimm_freq_min > 1333))
        {
            l_dimm_freq_min = 1333;
            l_spd_min_tck_max = 1500;
            FAPI_INF( "Dual Drop RDIMM with more than 4 Rank Cnfg limitation.  New Freq: %d", l_dimm_freq_min); 
        }
        // Double Drop RDIMMs Cnfgs cannot run faster than 1066 with 8 ranks total
        else if ((module_type_group_1 == ENUM_ATTR_SPD_MODULE_TYPE_RDIMM)&&(plug_config == MSS_FREQ_DUAL_DROP)&&(num_ranks_total == 8)&&(l_dimm_freq_min > 1066))
        {
            l_dimm_freq_min = 1066;
            l_spd_min_tck_max = 1875;
            FAPI_INF( "Dual Drop RDIMM with more than 8 Rank Cnfg limitation.  New Freq: %d", l_dimm_freq_min); 
        }
        // Single Drop LRDIMMs Cnfgs cannot run faster than 1333 with greater than 2 ranks
        else if ((module_type_group_1 == ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM)&&(plug_config == MSS_FREQ_SINGLE_DROP)&&(num_ranks_total > 2)&&(l_dimm_freq_min > 1333))
        {
            l_dimm_freq_min = 1333;
            l_spd_min_tck_max = 1500;
            FAPI_INF( "Single Drop LRDIMM with more than 2 Rank Cnfg limitation.  New Freq: %d", l_dimm_freq_min); 
        }
        // Dual Drop LRDIMMs Cnfgs cannot run faster than 1333
        else if ((module_type_group_1 == ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM)&&(plug_config == MSS_FREQ_DUAL_DROP)&&(l_dimm_freq_min > 1333))
        {
            l_dimm_freq_min = 1333;
            l_spd_min_tck_max = 1500;
            FAPI_INF( "Dual Drop LRDIMM Cnfg limitation.  New Freq: %d", l_dimm_freq_min); 
        }

        if ( l_spd_min_tck_max == 0)
        {
	        // Loop through the 2 MBA's                                                                                                  
            for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
            {
                // Get a vector of DIMM targets                                                                                          
                l_rc = fapiGetAssociatedDimms(l_mbaChiplets[i], l_dimm_targets);
                if (l_rc)
                {
                    FAPI_ERR("Error Getting DIMM targets.");
                    break;
                }
                for (uint32_t j=0; j < l_dimm_targets.size(); j++)
                {
                    l_rc = FAPI_ATTR_GET(ATTR_SPD_TCKMIN, &l_dimm_targets[j], l_spd_min_tck_MTB);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read SPD Minimum TCK (Min Clock Cycle).");
                        break;
                    }
                    if ( l_spd_min_tck_MTB == 0 )
                    {
                        FAPI_ERR("l_spd_min_tck_max = 0 unable to calculate freq or cl.  Possibly no centaurs configured. ");
                        const uint32_t &MIN_TCK = l_spd_min_tck_max;
                        const uint32_t &MIN_TAA = l_spd_min_taa_max;
                        const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
                        const fapi::Target &TARGET = i_target_memb;
                        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_SPD_DATA_COMMON);
                        fapiLogError(l_rc);
                    }
                } // DIMM
                if (l_rc)
                {
                    break;
                }
	        } // MBA
        } // if
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }
        if (!l_rc)
        {
            l_rc = FAPI_ATTR_GET(ATTR_MSS_FREQ_OVERRIDE,  &i_target_memb, l_freq_override); 
            if ( l_freq_override != 0)
            {
                // The relationship is as such
                // l_dimm_freq_min = 2000000 / l_spd_min_tck_max

                if (l_freq_override == 1866)
                {
                    l_dimm_freq_min = 1866;
                    l_spd_min_tck_max = 1072;
                }

                if (l_freq_override == 1600)
                {
                    l_dimm_freq_min = 1600;
                    l_spd_min_tck_max = 1250;
                }

                if (l_freq_override == 1333)
                {
                    l_dimm_freq_min = 1333;
                    l_spd_min_tck_max = 1500;
                }

                if (l_freq_override == 1066)
                {
                    l_dimm_freq_min = 1066;
                    l_spd_min_tck_max = 1875;
                }

                FAPI_INF( "Override Frequency Detected: %d", l_dimm_freq_min); 
            }
        }



        //If no common supported CL get rid of the minority DIMMs
        if ((l_spd_cas_lat_supported_all == 0) && (!l_rc))
        {
            for(uint8_t i=0;i<20;i++) 
            { 
                if (cl_count_array[i] > highest_cl_count)
                {
                    highest_common_cl = i; 
                }
            } 


            // Loop through the 2 MBA's                                                                                                  
            for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
            {
                // Get a vector of DIMM targets                                                                                          
                l_rc = fapiGetAssociatedDimms(l_mbaChiplets[i], l_dimm_targets);
                if (l_rc)
                {
                    FAPI_ERR("Error Getting DIMM targets.");
                    break;
                }
                for (uint32_t j=0; j < l_dimm_targets.size(); j++)
                {
                    l_rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED, &l_dimm_targets[j], l_spd_cas_lat_supported);
                    if (l_rc)
                    {
                        FAPI_ERR("Unable to read SPD Supported CAS Latencies.");
                        break;
                    }
                    if ( !(l_spd_cas_lat_supported & 0x0000001 << highest_common_cl) )
                    {
                        const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
                        const uint32_t &CL_SUPPORTED = l_spd_cas_lat_supported;
                        FAPI_ERR("No common supported CAS latencies between DIMMS.");
                        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_NO_COMMON_SUPPORTED_CL);
                        fapiLogError(l_rc);
                    }
                } // DIMM
                if (l_rc)
                {
                    break;
                }
            } // MBA
        } // if
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }
        if (!l_rc) 
        {

            //Determine a proposed CAS latency
            l_cas_latency = l_spd_min_taa_max / l_spd_min_tck_max;

            FAPI_INF( "CL = TAA / TCK ... TAA(ps): %d TCK(ps): %d", l_spd_min_taa_max, l_spd_min_tck_max);
            FAPI_INF( "Calculated CL: %d", l_cas_latency);

            if ( l_spd_min_taa_max % l_spd_min_tck_max)
            {
                l_cas_latency++;
                FAPI_INF( "After rounding up ... CL: %d", l_cas_latency);
            }

            l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;

            // If the CL proposed is not supported or the TAA exceeds TAA max
            // Spec defines tAAmax as 20 ns for all DDR3 speed grades.
            // Break loop if we have an override condition without a solution.

            while (    ( (!( l_spd_cas_lat_supported_all & (0x00000001<<(l_cas_latency-4)))) || (l_cl_mult_tck > 20000) )
                    && ( l_override_path == 0 ) )
            {

                FAPI_INF( "Warning calculated CL is not supported in VPD.  Searching for a new CL.");

                // If not supported, increment the CL up to 18 (highest supported CL) looking for Supported CL 
                while ((!( l_spd_cas_lat_supported_all & (0x00000001<<(l_cas_latency-4))))&&(l_cas_latency < 18))
                {
                    l_cas_latency++;
                }

                // If still not supported CL or TAA is > 20 ns ... pick a slower TCK and start again
                l_cl_mult_tck = l_cas_latency * l_spd_min_tck_max;

                // Do not move freq if using an override freq.  Just continue.  Hence the overide in this if statement
                if ( ( (!( l_spd_cas_lat_supported_all & (0x00000001<<(l_cas_latency-4)))) || (l_cl_mult_tck > 20000) )
                        && ( l_freq_override == 0) )
                {
                    FAPI_INF( "No Supported CL works for calculating frequency.  Lowering frequency and trying CL Algorithm again.");

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
                        //Therefore we will deconfig the minority dimms.
                        for(uint8_t i=0;i<20;i++) 
                        { 
                            if (cl_count_array[i] > lowest_cl_count)
                            {
                                lowest_common_cl = i; 
                            }
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
                                l_rc = FAPI_ATTR_GET(ATTR_SPD_CAS_LATENCIES_SUPPORTED, &l_dimm_targets[j], l_spd_cas_lat_supported);
                                if (l_rc)
                                {
                                    FAPI_ERR("Unable to read SPD Supported CAS Latencies.");
                                    break;
                                }
                                if (l_spd_cas_lat_supported & 0x0000001 << lowest_common_cl)
                                {
                                    const fapi::Target &DIMM_TARGET = l_dimm_targets[j];
                                    const uint32_t &CL_SUPPORTED = l_spd_cas_lat_supported;
                                    FAPI_ERR("Lowered Frequency to TCLK MIN finding no supported CL without exceeding TAA MAX.");
                                    FAPI_SET_HWP_ERROR(l_rc, RC_MSS_EXCEED_TAA_MAX_NO_CL );
                                    fapiLogError(l_rc);
                                }
                            } // DIMM
                            if (l_rc)
                            {
                                break;
                            }
                        } // MBA
                    } // else
                    if (l_rc)
                    {
                        // Break out of while loop
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

                } // if
                // Need to break the loop in case we reach this condition because no longer modify freq and CL
                // With an overrride
                if ( ( (!( l_spd_cas_lat_supported_all & (0x00000001<<(l_cas_latency-4)))) || (l_cl_mult_tck > 20000) )
                        && ( l_freq_override != 0) )
                {

                    FAPI_INF( "No Supported CL works for override frequency.  Using override frequency with an unsupported CL.");
                    l_override_path = 1;
                }
            } // while
        } // if
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }
        //bucketize dimm freq.
        if (!l_rc) 
        {
            if (l_dimm_freq_min < 1013)
            {
                FAPI_ERR("Unsupported frequency:  DIMM Freq calculated < 1013 MHz");
                const uint32_t &DIMM_MIN_FREQ = l_dimm_freq_min;
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_FREQ_CALCULATED);
                break;
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
                const uint32_t &DIMM_MIN_FREQ = l_dimm_freq_min;
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_UNSUPPORTED_FREQ_CALCULATED);
                break;
            }
        }

        if (!l_rc)
        {
            // 0x03 = capable of both 8.0G/9.6G, 0x01 = capable of 8.0G, 0x02 = capable 9.6G
            if ( l_selected_dimm_freq == 1066)
            {
                l_nest_capable_frequencies = 0x01;
                l_rc = FAPI_ATTR_SET(ATTR_MSS_NEST_CAPABLE_FREQUENCIES, &i_target_memb, l_nest_capable_frequencies);
            }
            else
            {
                l_nest_capable_frequencies = 0x02;
                l_rc = FAPI_ATTR_SET(ATTR_MSS_NEST_CAPABLE_FREQUENCIES, &i_target_memb, l_nest_capable_frequencies);
            }

        }

        // set frequency in centaur attribute ATTR_MSS_FREQ
        if (!l_rc) 
        {
            l_rc = FAPI_ATTR_SET(ATTR_MSS_FREQ, &i_target_memb, l_selected_dimm_freq);
            if (l_rc) 
            {
                break;
            }
            FAPI_INF( "Final Chosen Frequency: %d ",  l_selected_dimm_freq);
            FAPI_INF( "Final Chosen CL: %d ",  l_cas_latency);
            for (uint32_t k=0; k < l_mbaChiplets.size(); k++)
            {
                l_rc = FAPI_ATTR_SET(ATTR_EFF_DRAM_CL, &l_mbaChiplets[k], l_cas_latency);
                if (l_rc) 
                {
                    break;
                }
            }
        }
    }while(0);
    //all done.
    return l_rc;
}

