/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/mmio_access.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file mmio_access.H
///
/// @brief Hardware access functions that needs to be specialized for
///        platform implementation.
///

#ifndef _FAPI2_MMIO_ACCESS_H_
#define _FAPI2_MMIO_ACCESS_H_

#include <fapi2_mmio_access.H>
#include <plat_mmio_access.H>

namespace fapi2
{
  //----------------------------------------------------------------------------
  // HW Communication Functions to be implemented at the platform layer.
  //----------------------------------------------------------------------------
  /**
   * @brief Calls platform-level implementation of getMMIO()
   *
   * @param[in]  i_target     HW target to operate on.
   * @param[in]  i_mmioAddr   Address to read, relative to this Target's system
   *                          MMIO address.
   * @param[in]  i_transSize  Number of bytes to read in a single transaction.
   * @param[out] o_data       Buffer that holds data read from HW target.
   *                          The size of the buffer determines the number of
   *                          bytes that are read.
   *
   * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
   */
  template< TargetType K >
  inline ReturnCode getMMIO(const Target<K>& i_target,
                            const uint64_t i_mmioAddr,
                            const size_t i_transSize,
                            std::vector<uint8_t>& o_data)
  {
    return platGetMMIO(i_target, i_mmioAddr, i_transSize, o_data);
  }

  /**
   * @brief Calls platform-level implementation of putMMIO()
   *
   * @param[in]  i_target    HW target to operate on.
   * @param[in]  i_mmioAddr  Address for write, relative to this Target's
   *                         system MMIO address.
   * @param[in]  i_transSize Size of a single transaction, not the total amount
   *                         of data to be transferred. For example, there is
   *                         a requirement that we access the AXI regs with a
   *                         4-byte load and the SCOM regs with a 8-byte load.
   * @param[in]  i_data      Buffer that holds data to write to the HW target.
   *                         The size of the buffer determines the number of
   *                         bytes to be written.
   * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
   */
  template< TargetType K >
  inline ReturnCode putMMIO(const Target<K>& i_target,
                            const uint64_t i_mmioAddr,
                            const size_t i_transSize,
                            const std::vector<uint8_t>& i_data)
  {
    return platPutMMIO(i_target, i_mmioAddr, i_transSize, i_data);
  }

}; // fapi2 namespace

#endif // _FAPI2_MMIO_ACCESS_H_
