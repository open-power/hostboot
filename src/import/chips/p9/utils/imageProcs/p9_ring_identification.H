/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ring_identification.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


// General Ring ID list structure
typedef struct
{
    const char*  ringName;
    uint8_t      ringId;
    uint8_t      instanceIdMin;    // the min instanceId
    uint8_t      instanceIdMax;    // the max instanceId
    const char*  ringNameImg; // Ring name in image: ringName + "_ring"
    uint8_t      vpdKeyword;
    uint8_t      pllCopy;     // 0,1,2,3,4,5 -- No of PLL copies required
    uint64_t     scanRegionType;
} GenRingIdList;

typedef struct
{
    uint16_t  ring_offset;
    uint16_t  ring_size;
} Ring_toc_entry;

namespace PERV
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace N0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace N1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace N2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace N3
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace XB
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace MC
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace OB
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace PCI0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace PCI1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace PCI2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace EQ
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

namespace EC
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
}

// VPD Ring ID list structure.
typedef struct
{
    const char*  ringName;
    uint8_t      ringId;
    uint8_t      instanceIdMin;    // the min instanceId
    uint8_t      instanceIdMax;    // the max instanceId
    const char*  ringNameImg; // Ring name in image: ringName + "_ring"
    uint8_t      vpdKeyword;
    uint8_t      bWcSpace;     // 0: fitted  1: worst-case space (3 x ring length)
} RingIdList;



extern const RingIdList  RING_ID_LIST_PG[], RING_ID_LIST_PR[];
extern const uint32_t    RING_ID_LIST_PG_SIZE, RING_ID_LIST_PR_SIZE;
extern const RingIdList  RING_ID_LIST[];
extern const uint32_t    RING_ID_LIST_SIZE;

extern const uint32_t    RING_ID_LIST_CHIP_SIZE, RING_ID_LIST_CORE_SIZE,
       RING_ID_LIST_CME_SIZE, RING_ID_LIST_CC_SIZE;


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
    NON_VPD_RING = 3,
    NON_VPD_PLL_RING = 4,
};



int get_vpd_ring_list_entry(const char* i_ringName,
                            const uint8_t i_ringId,
                            RingIdList** i_ringIdList);


#endif
