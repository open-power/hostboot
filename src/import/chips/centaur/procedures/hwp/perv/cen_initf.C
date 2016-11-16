/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_initf.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file cen_initf.C
/// @brief Centaur initf (FAPI2)
///
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_initf.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fixes.H>
#include <centaur_misc_constants.H>

#ifndef __HOSTBOOT_MODULE
    #include <centaur_mbs_scan.H>
    #include <centaur_mba_scan.H>
    #include <centaur_dmi_scan.H>
    #include <centaur_thermal_scan.H>
#endif

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_initf(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");

#ifndef __HOSTBOOT_MODULE
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ReturnCode l_rc;

    // apply initfiles
    ecmdChipTarget l_ecmd_target;
    fapiTargetToEcmdTarget(i_target, l_ecmd_target);
    ecmdEnableRingCache(l_ecmd_target);
    FAPI_EXEC_HWP(l_rc, centaur_mbs_scan, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from centaur_mbs_scan");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    FAPI_EXEC_HWP(l_rc, centaur_mba_scan, i_target);

    if (l_rc)
    {
        FAPI_ERR("Error from centaur_mba_scan");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    FAPI_EXEC_HWP(l_rc, centaur_dmi_scan, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from centaur_dmi_scan");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    FAPI_EXEC_HWP(l_rc, centaur_thermal_scan, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from centaur_thermal_scan");
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    ecmdDisableRingCache(l_ecmd_target);

fapi_try_exit:
#endif
    FAPI_DBG("End");
    return fapi2::current_err;
}
