/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_homer_map.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: p8_homer_map.h,v 1.2 2014/07/26 13:58:54 jmcgill Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
//------------------------------------------------------------------------------
// *! OWNER NAME  : Frank Campisano Email: campisan@us.ibm.com

/**
 *  @file p8_homer_map.h
 *
 *  @brief Defines the memory layout for the 4MB HOMER space for OCC, SLW, CPM, and other 
 *
 * Start	End     	Size	Description
 *============= =============== ======= ===================================================
 * 0x00000000	0x000FFFFF	1 MB	OCC Image (Bootloader, OCC Image, OCC Applets)
 * 0x00100000	0x0011FFFF	128 kB	OCC Host Data Area (nest freq, config) (per chip)
 * 0x00120000	0x001EFFFF	832 kB	Unused Pad for OCC
 * 0x001F0000	0x001F7FFF	32 kB 	PowerProxy Trace Records
 * 0x001F8000	0x001FFFFF	32 kB 	Sapphire Data
 * 0x00200000	0x002FFFFF	1 MB	SLW Image
 * 0x00300000	0x0031FFFF	128 kB	SLW Spill over
 * 0x00320000	0x0039FFFF	512 kB	SLW 24x7 Counters Data Area (per chip)
 * 0x003A0000	0x003AFFFF	64 kB	SLW<->PHYP I2C Offload Comm Buffers (per chip)
 * 0x003B0000	0x003BFFFF	64 kB	CPM Calibration Data Buffer Block 
 * 0x003C0000	0x003C0FFF	4 kB	CPM Control Vector Block
 * 0x003C1000	0x003C1FFF	4 kB	PTS debug/FFDC assist data
 * 0x003C2000	0x003FFFFF	248 kB	Unused Pad for PBABAR
 */

#ifndef _P8_HOMER_MAP_H_
#define _P8_HOMER_MAP_H_

// Offset Addresses from HOMER BAR address (per chip)

CONST_UINT64_T( HOMER_OCC_IMAGE_OFFSET_ADDR                , ULL(0x00000000) );
CONST_UINT64_T( HOMER_OCC_HOST_DATA_OFFSET_ADDR            , ULL(0x00100000) );
CONST_UINT64_T( HOMER_OCC_PAD_OFFSET_ADDR                  , ULL(0x00120000) );
CONST_UINT64_T( HOMER_POWERPROXY_TRACE_OFFSET_ADDR         , ULL(0x001F0000) );
CONST_UINT64_T( HOMER_SAPPHIRE_DATA_OFFSET_ADDR            , ULL(0x001F8000) );
CONST_UINT64_T( HOMER_SLW_IMAGE_OFFSET_ADDR                , ULL(0x00200000) );
CONST_UINT64_T( HOMER_SLW_SPILL_BUFFER_OFFSET_ADDR         , ULL(0x00300000) );
CONST_UINT64_T( HOMER_SLW_24X7_COUNTER_OFFSET_ADDR         , ULL(0x00320000) );
CONST_UINT64_T( HOMER_SLW_PHYP_I2C_OFFOAD_OFFSET_ADDR      , ULL(0x003A0000) );
CONST_UINT64_T( HOMER_CPM_CAL_DATA_VECTOR_OFFSET_ADDR      , ULL(0x003B0000) );
CONST_UINT64_T( HOMER_CPM_CAL_CTRL_VECTOR_OFFSET_ADDR      , ULL(0x003C0000) );
CONST_UINT64_T( HOMER_CPM_CAL_GOLD_CTRL_VECTOR_OFFSET_ADDR , ULL(0x003C0080) );
CONST_UINT64_T( HOMER_PTS_DATA                             , ULL(0x003C1000) );
CONST_UINT64_T( HOMER_PAD_OFFSET_ADDR                      , ULL(0x003C2000) );

// Buffer sizes for HOMER sections

CONST_UINT64_T( HOMER_OCC_IMAGE_BUFFER_SIZE                , ULL(0x00100000) );
CONST_UINT64_T( HOMER_OCC_HOST_DATA_BUFFER_SIZE            , ULL(0x00020000) );
CONST_UINT64_T( HOMER_OCC_PAD_BUFFER_SIZE                  , ULL(0x000D0000) );
CONST_UINT64_T( HOMER_POWERPROXY_TRACE_RECORD_BUFFER_SIZE  , ULL(0x00008000) );
CONST_UINT64_T( HOMER_SAPPHIRE_DATA_BUFFER_SIZE            , ULL(0x00008000) );
CONST_UINT64_T( HOMER_SLW_IMAGE_BUFFER_SIZE                , ULL(0x00100000) );
CONST_UINT64_T( HOMER_SLW_SPILL_BUFFER_BUFFER_SIZE         , ULL(0x00020000) );
CONST_UINT64_T( HOMER_SLW_24X7_COUNTER_BUFFER_SIZE         , ULL(0x00080000) );
CONST_UINT64_T( HOMER_SLW_PHYP_I2C_OFFOAD_BUFFER_SIZE      , ULL(0x00010000) );
CONST_UINT64_T( HOMER_CPM_CAL_DATA_BUFFER_BUFFER_SIZE      , ULL(0x00010000) );
CONST_UINT64_T( HOMER_CPM_CAL_CTRL_VECTOR_BUFFER_SIZE      , ULL(0x00001000) );
CONST_UINT64_T( HOMER_CPM_CAL_GOLD_CTRL_VECTOR_BUFFER_SIZE , ULL(0x00000080) );
CONST_UINT64_T( HOMER_PTS_DATA_SIZE                        , ULL(0x00001000) );
CONST_UINT64_T( HOMER_PAD_BUFFER_SIZE                      , ULL(0x0003E000) );

#endif  // _P8_HOMER_MAP_H_
