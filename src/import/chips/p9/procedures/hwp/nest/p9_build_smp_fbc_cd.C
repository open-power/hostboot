/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_build_smp_fbc_cd.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_build_smp_fbc_cd.C
/// @brief Fabric configuration (hotplug, CD) functions
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 3
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_misc_scom_addresses.H>
#include <p9_build_smp_fbc_cd.H>
#include <p9_build_smp_adu.H>
#include <p9_fbc_cd_hp1_scom.H>
#include <p9_fbc_cd_hp2_scom.H>
#include <p9_fbc_cd_hp3_scom.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// NOTE: see comments above function prototype in header
fapi2::ReturnCode p9_build_smp_set_fbc_cd(p9_build_smp_system& i_smp)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // iterate through application of three CD hotplug sequences, each with their
    // own unique initfile
    for (uint8_t ii = 1;
         ii <= 3;
         ii++)
    {
        // apply initfile on all chips
        for (auto g_iter = i_smp.groups.begin();
             g_iter != i_smp.groups.end();
             ++g_iter)
        {
            for (auto p_iter = g_iter->second.chips.begin();
                 p_iter != g_iter->second.chips.end();
                 ++p_iter)
            {
                // initialize serial SCOM chains
                switch (ii)
                {
                    case 1:
                        FAPI_EXEC_HWP(l_rc, p9_fbc_cd_hp1_scom, *(p_iter->second.target), FAPI_SYSTEM);
                        break;

                    case 2:
                        FAPI_EXEC_HWP(l_rc, p9_fbc_cd_hp2_scom, *(p_iter->second.target), FAPI_SYSTEM);
                        break;

                    case 3:
                        FAPI_EXEC_HWP(l_rc, p9_fbc_cd_hp3_scom, *(p_iter->second.target), FAPI_SYSTEM);
                        break;

                    default:
                        FAPI_ASSERT(false,
                                    fapi2::P9_BUILD_SMP_UNKNOWN_CD_HP_ERR()
                                    .set_TARGET(*(p_iter->second.target))
                                    .set_CD_HP(ii),
                                    "Code error -- attempted to run unsupported CD hotplug initfile");
                }

                if (l_rc)
                {
                    FAPI_ERR("Error from p9_fbc_cd_hp%d_scom", ii);
                    fapi2::current_err = l_rc;
                    goto fapi_try_exit;
                }
            }
        }

        // issue switch CD on all chips to force updates to occur
        FAPI_TRY(p9_build_smp_sequence_adu(i_smp, SMP_ACTIVATE_PHASE1, SWITCH_CD),
                 "Error from p9_build_smp_sequence_adu (SWITCH_CD, #%d)", ii);
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
