/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/inband/ody_inband.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file ody_inband.H
/// @brief Odyssey specifics for get/putMMIO inband ops
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB
// EKB-Mirror-To: hostboot

#ifndef _ODY_INBAND_H_
#define _ODY_INBAND_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <mmio_access.H>


namespace mss
{

namespace ody
{

namespace ib
{
static const size_t BUFFER_TRANSACTION_SIZE = 8;

static const uint64_t ODY_IB_CONFIG_OFFSET = 0x0000000000000000ull;

/// @brief Reads 32 bits of data from OpenCAPI config space on the selected Odyssey
///
/// @param[in] i_target     The Odyssey chip to read data from
/// @param[in] i_cfgAddr    The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getOCCfg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_cfgAddr,
    fapi2::buffer<uint32_t>& o_data);


/// @brief Writes 32 bits of data to OpenCAPI config space
///
/// @param[in] i_target     The Odyssey chip to write
/// @param[in] i_cfgAddr    The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putOCCfg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_cfgAddr,
    const fapi2::buffer<uint32_t>& i_data);

} // namespace ib

} // namespace ody

} // namespace mss


#endif
