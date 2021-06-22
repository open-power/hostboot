/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_dynamic_vio.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_io_dynamic_vio.C
/// @brief Adjust VIO based on the system config
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HWSV
///-----------------------------------------------------------------------------
// EKB-Mirror-To: hwsv

#include <p10_io_dynamic_vio.H>


///
/// @brief Set VIO based on the configuration
///
/// @param[in] i_target    Chip target to start
/// @param[in] i_num_nodes Number of nodes
/// @param[in] i_revision  Revision of processor
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_dynamic_vio(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t& i_num_nodes,
    const uint8_t& i_version,
    uint32_t& o_vio_mv)
{
    const uint32_t C_MIN_VIO_MV = 930;
    const uint32_t C_MAX_VIO_MV = 1040;
    const uint32_t C_MIN_CONFIG_DIMMS = 8;
    const uint32_t C_BASE_VIO_UV = i_version ? 960000 : 1020000; // 960mv or 1020mv
    const uint32_t C_DIMM_UPLIFT = 900; // 900uV
    const uint32_t C_ABUS_UPLIFT = 2666; // 2.666mV
    uint32_t l_uplift = 0;
    uint32_t l_num_dimms = 0;

    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        for (auto l_omic_target : l_omic_targets)
        {
            auto l_omi_targets = l_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();
            l_num_dimms += l_omi_targets.size();
        }
    }


    // Max uplift = (0.900mV * 8 DIMMs) + (2.666mV * 3 Abus Ports) = 15.2mV
    // Abus
    if (i_num_nodes == 4)
    {
        l_uplift += C_ABUS_UPLIFT * 3;
    }
    else if (i_num_nodes == 3 || i_num_nodes == 2)
    {
        l_uplift += (C_ABUS_UPLIFT * 2);
    }

    // OMI
    if (l_num_dimms > C_MIN_CONFIG_DIMMS)
    {
        l_uplift += (C_DIMM_UPLIFT * (l_num_dimms - C_MIN_CONFIG_DIMMS));
    }

    FAPI_DBG("Dynamic VIO :: Nodes(%d) Dimms(%d)", i_num_nodes, l_num_dimms);

    o_vio_mv = (C_BASE_VIO_UV + l_uplift + 500) / 1000; // Convert to mv
    FAPI_DBG("Dynamic VIO :: Basepoint(%d uV) Uplift(%d uV) Final(%d mV)", C_BASE_VIO_UV, l_uplift, o_vio_mv);

    if (o_vio_mv < C_MIN_VIO_MV)
    {
        FAPI_DBG("Dynamic VIO :: Adjusted VIO(%d) is below the minimum(%d).  Forcing to Minimum.", o_vio_mv,
                 C_MIN_VIO_MV);
        o_vio_mv = C_MIN_VIO_MV;
    }
    else if (o_vio_mv > C_MAX_VIO_MV)
    {
        FAPI_DBG("Dynamic VIO :: Adjusted VIO(%d) is above the maximum(%d).  Forcing to Maximum.", o_vio_mv,
                 C_MAX_VIO_MV);
        o_vio_mv = C_MAX_VIO_MV;
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VIO_SET_POINT_MV, i_target, o_vio_mv));

fapi_try_exit:
    return fapi2::current_err;
}
