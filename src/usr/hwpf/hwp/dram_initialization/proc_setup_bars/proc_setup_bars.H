/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/proc_setup_bars.H $ */
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
// $Id: proc_setup_bars.H,v 1.17 2014/08/05 20:43:46 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_setup_bars.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_setup_bars.H
// *! DESCRIPTION : Program nest base address registers (BARs) (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *! Program nest unit BAR registers, driven by attributes representing system
// *! memory map (including MMIO).
// *!
// *! High level execution flow:
// *!     proc_setup_bars()
// *!         proc_setup_bars_process_chips()
// *!             proc_setup_bars_process_chip()
// *!                 proc_fab_smp_get_pcie_dsmp_mux_attrs()
// *!                 proc_fab_smp_get_node_id_attr()
// *!                 proc_fab_smp_get_chip_id_attr()
// *!                 proc_setup_bars_get_bar_attrs()
// *!                     proc_setup_bars_get_memory_range_attrs (non-mirrored)
// *!                     proc_setup_bars_get_memory_range_attrs (mirrored)
// *!                     proc_setup_bars_get_range_attrs (foreign, near)
// *!                     proc_setup_bars_get_range_attrs (foreign, far)
// *!                     proc_setup_bars_get_range_attrs (psi)
// *!                     proc_setup_bars_get_range_attrs (fsp)
// *!                     proc_setup_bars_get_range_attrs (fsp mmio mask)
// *!                     proc_setup_bars_get_range_attrs (intp)
// *!                     proc_setup_bars_get_range_attrs (nx)
// *!                     proc_setup_bars_get_range_attrs (as)
// *!                     proc_setup_bars_get_range_attrs (pcie)
// *!             proc_setup_bars_insert_chip()
// *!         proc_setup_bars_write_bars()
// *!             proc_setup_bars_write_local_chip_region_bars()
// *!             proc_setup_bars_write_local_node_region_bars()
// *!             proc_setup_bars_find_remote_node()
// *!             proc_setup_bars_write_remote_node_region_bars()
// *!             proc_setup_bars_write_foreign_region_bars()
// *!
// *! Platform Notes:
// *!     This HWP has multiple IPL use cases. In all cases the HWP input
// *!     is expected to contain an entry for each chip in the SMP at the
// *!     time/scope of the invocation:
// *!
// *!         1. HBI (drawer scope):
// *!            All local chip/local node resources should be initialized
// *!            at this time (HWP boolean flag controlling this function
// *!            set to true).
// *!
// *!            All A links active in the scope of the drawer should be
// *!            reflected in the per-chip HWP input structures.
// *!
// *!         2. FSP (drawer integration):
// *!            All local chip/local node resources should already have
// *!            been initialized in each drawer, so the HWP boolean flag
// *!            controlling this function should be set to false.
// *!
// *!            Only 'new' A links which cross previously initialized
// *!            drawers should be reflected in the per-chip HWP input
// *!            structures.
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_SETUP_BARS_H_
#define _PROC_SETUP_BARS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <vector>
#include <map>
#include <fapi.H>
#include "proc_fab_smp.H"
#include "p8_scom_addresses.H"


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// HWP argument structure defining properties of this chip
// and links which should be considered in this invocation (A/F)
struct proc_setup_bars_proc_chip
{
    // target for this chip
    fapi::Target this_chip;

    // targets defining A link connected chips
    // qualify which remote node based BAR resources should be initalized on
    // this chip
    fapi::Target a0_chip;
    fapi::Target a1_chip;
    fapi::Target a2_chip;

    // init F link related BARs for this chip?
    bool process_f0;
    bool process_f1;
};

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode
(*proc_setup_bars_FP_t)(std::vector<proc_setup_bars_proc_chip>&,
                        const bool);


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: program nest unit BAR registers, driven by attributes representing
//           system memory map (including MMIO)
// parameters: i_proc_chips => vector of structures defining properties of each
//                             chip and links which should be considered in
//                             this invocation to drive initialization of BARs
//                             tied to remote node regions (A links) and
//                             foreign regions (F links)
//             i_init_local_chip_local_node => boolean qualifying initilization
//                                             of BARs tied to local chip/local
//                                             node regions
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          RC_PROC_SETUP_BARS_ATTR_LOOKUP_ERR if no rule is found to set
//              BAR/range address, enable, or size,
//          RC_PROC_SETUP_BARS_ATTR_CONTENT_ERR if BAR/range attribute content
//              violates expected behavior,
//          RC_PROC_SETUP_BARS_CHIP_MEMORY_RANGE_ATTR_OVERLAP_ERR if chip
//              memory range attributes specify overlapping address ranges,
//          RC_PROC_SETUP_BARS_CHIP_MEMORY_RANGE_ERR if merged
//              chip memory address range is invalid,
//          RC_PROC_SETUP_BARS_NODE_ADD_INTERNAL_ERR if node map insert fails,
//          RC_PROC_SETUP_BARS_NODE_FIND_INTERNAL_ERR if node map lookup is
//              unsuccessful,
//          RC_PROC_SETUP_BARS_DUPLICATE_FABRIC_ID_ERR if chips with duplicate
//              fabric node/chip IDs are detected,
//          RC_PROC_SETUP_BARS_INVALID_BAR_REG_DEF if BAR register definition
//              structure is invalid,
//          RC_PROC_SETUP_BARS_SIZE_XLATE_ERR if BAR logical->physical size
//              translation is unsuccessful,
//          RC_PROC_SETUP_BARS_SYSTEM_RANGE_OVERLAP_ERR if any overapping
//              ranges are detected, considering all ranges in system,
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_setup_bars(
    std::vector<proc_setup_bars_proc_chip>& i_proc_chips,
    const bool i_init_local_chip_local_node);

} // extern "C"


#endif // _PROC_SETUP_BARS_H_
