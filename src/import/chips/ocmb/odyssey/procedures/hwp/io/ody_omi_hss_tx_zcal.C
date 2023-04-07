/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_tx_zcal.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_hss_tx_zcal.C
/// @brief Odyssey HWP that runs TDR on links
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_tx_zcal.H>
#include <common_io_omi_tdr.H>
#include <ody_io_ppe_common.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_tx_zcal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start");

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sys;
    fapi2::ATTR_IS_SIMULATION_Type l_sim = 0;
    fapi2::ATTR_IS_SIMICS_Type l_simics = fapi2::ENUM_ATTR_IS_SIMICS_REALHW;
    fapi2::ATTR_MSS_IS_APOLLO_Type l_is_apollo;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, l_sys, l_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, l_sys, l_simics));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_IS_APOLLO, l_sys, l_is_apollo));

    if (!l_sim && !l_is_apollo && !(l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS))
    {
        fapi2::ATTR_FREQ_OMI_MHZ_Type l_freq;

        FAPI_DBG("Running OMI TDR");
        // Run TDR isolation
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_freq));
        FAPI_TRY(common_io_omi_tdr(i_target, l_freq, PHY_ODY_OMI_BASE),
                 "Error on TDR isolation");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
