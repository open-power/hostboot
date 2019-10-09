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
const uint32_t  MAX_SBE_SEEPROM_SIZE    = 4 * 64 * 1024; // Max SBE Seeprom size
const uint32_t  MAX_SEEPROM_IMAGE_SIZE  = 4 * ((64 * 1024) / 9 * 8) -
        256; // Max Seeprom image size, excl ECC bits (4 banks).
const uint32_t  MAX_RT_IMAGE_SIZE       = 1024 * 1024;   // Max Runtime size.

// The below buffer sizes are governed by the longest p10 engd ring, n1_fure, which is
// some 1,775,113 bits long.  And we need to hold both data *and* care parts in the buffer.
// So... 1,775,113 x 2 / 8 = 443,778 + size to grow
const uint32_t  MAX_RING_BUF_SIZE       = 650000;        // Max ring buffer size (agreed w/HB).
const uint32_t  MAX_RING_BUF_SIZE_TOOL  = 450000;        // Max ring buf size for tools.

const uint32_t  MAX_OVERRIDES_SIZE      = 2 * 1024;      // Max overrides ring section size.
const uint32_t  MAX_HBBL_SIZE           = 20 * 1024;     // Max hbbl bin section size.

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
        #define MY_INF(_fmt_, _args_...) printf(_fmt_, ##_args_)
        #define MY_ERR(_fmt_, _args_...) printf(_fmt_, ##_args_)
        #define MY_DBG(_fmt_, _args_...) printf(_fmt_, ##_args_)
    #endif
#endif


// N-byte align an address, offset or size (aos)
inline uint64_t myByteAlign( const uint8_t nBytes, const uint64_t aos)
{
    return ((aos + nBytes - 1) / nBytes) * nBytes;
}

#endif //_P10_INFRASTRUCT_HELP_H_
