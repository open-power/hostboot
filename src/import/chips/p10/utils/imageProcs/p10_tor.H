/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_tor.H $             */
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
#ifndef _P10_TOR_H_
#define _P10_TOR_H_

#include <common_ringId.H>


///
/// ****************************************************************************
/// Function declares.
/// ****************************************************************************
///
/// Traverse on TOR structure and copies data in granular up to DD type,
/// ppe type, ring type, RS4 ring container and ring address
///
/// \param[in]  i_ringSection A pointer to a Ring section binary image.
///
/// \param[in]  i_ringId A enum to indicate unique ID for the ring
///
/// \param[in]  i_ddLevel A variable to indicate chip DD level. TOR API
/// uses DD level to extract single ring or block of rings from hw_image
///
/// \param[in/out] io_instanceId A variable to indicate chiplet instance ID.
/// It returns Chiplet instance ID while doing get single ring operation
///
/// \param[in] i_ringRequest  A enum to indicate type of operation performed
/// by TOR API Option:
/// GET_SINGLE_RING indicates to extract single ring container.
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
/// \param[in] i_debug Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_access_ring( void*           i_ringSection,    // Ring section ptr
                     RingId_t        i_ringId,         // Ring ID
                     uint8_t         i_ddLevel,        // DD level info
                     uint8_t&        io_instanceId,    // Chiplet instance ID
                     RingRequest_t   i_ringRequest,    // {GET,PUT}_SINGLE_RING
                     void**          io_ringBlockPtr,  // Addr of ring buffer
                     uint32_t&       io_ringBlockSize, // Size of ring data
                     char*           o_ringName,       // Ring name
                     uint32_t        i_dbgl = 0 );     // Debug option


/// Traverse on TOR structure and copies RS4 ring container data
///
/// \param[in]  i_ringSection A pointer to a Ring section binary image.
///
/// \param[in]  i_ringId A enum to indicate unique ID for the ring
///
/// \param[in]  i_ddLevel A variable to indicate chip DD level. TOR API
/// uses DD level to extract single ring or block of rings on hw_image.
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
/// \param[in] i_debug Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_get_single_ring ( void*          i_ringSection,
                          uint8_t        i_ddLevel,
                          RingId_t       i_ringId,
                          uint8_t        i_instanceId,
                          void**         io_ringBlockPtr,
                          uint32_t&      io_ringBlockSize,
                          uint32_t       i_dbgl = 0 );        // Debug option

/// Traverse on TOR structure and copies absolute memory address of Ringtype
/// offset addres and TOR offset slot address
///
/// \param[in] i_ringSection A pointer to a Ring section binary image.
///
/// \param[in/out] io_ringSectionSize   In: Exact size of i_ringSection.
/// Out: Updated size of i_ringSection.
/// Note: Caller manages this buffer and must make sure the RS4 ring fits
/// before making this call
///
/// \param[in] i_ringId A enum to indicate unique ID for the ring
///
/// \param[in] i_instanceId A variable to indicate chiplet instance ID
///
/// \param[in] i_rs4_container A void pointer. Contains RS4 compressed ring
/// data to be appended at the end of binary i_ringSection
///
/// \param[in] i_debug Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
///
int tor_append_ring( void*           i_ringSection,
                     uint32_t&       io_ringSectionSize,
                     RingId_t        i_ringId,
                     uint8_t         i_instanceId,
                     void*           i_rs4Container,
                     uint32_t        i_dbgl = 0 );


/// Create a complete TOR ring section but with empty offset ring slots.
///
/// \param[in/out] io_ringSection A pointer to a ring section binary image.
/// This ring section should initially be empty. If not, it'll be overwritten.
///
/// \param[in] i_torMagic TOR magic number.
///
/// \param[in] i_torVersion TOR version.
///
/// \param[in] i_ddLevel The ddLevel.
///
/// \param[in] i_chipId The chip ID.
///
/// \param[in] i_debug Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
///
int tor_skeleton_generation( void*         io_ringSection,
                             uint32_t      i_torMagic,
                             uint8_t       i_torVersion,
                             uint8_t       i_ddLevel,
                             ChipId_t      i_chipId,
                             uint32_t      dbgl = 0 );


/// Inform caller of TOR version
///
/// \param[in] - none
///
/// \retval - TOR version
uint8_t tor_version( void);

#endif //_P10_TOR_H_
