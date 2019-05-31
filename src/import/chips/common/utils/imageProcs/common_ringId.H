/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/imageProcs/common_ringId.H $    */
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

#ifndef _COMMON_RINGID_H_
#define _COMMON_RINGID_H_

#include <stdint.h>
#include <stddef.h>

///////////////////////////////////////////////////////////////////////////////
//                     Declare assumptions - Begin                           //
//                                                                           //
//

// Various data type defs for enums. Serves following purposes:
// - Reduces space since enum defaults to an int type.
// - Enables using these types without the scope operator for
//   those enums that are namespaced, e.g. RingID.
// NB! DO NOT CHANGE THESE DEFS W/O EXPLICIT CONSENT FROM
//     INFRASTRUCT TEAM. (These defs affect packing assumptions
//     of ring structures that go into the image ringSections.)
typedef uint16_t  RingId_t;         // Type for RingID enum
typedef uint16_t  RingClass_t;      // Type for RingClass enum vectors used in non-SBE
typedef uint8_t   ChipletType_t;    // Type for Chiplets enum
typedef uint8_t   ChipId_t;         // Type for ChipId enum
typedef uint8_t   RingType_t;       // Type for RingType enum
typedef uint8_t   RingRequest_t;    // Type for RingRequest enum, e.g. GET_SINGLE_RING
typedef uint32_t  TorCpltOffset_t;  // Type for offset value to chiplet's CMN or INST section
typedef uint8_t   MyBool_t;         // false:0, true:1, undefined:UNDEFINED_BOOLEAN

#define  UNDEFINED_RING_ID         (RingId_t)0xffff
#define  UNDEFINED_SCOM_ADDR       (uint32_t)0xffffffff
#define  UNDEFINED_RING_CLASS      (RingClass_t)0xffff
#define  UNDEFINED_CHIPLET_TYPE    (ChipletType_t)0xff
#define  UNDEFINED_CHIP_ID         (ChipId_t)0xff
#define  INVALID_RING_TYPE         (RingType_t)0xff

#define  UNDEFINED_DD_LEVEL     (uint8_t)0xff

#define  MAX_TOR_RING_OFFSET    (uint16_t)(256*256-1) // Max val of uint16

#define  MAX_RING_PATH_LENGTH   (uint8_t)500
#define  MAX_RING_NAME_LENGTH   (uint8_t)50

#define  UNDEFINED_BOOLEAN      (MyBool_t)0xff

//                                                                           //
//                     Declare assumptions - End                             //
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//                     TOR layout definitions - Begin                        //
//                                                                           //

//
// TOR header field (appears in top of every HW, SBE, OVRD, etc ring section)
//
typedef struct
{
    uint32_t  magic;       // =TOR_MAGIC_xyz
    uint8_t   version;     // =TOR_VERSION
    ChipId_t  chipId;      // Value from ChipId enum
    uint8_t   ddLevel;     // Actual DD level of ringSection
    uint8_t   undefined;
    uint32_t  size;        // Size of ringSection.
} TorHeader_t;

typedef struct
{
    TorCpltOffset_t cmnOffset;
    TorCpltOffset_t instOffset;
} TorCpltBlock_t;

typedef uint16_t TorRingOffset_t;  // Offset value to actual ring

//                                                                           //
//                     TOR layout definitions - End                          //
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//                     Key TOR constants - Begin                             //
//                                                                           //

// P9 TOR versions (kept here for historic context)
//#define TOR_VERSION  1  // Initial version. Large RS4 header.
//#define TOR_VERSION  2  // Reduced RS4 header.
//#define TOR_VERSION  3  // Added TOR magic header.
//#define TOR_VERSION  4  // TOR API code restructuring.
//#define TOR_VERSION  5  // Removed TOR-level DD handling.
//#define TOR_VERSION  6  // Added additional runtime risk level (RL2)
//#define TOR_VERSION  7  // Added three more runtime risk levels (RL3/4/5)

// P10 TOR versions
#define TOR_VERSION  1  // Removed all ring variant support. Only BASE rings supported now.


// TOR Magic values for top-level TOR ringSection and sub-ringSections
enum TorMagicNum
{
    TOR_MAGIC       = (uint32_t)0x544F52  ,   // "TOR"
    TOR_MAGIC_HW    = (uint32_t)0x544F5248,   // "TORH"
    TOR_MAGIC_SBE   = (uint32_t)0x544F5253,   // "TORS"
    TOR_MAGIC_QME   = (uint32_t)0x544F5251,   // "TORQ"
    TOR_MAGIC_OVLY  = (uint32_t)0x544F524C,   // "TORL"
    TOR_MAGIC_DYN   = (uint32_t)0x544F5244,   // "TORD"
    TOR_MAGIC_OVRD  = (uint32_t)0x544F5252,   // "TORR"
};

//                                                                           //
//                     Key TOR constants - End                               //
///////////////////////////////////////////////////////////////////////////////


//
// Chip ID list
//
enum ChipId
{
    CID_EXPLORER = 0x8,
    CID_P10 = 0xA,
};

#define P10_MVPD_CHIP_NAME 0xda

// Ring classes
// - Specified whether root ring:            ROOT (only applied in RING_PROPERTIES list)
// - Specifies origination repo:             EKB or MVPD
// - Specifies chip ID:                      P9
// - Specifies MVPD subclass:                #G or #R
// - Specifies flush status assumption:      Flushed or non-flushed (prev scanned)
// - Specifies various special ring classes: FSM, OVLY, STUMPED, CMSK
//
enum RingClass
{
    RCLS_ROOT_RING         = 0b0000000000000001, // ENGD root ring marker bit
    RCLS_FLUSH_RING        = 0b0000000000000010, // Flush-scan marker bit
    RCLS_NONFLUSH_RING     = 0b0000000000000100, // Nonflush-scan marker bit
    RCLS_EKB_FLUSH_RING    = 0b0000000000001010, // EKB P9 ring. Flush-scanned
    RCLS_EKB_NONFLUSH_RING = 0b0000000000001100, // EKB P9 ring. Nonflush-scanned
    RCLS_MVPD_PDG_RING     = 0b0000000000010010, // MVPD #G P9 ring. Flush-scanned
    RCLS_MVPD_PDR_RING     = 0b0000000000100010, // MVPD #R P9 ring. Flush-scanned
    RCLS_EKB_FSM_RING      = 0b0000000010000110, // EKB P9 ring for eq_ana_bndy. Mixed-scanned
    RCLS_EKB_OVLY_RING     = 0b0000000100010010, // EKB P9 ovly for MVPD GPTR ring. Flush-scanned
    RCLS_EKB_STUMPED_RING  = 0b0000001000000010, // EKB P9 CMSK stump ring. Flush-scanned
    RCLS_EKB_CMSK_RING     = 0b0000010000000010, // EKB P9 CMSK ring. Flush-scanned
};

// Ring types supported.
// - This enum also reflects the order with which they appear in various images' .rings section.
// - Do  NOT  make changes to the values or order of this enum.
enum RingType
{
    COMMON_RING = 0,
    INSTANCE_RING = 1,
    ALLRING = 2
};

enum RingRequest
{
    GET_SINGLE_RING     = 0x00,
    PUT_SINGLE_RING     = 0x01
};

//
// Main ring properties structure
// - This structure is the basis for the RING_PROPERTIES list (further below) which, through the
//   enumerated ringId index, associates (ringId, ringName, scanScomAddr, torOffset, chipletType)
// - For PPE we omit the ringName and scanScomAddr to save space in the SBE h-code.
//
typedef struct
{
#ifndef __PPE__
    char          ringName[MAX_RING_NAME_LENGTH];
    uint32_t      scanScomAddr;
#endif
    uint8_t       idxRing;
    ChipletType_t chipletType;
#ifndef __PPE__
    RingClass_t   ringClass;
#endif
} RingProperties_t;

//
// Main chiplet properties structure
//
typedef struct
{
    // This is the instance ID range of the chiplet.
    uint8_t chipletBaseId;  // This is also the chiplet base ID for the COMMON rings in the chiplet
    uint8_t numChipletInstances;      // Num of chiplet instances
    uint8_t numCommonRings;           // Num of common rings
    uint8_t numInstanceRings;         // Num of instance rings (w/different ringId values)
} ChipletData_t;

// This is used to Set (Mark) the left-most bit
#define  INSTANCE_RING_MARK  (uint8_t)0x80
//
// This is used to Clear the left-most bit
#define  INSTANCE_RING_MASK  (uint8_t)0x7F

// This is used to mark an invalid ring in the ring properties list
#define INVALID_RING_OFFSET  (uint8_t)0xFF



//
// Universal infrastructure error codes
//
#define INFRASTRUCT_RC_SUCCESS                0
#define INFRASTRUCT_RC_FAILURE                1
#define INFRASTRUCT_RC_CODE_BUG               2
#define INFRASTRUCT_RC_USER_ERROR             3
#define INFRASTRUCT_RC_ENV_ERROR              4
#define INFRASTRUCT_NOOF_RCS                  5 // Do not use as RC code
//
// TOR specific error codes
//
#define TOR_SUCCESS                           INFRASTRUCT_RC_SUCCESS
#define TOR_FAILURE                           INFRASTRUCT_RC_FAILURE
#define TOR_CODE_BUG                          INFRASTRUCT_RC_CODE_BUG
#define TOR_USER_ERROR                        INFRASTRUCT_RC_USER_ERROR
#define TOR_INVALID_MAGIC_NUMBER              INFRASTRUCT_NOOF_RCS + 1
#define TOR_INVALID_CHIP_ID                   INFRASTRUCT_NOOF_RCS + 3
#define TOR_INVALID_CHIPLET_TYPE              INFRASTRUCT_NOOF_RCS + 4
#define TOR_INVALID_VARIANT                   INFRASTRUCT_NOOF_RCS + 5
#define TOR_INVALID_RING_ID                   INFRASTRUCT_NOOF_RCS + 6
#define TOR_INVALID_INSTANCE_ID               INFRASTRUCT_NOOF_RCS + 7
#define TOR_INVALID_RING_REQUEST              INFRASTRUCT_NOOF_RCS + 8
#define TOR_UNSUPPORTED_RING_SECTION          INFRASTRUCT_NOOF_RCS + 9
#define TOR_RING_NOT_FOUND                    INFRASTRUCT_NOOF_RCS + 10 // to be phased out
#define TOR_RING_IS_EMPTY                     INFRASTRUCT_NOOF_RCS + 10 // non-fatal replace
#define TOR_RING_IS_POPULATED                 INFRASTRUCT_NOOF_RCS + 11
#define TOR_RING_HAS_NO_TOR_SLOT              INFRASTRUCT_NOOF_RCS + 12 // fatal replace
#define TOR_AMBIGUOUS_API_PARMS               INFRASTRUCT_NOOF_RCS + 13
#define TOR_SECTION_NOT_FOUND                 INFRASTRUCT_NOOF_RCS + 14
#define TOR_DD_LEVEL_NOT_FOUND                INFRASTRUCT_NOOF_RCS + 15
#define TOR_BUFFER_TOO_SMALL                  INFRASTRUCT_NOOF_RCS + 16
#define TOR_OFFSET_TOO_BIG                    INFRASTRUCT_NOOF_RCS + 17
#define TOR_NO_RINGS_FOR_VARIANT              INFRASTRUCT_NOOF_RCS + 18
#define TOR_SCOM_ADDR_NOT_FOUND               INFRASTRUCT_NOOF_RCS + 19
#define TOR_RING_NAME_NOT_FOUND               INFRASTRUCT_NOOF_RCS + 20
#define TOR_NO_RINGS_FOR_CHIP                 INFRASTRUCT_NOOF_RCS + 21

#ifndef __HOSTBOOT_MODULE // Only needed by ring_apply in EKB
int ringid_get_raw_ring_file_path( uint32_t       i_magic,
                                   char*          io_directory );
#endif

// This function returns the main ring properties list associated w/the chip ID.
int ringid_get_ringProps( ChipId_t           i_chipId,
                          RingProperties_t** o_ringProps );

int ringid_get_chipletProps( ChipId_t           i_chipId,
                             uint32_t           i_torMagic,
                             uint8_t            i_torVersion,
                             ChipletType_t      i_chipletType, // Ignored if one chiplet in torMagic
                             ChipletData_t**    o_chipletData);

int ringid_get_num_ring_ids( ChipId_t   i_chipId,
                             RingId_t*  o_numRingIds );

int ringid_get_num_chiplets( ChipId_t  i_chipId,
                             uint32_t  i_torMagic,
                             uint8_t*  o_numChiplets );

// This function returns the scanScomAddr associated with the ringId.
int ringid_get_scanScomAddr( ChipId_t   i_chipId,
                             RingId_t   i_ringId,
                             uint32_t*  o_scanScomAddr );

// This fumction returns the ringClass associated with the ringId.
int ringid_get_ringClass( ChipId_t      i_chipId,
                          RingId_t      i_ringId,
                          RingClass_t*  o_ringClass );

// Check for valid chip ID and ring ID.
int ringid_check_ringId( ChipId_t  i_chipId,
                         RingId_t  i_ringId );

// Check and resolve the effective chipletType's index in a given TOR magic ring section
int ringid_get_chipletIndex( ChipId_t        i_chipId,
                             uint32_t        i_torMagic,
                             ChipletType_t   i_chipletType,
                             ChipletType_t*  o_chipletIndex );


#if !defined(__PPE__) && !defined(NO_STD_LIB_IN_PPE) && !defined(__HOSTBOOT_MODULE) && !defined(FIPSODE)

#include <map>
#include <string>

// The following two maps replaces all chipId/chipType maps defined various places in initCompiler codes
extern std::map <ChipId_t, std::string> chipIdToTypeMap;
extern std::map <std::string, ChipId_t> chipTypeToIdMap;

// This function returns the root ringId of a given scanScomAddr.
// Notes:
// - The "root" ringId is the ringId which has a ringName identical to that associated with the
//   scanScomAddr in the engineering data (engd).
// - In IS's ring list, we can have multiple ringId for the same scanScomAddr since a ring may have
//   multiple variations of itself, e.g. due to different frequency, filter or FSM settings, and
//   which are identified through an "_bucket" extension on their ringName.  All those rings,
//   however, are classified as non-ROOT_RINGs.
// - If the fully "qualified" unique ringId is required, then use ringidGetRingId1() and supply
//   the ringName instead of the scanScomAddr.
// - Setting bTest=true will test if more than one root ring exist for a given scanScomAddr and
//   produce an error.
//
int ringidGetRootRingId( ChipId_t   i_chipId,
                         uint32_t   i_scanScomAddr,
                         RingId_t&  o_ringId,
                         bool       i_bTest = false );

// This function returns the ringId associated with the ringName.
// Notes:
// - Setting bTest=true will test if more than one ring exist for a given ringName and
//   produce an error.
//
int ringidGetRingId1( ChipId_t     i_chipId,
                      std::string  i_ringName,
                      RingId_t&    o_ringId,
                      bool         i_bTest = false );

// This function returns the ringId associated with the effective ring index within a chiplet.
// (Note that "effective" means the index is void of the instance marker bit.)
int ringidGetRingId2( ChipId_t       i_chipId,
                      uint32_t       i_torMagic,
                      ChipletType_t  i_chipletType, // Ignored if only one chiplet in torMagic
                      uint8_t        i_idxRing,     // The eEffective ring index within chiplet's
                      // common or instance ring section
                      MyBool_t       i_bInstCase,   // =0 common ring, =1 instance ring
                      RingId_t&      o_ringId,
                      bool           i_bTest = false );

// This function returns the ringName associated with the ringId.
int ringidGetRingName( ChipId_t     i_chipId,
                       RingId_t     i_ringId,
                       std::string& o_ringName );

// This fumction returns the ringClass associated with the ringId.
int ringidGetRingClass( ChipId_t      i_chipId,
                        RingId_t      i_ringId,
                        RingClass_t&  o_ringClass );

#endif // __PPE__ && NO_STD_LIB_IN_PPE

#endif  // _COMMON_RINGID_H_
