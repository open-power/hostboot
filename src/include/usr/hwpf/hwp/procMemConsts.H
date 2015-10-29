/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/procMemConsts.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
/**
 *  @file procMemConsts.H
 *
 *  @brief Constants to implement support for proc_setup_bars and mss_setup_bars
 *          Taken from Shawn Lambeth's MMIOMap8.1.0 spreadsheet
 */

#ifndef _HWP_PROCMEMCONSTS_H_
#define _HWP_PROCMEMCONSTS_H_

// Lower FSP Bar Regions - line 226 Overall Map, line 72 service processor
//  size is 4_GB
const uint64_t  SP_BAR_SIZE         =   0x0000000100000000ULL ;

//  FSP Bar Size,  line 227 Overall Map
const uint64_t  FSP_BAR_SIZE        =   0x0000000100000000ULL ;

//  Fsp MMIO Mask Size
//  @todo P7 had this at 4_GB, don't see it in the spreadsheet.
const uint64_t  FSP_MMIO_MASK_SIZE  =   0x0000000100000000 ;

//  Processor RNG Space, for NX_MMIO - line 46 Overall Map
//  size is 4_KB
const uint64_t  PROC_RNG_SIZE	    =   0x0000000000001000ULL;

//  PCIE Mem Address Space   -   line 236 Overall Map
//      corresponds to the "unit number" in ATTR description
//  size is 64_GB
const uint64_t  PCI_MEM_SIZE	    =   0x0000001000000000ULL;

//  PCIE BAR size values
//      Bar0 = 64_GB  ( from spreadsheet)
//      Bar1 = 2_GB   ( from spreadsheet)
//      Bar2 = 4_KB see NOTE above
const uint64_t  PCIE_BAR0_SIZE      =   0x0000001000000000ULL;
const uint64_t  PCIE_SAPH_BAR0_SIZE =   0x0000010000000000ULL;  //1TB for K80
const uint64_t  PCIE_BAR1_SIZE      =   0x0000000080000000ULL;
const uint64_t  PCIE_BAR2_SIZE      =   0x0000000000001000ULL;

// 4 PHB per chip, 4chips per node, max 4 nodes
const uint64_t  PCIE_BAR0_OFFSET_MASK =  ((PCIE_BAR0_SIZE*4*4*4)-1);
const uint64_t  PCIE_BAR1_OFFSET_MASK =  ((PCIE_BAR1_SIZE*4*4*4)-1);
const uint64_t  SAPPHIRE_PCIE_BAR0_BASE = 0x0000200000000000; // 32TB for K80
const uint64_t  SAPPHIRE_PCIE_BAR1_BASE = 0x00003FE000000000;



//  PHB Register Address Space  -   line 90 Overall Map
//  size is 1_MB
const uint64_t  PHB_REGS_SIZE       =   0x0000000000100000ULL;


#endif
