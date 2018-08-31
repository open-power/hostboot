/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_setup_runtime_wakeup_mode.C $ */
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
/// @file   p9_setup_runtime_wakeup_mode.H
/// @brief  describes HWP interface that configures runtime wakeup mode of core.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot
//

#include <p9_setup_runtime_wakeup_mode.H>
#include <p9_quad_scom_addresses.H>

enum
{
    RUN_TIME_WAKEUP_MODE_BIT_POS    =   3,
    HV_COMPATIBILITY_MODE_BIT_POS   =   4,
};

fapi2::ReturnCode p9_setup_runtime_wakeup_mode(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget )
{
    FAPI_INF("> p9_setup_runtime_wakeup_mode" );
    fapi2::buffer<uint64_t> l_wakeupMode;
    uint8_t l_smfEnabled;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_coreList =
        i_procTarget.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SMF_ENABLED,
                           FAPI_SYSTEM,
                           l_smfEnabled),
             "Error from FAPI_ATTR_GET for attribute ATTR_SMF_ENABLED ");

    FAPI_DBG("SMF Status : %s", l_smfEnabled ? "Enabled" : "Disabled" );

    for( auto core : l_coreList )
    {
        FAPI_TRY(fapi2::getScom( core, C_CPPM_CPMMR, l_wakeupMode),
                 "Failed To Read CPMMR");

        FAPI_DBG( "Initial CPMMR Value 0x%016llx", l_wakeupMode );

        if( l_smfEnabled )
        {
            //Wakeup in Ultravisor mode
            l_wakeupMode.clearBit( RUN_TIME_WAKEUP_MODE_BIT_POS );
            l_wakeupMode.clearBit( HV_COMPATIBILITY_MODE_BIT_POS );
        }
        else
        {
            //Wakeup in Hypervisor mode
            l_wakeupMode.setBit( RUN_TIME_WAKEUP_MODE_BIT_POS );
            l_wakeupMode.setBit( HV_COMPATIBILITY_MODE_BIT_POS );
        }

        FAPI_TRY(fapi2::putScom(core, C_CPPM_CPMMR, l_wakeupMode),
                 "Failed To Write CPMMR");

        FAPI_DBG( "Final CPMMR Value 0x%016llx", l_wakeupMode );

    }

fapi_try_exit:
    FAPI_INF("< p9_setup_runtime_wakeup_mode" );
    return fapi2::current_err;
}
