/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_tor.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#include <p10_scan_compression.H>


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


/// Retrieve a single RS4 ring from a TOR ring section
///
/// \param[in] i_ringSection  A pointer to the ring section.
///
/// \param[in] i_ringId  A enum to indicate unique ID for the ring
///
/// \param[in] i_ddLevel  A variable to indicate chip DD level. TOR API uses
///                       DD level to verify validity of ring section.
///
/// \param[in] i_chipletId  A variable to indicate chiplet instance ID. Only
///                         used for Instance rings. Ignored for Common rings.
///
/// \param[in/out] io_rs4Ring  A void pointer. Contains copied ring. Note that
///                            it's caller's responsibility to manage buffer.
///
/// \param[in/out] io_ringBufSize  A variable that returns size of ring
///                                copied into io_rs4Ring
///
/// \param[in] i_debug  Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
int tor_get_single_ring ( void*          i_ringSection,
                          uint8_t        i_ddLevel,
                          RingId_t       i_ringId,
                          uint8_t        i_chipletId,
                          void*          io_rs4Ring,
                          uint32_t&      io_ringBufSize, // Query, rs4Size, or max buf size
                          uint32_t       i_dbgl = 0 );


/// Append an RS4 ring to the end of a TOR ring section.
///
/// \param[in/out] io_ringSection  A pointer to a TOR ring section.
///                                Note that caller manages this buffer.
///
/// \param[in] i_maxRingSectionSize  Max ring section size
///
/// \param[in] i_ringId  The enum ID for the ring in rs4Ring to be appended
///
/// \param[in] i_chipletId  The chiplet instance ID. Only needed for Instance rings.
///                         Ignored for Common rings.
///
/// \param[in] i_rs4Ring  Pointer to the RS4 compressed ring container.
///
/// \param[in] i_debug  Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0  See \ref TOR API RETURN errors
///
int tor_append_ring( void*           io_ringSection,
                     uint32_t        i_maxRingSectionSize,
                     RingId_t        i_ringId,
                     uint8_t         i_chipletId,
                     void*           i_rs4Ring, // Ptr to the RS4 ring container
                     uint32_t        i_dbgl = 0 );


/// Inform caller of TOR version
///
/// \param[in] - none
///
/// \retval - TOR version
uint8_t tor_version( void);


/// Retrieve a single RS4 ring from a Dynamic ring section (non-TOR layout).
///
/// \param[in]  i_ringSection A pointer to the Dynamic ring section.
///
/// \param[in]  i_ringId      A enum to indicate unique ID for the ring
///
/// \param[in]  i_selector    A variable representing a "variant" feature of the ringId
///
/// \param[in]  i_ddLevel     A variable to indicate chip DD level. The TOR API
///                           uses ddLevel to verify validity of ring section.
///
/// \param[in/out] io_rs4Ring The IO ring buffer (caller managed) and will contain the
///                           retrieved ring with matching (ringId,selector).
///
/// \param[in/out] io_ringBufSize 1) if ==0 on input, contains RS4 ring size on output.
///                               2) if >0 on input it is assumed it represents max buffer
///                                  size and will contain exact RS4 ring size on output.
///
/// \param[in] i_debug Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
///
int dyn_get_ring( void*         i_ringSection,
                  RingId_t      i_ringId,
                  Rs4Selector_t i_selector,
                  uint8_t       i_ddLevel,
                  void*         io_rs4Ring,     // IO ring buffer (caller mgd)
                  uint32_t&     io_ringBufSize, // Query, rs4Size, or max buf size
                  uint32_t      i_dbgl );


/// Append a single RS4 ring to the end of a Dynamic ring section (non-TOR layout).
///
/// \param[in]  io_ringSection        A pointer to the Dynamic ring section.
///                                   Note that caller manages buffer.
///
/// \param[in]  i_maxRingSectionSize  Max size of i_ringSection.
///
/// \param[in]  i_rs4Ring             The RS4 ring to be appended.
///
/// \param[in] i_debug Debug level [0:3].
///
/// \retval 0 Success
///
/// \retval non-0 See \ref TOR API RETURN errors
///
int dyn_append_ring( void*    io_ringSection,       // Ring section buffer
                     uint32_t i_maxRingSectionSize, // Max size of ringSection for buffer
                     void*    i_rs4Ring,            // RS4 ring
                     uint32_t i_dbgl );


#endif //_P10_TOR_H_
