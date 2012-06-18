/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/hwp/procMemConsts.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file procMemConsts.H
 *
 *  @brief Constants to implement support for proc_setup_bars and mss_setup_bars
 *          Taken from Shawn Lambeth's MMIOMap8.1.0 spreadsheet
 */

#ifndef _HWP_PROCMEMCONSTS_H_
#define _HWP_PROCMEMCONSTS_H_

//  Service Processor PSI Space - line 85 Overall Map
//  size is 1_MB
const uint64_t  SP_PSI_START        =   0x0003FFFE80000000ULL ;
const uint64_t  SP_PSI_SIZE         =   0x0000000000100000ULL ;


//  Processor Interrupt Space - line 7 Overall Map
//  size is 1_MB
const uint64_t  PROC_INTP_START      =   0x0003FFFF80000000ULL;
const uint64_t  PROC_INTP_SIZE       =   0x0000000000100000ULL;


// Lower FSP Bar Regions - line 226 Overall Map, line 72 service processor
//  size is 4_GB
const uint64_t  SP_BAR_START        =   0x0003FFE000000000ULL ;
const uint64_t  SP_BAR_SIZE         =   0x0000000100000000ULL ;

//  FSP Bar Size,  line 227 Overall Map
const uint64_t  FSP_BAR_SIZE        =   0x0000000100000000ULL ;

//  Fsp MMIO Mask Size
//  @todo P7 had this at 4_GB, don't see it in the spreadsheet.
const uint64_t  FSP_MMIO_MASK_SIZE  =   0x0000000100000000 ;

//  Processor RNG Space, for NX_MMIO - line 46 Overall Map
//  size is 4_KB
const uint64_t  PROC_RNG_START	    =   0x0003FFFF40000000ULL;
const uint64_t  PROC_RNG_SIZE	    =   0x0000000000001000ULL;

//  PCIE Mem Address Space   -   line 236 Overall Map
//      corresponds to the "unit number" in ATTR description
//  size is 64_GB
const uint64_t  PCI_MEM_START	    =   0x0003D00000000000ULL;
const uint64_t  PCI_MEM_SIZE	    =   0x0000001000000000ULL;

//  PCIE BAR size values
//      Bar0 = 64_GB  ( from spreadsheet)
//      Bar1 = always 0 and disabled ( Joe McGill )
//      Bar2 = 4_KB see NOTE above
const uint64_t  PCIE_BAR0_SIZE      =   0x0000001000000000ULL;
const uint64_t  PCIE_BAR1_SIZE      =   0x0000001000000000ULL;
const uint64_t  PCIE_BAR2_SIZE      =   0x0000000000001000ULL;

//  PHB Register Address Space  -   line 90 Overall Map
//  size is 1_MB
const uint64_t  PHB_REGS_START	    =   0x0003FFFE40000000ULL;
const uint64_t  PHB_REGS_SIZE       =   0x0000000000100000ULL;


#endif
