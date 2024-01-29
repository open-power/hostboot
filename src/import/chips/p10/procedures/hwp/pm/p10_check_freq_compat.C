/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_check_freq_compat.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
/// @file  p10_check_freq_compat.C
/// @brief Se the pstate0 and nominal freq
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : HB
///
/// @verbatim
/// Procedure Summary:
///   - THis procedure will match the pstate0 freq across node pstate0
/// @endverbatim

// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
// EKB-Mirror-To: hostboot


#include <fapi2.H>
#include "p10_check_freq_compat.H"
#include <p10_pm_get_poundv_bucket.H>
#include <p10_pm_utils.H>

#define __INTERNAL_POUNDV__
#include "p10_pstate_parameter_block_int_vpd.H"
//Function declaration
fapi2::ReturnCode
p10_check_pau_freq_compat(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_targ);

///////////////////////////////////////////////////////////
//////// p10_check_freq_compat 
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_check_freq_compat(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_targ,
                             uint32_t i_pstate0)
{
    FAPI_DBG("> p10_check_freq_compat");
    fapi2::ATTR_SYSTEM_COMPAT_FREQ_MHZ_Type l_sys_compat_freq_mhz = 0;
    fapi2::ATTR_SYSTEM_FMAX_ENABLE_Type l_sys_fmax_enable = 0;

    do
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_COMPAT_FREQ_MHZ,
                i_sys_targ,l_sys_compat_freq_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_FMAX_ENABLE,
                i_sys_targ,l_sys_fmax_enable));

       if (!l_sys_fmax_enable)
       {

           FAPI_ASSERT((i_pstate0 == l_sys_compat_freq_mhz),
                   fapi2::MULTINODE_FREQ_MISMATCH()
                   .set_LOCAL_UT_FREQ(l_sys_compat_freq_mhz)
                   .set_SYSTEM_UT_FREQ(i_pstate0),
                   "p10_check_freq_compat :Failed to match the same pstate0 freq across node");
       }


       //Verify PAU frequency from #V with the system attribute
       FAPI_TRY(p10_check_pau_freq_compat(i_sys_targ));
    }
    while(0);

fapi_try_exit:
    return fapi2::current_err;
}



///////////////////////////////////////////////////////////
//////// p10_check_pau_freq_compat
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_check_pau_freq_compat(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_targ)
{
    FAPI_DBG("> p10_check_pau_freq_compat");
    fapi2::ATTR_FREQ_PAU_VPD_MHZ_Type l_sys_compat_pau_freq_mhz = 0;

    do
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_VPD_MHZ,
                    i_sys_targ,l_sys_compat_pau_freq_mhz));
        fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE_Type l_poundv_static_data = 0;
        fapi2::voltageBucketData_t l_poundV_data;

        //Get proc list from sys target, In multinode system, this should give
        //the list of procs of all the nodes.
        for (auto l_proc_target : i_sys_targ.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                        i_sys_targ,
                        l_poundv_static_data));

            if (l_poundv_static_data)
            {
                FAPI_INF("attribute ATTR_POUND_V_STATIC_DATA_ENABLE is set");
                FAPI_INF("&l_poundV_data %p;   &g_vpd_PVData %p sizeof(g_vpd_PVData) %d sizeof(l_poundV_data) %d",
                        &l_poundV_data,&g_vpd_PVData,sizeof(g_vpd_PVData),sizeof(l_poundV_data));

                memset(&l_poundV_data, 0, sizeof(g_vpd_PVData));
                memcpy(&l_poundV_data, &g_vpd_PVData, sizeof(g_vpd_PVData));
            }
            else
            {
                FAPI_INF("attribute ATTR_POUND_V_STATIC_DATA_ENABLE is NOT set");
                //Read #V data from each proc
                FAPI_TRY(p10_pm_get_poundv_bucket(l_proc_target, l_poundV_data));
            }

            //If we are in PNEXT system, then only will verify PAU freq
            if ((l_poundV_data.static_rails.modelDataFlag & PDV_MODEL_DATA_PNEXT)
                    == PDV_MODEL_DATA_PNEXT)
            {
                if ( l_sys_compat_pau_freq_mhz != l_poundV_data.other_info.PAUFreq)
                {
                    FAPI_ASSERT(false,
                            fapi2::SYSTEM_PAU_FREQ_MISMATCH()
                            .set_CHIP_TARGET(l_proc_target)
                            .set_PAU_FREQ(l_sys_compat_pau_freq_mhz)
                            .set_VPD_PAU_FREQ(l_poundV_data.other_info.PAUFreq),
                            "The PAU frequencies need to be compatible");

                }
            }

        }
    }
    while(0);

fapi_try_exit:
    return fapi2::current_err;
}
// *INDENT-ON*
