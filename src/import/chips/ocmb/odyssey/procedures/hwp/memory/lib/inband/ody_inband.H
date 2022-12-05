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

/// One host bar register is set per MC channel for MMIO, and another
/// is set per MC channel for config space.  Each bar is shared between
/// both sub-channels each with an OCMB.  The upper bit of the address
/// determined by the bar sizes is used to determine which sub-channel
/// is selected.  This means that for a pair of OCMB's on a channel
/// their config space is contiguous and their MMIO space is contiguous.
/// Therefore a single OCMB's MMIO and config space cannot be contiguous.
/// However, we can still use one BAR attribute and the set_bars procedure
/// can interleave the config space and MMIO space as shown in the table
/// bellow.  For example, both MMIO and config bar sizes are 2GB.  The
/// 2GB bit becomes the selector for the subchannel.  The 4GB bit
/// becomes the offset applied for MMIO operations.
///
///
/// Each OCMB is assigned one base address attribute.  For example:
/// ocmb  |  BAR ATTRIBUTE     | Type | Base reg           - end addr           | size | sub-ch
/// +-----+--------------------+------+-----------------------------------------+------+-------
/// ocmb0 | 0x0006030200000000 | cnfg | 0x0006030200000000 - 0x000603027FFFFFFF | 2GB  | 0
/// ocmb1 | 0x0006030280000000 | cnfg | 0x0006030280000000 - 0x00060302FFFFFFFF | 2GB  | 1
/// ocmb0 | N/A                | mmio | 0x0006030300000000 - 0x000603037FFFFFFF | 2GB  | 0
/// ocmb1 | N/A                | mmio | 0x0006030380000000 - 0x00060303FFFFFFFF | 2GB  | 1
/// +-----+--------------------+------+-----------------------------------------+------+-------
/// ocmb2 | 0x0006030400000000 | cnfg | 0x0006030400000000 - 0x000603047FFFFFFF | 2GB  | 0
/// ocmb3 | 0x0006030480000000 | cnfg | 0x0006030480000000 - 0x00060304FFFFFFFF | 2GB  | 1
/// ocmb2 | N/A                | mmio | 0x0006030500000000 - 0x000603057FFFFFFF | 2GB  | 0
/// ocmb3 | N/A                | mmio | 0x0006030580000000 - 0x00060305FFFFFFFF | 2GB  | 1
///

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
static const uint64_t ODY_IB_MMIO_OFFSET = 0x0000000100000000ull;

//--------------------------------------------------------------------------------
// Read operations
//--------------------------------------------------------------------------------

/// @brief Reads 64 bits of data from MMIO space on the selected Odyssey
///
/// @param[in] i_target     The Odyssey chip to read data from
/// @param[in] i_addr       The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getMMIO64(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    fapi2::buffer<uint64_t>& o_data);

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


//--------------------------------------------------------------------------------
// Write operations
//--------------------------------------------------------------------------------

/// @brief Writes 64 bits of data to MMIO space to the selected Odyssey
///
/// @param[in] i_target     The Odyssey chip to write
/// @param[in] i_addr       The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putMMIO64(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    const fapi2::buffer<uint64_t>& i_data);

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
