/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/inband/ody_inband.C $ */
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

/// @file ody_inband.C
/// @brief implement OpenCAPI config.
//
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB
// EKB-Mirror-To: hostboot

#include <lib/inband/ody_inband.H>
#include <lib/shared/ody_consts.H>
#include <mmio_access.H>
#include <generic/memory/lib/utils/endian_utils.H>

namespace mss
{

namespace ody
{

namespace ib
{

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
    fapi2::buffer<uint64_t>& o_data)
{
    uint64_t l_rd = 0;
    std::vector<uint8_t> l_data(8);
    uint32_t l_idx = 0;
    FAPI_TRY(fapi2::getMMIO(i_target, ODY_IB_MMIO_OFFSET | i_addr, 8, l_data));
    readLE(l_data, l_idx, l_rd);
    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

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
    fapi2::buffer<uint32_t>& o_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint32_t l_rd = 0;
    std::vector<uint8_t> l_data(4);
    uint32_t l_idx = 0;
    fapi2::ATTR_MSS_OCMB_ODY_OMI_CFG_ENDIAN_CTRL_Type l_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_ODY_OMI_CFG_ENDIAN_CTRL,
                           FAPI_SYSTEM, l_endian));

    FAPI_TRY(fapi2::getMMIO(i_target, i_cfgAddr | ODY_IB_CONFIG_OFFSET, 4, l_data));

    if (l_endian == fapi2::ENUM_ATTR_MSS_OCMB_ODY_OMI_CFG_ENDIAN_CTRL_LITTLE_ENDIAN)
    {
        readLE(l_data, l_idx, l_rd);
    }
    else
    {
        readBE(l_data, l_idx, l_rd);
    }

    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

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
    const fapi2::buffer<uint64_t>& i_data)
{
    uint64_t l_v = static_cast<uint64_t>(i_data);
    std::vector<uint8_t> l_wd;
    forceLE(l_v, l_wd);
    return fapi2::putMMIO(i_target, ODY_IB_MMIO_OFFSET | i_addr, 8, l_wd);
}

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
    const fapi2::buffer<uint32_t>& i_data)
{
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint32_t l_v = static_cast<uint32_t>(i_data);
    std::vector<uint8_t> l_wd;
    fapi2::ATTR_MSS_OCMB_ODY_OMI_CFG_ENDIAN_CTRL_Type l_endian;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_ODY_OMI_CFG_ENDIAN_CTRL,
                           FAPI_SYSTEM, l_endian));

    if (l_endian == fapi2::ENUM_ATTR_MSS_OCMB_ODY_OMI_CFG_ENDIAN_CTRL_LITTLE_ENDIAN)
    {
        forceLE(l_v, l_wd);
    }
    else
    {
        forceBE(l_v, l_wd);
    }

    FAPI_TRY(fapi2::putMMIO(i_target, i_cfgAddr | ODY_IB_CONFIG_OFFSET, 4, l_wd));

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t)fapi2::current_err);
    return fapi2::current_err;
}

} // namespace ib

} // namespace ody

} // namespace mss
