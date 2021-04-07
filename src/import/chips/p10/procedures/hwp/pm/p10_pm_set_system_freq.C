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

// Defined here so as not have to shadow pstates_common.H to HWSV
#define CF7 7

fapi2::ReturnCode pm_set_frequency(
       const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target);


///////////////////////////////////////////////////////////
////////    p10_pm_set_system_freq
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_pm_set_system_freq(const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target)
{
    FAPI_DBG("> p10_pm_set_system_freq");

    do
    {
        FAPI_TRY(pm_set_frequency(i_sys_target));
    }
    while(0);

fapi_try_exit:
    return fapi2::current_err;
}
///////////////////////////////////////////////////////////
////////  pm_set_frequency
///////////////////////////////////////////////////////////
fapi2::ReturnCode pm_set_frequency(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_sys_target)
{
    FAPI_INF("pm_set_frequency >>>>>");

    // Bring in data for local testing
    #define __INTERNAL_POUNDV__
    #include "p10_pstate_parameter_block_int_vpd.H"

    fapi2::voltageBucketData_t l_poundV_data;
    uint32_t l_fmax_freq = 0;
    uint32_t l_ut_freq =0;
    uint32_t l_part_freq = 0;
    uint32_t l_psav_freq = 0;
    uint32_t l_wofbase_freq = 0;
    uint32_t l_pstate0_freq = 0;
    uint8_t  l_sys_pdv_mode = 0;
    uint16_t l_tmp_psav_freq = 0;
    uint16_t l_tmp_wofbase_freq = 0;
    uint16_t l_part_running_freq = 0;

    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_sys_freq_core_floor_mhz = 0;
    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_OVERRIDE_Type l_sys_freq_core_floor_mhz_ovr;
    fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ_Type l_sys_pstate0_freq_mhz = 0;
    fapi2::ATTR_NOMINAL_FREQ_MHZ_Type l_sys_nominal_freq_mhz = 0;
    fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_Type l_sys_freq_core_ceil_mhz = 0;
    fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_OVERRIDE_Type l_sys_freq_core_ceil_mhz_ovr;
    fapi2::ATTR_FREQ_CORE_FLOOR_MHZ_Type l_floor_freq_mhz = 0;
    fapi2::ATTR_FREQ_CORE_CEILING_MHZ_Type l_ceil_freq_mhz = 0;
    fapi2::ATTR_CHIP_EC_FEATURE_STATIC_POUND_V_Type l_chip_static_pound_v = 0;
    fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE_Type l_poundv_static_data = 0;

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

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_OVERRIDE,
                i_sys_target, l_sys_freq_core_ceil_mhz_ovr));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
                i_sys_target, l_sys_pdv_mode));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,
                i_sys_target, l_sys_pstate0_freq_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NOMINAL_FREQ_MHZ,
                i_sys_target, l_sys_nominal_freq_mhz));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                 i_sys_target,
                 l_poundv_static_data),
                 "Error from FAPI_ATTR_GET for attribute ATTR_POUND_V_STATIC_DATA_ENABLE");
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

            if (l_chip_static_pound_v && !l_poundv_static_data)
            {
                l_poundv_static_data = 1; 
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                            i_sys_target,
                            l_poundv_static_data),
                        "Error from FAPI_ATTR_SET for attribute ATTR_POUND_V_STATIC_DATA_ENABLE");
            }


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
            fapi2::voltageBucketData_t* p_poundV_data = &l_poundV_data;
            FAPI_TRY(wof_apply_overrides(l_proc_target, p_poundV_data));
#endif

            l_pstate0_freq = htobe16(l_poundV_data.operating_pts[CF7].core_frequency);

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_BIAS,
                        i_sys_target,
                        attr_freq_bias_0p5pct),
                    "Error from FAPI_ATTR_GET for attribute ATTR_FREQ_BIAS");

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

            FAPI_INF("VPD fmax_freq=%04d, ut_freq=%04d  psav_freq=%04d, psav_freq=%04d ",
                   l_fmax_freq, l_ut_freq, l_wofbase_freq, l_psav_freq);

            if (l_pstate0_freq > l_sys_pstate0_freq_mhz)
            {
                l_sys_pstate0_freq_mhz = l_pstate0_freq;
                FAPI_DBG("Setting Pstate 0 to Fmax of %04d (0x%04X)",
                        l_sys_pstate0_freq_mhz,  l_sys_pstate0_freq_mhz);
            }

            //Compute FMAX and Ceil freq
            if ( l_fmax_freq > l_sys_freq_core_ceil_mhz)
            {
                l_sys_freq_core_ceil_mhz = l_fmax_freq;
                FAPI_DBG("Setting CEIL to Fmax of %04d (0x%04X)",
                        l_sys_freq_core_ceil_mhz ,  l_sys_freq_core_ceil_mhz);

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
                    FAPI_INF("Present System WOF Base freq %04d is not equal to this chip's WOF Base Freq %04d",
                            l_part_running_freq, l_wofbase_freq);
                    // This does not produce an error log as the system will operate ok
                    // for this case.
                }

                if ( l_part_freq > l_part_running_freq)
                {
                    l_part_freq = l_part_running_freq;
                }
            }

            FAPI_INF("Running Computed ceiling (PS0) frequency: %04d (0x%04x)", l_sys_freq_core_ceil_mhz, l_sys_freq_core_ceil_mhz);
            FAPI_INF("Running Computed floor frequency:         %04d (0x%04x)", l_floor_freq_mhz, l_floor_freq_mhz);
            FAPI_INF("Running Computed wofbase frequency:       %04d (0x%04x)", l_tmp_wofbase_freq, l_tmp_wofbase_freq);
            FAPI_INF("Running Computed fixed frequency:         %04d (0x%04x)", l_part_running_freq, l_part_running_freq);

        } //end of proc list

        // Now clip things with system overrides
        // ATTR_FREQ_SYSTEM_CORE_CEIL_MHZ_OVERRIDE --> MRW
        //  -->l_sys_freq_core_ceil_mhz_ovr
        //
        // ATTR_FREQ_SYSTEM_CORE_CEIL_MHZ  -->calculated ceiling, can be
        // overridden by user
        //  -->l_sys_freq_core_ceil_mhz
        //

        // Determine the minimum of the following to set the maximum frequency
        //    - EC dependent limits if l_sys_freq_core_ceil_mhz_ovr is non-zero.
        //    - l_sys_freq_core_ceil_mhz,
        //    - l_sys_freq_core_ceil_mhz_ovr,
        //    - the computed Pstate 0.

        if (l_sys_freq_core_ceil_mhz_ovr &&
            l_sys_freq_core_ceil_mhz_ovr < l_sys_freq_core_ceil_mhz)
        {
            l_sys_freq_core_ceil_mhz = l_sys_freq_core_ceil_mhz_ovr;
            FAPI_INF("Lowering Pstate0 based on ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_OVERRIDE:  %04d ",
                    l_sys_freq_core_ceil_mhz_ovr);
        }

        // Determine the maximum of the following to set the minimum frequency
        //    - l_sys_freq_core_floor_mhz,
        //    - l_sys_freq_core_floor_mhz_ovr
        //    - the computed floor.
        if (l_sys_freq_core_floor_mhz > l_floor_freq_mhz)
        {
            l_floor_freq_mhz = l_sys_freq_core_floor_mhz;
            FAPI_INF("Raising the floor based on ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ:  %04d ",
                    l_sys_freq_core_floor_mhz);
        }

        if (l_sys_freq_core_floor_mhz_ovr > l_floor_freq_mhz)
        {
            l_floor_freq_mhz = l_sys_freq_core_floor_mhz_ovr;
            FAPI_INF("Raising floor based on ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_OVERRIDE:  %04d ",
                    l_sys_freq_core_floor_mhz_ovr);
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

        // Write out attributes with the results
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,     i_sys_target, l_sys_pstate0_freq_mhz));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_NOMINAL_FREQ_MHZ,            i_sys_target, l_part_freq));

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ,i_sys_target, l_sys_freq_core_ceil_mhz));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ,  i_sys_target, l_floor_freq_mhz));

        for (auto l_proc_target : i_sys_target.getChildren<fapi2::TARGET_TYPE_PROC_CHIP>())
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_CORE_CEILING_MHZ,   l_proc_target, l_sys_pstate0_freq_mhz));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,     l_proc_target, l_floor_freq_mhz));
        }

        FAPI_INF("Final Pstate0 Frequency: %04d (0x%04x)", l_sys_pstate0_freq_mhz, l_sys_pstate0_freq_mhz);

    }
    while(0);
fapi_try_exit:
    FAPI_INF("pm_set_frequency <<<<<<<");
    return fapi2::current_err;
}
// *INDENT-ON*
