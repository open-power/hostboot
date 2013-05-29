/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/opt_memmap.H $      */
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
// $Id: opt_memmap.H,v 1.4 2013/05/06 15:14:25 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/opt_memmap.H,v $      */


//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.4    | jmcgill  | 04/28/13| Shift constant definitions
//  1.3    | vanlee   | 02/20/13| Added i_init parameter
//  1.2    | vanlee   | 01/04/13| Added version string
//  1.1    | vanlee   | 12/01/12| Initial version

#ifndef MSS_OPT_MEMMAP_H_
#define MSS_OPT_MEMMAP_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// conversion factor definitions
const uint64_t OPT_MEMMAP_GB = 0x0000000040000000ULL;

// default origin for non-mirrored/mirrored address regions
const uint64_t OPT_MEMMAP_BASE_ORIGIN   = 0;                     // 0
const uint64_t OPT_MEMMAP_OFFSET_ORIGIN = 0x0002000000000000LL;  // 512TB

// maximum non-mirrored/mirrored regions supported
const uint8_t OPT_MEMMAP_MAX_NM_REGIONS = 8;
const uint8_t OPT_MEMMAP_MAX_M_REGIONS  = 4;

// attribute index constants
// first array dimension (group ID)
const uint8_t OPT_MEMMAP_GROUP_32_NM_START_INDEX = 0;
const uint8_t OPT_MEMMAP_GROUP_32_NM_END_INDEX   = 7;
const uint8_t OPT_MEMMAP_GROUP_32_M_START_INDEX  = 8;
const uint8_t OPT_MEMMAP_GROUP_32_M_END_INDEX    = 15;

const uint8_t OPT_MEMMAP_GROUP_32_DIM1 = (OPT_MEMMAP_GROUP_32_M_END_INDEX-
                                          OPT_MEMMAP_GROUP_32_NM_START_INDEX)+1;

// second array dimension (group definition)
const uint8_t OPT_MEMMAP_GROUP_32_MCS_SIZE_INDEX      = 0;
const uint8_t OPT_MEMMAP_GROUP_32_MCS_IN_GROUP_INDEX  = 1;
const uint8_t OPT_MEMMAP_GROUP_32_SIZE_INDEX          = 2;
const uint8_t OPT_MEMMAP_GROUP_32_BASE_INDEX          = 3;
const uint8_t OPT_MEMMAP_GROUP_32_MEMBERS_START_INDEX = 4;
const uint8_t OPT_MEMMAP_GROUP_32_MEMBERS_END_INDEX   = 11;
const uint8_t OPT_MEMMAP_GROUP_32_ALT_VALID_INDEX     = 12;
const uint8_t OPT_MEMMAP_GROUP_32_ALT_SIZE_INDEX      = 13;
const uint8_t OPT_MEMMAP_GROUP_32_ALT_BASE_INDEX      = 14;
const uint8_t OPT_MEMMAP_GROUP_32_LARGEST_MBA_INDEX   = 15;

const uint8_t OPT_MEMMAP_GROUP_32_DIM2 = (OPT_MEMMAP_GROUP_32_LARGEST_MBA_INDEX-
                                          OPT_MEMMAP_GROUP_32_MCS_SIZE_INDEX)+1;


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*opt_memmap_FP_t)(std::vector<fapi::Target> & i_procs,
                                            bool i_init);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

// i_init = true  : initialize all ATTR_PROC_MEM_BASE attributes to 0
//        = false : perform memory map optimization
fapi::ReturnCode opt_memmap(std::vector<fapi::Target> & i_procs, bool i_init);


} // extern "C"

#endif // MSS_OPT_MEMMAP_H_
