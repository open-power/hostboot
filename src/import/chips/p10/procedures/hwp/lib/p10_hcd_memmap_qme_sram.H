/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_hcd_memmap_qme_sram.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// EKB-Mirror-To: hw/ppe
///
/// @file  p10_hcd_memmap_qme_sram.H
/// @brief defines region constants of qme sram.
///

// *HWP HWP Owner:        David Du   <daviddu@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:         Prem S Jha <premjha2@in.ibm.com>
// *HWP Team:             PM
// *HWP Level:            2
// *HWP Consumed by:      PM:Hostboot: Phyp

#ifndef __P10_HCD_MEMMAP_QME_SRAM_H__
#define __P10_HCD_MEMMAP_QME_SRAM_H__

#include <p10_hcd_header_defs.H>
#include <p10_hcd_memmap_base.H>

// -------------------------------------------------------------------
// Note: There can be NO semicolons(";") at end of macros in this file
//       There can ONLY have HCD_CONST/HCD_CONST64 macros in this file
// -------------------------------------------------------------------

HCD_CONST(QME_SRAM_BASE_ADDR,           0xFFFF0000)
HCD_CONST(FFDC_PPE_IMG_HDR_START,       (QME_INT_VECTOR_SIZE + QME_SRAM_BASE_ADDR))
HCD_CONST(QME_SRAM_HEADER_ADDR,
          (QME_SRAM_BASE_ADDR + QME_INT_VECTOR_SIZE))
HCD_CONST(FFDC_QME_TRACE_START,         (QME_SRAM_BASE_ADDR + QME_DEBUG_PTRS_OFFSET))
HCD_CONST(FFDC_QME_DASH_BOARD_START,    (FFDC_QME_TRACE_START + QME_DEBUG_PTRS_SIZE - 4 ))

#endif /* __P10_HCD_MEMMAP_QME_SRAM_H__ */
