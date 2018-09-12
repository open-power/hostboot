/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_mmio_access.H $                    */
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
/// @file plat_mmio_access.H
///
/// @brief Platform mmio-access definitions
///

#ifndef _FAPI2_PLAT_MMIOACCESS_H_
#define _FAPI2_PLAT_MMIOACCESS_H_

namespace fapi2
{

  /**
   * @brief Platform-level implementation of getMMIO()
   *        Reads data via MMIO from the target
   *
   * @param[in]  i_target     FAPI HW target to operate on.
   * @param[in]  i_mmioAddr   Address to read, relative to this Target's system
   *                          MMIO address.
   * @param[in]  i_transSize  Number of bytes to read in a single transaction.
   * @param[out] o_data       Buffer that holds data read from HW target.
   *                          The size of the buffer determines the number of
   *                          bytes that are read.
   *
   * @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
   */
  ReturnCode platGetMMIO( const Target<TARGET_TYPE_ALL>& i_target,
                          const uint64_t i_mmioAddr,
                          const size_t i_transSize,
                          std::vector<uint8_t>& o_data );

  /**
   * @brief Platform-level implementation of putMMIO()
   *        Writes data via MMIO to the target
   *
   * @param[in]  i_target    FAPI HW target to operate on.
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
  ReturnCode platPutMMIO( const Target<TARGET_TYPE_ALL>& i_target,
                          const uint64_t i_mmioAddr,
                          const size_t i_transSize,
                          const std::vector<uint8_t>& i_data );

};
#endif // _FAPI2_PLAT_MMIOACCESS_H_
