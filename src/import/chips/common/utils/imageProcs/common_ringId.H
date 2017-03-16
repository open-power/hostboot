/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/imageProcs/common_ringId.H $    */
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

#ifndef _COMMON_RINGID_H_
#define _COMMON_RINGID_H_

#include <stdint.h>
#include <stddef.h>

//
// Various data typedefs for enums. Serves following purposes:
// - Reduces space since enum defaults to an int type.
// - Enables using these types without the scope operator for
//   those enums that are namespaced, e.g. RingID.
// NB! DO NOT CHANGE THESE DEFS W/O EXPLICIT CONSENT FROM
//     INFRASTRUCT TEAM. (These defs affect packing assumptions
//     of ring structures that go into the image ringSections.)
typedef uint16_t  RingId_t;         // Type for RingID enum
typedef uint8_t   ChipletType_t;    // Type for CHIPLET_TYPE enum
typedef uint8_t   PpeType_t;        // Type for PpeType
typedef uint8_t   ChipType_t;       // Type for ChipType enum
typedef uint8_t   RingType_t;       // Type for RingType enum
typedef uint8_t   RingVariant_t;    // Type for RingVariant enum

#define  INVALID_RING_ID  (RingId_t)0xffff
#define  INVALID_RING_TYPE  (RingType_t)0xff
#define  INVALID_CHIP_TYPE  (ChipType_t)0xff
#define  INVALID_CHIPLET_TYPE  (ChipletType_t)0xff

//
// Chip types and List to represent p9n, p9c, cen (centaur)
// NB! There's a matching CHIP_TYPE_LIST definition in common_ringId.C
//
enum ChipType
{
    CT_P9N,  // ==P9 for now
    CT_P9C,  // ==P9 for now
    CT_CEN,
    NUM_CHIP_TYPES
};

typedef struct
{
    const char*  name;
    ChipType_t   type;
} ChipTypeList_t;

static const ChipTypeList_t CHIP_TYPE_LIST[] =
{
    {"p9n", CT_P9N},
    {"p9c", CT_P9C},
    {"cen", CT_CEN},
};


//
// Ring related data structs and types
//
typedef enum RingClass
{
    EKB_RING,
    EKB_FSM_RING,
    EKB_STUMPED_RING,
    EKB_CMSK_RING,
    VPD_RING,
    CEN_RING,
    NUM_RING_CLASSES
} RingClass_t;

//
// General Ring ID list structure
//
typedef struct
{
    const char*  ringName;
    RingId_t     ringId;
    uint8_t      instanceIdMin;
    uint8_t      instanceIdMax;
    RingClass_t  ringClass;
    uint32_t     scanScomAddress;
} GenRingIdList;

enum RingVariant
{
    BASE     = 0x00,
    CC       = 0x01,
    RL       = 0x02,
    OVERRIDE = 0x03,   //@FIXME We should remove this. Its own image now.
    OVERLAY  = 0x04,   //@FIXME Not supported.
    NUM_RING_VARIANTS = 0x05,
    NOT_VALID = 0xff
};

typedef struct
{
    RingVariant_t  variant[3];
} RingVariantOrder;


enum RingType
{
    COMMON_RING = 0,
    INSTANCE_RING = 1,
    ALLRING = 2
};

typedef struct
{
    // This is the chiplet-ID of the first instance of the Chiplet
    uint8_t iv_base_chiplet_number;

    // The no.of common rings for the Chiplet
    uint8_t iv_num_common_rings;

    // The no.of instance rings for the Chiplet (w/different ringId values)
    uint8_t iv_num_instance_rings;

    // The no.of instance rings for the Chiplet (w/different ringId values
    // AND different scanAddress values)
    uint8_t iv_num_instance_rings_scan_addrs;

    // The no.of ring variants
    uint8_t iv_num_ring_variants;
} ChipletData_t;

// This is used to Set (Mark) the left-most bit
#define  INSTANCE_RING_MARK  (uint8_t)0x80
//
// This is used to Set (Mark) the left-most bit
#define  INSTANCE_RING_MASK  (uint8_t)0x7F

// This is used to mark an invalid ring in the ring properties list
#define INVALID_RING_OFFSET  (uint8_t)0xFF

// This structure is needed for mapping a RingID to it's corresponding name.
// The names will be used by the build scripts when generating the TOR.
#ifndef __PPE__
struct RingProperties_t
{
    uint8_t       iv_torOffSet;
    char          iv_name[50];
    ChipletType_t iv_type;
};
#else
struct RingProperties_t
{
    uint8_t       iv_torOffSet;
    ChipletType_t iv_type;
};
#endif

#endif  // _COMMON_RINGID_H_

