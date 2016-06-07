/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_infrastruct_help.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#ifndef _P9_INFRASTRUCT_HELP_H_
#define _P9_INFRASTRUCT_HELP_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>     //memcpy()
#include <errno.h>

//
// Various image/ring buffer sizes. Must be used by all users (VBU, FSP, HB, HBI, Cronus)
//
const uint32_t  MAX_REF_IMAGE_SIZE    =     1024 *
        1024; // Max reference image size.
const uint32_t  FIXED_RING_BUF_SIZE   =
    60000; // Fixed ring buf size for _fixed.

#define CHIPLET_ID_MIN            (uint8_t)0x00
#define CHIPLET_ID_MAX            (uint8_t)0x37

#define MY_INF(_fmt_, _args_...) printf(_fmt_, ##_args_)
#define MY_ERR(_fmt_, _args_...) printf(_fmt_, ##_args_)
#define MY_DBG(_fmt_, _args_...) printf(_fmt_, ##_args_)


// Byte-reverse a 32-bit integer
inline uint32_t myRev32(const uint32_t i_x)
{
    uint32_t rx;

#ifdef _BIG_ENDIAN
    rx = i_x;
#else
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    prx[0] = pix[3];
    prx[1] = pix[2];
    prx[2] = pix[1];
    prx[3] = pix[0];
#endif

    return rx;
}

// Byte-reverse a 64-bit integer
inline uint64_t myRev64(const uint64_t i_x)
{
    uint64_t rx;

#ifdef _BIG_ENDIAN
    rx = i_x;
#else
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    prx[0] = pix[7];
    prx[1] = pix[6];
    prx[2] = pix[5];
    prx[3] = pix[4];
    prx[4] = pix[3];
    prx[5] = pix[2];
    prx[6] = pix[1];
    prx[7] = pix[0];
#endif

    return rx;
}


// Byte-reverse a 16-bit integer if on an LE machine
inline uint16_t myRev16(const uint16_t i_x)
{
    uint16_t rx;

#ifdef _BIG_ENDIAN
    rx = i_x;
#else
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    prx[0] = pix[1];
    prx[1] = pix[0];
#endif

    return rx;
}

// N-byte align an address, offset or size (aos)
inline uint64_t myByteAlign( const uint8_t nBytes, const uint64_t aos)
{
    return ((aos + nBytes - 1) / nBytes) * nBytes;
}

#endif //_P9_INFRASTRUCT_HELP_H_
