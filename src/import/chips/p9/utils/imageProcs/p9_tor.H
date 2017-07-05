/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_tor.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

// Different options to extract data using tor_access_ring API
typedef enum RingBlockType
{
    GET_SINGLE_RING     = 0x00,
#ifdef TORV3_SUPPORT
    GET_DD_LEVEL_RINGS  = 0x01,
#endif
    GET_PPE_LEVEL_RINGS = 0x02,
    PUT_SINGLE_RING     = 0x03
} RingBlockType_t;

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
/// GET_PPE_LEVEL_RINGS indcates to extract specific PPE level TOR and rings
/// PUT_SINGLE_RING indicates to extract ring absolute memory addres for
/// ringTorSlot location
///
/// \param[in/out] io_ringBlockPtr A void pointer to pointer. Returns data
/// which copied during extract ring operation and returns tor absolute address
/// where offset slot is located while PUT_SINGLE_RING call.
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
/// \a io_ringBlockPtr contains RS4 container \a io_ringBlockSize contains size
/// of data copied into io_ringBlockPtr. \a o_ringName returns ring string name.
///
/// GET_PPE_LEVEL_RINGS (\a i_ringVariant) - traverse on \a i_ringSection
/// buffer based on \a i_ppeType which gives ppe type info  and \a i_ddLevel which
/// gives dd spec used only for HW image/optional for other image) On return,
/// \a io_ringBlockPtr contains PPE type specific ring section and
/// \a io_ringBlockSize contains size of the data copied into io_ringBlockPtr.
/// \a Other params are optional. This ringVariant works on HW image.
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
int tor_access_ring( void*           i_ringSection,    // Ring section ptr
                     RingId_t        i_ringId,         // Unique ring ID
                     uint8_t         i_ddLevel,        // DD level info
                     PpeType_t       i_PpeType,        // PPE type : SBE, CME, etc
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
                          uint8_t        i_ddLevel,
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
/// \param[in]  i_RingVariant A enum to indicate which variant type of
/// requested for single ring extract. There are three major types.
/// They are base, Cache contained and Risk level ring
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
/// to copy block of rings in DD level and PPE level rings.
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_get_block_of_rings ( void*          i_ringSection,
                             uint8_t        i_ddLevel,
                             PpeType_t      i_PpeType,
                             RingVariant_t  i_RingVariant,
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

