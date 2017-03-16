/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_tor.H $               */
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
#ifndef _P9_TOR_H_
#define _P9_TOR_H_

#include <common_ringId.H>

#define MAX_TOR_RING_OFFSET  (256*256-1)  // Max value of 2Byte uint

extern const char* ppeTypeName[];
extern const char* ringVariantName[];

#define  TOR_VERSION  3

//
// TOR Magic values for top-level TOR image and TOR sub-images
//
enum TorMagicNum
{
    TOR_MAGIC       = (uint32_t)0x544F52  ,   // "TOR"
    TOR_MAGIC_HW    = (uint32_t)0x544F5248,   // "TORH"
    TOR_MAGIC_SBE   = (uint32_t)0x544F5242,   // "TORB"
    TOR_MAGIC_SGPE  = (uint32_t)0x544F5247,   // "TORG"
    TOR_MAGIC_CME   = (uint32_t)0x544F524D,   // "TORM"
    TOR_MAGIC_OVRD  = (uint32_t)0x544F5252,   // "TORR"
    TOR_MAGIC_OVLY  = (uint32_t)0x544F524C,   // "TORL"
    TOR_MAGIC_CEN   = (uint32_t)0x544F524E,   // "TORN"
};

//
// TOR header field (appears in top of every HW, SBE, CEN, OVRD, etc ring section)
//
typedef struct
{
    uint32_t   magic;
    uint8_t    version;
    ChipType_t chipType;    // Value from ChipType enum
    uint8_t    ddLevel;     // =0xff if MAGIC_HW, >0 all other MAGICs
    uint8_t    numDdLevels; // >0 if MAGIC_HW, =1 all other MAGICs
    uint32_t   size;        // Size of the TOR ringSection.
} TorHeader_t;

#define UNDEFINED_DD_LEVEL (uint8_t)0xff

//
// Subsequent TOR fields (listed in order they appear in TOR for easier understanding)
//
typedef struct
{
    uint32_t offset;
    uint32_t size;
    uint8_t  ddLevel;
    uint8_t  reserved[3];
} TorDdBlock_t;

typedef struct
{
    uint32_t offset;
    uint32_t size;
} TorPpeBlock_t;

typedef struct
{
    uint32_t commonOffset;
    uint32_t instanceOffset;
} TorCpltBlock_t;

typedef uint16_t TorRingOffset_t;  // Ring offset value in TOR offset slot

//@FIXME Discard asap
typedef enum TorOffsetSize
{
    RING_OFFSET_SIZE = 2,
    CPLT_OFFSET_SIZE = 4
} TorOffsetSize_t;

#define TOR_SUCCESS                           0
#define TOR_RING_FOUND                        0
#define TOR_RING_NOT_FOUND                    1
#define TOR_AMBIGUOUS_API_PARMS               2
#define TOR_SECTION_NOT_FOUND                 3
#define TOR_DD_LEVEL_NOT_FOUND                4
#define TOR_OP_BUFFER_INVALID                 5
#define TOR_OP_BUFFER_SIZE_EXCEEDED           6
#define TOR_INVALID_RING_ID                   7
#define TOR_INVALID_INSTANCE_ID               8
#define TOR_INVALID_CHIPLET                   9
#define TOR_INVALID_RING_BLOCK_TYPE          10
#define TOR_INVALID_MAGIC_NUMBER             11
#define TOR_IMAGE_DOES_NOT_SUPPORT_CME       12
#define TOR_IMAGE_DOES_NOT_SUPPORT_SGPE      13
#define TOR_IMAGE_DOES_NOT_SUPPORT_DD_LEVEL  14
#define TOR_IMAGE_DOES_NOT_SUPPORT_PPE_LEVEL 15
#define TOR_RING_AVAILABLE_IN_RINGSECTION    16  // Ring is already present
#define TOR_BUFFER_TOO_SMALL                 17
#define TOR_TOO_MANY_DD_LEVELS               18
#define TOR_OFFSET_TOO_BIG                   19
#define TOR_INVALID_VARIANT                  20

// Different options to extract data using tor_access_ring API
typedef enum RingBlockType
{
    GET_SINGLE_RING      = 0x00,
    GET_DD_LEVEL_RINGS   = 0x01,
    GET_PPE_LEVEL_RINGS  = 0x02,
    PUT_SINGLE_RING      = 0x03
} RingBlockType_t;

enum PpeType
{
    PT_SBE        = 0x00,
    PT_CME        = 0x01,
    PT_SGPE       = 0x02,
    NUM_PPE_TYPES = 0x03
};

///
/// ****************************************************************************
/// Function declares.
/// ****************************************************************************
///
/// Traverse on TOR structure and copies data in granular up to DD type,
/// ppe type, ring type, RS4 ring container and ring address
///
/// \param[in]  i_ringSection A pointer to a Ring section binary image.
/// It contains details of p9 Ring, which is used for scanning operation.
/// TOR API supports two type of binary image. 1) HW image format and 2)
/// SEEPROM image format binary
///
/// \param[in]  i_ringId A enum to indicate unique ID for the ring
///
/// \param[in]  i_ddLevel A variable to indicate chip DD level. TOR API
/// uses DD level to extract single ring or block of rings from hw_image
///
/// \param[in]  i_PpeType A enum to indicate ppe type. They are SBE, CME
/// and SGPE. It is used to decode TOR structure
///
/// \param[in/out] io_RingType A enum and passed by reference. Acts as input
/// paramfor extracting block of rings copy under Chiplet level. Acts as
/// outputparam to indicate type of single ring copied is whether common or
/// instance specific ring
///
/// \param[in]  i_RingVariant A enum to indicate which variant type of
/// requested for single ring extract. There are three major types. They are
/// base, Cache contained and Risk level ring
///
/// \param[in/out] io_instanceId A variable to indicate chiplet instance ID.
/// It returns Chiplet instance ID while doing get single ring operation
///
/// \param[in] i_RingVariant  A enum to indicate type of operation performed
/// by TOR API Option:
/// GET_SINGLE_RING indicates to extract single ring container.
/// GET_DD_LEVEL_RINGS indicates to extract specific DD level TOR and rings
/// GET_PPE_LEVEL_RINGS indcates to extract specific PPE level TOR and rings
/// GET_CPLT_LEVEL_RINGS indciates to extract specific chiplet ring type
/// TOR and rings
/// PUT_SINGLE_RING indicates to extract ring absolute memory addres for
/// ringType start and ringTorSlot location
///
/// \param[in/out] io_ringBlockPtr A void pointer to pointer. Returns data
/// which copied during extract ring operation and returns tor absolute address
/// where RingType offset slot is located while PUT_SINGLE_RING call.
/// Note:- Caller's responsibility for free() to avoid memory leak
///
/// \param[in/out] io_ringBlockSize A variable. Returns size of data copied
/// into io_ringBlockPtr and returns absolute offset where ring RS4 starts in
/// TOR during PUT_SINGLE_RING call
///
/// \param[out] o_ringName A string. Returns name of ring ID in characters
///
/// \param[in] - i_debug is debug statment params. Supports 0 to 3.
///
/// This API traverse TOR structure of .ringSection from HW image or SBE image
/// and the following n number of operation based on the call.
///
/// GET_SINGLE_RING (\a i_ringVariant) - traverse on \a i_ringSection buffer
/// based on \a i_ringId which gives ring info, \a i_ddLevel which gives dd spec
/// (Used only for HW image/optional for other image) i_ppeType which gives ppe
/// type info, \a i_ringVarint gives ring variant info and \a io_instance which
/// gives chiplet instance specific while accessing instance specific ring and
/// returns chiplet number while accessing common ring. On return,
/// \a io_ringBlockPtr contains RS4 container \a io_RingType contains which
/// ring type of ring requested and \a io_ringBlockSize contains size of the
/// data copied into io_ringBlockPtr. \a o_ringName returns ring string name.
///
/// GET_DD_LEVEL_RINGS (\a i_ringVariant) - traverse on \a i_ringSection
/// buffer based on \a i_ddLevel which gives dd spec (used only for HW image
/// /optional  for other image) On return, \a io_ringBlockPtr contains DD level
/// specific ring section and \a io_ringBlockSize contains size of the data
/// copied into io_ringBlockPtr. \a Other params are optional.
/// This ringVariant works on HW image.
///
/// GET_PPE_LEVEL_RINGS (\a i_ringVariant) - traverse on \a i_ringSection
/// buffer based on \a i_ppeType which gives ppe type info  and \a i_ddLevel which
/// gives dd spec used only for HW image/optional for other image) On return,
/// \a io_ringBlockPtr contains PPE type specific ring section and
/// \a io_ringBlockSize contains size of the data copied into io_ringBlockPtr.
/// \a Other params are optional. This ringVariant works on HW image.
///
/// GET_CPLT_LEVEL_RINGS (\a i_ringVariant) - traverse on \a i_ringSection
/// buffer based on \a i_ppeType which gives ppe type info, \a i_ddLevel which gives
/// dd spec (used only for HW image/optional for other image) and \a io_RingType
/// which gives ring type info. On return, \a io_ringBlockPtr contains chiplet
/// specific ring type ring section and \a io_ringBlockSize contains size of
/// the data copied into io_ringBlockPtr. \a Other params are optional.
///
/// PUT_SINGLE_RING (\a i_ringVariant) - traverse on \a i_ringSection buffer
/// based on \a i_ringId which gives ring info, \a i_ddLevel which gives dd spec
/// (used only for HW image/optional for other image), i_ppeType which gives
/// ppe type info, \a i_ringVarint gives ring variant info and \a io_instance
/// which gives chiplet instance specific while accessing instance specific
/// ring and returns chiplet number while accessing common ring. On return,
/// \a io_ringBlockPtr contains absolute memory address of ring type of
/// requested ring and \a io_ringBlockSize contains of absolute memory addres
/// of ringTor slot copied into io_ringBlockPtr \a o_ringName returns ring
/// string name
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_access_ring( void*           i_ringSection, // Ring address Ptr any of .rings, .overrides and .overlays.
                     RingId_t        i_ringId,         // Unique ring ID
                     uint16_t        i_ddLevel,        // DD level info
                     PpeType_t       i_PpeType,        // PPE type : SBE, CME, etc
                     RingType_t&     io_RingType,      // 0: Common 1: Instance
                     RingVariant_t   i_RingVariant,    // Base, Cache etc
                     uint8_t&        io_instanceId,    // chiplet instance ID
                     RingBlockType_t i_RingBlockType,  // 0: single ring,  1: ring block
                     void**          io_ringBlockPtr,  // Addr of ring buffer
                     uint32_t&       io_ringBlockSize, // size of ring data
                     char*           o_ringName,       // Ring name
                     uint32_t        i_dbgl = 0 );     // Debug option


/// Traverse on TOR structure and copies RS4 ring container data for ring
/// variant
///
/// \param[in]  i_ringSection A pointer to a Ring section binary image.
/// It contain details of p9 Ring which is used for scanning operation.
/// TOR API supports HW image format  only
///
/// \param[in]  i_ringId A enum to indicate unique ID for the ring
///
/// \param[in]  i_ddLevel A variable to indicate chip DD level. TOR API
/// uses DD level to extract single ring or block of rings on hw_image.
///
/// \param[in]  i_PpeType A enum to indicate ppe type.
/// They are SBE, CME and SGPE. It is used to decode TOR structure
///
/// \param[in]  i_RingVariant A enum to indicate which variant type of
/// requested for get single ring operation There are three major types.
/// They are base, Cache contained and Risk level ring
///
/// \param[in] io_instanceId A variable to indicate chiplet instance ID
///
/// \param[in/out] io_ringBlockPtr A void point to pointer. Returns data
/// which copied during extract ring operation
/// Note- Caller's responsibility for free() to avoid memory leak
///
/// \param[in/out] io_ringBlockSize A variable. Returns size of data copied
///  into io_ringBlockPtr
///
/// \param[in] - i_debug is debug statment params. Supports 0 to 3.
///
/// This API contains wrapper on top of tor_access_ring API to support get
/// single ring container from .ring section and customizes for
/// get_single_ring parameter.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_get_single_ring ( void*          i_ringSection,
                          uint16_t       i_ddLevel,
                          RingId_t       i_ringId,
                          PpeType_t      i_PpeType,
                          RingVariant_t  i_RingVariant,
                          uint8_t        i_instanceId,
                          void**         io_ringBlockPtr,
                          uint32_t&      io_ringBlockSize,
                          uint32_t       i_dbgl = 0 );        // Debug option

/// Traverse on TOR structure and copies data in block level up to DD type,
/// ppe type and ring type
///
/// \param[in]  i_ringSection A pointer to a Ring section binary image.
/// It contains details of p9 Ring which is used for scanning operation.
/// API supports HW image format only
///
/// \param[in]  i_ddLevel A variable to indicate chip DD level. TOR API
/// uses DD level to extract single ring or block of rings on hw_image
///
/// \param[in]  i_PpeType A enum to indicate ppe type passed.
/// they are SBE, CME and SGPE. It is used to decode TOR structure
/// TOR API uses Ppe type to extract single ring or block of rings
/// on either hw_image or SBE image
///
/// \param[in]  i_RingType A enum and passed by reference. Acts as
/// input param for extracting block of rings copy under Chiplet level
///
/// \param[in]  i_RingVariant A enum to indicate which variant type of
/// requested for single ring extract. There are three major types.
/// They are base, Cache contained and Risk level ring
///
/// \param[in]  i_instanceId A variable to indicate chiplet instance ID
///
/// \param[in/out] io_ringBlockPtr A void point to pointer. Returns data
/// which copied block of rings. Note: Caller's responsibility for free()
/// to avoid memory leak
//
/// \param[in/out] io_ringBlockSize A variable. Returns size of data
/// copied into io_ringBlockPtr
///
/// \param[in] - i_debug is debug statment params. Supports 0 to 3.
///
/// This API contains wrapper on top of tor_access_ring API and supports
/// to copy block of rings in DD level, ppe level and ringType level.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_get_block_of_rings ( void*          i_ringSection,
                             uint16_t       i_ddLevel,
                             PpeType_t      i_PpeType,
                             RingType_t     i_RingType,
                             RingVariant_t  i_RingVariant,
                             uint8_t        i_instanceId,
                             void**         io_ringBlockPtr,
                             uint32_t&      io_ringBlockSize,
                             uint32_t       i_dbgl = 0 );

/// Traverse on TOR structure and copies absolute memory address of Ringtype
///  offset addres and TOR offset slot address
///
/// \param[in]  i_ringSection A pointer to a Ring section binary image.
/// It contains details of p9 Ring which is used for scanning operation.
///  TOR API supports SEEPROM image format.
///
/// \param[in/out]  io_ringSectionSize   In: Exact size of i_ringSection.
/// Out: Updated size of i_ringSection.
/// Note: Caller manages this buffer and must make sure the RS4 ring fits
/// before making this call
///
/// \param[in]  i_ringBuffer A pointer to a ring work buffer, which is used
/// for scanning operation purpose
///
/// \param[in]  i_ringBufferSize A constant value to indicate size of
/// ringBuffer data passed in
///
/// \param[in]  i_ringId A enum to indicate unique ID for the ring
///
/// \param[in]  i_PpeType A enum to indicate ppe type. They are SBE,
/// CME and SGPE. It is used to decode TOR structure
///
/// \param[in]  i_RingType A enum to indicate ring type of ring whether
/// common or instance specific ring
///
/// \param[in]  i_RingVariant A enum and used as input param to indicate
/// which variant type of requested for single ring extract
///
/// \param[in] i_instanceId A variable to indicate chiplet instance ID
///
/// \param[in] i_rs4_container A void pointer. Contains RS4 compressed ring
/// data which eventually attached into void image pointer i_ringSection
///
/// \param[in] - i_debug is debug statment params. Supports 0 to 3.
///
/// This API contains wrapper on tor_access_ring to get \a io_ringBlockPtr
/// contains absolute memory address of ring type start address of the ring
/// \a io_ringBlockSize contains absolute memory address of ringTorslot. Then
/// appends new rs4 ring container at the end of ring section and updates new
/// ring offset address on ring offset location. the slot must be empty. If there
/// is non-zero content in the slot, the API will fail catastrophically. Do not
/// "insert" or "replace" rings at ring section.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_append_ring(  void*           i_ringSection,
                      uint32_t&       io_ringSectionSize,
                      void*           i_ringBuffer,
                      const uint32_t  i_ringBufferSize,
                      RingId_t        i_ringId,
                      PpeType_t       i_ppeType,
                      RingType_t      i_RingType,
                      RingVariant_t   i_RingVariant,
                      uint8_t         i_instanceId,
                      void*           i_rs4Container,
                      uint32_t        i_dbgl = 0 );


/// Inform caller of TOR version
///
/// \param[in] - none
///
/// \retval - TOR version
uint8_t tor_version( void);

#endif //_P9_TOR_H_

