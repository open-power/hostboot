/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_set_system_freq.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file  p10_pm_set_system_freq.C
/// @brief Se the pstate0 and nominal freq
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : HWSV
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD value of each proc and compute system pstate0 and nominal frequency.
/// @endverbatim
// EKB-Mirror-To: hostboot
// EKB-Mirror-To: hwsv
// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi2.H>
#include "p10_pm_set_system_freq.H"
#include "p10_pm_get_poundv_bucket.H"
#include "p10_pm_utils.H"
#include <endian.h>

#define __INTERNAL_POUNDV__
#include "p10_pstate_parameter_block_int_vpd.H"

// Defined here so as not have to shadow pstates_common.H to HWSV
#define CF7 7

fapi2::ReturnCode pm_set_frequency(
       const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target,
       const bool i_wof_state);

fapi2::ReturnCode pm_set_wofbase_frequency(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target);

///////////////////////////////////////////////////////////
////////    p10_pm_set_system_freq
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_pm_set_system_freq(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target,
                       const bool i_wof_state)
{
    FAPI_DBG("> p10_pm_set_system_freq");

    do
    {
        FAPI_TRY(pm_set_frequency(i_sys_target, i_wof_state));
    }
    while(0);

fapi_try_exit:
    return fapi2::current_err;
}
///////////////////////////////////////////////////////////
////////  pm_set_frequency
///////////////////////////////////////////////////////////
fapi2::ReturnCode pm_set_frequency(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target,
    const bool i_wof_state)
{
    FAPI_INF("pm_set_frequency >>>>>");

    // Bring in data for local testing

    fapi2::voltageBucketData_t l_poundV_data;
    uint32_t l_fmax_freq = 0;
    uint32_t l_ut_freq =0;
    uint32_t l_vpd_ut_freq =0;
    uint32_t l_part_freq = 0;
    uint32_t l_psav_freq = 0;
    uint32_t l_wofbase_freq = 0;
    uint32_t l_pstate0_freq = 0;
    uint8_t  l_sys_pdv_mode = 0;
    uint16_t l_tmp_psav_freq = 0;
    uint16_t l_tmp_wofbase_freq = 0;
    uint16_t l_part_running_freq = 0;
    bool l_wof_state = i_wof_state;

    bool     b_dd1_floor = false;

    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_OVERRIDE_Type l_sys_freq_core_floor_mhz_ovr;
    fapi2::ATTR_MRW_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_mrw_freq_core_floor_mhz;
    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_sys_freq_core_floor_mhz = 0;
    fapi2::ATTR_FREQ_CORE_FLOOR_MHZ_Type l_floor_freq_mhz = 0;
    fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ_Type l_sys_pstate0_freq_mhz = 0;
    fapi2::ATTR_SYSTEM_COMPAT_FREQ_MHZ_Type l_sys_compat_freq_mhz = 0;
    fapi2::ATTR_NOMINAL_FREQ_MHZ_Type l_sys_nominal_freq_mhz = 0;
    fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_Type l_sys_freq_core_ceil_mhz = 0;
    fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_OVERRIDE_Type l_sys_freq_core_ceil_mhz_ovr;
    fapi2::ATTR_FREQ_CORE_CEILING_MHZ_Type l_ceil_freq_mhz = 0;
    fapi2::ATTR_CHIP_EC_FEATURE_STATIC_POUND_V_Type l_chip_static_pound_v = 0;
    fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE_Type l_poundv_static_data = 0;
    fapi2::ATTR_SYSTEM_FMAX_ENABLE_Type l_fmax_enable = 0;
    fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE_Type l_pdv_mode;

    fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_FREQUENCY_Type l_limited_freq_mhz;
    const fapi2::ATTR_FREQ_CORE_CEILING_MHZ_Type l_forced_ceil_freq_mhz = 2400;

    do
    {
        //We loop thru all the processors in the system and will figure out the
        //max of PSAV, FMAX, and UT in that list.  We look for the min of the WOFBase
        //values.  An attribute switch is used to specifically fail the WOFBase check.
        // - Min value of FMAX will be initialized to ATTR_SYSTEM_PSTATE0_FREQ_MHZ
        //   and same value will be initialized to ATTR_FREQ_SYSTEM_CORE_CEIL_MHZ
        // - Max value of PSAV will be initialized to ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ
        // - Min value of Fixed Frequecny will be initialized to ATTR_NOMINAL_FREQ_MHZ

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ,
                i_sys_target, l_sys_freq_core_floor_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ,
                i_sys_target, l_sys_freq_core_ceil_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_OVERRIDE,
                i_sys_target, l_sys_freq_core_floor_mhz_ovr));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_FREQ_SYSTEM_CORE_FLOOR_MHZ,
                i_sys_target, l_mrw_freq_core_floor_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_OVERRIDE,
                i_sys_target, l_sys_freq_core_ceil_mhz_ovr));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
                i_sys_target, l_sys_pdv_mode));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,
                i_sys_target, l_sys_pstate0_freq_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_COMPAT_FREQ_MHZ,
                i_sys_target, l_sys_compat_freq_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NOMINAL_FREQ_MHZ,
                i_sys_target, l_sys_nominal_freq_mhz));

        // RTC: 269377
        // FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_FMAX_ENABLE,
        //        i_sys_target, l_fmax_enable));
        l_fmax_enable = false;

#if defined(__HOSTBOOT_MODULE) || defined(FIPSODE)
        FAPI_INF("Running #V Validation checking under FW controls");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
                i_sys_target, l_pdv_mode));
#else
        FAPI_INF("Running #V Validation checking under LAB controls");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
                i_sys_target, l_pdv_mode));
#endif
        FAPI_TRY(pm_set_wofbase_frequency(i_sys_target));

        // Find Pstate 0 across the processor chips depending on the mode (FMax or UT)
        for (auto l_proc_target : i_sys_target.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
        {
            static const uint32_t TGT_STRING_SIZE = 64;
            char l_tgt_string[TGT_STRING_SIZE];
            fapi2::toString(l_proc_target, l_tgt_string, TGT_STRING_SIZE);
            FAPI_INF("Processing %s", l_tgt_string);

            fapi2::ATTR_FREQ_BIAS_Type attr_freq_bias_0p5pct = 0;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_STATIC_POUND_V,
                        l_proc_target, l_chip_static_pound_v));

            // if static data is needed, set the enable
            if (l_chip_static_pound_v)
            {
                l_poundv_static_data = 0x1;
                 FAPI_INF("EC level requiring static #V data detected.  Setting ATTR_POUND_V_STATIC_DATA_ENABLE");
            }

            // Write the enable out
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                            i_sys_target,
                            l_poundv_static_data),
                        "Error from FAPI_ATTR_SET for attribute ATTR_POUND_V_STATIC_DATA_ENABLE");

            // Read back to pick up any override
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                            i_sys_target,
                            l_poundv_static_data));

//             if (l_chip_static_pound_v)
//             {
//                 FAPI_ASSERT_NOEXIT(l_poundv_static_data,
//                         fapi2::PM_STATIC_POUNDV_EC_MISMATCH()
//                         .set_CHIP_TARGET(l_proc_target),
//                         "A chip that shouldn't consume external VPD has been detected but an "
//                         "ATTR_CHIP_EC_FEATURE_STATIC_POUND_V override is in place to allow it");
//             }

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

#ifndef FIPSODE
            if ((l_poundV_data.static_rails.modelDataFlag & 0x1) == 0x1)
            {
                //we detected non sorted part
                fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled =
                    (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_FORCE_DISABLED;

                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_ENABLED,
                            l_proc_target, l_wof_enabled));
                l_wof_state = false;
            }
            fapi2::voltageBucketData_t* p_poundV_data = &l_poundV_data;
            FAPI_TRY(wof_apply_overrides(l_proc_target, p_poundV_data,l_wof_state));
#endif
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_BIAS,
                        i_sys_target,
                        attr_freq_bias_0p5pct),
                    "Error from FAPI_ATTR_GET for attribute ATTR_FREQ_BIAS");

            l_pstate0_freq = bias_adjust_mhz(htobe16(l_poundV_data.operating_pts[CF7].core_frequency),
                                               attr_freq_bias_0p5pct);
            l_vpd_ut_freq  = bias_adjust_mhz(htobe16(l_poundV_data.other_info.VddUTCoreFreq),
                                               attr_freq_bias_0p5pct);


            l_fmax_freq     = bias_adjust_mhz(htobe16(l_poundV_data.other_info.VddFmxCoreFreq),
                                              attr_freq_bias_0p5pct);

            l_ut_freq       = bias_adjust_mhz(htobe16(l_poundV_data.other_info.VddUTCoreFreq),
                                              attr_freq_bias_0p5pct);

            l_wofbase_freq  = bias_adjust_mhz(htobe16(l_poundV_data.other_info.VddTdpWofCoreFreq),
                                              attr_freq_bias_0p5pct);

            l_psav_freq     = bias_adjust_mhz(htobe16(l_poundV_data.other_info.VddPsavCoreFreq),
                                              attr_freq_bias_0p5pct);

            l_part_freq    = bias_adjust_mhz(htobe16(l_poundV_data.other_info.FxdFreqMdeCoreFreq),
                                              attr_freq_bias_0p5pct);

            FAPI_INF("VPD CF[7]=%04d, fmax_freq=%04d, ut_freq=%04d  wofbase_freq=%04d, psav_freq=%04d ",
                   l_pstate0_freq, l_fmax_freq, l_ut_freq, l_wofbase_freq, l_psav_freq);

            if (l_vpd_ut_freq > l_sys_compat_freq_mhz)
            {
                if (l_sys_compat_freq_mhz == 0 || attr_freq_bias_0p5pct)
                {
                    l_sys_compat_freq_mhz = l_vpd_ut_freq;
                    FAPI_INF("Setting Compatibilty frequency to UT of %04d (0x%04X)",
                            l_sys_compat_freq_mhz,  l_sys_compat_freq_mhz);
                }
                else
                {
                    if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_WARN ||
                        l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO   )
                    {
                        FAPI_INF("**** WARNING : #V UltraTurbo does not match the other UltraTurbo values. UT=%d MHz; Compat=%d Mhz",
                                l_vpd_ut_freq, l_sys_compat_freq_mhz);
                        FAPI_INF("**** WARNING : No functions are disabled but this is NOT a supported product configuration");
                        FAPI_INF("**** WARNING : Tracing due to ATTR_SYSTEM_PDV_VALIDATION_MODE = WARN or INFO");

                        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO)
                        {
                            if (!fapi2::is_platform<fapi2::PLAT_CRONUS>())
                            {
                                FAPI_ASSERT_NOEXIT(false,
                                    fapi2::PSTATE_PB_UT_FREQ_MISMATCH()
                                    .set_CHIP_TARGET(l_proc_target)
                                    .set_UT_FREQ(l_vpd_ut_freq)
                                    .set_COMPAT_FREQ(l_sys_compat_freq_mhz),
                                    "The UltraTurbo frequencies need to be compatabile");
                            }
                        }
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                        break;
                    }

                    if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
                    {
                        FAPI_ERR("**** ERROR : #V UltraTurbo does not match the other UltraTurbo values. UT=%d MHz; Compat=%d Mhz",
                                l_vpd_ut_freq, l_sys_compat_freq_mhz);
                        FAPI_ERR("**** ERROR : Halting due to ATTR_SYSTEM_PDV_VALIDATION_MODE = FAIL");

                        FAPI_ASSERT(false,
                            fapi2::PSTATE_PB_UT_FREQ_MISMATCH()
                            .set_CHIP_TARGET(l_proc_target)
                            .set_UT_FREQ(l_vpd_ut_freq)
                            .set_COMPAT_FREQ(l_sys_compat_freq_mhz),
                            "The UltraTurbo frequencies need to be compatabile");
                    }
                }
            }

            if (l_pstate0_freq > l_sys_pstate0_freq_mhz)
            {
                l_sys_pstate0_freq_mhz = l_pstate0_freq;
                FAPI_INF("Setting Pstate 0 to CF[7] of %04d (0x%04X)",
                        l_sys_pstate0_freq_mhz,  l_sys_pstate0_freq_mhz);
            }

            //Compute the Ceil freq
            // RTC: 269377
            if (l_fmax_enable)
            {
                if (l_fmax_freq > l_sys_freq_core_ceil_mhz)
                {
                    l_sys_freq_core_ceil_mhz = l_fmax_freq;
                    FAPI_INF("Setting CEIL to Fmax of %04d (0x%04X)",
                            l_sys_freq_core_ceil_mhz ,  l_sys_freq_core_ceil_mhz);

                }
            }
            else
            {
                if (l_ut_freq > l_sys_freq_core_ceil_mhz)
                {
                    l_sys_freq_core_ceil_mhz = l_ut_freq;
                    FAPI_INF("Setting CEIL to UT of %04d (0x%04X)",
                            l_sys_freq_core_ceil_mhz ,  l_sys_freq_core_ceil_mhz);
                }
            }

            FAPI_INF("PSTATE 0 Freq %04d (0x%04X)", l_sys_pstate0_freq_mhz, l_sys_pstate0_freq_mhz);
            // Get processor scope attributes
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,
                        l_proc_target, l_floor_freq_mhz));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_CEILING_MHZ,
                        l_proc_target, l_ceil_freq_mhz));





            //Compute floor freq
            if (!l_tmp_psav_freq)
            {
                l_tmp_psav_freq = l_psav_freq;
            }
            else
            {
                if (l_psav_freq >= l_tmp_psav_freq)
                {
                    l_tmp_psav_freq = l_psav_freq;
                }
                if ( l_tmp_psav_freq >= l_floor_freq_mhz)
                {
                    l_floor_freq_mhz = l_tmp_psav_freq;
                }
            }

            // Processor overrides the ceiling below Pstate 0 clips it
            if (l_ceil_freq_mhz != 0 && l_ceil_freq_mhz > l_floor_freq_mhz &&
                    l_sys_freq_core_ceil_mhz > l_ceil_freq_mhz)
            {
                l_ceil_freq_mhz = l_sys_freq_core_ceil_mhz;
                FAPI_INF("Processor target override limiting Pstate 0. %04d MHz (0x%X)", l_ceil_freq_mhz, l_ceil_freq_mhz );
            }

            // Limit to DD specific values only if all the CEIL overrides are non-zero
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_FREQUENCY,
                    l_proc_target, l_limited_freq_mhz));
            if (l_limited_freq_mhz &&
                    !l_sys_freq_core_ceil_mhz_ovr && !l_sys_freq_core_ceil_mhz && !l_ceil_freq_mhz)
            {
                if (l_sys_freq_core_ceil_mhz > l_forced_ceil_freq_mhz)
                {
                    l_sys_freq_core_ceil_mhz = l_forced_ceil_freq_mhz;
                }
            }

            if (l_limited_freq_mhz && l_sys_freq_core_ceil_mhz_ovr < 2400)
            {
                l_sys_freq_core_ceil_mhz_ovr = l_forced_ceil_freq_mhz;
            }
            if (l_limited_freq_mhz && l_sys_freq_core_ceil_mhz < 2400)
            {
                l_sys_freq_core_ceil_mhz = l_forced_ceil_freq_mhz;
            }

            if (l_limited_freq_mhz)
            {
                b_dd1_floor = true;
            }


            // Compute WOFBase (minumim across chips)
            if (l_wofbase_freq > l_tmp_wofbase_freq &&
                    l_tmp_wofbase_freq == 0)
            {
                l_tmp_wofbase_freq = l_wofbase_freq;
            }
            else
            {
                if (l_wofbase_freq != l_tmp_wofbase_freq)
                {
                    FAPI_INF("Present System WOF Base freq %04d is not equal to this chip's WOF Base Freq %04d",
                            l_tmp_wofbase_freq, l_wofbase_freq);
                    // This does not produce an error log as the system will operate ok
                    // for this case.
                }

                if ( l_wofbase_freq < l_tmp_wofbase_freq)
                {
                    l_tmp_wofbase_freq = l_wofbase_freq;
                }
            }
            //Compute Fixed Frequency (minumim across chips)
            if (l_part_freq > l_part_running_freq &&
                    l_part_running_freq == 0)
            {
                l_part_running_freq = l_part_freq;
            }
            else
            {
                if (l_part_freq != l_part_running_freq)
                {
                    FAPI_INF("Present part freq %04d is not equal to this chip's part Freq %04d",
                            l_part_freq, l_part_running_freq);
                    // This does not produce an error log as the system will operate ok
                    // for this case.
                }

                if ( l_part_freq < l_part_running_freq)
                {
                    l_part_running_freq = l_part_freq;
                }
            }

            FAPI_INF("Running Computed ceiling frequency:   %04d (0x%04x)", l_sys_freq_core_ceil_mhz, l_sys_freq_core_ceil_mhz);
            FAPI_INF("Running Computed floor frequency:     %04d (0x%04x)", l_floor_freq_mhz, l_floor_freq_mhz);
            FAPI_INF("Running Computed wofbase frequency:   %04d (0x%04x)", l_tmp_wofbase_freq, l_tmp_wofbase_freq);
            FAPI_INF("Running Computed fixed frequency:     %04d (0x%04x)", l_part_running_freq, l_part_running_freq);

        } //end of proc list
        l_part_freq = l_part_running_freq;
        l_wofbase_freq = l_tmp_wofbase_freq;


        // Now clip things with system overrides
        // ATTR_FREQ_SYSTEM_CORE_CEIL_MHZ_OVERRIDE --> Lab
        //  -->l_sys_freq_core_ceil_mhz_ovr
        //
        // ATTR_FREQ_SYSTEM_CORE_CEIL_MHZ  -->calculated ceiling, can be
        // overridden by user
        //  -->l_sys_freq_core_ceil_mhz
        //

       // The ceiling override trumps everything
        if (l_sys_freq_core_ceil_mhz_ovr)
        {
            l_sys_freq_core_ceil_mhz = l_sys_freq_core_ceil_mhz_ovr;
            FAPI_INF("Changing Pstate0 based on ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_OVERRIDE:  %04d ",
                    l_sys_freq_core_ceil_mhz_ovr);

            if (l_sys_freq_core_ceil_mhz_ovr > l_sys_freq_core_ceil_mhz)
            {
                FAPI_IMP("WARNING: ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_OVERRIDE of %04d is raising PSTATE 0 beyond "
                         "the VPD based frequency of %04d .  Pstate operations may lead to suspicious outcomes",
                    l_sys_freq_core_ceil_mhz_ovr, l_sys_freq_core_ceil_mhz);
            }
        }

        // Raise the floor if the computed attribute is overrided for some reason
        if (l_sys_freq_core_floor_mhz > l_floor_freq_mhz)
        {
            l_floor_freq_mhz = l_sys_freq_core_floor_mhz;
            FAPI_INF("Raising the floor based on ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ:  %04d ",
                    l_sys_freq_core_floor_mhz);
        }

        // Adjust the nominal to be between the ceiling and the floor
        if (l_sys_freq_core_ceil_mhz < l_part_freq)
        {
            l_part_freq = l_sys_freq_core_ceil_mhz;
            FAPI_INF("Clipping the nominal frequency to the ceiling frequency:  %04d ",
                    l_part_freq);
        }

        if (l_floor_freq_mhz > l_part_freq)
        {
            l_part_freq  = l_floor_freq_mhz;
            FAPI_INF("Raising the nominal frequency to the floor frequency:  %04d ",
                    l_part_freq);
        }

        //Verify floor and ceil freq ratio, if remainder is greater
        //than 2 , then need to adjust floor freq
        //Round up the ceiling up to nearest even frequency and then divide by 2
        uint32_t l_computed_freq_mhz = (((l_sys_freq_core_ceil_mhz << 2) + 1) >> 2) >> 1;
        if (l_floor_freq_mhz < l_computed_freq_mhz)
        {
            l_floor_freq_mhz = l_computed_freq_mhz;
        }

        // Adjust with MRW defined floor if not DD1
        if (l_mrw_freq_core_floor_mhz > l_floor_freq_mhz)
        {
            if (b_dd1_floor)
            {
                FAPI_INF("Skipping use of ATTR_MRW_FREQ_SYSTEM_CORE_FLOOR_MHZ on DD1 systems");
            }
            else
            {
                l_floor_freq_mhz = l_mrw_freq_core_floor_mhz;
                FAPI_INF("Setting the floor based on ATTR_MRW_FREQ_SYSTEM_CORE_FLOOR_MHZ:  %04d ",
                        l_mrw_freq_core_floor_mhz);
            }
        }

        // The floor override trumps everything
        if (l_sys_freq_core_floor_mhz_ovr)
        {
            l_floor_freq_mhz = l_sys_freq_core_floor_mhz_ovr;
            FAPI_INF("Setting the floor based on ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_OVERRIDE:  %04d ",
                    l_sys_freq_core_floor_mhz_ovr);
        }
        // Write out attributes with the results
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,     i_sys_target, l_sys_pstate0_freq_mhz));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_COMPAT_FREQ_MHZ,      i_sys_target, l_sys_compat_freq_mhz));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_NOMINAL_FREQ_MHZ,            i_sys_target, l_part_freq));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOFBASE_FREQ_MHZ,            i_sys_target, l_wofbase_freq));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ,i_sys_target, l_sys_freq_core_ceil_mhz));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ,  i_sys_target, l_floor_freq_mhz));

        for (auto l_proc_target : i_sys_target.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
        {
            uint32_t ceil_freq =
            (l_sys_pstate0_freq_mhz < l_sys_freq_core_ceil_mhz) ? l_sys_pstate0_freq_mhz : l_sys_freq_core_ceil_mhz;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_CORE_CEILING_MHZ,   l_proc_target, ceil_freq));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,     l_proc_target, l_floor_freq_mhz));
        }

        FAPI_INF("Final Pstate0 Frequency: %04d (0x%04x)", l_sys_pstate0_freq_mhz, l_sys_pstate0_freq_mhz);

    }
    while(0);
fapi_try_exit:
    FAPI_INF("pm_set_frequency <<<<<<<");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////////
////////  pm_set_wofbase_frequency
///////////////////////////////////////////////////////////
fapi2::ReturnCode pm_set_wofbase_frequency(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target)
{
    FAPI_INF("pm_set_wofbase_frequency >>>>>");

    // Bring in data for local testing
    //#define __INTERNAL_POUNDV__
   // #include "p10_pstate_parameter_block_int_vpd.H"

    fapi2::voltageBucketData_t l_poundV_data;
    uint32_t l_wofbase_freq = 0;
    uint16_t l_tmp_wofbase_freq = 0;

    fapi2::ATTR_CHIP_EC_FEATURE_STATIC_POUND_V_Type l_chip_static_pound_v = 0;
    fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE_Type l_poundv_static_data = 0;
    fapi2::ATTR_SOCKET_POWER_NOMINAL_Type l_powr_nom;

    do
    {


        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOFBASE_FREQ_MHZ,
                        i_sys_target, l_wofbase_freq));

        if ( l_wofbase_freq )
        {
            FAPI_INF("WOFBASE %x, is already set",l_wofbase_freq);
            break;
        }
        // Find Pstate 0 across the processor chips depending on the mode (FMax or UT)
        for (auto l_proc_target : i_sys_target.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
        {
            static const uint32_t TGT_STRING_SIZE = 64;
            char l_tgt_string[TGT_STRING_SIZE];
            fapi2::toString(l_proc_target, l_tgt_string, TGT_STRING_SIZE);
            FAPI_INF("Processing %s", l_tgt_string);

            fapi2::ATTR_FREQ_BIAS_Type attr_freq_bias_0p5pct = 0;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_STATIC_POUND_V,
                        l_proc_target, l_chip_static_pound_v));

            // if static data is needed, set the enable
            if (l_chip_static_pound_v)
            {
                l_poundv_static_data = 0x1;
                FAPI_INF("EC level requiring static #V data detected.  Setting ATTR_POUND_V_STATIC_DATA_ENABLE");
            }

            // Write the enable out
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                        i_sys_target,
                        l_poundv_static_data),
                    "Error from FAPI_ATTR_SET for attribute ATTR_POUND_V_STATIC_DATA_ENABLE");

            // Read back to pick up any override
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                        i_sys_target,
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

            //Update power nominal target
            if (!l_powr_nom)
            {
                l_powr_nom = l_poundV_data.other_info.TSrtSocPowTgt;
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SOCKET_POWER_NOMINAL,
                            l_proc_target, l_powr_nom));
            }


            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_BIAS,
                        i_sys_target,
                        attr_freq_bias_0p5pct),
                    "Error from FAPI_ATTR_GET for attribute ATTR_FREQ_BIAS");


            l_wofbase_freq  = bias_adjust_mhz(htobe16(l_poundV_data.other_info.VddTdpWofCoreFreq),
                    attr_freq_bias_0p5pct);


            FAPI_INF("wofbase_freq=%04d",l_wofbase_freq);

            // Compute WOFBase (minumim across chips)
            if (l_wofbase_freq > l_tmp_wofbase_freq &&
                    l_tmp_wofbase_freq == 0)
            {
                l_tmp_wofbase_freq = l_wofbase_freq;
            }
            else
            {
                if (l_wofbase_freq != l_tmp_wofbase_freq)
                {
                    FAPI_INF("Present System WOF Base freq %04d is not equal to this chip's WOF Base Freq %04d",
                            l_tmp_wofbase_freq, l_wofbase_freq);
                    // This does not produce an error log as the system will operate ok
                    // for this case.
                }

                if ( l_wofbase_freq < l_tmp_wofbase_freq)
                {
                    l_tmp_wofbase_freq = l_wofbase_freq;
                }
            }
            FAPI_INF("Running Computed wofbase frequency:   %04d (0x%04x)", l_tmp_wofbase_freq, l_tmp_wofbase_freq);
        } //end of proc list
        l_wofbase_freq = l_tmp_wofbase_freq;

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOFBASE_FREQ_MHZ,i_sys_target, l_wofbase_freq));
    }
    while(0);
fapi_try_exit:
    FAPI_INF("pm_set_wofbase_frequency <<<<<<<");
    return fapi2::current_err;
}
// *INDENT-ON*
