/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/imageProcs/common_ringId.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

#ifdef WIN32
    #include <win32_stdint.h>
#else
    #include <stdint.h>
#endif
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
typedef uint16_t  Rs4Selector_t;    // Type for dynamic inits and PLL selectors
typedef uint16_t  RingClass_t;      // Type for RingClass enum vectors used in non-SBE
typedef uint8_t   ChipletType_t;    // Type for Chiplets enum
typedef uint8_t   ChipId_t;         // Type for ChipId enum
typedef uint8_t   RingType_t;       // Type for RingType enum
typedef uint8_t   RingRequest_t;    // Type for RingRequest enum, e.g. GET_SINGLE_RING
typedef uint16_t  TorOffset_t;      // Type for offset value to various TOR objects (chiplet,ring)
typedef uint8_t   MyBool_t;         // false:0, true:1, undefined:UNDEFINED_BOOLEAN

#define  UNDEFINED_RING_ID         (RingId_t)0xffff
#define  HOLE_RING_ID              (RingId_t)0xeeee
#define  UNDEFINED_SCOM_ADDR       (uint32_t)0xffffffff
#define  UNDEFINED_RING_CLASS      (RingClass_t)0xffff
#define  UNDEFINED_CHIPLET_TYPE    (ChipletType_t)0xff
#define  UNDEFINED_CHIPLET_ID      (uint8_t)0xff
#define  UNDEFINED_CHIP_ID         (ChipId_t)0xff
#define  UNDEFINED_RING_INDEX      (uint8_t)0xff
#define  UNDEFINED_BOOLEAN         (MyBool_t)0xff

#define  UNDEFINED_DD_LEVEL     (uint8_t)0xff

#define  MAX_RING_NAME_LENGTH   (uint8_t)50

// Ring section defines
#define  MAX_TOR_RING_OFFSET        (uint16_t)(256*256-1) // Max val of uint16
#define  MAX_TOR_RING_SECTION_SIZE  (uint32_t)(256*256)
#define  MAX_DYN_RING_SECTION_SIZE  (uint32_t)(1024*1024)

// Chiplet ID defines
#define  CHIPLET_ID_MASK       (uint32_t)0xFF000000
#define  MIN_INSTANCE_ID       (uint8_t)0x01
#define  MAX_INSTANCE_ID       (uint8_t)0x3F

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
    uint8_t   rtVersion;   // Ring table version (greater of EKB and Mvpd)
    uint32_t  size;        // Size of ringSection (incl this header).
} TorHeader_t;

typedef struct
{
    TorOffset_t cmnOffset;
    TorOffset_t instOffset;
} TorCpltBlock_t;

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
//#define TOR_VERSION  1  // Removed all ring variant support. Only BASE rings supported now.
#define TOR_VERSION  2  // TOR ringSection offsets now wrt origin of ringSection at TOR header.


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


///////////////////////////////////////////////////////////////////////////////
//                           MVPD defs - Begin                               //
//                                                                           //

// The MVPD "Magic" word located in the first 55 byte VHDR header.
// (We have agreed with Mvpd team to only use 7 bytes of the RT keyword field)
static const uint64_t MVPD_MAGIC = 0x52540456484452; // "RT.VHDR"

// The below structure partially defines the 55 byte VHDR header of the MVPD.
// This header is the very first content of any MVPD and contains, among other
// things, the "magic word" defined above which we use to uniquely identify an
// MVPD file. Since the presence of this magic word is the only reason we need
// this structure, all other fields before the magic word are declared as
// undefined.  Further, since the magic word is an 8-byte entity that is not
// on an 8-byte boundary, the structure is declared "packed".
#ifndef WIN32
typedef struct
{
    uint8_t  undefined[14];
    uint64_t magic;  // Represents the 7-byte RT keyword field (+ 1-byte)
} __attribute__((packed)) MvpdHeader_t;
#else
#pragma pack(push,1)
typedef struct
{
    uint8_t  undefined[14];
    uint64_t magic;  // Represents the 7-byte RT keyword field (+ 1-byte)
} MvpdHeader_t;
#pragma pack(pop)
#endif
// MVPD chip name (Corresponds to POWER platforms chip type, e.g CID_P10=0xa)
enum MvpdChipName
{
    MVPD_CHIP_NAME_P10 = 0xda,
};

// Constant to verify version of DD keyword
static const uint8_t MVPD_DD_KWD_VER1 = 0x01;

// MVPD file size
static const uint32_t SIZE_OF_MVPD_FILE = 64 * 1024;

//                                                                           //
//                           MVPD defs - End                                 //
///////////////////////////////////////////////////////////////////////////////


//
// Chip ID list
//
enum ChipId
{
    CID_EXPLORER = 0x8,
    CID_ODYSSEY = 0xC,
    CID_P10 = 0xA,
};


//
// Ring markers and pre-defined classes (both used in RING_PROPERTIES to classify rings)
//
// Assumptions:
// - Main assumption is that ALL rings are assumed to be scanned onto previously flushed
//   HW scan chains. The exception to this rule is a couple of rings that will be
//   scanned onto previously scanned HW scan chains, such as the ana_bndy and filter rings.
//   So to simplify the marking work in the RING_PROPERTIES list, there's only a need for a
//   NONFLUSH ring marker, and if not set, which will be by far the most cases, implies an
//   FLUSH ring.
//
// ROOT:      Ring name exists verbatim in ENGD. Denoted a ROOT ring as opposed to a derived
//            ring that has a suffix added to its ringName by ifCompiler, eg _bucket or _flt.
// NONFLUSH:  Ring created with the assumption the scan chain has been previously scanned.
// EKB_RINGS: Ring content [possibly partly] from initfiles. Destined for .rings ringSection.
// GPTR_OVLY: Ring content [possibly partly] from initfiles. Destined for .overlays ringSection.
// MVPD_PDG:  #G Gptr/Time MVPD ring.
// MVPD_PDP:  #P Pll       MVPD ring.
// MVPD_PDR:  #R Repr      MVPD ring.
// MVPD_NEST: Ring is in a NEST chiplet. (Needed for bootCoreMask in ipl_customize)
// MVPD_EQ:   Ring is in the EQ chiplet. (Needed for bootCoreMask in ipl_customize)
// MVPD_CORE: Ring is in the core chiplet. (Needed for bootCoreMask in ipl_customize)
//
#ifdef WIN32
enum RingMarker //: RingClass_t
{
    RMRK_ROOT         = (RingClass_t)0x1,         // ENGD root ring marker bit
    RMRK_HAS_DERIVS   = (RingClass_t)(0x1 << 1),  // Ring has derivatives, e.g. has buckets
    RMRK_EKB_RINGS    = (RingClass_t)(0x1 << 2),  // EKB .rings and .dynamic marker bit
    RMRK_GPTR_OVLY    = (RingClass_t)(0x1 << 3),  // Gptr overlay ring marker bit
    RMRK_TIME         = (RingClass_t)(0x1 << 4),  // Time ring marker bit
    RMRK_MVPD_PDG     = (RingClass_t)(0x1 << 7),  // MVPD #G gptr/time ring marker bit
    RMRK_MVPD_PDP     = (RingClass_t)(0x1 << 8),  // MVPD #P pll ring marker bit
    RMRK_MVPD_PDR     = (RingClass_t)(0x1 << 9),  // MVPD #R repr ring marker bit
    RMRK_MVPD_PDS     = (RingClass_t)(0x1 << 10), // MVPD #S dts ring marker bit
    RMRK_MVPD_NEST    = (RingClass_t)(0x1 << 11), // NEST (non-EQ) ring marker bit
    RMRK_MVPD_EQ      = (RingClass_t)(0x1 << 12), // EQ (non-core) ring marker bit
    RMRK_MVPD_CORE    = (RingClass_t)(0x1 << 13), // Core ring marker bit
    RMRK_SCAN_BY_QME  = (RingClass_t)(0x1 << 14), // QME scannable ring marker bit
};
#else
enum RingMarker
{
    RMRK_ROOT        = (RingClass_t)0b0000000000000001, // ENGD root ring marker bit
    RMRK_HAS_DERIVS  = (RingClass_t)0b0000000000000010, // Ring has derivatives, e.g. has buckets
    RMRK_EKB_RINGS   = (RingClass_t)0b0000000000000100, // EKB .rings and .dynamic marker bit
    RMRK_GPTR_OVLY   = (RingClass_t)0b0000000000001000, // Gptr overlay ring marker bit
    RMRK_TIME        = (RingClass_t)0b0000000000010000, // Time ring marker bit
    RMRK_MVPD_PDG    = (RingClass_t)0b0000000010000000, // MVPD #G gptr/time ring marker bit
    RMRK_MVPD_PDP    = (RingClass_t)0b0000000100000000, // MVPD #P pll ring marker bit
    RMRK_MVPD_PDR    = (RingClass_t)0b0000001000000000, // MVPD #R repr ring marker bit
    RMRK_MVPD_PDS    = (RingClass_t)0b0000010000000000, // MVPD #S dts ring marker bit
    RMRK_MVPD_NEST   = (RingClass_t)0b0000100000000000, // NEST (non-EQ) ring marker bit
    RMRK_MVPD_EQ     = (RingClass_t)0b0001000000000000, // EQ (non-core) ring marker bit
    RMRK_MVPD_CORE   = (RingClass_t)0b0010000000000000, // Core ring marker bit
    RMRK_SCAN_BY_QME = (RingClass_t)0b0100000000000000, // QME scannable ring marker bit
};
#endif
//
// Predefined ring classes
// - The following ring classes are combining the above RingMarker bits to condense the
//   programming of the ringClass field in the RING_PROPERTIES list in p10_ringId.H.
//
// EKB class to represent COMMON rings
#define RCLS_EKB_RINGS          (RMRK_EKB_RINGS)
// EKB and MVPD class to represent COMMON rings
#define RCLS_EKB_MVPD_PDG_OVLY  (RMRK_MVPD_PDG | RMRK_GPTR_OVLY)
#define RCLS_EKB_MVPD_PDP       (RMRK_MVPD_PDP)
// MVPD class to represent COMMON rings
#define RCLS_MVPD_PDG_TIME      (RMRK_MVPD_PDG | RMRK_TIME)
// MVPD class to represent INSTANCE rings
#define RCLS_MVPD_PDR_NEST      (RMRK_MVPD_PDR | RMRK_MVPD_NEST)
#define RCLS_MVPD_PDR_EQ        (RMRK_MVPD_PDR | RMRK_MVPD_EQ)
#define RCLS_MVPD_PDR_CORE      (RMRK_MVPD_PDR | RMRK_MVPD_CORE)
#define RCLS_MVPD_PDS_NEST      (RMRK_MVPD_PDS | RMRK_MVPD_NEST)
#define RCLS_MVPD_PDS_EQ        (RMRK_MVPD_PDS | RMRK_MVPD_EQ)
#define RCLS_MVPD_PDS_CORE      (RMRK_MVPD_PDS | RMRK_MVPD_CORE)
// MVPD keyword mask
#define RCLS_MVPD_MASK          (RMRK_MVPD_PDG | RMRK_MVPD_PDP | RMRK_MVPD_PDR | RMRK_MVPD_PDS)

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
    GET_SINGLE_RING        = 0,
    PUT_SINGLE_RING        = 1,
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
    RingId_t      ringId;
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
#define TOR_HEADER_CHECK_FAILURE              INFRASTRUCT_NOOF_RCS + 1
#define TOR_INVALID_MAGIC_NUMBER              INFRASTRUCT_NOOF_RCS + 2
#define TOR_INVALID_CHIP_ID                   INFRASTRUCT_NOOF_RCS + 3
#define TOR_INVALID_CHIPLET_TYPE              INFRASTRUCT_NOOF_RCS + 4
#define TOR_INVALID_RING_ID                   INFRASTRUCT_NOOF_RCS + 5  // ringId falls outside Mvpd and Ekb range
#define TOR_INVALID_CHIPLET_ID                INFRASTRUCT_NOOF_RCS + 6
#define TOR_INVALID_RING_REQUEST              INFRASTRUCT_NOOF_RCS + 7
#define TOR_UNSUPPORTED_RING_SECTION          INFRASTRUCT_NOOF_RCS + 8
#define TOR_RING_FILE_NOT_FOUND               INFRASTRUCT_NOOF_RCS + 9
#define TOR_RING_IS_EMPTY                     INFRASTRUCT_NOOF_RCS + 10
#define TOR_RING_IS_POPULATED                 INFRASTRUCT_NOOF_RCS + 11
#define TOR_RING_HAS_NO_TOR_SLOT              INFRASTRUCT_NOOF_RCS + 12
#define TOR_RING_HAS_DERIVS                   INFRASTRUCT_NOOF_RCS + 13
#define TOR_AMBIGUOUS_API_PARMS               INFRASTRUCT_NOOF_RCS + 14
#define TOR_SECTION_NOT_FOUND                 INFRASTRUCT_NOOF_RCS + 15
#define TOR_DD_LEVEL_NOT_FOUND                INFRASTRUCT_NOOF_RCS + 16
#define TOR_BUFFER_TOO_SMALL                  INFRASTRUCT_NOOF_RCS + 17
#define TOR_OFFSET_TOO_BIG                    INFRASTRUCT_NOOF_RCS + 18
#define TOR_SCOM_ADDR_NOT_FOUND               INFRASTRUCT_NOOF_RCS + 19
#define TOR_RING_NAME_NOT_FOUND               INFRASTRUCT_NOOF_RCS + 20
#define TOR_NO_RINGS_FOR_CHIP                 INFRASTRUCT_NOOF_RCS + 21
#define TOR_DYN_RING_NOT_FOUND                INFRASTRUCT_NOOF_RCS + 22
#define TOR_HOLE_RING_ID                      INFRASTRUCT_NOOF_RCS + 23
#define TOR_INVALID_RS4_MAGIC                 INFRASTRUCT_NOOF_RCS + 24
#define TOR_INVALID_RS4_VERSION               INFRASTRUCT_NOOF_RCS + 25
#define TOR_INVALID_RS4_TYPE                  INFRASTRUCT_NOOF_RCS + 26
#define TOR_RING_ID_MISMATCH                  INFRASTRUCT_NOOF_RCS + 27 //ringId and Rs4 mismatch

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

// This function returns the ringClass associated with the ringId.
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

// Check if ring is an Mvpd ring
MyBool_t ringid_is_mvpd_ring( ChipId_t  i_chipId,
                              RingId_t  i_ringId );

// Check if ring is a GPTR ring
/*
MyBool_t ringid_is_gptr_ring( ChipId_t  i_chipId,
                              RingId_t  i_ringId );
*/

// Check if ring is a Common or Instance ring
MyBool_t ringid_is_instance_ring( RingId_t  i_rpIndex);

// Check if ring has derivative, eg if it has bucket rings. Note that the actual
// derivative ring itself, eg the *_bucket_n ring, will *not* be marked as derivative.
// Only the "root ring", eg that does *not* have the *_bucket_n suffix, will be marked.
MyBool_t ringid_has_derivs( ChipId_t  i_chipId,
                            RingId_t  i_ringId );

// Returns the version of the master ring table that EKB (ie, non-MVPD) rings are based on
uint8_t ringid_get_ring_table_version_ekb( void);

// Returns the version of the master ring table that MVPD rings are based on
uint8_t ringid_get_ring_table_version_mvpd( void);

// Returns the effective version of the master ring table that HW image rings are based on
uint8_t ringid_get_ring_table_version_hwimg( void);

#if !defined(__PPE__) && !defined(NO_STD_LIB_IN_PPE) && !defined(WIN32)

#include <map>

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

// This fumction returns the ringClass associated with the ringId.
int ringidGetRingClass( ChipId_t      i_chipId,
                        RingId_t      i_ringId,
                        RingClass_t&  o_ringClass );

// string is not supported by Hostboot or Hostboot Bootloader
#if !defined(FIPSODE) && !defined(NO_PLAT_STD_STRING_SUPPORT)

#include <string>

// The following two maps replaces all chipId/chipType maps defined various places in initCompiler codes
extern std::map <ChipId_t, std::string> chipIdToTypeMap;
extern std::map <std::string, ChipId_t> chipTypeToIdMap;

// This function returns the ringId associated with the ringName.
// Notes:
// - Setting bTest=true will test if more than one ring exist for a given ringName and
//   produce an error.
//
int ringidGetRingId1( ChipId_t     i_chipId,
                      std::string  i_ringName,
                      RingId_t&    o_ringId,
                      bool         i_bTest = false );

// This function returns the ringName associated with the ringId.
int ringidGetRingName( ChipId_t     i_chipId,
                       RingId_t     i_ringId,
                       std::string& o_ringName );

#endif // __HOSTBOOT_MODULE && FIPSODE

#endif // __PPE__ && NO_STD_LIB_IN_PPE && WIN32

#endif  // _COMMON_RINGID_H_
