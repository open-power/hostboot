/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_mmio_access.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
///
/// @file fapi2_mmio_access.H
/// @brief Common file that defines the mmio access functions that
/// platform code must implement.
///

#ifndef _FAPI2_COMMON_MMIO_ACCESS_H_
#define _FAPI2_COMMON_MMIO_ACCESS_H_

// Note : deliberately not including header files in here
//        in order to force users to always include the
//        external header 'mmio_access.H'

namespace fapi2
{

/// @brief Reads data via mmio from the target
///
/// @tparam K the type (Kind) of target, from i_target
/// @tparam V the type of the target's Value, from i_target
/// @param[in]  i_target     HW target to operate on.
/// @param[in]  i_mmioAddr   Address to read, relative to this Target's system
///                          MMIO address.
/// @param[in]  i_transSize  Number of bytes to read in a single transaction.
/// @param[out] o_data       Buffer that holds data read from HW target.
///                          The size of the buffer determines the number of
///                          amount of bytes that are read.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, typename V >
inline ReturnCode getMMIO(const Target<K, V>& i_target,
                          const uint64_t i_mmioAddr,
                          const size_t i_transSize,
                          std::vector<uint8_t>& o_data);

/// @brief Writes data via mmio to the target.
///
/// @tparam K the type (Kind) of target, from i_target
/// @tparam V the type of the target's Value, from i_target
/// @param[in] i_target      HW target to operate on.
/// @param[in] i_mmioAddr   Address to read, relative to this Target's system
///                          MMIO address.
/// @param[in]  i_transSize  Number of bytes to read in a single transaction.
/// @param[in] i_data        Buffer that holds data to write to the HW target.
///                          The size of the buffer determines the number of
///                          amount of bytes that are written.
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template< TargetType K, typename V >
inline ReturnCode putMMIO(const Target<K, V>& i_target,
                          const uint64_t i_mmioAddr,
                          const size_t i_transSize,
                          const std::vector<uint8_t>& i_data);

};

#endif // _FAPI2_COMMON_MMIO_ACCESS_H_
