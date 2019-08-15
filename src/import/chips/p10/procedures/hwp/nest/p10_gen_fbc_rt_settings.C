/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_gen_fbc_rt_settings.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_gen_fbc_rt_settings.C
/// @brief Trigger SBE assist to apply fabric runtime settings
///

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_gen_fbc_rt_settings.H>
#include <p10_gen_xscom_init.H>
#include <p10_scom_proc.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Process FBC SL domain attribute to calculate required XSCOM inits
///
/// @param[in]  i_targets           Collection of processor chip targets in drawer
/// @param[out] o_xscom_inits       Vector (address/data pairs) to append
///                                 required XSCOM inits
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///

fapi2::ReturnCode
p10_gen_fbc_rt_settings_append_sl_inits(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    std::vector<std::pair<uint64_t, uint64_t>>& o_xscom_inits)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    for (const auto& l_target : i_targets)
    {
        fapi2::ATTR_PROC_FABRIC_SL_DOMAIN_Type l_sl_domain;
        fapi2::buffer<uint64_t> l_station_mode_data = 0;
        fapi2::buffer<uint64_t> l_station_mode_data_valid_mask = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SL_DOMAIN,
                               l_target,
                               l_sl_domain),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_SL_DOMAIN)");

        FAPI_TRY(PREP_PB_COM_SCOM_EQ0_STATION_MODE(l_target));

        if (l_sl_domain == fapi2::ENUM_ATTR_PROC_FABRIC_SL_DOMAIN_CHIP)
        {
            SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(l_station_mode_data);
        }
        else
        {
            CLEAR_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(l_station_mode_data);
        }

        SET_PB_COM_SCOM_EQ0_STATION_MODE_PB_CFG_SL_DOMAIN_SIZE_EQ0(l_station_mode_data_valid_mask);

        for (uint8_t l_station = 0; l_station < FABRIC_NUM_STATIONS; l_station++)
        {

            uint64_t l_station_mode_addr = PB_COM_SCOM_EQ0_STATION_MODE + (l_station << 6);

            FAPI_TRY(p10_gen_xscom_init(
                         l_target,
                         p10_chipUnitPairing_t(P10_NO_CU, 0),
                         l_station_mode_addr,
                         l_station_mode_data,
                         l_station_mode_data_valid_mask,
                         o_xscom_inits),
                     "Error from p10_gen_xscom_init");
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

// doxygen in header
fapi2::ReturnCode
p10_gen_fbc_rt_settings(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    std::vector<std::pair<uint64_t, uint64_t>>& o_reg_inits)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_IS_MPIPL_Type l_is_mpipl;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL,
                           FAPI_SYSTEM,
                           l_is_mpipl),
             "Error from FAPI_ATTR_GET (ATTR_IS_MPIPL)");

    if (l_is_mpipl == fapi2::ENUM_ATTR_IS_MPIPL_TRUE)
    {
        FAPI_DBG("Skipping execvution (mpipl: %d)",
                 (l_is_mpipl) ? (1) : (0));
        goto fapi_try_exit;
    }

    FAPI_TRY(p10_gen_fbc_rt_settings_append_sl_inits(i_targets,
             o_reg_inits),
             "Error from p10_gen_fbc_rt_settings_append_sl_inits");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
