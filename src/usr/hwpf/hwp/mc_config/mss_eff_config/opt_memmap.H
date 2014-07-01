/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/opt_memmap.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: opt_memmap.H,v 1.9 2014-06-19 14:06:35 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/opt_memmap.H,v $      */


//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : opt_memmap.H
// *! DESCRIPTION : Layout non-mirrored/mirrored address map (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *! BACKUP NAME : ???           Email: ???@us.ibm.com
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.9    | dcrowell | 06/19/14| Remove OPT_MEMMAP_OFFSET_ORIGIN
//  1.7    | jmcgill  | 07/10/13| Update to match new attributes, selective
//         |          |         | aligment policy changes
//  1.6    | jmcgill  | 05/24/13| Correct index name
//  1.5    | jmcgill  | 05/23/13| Address FW review issues
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
const uint64_t OPT_MEMMAP_TB = 0x0000010000000000ULL;

// default origin for non-mirrored/mirrored address regions
const uint64_t OPT_MEMMAP_BASE_ORIGIN      = 0;                     // 0
const uint64_t OPT_MEMMAP_SELECTIVE_ORIGIN = 0x0000080000000000LL;  // 8TB

// maximum non-mirrored/mirrored regions supported
const uint8_t OPT_MEMMAP_MAX_NM_REGIONS = 8;
const uint8_t OPT_MEMMAP_MAX_M_REGIONS  = 4;


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
