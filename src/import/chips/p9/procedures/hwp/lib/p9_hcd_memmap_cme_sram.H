/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_hcd_memmap_cme_sram.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
///
/// @file  p9_hcd_memmap_cme_sram.H
/// @brief defines region constants of cme sram.
///

// *HWP HWP Owner:        David Du   <daviddu@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:         Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:             PM
// *HWP Level:            2
// *HWP Consumed by:      PM:Hostboot: Phyp

#ifndef __P9_HCD_MEMMAP_CME_SRAM_H__
#define __P9_HCD_MEMMAP_CME_SRAM_H__

#include <p9_hcd_header_defs.H>
#include <p9_hcd_memmap_base.H>

// -------------------------------------------------------------------
// Note: There can be NO semicolons(";") at end of macros in this file
//       There can ONLY have HCD_CONST/HCD_CONST64 macros in this file
// -------------------------------------------------------------------

HCD_CONST(CME_SRAM_BASE_ADDR,                   0xFFFF8000)
HCD_CONST(FFDC_PPE_IMG_HDR_START,       (CME_INT_VECTOR_SIZE + CME_SRAM_BASE_ADDR))
HCD_CONST(CME_SRAM_HEADER_ADDR,
          (CME_SRAM_BASE_ADDR + CME_INT_VECTOR_SIZE))
HCD_CONST(FFDC_CME_TRACE_START,         (CME_SRAM_BASE_ADDR + CME_DEBUG_PTRS_OFFSET))
HCD_CONST(FFDC_CME_DASH_BOARD_START,    (FFDC_CME_TRACE_START + CME_DEBUG_PTRS_SIZE - 4 ))

#endif /* __P9_HCD_MEMMAP_CME_SRAM_H__ */
