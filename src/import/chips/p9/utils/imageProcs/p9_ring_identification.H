/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ring_identification.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

typedef struct
{
    uint8_t  variant[3];
} RingVariantOrder;


namespace PERV
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N3
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace XB
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace MC
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB3
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace PCI0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace PCI1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace PCI2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace EQ
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace EC
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

// MVPD Ring ID list structure.
typedef struct
{
    const char*  ringName;
    //@FIXME: CMO: Replace this with RingID asap.
    uint8_t      ringId;
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

extern const RingIdList  RING_ID_LIST_PG[], RING_ID_LIST_PR[];
extern const VPDRingList ALL_VPD_RINGS[];

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


enum VpdRingClass
{
    VPD_RING_CLASS_NEST = 0,   // Indicates NEST rings
    VPD_RING_CLASS_EQ = 1,     // Indicates EQ rings
    VPD_RING_CLASS_EX = 2,     // Indicates EX rings
    VPD_RING_CLASS_EC = 3,     // Indicates EC rings
    VPD_RING_CLASS_GPTR = 4,   // Indicates GPTR #G rings
    VPD_RING_CLASS_LAST = 5,
};


#define MVPD_END_OF_DATA_MAGIC (uint32_t)0x454E4400 // "END "


#endif
