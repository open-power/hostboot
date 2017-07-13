/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ring_identification.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#ifndef _P9_RING_IDENT_H_
#define _P9_RING_IDENT_H_
#include <stddef.h>
#ifdef WIN32
    #include "win32_stdint.h"
#else
    #ifdef __sun
        #include <sys/int_types.h>
    #else
        #include <stdint.h>
    #endif
#endif
#include <stdlib.h>
#include <string.h>
#include <p9_ring_id.h>

// MVPD Ring ID list structure.
typedef struct
{
    const char*  ringName;
    RingID       ringId;
    uint8_t      instanceIdMin;    // the min instanceId
    uint8_t      instanceIdMax;    // the max instanceId
    uint8_t      vpdKeyword;
    uint8_t      vpdRingClass;     // Indicates std, gptr, or ex instance.
} RingIdList;


typedef struct
{
    const RingIdList* ringIdList;
    uint32_t    ringIdListSize;
} VPDRingList;

extern const VPDRingList ALL_VPD_RINGS[];

extern const uint32_t    RING_ID_LIST_CHIP_SIZE, RING_ID_LIST_CORE_SIZE,
       RING_ID_LIST_CME_SIZE, RING_ID_LIST_CC_SIZE;

#if defined(WIN32) || defined(__sun)
    extern const RingIdList  RING_ID_LIST_PDG[], RING_ID_LIST_PDR[];
    extern const uint32_t    RING_ID_LIST_PG_SIZE, RING_ID_LIST_PR_SIZE;
#endif

// Enumerated VPD keyword values.
// Note! This is DIFFERENT from the MvpdKeyword list in fapiMvpdAccess.H which
//       can't be used in this file since it's not, per se, a fapi file. So
//       these values need to be translated in xip_customize when passing the
//       mvpdKeyword to getMvpdRing();
enum VpdKeyword
{
    VPD_KEYWORD_PDG = 0,
    VPD_KEYWORD_PDR = 1,
    NUM_OF_VPD_TYPES = 2,
};


enum VpdRingClass
{
    VPD_RING_CLASS_NEST = 0,   // Indicates NEST [common] rings, except GPTR #G rings.
    VPD_RING_CLASS_GPTR_NEST = 1,   // Indicates GPTR #G [common]rings-NEST
    VPD_RING_CLASS_GPTR_EQ = 2,   // Indicates GPTR #G [common]rings-EQ
    VPD_RING_CLASS_GPTR_EX = 3,   // Indicates GPTR #G [common]rings-EX
    VPD_RING_CLASS_GPTR_EC = 4,   // Indicates GPTR #G [common]rings-EC
    VPD_RING_CLASS_EQ = 5,     // Indicates EQ [common] rings
    VPD_RING_CLASS_EX = 6,     // Indicates EX [common] rings
    VPD_RING_CLASS_EC = 7,     // Indicates EC [common] rings
    VPD_RING_CLASS_EQ_INS = 8, // Indicates EQ instance rings
    VPD_RING_CLASS_EX_INS = 9, // Indicates EX instance rings
    VPD_RING_CLASS_EC_INS = 10, // Indicates EC instance rings
    VPD_RING_CLASS_LAST = 11,
};


#define MVPD_END_OF_DATA_MAGIC (uint32_t)0x454E4400 // "END "


#endif
