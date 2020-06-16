/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_infrastruct_help.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#ifndef _P10_INFRASTRUCT_HELP_H_
#define _P10_INFRASTRUCT_HELP_H_

#ifdef WIN32
    #include "win32_stdint.h"
#else
    #include <stdint.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//
// Various image/ring buffer sizes. Must be used by all users (VBU, FSP, HB, HBI, Cronus)
//
const uint32_t  PCPLS = 1; // Physical Chips Per Logical Seeprom
const uint32_t  SEEPROM_PHYS_CHIP_SIZE = (512 * 1024);
const uint32_t  MAX_SBE_SEEPROM_SIZE        = PCPLS * SEEPROM_PHYS_CHIP_SIZE;
const uint32_t  MAX_SEEPROM_IMAGE_SIZE      = PCPLS * (SEEPROM_PHYS_CHIP_SIZE / 9 * 8) - 256; // excl ECC bits
const uint32_t  MAX_MEAS_SEEPROM_IMAGE_SIZE = PCPLS * ((SEEPROM_PHYS_CHIP_SIZE * 3 / 8) / 9 * 8) - 256;
const uint32_t  MAX_RT_IMAGE_SIZE           = 1024 * 1024;   // Max Runtime size.

// The below buffer sizes are governed by the longest p10 engd ring, n1_fure, which is
// 1,207,902 bits long (20200404).  And we need to hold both data *and* care parts in the buffer.
// So... 1,207,902 x 2 / 8 ~ 302,000
const uint32_t  MAX_RING_BUF_SIZE       = 650000;        // Max ring buffer size (for two rings)
const uint32_t  MAX_RING_BUF_SIZE_TOOL  = 450000;        // Max ring buf size for tools.

const uint32_t  RS4_RING_BUF_SIZE   = 64 * 1024;         // Max RS4 size set to max size of ring section.
const uint32_t  OVLY_WORK_BUF_SIZE  = 4 * RS4_RING_BUF_SIZE; // Used for Raw4 overlays op

// Buffer sizes to be passed to ipl_customize directly from platform or via hcode_image_build
enum XIP_CUSTOMIZE_BUFFER_SIZES
{
    XIPC_RING_BUF1_SIZE =  RS4_RING_BUF_SIZE,
    XIPC_RING_BUF2_SIZE =  RS4_RING_BUF_SIZE,
    XIPC_RING_BUF3_SIZE =  OVLY_WORK_BUF_SIZE,
};

const uint32_t  MAX_OVERRIDES_SIZE      = 2 * 1024;      // Max overrides ring section size.

// @HBBL_SIZE_SYNC@
const uint32_t  MAX_HBBL_SIZE           = 32 * 1024;     // Max hbbl bin section size.

const uint32_t  MAX_NOOF_DD_LEVELS_IN_IMAGE = 20;

#if defined(__FAPI)
    #include <fapi2.H>
    #define MY_INF(_fmt_, _args_...) FAPI_INF(_fmt_, ##_args_)
    #define MY_ERR(_fmt_, _args_...) FAPI_ERR(_fmt_, ##_args_)
    #define MY_DBG(_fmt_, _args_...) FAPI_DBG(_fmt_, ##_args_)
#else
    #ifdef WIN32
        #define MY_INF(...) { printf(__VA_ARGS__); }
        #define MY_ERR(...) { printf(__VA_ARGS__); }
        #define MY_DBG(...) { printf(__VA_ARGS__); }
    #else
        #define MY_INF(_fmt_, _args_...) if (getenv("PRINT_INFO") != NULL) printf(_fmt_, ##_args_)
        #define MY_ERR(_fmt_, _args_...) printf(_fmt_, ##_args_)
        #define MY_DBG(_fmt_, _args_...) if (getenv("PRINT_DEBUG") != NULL) printf(_fmt_, ##_args_)
    #endif
#endif


// N-byte align an address, offset or size (aos)
inline uint64_t myByteAlign( const uint8_t nBytes, const uint64_t aos)
{
    return ((aos + nBytes - 1) / nBytes) * nBytes;
}

#endif //_P10_INFRASTRUCT_HELP_H_
