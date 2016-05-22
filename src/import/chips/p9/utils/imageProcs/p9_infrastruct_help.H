/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/imageProcs/p9_infrastruct_help.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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


// N-byte align an address, offset or size (aos)
inline uint64_t myByteAlign( const uint8_t nBytes, const uint64_t aos)
{
    return ((aos + nBytes - 1) / nBytes) * nBytes;
}

#endif //_P9_INFRASTRUCT_HELP_H_
