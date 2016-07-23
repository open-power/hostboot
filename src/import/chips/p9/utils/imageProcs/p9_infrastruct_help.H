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
//@FIXME: CMO: get rid of FIXED_RING_BUF_SIZE when ring_apply no longer uses it.
const uint32_t  FIXED_RING_BUF_SIZE     = 60000; // Fixed ring buf size for _fixed.
const uint32_t  MAX_SEEPROM_IMAGE_SIZE  = 4 * 56 * 1024; // Max Seeprom size, excl ECC bits (4 banks).
const uint32_t  MAX_RT_IMAGE_SIZE       = 1024 * 1024;   // Max Runtime size.
const uint32_t  MAX_RING_BUF_SIZE       = 60000;         // Max ring buffer size.
const uint32_t  MAX_OVERRIDES_SIZE      = 2 * 1024;      // Max overrides section size.
const uint32_t  MAX_HBBL_SIZE           = 20 * 1024;     // Max hbbl section size.

enum SYSPHASE
{
    SYSPHASE_HB_SBE = 0,
    SYSPHASE_RT_CME = 1,
    SYSPHASE_RT_SGPE = 2,
    NOOF_SYSPHASES = 3,
};

enum MODEBUILD
{
    MODEBUILD_IPL = 0,
    MODEBUILD_REBUILD = 1,
    NOOF_MODEBUILDS = 2,
};

#if defined(__FAPI)
    #include <fapi2.H>
    #define MY_INF(_fmt_, _args_...) FAPI_INF(_fmt_, ##_args_)
    #define MY_ERR(_fmt_, _args_...) FAPI_INF(_fmt_, ##_args_)
    #define MY_DBG(_fmt_, _args_...) FAPI_DBG(_fmt_, ##_args_)
#else
    #define MY_INF(_fmt_, _args_...) printf(_fmt_, ##_args_)
    #define MY_ERR(_fmt_, _args_...) printf(_fmt_, ##_args_)
    #define MY_DBG(_fmt_, _args_...) printf(_fmt_, ##_args_)
#endif


// N-byte align an address, offset or size (aos)
inline uint64_t myByteAlign( const uint8_t nBytes, const uint64_t aos)
{
    return ((aos + nBytes - 1) / nBytes) * nBytes;
}

#endif //_P9_INFRASTRUCT_HELP_H_
