/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_setup_runtime_wakeup_mode.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file   p10_setup_runtime_wakeup_mode.H
/// @brief  describes HWP interface that configures runtime wakeup mode of core.
///
/// *HWP HWP Owner:      Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner:       Prem S Jha <premjha2@in.ibm.com>
/// *HWP Team:           PM
/// *HWP Level:          2
/// *HWP Consumed by:    Hostboot
//

#include <p10_setup_runtime_wakeup_mode.H>
#include <p10_scom_eq_c.H>
#include <multicast_group_defs.H>
#include <p10_pm_hcd_flags.h>

void testWakeUpMode( uint32_t i_qmeFlag, fapi2::buffer<uint64_t> i_wakeupMode )
{
    FAPI_DBG( "Setup Runtime Wakeup Mode 0x%08x , x%016lx",
              i_qmeFlag, i_wakeupMode );
}

fapi2::ReturnCode p10_setup_runtime_wakeup_mode(
    const fapi2::Target < fapi2::TARGET_TYPE_PROC_CHIP>& i_procTarget )
{
    FAPI_INF("> p10_setup_runtime_wakeup_mode" );
    fapi2::buffer<uint64_t> l_wakeupMode;
    uint8_t l_smfConfig         =   0;
    uint32_t l_qmeFlagReggAddr  =   scomt::eq::QME_FLAGS_WO_OR;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

// TODO:  why only SIM?
#ifndef __SIM_ENV
    auto l_eq_mc_or             =   i_procTarget.getMulticast<fapi2::TARGET_TYPE_EQ,
         fapi2::MULTICAST_OR >(fapi2::MCGROUP_GOOD_EQ);
#endif

    l_wakeupMode.flush<0>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SMF_CONFIG,
                           FAPI_SYSTEM,
                           l_smfConfig),
             "Error from FAPI_ATTR_GET for attribute ATTR_SMF_CONFIG ");

    FAPI_INF("SMF Status : %s", l_smfConfig ? "Enabled" : "Disabled" );

    l_wakeupMode.setBit( p10hcd::QME_FLAGS_RUNTIME_WAKEUP_MODE );
    l_wakeupMode.setBit( p10hcd::QME_FLAGS_SMF_DISABLE_MODE );

    if( l_smfConfig )
    {
        //Wakeup in Ultravisor mode
        l_qmeFlagReggAddr   =   scomt::eq::QME_FLAGS_WO_CLEAR;
    }
    else
    {
        //Wakeup in Hypervisor mode
        l_qmeFlagReggAddr   =   scomt::eq::QME_FLAGS_WO_OR;
    }



#ifdef __SIM_ENV

    testWakeUpMode( l_qmeFlagReggAddr, l_wakeupMode );

#else

    FAPI_TRY( putScom( l_eq_mc_or, l_qmeFlagReggAddr, l_wakeupMode ),
              "Failed To Setup Runtime Wakeup Mode 0x%016lx", l_wakeupMode );
#endif

fapi_try_exit:
    FAPI_INF("< p10_setup_runtime_wakeup_mode" );
    return fapi2::current_err;
}
