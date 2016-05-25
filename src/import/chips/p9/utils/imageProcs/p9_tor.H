/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/imageProcs/p9_tor.H $                          */
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
#ifndef _P9_TOR_H_
#define _P9_TOR_H_

#include "p9_ring_identification.H"
#include "p9_ringId.H"
#include "p9_infrastruct_help.H"

#define NUM_RING_IDS              P9_NUM_RINGS

typedef struct
{
    uint32_t sizeOfThis;
    uint16_t sizeOfCmsk;
    uint16_t sizeOfMeta; // Exact size of meta data. Arbitrary size. Not null terminated.
} RingLayout_t;


//
// Temporary define until in TOR header by Giri.
//
//
// Temporary define until in TOR header by Giri.
//
typedef struct
{
    uint32_t TorNumDdLevels;
    uint32_t reserved;
} TorNumDdLevels_t;

typedef struct
{
    uint32_t TorDdLevelAndOffset;
    uint32_t TorDdBlockSize;
} TorDdLevelBlock_t;

typedef struct
{
    uint32_t TorPpeTypeOffset;
    uint32_t TorPpeBlockSize;
} TorPpeBlock_t;


#define MAX_CPLT_SBE                                  13
#define IMGBUILD_TGR_RING_FOUND                        0
#define IMGBUILD_TGR_RING_BLOCKS_FOUND                 0
#define IMGBUILD_TGR_RING_NOT_FOUND                    1  // Ring is not found in HW image.
#define IMGBUILD_TGR_INVALID_RING_ID                   2  // Ring is invalid or mismatch.
#define IMGBUILD_TGR_AMBIGUOUS_API_PARMS               3  // Ring search in HW iamge got ambiguous condition.
#define IMGBUILD_TGR_SECTION_NOT_FOUND                 4
#define IMGBUILD_TGR_DD_LVL_INFO_NOT_FOUND             5
#define IMGBUILD_TGR_OP_BUFFER_INVALID                 6
#define IMGBUILD_TGR_OP_BUFFER_SIZE_EXCEEDED           7
#define IMGBUILD_INVALID_INSTANCEID                    8
#define IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_CME       10
#define IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_SGPE      11
#define IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_DD_LEVEL  12
#define IMGBUILD_TGR_IMAGE_DOES_NOT_SUPPORT_PPE_LEVEL 13

#define MY_INF(_fmt_, _args_...) printf(_fmt_, ##_args_)
#define MY_ERR(_fmt_, _args_...) printf(_fmt_, ##_args_)
#define MY_DBG(_fmt_, _args_...) printf(_fmt_, ##_args_)


extern const char* ringVariantName[];
extern const char* ppeTypeName[];


typedef enum
RingBlockType   // Different options to extract data using tor_get_ring API
{
    SINGLE_RING      = 0x00,
    DD_LEVEL_RINGS   = 0x01,
    PPE_LEVEL_RINGS  = 0x02,
    CPLT_LEVEL_RINGS = 0x03
} RingBlockType_t;


typedef enum RingType      // Different type of Rings
{
    COMMON   = 0x00,
    INSTANCE = 0x01,
    ALLRING  = 0x02
} RingType_t;



typedef enum RingVariant   // Base variables
{
    BASE     = 0x00,
    CC       = 0x01,
    RL       = 0x02,
    OVERRIDE = 0x03,
    OVERLAY  = 0x04,
    NUM_RING_VARIANTS = 0x05
} RingVariant_t;


//
// PPE types
//
typedef enum PpeType
{
    SBE           = 0x00,     // Ppe type partition in Ringsection
    CME           = 0x01,
    SGPE          = 0x02,
    NUM_PPE_TYPES = 0x03
} PpeType_t;



typedef enum RingSectionId
{
    SECTION_RING    = 0x00,    //.ring section ID
    SECTION_OVRD    = 0x01,    //.Override section ID
    SECTION_OVRL    = 0x02     //.Overlay section ID
} RingSectionId_t;

typedef enum SbeTorId
{
    PERV_CPLT = 0,
    N0_CPLT =   1,
    N1_CPLT =   2,
    N2_CPLT =   3,
    N3_CPLT =   4,
    XB_CPLT =   5,
    MC_CPLT =   6,
    OB_CPLT =   7,
    PCI0_CPLT = 8,
    PCI1_CPLT = 9,
    PCI2_CPLT = 10,
    EQ_CPLT   = 11,
    EC_CPLT   = 12,
    SBEALL  =   13
} SbeTorId_t;
typedef enum CmeTorId
{
    CME0_CPLT    = 0,
    CME1_CPLT    = 1,
    CME2_CPLT    = 2,
    CME3_CPLT    = 3,
    CME4_CPLT    = 4,
    CME5_CPLT    = 5,
    CME6_CPLT    = 6,
    CME7_CPLT    = 7,
    CME8_CPLT    = 8,
    CME9_CPLT    = 9,
    CME10_CPLT   = 10,
    CME11_CPLT   = 11,
    CMEALL       = 12
} CmeTorId_t;
///
/// ****************************************************************************
/// Function declares.
/// ****************************************************************************
///


int get_ring_from_sbe_image ( void*
                              i_ringSectionPtr, // Image pointer
                              uint64_t        i_magic,          // Image Magic Number
                              RingID          i_ringId,         // Unique ring ID
                              uint16_t        i_ddLevel,        // DD level details
                              RingType_t&     io_RingType,      // 0: Common 1: Instance
                              RingVariant_t   i_RingVariant,    // Base, cache contained, Risk level,
                              // Override and Overlay
                              uint8_t&        io_instanceId,    // required Instance
                              RingBlockType_t RingBlockType,    // 0: single ring,  1: ddLevel block
                              void**          io_ringBlockPtr,  // RS4 Container data or block data
                              uint32_t&       io_ringBlockSize, // size of data copied into ring block pointer
                              char*           o_ringName,       // Name of ring
                              uint32_t        dbgl);            // Debug option

int get_ring_from_sgpe_image ( void*
                               i_ringSectionPtr, // Image pointer
                               RingID          i_ringId,         // Unique ring ID
                               uint16_t        i_ddLevel,        // DD level details
                               RingType_t&      io_RingType,       // 0: Common 1: Instance
                               RingVariant_t   i_RingVariant,    // Base, cache contained, Risk level,
                               // Override and Overlay
                               uint8_t&         io_instanceId,    // required Instance
                               RingBlockType_t RingBlockType,    // 0: single ring,  1: ddLevel block
                               void**          io_ringBlockPtr,   // RS4 Container data or block data
                               uint32_t&       io_ringBlockSize, // size of data copied into ring block pointer
                               char*           o_ringName,       // Name of ring
                               uint32_t        dbgl);            // Debug option

int get_ring_from_cme_image ( void*           i_ringSectionPtr, // Image pointer
                              RingID          i_ringId,         // Unique ring ID
                              uint16_t        i_ddLevel,        // DD level details
                              RingType_t&      io_RingType,       // 0: Common 1: Instance
                              RingVariant_t   i_RingVariant,    // Base, cache contained, Risk level,
                              // Override and Overlay
                              uint8_t&        io_instanceId,    // required Instance
                              RingBlockType_t RingBlockType,    // 0: single ring,  1: ddLevel block
                              void**          io_ringBlockPtr,   // RS4 Container data or block data
                              uint32_t&       io_ringBlockSize, // size of data copied into ring block pointer
                              char*           o_ringName,       // Name of ring
                              uint32_t        dbgl);            // Debug option

int tor_get_ring(  void*
                   i_ringSectionPtr, // Ring address Ptr any of .rings, .overrides and .overlays.
                   uint64_t        i_magic,             // Image Magic Number
                   RingID          i_ringId,         // Unique ring ID
                   uint16_t        i_ddLevel,        // DD level info
                   PpeType_t       i_PpeType,        // PPE type : SBE, CME, etc
                   RingType_t&      io_RingType,       // 0: Common 1: Instance
                   RingVariant_t   i_RingVariant,    // Base, Cache etc
                   uint8_t&        io_instanceId,     // chiplet instance ID
                   RingBlockType_t i_RingBlockType,  // 0: single ring,  1: ring block
                   void**          io_ringBlockPtr,  // Addr of ring buffer
                   uint32_t&       io_ringBlockSize, // size of ring data
                   char*           o_ringName        // Ring name
                );

int tor_get_single_ring ( void*
                          i_ringSectionPt,     // Ring address Ptr any of .rings, .overrides and .overlays.
                          uint16_t      i_ddLevel,           // DD level info
                          RingID        i_ringId,            // Unique ring ID
                          PpeType_t     i_PpeType,           // ppe Type
                          RingVariant_t
                          i_RingVariant,       // Base, cache contained, Risk level, Override and Overlay
                          uint8_t       i_instanceId,        // Chiplet Instance ID
                          void**        io_ringBlockPtr,     // Addr of ring buffer
                          uint32_t&     io_ringBlockSize );  // size of ring data


int tor_get_block_of_rings ( void*
                             i_ringSectionPt,  // Ring address Ptr any of .rings, .overrides and .overlays.
                             uint16_t      i_ddLevel,        // DD level
                             PpeType_t     i_PpeType,        // ppe Type
                             RingType_t    i_RingType,       // Common Or Instance
                             RingVariant_t i_RingVariant,    // base,cache,etc
                             uint8_t       i_instanceId,     // Chiplet Instance ID
                             void**        io_ringBlockPtr,  // Addr of ring buffer
                             uint32_t&     io_ringBlockSize  // size of ring data
                           );


#endif //_P9_TOR_H_
